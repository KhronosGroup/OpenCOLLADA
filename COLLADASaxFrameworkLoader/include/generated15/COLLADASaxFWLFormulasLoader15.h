/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_FORMULASLOADER15_H__
#define __COLLADASAXFWL_FORMULASLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFormulasLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class FormulasLoader15 : public IParserImpl15
{
private:
FormulasLoader* mLoader;

public:
FormulasLoader15(FormulasLoader* loader)
 : mLoader(loader)
{}


virtual bool begin__formula( const COLLADASaxFWL15::formula__AttributeData& attributeData );

virtual bool end__formula();

virtual bool begin__newparam____formula_newparam_type( const COLLADASaxFWL15::newparam____formula_newparam_type__AttributeData& attributeData );

virtual bool end__newparam____formula_newparam_type();

virtual bool begin__target();

virtual bool end__target();

virtual bool begin__param____common_param_type();

virtual bool end__param____common_param_type();

virtual bool data__param____common_param_type( const ParserChar* value, size_t length );

virtual bool begin__float____float_type();

virtual bool end__float____float_type();

virtual bool data__float____float_type( float value );

virtual bool begin__int____int_type();

virtual bool end__int____int_type();

virtual bool data__int____int_type( sint64 value );

virtual bool begin__bool();

virtual bool end__bool();

virtual bool data__bool( bool value );

virtual bool begin__technique_common____formula_technique_type();

virtual bool end__technique_common____formula_technique_type();

virtual bool begin__math( const COLLADASaxFWL15::math__AttributeData& attributeData );

virtual bool end__math();

virtual bool begin__apply( const COLLADASaxFWL15::apply__AttributeData& attributeData );

virtual bool end__apply();

virtual bool begin__cn( const COLLADASaxFWL15::cn__AttributeData& attributeData );

virtual bool end__cn();

virtual bool data__cn( const ParserChar* value, size_t length );

virtual bool begin__sep();

virtual bool end__sep();

virtual bool begin__ci( const COLLADASaxFWL15::ci__AttributeData& attributeData );

virtual bool end__ci();

virtual bool data__ci( const ParserChar* value, size_t length );

virtual bool begin__csymbol( const COLLADASaxFWL15::csymbol__AttributeData& attributeData );

virtual bool end__csymbol();

virtual bool data__csymbol( const ParserChar* value, size_t length );

virtual bool begin__declare( const COLLADASaxFWL15::declare__AttributeData& attributeData );

virtual bool end__declare();

virtual bool begin__quotient( const COLLADASaxFWL15::quotient__AttributeData& attributeData );

virtual bool end__quotient();

virtual bool begin__divide( const COLLADASaxFWL15::divide__AttributeData& attributeData );

virtual bool end__divide();

virtual bool begin__minus( const COLLADASaxFWL15::minus__AttributeData& attributeData );

virtual bool end__minus();

virtual bool begin__plus( const COLLADASaxFWL15::plus__AttributeData& attributeData );

virtual bool end__plus();

virtual bool begin__times( const COLLADASaxFWL15::times__AttributeData& attributeData );

virtual bool end__times();

virtual bool begin__sum( const COLLADASaxFWL15::sum__AttributeData& attributeData );

virtual bool end__sum();

virtual bool begin__product( const COLLADASaxFWL15::product__AttributeData& attributeData );

virtual bool end__product();

virtual bool begin__exponentiale( const COLLADASaxFWL15::exponentiale__AttributeData& attributeData );

virtual bool end__exponentiale();

virtual bool begin__pi( const COLLADASaxFWL15::pi__AttributeData& attributeData );

virtual bool end__pi();

virtual bool begin__true( const COLLADASaxFWL15::true__AttributeData& attributeData );

virtual bool end__true();

virtual bool begin__false( const COLLADASaxFWL15::false__AttributeData& attributeData );

virtual bool end__false();

virtual bool begin__and( const COLLADASaxFWL15::and__AttributeData& attributeData );

virtual bool end__and();

virtual bool begin__or( const COLLADASaxFWL15::or__AttributeData& attributeData );

virtual bool end__or();

virtual bool begin__xor( const COLLADASaxFWL15::xor__AttributeData& attributeData );

virtual bool end__xor();

virtual bool begin__not( const COLLADASaxFWL15::not__AttributeData& attributeData );

virtual bool end__not();

virtual bool begin__eq( const COLLADASaxFWL15::eq__AttributeData& attributeData );

virtual bool end__eq();

virtual bool begin__neq( const COLLADASaxFWL15::neq__AttributeData& attributeData );

virtual bool end__neq();

virtual bool begin__leq( const COLLADASaxFWL15::leq__AttributeData& attributeData );

virtual bool end__leq();

virtual bool begin__lt( const COLLADASaxFWL15::lt__AttributeData& attributeData );

virtual bool end__lt();

virtual bool begin__geq( const COLLADASaxFWL15::geq__AttributeData& attributeData );

virtual bool end__geq();

virtual bool begin__gt( const COLLADASaxFWL15::gt__AttributeData& attributeData );

virtual bool end__gt();

virtual bool begin__equivalent( const COLLADASaxFWL15::equivalent__AttributeData& attributeData );

virtual bool end__equivalent();

virtual bool begin__power( const COLLADASaxFWL15::power__AttributeData& attributeData );

virtual bool end__power();

virtual bool begin__factorial( const COLLADASaxFWL15::factorial__AttributeData& attributeData );

virtual bool end__factorial();

virtual bool begin__abs( const COLLADASaxFWL15::abs__AttributeData& attributeData );

virtual bool end__abs();

virtual bool begin__exp( const COLLADASaxFWL15::exp__AttributeData& attributeData );

virtual bool end__exp();

virtual bool begin__ln( const COLLADASaxFWL15::ln__AttributeData& attributeData );

virtual bool end__ln();

virtual bool begin__min____Arith_type( const COLLADASaxFWL15::min____Arith_type__AttributeData& attributeData );

virtual bool end__min____Arith_type();

virtual bool begin__max____Arith_type( const COLLADASaxFWL15::max____Arith_type__AttributeData& attributeData );

virtual bool end__max____Arith_type();

virtual bool begin__ceiling( const COLLADASaxFWL15::ceiling__AttributeData& attributeData );

virtual bool end__ceiling();

virtual bool begin__floor( const COLLADASaxFWL15::floor__AttributeData& attributeData );

virtual bool end__floor();

virtual bool begin__gcd( const COLLADASaxFWL15::gcd__AttributeData& attributeData );

virtual bool end__gcd();

virtual bool begin__lcm( const COLLADASaxFWL15::lcm__AttributeData& attributeData );

virtual bool end__lcm();

virtual bool begin__rem( const COLLADASaxFWL15::rem__AttributeData& attributeData );

virtual bool end__rem();

virtual bool begin__root( const COLLADASaxFWL15::root__AttributeData& attributeData );

virtual bool end__root();

virtual bool begin__log( const COLLADASaxFWL15::log__AttributeData& attributeData );

virtual bool end__log();

virtual bool begin__logbase( const COLLADASaxFWL15::logbase__AttributeData& attributeData );

virtual bool end__logbase();

virtual bool begin__sin( const COLLADASaxFWL15::sin__AttributeData& attributeData );

virtual bool end__sin();

virtual bool begin__cos( const COLLADASaxFWL15::cos__AttributeData& attributeData );

virtual bool end__cos();

virtual bool begin__tan( const COLLADASaxFWL15::tan__AttributeData& attributeData );

virtual bool end__tan();

virtual bool begin__cot( const COLLADASaxFWL15::cot__AttributeData& attributeData );

virtual bool end__cot();

virtual bool begin__sec( const COLLADASaxFWL15::sec__AttributeData& attributeData );

virtual bool end__sec();

virtual bool begin__csc( const COLLADASaxFWL15::csc__AttributeData& attributeData );

virtual bool end__csc();

virtual bool begin__arcsin( const COLLADASaxFWL15::arcsin__AttributeData& attributeData );

virtual bool end__arcsin();

virtual bool begin__arccos( const COLLADASaxFWL15::arccos__AttributeData& attributeData );

virtual bool end__arccos();

virtual bool begin__arctan( const COLLADASaxFWL15::arctan__AttributeData& attributeData );

virtual bool end__arctan();

virtual bool begin__arccot( const COLLADASaxFWL15::arccot__AttributeData& attributeData );

virtual bool end__arccot();

virtual bool begin__arcsec( const COLLADASaxFWL15::arcsec__AttributeData& attributeData );

virtual bool end__arcsec();

virtual bool begin__arccsc( const COLLADASaxFWL15::arccsc__AttributeData& attributeData );

virtual bool end__arccsc();

virtual bool begin__sinh( const COLLADASaxFWL15::sinh__AttributeData& attributeData );

virtual bool end__sinh();

virtual bool begin__cosh( const COLLADASaxFWL15::cosh__AttributeData& attributeData );

virtual bool end__cosh();

virtual bool begin__tanh( const COLLADASaxFWL15::tanh__AttributeData& attributeData );

virtual bool end__tanh();

virtual bool begin__sech( const COLLADASaxFWL15::sech__AttributeData& attributeData );

virtual bool end__sech();

virtual bool begin__csch( const COLLADASaxFWL15::csch__AttributeData& attributeData );

virtual bool end__csch();

virtual bool begin__coth( const COLLADASaxFWL15::coth__AttributeData& attributeData );

virtual bool end__coth();

virtual bool begin__arcsinh( const COLLADASaxFWL15::arcsinh__AttributeData& attributeData );

virtual bool end__arcsinh();

virtual bool begin__arccosh( const COLLADASaxFWL15::arccosh__AttributeData& attributeData );

virtual bool end__arccosh();

virtual bool begin__arctanh( const COLLADASaxFWL15::arctanh__AttributeData& attributeData );

virtual bool end__arctanh();

virtual bool begin__arcsech( const COLLADASaxFWL15::arcsech__AttributeData& attributeData );

virtual bool end__arcsech();

virtual bool begin__arccsch( const COLLADASaxFWL15::arccsch__AttributeData& attributeData );

virtual bool end__arccsch();

virtual bool begin__arccoth( const COLLADASaxFWL15::arccoth__AttributeData& attributeData );

virtual bool end__arccoth();


private:
/** Disable default copy ctor. */
FormulasLoader15(const FormulasLoader15&);
/** Disable default assignment operator. */
const FormulasLoader15& operator=(const FormulasLoader15&);
};
}
#endif // __COLLADASAXFWL_FORMULASLOADER15_H__
