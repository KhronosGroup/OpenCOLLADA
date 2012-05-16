/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_COLOR_H__
#define __COLLADASTREAMWRITER_COLOR_H__

#include "COLLADASWPrerequisites.h"


namespace COLLADASW
{

    class Color
    {

    private:

        double mR;
        double mG;
        double mB;
        double mA;
        String mSid;

    public:

        Color ( double r, double g, double b, double a, String sid="" )
            : mR ( r ), mG ( g ), mB ( b ), mA ( a ), mSid ( sid ) {}

        /** Creates a color with opacity 1.*/
        Color ( double r, double g, double b, String sid="" )
            : mR ( r ), mG ( g ), mB ( b ), mA ( 1 ), mSid ( sid ) {}

        /** Creates an invalid color*/
        Color( )
            : mR ( -1 ), mG ( -1 ), mB ( -1 ), mA ( -1 ), mSid ( "" ) {}

        /** Sets the values of color*/
        void set ( double r, double g, double b, double a, String sid="" );

        /** Return true if the color is valid, false otherwise*/
        bool isValid() const;

        /** Returns the red component*/
        double getRed() const
        {
            return mR;
        }

        /** Returns the green component*/
        double getGreen() const
        {
            return mG;
        }

        /** Returns the blue component*/
        double getBlue() const
        {
            return mB;
        }

        /** Returns the alpha component*/
        double getAlpha() const
        {
            return mA;
        }

        /** A white color object*/
        static const Color WHITE;

        /** A black color object*/
        static const Color BLACK;

    };

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_COLOR_H__
