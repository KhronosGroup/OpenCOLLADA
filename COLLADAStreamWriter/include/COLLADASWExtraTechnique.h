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

	class Technique;

    //---------------------------------------------------------------
    /** The different parameter types. */
    enum ParamType
    {
        STRING = 0,
        INTEGER,
        INTEGER2,
        INTEGER3,
        DOUBLE,
        DOUBLE2,
        DOUBLE3,
        DOUBLE4,
        FLOAT,
        FLOAT2,
        FLOAT3,
        BOOL,
        MATRIX,
        ENUM
    };

	
	

    //---------------------------------------------------------------
    /** Structure with the parameter value. */

	struct ParamData
    {
		String sid;

        String stringValue;
        int integerValue[3];
        double doubleValue[4];
        float floatValue[3];
        bool boolValue;
        double ( *matrix ) [4];

        ParamType paramType;
		String tagName;

	};

    struct CustomTagData
    {
        String attributeName;
        String attributeValue;
    };

	struct CustomTagData2
	{
		//String attributeName;
		float attributeValue;
	};


    //---------------------------------------------------------------
    /** Map with the parameter names and the value */
    typedef std::pair<String, ParamData> Parameter;
    typedef std::vector<Parameter> Parameters;

    /** The child elements with their parameters under the current profile */
    typedef std::map<String, Parameters> ChildElementsMap;
    typedef std::pair<String, Parameters> ChildElement;


//	typedef std::pair<String, CustomTagData> CustomParameter;
//	typedef std::vector<CustomParameter> CustomParameters;

	typedef std::map<String, CustomTagData> ChildCustomTagMap;
	typedef std::pair<String, CustomTagData> ChildCustomElement;


    typedef std::map<String, CustomTagData> CustomTags;
    typedef std::pair<String, CustomTagData> CustomTag;

	typedef std::map<String, CustomTagData2> CustomTags2;
	typedef std::pair<String, CustomTagData2> CustomTag2;

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

		ChildCustomTagMap mChildCustomTags;

        CustomTags mCustomTags;

		CustomTags2 mCustomTags2;
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
         * Reinitialize to blank
         */
        void flushAllTechniques ( );

        /**
         * Adds a textblock to the extra profile, which contains the full extra technique text.
         */
        void addExtraTechniqueTextblock ( const String& profileName, const String& text );

        /**
        * Creates an extra and a technique tag with the profile name (if not already exist)
        * and writes the given parameter in the tags.
        */
		void addExtraTechniqueParameter(const String& profileName, const String& paramName, const String &value = "", const String &paramSid = "", const String& tagName = "");
		void addExtraTechniqueParameter(const String& profileName, const String& paramName, const int &value, const String &paramSid = "", const String& tagName = "");
        void addExtraTechniqueParameter(const String& profileName, const String& paramName, const int &value0, const int &value1, const String &paramSid = "", const String& tagName = "");
        void addExtraTechniqueParameter(const String& profileName, const String& paramName, const int &value0, const int &value1, const int &value2, const String &paramSid = "", const String& tagName = "");
		void addExtraTechniqueParameter(const String& profileName, const String& paramName, const double &value, const String &paramSid = "", const String& tagName = "");
        void addExtraTechniqueParameter(const String& profileName, const String& paramName, const double &value0, const double &value1, const String &paramSid = "", const String& tagName = "");
        void addExtraTechniqueParameter(const String& profileName, const String& paramName, const double &value0, const double &value1, const double &value2, const String &paramSid = "", const String& tagName = "");
        void addExtraTechniqueParameter(const String& profileName, const String& paramName, const double &value0, const double &value1, const double &value2, const double &value3, const String &paramSid = "", const String& tagName = "");
		void addExtraTechniqueParameter(const String& profileName, const String& paramName, const float &value, const String &paramSid = "", const String& tagName = "");
        void addExtraTechniqueParameter(const String& profileName, const String& paramName, const float &value0, const float &value1, const String &paramSid = "", const String& tagName = "");
        void addExtraTechniqueParameter(const String& profileName, const String& paramName, const float &value0, const float &value1, const float &value2, const String &paramSid = "", const String& tagName = "");
		void addExtraTechniqueParameter(const String& profileName, const String& paramName, const bool &value, const String &paramSid = "", const String& tagName = "");
        void addExtraTechniqueEnumParameter(const String& profileName, const String& paramName, const String &enumStr = "", const String &paramSid = "", const String& tagName = "");

        /** Adds a child element under the given profile. */
		void addExtraTechniqueChildParameter(const String& profileName, const String& childName, const String& paramName, const String &value = "", const String &paramSid = "", const String& tagName = "");
		void addExtraTechniqueChildParameter(const String& profileName, const String& childName, const String& paramName, const int &value, const String &paramSid = "", const String& tagName = "");
		void addExtraTechniqueChildParameter(const String& profileName, const String& childName, const String& paramName, const double &value, const String &paramSid = "", const String& tagName = "");
		void addExtraTechniqueChildParameter(const String& profileName, const String& childName, const String& paramName, const float &value, const String &paramSid = "", const String& tagName = "");
		void addExtraTechniqueChildParameter(const String& profileName, const String& childName, const String& paramName, const bool &value, const String &paramSid = "", const String& tagName = "");
		void addExtraTechniqueChildParameter(const String& profileName, const String& childName, const String& paramName, double matrix[][4], const String &paramSid = "", const String& tagName = "");

        void addExtraTechniqueElement(const String& profileName, const String& tagName, const String& attributeName, const String& attributeValue);
		void addExtraTechniqueElement(const String& profileName, const String& tagName, const float& attributeValue);

		void addExtraTechniqueChildCustomTag(const String& profileName, const String& tagName, const String& attributeName, const String& attributeValue);
		void addExtraTechniques(StreamWriter* streamWriter) const;

    private:

        void addCustomTags(COLLADASW::Technique & technique, const CustomTags & customTags) const;
		void addCustomTags2(COLLADASW::Technique & technique, const CustomTags2 & customTags) const;

        /** Adds the parameters in the list to the given technique tag. */
		void addTechniqueParameters(COLLADASW::Technique &colladaTechnique, const Parameters &parameters) const;

        /** Returns the profile with the given name.
        Gets the current profile from the map or create a new one. */
        Profile& getProfile ( const String& profileName );

        /** Returns the child element of the list with the given name.
        Gets the current child element from the map or create a new one. */
        Parameters& getChildParameters ( ChildElementsMap& childElements, const String& childName );
		CustomTagData& getChildCustomTag(ChildCustomTagMap& childElements, const String& childName);

    };

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_EXTRA_TECHNIQUE_H__

