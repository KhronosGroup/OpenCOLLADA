/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_TRANSLATE_H__
#define __COLLADAFW_TRANSLATE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTransformation.h"

#include "Math/COLLADABUMathVector3.h"


namespace COLLADAFW
{
	/** Describes the transformation of a node
		Animations for this class must have one of the following animation classes:
		POSITION_XYZ
		POSITION_X
		POSITION_Y
		POSITION_Z
	*/
	class Translate : public Transformation 
	{
	private:
		/** The vector that represents the translation.*/
		COLLADABU::Math::Vector3 mTranslationVector;
	
	public:
		/** Default constructor. Constructs identity translation.*/ 
		Translate();

		/** Sets translation to @a vector.*/ 
		Translate(const COLLADABU::Math::Vector3& translationVector);

		/** Sets the components of the translation to @a x, @a y, @a z.*/
		Translate(double x, double y, double z);

		virtual ~Translate();

		/** Returns the translation vector.*/
		COLLADABU::Math::Vector3& getTranslation() { return mTranslationVector; }

		/** Returns the translation vector.*/
		const COLLADABU::Math::Vector3& getTranslation() const { return mTranslationVector; }

		/** Sets the translation vector.*/
		void setTranslation(const COLLADABU::Math::Vector3& translationVector) { mTranslationVector = translationVector; }

		/**  Sets the components of the translation to @a x, @a y, @a z.*/
		void setTranslation(double x, double y, double z) { mTranslationVector = COLLADABU::Math::Vector3(x, y, z); }

		/** Clones the translation.*/
		Translate* clone() const { return new Translate(*this); }

	};
} // namespace COLLADAFW

#endif // __COLLADAFW_TRANSLATE_H__
