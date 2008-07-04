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
