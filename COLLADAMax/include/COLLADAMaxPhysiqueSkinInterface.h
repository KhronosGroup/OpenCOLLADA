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

#ifndef __COLLADAMAX_PHYSIQUESKININTERFACE_H__
#define __COLLADAMAX_PHYSIQUESKININTERFACE_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxISkinInterface.h"

#include "cs/Phyexp.h"

#include <map>
#include <vector>


namespace COLLADAMax
{

	class PhysiqueSkinInterface : public ISkinInterface
	{
	private:
		INode* mInode;
		Modifier* mModifier;
		IPhysiqueExport* mModifierInterface;
		IPhyContextExport* mSkinContext;

		int mNumBones;
		std::map<INode*, int> mBonesMap;
		std::vector<INode*> mBonesList;

	public:
		PhysiqueSkinInterface(Modifier* modifier, INode* node);

		~PhysiqueSkinInterface();
		void releaseMe();

		bool getSkinInitTM(Matrix3 &initTM, bool bObjOffset = false);
		bool getBoneInitTM(INode* mInode, Matrix3 &boneInitTM);

		int getNumBones();
		INode* getBone(int i);

		int getNumVertices();
		int getNumAssignedBones(int i);
		float getBoneWeight(int vertexIdx, int boneIdx);
		int getAssignedBone(int vertexIdx, int boneIdx);

	private:
		int getBonesListIdx(INode* mInode);
		void fillBoneMap(INode* parentNode);
		void scaleBiped(INode* mInode, int scale);
	};




} // namespace COLLADAMAX

#endif // __COLLADAMAX_PHYSIQUESKININTERFACE_H__
