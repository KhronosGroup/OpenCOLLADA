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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaAnimationSampleCache.h"
#include "COLLADAMayaAnimationHelper.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaSyntax.h"

#include <maya/MFnTransform.h>
#include <maya/MFnAnimCurve.h>
#include <maya/MPlugArray.h>
#include <maya/MFnIkHandle.h>
#include <maya/MFnMatrixData.h>
#include <maya/MGlobal.h>
#include <maya/MItDependencyGraph.h>


namespace COLLADAMaya
{
    // --------------------------------------------
    AnimationSampleCache::AnimationSampleCache() : mNodeSearch ( NULL ) {}

    // --------------------------------------------
    AnimationSampleCache::~AnimationSampleCache()
    {
        mNodeSearch = NULL;

        CacheNodeMap::iterator it = mNodes.begin();
        for ( ; it!=mNodes.end(); ++it )
        {
            CacheNode* node = ( *it ).second;
            delete node;
        }

        mNodes.clear();
    }

    // --------------------------------------------
    void AnimationSampleCache::cacheTransformNode ( const MObject& node )
    {
        if ( node.hasFn ( MFn::kTransform ) )
        {
            MFnDagNode nodeFn ( node );
            MPlug p;

#define ADD_PLUG(name, mx) p = nodeFn.findPlug(name); cachePlug(p, mx);
            ADD_PLUG ( ATTR_ROTATE, false );
            ADD_PLUG ( ATTR_ROTATE_X, false );
            ADD_PLUG ( ATTR_TRANSLATE, false );
            ADD_PLUG ( ATTR_SCALE, false );
            ADD_PLUG ( ATTR_MATRIX, true );
#undef ADD_PLUG
        }
        else
        {
            std::cerr << "Unsupported sampling type: " << node.apiTypeStr() << std::endl;
        }
    }

    // --------------------------------------------
    bool AnimationSampleCache::findCacheNode ( const MObject& node )
    {
        // Get the node name
        MFnDependencyNode fn ( node );
        String nodeName = fn.name().asChar();

        CacheNodeMap::iterator it = mNodes.find ( nodeName );
        if ( it != mNodes.end() )
        {
            mNodeSearch = ( *it ).second;
            return true;
        }

        mNodeSearch = NULL;
        return false;
    }

    // --------------------------------------------
    bool AnimationSampleCache::findCachePlug ( const MPlug& plug,
            std::vector<float>*& inputs,
            std::vector<float>*& outputs )
    {
        inputs = NULL;
        outputs = NULL;

        if ( mNodeSearch == NULL || mNodeSearch->node != plug.node() ) findCacheNode ( plug.node() );
        if ( mNodeSearch == NULL ) return false;

        for ( CachePartList::iterator it = mNodeSearch->parts.begin(); it != mNodeSearch->parts.end(); ++it )
        {
            if ( ( *it ).plug == plug && ( *it ).plug.logicalIndex() == plug.logicalIndex() )
            {
                if ( ( *it ).isAnimated )
                {
                    inputs = &AnimationHelper::mSamplingTimes;
                    outputs = & ( *it ).values;
                }

                return true;
            }
        }

        return false;
    }

    // --------------------------------------------
    bool AnimationSampleCache::findCachePlug ( const MPlug& plug, bool& isAnimated )
    {
        if ( mNodeSearch == NULL || mNodeSearch->node != plug.node() ) findCacheNode ( plug.node() );
        if ( mNodeSearch == NULL ) return false;

        for ( CachePartList::iterator it = mNodeSearch->parts.begin(); it != mNodeSearch->parts.end(); ++it )
        {
            if ( ( *it ).plug == plug && ( *it ).plug.logicalIndex() == plug.logicalIndex() )
            {
                isAnimated = ( *it ).isAnimated;
                return true;
            }
        }

        return false;
    }

    // --------------------------------------------
    bool AnimationSampleCache::markPlugWanted ( const MPlug& plug )
    {
        if ( mNodeSearch == NULL || mNodeSearch->node != plug.node() ) findCacheNode ( plug.node() );
        if ( mNodeSearch == NULL ) return false;

        bool isSampling = false;
        uint childCount = plug.numChildren();
        std::vector<MPlug> marks ( 1 + childCount );
        marks[childCount] = plug;

        for ( uint i = 0; i < childCount; ++i ) marks[i] = plug.child ( i );
        for ( CachePartList::iterator it = mNodeSearch->parts.begin(); it != mNodeSearch->parts.end(); ++it )
        {
            for ( uint i = 0; i < childCount + 1; ++i )
            {
                if ( ( *it ).plug == marks[i] && ( *it ).plug.logicalIndex() == marks[i].logicalIndex() )
                {
                    isSampling = ( *it ).isWanted = true;
                    break;
                }
            }
        }

        return isSampling;
    }

    // --------------------------------------------
    void AnimationSampleCache::cachePlug ( const MPlug& plug, bool isMatrix )
    {
        if ( mNodeSearch == NULL || mNodeSearch->node != plug.node() ) findCacheNode ( plug.node() );
        if ( mNodeSearch == NULL )
        {
            mNodeSearch = new CacheNode ( plug.node() );

            MFnDependencyNode fn ( plug.node() );
            String nodeName = fn.name().asChar();
            mNodes.insert ( std::pair<String, CacheNode*> ( nodeName, mNodeSearch ) );
        }

        std::vector<MPlug> marks;
        uint childCount = plug.numChildren();
        if ( childCount == 0 || isMatrix )
        {
            marks.push_back ( plug );
            childCount = 1;
        }
        else
        {
            marks.resize ( childCount );
            for ( uint i = 0; i < childCount; ++i ) marks[i] = plug.child ( i );
        }

        for ( uint i = 0; i < childCount; ++i )
        {
            MPlug p = marks[i];
            bool found = false;

            for ( CachePartList::iterator it = mNodeSearch->parts.begin(); it != mNodeSearch->parts.end() && !found; ++it )
            {
                found = ( *it ).plug == p && ( *it ).plug.logicalIndex() == p.logicalIndex();
            }
            if ( !found )
            {
                mNodeSearch->parts.push_back ( CacheNode::Part ( p ) );
                mNodeSearch->parts.back().isMatrix = isMatrix;
            }
        }
    }

    // --------------------------------------------
    void AnimationSampleCache::sampleExpression ( const MObject& object )
    {
        MStatus status;
        MFnDependencyNode depNode ( object );
        MPlug plug = depNode.findPlug ( ATTR_OUTPUT );

        uint elementCount = plug.numElements();

        for ( uint e = 0; e < elementCount; e++ )
        {
            MPlug elementPlug = plug.elementByPhysicalIndex ( e );

            MPlugArray connections;
            elementPlug.connectedTo ( connections, false, true, &status );

            uint connectionCount = connections.length();

            for ( uint c = 0; c < connectionCount; ++c )
            {
                MPlug sampledPlug = connections[c];
                MObject connectedNode = connections[c].node();

                // By-pass any unit conversion nodes
                while ( connectedNode.hasFn ( MFn::kUnitConversion ) )
                {
                    bool hasConnection = DagHelper::getPlugConnectedTo ( connectedNode, ATTR_OUTPUT, sampledPlug );
                    connectedNode = ( hasConnection ) ? sampledPlug.node() : MObject::kNullObj;
                }

                // Add the corresponding plug to the sampling list
                cachePlug ( sampledPlug, false );
            }
        }
    }

    // --------------------------------------------
    void AnimationSampleCache::sampleConstraint ( const MDagPath& dagPath )
    {
        // Find all the transforms below this node.
        MObject temp = dagPath.node();
        MItDependencyGraph itDG ( temp, MFn::kTransform, MItDependencyGraph::kDownstream, MItDependencyGraph::kBreadthFirst, MItDependencyGraph::kNodeLevel );

        for ( ; !itDG.isDone(); itDG.next() )
        {
            cacheTransformNode ( itDG.thisNode() );
        }
    }

    // --------------------------------------------
    void AnimationSampleCache::sampleIKHandle ( const MDagPath& dagPath )
    {
        MStatus status;
        MFnIkHandle ikHandle ( dagPath, &status );

        if ( status == MStatus::kSuccess )
        {
            // Make sure this IK handle seems valid (represents a valid chain
            // between two dag paths).
            MDagPath joint, effector;

            if ( ikHandle.getStartJoint ( joint ) != MStatus::kSuccess ) return;
            if ( ikHandle.getEffector ( effector ) != MStatus::kSuccess ) return;
            if ( effector.length() <= joint.length() ) return;

            effector.pop ( effector.length() - joint.length() );
            if ( ! ( effector == joint ) ) return;

            // OK, I guess it's good.  Now add all nodes affected by this IK
            // handle to a list of IK affected nodes.  We will mark all these
            // as needing to be sampled...
            ikHandle.getEffector ( effector );
            for ( effector.pop ( 1 ); effector.length() >=joint.length(); effector.pop ( 1 ) )
            {
                MFnDagNode effectorNode ( effector );
                MObject _enobj = effectorNode.object();
                cacheTransformNode ( _enobj );
            }
        }
    }

    // --------------------------------------------
    void AnimationSampleCache::samplePlugs()
    {
        if ( mNodes.empty() ) return;

        MTime originalTime;
        MFnMatrixData matrixData;
        MStatus stat;
        AnimationHelper::getCurrentTime ( originalTime );

        std::vector<float>& times = AnimationHelper::mSamplingTimes;
        uint sampleCount = ( uint ) times.size();

        // Allocate the necessary memory in all the plug timing buffers
        for ( CacheNodeMap::iterator it = mNodes.begin(); it != mNodes.end(); ++it )
        {
            CacheNode* c = ( *it ).second;
            for ( CachePartList::iterator it2 = c->parts.begin(); it2 != c->parts.end(); ++it2 )
            {
                CacheNode::Part& part = ( *it2 );
                if ( part.isWanted )
                {
                    part.values.resize ( ( !part.isMatrix ) ? sampleCount : 16 * sampleCount );
                }
            }
        }

        // Sample all the wanted plugs
        for ( uint i = 0; i < sampleCount; ++i )
        {
            MTime t ( times[i], MTime::kSeconds );
            AnimationHelper::setCurrentTime ( t );

            for ( CacheNodeMap::iterator it = mNodes.begin(); it != mNodes.end(); ++it )
            {
                CacheNode* c = ( *it ).second;

                for ( CachePartList::iterator it2 = c->parts.begin(); it2 != c->parts.end(); ++it2 )
                {
                    CacheNode::Part& part = ( *it2 );
                    if ( part.isWanted )
                    {
                        if ( !part.isMatrix )
                        {
                            part.plug.getValue ( part.values[i] );

                            if ( i > 0 && part.values[i-1] != part.values[i] ) part.isAnimated = true;
                        }
                        else
                        {
                            MObject val;
                            part.plug.getValue ( val );

                            stat = matrixData.setObject ( val );
                            if ( stat != MStatus::kSuccess ) MGlobal::displayWarning ( "Unable to set matrixData on sampled transform." );

                            MMatrix matrix = matrixData.matrix ( &stat );
                            if ( stat != MStatus::kSuccess ) MGlobal::displayWarning ( "Unable to retrieve sampled matrixData." );

#define PV(a,b,c) part.values[16*i+a] = (float) matrix[b][c]
                            PV ( 0, 0, 0 );
                            PV ( 1, 1, 0 );
                            PV ( 2, 2, 0 );
                            PV ( 3, 3, 0 );
                            PV ( 4, 0, 1 );
                            PV ( 5, 1, 1 );
                            PV ( 6, 2, 1 );
                            PV ( 7, 3, 1 );
                            PV ( 8, 0, 2 );
                            PV ( 9, 1, 2 );
                            PV ( 10,2, 2 );
                            PV ( 11,3, 2 );
                            PV ( 12,0, 3 );
                            PV ( 13,1, 3 );
                            PV ( 14,2, 3 );
                            PV ( 15,3, 3 );
#undef PV

#define PD(a) part.values[16*i+a] != part.values[16*(i-1)+a]
                            if ( i > 0 && ( PD ( 0 ) || PD ( 1 ) || PD ( 2 ) || PD ( 3 ) || PD ( 4 )
                                            || PD ( 5 ) || PD ( 6 ) || PD ( 7 ) || PD ( 8 ) || PD ( 9 ) || PD ( 10 )
                                            || PD ( 11 ) || PD ( 12 ) || PD ( 13 ) || PD ( 14 ) || PD ( 15 ) ) )
                                part.isAnimated = true;
                        }
                    }
                }
            }
        }

        AnimationHelper::setCurrentTime ( originalTime );
    }

}