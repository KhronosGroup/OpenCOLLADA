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

#ifndef __COLLADAMAX_ANIMATIONCREATOR_H__
#define __COLLADAMAX_ANIMATIONCREATOR_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"


namespace COLLADAFW
{
	class AnimationCurve;
};


namespace COLLADAMax
{

	/** Base class for classes that creat max animations. */
	class AnimationCreator : public ImporterBase 
	{
	protected:

		/** Constructor. */
		AnimationCreator( DocumentImporter* documentImporter );

		/** Destructor. */
		virtual ~AnimationCreator();

		/** Creates an empty max float controller for of @a animationCurve. If @a isLinear is true
		@a maxController a linear float controller is created, otherwise a hybrid float controller.*/
		Control* createMaxFloatController( COLLADAFW::AnimationCurve* animationCurve, bool isLinear);

		/** Creates an empty linear max transformation controller for of @a animationCurve. */
		Control* createMaxTransformationController( COLLADAFW::AnimationCurve* animationCurve);

		/** Creates an empty constant linear max float controller. 
		@param constantValue The value the float controller should have for all time.*/
		Control* createMaxConstantFloatController( float constantValue );

		/** Creates an empty max color RGBA controller.*/
		Control* createMaxColorRGBAController( );

		/** Creates an empty max scale controller.*/
		Control* AnimationCreator::createMaxScaleController();

		/** Creates an empty max controller  with SClass_ID @a controllerSuperClassID and Class_ID 
		@a controllerClassID*/
		Control* createMaxController( SClass_ID controllerSuperClassID, Class_ID controllerClassID );

		/** Clones @a controllerToClone and converts its values and if necessary its tangents, using
		@a conversionFunctor.
		@param controllerToClone The controller to clone. If 0, the controlled is cloned without key value 
		conversion.
		@param conversionFunctor The conversion functor used to convert the key values of the controller.
		@return The cloned controller.*/
		Control* cloneController( Control* controllerToClone, ConversionFunctorType conversionFunctor = 0);

	private:

		/** Disable default copy ctor. */
		AnimationCreator( const AnimationCreator& pre );

		/** Disable default assignment operator. */
		const AnimationCreator& operator= ( const AnimationCreator& pre );
	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_ANIMATIONCREATOR_H__
