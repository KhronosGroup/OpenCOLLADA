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

#ifndef __COLLADAMAX_ANIMATIONIMPORTER_H__
#define __COLLADAMAX_ANIMATIONIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxAnimationCreator.h"

#include "COLLADAFWAnimationCurve.h"


class Control;



namespace COLLADAMax
{

	/** Imports an animation into the max scene */
	class AnimationImporter : public AnimationCreator 
		{
	private:
		/** The animation to import.*/
		const COLLADAFW::Animation* mAnimation;

		const DocumentImporter::UnitConversionFunctors& mUnitConversionFunctors; 
	
	public:

        /** Constructor. */
		AnimationImporter( DocumentImporter* documentImporter, const COLLADAFW::Animation* animation );

        /** Destructor. */
		virtual ~AnimationImporter();

		/** Performs the import of the animation.
		@return True on success, false otherwise.*/
		bool import();

		/** Creates a max float controller for dimension @a dimension of @a animationCurve and fills in the keys and values.*/
		Control* createAndFillMaxFloatController( COLLADAFW::AnimationCurve* animationCurve, size_t dimension);

		/** Creates a max transformation controller of @a animationCurve and fills in the keys and values. 
		@a animationCurve has to have dimension 16 and must be linearly interpolated.*/
		Control* createAndFillMaxTransformationController( COLLADAFW::AnimationCurve* animationCurve);

		/** Fills @a maxController with the values of @a dimension'th dimension of @a animationCurve. If @a isLinear is true
		@a maxController must be a linear float controller, otherwise a hybrid float controller.*/
		bool fillMaxFloatController( IKeyControl* maxKeyController, COLLADAFW::AnimationCurve* animationCurve, size_t dimension, bool isLinear);

		/** Fills @a maxController with the values of 16 dimension linear @a animationCurve. */
		bool fillMaxTransformationController( Control* maxController, COLLADAFW::AnimationCurve* animationCurve);

		/** Fills the keys and values from @a inputValues and @a outputValues into @a maxKeyController.
		@param maxKeyController The max key controller to fill
		@param keyCount The number of keys of the animation curve
		@param dimensions The number of dimensions of the animation curve, e.g. 3 for POSITION_XYZ
		@param dimension The dimension of the animation, e.g. 2 for Y component 
		@param inputValues Array containing the input values. Size must be equal to @a keyCount
		@param outputValues Array containing the output values. Size must be @a keyCount * @a dimensions*/
		template<class InputArrayType, class OutputArrayType> 
		bool fillLinearMaxFloatController( IKeyControl* maxKeyController, 
								    	   size_t keyCount, 
										   size_t dimensions, 
										   size_t dimension, 
										   const InputArrayType& inputValues, 
										   const OutputArrayType& outputValues,
										   ConversionFunctorType inputConversionFunctor,
										   ConversionFunctorType outputConversionFunctor );

		template<class InputArrayType, class OutputArrayType, class InTangentArrayType, class OutTangentArrayType> 
		bool fillBezierMaxFloatController( IKeyControl* maxKeyController, 
			size_t keyCount, 
			size_t dimensions, 
			size_t dimension, 
			const InputArrayType& inputValues, 
			const OutputArrayType& outputValues,
			const InTangentArrayType& inTangentValues,
			const OutTangentArrayType& outTangentValues,
			const COLLADAFW::AnimationCurve::InterpolationType interpolationType,
			const COLLADAFW::AnimationCurve::InterpolationTypeArray& interpolationTypes,
			ConversionFunctorType inputConversionFunctor,
			ConversionFunctorType outputConversionFunctor);

	
		//------------------------------
		template<class InputArrayType, class OutputArrayType> 
		bool fillLinearMaxTransformationController( Control* maxController, 
			size_t keyCount, 
			const InputArrayType& inputValues, 
			const OutputArrayType& outputValues,
			ConversionFunctorType inputConversionFunctor,
			ConversionFunctor* outputConversionFunctors[]);


	private:

        /** Disable default copy ctor. */
		AnimationImporter( const AnimationImporter& pre );

        /** Disable default assignment operator. */
		const AnimationImporter& operator= ( const AnimationImporter& pre );
		
		/** Returns the ConversionFunctor to convert a quantity of @a physicalDimension from framework to max units.*/
		ConversionFunctor* AnimationImporter::getConversionFunctorByPhysicalDimension( COLLADAFW::PhysicalDimension physicalDimension );
	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_ANIMATIONIMPORTER_H__
