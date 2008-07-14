/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#include "ColladaMaxStableHeaders.h"

#include "COLLADAStreamWriter.h"
#include "COLLADASource.h"
#include "COLLADAMathUtils.h"

#include "COLLADAMaxAnimationExporter.h"
#include "COLLADAMaxExportSceneGraph.h"



namespace COLLADAMax
{


    //---------------------------------------------------------------
    Animation::Animation ( Control * controller, const String & id, const String & sid, const String * parameter, int type, ConversionFunction conversionFunction )
            : mController ( controller ),
            mId ( id ),
            mSid ( sid ),
            mParameters ( parameter ),
            mType ( type ),
            mConversionFunction ( conversionFunction )
    {}

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

        default:
            return 0;
        }
    }

    const float AnimationExporter::DEFAULT_INLENGHT = 0.333f;
    const float AnimationExporter::DEFAULT_OUTLENGHT = 0.333f;


    const float AnimationExporter::mTimeFactor = 1.0f / ( GetTicksPerFrame() * GetFrameRate() );



    //---------------------------------------------------------------
    AnimationExporter::AnimationExporter ( COLLADA::StreamWriter * streamWriter, DocumentExporter * documentExporter )
            : COLLADA::LibraryAnimations ( streamWriter ),
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
    void AnimationExporter::addAnimatedPoint3 ( Control * controller, const String & id, const String & sid, const String parameters[] )
    {
        Control * subControllers[ 3 ] = {controller->GetXController(), controller->GetYController(), controller->GetZController() };

        // First, Try to extract animations from the component controllers

        if ( subControllers[ 0 ] != NULL && subControllers[ 1 ] != NULL && subControllers[ 2 ] != NULL )
        {
            for ( int i = 0; i < 3; ++i )
            {
                if ( isAnimated ( subControllers[ i ] ) )
                {
                    Animation animation ( subControllers[ i ], id, sid, parameters + i, Animation::FLOAT );
                    addAnimation ( animation );
                }
            }
        }

        else if ( isAnimated ( controller ) )
        {
            // Else, with no subs, try and export ourselves as keyframes
            Animation animation ( controller, id, sid, parameters, Animation::FLOAT3 );
            addAnimation ( animation );
        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::addAnimatedAngle ( Control * controller, const String & id, const String & sid, const String parameters[], int animatedAngle )
    {
        if ( isAnimated ( controller ) )
        {

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

            Animation animation ( controller, id, sid, parameters, animatedAngle, &COLLADA::MathUtils::radToDeg );

            addAnimation ( animation );
        }
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
    String AnimationExporter::getBaseId ( const Animation & animation )
    {
        if ( animation.getDimension() == 1 )
            return animation.getId() + "_" + animation.getSid() + "." + * ( animation.getParameter() );
        else
            return animation.getId() + "_" + animation.getSid();
    }

    //---------------------------------------------------------------
    String AnimationExporter::getTarget ( const Animation & animation )
    {
        if ( animation.getDimension() == 1 )
            return animation.getId() + "/" + animation.getSid() + "." + * ( animation.getParameter() );
        else
            return animation.getId() + "/" + animation.getSid();
    }

    //---------------------------------------------------------------
    void AnimationExporter::exportSources ( const Animation & animation )
    {
        bool isSampling = mDocumentExporter->getOptions().sampleAnimation(); //||forceSampling;

        Control * controller = animation.getController();

        String baseId = getBaseId ( animation );

        if ( !isSampling )
        {
            IKeyControl * keyInterface = GetKeyControlInterface ( controller );
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
                    exportOutputSource ( animation, baseId, keyInterface, COLLADAMax::AnimationExporter::getFloatValue<ILinFloatKey> );
                    exportInterpolationSource ( baseId, keyInterface, getUniformInterpolation<LibraryAnimations::LINEAR_NAME>, keyInterface->GetNumKeys() );
                    break;

                case LININTERP_POSITION_CLASS_ID:
                    exportInputSource<ILinPoint3Key> ( baseId, controller, keyInterface );

                    if ( animation.getDimension() == 1 )
                        exportOutputSource ( animation, baseId, keyInterface, COLLADAMax::AnimationExporter::getLinearPositionSingleValue );
                    else
                        exportOutputSource ( animation, baseId, keyInterface, COLLADAMax::AnimationExporter::getLinearPositionValue );

                    exportInterpolationSource ( baseId, keyInterface, getUniformInterpolation<LibraryAnimations::LINEAR_NAME>, keyInterface->GetNumKeys() );

                    break;

                case LININTERP_ROTATION_CLASS_ID:
                    exportInputSource<ILinRotKey> ( baseId, controller, keyInterface );

                    if ( animation.getDimension() == 1 )
                        exportOutputSource ( animation, baseId, keyInterface, COLLADAMax::AnimationExporter::getLinearRotationSingleValue );
                    else
                        exportOutputSource ( animation, baseId, keyInterface, COLLADAMax::AnimationExporter::getLinearRotationValue );

                    exportInterpolationSource ( baseId, keyInterface, getUniformInterpolation<LibraryAnimations::LINEAR_NAME>, keyInterface->GetNumKeys() );

                    break;

                case HYBRIDINTERP_FLOAT_CLASS_ID:
                    exportInputSource<IBezFloatKey> ( baseId, controller, keyInterface );

                    exportOutputSource ( animation, baseId, keyInterface, COLLADAMax::AnimationExporter::getFloatValue<IBezFloatKey> );

                    exportInTangentSource ( animation, baseId, keyInterface, &COLLADAMax::AnimationExporter::getInTangentValue );

                    exportOutTangentSource ( animation, baseId, keyInterface, &COLLADAMax::AnimationExporter::getOutTangentValue );

                    exportInterpolationSource ( baseId, keyInterface, getBezierInterpolation, keyInterface->GetNumKeys() );

                    break;

                }

            }

        }
    }


    //---------------------------------------------------------------

    template <class KeyClassName>
    void AnimationExporter::exportInputSource ( const String & baseId, Control * controller, IKeyControl* keyInterface )
    {
        int keyCount = keyInterface->GetNumKeys();

        COLLADA::FloatSource source ( mSW );
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

        COLLADA::FloatSource source ( mSW );
        source.setId ( baseId + OUTPUT_SOURCE_ID_SUFFIX );
        source.setArrayId ( baseId + OUTPUT_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        source.setAccessorStride ( keyLength );

        for ( int i = 0; i < keyLength; ++i )
            source.getParameterNameList().push_back ( * ( animation.getParameter() + i ) );

        source.setAccessorCount ( keyCount );

        source.prepareToAppendValues();

        float * keyBuffer = new float[ keyLength ];

        for ( int i = 0; i < keyCount; ++i )
        {
            outputValueFunction ( keyBuffer, keyInterface, i, animation );

            for ( int j = 0; j < keyLength; ++j )
            {
                const Animation::ConversionFunction & conversionFunction = animation.getConversionFunction();

                if ( conversionFunction )
                    source.appendValues ( conversionFunction ( keyBuffer[ j ] ) );
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
    void AnimationExporter::getLinearPositionSingleValue ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation )
    {
        ILinPoint3Key k;
        keyInterface->GetKey ( keyIndex, &k );
        *keyValues = k.val[ animation.getType() - Animation::POSITION_X ];
    }

    //---------------------------------------------------------------
    void AnimationExporter::getLinearPositionValue ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation )
    {
        ILinPoint3Key k;
        keyInterface->GetKey ( keyIndex, &k );
        keyValues[ 0 ] = k.val[ 0 ];
        keyValues[ 1 ] = k.val[ 1 ];
        keyValues[ 2 ] = k.val[ 2 ];
    }

    //---------------------------------------------------------------
    void AnimationExporter::getLinearRotationSingleValue ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation )
    {
        ILinRotKey k;
        keyInterface->GetKey ( keyIndex, &k );
        float eulerAngles[ 3 ];
        k.val.GetEuler ( &eulerAngles[ 0 ], &eulerAngles[ 1 ], &eulerAngles[ 2 ] );
        *keyValues = eulerAngles[ animation.getType() - Animation::ROTATION_X ];
    }

    //---------------------------------------------------------------
    void AnimationExporter::getLinearRotationValue ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation )
    {
        ILinRotKey k;
        keyInterface->GetKey ( keyIndex, &k );
        k.val.GetEuler ( &keyValues[ 0 ], &keyValues[ 1 ], &keyValues[ 2 ] );
    }

    //---------------------------------------------------------------
    void AnimationExporter::exportTangentSource ( const String & sourceIdSuffix, const Animation & animation, const String & baseId, IKeyControl* keyInterface, TangentValueFunctionPtr tangentValueFunction )
    {
        int keyCount = keyInterface->GetNumKeys();

        COLLADA::FloatSource source ( mSW );
        source.setId ( baseId + sourceIdSuffix );
        source.setArrayId ( baseId + sourceIdSuffix + ARRAY_ID_SUFFIX );
        source.setAccessorStride ( 2 );
        source.getParameterNameList().push_back ( "X" );
        source.getParameterNameList().push_back ( "Y" );
        source.setAccessorCount ( keyCount );
        source.prepareToAppendValues();

        for ( int i = 0; i < keyCount; ++i )
        {
            float x, y;
            ( this->*tangentValueFunction ) ( x, y, keyInterface, i, keyCount, animation );
            source.appendValues ( x, y );
        }

        source.finish();
    }

    //---------------------------------------------------------------
    void AnimationExporter::exportInTangentSource ( const Animation & animation, const String & baseId, IKeyControl* keyInterface, TangentValueFunctionPtr tangentValueFunction )
    {
        exportTangentSource ( INTANGENT_SOURCE_ID_SUFFIX, animation, baseId, keyInterface, tangentValueFunction );
    }

    //---------------------------------------------------------------
    void AnimationExporter::getInTangentValue ( float & x, float & y, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation )
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
        InterpolationType interpolationOutType = getInterpolationType ( key.flags );

        // export control point. If it is not a BEZIER interpolation, export the point itself

        if ( interpolationOutType == BEZIER )
        {
            if ( GetInTanType ( key.flags ) != BEZKEY_USER )
                key.inLength = DEFAULT_INLENGHT;
            else if ( key.flags & BEZKEY_UNCONSTRAINHANDLE )
                key.inLength *= GetTicksPerFrame() / ( float ) ( key.time - previousTime );

            float inInterval = ( key.time - previousTime ) * key.inLength;

            x = ( key.time - inInterval ) * mTimeFactor;

            y = key.val + key.intan * inInterval;
        }

        else
        {
            /// @TODO: clarify if this makes sense or if we should export the same as above
            x = key.time * mTimeFactor;
            y = key.val;
        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::exportOutTangentSource ( const Animation & animation, const String & baseId, IKeyControl* keyInterface, TangentValueFunctionPtr tangentValueFunction )
    {
        exportTangentSource ( OUTTANGENT_SOURCE_ID_SUFFIX, animation, baseId, keyInterface, tangentValueFunction );
    }

    //---------------------------------------------------------------
    void AnimationExporter::getOutTangentValue ( float & x, float & y, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation )
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
        InterpolationType interpolationOutType = getInterpolationType ( key.flags );

        // export control point. If it is not a BEZIER interpolation, export the point itself

        if ( interpolationOutType == BEZIER )
        {
            if ( GetOutTanType ( key.flags ) != BEZKEY_USER )
                key.outLength = DEFAULT_OUTLENGHT;
            else if ( key.flags & BEZKEY_UNCONSTRAINHANDLE )
                key.outLength *= GetTicksPerFrame() / ( float ) ( nextTime - key.time );

            float outInterval = ( nextTime - key.time ) * key.outLength;

            x = ( key.time + outInterval ) * mTimeFactor;

            y = key.val + key.outtan * outInterval;
        }

        else
        {
            x = key.time * mTimeFactor;
            y = key.val;
        }
    }

    //---------------------------------------------------------------
    AnimationExporter::InterpolationType AnimationExporter::getInterpolationType ( const DWORD & flags )
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
        COLLADA::NameSource source ( mSW );
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
    const String & AnimationExporter::getBezierInterpolation ( IKeyControl * keyInterface, int keyIndex )
    {
        IBezFloatKey key;
        keyInterface->GetKey ( keyIndex, &key );
        return getNameOfInterpolation ( getInterpolationType ( key.flags ) );
    }

    //---------------------------------------------------------------
    void AnimationExporter::exportSampler ( const Animation & animation )
    {
        bool isSampling = mDocumentExporter->getOptions().sampleAnimation(); //||forceSampling;

        Control * controller = animation.getController();

        String baseId = getBaseId ( animation );

        if ( !isSampling )
        {
            IKeyControl * keyInterface = GetKeyControlInterface ( controller );
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

                LibraryAnimations::Sampler sampler ( baseId + SAMPLER_ID_SUFFIX );

                switch ( classId.PartA() )
                {

                case LININTERP_FLOAT_CLASS_ID:

                case LININTERP_POSITION_CLASS_ID:

                case LININTERP_ROTATION_CLASS_ID:
                    sampler.addInput ( LibraryAnimations::Sampler::INPUT, "#" + baseId + INPUT_SOURCE_ID_SUFFIX );
                    sampler.addInput ( LibraryAnimations::Sampler::OUTPUT, "#" + baseId + OUTPUT_SOURCE_ID_SUFFIX );
                    sampler.addInput ( LibraryAnimations::Sampler::INTERPOLATION, "#" + baseId + INTERPOLATION_SOURCE_ID_SUFFIX );
                    break;

                case HYBRIDINTERP_FLOAT_CLASS_ID:
                    sampler.addInput ( LibraryAnimations::Sampler::INPUT, "#" + baseId + INPUT_SOURCE_ID_SUFFIX );
                    sampler.addInput ( LibraryAnimations::Sampler::OUTPUT, "#" + baseId + OUTPUT_SOURCE_ID_SUFFIX );
                    sampler.addInput ( LibraryAnimations::Sampler::IN_TANGENT, "#" + baseId + INTANGENT_SOURCE_ID_SUFFIX );
                    sampler.addInput ( LibraryAnimations::Sampler::OUT_TANGENT, "#" + baseId + OUTTANGENT_SOURCE_ID_SUFFIX );
                    sampler.addInput ( LibraryAnimations::Sampler::INTERPOLATION, "#" + baseId + INTERPOLATION_SOURCE_ID_SUFFIX );
                    break;
                }

                addSampler ( sampler );
            }

        }
    }

    //---------------------------------------------------------------
    void AnimationExporter::exportChannel ( const Animation & animation )
    {
        addChannel ( "#" + getBaseId ( animation ) + SAMPLER_ID_SUFFIX, getTarget ( animation ) );
    }


}
