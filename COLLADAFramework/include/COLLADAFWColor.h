/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFRAMEWORK_COLOR_H__
#define __COLLADAFRAMEWORK_COLOR_H__

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWAnimatable.h"


namespace COLLADAFW
{

    class Color : public Animatable
    {

    private:

        double mR;
        double mG;
        double mB;
        double mA;
        String mSid;

    public:

        Color( double r, double g, double b, double a, String sid="" )
            : mR( r ), mG( g ), mB( b ), mA( a ), mSid( sid ) {}

        /** Creates a color with opacity 1.*/
        Color( double r, double g, double b, String sid="" )
            : mR( r ), mG( g ), mB( b ), mA( 1 ), mSid( sid ) {}

        /** Creates an invalid color*/
        Color( )
            : mR( -1 ), mG( -1 ), mB( -1 ), mA( -1 ), mSid( "" ) {}

        /** Sets the values of color*/
        void set( double r, double g, double b, double a, String sid="" );

        /** Return true if the color is valid, false otherwise*/
        bool isValid() const;

        /** Returns the red component*/
        double getRed() const {return mR; }

		/** Sets the red component*/
		void setRed( double r ) {mR = r; }

        /** Returns the green component*/
        double getGreen() const { return mG; }

		/** Sets the green component*/
		void setGreen( double g ) {mG = g; }

        /** Returns the blue component*/
        double getBlue() const { return mB; }

		/** Sets the red component*/
		void setBlue( double b ) {mB = b; }

        /** Returns the alpha component*/
        double getAlpha() const { return mA; }

		/** Sets the red component*/
		void setAlpha( double a ) {mA = a; }

        /** A white color object*/
        static const Color WHITE;

        /** A black color object*/
        static const Color BLACK;

        /** A grey color object*/
        static const Color GREY;

        /** Operator overloading. */
        bool operator==(const Color& uid) const;
        bool operator!=(const Color& uid) const;

    };

} //namespace COLLADAFW


#endif //__COLLADAFRAMEWORK_COLOR_H__
