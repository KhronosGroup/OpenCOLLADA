/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MAAnimationImporter.h"
#include "DAE2MASyntax.h"
#include "DAE2MAVisualSceneImporter.h"
#include "DAE2MATransformAnimation.h"
#include "DAE2MAEffectImporter.h"
#include "DAE2MAMorphAnimation.h"
#include "DAE2MAControllerImporter.h"

#include "COLLADAFWFloatOrDoubleArray.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWTranslate.h"

#include <MayaDMAnimCurveTA.h>
#include <MayaDMAnimCurveTU.h>
#include <MayaDMCommands.h>
#include <MayaDMScript.h>


namespace DAE2MA
{

    /** The standard name for an animation. */
    const String AnimationImporter::ANIMATION_NAME = "anim";

    /** The framerate of the animation. */
    const double AnimationImporter::ANIM_FRAMERATE = 24;


    //------------------------------
	AnimationImporter::AnimationImporter( DocumentImporter* documentImporter )
        : BaseImporter ( documentImporter )
	{
	}
	
    //------------------------------
	AnimationImporter::~AnimationImporter()
	{
        std::map<COLLADAFW::UniqueId, std::vector<MayaDM::AnimCurve*> >::iterator it = mMayaDMAnimationCurves.begin ();
        while ( it != mMayaDMAnimationCurves.end () )
        {
            std::vector<MayaDM::AnimCurve*> animCurves = it->second;
            for ( size_t i=0; i<animCurves.size (); ++i )
            {
                MayaDM::AnimCurve* animCurve = animCurves [i];
                delete animCurve;
            }
            animCurves.clear ();

            ++it;
        }
        mMayaDMAnimationCurves.clear ();
	}

    //------------------------------
    void AnimationImporter::importAnimation ( const COLLADAFW::Animation* animation )
    {
        // Check if the animation is already imported.
        const COLLADAFW::UniqueId& animationId = animation->getUniqueId ();
        if ( findAnimation ( animationId ) ) return;

        // Push the animation id in the list of imported ids.
        mAnimationIds.push_back ( animationId );

        // Import the animation data.
        const COLLADAFW::Animation::AnimationType& animationType = animation->getAnimationType ();
        switch ( animationType )
        {
        case COLLADAFW::Animation::ANIMATION_CURVE:
            {
                COLLADAFW::AnimationCurve* animationCurve = ( COLLADAFW::AnimationCurve* ) animation;
                importAnimationCurve ( animationCurve );
                break;
            }
        case COLLADAFW::Animation::ANIMATION_FORMULA:
            break;
        default:
            break;
        }
    }

    //------------------------------
    void AnimationImporter::importAnimationCurve ( COLLADAFW::AnimationCurve* animationCurve )
    {
        const COLLADAFW::PhysicalDimension& physicalDimension = animationCurve->getInPhysicalDimension ();
        if ( physicalDimension != COLLADAFW::PHYSICAL_DIMENSION_TIME )
        {
            std::cerr << "Import of other physical dimension then TIME not supported: " << physicalDimension << std::endl;
            return;
        }

        // Write the key time values
        const COLLADAFW::AnimationCurve::InterpolationType& interpolationType = animationCurve->getInterpolationType ();
        switch ( interpolationType )
        {
        case COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER:
            {
                TangentType tangentType = TANGENT_TYPE_FIXED;
                writeAnimationCurve ( animationCurve, tangentType );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_BSPLINE:
            {
                std::cerr << "Unknown animation interpolation type: INTERPOLATION_BSPLINE" << std::endl;
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_CARDINAL:
            {
                std::cerr << "Unknown animation interpolation type: INTERPOLATION_CARDINAL" << std::endl;
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_HERMITE:
            {
                std::cerr << "Unknown animation interpolation type: INTERPOLATION_HERMITE" << std::endl;
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR:
            {
                TangentType tangentType = TANGENT_TYPE_LINEAR;
                writeAnimationCurve ( animationCurve, tangentType );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_MIXED:
            {
                writeAnimationCurveByKeys ( animationCurve );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_STEP:
            {
                TangentType tangentType = TANGENT_TYPE_STEP;
                writeAnimationCurve ( animationCurve, tangentType );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_UNKNOWN:
            {
                TangentType tangentType = TANGENT_TYPE_CLAMPED;
                writeAnimationCurve ( animationCurve, tangentType );
                //std::cerr << "Unknown animation interpolation type!" << std::endl;
                break;
            }
        default:
            break;
        }
    }

    //------------------------------
    void AnimationImporter::writeAnimationCurve ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        const TangentType& tangentType /*= TANGENT_TYPE_DEFAULT*/ )
    {
        // The input is always the time with a stride of 2
        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = animationCurve->getInputValues ();
        size_t numInputValues = inputValuesArray.getValuesCount ();

        // The output can have different dimensions.
        const COLLADAFW::FloatOrDoubleArray& outputValuesArray = animationCurve->getOutputValues ();
        size_t outDimension = animationCurve->getOutDimension ();
        size_t numOutputValues = outputValuesArray.getValuesCount () / outDimension;

        const COLLADAFW::PhysicalDimensionArray& outPhysicalDimensions = animationCurve->getOutPhysicalDimensions ();
        size_t outDimension2 = outPhysicalDimensions.getCount ();

        if ( numInputValues != numOutputValues || outDimension != outDimension2 )
        {
            std::cerr << "Invalid animation!" << std::endl;
            return;
        }

        // The uniqueId of the animation.
        const COLLADAFW::UniqueId& animationId = animationCurve->getUniqueId ();

        // Create a curve for every animated element.
        for ( size_t outputIndex=0; outputIndex<outDimension; ++outputIndex )
        {
            // Make the maya name unique and manage it in all necessary lists.
            String animationName = animationCurve->getName ();
            if ( animationName.empty () ) animationName = ANIMATION_NAME;
            animationName = DocumentImporter::frameworkNameToMayaName ( animationName );
            const ExtraDataCallbackHandler& callbackHandler = getDocumentImporter ()->getMayaIdCallbackHandler ();
            String originalMayaId = getOriginalMayaId ( callbackHandler, animationId, COLLADASaxFWL15::HASH_ELEMENT_ANIMATION );
            if ( !originalMayaId.empty () ) animationName = originalMayaId;
            animationName = generateUniqueDependNodeName ( animationName, true, true );

            // Get the maya file
            FILE* file = getDocumentImporter ()->getFile ();

            // Create the animation curve.
            MayaDM::AnimCurve* animCurve = 0;

            const COLLADAFW::PhysicalDimension& outPhysicalDimension = outPhysicalDimensions [outputIndex];
            switch ( outPhysicalDimension )
            {
            case COLLADAFW::PHYSICAL_DIMENSION_LENGTH:
                {
                    // We have to check for scale animations. They have to use an AnimCurveTU 
                    // (like dimension number) instead of an AnimCurveTL (like dimension length).
                    if ( !isScaleAnimation ( animationId ) )
                    {
                        animCurve = new MayaDM::AnimCurveTL ( file, animationName );
                        animCurve->setTangentType ( tangentType );
                        setKeyTimeValues ( animationCurve, (MayaDM::AnimCurveTL*)animCurve, outputIndex );
                    }
                    else
                    {
                        animCurve = new MayaDM::AnimCurveTU ( file, animationName );
                        animCurve->setTangentType ( tangentType );
                        setKeyTimeValues ( animationCurve, (MayaDM::AnimCurveTU*)animCurve, outputIndex );
                    }
                }
                break;
            case COLLADAFW::PHYSICAL_DIMENSION_ANGLE:
                {
                    animCurve = new MayaDM::AnimCurveTA ( file, animationName );
                    animCurve->setTangentType ( tangentType );
                    setKeyTimeValues ( animationCurve, (MayaDM::AnimCurveTA*)animCurve, outputIndex );
                }
                break;
            case COLLADAFW::PHYSICAL_DIMENSION_COLOR:
            case COLLADAFW::PHYSICAL_DIMENSION_NUMBER:
                {
                    animCurve = new MayaDM::AnimCurveTU ( file, animationName );
                    animCurve->setTangentType ( tangentType );
                    setKeyTimeValues ( animationCurve, (MayaDM::AnimCurveTU*)animCurve, outputIndex );
                }
                break;
            case COLLADAFW::PHYSICAL_DIMENSION_TIME:
                std::cerr << "Physical dimension not supported: PHYSICAL_DIMENSION_TIME" << std::endl;
                return; break;
            default:
                std::cerr << "Unknown physical dimension!" << std::endl;
                return; break;
            }

            // Add the original id attribute.
            String colladaId = animationCurve->getOriginalId ();
            if ( !colladaId.empty () )
            {
                MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_DATA_TYPE, ATTRIBUTE_TYPE_STRING );
                MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_STRING, colladaId );
            }
//             // TODO Add the attributes for all the extra tags.
//             setExtraData ( animationCurve->getExtraDataArray () );

            // Push the maya animation curve element in a list.
            const COLLADAFW::UniqueId& animationId = animationCurve->getUniqueId ();
            mMayaDMAnimationCurves [animationId].push_back ( animCurve );

            // True makes the in- and out-tangents move together. False makes them move separately.
            setKeyTangentLocks ( animationCurve, animCurve, false );

            // Set the in- and out-tangents
            if ( tangentType != TANGENT_TYPE_LINEAR && tangentType != TANGENT_TYPE_STEP )
            {
                setWeightedInTangents ( animationCurve, outPhysicalDimension, outputIndex, animCurve );
                setWeightedOutTangents ( animationCurve, outPhysicalDimension, outputIndex, animCurve );
            }
        }
    }

    //------------------------------
    const std::vector<MayaDM::AnimCurve*>* AnimationImporter::findMayaDMAnimCurves ( 
        const COLLADAFW::UniqueId& animationId )
    {
        const std::map<COLLADAFW::UniqueId, std::vector<MayaDM::AnimCurve*> >::iterator it = mMayaDMAnimationCurves.find ( animationId );
        if ( it != mMayaDMAnimationCurves.end () )
        {
            return &(it->second);
        }
        return 0;
    }

    //------------------------------
    void AnimationImporter::writeAnimationCurveByKeys (
        const COLLADAFW::AnimationCurve* animationCurve )
    {
        // The output can have different dimensions.
        const COLLADAFW::FloatOrDoubleArray& outputValuesArray = animationCurve->getOutputValues ();
        size_t outDimension = animationCurve->getOutDimension ();
        size_t numOutputValues = outputValuesArray.getValuesCount () / outDimension;

        const COLLADAFW::PhysicalDimensionArray& outPhysicalDimensions = animationCurve->getOutPhysicalDimensions ();
        size_t outDimension2 = outPhysicalDimensions.getCount ();

        size_t keyCount = animationCurve->getKeyCount ();
        if ( numOutputValues != keyCount  || outDimension != outDimension2 )
        {
            std::cerr << "Animation not valid!" << std::endl;
            return;
        }

        // The uniqueId of the element.
        const COLLADAFW::UniqueId& animationId = animationCurve->getUniqueId ();

        // Create a curve for every animated element.
        for ( size_t outputIndex=0; outputIndex<outDimension; ++outputIndex )
        {
            // Make the maya name unique and manage it in all necessary lists.
            String animationName = animationCurve->getName ();
            if ( animationName.empty () ) animationName = ANIMATION_NAME;
            animationName = DocumentImporter::frameworkNameToMayaName ( animationName );
            const ExtraDataCallbackHandler& callbackHandler = getDocumentImporter ()->getMayaIdCallbackHandler ();
            String originalMayaId = getOriginalMayaId ( callbackHandler, animationId, COLLADASaxFWL15::HASH_ELEMENT_ANIMATION );
            if ( !originalMayaId.empty () ) animationName = originalMayaId;
            animationName = generateUniqueDependNodeName ( animationName );

            // Create the animation curve.
            FILE* file = getDocumentImporter ()->getFile ();

            // Flag, if the values of the tangents should be normalized.
            bool normalizeTangents = true;

            // Create the animation curve.
            MayaDM::AnimCurve* animCurve = 0;

            const COLLADAFW::PhysicalDimension& outPhysicalDimension = outPhysicalDimensions [outputIndex];
            switch ( outPhysicalDimension )
            {
            case COLLADAFW::PHYSICAL_DIMENSION_LENGTH:
                {
                    animCurve = new MayaDM::AnimCurveTL ( file, animationName );
                    animCurve->setTangentType ( TANGENT_TYPE_FIXED );
                    setKeyTimeValues ( animationCurve, (MayaDM::AnimCurveTL*)animCurve, outputIndex );
                }
                break;
            case COLLADAFW::PHYSICAL_DIMENSION_ANGLE:
                {
                    animCurve = new MayaDM::AnimCurveTA ( file, animationName );
                    animCurve->setTangentType ( TANGENT_TYPE_FIXED );
                    setKeyTimeValues ( animationCurve, (MayaDM::AnimCurveTA*)animCurve, outputIndex );
                    normalizeTangents = false;
                }
                break;
            case COLLADAFW::PHYSICAL_DIMENSION_TIME:
                std::cerr << "Physical dimension not supported: PHYSICAL_DIMENSION_TIME" << std::endl;
                return; break;
            case COLLADAFW::PHYSICAL_DIMENSION_COLOR:
                std::cerr << "Physical dimension not supported: PHYSICAL_DIMENSION_COLOR" << std::endl;
                return; break;
            case COLLADAFW::PHYSICAL_DIMENSION_NUMBER:
                {
//                     animCurve = new MayaDM::AnimCurveTL ( file, animationName );
//                     animCurve->setTangentType ( TANGENT_TYPE_FIXED );
//                     setKeyTimeValues ( animationCurve, (MayaDM::AnimCurveTL*)animCurve, outputIndex );
                    std::cerr << "Physical dimension not supported: PHYSICAL_DIMENSION_NUMBER" << std::endl;
                }
                return; break;
            default:
                std::cerr << "Unknown physical dimension!" << std::endl;
                return; break;
            }

            // Add the original id attribute.
            String colladaId = animationCurve->getOriginalId ();
            if ( !colladaId.empty () )
            {
                MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_DATA_TYPE, ATTRIBUTE_TYPE_STRING );
                MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_STRING, colladaId );
            }
//             // TODO Add the attributes for all the extra tags.
//             setExtraData ( animationCurve->getExtraDataArray () );

            // Push the maya animation curve element in a list.
            const COLLADAFW::UniqueId& animationId = animationCurve->getUniqueId ();
            mMayaDMAnimationCurves [animationId].push_back ( animCurve );

            // Set key tangent in and out types
            setKeyTangentInTypes ( animationCurve, animCurve );
            setKeyTangentOutTypes ( animationCurve, animCurve );

            // True makes the in- and out-tangents move together. False makes them move separately.
            setKeyTangentLocks ( animationCurve, animCurve, false );
            
            // Set the in- and out-tangents
            setWeightedInTangents ( animationCurve, outPhysicalDimension, outputIndex, animCurve );
            setWeightedOutTangents ( animationCurve, outPhysicalDimension, outputIndex, animCurve );
        }
    }

    //------------------------------
    void AnimationImporter::setKeyTimeValues ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        MayaDM::AnimCurveTL* animCurveTL, 
        const size_t outputIndex )
    {
        // The input is always the time 
        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = animationCurve->getInputValues ();
        size_t numInputValues = inputValuesArray.getValuesCount ();

        // The output can have different dimensions.
        const COLLADAFW::FloatOrDoubleArray& outputValuesArray = animationCurve->getOutputValues ();
        size_t outDimension = animationCurve->getOutDimension ();
        size_t numOutputValues = outputValuesArray.getValuesCount () / outDimension;

        size_t keyCount = animationCurve->getKeyCount ();
        if ( numInputValues != numOutputValues || numInputValues != keyCount )
        {
            std::cerr << "AnimationImporter::setKeyTimeValues(): Invalid animation!" << std::endl;
            return;
        }

        // Start
        animCurveTL->startKeyTimeValue ( 0, keyCount-1 );
        MayaDM::AnimCurveTL::KeyTimeValue keyTimeValue;

        double inputValue = 0;
        double outputValue = 0;

        for ( size_t inputIndex=0; inputIndex<keyCount; ++inputIndex )
        {
            inputValue = getDoubleValue ( inputValuesArray, inputIndex );
            size_t currentOutputIndex = inputIndex*outDimension + outputIndex;
            outputValue = getDoubleValue ( outputValuesArray, currentOutputIndex );

            // Framerate: 24 frames per second...
            keyTimeValue.keyTime = inputValue * ANIM_FRAMERATE;
            keyTimeValue.keyValue = outputValue;
            animCurveTL->appendKeyTimeValue ( keyTimeValue );

            // Set the maya playback options (start and end time).
            mPlaybackOptions.setTimeValue ( inputValue * ANIM_FRAMERATE );
        }

        animCurveTL->endKeyTimeValue ();
    }

    //------------------------------
    void AnimationImporter::setKeyTimeValues ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        MayaDM::AnimCurveTU* animCurveTU, 
        const size_t outputIndex )
    {
        // The input is always the time 
        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = animationCurve->getInputValues ();
        size_t numInputValues = inputValuesArray.getValuesCount ();

        // The output can have different dimensions.
        const COLLADAFW::FloatOrDoubleArray& outputValuesArray = animationCurve->getOutputValues ();
        size_t outDimension = animationCurve->getOutDimension ();
        size_t numOutputValues = outputValuesArray.getValuesCount () / outDimension;

        size_t keyCount = animationCurve->getKeyCount ();
        if ( numInputValues != numOutputValues || numInputValues != keyCount )
        {
            std::cerr << "AnimationImporter::setKeyTimeValues(): Invalid animation!" << std::endl;
            return;
        }

        // Start
        animCurveTU->startKeyTimeValue ( 0, keyCount-1 );
        MayaDM::AnimCurveTU::KeyTimeValue keyTimeValue;

        double inputValue = 0;
        double outputValue = 0;

        for ( size_t inputIndex=0; inputIndex<keyCount; ++inputIndex )
        {
            inputValue = getDoubleValue ( inputValuesArray, inputIndex );
            size_t currentOutputIndex = inputIndex*outDimension + outputIndex;
            outputValue = getDoubleValue ( outputValuesArray, currentOutputIndex );

            // Framerate: 24 frames per second...
            keyTimeValue.keyTime = inputValue * ANIM_FRAMERATE;
            keyTimeValue.keyValue = outputValue;
            animCurveTU->appendKeyTimeValue ( keyTimeValue );

            // Set the maya playback options (start and end time).
            mPlaybackOptions.setTimeValue ( inputValue * ANIM_FRAMERATE );
        }

        animCurveTU->endKeyTimeValue ();
    }

    //------------------------------
    void AnimationImporter::setKeyTimeValues ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        MayaDM::AnimCurveTA* animCurveTA, 
        const size_t outputIndex )
    {
        // The input is always the time 
        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = animationCurve->getInputValues ();
        size_t numInputValues = inputValuesArray.getValuesCount ();

        // The output can have different dimensions.
        const COLLADAFW::FloatOrDoubleArray& outputValuesArray = animationCurve->getOutputValues ();
        size_t outDimension = animationCurve->getOutDimension ();
        size_t numOutputValues = outputValuesArray.getValuesCount () / outDimension;

        size_t keyCount = animationCurve->getKeyCount ();
        if ( numInputValues != numOutputValues || numInputValues != keyCount )
        {
            std::cerr << "AnimationImporter::setKeyTimeValues(): Invalid animation!" << std::endl;
            return;
        }

        // Start
        animCurveTA->startKeyTimeValue ( 0, keyCount-1 );
        MayaDM::AnimCurveTA::KeyTimeValue keyTimeValue;

        double inputValue = 0;
        double outputValue = 0;

        for ( size_t inputIndex=0; inputIndex<keyCount; ++inputIndex )
        {
            inputValue = getDoubleValue ( inputValuesArray, inputIndex );
            size_t currentOutputIndex = inputIndex*outDimension + outputIndex;
            outputValue = getDoubleValue ( outputValuesArray, currentOutputIndex );

            // Framerate: 24 frames per second...
            keyTimeValue.keyTime = inputValue * ANIM_FRAMERATE;
            keyTimeValue.keyValue = outputValue;
            animCurveTA->appendKeyTimeValue ( keyTimeValue );

            // Set the maya playback options (start and end time).
            mPlaybackOptions.setTimeValue ( inputValue * ANIM_FRAMERATE );
        }

        animCurveTA->endKeyTimeValue ();
    }

    //------------------------------
    void AnimationImporter::setWeightedInTangents ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        const COLLADAFW::PhysicalDimension& outPhysicalDimension, 
        const size_t outputIndex, 
        MayaDM::AnimCurve* animCurve )
    {
        setWeightedInTangentXValues ( animationCurve, outPhysicalDimension, outputIndex, animCurve );
        setWeightedInTangentYValues ( animationCurve, outPhysicalDimension, outputIndex, animCurve );
    }

    //------------------------------
    void AnimationImporter::setWeightedInTangentXValues ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        const COLLADAFW::PhysicalDimension& outPhysicalDimension, 
        const size_t outputIndex, 
        MayaDM::AnimCurve* animCurve )
    {
        // Check the interpolation type
        bool mixedInterpolation = false;
        COLLADAFW::AnimationCurve::InterpolationType interpolationType = animationCurve->getInterpolationType ();
        if ( interpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR ) return;
        if ( interpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_MIXED ) mixedInterpolation = true;

        // The time input and the output.
        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = animationCurve->getInputValues ();

        // The in-tangent positions
        const size_t keyCount = animationCurve->getKeyCount ();
        const COLLADAFW::FloatOrDoubleArray& inTangentValuesArray = animationCurve->getInTangentValues ();
        size_t numTangentValues = inTangentValuesArray.getValuesCount ();
        if ( numTangentValues == 0 ) return;

        const size_t outDimension = animationCurve->getOutDimension ();

        // Write the in-tangent x values.
        animCurve->startKeyTanInX ( 0, keyCount-1 );
        for ( size_t keyPosition=0; keyPosition<keyCount; ++keyPosition )
        {
            if ( mixedInterpolation )
                interpolationType = animationCurve->getInterpolationTypes () [keyPosition];

            switch ( interpolationType )
            {
            case COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER:
                {
                    double inputValue = getDoubleValue ( inputValuesArray, keyPosition );
                    size_t indexX = keyPosition*(outDimension*2) + (outputIndex*2);
                    double inTangentValueX = getDoubleValue ( inTangentValuesArray, indexX );
                    double resultX = 3 * ( inputValue - inTangentValueX );
                    animCurve->appendKeyTanInX ( resultX );
                }
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR:
                {
                    double inputValue = getDoubleValue ( inputValuesArray, keyPosition );
                    double lastInputValue = 0;
                    if ( keyPosition > 0 )
                        lastInputValue = getDoubleValue ( inputValuesArray, keyPosition-1 );
                    double resultX = inputValue - lastInputValue;
                    animCurve->appendKeyTanInX ( resultX );
                }
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_STEP:
                {
                    animCurve->appendKeyTanInX ( 0 );
                }
                break;
            default:
                {
                    std::cerr << "Interpolation type not supported!" << std::endl;
                    animCurve->appendKeyTanInX ( 0 );
                }
                break;
            }
        }
        animCurve->endKeyTanInX ();
    }

    //------------------------------
    void AnimationImporter::setWeightedInTangentYValues ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        const COLLADAFW::PhysicalDimension& outPhysicalDimension, 
        const size_t outputIndex, 
        MayaDM::AnimCurve* animCurve )
    {
        // Check the interpolation type
        bool mixedInterpolation = false;
        COLLADAFW::AnimationCurve::InterpolationType interpolationType = animationCurve->getInterpolationType ();
        if ( interpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR ) return;
        if ( interpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_MIXED ) mixedInterpolation = true;

        // The time input values and the output values.
        const COLLADAFW::FloatOrDoubleArray& outputValuesArray = animationCurve->getOutputValues ();

        // The in-tangent positions
        const size_t keyCount = animationCurve->getKeyCount ();
        const COLLADAFW::FloatOrDoubleArray& inTangentValuesArray = animationCurve->getInTangentValues ();
        size_t numTangentValues = inTangentValuesArray.getValuesCount ();
        if ( numTangentValues == 0 ) return;

        const size_t outDimension = animationCurve->getOutDimension ();

        // Write the in-tangent y values
        animCurve->startKeyTanInY ( 0, keyCount-1 );
        for ( size_t keyPosition=0; keyPosition<keyCount; ++keyPosition )
        {
            if ( mixedInterpolation )
                interpolationType = animationCurve->getInterpolationTypes () [keyPosition];

            switch ( interpolationType )
            {
            case COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER:
                {
                    size_t outputValueIndex = keyPosition*outDimension + outputIndex;
                    double outputValue = getDoubleValue ( outputValuesArray, outputValueIndex );
                    size_t indexY = keyPosition*(outDimension*2) + (outputIndex*2) + 1;
                    double inTangentValueY = getDoubleValue ( inTangentValuesArray, indexY );
                    double resultY = 3 * ( outputValue - inTangentValueY );
                    if ( outPhysicalDimension == COLLADAFW::PHYSICAL_DIMENSION_ANGLE )
                        resultY = COLLADABU::Math::Utils::degToRad ( resultY );
                    animCurve->appendKeyTanInY ( resultY );
                }
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR:
                {
                    size_t outputValueIndex = keyPosition*outDimension + outputIndex;
                    double outputValue = getDoubleValue ( outputValuesArray, outputValueIndex );
                    double lastOutputValue = 0;
                    if ( keyPosition > 0 )
                        lastOutputValue = getDoubleValue ( outputValuesArray, keyPosition-1 );
                    double resultY = outputValue - lastOutputValue;
                    if ( outPhysicalDimension == COLLADAFW::PHYSICAL_DIMENSION_ANGLE )
                        resultY = COLLADABU::Math::Utils::degToRad ( resultY );
                    animCurve->appendKeyTanInX ( resultY );
                }
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_STEP:
                {
                    animCurve->appendKeyTanInX ( 0 );
                }
                break;
            default:
                {
                    std::cerr << "Interpolation type not supported!" << std::endl;
                    animCurve->appendKeyTanInX ( 0 );
                }
                break;
            }
        }
        animCurve->endKeyTanInY ();
    }

    //------------------------------
    void AnimationImporter::setWeightedOutTangents ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        const COLLADAFW::PhysicalDimension& outPhysicalDimension, 
        const size_t outputIndex, 
        MayaDM::AnimCurve* animCurve )
    {
        setWeightedOutTangentXValues ( animationCurve, outPhysicalDimension, outputIndex, animCurve );
        setWeightedOutTangentYValues ( animationCurve, outPhysicalDimension, outputIndex, animCurve );
    }

    //------------------------------
    void AnimationImporter::setWeightedOutTangentXValues ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        const COLLADAFW::PhysicalDimension& outPhysicalDimension, 
        const size_t outputIndex, 
        MayaDM::AnimCurve* animCurve )
    {
        // The time input values and the output values.
        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = animationCurve->getInputValues ();
 
        // The out-tangent positions
        const size_t keyCount = animationCurve->getKeyCount ();
        const COLLADAFW::FloatOrDoubleArray& outTangentValuesArray = animationCurve->getOutTangentValues ();
        size_t numTangentValues = outTangentValuesArray.getValuesCount ();
        if ( numTangentValues == 0 ) return;

        // Check the interpolation type
        bool mixedInterpolation = false;
        COLLADAFW::AnimationCurve::InterpolationType interpolationType = animationCurve->getInterpolationType ();
        const COLLADAFW::AnimationCurve::InterpolationTypeArray& interpolationTypeArray = animationCurve->getInterpolationTypes ();
        if ( interpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR ) return;
        if ( interpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_MIXED ) mixedInterpolation = true;

        const size_t outDimension = animationCurve->getOutDimension ();

        // Write the in-tangent x values.
        animCurve->startKeyTanOutX ( 0, keyCount-1 );
        for ( size_t keyPosition=0; keyPosition<keyCount; ++keyPosition )
        {
            if ( mixedInterpolation )
                interpolationType = interpolationTypeArray [keyPosition];

            switch ( interpolationType )
            {
            case COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER:
                {
                    double inputValue = getDoubleValue ( inputValuesArray, keyPosition );
                    size_t indexX = keyPosition*(outDimension*2) + (outputIndex*2);
                    double outTangentValueX = getDoubleValue ( outTangentValuesArray, indexX );
                    double resultX = -3 * ( inputValue - outTangentValueX );
                    animCurve->appendKeyTanOutX ( resultX );
                }
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR:
                {
                    double inputValue = getDoubleValue ( inputValuesArray, keyPosition );
                    double nextInputValue = 0;
                    if ( keyPosition < keyCount-1 )
                    {
                        nextInputValue = getDoubleValue ( inputValuesArray, keyPosition+1 );
                        double resultX = nextInputValue - inputValue;
                        animCurve->appendKeyTanInX ( resultX );
                    }
                    else animCurve->appendKeyTanInX ( 1 );
                }
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_STEP:
                {
                    animCurve->appendKeyTanInX ( 0 );
                }
                break;
            default:
                {
                    std::cerr << "Interpolation type not supported!" << std::endl;
                    animCurve->appendKeyTanInX ( 0 );
                }
                break;
            }
        }
        animCurve->endKeyTanOutX ();
    }

    //------------------------------
    void AnimationImporter::setWeightedOutTangentYValues ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        const COLLADAFW::PhysicalDimension& outPhysicalDimension, 
        const size_t outputIndex, 
        MayaDM::AnimCurve* animCurve )
    {
        // The time input values and the output values.
        const COLLADAFW::FloatOrDoubleArray& outputValuesArray = animationCurve->getOutputValues ();

        // The out-tangent positions
        const size_t keyCount = animationCurve->getKeyCount ();
        const COLLADAFW::FloatOrDoubleArray& outTangentValuesArray = animationCurve->getOutTangentValues ();
        size_t numTangentValues = outTangentValuesArray.getValuesCount ();
        if ( numTangentValues == 0 ) return;

        // Check the interpolation type
        bool mixedInterpolation = false;
        COLLADAFW::AnimationCurve::InterpolationType interpolationType = animationCurve->getInterpolationType ();
        const COLLADAFW::AnimationCurve::InterpolationTypeArray& interpolationTypeArray = animationCurve->getInterpolationTypes ();
        if ( interpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR ) return;
        if ( interpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_MIXED ) mixedInterpolation = true;

        const size_t outDimension = animationCurve->getOutDimension ();

        // Write the in-tangent y values 
        animCurve->startKeyTanOutY ( 0, keyCount-1 );
        for ( size_t keyPosition=0; keyPosition<keyCount; ++keyPosition )
        {
            if ( mixedInterpolation )
                interpolationType = interpolationTypeArray [keyPosition];

            switch ( interpolationType )
            {
            case COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER:
                {
                    size_t outputValueIndex = keyPosition*outDimension + outputIndex;
                    double outputValue = getDoubleValue ( outputValuesArray, outputValueIndex );
                    size_t indexY = keyPosition*(outDimension*2) + (outputIndex*2) + 1;
                    double outTangentValueY = getDoubleValue ( outTangentValuesArray, indexY );
                    double resultY = -3 * ( outputValue - outTangentValueY );
                    if ( outPhysicalDimension == COLLADAFW::PHYSICAL_DIMENSION_ANGLE )
                        resultY = COLLADABU::Math::Utils::degToRad ( resultY );
                    animCurve->appendKeyTanOutY ( resultY );
                }
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR:
                {
                    size_t outputValueIndex = keyPosition*outDimension + outputIndex;
                    double outputValue = getDoubleValue ( outputValuesArray, outputValueIndex );
                    double nextOutputValue = 0;
                    if ( keyPosition < keyCount-1 )
                    {
                        nextOutputValue = getDoubleValue ( outputValuesArray, keyPosition+1 );
                        double resultY = nextOutputValue - outputValue;
                        if ( outPhysicalDimension == COLLADAFW::PHYSICAL_DIMENSION_ANGLE )
                            resultY = COLLADABU::Math::Utils::degToRad ( resultY );
                        animCurve->appendKeyTanInX ( resultY );
                    }
                    else animCurve->appendKeyTanInX ( 0 );
                }
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_STEP:
                {
                    animCurve->appendKeyTanInX ( 0 );
                }
                break;
            default:
                {
                    std::cerr << "Interpolation type not supported!" << std::endl;
                    animCurve->appendKeyTanInX ( 0 );
                }
                break;
            }
        }
        animCurve->endKeyTanOutY ();
    }

    //------------------------------
    void AnimationImporter::setNonWeightedInTangents ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        MayaDM::AnimCurve* animCurve, 
        const size_t outputIndex, 
        const bool normalize /*= true*/ )
    {
        // The input is always the time 
        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = animationCurve->getInputValues ();

        // The output array.
        const COLLADAFW::FloatOrDoubleArray& outputValuesArray = animationCurve->getOutputValues ();

        // The in-tangent positions
        const size_t keyCount = animationCurve->getKeyCount ();
        const COLLADAFW::FloatOrDoubleArray& inTangentValuesArray = animationCurve->getInTangentValues ();
        size_t numTangentValues = inTangentValuesArray.getValuesCount ();
        if ( numTangentValues == 0 ) return;
        
        const size_t outDimension = animationCurve->getOutDimension ();

        // Write the in-tangent x values.
        animCurve->startKeyTanInX ( 0, keyCount-1 );
        for ( size_t keyPosition=0; keyPosition<keyCount; ++keyPosition )
        {
            // Get the delta x
            double inputValue = getDoubleValue ( inputValuesArray, keyPosition );
            size_t indexX = keyPosition*outDimension*2 + outputIndex;
            double inTangentValueX = getDoubleValue ( inTangentValuesArray, indexX );
            double deltaX = inputValue - inTangentValueX;
            double normedDeltaX = 0;
            if ( deltaX != 0 )
            {
                // Get the delta x
                size_t outputValueIndex = keyPosition*outDimension + outputIndex;
                double outputValue = getDoubleValue ( outputValuesArray, outputValueIndex );
                size_t indexY = keyPosition*outDimension*2 + outputIndex + 1;
                double inTangentValueY = getDoubleValue ( inTangentValuesArray, indexY );
                double deltaY = outputValue - inTangentValueY;
                if ( normalize && deltaY != 0 )
                {
                    // Norm the delta x to a delta y of 1
                    double m = deltaY / deltaX;
                    normedDeltaX = 1 / m;
                    if ( normedDeltaX < 0 ) normedDeltaX *= -1;
                }
                else normedDeltaX = deltaX;
            }

            // Set the normed x delta value.
            animCurve->appendKeyTanInX ( normedDeltaX );
        }
        animCurve->endKeyTanInX ();

        // Write the in-tangent y values (just the normed values of 1)
        animCurve->startKeyTanInY ( 0, keyCount-1 );
        for ( size_t keyPosition=0; keyPosition<keyCount; ++keyPosition )
        {
            // Get the delta y
            size_t outputValueIndex = keyPosition*outDimension + outputIndex;
            double outputValue = getDoubleValue ( outputValuesArray, outputValueIndex );
            size_t indexY = keyPosition*outDimension*2 + outputIndex + 1;
            double inTangentValueY = getDoubleValue ( inTangentValuesArray, indexY );
            double deltaY = outputValue - inTangentValueY;
            double normedDeltaY = 0;
            if ( normalize && deltaY != 0 )
            {
                // Set the key tangent in y value.
                normedDeltaY = -1;
                if ( deltaY > 0 ) normedDeltaY = 1;
            }
            else normedDeltaY = deltaY;

            // Set the normed y delta value.
            animCurve->appendKeyTanInY ( normedDeltaY );
        }
        animCurve->endKeyTanInY ();
    }

    //------------------------------
    void AnimationImporter::setNonWeightedOutTangents ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        MayaDM::AnimCurve* animCurve, 
        const size_t outputIndex, 
        const bool normalize /*= true*/ )
    {
        // The input is always the time 
        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = animationCurve->getInputValues ();

        // The output array.
        const COLLADAFW::FloatOrDoubleArray& outputValuesArray = animationCurve->getOutputValues ();

        // The out-tangent positions
        const size_t keyCount = animationCurve->getKeyCount ();
        const COLLADAFW::FloatOrDoubleArray& outTangentValuesArray = animationCurve->getOutTangentValues ();
        size_t numTangentValues = outTangentValuesArray.getValuesCount ();
        if ( numTangentValues == 0 ) return;

        const size_t outDimension = animationCurve->getOutDimension ();

        // Write the in-tangent x values.
        animCurve->startKeyTanOutX ( 0, keyCount-1 );
        for ( size_t keyPosition=0; keyPosition<keyCount; ++keyPosition )
        {
            // Get the delta x
            double inputValue = getDoubleValue ( inputValuesArray, keyPosition );
            size_t indexX = keyPosition*outDimension*2 + outputIndex;
            double outTangentValueX = getDoubleValue ( outTangentValuesArray, indexX );
            double deltaX = inputValue - outTangentValueX;
            double normedDeltaX = 0;
            if ( deltaX != 0 )
            {
                // Get the delta y
                size_t outputValueIndex = keyPosition*outDimension + outputIndex;
                double outputValue = getDoubleValue ( outputValuesArray, outputValueIndex );
                size_t indexY = keyPosition*outDimension*2 + outputIndex + 1;
                double outTangentValueY = getDoubleValue ( outTangentValuesArray, indexY );
                double deltaY = outputValue - outTangentValueY;
                if ( normalize && deltaY != 0 )
                {
                    // Norm the delta x to a delta y of 1
                    double m = deltaY / deltaX;
                    normedDeltaX = 1 / m;
                    if ( normedDeltaX < 0 ) normedDeltaX *= -1;
                }
                else normedDeltaX = deltaX * -1;
            }

            // Set the key tangent in x value.
            animCurve->appendKeyTanOutX ( normedDeltaX );
        }
        animCurve->endKeyTanOutX ();

        // Write the in-tangent y values (just the normed values of 1)
        animCurve->startKeyTanOutY ( 0, keyCount-1 );
        for ( size_t keyPosition=0; keyPosition<keyCount; ++keyPosition )
        {
            // Get the delta y
            size_t outputValueIndex = keyPosition*outDimension + outputIndex;
            double outputValue = getDoubleValue ( outputValuesArray, outputValueIndex );
            size_t indexY = keyPosition*outDimension*2 + outputIndex + 1;
            double outTangentValueY = getDoubleValue ( outTangentValuesArray, indexY );
            double deltaY = outputValue - outTangentValueY;
            double normedDeltaY = 0;
            if ( normalize && deltaY != 0 )
            {
                // Set the key tangent out y value.
                normedDeltaY = 1;
                if ( deltaY > 0 ) normedDeltaY = -1;
            }
            else normedDeltaY = deltaY;

            // Set the key tangent in y value.
            animCurve->appendKeyTanOutY ( normedDeltaY );
        }
        animCurve->endKeyTanOutY ();
    }

    //------------------------------
    void AnimationImporter::setKeyTangentInTypes ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        MayaDM::AnimCurve* animCurve )
    {
        TangentType keyTangentInType;

        // The interpolation types
        const COLLADAFW::AnimationCurve::InterpolationTypeArray& interpolationTypes = animationCurve->getInterpolationTypes ();
        size_t numInterpolationTypes = interpolationTypes.getCount ();

        size_t keyCount = animationCurve->getKeyCount ();
        if ( numInterpolationTypes != keyCount )
        {
            std::cerr << "AnimationImporter::setKeyTangentInType(): Invalid animation!" << std::endl;
            return;
        }

        animCurve->startKeyTanInType ( 0, keyCount-1 );
        for ( size_t i=0; i<keyCount; ++i )
        {
            const COLLADAFW::AnimationCurve::InterpolationType& interpolationType = interpolationTypes [i];
            switch ( interpolationType )
            {
            case COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER:
                keyTangentInType = TANGENT_TYPE_FIXED;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_BSPLINE:
                keyTangentInType = TANGENT_TYPE_FIXED;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_CARDINAL:
                keyTangentInType = TANGENT_TYPE_FIXED;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_HERMITE:
                keyTangentInType = TANGENT_TYPE_FIXED;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR:
                keyTangentInType = TANGENT_TYPE_LINEAR;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_STEP:
                keyTangentInType = TANGENT_TYPE_STEP;
                break;
            default:
                std::cerr << "Unknown interpolation type in mixed interpolations!" << std::endl;
                keyTangentInType = TANGENT_TYPE_DEFAULT;
            }
            animCurve->appendKeyTanInType ( keyTangentInType );
        }
        animCurve->endKeyTanInType ();
    }

    //------------------------------
    void AnimationImporter::setKeyTangentOutTypes ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        MayaDM::AnimCurve* animCurve )
    {
        TangentType keyTangentOutType;

        // The interpolation types
        const COLLADAFW::AnimationCurve::InterpolationTypeArray& interpolationTypes = animationCurve->getInterpolationTypes ();
        size_t numInterpolationTypes = interpolationTypes.getCount ();

        size_t keyCount = animationCurve->getKeyCount ();
        if ( numInterpolationTypes != keyCount )
        {
            std::cerr << "AnimationImporter::setKeyTangentOutType(): Invalid animation!" << std::endl;
            return;
        }

        animCurve->startKeyTanOutType ( 0, keyCount-1 );
        for ( size_t i=0; i<keyCount; ++i )
        {
            const COLLADAFW::AnimationCurve::InterpolationType& interpolationType = interpolationTypes [i];
            switch ( interpolationType )
            {
            case COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER:
                keyTangentOutType = TANGENT_TYPE_FIXED;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_BSPLINE:
                keyTangentOutType = TANGENT_TYPE_FIXED;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_CARDINAL:
                keyTangentOutType = TANGENT_TYPE_FIXED;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_HERMITE:
                keyTangentOutType = TANGENT_TYPE_FIXED;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR:
                keyTangentOutType = TANGENT_TYPE_LINEAR;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_STEP:
                keyTangentOutType = TANGENT_TYPE_STEP;
                break;
            default:
                std::cerr << "Unknown interpolation type in mixed interpolations!" << std::endl;
                keyTangentOutType = TANGENT_TYPE_DEFAULT;
            }
            animCurve->appendKeyTanOutType ( keyTangentOutType );
        }
        animCurve->endKeyTanOutType ();
    }

    //------------------------------
    void AnimationImporter::setKeyTangentLocks ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        MayaDM::AnimCurve* animCurve,
        const bool keyTanLocked )
    {
        if ( !keyTanLocked )
        {
            size_t keyCount = animationCurve->getKeyCount ();
            animCurve->startKeyTanLocked ( 0, keyCount-1 );
            for ( size_t i=0; i<keyCount; ++i )
            {
                animCurve->appendKeyTanLocked ( keyTanLocked );
            }
            animCurve->endKeyTanLocked ();
        }
    }

    //------------------------------
    void AnimationImporter::importPlaybackOptions ()
    {
        // Get the minimum and the maximum time values of the animations to get the start 
        // time and the end time of the animation. This times we have to set as the 
        // "playbackOptions" in the "sceneConfigurationScriptNode".

        // Get the maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // createNode script -n "sceneConfigurationScriptNode";
        // setAttr ".b" -type "string" "playbackOptions -min 1 -max 50 -ast 1 -aet 50 ";
        // setAttr ".st" 6;
        if ( mPlaybackOptions.getMaxEndTime () > 0 )
        {
            MayaDM::Script scriptNode ( file, SCRIPT_NODE_SCENE_CONFIG );
            std::ostringstream scriptValue;
            scriptValue << "playbackOptions -min " << mPlaybackOptions.getMinStartTime () 
                << " -max " << mPlaybackOptions.getMaxEndTime () << " -ast " 
                << mPlaybackOptions.getMinStartTime () << " -aet " << mPlaybackOptions.getMaxEndTime ();

            scriptNode.setBefore ( scriptValue.str () );
            scriptNode.setScriptType ( 2 );
        }
    }

    //------------------------------
    const bool AnimationImporter::findAnimation ( const COLLADAFW::UniqueId& animationId )
    {
        UniqueIdVec::const_iterator it = mAnimationIds.begin ();
        while ( it != mAnimationIds.end () )
        {
            const COLLADAFW::UniqueId& uniqueId = *it;
            if ( uniqueId == animationId ) return true;

            ++it;
        }
        return false;
    }

    //------------------------------
    const bool AnimationImporter::findAnimationList ( const COLLADAFW::UniqueId& animationListId )
    {
        UniqueIdVec::const_iterator it = mAnimationListIds.begin ();
        while ( it != mAnimationListIds.end () )
        {
            const COLLADAFW::UniqueId& uniqueId = *it;
            if ( uniqueId == animationListId ) return true;

            ++it;
        }
        return false;
    }

    //------------------------------
    void AnimationImporter::detectScaleAnimations ( const COLLADAFW::AnimationList* animationList )
    {
        // Get the id of the current animation list.
        const COLLADAFW::UniqueId& animationListId = animationList->getUniqueId ();

        // Get the node, which use this animation list.
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        const TransformAnimation* transformAnimation = visualSceneImporter->findTransformAnimation ( animationListId );
        if ( !transformAnimation ) return;

        const COLLADAFW::Transformation* transformation = transformAnimation->getTransformation ();
        COLLADAFW::Transformation::TransformationType transformType = transformation->getTransformationType ();

        // Check if it is a scale animation.
        switch ( transformType )
        {
        case COLLADAFW::Transformation::SCALE:
            {
                // Get the animation bindings.
                const COLLADAFW::AnimationList::AnimationBindings& animationBindings = animationList->getAnimationBindings ();

                // Get the animation curves of the current animated element.
                size_t numAnimationBindings = animationBindings.getCount ();
                for ( size_t i=0; i<numAnimationBindings; ++i )
                {
                    // Get the animation curve element of the current animation id.
                    const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings [i]; 
                    const COLLADAFW::UniqueId& animationId = animationBinding.animation;

                    // Store the scale animation id in a list.
                    mScaleAnimations.push_back ( animationId );
                }
            }
            break;
        default:
            break;
        }
    }

    //------------------------------
    const bool AnimationImporter::isScaleAnimation ( const COLLADAFW::UniqueId& animationId )
    {
        UniqueIdVec::const_iterator it = mScaleAnimations.begin ();
        while ( it != mScaleAnimations.end () )
        {
            if ( animationId == *it ) return true;
            ++it;
        }
        return false;
    }

    //------------------------------
    void AnimationImporter::writeConnections ( const COLLADAFW::AnimationList* animationList )
    {
        // Get the id of the current animation list.
        const COLLADAFW::UniqueId& animationListId = animationList->getUniqueId ();
        if ( findAnimationList ( animationListId ) ) return;
        mAnimationListIds.push_back ( animationListId );

        // Get the animation bindings.
        const COLLADAFW::AnimationList::AnimationBindings& animationBindings = animationList->getAnimationBindings ();

        // Write the transformation animation connections.
        connectTransforms ( animationListId, animationBindings );

        // Write the effect animation connections.
        connectEffects ( animationListId, animationBindings );

        // Write the morph controller source connections.
        connectMorphControllers ( animationListId, animationBindings );
    }

    //------------------------------
    void AnimationImporter::connectEffects ( 
        const COLLADAFW::UniqueId& animationListId, 
        const COLLADAFW::AnimationList::AnimationBindings& animationBindings )
    {
        // Get the maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the node, which use this animation list.
        EffectImporter* effectImporter = getDocumentImporter ()->getEffectImporter ();
        const EffectAnimation* effectAnimation = effectImporter->findEffectAnimation ( animationListId );
        if ( !effectAnimation ) return;

        // Get the maya node object for the id.
        const COLLADAFW::UniqueId& effectId = effectAnimation->getAnimationSourceId ();
        const MayaEffectList* mayaEffectList = effectImporter->findMayaEffects ( effectId );
        if ( mayaEffectList != 0 )
        {
            for ( size_t effectIndex=0; effectIndex<mayaEffectList->size (); ++effectIndex )
            {
                const MayaDM::Lambert* lambertNode = (*mayaEffectList) [effectIndex];

                // Get the animated value type
                const EffectAnimation::AnimatedValueType& animatedValueType = effectAnimation->getAnimatedValueType ();
                switch ( animatedValueType )
                {
                case EffectAnimation::COLOR_OR_TEXTURE_AMBIENT:
                case EffectAnimation::COLOR_OR_TEXTURE_DIFFUSE:
                case EffectAnimation::COLOR_OR_TEXTURE_TRANSPARENCY:
                case EffectAnimation::COLOR_OR_TEXTURE_EMISSION:
                case EffectAnimation::COLOR_OR_TEXTURE_REFLECTED:
                case EffectAnimation::COLOR_OR_TEXTURE_SPECULAR:
                case EffectAnimation::COLOR_OR_TEXTURE_STANDARD:
                    {
                        // Get the animation curves of the current animated element.
                        size_t numAnimationBindings = animationBindings.getCount ();
                        for ( size_t i=0; i<numAnimationBindings; ++i )
                        {
                            // Get the animation curve element of the current animation id.
                            const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings [i]; 
                            const COLLADAFW::UniqueId& animationId = animationBinding.animation;
                            const std::vector<MayaDM::AnimCurve*>* animationCurves = findMayaDMAnimCurves ( animationId );
                            if ( animationCurves == 0 ) continue;

                            // Connect all animation curves of the current animation.
                            size_t animationCurveCount = animationCurves->size ();
                            for ( size_t curveIndex=0; curveIndex<animationCurveCount; ++curveIndex )
                            {
                                const MayaDM::AnimCurve* animCurve = (*animationCurves) [curveIndex];
                                MayaDM::AnimCurveTL* animCurveTL = (MayaDM::AnimCurveTL*) animCurve;

                                // Connect the animation curve and the current transform node.
                                // connectAttr "lambert2_colorB.o" "lambert2.cb";
                                const COLLADAFW::AnimationList::AnimationClass& animationClass = animationBinding.animationClass;
                                switch ( animationClass )
                                {
                                case COLLADAFW::AnimationList::COLOR_R:
                                    connectAttr ( file, animCurveTL->getOutput (),lambertNode->getColorR () );
                                    break;
                                case COLLADAFW::AnimationList::COLOR_G:
                                    connectAttr ( file, animCurveTL->getOutput (),lambertNode->getColorG () );
                                    break;
                                case COLLADAFW::AnimationList::COLOR_B:
                                    connectAttr ( file, animCurveTL->getOutput (),lambertNode->getColorB () );
                                    break;
                                case COLLADAFW::AnimationList::COLOR_A:
                                    std::cerr << "Animation of for animation class \"COLOR_A\" not implemented!" << std::endl;
                                    //connectAttr ( file, animCurveTL->getOutput (),lambertNode->getColorA () );
                                    break;
                                case COLLADAFW::AnimationList::COLOR_RGB:
                                    if ( animationCurveCount == 1 )
                                    {
                                        connectAttr ( file, animCurveTL->getOutput (),lambertNode->getColor () );
                                    }
                                    else
                                    {
                                        switch ( curveIndex )
                                        {
                                        case 0:
                                            connectAttr ( file, animCurveTL->getOutput (),lambertNode->getColorR () );
                                            break;
                                        case 1:
                                            connectAttr ( file, animCurveTL->getOutput (),lambertNode->getColorG () );
                                            break;
                                        case 2:
                                            connectAttr ( file, animCurveTL->getOutput (),lambertNode->getColorB () );
                                            break;
                                        default:
                                            std::cerr << "Too much animation curves for animation class \"COLOR_RGB\"!" << std::endl;
                                        }
                                    }
                                    break;
                                case COLLADAFW::AnimationList::COLOR_RGBA:
                                    if ( animationCurveCount == 1 )
                                    {
                                        connectAttr ( file, animCurveTL->getOutput (),lambertNode->getColor () );
                                    }
                                    else
                                    {
                                        switch ( curveIndex )
                                        {
                                        case 0:
                                            connectAttr ( file, animCurveTL->getOutput (),lambertNode->getColorR () );
                                            break;
                                        case 1:
                                            connectAttr ( file, animCurveTL->getOutput (),lambertNode->getColorG () );
                                            break;
                                        case 2:
                                            connectAttr ( file, animCurveTL->getOutput (),lambertNode->getColorB () );
                                            break;
                                        case 3:
                                            std::cerr << "Can't connect the animation of alpha values!" << std::endl;
                                            break;
                                        default:
                                            std::cerr << "Too much animation curves for animation class \"COLOR_RGBA\"!" << std::endl;
                                        }
                                    }
                                    break;
                                default:
                                    std::cerr << "Animation class for effect type \"COLOR_OR_TEXTURE_STANDARD_COLOR\" not implemented!" << std::endl;
                                    break;
                                }
                            }
                        }
                    }
                    break;
                case EffectAnimation::FLOAT_OR_PARAM_COSINE_POWER:
                case EffectAnimation::FLOAT_OR_PARAM_ECCENTRICITY:
                case EffectAnimation::FLOAT_OR_PARAM_REFLECTIVITY:
                case EffectAnimation::FLOAT_OR_PARAM_REFRACTIVE_INDEX:
                    {
                        // Get the animation curves of the current animated element.
                        size_t numAnimationBindings = animationBindings.getCount ();
                        for ( size_t i=0; i<numAnimationBindings; ++i )
                        {
                            // Get the animation curve element of the current animation id.
                            const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings [i]; 
                            const COLLADAFW::UniqueId& animationId = animationBinding.animation;
                            const std::vector<MayaDM::AnimCurve*>* animationCurves = findMayaDMAnimCurves ( animationId );
                            if ( animationCurves == 0 ) continue;

                            // Connect all animation curves of the current animation.
                            size_t animationCurveCount = animationCurves->size ();
                            for ( size_t curveIndex=0; curveIndex<animationCurveCount; ++curveIndex )
                            {
                                const MayaDM::AnimCurve* animCurve = (*animationCurves) [curveIndex];
                                MayaDM::AnimCurveTL* animCurveTU = (MayaDM::AnimCurveTL*) animCurve;

                                // Connect the animation curve and the current transform node.
                                // connectAttr "lambert2_colorB.o" "lambert2.cb";
                                const COLLADAFW::AnimationList::AnimationClass& animationClass = animationBinding.animationClass;
                                switch ( animationClass )
                                {
                                case COLLADAFW::AnimationList::FLOAT:
                                    switch ( animatedValueType )
                                    {
                                    case EffectAnimation::FLOAT_OR_PARAM_COSINE_POWER:
                                        connectAttr ( file, animCurveTU->getOutput (),((MayaDM::Phong*)lambertNode)->getCosinePower () );
                                        break;
                                    case EffectAnimation::FLOAT_OR_PARAM_ECCENTRICITY:
                                        connectAttr ( file, animCurveTU->getOutput (),((MayaDM::Blinn*)lambertNode)->getEccentricity () );
                                        break;
                                    case EffectAnimation::FLOAT_OR_PARAM_REFLECTIVITY:
                                        connectAttr ( file, animCurveTU->getOutput (),((MayaDM::Reflect*)lambertNode)->getReflectivity () );
                                        break;
                                    case EffectAnimation::FLOAT_OR_PARAM_REFRACTIVE_INDEX:
                                        connectAttr ( file, animCurveTU->getOutput (),lambertNode->getRefractiveIndex () );
                                        break;
                                    default:
                                        std::cerr << "Animation class for effect type \"FLOAT\" not implemented!" << std::endl;
                                        break;
                                    }
                                    break;
                                default:
                                    std::cerr << "Animation class for effect type \"FLOAT_OR_PARAM_...\" not implemented!" << std::endl;
                                    break;
                                }
                            }
                        }
                    }
                    break;
                default:
                    std::cerr << "Animation on effect not supported!" << std::endl;
                    break;
                }
            }
        }
    }

    //------------------------------
    void AnimationImporter::connectMorphControllers ( 
        const COLLADAFW::UniqueId& animationListId, 
        const COLLADAFW::AnimationList::AnimationBindings& animationBindings )
    {
        // Get the maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the node, which use this animation list.
        ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();
        const MorphAnimation* morphAnimation = controllerImporter->findMorphAnimation ( animationListId );
        if ( !morphAnimation ) return;

        // connectAttr "animCurveTU1.output" "geom_QuadPatch01_morph1.weight[0]";
        MayaDM::BlendShape blendShapeTarget = morphAnimation->getBlendShapeTarget ();

        // Get the animation curves of the current animated element.
        size_t numAnimationBindings = animationBindings.getCount ();
        for ( size_t i=0; i<numAnimationBindings; ++i )
        {
            // Get the animation curve element of the current animation id.
            const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings [i]; 
            const COLLADAFW::UniqueId& animationId = animationBinding.animation;
            const std::vector<MayaDM::AnimCurve*>* animationCurves = findMayaDMAnimCurves ( animationId );
            if ( animationCurves == 0 ) continue;

            // Get the array binding.
            size_t firstIndex = animationBinding.firstIndex;

            // Connect all animation curves of the current animation.
            size_t animationCurveCount = animationCurves->size ();
            if ( animationCurveCount > 1 )
            {
                std::cerr << "Multiple curves on morph animation not implemented!" << std::endl;
                return;
            }
            for ( size_t curveIndex=0; curveIndex<animationCurveCount; ++curveIndex )
            {
                const MayaDM::AnimCurve* animCurve = (*animationCurves) [curveIndex];
                MayaDM::AnimCurveTA* animCurveTA = (MayaDM::AnimCurveTA*) animCurve;

                // Connect the animation curve and the current transform node.
                // connectAttr "pCube1_translateX.output" "pCube1.translateX";
                const COLLADAFW::AnimationList::AnimationClass& animationClass = animationBinding.animationClass;
                switch ( animationClass )
                {
                case COLLADAFW::AnimationList::ARRAY_ELEMENT_1D:
                    {
                        connectAttr ( file, animCurveTA->getOutput (), blendShapeTarget.getWeight ( firstIndex ) );
                    }
                    break;
                default:
                    {
                        std::cerr << "Animation class for morph controller animation not implemented!" << std::endl;
                        break;
                    }
                }
            }
        }
    }

    //------------------------------
    void AnimationImporter::connectTransforms ( 
        const COLLADAFW::UniqueId& animationListId, 
        const COLLADAFW::AnimationList::AnimationBindings& animationBindings )
    {
        // Get the node, which use this animation list.
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        const TransformAnimation* transformAnimation = visualSceneImporter->findTransformAnimation ( animationListId );
        if ( !transformAnimation ) return;

        // Get the maya node object for the id.
        const COLLADAFW::UniqueId& transformNodeId = transformAnimation->getAnimationSourceId ();
        const MayaDM::Transform* transform = visualSceneImporter->findMayaDMTransform ( transformNodeId );
        const MayaTransform::TransformPhase& transformPhase = transformAnimation->getTransformPhase ();
        const bool isJointTransform = transformAnimation->getIsJointTransform ();

        const COLLADAFW::Transformation* transformation = transformAnimation->getTransformation ();
        COLLADAFW::Transformation::TransformationType transformType = transformation->getTransformationType ();

        // Set the transformation information in depend of the transform type.
        switch ( transformType )
        {
        case COLLADAFW::Transformation::ROTATE:
            writeRotateConnections ( transformation, transformPhase, isJointTransform, animationBindings, transform );
            break;
        case COLLADAFW::Transformation::SCALE:
            writeScaleConnections ( transformation, animationBindings, transform );
            break;
        case COLLADAFW::Transformation::SKEW:
            std::cerr << "Import of animated skew not implemented!" << std::endl;
//            writeSkewConnections ( transformation, animationList, transform );
            break;
        case COLLADAFW::Transformation::TRANSLATE:
            writeTranslateConnections ( transformation, animationBindings, transform );
            break;
        default:
            std::cerr << "Animation on transformation not supported!" << std::endl;
            break;
        }
    }

    //------------------------------
    void AnimationImporter::writeRotateConnections ( 
        const COLLADAFW::Transformation* transformation, 
        const MayaTransform::TransformPhase& transformPhase, 
        const bool isJointTransform,
        const COLLADAFW::AnimationList::AnimationBindings& animationBindings, 
        const MayaDM::Transform* transform )
    {
        // Get the maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Write the current rotation in a quaternion and 
        // multiplicate with the existing rotation.
        COLLADAFW::Rotate* rotation = ( COLLADAFW::Rotate* )transformation;
        COLLADABU::Math::Vector3& axis = rotation->getRotationAxis ();

        // Get the animation curves of the current animated element.
        size_t numAnimationBindings = animationBindings.getCount ();
        for ( size_t i=0; i<numAnimationBindings; ++i )
        {
            // Get the animation curve element of the current animation id.
            const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings [i]; 
            const COLLADAFW::UniqueId& animationId = animationBinding.animation;
            const std::vector<MayaDM::AnimCurve*>* animationCurves = findMayaDMAnimCurves ( animationId );
            if ( animationCurves == 0 ) continue;

            // TODO
            size_t firstIndex = animationBinding.firstIndex;

            // Connect all animation curves of the current animation.
            size_t animationCurveCount = animationCurves->size ();
            for ( size_t curveIndex=0; curveIndex<animationCurveCount; ++curveIndex )
            {
                const MayaDM::AnimCurve* animCurve = (*animationCurves) [curveIndex];
                MayaDM::AnimCurveTA* animCurveTA = (MayaDM::AnimCurveTA*) animCurve;

                // Connect the animation curve and the current transform node.
                // connectAttr "pCube1_translateX.output" "pCube1.translateX";
                const COLLADAFW::AnimationList::AnimationClass& animationClass = animationBinding.animationClass;
                switch ( animationClass )
                {
                case COLLADAFW::AnimationList::ANGLE:
                    {
                        switch ( transformPhase )
                        {
                        case MayaTransform::PHASE_JOINT_ORIENT1:
                        case MayaTransform::PHASE_JOINT_ORIENT2:
                        case MayaTransform::PHASE_JOINT_ORIENT3:
                            {
                                if ( !isJointTransform )
                                {
                                    std::cerr << " Can't connect rotate animation, about the transform is not a joint node!" << std::endl;
                                    return;
                                }
                                if ( COLLADABU::Math::Vector3::UNIT_X == axis )
                                { 
                                    connectAttr ( file, animCurveTA->getOutput (), ((MayaDM::Joint*)transform)->getJointOrientX () ); 
                                }
                                else if ( COLLADABU::Math::Vector3::UNIT_Y == axis )
                                {
                                    connectAttr ( file, animCurveTA->getOutput (), ((MayaDM::Joint*)transform)->getJointOrientY () );
                                }
                                else if ( COLLADABU::Math::Vector3::UNIT_Z == axis )
                                {
                                    connectAttr ( file, animCurveTA->getOutput (), ((MayaDM::Joint*)transform)->getJointOrientZ () );
                                }
                            }
                            break;
                        case MayaTransform::PHASE_ROTATE1:
                        case MayaTransform::PHASE_ROTATE2:
                        case MayaTransform::PHASE_ROTATE3:
                            {
                                if ( COLLADABU::Math::Vector3::UNIT_X == axis )
                                {
                                    connectAttr ( file, animCurveTA->getOutput (), transform->getRotateX () );
                                }
                                else if ( COLLADABU::Math::Vector3::UNIT_Y == axis )
                                {
                                    connectAttr ( file, animCurveTA->getOutput (), transform->getRotateY () );
                                }
                                else if ( COLLADABU::Math::Vector3::UNIT_Z == axis )
                                {
                                    connectAttr ( file, animCurveTA->getOutput (), transform->getRotateZ () );
                                }
                            }
                            break;
                        case MayaTransform::PHASE_ROTATE_ORIENT1:
                        case MayaTransform::PHASE_ROTATE_ORIENT2:
                        case MayaTransform::PHASE_ROTATE_ORIENT3:
                            {
                                if ( COLLADABU::Math::Vector3::UNIT_X == axis )
                                {
                                    connectAttr ( file, animCurveTA->getOutput (), transform->getRotateAxisX () );
                                }
                                else if ( COLLADABU::Math::Vector3::UNIT_Y == axis )
                                {
                                    connectAttr ( file, animCurveTA->getOutput (), transform->getRotateAxisY () );
                                }
                                else if ( COLLADABU::Math::Vector3::UNIT_Z == axis )
                                {
                                    connectAttr ( file, animCurveTA->getOutput (), transform->getRotateAxisZ () );
                                }
                            }
                            break;
                        }
                    }
                    break;
                case COLLADAFW::AnimationList::AXISANGLE:
                    {
                        switch ( transformPhase )
                        {
                        case MayaTransform::PHASE_JOINT_ORIENT1:
                        case MayaTransform::PHASE_JOINT_ORIENT2:
                        case MayaTransform::PHASE_JOINT_ORIENT3:
                            {
                                if ( !isJointTransform )
                                {
                                    std::cerr << " Can't connect rotate animation, about the transform is not a joint node!" << std::endl;
                                    return;
                                }
                                connectAttr ( file, animCurveTA->getOutput (), ((MayaDM::Joint*)transform)->getJointOrient () );
                            }
                            break;
                        case MayaTransform::PHASE_ROTATE1:
                        case MayaTransform::PHASE_ROTATE2:
                        case MayaTransform::PHASE_ROTATE3:
                            {
                                connectAttr ( file, animCurveTA->getOutput (), transform->getRotate () );
                            }
                            break;
                        case MayaTransform::PHASE_ROTATE_ORIENT1:
                        case MayaTransform::PHASE_ROTATE_ORIENT2:
                        case MayaTransform::PHASE_ROTATE_ORIENT3:
                            {
                                connectAttr ( file, animCurveTA->getOutput (), transform->getRotateAxis () );
                            }
                            break;
                        }
                    }
                    break;
                default:
                    {
                        std::cerr << "Animation class for transformation type \"ROTATE\" not implemented!" << std::endl;
                        break;
                    }
                }
            }
        }
    }

    //------------------------------
    void AnimationImporter::writeScaleConnections ( 
        const COLLADAFW::Transformation* transformation, 
        const COLLADAFW::AnimationList::AnimationBindings& animationBindings, 
        const MayaDM::Transform* transform )
    {
        // Get the scale.
        COLLADAFW::Scale* scale = ( COLLADAFW::Scale* )transformation;

        // Get the maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the animation curves of the current animated element.
        size_t numAnimationBindings = animationBindings.getCount ();
        for ( size_t i=0; i<numAnimationBindings; ++i )
        {
            // Get the animation curve element of the current animation id.
            const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings [i]; 
            const COLLADAFW::UniqueId& animationId = animationBinding.animation;
            const std::vector<MayaDM::AnimCurve*>* animCurves = findMayaDMAnimCurves ( animationId );
            if ( animCurves == 0 ) continue;

            // Connect all animation curves of the current animation.
            size_t animationCurveCount = animCurves->size ();
            for ( size_t curveIndex=0; curveIndex<animationCurveCount; ++curveIndex )
            {
                const MayaDM::AnimCurve* animCurve = (*animCurves) [curveIndex];
                MayaDM::AnimCurveTL* animCurveTU = (MayaDM::AnimCurveTL*) animCurve;

                // Connect the animation curve and the current transform node.
                // connectAttr "pCube1_translateX.output" "pCube1.translateX";
                const COLLADAFW::AnimationList::AnimationClass& animationClass = animationBinding.animationClass;
                switch ( animationClass )
                {
                case COLLADAFW::AnimationList::POSITION_X:
                    connectAttr ( file, animCurveTU->getOutput (), transform->getScaleX() );
                    break;
                case COLLADAFW::AnimationList::POSITION_Y:
                    connectAttr ( file, animCurveTU->getOutput (), transform->getScaleY() );
                    break;
                case COLLADAFW::AnimationList::POSITION_Z:
                    connectAttr ( file, animCurveTU->getOutput (), transform->getScaleZ() );
                    break;
                case COLLADAFW::AnimationList::POSITION_XYZ:
                    if ( animationCurveCount == 1 )
                    {
                        connectAttr ( file, animCurveTU->getOutput (), transform->getScale() );
                    }
                    else
                    {
                        switch ( curveIndex )
                        {
                        case 0:
                            connectAttr ( file, animCurveTU->getOutput (), transform->getScaleX() );
                            break;
                        case 1:
                            connectAttr ( file, animCurveTU->getOutput (), transform->getScaleY() );
                            break;
                        case 2:
                            connectAttr ( file, animCurveTU->getOutput (), transform->getScaleZ() );
                            break;
                        default:
                            std::cerr << "Too much animation curves for animation class \"POSITION_XYZ\" in transformation type \"SCALE\"!" << std::endl;
                            break;
                        }
                    }
                    break;
                default:
                    std::cerr << "Animation class for transformation type \"SCALE\" not implemented!" << std::endl;
                    break;
                }
            }
        }
    }

    //------------------------------
    void AnimationImporter::writeSkewConnections ( 
        const COLLADAFW::Transformation* transformation, 
        const COLLADAFW::AnimationList::AnimationBindings& animationBindings, 
        const MayaDM::Transform* transform )
    {
        // Get the skew.
        COLLADAFW::Skew* skew = ( COLLADAFW::Skew* )transformation;

        float s = tanf ( COLLADABU::Math::Utils::degToRadF ( skew->getAngle () ) );

        const COLLADABU::Math::Vector3& rotateAxis = skew->getRotateAxis();
        const COLLADABU::Math::Vector3& translateAxis = skew->getTranslateAxis();

//         MMatrix matrix;
//         skewValuesToMayaMatrix ( skew, matrix );
//         MTransformationMatrix tm ( matrix );
// 
//         double shear[3];
//         tm.getShear ( shear, MSpace::kTransform );

        // Get the maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the animation curves of the current animated element.
        size_t numAnimationBindings = animationBindings.getCount ();
        for ( size_t i=0; i<numAnimationBindings; ++i )
        {
            // Get the animation curve element of the current animation id.
            const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings [i]; 
            const COLLADAFW::UniqueId& animationId = animationBinding.animation;
            const std::vector<MayaDM::AnimCurve*>* animCurves = findMayaDMAnimCurves ( animationId );
            if ( animCurves == 0 ) continue;

            // Connect all animation curves of the current animation.
            size_t animationCurveCount = animCurves->size ();
            for ( size_t curveIndex=0; curveIndex<animationCurveCount; ++curveIndex )
            {
                const MayaDM::AnimCurve* animCurve = (*animCurves) [curveIndex];
                MayaDM::AnimCurveTL* animCurveTL = (MayaDM::AnimCurveTL*) animCurve;

                // Connect the animation curve and the current transform node.
                // connectAttr "pCube1_translateX.output" "pCube1.translateX";
                const COLLADAFW::AnimationList::AnimationClass& animationClass = animationBinding.animationClass;
                switch ( animationClass )
                {
                    //TODO
//                 case COLLADAFW::AnimationList::POSITION_X:
//                     connectAttr ( file, animationCurve->getOutput (), transform->getShearX() );
//                     break;
//                 case COLLADAFW::AnimationList::POSITION_Y:
//                     connectAttr ( file, animationCurve->getOutput (), transform->getShearY() );
//                     break;
//                 case COLLADAFW::AnimationList::POSITION_Z:
//                     connectAttr ( file, animationCurve->getOutput (), transform->getShearZ() );
//                     break;
                case COLLADAFW::AnimationList::POSITION_XYZ:
                    connectAttr ( file, animCurveTL->getOutput (), transform->getShear() );
                    break;
                default:
                    std::cerr << "Animation class for transformation type \"SHEAR\" not implemented!" << std::endl;
                    break;
                }
            }
        }
    }

    //------------------------------
    void AnimationImporter::writeTranslateConnections ( 
        const COLLADAFW::Transformation* transformation, 
        const COLLADAFW::AnimationList::AnimationBindings& animationBindings, 
        const MayaDM::Transform* transform )
    {
        COLLADAFW::Translate* translate = ( COLLADAFW::Translate* )transformation;
        COLLADABU::Math::Vector3 translation = translate->getTranslation ();

        // Get the maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the animation curves of the current animation list.
        size_t numAnimationBindings = animationBindings.getCount ();
        for ( size_t i=0; i<numAnimationBindings; ++i )
        {
            const COLLADAFW::AnimationList::AnimationBinding& animationBinding = animationBindings [i]; 

            // Get the animation curve element of the current animation id.
            const COLLADAFW::UniqueId& animationId = animationBinding.animation;
            const std::vector<MayaDM::AnimCurve*>* animCurves = findMayaDMAnimCurves ( animationId );
            if ( animCurves == 0 ) continue;

            // Connect all animation curves of the current animation.
            size_t animationCurveCount = animCurves->size ();
            for ( size_t curveIndex=0; curveIndex<animationCurveCount; ++curveIndex )
            {
                const MayaDM::AnimCurve* animCurve = (*animCurves) [curveIndex];
                MayaDM::AnimCurveTL* animCurveTL = (MayaDM::AnimCurveTL*) animCurve;

                // Connect the animation curve and the current transform node.
                // connectAttr "pCube1_translateX.output" "pCube1.translateX";
                const COLLADAFW::AnimationList::AnimationClass& animationClass = animationBinding.animationClass;
                switch ( animationClass )
                {
                case COLLADAFW::AnimationList::POSITION_X:
                    connectAttr ( file, animCurveTL->getOutput (), transform->getTranslateX () );
                    break;
                case COLLADAFW::AnimationList::POSITION_Y:
                    connectAttr ( file, animCurveTL->getOutput (), transform->getTranslateY () );
                    break;
                case COLLADAFW::AnimationList::POSITION_Z:
                    connectAttr ( file, animCurveTL->getOutput (), transform->getTranslateZ () );
                    break;
                case COLLADAFW::AnimationList::POSITION_XYZ:
                    {
                        if ( animationCurveCount == 1 )
                        {
                            connectAttr ( file, animCurveTL->getOutput (), transform->getTranslate () );
                        }
                        else
                        {
                            switch ( curveIndex )
                            {
                            case 0:
                                connectAttr ( file, animCurveTL->getOutput (), transform->getTranslateX () );
                                break;
                            case 1:
                                connectAttr ( file, animCurveTL->getOutput (), transform->getTranslateY () );
                                break;
                            case 2:
                                connectAttr ( file, animCurveTL->getOutput (), transform->getTranslateZ () );
                                break;
                            default:
                                std::cerr << "Too much animation curves for animation class \"POSITION_XYZ\" in transformation type \"TRANSLATE\"!" << std::endl;
                            }
                        }
                    }
                    break;
                default:
                    std::cerr << "Animation class for transformation type \"TRANSLATE\" not implemented!" << std::endl;
                    break;
                }
            }
        }
    }

} // namespace DAE2MA
