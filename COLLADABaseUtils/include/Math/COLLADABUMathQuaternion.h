/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_MATH_QUATERNION_H__
#define __COLLADABU_MATH_QUATERNION_H__

#include "COLLADABUMathPrerequisites.h"

namespace COLLADABU
{
    namespace Math
    {
		class Matrix3;
		class Vector3;

        /** Implementation of a Quaternion, i.e. a rotation around an axis.
        */

        class  Quaternion
        {

        public:
            inline Quaternion (
                Real fW = 1.0,
                Real fX = 0.0, Real fY = 0.0, Real fZ = 0.0 )
            {
                w = fW;
                x = fX;
                y = fY;
                z = fZ;
            }

            inline Quaternion ( const Quaternion& rkQ )
            {
                w = rkQ.w;
                x = rkQ.x;
                y = rkQ.y;
                z = rkQ.z;
            }

            /// Construct a quaternion from a rotation matrix
            inline Quaternion( const Matrix3& rot )
            {
                this->fromRotationMatrix( rot );
            }

            /// Construct a quaternion from an angle/axis
            inline Quaternion( const Real& rfAngle_radian, const Vector3& rkAxis )
            {
                this->fromAngleAxis( rfAngle_radian, rkAxis );
            }

            /// Construct a quaternion from 3 orthonormal local axes
            inline Quaternion( const Vector3& xaxis, const Vector3& yaxis, const Vector3& zaxis )
            {
                this->fromAxes( xaxis, yaxis, zaxis );
            }

            /// Construct a quaternion from 3 orthonormal local axes
            inline Quaternion( const Vector3* akAxis )
            {
                this->fromAxes( akAxis );
            }

            inline void setAllElements ( Real fW , Real fX , Real fY, Real fZ )
            {
                w = fW;
                x = fX;
                y = fY;
                z = fZ;
            }

            void fromRotationMatrix ( const Matrix3& kRot );
            void toRotationMatrix ( Matrix3& kRot ) const;
            void fromAngleAxis ( const Real& rfAngle_radian, const Vector3& rkAxis );
            void toAngleAxis ( Real& rfAngle_radian, Vector3& rkAxis ) const;

            void fromAxes ( const Vector3* akAxis );
            void fromAxes ( const Vector3& xAxis, const Vector3& yAxis, const Vector3& zAxis );
            void toAxes ( Vector3* akAxis ) const;
            void toAxes ( Vector3& xAxis, Vector3& yAxis, Vector3& zAxis ) const;
            /// Get the local x-axis
            Vector3 xAxis( void ) const;
            /// Get the local y-axis
            Vector3 yAxis( void ) const;
            /// Get the local z-axis
            Vector3 zAxis( void ) const;

            inline Quaternion& operator= ( const Quaternion& rkQ )
            {
                w = rkQ.w;
                x = rkQ.x;
                y = rkQ.y;
                z = rkQ.z;
                return *this;
            }

            Quaternion operator+ ( const Quaternion& rkQ ) const;
            Quaternion operator- ( const Quaternion& rkQ ) const;
            Quaternion operator* ( const Quaternion& rkQ ) const;
            Quaternion operator* ( Real fScalar ) const;
            friend Quaternion operator* ( Real fScalar,
                                          const Quaternion& rkQ );
            Quaternion operator- () const;
            inline bool operator== ( const Quaternion& rhs ) const
            {
                return ( rhs.x == x ) && ( rhs.y == y ) &&
                       ( rhs.z == z ) && ( rhs.w == w );
            }

            inline bool operator!= ( const Quaternion& rhs ) const
            {
                return !operator==( rhs );
            }

            // functions of a quaternion
            Real dot ( const Quaternion& rkQ ) const;  // dot product
            Real norm () const;  // squared-length
            /// Normalises this quaternion, and returns the previous length
            Real normalise( void );
            Quaternion inverse () const;  // apply to non-zero quaternion
            Quaternion unitInverse () const;  // apply to unit-length quaternion
            Quaternion exp () const;
            Quaternion log () const;

            // rotation of a vector by a quaternion
            Vector3 operator* ( const Vector3& rkVector ) const;

			/// Calculate the local roll  element (in radians) of this quaternion
            Real getRoll( void ) const;
            /// Calculate the local pitch element (in radians) of this quaternion
            Real getPitch( void ) const;
            /// Calculate the local yaw element (in radians) of this quaternion
            Real getYaw( void ) const;
            /// Equality with tolerance (tolerance is max angle difference)
            bool equals( const Quaternion& rhs, const Real& tolerance_radian ) const;

            // spherical linear interpolation
            static Quaternion slerp ( Real fT, const Quaternion& rkP,
                                      const Quaternion& rkQ, bool shortestPath = false );

            static Quaternion slerpExtraSpins ( Real fT,
                                                const Quaternion& rkP, const Quaternion& rkQ,
                                                int iExtraSpins );

            // setup for spherical quadratic interpolation
            static void intermediate ( const Quaternion& rkQ0,
                                       const Quaternion& rkQ1, const Quaternion& rkQ2,
                                       Quaternion& rka, Quaternion& rkB );

            // spherical quadratic interpolation
            static Quaternion squad ( Real fT, const Quaternion& rkP,
                                      const Quaternion& rkA, const Quaternion& rkB,
                                      const Quaternion& rkQ, bool shortestPath = false );

            // normalised linear interpolation - faster but less accurate (non-constant rotation velocity)
            static Quaternion nlerp( Real fT, const Quaternion& rkP,
                                     const Quaternion& rkQ, bool shortestPath = false );

            // cutoff for sine near zero
            static const Real ms_fEpsilon;

            // special values
            static const Quaternion ZERO;
            static const Quaternion IDENTITY;

            Real w, x, y, z;


        };

    }

}

#endif // __COLLADABU__MATH__QUATERNION_H__
