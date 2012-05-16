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

#ifndef __COLLADAMAX_ISKININTERFACE_H__
#define __COLLADAMAX_ISKININTERFACE_H__

#include "COLLADAMaxPrerequisites.h"


namespace COLLADAMax
{

	/** Abstract wrapper class defines all the functionality we will want from 
	whatever skin classes we will work with.  To implement an
	interface for whatever skinnable modifier, inherit this class
	and implement its functions.*/

	class ISkinInterface
	{
	public:
		/* Call this function when you are done with this interface
		*  to release the skins back into the wild.  Will also delete
		*  this (the current class) so don't touch it again. */
		virtual void releaseMe()=0;

		/* Get the transform of the object
		*  when it was skinned */
		virtual bool getSkinInitTM(Matrix3 &initTM, bool bObjOffset = false)=0;

		/* Get the initial transform of the
		*  i'th bone when skinned */
		virtual bool getBoneInitTM(INode* node, Matrix3 &boneInitTM)=0;

		/* Get the number of bones affecting this skin */
		virtual int getNumBones()=0;

		/* Get the i'th bone */
		virtual INode* getBone(int i)=0;

		/** Vertex Methods* */

		/* Get the number of vertices' this
		*  modifier affects */
		virtual int getNumVertices()=0;

		/* Get the number of bones assigned
		*  to the i'th vertex */
		virtual int getNumAssignedBones(int i)=0;

		/* Get the bone weight of the binded
		*  bone on the vindex'ed vertex */
		virtual float getBoneWeight(int vertexIdx, int boneIdx)=0;

		/* Get the Joint index of the bindex bone on
		*  the vindex'ed vertex */
		virtual int getAssignedBone(int vertexIdx, int boneIdx)=0;
	};


} // namespace COLLADAMAX

#endif // __COLLADAMAX_ISKININTERFACE_H__
