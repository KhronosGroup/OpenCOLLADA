/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
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

