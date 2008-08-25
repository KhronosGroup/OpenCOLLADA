/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"
#include "COLLADAMaxAnimationExporter.h"

#include "COLLADAMaxExtra.h"



namespace COLLADAMax
{


    const String Extra::TECHNIQUE_PROFILE_3DSMAX = "3dsMAX";


    //---------------------------------------------------------------
    Extra::Extra ( COLLADA::StreamWriter * streamWriter, AnimationExporter * animationExporter )
            : COLLADA::BaseExtraTechnique ( ),
			mSW(streamWriter),
			mAnimationExporter(animationExporter)
    {}


	//---------------------------------------------------------------
	void Extra::addAnimatedExtraParameter(const String & parameterName, const String& childName, IParamBlock2* parameters, int parameterIndex, const String& baseId)
	{
		ParamType2 parameterType = parameters->GetParameterType(parameterIndex);

		// use the animation number with the GetController method
		// since the parameters enumeration doesn't reflect the param
		// block order.
		int animationNumber = parameters->GetAnimNum(parameterIndex);
		Control *controller = parameters->GetController(animationNumber);

		switch (parameterType)
		{
		case TYPE_BOOL:
			addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex)!= false);
			// NO ANIMATION ON BOOLEANS
			break;
		case TYPE_INT:
			if ( AnimationExporter::isAnimated(parameters, parameterIndex) )
			{
				addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex) , parameterName);
				mAnimationExporter->addAnimatedParameter(parameters, parameterIndex, baseId, parameterName, 0);
			}
			else
			{
				addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex));
			}
			break;
		case TYPE_FLOAT:
			if ( AnimationExporter::isAnimated(parameters, parameterIndex) )
			{
				addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetFloat(parameterIndex), parameterName);
				mAnimationExporter->addAnimatedParameter(parameters, parameterIndex, baseId, parameterName, 0);
			}
			else
			{
				addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetFloat(parameterIndex));
			}
			break;
		default:
			break;
		}
	}


	//---------------------------------------------------------------
	void Extra::addAnimatedExtraParameter(const String & parameterName, const String& childName, IParamBlock* parameters, int parameterIndex, const String& baseId)
	{
		ParamType parameterType = parameters->GetParameterType(parameterIndex);

		// use the animation number with the GetController method
		// since the parameters enumeration doesn't reflect the param
		// block order.
		Control *controller = parameters->GetController(parameterIndex);

		switch (parameterType)
		{
		case TYPE_BOOL:
			addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex)!= false);
			// NO ANIMATION ON BOOLEANS
			break;
		case TYPE_INT:
			if ( AnimationExporter::isAnimated(parameters, parameterIndex) )
			{
				addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex) , parameterName);
				mAnimationExporter->addAnimatedParameter(parameters, parameterIndex, baseId, parameterName, 0);
			}
			else
			{
				addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex));
			}
			break;
		case TYPE_FLOAT:
			if ( AnimationExporter::isAnimated(parameters, parameterIndex) )
			{
				addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetFloat(parameterIndex), parameterName);
				mAnimationExporter->addAnimatedParameter(parameters, parameterIndex, baseId, parameterName, 0);
			}
			else
			{
				addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetFloat(parameterIndex));
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

	//---------------------------------------------------------------
	void Extra::addExtraTechniques()
	{
		addTextureExtraTechniques(*mSW);
	}

}
