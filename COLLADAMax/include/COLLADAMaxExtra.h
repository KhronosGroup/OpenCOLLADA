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


#ifndef __COLLADAMAX_EXTRA_H__
#define __COLLADAMAX_EXTRA_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADASWStreamWriter.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWExtra.h"


class Object;

namespace COLLADAMax
{

	class DocumentExporter;
	class AnimationExporter;
	class Options;

	/** Base class to export extra tags in max.*/
    class Extra //: public COLLADASW::BaseExtraTechnique
    {

	protected:

		struct ExtraParameter
		{
			/** Type of the parameter. One of the max types TYPE_FLOAT, TYPE_INT, TYPE_BOOL.*/
			int type;
			/** The id of the option to retrieve from the param block.*/
			int paramId;
			/** The name of the parameter, which is equals the elements name in the extra tag.*/
			String paramName;
		};


    public:
		/** The technique profile name use for max specific extra data.*/
		static const String TECHNIQUE_PROFILE_3DSMAX;

		/** The technique profile name used for general extra data.*/
		static const String TECHNIQUE_PROFILE_OPENCOLLADA;

		/** The element name of the element to store user defined properties.*/
		static const String USERDEFINED_PROPERTIES;

    private:
		COLLADASW::StreamWriter* mSW;
		AnimationExporter * mAnimationExporter;
		const Options& mOptions;

		/** The extra technique to fill.*/
		COLLADASW::BaseExtraTechnique* mExtraTechnique;

    public:
        /** Constructor
         @param streamWriter the stream the extra tags should be written to.*/
        Extra ( COLLADASW::StreamWriter * streamWriter, DocumentExporter * documentExporter  );

        /** Destructor*/
        virtual ~Extra()
        {}


    protected:

		/** Sets the extra technique to fill.*/
		void setExtraTechnique( COLLADASW::BaseExtraTechnique* extraTechnique) { mExtraTechnique = extraTechnique; }

		/** Adds a parameter with name @a paramName, value @a value and optional sid @a paramSid to the list 
		of parameters in the max profile.*/
		template<class ValueType> 
		void addExtraParameter ( const String& paramName, const ValueType &value, const String &paramSid="" )
		{
			mExtraTechnique->addExtraTechniqueParameter (TECHNIQUE_PROFILE_3DSMAX , paramName, value, paramSid );
		}


		/** Adds a parameter with name @a paramName, value @a value and optional sid @a paramSid to the list 
		of parameters in the max profile.*/
		template<class ValueType> 
		void addExtraChildParameter ( const String& childName, const String& paramName, const ValueType &value, const String &paramSid="" )
		{
			mExtraTechnique->addExtraTechniqueChildParameter (TECHNIQUE_PROFILE_3DSMAX, childName, paramName, value, paramSid );
		}


		/** Adds an animatable parameter to the list of parameters in the max profile.
		@param parameterName Name of the parameter element. If the parameter is animated, this is also used as sid.
		@param childName The name of the element (child element of the technique element) this parameter should be added to.
		@param parameters The IParamBlock2  that hold all the parameter.
		@param parameterIndex The index of the parameter in the IParamBlock2.
		@param baseId The id of element this extra tag is written to. It is used to reference the parameter and to generate 
		ids for the animation.*/
		void addAnimatedExtraParameter(const String & parameterName, const String& childName, IParamBlock2* parameters, int parameterIndex, const String& baseId);

		/** Adds an animatable parameter to the list of parameters in the max profile.
		@param parameterName Name of the parameter element. If the parameter is animated, this is also used as sid.
		@param childName The name of the element (child element of the technique element) this parameter should be added to.
		@param parameters The IParamBlock  that hold all the parameter.
		@param parameterIndex The index of the parameter in the IParamBlock.
		@param baseId The id of element this extra tag is written to. It is used to reference the parameter and to generate 
		ids for the animation.*/
		void addAnimatedExtraParameter(const String & parameterName, const String& childName, IParamBlock* parameters, int parameterIndex, const String& baseId);

		/** Adds animatable parameters, contained in an IParamBlock, to the max profile of the extra tag. The names of the 
		parameters and and there ids in the IParamBlock must be specified in an array of ExtraParameters.
		@param childElementName The name of the element (child element of the technique element) this parameter should be added to.
		@param extraParameters Pointer to the array of ExtraParameters that hold information for each parameter.
		@param extraParametersCount Number of elements in extraParameters.
		@param paramBlock The IParamBlock  that hold all the parameter.
		@param baseId The id of element this extra tag is written to. It is used to reference the parameter and to generate 
		ids for the animation.*/
		void addParamBlockAnimatedExtraParameters ( const String & childElementName, const ExtraParameter extraParameters[], int extraParametersCount, IParamBlock * paramBlock, const String& baseId );

		/** Adds animatable parameters, contained in an IParamBlock2, to the max profile of the extra tag. The names of the 
		parameters and and there ids in the IParamBlock2 must be specified in an array of ExtraParameters.
		@param childElementName The name of the element (child element of the technique element) this parameter should be added to.
		@param extraParameters Pointer to the array of ExtraParameters that hold information for each parameter.
		@param extraParametersCount Number of elements in extraParameters.
		@param paramBlock The IParamBlock2  that hold all the parameter.
		@param baseId The id of element this extra tag is written to. It is used to reference the parameter and to generate 
		ids for the animation.*/
		void addParamBlockAnimatedExtraParameters ( const String & childElementName, const ExtraParameter extraParameters[], int extraParametersCount, IParamBlock2 * paramBlock, const String& baseId );

		/** Writes all information of the IParamBlock2 @a parameters to the file @a fileName. For development purposes
		only.
		sample usage: if ( extendedParameters ) writeParameterBlockInfo("c:\\temp\\paramters.txt", extendedParameters);
		*/
		void writeParameterBlockInfo(const String& fileName, IParamBlock2* parameters);
		void writeParameterBlockInfo(const String& fileName, IParamBlock* parameters);

    };


}


#endif //__COLLADAMAX_EXTRA_H__

