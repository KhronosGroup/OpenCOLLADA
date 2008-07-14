/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_CONVERSION_H__
#define __COLLADA_MAYA_CONVERSION_H__

#include "ColladaMayaPrerequisites.h"


namespace COLLADAMaya
{
    // ----------------------------------------------------------
    /** A simple conversion functor. */

    class ConversionFunctor
    {

    public:
        ConversionFunctor() {}

        virtual ~ConversionFunctor() {}

        /** Main functor to override. @param v The value to convert. @return The converted value. */
        virtual float operator() ( float v ) = 0;
    };

    // ----------------------------------------------------------
    /** A sample conversion functor: it scales the value by a given amount. */

    class ConversionScaleFunctor : public ConversionFunctor
    {

    private:
        float scaleFactor;

    public:
        /** Constructor. @param factor The scale factor. */
        ConversionScaleFunctor ( float factor )
        {
            scaleFactor = factor;
        }

        virtual ~ConversionScaleFunctor() {}

        /** Mutator. @param factor The new scale factor. */
        void setScaleFactor ( float factor )
        {
            scaleFactor = factor;
        }

        /** Scales the given value. @param v The value to scale. @return The scaled value. */
        virtual float operator() ( float v )
        {
            return v * scaleFactor;
        }
    };

    // ----------------------------------------------------------
    /** A sample conversion functor: it offsets the value by a given amount. */

    class ConversionOffsetFunctor : public ConversionFunctor
    {

    private:
        float offset;

    public:
        /**< Constructor. @param _offset The value offset. */
        ConversionOffsetFunctor ( float _offset )
        {
            offset = _offset;
        }

        virtual ~ConversionOffsetFunctor() {}

        /**< Offsets the given value. @param v The value to offset. @return The offseted value. */
        virtual float operator() ( float v )
        {
            return v + offset;
        }
    };

}

#endif // __COLLADA_MAYA_CONVERSION_H__

