/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_SIDTREENODE_H__
#define __COLLADASAXFWL_SIDTREENODE_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADAFWAnimatable.h"
#include "COLLADAFWObject.h"

#include <map>
#include <vector>

namespace COLLADASaxFWL
{

	class IntermediateTargetable;

    /** The SidTreeNode is used to build the Sid tree. The Sid tree  represents the parent child relation between elements
	that can have sids. This tree is used to resolve sids.
	TODO the sid node tree currently does not support multiple occurrences of an sid on the same hierarchy in different 
	techniques.
	*/
	class SidTreeNode 	
	{
	public:
		struct SidIdentifier
		{
			SidIdentifier( const String& _sid, size_t _hierarchyLevel)
				: sid(_sid), hierarchyLevel(_hierarchyLevel){}

			const String& sid;

			/** Defines how deep in the hierarchy the node is placed. For the determination of the hierarchy level
			only elements with an sid are considered.*/
			size_t hierarchyLevel;

			bool operator<(const SidIdentifier& rhs)const;
		};

		typedef std::map< SidIdentifier, SidTreeNode*> SidIdentifierSidTreeNodeMap;

		typedef std::vector< SidTreeNode*> SidTreeNodeList;

		enum TargetTypeClass
		{
			TARGETTYPECLASS_UNKNOWN,
			TARGETTYPECLASS_OBJECT,
			TARGETTYPECLASS_ANIMATABLE,
			TARGETTYPECLASS_INTERMEDIATETARGETABLE
		};

	private:
		union Target
		{
			COLLADAFW::Animatable * animatable;
			COLLADAFW::Object * object;
			IntermediateTargetable * intermediateTargetable;
		};

	private:
		/** The parent node.*/
		SidTreeNode *mParent;

		/** Maps sids to the children. One sid can appear more than once, since COLLADA allows sids to appear more than once
		in different technique elements of the same parent.*/
		SidIdentifierSidTreeNodeMap mChildren;

		/** List of all direct children. Is used to delete all of them.*/
		SidTreeNodeList mDirectChildren;

		/** The target the sid points to. Different types of targets are supported. @see mTargetType*/
		Target mTarget;

		/** The type of the target.*/
		TargetTypeClass mTargetType;

		/** The sid of the node.*/
		String mSid;
	public:

        /** Constructor. */
		SidTreeNode( const String& sid, SidTreeNode *mParent);

        /** Destructor. */
		virtual ~SidTreeNode();

		/** Returns the parent.*/
		SidTreeNode * getParent() { return mParent; }

		/** Returns the type of the target.*/
		TargetTypeClass getTargetType() const { return mTargetType; }

		/** Sets the type of the target.*/
		void setTargetType(TargetTypeClass targetType) { mTargetType = targetType; }

		/** Returns the target, if it is an object, null otherwise.*/
		COLLADAFW::Object* getObjectTarget() const { return (mTargetType==TARGETTYPECLASS_OBJECT) ? mTarget.object : 0; }

		/** Returns the target, if it is an animatable, null otherwise.*/
		COLLADAFW::Animatable* getAnimatableTarget() const { return (mTargetType==TARGETTYPECLASS_ANIMATABLE) ? mTarget.animatable: 0; }

		/** Returns the target, if it is a IntermediateTargetable, null otherwise.*/
		IntermediateTargetable* getIntermediateTargetableTarget() const { return (mTargetType==TARGETTYPECLASS_INTERMEDIATETARGETABLE) ? mTarget.intermediateTargetable : 0; }

		/** Sets the target to @a target and the target type to @a TARGETTYPECLASS_OBJECT.*/
		void setTarget(COLLADAFW::Object* target) { mTarget.object = target; mTargetType = TARGETTYPECLASS_OBJECT; }

		/** Sets the target to @a target and the target type to @a TARGETTYPECLASS_ANIMATABLE.*/
		void setTarget(COLLADAFW::Animatable* target) { mTarget.animatable = target; mTargetType = TARGETTYPECLASS_ANIMATABLE; }

		/** Sets the target to @a target and the target type to @a TARGETTYPECLASS_ANIMATABLE.*/
		void setTarget(IntermediateTargetable* target) { mTarget.intermediateTargetable= target; mTargetType = TARGETTYPECLASS_INTERMEDIATETARGETABLE; }

		/** Creates a new child with sid @a sid and adds it to the list of children. */
		SidTreeNode* createAndAddChild( const String& sid);

		/** Returns the sid.*/
		const String& getSid() const { return mSid; };

		/** Searches for a child with @a sid in the entire sub hierarchy. If there exist more then one child with @a sid, 
		the one with the lowest hierarchy level is returned. If no child could be found, null is returned.*/
		SidTreeNode* findChildBySid( const String& sid);


	private:

        /** Disable default copy ctor. */
		SidTreeNode( const SidTreeNode& pre );

        /** Disable default assignment operator. */
		const SidTreeNode& operator= ( const SidTreeNode& pre );

		/** Adds @a sidTreeNode to the children map of all the parent nodes. For each level in the hierarchy */
		void addChildToParents( SidTreeNode *sidTreeNode, const SidIdentifier& sidIdentifier);

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_SIDTREENODE_H__
