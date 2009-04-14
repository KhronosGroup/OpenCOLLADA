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

#include "COLLADAFWFloatOrDoubleArray.h"


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
	}

    //------------------------------
    void AnimationImporter::importAnimation ( const COLLADAFW::Animation* animation )
    {
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
            MGlobal::displayWarning ( "Export of other physical dimension then TIME not supported: " + physicalDimension );
            return;
        }

        TangentType tangentType = TANGENT_TYPE_DEFAULT;
        TangentType keyTangentOutType = TANGENT_TYPE_DEFAULT;

        bool weightedTangents = false;
        bool keyTanLocked = true;

        // Write the key time values
        const COLLADAFW::AnimationCurve::InterpolationType& interpolationType = animationCurve->getInterpolationType ();
        switch ( interpolationType )
        {
        case COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER:
            {
                tangentType = TANGENT_TYPE_FIXED;
                weightedTangents = true;
                writeAnimationCurve ( animationCurve, tangentType, keyTangentOutType, weightedTangents );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_BSPLINE:
            {
                MGlobal::displayError ( "Unknown animation interpolation type: INTERPOLATION_BSPLINE");
//                 tangentType = TANGENT_TYPE_CLAMPED;
//                 keyTanLocked = false;
//                 writeAnimationCurve ( animationCurve, tangentType, keyTangentOutType, weightedTangents, keyTanLocked );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_CARDINAL:
            {
                MGlobal::displayError ( "Unknown animation interpolation type: INTERPOLATION_CARDINAL");
//                 tangentType = TANGENT_TYPE_CLAMPED;
//                 weightedTangents = true;
//                 keyTanLocked = false;
//                 writeAnimationCurve ( animationCurve, tangentType, keyTangentOutType, weightedTangents, keyTanLocked );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_HERMITE:
            {
                MGlobal::displayError ( "Unknown animation interpolation type: INTERPOLATION_HERMITE");
//                 tangentType = TANGENT_TYPE_CLAMPED;
//                 keyTanLocked = false;
//                 writeAnimationCurve ( animationCurve, tangentType, keyTangentOutType, weightedTangents, keyTanLocked );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR:
            {
                tangentType = TANGENT_TYPE_LINEAR;
                weightedTangents = true;
                writeAnimationCurve ( animationCurve, tangentType, keyTangentOutType, weightedTangents );
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
        const TangentType& keyTangentOutType /*= TANGENT_TYPE_DEFAULT*/, 
        const bool weightedTangents /*= false*/, 
        const bool keyTanLocked /*= true*/ )
    {
        // The input is always the time with a stride of 2
        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = animationCurve->getInputValues ();
        size_t numInputValues = inputValuesArray.getValuesCount ();

        // The output can have different dimensions.
        const COLLADAFW::FloatOrDoubleArray& outputValuesArray = animationCurve->getOutputValues ();
        size_t outDimension = animationCurve->getOutDimension ();
        size_t numOutputValues = outputValuesArray.getValuesCount () / outDimension;

        if ( numInputValues != numOutputValues )
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

            animationName += "_" + XYZW_PARAMETERS[outputIndex];
            animationName = mAnimationIdList.addId ( animationName );

            // Create the animation curve.
            FILE* file = getDocumentImporter ()->getFile ();
            MayaDM::AnimCurveTL animCurveTL ( file, animationName );

            // Push the maya animation curve element in a list.
            const COLLADAFW::UniqueId& animationId = animationCurve->getUniqueId ();
            mMayaDMAnimationCurves [animationId].push_back ( animCurveTL );

            // Set tangent type
            if ( tangentType != TANGENT_TYPE_DEFAULT )
                animCurveTL.setTangentType ( tangentType );

            // Write weighted tangents
            if ( weightedTangents )
                animCurveTL.setWeightedTangents ( weightedTangents );

            // Set the key time values
            setKeyTimeValues ( animationCurve, animCurveTL, outputIndex );

            // setKeyTanLocked ();
            setKeyTangentLocks ( animationCurve, animCurveTL, keyTanLocked );

            // Set the in- and out-tangents
            if ( tangentType != TANGENT_TYPE_LINEAR && tangentType != TANGENT_TYPE_STEP )
            {
                setInTangents ( animationCurve, animCurveTL, outputIndex );
                setOutTangents ( animationCurve, animCurveTL, outputIndex );
            }
        }
    }

    //------------------------------
    const std::vector<MayaDM::AnimCurveTL>* AnimationImporter::findMayaDMAnimationCurve ( const COLLADAFW::UniqueId& animationId )
    {
        const std::map<COLLADAFW::UniqueId, std::vector<MayaDM::AnimCurveTL> >::iterator it = mMayaDMAnimationCurves.find ( animationId );
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

        size_t keyCount = animationCurve->getKeyCount ();
        if ( numOutputValues != keyCount )
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

            animationName += "_" + XYZW_PARAMETERS[outputIndex];
            animationName = mAnimationIdList.addId ( animationName );

            // Create the animation curve.
            FILE* file = getDocumentImporter ()->getFile ();
            MayaDM::AnimCurveTL animCurveTL ( file, animationName );

            // Push the maya animation curve element in a list.
            const COLLADAFW::UniqueId& animationId = animationCurve->getUniqueId ();
            mMayaDMAnimationCurves [animationId].push_back ( animCurveTL );

            // Set tangent type
            animCurveTL.setTangentType ( TANGENT_TYPE_FIXED );

            // Write weighted tangents
            animCurveTL.setWeightedTangents ( false );

            // Set the key time values
            setKeyTimeValues ( animationCurve, animCurveTL, outputIndex );

            // Set key tangent in type
            setKeyTangentInTypes ( animationCurve, animCurveTL );

            // Set key tangent out type
            setKeyTangentOutTypes ( animationCurve, animCurveTL );

            // Set the in- and out-tangents
            setInTangents ( animationCurve, animCurveTL, outputIndex );
            setOutTangents ( animationCurve, animCurveTL, outputIndex );
        }
    }

    //------------------------------
    void AnimationImporter::setKeyTimeValues ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        MayaDM::AnimCurveTL& animCurveTL, 
        const size_t outputIndex )
    {
        // The input is always the time 
        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = animationCurve->getInputValues ();
        const COLLADAFW::FloatOrDoubleArray::DataType& inputDataType = inputValuesArray.getType ();
        size_t numInputValues = inputValuesArray.getValuesCount ();

        // The output can have different dimensions.
        const COLLADAFW::FloatOrDoubleArray& outputValuesArray = animationCurve->getOutputValues ();
        const COLLADAFW::FloatOrDoubleArray::DataType& outputDataType = outputValuesArray.getType ();
        size_t outDimension = animationCurve->getOutDimension ();
        size_t numOutputValues = outputValuesArray.getValuesCount () / outDimension;

        size_t keyCount = animationCurve->getKeyCount ();
        if ( numInputValues != numOutputValues || numInputValues != keyCount )
        {
            MGlobal::displayError ( "AnimationImporter::setKeyTimeValues(): Invalid animation!" );
            return;
        }

        // Start
        animCurveTL.startKeyTimeValue ( 0, keyCount-1 );
        MayaDM::AnimCurveTL::KeyTimeValue keyTimeValue;

        double inputValue = 0;
        double outputValue = 0;

        for ( size_t inputIndex=0; inputIndex<keyCount; ++inputIndex )
        {
            switch ( inputDataType )
            {
            case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE:
                {
                    const COLLADAFW::ArrayPrimitiveType<double>* values = inputValuesArray.getDoubleValues ();
                    inputValue = (*values)[inputIndex];
                    break;
                }
            case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT:
                {
                    const COLLADAFW::ArrayPrimitiveType<float>* values = inputValuesArray.getFloatValues ();
                    inputValue = (*values)[inputIndex];
                    break;
                }
            case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_UNKNOWN:
            default:
                {
                    std::cerr << "No valid data type for bezier curve: " << inputDataType << std::endl;
                    MGlobal::displayError ( "No valid data type for bezier curve: " + inputDataType );
                    break;
                }
            }

            switch ( outputDataType )
            {
            case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE:
                {
                    const COLLADAFW::ArrayPrimitiveType<double>* values = outputValuesArray.getDoubleValues ();
                    size_t currentOutputIndex = inputIndex*outDimension + outputIndex;
                    outputValue = (*values)[currentOutputIndex];
                    break;
                }
            case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT:
                {
                    const COLLADAFW::ArrayPrimitiveType<float>* values = outputValuesArray.getFloatValues ();
                    size_t currentOutputIndex = inputIndex*outDimension + outputIndex;
                    outputValue = (*values)[currentOutputIndex];
                    break;
                }
            default:
                {
                    std::cerr << "No valid data type for bezier curve: " << inputDataType << std::endl;
                    MGlobal::displayError ( "No valid data type for bezier curve: " + inputDataType );
                    break;
                }
            }

            // TODO Framerate: 24 frames per second...
            keyTimeValue.keyTime = inputValue * 24;
            keyTimeValue.keyValue = outputValue;
            animCurveTL.appendKeyTimeValue ( keyTimeValue );
        }

        animCurveTL.endKeyTimeValue ();
    }

    //------------------------------
    void AnimationImporter::setInTangents ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        MayaDM::AnimCurveTL &animCurveTL, 
        const size_t outputIndex )
    {
        // The input is always the time 
        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = animationCurve->getInputValues ();

        // The output array.
        const COLLADAFW::FloatOrDoubleArray& outputValuesArray = animationCurve->getOutputValues ();

        // The in-tangent positions
        const size_t keyCount = animationCurve->getKeyCount ();
        const COLLADAFW::FloatOrDoubleArray& tangents = animationCurve->getInTangentValues ();
        const COLLADAFW::FloatOrDoubleArray::DataType& tangentsDataType = tangents.getType ();
        size_t numTangentValues = tangents.getValuesCount ();
        
        const size_t outDimension = animationCurve->getOutDimension ();

        // Write the in-tangent x values.
        animCurveTL.startKeyTanInX ( 0, keyCount-1 );
        for ( size_t keyPosition=0; keyPosition<keyCount; ++keyPosition )
        {
            double prevTime = 
                ( keyPosition > 0 ?
                getDoubleValue ( inputValuesArray, keyPosition-1 ) :
                getDoubleValue ( inputValuesArray, 0 ) - 1.0 );
            double curTime = ( getDoubleValue ( inputValuesArray, keyPosition ) );
            double nextTime = 
                ( keyPosition < keyCount - 1 ?
                getDoubleValue ( inputValuesArray, keyPosition+1 ) :
                getDoubleValue ( inputValuesArray, keyPosition ) + 1.0 );

            //double slopeX = ( curTime - prevTime ) / 3;

            size_t indexX = keyPosition*outDimension + outputIndex;
            double inTangentValueX = getDoubleValue ( tangents, indexX );
            double slopeX = inTangentValueX * 3;

            // Set the key tangent in x value.
            double resultX = curTime - slopeX;
            animCurveTL.appendKeyTanInX ( resultX );
        }
        animCurveTL.endKeyTanInX ();

        // Write the in-tangent y values.
        animCurveTL.startKeyTanInY ( 0, keyCount-1 );
        for ( size_t keyPosition=0; keyPosition<keyCount; ++keyPosition )
        {
            double prevTime =
                keyPosition > 0 ?
                getDoubleValue ( inputValuesArray, keyPosition-1 ) :
                getDoubleValue ( inputValuesArray, 0 ) - 1.0 ;
            double curTime = getDoubleValue ( inputValuesArray, keyPosition );
            double nextTime =
                keyPosition < keyCount - 1 ?
                getDoubleValue ( inputValuesArray, keyPosition+1 ) :
                getDoubleValue ( inputValuesArray, keyPosition ) + 1.0;

            double slopeX = ( curTime - prevTime ) / 3;

            double outputValue = getDoubleValue ( outputValuesArray, keyPosition );
            size_t indexY = keyPosition*outDimension + outputIndex + 1;
            double inTangentValueY = getDoubleValue ( tangents, indexY );
            double slopeY = ( (outputValue-inTangentValueY)*3*slopeX ) / ( curTime - prevTime );

            // Set the key tangent in y value.
            animCurveTL.appendKeyTanInY ( slopeY );
        }
        animCurveTL.endKeyTanInY ();
    }

    //------------------------------
    void AnimationImporter::setOutTangents ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        MayaDM::AnimCurveTL &animCurveTL, 
        const size_t outputIndex )
    {
        const size_t keyCount = animationCurve->getKeyCount ();
        const COLLADAFW::FloatOrDoubleArray& tangents = animationCurve->getOutTangentValues ();
        const COLLADAFW::FloatOrDoubleArray::DataType& tangentsDataType = tangents.getType ();
        size_t numTangentValues = tangents.getValuesCount ();

        const size_t outDimension = animationCurve->getOutDimension ();

        // Write the in-tangent x values.
        animCurveTL.startKeyTanOutX ( 0, keyCount-1 );
        for ( size_t inputIndex=0; inputIndex<keyCount; ++inputIndex )
        {
            switch ( tangentsDataType )
            {
            case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE:
                {
                    // Key out-tangent x values
                    const COLLADAFW::DoubleArray* values = tangents.getDoubleValues ();
                    size_t index = inputIndex*outDimension + outputIndex;
                    animCurveTL.appendKeyTanOutX ( (*values)[index] );
                }
                break;
            case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT:
                {
                    // Key out-tangent x values
                    const COLLADAFW::FloatArray* values = tangents.getFloatValues ();
                    size_t index = inputIndex*outDimension + outputIndex;
                    animCurveTL.appendKeyTanOutX ( (double)(*values)[index] );
                }
                break;
            default:
                MGlobal::displayError ( "AnimationImporter::setOutTangents(): Unknown data type!" );
                return;
            }
        }
        animCurveTL.endKeyTanOutX ();

        // Write the out-tangent y values.
        animCurveTL.startKeyTanOutY ( 0, keyCount-1 );
        for ( size_t inputIndex=0; inputIndex<keyCount; ++inputIndex )
        {
            switch ( tangentsDataType )
            {
            case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE:
                {
                    // Key out-tangent y values
                    const COLLADAFW::DoubleArray* values = tangents.getDoubleValues ();
                    size_t index = inputIndex*outDimension + outputIndex + 1;
                    animCurveTL.appendKeyTanOutY ( (*values)[index] );
                }
                break;
            case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT:
                {
                    // Key out-tangent y values
                    const COLLADAFW::FloatArray* values = tangents.getFloatValues ();
                    size_t index = inputIndex*outDimension + outputIndex + 1;
                    animCurveTL.appendKeyTanOutY ( (double)(*values)[index] );
                }
                break;
            default:
                MGlobal::displayError ( "AnimationImporter::setOutTangents(): Unknown data type!" );
                return;
            }
        }
        animCurveTL.endKeyTanOutY ();
    }

    //------------------------------
    void AnimationImporter::setKeyTangentInTypes ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        MayaDM::AnimCurveTL &animCurveTL )
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

        animCurveTL.startKeyTanInType ( 0, keyCount-1 );
        for ( size_t i=0; i<keyCount; ++i )
        {
            const COLLADAFW::AnimationCurve::InterpolationType& interpolationType = interpolationTypes [i];
            switch ( interpolationType )
            {
            case COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER:
                keyTangentInType = TANGENT_TYPE_CLAMPED;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_BSPLINE:
                keyTangentInType = TANGENT_TYPE_CLAMPED;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_CARDINAL:
                keyTangentInType = TANGENT_TYPE_CLAMPED;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_HERMITE:
                keyTangentInType = TANGENT_TYPE_CLAMPED;
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
            animCurveTL.appendKeyTanInType ( keyTangentInType );
        }
        animCurveTL.endKeyTanInType ();
    }

    //------------------------------
    void AnimationImporter::setKeyTangentOutTypes ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        MayaDM::AnimCurveTL &animCurveTL )
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

        animCurveTL.startKeyTanOutType ( 0, keyCount-1 );
        for ( size_t i=0; i<keyCount; ++i )
        {
            const COLLADAFW::AnimationCurve::InterpolationType& interpolationType = interpolationTypes [i];
            switch ( interpolationType )
            {
            case COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER:
                keyTangentOutType = TANGENT_TYPE_CLAMPED;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_BSPLINE:
                keyTangentOutType = TANGENT_TYPE_CLAMPED;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_CARDINAL:
                keyTangentOutType = TANGENT_TYPE_CLAMPED;
                break;
            case COLLADAFW::AnimationCurve::INTERPOLATION_HERMITE:
                keyTangentOutType = TANGENT_TYPE_CLAMPED;
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
            animCurveTL.appendKeyTanOutType ( keyTangentOutType );
        }
        animCurveTL.endKeyTanOutType ();
    }

    //------------------------------
    void AnimationImporter::setKeyTangentLocks ( 
        const COLLADAFW::AnimationCurve* animationCurve, 
        MayaDM::AnimCurveTL &animCurveTL,
        const bool keyTanLocked )
    {
        if ( !keyTanLocked )
        {
            size_t keyCount = animationCurve->getKeyCount ();
            animCurveTL.startKeyTanLocked ( 0, keyCount-1 );
            for ( size_t i=0; i<keyCount; ++i )
            {
                animCurveTL.appendKeyTanLocked ( keyTanLocked );
            }
            animCurveTL.endKeyTanLocked ();
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

} // namespace COLLADAMaya
