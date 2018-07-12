/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_FORMULA_H__
#define __COLLADAFW_FORMULA_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"
#include "COLLADAFWPointerArray.h"
#include "COLLADAFWFormulaNewParam.h"

#include <map>


namespace MathML
{
    namespace AST
    {
        class INode;
    }
}

namespace COLLADAFW
{
    /** An Array of MathML::AST pointers. */
    typedef ArrayPrimitiveType<MathML::AST::INode*> MathmlAstArray;

    /**
     * A mathematical formula description which uses MathML.
     */
    class Formula : public ObjectTemplate < COLLADA_TYPE::FORMULA >
    {
	public:
		typedef std::map<MathML::AST::INode*, MathML::AST::INode*> ASTNodeASTNodeMap;

	private:
	
		/** The new params, i.e. the parameters of the formula. They are referenced from within the ASTS elemenst,
		using the index in this array. */
		FormulaNewParamPointerArray mNewParams;

        /** Root of MathML ASTs representing this formula. */
        MathmlAstArray mMathmlAsts;

        /**
         * The original object id, if it in the original file format exist. 
         */
        String mOriginalId;

        /** The name of the formula. */
        String mName;

    public:

        /** @param objectId The object id of the formula. */
        Formula( const UniqueId& uniqueId );

        /** Destructor. */
        virtual ~Formula();

		/** Returns the new params, i.e. the parameters of the formula. They are referenced from within the ASTS elemenst,
		using the index in this array. */
		const FormulaNewParamPointerArray& getNewParams() const { return mNewParams; }

		/** Returns the new params, i.e. the parameters of the formula. They are referenced from within the ASTS elemenst,
		using the index in this array. */
		FormulaNewParamPointerArray& getNewParams() { return mNewParams; }

        /** Returns the Mathml Asts. */
        MathmlAstArray& getMathmlAsts() { return mMathmlAsts; }

        /** Returns the Mathml Asts. */
        const MathmlAstArray& getMathmlAsts() const { return mMathmlAsts; }

        /**
         * The original object id, if it in the original file format exist. 
         */
        const String& getOriginalId () const { return mOriginalId; }

        /**
         * The original object id, if it in the original file format exist. 
         */
        void setOriginalId ( const String& val ) { mOriginalId = val; }

        /** Returns the name of the formula. */
        const String& getName() const { return mName; }

        /** Returns the name of the formula. */
        void setName( const String& name ) { mName = name; }

    private:
		friend class Formulas;
        /** disable default copy ctor and assignment op. */
        Formula( const Formula& rhs );
		const Formula& operator=( const Formula& rhs );

		/** Special constructor to clone Formula that is within a Formulas object.*/
		Formula( const Formula& rhs, ASTNodeASTNodeMap& originalClonedASTNodeMap );

		Formula* clone( ASTNodeASTNodeMap& originalClonedASTNodeMap ) const { return FW_NEW Formula(*this, originalClonedASTNodeMap); }

	};

	typedef PointerArray<Formula> FormulaPointerArray;
	typedef ArrayPrimitiveType<Formula*> FormulaArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_FORMULA_H__
