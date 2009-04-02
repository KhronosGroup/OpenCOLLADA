/*
Copyright (c) 2008 NetAllied Systems GmbH

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
#include "COLLADAMaxAnimationAssigner.h"

#include "COLLADAFWTransformation.h"
#include "COLLADAFWNode.h"
#include "COLLADAFWAnimationList.h"


namespace COLLADAMax
{

    //------------------------------
	AnimationAssigner::AnimationAssigner( DocumentImporter* documentImporter )
		: ImporterBase(documentImporter)
	{
	}
	
    //------------------------------
	AnimationAssigner::~AnimationAssigner()
	{
	}

	//------------------------------
	bool AnimationAssigner::assign()
	{
		if ( !assignTransformationControllers() )
			return false;

		return true;
	}


	//------------------------------
	bool AnimationAssigner::assignTransformationControllers()
	{
		const DocumentImporter::UniqueIdFWNodeMap& uniqueIdFWNodeMap = getUniqueIdFWNodeMap( );
		DocumentImporter::UniqueIdFWNodeMap::const_iterator it = uniqueIdFWNodeMap.begin();

		for ( ; it != uniqueIdFWNodeMap.end(); ++it)
		{
			const COLLADAFW::Node* node = it->second;
			INode* iNode = getINodeByUniqueId( it->first );
			assignTransformationController( node, iNode);
		}
		return true;
	}

	//------------------------------
	bool AnimationAssigner::assignTransformationController( const COLLADAFW::Node* node, INode* iNode)
	{
		// check if node has animated transformations
		bool hasTransformations = false;
		const COLLADAFW::TransformationPointerArray& transformations = node->getTransformations();
		for ( size_t i = 0, count = transformations.getCount(); i < count; ++i)
		{
			const COLLADAFW::Transformation* transformation = transformations[i];
			const COLLADAFW::UniqueId& animationListUniqueId = transformation->getAnimationList();
			if ( animationListUniqueId.isValid() )
			{
				hasTransformations = true;
				break;
			}
		}

		// If there is no transformation, there is nothing to do
		if ( !hasTransformations )
			return true;


		for ( size_t i = 0, count = transformations.getCount(); i < count; ++i)
		{
			const COLLADAFW::Transformation* transformation = transformations[i];
			const COLLADAFW::UniqueId& animationListUniqueId = transformation->getAnimationList();
			if ( animationListUniqueId.isValid() )
			{
				const COLLADAFW::AnimationList* animationList = getAnimationListByUniqueId( animationListUniqueId );
				
				if ( !animationList )
					continue;
				const COLLADAFW::AnimationList::AnimationBindings& animationBindings = animationList->getAnimationBindings();
				for ( size_t j = 0, count = animationBindings.getCount(); j < count; ++j)
				{
					const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings[j];
					const COLLADAFW::UniqueId& animationUniqueId = animationBinding.animation;
					const DocumentImporter::MaxControllerList& maxControllerList = getMaxControllerListByAnimationUniqueId( animationBinding.animation );

					if ( animationBinding.animationClass == COLLADAFW::AnimationList::POSITION_XYZ )
					{
						Control* positionController = iNode->GetTMController()->GetPositionController();

						for ( size_t k = 0, count = maxControllerList.size(); k < count; ++k)
						{
							Control* xController = maxControllerList[k];
							if ( xController )
								positionController->AssignController( xController, k );
						}

					}

				}


			}
		}


		
		return true;
	}


} // namespace COLLADAMax
