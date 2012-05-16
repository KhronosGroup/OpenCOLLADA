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
#include "COLLADAMaxAnimationAssigner.h"
#include "COLLADAMaxMaterialCreator.h"
#include "COLLADAMaxMultiMtl.h"

#include "COLLADAFWTransformation.h"
#include "COLLADAFWNode.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWRotate.h"



namespace COLLADAMax
{

	//------------------------------
	AnimationAssigner::AnimationAssigner( DocumentImporter* documentImporter,
		                                  const MaterialCreator& materialCreator)
		: AnimationCreator(documentImporter)
		, mMaterialCreator(materialCreator)
	{
	}

	//------------------------------
	AnimationAssigner::~AnimationAssigner()
	{
	}


	// Search for a sub-animatable object, given by name, on a given Animatable entity
	Animatable* findAnimatableByName(Animatable* entity, const char* animName, int& subAnimIndex)
	{
		std::vector<Animatable*> queue; 
		queue.reserve(6);
		queue.push_back(entity);
		while (!queue.empty())
		{
			Animatable* a = queue.back();
			queue.pop_back();

			// Look for the animatable object in the sub-anims
			int subAnimatableCount = a->NumSubs();
			for (subAnimIndex = 0; subAnimIndex < subAnimatableCount; ++subAnimIndex)
			{
				Animatable* b = a->SubAnim(subAnimIndex);
				if ( !b )
				{
					continue;
				}

				TSTR name = a->SubAnimName(subAnimIndex);
				if ( _stricmp(animName, name.data()) == 0 )
				{
					return a;
				}

				// Queue up the sub-animatable objects
				queue.push_back(b);
			}
		}
		return 0;
	}


	//------------------------------
	bool AnimationAssigner::assign()
	{
		if ( !assignTransformationControllers() )
			return false;

		if ( !assignEffectParameterControllers() )
			return false;

		if ( !assignLightParameterControllers() )
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
			// the transformations do not fit into the max transformation stack
			// try a matrix transformation 
			assignMatrixTransformationController( node, iNode );
			return true;
		}
		else
		{
			Control* transformationController = iNode->GetTMController();

			Control* positionController = transformationController->GetPositionController();


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


			if ( controllers[ SCALE_X ] || controllers[ SCALE_Y ] || controllers[ SCALE_Z ] )
			{
				const DocumentImporter::UnitConversionFunctors& unitConversionFunctors = getUnitConversionFunctors();
				ConversionFunctorType reScaleFunctor = unitConversionFunctors.inverseLengthConversion;

				Control* scaleController = createMaxScaleController();

				if ( controllers[ SCALE_X ] )
				{
					scaleController->AssignController( cloneController(controllers[ SCALE_X ], reScaleFunctor), 0 );
				}
				else
				{
					scaleController->AssignController( createMaxConstantFloatController(1), 0 );
				}

				if ( controllers[ SCALE_Y ] )
				{
					scaleController->AssignController( cloneController(controllers[ SCALE_Y ], reScaleFunctor), 1 );
				}
				else
				{
					scaleController->AssignController( createMaxConstantFloatController(1), 1 );
				}

				if ( controllers[ SCALE_Z ] )
				{
					scaleController->AssignController( cloneController(controllers[ SCALE_Z ], reScaleFunctor), 2 );
				}
				else
				{
					scaleController->AssignController( createMaxConstantFloatController(1), 2 );
				}

				transformationController->SetScaleController( scaleController );
			}
		}

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

			const COLLADAFW::AnimationList* animationList = getAnimationList( transformation );

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

				if ( !assign3DController<COLLADAFW::AnimationList::POSITION_XYZ,
										 COLLADAFW::AnimationList::POSITION_X,
										 COLLADAFW::AnimationList::POSITION_Y,
										 COLLADAFW::AnimationList::POSITION_Z>( TRANSLATE_X, TRANSLATE_Y, TRANSLATE_Z, animationBindings, controllers) )
				{
					return false;
				}

				bucketDepth = TRANSLATE;
				break;

			case COLLADAFW::Transformation::SCALE:
				if ( bucketDepth >= SCALE )
				{
					// Only one scale transform is allowed per node.
					return false;
				}
				if ( !assign3DController<COLLADAFW::AnimationList::POSITION_XYZ,
										 COLLADAFW::AnimationList::POSITION_X,
										 COLLADAFW::AnimationList::POSITION_Y,
										 COLLADAFW::AnimationList::POSITION_Z>( SCALE_X, SCALE_Y, SCALE_Z, animationBindings, controllers) )
				{
					return false;
				}
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
						assert( maxControllerList.size() >= 1 );
						if ( maxControllerList.empty() )
						{
							break;
						}
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
						assert( maxControllerList.size() >= 1 );
						if ( maxControllerList.empty() )
						{
							break;
						}
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
						assert( maxControllerList.size() >= 1 );
						if ( maxControllerList.empty() )
						{
							break;
						}
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


	//------------------------------
	template<COLLADAFW::AnimationList::AnimationClass class_XYZ, 
			 COLLADAFW::AnimationList::AnimationClass class_X,
			 COLLADAFW::AnimationList::AnimationClass class_Y,
			 COLLADAFW::AnimationList::AnimationClass class_Z>
	bool AnimationAssigner::assign3DController( int bucket_X, 
												int bucket_Y,
												int bucket_Z,
												const COLLADAFW::AnimationList::AnimationBindings& animationBindings, 
												Control** controllers)
	{
		for ( size_t j = 0, count = animationBindings.getCount(); j < count; ++j)
		{
			const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings[j];
			const DocumentImporter::MaxControllerList& maxControllerList = getMaxControllerListByAnimationUniqueId( animationBinding.animation );

			switch (animationBinding.animationClass )
			{
			case class_X:
				{
					assert( maxControllerList.size() >= 1);
					if ( maxControllerList.empty() )
					{
						break;
					}
					if ( controllers[bucket_X] )
					{
						//The x controller has already been set
						break;
					}
					controllers[bucket_X] = maxControllerList[0];
				}
				break;
			case class_Y:
				{
					assert( maxControllerList.size() >= 1);
					if ( maxControllerList.empty() )
					{
						break;
					}
					if ( controllers[bucket_Y] )
					{
						//The y controller has already been set
						break;
					}
					controllers[bucket_Y] = maxControllerList[0];
				}
				break;
			case class_Z:
				{
					assert( maxControllerList.size() >= 1);
					if ( maxControllerList.empty() )
					{
						break;
					}
					if ( controllers[bucket_Z] )
					{
						//The z controller has already been set
						break;
					}
					controllers[bucket_Z] = maxControllerList[0];
				}
				break;
			case class_XYZ:
				{
					assert( maxControllerList.size() >= 3);
					if ( maxControllerList.size() < 3 )
					{
						break;
					}

					if ( controllers[bucket_X] || controllers[bucket_Y] || controllers[bucket_Z])
					{
						//A controller for at least one of the translates has already been set
						break;
					}

					controllers[bucket_X] = maxControllerList[0];
					controllers[bucket_Y] = maxControllerList[1];
					controllers[bucket_Z] = maxControllerList[2];
				}
				break;
			default:
				return false;
			}
		}
		return true;
	}


	//------------------------------
	template<COLLADAFW::AnimationList::AnimationClass class_XYZW, 
	   		 COLLADAFW::AnimationList::AnimationClass class_XYZ,
			 COLLADAFW::AnimationList::AnimationClass class_X,
			 COLLADAFW::AnimationList::AnimationClass class_Y,
			 COLLADAFW::AnimationList::AnimationClass class_Z,
		     COLLADAFW::AnimationList::AnimationClass class_W>
	bool AnimationAssigner::assign4DController( int bucket_X, 
												int bucket_Y,
												int bucket_Z,
												int bucket_W,
												const COLLADAFW::AnimationList::AnimationBindings& animationBindings, 
												Control** controllers)
	{
		for ( size_t j = 0, count = animationBindings.getCount(); j < count; ++j)
		{
			const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings[j];
			const DocumentImporter::MaxControllerList& maxControllerList = getMaxControllerListByAnimationUniqueId( animationBinding.animation );

			switch (animationBinding.animationClass )
			{
			case class_X:
				{
					assert( maxControllerList.size() >= 1);
					if ( maxControllerList.empty() )
					{
						break;
					}
					if ( controllers[bucket_X] )
					{
						//The x controller has already been set
						break;
					}
					controllers[bucket_X] = maxControllerList[0];
				}
				break;
			case class_Y:
				{
					assert( maxControllerList.size() >= 1);
					if ( maxControllerList.empty() )
					{
						break;
					}
					if ( controllers[bucket_Y] )
					{
						//The y controller has already been set
						break;
					}
					controllers[bucket_Y] = maxControllerList[0];
				}
				break;
			case class_Z:
				{
					assert( maxControllerList.size() >= 1);
					if ( maxControllerList.empty() )
					{
						break;
					}
					if ( controllers[bucket_Z] )
					{
						//The z controller has already been set
						break;
					}
					controllers[bucket_Z] = maxControllerList[0];
				}
				break;
			case class_W:
				{
					assert( maxControllerList.size() >= 1);
					if ( maxControllerList.empty() )
					{
						break;
					}
					if ( controllers[bucket_W] )
					{
						//The z controller has already been set
						break;
					}
					controllers[bucket_W] = maxControllerList[0];
				}
				break;
			case class_XYZ:
				{
					assert( maxControllerList.size() >= 3);
					if ( maxControllerList.size() < 3 )
					{
						break;
					}

					if ( controllers[bucket_X] || controllers[bucket_Y] || controllers[bucket_Z])
					{
						//A controller for at least one of the translates has already been set
						break;
					}

					controllers[bucket_X] = maxControllerList[0];
					controllers[bucket_Y] = maxControllerList[1];
					controllers[bucket_Z] = maxControllerList[2];
				}
				break;
			case class_XYZW:
				{
					assert( maxControllerList.size() >= 4);
					if ( maxControllerList.size() < 4 )
					{
						break;
					}

					if ( controllers[bucket_X] || controllers[bucket_Y] || controllers[bucket_Z] || controllers[bucket_W])
					{
						//A controller for at least one of the translates has already been set
						break;
					}

					controllers[bucket_X] = maxControllerList[0];
					controllers[bucket_Y] = maxControllerList[1];
					controllers[bucket_Z] = maxControllerList[2];
					controllers[bucket_W] = maxControllerList[3];
				}
				break;
			default:
				return false;
			}
		}
		return true;
	}

	//------------------------------
	bool AnimationAssigner::assignMatrixTransformationController( const COLLADAFW::Node* node, INode* iNode)
	{
		const COLLADAFW::TransformationPointerArray& transformations = node->getTransformations();
		size_t transformationCount = transformations.getCount();

		// We can handle this nodes transformation animation only, if it has one transformation of type matrix
		if ( transformationCount != 1 )
		{
			return false;
		}

		const COLLADAFW::Transformation* transformation = transformations[0];

		if ( transformation->getTransformationType() != COLLADAFW::Transformation::MATRIX )
		{
			return false;
		}

		const COLLADAFW::AnimationList* animationList = getAnimationList( transformation );

		if ( !animationList )
		{
			// the animation list could not be found
			return false;
		}

		const COLLADAFW::AnimationList::AnimationBindings& animationBindings = animationList->getAnimationBindings();

		if ( animationBindings.getCount() != 1 )
		{
			// we can handle only one binding
			return false;
		}

		// this binding has to be of type MATRIX4X4
		const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings[0];

		if ( animationBinding.animationClass != COLLADAFW::AnimationList::MATRIX4X4 )
		{
			return false;
		}

		const DocumentImporter::MaxControllerList& maxControllerList = getMaxControllerListByAnimationUniqueId( animationBinding.animation );
		assert(maxControllerList.size() == 1);
		if ( maxControllerList.size() != 1 )
		{
			// we expect exactly one controller
			return false;
		}

		Control* transformationController = maxControllerList[0];

		//remove
		if ( transformationController )
		{
			SClass_ID sc = transformationController->SuperClassID();
			Class_ID c = transformationController->ClassID();
			int g = 5;
		}

		SuspendAnimate();

		AnimateOn();
		iNode->SetTMController(transformationController);
		ResumeAnimate(); 

		return true;
	}

	//------------------------------
	bool AnimationAssigner::assignEffectParameterControllers()
	{
		const MaterialCreator::MaterialIdentifierMaxMaterialMap& materialIdentifierMaxMaterialMap = mMaterialCreator.getMaterialIdentifierMaxMaterialMap();
		MaterialCreator::MaterialIdentifierMaxMaterialMap::const_iterator it = materialIdentifierMaxMaterialMap.begin();

		for ( ; it != materialIdentifierMaxMaterialMap.end(); ++it )
		{
			if ( !assignEffectParameterControllers( it->first.effectUniqueId, it->second ) )
			{
				return false;
			}
		}

		return true;
	}

	//------------------------------
	bool AnimationAssigner::assignEffectParameterControllers( const COLLADAFW::UniqueId& effectUniqueId, Mtl* maxMaterial)
	{
		const COLLADAFW::Effect* effect = getFWEffectByUniqueId(effectUniqueId);

		if ( !effect )
		{
			// TODO handle error
			return true;
		}

		const COLLADAFW::CommonEffectPointerArray& commonEffects = effect->getCommonEffects();

		if ( commonEffects.empty() )
		{
			// there is no common effect, therefore nothing can be animated
			return true;
		}

		// we import only the first 
		const COLLADAFW::EffectCommon* commonEffect = commonEffects[0];

		COLLADAFW::EffectCommon::ShaderType shaderType = commonEffect->getShaderType();

		StdMat2* standardMaterial = (StdMat2*) maxMaterial;

		// Retrieve the shader parameter blocks
		Shader* materialShader = standardMaterial->GetShader();
		IParamBlock2* shaderParameters = (IParamBlock2*) materialShader->GetReference(0);
		IParamBlock2* extendedParameters = (IParamBlock2*) standardMaterial->GetReference(StandardMaterial::EXTENDED_PB_REF);

		assignColorRGBAController( shaderParameters, StandardMaterial::shdr_diffuse, commonEffect->getDiffuse());
		assignColorRGBAController( shaderParameters, StandardMaterial::shdr_self_illum_color, commonEffect->getEmission());

		if ( shaderType != COLLADAFW::EffectCommon::SHADER_CONSTANT )
		{
			assignColorRGBAController( shaderParameters, StandardMaterial::shdr_ambient, commonEffect->getAmbient());
		}

		if ( shaderType == COLLADAFW::EffectCommon::SHADER_PHONG || shaderType == COLLADAFW::EffectCommon::SHADER_BLINN )
		{
			assignColorRGBAController( shaderParameters, StandardMaterial::shdr_specular, commonEffect->getSpecular());
		}

		return true;
	}

	//------------------------------
	bool AnimationAssigner::assignColorRGBAController(IParamBlock2* entity, int pid, const COLLADAFW::ColorOrTexture& colorOrTexture)
	{
		if ( !colorOrTexture.isColor() )
		{
			// no color to animate
			return true;
		}

		const COLLADAFW::Color& color = colorOrTexture.getColor();

		const COLLADAFW::AnimationList* animationList = getAnimationList( &color );

		if ( !animationList )
		{
			// color is not animated
			return true;
		}

		int subAnimNum = entity->GetAnimNum(pid);
		return assignColorRGBAController((Animatable*) entity, subAnimNum, animationList);
	}

	//------------------------------
	bool AnimationAssigner::assignColorRGBAController( Animatable* entity, int pid, const COLLADAFW::AnimationList* animationList )
	{
		Control* maxController = createMaxColorRGBAController();

		Control* maxControllers[4];

		for ( size_t i = 0; i < 4; ++i)
		{
			maxControllers[i] = 0;
		}
		
		assign4DController< COLLADAFW::AnimationList::COLOR_RGBA,
							COLLADAFW::AnimationList::COLOR_RGB,
							COLLADAFW::AnimationList::COLOR_R,
							COLLADAFW::AnimationList::COLOR_G,
							COLLADAFW::AnimationList::COLOR_B,
							COLLADAFW::AnimationList::COLOR_A>( 0, 1, 2, 3, animationList->getAnimationBindings(), maxControllers );

		for ( int i = 0; i < 3; ++i)
		{
			Control*& controller = maxControllers[i];
			if ( controller )
			{
				maxController->AssignController( controller, i );
			}
		}

		// Assign the controller to the animatable entity.
		if ( !entity->AssignController(maxController, pid) )
		{
			// TODO handle error
			int gg = 0;
		}
		return true;	
	}

	//------------------------------
	bool AnimationAssigner::assignLightParameterControllers()
	{
		const DocumentImporter::LightList& lightsPairs = getLightList();
		DocumentImporter::LightList::const_iterator it = lightsPairs.begin();
		for ( ; it != lightsPairs.end(); ++it)
		{
			const COLLADAFW::Light& fwLight = *it;
			if ( !assignLightParameterController( fwLight) )
			{
				return false;
			}
		}
		return true;
	}


	//------------------------------
	bool AnimationAssigner::assignColorRGBController( Animatable* entity, int pid, const COLLADAFW::AnimationList* animationList )
	{
		Control* maxController = createMaxColorRGBAController();

		Control* maxControllers[3];

		for ( size_t i = 0; i < 3; ++i)
		{
			maxControllers[i] = 0;
		}

		assign3DController< COLLADAFW::AnimationList::COLOR_RGB,
			COLLADAFW::AnimationList::COLOR_R,
			COLLADAFW::AnimationList::COLOR_G,
			COLLADAFW::AnimationList::COLOR_B>( 0, 1, 2, animationList->getAnimationBindings(), maxControllers );

		for ( int i = 0; i < 3; ++i)
		{
			Control*& controller = maxControllers[i];
			if ( controller )
			{
				maxController->AssignController( controller, i );
			}
		}

		// Assign the controller to the animatable entity.
		if ( !entity->AssignController(maxController, pid) )
		{
			// TODO handle error
			int gg = 0;
		}
		return true;	
	}

	//------------------------------
	bool AnimationAssigner::assignLightParameterController( const COLLADAFW::Light& fwLight )
	{
		Object* lightObject = getObjectByUniqueId( fwLight.getUniqueId() );
		if ( !lightObject )
		{
			return true;
		}

		assert( lightObject->SuperClassID() == LIGHT_CLASS_ID);
		if ( lightObject->SuperClassID() != LIGHT_CLASS_ID )
		{
			return true;
		}

		GenLight* maxLight = (GenLight*)lightObject;

		const COLLADAFW::Color& color = fwLight.getColor();
		const COLLADAFW::UniqueId& colorUniqueId = color.getAnimationList();
		const COLLADAFW::AnimationList* colorAnimationList = getAnimationListByUniqueId( colorUniqueId );

		if ( colorAnimationList )
		{
			int pid = 0;
			Animatable* colorController = findAnimatableByName( maxLight, "Color", pid);
			if ( colorController )
			{
				assignColorRGBController( colorController, pid, colorAnimationList);
			}
		}


		//Find a better way to access parameter controller
#if 0
		const COLLADAFW::AnimatableFloat& fallOffAngle = fwLight.getFallOffAngle();
		const COLLADAFW::UniqueId& fallOffAngleUniqueId = fallOffAngle.getAnimationList();
		const COLLADAFW::AnimationList* fallOffAngleAnimationList = getAnimationListByUniqueId( fallOffAngleUniqueId );

		Animatable* fallOffAngleController = findAnimatableByName( maxLight, "Falloff", pid);
		if ( fallOffAngleController )
		{
			assignFloatController( fallOffAngleController, pid, fallOffAngleAnimationList);
		}
		fallOffAngleController->
#endif
		return true;

	}
} // namespace COLLADAMax
