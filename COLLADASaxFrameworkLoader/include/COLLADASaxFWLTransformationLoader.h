/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_TRANSFORMATIONLOADER_H__
#define __COLLADASAXFWL_TRANSFORMATIONLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{ 
	class Transformation;
}


namespace COLLADASaxFWL
{

    /** Helper class to load transformations.  */
	class TransformationLoader 	
	{
	private:
		/** The transformation, that is currently being parsed. Null if none is being parsed.*/
		COLLADAFW::Transformation* mCurrentTransformation;

		/** The number of floats that have been received since the last begin__* method 
		by the transformation data* methods. This is used to know where the next received number must 
		be placed in the transformation.*/
		size_t mTransformationNumbersReceived;

	public:

        /** Constructor. */
		TransformationLoader();

        /** Destructor. */
		virtual ~TransformationLoader();

		/** Sax callback function for the float data of a translate element.*/
		bool dataTranslate( const float* data, size_t length );

		/** Sax callback function for the float data of a rotate element.*/
		bool dataRotate( const float* data, size_t length );

		/** Sax callback function for the float data of a rotate element.*/
		bool dataMatrix( const float* data, size_t length );

		/** Sax callback function for the float data of a scale element.*/
		bool dataScale( const float* data, size_t length );

		bool dataSkew( const float* data, size_t length );

		bool dataLookat( const float* data, size_t length );


		COLLADAFW::Transformation* getCurrentTransformation() { return mCurrentTransformation; }

		/** Creates a new transformation of type Transformationtype using FW_NEW. The new transformation 
		is never deleted by	the TransformationLoader.*/
		template<class Transformationtype> 
		void beginTransformation( )
		{
			mCurrentTransformation = FW_NEW Transformationtype();
		}


		/** Resets the joint loader. Call this after each end of transformation.*/
		void endTransformation();

	private:

        /** Disable default copy ctor. */
		TransformationLoader( const TransformationLoader& pre );

        /** Disable default assignment operator. */
		const TransformationLoader& operator= ( const TransformationLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_TRANSFORMATIONLOADER_H__
