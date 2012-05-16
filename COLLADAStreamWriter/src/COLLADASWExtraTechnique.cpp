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
        const String &paramSid )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.stringValue = value;
        paramValue.paramType = STRING;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( 
        const String& profileName,
        const String& childName,
        const String& paramName,
        const String &value, 
        const String &paramSid )
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

        // Add the given parameter into the parameter list of the child element
        childParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter ( 
        const String& profileName,
        const String& paramName,
        const int &value, 
        const String &paramSid )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.integerValue = value;
        paramValue.paramType = INTEGER;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( 
        const String& profileName,
        const String& childName,
        const String& paramName,
        const int &value, 
        const String &paramSid )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Get the current childElement from the map or create a new one.
        Parameters& childParameters = getChildParameters ( profile.mChildElements, childName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.integerValue = value;
        paramValue.paramType = INTEGER;

        // Add the given parameter into the parameter list of the child element
        childParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter ( 
        const String& profileName,
        const String& paramName,
        const double &value, 
        const String &paramSid )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.doubleValue = value;
        paramValue.paramType = DOUBLE;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( 
        const String& profileName,
        const String& childName,
        const String& paramName,
        const double &value, 
        const String &paramSid )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Get the current childElement from the map or create a new one.
        Parameters& childParameters = getChildParameters ( profile.mChildElements, childName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.doubleValue = value;
        paramValue.paramType = DOUBLE;

        // Add the given parameter into the parameter list of the child element
        childParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter ( 
        const String& profileName,
        const String& paramName,
        const float &value, 
        const String &paramSid )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.floatValue = value;
        paramValue.paramType = FLOAT;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( 
        const String& profileName,
        const String& childName,
        const String& paramName,
        const float &value, 
        const String &paramSid )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Get the current childElement from the map or create a new one.
        Parameters& childParameters = getChildParameters ( profile.mChildElements, childName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.floatValue = value;
        paramValue.paramType = FLOAT;

        // Add the given parameter into the parameter list of the child element
        childParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter ( 
        const String& profileName,
        const String& paramName,
        const bool &value, 
        const String &paramSid )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Create the value
        ParamData paramValue;
        paramValue.sid = paramSid;
        paramValue.boolValue = value;
        paramValue.paramType = BOOL;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( 
        const String& profileName,
        const String& childName,
        const String& paramName,
        const bool &value, 
        const String &paramSid )
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

        // Add the given parameter into the parameter list of the child element
        childParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( 
        const String& profileName,
        const String& childName,
        const String& paramName,
        double matrix[][4], 
        const String &paramSid )
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

        // Add the given parameter into the parameter list of the child element
        childParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniques ( StreamWriter* streamWriter ) const
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

                // Write the parameters for the current profile
                addTechniqueParameters ( colladaTechnique, profile.mParameters );

                // Write the child elements
                const ChildElementsMap& childElements = profile.mChildElements;
                ChildElementsMap::const_iterator childIt = childElements.begin();
                while ( childIt != childElements.end() )
                {
                    const String childElementName = ( *childIt ).first;
                    colladaTechnique.addChildElement ( childElementName );

                    addTechniqueParameters ( colladaTechnique, ( *childIt ).second );

                    colladaTechnique.closeChildElement ( childElementName );

                    ++childIt;
                }

                colladaTechnique.closeTechnique();

                // Get the next element
                ++extraTechniquesIt;
            }

            colladaExtra.closeExtra();
        }
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addTechniqueParameters ( 
        COLLADASW::Technique &colladaTechnique,
        const Parameters &parameters ) const
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
                colladaTechnique.addParameter ( paramName, paramData.stringValue, paramData.sid );
                break;

            case INTEGER:
                colladaTechnique.addParameter ( paramName, paramData.integerValue, paramData.sid );
                break;

            case DOUBLE:
                colladaTechnique.addParameter ( paramName, paramData.doubleValue, paramData.sid );
                break;

            case FLOAT:
                colladaTechnique.addParameter ( paramName, paramData.floatValue, paramData.sid );
                break;

            case BOOL:
                colladaTechnique.addParameter ( paramName, paramData.boolValue, paramData.sid );
                break;
            }

            // Get the next element
            ++paramsIt;
        }
    }

} //namespace COLLADASW
