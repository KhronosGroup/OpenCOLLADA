/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_EXTRA_TECHNIQUE_H__
#define __COLLADASTREAMWRITER_EXTRA_TECHNIQUE_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWTechnique.h"
#include <map>

namespace COLLADASW
{
    //---------------------------------------------------------------
    /** The different parameter types. */
    enum ParamType
    {
        STRING = 0,
        INTEGER,
        DOUBLE,
        FLOAT, 
        BOOL,
        MATRIX
    };


    //---------------------------------------------------------------
    /** Structure with the parameter value. */

    struct ParamData
    {
        String sid;

        String stringValue;
        int integerValue;
        double doubleValue;
        float floatValue;
        bool boolValue;
        double ( *matrix ) [4];

        ParamType paramType;
    };


    //---------------------------------------------------------------
    /** Map with the parameter names and the value */
    typedef std::map<String, ParamData> Parameters;
    typedef std::pair<String, ParamData> Parameter;

    /** The child elements with their parameters under the current profile */
    typedef std::map<String, Parameters> ChildElementsMap;
    typedef std::pair<String, Parameters> ChildElement;

    //---------------------------------------------------------------

    class Profile
    {

    public:
        /** Constructor */
        Profile() {}; //: mParameters(NULL) { mParameters = new Parameters(); }

        /** Destructor */
        virtual ~Profile() {};

        /** A textblock, which contains the full extra technique text. */
        String mText;

        /** The parameters of the current profile */
        Parameters mParameters;

        /** The child elements with their parameters under the current profile */
        ChildElementsMap mChildElements;
    };


    //---------------------------------------------------------------
    /** 
     * The base class, if you want to add extra and technique tags into the derived COLLADASW element. 
     */
    class BaseExtraTechnique
    {

    private:

        /** Map with all names of the techniques to add and the corresponding parameters */
        typedef std::map<String, Profile> ExtraTechniquesMap;
        typedef std::pair<String, Profile> ExtraTechnique;

    protected:

        /** Map with all names of the techniques to add and the corresponding parameters */
        ExtraTechniquesMap mExtraTechniques;

    public:
        /** Constructor */
        BaseExtraTechnique() {};

        /** Destructor */
        virtual ~BaseExtraTechnique() {};

        /**
         * Adds a textblock to the extra profile, which contains the full extra technique text.
         */
        void addExtraTechniqueTextblock ( const String& profileName, const String& text );

        /**
        * Creates an extra and a technique tag with the profile name (if not already exist)
        * and writes the given parameter in the tags.
        */
        void addExtraTechniqueParameter ( const String& profileName, const String& paramName, const String &value="", const String &paramSid="" );
        void addExtraTechniqueParameter ( const String& profileName, const String& paramName, const int &value, const String &paramSid="" );
        void addExtraTechniqueParameter ( const String& profileName, const String& paramName, const double &value, const String &paramSid="" );
        void addExtraTechniqueParameter ( const String& profileName, const String& paramName, const float &value, const String &paramSid="" );
        void addExtraTechniqueParameter ( const String& profileName, const String& paramName, const bool &value, const String &paramSid="" );

        /** Adds a child element under the given profile. */
        void addExtraTechniqueChildParameter ( const String& profileName, const String& childName, const String& paramName, const String &value="", const String &paramSid="" );
        void addExtraTechniqueChildParameter ( const String& profileName, const String& childName, const String& paramName, const int &value, const String &paramSid="" );
        void addExtraTechniqueChildParameter ( const String& profileName, const String& childName, const String& paramName, const double &value, const String &paramSid="" );
        void addExtraTechniqueChildParameter ( const String& profileName, const String& childName, const String& paramName, const float &value, const String &paramSid="" );
        void addExtraTechniqueChildParameter ( const String& profileName, const String& childName, const String& paramName, const bool &value, const String &paramSid="" );
        void addExtraTechniqueChildParameter ( const String& profileName, const String& childName, const String& paramName, double matrix[][4], const String &paramSid="" );

        /** Writes the extra techniques of the texture in the COLLADASW file. */
        void addExtraTechniques ( StreamWriter* streamWriter ) const;

    private:

        /** Adds the parameters in the list to the given technique tag. */
        void addTechniqueParameters ( COLLADASW::Technique &colladaTechnique, const Parameters &parameters ) const;

        /** Returns the profile with the given name.
        Gets the current profile from the map or create a new one. */
        Profile& getProfile ( const String& profileName );

        /** Returns the child element of the list with the given name.
        Gets the current child element from the map or create a new one. */
        Parameters& getChildParameters ( ChildElementsMap& childElements, const String& childName );

    };

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_EXTRA_TECHNIQUE_H__

