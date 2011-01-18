/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFRAMEWORK_GRAVITY_H__
#define __COLLADAFRAMEWORK_GRAVITY_H__

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWAnimatable.h"


namespace COLLADAFW
{

    class Gravity : public Animatable
    {

    private:

        double mX;
        double mY;
        double mZ;
        
        String mSid;

    public:

        Gravity( double x, double y, double z, String sid="" )
            : mX( x ), mY( y ), mZ( z ), mSid( sid ) {}

        /** Sets the values of color*/
        void set( double x, double y, double z, String sid="" );

        /** Returns the X component*/
        double getX() const {return mX; }

		/** Sets the red component*/
		void setX( double x ) {mX = x; }

        /** Returns the Y component*/
        double getY() const { return mY; }

		/** Sets the Y component*/
		void setY( double y ) {mY = y; }

        /** Returns the Z component*/
        double getZ() const { return mZ; }

		/** Sets the Z component*/
		void setZ( double z ) {mZ = z; }

        /** Operator overloading. */
     /*   bool operator==(const Color& uid) const;
        bool operator!=(const Color& uid) const;*/

    };

	void Gravity::set ( double x, double y, double z, String sid )
    {
        mX = x;
        mY = y;
        mZ = z;
        mSid = sid;
    }

} //namespace COLLADAFW


#endif //__COLLADAFRAMEWORK_GRAVITY_H__
