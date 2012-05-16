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

#ifndef __COLLADAMAX_SKININTERFACE_H__
#define __COLLADAMAX_SKININTERFACE_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxISkinInterface.h"

class INode;
class Modifier;
class ISkin;
class ISkinContextData;


namespace COLLADAMax
{

	/*
	*  Skin modifier wrapper
	*  CAUTION - This should only be used for the node its
	*  instantiated for.
	*/

	class SkinInterface : public ISkinInterface
	{
	private:
		INode* mInode;
		Modifier* mModifier;
		ISkin* mModifierInterface;
		ISkinContextData* mSkinContext;

	public:
		SkinInterface(Modifier* modifier ,INode* node );

		~SkinInterface();
		void releaseMe();

		bool getSkinInitTM(Matrix3 &initTM, bool bObjOffset = false);
		bool getBoneInitTM(INode* node, Matrix3 &boneInitTM);

		int getNumBones();
		INode* getBone(int i);

		int getNumVertices();
		int getNumAssignedBones(int i);
		float getBoneWeight(int vertexIdx, int boneIdx);
		int getAssignedBone(int vertexIdx, int boneIdx);
	};


} // namespace COLLADAMAX

#endif // __COLLADAMAX_SKININTERFACE_H__
