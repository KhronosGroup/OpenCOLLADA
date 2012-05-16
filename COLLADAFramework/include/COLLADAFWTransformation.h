/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_TRANSFORMATIONBASE_H__
#define __COLLADAFW_TRANSFORMATIONBASE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWPointerArray.h"
#include "COLLADAFWAnimatable.h"


namespace COLLADAFW
{
	/** This is the Base class of all transformations that can occur within a scene graph.*/
	class Transformation : public Animatable
	{
	public:
		enum TransformationType
		{
			MATRIX,
			TRANSLATE,
			ROTATE,
			SCALE,
			LOOKAT,
			SKEW
		};
	private:
		/** The type of transformation.*/
		TransformationType mTransformationType;

	public:
		virtual ~Transformation();

		/** Returns the type of the transformation.*/
		TransformationType getTransformationType() const {return mTransformationType;}

		virtual Transformation* clone() const = 0;

	protected:
		/** The only available constructor. Can only be used by the derived classes.
		@param transformationType The type of the transformation.*/
		Transformation(TransformationType transformationType);

	
	private:
        /** Disable default copy ctor. */
//		Transformation( const Transformation& pre );
        /** Disable default assignment operator. */
		const Transformation& operator= ( const Transformation& pre );
	};

	typedef ArrayPrimitiveType<Transformation*> TransformationArray;
	typedef PointerArray<Transformation> TransformationPointerArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_TRANSFORMATIONBASE_H__
