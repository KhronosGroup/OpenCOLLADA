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
#include "COLLADAFWRotate.h"


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

		Control* controllers[ BUCKET_COUNT ];

		if ( !buckedTransforms( transformations, controllers) )
		{
			// the transformation do not fit into the max transformation stack
			return true;
		}

		Control* transformationController = iNode->GetTMController();

		Control* positionController = transformationController->GetPositionController();


#if 0
		if ( controllers[ TRANSLATE_X ] )
		{
			positionController->AssignController( controllers[ TRANSLATE_X ], 0 );
		}

		if ( controllers[ TRANSLATE_Y ] )
		{
			positionController->AssignController( controllers[ TRANSLATE_Y ], 1 );
		}

		if ( controllers[ TRANSLATE_Z ] )
		{
			positionController->AssignController( controllers[ TRANSLATE_Z ], 2 );
		}

		Control* rotationController = transformationController->GetRotationController();

		if ( controllers[ ROTATE_X ] )
		{
			rotationController->AssignController( controllers[ ROTATE_X ], 0 );
		}

		if ( controllers[ ROTATE_Y ] )
		{
			rotationController->AssignController( controllers[ ROTATE_Y ], 1 );
		}

		if ( controllers[ ROTATE_Z ] )
		{
			rotationController->AssignController( controllers[ ROTATE_Z ], 2 );
		}
#endif
		Control* scaleController = transformationController->GetScaleController();
		Class_ID ci = scaleController->ClassID();
		SClass_ID sci = scaleController->SuperClassID();


		Class_ID controllerClassID;//(isLinear ? LININTERP_FLOAT_CLASS_ID : HYBRIDINTERP_FLOAT_CLASS_ID, 0);
		//Control* maxController = (Control*)createMaxObject( CTRL_POINT3_CLASS_ID, controllerClassID);
		Control* maxController = NewDefaultScaleController();
		maxController->AssignController( controllers[ TRANSLATE_X ], 0 );
		maxController->AssignController( controllers[ TRANSLATE_X ], 1 );
		maxController->AssignController( controllers[ TRANSLATE_X ], 2 );

		transformationController->SetScaleController( maxController );



		Class_ID ci2 = maxController->ClassID();
		SClass_ID sci2 = maxController->SuperClassID();
		int gg=0;

#if 0
		Control* scaleController = transformationController->GetScaleController();

		scaleController->AssignController( controllers[ TRANSLATE_X ], 0 );
		scaleController->AssignController( controllers[ TRANSLATE_X ], 1 );
		scaleController->AssignController( controllers[ TRANSLATE_X ], 2 );
		scaleController->AssignController( controllers[ TRANSLATE_X ], 3 );
		scaleController->AssignController( controllers[ TRANSLATE_X ], 4 );
		scaleController->AssignController( controllers[ TRANSLATE_X ], 5 );
		scaleController->AssignController( controllers[ TRANSLATE_X ], 6 );

		Control* c[7];
		c[0] = scaleController->GetXController();
		c[1] = scaleController->GetYController();
		c[2] = scaleController->GetZController();
		c[3] = scaleController->GetWController();
#endif
		return true;
	}

	//------------------------------
	bool AnimationAssigner::buckedTransforms( const COLLADAFW::TransformationPointerArray& transformations, Control** controllers )
	{
		for ( size_t i = 0; i < BUCKET_COUNT; ++i) 
		{
			controllers[i] = 0;
		}
		int bucketDepth = -1;

		size_t transformationCount = transformations.getCount();

		// Attempt to fill in the buckets with the COLLADA scene node transforms
		for (size_t t = 0; t < transformationCount; ++t)
		{
			// Verify that this transformation is either animated or does an actual real transform.
			const COLLADAFW::Transformation* transformation = transformations[t];
			const COLLADAFW::UniqueId& animationListUniqueId = transformation->getAnimationList();

			const COLLADAFW::AnimationList* animationList = 0;
			if ( !animationListUniqueId.isValid() )
			{
				// the transform is not animated
				continue;
			}

			animationList = getAnimationListByUniqueId( animationListUniqueId );

			if ( !animationList )
			{
				// the animation list could not be found
				continue;
			}

			const COLLADAFW::AnimationList::AnimationBindings& animationBindings = animationList->getAnimationBindings();


			// Attempt to bucket this transformation.
			switch (transformation->getTransformationType())
			{
			case COLLADAFW::Transformation::TRANSLATE:
				if ( bucketDepth >= TRANSLATE )
				{
					// Only one translation transform is allowed per node.
					return false;
				}

				for ( size_t j = 0, count = animationBindings.getCount(); j < count; ++j)
				{
					const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings[j];
					const DocumentImporter::MaxControllerList& maxControllerList = getMaxControllerListByAnimationUniqueId( animationBinding.animation );

					switch (animationBinding.animationClass )
					{
					case COLLADAFW::AnimationList::POSITION_X:
						{
							assert( maxControllerList.size() >= 1);
							if ( controllers[TRANSLATE_X] )
							{
								//The x controller has already been set
								break;
							}
							controllers[TRANSLATE_X] = maxControllerList[0];
						}
						break;
					case COLLADAFW::AnimationList::POSITION_Y:
						{
							assert( maxControllerList.size() >= 1);
							if ( controllers[TRANSLATE_Y] )
							{
								//The y controller has already been set
								break;
							}
							controllers[TRANSLATE_Y] = maxControllerList[0];
						}
						break;
					case COLLADAFW::AnimationList::POSITION_Z:
						{
							assert( maxControllerList.size() >= 1);
							if ( controllers[TRANSLATE_Z] )
							{
								//The z controller has already been set
								break;
							}
							controllers[TRANSLATE_Z] = maxControllerList[0];
						}
						break;
					case COLLADAFW::AnimationList::POSITION_XYZ:
						{
							assert( maxControllerList.size() >= 3);

							if ( controllers[TRANSLATE_X] || controllers[TRANSLATE_Y] || controllers[TRANSLATE_Z])
							{
								//A controller for at least one of the translates has already been set
								break;
							}

							controllers[TRANSLATE_X] = maxControllerList[0];
							controllers[TRANSLATE_Y] = maxControllerList[1];
							controllers[TRANSLATE_Z] = maxControllerList[2];
						}
						break;
					default:
						return false;
					}
				}
				bucketDepth = TRANSLATE;
				break;

			case COLLADAFW::Transformation::SCALE:
				if ( bucketDepth >= SCALE )
				{
					// Only one scale transform is allowed per node.
					return false;
				}
				//controllers[SCALE] = transform;
				bucketDepth = SCALE;
				break;

			case COLLADAFW::Transformation::ROTATE: 
				{
					COLLADAFW::Rotate* rotatate = (COLLADAFW::Rotate*) transformation;
					const COLLADABU::Math::Vector3 rotationAxis = rotatate->getRotationAxis();

					if (bucketDepth >= SCALE_AXIS_ROTATE_R)
					{
						// Only one rotatate is allowed after the scale transform: the reverse scale-axis rotatate.
						return false;
					}
#if 0
					else if (bucketDepth == SCALE)
					{
						// Check for reverse of scale axis transformation
						Bucket reverseBucket = BUCKET_COUNT;
						if (buckets[SCALE_AXIS_ROTATE] != NULL) reverseBucket = SCALE_AXIS_ROTATE;
						else if (buckets[ROTATE_AXIS] != NULL) reverseBucket = ROTATE_AXIS;
						else if (buckets[ROTATE_X] != NULL) reverseBucket = ROTATE_X;
						else if (buckets[ROTATE_Y] != NULL) reverseBucket = ROTATE_Y;
						else if (buckets[ROTATE_Z] != NULL) reverseBucket = ROTATE_Z;

						if (reverseBucket < BUCKET_COUNT)
						{
							const FCDTRotation* reverseRotation = (const FCDTRotation*) buckets[reverseBucket];
							float reverseAngle = FMath::DegToRad(reverseRotation->GetAngle());
							if (IsEquivalent(reverseRotation->GetAxis(), aa.axis) && IsEquivalent(reverseAngle, -aa.angle))
							{
								// Bucket as the reverse scale axis rotatate
								if (reverseBucket != SCALE_AXIS_ROTATE)
								{
									buckets[SCALE_AXIS_ROTATE] = buckets[reverseBucket];
									buckets[reverseBucket] = NULL;
								}
								buckets[SCALE_AXIS_ROTATE_R] = rotatate;
								bucketDepth = SCALE_AXIS_ROTATE_R;
								break;
							}
						}

						// No rotatate to reverse as the scale-axis rotatate: force sampling
						return false;
					}
#endif
					else if (bucketDepth < ROTATE_X && rotationAxis == COLLADABU::Math::Vector3::UNIT_X)
					{ 
						if ( animationBindings.getCount() > 1)
						{
							// we can apply only one animation here
							return false;
						}

						bucketDepth = ROTATE_X;

						if ( animationBindings.getCount() == 0 )
						{
							// no animation for this rotation axis
							break;
						}

						const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings[0];
						if ( animationBinding.animationClass != COLLADAFW::AnimationList::ANGLE )
						{
							// only pure angle transformations can be supported here
							return false;
						}
						const DocumentImporter::MaxControllerList& maxControllerList = getMaxControllerListByAnimationUniqueId( animationBinding.animation );
						assert( maxControllerList.size() == 1 );
						controllers[ROTATE_X] = maxControllerList[0];
						bucketDepth = ROTATE_X;
					}
					else if (bucketDepth < ROTATE_Y && rotationAxis == COLLADABU::Math::Vector3::UNIT_Y)
					{
						if ( animationBindings.getCount() > 1)
						{
							// we can apply only one animation here
							return false;
						}

						bucketDepth = ROTATE_Y;

						if ( animationBindings.getCount() == 0 )
						{
							// no animation for this rotation axis
							break;
						}

						const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings[0];
						if ( animationBinding.animationClass != COLLADAFW::AnimationList::ANGLE )
						{
							// only pure angle transformations can be supported here
							return false;
						}
						const DocumentImporter::MaxControllerList& maxControllerList = getMaxControllerListByAnimationUniqueId( animationBinding.animation );
						assert( maxControllerList.size() == 1 );
						controllers[ROTATE_Y] = maxControllerList[0];
						bucketDepth = ROTATE_Y;
					}
					else if (bucketDepth < ROTATE_Z && rotationAxis == COLLADABU::Math::Vector3::UNIT_Z)
					{
						if ( animationBindings.getCount() > 1)
						{
							// we can apply only one animation here
							return false;
						}

						bucketDepth = ROTATE_Z;

						if ( animationBindings.getCount() == 0 )
						{
							// no animation for this rotation axis
							break;
						}

						const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings[0];
						if ( animationBinding.animationClass != COLLADAFW::AnimationList::ANGLE )
						{
							// only pure angle transformations can be supported here
							return false;
						}
						const DocumentImporter::MaxControllerList& maxControllerList = getMaxControllerListByAnimationUniqueId( animationBinding.animation );
						assert( maxControllerList.size() == 1 );
						controllers[ROTATE_Z] = maxControllerList[0];
						bucketDepth = ROTATE_Z;
					}
#if 0
					else if (bucketDepth < ROTATE_Z) // Only use this if we have no rotations yet.
					{
						buckets[ROTATE_AXIS] = rotatate;
						bucketDepth = ROTATE_AXIS;
					}
					else if (bucketDepth < SCALE_AXIS_ROTATE)
					{
						buckets[SCALE_AXIS_ROTATE] = rotatate;
						bucketDepth = SCALE_AXIS_ROTATE;
					}
#endif
					else 
						return false;
					break; 
				} 

			case COLLADAFW::Transformation::MATRIX:
			case COLLADAFW::Transformation::LOOKAT:
			case COLLADAFW::Transformation::SKEW:
			default:
				// No place for these in the Max transform stack: force sampling
				return false;
			}
		}
		return true;
	}

} // namespace COLLADAMax
