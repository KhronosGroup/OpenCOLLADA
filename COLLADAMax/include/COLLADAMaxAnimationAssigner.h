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

#ifndef __COLLADAMAX_ANIMATIONASSIGNER_H__
#define __COLLADAMAX_ANIMATIONASSIGNER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxAnimationCreator.h"

#include "COLLADAFWTransformation.h"
#include "COLLADAFWAnimationList.h"

namespace COLLADAMax
{
	class MaterialCreator;

    /** Assigns all the controllers to the corresponding animatables. */
	class AnimationAssigner : public AnimationCreator 
	{
	private:

		enum Bucket
		{ 
			TRANSLATE_X = 0, 
			TRANSLATE_Y, 
			TRANSLATE_Z, 
			TRANSLATE = TRANSLATE_Z, 
			ROTATE_Z, 
			ROTATE_Y, 
			ROTATE_X, 
			ROTATE_AXIS, 
			SCALE_AXIS_ROTATE, 
			SCALE_X,
			SCALE_Y,
			SCALE_Z,
			SCALE = SCALE_Z, 
			SCALE_AXIS_ROTATE_R, 
			BUCKET_COUNT 
		};

	private:
		const MaterialCreator& mMaterialCreator;
	
	public:

        /** Constructor. */
		AnimationAssigner( DocumentImporter* documentImporter, 
			               const MaterialCreator& materialCreator );

        /** Destructor. */
		virtual ~AnimationAssigner();

		/** Performs the assignment.
		@return True on success, false otherwise.*/
		bool assign();


	private:

        /** Disable default copy ctor. */
		AnimationAssigner( const AnimationAssigner& pre );

        /** Disable default assignment operator. */
		const AnimationAssigner& operator= ( const AnimationAssigner& pre );

		/** Assigns all transformation controllers.*/
		bool assignTransformationControllers();

		/** Assigns the animations referenced by the transformations in @a node to the transformations in @a iNode.*/
		bool assignTransformationController( const COLLADAFW::Node* node, INode* iNode );

		/** Assigns the matrix animations referenced by the transformations in @a node to the transformations in @a iNode.
		@a node hast to have exactly one transformation of type matrix.*/
		bool assignMatrixTransformationController( const COLLADAFW::Node* node, INode* iNode);

		/** Assigns all controllers of animated effect parameters.*/
		bool assignEffectParameterControllers();

		bool buckedTransforms( const COLLADAFW::TransformationPointerArray& transformations, Control** controllers );
		
		template<COLLADAFW::AnimationList::AnimationClass class_XYZ, 
				 COLLADAFW::AnimationList::AnimationClass class_X,
				 COLLADAFW::AnimationList::AnimationClass class_Y,
				 COLLADAFW::AnimationList::AnimationClass class_Z>
		bool assign3DController( int bucket_X, 
							  	 int bucket_Y,
								 int bucket_Z,
							     const COLLADAFW::AnimationList::AnimationBindings& animationBindings, 
								 Control** controllers);
		
		
		template<COLLADAFW::AnimationList::AnimationClass class_XYZW, 
	  			 COLLADAFW::AnimationList::AnimationClass class_XYZ,
				 COLLADAFW::AnimationList::AnimationClass class_X,
				 COLLADAFW::AnimationList::AnimationClass class_Y,
				 COLLADAFW::AnimationList::AnimationClass class_Z,
				 COLLADAFW::AnimationList::AnimationClass class_W>
		bool assign4DController( int bucket_X, 
			 					 int bucket_Y,
								 int bucket_Z,
								 int bucket_W,
								 const COLLADAFW::AnimationList::AnimationBindings& animationBindings, 
								 Control** controllers);

		
		bool assignEffectParameterControllers( const COLLADAFW::UniqueId& effectUniqueId, Mtl* maxMaterial);
	
		bool assignColorRGBAController(IParamBlock2* entity, int pid, const COLLADAFW::ColorOrTexture& colorOrTexture);

		bool assignColorRGBAController( Animatable* entity, int pid, const COLLADAFW::AnimationList* animationList);

		bool assignColorRGBController( Animatable* entity, int pid, const COLLADAFW::AnimationList* animationList);

		bool assignLightParameterControllers();

		bool assignLightParameterController( const COLLADAFW::Light& fwLight);

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_ANIMATIONASSIGNER_H__
