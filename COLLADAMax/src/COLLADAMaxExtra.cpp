/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxAnimationExporter.h"

#include "COLLADAMaxExtra.h"



namespace COLLADAMax
{


	const String Extra::TECHNIQUE_PROFILE_3DSMAX = "OpenCOLLADA3dsMax";

	const String Extra::TECHNIQUE_PROFILE_OPENCOLLADA = "OpenCOLLADA";

	const String Extra::USERDEFINED_PROPERTIES = "user_properties";


    //---------------------------------------------------------------
    Extra::Extra ( COLLADASW::StreamWriter * streamWriter, DocumentExporter * documentExporter )
            :mSW(streamWriter),
			mAnimationExporter(documentExporter->getAnimationExporter()),
			mOptions(documentExporter->getOptions()),
			mExtraTechnique(0)
    {}


	//---------------------------------------------------------------
	void Extra::addAnimatedExtraParameter(const String & parameterName, const String& childName, IParamBlock2* parameters, int parameterIndex, const String& baseId)
	{
		//check if the parameterIndex is a valid index for this param block
		if ( parameters->IDtoIndex(parameterIndex) < 0 )
			return;

		ParamType2 parameterType = parameters->GetParameterType(parameterIndex);

		TimeValue animationStart = mOptions.getAnimationStart();


		switch (parameterType)
		{
		case TYPE_BOOL:
			mExtraTechnique->addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex, animationStart)!= false);
			// NO ANIMATION ON BOOLEANS
			break;
		case TYPE_INT:
			if ( AnimationExporter::isAnimated(parameters, parameterIndex) )
			{
				mExtraTechnique->addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex, animationStart) , parameterName);
				mAnimationExporter->addAnimatedParameter(parameters, parameterIndex, baseId, parameterName, 0);
			}
			else
			{
				mExtraTechnique->addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex, animationStart));
			}
			break;
		case TYPE_FLOAT:
			if ( AnimationExporter::isAnimated(parameters, parameterIndex) )
			{
				mExtraTechnique->addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetFloat(parameterIndex, animationStart), parameterName);
				mAnimationExporter->addAnimatedParameter(parameters, parameterIndex, baseId, parameterName, 0);
			}
			else
			{
				mExtraTechnique->addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetFloat(parameterIndex, animationStart));
			}
			break;
		default:
			break;
		}
	}


	//---------------------------------------------------------------
	void Extra::addAnimatedExtraParameter(const String & parameterName, const String& childName, IParamBlock* parameters, int parameterIndex, const String& baseId)
	{
		if ( parameterIndex >= parameters->NumParams() )
			return;

		ParamType parameterType = parameters->GetParameterType(parameterIndex);

		TimeValue animationStart = mOptions.getAnimationStart();

		// use the animation number with the GetController method
		// since the parameters enumeration doesn't reflect the param
		// block order.
		Control *controller = parameters->GetController(parameterIndex);

		switch (parameterType)
		{
		case TYPE_BOOL:
			mExtraTechnique->addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex, animationStart)!= false);
			// NO ANIMATION ON BOOLEANS
			break;
		case TYPE_INT:
			if ( AnimationExporter::isAnimated(parameters, parameterIndex) )
			{
				mExtraTechnique->addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex, animationStart) , parameterName);
				mAnimationExporter->addAnimatedParameter(parameters, parameterIndex, baseId, parameterName, 0);
			}
			else
			{
				mExtraTechnique->addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex, animationStart));
			}
			break;
		case TYPE_FLOAT:
			if ( AnimationExporter::isAnimated(parameters, parameterIndex) )
			{
				mExtraTechnique->addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetFloat(parameterIndex, animationStart), parameterName);
				mAnimationExporter->addAnimatedParameter(parameters, parameterIndex, baseId, parameterName, 0);
			}
			else
			{
				mExtraTechnique->addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetFloat(parameterIndex, animationStart));
			}
			break;
		default:
			break;
		}
	}



	//---------------------------------------------------------------
	void Extra::addParamBlockAnimatedExtraParameters ( const String & elementName, const ExtraParameter extraParameters[], int extraParametersCount, IParamBlock * paramBlock, const String& baseId )
	{
		for ( int i = 0; i < extraParametersCount; ++i )
		{
			const ExtraParameter & parameter = extraParameters[ i ];
			addAnimatedExtraParameter ( parameter.paramName, elementName, paramBlock, parameter.paramId, baseId );
		}
	}

	//---------------------------------------------------------------
	void Extra::addParamBlockAnimatedExtraParameters ( const String & elementName, const ExtraParameter extraParameters[], int extraParametersCount, IParamBlock2 * paramBlock, const String& baseId )
	{
		for ( int i = 0; i < extraParametersCount; ++i )
		{
			const ExtraParameter & parameter = extraParameters[ i ];
			addAnimatedExtraParameter ( parameter.paramName, elementName, paramBlock, parameter.paramId, baseId );
		}
	}

	void Extra::writeParameterBlockInfo( const String& fileName, IParamBlock* parameters )
	{

		std::filebuf fb;

		fb.open ( fileName.c_str(), std::ios::app );

		std::ostream os ( &fb );


		int count = parameters->NumParams();


		for (int i = 0; i<count; ++i)
		{
			ParamType type = parameters->GetParameterType(i);

			os << i << " ";

			switch ( type )
			{

			case TYPE_BOOL:
				os << "TYPE_BOOL " << parameters->GetInt ( i ) << " ";
				break;

			case TYPE_FLOAT:
				os << "TYPE_FLOAT " << parameters->GetFloat ( i ) << " ";
				break;

			case TYPE_INT:
				os << "TYPE_INT " << parameters->GetInt ( i ) << " ";
				break;
			case TYPE_RGBA:
				Color color = parameters->GetColor(i);
				os << "TYPE_RGBA " << color.r << " " << color.g << " " << color.b << " " ;
				break;


			}

			os << std::endl << std::endl;
		}

		fb.close();
	}


	void Extra::writeParameterBlockInfo( const String& fileName, IParamBlock2* parameters )
	{

		std::filebuf fb;

		fb.open ( fileName.c_str(), std::ios::app );

		std::ostream os ( &fb );


		int count = parameters->NumParams();


		for (int i = 0; i<count; ++i)
		{

			int parameterID = parameters->IndextoID(i);

			ParamType2 type = parameters->GetParameterType(parameterID);
			bool printName = true;

			os << i << " " << parameterID << " ";

			switch ( type )
			{

			case TYPE_BOOL:
				os << "TYPE_BOOL " << parameters->GetInt ( parameterID ) << " ";
				break;

			case TYPE_FLOAT:
				os << "TYPE_FLOAT " << parameters->GetFloat ( parameterID ) << " ";
				break;
			case TYPE_PCNT_FRAC:
				os << "TYPE_PCNT_FRAC " << parameters->GetFloat ( parameterID ) << " ";
				break;

			case TYPE_INT:
				os << "TYPE_INT " << parameters->GetInt ( parameterID ) << " ";
				break;
			case TYPE_RGBA:
				{
					Color color = parameters->GetColor(i);
					os << "TYPE_RGBA " << color.r << " " << color.g << " " << color.b << " " ;
					break;
				}
			case TYPE_TEXMAP:
				{
					Texmap* texmap = parameters->GetTexmap(i);
					os << "TYPE_TEXMAP ";
					if ( texmap )
						os << texmap->GetName();
					os << " " ;
					break;
				}
			default:
				printName = false;


			}

			if ( printName )
				os << parameters->GetLocalName ( parameterID );

			os << std::endl << std::endl;
		}

		fb.close();
	}



}
