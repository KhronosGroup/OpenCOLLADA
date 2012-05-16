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
#include "COLLADAMaxPhysiqueSkinInterface.h"


namespace COLLADAMax
{

	PhysiqueSkinInterface::PhysiqueSkinInterface(Modifier *modifier, INode *node)
		: mInode( node )
		, mModifier( modifier )
		, mModifierInterface( mModifier ? (IPhysiqueExport*)mModifier->GetInterface(I_PHYINTERFACE) : 0)
		, mSkinContext( ( mInode && mModifierInterface) ? mModifierInterface->GetContextInterface(mInode) : 0)
		, mNumBones( 0 )
	{
		assert( mModifier );
		assert( mModifierInterface );
		assert( !node || mSkinContext );


		if ( mSkinContext )
		{
			// Now, Physique does'nt provide a way for us to list
			// all our bones nicely, so try and find all our info here.

			//convert to rigid for time independent vertex assignment
			mSkinContext->ConvertToRigid(TRUE);

			//allow blending to export multi-link assignments
			mSkinContext->AllowBlending(true);

			// Attempt to find all Physique bone nodes by using its MATRIX_RETURNED
			// inherent hierarchical nature - ie find the root
			// bone, by definition all children are physique nodes too

			if (mSkinContext->GetNumberVertices() > 0)
			{
				Matrix3 ignored;
				INode *nextNode, *rootNode = 0;
				IPhyVertexExport *vtxExport = mSkinContext->GetVertexInterface(0);
				if (vtxExport)
				{
					//need to check if vertex has blending
					if (vtxExport->GetVertexType() & BLENDED_TYPE)
					{
						IPhyBlendedRigidVertex *vtxBlend = (IPhyBlendedRigidVertex *)vtxExport;
						rootNode = vtxBlend->GetNode(0);
					}
					else
					{
						IPhyRigidVertex *vtxNoBlend = (IPhyRigidVertex *)vtxExport;
						rootNode = vtxNoBlend->GetNode();
					}
					mSkinContext->ReleaseVertexInterface(vtxExport);
				}

				if (rootNode != NULL)
				{
					nextNode = rootNode->GetParentNode();
					while (nextNode != NULL && !nextNode->IsRootNode())
					{
						if (mModifierInterface->GetInitNodeTM(nextNode, ignored) == NODE_NOT_FOUND)
							break;

						rootNode = nextNode;
						nextNode = rootNode->GetParentNode();
					}

					// now we have a root node, turn around and add all children to our nodeList.
					//mBonesMap[rootNode] = 1;
					fillBoneMap(rootNode);
				}
			}
			size_t blsize = mBonesList.size();
			size_t bmsize = mBonesMap.size();
			size_t nbsize = (size_t)mNumBones;
			assert(blsize == bmsize && nbsize == bmsize);
		}

	}

	// Release our interfaces on death
	PhysiqueSkinInterface::~PhysiqueSkinInterface()
	{
		// Are we all released?
		assert( !mSkinContext );
		assert( !mModifierInterface );
	}

	void PhysiqueSkinInterface::releaseMe()
	{
		mModifierInterface->ReleaseContextInterface(mSkinContext);
		mSkinContext = 0;
		mModifier->ReleaseInterface(I_PHYINTERFACE, mModifierInterface);
		mModifierInterface = 0;
		// when we are all released, delete ourselves
		delete this;
	}

	bool PhysiqueSkinInterface::getSkinInitTM(Matrix3 &initTM, bool bObjOffset)
	{
		// We should really allow some errors.
		bObjOffset = bObjOffset;
		return mModifierInterface->GetInitNodeTM(mInode, initTM) == MATRIX_RETURNED;
	}

	int PhysiqueSkinInterface::getNumBones()
	{
		//return mBonesList.Count();
		return mNumBones;
	}

	INode *PhysiqueSkinInterface::getBone(int i)
	{
		return mBonesList[i];
	}

	bool PhysiqueSkinInterface::getBoneInitTM(INode *mInode, Matrix3 &boneInitTM)
	{
		return mModifierInterface->GetInitNodeTM(mInode, boneInitTM) == MATRIX_RETURNED;
	}

	int PhysiqueSkinInterface::getNumVertices()
	{
		return mSkinContext->GetNumberVertices();
	}

	int PhysiqueSkinInterface::getNumAssignedBones(int i)
	{
		int retval = 0;

		IPhyVertexExport *vtxExport = mSkinContext->GetVertexInterface(i);
		if (vtxExport)
		{
			if (vtxExport->GetVertexType() & BLENDED_TYPE)
			{
				IPhyBlendedRigidVertex *vtxBlend = (IPhyBlendedRigidVertex *)vtxExport;
				retval = vtxBlend->GetNumberNodes();
			}
			else
			{
				retval = 1;
			}
			mSkinContext->ReleaseVertexInterface(vtxExport);
		}
		return retval;
	}

	float PhysiqueSkinInterface::getBoneWeight(int vertexIdx, int boneIdx)
	{
		float retval = 0.0f;

		IPhyVertexExport *vtxExport = mSkinContext->GetVertexInterface(vertexIdx);
		if (vtxExport)
		{
			if (vtxExport->GetVertexType() & BLENDED_TYPE)
			{
				IPhyBlendedRigidVertex *vtxBlend = (IPhyBlendedRigidVertex *)vtxExport;
				retval = vtxBlend->GetWeight(boneIdx);
			}
			else
			{
				if (boneIdx == 0) 
					retval = 1.0f;
			}
			mSkinContext->ReleaseVertexInterface(vtxExport);
		}
		return retval;
	}

	int PhysiqueSkinInterface::getAssignedBone(int vertexIdx, int boneIdx)
	{
		int retval = -1;
		IPhyVertexExport *vtxExport = mSkinContext->GetVertexInterface(vertexIdx);
		if (vtxExport)
		{
			if (vtxExport->GetVertexType() & BLENDED_TYPE)
			{
				IPhyBlendedRigidVertex *vtxBlend = (IPhyBlendedRigidVertex *)vtxExport;
				retval = getBonesListIdx(vtxBlend->GetNode(boneIdx));
			}
			else
			{
				IPhyRigidVertex *vtxBlend = (IPhyRigidVertex *)vtxExport;
				if (boneIdx == 0) retval = getBonesListIdx(vtxBlend->GetNode());
			}
			mSkinContext->ReleaseVertexInterface(vtxExport);
		}
		assert(retval >= 0);
		return retval;
	}

	/** private methods **/

	int PhysiqueSkinInterface::getBonesListIdx(INode *mInode)
	{
		std::map<INode*, int>::iterator itr = mBonesMap.find(mInode);
		if (itr != mBonesMap.end())
			return (*itr).second;
		return -1;
		/*	for (int j = 0; j < mBonesList.Count(); j++)
		{
		if (mBonesList[j] == node)
		return j;
		}
		return -1; */
	}

	void PhysiqueSkinInterface::fillBoneMap(INode* parentNode)
	{
		if ( !parentNode )
			return;

		//If the bone is a biped bone, scale needs to be
		//restored before exporting skin data 
		scaleBiped(parentNode, 0);

		mBonesMap[parentNode] = (int)mNumBones++;
		mBonesList.push_back(parentNode);

		int numChildren = parentNode->NumberOfChildren();
		for (int i = 0; i < numChildren; i++)
		{
			fillBoneMap(parentNode->GetChildNode(i));
		}
	}

	// Taken from PhyExportSample
	//
	// This function can be used to set the non-uniform scale of a biped.
	// The node argument should be a biped node.
	// If the scale argument is non-zero the non-uniform scale will be removed from the biped.
	// Remove the non-uniform scale before exporting biped nodes and animation data
	// If the scale argument is zero the non-uniform scaling will be reapplied to the biped.
	// Add the non-uniform scaling back on the biped before exporting skin data
	//***********************************************************************************
	void PhysiqueSkinInterface::scaleBiped(INode* mInode, int scale)
	{
		if (mInode->IsRootNode()) return;

		// Use the class ID to check to see if we have a biped node
		Control* c = mInode->GetTMController();
		if ((c->ClassID() == BIPSLAVE_CONTROL_CLASS_ID) ||
			(c->ClassID() == BIPBODY_CONTROL_CLASS_ID) ||
			(c->ClassID() == FOOTPRINT_CLASS_ID))
		{

			// Get the Biped Export Interface from the controller 
			IBipedExport *BipIface = (IBipedExport *) c->GetInterface(I_BIPINTERFACE);

			// Either remove the non-uniform scale from the biped, 
			// or add it back in depending on the boolean scale value
			BipIface->RemoveNonUniformScale(scale);
			Control* iMaster = (Control *) c->GetInterface(I_MASTER);
			iMaster->NotifyDependents(FOREVER, PART_TM, REFMSG_CHANGE);

			// Release the interfaces
			c->ReleaseInterface(I_MASTER,iMaster);
			c->ReleaseInterface(I_BIPINTERFACE,BipIface);
		}
	}

} // namespace COLLADAMax
