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
#include "COLLADAMayaAnimationExporter.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaAnimationHelper.h"
#include "COLLADAMayaAnimationTools.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaGeometryExporter.h"
#include "COLLADAMayaVisualSceneExporter.h"

#include <maya/MFnDependencyNode.h>
#include <maya/MFnDagNode.h>
#include <maya/MPlug.h>
#include <maya/MPlugArray.h>
#include <maya/MFnCharacter.h>
#include <maya/MFnClip.h>

#include "COLLADASWSource.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWLibraryAnimationClips.h"

#include "Math/COLLADABUMathUtils.h"


namespace COLLADAMaya
{

    const String AnimationExporter::PARAM_TYPE_INTERPOLATION     = "INTERPOLATION";
    const String AnimationExporter::PARAM_TYPE_EASES             = "EASES";
    const String AnimationExporter::PARAM_TYPE_TCBS              = "TCBS";
    const String AnimationExporter::PARAM_TYPE_TIME              = "TIME";
    const String AnimationExporter::PARAM_TYPE_TRANSFORM         = "TRANSFORM";
    const String AnimationExporter::PARAM_TYPE_X_Y               = "X_Y";

#define SMALL_DELTA 0.001f


    //---------------------------------------------------------------
    AnimationExporter::AnimationExporter ( COLLADASW::StreamWriter* streamWriter,
                                           DocumentExporter* documentExporter )
            : COLLADASW::LibraryAnimations ( streamWriter )
            , mDocumentExporter ( documentExporter )
            , isImport ( false )
    {

    }

    //---------------------------------------------------------------
    AnimationExporter::~AnimationExporter()
    {
        {
            AnimatedElementList::iterator it = mAnimationElements.begin();
            for ( ; it!=mAnimationElements.end(); ++it )
            {
                AnimationElement* animatedElement = *it;
                delete animatedElement;
            }
            mAnimationElements.clear();
        }

        {
            AnimationClipList::iterator it = mAnimationClips.begin();
            for ( ; it!=mAnimationClips.end(); ++it )
            {
                AnimationClip* animationClip = *it;
                delete animationClip;
            }
            mAnimationClips.clear();
        }
    }

    //---------------------------------------------------------------
    const AnimationClipList* AnimationExporter::exportAnimations()
    {
        // Go through the scene graph and look for IK-Handles to sample.
        lookForSamples();

        // Create the curves for the samples
        AnimationSampleCache* animationSampleCache = mDocumentExporter->getAnimationCache();
        animationSampleCache->samplePlugs();

        // Export all animations, which aren't exported until now.
        postSampling();

        if ( !mAnimationElements.empty() )
        {
            // Open the animation library
            openLibrary();

            // Export the curves of the animated element and of the child elements recursive
            exportAnimatedElements ( mAnimationElements );

            // Close the collada animation tag
            closeLibrary();
        }

        // Return the list with the animation clips to export
        return &mAnimationClips;
    }

    //---------------------------------------------------------------
    void AnimationExporter::lookForSamples()
    {
        if ( ExportOptions::exportJointsAndSkin() )
        {
            // Get the list with the transform nodes.
            SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
            SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

            // Export all/selected DAG nodes
            size_t length = exportNodesTree->size();
            for ( size_t i=0; i<length; ++i )
            {
                SceneElement* sceneElement = ( *exportNodesTree ) [i];

                // Recursive call for the current element and all children.
                lookForSamples ( sceneElement );
            }
        }
    }

    // --------------------------------------------------------
    void AnimationExporter::lookForSamples ( SceneElement* sceneElement )
    {
        // Get the animation cache
        AnimationSampleCache* animationCache = mDocumentExporter->getAnimationCache();

        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();

        // Check if it is an export node
        if ( sceneElement->getIsExportNode() )
        {
            // Check, if it is an Inverse Kinematic
            if ( sceneElement->getType() == SceneElement::IKHANDLE )
            {
                animationCache->sampleIKHandle ( dagPath );
            }
            else if ( sceneElement->getType() == SceneElement::CONSTRAINT )
            {
                animationCache->sampleConstraint ( dagPath );
            }
        }

        // Recursive call for all the child elements
        for ( uint i=0; i<sceneElement->getChildCount(); ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );
            lookForSamples ( childElement );
        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::exportAnimatedElements ( const AnimatedElementList &animatedElements )
    {
        // Export the curves of the animated element and of the child elements recursive
        AnimatedElementList::const_iterator elementIter = animatedElements.begin();
        for ( ; elementIter!=animatedElements.end(); ++elementIter )
        {
            // Get the animated element
            AnimationElement* animatedElement = *elementIter;

            // Check the flag, if the element or a child element has curves
            if ( !animatedElement->hasCurves() ) continue;

            // TODO id preservation
            // Open an animation node and add the channel of the current animation
            const String& originalColladaId = animatedElement->getOriginalColladaId ();
            if ( !originalColladaId.empty () )
            {
                openAnimation ( originalColladaId );
            }
            else
            {
                const String& baseId = animatedElement->getBaseId();
                openAnimation ( baseId );
            }

            // Recursive call for all the animated children
            const AnimatedElementList childElements = animatedElement->getAnimatedChildElements();
            exportAnimatedElements ( childElements );

            // Get the animated curves
            AnimationCurveList animatedCurves = animatedElement->getAnimatedCurves();
            if ( animatedCurves.size() > 0 )
            {
                // Check if the curves in the animated element can be merged.
                std::vector<float> defaultValues;
                curvesAreMergeable ( animatedElement, &defaultValues );
                if ( defaultValues.size() != 0 )
                {
                    // Create a multi curve and export it
                    exportAnimatedMultiCurve ( animatedElement, defaultValues );
                }
                else
                {
                    // Export the data of every curve in the animated element
                    exportAnimatedCurves ( animatedElement );
                }
            }

            // Close the current animation tag
            closeAnimation();
        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::exportAnimatedMultiCurve (
        AnimationElement *animatedElement,
        std::vector<float> &defaultValues )
    {
        // Merge and export the curves
        AnimationMultiCurve* mergedCurve = createAnimationMultiCurve ( animatedElement, defaultValues );

        // Export the sources
        exportAnimationSource ( *mergedCurve );

        // Export the sampler
        writeAnimationSampler ( *mergedCurve );

        // Export the channel
        writeAnimationChannel ( *mergedCurve );

        // Delete the created merged curve
        delete mergedCurve;
    }

    //---------------------------------------------------------------
    AnimationMultiCurve* AnimationExporter::createAnimationMultiCurve (
        AnimationElement *animatedElement,
        std::vector<float> &defaultValues )
    {
        // The multi curve object
        AnimationMultiCurve* multiCurve = NULL;

        // Get the animated curves (possibly without the static curves)
        AnimationCurveList curves = animatedElement->getAnimatedCurves();

        // Check for a reference curve
        if ( curves.size() == 0 ) return multiCurve;
        AnimationCurve* mergedCurve = curves[0];

        // Get the real curve count (with the removed static curves)
        uint dimension = animatedElement->getDimension();

        // Create the new multi curve
        String baseId = COLLADASW::Utils::checkID ( animatedElement->getTargetSid() );
        multiCurve = new AnimationMultiCurve ( animatedElement, baseId, dimension );
        multiCurve->setPreInfinity ( mergedCurve->getPreInfinity() );
        multiCurve->setPostInfinity ( mergedCurve->getPostInfinity() );

        // Calculate the merged input keys and their wanted interpolations.
        std::vector<float> mergedInputs;
        std::vector<int> mergedInterpolations;
        AnimationCurveList::iterator curveIter = curves.begin();
        for ( ; curveIter!=curves.end(); ++curveIter )
        {
            const AnimationCurve* curve = *curveIter;
            if ( curve == NULL ) continue;

            const AnimationKeyList curveKeys = curve->getKeys();

            // Merge each curve's keys, which should already be sorted, into the multi-curve's
            size_t multiCurveKeyCount = mergedInputs.size(), m = 0;
            size_t curveKeyCount = curve->getKeyCount(), c = 0;
            while ( m < multiCurveKeyCount && c < curveKeyCount )
            {
                if ( mergedInputs[m] == curveKeys[c]->input )
                {
                    if ( mergedInterpolations[m] != curveKeys[c]->interpolation )
                        mergedInterpolations[m] = COLLADASW::LibraryAnimations::BEZIER;
                    ++c; ++m;
                }
                else if ( mergedInputs[m] < curveKeys[c]->input )
                {
                    ++m;
                }
                else
                {
                    // Insert this new key within the merged list.
                    mergedInputs.insert ( mergedInputs.begin() + m, curveKeys[c]->input );
                    mergedInterpolations.insert ( mergedInterpolations.begin() + m, curveKeys[c]->interpolation );
                    ++multiCurveKeyCount;
                    ++m; ++c;
                }
            }

            while ( c < curveKeyCount )
            {
                // Insert all these extra keys at the end of the merged list.
                mergedInputs.push_back ( curveKeys[c]->input );
                mergedInterpolations.push_back ( curveKeys[c]->interpolation );
                ++c;
            }
        }

        // Create the multi-dimensional keys.
        size_t keyCount = mergedInputs.size();
        for ( size_t curvePosition=0; curvePosition<keyCount; ++curvePosition )
        {
            AnimationMKey* key = multiCurve->addKey ( ( COLLADASW::LibraryAnimations::InterpolationType ) mergedInterpolations[curvePosition] );
            key->input = mergedInputs[curvePosition];
        }

        // Get the keys
        AnimationMKeyList keys = multiCurve->getKeys();

        // Create a curves list
        AnimationCurveList multiCurves;
        multiCurves.resize( dimension, NULL );
        size_t numCurves = curves.size();
        for ( size_t c=0; c<numCurves; ++c )
        {
            AnimationCurve* curve = curves[c];
            uint index = curve->getCurveIndex();
            size_t multiCurvesSize = multiCurves.size();
            if ( index >= multiCurvesSize ) 
            {
                std::cerr << "Wrong curve index!" << std::endl; 
                return NULL; 
            }
            else multiCurves[index] = curve;
        }

        // Merge the curves one by one into the multi-curve
        for ( size_t curvePosition=0; curvePosition<dimension; ++curvePosition )
        {
            const AnimationCurve* curve = multiCurves[curvePosition];
            if ( curve == NULL || curve->getKeyCount() == 0 )
            {
                // No curve, or an empty curve, set the default value on all the keys
                createDefaultKeys ( &keys, curvePosition, defaultValues, keyCount, mergedInputs );

                continue;
            }

            // Merge in this curve's values, sampling when the multi-curve's
            // key is not present in the curve.
            // Calculate and retrieve the tangents in a polar-like form.
            mergeCurves ( &keys, curve, keyCount, curvePosition );
        }

        return multiCurve;
    }

    //---------------------------------------------------------------
    void AnimationExporter::createDefaultKeys (
        AnimationMKeyList* keys,
        size_t curvePosition,
        std::vector<float> &defaultValues,
        const size_t keyCount,
        const std::vector<float> mergedInputs )
    {
        float defaultValue = ( curvePosition < defaultValues.size() ) ? defaultValues[curvePosition] : 0.0f;
        for ( size_t k=0; k<keyCount; ++k )
        {
            ( *keys ) [k]->output[curvePosition] = defaultValue;

            if ( ( *keys ) [k]->interpolation == COLLADASW::LibraryAnimations::BEZIER )
            {
                float previousSpan = ( k > 0 ? mergedInputs[k] - mergedInputs[k - 1] : 1.0f ) / 3.0f;
                float nextSpan = ( k < keyCount - 1 ? mergedInputs[k + 1] - mergedInputs[k] : 1.0f ) / 3.0f;

                AnimationMKeyBezier* bkey = ( AnimationMKeyBezier* ) ( *keys ) [k];
                bkey->inTangent[curvePosition] = TangentPoint ( ( *keys ) [k]->input - previousSpan, defaultValue );
                bkey->outTangent[curvePosition] = TangentPoint ( ( *keys ) [k]->input + nextSpan, defaultValue );
            }
        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::mergeCurves (
        AnimationMKeyList* keys,
        const AnimationCurve* curve,
        size_t keyCount,
        size_t curvePosition )
    {
        const AnimationKeyList curveKeys = curve->getKeys();
        size_t curveKeyCount = curve->getKeyCount();

        for ( size_t k=0, keyPosition=0; k<keyCount; ++k )
        {
            AnimationMKey* key = ( *keys ) [k];

            float input = key->input;
            float previousSpan = ( k > 0 ? input - ( *keys ) [k - 1]->input : 1.0f ) / 3.0f;
            float nextSpan = ( k < keyCount - 1 ? ( *keys ) [k + 1]->input - input : 1.0f ) / 3.0f;

            if ( keyPosition >= curveKeyCount || ! ( key->input == curveKeys[keyPosition]->input ) )
            {
                sampleMKey ( key, curve, curvePosition, input, previousSpan, nextSpan );
            }
            else
            {
                // Keys match, grab the value directly
                key->output[curvePosition] = curveKeys[keyPosition]->output;
                float output = curveKeys[keyPosition]->output;

                // Check the wanted interpolation type to retrieve/calculate the extra necessary information.
                if ( key->interpolation == COLLADASW::LibraryAnimations::BEZIER )
                {
                    createBezierMKey ( key, curveKeys, curvePosition,
                                       previousSpan, nextSpan, keyPosition );
                }
                else if ( key->interpolation == COLLADASW::LibraryAnimations::TCB )
                {
                    createTCBMKey ( key, curveKeys, curvePosition, keyPosition );
                }

                // Go to the next existing key in the 1D curve.
                ++keyPosition;
            }
        }
    }

    //---------------------------------------------------------------
    bool AnimationExporter::curvesAreMergeable (
        const AnimationElement* animationElement,
        std::vector<float>* defaultValues )
    {
        // Flag, if the curves can be merged.
        bool doMergeCurves = true;

        // Get the real curve count (with the removed static curves)
        uint realCurveCount = animationElement->getDimension();

        // Placeholder for the master curve
        AnimationCurve* masterCurve = NULL;

        // Get the animated curves (possibly without the static curves)
        AnimationCurveList curves = animationElement->getAnimatedCurves();

        // Check if all curves have the same inputs, interpolations and infinity types
        if ( curves.size() <= 1 )
        {
            doMergeCurves = false;
        }
        else
        {
            // Iterate through the curves and merge them
            AnimationCurveList::iterator curveIter = curves.begin();
            for ( ; curveIter!=curves.end() && doMergeCurves; ++curveIter )
            {
                if ( masterCurve == NULL ) masterCurve = *curveIter;
                else doMergeCurves = curveIsMergeable ( masterCurve, *curveIter );
            }
        }

        // If the curves have the same inputs, interpolations and infinity types,
        // we are allowed to copy the input values of any curve.
        if ( doMergeCurves )
            createDefaultValues ( masterCurve, defaultValues );

        return doMergeCurves;
    }

    //---------------------------------------------------------------
    bool AnimationExporter::curveIsMergeable (
        const AnimationCurve* masterCurve,
        const AnimationCurve* curve )
    {
        bool doMergeCurves = true;

        // Check the infinity types, the keys and the interpolations.
        size_t curveKeyCount = curve->getKeyCount();
        size_t masterKeyCount = masterCurve->getKeyCount();
        doMergeCurves &= masterKeyCount == curveKeyCount;
        if ( !doMergeCurves ) return doMergeCurves;

        for ( size_t j=0; j<curveKeyCount && doMergeCurves; ++j )
        {
            AnimationKey* curveKey = curve->getKey ( j );
            AnimationKey* masterKey = masterCurve->getKey ( j );
            doMergeCurves &= ( curveKey->input == masterKey->input );
            doMergeCurves &= ( curveKey->interpolation == masterKey->interpolation );

            // Prevent curve having TCB interpolation from merging
            doMergeCurves &= curveKey->interpolation != COLLADASW::LibraryAnimations::TCB;
            doMergeCurves &= masterKey->interpolation != COLLADASW::LibraryAnimations::TCB;
        }

        if ( doMergeCurves )
        {
            doMergeCurves &= curve->getPostInfinity() == masterCurve->getPostInfinity();
            doMergeCurves &= curve->getPreInfinity() == masterCurve->getPreInfinity();
        }

        return doMergeCurves;
    }

    //---------------------------------------------------------------
    void AnimationExporter::createDefaultValues (
        const AnimationCurve* masterCurve,
        std::vector<float>* defaultValues )
    {
        size_t keyCount = masterCurve->getKeyCount();
        for ( size_t i=0; i<keyCount; ++i )
        {
            if ( masterCurve->getParent()->getIsRelativeAnimation() )
            {
                AnimationKey* key = masterCurve->getKey ( i );
                defaultValues->push_back ( key->input );
            }
            else
            {
                defaultValues->push_back ( 0.0f );
            }
        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::exportAnimatedCurves ( const AnimationElement* animatedElement )
    {
        // Get the animated curves
        const AnimationCurveList& animatedCurves = animatedElement->getAnimatedCurves();

        // Export the data of every curve in the animated element
        AnimationCurveList::const_iterator curveIter;

        uint curveIndex=0;
        for ( curveIter=animatedCurves.begin(); curveIter!=animatedCurves.end(); ++curveIter )
        {
            // Get the current curve
            AnimationCurve* curve = *curveIter;

            // Export the sources
            exportAnimationSource ( *curve );
        }

        // Export the samplers for every curve
        for ( curveIter=animatedCurves.begin(); curveIter!=animatedCurves.end(); ++curveIter )
        {
            // Get the current curve
            AnimationCurve* curve = *curveIter;

            // Export the sampler
            writeAnimationSampler ( *curve );
        }

        // Export the channel for every curve
        for ( curveIter=animatedCurves.begin(); curveIter!=animatedCurves.end(); ++curveIter )
        {
            // Get the current curve
            AnimationCurve* curve = *curveIter;

            // Export the channel
            writeAnimationChannel ( *curve );
        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::postSampling()
    {
        AnimatedElementList::iterator it = mAnimationElements.begin();
        while ( it!=mAnimationElements.end() )
        {
            AnimationElement* animatedElement = *it;

            // Sample the animated elements, which aren't created until now
            if ( animatedElement->isSampling() )
            {
                if ( !exportAnimation ( animatedElement ) )
                {
                    delete animatedElement;

                    // After erase, the iterator points to the next element in the list
                    it = mAnimationElements.erase ( it );
                }
                else
                {
                    ++it;
                }
            }
            else
            {
                ++it;
            }
        }
    }

    //---------------------------------------------------------------
    bool AnimationExporter::exportAnimation ( AnimationElement* animatedElement )
    {
        if ( !ExportOptions::exportAnimations() ) return false;

        // The flag, if a curve was created
        bool curveCreated = false;

        // Get the animation plug
        const MPlug& plug = animatedElement->getPlug();
        MString partialName = plug.partialName ( false, false, false, false, false, true );
        String plugName = partialName.asChar ();
        // FCDAnimated* animated = animation->animatedValue;

        // Get the sample type
        SampleType sampleType = ( SampleType ) ( animatedElement->getSampleType() & kValueMask );

        // TODO
        // size_t elementCount = animated->GetValueCount();
        bool isCompound = plug.isCompound();
        if ( !isCompound || sampleType == kSingle ) // || elementCount == 1)
        {
            // Create the list for the curves
            AnimationCurveList curves;

            // Export the single curve without fuss
            ConversionFunctor* conversion = animatedElement->getConversion();
            curveCreated = createAnimationCurve ( animatedElement, plug, sampleType, conversion, curves );

            // Push the generated curves in the curves list of the animation element
            for ( uint i=0; i<curves.size(); ++i )
            {
                // Add the curve to the animated element
                animatedElement->addAnimatedCurve ( curves[i] );
            }
        }
        else
        {
            // Set the flag, that it is a compound element
            animatedElement->isCompoundElement ( true );

            // Get the animation data for each child plug
            uint numChildren = plug.numChildren();
            // TODO
            //  uint elementCount = min(numChildren, elementCount);
            uint elementCount = numChildren;
            for ( uint curveIndex=0; curveIndex<elementCount; ++curveIndex )
            {
                MPlug childPlug = plug.child ( curveIndex );
                String plugName = childPlug.name().asChar();
                MFnDependencyNode fn (childPlug.node());
                String name = fn.name().asChar();

                // The list for the created curves
                AnimationCurveList curves;

                // The conversion functor
                ConversionFunctor* conversion = animatedElement->getConversion();

                // Creates the curve(s)
                if ( createAnimationCurve ( animatedElement, childPlug, sampleType, conversion, curves, curveIndex ) )
                    curveCreated = true;

                // Add the curves to the animated elements
                for ( uint c=0; c<curves.size(); ++c )
                {
                    // Get the curve
                    AnimationCurve* animationCurve = curves[c];

                    // Set the sample type to single (just one dimension in every child curve)
                    animationCurve->setDimension ( kSingle );

                    // Add the curve to the animated element
                    animatedElement->addAnimatedCurve ( animationCurve );
                }
            }
        }

        // Return, if any curve was created
        return curveCreated;
    }

    // ---------------------------------------------------------------------
    void AnimationExporter::exportAnimationSource ( AnimationCurve &animationCurve )
    {
        // Get the key count
        size_t keyCount = animationCurve.getKeyCount();

        // The value lists for the collada sources
        std::vector<float> input, output, inTangents, outTangents, tcbs, eases;
        std::vector<String> interpolations;

        bool hasTangents = animationCurve.hasTangents();
        bool hasTCB = animationCurve.hasTCB();

        // Convert the maya internal units to the UI units, if necessary
        const AnimationElement* parent = animationCurve.getParent ();
        bool convertUnits = parent->getConvertUnits ();

        // Add the key values
        for ( uint i=0; i<keyCount; ++i )
        {
            AnimationKey* key = ( ( AnimationKey* ) animationCurve.getKey ( i ) );
            input.push_back ( key->input );

            if ( convertUnits ) 
                output.push_back ( ( float ) MDistance::internalToUI ( key->output ) );
            else
                output.push_back ( key->output );

            interpolations.push_back ( COLLADASW::LibraryAnimations::getNameOfInterpolation ( key->interpolation ) );

            // Handle Tangents
            if ( hasTangents )
            {
                if ( key->interpolation == COLLADASW::LibraryAnimations::BEZIER )
                {
                    // Export bezier tangents
                    AnimationKeyBezier* bezKey = ( AnimationKeyBezier* ) key;

                    inTangents.push_back ( bezKey->inTangent.x );

                    if ( !convertUnits ) inTangents.push_back ( bezKey->inTangent.y );
                    else inTangents.push_back ( ( float ) MDistance::internalToUI ( bezKey->inTangent.y ) );

                    outTangents.push_back ( bezKey->outTangent.x );

                    if ( !convertUnits ) outTangents.push_back ( bezKey->outTangent.y );
                    else outTangents.push_back ( ( float ) MDistance::internalToUI ( bezKey->outTangent.y ) );
                }
                else
                {
                    // Export flat tangents
                    inTangents.push_back ( key->input - 0.0001f );

                    if ( !convertUnits ) inTangents.push_back ( key->output );
                    else inTangents.push_back ( ( float ) MDistance::internalToUI ( key->output ) );

                    outTangents.push_back ( key->input + 0.0001f );

                    if ( !convertUnits ) outTangents.push_back ( key->output );
                    else outTangents.push_back ( ( float ) MDistance::internalToUI ( key->output ) );
                }
            }

            // Handle TCB
            if ( hasTCB )
            {
                if ( key->interpolation == COLLADASW::LibraryAnimations::TCB )
                {
                    AnimationKeyTCB* tcbKey = ( AnimationKeyTCB* ) key;

                    tcbs.push_back ( tcbKey->tension );
                    tcbs.push_back ( tcbKey->continuity );
                    tcbs.push_back ( tcbKey->bias );

                    eases.push_back ( tcbKey->easeIn );
                    eases.push_back ( tcbKey->easeOut );
                }
                else
                {
                    // Export flat tangents
                    tcbs.push_back ( 0.5f );
                    tcbs.push_back ( 0.5f );
                    tcbs.push_back ( 0.5f );

                    eases.push_back ( 0.0f );
                    eases.push_back ( 0.0f );
                }
            }
        }

        // Write the input, output, tangents, tcbs and eases in the collada document
        writeAnimationSource ( animationCurve, input, output, interpolations,
                               inTangents, outTangents, tcbs, eases );
    }

    // ---------------------------------------------------------------------
    template<class T>
    void AnimationExporter::writeAnimationSource (
        const BaseAnimationCurve<T> &animationCurve,
        const std::vector<float> &input,
        const std::vector<float> &output,
        const std::vector<String> &interpolations,
        const std::vector<float> &inTangents,
        const std::vector<float> &outTangents,
        const std::vector<float> &tcbs,
        const std::vector<float> &eases )
    {
        // Get the source id
        String sourceId = animationCurve.getSourceId();

        // Export the infinity parameters
        String preInfinityType = AnimationHelper::mayaInfinityTypeToString ( animationCurve.getPreInfinity() );
        String postInfinityType = AnimationHelper::mayaInfinityTypeToString ( animationCurve.getPostInfinity() );
        writeInputSource ( sourceId, input, preInfinityType, postInfinityType );

        // Get the parameters of the current curve
        const String* parameters = animationCurve.getParameters();

        // The index of the curve, if it is a compound object.
        uint index = animationCurve.getCurveIndex();

        // Get the dimension
        uint dimension = animationCurve.getDimension();

        writeOutputSource ( sourceId, parameters+index, dimension, output );
        writeInterpolationSource ( sourceId, interpolations );

        bool hasTangents = animationCurve.hasTangents();
        if ( hasTangents )
        {
            writeInTangentSource ( sourceId, dimension, inTangents );
            writeOutTangentSource ( sourceId, dimension, outTangents );
        }

        bool hasTCB = animationCurve.hasTCB();
        if ( hasTCB )
        {
            writeTCBSource ( sourceId, tcbs );
            writeEasesSource ( sourceId, eases );
        }
    }

    // ---------------------------------------------------------------------
    void AnimationExporter::exportAnimationSource ( AnimationMultiCurve &animationCurve )
    {
        // Get the key count and dimension
        size_t keyCount = animationCurve.getKeyCount();
        uint dimension = animationCurve.getDimension();

        // Create the source id
        String sourceId = animationCurve.getSourceId();

        // The value lists for the collada sources
        std::vector<float> input, output, inTangents, outTangents, tcbs, eases;
        std::vector<String> interpolations;

        bool hasTangents = animationCurve.hasTangents();
        bool hasTCB = animationCurve.hasTCB();

        // Convert the maya internal units to the UI units, if necessary
        const AnimationElement* parent = animationCurve.getParent ();
        bool convertUnits = parent->getConvertUnits ();
        const SampleType& sampleType = parent->getSampleType ();

        // Add the key values
        for ( uint i=0; i<keyCount; ++i )
        {
            AnimationMKey* key = ( ( AnimationMKey* ) animationCurve.getKey ( i ) );
            input.push_back ( key->input );

            // Write the output list
            float* outputList = key->output;
            for ( uint j=0; j<dimension; ++j )
            {
                // Just convert the transformation of the matrix transform
                // Either here or in method AnimationHelper::sampleAnimatedTransform
                if ( sampleType == kMatrix )
                {
                    if ( convertUnits && (j+1)%4==0 && (j+1)<16 ) 
                        output.push_back ( (float) MDistance::internalToUI ( *outputList ) );
                    else
                        output.push_back ( *outputList );
                }
                else
                {
                    if ( convertUnits )
                        output.push_back ( (float) MDistance::internalToUI ( *outputList ) );
                    else
                        output.push_back ( *outputList );
                }

                ++outputList;
            }

            // Set the interpolation
            interpolations.push_back ( COLLADASW::LibraryAnimations::getNameOfInterpolation ( key->interpolation ) );

            // Handle Tangents
            if ( hasTangents )
                createMultiCurveTangents ( key, dimension, convertUnits, inTangents, outTangents, outputList );

            // Handle TCB
            if ( hasTCB )
                createMultiCurveTCBs ( key, dimension, tcbs, eases );
        }

        // Write the input, output, tangents, tcbs and eases in the collada document
        writeAnimationSource ( animationCurve, input, output, interpolations,
                               inTangents, outTangents, tcbs, eases );
    }

    //---------------------------------------------------------------
    void AnimationExporter::createMultiCurveTCBs (
        AnimationMKey* key,
        uint dimension,
        std::vector<float> &tcbs,
        std::vector<float> &eases )
    {
        if ( key->interpolation == COLLADASW::LibraryAnimations::TCB )
        {
            AnimationMKeyTCB* tcbKey = ( AnimationMKeyTCB* ) key;

            float* tension = tcbKey->tension;
            float* continuity = tcbKey->continuity;
            float* bias = tcbKey->bias;
            float* easeIn = tcbKey->easeIn;
            float* easeOut = tcbKey->easeOut;

            for ( uint j=0; j<dimension; ++j )
            {
                tcbs.push_back ( *tension );
                ++tension;
                tcbs.push_back ( *continuity );
                ++continuity;
                tcbs.push_back ( *bias );
                ++bias;

                eases.push_back ( *easeIn );
                ++easeIn;
                eases.push_back ( *easeOut );
                ++ easeOut;
            }
        }

        else
        {
            // Export flat tangents
            for ( uint j=0; j<dimension; ++j )
            {
                tcbs.push_back ( 0.5f );
                tcbs.push_back ( 0.5f );
                tcbs.push_back ( 0.5f );

                eases.push_back ( 0.0f );
                eases.push_back ( 0.0f );
            }
        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::createMultiCurveTangents (
        const AnimationMKey* key,
        const uint dimension,
        const bool convertUnits,
        std::vector<float> &inTangents,
        std::vector<float> &outTangents,
        float* outputList )
    {
        if ( key->interpolation == COLLADASW::LibraryAnimations::BEZIER )
        {
            // Export bezier tangents
            AnimationMKeyBezier* bezKey = ( AnimationMKeyBezier* ) key;

            TangentPoint* inTangentPoints = bezKey->inTangent;
            TangentPoint* outTangentPoints = bezKey->outTangent;

            for ( uint j=0; j<dimension; ++j )
            {
                if ( convertUnits )
                {
                    inTangents.push_back ( ( *inTangentPoints ).x );
                    inTangents.push_back ( (float) MDistance::internalToUI ( ( *inTangentPoints ).y ) );

                    outTangents.push_back ( ( *outTangentPoints ).x );
                    outTangents.push_back ( (float) MDistance::internalToUI ( ( *outTangentPoints ).y ) );
                }
                else
                {
                    inTangents.push_back ( ( *inTangentPoints ).x );
                    inTangents.push_back ( ( *inTangentPoints ).y );

                    outTangents.push_back ( ( *outTangentPoints ).x );
                    outTangents.push_back ( ( *outTangentPoints ).y );
                }
                ++inTangentPoints;
                ++outTangentPoints;
            }
        }

        else
        {
            // Export flat tangents
            float* outputList = key->output;

            for ( uint j=0; j<dimension; ++j )
            {
                if ( convertUnits )
                {
                    inTangents.push_back ( key->input - 0.0001f );
                    inTangents.push_back ( (float) MDistance::internalToUI ( *outputList ) );

                    outTangents.push_back ( key->input + 0.0001f );
                    outTangents.push_back ( (float) MDistance::internalToUI ( *outputList ) );
                }
                else
                {
                    inTangents.push_back ( key->input - 0.0001f );
                    inTangents.push_back ( *outputList );

                    outTangents.push_back ( key->input + 0.0001f );
                    outTangents.push_back ( *outputList );
                }

                ++outputList;
            }
        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::writeInputSource (
        const String sourceId,
        const std::vector<float> &values,
        String preInfinityType,
        String postInfinityType )
    {
        // Just export if there are values
        if ( values.size() > 0 )
        {
            COLLADASW::FloatSourceF source ( mSW );
            source.setId ( sourceId + INPUT_SOURCE_ID_SUFFIX );
            source.setNodeName ( sourceId + INPUT_SOURCE_ID_SUFFIX );
            source.setArrayId ( sourceId + INPUT_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
            source.setAccessorStride ( 1 );
            source.getParameterNameList().push_back ( PARAM_TYPE_TIME );
            source.setAccessorCount ( ( unsigned long ) values.size() );
            source.prepareToAppendValues();
            source.appendValues ( values );
            source.finish ( false );

            // Export the infinity parameters
            COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
            COLLADASW::Technique techniqueSource ( streamWriter );
            techniqueSource.openTechnique ( PROFILE_MAYA );
            techniqueSource.addParameter ( MAYA_PREINFINITY_PARAMETER, preInfinityType );
            techniqueSource.addParameter ( MAYA_POSTINFINITY_PARAMETER, postInfinityType );
            techniqueSource.closeTechnique();
            source.closeSourceElement();
        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::writeOutputSource (
        const String sourceId,
        const String* parameters,
        const uint dimension,
        const std::vector<float> &values )
    {
        // Just export if there are values
        size_t size = values.size();
        if ( values.size() > 0 && dimension > 0 )
        {
            COLLADASW::TypeIndependentSourceF source ( mSW );
            source.setId ( sourceId + OUTPUT_SOURCE_ID_SUFFIX );
            source.setNodeName ( sourceId + OUTPUT_SOURCE_ID_SUFFIX );
            source.setArrayId ( sourceId + OUTPUT_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
            source.setAccessorStride ( dimension );

            if ( dimension != 16 && dimension != 32 )
            {
                // It's a float source.
                source.setParameterTypeName ( &COLLADASW::CSWC::CSW_VALUE_TYPE_FLOAT );
                for ( uint i=0; i<dimension; ++i )
                    source.getParameterNameList().push_back ( * ( parameters + i ) );
            }

            else if ( dimension == 16 )
            {
                // It's a matrix source.
                source.setParameterTypeName ( &COLLADASW::CSWC::CSW_VALUE_TYPE_FLOAT4x4 );
                source.getParameterNameList().push_back ( PARAM_TYPE_TRANSFORM ); // That's the "TRANSFORM" parameter
            }

            else if ( dimension == 32 )
            {
                // It's a matrix source.
                source.setParameterTypeName ( &COLLADASW::CSWC::CSW_VALUE_TYPE_FLOAT4x4 );
                source.getParameterNameList().push_back ( PARAM_TYPE_X_Y ); // That's the "X_Y" parameter
            }

            source.setAccessorCount ( ( unsigned long ) ( values.size() / dimension ) );
            source.prepareToAppendValues();
            source.appendValues ( values );
            source.finish();
        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::writeInterpolationSource ( const String sourceId,
            const std::vector<String> interpolations )
    {
        // Just export if there are values
        if ( interpolations.size() > 0 )
        {
            COLLADASW::NameSource source ( mSW );
            source.setId ( sourceId + INTERPOLATION_SOURCE_ID_SUFFIX );
            source.setNodeName ( sourceId + INTERPOLATION_SOURCE_ID_SUFFIX );
            source.setArrayId ( sourceId + INTERPOLATION_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
            source.setAccessorStride ( 1 );
            source.getParameterNameList().push_back ( PARAM_TYPE_INTERPOLATION );
            source.setAccessorCount ( ( unsigned long ) interpolations.size() );
            source.prepareToAppendValues();
            source.appendValues ( interpolations );
            source.finish();
        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::writeInTangentSource ( const String sourceId,
            const uint dimension,
            const std::vector<float> &inTangent )
    {
        writeTangentSource ( sourceId, INTANGENT_SOURCE_ID_SUFFIX, dimension, inTangent );
    }

    //---------------------------------------------------------------
    void AnimationExporter::writeOutTangentSource ( const String sourceId,
            const uint dimension,
            const std::vector<float> &outTangent )
    {
        writeTangentSource ( sourceId, OUTTANGENT_SOURCE_ID_SUFFIX, dimension, outTangent );
    }

    //---------------------------------------------------------------
    void AnimationExporter::writeTangentSource ( const String sourceId,
            const String sourceIdSuffix,
            const uint dimension,
            const std::vector<float> &values )
    {
        // Just export if there are values
        if ( values.size() > 0 )
        {
            COLLADASW::FloatSourceF source ( mSW );
            source.setId ( sourceId + sourceIdSuffix );
            source.setNodeName ( sourceId + sourceIdSuffix );
            source.setArrayId ( sourceId + sourceIdSuffix + ARRAY_ID_SUFFIX );

            uint stride = dimension * 2; // One for the in- and one for the outtangent.
            source.setAccessorStride ( stride );

            for ( uint i=0; i<dimension; ++i )
            {
                source.getParameterNameList().push_back ( * ( XY_PARAMETERS + 0 ) );
                source.getParameterNameList().push_back ( * ( XY_PARAMETERS + 1 ) );
            }

            source.setAccessorCount ( ( unsigned long ) ( values.size() / stride ) );
            source.prepareToAppendValues();
            source.appendValues ( values );
            source.finish();
        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::writeTCBSource ( const String sourceId,
            const std::vector<float> &values )
    {
        // Just export if there are values
        if ( values.size() > 0 )
        {
            COLLADASW::FloatSourceF source ( mSW );
            source.setId ( sourceId + TCBS_SOURCE_ID_SUFFIX );
            source.setNodeName ( sourceId + TCBS_SOURCE_ID_SUFFIX );
            source.setArrayId ( sourceId + TCBS_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
            source.setAccessorStride ( 1 );
            source.getParameterNameList().push_back ( PARAM_TYPE_TCBS );
            source.setAccessorCount ( ( unsigned long ) values.size() );
            source.prepareToAppendValues();
            source.appendValues ( values );
            source.finish();
        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::writeEasesSource ( const String sourceId,
            const std::vector<float> &values )
    {
        // Just export if there are values
        if ( values.size() > 0 )
        {
            COLLADASW::FloatSourceF source ( mSW );
            source.setId ( sourceId + EASES_SOURCE_ID_SUFFIX );
            source.setNodeName ( sourceId + EASES_SOURCE_ID_SUFFIX );
            source.setArrayId ( sourceId + EASES_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
            source.setAccessorStride ( 1 );
            source.getParameterNameList().push_back ( PARAM_TYPE_EASES );
            source.setAccessorCount ( ( unsigned long ) values.size() );
            source.prepareToAppendValues();
            source.appendValues ( values );
            source.finish();
        }
    }

    //---------------------------------------------------------------
    template<class T>
    void AnimationExporter::writeAnimationSampler ( const BaseAnimationCurve<T> &animationCurve )
    {
        String sourceId = animationCurve.getSourceId();

        LibraryAnimations::Sampler sampler ( mSW, sourceId + SAMPLER_ID_SUFFIX );

        sampler.addInput ( COLLADASW::InputSemantic::INPUT, COLLADASW::URI ( EMPTY_STRING, sourceId + INPUT_SOURCE_ID_SUFFIX ) );
        sampler.addInput ( COLLADASW::InputSemantic::OUTPUT, COLLADASW::URI ( EMPTY_STRING, sourceId + OUTPUT_SOURCE_ID_SUFFIX ) );
        sampler.addInput ( COLLADASW::InputSemantic::INTERPOLATION, COLLADASW::URI ( EMPTY_STRING, sourceId + INTERPOLATION_SOURCE_ID_SUFFIX ) );

        if ( animationCurve.hasTangents() )
        {
            sampler.addInput ( COLLADASW::InputSemantic::IN_TANGENT, COLLADASW::URI ( EMPTY_STRING, sourceId + INTANGENT_SOURCE_ID_SUFFIX ) );
            sampler.addInput ( COLLADASW::InputSemantic::OUT_TANGENT, COLLADASW::URI ( EMPTY_STRING, sourceId + OUTTANGENT_SOURCE_ID_SUFFIX ) );
        }

        addSampler ( sampler );
    }

    //---------------------------------------------------------------
    template<class T>
    void AnimationExporter::writeAnimationChannel ( const BaseAnimationCurve<T> &animationCurve )
    {
        String sourceId = animationCurve.getSourceId();
        String target = getTarget ( animationCurve );

        addChannel ( COLLADASW::URI ( EMPTY_STRING, sourceId + SAMPLER_ID_SUFFIX ), target );
    }

    //---------------------------------------------------------------
    template<class T>
    String AnimationExporter::getTarget ( const BaseAnimationCurve<T> &animationCurve )
    {
        String subId = animationCurve.getTargetSid();
        String nodeId = animationCurve.getNodeId();
        const uint dimension = animationCurve.getDimension();

        int arrayElement = animationCurve.getArrayElement();
        if ( arrayElement >= 0 )
        {
            std::ostringstream stream;
            stream << subId << "(" << arrayElement << ")";
            return stream.str();
        }
        else
        {
            const String* parameters = animationCurve.getParameters();
            const uint index = animationCurve.getCurveIndex();

            if ( dimension == 1 && ! ( *parameters ).empty() )
            {
                if ( !nodeId.empty() )
                    return nodeId + "/" + subId + "." + * ( parameters+index );
                else
                    return subId + "." + * ( parameters+index );
            }
            else
            {
                if ( !nodeId.empty() )
                    return nodeId + "/" + subId;
                else
                    return subId;
            }
        }
    }

    //---------------------------------------------------------------
    String AnimationExporter::getBaseId ( const MPlug &plug )
    {
        String nodeId = getNodeId ( plug );
        if ( nodeId.empty() )
        {
            return DocumentExporter::mayaNameToColladaName ( plug.name() );
        }
        return DocumentExporter::mayaNameToColladaName ( plug.name() ) + "_" + nodeId;
//        return mDocumentExporter->mayaNameToColladaName ( plug.name() );

        /*
        if ( animation.getDimension() == 1 )
        return animation.getId() + "_" + animation.getSid() + "." + *animation.getParameter();
        else
        return animation.getId() + "_" + animation.getSid();
        */
    }

    //---------------------------------------------------------------
    String AnimationExporter::getNodeId ( const MPlug &plug )
    {
        MObject node = plug.node();
        MFnDagNode fnDagNode ( node );

        // Get the collada id.
        if ( node.hasFn ( MFn::kTransform ) )
        {
            // Check if there is an extra attribute "colladaId" and use this as export id.
            String nodeId;
            MString attributeValue;
            DagHelper::getPlugValue ( node, COLLADA_ID_ATTRIBUTE_NAME, attributeValue );
            if ( attributeValue != EMPTY_CSTRING )
                nodeId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false );
            else nodeId = mDocumentExporter->mayaNameToColladaName ( fnDagNode.name ().asChar () );
            return nodeId;
        }
        // TODO Do we need it?
        else if ( node.hasFn ( MFn::kMesh ) )
        {
            MStatus status;
            MFnMesh meshNode ( node, &status );
            if ( status != MStatus::kSuccess ) 
            {
                MGlobal::displayError ( "No mesh object!" );
                return EMPTY_STRING;
            }
            MDagPath dagPath = meshNode.dagPath ();
            GeometryExporter* geometryExporter = mDocumentExporter->getGeometryExporter ();
            const String& colladaId = geometryExporter->getColladaGeometryId ( dagPath );
            return colladaId;
        }
        else
        {
            String partialPathName = fnDagNode.partialPathName().asChar();
            if ( partialPathName.empty() )
            {
                return partialPathName;
            }
            return DocumentExporter::mayaNameToColladaName ( fnDagNode.partialPathName(), false );
        }

        return EMPTY_STRING;
    }

    //---------------------------------------------------------------
    bool AnimationExporter::addNodeAnimation(
        MObject node,
        const String& attrname,
        const SampleType& sampleType,
        const String* parameters /* = EMPTY_PARAMETER */,
        const bool convertUnits /*= false*/, 
        const int arrayElement /*= -1*/,
        const bool isRelativeAnimation /*= false*/,
        ConversionFunctor* conversion /*= NULL */ )
    {
        // Take the attribute name as the sub id.
        String targetSid = attrname;

        return addNodeAnimation (
            node,
            targetSid,
            attrname,
            sampleType,
            parameters,
            convertUnits, 
            arrayElement,
            isRelativeAnimation,
            conversion );
    }

    //---------------------------------------------------------------
    bool AnimationExporter::addNodeAnimation (
        MObject node,
        const String& targetSid,
        const String& attrname,
        const SampleType& sampleType,
        const String* parameters /* = EMPTY_PARAMETER */,
        const bool convertUnits /*= false*/, 
        const int arrayElement /*= -1*/,
        const bool isRelativeAnimation /*= false*/,
        ConversionFunctor* conversion /*= NULL */ )
    {
        // We will not proceed, if we don't have a node object
        if ( node == MObject::kNullObj ) return false;

        // attach the function set to the object
        MFnDependencyNode fn ( node );

        // get the plug to the requested attribute
        MStatus status;
        MPlug plug = fn.findPlug ( attrname.c_str(), &status );
        if ( status != MS::kSuccess ) return false;

        return addPlugAnimation (
            plug,
            targetSid,
            sampleType,
            parameters,
            convertUnits, 
            arrayElement,
            isRelativeAnimation,
            conversion );
    }

    //---------------------------------------------------------------
    bool AnimationExporter::addPlugAnimation (
        MPlug& plug,
        const String& targetSid,
        const uint sampleType,
        const String* parameters /* = EMPTY_PARAMETER */,
        const bool convertUnits /*= false*/, 
        const int arrayElement /*= -1*/,
        const bool isRelativeAnimation /*= false*/,
        ConversionFunctor* conversion /*= NULL */ )
    {
        return addPlugAnimation (
            plug,
            targetSid,
            ( SampleType ) sampleType,
            parameters,
            convertUnits, 
            arrayElement,
            isRelativeAnimation,
            conversion );
    }

    //---------------------------------------------------------------
    bool AnimationExporter::addPlugAnimation (
        MPlug& plug,
        const String& targetSid,
        const SampleType& sampleType,
        const String* parameters /* = EMPTY_PARAMETER */,
        const bool convertUnits /*= false*/, 
        const int arrayElement /*= -1*/,
        const bool isRelativeAnimation /*= false*/,
        ConversionFunctor* conversion /*= NULL */ )
    {
        // if (animatedValue == NULL) return;
        bool isAnimated = false;
        bool isSampling = false;

        if ( !isImport )
        {
            AnimationSampleCache* animCache = mDocumentExporter->getAnimationCache();
            AnimationHelper::checkForSampling ( animCache, sampleType, plug );
            isSampling = animCache->markPlugWanted ( plug );
        }

        // Buffer the call to support driven-key animations
        String baseId = getBaseId ( plug );
        String nodeId = getNodeId ( plug );

        // Create the animated element.
        AnimationElement* animatedElement;
        animatedElement = new AnimationElement ( plug, baseId, targetSid, nodeId, parameters, convertUnits, sampleType );
        animatedElement->setIsRelativeAnimation( isRelativeAnimation );
        animatedElement->setArrayElement ( arrayElement );
        animatedElement->setIsSampling ( isSampling );

        // Get the animation object
        MObject animationObject = plug.node();

        // Check if there is an extra attribute "colladaId" and use this as export id.
        MString attributeValue;
        DagHelper::getPlugValue ( animationObject, COLLADA_ID_ATTRIBUTE_NAME, attributeValue );
        if ( attributeValue != EMPTY_CSTRING )
        {
            // Generate a valid collada name, if necessary.
            String colladaAnimationId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false );
            animatedElement->setOriginalColladaId ( colladaAnimationId );
        }

        // Copy the conversion functor. If none is provided: generate one.
        if ( conversion != NULL )
        {
            animatedElement->setConversion ( conversion );
        }
        else if ( ( sampleType & kAngle ) == kAngle )
        {
            ConversionFunctor* conversion = new ConversionScaleFunctor (
                isImport ? COLLADABU::Math::Utils::degToRadF ( 1.0f ) : COLLADABU::Math::Utils::radToDegF ( 1.0f ) );
            animatedElement->setConversion ( conversion );
        }

        if ( isSampling )
        {
            mAnimationElements.push_back ( animatedElement );
            isAnimated = true;
        }
        else if ( exportAnimation ( animatedElement ) )
        {
            mAnimationElements.push_back ( animatedElement );
            isAnimated = true;

            /*
            // TODO
            // check with the unset driven curves to see if new curve matches what they are waiting for
            size_t unsetDrivenCurvesCount = unsetDrivenCurves.size();
            for (size_t i = unsetDrivenCurvesCount; i > 0; i --)
            {
            DaeUnsetDriven* unsetDriven = unsetDrivenCurves.at(i-1);
            int index = -1;
            if (FindAnimated(unsetDriven->plug, index, animatedPlug))
            {
            unsetDriven->curve->SetDriver(animatedPlug->animatedValue, index);
            unsetDrivenCurves.erase(i-1);
            SAFE_DELETE(unsetDriven);
            }
            }
            */
        }
        else
        {
            delete animatedElement;
        }

        return isAnimated;
    }

    // ------------------------------------------------------------
    bool AnimationExporter::createAnimationCurve (
        AnimationElement* animatedElement,
        const MPlug& plug,
        const SampleType sampleType,
        ConversionFunctor* conversion,
        AnimationCurveList& curves,
        uint curveIndex )
    {
        // Export any animation associated with the specified plug
        bool curveCreated = false;

        // Get the current sample type
        SampleType typeValue = ( SampleType ) ( sampleType & kValueMask );

        // Check if this plug is animated
        // Differentiate between expression, IK, and animCurve-based curves here.
        bool animatedMatrix = typeValue == kMatrix;

        MPlugArray connections, sourcePlugs;
        AnimationSampleCache* animCache = mDocumentExporter->getAnimationCache();
        AnimationResult aresult = AnimationHelper::isAnimated ( animCache, plug );
        if ( aresult == kISANIM_None && !animatedMatrix ) return false;

        if ( !ExportOptions::isSampling() && ( aresult == kISANIM_Curve || aresult == kISANIM_Character ) )
        {
            // Create a AnimationCurve for the corresponding Maya animation curve node
            if ( aresult == kISANIM_Curve )
            {
                // Get the curve object
                MObject curveObject = DagHelper::getSourceNodeConnectedTo ( plug );

                // Get the animation id.
                String mayaAnimationId = getBaseId ( plug );

                // Check if there is an extra attribute "colladaId" and use this as export id.
                MString attributeValue;
                DagHelper::getPlugValue ( curveObject, COLLADA_ID_ATTRIBUTE_NAME, attributeValue );
                if ( attributeValue != EMPTY_CSTRING )
                {
                    // Generate a valid collada name, if necessary.
                    String colladaAnimationId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false );
                    animatedElement->setOriginalColladaId ( colladaAnimationId );
                }

                // Create the curve with the ids
                AnimationCurve* curve;
                curve = createAnimationCurveFromNode ( animatedElement, curveObject, mayaAnimationId, curveIndex );

                // Push the curve in the list of curves
                if ( curve != NULL ) 
                {
                    // Set the flag, that a curve exist.
                    curveCreated = true;

                    curves.push_back ( curve );
                    ++curveIndex;
                }
            }
            else if ( aresult == kISANIM_Character )
            {
                // Get the curve object
                MObject curveObject = DagHelper::getSourceNodeConnectedTo ( plug );

                // TODO id preservation doesn't work in this case...
                // Check if there is an extra attribute "colladaId" and use this as export id.
                MString attributeValue;
                DagHelper::getPlugValue ( curveObject, COLLADA_ID_ATTRIBUTE_NAME, attributeValue );
                if ( attributeValue != EMPTY_CSTRING )
                {
                    // Generate a valid collada name, if necessary.
                    String colladaAnimationId = colladaAnimationId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false );
                    animatedElement->setOriginalColladaId ( colladaAnimationId );
                }

                // Create the animation curve from the current clip
                curveCreated = createAnimationCurveFromClip ( animatedElement, plug, conversion, curves, curveIndex );

                // It is possible that the character has some curves as well as clips
                MPlug plugIntermediate;
                DagHelper::getPlugConnectedTo ( plug, plugIntermediate );

                // TODO Should I increment the curve index in this case???
                // Clips will not have curves directly attached like this
                createAnimationCurve ( animatedElement, plugIntermediate, sampleType, NULL, curves, curveIndex );
            }

            // For a boolean-typed curve, back out early. The curve is valid,
            // but doesn't include interpolations or tangents.
            for ( AnimationCurveList::iterator itC = curves.begin(); itC != curves.end(); ++itC )
            {
                AnimationCurve* curve = ( *itC );
                curve->convertValues ( conversion, conversion );
            }
        }
        else
        {
            // Get the cache with the animations
            AnimationSampleCache* animCache = mDocumentExporter->getAnimationCache();
            String baseId = getBaseId ( plug );

            // Get the curve object
            MObject curveObject = DagHelper::getSourceNodeConnectedTo ( plug );

            // Check if there is an extra attribute "colladaId" and use this as export id.
            MString attributeValue;
            DagHelper::getPlugValue ( curveObject, COLLADA_ID_ATTRIBUTE_NAME, attributeValue );
            if ( attributeValue != EMPTY_CSTRING )
            {
                // Generate a valid collada name, if necessary.
                String colladaAnimationId = colladaAnimationId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false );
                animatedElement->setOriginalColladaId ( colladaAnimationId );
            }

            // Sample the animation.
            if ( animatedMatrix )
            {
                for ( uint i = 0; i<16; ++i )
                {
                    AnimationCurve* curve = new AnimationCurve ( animatedElement, baseId );
                    curve->setCurveIndex ( curveIndex );
                    ++curveIndex;

                    curves.push_back ( curve );
                }

                // Sample the curves
                curveCreated = AnimationHelper::sampleAnimatedTransform ( animCache, plug, curves );
            }
            else
            {
                AnimationCurve* curve = new AnimationCurve ( animatedElement, baseId );
                curve->setCurveIndex ( curveIndex );
                ++curveIndex;

                curveCreated = AnimationHelper::sampleAnimatedPlug ( animCache, plug, curve, conversion );
                curves.push_back ( curve );
            }

            // Verify that there is, in fact, an animation in this curve.
            bool equals = curvesAreEqual ( curves );

            // If there is no animation, we can delete the curve
            if ( equals )
            {
                for ( uint i=0; i<curves.size(); ++i )
                {
                    AnimationCurve* curve = curves[i];
                    delete curve;
                    curve = NULL;
                }
                curves.clear();

                // Reset the flag, that a curve exist.
                curveCreated = false;
            }
        }

        // Return the flag, if a curve was created.
        return curveCreated;
    }

    // ------------------------------------------------------------
    bool AnimationExporter::curvesAreEqual ( const AnimationCurveList &curves )
    {
        bool equals = true;

        for ( uint i=0; i<curves.size() && equals; ++i )
        {
            AnimationCurve* curve = curves[i];
            size_t valueCount = curve->getKeyCount();
            if ( valueCount > 1 )
            {
                for ( size_t j=0; j< ( valueCount-1 ) && equals; ++j )
                {
                    AnimationKey* key1 = ( ( AnimationKey* ) curve->getKey ( j ) );
                    AnimationKey* key2 = ( ( AnimationKey* ) curve->getKey ( j+1 ) );
                    equals = key1->output == key2->output;
                }
            }
        }

        return equals;
    }

    // ------------------------------------------------------------
    // Export a plug's animations, if present
    bool AnimationExporter::createAnimationCurveFromClip (
        AnimationElement* animatedElement,
        const MPlug& plug,
        ConversionFunctor* conversion,
        AnimationCurveList& curves,
        const uint curveIndex )
    {
        // Flag, if a curve was created
        bool curveCreated = false;

        // Verify the character node for this plug
        MStatus status;
        MObject characterNode = AnimationHelper::getAnimatingNode ( plug );
        MFnCharacter characterFn ( characterNode, &status );
        if ( status != MStatus::kSuccess ) return false;

        // Find/Create the clips associated with this character node
        AnimationClipList clips;
        getCharacterClips ( characterNode, clips );
        if ( clips.empty() ) return false;

        // Iterate through the clips
        for ( AnimationClipList::iterator it = clips.begin(); it != clips.end(); ++it )
        {
            AnimationClip* clip = ( *it );
            int index = clip->findPlug ( plug );
            if ( index == -1 ) continue;

            // Create a new animated element
            String baseId = getBaseId ( plug ) + "-" + clip->getClipId();
            String subId = COLLADASW::Utils::checkID ( animatedElement->getTargetSid() );
            String nodeId = animatedElement->getNodeId();
            const String* parameters = animatedElement->getParameters();
            bool convertUnits = animatedElement->getConvertUnits ();
            SampleType sampleType = animatedElement->getSampleType();
            AnimationElement* animatedChild = new AnimationElement ( plug, baseId, subId, nodeId, parameters, convertUnits, sampleType );

            // Push the animated child in the child list of the parent animated element
            animatedElement->addChildElement ( animatedChild );

            // Create the curve segment for this clip-plug std::pair
            MObject animCurveNode = clip->animCurves[index];
            AnimationCurve* curve = createAnimationCurveFromNode ( animatedChild, animCurveNode, baseId, curveIndex );

            if ( curve == NULL ) continue;

            // Convert the values, for example if using angles.
            curve->convertValues ( conversion, conversion );

            // Set the dimension of the child clips
            if ( animatedElement->isCompoundElement() ) curve->setDimension ( kSingle );

            // Add the created curve to the list of curves of the child element.
            animatedChild->addAnimatedCurve ( curve );

            // Set the flag, that a curve was created
            curveCreated = true;

            // Assign the new curve to the animation clip.
            // Open an animation node and add the channel of the current animation
            const String& originalColladaId = animatedElement->getOriginalColladaId ();
            if ( !originalColladaId.empty () )
            {
                clip->colladaClip->setInstancedAnimation ( originalColladaId );
            }
            else
            {
                clip->colladaClip->setInstancedAnimation ( curve->getBaseId() );
            }

            // Push the current curve in the list of curves
            //  curves.push_back(curve);
        }

        // Return the flag, that a curve was created
        return curveCreated;
    }

    // ------------------------------------------------------------
    // Retrieve/Create the clips associated with a character node
    void AnimationExporter::getCharacterClips (
        const MObject& characterNode,
        AnimationClipList& characterClips )
    {
        MStatus status;

        // Retrieve the known clips associated with this character node
        AnimationClipList::iterator itC = mAnimationClips.begin();
        for ( ; itC != mAnimationClips.end(); ++itC )
        {
            if ( ( *itC )->characterNode == characterNode )
                characterClips.push_back ( *itC );
        }

        if ( characterClips.empty() )
        {
            // Create the clips associated with this character
            MFnCharacter characterFn ( characterNode );
            int clipCount = characterFn.getSourceClipCount();
            if ( clipCount == 0 ) return;

            MPlugArray plugs;
            for ( int i=0; i<clipCount; ++i )
            {
                // Export any source clip, including poses, which are simply 1-key curves.
                MObject clipNode = characterFn.getSourceClip ( i );
                MFnClip clipFn ( clipNode, &status );
                if ( status != MStatus::kSuccess ) continue;

                // Create the corresponding COLLADA animation clip
                String clipName = DocumentExporter::mayaNameToColladaName ( clipFn.name() );
                float startTime = ( float ) clipFn.getSourceStart().as ( MTime::kSeconds );
                float endTime = startTime + ( float ) clipFn.getSourceDuration().as ( MTime::kSeconds );

                AnimationClip* clip = new AnimationClip();
                clip->colladaClip = new COLLADASW::ColladaAnimationClip ( clipName, startTime, endTime );
                clip->characterNode = characterNode;
                clipFn.getMemberAnimCurves ( clip->animCurves, clip->plugs );

                mAnimationClips.push_back ( clip );
                characterClips.push_back ( clip );
            }
        }
    }

    // ------------------------------------------------------------
    // Create a curve from a Maya node, which should be an 'animCurveXX' type
    AnimationCurve* AnimationExporter::createAnimationCurveFromNode (
        AnimationElement* animatedElement,
        const MObject& curveObject,
        const String& baseId,
        const uint curveIndex )
    {
        MStatus status;
        MFnAnimCurve animCurveFn ( curveObject, &status );
        if ( status != MStatus::kSuccess ) return NULL;

        // Check for a supported curve type
        bool isLengthCurve = false;
        MFnAnimCurve::AnimCurveType curveType = animCurveFn.animCurveType();
        if ( curveType == MFnAnimCurve::kAnimCurveTT ||
                curveType == MFnAnimCurve::kAnimCurveUT ||
                curveType == MFnAnimCurve::kAnimCurveUnknown )
        {
            // Unsupported curve types.
            std::cerr << "Animation curve type not supported! " << curveType << std::endl;
            return NULL;
        }

        isLengthCurve = ( curveType == MFnAnimCurve::kAnimCurveTL ) || ( curveType == MFnAnimCurve::kAnimCurveUL );

        // Create the output, single-dimensional curve
        AnimationCurve* curve = new AnimationCurve ( animatedElement, baseId );
        curve->setCurveIndex ( curveIndex );
        curve->setPreInfinity ( animCurveFn.preInfinityType() );
        curve->setPostInfinity ( animCurveFn.postInfinityType() );
        curve->setIsStatic ( animCurveFn.isStatic() );

        // TODO
        AnimationElement* infoElement = NULL; // used for driven key only
        if ( !animCurveFn.isTimeInput() && animCurveFn.isUnitlessInput() )
        {
            int index = -1;

            // Figure out the real curve input
            MPlug connected;
            bool connection = DagHelper::getPlugConnectedTo ( animCurveFn.object(), ATTR_INPUt, connected );
            if ( connection && connected.node() != MObject::kNullObj )
            {
                // Look-ups for the element
                infoElement = findAnimated ( connected, index );

                // TODO I don't know, what this is...
                //     if (infoElement != NULL)
                //     {
                //      curve->SetDriver(infoElement->animatedValue, index);
                //     }
                //     else
                //     {
                //      ANIM->AddUnsetDrivenCurve(curve, connected); // cache until we find the real curve
                //     }
            }
        }

        // Create the animation keys
        createAnimationCurveKeys ( animCurveFn, curve, infoElement );

        return curve;
    }


    // ------------------------------------------------------------
    AnimationElement* AnimationExporter::findAnimated ( const MPlug& plug, int& index )
    {
        // Check the known plugs and their child plugs
        AnimatedElementList::iterator it = mAnimationElements.begin();
        for ( ; it != mAnimationElements.end(); ++it )
        {
            if ( findAnimated ( plug, index, *it ) ) return *it;
        }

        return NULL;
    }

    // ------------------------------------------------------------
    bool AnimationExporter::findAnimated ( const MPlug& plug, int& index, AnimationElement* animation )
    {
        if ( animation->getPlug() == plug )
        {
            index = -1;
            return true;
        }
        else
        {
            uint childCount = animation->getPlug().numChildren();
            for ( uint j = 0; j < childCount; ++j )
            {
                if ( animation->getPlug().child ( j ) == plug )
                {
                    index = ( int ) j;
                    return true;
                }
            }
        }

        return false;
    }

    // ------------------------------------------------------------
    // Create the animation keys
    void AnimationExporter::createAnimationCurveKeys (
        MFnAnimCurve &animCurveFn,
        AnimationCurve* curve,
        AnimationElement* animatedElement )
    {
        // Create the animation keys
        uint keyCount = animCurveFn.numKeys();
        for ( uint keyPosition = 0; keyPosition < keyCount; ++keyPosition )
        {
            InterpolationType interpolationType;
            interpolationType = AnimationHelper::toInterpolation ( animCurveFn.outTangentType ( keyPosition ) );
            AnimationKey* key = ( ( AnimationKey* ) curve->addKey ( interpolationType ) );

            // Gather the key time values
            if ( animCurveFn.isTimeInput() )
            {
                key->input = ( float ) animCurveFn.time ( keyPosition ).as ( MTime::kSeconds );
                key->output = ( float ) animCurveFn.value ( keyPosition );
            }
            else if ( animCurveFn.isUnitlessInput() )
            {
                // Driven-key animation curve!

                // Transform the input values into something known by COLLADA
                float value = ( float ) animCurveFn.unitlessInput ( keyPosition );
                if ( animatedElement != NULL )
                {
                    if ( animatedElement->getConversion() != NULL )
                    {
                        MDGContext context;
                        value = ( *animatedElement->getConversion() ) ( value );
                    }

                    if ( ( animatedElement->getSampleType() & kAngle ) == kAngle )
                        value = COLLADABU::Math::Utils::radToDegF ( value );
                }

                key->input = value;
                key->output = ( float ) animCurveFn.value ( keyPosition );
            }

            if ( key->interpolation == COLLADASW::LibraryAnimations::BEZIER )
            {
                // Create the bezier keys
                MFnAnimCurve::AnimCurveType type = animCurveFn.animCurveType  ();
                createBezierKey ( key, animCurveFn, keyPosition, keyCount );
            }
        }
    }

    // ------------------------------------------------------------
    void AnimationExporter::createBezierKey (
        AnimationKey* key,
        MFnAnimCurve &animCurveFn,
        uint keyPosition,
        uint keyCount )
    {
        // Get tangent control points and fill in the animation data structure
        AnimationKeyBezier* bkey = ( AnimationKeyBezier* ) key;

        // 
        // COLLADA Spec:
        // -------------
        // In COLLADA, the <input> semantics IN_TANGENT and OUT_TANGENT 
        // for Bezier curves are used to store the control points.
        // 
        // In COLLADA, a geometry vector for Bézier segment[i] is defined by:
        // • P0 is POSITION[i]
        // • C0 is OUT_TANGENT[i]
        // • C1 is IN_TANGENT[i+1]
        // • P1 is POSITION[i+1]
        // 
        // A cubic Bézier spline equation is given by:
        // B(s) = P0*(1-s)^3 + 3*C0*s*(1-s)^2 + 3*C1*s^2*(1-s) + P1*s^3
        // 
        // Now the way to the magic factor 3:
        // ----------------------------------
        // The first derivation of B(s):
        // B'(s) = -3*P0*(1-s)^2 + 3*C0*(1-s)^2 - 2*s*(1-s) + 3*C1*(2s(1-s)-s^2) + 3*P1*s^2
        // 
        // This resolves for s=0 (out tangent):
        // B'(0) = -3*P0 + 3*C0 = 3*(C0-P0) = To
        // ==> C0 = ( To / 3 ) + P0
        // 
        // This resolves for s=1 (in tangent):
        // B'(0) = -3*C1 + 3*P1 = Ti
        // ==> C1 = P1 - ( Ti / 3 ) 
        // 
        // Maya documentation:
        // -------------------
        // Animation curves may have either weighted or non-weighted tangents. 
        // With non-weighted tangents, tangents are implemented as vectors and P2 and P3 are 
        // internally adjusted to account for the time difference between P1 and P4.
        // 
        // When evaluating a time within a segment, the following algortithms are used:
        // 
        // For weighted tangents:
        //      where x is the start of the segment
        //      given the bezier x parameters a', b', c', d', find the parameter t 
        //      which satisfies the formula:
        //          (time - x) = (t^3 * a') + (t^2 + b') + (t * c') + d'
        //      with t (and the bezier y parameters a, b, c, d) compute the value as:
        //          v = (t^3 * a) + (t^2 + b) + (t * c) + d
        // 
        // For non-weighted tangents:
        //      where x is the start of the segment
        //      compute the parameter t as time - x
        //      with t (and the bezier y parameters a, b, c, d) compute the value as:
        //          v = (t^3 * a) + (t^2 + b) + (t * c) + d
        // 

        bool isWeightedCurve = animCurveFn.isWeighted();
        float prevTime =
            keyPosition > 0 ?
            ( float ) animCurveFn.time ( keyPosition-1 ).as ( MTime::kSeconds ) :
            ( float ) ( animCurveFn.time ( 0 ).as ( MTime::kSeconds ) - 1.0 );
        float curTime = ( float ) animCurveFn.time ( keyPosition ).as ( MTime::kSeconds );
        float nextTime =
            keyPosition < keyCount - 1 ?
            ( float ) animCurveFn.time ( keyPosition+1 ).as ( MTime::kSeconds ) :
            ( float ) ( animCurveFn.time ( keyPosition ).as ( MTime::kSeconds ) + 1.0 );

        // --------------------------------
        // In-tangent

        float slopeX, slopeY;
        animCurveFn.getTangent ( keyPosition, slopeX, slopeY, true /*keyPosition>0*/ );

        if ( !isWeightedCurve )
        {
            // Extend the slope to be one third of the time-line in the X-coordinate.
            // We need to multiply the slopeY value with itself 
            // to get the direction of the tangents slope.
            if ( slopeX == 0 ) slopeY = 0;
            else slopeY *= ( curTime - prevTime ) / slopeX / 3.0f;
            slopeX = ( curTime - prevTime ) / 3.0f;
        }
        else
        {
            // Take out the magic 3.0 factor. See documentation above.
            slopeX /= 3.0f;
            slopeY /= 3.0f; 
        }
        bkey->inTangent = TangentPoint ( bkey->input - slopeX, bkey->output - slopeY );

        // --------------------------------
        // Out-tangent

        animCurveFn.getTangent ( keyPosition, slopeX, slopeY, false /*keyPosition>=keyCount-1*/ );

        if ( !isWeightedCurve )
        {
            // Extend the slope to be one third of the time-line in the X-coordinate.
            // We need to multiply the slopeY value with itself 
            // to get the direction of the tangents slope.
            if ( slopeX == 0 ) slopeY = 0;
            else slopeY *= ( nextTime - curTime ) / slopeX / 3.0f;
            slopeX = ( nextTime - curTime ) / 3.0f;
        }
        else
        {
            // Take out the magic 3.0 factor. See documentation above.
            slopeX /= 3.0f;
            slopeY /= 3.0f;
        }

        bkey->outTangent = TangentPoint ( bkey->input + slopeX, bkey->output + slopeY );
    }

    // ------------------------------------------------------------
    void AnimationExporter::sampleMKey ( AnimationMKey* key,
                                         const AnimationCurve* curve,
                                         const size_t curvePosition,
                                         const float input,
                                         const float previousSpan,
                                         const float nextSpan )
    {
        // Sample the curve
        float value = key->output[curvePosition] = curve->evaluate ( input );

        if ( key->interpolation == COLLADASW::LibraryAnimations::BEZIER )
        {
            // Calculate the slope at the sampled point.
            // Since the curve should be smooth: the in/out tangents should be equal.
            AnimationMKeyBezier* bkey = ( AnimationMKeyBezier* ) key;
            float slope = ( value - curve->evaluate ( input - SMALL_DELTA ) ) / SMALL_DELTA;
            bkey->inTangent[curvePosition] = TangentPoint ( input - previousSpan, value - slope * previousSpan );
            bkey->outTangent[curvePosition] = TangentPoint ( input + nextSpan, value + slope * nextSpan );
        }
        else if ( key->interpolation == COLLADASW::LibraryAnimations::TCB )
        {
            // Don't fool around: just set default values.
            AnimationMKeyTCB* tkey = ( AnimationMKeyTCB* ) key;
            tkey->tension[curvePosition] = tkey->continuity[curvePosition] = tkey->bias[curvePosition] = 0.5f;
            tkey->easeIn[curvePosition] = tkey->easeOut[curvePosition] = 0.0f;
        }
    }

    // ------------------------------------------------------------
    void AnimationExporter::createTCBMKey ( AnimationMKey* key,
                                            const AnimationKeyList& curveKeys,
                                            const size_t curvePosition,
                                            const size_t keyPosition )
    {
        AnimationMKeyTCB* tkey = ( AnimationMKeyTCB* ) key;

        if ( curveKeys[keyPosition]->interpolation == COLLADASW::LibraryAnimations::TCB )
        {
            AnimationKeyTCB* tkey2 = ( AnimationKeyTCB* ) curveKeys[keyPosition];
            tkey->tension[curvePosition] = tkey2->tension;
            tkey->continuity[curvePosition] = tkey2->continuity;
            tkey->bias[curvePosition] = tkey2->bias;
            tkey->easeIn[curvePosition] = tkey2->easeIn;
            tkey->easeOut[curvePosition] = tkey2->easeOut;
        }
        else
        {
            // Default to flat values.
            tkey->tension[curvePosition] = tkey->continuity[curvePosition] = tkey->bias[curvePosition] = 0.5f;
            tkey->easeIn[curvePosition] = tkey->easeOut[curvePosition] = 0.0f;
        }
    }

    // ------------------------------------------------------------
    void AnimationExporter::createBezierMKey (
        AnimationMKey* key,
        const AnimationKeyList& curveKeys,
        const size_t curvePosition,
        const float previousSpan,
        const float nextSpan,
        const size_t keyPosition )
    {
        size_t curveKeyCount = curveKeys.size();
        float oldPreviousSpan = ( keyPosition > 0 ? curveKeys[keyPosition]->input - curveKeys[keyPosition - 1]->input : 1.0f ) / 3.0f;
        float oldNextSpan = ( keyPosition < curveKeyCount - 1 ? curveKeys[keyPosition + 1]->input - curveKeys[keyPosition]->input : 1.0f ) / 3.0f;

        // Calculate the new tangent: keep the slope proportional
        AnimationMKeyBezier* bkey = ( AnimationMKeyBezier* ) key;

        if ( curveKeys[keyPosition]->interpolation == COLLADASW::LibraryAnimations::BEZIER )
        {
            AnimationKeyBezier* bkey2 = ( AnimationKeyBezier* ) curveKeys[keyPosition];
            TangentPoint absolute ( bkey->input, bkey->output[curvePosition] );

            TangentPoint inTangent = bkey2->inTangent;
            TangentPoint inPoint = inTangent - absolute;
            TangentPoint result = absolute + inPoint;

            bkey->inTangent[curvePosition] = absolute + ( bkey2->inTangent - absolute ) / oldPreviousSpan * previousSpan;
            bkey->outTangent[curvePosition] = absolute + ( bkey2->outTangent - absolute ) / oldNextSpan * nextSpan;
        }
        else
        {
            // Default to flat tangents.
            bkey->inTangent[curvePosition] = TangentPoint ( bkey->input - previousSpan, bkey->output[curvePosition] );
            bkey->outTangent[curvePosition] = TangentPoint ( bkey->input + nextSpan, bkey->output[curvePosition] );
        }
    }

    // ------------------------------------
    const String AnimationExporter::findColladaAnimationId ( const String& mayaAnimationId )
    {
        const StringToStringMap::const_iterator it = mMayaIdColladaIdMap.find ( mayaAnimationId );
        if ( it != mMayaIdColladaIdMap.end () )
        {
            return it->second;
        }
        return EMPTY_STRING;
    }

} // namespace COLLADAMaya
