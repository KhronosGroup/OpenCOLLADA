/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxSkinInterface.h"

#include "max.h"
#include "iskin.h"

namespace COLLADAMax
{

	// ONLY CONSTRUCTOR: Assumes we have been called with correct
	// modifier
	SkinInterface::SkinInterface(Modifier *modifier, INode *node )
		: mInode( node )
		, mModifier( modifier ) 
		, mModifierInterface( modifier ? (ISkin*)mModifier->GetInterface(I_SKIN) : 0 )
		, mSkinContext( (node && mModifierInterface) ? mModifierInterface->GetContextInterface(node) : 0)
	{
		assert( mModifier );
		assert( mModifierInterface );
		assert( !node || mSkinContext );
	}

	// Release our interface on death
	SkinInterface::~SkinInterface()
	{
		// Check to make sure we are released
		// If we are not, someone has forgotten
		// about us!
		assert( !mModifierInterface );
	}

	void SkinInterface::releaseMe()
	{
		mModifier->ReleaseInterface(I_SKIN, (void*)mModifierInterface);
		mModifierInterface = 0;
		delete this;
	}

	bool SkinInterface::getSkinInitTM(Matrix3 &initTM, bool bObjOffset)
	{
		assert( mInode );
		return mModifierInterface->GetSkinInitTM(mInode, initTM, bObjOffset) == SKIN_OK;
	}

	int SkinInterface::getNumBones()
	{
		return mModifierInterface->GetNumBones();
	}

	INode *SkinInterface::getBone(int i)
	{
		return mModifierInterface->GetBone(i);
	}

	bool SkinInterface::getBoneInitTM(INode *node, Matrix3 &boneInitTM)
	{
		return mModifierInterface->GetBoneInitTM(node, boneInitTM) == SKIN_OK;
	}

	int SkinInterface::getNumVertices()
	{
		assert( mSkinContext );
		return mSkinContext->GetNumPoints();
	}

	int SkinInterface::getNumAssignedBones(int i)
	{
		assert( mSkinContext );
		return mSkinContext->GetNumAssignedBones(i);
	}

	float SkinInterface::getBoneWeight(int vertexIdx, int boneIdx)
	{
		assert( mSkinContext );
		return mSkinContext->GetBoneWeight(vertexIdx, boneIdx);
	}

	int SkinInterface::getAssignedBone(int vertexIdx, int boneIdx)
	{
		assert( mSkinContext );
		return mSkinContext->GetAssignedBone(vertexIdx, boneIdx);
	}


} // namespace COLLADAMax
