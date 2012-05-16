/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_PARAM_H__
#define __COLLADAFW_PARAM_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWValueType.h"


namespace COLLADAFW
{

    /** 
     * Declares parametric information for its parent element. 
     * A functional or programmatical format requires a means for users to specify parametric 
     * information. This information represents function parameter (argument) data.
     * Material shader programs may contain code representing vertex or pixel programs. These 
     * programs require parameters as part of their state information.
     * The basic declaration of a parameter describes the name, data type, and value data of the 
     * parameter. That parameter name identifies it to the function or program. The parameter type 
     * indicates the encoding of its value. The <param> element contains information of type 
     * xs:string, which is the parameter�s actual value.
     */
    class Param
    {

    private:

        /**
         * xs:NCName The text string name of this element. Optional.
         */
        String mName;

        /**
         * xs:NCName A text string value containing the subidentifier of this element. 
         * This value must be unique within the scope of the parent element. Optional.
         */
        String mSid;

        /**
         * The type of the value data. This text string must be understood by 
         * the application. Required.
         */
        ValueType::ColladaType mType;

        /**
         *  xs:NMTOKEN The user-defined meaning of the parameter. Optional.
         */
        String mSemantic;

        /**
         * Value data of the parameter. The <param> element contains information of 
         * type xs:string, which is the parameter�s actual value. The parameter type 
         * indicates the encoding of its value.
         */
        //Type mValue;

    public:

        /** Constructor. */
        Param ( const ValueType::ColladaType paramType=ValueType::VALUE_TYPE_UNSPECIFIED ) 
        : mType ( paramType ) 
        {}

        /** Destructor. */
        virtual ~Param () {}

        /**
         * The text string name of this element. Optional.
         * @return const String The text string name of this element. 
         */
        const String getName () const { return mName; }

        /**
         * The text string name of this element. Optional.
         * @param name The text string name of this element.
         */
        void setName ( const String name ) { mName = name; }

        /**
         * A text string value containing the subidentifier of this element. 
         * This value must be unique within the scope of the parent element. Optional.
         * @return const String The subidentifier of this element. 
         */
        const String getSid () const { return mSid; }

        /**
         * A text string value containing the subidentifier of this element. 
         * This value must be unique within the scope of the parent element. Optional.
         * @param sid The subidentifier of this element. 
         */
        void setSid ( const String sid ) { mSid = sid; }

        /**
         * The type of the value data. This text string must be understood by 
         * the application. Required.
         * @return const ValueType::ColladaType The type of the value data.
         */
        const ValueType::ColladaType getType () const { return mType; }

        /**
         * The type of the value data. This text string must be understood by 
         * the application. Required.
         * @param type The type of the value data.
         */
        void setType ( const ValueType::ColladaType type ) { mType = type; }

        /**
         * The user-defined meaning of the parameter. Optional.
         * @return const String The semantic of the parameter.
         */
        const String getSemantic () const { return mSemantic; }

        /**
         * The user-defined meaning of the parameter. Optional.
         * @param semantic The semantic of the parameter.
         */
        void setSemantic ( const String semantic ) { mSemantic = semantic; }

//         /**
//         * Value data of the parameter. The <param> element contains information of 
//         * type xs:string, which is the parameter�s actual value. The parameter type 
//         * indicates the encoding of its value.
//         */
//         template < class Type >
//         const Type getValue () const { return mValue; }
// 
//         /**
//         * Value data of the parameter. The <param> element contains information of 
//         * type xs:string, which is the parameter�s actual value. The parameter type 
//         * indicates the encoding of its value.
//         */
//         template < class Type >
//         void setValue ( const Type Value ) { mValue = Value; }

    };


    /**
     * Typedef for the array of parameters.
     */
    typedef Param* ParamArray;

//    typedef Param < String >* ParamArrayString;
//    typedef Param < class Type >* ParamArray;

}

#endif // __COLLADAFW_PARAM_H__
