/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_CONVERSION_H__
#define __COLLADA_MAYA_CONVERSION_H__

#include "COLLADAMayaPrerequisites.h"

#include "Math/COLLADABUMathMatrix4.h"
#include "Math/COLLADABUMathUtils.h"


namespace COLLADAMaya
{


    // ----------------------------------------------------------
    // Fills the two dimensional array @a copy with the values contained in @a original
    static void convertMayaMatrixToTransposedDouble4x4 ( 
        double copy[][4], 
        const MMatrix& original, 
        const double tolerance )
    {
        if (COLLADABU::Math::Utils::equalsZero ( original[0][0], tolerance )) copy[0][0] = 0.0;
        else copy[0][0] = original[0][0];
        if (COLLADABU::Math::Utils::equalsZero ( original[0][1], tolerance )) copy[1][0] = 0.0;
        else copy[1][0] = original[0][1];
        if (COLLADABU::Math::Utils::equalsZero ( original[0][2], tolerance )) copy[2][0] = 0.0;
        else copy[2][0] = original[0][2];
        copy[3][0] = 0;

        if (COLLADABU::Math::Utils::equalsZero ( original[1][0], tolerance )) copy[0][1] = 0.0;
        else copy[0][1] = original[1][0];
        if (COLLADABU::Math::Utils::equalsZero ( original[1][1], tolerance )) copy[1][1] = 0.0;
        else copy[1][1] = original[1][1];
        if (COLLADABU::Math::Utils::equalsZero ( original[1][2], tolerance )) copy[2][1] = 0.0;
        else copy[2][1] = original[1][2];
        copy[3][1] = 0;

        if (COLLADABU::Math::Utils::equalsZero ( original[2][0], tolerance )) copy[0][2] = 0.0;
        else copy[0][2] = original[2][0];
        if (COLLADABU::Math::Utils::equalsZero ( original[2][1], tolerance )) copy[1][2] = 0.0;
        else copy[1][2] = original[2][1];
        if (COLLADABU::Math::Utils::equalsZero ( original[2][2], tolerance )) copy[2][2] = 0.0;
        else copy[2][2] = original[2][2];
        copy[3][2] = 0;

        if (COLLADABU::Math::Utils::equalsZero ( original[3][0], tolerance )) copy[0][3] = 0.0;
        else copy[0][3] = original[3][0];
        if (COLLADABU::Math::Utils::equalsZero ( original[3][1], tolerance )) copy[1][3] = 0.0;
        else copy[1][3] = original[3][1];
        if (COLLADABU::Math::Utils::equalsZero ( original[3][2], tolerance )) copy[2][3] = 0.0;
        else copy[2][3] = original[3][2];
        copy[3][3] = 1;
    }

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

    // ----------------------------------------------------------
    /** Exporter converter functors */
    class FocalLengthConverter : public ConversionFunctor
    {
    public:
        float aperture;

        FocalLengthConverter(float _aperture) { aperture = _aperture; }

        virtual float operator() (float v)
        {
            return COLLADABU::Math::Utils::radToDegF ( 2.0f * atan(25.4f * aperture / 2.0f / v) );
        }
    };


}

#endif // __COLLADA_MAYA_CONVERSION_H__

