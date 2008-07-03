/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAX_OPTIONS_H__
#define __COLLADAMAX_OPTIONS_H__

#include "COLLADAMaxPrerequisites.h"

#include "maxtypes.h"

namespace COLLADAMax
{


    /** A class that stores all the options available for the export.
    */

    class Options
    {

    public:
        /** Constructor*/
        Options();

        /** Destructor*/
        ~Options()
        {}

        // Displays the exporter options dialog to allow the user to change the options.
        //bool ShowDialog(bool exporter);

        /** Returns if the normals are exported */
        bool exportNormals() const
        {
            return mNormals;
        }

        /** Returns, if the editable polygons are exported as triangles.*/
        bool exportEPolyAsTriangles() const
        {
            return mTriangulate;
        }

        /** Returns, if XRef are exported.*/
        bool exportXRefs() const
        {
            return mXrefs;
        }

        /** Returns, if tangents are exported.*/
        bool exportTangents() const
        {
            return mTangents;
        }

        /** Returns, if animations are exported.*/
        bool exportAnimations() const
        {
            return mAnimations;
        }

        /** Returns, if animations are sampled.*/
        bool sampleAnimation() const
        {
            return mSampleAnimation;
        }

        /** Returns, if an animation clip is exported.*/
        bool exportAnimClip() const
        {
            return mCreateClip;
        }

        /** Returns, if the transformations are exported as matrices.*/
        bool bakeMatrices() const
        {
            return mBakeMatrices;
        }

        /** Returns, if paths are exported as relative paths.*/
        bool exportRelativePaths() const
        {
            return mRelativePaths;
        }

        /** Returns if only the selected parts are exported.*/
        bool exportSelected() const
        {
            return mSelectionOnly;
        }

        /** Returns the animation start time.*/
        TimeValue animationStart() const
        {
            return mAnimationStart;
        }

        /** Returns the animation end time.*/
        TimeValue animationEnd() const
        {
            return mAnimationEnd;
        }



    private:
        // options dialog state
        bool mNormals;     //!< export normals
        bool mTriangulate;    //!< convert Editable Polygons to triangles
        bool mXrefs;     //!< export external references
        bool mTangents;     //!< export tangents and binormals
        bool mAnimations;    //!< export animations;
        bool mSampleAnimation;   //!< export sampled animation
        bool mCreateClip;    //!< create one animation clip with all the animations of the scene
        bool mBakeMatrices;    //!< export transforms as matrices
        bool mRelativePaths;   //!< export relative paths
        bool importUnits;    //!< import assets in their units
        bool importUpAxis;    //!< import assets in their up-axis
        TimeValue mAnimationStart; //!< start sample TimeValue(frame * GetTicksPerFrame)
        TimeValue mAnimationEnd;  //!< end sample TimeValue  (frame * GetTicksPerFrame)
        bool mSelectionOnly;   //!< export only selected nodes/objects

    };

}


#endif //__COLLADAMAX_OPTIONS_H__
