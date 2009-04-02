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

#ifndef __COLLADAMAX_ANIMATIONIMPORTER_H__
#define __COLLADAMAX_ANIMATIONIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"


class Control;

namespace COLLADAFW
{
	class Animation;
	class AnimationCurve;
};


namespace COLLADAMax
{

	/** Imports an animation into the max scene */
	class AnimationImporter : public ImporterBase 
		{
	private:
		/** The animation to import.*/
		const COLLADAFW::Animation* mAnimation;
	
	public:

        /** Constructor. */
		AnimationImporter( DocumentImporter* documentImporter, const COLLADAFW::Animation* animation );

        /** Destructor. */
		virtual ~AnimationImporter();

		/** Performs the import of the animation.
		@return True on success, false otherwise.*/
		bool import();

		/** COLLADA has time in seconds, while Max uses frame time.	The following returns the conversion factor.*/
		static int getTimeFactor() { return GetTicksPerFrame() * GetFrameRate(); }


		/** Creates a max float controller for dimension @a dimension of @a animationCurve and fills in the keys and values.*/
		Control* createAndFillMaxFloatController( COLLADAFW::AnimationCurve* animationCurve, size_t dimension);

		/** Creates an empty max float controller for of @a animationCurve. If @a isLinear is true
		@a maxController a linear float controller is created, otherwise a hybrid float controller.*/
		Control* createMaxFloatController( COLLADAFW::AnimationCurve* animationCurve, bool isLinear);

		/** Fills @a maxController with the values of @a dimension'th dimension of @a animationCurve. If @a isLinear is true
		@a maxController must be a linear float controller, otherwise a hybrid float controller.*/
		bool fillMaxFloatController( IKeyControl* maxKeyController, COLLADAFW::AnimationCurve* animationCurve, size_t dimension, bool isLinear);

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
										   const OutputArrayType& outputValues );

	private:

        /** Disable default copy ctor. */
		AnimationImporter( const AnimationImporter& pre );

        /** Disable default assignment operator. */
		const AnimationImporter& operator= ( const AnimationImporter& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_ANIMATIONIMPORTER_H__
