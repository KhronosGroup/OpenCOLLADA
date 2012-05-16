/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ASSET_H__
#define __COLLADAFW_ASSET_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWPointerArray.h"

#include "COLLADABUURI.h"


namespace COLLADAFW
{

    /**
    Computers store vast amounts of information. An asset is a set of information that is organized into a
    distinct collection and managed as a unit. A wide range of attributes describes assets so that the
    information can be maintained and understood both by software tools and by humans. Asset information is
    often hierarchical, where the parts of a large asset are divided into smaller pieces that are managed as
    distinct assets themselves.
    */
    class FileInfo
    {
    public:

        typedef std::pair<String, String> ValuePair;
        typedef PointerArray<ValuePair> ValuePairPointerArray;

    public:

        /** Descriptive information about unit of measure. Its optional attributes are:*/
        class Unit
        {
        public:
            static const double LINEAR_UNIT_KILOMETER;
            static const double LINEAR_UNIT_METER;
            static const double LINEAR_UNIT_DECIMETER;
            static const double LINEAR_UNIT_CENTIMETER;
            static const double LINEAR_UNIT_MILLIMETER;
            static const double LINEAR_UNIT_FOOT;
            static const double LINEAR_UNIT_INCH;
            static const double LINEAR_UNIT_YARD;

            static const String LINEAR_UNIT_KILOMETER_NAME;
            static const String LINEAR_UNIT_METER_NAME;
            static const String LINEAR_UNIT_DECIMETER_NAME;
            static const String LINEAR_UNIT_CENTIMETER_NAME;
            static const String LINEAR_UNIT_MILLIMETER_NAME;
            static const String LINEAR_UNIT_FOOT_NAME;
            static const String LINEAR_UNIT_INCH_NAME;
            static const String LINEAR_UNIT_YARD_NAME;

            static const String ANGULAR_UNIT_DEGREES_NAME;
            static const String ANGULAR_UNIT_RADIANS_NAME;

            static const String TIME_UNIT_FILM_NAME;


            enum LinearUnit
            {
                KILOMETER,
                METER,
                DECIMETER,
                CENTIMETER,
                MILLIMETER,
                FOOT,
                INCH,
                YARD,
                UNKNOWN_LINEAR_UNIT
            };

            enum AngularUnit
            {
                DEGREES,
                RADIANS,
                UNKNOWN_ANGULAR_UNIT
            };

            enum TimeUnit
            {
                FILM,
                UNKNOWN_TIME_UNIT
            };

        private:

            /**
             * The enum value for the linear unit.
             */
            LinearUnit mLinearUnitUnit;

            /**
            * The name of the distance unit to use in the scene. For example,
            * "meter", "centimeter", "inches", or "parsec". This can be the
            * real name of a measurement, or an imaginary name.
            */
            String mLinearUnitName;

            /**
            * How many real-world meters in one distance unit as a floating-point number.
            * For example, 1.0 for the name "meter"; 1000 for the name "kilometer";
            * 0.3048 for the name "foot".
             */
            double mLinearUnitMeter;

            /**
             * The angular unit;
             */
            String mAngularUnitName;
            AngularUnit mAngularUnitUnit;

            /**
             * The time unit.
             */
            String mTimeUnitName;
            TimeUnit mTimeUnitUnit;

        public:

            Unit ()
                : mLinearUnitUnit ( CENTIMETER )
                , mLinearUnitName ( LINEAR_UNIT_CENTIMETER_NAME )
                , mLinearUnitMeter ( LINEAR_UNIT_CENTIMETER )
                , mAngularUnitName ( ANGULAR_UNIT_DEGREES_NAME )
                , mAngularUnitUnit ( DEGREES )
                , mTimeUnitName ( TIME_UNIT_FILM_NAME )
                , mTimeUnitUnit ( FILM )
            {}

            Unit ( String linearUnitName, double linearUnitMeter,
                String angularUnitName, String timeUnitName = TIME_UNIT_FILM_NAME )
                : mLinearUnitName ( linearUnitName )
                , mLinearUnitMeter ( linearUnitMeter )
                , mAngularUnitName ( angularUnitName )
                , mTimeUnitName ( timeUnitName )
            {
                initializeLinearUnitUnit ( linearUnitMeter );
                initializeAngularUnitUnitByName ( mAngularUnitName );
                initializeTimeUnitUnitByName ( mTimeUnitName );
            }

            virtual ~Unit () {}

            /**
            * The enum value for the linear unit.
            */
            const LinearUnit& getLinearUnitUnit () const { return mLinearUnitUnit; }
            void setLinearUnitUnit ( const LinearUnit& val ) { mLinearUnitUnit = val; }

            /**
            * The name of the distance unit to use in the scene. For example,
            * "meter", "centimeter", "inches", or "parsec". This can be the
            * real name of a measurement, or an imaginary name.
            */
            const String& getLinearUnitName () const { return mLinearUnitName; }
            void setLinearUnitName ( const String& val );

            /**
             * Initializes the linear unit unit with the specified enum value
             * in depend of the given name.
             */
            void initializeLinearUnitUnit ( const double val );

            /**
            * How many real-world meters in one distance unit as a floating-point number.
            * For example, 1.0 for the name "meter"; 1000 for the name "kilometer";
            * 0.3048 for the name "foot".
            */
            const double getLinearUnitMeter () const { return mLinearUnitMeter; }
            void setLinearUnitMeter ( const double val );

			/**
			* The angular unit;
			*/
			AngularUnit getAngularUnit () const { return mAngularUnitUnit; }
			void setAngularUnit ( AngularUnit angularUnitUnit ) { mAngularUnitUnit = angularUnitUnit;}

			/**
			* The angular unit;
			*/
			const String& getAngularUnitName () const { return mAngularUnitName; }
			void setAngularUnitName ( const String& val );

            /**
            * Initializes the angular unit unit with the specified enum value
            * in depend of the given name.
            */
            void initializeAngularUnitUnitByName ( const String& angularUnitName );

            /**
            * The time unit.
            */
            const String& getTimeUnitName () const { return mTimeUnitName; }
            void setTimeUnitName ( const String& val );

            /**
            * Initializes the time unit unit with the specified enum value
            * in depend of the given name.
            */
            void initializeTimeUnitUnitByName ( const String& timeUnitName );

        };


        /*Descriptive information about the coordinate system
        of the geometric data. All coordinates are right handed
        by definition. Valid values are X_UP, Y_UP,
        or Z_UP. This element specifies which axis is
        considered upward, which is considered to the
        right, and which is considered inward.*/
        enum UpAxisType
        {
            NONE,
            X_UP,
            Y_UP,
            Z_UP
        };

        static const String X_UP_STRING;
        static const String Y_UP_STRING;
        static const String Z_UP_STRING;

    private:

        /** Descriptive information about unit of measure. Its optional attributes are:*/
        Unit mUnit;

        /* Descriptive information about the coordinate system of the geometric data.
        All coordinates are right handed by definition. Valid values are X_UP, Y_UP,
        or Z_UP. This element specifies which axis is considered upward, which is considered
        to the right, and which is considered inward. */
        UpAxisType mUpAxisType;

        /** A pair where you can hold file informations. */
        ValuePairPointerArray mValuePairArray;

		/** The absolute file uri.*/
		COLLADABU::URI mAbsoluteFileUri;

	public:

        /** Constructor. */
        FileInfo();

        /** Destructor. */
        virtual ~FileInfo();

        /** A pair where you can hold file informations. */
        void appendValuePair ( ValuePair* valuePair );

        /** A pair where you can hold file informations. */
        void appendValuePair ( const String& value1, const String& value2 );

        /** A pair where you can hold file informations. */
        const ValuePairPointerArray& getValuePairArray () const { return mValuePairArray; }


        /** Sets the unit used by the document.
        @param unit The unit to use.
        */
        void setUnit ( const Unit& unit )
        {
            mUnit = unit;
        }

        /**
        * Sets the linear unit.
        */
        void setLinearUnit ( const String& linearUnit )
        {
            mUnit.setLinearUnitName ( linearUnit );
        }

        /**
        * Sets the linear unit meter.
        */
        void setLinearUnitMeter ( double linearUnitMeter )
        {
            mUnit.setLinearUnitMeter ( linearUnitMeter );
        }

        /** Returns the unit. */
        Unit& getUnit()
        {
            return mUnit;
        }

        /** Returns the unit. */
        const Unit& getUnit() const
        {
            return mUnit;
        }

        /** Sets the up axis of the document. */
        void setUpAxisType ( UpAxisType upAxisType )
        {
            mUpAxisType = upAxisType;
        }

        /** Sets the up axis of the document. */
        void setUpAxisType ( const String& upAxis );

        /** Returns the up axis. */
        UpAxisType getUpAxisType() const
        {
            return mUpAxisType;
        }

		/** Returns the absolute uri of the file.*/
		const COLLADABU::URI& getAbsoluteFileUri() const { return mAbsoluteFileUri; }

		/** Sets the absolute uri of the file.*/
		void setAbsoluteFileUri( const COLLADABU::URI& absoluteFileUri) { mAbsoluteFileUri = absoluteFileUri; }

	private:

        /** Disable default copy ctor. */
		FileInfo( const FileInfo& pre );

        /** Disable default assignment operator. */
		const FileInfo& operator= ( const FileInfo& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_ASSET_H__
