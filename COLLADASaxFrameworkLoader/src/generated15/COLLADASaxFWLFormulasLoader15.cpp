/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLFormulasLoader15.h"


namespace COLLADASaxFWL
{


bool FormulasLoader15::begin__formula( const COLLADASaxFWL15::formula__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__formula(attributeData));
COLLADASaxFWL::formula__AttributeData attrData;
attrData.id = attributeData.id;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
return mLoader->begin__formula(attrData);
}


bool FormulasLoader15::end__formula()
{
SaxVirtualFunctionTest15(end__formula());
return mLoader->end__formula();
}


bool FormulasLoader15::begin__newparam____formula_newparam_type( const COLLADASaxFWL15::newparam____formula_newparam_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__newparam____formula_newparam_type(attributeData));
COLLADASaxFWL::formula_newparam_type__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__newparam(attrData);
}


bool FormulasLoader15::end__newparam____formula_newparam_type()
{
SaxVirtualFunctionTest15(end__newparam____formula_newparam_type());
return mLoader->end__newparam();
}


bool FormulasLoader15::begin__target()
{
SaxVirtualFunctionTest15(begin__target());
return mLoader->begin__target();
}


bool FormulasLoader15::end__target()
{
SaxVirtualFunctionTest15(end__target());
return mLoader->end__target();
}


bool FormulasLoader15::begin__param____common_param_type()
{
SaxVirtualFunctionTest15(begin__param____common_param_type());
return mLoader->begin__param();
}


bool FormulasLoader15::end__param____common_param_type()
{
SaxVirtualFunctionTest15(end__param____common_param_type());
return mLoader->end__param();
}


bool FormulasLoader15::data__param____common_param_type( const ParserChar* value, size_t length )
{
SaxVirtualFunctionTest15(data__param____common_param_type(value, length));
return mLoader->data__param(value, length);
}


bool FormulasLoader15::begin__float____float_type()
{
SaxVirtualFunctionTest15(begin__float____float_type());
return mLoader->begin__float();
}


bool FormulasLoader15::end__float____float_type()
{
SaxVirtualFunctionTest15(end__float____float_type());
return mLoader->end__float();
}


bool FormulasLoader15::data__float____float_type( float value )
{
SaxVirtualFunctionTest15(data__float____float_type(value));
return mLoader->data__float(value);
}


bool FormulasLoader15::begin__int____int_type()
{
SaxVirtualFunctionTest15(begin__int____int_type());
return mLoader->begin__int();
}


bool FormulasLoader15::end__int____int_type()
{
SaxVirtualFunctionTest15(end__int____int_type());
return mLoader->end__int();
}


bool FormulasLoader15::data__int____int_type( int value )
{
SaxVirtualFunctionTest15(data__int____int_type(value));
return mLoader->data__int(value);
}


bool FormulasLoader15::begin__bool()
{
SaxVirtualFunctionTest15(begin__bool());
return mLoader->begin__bool();
}


bool FormulasLoader15::end__bool()
{
SaxVirtualFunctionTest15(end__bool());
return mLoader->end__bool();
}


bool FormulasLoader15::data__bool( bool value )
{
SaxVirtualFunctionTest15(data__bool(value));
return mLoader->data__bool(value);
}


bool FormulasLoader15::begin__technique_common____formula_technique_type()
{
SaxVirtualFunctionTest15(begin__technique_common____formula_technique_type());
return mLoader->begin__technique_common();
}


bool FormulasLoader15::end__technique_common____formula_technique_type()
{
SaxVirtualFunctionTest15(end__technique_common____formula_technique_type());
return mLoader->end__technique_common();
}


bool FormulasLoader15::begin__math( const COLLADASaxFWL15::math__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__math(attributeData));
COLLADASaxFWL::math__AttributeData attrData;
attrData.baseline = attributeData.baseline;
attrData.alttext = attributeData.alttext;
attrData.type = attributeData.type;
attrData.name = attributeData.name;
attrData.height = attributeData.height;
attrData.width = attributeData.width;
attrData.macros = attributeData.macros;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.unknownAttributes = attributeData.unknownAttributes;
switch (attributeData.overflow) {
case COLLADASaxFWL15::ENUM__mathml__overflow__scroll: attrData.overflow=COLLADASaxFWL::ENUM__mathml__overflow__scroll; break;
case COLLADASaxFWL15::ENUM__mathml__overflow__elide: attrData.overflow=COLLADASaxFWL::ENUM__mathml__overflow__elide; break;
case COLLADASaxFWL15::ENUM__mathml__overflow__truncate: attrData.overflow=COLLADASaxFWL::ENUM__mathml__overflow__truncate; break;
case COLLADASaxFWL15::ENUM__mathml__overflow__scale: attrData.overflow=COLLADASaxFWL::ENUM__mathml__overflow__scale; break;
case COLLADASaxFWL15::ENUM__mathml__overflow__COUNT: attrData.overflow=COLLADASaxFWL::ENUM__mathml__overflow__INVALID; break;
case COLLADASaxFWL15::ENUM__mathml__overflow__NOT_PRESENT: attrData.overflow=COLLADASaxFWL::ENUM__mathml__overflow__NOT_PRESENT; break;
}
switch (attributeData.display) {
case COLLADASaxFWL15::ENUM__mathml__display__block: attrData.display=COLLADASaxFWL::ENUM__mathml__display__block; break;
case COLLADASaxFWL15::ENUM__mathml__display__inline: attrData.display=COLLADASaxFWL::ENUM__mathml__display__inline; break;
case COLLADASaxFWL15::ENUM__mathml__display__COUNT: attrData.display=COLLADASaxFWL::ENUM__mathml__display__INVALID; break;
case COLLADASaxFWL15::ENUM__mathml__display__NOT_PRESENT: attrData.display=COLLADASaxFWL::ENUM__mathml__display__NOT_PRESENT; break;
}
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::math__AttributeData::ATTRIBUTE_ALTIMG_PRESENT) == COLLADASaxFWL15::math__AttributeData::ATTRIBUTE_ALTIMG_PRESENT ) {
    attrData.altimg = attributeData.altimg;
    attrData.present_attributes |= COLLADASaxFWL::math__AttributeData::ATTRIBUTE_ALTIMG_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::math__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::math__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::math__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::math__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::math__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::math__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__math(attrData);
}


bool FormulasLoader15::end__math()
{
SaxVirtualFunctionTest15(end__math());
return mLoader->end__math();
}


bool FormulasLoader15::begin__apply( const COLLADASaxFWL15::apply__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__apply(attributeData));
COLLADASaxFWL::apply__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::apply__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::apply__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::apply__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::apply__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::apply__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::apply__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__apply(attrData);
}


bool FormulasLoader15::end__apply()
{
SaxVirtualFunctionTest15(end__apply());
return mLoader->end__apply();
}


bool FormulasLoader15::begin__cn( const COLLADASaxFWL15::cn__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__cn(attributeData));
COLLADASaxFWL::cn__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::cn__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::cn__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::cn__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::cn__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::cn__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::cn__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::cn__AttributeData::ATTRIBUTE_BASE_PRESENT) == COLLADASaxFWL15::cn__AttributeData::ATTRIBUTE_BASE_PRESENT ) {
    attrData.base = attributeData.base;
    attrData.present_attributes |= COLLADASaxFWL::cn__AttributeData::ATTRIBUTE_BASE_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::cn__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::cn__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::cn__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
switch (attributeData.type) {
case COLLADASaxFWL15::ENUM__mathml__cn__type__e_notation: attrData.type=COLLADASaxFWL::ENUM__mathml__cn__type__e_notation; break;
case COLLADASaxFWL15::ENUM__mathml__cn__type__integer: attrData.type=COLLADASaxFWL::ENUM__mathml__cn__type__integer; break;
case COLLADASaxFWL15::ENUM__mathml__cn__type__rational: attrData.type=COLLADASaxFWL::ENUM__mathml__cn__type__rational; break;
case COLLADASaxFWL15::ENUM__mathml__cn__type__real: attrData.type=COLLADASaxFWL::ENUM__mathml__cn__type__real; break;
case COLLADASaxFWL15::ENUM__mathml__cn__type__complex_cartesian: attrData.type=COLLADASaxFWL::ENUM__mathml__cn__type__complex_cartesian; break;
case COLLADASaxFWL15::ENUM__mathml__cn__type__complex_polar: attrData.type=COLLADASaxFWL::ENUM__mathml__cn__type__complex_polar; break;
case COLLADASaxFWL15::ENUM__mathml__cn__type__constant: attrData.type=COLLADASaxFWL::ENUM__mathml__cn__type__constant; break;
case COLLADASaxFWL15::ENUM__mathml__cn__type__COUNT: attrData.type=COLLADASaxFWL::ENUM__mathml__cn__type__INVALID; break;
case COLLADASaxFWL15::ENUM__mathml__cn__type__NOT_PRESENT: attrData.type=COLLADASaxFWL::ENUM__mathml__cn__type__NOT_PRESENT; break;
}
return mLoader->begin__cn(attrData);
}


bool FormulasLoader15::end__cn()
{
SaxVirtualFunctionTest15(end__cn());
return mLoader->end__cn();
}


bool FormulasLoader15::data__cn( const ParserChar* value, size_t length )
{
SaxVirtualFunctionTest15(data__cn(value, length));
return mLoader->data__cn(value, length);
}


bool FormulasLoader15::begin__sep()
{
SaxVirtualFunctionTest15(begin__sep());
return mLoader->begin__sep();
}


bool FormulasLoader15::end__sep()
{
SaxVirtualFunctionTest15(end__sep());
return mLoader->end__sep();
}


bool FormulasLoader15::begin__ci( const COLLADASaxFWL15::ci__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__ci(attributeData));
COLLADASaxFWL::ci__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.type = attributeData.type;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::ci__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::ci__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::ci__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::ci__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::ci__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::ci__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::ci__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::ci__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::ci__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
return mLoader->begin__ci(attrData);
}


bool FormulasLoader15::end__ci()
{
SaxVirtualFunctionTest15(end__ci());
return mLoader->end__ci();
}


bool FormulasLoader15::data__ci( const ParserChar* value, size_t length )
{
SaxVirtualFunctionTest15(data__ci(value, length));
return mLoader->data__ci(value, length);
}


bool FormulasLoader15::begin__csymbol( const COLLADASaxFWL15::csymbol__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__csymbol(attributeData));
COLLADASaxFWL::csymbol__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::csymbol__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::csymbol__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::csymbol__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::csymbol__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::csymbol__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::csymbol__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::csymbol__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::csymbol__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::csymbol__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
return mLoader->begin__csymbol(attrData);
}


bool FormulasLoader15::end__csymbol()
{
SaxVirtualFunctionTest15(end__csymbol());
return mLoader->end__csymbol();
}


bool FormulasLoader15::data__csymbol( const ParserChar* value, size_t length )
{
SaxVirtualFunctionTest15(data__csymbol(value, length));
return mLoader->data__csymbol(value, length);
}


bool FormulasLoader15::begin__declare( const COLLADASaxFWL15::declare__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__declare(attributeData));
COLLADASaxFWL::declare__AttributeData attrData;
attrData.type = attributeData.type;
attrData.scope = attributeData.scope;
attrData.encoding = attributeData.encoding;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::declare__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::declare__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::declare__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::declare__AttributeData::ATTRIBUTE_NARGS_PRESENT) == COLLADASaxFWL15::declare__AttributeData::ATTRIBUTE_NARGS_PRESENT ) {
    attrData.nargs = attributeData.nargs;
    attrData.present_attributes |= COLLADASaxFWL::declare__AttributeData::ATTRIBUTE_NARGS_PRESENT;
}
switch (attributeData.occurrence) {
case COLLADASaxFWL15::ENUM__mathml__declare__occurrence__prefix: attrData.occurrence=COLLADASaxFWL::ENUM__mathml__declare__occurrence__prefix; break;
case COLLADASaxFWL15::ENUM__mathml__declare__occurrence__infix: attrData.occurrence=COLLADASaxFWL::ENUM__mathml__declare__occurrence__infix; break;
case COLLADASaxFWL15::ENUM__mathml__declare__occurrence__function_model: attrData.occurrence=COLLADASaxFWL::ENUM__mathml__declare__occurrence__function_model; break;
case COLLADASaxFWL15::ENUM__mathml__declare__occurrence__COUNT: attrData.occurrence=COLLADASaxFWL::ENUM__mathml__declare__occurrence__INVALID; break;
case COLLADASaxFWL15::ENUM__mathml__declare__occurrence__NOT_PRESENT: attrData.occurrence=COLLADASaxFWL::ENUM__mathml__declare__occurrence__NOT_PRESENT; break;
}
return mLoader->begin__declare(attrData);
}


bool FormulasLoader15::end__declare()
{
SaxVirtualFunctionTest15(end__declare());
return mLoader->end__declare();
}


bool FormulasLoader15::begin__quotient( const COLLADASaxFWL15::quotient__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__quotient(attributeData));
COLLADASaxFWL::quotient__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::quotient__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::quotient__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::quotient__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::quotient__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::quotient__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::quotient__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::quotient__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::quotient__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::quotient__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__quotient(attrData);
}


bool FormulasLoader15::end__quotient()
{
SaxVirtualFunctionTest15(end__quotient());
return mLoader->end__quotient();
}


bool FormulasLoader15::begin__divide( const COLLADASaxFWL15::divide__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__divide(attributeData));
COLLADASaxFWL::divide__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::divide__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::divide__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::divide__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::divide__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::divide__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::divide__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::divide__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::divide__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::divide__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__divide(attrData);
}


bool FormulasLoader15::end__divide()
{
SaxVirtualFunctionTest15(end__divide());
return mLoader->end__divide();
}


bool FormulasLoader15::begin__minus( const COLLADASaxFWL15::minus__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__minus(attributeData));
COLLADASaxFWL::minus__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::minus__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::minus__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::minus__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::minus__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::minus__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::minus__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::minus__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::minus__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::minus__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__minus(attrData);
}


bool FormulasLoader15::end__minus()
{
SaxVirtualFunctionTest15(end__minus());
return mLoader->end__minus();
}


bool FormulasLoader15::begin__plus( const COLLADASaxFWL15::plus__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__plus(attributeData));
COLLADASaxFWL::plus__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::plus__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::plus__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::plus__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::plus__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::plus__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::plus__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::plus__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::plus__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::plus__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__plus(attrData);
}


bool FormulasLoader15::end__plus()
{
SaxVirtualFunctionTest15(end__plus());
return mLoader->end__plus();
}


bool FormulasLoader15::begin__times( const COLLADASaxFWL15::times__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__times(attributeData));
COLLADASaxFWL::times__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::times__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::times__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::times__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::times__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::times__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::times__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::times__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::times__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::times__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__times(attrData);
}


bool FormulasLoader15::end__times()
{
SaxVirtualFunctionTest15(end__times());
return mLoader->end__times();
}


bool FormulasLoader15::begin__sum( const COLLADASaxFWL15::sum__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__sum(attributeData));
COLLADASaxFWL::sum__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::sum__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::sum__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::sum__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::sum__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::sum__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::sum__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::sum__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::sum__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::sum__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__sum(attrData);
}


bool FormulasLoader15::end__sum()
{
SaxVirtualFunctionTest15(end__sum());
return mLoader->end__sum();
}


bool FormulasLoader15::begin__product( const COLLADASaxFWL15::product__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__product(attributeData));
COLLADASaxFWL::product__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::product__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::product__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::product__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::product__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::product__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::product__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::product__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::product__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::product__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__product(attrData);
}


bool FormulasLoader15::end__product()
{
SaxVirtualFunctionTest15(end__product());
return mLoader->end__product();
}


bool FormulasLoader15::begin__exponentiale( const COLLADASaxFWL15::exponentiale__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__exponentiale(attributeData));
COLLADASaxFWL::exponentiale__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::exponentiale__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::exponentiale__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::exponentiale__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::exponentiale__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::exponentiale__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::exponentiale__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::exponentiale__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::exponentiale__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::exponentiale__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__exponentiale(attrData);
}


bool FormulasLoader15::end__exponentiale()
{
SaxVirtualFunctionTest15(end__exponentiale());
return mLoader->end__exponentiale();
}


bool FormulasLoader15::begin__pi( const COLLADASaxFWL15::pi__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__pi(attributeData));
COLLADASaxFWL::pi__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::pi__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::pi__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::pi__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::pi__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::pi__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::pi__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::pi__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::pi__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::pi__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__pi(attrData);
}


bool FormulasLoader15::end__pi()
{
SaxVirtualFunctionTest15(end__pi());
return mLoader->end__pi();
}


bool FormulasLoader15::begin__true( const COLLADASaxFWL15::true__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__true(attributeData));
COLLADASaxFWL::true__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::true__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::true__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::true__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::true__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::true__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::true__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::true__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::true__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::true__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__true(attrData);
}


bool FormulasLoader15::end__true()
{
SaxVirtualFunctionTest15(end__true());
return mLoader->end__true();
}


bool FormulasLoader15::begin__false( const COLLADASaxFWL15::false__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__false(attributeData));
COLLADASaxFWL::false__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::false__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::false__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::false__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::false__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::false__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::false__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::false__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::false__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::false__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__false(attrData);
}


bool FormulasLoader15::end__false()
{
SaxVirtualFunctionTest15(end__false());
return mLoader->end__false();
}


bool FormulasLoader15::begin__and( const COLLADASaxFWL15::and__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__and(attributeData));
COLLADASaxFWL::and__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::and__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::and__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::and__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::and__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::and__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::and__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::and__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::and__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::and__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__and(attrData);
}


bool FormulasLoader15::end__and()
{
SaxVirtualFunctionTest15(end__and());
return mLoader->end__and();
}


bool FormulasLoader15::begin__or( const COLLADASaxFWL15::or__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__or(attributeData));
COLLADASaxFWL::or__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::or__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::or__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::or__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::or__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::or__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::or__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::or__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::or__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::or__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__or(attrData);
}


bool FormulasLoader15::end__or()
{
SaxVirtualFunctionTest15(end__or());
return mLoader->end__or();
}


bool FormulasLoader15::begin__xor( const COLLADASaxFWL15::xor__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__xor(attributeData));
COLLADASaxFWL::xor__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::xor__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::xor__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::xor__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::xor__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::xor__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::xor__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::xor__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::xor__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::xor__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__xor(attrData);
}


bool FormulasLoader15::end__xor()
{
SaxVirtualFunctionTest15(end__xor());
return mLoader->end__xor();
}


bool FormulasLoader15::begin__not( const COLLADASaxFWL15::not__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__not(attributeData));
COLLADASaxFWL::not__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::not__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::not__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::not__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::not__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::not__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::not__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::not__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::not__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::not__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__not(attrData);
}


bool FormulasLoader15::end__not()
{
SaxVirtualFunctionTest15(end__not());
return mLoader->end__not();
}


bool FormulasLoader15::begin__eq( const COLLADASaxFWL15::eq__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__eq(attributeData));
COLLADASaxFWL::eq__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::eq__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::eq__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::eq__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::eq__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::eq__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::eq__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::eq__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::eq__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::eq__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__eq(attrData);
}


bool FormulasLoader15::end__eq()
{
SaxVirtualFunctionTest15(end__eq());
return mLoader->end__eq();
}


bool FormulasLoader15::begin__neq( const COLLADASaxFWL15::neq__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__neq(attributeData));
COLLADASaxFWL::neq__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::neq__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::neq__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::neq__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::neq__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::neq__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::neq__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::neq__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::neq__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::neq__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__neq(attrData);
}


bool FormulasLoader15::end__neq()
{
SaxVirtualFunctionTest15(end__neq());
return mLoader->end__neq();
}


bool FormulasLoader15::begin__leq( const COLLADASaxFWL15::leq__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__leq(attributeData));
COLLADASaxFWL::leq__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::leq__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::leq__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::leq__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::leq__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::leq__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::leq__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::leq__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::leq__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::leq__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__leq(attrData);
}


bool FormulasLoader15::end__leq()
{
SaxVirtualFunctionTest15(end__leq());
return mLoader->end__leq();
}


bool FormulasLoader15::begin__lt( const COLLADASaxFWL15::lt__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__lt(attributeData));
COLLADASaxFWL::lt__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::lt__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::lt__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::lt__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::lt__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::lt__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::lt__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::lt__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::lt__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::lt__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__lt(attrData);
}


bool FormulasLoader15::end__lt()
{
SaxVirtualFunctionTest15(end__lt());
return mLoader->end__lt();
}


bool FormulasLoader15::begin__geq( const COLLADASaxFWL15::geq__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__geq(attributeData));
COLLADASaxFWL::geq__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::geq__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::geq__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::geq__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::geq__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::geq__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::geq__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::geq__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::geq__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::geq__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__geq(attrData);
}


bool FormulasLoader15::end__geq()
{
SaxVirtualFunctionTest15(end__geq());
return mLoader->end__geq();
}


bool FormulasLoader15::begin__gt( const COLLADASaxFWL15::gt__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__gt(attributeData));
COLLADASaxFWL::gt__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::gt__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::gt__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::gt__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::gt__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::gt__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::gt__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::gt__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::gt__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::gt__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__gt(attrData);
}


bool FormulasLoader15::end__gt()
{
SaxVirtualFunctionTest15(end__gt());
return mLoader->end__gt();
}


bool FormulasLoader15::begin__equivalent( const COLLADASaxFWL15::equivalent__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__equivalent(attributeData));
COLLADASaxFWL::equivalent__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::equivalent__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::equivalent__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::equivalent__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::equivalent__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::equivalent__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::equivalent__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::equivalent__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::equivalent__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::equivalent__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__equivalent(attrData);
}


bool FormulasLoader15::end__equivalent()
{
SaxVirtualFunctionTest15(end__equivalent());
return mLoader->end__equivalent();
}


bool FormulasLoader15::begin__power( const COLLADASaxFWL15::power__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__power(attributeData));
COLLADASaxFWL::power__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::power__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::power__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::power__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::power__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::power__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::power__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::power__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::power__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::power__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__power(attrData);
}


bool FormulasLoader15::end__power()
{
SaxVirtualFunctionTest15(end__power());
return mLoader->end__power();
}


bool FormulasLoader15::begin__factorial( const COLLADASaxFWL15::factorial__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__factorial(attributeData));
COLLADASaxFWL::factorial__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::factorial__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::factorial__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::factorial__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::factorial__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::factorial__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::factorial__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::factorial__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::factorial__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::factorial__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__factorial(attrData);
}


bool FormulasLoader15::end__factorial()
{
SaxVirtualFunctionTest15(end__factorial());
return mLoader->end__factorial();
}


bool FormulasLoader15::begin__abs( const COLLADASaxFWL15::abs__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__abs(attributeData));
COLLADASaxFWL::abs__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::abs__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::abs__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::abs__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::abs__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::abs__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::abs__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::abs__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::abs__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::abs__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__abs(attrData);
}


bool FormulasLoader15::end__abs()
{
SaxVirtualFunctionTest15(end__abs());
return mLoader->end__abs();
}


bool FormulasLoader15::begin__exp( const COLLADASaxFWL15::exp__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__exp(attributeData));
COLLADASaxFWL::exp__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::exp__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::exp__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::exp__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::exp__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::exp__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::exp__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::exp__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::exp__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::exp__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__exp(attrData);
}


bool FormulasLoader15::end__exp()
{
SaxVirtualFunctionTest15(end__exp());
return mLoader->end__exp();
}


bool FormulasLoader15::begin__ln( const COLLADASaxFWL15::ln__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__ln(attributeData));
COLLADASaxFWL::ln__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::ln__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::ln__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::ln__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::ln__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::ln__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::ln__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::ln__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::ln__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::ln__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__ln(attrData);
}


bool FormulasLoader15::end__ln()
{
SaxVirtualFunctionTest15(end__ln());
return mLoader->end__ln();
}


bool FormulasLoader15::begin__min____Arith_type( const COLLADASaxFWL15::min____Arith_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__min____Arith_type(attributeData));
COLLADASaxFWL::min__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::min____Arith_type__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::min____Arith_type__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::min__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::min____Arith_type__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::min____Arith_type__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::min__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::min____Arith_type__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::min____Arith_type__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::min__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__min(attrData);
}


bool FormulasLoader15::end__min____Arith_type()
{
SaxVirtualFunctionTest15(end__min____Arith_type());
return mLoader->end__min();
}


bool FormulasLoader15::begin__max____Arith_type( const COLLADASaxFWL15::max____Arith_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__max____Arith_type(attributeData));
COLLADASaxFWL::max__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::max____Arith_type__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::max____Arith_type__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::max__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::max____Arith_type__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::max____Arith_type__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::max__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::max____Arith_type__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::max____Arith_type__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::max__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__max(attrData);
}


bool FormulasLoader15::end__max____Arith_type()
{
SaxVirtualFunctionTest15(end__max____Arith_type());
return mLoader->end__max();
}


bool FormulasLoader15::begin__ceiling( const COLLADASaxFWL15::ceiling__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__ceiling(attributeData));
COLLADASaxFWL::ceiling__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::ceiling__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::ceiling__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::ceiling__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::ceiling__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::ceiling__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::ceiling__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::ceiling__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::ceiling__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::ceiling__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__ceiling(attrData);
}


bool FormulasLoader15::end__ceiling()
{
SaxVirtualFunctionTest15(end__ceiling());
return mLoader->end__ceiling();
}


bool FormulasLoader15::begin__floor( const COLLADASaxFWL15::floor__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__floor(attributeData));
COLLADASaxFWL::floor__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::floor__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::floor__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::floor__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::floor__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::floor__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::floor__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::floor__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::floor__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::floor__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__floor(attrData);
}


bool FormulasLoader15::end__floor()
{
SaxVirtualFunctionTest15(end__floor());
return mLoader->end__floor();
}


bool FormulasLoader15::begin__gcd( const COLLADASaxFWL15::gcd__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__gcd(attributeData));
COLLADASaxFWL::gcd__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::gcd__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::gcd__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::gcd__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::gcd__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::gcd__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::gcd__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::gcd__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::gcd__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::gcd__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__gcd(attrData);
}


bool FormulasLoader15::end__gcd()
{
SaxVirtualFunctionTest15(end__gcd());
return mLoader->end__gcd();
}


bool FormulasLoader15::begin__lcm( const COLLADASaxFWL15::lcm__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__lcm(attributeData));
COLLADASaxFWL::lcm__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::lcm__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::lcm__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::lcm__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::lcm__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::lcm__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::lcm__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::lcm__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::lcm__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::lcm__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__lcm(attrData);
}


bool FormulasLoader15::end__lcm()
{
SaxVirtualFunctionTest15(end__lcm());
return mLoader->end__lcm();
}


bool FormulasLoader15::begin__rem( const COLLADASaxFWL15::rem__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__rem(attributeData));
COLLADASaxFWL::rem__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::rem__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::rem__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::rem__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::rem__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::rem__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::rem__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::rem__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::rem__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::rem__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__rem(attrData);
}


bool FormulasLoader15::end__rem()
{
SaxVirtualFunctionTest15(end__rem());
return mLoader->end__rem();
}


bool FormulasLoader15::begin__root( const COLLADASaxFWL15::root__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__root(attributeData));
COLLADASaxFWL::root__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::root__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::root__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::root__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::root__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::root__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::root__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::root__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::root__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::root__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__root(attrData);
}


bool FormulasLoader15::end__root()
{
SaxVirtualFunctionTest15(end__root());
return mLoader->end__root();
}


bool FormulasLoader15::begin__log( const COLLADASaxFWL15::log__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__log(attributeData));
COLLADASaxFWL::log__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::log__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::log__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::log__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::log__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::log__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::log__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::log__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::log__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::log__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__log(attrData);
}


bool FormulasLoader15::end__log()
{
SaxVirtualFunctionTest15(end__log());
return mLoader->end__log();
}


bool FormulasLoader15::begin__logbase( const COLLADASaxFWL15::logbase__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__logbase(attributeData));
COLLADASaxFWL::logbase__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::logbase__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::logbase__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::logbase__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::logbase__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::logbase__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::logbase__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__logbase(attrData);
}


bool FormulasLoader15::end__logbase()
{
SaxVirtualFunctionTest15(end__logbase());
return mLoader->end__logbase();
}


bool FormulasLoader15::begin__sin( const COLLADASaxFWL15::sin__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__sin(attributeData));
COLLADASaxFWL::sin__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::sin__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::sin__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::sin__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::sin__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::sin__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::sin__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::sin__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::sin__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::sin__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__sin(attrData);
}


bool FormulasLoader15::end__sin()
{
SaxVirtualFunctionTest15(end__sin());
return mLoader->end__sin();
}


bool FormulasLoader15::begin__cos( const COLLADASaxFWL15::cos__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__cos(attributeData));
COLLADASaxFWL::cos__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::cos__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::cos__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::cos__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::cos__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::cos__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::cos__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::cos__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::cos__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::cos__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__cos(attrData);
}


bool FormulasLoader15::end__cos()
{
SaxVirtualFunctionTest15(end__cos());
return mLoader->end__cos();
}


bool FormulasLoader15::begin__tan( const COLLADASaxFWL15::tan__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__tan(attributeData));
COLLADASaxFWL::tan__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::tan__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::tan__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::tan__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::tan__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::tan__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::tan__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::tan__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::tan__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::tan__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__tan(attrData);
}


bool FormulasLoader15::end__tan()
{
SaxVirtualFunctionTest15(end__tan());
return mLoader->end__tan();
}


bool FormulasLoader15::begin__cot( const COLLADASaxFWL15::cot__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__cot(attributeData));
COLLADASaxFWL::cot__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::cot__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::cot__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::cot__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::cot__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::cot__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::cot__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::cot__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::cot__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::cot__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__cot(attrData);
}


bool FormulasLoader15::end__cot()
{
SaxVirtualFunctionTest15(end__cot());
return mLoader->end__cot();
}


bool FormulasLoader15::begin__sec( const COLLADASaxFWL15::sec__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__sec(attributeData));
COLLADASaxFWL::sec__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::sec__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::sec__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::sec__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::sec__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::sec__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::sec__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::sec__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::sec__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::sec__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__sec(attrData);
}


bool FormulasLoader15::end__sec()
{
SaxVirtualFunctionTest15(end__sec());
return mLoader->end__sec();
}


bool FormulasLoader15::begin__csc( const COLLADASaxFWL15::csc__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__csc(attributeData));
COLLADASaxFWL::csc__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::csc__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::csc__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::csc__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::csc__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::csc__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::csc__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::csc__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::csc__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::csc__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__csc(attrData);
}


bool FormulasLoader15::end__csc()
{
SaxVirtualFunctionTest15(end__csc());
return mLoader->end__csc();
}


bool FormulasLoader15::begin__arcsin( const COLLADASaxFWL15::arcsin__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__arcsin(attributeData));
COLLADASaxFWL::arcsin__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::arcsin__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::arcsin__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::arcsin__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arcsin__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::arcsin__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::arcsin__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arcsin__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::arcsin__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::arcsin__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__arcsin(attrData);
}


bool FormulasLoader15::end__arcsin()
{
SaxVirtualFunctionTest15(end__arcsin());
return mLoader->end__arcsin();
}


bool FormulasLoader15::begin__arccos( const COLLADASaxFWL15::arccos__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__arccos(attributeData));
COLLADASaxFWL::arccos__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccos__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::arccos__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::arccos__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccos__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::arccos__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::arccos__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccos__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::arccos__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::arccos__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__arccos(attrData);
}


bool FormulasLoader15::end__arccos()
{
SaxVirtualFunctionTest15(end__arccos());
return mLoader->end__arccos();
}


bool FormulasLoader15::begin__arctan( const COLLADASaxFWL15::arctan__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__arctan(attributeData));
COLLADASaxFWL::arctan__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::arctan__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::arctan__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::arctan__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arctan__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::arctan__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::arctan__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arctan__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::arctan__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::arctan__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__arctan(attrData);
}


bool FormulasLoader15::end__arctan()
{
SaxVirtualFunctionTest15(end__arctan());
return mLoader->end__arctan();
}


bool FormulasLoader15::begin__arccot( const COLLADASaxFWL15::arccot__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__arccot(attributeData));
COLLADASaxFWL::arccot__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccot__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::arccot__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::arccot__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccot__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::arccot__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::arccot__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccot__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::arccot__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::arccot__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__arccot(attrData);
}


bool FormulasLoader15::end__arccot()
{
SaxVirtualFunctionTest15(end__arccot());
return mLoader->end__arccot();
}


bool FormulasLoader15::begin__arcsec( const COLLADASaxFWL15::arcsec__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__arcsec(attributeData));
COLLADASaxFWL::arcsec__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::arcsec__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::arcsec__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::arcsec__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arcsec__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::arcsec__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::arcsec__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arcsec__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::arcsec__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::arcsec__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__arcsec(attrData);
}


bool FormulasLoader15::end__arcsec()
{
SaxVirtualFunctionTest15(end__arcsec());
return mLoader->end__arcsec();
}


bool FormulasLoader15::begin__arccsc( const COLLADASaxFWL15::arccsc__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__arccsc(attributeData));
COLLADASaxFWL::arccsc__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccsc__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::arccsc__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::arccsc__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccsc__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::arccsc__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::arccsc__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccsc__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::arccsc__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::arccsc__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__arccsc(attrData);
}


bool FormulasLoader15::end__arccsc()
{
SaxVirtualFunctionTest15(end__arccsc());
return mLoader->end__arccsc();
}


bool FormulasLoader15::begin__sinh( const COLLADASaxFWL15::sinh__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__sinh(attributeData));
COLLADASaxFWL::sinh__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::sinh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::sinh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::sinh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::sinh__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::sinh__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::sinh__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::sinh__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::sinh__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::sinh__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__sinh(attrData);
}


bool FormulasLoader15::end__sinh()
{
SaxVirtualFunctionTest15(end__sinh());
return mLoader->end__sinh();
}


bool FormulasLoader15::begin__cosh( const COLLADASaxFWL15::cosh__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__cosh(attributeData));
COLLADASaxFWL::cosh__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::cosh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::cosh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::cosh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::cosh__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::cosh__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::cosh__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::cosh__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::cosh__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::cosh__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__cosh(attrData);
}


bool FormulasLoader15::end__cosh()
{
SaxVirtualFunctionTest15(end__cosh());
return mLoader->end__cosh();
}


bool FormulasLoader15::begin__tanh( const COLLADASaxFWL15::tanh__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__tanh(attributeData));
COLLADASaxFWL::tanh__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::tanh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::tanh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::tanh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::tanh__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::tanh__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::tanh__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::tanh__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::tanh__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::tanh__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__tanh(attrData);
}


bool FormulasLoader15::end__tanh()
{
SaxVirtualFunctionTest15(end__tanh());
return mLoader->end__tanh();
}


bool FormulasLoader15::begin__sech( const COLLADASaxFWL15::sech__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__sech(attributeData));
COLLADASaxFWL::sech__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::sech__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::sech__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::sech__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::sech__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::sech__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::sech__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::sech__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::sech__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::sech__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__sech(attrData);
}


bool FormulasLoader15::end__sech()
{
SaxVirtualFunctionTest15(end__sech());
return mLoader->end__sech();
}


bool FormulasLoader15::begin__csch( const COLLADASaxFWL15::csch__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__csch(attributeData));
COLLADASaxFWL::csch__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::csch__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::csch__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::csch__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::csch__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::csch__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::csch__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::csch__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::csch__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::csch__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__csch(attrData);
}


bool FormulasLoader15::end__csch()
{
SaxVirtualFunctionTest15(end__csch());
return mLoader->end__csch();
}


bool FormulasLoader15::begin__coth( const COLLADASaxFWL15::coth__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__coth(attributeData));
COLLADASaxFWL::coth__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::coth__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::coth__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::coth__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::coth__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::coth__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::coth__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::coth__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::coth__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::coth__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__coth(attrData);
}


bool FormulasLoader15::end__coth()
{
SaxVirtualFunctionTest15(end__coth());
return mLoader->end__coth();
}


bool FormulasLoader15::begin__arcsinh( const COLLADASaxFWL15::arcsinh__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__arcsinh(attributeData));
COLLADASaxFWL::arcsinh__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::arcsinh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::arcsinh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::arcsinh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arcsinh__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::arcsinh__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::arcsinh__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arcsinh__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::arcsinh__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::arcsinh__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__arcsinh(attrData);
}


bool FormulasLoader15::end__arcsinh()
{
SaxVirtualFunctionTest15(end__arcsinh());
return mLoader->end__arcsinh();
}


bool FormulasLoader15::begin__arccosh( const COLLADASaxFWL15::arccosh__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__arccosh(attributeData));
COLLADASaxFWL::arccosh__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccosh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::arccosh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::arccosh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccosh__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::arccosh__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::arccosh__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccosh__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::arccosh__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::arccosh__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__arccosh(attrData);
}


bool FormulasLoader15::end__arccosh()
{
SaxVirtualFunctionTest15(end__arccosh());
return mLoader->end__arccosh();
}


bool FormulasLoader15::begin__arctanh( const COLLADASaxFWL15::arctanh__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__arctanh(attributeData));
COLLADASaxFWL::arctanh__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::arctanh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::arctanh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::arctanh__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arctanh__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::arctanh__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::arctanh__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arctanh__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::arctanh__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::arctanh__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__arctanh(attrData);
}


bool FormulasLoader15::end__arctanh()
{
SaxVirtualFunctionTest15(end__arctanh());
return mLoader->end__arctanh();
}


bool FormulasLoader15::begin__arcsech( const COLLADASaxFWL15::arcsech__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__arcsech(attributeData));
COLLADASaxFWL::arcsech__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::arcsech__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::arcsech__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::arcsech__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arcsech__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::arcsech__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::arcsech__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arcsech__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::arcsech__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::arcsech__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__arcsech(attrData);
}


bool FormulasLoader15::end__arcsech()
{
SaxVirtualFunctionTest15(end__arcsech());
return mLoader->end__arcsech();
}


bool FormulasLoader15::begin__arccsch( const COLLADASaxFWL15::arccsch__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__arccsch(attributeData));
COLLADASaxFWL::arccsch__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccsch__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::arccsch__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::arccsch__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccsch__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::arccsch__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::arccsch__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccsch__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::arccsch__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::arccsch__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__arccsch(attrData);
}


bool FormulasLoader15::end__arccsch()
{
SaxVirtualFunctionTest15(end__arccsch());
return mLoader->end__arccsch();
}


bool FormulasLoader15::begin__arccoth( const COLLADASaxFWL15::arccoth__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__arccoth(attributeData));
COLLADASaxFWL::arccoth__AttributeData attrData;
attrData.style = attributeData.style;
attrData.xref = attributeData.xref;
attrData.id = attributeData.id;
attrData.encoding = attributeData.encoding;
attrData.unknownAttributes = attributeData.unknownAttributes;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccoth__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT) == COLLADASaxFWL15::arccoth__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT ) {
    attrData.definitionURL = attributeData.definitionURL;
    attrData.present_attributes |= COLLADASaxFWL::arccoth__AttributeData::ATTRIBUTE_DEFINITIONURL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccoth__AttributeData::ATTRIBUTE__CLASS_PRESENT) == COLLADASaxFWL15::arccoth__AttributeData::ATTRIBUTE__CLASS_PRESENT ) {
    attrData._class = attributeData._class;
    attrData.present_attributes |= COLLADASaxFWL::arccoth__AttributeData::ATTRIBUTE__CLASS_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::arccoth__AttributeData::ATTRIBUTE_HREF_PRESENT) == COLLADASaxFWL15::arccoth__AttributeData::ATTRIBUTE_HREF_PRESENT ) {
    attrData.href = attributeData.href;
    attrData.present_attributes |= COLLADASaxFWL::arccoth__AttributeData::ATTRIBUTE_HREF_PRESENT;
}
return mLoader->begin__arccoth(attrData);
}


bool FormulasLoader15::end__arccoth()
{
SaxVirtualFunctionTest15(end__arccoth());
return mLoader->end__arccoth();
}



}
