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

#ifndef __COLLADA_MAYA_ANIMATION_SAMPLE_CACHE_H__
#define __COLLADA_MAYA_ANIMATION_SAMPLE_CACHE_H__

#include "COLLADAMayaAnimationHelper.h"
#include <map>
#include <vector>

#include <maya/MObject.h>
#include <maya/MDagPath.h>
#include <maya/MPlug.h>
#include <maya/MTime.h>
#include <maya/MFloatArray.h>


namespace COLLADAMaya
{

    /**
     * This class caches all animations.
     */

    class AnimationSampleCache
    {

    private:

        struct CacheNode
        {
            /** The parts are the sample plugs of the current node */
            struct Part
            {
                MPlug plug;
                std::vector<float> values;
                bool isMatrix, isWanted, isAnimated;

                Part() : isMatrix ( false ), isWanted ( false ), isAnimated ( false ) {}
                Part ( const MPlug& plug ) : plug ( plug ), isMatrix ( false ), isWanted ( false ), isAnimated ( false ) {}
            };

            std::vector<Part> parts;

            MObject node;
            CacheNode ( const MObject& node ) : node ( node ) {}

            CacheNode& operator= ( const CacheNode &a )
            {
                node = a.node;
                parts = a.parts;
                return *this;
            }
        };

        /** Map for the cache nodes. */
        typedef std::map<String, CacheNode*> CacheNodeMap;
        typedef std::vector<CacheNode::Part> CachePartList;

        // list of nodes that require sampling
        CacheNodeMap mNodes;
        CacheNode* mNodeSearch;

    public:
        /** Constructor */
        AnimationSampleCache();

        /** Destructor */
        virtual ~AnimationSampleCache();

        /**
         * @todo documentation
         * @param plug
         * @param isMatrix
         */
        void cachePlug ( const MPlug& plug, bool isMatrix );

        /**
         * @todo documentation
         * @param plug
         * @return bool
         */
        bool markPlugWanted ( const MPlug& plug );

        /**
         * @todo documentation
         * @param node
         * @return bool
         */
        bool findCacheNode ( const MObject& node );

        /**
         * @todo documentation
         * @param plug
         * @param inputs
         * @param outputs
         * @return bool
         */
        bool findCachePlug ( const MPlug& plug, std::vector<float>*& inputs, std::vector<float>*& outputs );

        /**
         * @todo documentation
         * @param plug
         * @param isAnimated
         * @return bool
         */
        bool findCachePlug ( const MPlug& plug, bool& isAnimated );

        /**
         * @todo documentation
         * @param object
         */
        void sampleExpression ( const MObject& object );

        /**
         * @todo documentation
         * @param dagPath
         */
        void sampleConstraint ( const MDagPath& dagPath );

        /**
         * Set the path to sampling, if it is a valid inverse kinematic handle.
         * Maya provides inverse kinematics tools called "IK handles". The effect
         * of an IK handle on a joint chain is determined by the type of IK solver
         * that you choose.
         * There are three types of IK handles with corresponding solvers:
         * Single Chain (SC) Handle, Rotate Plane (RP) Handle, and Spline Handle.
         * - Single Chain (SC) Handle and Rotate Plane (RP)
         *  Handle can be used to animate the motion of an articulated figure's
         *  limbs, and similar objects.
         * - Spline Handle can be used to animate the motion of curvy or twisty shapes,
         *  such as tails, necks, spines, tentacles, bull-whips, and snakes.
         * @see http://accad.osu.edu/~midori/Materials/IK_solvers.html
         * @param dagPath The path to the IK-handle.
         */
        void sampleIKHandle ( const MDagPath& dagPath );

        /** Sample all the cached plugs */
        void samplePlugs();

    private:

        /**
         * @todo documentation
         * @param node
         */
        void cacheTransformNode ( const MObject& node );

    };

}

#endif  // __COLLADA_MAYA_ANIMATION_SAMPLE_CACHE_H__
