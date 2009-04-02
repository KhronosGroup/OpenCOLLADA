/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaAnimationImporter.h"

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
        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the unique id of the current curve.
        const COLLADAFW::UniqueId& animationId = animationCurve->getUniqueId ();

        // Create a unique name.
        String animationName = mAnimationIdList.addId ( ANIMATION_NAME );

        // Create the animation curve.
        MayaDM::AnimCurveTL animCurve ( file, animationName );

        // Write the key time values
        const COLLADAFW::AnimationCurve::InterpolationType& interpolationType = animationCurve->getInterpolationType ();
        switch ( interpolationType )
        {
        case COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER:
            {
                importBezierCurve ( animCurve, animationCurve );
                break;
            }
        case COLLADAFW::AnimationCurve::INTERPOLATION_BSPLINE:
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_CARDINAL:
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_HERMITE:
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR:
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_MIXED:
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_STEP:
            break;
        case COLLADAFW::AnimationCurve::INTERPOLATION_UNKNOWN:
            {
                importBezierCurve ( animCurve, animationCurve );
                break;
            }
        default:
            break;
        }
    }

    //------------------------------
    void AnimationImporter::importBezierCurve ( 
        MayaDM::AnimCurveTL& animCurve, 
        COLLADAFW::AnimationCurve* animationCurve )
    {
        size_t keyCount = animationCurve->getKeyCount ();
        size_t outDimension = animationCurve->getOutDimension ();

        const COLLADAFW::FloatOrDoubleArray& inputValuesArray = animationCurve->getInputValues ();
        const COLLADAFW::FloatOrDoubleArray::DataType& inputDataType = inputValuesArray.getType ();
        size_t numInputValues = inputValuesArray.getValuesCount ();

        const COLLADAFW::FloatOrDoubleArray& outputValuesArray = animationCurve->getOutputValues ();
        const COLLADAFW::FloatOrDoubleArray::DataType& outputDataType = outputValuesArray.getType ();
        size_t numOutputValues = outputValuesArray.getValuesCount ();

        if ( numInputValues != numOutputValues )
        {
            MGlobal::displayError ( "Invalid animation!" );
            return;
        }

        // Start
        animCurve.startKeyTimeValue ( 0, keyCount-1 );
        MayaDM::AnimCurveTL::KeyTimeValue keyTimeValue;

        double inputValue = 0;
        double outputValue = 0;

        for ( size_t i=0; i<numInputValues; ++i )
        {
            switch ( inputDataType )
            {
            case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE:
                {
                    const COLLADAFW::ArrayPrimitiveType<double>* values = inputValuesArray.getDoubleValues ();
                    inputValue = (*values)[i];
                    break;
                }
            case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT:
                {
                    const COLLADAFW::ArrayPrimitiveType<float>* values = inputValuesArray.getFloatValues ();
                    inputValue = (*values)[i];
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
                    outputValue = (*values)[i];
                    break;
                }
            case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT:
                {
                    const COLLADAFW::ArrayPrimitiveType<float>* values = outputValuesArray.getFloatValues ();
                    outputValue = (*values)[i];
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
            animCurve.appendKeyTimeValue ( keyTimeValue );
        }

        animCurve.endKeyTimeValue ();
    }

    //------------------------------
    

} // namespace COLLADAMaya
