/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_ANIMATIONEXPORTER_H__
#define __COLLADAMAX_ANIMATIONEXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryAnimations.h"

#include "COLLADAMaxDocumentExporter.h"

class Control;

namespace COLLADAMax
{

    /** A class that holds all information needed to export an animation.*/

    class Animation
    {

    public:
        /** Type of Animation*/
        enum Type
        {
            FLOAT,          //!< Animated float
            FLOAT3,          //!< Animated float3
            FLOAT4,          //!< Animated float4

            POSITION_X,         //!< Animated x translation
            POSITION_Y,         //!< Animated y translation
            POSITION_Z,         //!< Animated z translation

            ROTATION_X,         //!< Animated x rotation
            ROTATION_Y,         //!< Animated y rotation
            ROTATION_Z,         //!< Animated z rotation

            SCALE_ROT_AXIS,        //!< The pivot rotation for scale/skew
            SCALE_ROT_AXIS_R,       //!< The reverse pivot rotation for scale/skew

            // Collapsed types
            SCALE = FLOAT3,        //!< Animated scale in three dimensions
            TRANSLATION = FLOAT3 //!< Animated translation in three dimensions
        };

        /** Function pointer for conversion functions, to convert doubles.*/
        typedef double ( *ConversionFunction ) ( const double & );

    private:
        /** The max controller.*/
        Control * mController;

        /** The id of the element to animate.*/
        String mId;

        /** The sid of the element to animate.*/
        String mSid;

        /** A pointer to an array of parameters to animate.*/
        const String * mParameters;

        /** Type of animation.*/
        int mType;

        /** Pointer to conversion function, to convert all animated values.*/
        ConversionFunction mConversionFunction;

    public:
        /**
        @param controller the controller used for the animation
        @param id The id of the element to animate
        @param sid The sid of the element to animate
        @param parameter A pointer to an array of parameters to animate
        @param type Type of animation
        @param conversionFunction Pointer to conversion function, to convert all animated values*/
        Animation ( Control * controller, const String & id, const String & sid, const String * parameter, int type, ConversionFunction conversionFunction = 0 );

        /** Destructor*/
        virtual ~Animation()
        {}



        /** Returns the controller.*/
        Control * getController() const
        {
            return mController;
        }

        /** Returns the id of the element to animate.*/
        const String & getId() const
        {
            return mId;
        }

        /** Returns the sid of the element to animate.*/
        const String & getSid() const
        {
            return mSid;
        }

        /** Returns the pointer to an array of parameters to animate.*/
        const String * getParameter() const
        {
            return mParameters;
        }

        /** Returns the type of the animation.*/
        int getType() const
        {
            return mType;
        }

        /** Returns the pointer to conversion function, to convert all animated values.*/
        const ConversionFunction & getConversionFunction() const
        {
            return mConversionFunction;
        }

        /** Returns the dimension of the animation, i.e. how many values are animated. */
        int getDimension() const;
    };


    /** Class to exports all animations of a max document.*/

    class AnimationExporter : public COLLADA::LibraryAnimations
    {

    private:
        /** List of animations*/
        typedef std::vector<Animation> AnimationList;

        /** Function pointer to a function that fills the float buffer @a keyValues with the @a keyIndex'th output value
        of @a animation. */
        typedef void ( *OutputValueFunctionPtr ) ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation );

        /** Function pointer to a function that fills the float buffer @a keyValues with the @a keyIndex'th output value
        of @a animation. */
        typedef void ( AnimationExporter::*TangentValueFunctionPtr ) ( float & x, float & y, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation );

        /** Function pointer to a function that returns the interpolation type as a string of @a i'th
        key of @a keyInterface. */
        typedef const String & ( *InterpolationTypeFunctionPtr ) ( IKeyControl * keyInterface, int i );

    private:
        /** Value uses for inlength if none is specified.*/
        static const float DEFAULT_INLENGHT;

        /** Value uses for outlength if none is specified.*/
        static const float DEFAULT_OUTLENGHT;

        /** The documentexporter this exporter belongs to.*/
        DocumentExporter * mDocumentExporter;

        /** List of all animations to export*/
        AnimationList mAnimationList;

        /** Factor to multiply the key time with to get the real time.*/
        static const float mTimeFactor;

    public:
        /** Constructor
        @param streamWriter The stream the animation should be written to
        @param documentExporter The documentexporter this exporter belongs to
        */
        AnimationExporter ( COLLADA::StreamWriter * streamWriter, DocumentExporter * documentExporter );

        /** Destructor*/
        ~AnimationExporter()
        {}


        /** Start export of all the animations.*/
        void doExport();

        /** Add @a animation to the list of animations that should be exported.*/
        void addAnimation ( const Animation & animation )
        {
            mAnimationList.push_back ( animation );
        }

        /** Adds an animation that animates a Point3.
        @param controller The controller that contains the animation
        @param id The id of the element to animate
        @param sid The sid of the element to animate
        @param parameters The parameter list of the element to animate
        */
        void addAnimatedPoint3 ( Control * controller, const String & id, const String & sid, const String parameters[] );

        /** Adds an animation that animates an angle.
        @param controller The controller that contains the animation
        @param id The id of the element to animate
        @param sid The sid of the element to animate
        @param parameters The parameter list of the element to animate
        @param animatedAngle The type of the angle that should be animated
        */
        void addAnimatedAngle ( Control * controller, const String & id, const String & sid, const String parameters[], int animatedAngle );

        /** Adds an animation that animates a Point3.
        @param controller The controller that contains the animation
        @param id The id of the element to animate
        @param sid The sid of the element to animate
        @param parameters The parameter list of the element to animate
        */
        void addAnimation4 ( Control * controller, const String & id, const String & sid, const String parameters[] );

        /** Returns true, if the controller is animated an should be exported.*/
        static bool isAnimated ( Control * controller );

        /** Generates an id from all the strings contained in @a animation.*/
        static String getBaseId ( const Animation & animation );

        /** Generates the correct target string for use in the @a \<channel\> element.*/
        static String getTarget ( const Animation & animation );

    private:
        /** Disable copy constructor.*/
        AnimationExporter ( const AnimationExporter & animationExporter );

        /** Disable assignment operator.*/
        AnimationExporter & operator= ( const AnimationExporter & animationExporter );


        /** Get the time of the key prior to key number @a i of @a controller.*/
        TimeValue getPreviousTime ( const int & i, Control * controller ) const;

        /** Get the time of the key next to key number @a i of @a controller.*/
        TimeValue getNextTime ( const int & i, const int & keyCount, Control * controller ) const;

        /** Exports all the source elements for @a animation.*/
        void exportSources ( const Animation & animation );

        /** Exports the input source element.
        @param baseId The base id of the animation
        @param controller The controller being exported
        @param keyInterface The IKeyControl interface*/

        template <class KeyClassName>
        void exportInputSource ( const String & baseId, Control * controller, IKeyControl* keyInterface );


        /** Exports the output source element.
        @param animation The animation being exported
        @param baseId The base id of the animation
        @param keyInterface The IKeyControl interface
        @param outputValueFunction Function pointer to a function used to retrieve the output values*/
        void exportOutputSource ( const Animation & animation, const String & baseId, IKeyControl* keyInterface, OutputValueFunctionPtr outputValueFunction );

        /** Retrieves the @a keyIndex'th value of type float from @a keyInterface of @a animation and stores it
        in the float buffer @a keyValues.*/
        template <class KeyType>
        static void getFloatValue ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation );

        /** Retrieves the @a keyIndex'th position value of a position animation that animates one value
        from @a keyInterface of @a animation and stores it  in the float buffer @a keyValues. The buffer
        @a keyValues must have at least
        length 1.*/
        static void getLinearPositionSingleValue ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation );

        /** Retrieves the three @a keyIndex'th position values of a position animation that animates all
        three values from @a keyInterface of @a animation and stores it in the float buffer @a keyValues.
        The buffer @a keyValues must have at least length 3.*/
        static void getLinearPositionValue ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation );

        /** Retrieves the @a keyIndex'th rotation value of a rotation animation that animates one value
        from @a keyInterface of @a animation and stores it  in the float buffer @a keyValues. The buffer
        @a keyValues must have at least length 1.*/
        static void getLinearRotationSingleValue ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation );

        /** Retrieves the three @a keyIndex'th rotation values of a rotation animation that animates all
        three values from @a keyInterface of @a animation and stores it in the float buffer @a keyValues.
        The buffer @a keyValues must have at least length 3.*/
        static void getLinearRotationValue ( float * keyValues, IKeyControl * keyInterface, const int & keyIndex, const Animation & animation );


        /** Exports a tangent  source element. It can be used for both in and out tangents.
        @param sourceIdSuffix The id suffix that should be used for the  source element
        @param animation The animation being exported
        @param baseId The base id of the animation
        @param keyInterface The IKeyControl interface
        @param tangentValueFunction Function pointer to a function used to retrieve the tangent values*/
        void exportTangentSource ( const String & sourceIdSuffix, const Animation & animation, const String & baseId, IKeyControl* keyInterface, TangentValueFunctionPtr tangentValueFunction );


        /** Exports the in tangent  source element.
        @param animation The animation being exported
        @param baseId The base id of the animation
        @param keyInterface The IKeyControl interface
        @param tangentValueFunction Function pointer to a function used to retrieve the in tangent values*/
        void exportInTangentSource ( const Animation & animation, const String & baseId, IKeyControl* keyInterface, TangentValueFunctionPtr tangentValueFunction );

        /** Retrieves an in tangent value.
        @param x float to store the x value
        @param y float to store the y value
        @param keyInterface The IKeyControl interface
        @param keyIndex The index of the key
        @param keyCount The number of keys in the animation
        @param animation The animation to export*/
        void getInTangentValue ( float & x, float & y, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation );


        /** Exports the out tangent  source element.
        @param animation The animation being exported
        @param baseId The base id of the animation
        @param keyInterface The IKeyControl interface
        @param tangentValueFunction Function pointer to a function used to retrieve the out tangent values*/
        void exportOutTangentSource ( const Animation & animation, const String & baseId, IKeyControl* keyInterface, TangentValueFunctionPtr tangentValueFunction );


        /** Retrieves an out tangent value
        @param x float to store the x value
        @param y float to store the y value
        @param keyInterface The IKeyControl interface
        @param keyIndex The index of the key
        @param keyCount The number of keys in the animation
        @param animation The animation to export*/
        void getOutTangentValue ( float & x, float & y, IKeyControl * keyInterface, const int & keyIndex, const int & keyCount, const Animation & animation );

        /** Determines the interpolation type depending on @a flags*/
        static InterpolationType getInterpolationType ( const DWORD & flags );

        /** Exports the interpolation source.
        @param baseId The base id of the animation
        @param keyInterface The IKeyControl interface
        @param interpolationTypeFunction Function pointer to a function used to retrieve the interpolation type
        @param keyCount The number of keys in the animation
        */
        void exportInterpolationSource ( const String & baseId, IKeyControl * keyInterface, InterpolationTypeFunctionPtr interpolationTypeFunction, int keyCount );

        /** Returns @a interpolationTypeName for all values of @a keyInterface and keyIndex.*/
        template <const String & interpolationTypeName>
        static const String & getUniformInterpolation ( IKeyControl * keyInterface, int keyIndex );

        /** Returns the type of the interpolation.
        @param keyInterface The IKeyControl interface
        @param keyIndex The number of the key*/
        static const String & getBezierInterpolation ( IKeyControl * keyInterface, int keyIndex );

        /** Exports the sampler element.*/
        void exportSampler ( const Animation & animation );

        /** Exports the channel element.*/
        void exportChannel ( const Animation & animation );
    };
}

#endif //__COLLADAMAX_ANIMATIONEXPORTER_H__




