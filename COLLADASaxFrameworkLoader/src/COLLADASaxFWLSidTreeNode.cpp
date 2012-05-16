/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSidTreeNode.h"

#include <iostream>

namespace COLLADASaxFWL
{


	//------------------------------
	bool SidTreeNode::SidIdentifier::operator<( const SidIdentifier& rhs ) const
	{
		if ( sid < rhs.sid)
			return true;

		if ( sid > rhs.sid)
			return false;

		if ( hierarchyLevel < rhs.hierarchyLevel)
			return true;

		if ( hierarchyLevel > rhs.hierarchyLevel)
			return false;

		return false;
	}

	//------------------------------
	SidTreeNode::SidTreeNode(const String& sid, SidTreeNode *parent)
		: mParent(parent)
		, mTargetType(TARGETTYPECLASS_UNKNOWN)
		, mSid(sid)
	{
		mTarget.object = 0;
	}

	//------------------------------
	SidTreeNode::~SidTreeNode()
	{
		for ( size_t i = 0, count = mDirectChildren.size(); i < count; ++i)
		{
			const SidTreeNode*const& sidTreeNode = mDirectChildren[i];
			delete sidTreeNode;
		}
	}

	//------------------------------
	SidTreeNode* SidTreeNode::createAndAddChild( const String& sid )
	{
		SidTreeNode* newChild = new SidTreeNode(sid, this);
		mDirectChildren.push_back(newChild);
		if ( !sid.empty() )
		{
			SidIdentifier newIdentifier(newChild->getSid(), 0);
			mChildren.insert(std::make_pair(newIdentifier, newChild));
			addChildToParents( newChild, newIdentifier );
		}
		return newChild;
	}

	//------------------------------
	void SidTreeNode::addChildToParents( SidTreeNode *sidTreeNode, const SidIdentifier& sidIdentifier )
	{
		if ( sidTreeNode )
		{
			SidTreeNode *parent = getParent();
			if ( parent )
			{
				SidIdentifier parentSidIdentifier = sidIdentifier;
				// if the parent has no sid, i.e. it has an id, we don't increase the hierarchy level.*/
				if ( !parent->getSid().empty() )
				{
					parentSidIdentifier.hierarchyLevel++;
				}
				parent->mChildren.insert(std::make_pair(parentSidIdentifier, sidTreeNode));
				parent->addChildToParents( sidTreeNode, parentSidIdentifier );
			}
		}
	}

	//------------------------------
	SidTreeNode* SidTreeNode::findChildBySid( const String& sid )
	{
		SidIdentifier lowerBound( sid, 0);
		SidIdentifierSidTreeNodeMap::iterator it = mChildren.lower_bound( lowerBound );

		if ( it == mChildren.end() )
			return 0;

		SidIdentifier canidate = it->first;
		if ( canidate.sid == sid )
		{
			return it->second;
		}
		else
		{
			return 0;
		}
	}

} // namespace COLLADASaxFWL
