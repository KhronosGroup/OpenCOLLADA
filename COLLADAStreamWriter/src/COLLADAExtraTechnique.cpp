/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#include "COLLADAStreamWriter.h"
#include "COLLADAExtraTechnique.h"
#include "COLLADAExtra.h"
#include "COLLADASWC.h"
#include "assert.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    Profile& BaseExtraTechnique::getProfile ( const String& profileName )
    {
        // Is the given profile already in the map?
        ExtraTechniquesMap::iterator it = mExtraTechniques.find ( profileName );

        if ( it == mExtraTechniques.end() )
            mExtraTechniques.insert ( ExtraTechnique ( profileName, Profile() ) );

        it = mExtraTechniques.find ( profileName );

        if ( it == mExtraTechniques.end() ) assert ( "Could not create a profile" );

        return ( *it ).second;
    }

    //---------------------------------------------------------------
    Parameters& BaseExtraTechnique::getChildParameters ( ChildElementsMap& childElements,
            const String& childName )
    {
        // Is the given childElement already in the map?
        ChildElementsMap::iterator it = childElements.find ( childName );

        if ( it == childElements.end() )
            childElements.insert ( ChildElement ( childName, Parameters() ) );

        it = childElements.find ( childName );

        if ( it == childElements.end() ) assert ( "Can't create a child parameter!" );

        return ( *it ).second;
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter ( const String& profileName,
            const String& paramName,
            const String& value )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Create the value
        ParamValue paramValue;
        paramValue.stringValue = value;
        paramValue.paramType = STRING;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( const String& profileName,
            const String& childName,
            const String& paramName,
            const String &value )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Get the list of child elements of the current profile
        ChildElementsMap& childElements = profile.mChildElements;

        // Get the current childElement from the map or create a new one.
        Parameters& childParameters = getChildParameters ( childElements, childName );

        // Create the value
        ParamValue paramValue;
        paramValue.stringValue = value;
        paramValue.paramType = STRING;

        // Add the given parameter into the parameter list of the child element
        childParameters.insert ( Parameter ( childName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter ( const String& profileName,
            const String& paramName,
            const int &value )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Create the value
        ParamValue paramValue;
        paramValue.integerValue = value;
        paramValue.paramType = INTEGER;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( const String& profileName,
            const String& childName,
            const String& paramName,
            const int &value )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Get the current childElement from the map or create a new one.
        Parameters& childParameters = getChildParameters ( profile.mChildElements, childName );

        // Create the value
        ParamValue paramValue;
        paramValue.integerValue = value;
        paramValue.paramType = INTEGER;

        // Add the given parameter into the parameter list of the child element
        childParameters.insert ( Parameter ( childName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter ( const String& profileName,
            const String& paramName,
            const double &value )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Create the value
        ParamValue paramValue;
        paramValue.doubleValue = value;
        paramValue.paramType = DOUBLE;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( const String& profileName,
            const String& childName,
            const String& paramName,
            const double &value )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Get the current childElement from the map or create a new one.
        Parameters& childParameters = getChildParameters ( profile.mChildElements, childName );

        // Create the value
        ParamValue paramValue;
        paramValue.doubleValue = value;
        paramValue.paramType = DOUBLE;

        // Add the given parameter into the parameter list of the child element
        childParameters.insert ( Parameter ( childName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueParameter ( const String& profileName,
            const String& paramName,
            const bool &value )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Create the value
        ParamValue paramValue;
        paramValue.boolValue = value;
        paramValue.paramType = BOOL;

        // Insert the value into the parameters map of the current profile.
        profile.mParameters.insert ( Parameter ( paramName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( const String& profileName,
            const String& childName,
            const String& paramName,
            const bool &value )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Get the current childElement from the map or create a new one.
        Parameters& childParameters = getChildParameters ( profile.mChildElements, childName );

        // Create the value
        ParamValue paramValue;
        paramValue.boolValue = value;
        paramValue.paramType = BOOL;

        // Add the given parameter into the parameter list of the child element
        childParameters.insert ( Parameter ( childName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addExtraTechniqueChildParameter ( const String& profileName,
            const String& childName,
            const String& paramName,
            double matrix[][4] )
    {
        // Get the current Profile from the map or create a new one.
        Profile& profile = getProfile ( profileName );

        // Get the current childElement from the map or create a new one.
        Parameters& childParameters = getChildParameters ( profile.mChildElements, childName );

        // Create the value
        ParamValue paramValue;
        paramValue.matrix = matrix;
        paramValue.paramType = MATRIX;

        // Add the given parameter into the parameter list of the child element
        childParameters.insert ( Parameter ( childName, paramValue ) );
    }

    //---------------------------------------------------------------
    void BaseExtraTechnique::addTextureExtraTechniques ( StreamWriter &streamWriter ) const
    {
        if ( !mExtraTechniques.empty() )
        {
            // Open the extra tag
            COLLADA::Extra colladaExtra ( &streamWriter );
            colladaExtra.openExtra();

            // Go through every extra-technique (for the different profiles)
            ExtraTechniquesMap::const_iterator extraTechniquesIt = mExtraTechniques.begin();

            while ( extraTechniquesIt != mExtraTechniques.end() )
            {
                // Write the current technique profile
                COLLADA::Technique colladaTechnique ( &streamWriter );

                const String profileName = ( *extraTechniquesIt ).first;
                colladaTechnique.openTechnique ( profileName );

                // Write the current profile
                const Profile& profile = ( *extraTechniquesIt ).second;

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
    void BaseExtraTechnique::addTechniqueParameters ( COLLADA::Technique &colladaTechnique,
            const Parameters &parameters ) const
    {
        Parameters::const_iterator paramsIt = parameters.begin();

        while ( paramsIt != parameters.end() )
        {
            // Add this parameter
            String paramName = ( *paramsIt ).first;
            ParamValue paramValue = ( *paramsIt ).second;

            switch ( paramValue.paramType )
            {

            case STRING:
                colladaTechnique.addParameter ( paramName, paramValue.stringValue );
                break;

            case INTEGER:
                colladaTechnique.addParameter ( paramName, paramValue.integerValue );
                break;

            case DOUBLE:
                colladaTechnique.addParameter ( paramName, paramValue.doubleValue );
                break;

            case BOOL:
                colladaTechnique.addParameter ( paramName, paramValue.boolValue );
                break;
            }

            // Get the next element
            ++paramsIt;
        }
    }

} //namespace COLLADA
