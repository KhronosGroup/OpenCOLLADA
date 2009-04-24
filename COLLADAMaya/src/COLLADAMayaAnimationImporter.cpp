/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaAnimationImporter.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaVisualSceneImporter.h"

#include "COLLADAFWFloatOrDoubleArray.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWTranslate.h"

#include <MayaDMAnimCurveTA.h>
#include <MayaDMCommands.h>


namespace COLLADAMaya
{

    const String AnimationImporter::ANIMATION_NAME = "Animation";


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
            MGlobal::displayWarning ( "Import of other physical dimension then TIME not supported: " + physicalDimension );
            return;
        }

        TangentType tangentType = TANGENT_TYPE_DEFAULT;
        TangentType keyTangentOutType = TANGENT_TYPE_DEFAULT;

        // Write the key time values
        const COLLADAFW::AnimationCurve::InterpolationType& interpolationType = animationCurve->getInterpolationType ();
        switch ( interpolationType )
        {
        case COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER:
            {
                tangentType = TANGENT_TYPE_FIXED;
                writeAnimationCurve ( animationCurve, tangentType, keyTangentOutType );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_BSPLINE:
            {
                MGlobal::displayError ( "Unknown animation interpolation type: INTERPOLATION_BSPLINE");
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_CARDINAL:
            {
                MGlobal::displayError ( "Unknown animation interpolation type: INTERPOLATION_CARDINAL");
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_HERMITE:
            {
                MGlobal::displayError ( "Unknown animation interpolation type: INTERPOLATION_HERMITE");
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR:
            {
                tangentType = TANGENT_TYPE_LINEAR;
                writeAnimationCurve ( animationCurve, tangentType, keyTangentOutType );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_MIXED:
            {
                writeAnimationCurveByKeys ( animationCurve );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_STEP:
            {
                tangentType = TANGENT_TYPE_STEP;
                writeAnimationCurve ( animationCurve, tangentType );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_UNKNOWN:
            {
                MGlobal::displayError ( "Unknown animation interpolation type!");
                break;
            }
        default:
            break;
        }
    }

    //------------------------------
    void AnimationImporter::writeAnimationCurve ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        const TangentType& tangentType /*= TANGENT_TYPE_DEFAULT*/, 
        const TangentType& keyTangentOutType /*= TANGENT_TYPE_DEFAULT*/ )
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
            MGlobal::displayError ( "Invalid animation!" );
            return;
        }

        // Create a curve for every animated element.
        for ( size_t outputIndex=0; outputIndex<outDimension; ++outputIndex )
        {
            // Create a unique name.
            String animationName = animationCurve->getName ();
            if ( COLLADABU::Utils::equals ( animationName, "" ) ) 
                animationName = ANIMATION_NAME;
            animationName = DocumentImporter::frameworkNameToMayaName ( animationName );

            // TODO
//             if ( outDimension > 1 )
//                 animationName += "_" + XYZW_PARAMETERS[outputIndex];
            animationName = mAnimationIdList.addId ( animationName );

            // Get the maya file
            FILE* file = getDocumentImporter ()->getFile ();

            // Create the animation curve.
            MayaDM::AnimCurve* animCurve = 0;

            const COLLADAFW::PhysicalDimension& outPhysicalDimension = outPhysicalDimensions [outputIndex];
            switch ( outPhysicalDimension )
            {
            case COLLADAFW::PHYSICAL_DIMENSION_LENGTH:
                {
                    animCurve = new MayaDM::AnimCurveTL ( file, animationName );
                    animCurve->setTangentType ( tangentType );
                    setKeyTimeValues ( animationCurve, (MayaDM::AnimCurveTL*)animCurve, outputIndex );
                }
                break;
            case COLLADAFW::PHYSICAL_DIMENSION_ANGLE:
                {
                    animCurve = new MayaDM::AnimCurveTA ( file, animationName );
                    animCurve->setTangentType ( tangentType );
                    setKeyTimeValues ( animationCurve, (MayaDM::AnimCurveTA*)animCurve, outputIndex );
                }
                break;
            case COLLADAFW::PHYSICAL_DIMENSION_TIME:
                MGlobal::displayError ( "Physical dimension not supported: PHYSICAL_DIMENSION_TIME" );
                return; break;
            case COLLADAFW::PHYSICAL_DIMENSION_COLOR:
                MGlobal::displayError ( "Physical dimension not supported: PHYSICAL_DIMENSION_COLOR" );
                return; break;
            case COLLADAFW::PHYSICAL_DIMENSION_NUMBER:
                MGlobal::displayError ( "Physical dimension not supported: PHYSICAL_DIMENSION_NUMBER" );
                return; break;
            default:
                MGlobal::displayError ( "Unknown physical dimension!" );
                return; break;
            }

            // Add the original id attribute.
            String colladaId = animationCurve->getOriginalId ();
            if ( !COLLADABU::Utils::equals ( colladaId, "" ) )
            {
                MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, "", "string" );
                MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, "", "string", colladaId );
            }

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
            MGlobal::displayError ( "Invalid animation!" );
            return;
        }

        // Create a curve for every animated element.
        for ( size_t outputIndex=0; outputIndex<outDimension; ++outputIndex )
        {
            // Create a unique name.
            String animationName = animationCurve->getName ();
            if ( COLLADABU::Utils::equals ( animationName, "" ) ) 
                animationName = ANIMATION_NAME;
            animationName = DocumentImporter::frameworkNameToMayaName ( animationName );

            // TODO
//            animationName += "_" + XYZW_PARAMETERS[outputIndex];
            animationName = mAnimationIdList.addId ( animationName );

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
                MGlobal::displayError ( "Physical dimension not supported: PHYSICAL_DIMENSION_TIME" );
                return; break;
            case COLLADAFW::PHYSICAL_DIMENSION_COLOR:
                MGlobal::displayError ( "Physical dimension not supported: PHYSICAL_DIMENSION_COLOR" );
                return; break;
            case COLLADAFW::PHYSICAL_DIMENSION_NUMBER:
                MGlobal::displayError ( "Physical dimension not supported: PHYSICAL_DIMENSION_NUMBER" );
                return; break;
            default:
                MGlobal::displayError ( "Unknown physical dimension!" );
                return; break;
            }

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
            MGlobal::displayError ( "AnimationImporter::setKeyTimeValues(): Invalid animation!" );
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

            // TODO Framerate: 24 frames per second...
            keyTimeValue.keyTime = inputValue * 24;
            keyTimeValue.keyValue = outputValue;
            animCurveTL->appendKeyTimeValue ( keyTimeValue );
        }

        animCurveTL->endKeyTimeValue ();
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
            MGlobal::displayError ( "AnimationImporter::setKeyTimeValues(): Invalid animation!" );
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

            // TODO Framerate: 24 frames per second...
            keyTimeValue.keyTime = inputValue * 24;
            keyTimeValue.keyValue = outputValue;
            animCurveTA->appendKeyTimeValue ( keyTimeValue );
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
            if ( mixedInterpolation )
                interpolationType = animationCurve->getInterpolationTypes () [keyPosition];

            switch ( interpolationType )
            {
            case COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER:
                {
                    double inputValue = getDoubleValue ( inputValuesArray, keyPosition );
                    size_t indexX = keyPosition*outDimension*2 + outputIndex;
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
                    MGlobal::displayError ( "Interpolation type not supported!" );
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
        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = animationCurve->getInputValues ();
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
                    size_t indexY = keyPosition*outDimension*2 + outputIndex + 1;
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
                    MGlobal::displayError ( "Interpolation type not supported!" );
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
                    size_t indexX = keyPosition*outDimension*2 + outputIndex;
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
                    MGlobal::displayError ( "Interpolation type not supported!" );
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
        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = animationCurve->getInputValues ();
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
                    size_t indexY = keyPosition*outDimension*2 + outputIndex + 1;
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
                    MGlobal::displayError ( "Interpolation type not supported!" );
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
            MGlobal::displayError ( "AnimationImporter::setKeyTangentInType(): Invalid animation!" );
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
                MGlobal::displayError ( "Unknown interpolation type in mixed interpolations!");
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
            MGlobal::displayError ( "AnimationImporter::setKeyTangentOutType(): Invalid animation!" );
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
                MGlobal::displayError ( "Unknown interpolation type in mixed interpolations!");
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
    double AnimationImporter::getDoubleValue ( 
        const COLLADAFW::FloatOrDoubleArray &inputValuesArray, 
        const size_t position )
    {
        double inputValue = 0;

        size_t numInputValues = inputValuesArray.getValuesCount ();
        if ( position > numInputValues -1 )
            MGlobal::displayError ("Out of range error!");

        const COLLADAFW::FloatOrDoubleArray::DataType& inputDataType = inputValuesArray.getType ();
        switch ( inputDataType )
        {
        case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE:
            {
                const COLLADAFW::DoubleArray* inputValues = inputValuesArray.getDoubleValues ();
                inputValue = (*inputValues) [position];
            }
            break;
        case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT:
            {
                const COLLADAFW::FloatArray* inputValues = inputValuesArray.getFloatValues ();
                inputValue = (double)(*inputValues) [position];
            }
            break;
        default:
            MGlobal::displayError ( "AnimationImporter::setInTangents(): inputDataType unknown data type!" );
        }

        return inputValue;
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
    void AnimationImporter::writeConnections ( const COLLADAFW::AnimationList* animationList )
    {
        // Get the id of the current animation list.
        const COLLADAFW::UniqueId& animationListId = animationList->getUniqueId ();
        if ( findAnimationList ( animationListId ) ) return;
        mAnimationListIds.push_back ( animationListId );

        // Get the maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the node, which use this animation list.
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        const TransformAnimation* transformAnimation = visualSceneImporter->findTransformAnimation ( animationListId );
        if ( !transformAnimation ) 
        {
            MGlobal::displayError ( "Nobody uses this animation list!" );
            return;
        }

        // Get the maya node object for the id.
        const COLLADAFW::UniqueId& transformNodeId = transformAnimation->getTransformNodeId ();
        const MayaDM::Transform* transform = visualSceneImporter->findMayaDMTransform ( transformNodeId );

        const COLLADAFW::Transformation* transformation = transformAnimation->getTransformation ();
        COLLADAFW::Transformation::TransformationType transformType = transformation->getTransformationType ();
        
        // Set the transformation information in depend of the transform type.
        switch ( transformType )
        {
        case COLLADAFW::Transformation::ROTATE:
            writeRotateConnections ( transformation, animationList, transform );
            break;
        case COLLADAFW::Transformation::SCALE:
            writeScaleConnections ( transformation, animationList, transform );
            break;
        case COLLADAFW::Transformation::SKEW:
            writeSkewConnections ( transformation, animationList, transform );
            break;
        case COLLADAFW::Transformation::TRANSLATE:
            writeTranslateConnections ( transformation, animationList, transform );
            break;
        default:
            std::cerr << "Animation on transformation not supported!" << endl;
            MGlobal::displayError ( "Animation on transformation not supported!" );
            break;
        }
    }

    //------------------------------
    void AnimationImporter::writeRotateConnections ( 
        const COLLADAFW::Transformation* transformation, 
        const COLLADAFW::AnimationList* animationList, 
        const MayaDM::Transform* transform )
    {
        // Get the maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Write the current rotation in a quaternion and 
        // multiplicate with the existing rotation.
        COLLADAFW::Rotate* rotation = ( COLLADAFW::Rotate* )transformation;
        double angle = rotation->getRotationAngle ();
        COLLADABU::Math::Vector3& axis = rotation->getRotationAxis ();

        // Get the animation curves of the current animated element.
        const COLLADAFW::AnimationList::AnimationBindings& animationBindings = animationList->getAnimationBindings ();
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
                        break;
                    }
                case COLLADAFW::AnimationList::AXISANGLE:
                    {
                        connectAttr ( file, animCurveTA->getOutput (), transform->getRotate () );
                        break;
                    }
                default:
                    {
                        MGlobal::displayInfo ( "Animation class for transformation type \"ROTATE\" not implemented!" );
                        break;
                    }
                }
            }
        }
    }

    //------------------------------
    void AnimationImporter::writeScaleConnections ( 
        const COLLADAFW::Transformation* transformation, 
        const COLLADAFW::AnimationList* animationList, 
        const MayaDM::Transform* transform )
    {
        // Get the scale.
        COLLADAFW::Scale* scale = ( COLLADAFW::Scale* )transformation;
        COLLADABU::Math::Vector3& scaleVec = scale->getScale ();

        // Get the maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the animation curves of the current animated element.
        const COLLADAFW::AnimationList::AnimationBindings& animationBindings = animationList->getAnimationBindings ();
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
                case COLLADAFW::AnimationList::SCALE_X:
                    connectAttr ( file, animCurveTL->getOutput (), transform->getScaleX() );
                    break;
                case COLLADAFW::AnimationList::SCALE_Y:
                    connectAttr ( file, animCurveTL->getOutput (), transform->getScaleX() );
                    break;
                case COLLADAFW::AnimationList::SCALE_Z:
                    connectAttr ( file, animCurveTL->getOutput (), transform->getScaleX() );
                    break;
                case COLLADAFW::AnimationList::SCALE_XYZ:
                    connectAttr ( file, animCurveTL->getOutput (), transform->getScale() );
                    break;
                default:
                    MGlobal::displayInfo ( "Animation class for transformation type \"SCALE\" not implemented!" );
                    break;
                }
            }
        }
    }

    //------------------------------
    void AnimationImporter::writeSkewConnections ( 
        const COLLADAFW::Transformation* transformation, 
        const COLLADAFW::AnimationList* animationList, 
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
        const COLLADAFW::AnimationList::AnimationBindings& animationBindings = animationList->getAnimationBindings ();
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
//                 case COLLADAFW::AnimationList::SKEW_X:
//                     connectAttr ( file, animationCurve->getOutput (), transform->getShearX() );
//                     break;
//                 case COLLADAFW::AnimationList::SKEW_Y:
//                     connectAttr ( file, animationCurve->getOutput (), transform->getShearY() );
//                     break;
//                 case COLLADAFW::AnimationList::SKEW_Z:
//                     connectAttr ( file, animationCurve->getOutput (), transform->getShearZ() );
//                     break;
                case COLLADAFW::AnimationList::SKEW_XYZ:
                    connectAttr ( file, animCurveTL->getOutput (), transform->getShear() );
                    break;
                default:
                    MGlobal::displayInfo ( "Animation class for transformation type \"SKEW\" not implemented!" );
                    break;
                }
            }
        }
    }

    //------------------------------
    void AnimationImporter::writeTranslateConnections ( 
        const COLLADAFW::Transformation* transformation, 
        const COLLADAFW::AnimationList* animationList, 
        const MayaDM::Transform* transform )
    {
        COLLADAFW::Translate* translate = ( COLLADAFW::Translate* )transformation;
        COLLADABU::Math::Vector3 translation = translate->getTranslation ();

//         if ( mayaTransform.phase == MayaTransformation::PHASE_TRANS1 )
//         {
//             mayaTransform.translate1Vec.push_back ( MVector (translation[0],translation[1],translation[2] ) );
//             ++mayaTransform.numTranslate1;
//             for ( unsigned int j=0; j<3; ++j )
//                 mayaTransform.translate1[j] += translation [j];
//         }
//         else if ( mayaTransform.phase == MayaTransformation::PHASE_TRANS2 )
//         {
//             mayaTransform.translate2Vec.push_back ( MVector (translation[0],translation[1],translation[2] ) );
//             ++mayaTransform.numTranslate2;
//             for ( unsigned int j=0; j<3; ++j )
//                 mayaTransform.translate2[j] += translation [j];
//         }
//         else if ( mayaTransform.phase == MayaTransformation::PHASE_TRANS3 )
//         {
//             mayaTransform.translate3Vec.push_back ( MVector (translation[0],translation[1],translation[2] ) );
//             ++mayaTransform.numTranslate3;
//             for ( unsigned int j=0; j<3; ++j )
//                 mayaTransform.translate3[j] += translation [j];
//         }

        // Get the maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the animation curves of the current animation list.
        const COLLADAFW::AnimationList::AnimationBindings& animationBindings = animationList->getAnimationBindings ();
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

                // TODO Connect the animation curve and the current transform node.
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
                    connectAttr ( file, animCurveTL->getOutput (), transform->getTranslate () );
//                     switch ( curveIndex )
//                     {
//                     case 0:
//                         connectAttr ( file, animationCurve->getOutput (), transform->getTranslateX () );
//                         break;
//                     case 1:
//                         connectAttr ( file, animationCurve->getOutput (), transform->getTranslateY () );
//                         break;
//                     case 2:
//                         connectAttr ( file, animationCurve->getOutput (), transform->getTranslateZ () );
//                         break;
//                     }
                    break;
                default:
                    MGlobal::displayInfo ( "Animation class for transformation type \"TRANSLATE\" not implemented!" );
                    break;
                }
            }
        }
    }

} // namespace COLLADAMaya
