/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_PARAM_TEMPLATE_H__
#define __COLLADASTREAMWRITER_PARAM_TEMPLATE_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAParamBase.h"
#include "COLLADAAnnotation.h"
#include "COLLADAValueType.h"
#include "COLLADASampler.h"
#include "COLLADASurface.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    /** A class to add a param to the stream.*/
    template < const String& paramName, class ClassType, ValueType::ColladaType paramType=ValueType::VALUE_TYPE_UNSPECIFIED >
    class BaseParamTemplate : public ParamBase
    {

    public:

        /** Constructor
        @param streamWriter The stream the asset should be written to.*/
        BaseParamTemplate ( StreamWriter* streamWriter ) 
        : ParamBase ( streamWriter, paramName, paramType ) {}

        /** Destructor*/
        virtual ~BaseParamTemplate() {}
    };

    /** A class to add a <newparam> to the stream.*/
    template < class Type, const ValueType::ColladaType paramType=ValueType::VALUE_TYPE_UNSPECIFIED >
    class NewParam : public BaseParamTemplate < CSWC::COLLADA_ELEMENT_NEWPARAM, Type, paramType >
    {
    public:

        /** Provides additional information about the volatility or linkage of 
        a <newparam> declaration. Allows COLLADA FX parameter declarations to 
        specify constant, external, or uniform parameters. */
        enum Modifier
        {
            MODI_CONST,
            MODI_UNIFORM,
            MODI_VARYING,
            MODI_STATIC,
            MODI_VOLATILE,
            MODI_EXTERN,
            MODI_SHARED
        };

    public:

        /** Constructor
        @param streamWriter The stream the asset should be written to.*/
        NewParam ( StreamWriter* streamWriter ) : BaseParamTemplate ( streamWriter ) {}

        /** Destructor*/
        virtual ~NewParam() {}

        /** 
        Opens the param element and set the attributes. 
        @param sid Identifier for this parameter (that is, the variable name). Required.
        */
        virtual void openParam ( const String& sid )
        {
            mParamCloser = mSW->openElement ( mParamName );
            
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, sid );
        }

        /** Allows COLLADA FX parameter declarations to specify constant, 
        external, or uniform parameters. */
        void addModifier ( const Modifier& modifier )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_MODIFIER );
            mSW->appendValues ( getModifierString ( modifier ) );
            mSW->closeElement ();
        }

    private:

        /** Returns the modifier as string. */
        String& getModifierString ( const Modifier& modifier )
        {
            switch ( modifier )
            {
            case Modifier::MODI_CONST: return CSWC::COLLADA_MODIFIER_CONST;
            case Modifier::MODI_UNIFORM: return CSWC::COLLADA_MODIFIER_UNIFORM;
            case Modifier::MODI_VARYING: return CSWC::COLLADA_MODIFIER_VARYING;
            case Modifier::MODI_STATIC: return CSWC::COLLADA_MODIFIER_STATIC;
            case Modifier::MODI_VOLATILE: return CSWC::COLLADA_MODIFIER_VOLATILE;
            case Modifier::MODI_EXTERN: return CSWC::COLLADA_MODIFIER_EXTERN;
            case Modifier::MODI_SHARED: return CSWC::COLLADA_MODIFIER_SHARED;
            default: return CSWC::EMPTY_STRING;
            }
        }

    };

    typedef NewParam < bool, ValueType::BOOL > NewParamBool;
    typedef NewParam < int, ValueType::INT > NewParamInt;
    typedef NewParam < String, ValueType::STRING > NewParamString;
    typedef NewParam < double, ValueType::FLOAT > NewParamFloat;
    typedef NewParam < double, ValueType::FLOAT2 > NewParamFloat2;
    typedef NewParam < double, ValueType::FLOAT3 > NewParamFloat3;
    typedef NewParam < double, ValueType::FLOAT4 > NewParamFloat4;
    typedef NewParam < double[4][4], ValueType::FLOAT4x4 > NewParamFloat4x4;
    typedef NewParam < Surface, ValueType::SURFACE > NewParamSurface;
    typedef NewParam < Sampler > NewParamSampler;

    /** A class to add a <setparam> to the stream.*/
    template<class Type, const ValueType::ColladaType paramType=ValueType::VALUE_TYPE_UNSPECIFIED>
    class SetParam : public BaseParamTemplate<CSWC::COLLADA_ELEMENT_SETPARAM, Type, paramType>
    {

    public:

        /** Constructor
        @param streamWriter The stream the asset should be written to.*/
        SetParam ( StreamWriter* streamWriter ) : BaseParamTemplate ( streamWriter ) {}

        /** Destructor*/
        virtual ~SetParam() {}

        /** 
        Opens the param element and set the attributes. 
        @param refe Attempts to reference the predefined parameter that will 
                        have its value set. Required.
        @param program Optional in <usertype> and in <technique> for GLSL and 
                        CG profiles; not valid in GLES profile, <generator>, or 
                        <instance_effect>.
         */
        void openParam ( const String& refe, const String& program = "" )
        {
            mParamCloser = mSW->openElement ( mParamName );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_REF, refe );

            if ( !program.empty() )
                mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_PROGRAM, program );
        }

    };

    typedef SetParam < bool, ValueType::BOOL > SetParamBool;
    typedef SetParam < int, ValueType::INT > SetParamInt;
    typedef SetParam < String, ValueType::STRING > SetParamString;
    typedef SetParam < double, ValueType::FLOAT > SetParamFloat;
    typedef SetParam < double, ValueType::FLOAT2 > SetParamFloat2;
    typedef SetParam < double, ValueType::FLOAT3 > SetParamFloat3;
    typedef SetParam < double, ValueType::FLOAT4 > SetParamFloat4;
    typedef SetParam < double[4][4], ValueType::FLOAT4x4 > SetParamFloat4x4;
    typedef SetParam < Surface, ValueType::SURFACE > SetParamSurface;
    typedef SetParam < Sampler > SetParamSampler;


} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_PARAM_TEMPLATE_H__
