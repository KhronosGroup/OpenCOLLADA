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
        // Write the key time values
        const COLLADAFW::AnimationCurve::InterpolationType& interpolationType = animationCurve->getInterpolationType ();
        switch ( interpolationType )
        {
        case COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER:
            {
                const TangentType tangentType = TANGENT_TYPE_CLAMPED;
                importBezierCurve ( animationCurve, tangentType, true );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_BSPLINE:
            {
                const TangentType tangentType = TANGENT_TYPE_CLAMPED;
                importBezierCurve ( animationCurve, tangentType, false, false );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_CARDINAL:
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_HERMITE:
            {
                const TangentType tangentType = TANGENT_TYPE_CLAMPED;
                importBezierCurve ( animationCurve, tangentType, false, false );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR:
            {
                const TangentType tangentType = TANGENT_TYPE_LINEAR;
                importBezierCurve ( animationCurve, tangentType, true );
            }
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_MIXED:
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_STEP:
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
    void AnimationImporter::importBezierCurve ( 
        const COLLADAFW::AnimationCurve* fwAnimationCurve, 
        const TangentType& tangentType, 
        const bool weightedTangents /*= false*/, 
        const bool keyTanLocked /*= true*/ )
    {
        const COLLADAFW::PhysicalDimension& physicalDimension = fwAnimationCurve->getInPhysicalDimension ();
        if ( physicalDimension != COLLADAFW::PHYSICAL_DIMENSION_TIME )
        {
            MGlobal::displayWarning ( "Export of other physical dimension then TIME not supported: " + physicalDimension );
        }

        size_t outDimension = fwAnimationCurve->getOutDimension ();

        // The input is always the time with a stride of 2
        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = fwAnimationCurve->getInputValues ();
        size_t numInputValues = inputValuesArray.getValuesCount ();

        // The output can have different dimensions.
        const COLLADAFW::FloatOrDoubleArray& outputValuesArray = fwAnimationCurve->getOutputValues ();
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
            String animationName = fwAnimationCurve->getName ();
            if ( COLLADABU::Utils::equals ( animationName, "" ) ) 
                animationName = ANIMATION_NAME;
            animationName = DocumentImporter::frameworkNameToMayaName ( animationName );

            animationName += "_" + XYZW_PARAMETERS[outputIndex];
            animationName = mAnimationIdList.addId ( animationName );

            // Create the animation curve.
            FILE* file = getDocumentImporter ()->getFile ();
            MayaDM::AnimCurveTL animCurveTL ( file, animationName );

            // Set tangent type
            animCurveTL.setTangentType ( tangentType );
            animCurveTL.setWeightedTangents ( weightedTangents );

            // Get the unique id of the current curve.
            const COLLADAFW::UniqueId& animationId = fwAnimationCurve->getUniqueId ();

            // TODO Push the maya animation curve element in a list.
            mMayaDMAnimationCurves [animationId].push_back ( animCurveTL );

            // Set the key time values
            setKeyTimeValues ( fwAnimationCurve, animCurveTL, inputValuesArray, outputValuesArray, outputIndex );

            // setKeyTanLocked ();
            size_t keyCount = fwAnimationCurve->getKeyCount ();
            animCurveTL.startKeyTanLocked ( 0, keyCount-1 );
            for ( size_t i=0; i<keyCount; ++i )
            {
                animCurveTL.appendKeyTanLocked ( keyTanLocked );
            }
            animCurveTL.endKeyTanLocked ();
        }
    }

    //------------------------------
    void AnimationImporter::writeConnections ()
    {
        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        getDocumentImporter ()->getVisualSceneImporter ();

        // TODO Connect the animation with the node's attributes.
        // connectAttr "pCube1_translateX.output" "pCube1.translateX";
//        connectAttr ( file, )
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
    void AnimationImporter::setKeyTimeValues ( 
        const COLLADAFW::AnimationCurve* fwAnimationCurve, 
        MayaDM::AnimCurveTL& animCurveTL, 
        const COLLADAFW::FloatOrDoubleArray &inputValuesArray, 
        const COLLADAFW::FloatOrDoubleArray &outputValuesArray, 
        const size_t outputIndex )
    {
        size_t keyCount = fwAnimationCurve->getKeyCount ();
        size_t outDimension = fwAnimationCurve->getOutDimension ();

        const COLLADAFW::FloatOrDoubleArray::DataType& inputDataType = inputValuesArray.getType ();
        size_t numInputValues = inputValuesArray.getValuesCount ();

        const COLLADAFW::FloatOrDoubleArray::DataType& outputDataType = outputValuesArray.getType ();
        size_t numOutputValues = outputValuesArray.getValuesCount () / outDimension;

        // Start
        animCurveTL.startKeyTimeValue ( 0, keyCount-1 );
        MayaDM::AnimCurveTL::KeyTimeValue keyTimeValue;

        double inputValue = 0;
        double outputValue = 0;

        for ( size_t inputIndex=0; inputIndex<numInputValues; ++inputIndex )
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
            case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_UNKNOWN:
            default:
                {
                    std::cerr << "No valid data type for bezier curve: " << inputDataType << std::endl;
                    MGlobal::displayError ( "No valid data type for bezier curve: " + inputDataType );
                    break;
                }
            }

            keyTimeValue.keyTime = inputValue * 24;
            keyTimeValue.keyValue = outputValue;
            animCurveTL.appendKeyTimeValue ( keyTimeValue );
        }

        animCurveTL.endKeyTimeValue ();
    }

} // namespace COLLADAMaya
