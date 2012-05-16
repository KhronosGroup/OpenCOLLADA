/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_FORMULASLOADER_H__
#define __COLLADASAXFWL_FORMULASLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLXmlTypes.h"
#include "COLLADASaxFWLHelperLoaderBase.h"

#include "COLLADAFWFormula.h"

#include <stack>
#include <vector>


// forward declarations
namespace MathML
{
	namespace AST
	{
		class INode;
		class ConstantExpression;
	}
}



namespace COLLADASaxFWL
{

	/** MathML operators and functions. */
	enum Operator
	{
		/** arithmetic operators. */
		ADD,
		SUB,
		MUL,
		DIV,

		/** logic operators. */
		NOT,
		AND,
		OR,
		XOR,

		/** relation operators. */
		EQ,
		NEQ,
		LT,
		LTE,
		GT,
		GTE,

		/** basic functions. */
		POW,
		FACTORIAL,
		ABS,
		EXP,
		LN,
		MIN,
		MAX,
		CEIL,
		FLOOR,
		GCD,
		LCM,
		REM,
		ROOT,
		LOG,

		/** trigonometric functions. */
		SIN,
		COS,
		TAN,
		SEC,
		CSC,
		COT,
		ARCSIN,
		ARCCOS,
		ARCTAN,
		ARCSEC,
		ARCCSC,
		ARCCOT,
		SINH,
		COSH,
		TANH,
		SECH,
		CSCH,
		COTH,
		ARCSINH,
		ARCCOSH,
		ARCTANH,
		ARCCOTH,
		ARCSECH,
		ARCCSCH,

		/** A function defined via MathML in the COLLADA file. */
		USER_DEFINED_FUNCTION
	};
	typedef std::vector< MathML::AST::INode* > NodeVector;
	typedef std::stack< NodeVector > NodeListStack;
	typedef std::stack< Operator > OperatorStack;


    /** Base class for all libraries that can contain formulas */
	class FormulasLoader : public HelperLoaderBase
		{
		private:
			/** The current formula. */
			COLLADAFW::Formula* mCurrentFormula;

			/** Stack of node lists. */
			NodeListStack mNodeListStack;

			/** Stack of operators. */
			OperatorStack mOperatorStack;

			/** Contains current Text data. May be used for cn/ci/csymbol. */
			String mCurrentTextData;

			/** Contains current Text data after <sep /> occurred. */
			String mCurrentTextDataAfterSep;

			/** Indicates if <sep /> was present inside <cn>. */
			bool mSepOccurred;

			/** Unique id of the function referenced by the current csymbol.*/
			COLLADAFW::UniqueId mCurrentCSymbolFunctionUniqueId;

			/** True if the currently open <csymbol> is a function, if none is open or it is not a function,
			it is false.*/
			bool mCurrentCSymbolIsFunction;

			/** True if a child of the last opened <apply> has been parsed. False otherwise.*/
			bool mCurrentApplyHasChild;

			/** True if we are within a new param element.*/
			bool mWithinNewParam;

			/** The formula new param currently being parsed.*/
			COLLADAFW::FormulaNewParam* mCurrentFormulaNewParam;

			/** The sid of the current new param.*/
			String mCurrentFormulaNewParamSid;

	
	public:

        /** Constructor. */
		FormulasLoader();

        /** Destructor. */
		virtual ~FormulasLoader();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();

		/** Creates a new formula.*/
		virtual bool begin__formula( const formula__AttributeData& attributeData );

		/** Sends formula to the writer.*/
		virtual bool end__formula();

		/**
		* TODO add parameters and target to FW Formula.
		* Do it in a way that <csymbol encoding="COLLADA">s can easily be resolved.
		* <csymbol type="function">s are referencing <formula>s from <library_formula>
		* these must be resolved and mapped to a AST::FragmentExpression.
		* The 'type' attribute of <csymbol> is not present in XSD.
		* Use unknownAttributes member of AttributeData struct.
		*/
		virtual bool begin__newparam( const formula_newparam_type__AttributeData& attributeData );
		virtual bool end__newparam();

		virtual bool begin__target(){return true;}
		virtual bool end__target(){return true;}

		virtual bool begin__param(){return true;}
		virtual bool end__param(){return true;}
		virtual bool data__param( const ParserChar* value, size_t length ){return true;}

		virtual bool begin__float();
		virtual bool end__float();
		virtual bool data__float( float value );

		virtual bool begin__int();
		virtual bool end__int();
		virtual bool data__int( int value );

		virtual bool begin__bool();
		virtual bool end__bool();
		virtual bool data__bool( bool value );

		virtual bool begin__technique_common(){return true;}
		virtual bool end__technique_common(){return true;}


		/** Pushes a new node list on node list stack. */
		virtual bool begin__math( const math__AttributeData& attributeData );
		/** Adds an MathML AST to current formula. */
		virtual bool end__math();

		/** Pushes a new node list on node list stack. */
		virtual bool begin__apply( const apply__AttributeData& attributeData );
		/** Creates a MathML AST and adds it to an appropriate NodeList. */
		virtual bool end__apply();

		/** Ignored. */
		virtual bool begin__cn( const cn__AttributeData& attributeData );
		/** 
		* Creates a ConstantExpression with mCurrentTextData
		* and adds it to top node list on stack.
		* Resets mSepOccurred.
		*/
		virtual bool end__cn();
		/** Appends text to mCurrentTextData. */
		virtual bool data__cn( const ParserChar* value, size_t length );

		/** Sets mSepOccurred. */
		virtual bool begin__sep(){mSepOccurred=true; return true;}
		/** Ignored. */
		virtual bool end__sep(){return true;}

		/** Ignored. */
		virtual bool begin__ci( const ci__AttributeData& attributeData );
		/** 
		* Creates a VariableExpression with mCurrentTextData
		* and adds it to top node list on stack.
		*/
		virtual bool end__ci();
		/** Appends text to mCurrentTextData. */
		virtual bool data__ci( const ParserChar* value, size_t length );

		/**
		* TODO create AST::VariableExpression or AST::FragmentExpression.
		*/
		/** We do not need to do anything here.*/
		virtual bool begin__csymbol( const csymbol__AttributeData& attributeData );
		/** 
		* Creates a COLLADACsymbol with mCurrentTextData
		* and adds it to top node list on stack.
		*/
		virtual bool end__csymbol();
		/** Appends text to mCurrentTextData. */
		virtual bool data__csymbol( const ParserChar* value, size_t length );

		/** 
		* As COLLADA uses it's own <formula> element to declare functions,
		* MathML <declare> is ignored.
		*/
		virtual bool begin__declare( const declare__AttributeData& attributeData ){return true;}
		virtual bool end__declare(){return true;}

		/** Creates a ConstantExpression with appropriate value. */
		virtual bool begin__exponentiale( const exponentiale__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__exponentiale(){return true;}

		/** Creates a ConstantExpression with appropriate value. */
		virtual bool begin__pi( const pi__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__pi(){return true;}

		/** Creates a ConstantExpression with appropriate value. */
		virtual bool begin__true( const true__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__true(){return true;}

		/** Creates a ConstantExpression with appropriate value. */
		virtual bool begin__false( const false__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__false(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__quotient( const quotient__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__quotient(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__divide( const divide__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__divide(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__times( const times__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__times(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__minus( const minus__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__minus(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__plus( const plus__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__plus(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__sum( const sum__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__sum(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__product( const product__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__product(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__and( const and__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__and(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__or( const or__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__or(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__xor( const xor__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__xor(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__not( const not__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__not(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__eq( const eq__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__eq(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__neq( const neq__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__neq(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__leq( const leq__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__leq(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__lt( const lt__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__lt(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__geq( const geq__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__geq(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__gt( const gt__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__gt(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__equivalent( const equivalent__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__equivalent(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__abs( const abs__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__abs(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__factorial( const factorial__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__factorial(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__floor( const floor__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__floor(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__ceiling( const ceiling__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__ceiling(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__rem( const rem__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__rem(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__power( const power__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__power(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__root( const root__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__root(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__max( const max__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__max(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__min( const min__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__min(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__gcd( const gcd__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__gcd(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__lcm( const lcm__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__lcm(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__exp( const exp__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__exp(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__ln( const ln__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__ln(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__log( const log__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__log(){return true;}

		/** Pushes a new node list on node list stack. */
		virtual bool begin__logbase( const logbase__AttributeData& attributeData );
		/** Adds first node of top node list to an appropriate NodeList. */
		virtual bool end__logbase();

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__sin( const sin__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__sin(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__cos( const cos__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__cos(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__tan( const tan__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__tan(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__sec( const sec__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__sec(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__csc( const csc__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__csc(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__cot( const cot__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__cot(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__arcsin( const arcsin__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__arcsin(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__arccos( const arccos__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__arccos(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__arctan( const arctan__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__arctan(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__arcsec( const arcsec__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__arcsec(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__arccsc( const arccsc__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__arccsc(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__arccot( const arccot__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__arccot(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__sinh( const sinh__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__sinh(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__cosh( const cosh__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__cosh(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__tanh( const tanh__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__tanh(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__sech( const sech__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__sech(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__csch( const csch__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__csch(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__coth( const coth__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__coth(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__arccosh( const arccosh__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__arccosh(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__arccoth( const arccoth__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__arccoth(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__arccsch( const arccsch__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__arccsch(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__arcsech( const arcsech__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__arcsech(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__arcsinh( const arcsinh__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__arcsinh(){return true;}

		/** Pushes an operator on mOperatorStack. */
		virtual bool begin__arctanh( const arctanh__AttributeData& attributeData );
		/** Ignored. */
		virtual bool end__arctanh(){return true;}


		/////////////////////////////////////////////////
		// The following SAX calls are ignored
		/////////////////////////////////////////////////

		virtual bool begin__conjugate( const conjugate__AttributeData& attributeData ){return true;}
		virtual bool end__conjugate(){return true;}

		virtual bool begin__arg( const arg__AttributeData& attributeData ){return true;}
		virtual bool end__arg(){return true;}

		virtual bool begin__real( const real__AttributeData& attributeData ){return true;}
		virtual bool end__real(){return true;}

		virtual bool begin__imaginary( const imaginary__AttributeData& attributeData ){return true;}
		virtual bool end__imaginary(){return true;}

		virtual bool begin__compose( const compose__AttributeData& attributeData ){return true;}
		virtual bool end__compose(){return true;}

		virtual bool begin__domain( const domain__AttributeData& attributeData ){return true;}
		virtual bool end__domain(){return true;}

		virtual bool begin__codomain( const codomain__AttributeData& attributeData ){return true;}
		virtual bool end__codomain(){return true;}

		virtual bool begin__image____Functions_type( const image____Functions_type__AttributeData& attributeData ){return true;}
		virtual bool end__image____Functions_type(){return true;}

		virtual bool begin__domainofapplication( const domainofapplication__AttributeData& attributeData ){return true;}
		virtual bool end__domainofapplication(){return true;}

		virtual bool begin__ident( const ident__AttributeData& attributeData ){return true;}
		virtual bool end__ident(){return true;}

		virtual bool begin__exists( const exists__AttributeData& attributeData ){return true;}
		virtual bool end__exists(){return true;}

		virtual bool begin__forall( const forall__AttributeData& attributeData ){return true;}
		virtual bool end__forall(){return true;}

		virtual bool begin__implies( const implies__AttributeData& attributeData ){return true;}
		virtual bool end__implies(){return true;}

		virtual bool begin__naturalnumbers( const naturalnumbers__AttributeData& attributeData ){return true;}
		virtual bool end__naturalnumbers(){return true;}

		virtual bool begin__primes( const primes__AttributeData& attributeData ){return true;}
		virtual bool end__primes(){return true;}

		virtual bool begin__integers( const integers__AttributeData& attributeData ){return true;}
		virtual bool end__integers(){return true;}

		virtual bool begin__rationals( const rationals__AttributeData& attributeData ){return true;}
		virtual bool end__rationals(){return true;}

		virtual bool begin__reals( const reals__AttributeData& attributeData ){return true;}
		virtual bool end__reals(){return true;}

		virtual bool begin__complexes( const complexes__AttributeData& attributeData ){return true;}
		virtual bool end__complexes(){return true;}

		virtual bool begin__emptyset( const emptyset__AttributeData& attributeData ){return true;}
		virtual bool end__emptyset(){return true;}

		virtual bool begin__imaginaryi( const imaginaryi__AttributeData& attributeData ){return true;}
		virtual bool end__imaginaryi(){return true;}

		virtual bool begin__eulergamma( const eulergamma__AttributeData& attributeData ){return true;}
		virtual bool end__eulergamma(){return true;}

		virtual bool begin__infinity( const infinity__AttributeData& attributeData ){return true;}
		virtual bool end__infinity(){return true;}

		virtual bool begin__notanumber( const notanumber__AttributeData& attributeData ){return true;}
		virtual bool end__notanumber(){return true;}

		virtual bool begin__set( const set__AttributeData& attributeData ){return true;}
		virtual bool end__set(){return true;}

		virtual bool begin__list( const list__AttributeData& attributeData ){return true;}
		virtual bool end__list(){return true;}

		virtual bool begin__union( const union__AttributeData& attributeData ){return true;}
		virtual bool end__union(){return true;}

		virtual bool begin__intersect( const intersect__AttributeData& attributeData ){return true;}
		virtual bool end__intersect(){return true;}

		virtual bool begin__in( const in__AttributeData& attributeData ){return true;}
		virtual bool end__in(){return true;}

		virtual bool begin__notin( const notin__AttributeData& attributeData ){return true;}
		virtual bool end__notin(){return true;}

		virtual bool begin__subset( const subset__AttributeData& attributeData ){return true;}
		virtual bool end__subset(){return true;}

		virtual bool begin__prsubset( const prsubset__AttributeData& attributeData ){return true;}
		virtual bool end__prsubset(){return true;}

		virtual bool begin__notsubset( const notsubset__AttributeData& attributeData ){return true;}
		virtual bool end__notsubset(){return true;}

		virtual bool begin__notprsubset( const notprsubset__AttributeData& attributeData ){return true;}
		virtual bool end__notprsubset(){return true;}

		virtual bool begin__setdiff( const setdiff__AttributeData& attributeData ){return true;}
		virtual bool end__setdiff(){return true;}

		virtual bool begin__card( const card__AttributeData& attributeData ){return true;}
		virtual bool end__card(){return true;}

		virtual bool begin__cartesianproduct( const cartesianproduct__AttributeData& attributeData ){return true;}
		virtual bool end__cartesianproduct(){return true;}

		virtual bool begin__approx( const approx__AttributeData& attributeData ){return true;}
		virtual bool end__approx(){return true;}

		virtual bool begin__factorof( const factorof__AttributeData& attributeData ){return true;}
		virtual bool end__factorof(){return true;}

		virtual bool begin__int____int_type____mathml( const int____int_type____mathml__AttributeData& attributeData ){return true;}
		virtual bool end__int____int_type____mathml(){return true;}

		virtual bool begin__diff( const diff__AttributeData& attributeData ){return true;}
		virtual bool end__diff(){return true;}

		virtual bool begin__partialdiff( const partialdiff__AttributeData& attributeData ){return true;}
		virtual bool end__partialdiff(){return true;}

		virtual bool begin__limit( const limit__AttributeData& attributeData ){return true;}
		virtual bool end__limit(){return true;}

		virtual bool begin__lowlimit( const lowlimit__AttributeData& attributeData ){return true;}
		virtual bool end__lowlimit(){return true;}

		virtual bool begin__uplimit( const uplimit__AttributeData& attributeData ){return true;}
		virtual bool end__uplimit(){return true;}

		virtual bool begin__tendsto( const tendsto__AttributeData& attributeData ){return true;}
		virtual bool end__tendsto(){return true;}

		virtual bool begin__vector( const vector__AttributeData& attributeData ){return true;}
		virtual bool end__vector(){return true;}

		virtual bool begin__matrix____matrix_type____mathml( const matrix____matrix_type____mathml__AttributeData& attributeData ){return true;}
		virtual bool end__matrix____matrix_type____mathml(){return true;}

		virtual bool begin__matrixrow( const matrixrow__AttributeData& attributeData ){return true;}
		virtual bool end__matrixrow(){return true;}

		virtual bool begin__determinant( const determinant__AttributeData& attributeData ){return true;}
		virtual bool end__determinant(){return true;}

		virtual bool begin__transpose( const transpose__AttributeData& attributeData ){return true;}
		virtual bool end__transpose(){return true;}

		virtual bool begin__selector( const selector__AttributeData& attributeData ){return true;}
		virtual bool end__selector(){return true;}

		virtual bool begin__vectorproduct( const vectorproduct__AttributeData& attributeData ){return true;}
		virtual bool end__vectorproduct(){return true;}

		virtual bool begin__scalarproduct( const scalarproduct__AttributeData& attributeData ){return true;}
		virtual bool end__scalarproduct(){return true;}

		virtual bool begin__outerproduct( const outerproduct__AttributeData& attributeData ){return true;}
		virtual bool end__outerproduct(){return true;}

		virtual bool begin__divergence( const divergence__AttributeData& attributeData ){return true;}
		virtual bool end__divergence(){return true;}

		virtual bool begin__grad( const grad__AttributeData& attributeData ){return true;}
		virtual bool end__grad(){return true;}

		virtual bool begin__curl( const curl__AttributeData& attributeData ){return true;}
		virtual bool end__curl(){return true;}

		virtual bool begin__laplacian( const laplacian__AttributeData& attributeData ){return true;}
		virtual bool end__laplacian(){return true;}

		virtual bool begin__mean( const mean__AttributeData& attributeData ){return true;}
		virtual bool end__mean(){return true;}

		virtual bool begin__sdev( const sdev__AttributeData& attributeData ){return true;}
		virtual bool end__sdev(){return true;}

		virtual bool begin__variance( const variance__AttributeData& attributeData ){return true;}
		virtual bool end__variance(){return true;}

		virtual bool begin__median( const median__AttributeData& attributeData ){return true;}
		virtual bool end__median(){return true;}

		virtual bool begin__mode____mode_type( const mode____mode_type__AttributeData& attributeData ){return true;}
		virtual bool end__mode____mode_type(){return true;}

		virtual bool begin__moment( const moment__AttributeData& attributeData ){return true;}
		virtual bool end__moment(){return true;}

		virtual bool begin__momentabout( const momentabout__AttributeData& attributeData ){return true;}
		virtual bool end__momentabout(){return true;}

		virtual bool begin__interval( const interval__AttributeData& attributeData ){return true;}
		virtual bool end__interval(){return true;}

		virtual bool begin__inverse( const inverse__AttributeData& attributeData ){return true;}
		virtual bool end__inverse(){return true;}

		virtual bool begin__condition( const condition__AttributeData& attributeData ){return true;}
		virtual bool end__condition(){return true;}

		virtual bool begin__lambda( const lambda__AttributeData& attributeData ){return true;}
		virtual bool end__lambda(){return true;}

		virtual bool begin__piecewise( const piecewise__AttributeData& attributeData ){return true;}
		virtual bool end__piecewise(){return true;}

		virtual bool begin__piece(){return true;}
		virtual bool end__piece(){return true;}

		virtual bool begin__bvar( const bvar__AttributeData& attributeData ){return true;}
		virtual bool end__bvar(){return true;}

		virtual bool begin__degree( const degree__AttributeData& attributeData ){return true;}
		virtual bool end__degree(){return true;}

		virtual bool begin__semantics( const semantics__AttributeData& attributeData ){return true;}
		virtual bool end__semantics(){return true;}

		virtual bool begin__annotation( const annotation__AttributeData& attributeData ){return true;}
		virtual bool end__annotation(){return true;}
		virtual bool data__annotation( const ParserChar* value, size_t length ){return true;}

		virtual bool begin__annotation_xml( const annotation_xml__AttributeData& attributeData ){return true;}
		virtual bool end__annotation_xml(){return true;}

		virtual bool begin__otherwise( const otherwise__AttributeData& attributeData ){return true;}
		virtual bool end__otherwise(){return true;}

	protected:
		/**
		* Creates a constant.
		* @param value Value of the constant.
		*/
		MathML::AST::ConstantExpression* createConstant( const String& value );

		/** 
		* Creates an operation with one operand.
		* @param nodes Parameter of the operation.
		* @param op Operator of the operation.
		*/
		virtual MathML::AST::INode* createUnaryOperation( const NodeVector& nodes, Operator op );

		/** 
		* Creates an operation with more than one operand.
		* @param nodes Parameters of the operation.
		* @param op Operator of the operation.
		*/
		virtual MathML::AST::INode* createMultiOperandOperation( const NodeVector& nodes, Operator op );

		/** 
		* Creates an arithmetic operation.
		* @param nodes Parameters of the operation.
		* @param op Operator of the operation.
		*/
		virtual MathML::AST::INode* createArithmeticOperation( const NodeVector& nodes, Operator op );

		/** 
		* Creates a logic operation.
		* @param nodes Parameters of the operation.
		* @param op Operator of the operation.
		*/
		virtual MathML::AST::INode* createLogicOperation( const NodeVector& nodes, Operator op );

		/** 
		* Creates a binary comparison operation.
		* @param nodes Parameters of the operation.
		* @param op Operator of the operation.
		*/
		virtual MathML::AST::INode* createBinaryComparisonOperation( const NodeVector& nodes, Operator op );

		/** 
		* Creates a function operation.
		* @param nodes Parameters of the function.
		* @param op Function code.
		*/
		virtual MathML::AST::INode* createFunctionOperation( const NodeVector& nodes, Operator op );

		/** 
		* Creates a user defined function operation.
		* @param nodes Parameters of the function.
		* @param op Function code.
		*/
		virtual MathML::AST::INode* createUserDefinedFunctionOperation( const NodeVector& nodes );

		/**
		* Finds out if given operator belongs to a function.
		* @param op Operator to check.
		* @return true if given operator is a function.
		*/
		virtual bool isFunction( Operator op );

		/** 
		* Adds given node to appropriate node list.
		* @param node New created node which shall be added to a list.
		* @return True on success.
		*/
		virtual bool appendNewNode( MathML::AST::INode* node );

	private:

        /** Disable default copy ctor. */
		FormulasLoader( const FormulasLoader& pre );

        /** Disable default assignment operator. */
		const FormulasLoader& operator= ( const FormulasLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_FORMULASLOADER_H__
