/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ASSET_H__
#define __COLLADAFW_ASSET_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWArrayPrimitiveType.h"


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
        typedef ArrayPrimitiveType<ValuePair*> ValuePairArray;

    public:

        /** Descriptive information about unit of measure. Its optional attributes are:*/
        struct Unit
        {
            /** 
            * The name of the distance unit to use in the scene. For example, 
            * "meter", "centimeter", "inches", or "parsec". This can be the 
            * real name of a measurement, or an imaginary name.
            */
            String mLinearUnit;

            /**
            * How many real-world meters in one distance unit as a floating-point number.
            * For example, 1.0 for the name "meter"; 1000 for the name "kilometer";
            * 0.3048 for the name "foot".
             */
            double mLinearUnitMeter;

            /**
             * The angular unit;
             */
            String mAngularUnit;

            /**
             * The time unit.
             */
            String mTimeUnit;

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
        ValuePairArray mValuePairArray;

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
        const ValuePairArray& getValuePairArray () const { return mValuePairArray; }


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
            mUnit.mLinearUnit = linearUnit;
        }

        /** 
        * Sets the linear unit meter.
        */
        void setLinearUnitMeter ( const double linearUnitMeter )
        {
            mUnit.mLinearUnitMeter = linearUnitMeter;
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
        void setUpAxisType ( const UpAxisType& upAxisType )
        {
            mUpAxisType = upAxisType;
        }

        /** Sets the up axis of the document. */
        void setUpAxisType ( const String& upAxis );

        /** Returns the up axis. */
        UpAxisType& getUpAxisType()
        {
            return mUpAxisType;
        }

	private:

        /** Disable default copy ctor. */
		FileInfo( const FileInfo& pre );

        /** Disable default assignment operator. */
		const FileInfo& operator= ( const FileInfo& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_ASSET_H__
