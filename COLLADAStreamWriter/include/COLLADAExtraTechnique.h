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


#ifndef __COLLADASTREAMWRITER_EXTRA_TECHNIQUE_H__
#define __COLLADASTREAMWRITER_EXTRA_TECHNIQUE_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include "COLLADATechnique.h"
#include <map>

namespace COLLADA
{
    //---------------------------------------------------------------
    /** The different parameter types. */
    enum ParamType
    {
        STRING = 0,
        INTEGER,
        DOUBLE,
        BOOL,
        MATRIX
    };


    //---------------------------------------------------------------
    /** Structure with the parameter value. */

    struct ParamValue
    {
        String stringValue;
        int integerValue;
        double doubleValue;
        bool boolValue;
        double ( *matrix ) [4];

        ParamType paramType;
    };


    //---------------------------------------------------------------
    /** Map with the parameter names and the value */
    typedef std::map<String, ParamValue> Parameters;
    typedef std::pair<String, ParamValue> Parameter;

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

        /** The parameters of the current profile */
        Parameters mParameters;

        /** The child elements with their parameters under the current profile */
        ChildElementsMap mChildElements;
    };

    /** Map with all names of the techniques to add and the corresponding parameters */
    typedef std::map<String, Profile> ExtraTechniquesMap;
    typedef std::pair<String, Profile> ExtraTechnique;



    //---------------------------------------------------------------
    /** The base class, if you want to add extra and technique tags into the derived COLLADA element. */

    class BaseExtraTechnique
    {

    protected:

        /** Map with all names of the techniques to add and the corresponding parameters */
        ExtraTechniquesMap mExtraTechniques;

    public:
        /** Constructor */
        BaseExtraTechnique() {};

        /** Destructor */
        virtual ~BaseExtraTechnique() {};

        /**
        * Creates an extra and a technique tag with the profile name (if not already exist)
        * and writes the given parameter in the tags.
        */
        void addExtraTechniqueParameter ( const String& profileName, const String& paramName, const String &value="" );
        void addExtraTechniqueParameter ( const String& profileName, const String& paramName, const int &value );
        void addExtraTechniqueParameter ( const String& profileName, const String& paramName, const double &value );
        void addExtraTechniqueParameter ( const String& profileName, const String& paramName, const bool &value );

        /** Adds a child element under the given profile. */
        void addExtraTechniqueChildParameter ( const String& profileName, const String& childName, const String& paramName, const String &value="" );
        void addExtraTechniqueChildParameter ( const String& profileName, const String& childName, const String& paramName, const int &value );
        void addExtraTechniqueChildParameter ( const String& profileName, const String& childName, const String& paramName, const double &value );
        void addExtraTechniqueChildParameter ( const String& profileName, const String& childName, const String& paramName, const bool &value );
        void addExtraTechniqueChildParameter ( const String& profileName, const String& childName, const String& paramName, double matrix[][4] );

        /** Returns the map with the extra techniques. */
        const ExtraTechniquesMap& getExtraTechniques()
        {
            return mExtraTechniques;
        }

        /** Writes the extra techniques of the texture in the COLLADA file. */
        void addTextureExtraTechniques ( StreamWriter &streamWriter ) const;

    private:

        /** Adds the parameters in the list to the given technique tag. */
        void addTechniqueParameters ( COLLADA::Technique &colladaTechnique, const Parameters &parameters ) const;

        /** Returns the profile with the given name.
        Gets the current profile from the map or create a new one. */
        Profile& getProfile ( const String& profileName );

        /** Returns the child element of the list with the given name.
        Gets the current child element from the map or create a new one. */
        Parameters& getChildParameters ( ChildElementsMap& childElements, const String& childName );

    };

} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_EXTRA_TECHNIQUE_H__

