/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWFormula.h"

#include "MathMLASTNode.h"


namespace COLLADAFW
{
    //------------------------------
    Formula::Formula( const UniqueId& uniqueId )
        : ObjectTemplate<COLLADA_TYPE::FORMULA> ( uniqueId )
		, mMathmlAsts( MathmlAstArray::OWNER )
    {
    }

	//------------------------------
	Formula::Formula( const Formula& rhs, ASTNodeASTNodeMap& originalClonedASTNodeMap )
		: ObjectTemplate<COLLADA_TYPE::FORMULA> ( rhs )
		, mNewParams(rhs.mNewParams)
		, mMathmlAsts( MathmlAstArray::OWNER )
		, mOriginalId(rhs.mOriginalId)
		, mName(rhs.mName)
	{
		// We clone the entire ast, but do not deep clone the fragment expression. They are set in a second step
		// to the node of the cloned corresponding formula node.

		// first step: clone ast
		size_t mMathmlAstsCount = rhs.mMathmlAsts.getCount();
		mMathmlAsts.reallocMemory(mMathmlAstsCount);
		for ( size_t i = 0; i < mMathmlAstsCount; ++i )
		{
			MathML::AST::INode* originalASTNode = rhs.mMathmlAsts[i];
			MathML::AST::INode* clonedASTNode = rhs.mMathmlAsts[i]->clone( MathML::AST::INode::CLONEFLAG_DEEPCOPY_FRAGMENT_PARAMS );
			mMathmlAsts[i] = clonedASTNode;
			originalClonedASTNodeMap.insert(std::make_pair( originalASTNode, clonedASTNode ));
		}
		mMathmlAsts.setCount(mMathmlAstsCount);

	}

    //------------------------------
    Formula::~Formula()
    {
        for (size_t i=0; i<mMathmlAsts.getCount(); ++i)
        {
            FW_DELETE mMathmlAsts[ i ];
        }
    }

} // namespace COLLADAFW
