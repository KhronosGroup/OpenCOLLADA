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


#ifndef __COLLADAMAX_CONVERSIONFUNCTOR_H__
#define __COLLADAMAX_CONVERSIONFUNCTOR_H__

#include "COLLADAMaxPrerequisites.h"

#include "Math/COLLADABUMathUtils.h"


namespace COLLADAMax
{

	/** A simple conversion functor. */
	class ConversionFunctor
	{
	public:
		/** Constructor. */
		ConversionFunctor() {}

		/** Destructor. */
		virtual ~ConversionFunctor() {} 

		/** This member must create a new instance of the class and return a pointer to it.*/
		virtual ConversionFunctor* clone()const = 0;

		/** Main functor to override. 
		@param v The value to convert. @return The converted value. */
		virtual float operator()(float v)const = 0; 
	};

	typedef const ConversionFunctor* const & ConversionFunctorType;


	/** Converts @a inValue using @a conversionFunctor. If @a conversionFunctor is null, @a inValue is returned.*/
	float convert( ConversionFunctorType conversionFunctor, float inValue);


	/** Conversion functor to convert to percent, i.e. ist divides by 100 */
	class ScaleConversionFunctor : public ConversionFunctor
	{
	private:
		float mScaleFactor;
	public:
		/** Constructor. */
		ScaleConversionFunctor(float scaleFactor) : mScaleFactor(scaleFactor) {}

		/** Destructor. */
		virtual ~ScaleConversionFunctor() {} 

		/** This member must create a new instance of the class and return a pointer to it.*/
		virtual ConversionFunctor* clone()const { return new ScaleConversionFunctor(*this); }

		/** Main functor to override. 
		@param v The value to convert. @return The converted value. */
		virtual float operator() (float v)const { return v * mScaleFactor; }; 
	};


	/** Collection of instantiations of conversion functors*/
	class ConversionFunctors
	{
	public:
		static ScaleConversionFunctor radToDeg;
		static ScaleConversionFunctor degToRad;
		static ScaleConversionFunctor fromPercent;
		static ScaleConversionFunctor toPercent;

	};



}


#endif //__COLLADAMAX_CONVERSIONFUNCTOR_H__

