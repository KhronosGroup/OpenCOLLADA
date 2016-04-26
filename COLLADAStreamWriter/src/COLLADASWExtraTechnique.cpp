/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWExtra.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    //---------------------------------------------------------------
    Profile& BaseExtraTechnique::getProfile ( const String& profileName )
    {
        // Is the given profile already in the map?
        ExtraTechniquesMap::iterator it = mExtraTechniques.find ( profileName );

        if ( it == mExtraTechniques.end() )
            mExtraTechniques.insert ( ExtraTechnique ( profileName, Profile() ) );

        it = mExtraTechniques.find ( profileName );
        if ( it == mExtraTechniques.end() ) { COLLADABU_ASSERT ( "Could not create a profile" ); }

        return ( *it ).second;
    }

    //---------------------------------------------------------------
    Parameters& BaseExtraTechnique::getChildParameters ( 
        ChildElementsMap& childElements,
        const String& childName )
    {
        // Is the given childElement already in the map?
        ChildElementsMap::iterator it = childElements.find ( childName );

        if ( it == childElements.end() )
            childElements.insert ( ChildElement ( childName, Parameters() ) );

        it = childElements.find ( childName );
        if ( it == childElements.end() ) { COLLADABU_ASSERT ( "Can't create a child parameter!" ); }

        return ( *it ).second;
    }

	//---------------------------------------------------------------
	CustomParameters& BaseExtraTechnique::getChildCustomTag(
		ChildCustomTagMap& childElements,
		const String& childName)
	{
		// Is the given childElement already in the map?
		ChildCustomTagMap::iterator it = childElements.find(childName);

		if (it == childElements.end())
			childElements.insert(ChildCustomElement(childName, CustomParameters()));

		it = childElements.find(childName);
		if (it == childElements.end()) { COLLADABU_ASSERT("Can't create a child parameter!"); }

		return (*it).second;
	}


	//---------------------------------------------------------------
	CustomTagData& BaseExtraTechnique::getParentCustomTag(
		ParentCustomTagMap& parentElements,
		const String& ParentName)
	{
		// Is the given childElement already in the map?
		ParentCustomTagMap::iterator it = parentElements.find(ParentName);

		if (it == parentElements.end())
			parentElements.insert(ParentCustomElement(ParentName, CustomTagData()));

		it = parentElements.find(ParentName);
		if (it == parentElements.end()) { COLLADABU_ASSERT("Can't create a child parameter!"); }

		return (*it).second;
	}

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueTextblock ( 
        const String& profileName, 
        const String& text )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Set the textblock.
        profile.mText = text;
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter ( 
        const String& profileName,
        const String& paramName,
        const String& value, 
        const String &paramSid,
		const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.stringValue = value;
        paramValue.paramType = STRING;
		paramValue.tagName = tagName;

        // Insert the value into the parameters map of the current profile.
		profile.mParameters.push_back ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueEnumParameter(
        const String& profileName,
        const String& paramName,
        const String &enumStr,
        const String &paramSid,
        const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile(profileName);

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.stringValue = enumStr;
        paramValue.paramType = ENUM;
        paramValue.tagName = tagName;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.push_back(Parameter(paramName, paramValue));
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( 
        const String& profileName,
        const String& childName,
        const String& paramName,
        const String &value, 
        const String &paramSid,
		const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Get the list of child elements of the current profile
        ChildElementsMap& childElements = profile.mChildElements;

        // Get the current childElement from the map or create a new one.
        Parameters& childParameters = getChildParameters ( childElements, childName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.stringValue = value;
        paramValue.paramType = STRING;
		paramValue.tagName = tagName;

        // Add the given parameter into the parameter list of the child element
        childParameters.push_back ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
	void BaseExtraTechnique::addExtraTechniqueParameter(
		const String& profileName,
		const String& paramName,
		const int &value,
		const String &paramSid,
		const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.integerValue[0] = value;
        paramValue.paramType = INTEGER;
		paramValue.tagName = tagName;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.push_back ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter(
        const String& profileName,
        const String& paramName,
        const int &value0,
        const int &value1,
        const String &paramSid,
        const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile(profileName);

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.integerValue[0] = value0;
        paramValue.integerValue[1] = value1;
        paramValue.paramType = INTEGER2;
        paramValue.tagName = tagName;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.push_back(Parameter(paramName, paramValue));
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter(
        const String& profileName,
        const String& paramName,
        const int &value0,
        const int &value1,
        const int &value2,
        const String &paramSid,
        const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile(profileName);

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.integerValue[0] = value0;
        paramValue.integerValue[1] = value1;
        paramValue.integerValue[2] = value2;
        paramValue.paramType = INTEGER3;
        paramValue.tagName = tagName;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.push_back(Parameter(paramName, paramValue));
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( 
        const String& profileName,
        const String& childName,
        const String& paramName,
        const int &value, 
        const String &paramSid,
		const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Get the current childElement from the map or create a new one.
        Parameters& childParameters = getChildParameters ( profile.mChildElements, childName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.integerValue[0] = value;
        paramValue.paramType = INTEGER;
		paramValue.tagName = tagName;

        // Add the given parameter into the parameter list of the child element
        childParameters.push_back( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter ( 
        const String& profileName,
        const String& paramName,
        const double &value, 
        const String &paramSid,
		const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.doubleValue[0] = value;
        paramValue.paramType = DOUBLE;
		paramValue.tagName = tagName;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.push_back( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter(
        const String& profileName,
        const String& paramName,
        const double &value0,
        const double &value1,
        const String &paramSid,
        const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile(profileName);

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.doubleValue[0] = value0;
        paramValue.doubleValue[1] = value1;
        paramValue.paramType = DOUBLE2;
        paramValue.tagName = tagName;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.push_back(Parameter(paramName, paramValue));
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter(
        const String& profileName,
        const String& paramName,
        const double &value0,
        const double &value1,
        const double &value2,
        const String &paramSid,
        const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile(profileName);

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.doubleValue[0] = value0;
        paramValue.doubleValue[1] = value1;
        paramValue.doubleValue[2] = value2;
        paramValue.paramType = DOUBLE3;
        paramValue.tagName = tagName;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.push_back(Parameter(paramName, paramValue));
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter(
        const String& profileName,
        const String& paramName,
        const double &value0,
        const double &value1,
        const double &value2,
        const double &value3,
        const String &paramSid,
        const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile(profileName);

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.doubleValue[0] = value0;
        paramValue.doubleValue[1] = value1;
        paramValue.doubleValue[2] = value2;
        paramValue.doubleValue[3] = value3;
        paramValue.paramType = DOUBLE4;
        paramValue.tagName = tagName;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.push_back(Parameter(paramName, paramValue));
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( 
        const String& profileName,
        const String& childName,
        const String& paramName,
        const double &value, 
        const String &paramSid,
		const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Get the current childElement from the map or create a new one.
        Parameters& childParameters = getChildParameters ( profile.mChildElements, childName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.doubleValue[0] = value;
        paramValue.paramType = DOUBLE;
		paramValue.tagName = tagName;

        // Add the given parameter into the parameter list of the child element
        childParameters.push_back(Parameter(paramName, paramValue));
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter ( 
        const String& profileName,
        const String& paramName,
        const float &value, 
        const String &paramSid,
		const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.floatValue[0] = value;
        paramValue.paramType = FLOAT;
		paramValue.tagName = tagName;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.push_back(Parameter(paramName, paramValue));
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter(
        const String& profileName,
        const String& paramName,
        const float &value0,
        const float &value1,
        const String &paramSid,
        const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile(profileName);

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.floatValue[0] = value0;
        paramValue.floatValue[1] = value1;
        paramValue.paramType = FLOAT2;
        paramValue.tagName = tagName;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.push_back(Parameter(paramName, paramValue));
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter(
        const String& profileName,
        const String& paramName,
        const float &value0,
        const float &value1,
        const float &value2,
        const String &paramSid,
        const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile(profileName);

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.floatValue[0] = value0;
        paramValue.floatValue[1] = value1;
        paramValue.floatValue[2] = value2;
        paramValue.paramType = FLOAT3;
        paramValue.tagName = tagName;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.push_back(Parameter(paramName, paramValue));
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( 
        const String& profileName,
        const String& childName,
        const String& paramName,
        const float &value, 
        const String &paramSid,
		const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Get the current childElement from the map or create a new one.
        Parameters& childParameters = getChildParameters ( profile.mChildElements, childName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.floatValue[0] = value;
        paramValue.paramType = FLOAT;
		paramValue.tagName = tagName;

        // Add the given parameter into the parameter list of the child element
        childParameters.push_back(Parameter(paramName, paramValue));
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter ( 
        const String& profileName,
        const String& paramName,
        const bool &value, 
        const String &paramSid,
		const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.boolValue = value;
        paramValue.paramType = BOOL;
		paramValue.tagName = tagName;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.push_back(Parameter(paramName, paramValue));
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( 
        const String& profileName,
        const String& childName,
        const String& paramName,
        const bool &value, 
        const String &paramSid,
		const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Get the current childElement from the map or create a new one.
        Parameters& childParameters = getChildParameters ( profile.mChildElements, childName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.boolValue = value;
        paramValue.paramType = BOOL;
		paramValue.tagName = tagName;

        // Add the given parameter into the parameter list of the child element
        childParameters.push_back(Parameter(paramName, paramValue));
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( 
        const String& profileName,
        const String& childName,
        const String& paramName,
        double matrix[][4], 
        const String &paramSid,
		const String& tagName)
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Get the current childElement from the map or create a new one.
        Parameters& childParameters = getChildParameters ( profile.mChildElements, childName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.matrix = matrix;
        paramValue.paramType = MATRIX;
		paramValue.tagName = tagName;

        // Add the given parameter into the parameter list of the child element
        childParameters.push_back(Parameter(paramName, paramValue));
    }

    //---------------------------------------------------------------
	void BaseExtraTechnique::addExtraTechniqueElement(const String& profileName, const String& tagName, const String& attributeName, const String& attributeValue)
    {
        Profile& profile = getProfile(profileName);

        CustomTagData customTagData;
        customTagData.attributeName = attributeName;
        customTagData.attributeValue = attributeValue;

        profile.mCustomTags.insert(CustomTag(tagName, customTagData));
    }


	//---------------------------------------------------------------
	void BaseExtraTechnique::addExtraTechniqueParentElement(
		const String& profileName,
		const String& tagName,
		const String& attributeName,
		const String& attributeValue)
	{
		// Get the current Profile from the map or create a new one.
		Profile& profile = getProfile(profileName);

		CustomTagData& parentParameter = getParentCustomTag(profile.mParentCustomTags, tagName);

		if (!attributeName.empty())
			parentParameter.attributeName = attributeName;
		
		if (!attributeValue.empty())
			parentParameter.attributeValue = attributeValue;

		// Get the current childElement from the map or create a new one.
		getChildCustomTag(profile.mChildCustomTags, tagName);
	}

	//---------------------------------------------------------------
	void BaseExtraTechnique::addExtraTechniqueChildElement(const String& profileName, const String& ParentTagName, const String& childTagName, const float& childAttributeValue)
	{
		Profile& profile = getProfile(profileName);

		// Get the current childElement from the map or create a new one.
		CustomParameters& childParameter = getChildCustomTag(profile.mChildCustomTags, ParentTagName);

		CustomParamData customTagData;
		customTagData.floatValue = childAttributeValue;

		childParameter.push_back(CustomParameter(childTagName, customTagData));
	}

	//---------------------------------------------------------------
	void BaseExtraTechnique::addExtraTechniqueChildElement(const String& profileName, const String& ParentTagName, const String& childTagName, const String& childAttributeValue)
	{
		Profile& profile = getProfile(profileName);

		// Get the current childElement from the map or create a new one.
		CustomParameters& childParameter = getChildCustomTag(profile.mChildCustomTags, ParentTagName);

		CustomParamData customTagData;
		customTagData.stringValue = childAttributeValue;

		childParameter.push_back(CustomParameter(childTagName, customTagData));
	}


    //---------------------------------------------------------------
	void BaseExtraTechnique::addExtraTechniques(StreamWriter* streamWriter) const
    {
        if ( !mExtraTechniques.empty() )
        {
            // Open the extra tag
            COLLADASW::Extra colladaExtra ( streamWriter );
            colladaExtra.openExtra();

            // Go through every extra-technique (for the different profiles)
            ExtraTechniquesMap::const_iterator extraTechniquesIt = mExtraTechniques.begin();
            while ( extraTechniquesIt != mExtraTechniques.end() )
            {
                // Write the current technique profile
                COLLADASW::Technique colladaTechnique ( streamWriter );

                const String profileName = ( *extraTechniquesIt ).first;
                colladaTechnique.openTechnique ( profileName );

                // Write the current profile
                const Profile& profile = ( *extraTechniquesIt ).second;

                // Write the textblock.
                streamWriter->appendTextBlock ( profile.mText );

                // Write custom tags
                addCustomTags(colladaTechnique, profile.mCustomTags);

                // Write the parameters for the current profile
				addTechniqueParameters(colladaTechnique, profile.mParameters);

                // Write the child elements
                const ChildElementsMap& childElements = profile.mChildElements;
                ChildElementsMap::const_iterator childIt = childElements.begin();
                while ( childIt != childElements.end() )
                {
                    const String childElementName = ( *childIt ).first;
                    colladaTechnique.addChildElement ( childElementName );
					
					addTechniqueParameters(colladaTechnique, (*childIt).second);

                    colladaTechnique.closeChildElement ( childElementName );

                    ++childIt;
                }

				// Write the Custom child elements
				const ChildCustomTagMap& childCustomTags = profile.mChildCustomTags;
				const ParentCustomTagMap& parentCustomTags = profile.mParentCustomTags;

				ChildCustomTagMap::const_iterator childCustomIt = childCustomTags.begin();
				while (childCustomIt != childCustomTags.end())
				{
					const String childElementName = (*childCustomIt).first;

					ParentCustomTagMap::const_iterator it = parentCustomTags.find(childElementName);
					if (it != parentCustomTags.end())
						colladaTechnique.addCustomChildElement(childElementName, it->second.attributeName, it->second.attributeValue);

					addTechniqueParameters(colladaTechnique, (*childCustomIt).second);
					
					colladaTechnique.closeChildElement(childElementName);

					++childCustomIt;
				}


                colladaTechnique.closeTechnique();

                // Get the next element
                ++extraTechniquesIt;
            }

            colladaExtra.closeExtra();
        }
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addCustomTags(COLLADASW::Technique & technique, const CustomTags & customTags) const
    {
        for (CustomTags::const_iterator it = customTags.begin(); it != customTags.end(); ++it)
        {
            const String & tagName = it->first;
            const CustomTagData & customTagData = it->second;
            technique.addElement(tagName, customTagData.attributeName, customTagData.attributeValue);
        }
    }

	//---------------------------------------------------------------
	void BaseExtraTechnique::addTechniqueParameters(COLLADASW::Technique & colladaTechnique, const CustomParameters &parameters) const
	{
		for (CustomParameters::const_iterator it = parameters.begin(); it != parameters.end(); ++it)
		{
			const String & tagName = it->first;
			const CustomParamData & paramData = it->second;
			
			if (!paramData.stringValue.empty())
				colladaTechnique.addElement(tagName, paramData.stringValue);
			else
				colladaTechnique.addElement(tagName, paramData.floatValue);
		}
	}

    //---------------------------------------------------------------
    void BaseExtraTechnique::addTechniqueParameters ( 
        COLLADASW::Technique &colladaTechnique,
        const Parameters &parameters) const
    {
        Parameters::const_iterator paramsIt = parameters.begin();
        while ( paramsIt != parameters.end() )
        {
            // Add this parameter
            String paramName = ( *paramsIt ).first;
            ParamData paramData = ( *paramsIt ).second;

            switch ( paramData.paramType )
            {

            case STRING:
				colladaTechnique.addParameter(paramName, paramData.stringValue, paramData.sid, CSWC::VALUE_TYPE_STRING, paramData.tagName);
				break;

            case INTEGER:
                colladaTechnique.addParameter(paramName, paramData.integerValue[0], paramData.sid, CSWC::CSW_VALUE_TYPE_INT, paramData.tagName);
                break;

            case INTEGER2:
                colladaTechnique.addParameter(paramName, paramData.integerValue[0], paramData.integerValue[1], paramData.sid, CSWC::CSW_VALUE_TYPE_INT2, paramData.tagName);
                break;

            case INTEGER3:
                colladaTechnique.addParameter(paramName, paramData.integerValue[0], paramData.integerValue[1], paramData.integerValue[2], paramData.sid, CSWC::CSW_VALUE_TYPE_INT3, paramData.tagName);
                break;

            case DOUBLE:
				colladaTechnique.addParameter(paramName, paramData.doubleValue[0], paramData.sid, CSWC::CSW_VALUE_TYPE_DOUBLE, paramData.tagName);
                break;

            case DOUBLE2:
                colladaTechnique.addParameter(paramName, paramData.doubleValue[0], paramData.doubleValue[1], paramData.sid, CSWC::CSW_VALUE_TYPE_DOUBLE2, paramData.tagName);
                break;

            case DOUBLE3:
                colladaTechnique.addParameter(paramName, paramData.doubleValue[0], paramData.doubleValue[1], paramData.doubleValue[2], paramData.sid, CSWC::CSW_VALUE_TYPE_DOUBLE3, paramData.tagName);
                break;

            case DOUBLE4:
                colladaTechnique.addParameter(paramName, paramData.doubleValue[0], paramData.doubleValue[1], paramData.doubleValue[2], paramData.doubleValue[3], paramData.sid, CSWC::CSW_VALUE_TYPE_DOUBLE4, paramData.tagName);
                break;

            case FLOAT:
				colladaTechnique.addParameter(paramName, paramData.floatValue[0], paramData.sid, CSWC::CSW_VALUE_TYPE_FLOAT, paramData.tagName);
                break;

            case FLOAT2:
                colladaTechnique.addParameter(paramName, paramData.floatValue[0], paramData.floatValue[1], paramData.sid, CSWC::CSW_VALUE_TYPE_FLOAT2, paramData.tagName);
                break;

            case FLOAT3:
                colladaTechnique.addParameter(paramName, paramData.floatValue[0], paramData.floatValue[1], paramData.floatValue[2], paramData.sid, CSWC::CSW_VALUE_TYPE_FLOAT3, paramData.tagName);
                break;

            case BOOL:
				colladaTechnique.addParameter(paramName, paramData.boolValue, paramData.sid, CSWC::VALUE_TYPE_BOOL, paramData.tagName);
                break;

            case ENUM:
                colladaTechnique.addParameter(paramName, paramData.stringValue, paramData.sid, "enum", paramData.tagName);
                break;
            }

            // Get the next element
            ++paramsIt;
        }
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::flushAllTechniques()
    {
      mExtraTechniques.clear();
    }

} //namespace COLLADASW
