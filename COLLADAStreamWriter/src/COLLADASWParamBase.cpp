/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWParamBase.h"

namespace COLLADASW
{

    // -----------------------------
    ParamBase::ParamBase(
        StreamWriter* streamWriter,
        const String* paramName/*=&CSWC::CSW_ELEMENT_PARAM*/,
        const ValueType::ColladaType& paramType/*=ValueType::UNKNOWN */ )
        : ElementWriter ( streamWriter )
        , mParamName ( *paramName )
        , mParamType ( paramType )
        , mValueElementIsOpen ( false )
    {

    }

    // -----------------------------
    void ParamBase::openParam( const String& refe/*=""*/ )
    {
        mParamCloser = mSW->openElement ( mParamName );

        if ( !refe.empty() )
            mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_REF, refe );
    }

    // -----------------------------
    void ParamBase::appendAttribute( const String& name, const String& val )
    {
        mSW->appendAttribute ( name, val );
    }

    // -----------------------------
    void ParamBase::addSemantic( const String &semantic )
    {
        if ( !semantic.empty() )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_SEMANTIC );
            mSW->appendValues( semantic );
            mSW->closeElement();
        }
    }

    // -----------------------------
    void ParamBase::openValuesElement()
    {
        if ( !mValueElementIsOpen && mParamType != ValueType::VALUE_TYPE_UNSPECIFIED )
        {
            mSW->openElement( ValueType::getColladaTypeString ( mParamType ) );
            mValueElementIsOpen = true;
        }
    }

    // -----------------------------
    void ParamBase::closeValuesElement()
    {
        if ( mValueElementIsOpen )
        {
            mSW->closeElement ();
            mValueElementIsOpen = false;
        }
    }

    // -----------------------------
    void ParamBase::closeParam()
    {
        closeValuesElement ();
        mParamCloser.close();
    }

    // -----------------------------
    void ParamBase::setParamType( const ValueType::ColladaType& paramType )
    {
        mParamType = paramType;
    }

    // -----------------------------
    void ParamBase::setParamName( const String& paramName )
    {
        mParamName = paramName;
    }

}
