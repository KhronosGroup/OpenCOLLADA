/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SPLINE_H__
#define __COLLADAFW_SPLINE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWGeometry.h"
#include "COLLADAFWMeshVertexData.h"
#include "COLLADAFWMeshPrimitive.h"

#include "COLLADABUUtils.h"


namespace COLLADAFW
{

    /** 
     * Describes splines
     */
    class Spline : public Geometry
    {
    public:
    
        enum Interpolation
        {
            LINEAR,
            BEZIER
        };

        typedef ArrayPrimitiveType<Interpolation> InterpolationArray;

    private:

        /** 
         * The positions array. Positions can be stored as float or double values.
         * Positions have always a stride of three (XYZ parameters). We don't need to store
         * this information.
         */
        MeshVertexData mPositions;
        MeshVertexData mInTangents;
        MeshVertexData mOutTangents;
        InterpolationArray mInterpolations;

    public:

        /** Constructor. */
        Spline ( const UniqueId& uniqueId );

        /** Destructor. */
        virtual ~Spline ();

        /** 
        * The positions array. 
        * Positions can be stored as float or double values.
        * Positions have always a stride of three (X, Y and Z parameter). So we don't need to 
        * store this information.
        */
        const MeshVertexData& getPositions () const { return mPositions; }

        /** 
        * The positions array. 
        * Positions can be stored as float or double values.
        * Positions have always a stride of three (X, Y and Z parameter). So we don't need to 
        * store this information.
        */
        MeshVertexData& getPositions () { return mPositions; }

        const MeshVertexData& getInTangents () const { return mInTangents; }
        MeshVertexData& getInTangents () { return mInTangents; }

        const MeshVertexData& getOutTangents () const { return mOutTangents; }
        MeshVertexData& getOutTangents () { return mOutTangents; }

        const InterpolationArray& getInterpolations () const { return mInterpolations; }
        InterpolationArray& getInterpolations () { return mInterpolations; }
    };
}

#endif // __COLLADA_MESH_H__
