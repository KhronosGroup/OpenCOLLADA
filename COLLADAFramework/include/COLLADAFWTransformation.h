/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_TRANSFORMATIONBASE_H__
#define __COLLADAFW_TRANSFORMATIONBASE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWArray.h"



namespace COLLADAFW
{
	/** This is the Base class of all transformations that can occur within a scene graph.*/
	class Transformation 	
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

		/** The sid of the transformation.*/
		String mSid;
	
	public:
		virtual ~Transformation();

		/** Returns the type of the transformation.*/
		TransformationType getTransformationType() const {return mTransformationType;}

		/** Returns the sid of the transformation.*/
		const String& getSid() const {return mSid;}

		/** Returns the sid of the transformation.*/
		void setSid(const String& sid) { mSid = sid; }

	protected:
		/** The only available constructor. Can only be used by the derived classes.
		@param transformationType The type of the transformation.*/
		Transformation(TransformationType transformationType);

	
	private:
        /** Disable default copy ctor. */
		Transformation( const Transformation& pre );
        /** Disable default assignment operator. */
		const Transformation& operator= ( const Transformation& pre );
	};

	typedef Array<Transformation*> TransformationArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_TRANSFORMATIONBASE_H__
