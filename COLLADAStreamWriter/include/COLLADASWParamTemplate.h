/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASWStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_PARAM_TEMPLATE_H__
#define __COLLADASTREAMWRITER_PARAM_TEMPLATE_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWParamBase.h"
#include "COLLADASWAnnotation.h"
#include "COLLADASWValueType.h"
#include "COLLADASWSampler.h"
#include "COLLADASWSurface.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    /** A class to add a param to the stream.*/
    template < const String* paramName, class ClassType, ValueType::ColladaType paramType=ValueType::VALUE_TYPE_UNSPECIFIED >
    class BaseParamTemplate : public ParamBase
    {

    public:

        /** Constructor
        @param streamWriter The stream the asset should be written to.*/
        BaseParamTemplate ( StreamWriter* streamWriter )
        : ParamBase ( streamWriter, paramName, paramType )
        {}

        /** Destructor*/
        virtual ~BaseParamTemplate() {}

    };

    /** A class to add a <newparam> to the stream.*/
    template < class Type, const ValueType::ColladaType paramType=ValueType::VALUE_TYPE_UNSPECIFIED >
    class NewParam : public BaseParamTemplate < &CSWC::CSW_ELEMENT_NEWPARAM, Type, paramType >
    {
    public:

        /** Provides additional information about the volatility or linkage of
        a <newparam> declaration. Allows COLLADASW FX parameter declarations to
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
        NewParam ( StreamWriter* streamWriter )
        : BaseParamTemplate < &CSWC::CSW_ELEMENT_NEWPARAM, Type, paramType > ( streamWriter )
        {}

        /** Destructor*/
        virtual ~NewParam() {}

        /**
        Opens the param element and set the attributes.
        @param sid Identifier for this parameter (that is, the variable name). Required.
        */
        virtual void openParam ( const String& sid )
        {
        	this->mParamCloser = this->mSW->openElement ( this->mParamName );

            this->mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, sid );
        }

        /** Allows COLLADASW FX parameter declarations to specify constant,
        external, or uniform parameters. */
        void addModifier ( const Modifier& modifier )
        {
        	this->mSW->openElement ( CSWC::CSW_ELEMENT_MODIFIER );
        	this->mSW->appendValues ( getModifierString ( modifier ) );
        	this->mSW->closeElement ();
        }

    private:

        /** Returns the modifier as string. */
        String& getModifierString ( const Modifier& modifier )
        {
            switch ( modifier )
            {
            case MODI_CONST: return CSWC::CSW_MODIFIER_CONST;
            case MODI_UNIFORM: return CSWC::CSW_MODIFIER_UNIFORM;
            case MODI_VARYING: return CSWC::CSW_MODIFIER_VARYING;
            case MODI_STATIC: return CSWC::CSW_MODIFIER_STATIC;
            case MODI_VOLATILE: return CSWC::CSW_MODIFIER_VOLATILE;
            case MODI_EXTERN: return CSWC::CSW_MODIFIER_EXTERN;
            case MODI_SHARED: return CSWC::CSW_MODIFIER_SHARED;
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
    template < class Type, const ValueType::ColladaType paramType=ValueType::VALUE_TYPE_UNSPECIFIED >
    class SetParam : public BaseParamTemplate < &CSWC::CSW_ELEMENT_SETPARAM, Type, paramType >
    {

    public:

        /** Constructor
        @param streamWriter The stream the asset should be written to.*/
        SetParam ( StreamWriter* streamWriter )
        : BaseParamTemplate < &CSWC::CSW_ELEMENT_SETPARAM, Type, paramType > ( streamWriter )
        {}

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
            this->mParamCloser = this->mSW->openElement ( this->mParamName );
            this->mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_REF, refe );

            if ( !program.empty() )
            	this->mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_PROGRAM, program );
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


} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_PARAM_TEMPLATE_H__
