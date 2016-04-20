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
#include "COLLADAMayaDocumentExporter.h"

#include <maya/MFnTransform.h>
#include <maya/MFnAttribute.h>
#include <maya/MFnAnimCurve.h>
#include <maya/MPlugArray.h>
#include <maya/MFnIkHandle.h>
#include <maya/MFnMatrixData.h>
#include <maya/MGlobal.h>
#include <maya/MItDependencyGraph.h>
#include <maya/MItDependencyNodes.h>

#include <maya/MFnCharacter.h>
#include <maya/MFnClip.h>


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
            std::vector<float>*& outputs,
			std::vector< std::pair<bool, Step> >*& interpolation)
    {
        inputs = NULL;
        outputs = NULL;

        if ( mNodeSearch == NULL || mNodeSearch->node != plug.node() ) findCacheNode ( plug.node() );
        if ( mNodeSearch == NULL ) return false;

        for ( CachePartList::iterator it = mNodeSearch->parts.begin(); it != mNodeSearch->parts.end(); ++it )
        {
            if ( ( *it ).plug == plug && ( *it ).plug.logicalIndex() == plug.logicalIndex() )
            {
				if ((*it).isAnimated)
                {
					inputs = &AnimationHelper::mSamplingTimes;
                    outputs = & ( *it ).values;
					interpolation = &(*it).stepInterpolation;
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


	void AnimationSampleCache::samplePlugsWithoutClip()
	{
		if (mNodes.empty()) return;

		// Search All AnimCurve associated directly to transform and set ALL plug associated with node exported
		for (CacheNodeMap::iterator it = mNodes.begin(); it != mNodes.end(); ++it)
		{
			CacheNode* c = (*it).second;
			for (CachePartList::iterator it2 = c->parts.begin(); it2 != c->parts.end(); ++it2)
			{
				CacheNode::Part& part = (*it2);
				
				part.animCurves.clear();

				MStatus status;

				MFnDependencyNode fnNode(part.plug.node());

				unsigned int attrCount = fnNode.attributeCount(&status);
				if (!status) return;
				for (unsigned int attrIndex = 0; attrIndex < attrCount; ++attrIndex)
				{
					MObject attrObject = fnNode.attribute(attrIndex, &status);
					if (!status) continue;

					MFnAttribute fnAttr(attrObject, &status);
					if (!status) continue;

					MString attrName = fnAttr.name(&status);
					if (!status) continue;

					MObject animCurve = DagHelper::getNodeConnectedTo(part.plug.node(), attrName.asChar());

					if (animCurve.hasFn(MFn::kAnimCurve))
					{
						part.animCurves.push_back(animCurve);
						
					}
						
					
				}
			}
		}

		samplePlugs();
	}



	void AnimationSampleCache::samplePlugsWithClip(MFnClip& clipFn)
	{
		if (mNodes.empty()) return;

		for (CacheNodeMap::iterator it = mNodes.begin(); it != mNodes.end(); ++it)
		{
			CacheNode* c = (*it).second;
			for (CachePartList::iterator it2 = c->parts.begin(); it2 != c->parts.end(); ++it2)
			{
				CacheNode::Part& part = (*it2);
				
				part.animCurves.clear();
			}
		}


		// Set All plug in relation with a clip "exported"
		MObjectArray animCurves;
		MPlugArray plugs;
		clipFn.getMemberAnimCurves(animCurves, plugs);

		for (unsigned int j = 0; j < animCurves.length(); j++)
		{
			MObject plugNode = plugs[j].node();
			MFnDependencyNode nodetracked(plugNode);
			String nameTracked = nodetracked.name().asChar();

			for (CacheNodeMap::iterator it = mNodes.begin(); it != mNodes.end(); ++it)
			{
				CacheNode* c = (*it).second;
				for (CachePartList::iterator it2 = c->parts.begin(); it2 != c->parts.end(); ++it2)
				{
					CacheNode::Part& part = (*it2);

					MFnDependencyNode node1(part.plug.node());
					String name = node1.name().asChar();
					
					if (plugs[j].node() == part.plug.node())
					{
						part.animCurves.push_back(animCurves[j]);
					}
				}
			}
		}

		samplePlugs();
	}

    // --------------------------------------------
	void AnimationSampleCache::samplePlugs()
    {
		MTime originalTime;
		MFnMatrixData matrixData;
		MStatus stat;
		AnimationHelper::getCurrentTime(originalTime);

		std::vector<float>& times = AnimationHelper::mSamplingTimes;
		uint sampleCount = (uint)times.size();

		for (CacheNodeMap::iterator it = mNodes.begin(); it != mNodes.end(); ++it)
		{
			CacheNode* c = (*it).second;
			for (CachePartList::iterator it2 = c->parts.begin(); it2 != c->parts.end(); ++it2)
			{
				CacheNode::Part& part = (*it2);

				std::vector< std::pair<float, Step> > interpolationStepTiming;
				
				MFnDependencyNode node1(part.plug.node());
				String name = node1.name().asChar();

				{
					if (part.isMatrix)
					{
						MStatus status;
						Step step;

						for (unsigned int j = 0; j < part.animCurves.size(); j++)
						{

							MFnDependencyNode animNode(part.animCurves[j]);
							String nameAttrib = animNode.name().asChar();
							

							MFnAnimCurve animCurveFn(part.animCurves[j], &status);

							uint keyCount = animCurveFn.numKeys();

							step._transform = NO_Transformation;

							for (uint keyPosition = 0; keyPosition < keyCount; ++keyPosition)
							{
								COLLADASW::LibraryAnimations::InterpolationType interpolationType;
								interpolationType = AnimationHelper::toInterpolation(animCurveFn.outTangentType(keyPosition));

								float stepTime = (float)animCurveFn.time(keyPosition).as(MTime::kSeconds);
								
								if ((interpolationType == COLLADASW::LibraryAnimations::STEP ||
									interpolationType == COLLADASW::LibraryAnimations::STEP_NEXT) && (stepTime >= (times.front())) && (stepTime <= (times.back())))
								{

									std::vector<float>::iterator itFound;

									itFound = find(times.begin(), times.end(), stepTime);
									
									if (ExportOptions::bakeTransforms() && interpolationType == COLLADASW::LibraryAnimations::STEP)
									{
										if (itFound != times.begin())
											stepTime = *(itFound - 1);
										else
											continue;
									}

									{
										std::vector<float>::iterator itLower = lower_bound(times.begin(), times.end(), stepTime);
										int element = (int)(itLower - times.begin());

										StepType type = interpolationType == COLLADASW::LibraryAnimations::STEP ? STEPPED : STEPPED_NEXT;

										if (nameAttrib.find("translateX") != std::string::npos)
										{
											step._transform = TransX;
											step._type[0] = type;
										}
										else if (nameAttrib.find("translateY") != std::string::npos)
										{
											step._transform = TransY;
											step._type[1] = type;
										}
										else if (nameAttrib.find("translateZ") != std::string::npos)
										{
											step._transform = TransZ;
											step._type[2] = type;
										}
										else if (nameAttrib.find("rotateX") != std::string::npos)
										{
											step._transform = RotX;
											step._type[3] = type;
										}
										else if (nameAttrib.find("rotateY") != std::string::npos)
										{
											step._transform = RotY;
											step._type[4] = type;
										}
										else if (nameAttrib.find("rotateZ") != std::string::npos)
										{
											step._transform = RotZ;
											step._type[5] = type;
										}
										else if (nameAttrib.find("scaleX") != std::string::npos)
										{
											step._transform = ScaleX;
											step._type[6] = type;
										}
										else if (nameAttrib.find("scaleY") != std::string::npos)
										{
											step._transform = ScaleY;
											step._type[7] = type;
										}
										else if (nameAttrib.find("scaleZ") != std::string::npos)
										{
											step._transform = ScaleZ;
											step._type[8] = type;
										}
										else
										{
											// No step if it's not on a Txyz & Rxyz & Sxyz
											continue;
										}


										class CompareStep
										{
										public:

											float stepTime;

											CompareStep(float step)
											{
												stepTime = step;
											}

											bool operator()(const std::pair<float, Step>& step)
											{
												return (step.first == stepTime);
											}

										};


										CompareStep  myStepComparaison(stepTime);

										std::vector< std::pair<float, Step> >::iterator itFoundInterpolation = find_if(interpolationStepTiming.begin(), interpolationStepTiming.end(), myStepComparaison);

										if ((itFoundInterpolation != interpolationStepTiming.end()))
										{
											(*itFoundInterpolation).second._transform = (StepTransform)((int)((*itFoundInterpolation).second._transform) | (int)(step._transform));

											for (int i = 0; i < 9; i++)
												(*itFoundInterpolation).second._type[i] = step._type[i];
										}
										else
											interpolationStepTiming.push_back(std::make_pair(stepTime, step));

									}
								}
							}
						}
					}

					part.stepInterpolation.resize(sampleCount);
					for (uint i = 0; i < sampleCount; i++)
					{
						Step step;
						part.stepInterpolation[i] = std::make_pair(false, step);
					}

					for (int j = 0; j < interpolationStepTiming.size(); j++)
					{
						std::vector<float>::iterator itLower = lower_bound(times.begin(), times.end(), interpolationStepTiming[j].first);
						int element = (int)(itLower - times.begin());

						part.stepInterpolation[element] = std::make_pair(true, interpolationStepTiming[j].second);
					}
				}
			}
		}


        // Allocate the necessary memory in all the plug timing buffers
		for (CacheNodeMap::iterator it = mNodes.begin(); it != mNodes.end(); ++it)
        {
            CacheNode* c = ( *it ).second;
            for ( CachePartList::iterator it2 = c->parts.begin(); it2 != c->parts.end(); ++it2 )
            {
                CacheNode::Part& part = ( *it2 );
                if ( part.isWanted)
                {
                    part.values.resize ( ( !part.isMatrix ) ? sampleCount : 16 * sampleCount );
                }
            }
        }

		for (uint i = 0; i < sampleCount; ++i)
		{
			MTime t(times[i], MTime::kSeconds);
			AnimationHelper::setCurrentTime(t);

			for (CacheNodeMap::iterator it = mNodes.begin(); it != mNodes.end(); ++it)
			{
				CacheNode* c = (*it).second;

				for (CachePartList::iterator it2 = c->parts.begin(); it2 != c->parts.end(); ++it2)
				{
					CacheNode::Part& part = (*it2);

					if (part.isWanted)
					{
						if (!part.isMatrix)
						{
							part.plug.getValue(part.values[i]);

							if (i > 0 && part.values[i - 1] != part.values[i]) part.isAnimated = true;
						}
						else
						{
							MFnDependencyNode node1(part.plug.node());
							String name = node1.name().asChar();

							MTime Mtiming2;
							AnimationHelper::getCurrentTime(Mtiming2);
							float timing2 = (float)Mtiming2.as(MTime::kSeconds);

							MObject val;
							part.plug.getValue(val);

							stat = matrixData.setObject(val);
							if (stat != MStatus::kSuccess) MGlobal::displayWarning("Unable to set matrixData on sampled transform.");

							MMatrix matrix = matrixData.matrix(&stat);
							if (stat != MStatus::kSuccess) MGlobal::displayWarning("Unable to retrieve sampled matrixData.");

#define PV(a,b,c) part.values[16*i+a] = (float) matrix[b][c]
							PV(0, 0, 0);
							PV(1, 1, 0);
							PV(2, 2, 0);
							PV(3, 3, 0);
							PV(4, 0, 1);
							PV(5, 1, 1);
							PV(6, 2, 1);
							PV(7, 3, 1);
							PV(8, 0, 2);
							PV(9, 1, 2);
							PV(10, 2, 2);
							PV(11, 3, 2);
							PV(12, 0, 3);
							PV(13, 1, 3);
							PV(14, 2, 3);
							PV(15, 3, 3);
#undef PV
							// 1 Frame Animation
							if (sampleCount == 1)
								part.isAnimated = true;

#define PD(a) part.values[16*i+a] != part.values[16*(i-1)+a]
							if (i > 0 && (PD(0) || PD(1) || PD(2) || PD(3) || PD(4)
								|| PD(5) || PD(6) || PD(7) || PD(8) || PD(9) || PD(10)
								|| PD(11) || PD(12) || PD(13) || PD(14) || PD(15)))
								part.isAnimated = true;
						}
					}
				}
			}
		}

        AnimationHelper::setCurrentTime ( originalTime );
    }

}