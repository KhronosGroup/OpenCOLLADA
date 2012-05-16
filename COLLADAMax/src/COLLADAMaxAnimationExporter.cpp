/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMaxStableHeaders.h"

#include "COLLADASWStreamWriter.h"
#include "COLLADASWSource.h"
#include "Math/COLLADABUMathUtils.h"

#include "COLLADAMaxAnimationExporter.h"
#include "COLLADAMaxExportSceneGraph.h"

#include <max.h>
#include <istdplug.h> 
#include <control.h>
#include <units.h>


namespace COLLADAMax
{


    //---------------------------------------------------------------
    Animation::Animation ( Control * controller, const String & id, const String & sid, const String * parameter, int type, ConversionFunctor* conversionFunctor )
            : mController ( controller ),
			mINode(0),
            mId ( id ),
            mSid ( sid ),
            mParameters ( parameter ),
			mMatrixIndex(-1),
            mType ( type ),
			mConversionFunctor( conversionFunctor ? conversionFunctor->clone() : 0 ),
			mInputTypeFlags(NONE)
    {}


	//---------------------------------------------------------------
	Animation::Animation ( Control * controller, const String & id, const String & sid, int matrixIndex, int type, ConversionFunctor* conversionFunctor )
		: mController ( controller ),
		mINode(0),
		mId ( id ),
		mSid ( sid ),
		mParameters ( 0 ),
		mMatrixIndex(matrixIndex),
		mType ( type ),
		mConversionFunctor( conversionFunctor ? conversionFunctor->clone() : 0 ),
		mInputTypeFlags(NONE)
	{}



	//---------------------------------------------------------------
	Animation::Animation ( INode * iNode, const String & id, const String & sid, const String * parameter, int type, ConversionFunctor* conversionFunctor )
		: 
		mController(0),
		mINode ( iNode ),
		mId ( id ),
		mSid ( sid ),
		mParameters ( parameter ),
		mMatrixIndex(-1),
		mType ( type ),
		mConversionFunctor( conversionFunctor ? conversionFunctor->clone() : 0 ),
		mInputTypeFlags(NONE)
	{}


	Animation::Animation( const Animation& other ):
		mController (other.mController),
		mINode (other.mINode),
		mId( other.mId),
		mSid(other.mSid),
		mParameters(other.mParameters),
		mMatrixIndex(other.mMatrixIndex),
		mType(other.mType),
		mInputTypeFlags(other.mInputTypeFlags),
		mConversionFunctor ( other.mConversionFunctor ? other.mConversionFunctor->clone() : 0)
	{}

	const Animation& Animation::operator=( const Animation& other )
	{
		mController  = other.mController;
		mINode  = other.mINode;
		mId =  other.mId;
		mSid = other.mSid;
		mParameters = other.mParameters;
		mMatrixIndex = other.mMatrixIndex;
		mType = other.mType;
		mInputTypeFlags = other.mInputTypeFlags;
		mConversionFunctor  = other.mConversionFunctor ? other.mConversionFunctor->clone() : 0; 
		return *this;
	}
	
	//---------------------------------------------------------------
    int Animation::getDimension() const
    {
        switch ( mType )
        {

        case FLOAT:
        case POSITION_X:
        case POSITION_Y:
        case POSITION_Z:
        case ROTATION_X:
        case ROTATION_Y:
        case ROTATION_Z:
            return 1;

		case FLOAT3:
            return 3;
		
		case SCALE_ROT_AXIS_R:
		case SCALE_ROT_AXIS:
		case FLOAT4:
			return 4;

		case FLOAT4x4:
			return 16;

        default:
            return 0;
        }
    }

	Animation::~Animation()
	{
		delete mConversionFunctor;
	}

	const float AnimationExporter::DEFAULT_INLENGHT = 0.333f;
	const float AnimationExporter::DEFAULT_OUTLENGHT = 0.333f;
    const float AnimationExporter::DEFAULT_INLENGHT_FLOAT = AnimationExporter::DEFAULT_INLENGHT;

	float AnimationExporter::DEFAULT_INLENGHT_POINTX_FLOAT_ARRAY[4] = {AnimationExporter::DEFAULT_INLENGHT, AnimationExporter::DEFAULT_INLENGHT, AnimationExporter::DEFAULT_INLENGHT, AnimationExporter::DEFAULT_INLENGHT};
    
	const float AnimationExporter::DEFAULT_OUTLENGHT_FLOAT = AnimationExporter::DEFAULT_OUTLENGHT;
	float AnimationExporter::DEFAULT_OUTLENGHT_POINTX_FLOAT_ARRAY[4] = {AnimationExporter::DEFAULT_OUTLENGHT, AnimationExporter::DEFAULT_OUTLENGHT, AnimationExporter::DEFAULT_OUTLENGHT, AnimationExporter::DEFAULT_OUTLENGHT};


    const float AnimationExporter::mTimeFactor = 1.0f / ( GetTicksPerFrame() * GetFrameRate() );



    //---------------------------------------------------------------
    AnimationExporter::AnimationExporter ( COLLADASW::StreamWriter * streamWriter, DocumentExporter * documentExporter )
            : COLLADASW::LibraryAnimations ( streamWriter ),
            mDocumentExporter ( documentExporter )
    {}

    //---------------------------------------------------------------
    TimeValue AnimationExporter::getPreviousTime ( const int & i, Control * controller ) const
    {
        return ( i > 0 ) ? controller->GetKeyTime ( i - 1 ) : controller->GetKeyTime ( i ) - TimeValue ( 1.0f / mTimeFactor );
    }

    //---------------------------------------------------------------
    TimeValue AnimationExporter::getNextTime ( const int & i, const int & keyCount, Control * controller ) const
    {
        return ( i < keyCount - 1 ) ? controller->GetKeyTime ( i + 1 ) : controller->GetKeyTime ( i ) + TimeValue ( 1.0f / mTimeFactor );
    }

	//---------------------------------------------------------------
	bool AnimationExporter::forceSampleMatrices(INode* iNode)
	{
		if ( iNode )
		{
			Control* controller = iNode->GetTMController();
			// The -only- class we can hope to export without sampling is the PRS controller
			if ( controller )
				return (controller->ClassID() != Class_ID(PRS_CONTROL_CLASS_ID, 0) || findConstraint(controller));
		}
		return false;
	}

	// Function searches controller and all subanims for presence of a Constraint.
	// This is bit of a cheap fix, a slightly better option may be to include
	// parent offset calculation in rotation/position sampling (like Matrix sampling).
	//---------------------------------------------------------------
	bool AnimationExporter::findConstraint(Animatable* controller)
	{
		if (controller->SuperClassID() == CTRL_FLOAT_CLASS_ID) 
			return false;
		Class_ID classId = controller->ClassID();
		if (classId.PartB() == 0)
		{
			unsigned long classIdPartA = classId.PartA();
			if (classIdPartA == POSITION_CONSTRAINT_CLASS_ID ||
				classIdPartA == ORIENTATION_CONSTRAINT_CLASS_ID ||
				classIdPartA == LOOKAT_CONSTRAINT_CLASS_ID)
			{
				return true;
			}
		}

		int SubcontrollerCount = controller->NumSubs();
		for (int i = 0; i < SubcontrollerCount; i++)
		{
			Animatable* subController = controller->SubAnim(i);
			if (subController )
			{
				if (findConstraint(subController)) 
					return true;
			}
		}
		return false;
	}


    //---------------------------------------------------------------
    void AnimationExporter::doExport()
    {
        if ( !mAnimationList.empty() )
        {
            openAnimation();

            for ( AnimationList::iterator it = mAnimationList.begin(); it != mAnimationList.end();++it )
                exportSources ( *it );

            for ( AnimationList::iterator it = mAnimationList.begin(); it != mAnimationList.end();++it )
                exportSampler ( *it );

            for ( AnimationList::iterator it = mAnimationList.begin(); it != mAnimationList.end();++it )
                exportChannel ( *it );

            closeLibrary();
        }
    }


	//---------------------------------------------------------------
	bool AnimationExporter::addAnimatedFloat ( Control * controller, const String & id, const String & sid, const String parameters[], bool forceFullCheck, ConversionFunctor* conversionFunctor)
	{
		if ( !isAnimated(controller) )
			return false;

		Animation animation(controller, id, sid, parameters, Animation::FLOAT, conversionFunctor);

		if ( !forceFullCheck || isAnimated(animation, true) )
		{
			addAnimation(animation);
			return true;
		}
		return false;
	}


	//---------------------------------------------------------------
	bool AnimationExporter::addAnimatedFloat ( Control * controller, const String & id, const String & sid, int matrixIndex, bool forceFullCheck, ConversionFunctor* conversionFunctor)
	{
		if ( !isAnimated(controller) )
			return false;

		Animation animation(controller, id, sid, matrixIndex, Animation::FLOAT, conversionFunctor);

		if ( !forceFullCheck || isAnimated(animation, true) )
		{
			addAnimation(animation);
			return true;
		}
		return false;
	}



    //---------------------------------------------------------------
    bool AnimationExporter::addAnimatedPoint3 ( Control * controller, const String & id, const String & sid, const String parameters[], bool forceFullCheck, ConversionFunctor* conversionFunctor )
    {
		if ( !isAnimated(controller))
			return false;

		bool animated = false;

        Control * subControllers[ 3 ] = {controller->GetXController(), controller->GetYController(), controller->GetZController() };

        // First, Try to extract animations from the component controllers

        if ( subControllers[ 0 ] && subControllers[ 1 ]  && subControllers[ 2 ]  )
        {
            for ( int i = 0; i < 3; ++i )
            {
                if ( isAnimated ( subControllers[ i ] ) )
                {
                    Animation animation ( subControllers[ i ], id, sid, parameters + i, Animation::FLOAT, conversionFunctor );
					if ( !forceFullCheck || isAnimated(animation, true) )
					{
						addAnimation ( animation );
						animated = true;
					}
                }
            }
        }
        else if ( isAnimated ( controller ) )
        {
            // Else, with no subs, try and export ourselves as keyframes
            Animation animation ( controller, id, sid, parameters, Animation::FLOAT3, conversionFunctor );
			if ( !forceFullCheck || isAnimated(animation, true) )
			{
				addAnimation ( animation );
				animated = true;
			}
        }
		return animated;
    }


	//---------------------------------------------------------------
	bool AnimationExporter::addAnimatedPoint4 ( Control * controller, const String & id, const String & sid, const String parameters[], bool forceFullCheck, ConversionFunctor* conversionFunctor )
	{
		bool animated = false;

		Control * subControllers[ 4 ] = {controller->GetXController(), controller->GetYController(), controller->GetZController(), controller->GetWController() };

		// First, Try to extract animations from the component controllers

		if ( subControllers[ 0 ] || subControllers[ 1 ]  || subControllers[ 2 ]  || subControllers[ 3 ] )
		{
			for ( int i = 0; i < 4; ++i )
			{
				if ( isAnimated ( subControllers[ i ] ) )
				{
					Animation animation ( subControllers[ i ], id, sid, parameters + i, Animation::FLOAT, conversionFunctor );
					if ( !forceFullCheck || isAnimated(animation, true) )
					{
						addAnimation ( animation );
						animated = true;
					}
				}
			}
		}

		else if ( isAnimated ( controller ) )
		{
			// Else, with no subs, try and export ourselves as keyframes
			Animation animation ( controller, id, sid, parameters, Animation::FLOAT4, conversionFunctor );
			if ( !forceFullCheck || isAnimated(animation, true) )
			{
				addAnimation ( animation );
				animated = true;
			}
		}

		return animated;
	}

	
	//---------------------------------------------------------------
    bool AnimationExporter::addAnimatedAngle ( Control * controller, const String & id, const String & sid, const String parameters[], int animatedAngle, bool forceFullCheck  )
    {
        if ( !isAnimated ( controller ) )
			return false;
        
		// maybe this rotation controller doesn't have XYZ components
		Control * xyzController = NULL;

		switch ( animatedAngle )
		{

		case Animation::ROTATION_X:
			xyzController = controller->GetXController();
			break;

		case Animation::ROTATION_Y:
			xyzController = controller->GetYController();
			break;

		case Animation::ROTATION_Z:
			xyzController = controller->GetZController();
			break;
		}

		if ( xyzController != NULL )
			controller = xyzController;

		Animation animation ( controller, id, sid, parameters, animatedAngle, &ConversionFunctors::radToDeg );

		if ( !forceFullCheck || isAnimated(animation, true) )
		{
			addAnimation ( animation );
			return true;
		}

		return false;
    }


	//---------------------------------------------------------------
	bool AnimationExporter::addAnimatedAxisAngle ( Control * controller, const String & id, const String & sid, const String parameters[], int type, bool forceFullCheck )
	{
		if ( !isAnimated ( controller ) )
			return false;

		Animation animation ( controller, id, sid, parameters, type);
		if ( !forceFullCheck || isAnimated(animation, true) )
		{
			addAnimation ( animation );
			return true;
		}
		return false;
	}


	//---------------------------------------------------------------
	bool AnimationExporter::addAnimatedFloat4x4 ( INode * node, const String & id, const String & sid, const String parameters[], bool forceFullCheck )
	{
		Animation animation ( node, id, sid, parameters, Animation::FLOAT4x4);
	
		if ( !forceFullCheck || isAnimated(animation, true) )
		{
			addAnimation ( animation );
			return true;
		}
	
		return false;
	}


	//---------------------------------------------------------------
	bool AnimationExporter::addAnimatedParameter( IParamBlock * parameterBlock, int parameterId, const String & id, const String & sid, const String parameters[], bool forceFullCheck, ConversionFunctor* conversionFunctor  )
	{
		ParamType type = parameterBlock->GetParameterType(parameterId);
		Control* controller = parameterBlock->GetController(parameterId);

		if ( !isAnimated(controller) )
			return false;

		switch ( type )
		{
		case TYPE_FLOAT:
			return addAnimatedFloat(controller, id, sid, parameters, forceFullCheck, conversionFunctor);
		case TYPE_COLOR:
		case TYPE_RGBA:
			return addAnimatedPoint4(controller, id, sid, parameters, forceFullCheck, conversionFunctor);
		}
		return false;
	}


	//---------------------------------------------------------------
	bool AnimationExporter::addAnimatedParameter( IParamBlock2 * parameterBlock, int parameterId, const String & id, const String & sid, const String parameters[], bool forceFullCheck, ConversionFunctor* conversionFunctor  )
	{
		ParamType2 type = parameterBlock->GetParameterType(parameterId);
		int animationNumber = parameterBlock->GetAnimNum(parameterId);
		if (animationNumber == -1)
			return false;

#ifdef MAX_2012_OR_NEWER
		Control *controller = parameterBlock->GetControllerByIndex(animationNumber);
#else
		Control *controller = parameterBlock->GetController(animationNumber);
#endif

		if ( !isAnimated(controller) )
			return false;

		switch ( type )
		{
		case TYPE_FLOAT:
			return addAnimatedFloat(controller, id, sid, parameters, forceFullCheck, conversionFunctor);
		case TYPE_COLOR:
		case TYPE_RGBA:
			return addAnimatedPoint4(controller, id, sid, parameters, forceFullCheck, conversionFunctor);
		}
		return false;
	}


    /* void AnimationExporter::addAnimation4( Control * controller, const String & id, const String & sid, const String parameters[])
     {
      Control * controllers[4] = {controller->GetXController(), controller->GetYController(), controller->GetZController(), controller->GetWController()};
      for ( int i = 0; i<4; ++i)
      {
       if ( isAnimated(controllers[i]) )
       {
        Animation animation(controllers[i], id, sid, parameters[i]);
        addAnimation(animation);
       }
      }
     }

    */

    //---------------------------------------------------------------
    bool AnimationExporter::isAnimated ( Control * controller )
    {
		return controller && controller->IsAnimated();
    }


	//---------------------------------------------------------------
	bool AnimationExporter::isAnimated ( const Animation& animation, bool forceFullCheck )
	{
		Control* controller = animation.getController();
		INode* iNode = animation.getNode();

		bool animated = isAnimated(controller) || iNode;

		if ( !animated )
			return false;

		if ( forceFullCheck )
			return checkIfIsAnimated(animation);

		return animated;
	}


	bool AnimationExporter::isAnimated( IParamBlock * paramBlock, int parameterId )
	{
		Control* controller = paramBlock->GetController(parameterId);
		return isAnimated(controller);
	}

	bool AnimationExporter::isAnimated( IParamBlock2 * paramBlock, int parameterId )
	{
		
		int animationNumber = paramBlock->GetAnimNum(parameterId);
		if (animationNumber == -1)
			return false;
		//int pi = paramBlock->AnimNumToParamNum(animationNumber, tabIndex);
#ifdef MAX_2012_OR_NEWER
		Control *controller = paramBlock->GetControllerByIndex(animationNumber);
#else
		Control *controller = paramBlock->GetController(animationNumber);
#endif

		return isAnimated(controller);
	}



	/** @TODO implement a test that check if an animations animated, i.e. if the values change */
	//---------------------------------------------------------------
	bool AnimationExporter::checkIfIsAnimated ( const Animation& animation )
	{
		Control * controller = animation.getController();
		INode * iNode = animation.getNode();

		bool isSampling = !controller || mDocumentExporter->getOptions().getSampleAnimation(); 

		IKeyControl * keyInterface = 0;

		if (!isSampling)
		{
			keyInterface = GetKeyControlInterface ( controller );
			if ( !keyInterface ) 
				isSampling = true;
			else if (keyInterface->GetNumKeys() <= 1) 
				return false;
		}

		if ( !isSampling )
		{
			Class_ID classId = controller->ClassID();

			if ( classId.PartB() != 0 )
			{
				// This is not a Max controller, sample it.
				// The only max controllers that have non-zero
				// values are not keyable (attach, link, etc).
				isSampling = true;
			}
			else if ( keyInterface && keyInterface->GetNumKeys() > 0 )
			{
				int keyCount = keyInterface->GetNumKeys();

				switch ( classId.PartA() )
				{

				case LININTERP_FLOAT_CLASS_ID:
					return checkIfIsAnimated ( animation,  keyInterface, &AnimationExporter::getFloatValue<ILinFloatKey> );
					break;

				case LININTERP_POSITION_CLASS_ID:
					if ( animation.getDimension() == 1 )
						return checkIfIsAnimated ( animation, keyInterface, &AnimationExporter::getPointXSingleValue<ILinPoint3Key> );
					else
						return checkIfIsAnimated ( animation, keyInterface, &AnimationExporter::getPointXValue<3, ILinPoint3Key> );

					break;

				case LININTERP_ROTATION_CLASS_ID:
					if ( animation.getDimension() == 1 )
						return checkIfIsAnimated ( animation, keyInterface, &AnimationExporter::getRotationSingleValue<ILinRotKey> );
					else
						return checkIfIsAnimated ( animation, keyInterface, &AnimationExporter::getRotationValue<ILinRotKey> );
					break;

				case HYBRIDINTERP_FLOAT_CLASS_ID:
//					return checkIfIsAnimated ( animation, keyInterface, &AnimationExporter::getFloatValue<IBezFloatKey> );
				case HYBRIDINTERP_POINT3_CLASS_ID:
				case HYBRIDINTERP_POSITION_CLASS_ID: 
				case HYBRIDINTERP_SCALE_CLASS_ID:
				case HYBRIDINTERP_COLOR_CLASS_ID:
/*					if ( animation.getDimension() == 1 )
					{
						return checkIfIsAnimated ( animation, keyInterface, &AnimationExporter::getPointXSingleValue<IBezPoint3Key> );
					}
					else
					{
						return checkIfIsAnimated ( animation, keyInterface, &AnimationExporter::getPointXValue<3, IBezPoint3Key> );
					}*/
				case HYBRIDINTERP_ROTATION_CLASS_ID:
/*					if ( animation.getDimension() == 1 )
					{
						mKeyValueList.reserve( keyInterface->GetNumKeys() );
						return checkIfIsAnimated ( animation, keyInterface, &AnimationExporter::getRotationSingleValuePatchEuler );
					}
					else
					{
						mKeyValueList.reserve( 3 * keyInterface->GetNumKeys() );
						return checkIfIsAnimated ( animation, keyInterface, &AnimationExporter::getRotationValuePatchEuler );
					}
					mKeyValueList.clear();*/
					return true; //For hybrid controllers its more complicated te test if they are constant (in-outtangens)
					break;
				case LININTERP_SCALE_CLASS_ID:
					if ( animation.getType() == Animation::SCALE)
						return checkIfIsAnimated ( animation, keyInterface, &AnimationExporter::getPointXValue<3, IBezScaleKey> );
					else if ( animation.getType() == Animation::SCALE_ROT_AXIS )
						return checkIfIsAnimated ( animation, keyInterface, &AnimationExporter::getScaleRotationAxisValue<IBezScaleKey, false> );
					else if ( animation.getType() == Animation::SCALE_ROT_AXIS_R )
						return checkIfIsAnimated ( animation, keyInterface, &AnimationExporter::getScaleRotationAxisValue<IBezScaleKey, true> );
					break;
				default:
					isSampling = true;
					break;
				}
			}
		}

		if ( isSampling )
		{
			int ticksPerFrame = GetTicksPerFrame();
			TimeValue startTime = mDocumentExporter->getOptions().getAnimationStart();
			TimeValue endTime = mDocumentExporter->getOptions().getAnimationEnd() + 1;

			if ( endTime > startTime )
			{
				if ( controller )
				{
					SClass_ID type = controller->SuperClassID();
					switch (type)
					{
					case CTRL_FLOAT_CLASS_ID:
						return checkIfSampledFloatIsAnimated(animation, keyInterface, startTime, endTime, ticksPerFrame);
						break;
					case CTRL_POINT3_CLASS_ID:
					case CTRL_POSITION_CLASS_ID:
						return checkIfSampledPoint3IsAnimated(animation, keyInterface, startTime, endTime, ticksPerFrame);
						break;
					case CTRL_ROTATION_CLASS_ID:
						return checkIfSampledRotationIsAnimated(animation, keyInterface, startTime, endTime, ticksPerFrame);
						break;
					}
				}
				else if ( animation.getNode() )
				{
					return checkIfSampledTransformationIsAnimated(animation, keyInterface, startTime, endTime, ticksPerFrame);
				}
			}

		}

		return false;
	}


	//---------------------------------------------------------------
	bool AnimationExporter::checkIfIsAnimated ( const Animation & animation, IKeyControl* keyInterface, OutputValueFunctionPtr outputValueFunction )
	{
		int keyCount = keyInterface->GetNumKeys();
		int keyLength = animation.getDimension();

		ConversionFunctorType conversionFunctor = animation.getConversionFunctor();

		bool animated = false;

		float * firstKeyBuffer = new float[ keyLength ];

		float * keyBuffer = new float[ keyLength ];

		for ( int i = 0; i < keyCount && !animated; ++i )
		{
			(this->*outputValueFunction) ( keyBuffer, keyInterface, i, animation );

			for ( int j = 0; j < keyLength && !animated; ++j )
			{
				if ( conversionFunctor )
					keyBuffer[j] = (*conversionFunctor) ( keyBuffer[ j ] );

				if ( i == 0 )
					std::swap(firstKeyBuffer, keyBuffer);
				else if ( !COLLADASW::MathUtils::equals(keyBuffer[j], firstKeyBuffer[j]) )
					animated = true;
			}
		}

		delete[] keyBuffer;
		delete[] firstKeyBuffer;
	
		return animated;
	}


	//---------------------------------------------------------------
	bool AnimationExporter::checkIfSampledFloatIsAnimated ( const Animation & animation, IKeyControl* keyInterface, TimeValue startTime, TimeValue endTime, int ticksPerFrame )
	{
		int keyCount = (endTime - startTime) / ticksPerFrame + 1;

		if ( keyCount < 2 )
			return false;

		ConversionFunctorType conversionFunctor = animation.getConversionFunctor();

		float firstKeyValue;

		for (TimeValue time = startTime; time < endTime; time += ticksPerFrame)
		{
			float keyValue;
			animation.getController()->GetValue(time, &keyValue, FOREVER, CTRL_ABSOLUTE);

			if ( conversionFunctor )
				keyValue = (*conversionFunctor)(keyValue);

			if ( time == startTime )
				firstKeyValue = keyValue;
			else if ( !COLLADASW::MathUtils::equals(keyValue, firstKeyValue) )
				return true;
		}
		return false;
	}

	//---------------------------------------------------------------
	bool AnimationExporter::checkIfSampledPoint3IsAnimated ( const Animation & animation, IKeyControl* keyInterface, TimeValue startTime, TimeValue endTime, int ticksPerFrame )
	{
		int keyCount = (endTime - startTime) / ticksPerFrame + 1;

		if ( keyCount < 2 )
			return false;

		int keyLength = animation.getDimension();

		ConversionFunctorType conversionFunctor = animation.getConversionFunctor();

		float firstFloatKeyValue;
		Point3 firstKeyValue;

		for (TimeValue time = startTime; time < endTime; time += ticksPerFrame)
		{

			Point3 keyValue;
			animation.getController()->GetValue(time, &keyValue, FOREVER, CTRL_ABSOLUTE);


			if ( keyLength == 1)
			{
				float floatKeyValue = keyValue[ animation.getType() - Animation::POSITION_X ];

				if ( conversionFunctor )
					floatKeyValue = (*conversionFunctor)( floatKeyValue );

				if ( time == startTime )
					firstFloatKeyValue = floatKeyValue;
				else if ( !COLLADASW::MathUtils::equals(floatKeyValue, firstFloatKeyValue) )
					return true;

			}
			else
			{
				for ( int j = 0; j < keyLength; ++j )
				{
					assert( (keyLength == 3) || (keyLength == 4));

					if ( conversionFunctor )
						keyValue[j] = (*conversionFunctor) ( keyValue[ j ] );

					if ( time > startTime && !COLLADASW::MathUtils::equals(keyValue[j], firstKeyValue[j]) )
						return true;
				}

				if ( time == startTime )
					firstKeyValue = keyValue;
			}
		}
		return false;
	}


	//---------------------------------------------------------------
	bool AnimationExporter::checkIfSampledRotationIsAnimated ( const Animation & animation, IKeyControl* keyInterface, TimeValue startTime, TimeValue endTime, int ticksPerFrame )
	{
		int keyCount = (endTime - startTime) / ticksPerFrame + 1;
		int keyLength = animation.getDimension();

		if ( keyCount < 2 )
			return false;

		ConversionFunctorType conversionFunctor = animation.getConversionFunctor();

		float firstFloatKeyValue;
		float firstEulerAngles[ 3 ];

		for (TimeValue time = startTime; time < endTime; time += ticksPerFrame)
		{

			float eulerAngles[ 3 ];

			if ( keyLength == 1 )
			{
				Quat quaternion;
				animation.getController()->GetValue(time, &quaternion, FOREVER, CTRL_ABSOLUTE);
				QuatToEuler(quaternion, eulerAngles, EULERTYPE_XYZ);
			}
			else
			{
				AngAxis angleAxis;
				animation.getController()->GetValue(time, &angleAxis, FOREVER, CTRL_ABSOLUTE);
				Quat quaternion(angleAxis);
				quaternion.GetEuler ( &eulerAngles[ 0 ], &eulerAngles[ 1 ], &eulerAngles[ 2 ] );
			}

			if ( time > startTime)
				patchEuler(mPreviousEulerAngles, eulerAngles);

			mPreviousEulerAngles[0] = eulerAngles[0];
			mPreviousEulerAngles[1] = eulerAngles[1];
			mPreviousEulerAngles[2] = eulerAngles[2];

			if ( keyLength == 1)
			{
				float floatKeyValue = eulerAngles[ animation.getType() - Animation::ROTATION_X ];

				if ( conversionFunctor )
					floatKeyValue = (*conversionFunctor)(floatKeyValue);

				if ( time == startTime )
					firstFloatKeyValue = floatKeyValue;
				else if ( !COLLADASW::MathUtils::equals(floatKeyValue, firstFloatKeyValue) )
					return true;
			}
			else
			{
				for ( int j = 0; j < 3; ++j )
				{
					if ( conversionFunctor )
						eulerAngles[j] = (*conversionFunctor) ( eulerAngles[ j ] );

					if ( time == startTime )
						firstEulerAngles[j] = eulerAngles[j];
					else if ( !COLLADASW::MathUtils::equals(eulerAngles[j], firstEulerAngles[j]) )
						return true;
				}
			}
		}
		return false;
	}



	bool AnimationExporter::checkIfSampledTransformationIsAnimated( const Animation & animation, IKeyControl* keyInterface, TimeValue startTime, TimeValue endTime, int ticksPerFrame )
	{
		int keyCount = (endTime - startTime) / ticksPerFrame + 1;
		int keyLength = animation.getDimension();

		if ( keyCount < 2 )
			return false;

		INode * iNode = animation.getNode();

		Matrix3 transformationMatrix;
		Matrix3 firstTransformationMatrix;
		Matrix3 parentTransformationMatrix;
		
		INode* parentINode = iNode->GetParentNode();

		if (parentINode && parentINode->IsRootNode()) 
			parentINode = 0;

		for (TimeValue time = startTime; time < endTime; time += ticksPerFrame)
		{
			// Export the base NODE TM
			transformationMatrix = iNode->GetNodeTM(time);

			if (parentINode)
			{
				// export a relative TM
				// We have to use whatever value we exported for this parent
				// in order to remain consistent in collada
				parentTransformationMatrix = parentINode->GetNodeTM(time);
				parentTransformationMatrix.Invert();
				transformationMatrix = transformationMatrix * parentTransformationMatrix;
			}

			const Matrix3& constTransformationMatrix = transformationMatrix;

			if ( time == startTime )
			{
				firstTransformationMatrix = transformationMatrix;
			}
			else
			{
				const Matrix3& constTransformationMatrix = transformationMatrix;
				const Matrix3& constFirstTransformationMatrix = firstTransformationMatrix;

				for ( int row = 0; row < 3; ++row)
					for ( int col = 0; col < 4; ++col)
						if ( !COLLADASW::MathUtils::equals(constTransformationMatrix[col][row], constFirstTransformationMatrix[col][row] ) )
							return true;
			}

		}

		return false;
	}



    //---------------------------------------------------------------
    String AnimationExporter::getBaseId ( const Animation & animation )
    {

		String baseId = animation.getId();

		const String& sid = animation.getSid();

		if ( !sid.empty() )
			baseId += "_" + animation.getSid();


		if ( animation.getMatrixIndex() < 0)
		{
			if ( (animation.getDimension() == 1) && (animation.getParameter()) )
				baseId += "." + * ( animation.getParameter() );
		}
		else
		{
			baseId += "_" + COLLADASW::Utils::toString(animation.getMatrixIndex()) + "_";
		}
		return baseId;
    }

    //---------------------------------------------------------------
    String AnimationExporter::getTarget ( const Animation & animation )
    {
		String target = animation.getId();

		const String& sid = animation.getSid();

		if ( !sid.empty() )
			target += "/" + animation.getSid();


		if ( animation.getMatrixIndex() < 0)
		{
			if ( (animation.getDimension() == 1) && (animation.getParameter()) )
				target += "." + * ( animation.getParameter() );
		}
		else
		{
			target += "(" + COLLADASW::Utils::toString(animation.getMatrixIndex()) + ")";
		}
		return target;
    }

    //---------------------------------------------------------------
    void AnimationExporter::exportSources ( Animation & animation )
    {
		Control * controller = animation.getController();
		INode * iNode = animation.getNode();

		bool isSampling = !controller || mDocumentExporter->getOptions().getSampleAnimation(); 

        String baseId = getBaseId ( animation );

		IKeyControl * keyInterface = 0;

		if (!isSampling)
		{
			keyInterface = GetKeyControlInterface ( controller );
			if ( !keyInterface ) 
				isSampling = true;
			else if (keyInterface->GetNumKeys() <= 1) 
				return;
		}


		if ( !isSampling )
        {
            Class_ID classId = controller->ClassID();

            if ( classId.PartB() != 0 )
            {
                // This is not a Max controller, sample it.
                // The only max controllers that have non-zero
                // values are not keyable (attach, link, etc).
                isSampling = true;
            }
            else if ( keyInterface != NULL && keyInterface->GetNumKeys() > 0 )
            {
                int keyCount = keyInterface->GetNumKeys();

                switch ( classId.PartA() )
                {

                case LININTERP_FLOAT_CLASS_ID:
                    exportInputSource<ILinFloatKey> ( baseId, controller, keyInterface );
                    exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getFloatValue<ILinFloatKey> );
                    exportInterpolationSource ( baseId, keyInterface, getUniformInterpolation<LibraryAnimations::LINEAR_NAME>, keyInterface->GetNumKeys() );
					animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::INTERPOLATION);
                    break;

                case LININTERP_POSITION_CLASS_ID:
                    exportInputSource<ILinPoint3Key> ( baseId, controller, keyInterface );

                    if ( animation.getDimension() == 1 )
                        exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXSingleValue<ILinPoint3Key> );
                    else
                        exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXValue<3, ILinPoint3Key> );

                    exportInterpolationSource ( baseId, keyInterface, getUniformInterpolation<LibraryAnimations::LINEAR_NAME>, keyInterface->GetNumKeys() );
					animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::INTERPOLATION);
                    break;

                case LININTERP_ROTATION_CLASS_ID:
                    exportInputSource<ILinRotKey> ( baseId, controller, keyInterface );

                    if ( animation.getDimension() == 1 )
                        exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getRotationSingleValue<ILinRotKey> );
                    else
                        exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getRotationValue<ILinRotKey> );

                    exportInterpolationSource ( baseId, keyInterface, getUniformInterpolation<LibraryAnimations::LINEAR_NAME>, keyInterface->GetNumKeys() );
					animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::INTERPOLATION);
                    break;
				case LININTERP_SCALE_CLASS_ID:
					exportInputSource<ILinScaleKey> ( baseId, controller, keyInterface );
					if ( animation.getType() == Animation::SCALE)
						exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXValue<3, ILinScaleKey> );
					else if ( animation.getType() == Animation::SCALE_ROT_AXIS )
						exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getScaleRotationAxisValue<ILinScaleKey, false> );
					else if ( animation.getType() == Animation::SCALE_ROT_AXIS_R )
						exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getScaleRotationAxisValue<ILinScaleKey, true> );
					exportInterpolationSource ( baseId, keyInterface, getUniformInterpolation<LibraryAnimations::LINEAR_NAME>, keyInterface->GetNumKeys() );
					animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::INTERPOLATION);
					break;
                case HYBRIDINTERP_FLOAT_CLASS_ID:
                    exportInputSource<IBezFloatKey> ( baseId, controller, keyInterface );

                    exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getFloatValue<IBezFloatKey> );

                    exportInTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getFloatInTangentValue );

                    exportOutTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getFloatOutTangentValue );

                    exportInterpolationSource ( baseId, keyInterface, getBezierInterpolation<IBezFloatKey>, keyInterface->GetNumKeys() );
					animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::IN_TANGENT | Animation::OUT_TANGENT | Animation::INTERPOLATION);

                    break;
				case HYBRIDINTERP_POINT3_CLASS_ID:
				case HYBRIDINTERP_POSITION_CLASS_ID: 
				case HYBRIDINTERP_COLOR_CLASS_ID:
					exportInputSource<IBezPoint3Key> ( baseId, controller, keyInterface );
					if ( animation.getDimension() == 1 )
					{
						exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXSingleValue<IBezPoint3Key> );
						exportInTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXSingleInTangentValue<IBezPoint3Key>);
						exportOutTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXSingleOutTangentValue<IBezPoint3Key> );
					}
					else
					{
						exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXValue<3, IBezPoint3Key> );
						exportInTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXInTangentValue<3, IBezPoint3Key> );
						exportOutTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXOutTangentValue<3, IBezPoint3Key> );
					}
					exportInterpolationSource ( baseId, keyInterface, getBezierInterpolation<IBezPoint3Key>, keyInterface->GetNumKeys() );
					animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::IN_TANGENT | Animation::OUT_TANGENT | Animation::INTERPOLATION);
					break;
				case HYBRIDINTERP_POINT4_CLASS_ID:
				case HYBRIDINTERP_FRGBA_CLASS_ID:
					exportInputSource<IBezPoint4Key> ( baseId, controller, keyInterface );
					if ( animation.getDimension() == 1 )
					{
						exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXSingleValue<IBezPoint4Key> );
						exportInTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXSingleInTangentValue<IBezPoint4Key> );
						exportOutTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXSingleOutTangentValue<IBezPoint4Key> );
					}
					else
					{
						exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXValue<4, IBezPoint4Key> );
						exportInTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXInTangentValue<4, IBezPoint4Key> );
						exportOutTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXOutTangentValue<4, IBezPoint4Key> );
					}
					exportInterpolationSource ( baseId, keyInterface, getBezierInterpolation<IBezPoint4Key>, keyInterface->GetNumKeys() );
					animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::IN_TANGENT | Animation::OUT_TANGENT | Animation::INTERPOLATION);
					break;

				case HYBRIDINTERP_ROTATION_CLASS_ID:
					exportInputSource<IBezQuatKey> ( baseId, controller, keyInterface );
					if ( animation.getDimension() == 1 )
					{
						mKeyValueList.reserve( keyInterface->GetNumKeys() );
						exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getRotationSingleValuePatchEuler );
						exportInTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getRotationSingleInTangentPatchEuler );
						exportOutTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getRotationSingleOutTangentPatchEuler );
					}
					else
					{
						mKeyValueList.reserve( 3 * keyInterface->GetNumKeys() );
						exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getRotationValuePatchEuler );
						exportInTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getRotationSingleInTangentPatchEuler );
						exportOutTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getRotationSingleOutTangentPatchEuler );
					}
					mKeyValueList.clear();
					exportInterpolationSource ( baseId, keyInterface, getBezierInterpolation<IBezQuatKey>, keyInterface->GetNumKeys() );
					animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::IN_TANGENT | Animation::OUT_TANGENT | Animation::INTERPOLATION);
					break;
				case HYBRIDINTERP_SCALE_CLASS_ID:
					exportInputSource<IBezScaleKey> ( baseId, controller, keyInterface );
					if ( animation.getType() == Animation::SCALE)
					{
						exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXValue<3, IBezScaleKey> );
						exportInTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXInTangentValue<3, IBezScaleKey> );
						exportOutTangentSource ( animation, baseId, keyInterface, &AnimationExporter::getPointXOutTangentValue<3, IBezScaleKey> );
						exportInterpolationSource ( baseId, keyInterface, getBezierInterpolation<IBezScaleKey>, keyInterface->GetNumKeys() );
						animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::IN_TANGENT | Animation::OUT_TANGENT | Animation::INTERPOLATION);
					}
					else if ( animation.getType() == Animation::SCALE_ROT_AXIS )
					{
						exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getScaleRotationAxisValue<IBezScaleKey, false> );
						exportInterpolationSource ( baseId, keyInterface, getUniformInterpolation<LibraryAnimations::LINEAR_NAME>, keyInterface->GetNumKeys() );
						animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::INTERPOLATION);
					}
					else if ( animation.getType() == Animation::SCALE_ROT_AXIS_R )
					{
						exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getScaleRotationAxisValue<IBezScaleKey, true> );
						exportInterpolationSource ( baseId, keyInterface, getUniformInterpolation<LibraryAnimations::LINEAR_NAME>, keyInterface->GetNumKeys() );
						animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::INTERPOLATION);
					}
					break;

//				case TCBINTERP_FLOAT_CLASS_ID:
//					exportInputSource<ITCBFloatKey> ( baseId, controller, keyInterface );
//					exportOutputSource ( animation, baseId, keyInterface, &AnimationExporter::getFloatValue<ITCBFloatKey> );

					break;
				default:
					isSampling = true;
					break;
                }
            }
        }

		if ( isSampling )
		{
			int ticksPerFrame = GetTicksPerFrame();
			TimeValue startTime = mDocumentExporter->getOptions().getAnimationStart();
			TimeValue endTime = mDocumentExporter->getOptions().getAnimationEnd() + 1;

			if ( endTime > startTime )
			{
				exportSamplingInputSource(baseId, startTime, endTime, ticksPerFrame);
				if ( controller )
				{
					SClass_ID type = controller->SuperClassID();
					switch (type)
					{
					case CTRL_FLOAT_CLASS_ID:
						exportSamplingFloatOutputSource(animation, baseId, keyInterface, startTime, endTime, ticksPerFrame);
						animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::INTERPOLATION);
						break;
					case CTRL_POINT3_CLASS_ID:
					case CTRL_POSITION_CLASS_ID:
						exportSamplingPoint3OutputSource(animation, baseId, keyInterface, startTime, endTime, ticksPerFrame);
						animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::INTERPOLATION);
						break;
					case CTRL_ROTATION_CLASS_ID:
						exportSamplingRotationOutputSource(animation, baseId, keyInterface, startTime, endTime, ticksPerFrame);
						animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::INTERPOLATION);
						break;
					}
				}
				else if ( iNode )
				{
					exportSamplingTransformationOutputSource(animation, baseId, keyInterface, startTime, endTime, ticksPerFrame);
					animation.setInputTypeFlags(Animation::INPUT | Animation::OUTPUT | Animation::INTERPOLATION);
				}
				exportSamplingInterpolationSource(baseId, startTime, endTime, ticksPerFrame);
			}

		}
    }


    //---------------------------------------------------------------
    template <class KeyClassName>
    void AnimationExporter::exportInputSource ( const String & baseId, Control * controller, IKeyControl* keyInterface )
    {
        int keyCount = keyInterface->GetNumKeys();

        COLLADASW::FloatSource source ( mSW );
        source.setId ( baseId + INPUT_SOURCE_ID_SUFFIX );
        source.setArrayId ( baseId + INPUT_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        source.setAccessorStride ( 1 );
        source.getParameterNameList().push_back ( "TIME" );
        source.setAccessorCount ( keyCount );
        source.prepareToAppendValues();

        for ( int i = 0; i < keyCount; ++i )
        {
            KeyClassName key;
            keyInterface->GetKey ( i, &key );
            source.appendValues ( key.time * mTimeFactor );
        }

        source.finish();
    }


    //---------------------------------------------------------------
    void AnimationExporter::exportOutputSource ( const Animation & animation, const String & baseId, IKeyControl* keyInterface, OutputValueFunctionPtr outputValueFunction )
    {
        int keyCount = keyInterface->GetNumKeys();
        int keyLength = animation.getDimension();

        COLLADASW::FloatSource source ( mSW );
        source.setId ( baseId + OUTPUT_SOURCE_ID_SUFFIX );
        source.setArrayId ( baseId + OUTPUT_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        source.setAccessorStride ( keyLength );

        for ( int i = 0; i < keyLength; ++i )
		{
			if ( animation.getParameter() ) 
				source.getParameterNameList().push_back ( * ( animation.getParameter() + i) );
			else
				source.getParameterNameList().push_back ( EMPTY_STRING );
		}

        source.setAccessorCount ( keyCount );

        source.prepareToAppendValues();

        float * keyBuffer = new float[ keyLength ];

        for ( int i = 0; i < keyCount; ++i )
        {
            (this->*outputValueFunction) ( keyBuffer, keyInterface, i, animation );

            for ( int j = 0; j < keyLength; ++j )
            {
                ConversionFunctorType conversionFunctor = animation.getConversionFunctor();

                if ( conversionFunctor )
                    source.appendValues ( (*conversionFunctor) ( keyBuffer[ j ] ) );
                else
                    source.appendValues ( keyBuffer[ j ] );
            }
        }

        delete[] keyBuffer;

        source.finish();
    }

    //---------------------------------------------------------------
	template <class KeyType>
    void AnimationExporter::getFloatValue ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation )
    {
        KeyType key;
        keyInterface->GetKey ( keyIndex, &key );
        *keyValues = key.val;
    }

    //---------------------------------------------------------------
	template<class KeyType>
    void AnimationExporter::getPointXSingleValue ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation )
    {
        KeyType key;
        keyInterface->GetKey ( keyIndex, &key );
        *keyValues = key.val[ animation.getType() - Animation::POSITION_X ];
    }

    //---------------------------------------------------------------
	template<int dimension, class KeyType>
    void AnimationExporter::getPointXValue ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation )
    {
        KeyType key;
        keyInterface->GetKey ( keyIndex, &key );
		for ( int i = 0; i<dimension; ++i)
			keyValues[ i ] = key.val[ i ];
    }

    //---------------------------------------------------------------
	template<class KeyType>
    void AnimationExporter::getRotationSingleValue ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation )
    {
        KeyType key;
        keyInterface->GetKey ( keyIndex, &key );
        float eulerAngles[ 3 ];
        key.val.GetEuler ( &eulerAngles[ 0 ], &eulerAngles[ 1 ], &eulerAngles[ 2 ] );
        *keyValues = eulerAngles[ animation.getType() - Animation::ROTATION_X ];
    }

    //---------------------------------------------------------------
	template<class KeyType>
    void AnimationExporter::getRotationValue ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation )
    {
        KeyType key;
        keyInterface->GetKey ( keyIndex, &key );
        key.val.GetEuler ( &keyValues[ 0 ], &keyValues[ 1 ], &keyValues[ 2 ] );
    }


	//---------------------------------------------------------------
	void AnimationExporter::getRotationSingleValuePatchEuler ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation )
	{
		IBezQuatKey key;
		keyInterface->GetKey ( keyIndex, &key );
		float eulerAngles[ 3 ];
		key.val.GetEuler ( &eulerAngles[ 0 ], &eulerAngles[ 1 ], &eulerAngles[ 2 ] );
		if ( keyIndex > 0)
			patchEuler(mPreviousEulerAngles, eulerAngles);

		mPreviousEulerAngles[0] = eulerAngles[0];
		mPreviousEulerAngles[1] = eulerAngles[1];
		mPreviousEulerAngles[2] = eulerAngles[2];

		*keyValues = eulerAngles[ animation.getType() - Animation::ROTATION_X ];
		
		ConversionFunctorType conversionFunctor = animation.getConversionFunctor();
		if ( conversionFunctor )
			mKeyValueList.push_back((float)((*conversionFunctor)(*keyValues)));
		else
			mKeyValueList.push_back((float)(*keyValues));

	}

	//---------------------------------------------------------------
	void AnimationExporter::getRotationValuePatchEuler ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation )
	{
		IBezQuatKey key;
		keyInterface->GetKey ( keyIndex, &key );
		float eulerAngles[ 3 ];
		key.val.GetEuler ( &eulerAngles[ 0 ], &eulerAngles[ 1 ], &eulerAngles[ 2 ] );
		if ( keyIndex > 0)
			patchEuler(mPreviousEulerAngles, eulerAngles);

		mPreviousEulerAngles[0] = eulerAngles[0];
		mPreviousEulerAngles[1] = eulerAngles[1];
		mPreviousEulerAngles[2] = eulerAngles[2];

		keyValues[ 0 ] = eulerAngles[0];
		keyValues[ 1 ] = eulerAngles[1];
		keyValues[ 2 ] = eulerAngles[2];

		ConversionFunctorType conversionFunctor = animation.getConversionFunctor();
		if ( conversionFunctor )
		{
			mKeyValueList.push_back((float)((*conversionFunctor)(eulerAngles[0])));
			mKeyValueList.push_back((float)((*conversionFunctor)(eulerAngles[1])));
			mKeyValueList.push_back((float)((*conversionFunctor)(eulerAngles[2])));
		}
		else
		{
			mKeyValueList.push_back(eulerAngles[0]);
			mKeyValueList.push_back(eulerAngles[1]);
			mKeyValueList.push_back(eulerAngles[2]);
		}
	}


	//---------------------------------------------------------------
	template<class KeyType, bool reversed>
	void AnimationExporter::getScaleRotationAxisValue( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation )
	{
		KeyType key;
		keyInterface->GetKey ( keyIndex, &key );
		AngAxis angleAxis(key.val.q);

		keyValues[0] = angleAxis.axis.x;
		keyValues[1] = angleAxis.axis.y;
		keyValues[2] = angleAxis.axis.z;
		if ( reversed )
			keyValues[3] = -COLLADASW::MathUtils::radToDegF(angleAxis.angle);
		else
			keyValues[3] = COLLADASW::MathUtils::radToDegF(angleAxis.angle);
	}

	
	//---------------------------------------------------------------
    void AnimationExporter::exportTangentSource ( const String & sourceIdSuffix, const Animation & animation, const String & baseId, IKeyControl* keyInterface, TangentValueFunctionPtr tangentValueFunction )
    {
        int keyCount = keyInterface->GetNumKeys();
		int keyLength = animation.getDimension();

        COLLADASW::FloatSource source ( mSW );
        source.setId ( baseId + sourceIdSuffix );
        source.setArrayId ( baseId + sourceIdSuffix + ARRAY_ID_SUFFIX );
        source.setAccessorStride ( 2 * keyLength );
		for ( int i = 0; i < keyLength; ++i )
		{
			source.getParameterNameList().push_back ( "X" );
			source.getParameterNameList().push_back ( "Y" );
		}
        source.setAccessorCount ( keyCount );
        source.prepareToAppendValues();

		float * keyBufferX = new float[ keyLength ];
		float * keyBufferY = new float[ keyLength ];

		ConversionFunctorType conversionFunctor = animation.getConversionFunctor();

        for ( int i = 0; i < keyCount; ++i )
        {
            ( this->*tangentValueFunction ) ( keyBufferX, keyBufferY, keyInterface, i, keyCount, animation );
			for ( int j = 0; j < keyLength; ++j )
			{
				if ( conversionFunctor )
					source.appendValues ( keyBufferX[j], (*conversionFunctor)(keyBufferY[j]) );
				else
					source.appendValues ( keyBufferX[j], keyBufferY[j] );
			}
        }

		delete[] keyBufferX;
		delete[] keyBufferY;

        source.finish();
    }

    //---------------------------------------------------------------
    void AnimationExporter::exportInTangentSource ( const Animation & animation, const String & baseId, IKeyControl* keyInterface, TangentValueFunctionPtr tangentValueFunction )
    {
        exportTangentSource ( INTANGENT_SOURCE_ID_SUFFIX, animation, baseId, keyInterface, tangentValueFunction );
    }

    //---------------------------------------------------------------
    void AnimationExporter::getFloatInTangentValue ( float * inTangentValuesX, float * inTangentValuesY, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation )
    {
        IBezFloatKey key;
        keyInterface->GetKey ( keyIndex, &key );

        float previousTime = ( float ) getPreviousTime ( keyIndex, animation.getController() );

        //testing
        /*        bool b1 = key.flags & BEZKEY_UNCONSTRAINHANDLE;
                bool b2 = GetInTanType( key.flags ) != BEZKEY_USER;
                bool b3 = GetOutTanType( key.flags ) != BEZKEY_USER;
                bool b4 = GetOutTanType( key.flags ) == BEZKEY_LINEAR;
                bool b5 = GetOutTanType( key.flags ) == BEZKEY_STEP;
        */
        InterpolationType interpolationInType = getInterpolationInType ( key.flags );

        // export control point. If it is not a BEZIER interpolation, export the point itself

        if ( interpolationInType == BEZIER )
        {
            if ( GetInTanType ( key.flags ) != BEZKEY_USER )
                key.inLength = DEFAULT_INLENGHT_FLOAT;
            else if ( key.flags & BEZKEY_UNCONSTRAINHANDLE )
                key.inLength *= GetTicksPerFrame() / ( float ) ( key.time - previousTime );

            float inInterval = ( key.time - previousTime ) * key.inLength;

            *inTangentValuesX = ( key.time - inInterval ) * mTimeFactor;

            *inTangentValuesY = key.val + key.intan * inInterval;
        }
		else if ( interpolationInType == LINEAR )
		{
			*inTangentValuesX = (key.time - ( key.time - previousTime )/3) * mTimeFactor;
			// get the previous key value
			int numKeys = keyInterface->GetNumKeys();
			int previousKeyIndex = ( keyIndex > 0 ) ? keyIndex - 1 : numKeys - 1;
			IBezFloatKey previousKey;
			keyInterface->GetKey ( previousKeyIndex, &previousKey );
			*inTangentValuesY = (key.val - ( key.val - previousKey.val )/3);
		}
        else
        {
            /// @TODO: clarify if this makes sense or if we should export the same as above
            *inTangentValuesX = key.time * mTimeFactor;
            *inTangentValuesY = key.val;
        }
    }


	//---------------------------------------------------------------
	template <class KeyType>
	void AnimationExporter::getPointXSingleInTangentValue ( float * inTangentValuesX, float * inTangentValuesY, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation )
	{
		KeyType key;
		keyInterface->GetKey ( keyIndex, &key );

		float previousTime = ( float ) getPreviousTime ( keyIndex, animation.getController() );

		//testing
		/*        bool b1 = key.flags & BEZKEY_UNCONSTRAINHANDLE;
		bool b2 = GetInTanType( key.flags ) != BEZKEY_USER;
		bool b3 = GetOutTanType( key.flags ) != BEZKEY_USER;
		bool b4 = GetOutTanType( key.flags ) == BEZKEY_LINEAR;
		bool b5 = GetOutTanType( key.flags ) == BEZKEY_STEP;
		*/
		InterpolationType interpolationInType = getInterpolationInType ( key.flags );

		int keyParamterIndex = animation.getType() - Animation::POSITION_X;

		// export control point. If it is not a BEZIER interpolation, export the point itself

		if ( interpolationInType == BEZIER )
		{
			if ( GetInTanType ( key.flags ) != BEZKEY_USER )
				key.inLength = DEFAULT_INLENGHT_POINTX_FLOAT_ARRAY;
			else if ( key.flags & BEZKEY_UNCONSTRAINHANDLE )
				key.inLength *= GetTicksPerFrame() / ( float ) ( key.time - previousTime );

			float inInterval = ( key.time - previousTime ) * key.inLength[keyParamterIndex];
			*inTangentValuesX = ( key.time - inInterval ) * mTimeFactor;
			*inTangentValuesY = key.val[keyParamterIndex] + key.intan[keyParamterIndex] * inInterval;
		}
		else if ( interpolationInType == LINEAR )
		{
			*inTangentValuesX = (key.time - ( key.time - previousTime )/3) * mTimeFactor;
			// get the previous key value
			int numKeys = keyInterface->GetNumKeys();
			int previousKeyIndex = ( keyIndex > 0 ) ? keyIndex - 1 : numKeys - 1;
			KeyType previousKey;
			keyInterface->GetKey( previousKeyIndex, &previousKey );
			*inTangentValuesY = (key.val[keyParamterIndex] - ( key.val[keyParamterIndex] - previousKey.val[keyParamterIndex] )/3);
		}
		else
		{
			/// @TODO: clarify if this makes sense or if we should export the same as above
			*inTangentValuesX = key.time * mTimeFactor;
			*inTangentValuesY = key.val[keyParamterIndex];
		}
	}


	//---------------------------------------------------------------
	template <int dimension, class KeyType>
	void AnimationExporter::getPointXInTangentValue ( float * inTangentValuesX, float * inTangentValuesY, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation )
	{
		KeyType key;
		keyInterface->GetKey ( keyIndex, &key );

		float previousTime = ( float ) getPreviousTime ( keyIndex, animation.getController() );

		//testing
		/*        bool b1 = key.flags & BEZKEY_UNCONSTRAINHANDLE;
		bool b2 = GetInTanType( key.flags ) != BEZKEY_USER;
		bool b3 = GetOutTanType( key.flags ) != BEZKEY_USER;
		bool b4 = GetOutTanType( key.flags ) == BEZKEY_LINEAR;
		bool b5 = GetOutTanType( key.flags ) == BEZKEY_STEP;
		*/
		InterpolationType interpolationInType = getInterpolationInType ( key.flags );

		// export control point. If it is not a BEZIER interpolation, export the point itself

		if ( interpolationInType == BEZIER )
		{
			if ( GetInTanType ( key.flags ) != BEZKEY_USER )
				key.inLength = DEFAULT_INLENGHT_POINTX_FLOAT_ARRAY;
			else if ( key.flags & BEZKEY_UNCONSTRAINHANDLE )
				key.inLength *= GetTicksPerFrame() / ( float ) ( key.time - previousTime );

			float inInterval;
			
			for ( int i = 0; i<dimension; ++i)
			{
				inInterval = ( key.time - previousTime ) * key.inLength[i];
				inTangentValuesX[i] = ( key.time - inInterval ) * mTimeFactor;
				inTangentValuesY[i] = key.val[i] + key.intan[i] * inInterval;
			}

		}
		else if ( interpolationInType == LINEAR )
		{
			float inTangentX = (key.time - ( key.time - previousTime )/3) * mTimeFactor;

			// get the previous key value
			int numKeys = keyInterface->GetNumKeys();
			int previousKeyIndex = ( keyIndex > 0 ) ? keyIndex - 1 : numKeys - 1;
			KeyType previousKey;
			keyInterface->GetKey ( previousKeyIndex, &previousKey );

			for ( int i = 0; i<dimension; ++i)
			{
				inTangentValuesX[i] = inTangentX;
				inTangentValuesY[i] = (key.val[i] - ( key.val[i] - previousKey.val[i] )/3);
			}
		}
		else
		{
			/// @TODO: clarify if this makes sense or if we should export the same as above
			for ( int i = 0; i<dimension; ++i)
			{
				inTangentValuesX[i] = key.time * mTimeFactor;
				inTangentValuesY[i] = key.val[i];
			}
		}
	}


	//---------------------------------------------------------------
	void AnimationExporter::getRotationSingleInTangentPatchEuler ( float * inTangentValuesX, float * inTangentValuesY, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation )
	{
		IBezQuatKey key;
		keyInterface->GetKey ( keyIndex, &key );

		float previousTime = ( float ) getPreviousTime ( keyIndex, animation.getController() );

		//testing
		/*        bool b1 = key.flags & BEZKEY_UNCONSTRAINHANDLE;
		bool b2 = GetInTanType( key.flags ) != BEZKEY_USER;
		bool b3 = GetOutTanType( key.flags ) != BEZKEY_USER;
		bool b4 = GetOutTanType( key.flags ) == BEZKEY_LINEAR;
		bool b5 = GetOutTanType( key.flags ) == BEZKEY_STEP;
		*/
		InterpolationType interpolationInType = getInterpolationInType ( key.flags );

		int keyParamterIndex = animation.getType() - Animation::ROTATION_X;


		// export control point. If it is not a BEZIER interpolation, export the point itself

		size_t keyValueIndex = keyIndex;

		if ( interpolationInType == BEZIER )
		{
			float inInterval = ( key.time - previousTime ) * DEFAULT_INLENGHT;
			*inTangentValuesX = ( key.time - inInterval ) * mTimeFactor;
			*inTangentValuesY = mKeyValueList[keyValueIndex];
		}
		else if ( interpolationInType == LINEAR )
		{
			*inTangentValuesX = (key.time - ( key.time - previousTime )/3) * mTimeFactor;
			// get the previous key value
			size_t numKeys = mKeyValueList.size();
			size_t previousKeyIndex = ( keyValueIndex > 0 ) ? keyValueIndex - 1 : numKeys - 1;
			*inTangentValuesY = (mKeyValueList[keyValueIndex] - ( mKeyValueList[keyValueIndex] - mKeyValueList[previousKeyIndex] )/3);
		}
		else
		{
			/// @TODO: clarify if this makes sense or if we should export the same as above
			*inTangentValuesX = key.time * mTimeFactor;

			*inTangentValuesY = mKeyValueList[keyValueIndex];
		}
	}


	//---------------------------------------------------------------
		void AnimationExporter::getRotationInTangentPatchEuler ( float * inTangentValuesX, float * inTangentValuesY, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation )
	{
		IBezQuatKey key;
		keyInterface->GetKey ( keyIndex, &key );

		float previousTime = ( float ) getPreviousTime ( keyIndex, animation.getController() );

		//testing
		/*        bool b1 = key.flags & BEZKEY_UNCONSTRAINHANDLE;
		bool b2 = GetInTanType( key.flags ) != BEZKEY_USER;
		bool b3 = GetOutTanType( key.flags ) != BEZKEY_USER;
		bool b4 = GetOutTanType( key.flags ) == BEZKEY_LINEAR;
		bool b5 = GetOutTanType( key.flags ) == BEZKEY_STEP;
		*/
		InterpolationType interpolationInType = getInterpolationInType ( key.flags );

		// export control point. If it is not a BEZIER interpolation, export the point itself

		size_t keyValueIndex = 3 * keyIndex;

		if ( interpolationInType == BEZIER )
		{
			float inInterval = ( key.time - previousTime ) * DEFAULT_INLENGHT;

			inTangentValuesX[0] = ( key.time - inInterval ) * mTimeFactor;
			inTangentValuesY[0] = mKeyValueList[keyValueIndex++];

			inTangentValuesX[1] = inTangentValuesX[0];
			inTangentValuesY[1] = mKeyValueList[keyValueIndex++];

			inTangentValuesX[2] = inTangentValuesX[0];
			inTangentValuesY[2] = mKeyValueList[keyValueIndex++];
		}
		else if ( interpolationInType == LINEAR )
		{
			size_t numKeys = mKeyValueList.size();

			float inTangentX = (key.time - ( key.time - previousTime )/3) * mTimeFactor;

			for ( size_t i = 0; i < 3; ++i, keyValueIndex++)
			{
				inTangentValuesX[i] = inTangentX;
				// get the previous key value
				size_t previousKeyIndex = ( keyValueIndex > 0 ) ? keyValueIndex - 1 : numKeys - 1;
				inTangentValuesY[i] = (mKeyValueList[keyValueIndex] - ( mKeyValueList[keyValueIndex] - mKeyValueList[previousKeyIndex] )/3);
			}
		}
		else
		{
			/// @TODO: clarify if this makes sense or if we should export the same as above
			inTangentValuesX[0] = key.time * mTimeFactor;
			inTangentValuesX[1] = inTangentValuesX[0];
			inTangentValuesX[2] = inTangentValuesX[0];

			inTangentValuesY[0] = mKeyValueList[keyValueIndex++];
			inTangentValuesY[1] = mKeyValueList[keyValueIndex++];
			inTangentValuesY[2] = mKeyValueList[keyValueIndex++];
		}
	}


	//---------------------------------------------------------------
    void AnimationExporter::exportOutTangentSource ( const Animation & animation, const String & baseId, IKeyControl* keyInterface, TangentValueFunctionPtr tangentValueFunction )
    {
        exportTangentSource ( OUTTANGENT_SOURCE_ID_SUFFIX, animation, baseId, keyInterface, tangentValueFunction );
    }

    //---------------------------------------------------------------
    void AnimationExporter::getFloatOutTangentValue ( float * outTangentValuesX, float * outTangentValuesY, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation )
    {
        IBezFloatKey key;
        keyInterface->GetKey ( keyIndex, &key );

        float nextTime = ( float ) getNextTime ( keyIndex, keyCount, animation.getController() );

        //testing
        /*        bool b1 = key.flags & BEZKEY_UNCONSTRAINHANDLE;
                bool b2 = GetInTanType( key.flags ) != BEZKEY_USER;
                bool b3 = GetOutTanType( key.flags ) != BEZKEY_USER;
                bool b4 = GetOutTanType( key.flags ) == BEZKEY_LINEAR;
                bool b5 = GetOutTanType( key.flags ) == BEZKEY_STEP;
        */
        InterpolationType interpolationOutType = getInterpolationOutType ( key.flags );

        // export control point. If it is not a BEZIER interpolation, export the point itself

        if ( interpolationOutType == BEZIER )
        {
            if ( GetOutTanType ( key.flags ) != BEZKEY_USER )
                key.outLength = DEFAULT_OUTLENGHT_FLOAT;
            else if ( key.flags & BEZKEY_UNCONSTRAINHANDLE )
                key.outLength *= GetTicksPerFrame() / ( float ) ( nextTime - key.time );

            float outInterval = ( nextTime - key.time ) * key.outLength;

            *outTangentValuesX = ( key.time + outInterval ) * mTimeFactor;

            *outTangentValuesY = key.val + key.outtan * outInterval;
        }
        else if ( interpolationOutType == LINEAR )
		{
			*outTangentValuesX = (key.time + ( nextTime - key.time )/3) * mTimeFactor;
			// get the next key value
			int numKeys = keyInterface->GetNumKeys();
			int nextKeyIndex = (keyIndex + 1 < numKeys ) ? keyIndex + 1 : 0;
			IBezFloatKey nextKey;
			keyInterface->GetKey ( nextKeyIndex, &nextKey );
			*outTangentValuesY = (key.val + ( nextKey.val - key.val )/3);
		}
		else
        {
            *outTangentValuesX = key.time * mTimeFactor;
            *outTangentValuesY = key.val;
        }
    }


	//---------------------------------------------------------------
	template <class KeyType>
	void AnimationExporter::getPointXSingleOutTangentValue ( float * outTangentValuesX, float * outTangentValuesY, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation )
	{
		KeyType key;
		keyInterface->GetKey ( keyIndex, &key );

		float nextTime = ( float ) getNextTime ( keyIndex, keyCount, animation.getController() );

		//testing
		/*        bool b1 = key.flags & BEZKEY_UNCONSTRAINHANDLE;
		bool b2 = GetInTanType( key.flags ) != BEZKEY_USER;
		bool b3 = GetOutTanType( key.flags ) != BEZKEY_USER;
		bool b4 = GetOutTanType( key.flags ) == BEZKEY_LINEAR;
		bool b5 = GetOutTanType( key.flags ) == BEZKEY_STEP;
		*/
		InterpolationType interpolationOutType = getInterpolationOutType ( key.flags );

		int keyParamterIndex = animation.getType() - Animation::POSITION_X;

		// export control point. If it is not a BEZIER interpolation, export the point itself

		if ( interpolationOutType == BEZIER )
		{

			if ( GetOutTanType ( key.flags ) != BEZKEY_USER )
				key.outLength = DEFAULT_OUTLENGHT_POINTX_FLOAT_ARRAY;
			else if ( key.flags & BEZKEY_UNCONSTRAINHANDLE )
				key.outLength *= GetTicksPerFrame() / ( float ) ( nextTime - key.time );

			float outInterval = ( nextTime - key.time ) * key.outLength[keyParamterIndex];

			*outTangentValuesX = ( key.time + outInterval ) * mTimeFactor;
			*outTangentValuesY = key.val[keyParamterIndex] + key.outtan[keyParamterIndex] * outInterval;
		}
		else if ( interpolationOutType == LINEAR )
		{
			*outTangentValuesX = (key.time + ( nextTime - key.time )/3) * mTimeFactor;
			// get the next key value
			int numKeys = keyInterface->GetNumKeys();
			int nextKeyIndex = (keyIndex + 1 < numKeys ) ? keyIndex + 1 : 0;
			KeyType nextKey;
			keyInterface->GetKey ( nextKeyIndex, &nextKey );
			*outTangentValuesY = (key.val[keyParamterIndex] + ( nextKey.val[keyParamterIndex] - key.val[keyParamterIndex] )/3);
		}
		else
		{
			/// @TODO: clarify if this makes sense or if we should export the same as above
			*outTangentValuesX = key.time * mTimeFactor;
			*outTangentValuesY = key.val[keyParamterIndex];
		}
	}


	//---------------------------------------------------------------
	template <int dimension, class KeyType>
	void AnimationExporter::getPointXOutTangentValue ( float * outTangentValuesX, float * outTangentValuesY, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation )
	{
		KeyType key;
		keyInterface->GetKey ( keyIndex, &key );

		float nextTime = ( float ) getNextTime ( keyIndex, keyCount, animation.getController() );

		//testing
		/*        bool b1 = key.flags & BEZKEY_UNCONSTRAINHANDLE;
		bool b2 = GetInTanType( key.flags ) != BEZKEY_USER;
		bool b3 = GetOutTanType( key.flags ) != BEZKEY_USER;
		bool b4 = GetOutTanType( key.flags ) == BEZKEY_LINEAR;
		bool b5 = GetOutTanType( key.flags ) == BEZKEY_STEP;
		*/
		InterpolationType interpolationOutType = getInterpolationOutType ( key.flags );

		// export control point. If it is not a BEZIER interpolation, export the point itself

		if ( interpolationOutType == BEZIER )
		{
			if ( GetOutTanType ( key.flags ) != BEZKEY_USER )
				key.outLength = DEFAULT_OUTLENGHT_POINTX_FLOAT_ARRAY;
			else if ( key.flags & BEZKEY_UNCONSTRAINHANDLE )
				key.outLength *= GetTicksPerFrame() / ( float ) ( nextTime - key.time );

			float outInterval;

			for ( int i = 0; i<dimension; ++i)
			{
				outInterval = ( nextTime - key.time ) * key.outLength[i];
				outTangentValuesX[i] = ( key.time + outInterval ) * mTimeFactor;
				outTangentValuesY[i] = key.val[i] + key.outtan[i] * outInterval;
			}
		}
		else if ( interpolationOutType == LINEAR )
		{
			float outTangentX = (key.time + ( nextTime - key.time )/3) * mTimeFactor;
			// get the next key value
			int numKeys = keyInterface->GetNumKeys();
			int nextKeyIndex = (keyIndex + 1 < numKeys ) ? keyIndex + 1 : 0;
			KeyType nextKey;
			keyInterface->GetKey ( nextKeyIndex, &nextKey );

			for ( int i = 0; i<dimension; ++i)
			{
				outTangentValuesX[i] = outTangentX;
				outTangentValuesY[i] = (key.val[i] + ( nextKey.val[i] - key.val[i] )/3);
			}
		}
		else
		{
			/// @TODO: clarify if this makes sense or if we should export the same as above
			for ( int i = 0; i<dimension; ++i)
			{
				outTangentValuesX[i] = key.time * mTimeFactor;
				outTangentValuesY[i] = key.val[i];
			}
		}
	}


	//---------------------------------------------------------------
	void AnimationExporter::getRotationSingleOutTangentPatchEuler ( float * outTangentValuesX, float * outTangentValuesY, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation )
	{
		IBezQuatKey key;
		keyInterface->GetKey ( keyIndex, &key );

		float nextTime = ( float ) getNextTime ( keyIndex, keyCount, animation.getController() );

		//testing
		/*        bool b1 = key.flags & BEZKEY_UNCONSTRAINHANDLE;
		bool b2 = GetInTanType( key.flags ) != BEZKEY_USER;
		bool b3 = GetOutTanType( key.flags ) != BEZKEY_USER;
		bool b4 = GetOutTanType( key.flags ) == BEZKEY_LINEAR;
		bool b5 = GetOutTanType( key.flags ) == BEZKEY_STEP;
		*/
		InterpolationType interpolationOutType = getInterpolationOutType ( key.flags );

		int keyParamterIndex = animation.getType() - Animation::ROTATION_X;


		// export control point. If it is not a BEZIER interpolation, export the point itself

		size_t keyValueIndex = keyIndex;

		if ( interpolationOutType == BEZIER )
		{
			float outInterval = ( nextTime - key.time ) * DEFAULT_INLENGHT;
			*outTangentValuesX = ( key.time + outInterval ) * mTimeFactor;
			*outTangentValuesY = mKeyValueList[keyValueIndex];
		}
		else if ( interpolationOutType == LINEAR )
		{ 
			*outTangentValuesX = (key.time + ( nextTime - key.time )/3) * mTimeFactor;
			// get the next key value
			int numKeys = (int)mKeyValueList.size();
			int nextKeyIndex = (keyIndex + 1 < numKeys ) ? keyIndex + 1 : 0;
			*outTangentValuesY = (mKeyValueList[keyValueIndex] + ( mKeyValueList[nextKeyIndex] - mKeyValueList[keyValueIndex] )/3);
		}
		else
		{
			/// @TODO: clarify if this makes sense or if we should export the same as above
			*outTangentValuesX = key.time * mTimeFactor;

			*outTangentValuesY = mKeyValueList[keyValueIndex];
		}
	}


	//---------------------------------------------------------------
	void AnimationExporter::getRotationOutTangentPatchEuler ( float * outTangentValuesX, float * outTangentValuesY, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation )
	{
		IBezQuatKey key;
		keyInterface->GetKey ( keyIndex, &key );

		float nextTime = ( float ) getNextTime ( keyIndex, keyCount, animation.getController() );

		//testing
		/*        bool b1 = key.flags & BEZKEY_UNCONSTRAINHANDLE;
		bool b2 = GetInTanType( key.flags ) != BEZKEY_USER;
		bool b3 = GetOutTanType( key.flags ) != BEZKEY_USER;
		bool b4 = GetOutTanType( key.flags ) == BEZKEY_LINEAR;
		bool b5 = GetOutTanType( key.flags ) == BEZKEY_STEP;
		*/
		InterpolationType interpolationOutType = getInterpolationOutType ( key.flags );

		// export control point. If it is not a BEZIER interpolation, export the point itself

		size_t keyValueIndex = 3 * keyIndex;

		if ( interpolationOutType == BEZIER )
		{
			float outInterval = ( nextTime - key.time ) * DEFAULT_INLENGHT;

			outTangentValuesX[0] = ( key.time + outInterval ) * mTimeFactor;
			outTangentValuesY[0] = mKeyValueList[keyValueIndex++];

			outTangentValuesX[1] = outTangentValuesX[0];
			outTangentValuesY[1] = mKeyValueList[keyValueIndex++];

			outTangentValuesX[2] = outTangentValuesX[0];
			outTangentValuesY[2] = mKeyValueList[keyValueIndex++];
		}
		else if ( interpolationOutType == LINEAR )
		{ 
			int numKeys = (int)mKeyValueList.size();

			float outTangentX = (key.time + ( nextTime - key.time )/3) * mTimeFactor;

			for ( size_t i = 0; i < 3; ++i, keyValueIndex++)
			{
				outTangentValuesX[i] = outTangentX;
				// get the next key value
				int nextKeyIndex = (keyIndex + 1 < numKeys ) ? keyIndex + 1 : 0;
				outTangentValuesY[i] = (mKeyValueList[keyValueIndex] + ( mKeyValueList[nextKeyIndex] - mKeyValueList[keyValueIndex] )/3);
			}
		}
		else
		{
			/// @TODO: clarify if this makes sense or if we should export the same as above
			outTangentValuesX[0] = key.time * mTimeFactor;
			outTangentValuesX[1] = outTangentValuesX[0];
			outTangentValuesX[2] = outTangentValuesX[0];

			outTangentValuesY[0] = mKeyValueList[keyValueIndex++];
			outTangentValuesY[1] = mKeyValueList[keyValueIndex++];
			outTangentValuesY[2] = mKeyValueList[keyValueIndex++];
		}
	}


	//---------------------------------------------------------------
	AnimationExporter::InterpolationType AnimationExporter::getInterpolationInType ( const DWORD & flags )
	{
		switch ( GetInTanType ( flags ) )
		{
		case BEZKEY_LINEAR:
			return LINEAR;
		case BEZKEY_STEP:
			return STEP;
		default:
			return BEZIER;
		}
	}

	//---------------------------------------------------------------
	AnimationExporter::InterpolationType AnimationExporter::getInterpolationOutType ( const DWORD & flags )
	{
		switch ( GetOutTanType ( flags ) )
		{
		case BEZKEY_LINEAR:
			return LINEAR;
		case BEZKEY_STEP:
			return STEP;
		default:
			return BEZIER;
		}
	}

    //---------------------------------------------------------------
    void AnimationExporter::exportInterpolationSource ( const String & baseId, IKeyControl * keyInterface, InterpolationTypeFunctionPtr interpolationTypeFunction, int keyCount )
    {
        COLLADASW::NameSource source ( mSW );
        source.setId ( baseId + INTERPOLATION_SOURCE_ID_SUFFIX );
        source.setArrayId ( baseId + INTERPOLATION_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        source.setAccessorStride ( 1 );
        source.getParameterNameList().push_back ( "INTERPOLATION" );
        source.setAccessorCount ( keyCount );
        source.prepareToAppendValues();

        for ( int i = 0; i < keyCount; ++i )
            source.appendValues ( interpolationTypeFunction ( keyInterface, i ) );

        source.finish();
    }

    //---------------------------------------------------------------
    template <const String & interpolationTypeName>
    const String & AnimationExporter::getUniformInterpolation ( IKeyControl * keyInterface, int keyIndex )
    {
        return interpolationTypeName;
    }

    //---------------------------------------------------------------
	template <class KeyType>
    const String & AnimationExporter::getBezierInterpolation ( IKeyControl * keyInterface, int keyIndex )
    {
        KeyType key;
		keyInterface->GetKey ( keyIndex, &key );
		InterpolationType interpolationOutType =  getInterpolationOutType ( key.flags );
		if ( interpolationOutType == STEP )
		{
			// step always wins
			return getNameOfInterpolation( STEP );
		}
		int numKeys = keyInterface->GetNumKeys();
		if ( keyIndex + 1 < numKeys )
		{
			KeyType nextKey;
			keyInterface->GetKey ( keyIndex + 1, &nextKey );
			InterpolationType nextInterpolationInType =  getInterpolationInType ( nextKey.flags );
			if ( nextInterpolationInType == STEP )
			{
				// step always wins
				return getNameOfInterpolation( STEP );
			}

			if ( (interpolationOutType == LINEAR) && (nextInterpolationInType == LINEAR) )
			{
				// linear only, if both are linear
				return getNameOfInterpolation( LINEAR );
			}
			else
			{
				// general case
				return getNameOfInterpolation( BEZIER );
			}
		}
		else
		{
			return getNameOfInterpolation ( interpolationOutType );
		}
    }


	//---------------------------------------------------------------
	void AnimationExporter::exportSamplingInputSource ( const String & baseId, TimeValue startTime, TimeValue endTime, int ticksPerFrame )
	{
		int keyCount = (endTime - startTime) / ticksPerFrame + 1;

		COLLADASW::FloatSource source ( mSW );
		source.setId ( baseId + INPUT_SOURCE_ID_SUFFIX );
		source.setArrayId ( baseId + INPUT_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
		source.setAccessorStride ( 1 );
		source.getParameterNameList().push_back ( "TIME" );
		source.setAccessorCount ( keyCount );
		source.prepareToAppendValues();


		for (TimeValue time = startTime; time < endTime; time += ticksPerFrame)
		{
			source.appendValues ( (float)time / (float)TIME_TICKSPERSEC );
		}

		source.finish();
	}



	//---------------------------------------------------------------
	void AnimationExporter::exportSamplingFloatOutputSource ( const Animation & animation, const String & baseId, IKeyControl* keyInterface, TimeValue startTime, TimeValue endTime, int ticksPerFrame )
	{
		int keyCount = (endTime - startTime) / ticksPerFrame + 1;

		COLLADASW::FloatSource source ( mSW );
		source.setId ( baseId + OUTPUT_SOURCE_ID_SUFFIX );
		source.setArrayId ( baseId + OUTPUT_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
		source.setAccessorStride ( 1 );

		if ( animation.getParameter() )
			source.getParameterNameList().push_back ( *(animation.getParameter()) );
		else
			source.getParameterNameList().push_back ( EMPTY_STRING );
		
		source.setAccessorCount ( keyCount );
		source.prepareToAppendValues();

		ConversionFunctorType conversionFunctor = animation.getConversionFunctor();

		for (TimeValue time = startTime; time < endTime; time += ticksPerFrame)
		{
			float keyValue;
			animation.getController()->GetValue(time, &keyValue, FOREVER, CTRL_ABSOLUTE);
			if ( conversionFunctor )
				source.appendValues ( (*conversionFunctor)(keyValue) );
			else
				source.appendValues ( keyValue );
		}

		source.finish();
	}


	//---------------------------------------------------------------
	void AnimationExporter::exportSamplingPoint3OutputSource ( const Animation & animation, const String & baseId, IKeyControl* keyInterface, TimeValue startTime, TimeValue endTime, int ticksPerFrame )
	{
		int keyCount = (endTime - startTime) / ticksPerFrame + 1;
		int keyLength = animation.getDimension();

		COLLADASW::FloatSource source ( mSW );
		source.setId ( baseId + OUTPUT_SOURCE_ID_SUFFIX );
		source.setArrayId ( baseId + OUTPUT_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
		source.setAccessorStride ( keyLength );

		for ( int i = 0; i < keyLength; ++i )
		{
			if ( animation.getParameter() ) 
				source.getParameterNameList().push_back ( * ( animation.getParameter() + i) );
			else
				source.getParameterNameList().push_back ( EMPTY_STRING );
		}

		source.setAccessorCount ( keyCount );
		source.prepareToAppendValues();

		ConversionFunctorType conversionFunctor = animation.getConversionFunctor();

		for (TimeValue time = startTime; time < endTime; time += ticksPerFrame)
		{

			Point3 keyValue;
			animation.getController()->GetValue(time, &keyValue, FOREVER, CTRL_ABSOLUTE);

			if ( keyLength == 1)
			{
				if ( conversionFunctor )
					source.appendValues ( (*conversionFunctor) ( keyValue[ animation.getType() - Animation::POSITION_X ] ) );
				else
					source.appendValues ( keyValue[ animation.getType() - Animation::POSITION_X ] );
			}
			else
			{
				assert( (keyLength == 3) || (keyLength == 4));

				for ( int j = 0; j < 3; ++j )
				{
					if ( conversionFunctor )
						source.appendValues ( (*conversionFunctor) ( keyValue[ j ] ) );
					else
						source.appendValues ( keyValue[ j ] );
				}

				// If the point3 controller has dimension 4, it is a rgba controller. In this case alpha is one.
				if ( keyLength == 4 )
				{
					source.appendValues ( 1 );
				}
			}
		}
		source.finish();
	}


	//---------------------------------------------------------------
	void AnimationExporter::exportSamplingRotationOutputSource ( const Animation & animation, const String & baseId, IKeyControl* keyInterface, TimeValue startTime, TimeValue endTime, int ticksPerFrame )
	{
		int keyCount = (endTime - startTime) / ticksPerFrame + 1;
		int keyLength = animation.getDimension();

		COLLADASW::FloatSource source ( mSW );
		source.setId ( baseId + OUTPUT_SOURCE_ID_SUFFIX );
		source.setArrayId ( baseId + OUTPUT_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
		source.setAccessorStride ( keyLength );

		for ( int i = 0; i < keyLength; ++i )
		{		
			if ( animation.getParameter() ) 
				source.getParameterNameList().push_back ( * ( animation.getParameter() + i) );
			else
				source.getParameterNameList().push_back ( EMPTY_STRING );
		}

		source.setAccessorCount ( keyCount );
		source.prepareToAppendValues();

		ConversionFunctorType conversionFunctor = animation.getConversionFunctor();

		for (TimeValue time = startTime; time < endTime; time += ticksPerFrame)
		{

			float eulerAngles[ 3 ];

			if ( keyLength == 1 )
			{
				Quat quaternion;
				animation.getController()->GetValue(time, &quaternion, FOREVER, CTRL_ABSOLUTE);
				QuatToEuler(quaternion, eulerAngles, EULERTYPE_XYZ);
			}
			else
			{
				AngAxis angleAxis;
				animation.getController()->GetValue(time, &angleAxis, FOREVER, CTRL_ABSOLUTE);
				Quat quaternion(angleAxis);
				quaternion.GetEuler ( &eulerAngles[ 0 ], &eulerAngles[ 1 ], &eulerAngles[ 2 ] );
			}

			if ( time > startTime)
				patchEuler(mPreviousEulerAngles, eulerAngles);

			mPreviousEulerAngles[0] = eulerAngles[0];
			mPreviousEulerAngles[1] = eulerAngles[1];
			mPreviousEulerAngles[2] = eulerAngles[2];

			if ( keyLength == 1)
			{
				if ( conversionFunctor )
					source.appendValues( (*conversionFunctor)(eulerAngles[ animation.getType() - Animation::ROTATION_X ]) );
				else
					source.appendValues( eulerAngles[ animation.getType() - Animation::ROTATION_X ] );
			}
			else
			{
				if ( conversionFunctor )
				{
					eulerAngles[0] = (*conversionFunctor)( eulerAngles[0] );
					eulerAngles[1] = (*conversionFunctor)( eulerAngles[1] );
					eulerAngles[2] = (*conversionFunctor)( eulerAngles[2] );
				}
				source.appendValues( eulerAngles[0], eulerAngles[1], eulerAngles[2] );
			}


		}
		source.finish();
	}


	void AnimationExporter::exportSamplingTransformationOutputSource( const Animation & animation, const String & baseId, IKeyControl* keyInterface, TimeValue startTime, TimeValue endTime, int ticksPerFrame )
	{
		int keyCount = (endTime - startTime) / ticksPerFrame + 1;
		int keyLength = animation.getDimension();

		COLLADASW::Float4x4SourceF source ( mSW );
		source.setId ( baseId + OUTPUT_SOURCE_ID_SUFFIX );
		source.setArrayId ( baseId + OUTPUT_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
		source.setAccessorStride ( keyLength );

		if ( animation.getParameter() ) 
			source.getParameterNameList().push_back ( * ( animation.getParameter()) );
		else
			source.getParameterNameList().push_back ( EMPTY_STRING );

		source.setAccessorCount ( keyCount );
		source.prepareToAppendValues();

		INode * iNode = animation.getNode();

		Matrix3 transformationMatrix, parentTransformationMatrix;
		INode* parentINode = iNode->GetParentNode();

		if (parentINode && parentINode->IsRootNode()) 
			parentINode = 0;

		for (TimeValue time = startTime; time < endTime; time += ticksPerFrame)
		{
			// Export the base NODE TM
			transformationMatrix = iNode->GetNodeTM(time);

			if (parentINode)
			{
				// export a relative TM
				// We have to use whatever value we exported for this parent
				// in order to remain consistent in collada
				parentTransformationMatrix = parentINode->GetNodeTM(time);
				parentTransformationMatrix.Invert();
				transformationMatrix = transformationMatrix * parentTransformationMatrix;
			}

			const Matrix3& constTransformationMatrix = transformationMatrix;
			for ( int row = 0; row < 3; ++row)
				source.appendValues(constTransformationMatrix[0][row], constTransformationMatrix[1][row], constTransformationMatrix[2][row], constTransformationMatrix[3][row]);
			source.appendValues(0, 0, 0, 1);

		}

		source.finish();
	}


	//---------------------------------------------------------------
	void AnimationExporter::exportSamplingInterpolationSource ( const String & baseId, TimeValue startTime, TimeValue endTime, int ticksPerFrame )
	{
		int keyCount = (endTime - startTime) / ticksPerFrame + 1;

		COLLADASW::NameSource source ( mSW );
		source.setId ( baseId + INTERPOLATION_SOURCE_ID_SUFFIX );
		source.setArrayId ( baseId + INTERPOLATION_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
		source.setAccessorStride ( 1 );
		source.getParameterNameList().push_back ( "INTERPOLATION" );
		source.setAccessorCount ( keyCount );
		source.prepareToAppendValues();

		for (TimeValue time = startTime; time < endTime; time += ticksPerFrame)
			source.appendValues ( LINEAR_NAME );

		source.finish();
	}


    //---------------------------------------------------------------
    void AnimationExporter::exportSampler ( const Animation & animation )
    {

		if ( animation.hasAnyInputFlagsSet() )
		{
			String baseId = getBaseId ( animation );

			LibraryAnimations::Sampler sampler(mSW, baseId + SAMPLER_ID_SUFFIX );

			if ( animation.inputFlagSet(Animation::INPUT) )
				sampler.addInput ( COLLADASW::InputSemantic::INPUT, "#" + baseId + INPUT_SOURCE_ID_SUFFIX );

			if ( animation.inputFlagSet(Animation::OUTPUT) )
				sampler.addInput ( COLLADASW::InputSemantic::OUTPUT, "#" + baseId + OUTPUT_SOURCE_ID_SUFFIX );

			if ( animation.inputFlagSet(Animation::IN_TANGENT) )
				sampler.addInput ( COLLADASW::InputSemantic::IN_TANGENT, "#" + baseId + INTANGENT_SOURCE_ID_SUFFIX );

			if ( animation.inputFlagSet(Animation::OUT_TANGENT) )
				sampler.addInput ( COLLADASW::InputSemantic::OUT_TANGENT, "#" + baseId + OUTTANGENT_SOURCE_ID_SUFFIX );

			if ( animation.inputFlagSet(Animation::INTERPOLATION) )
				sampler.addInput ( COLLADASW::InputSemantic::INTERPOLATION, "#" + baseId + INTERPOLATION_SOURCE_ID_SUFFIX );

			addSampler ( sampler );
		}
    }

    //---------------------------------------------------------------
    void AnimationExporter::exportChannel ( const Animation & animation )
    {
		if ( animation.hasAnyInputFlagsSet() )
		{
	        addChannel ( "#" + getBaseId ( animation ) + SAMPLER_ID_SUFFIX, getTarget ( animation ) );
		}
    }



	//---------------------------------------------------------------
	void AnimationExporter::angleApproach(float pval, float& val)
	{
		while (val - pval > MathUtils::PI_f) 
			val -= MathUtils::PI_f * 2.0f;
		while (val - pval < -MathUtils::PI_f) 
			val += MathUtils::PI_f * 2.0f;
	}


	//---------------------------------------------------------------
	void AnimationExporter::patchEuler(float* pval, float* val)
	{
		// Approach these Eulers to the previous value.
		for (int i = 0; i < 3; ++i) 
			angleApproach(pval[i], val[i]);

		float distanceSq = 0.0f; 
		for (int i = 0; i < 3; ++i) 
			distanceSq += (val[i] - pval[i]) * (val[i] - pval[i]);

		// All quaternions can be expressed two ways. Check if the second way is better.
		float alternative[3] = { val[0] + MathUtils::PI_f, MathUtils::PI_f - val[1], val[2] + MathUtils::PI_f };
		for (int i = 0; i < 3; ++i) 
			angleApproach(pval[i], alternative[i]);
		
		float alternateDistanceSq = 0.0f; for (int i = 0; i < 3; ++i) alternateDistanceSq += (alternative[i] - pval[i]) * (alternative[i] - pval[i]);

		if (alternateDistanceSq < distanceSq)
		{
			// Pick the alternative
			for (int i = 0; i < 3; ++i) 
				val[i] = alternative[i];
		}
	}

}
