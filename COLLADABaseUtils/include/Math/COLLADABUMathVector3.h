/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_MATH_VECTOR3_H__
#define __COLLADABU_MATH_VECTOR3_H__

#include "COLLADABUPlatform.h"
#include "COLLADABUMathPrerequisites.h"
#include "COLLADABUMathQuaternion.h"

#include <math.h>

namespace COLLADABU
{
    namespace Math
    {
        /** Standard 3-dimensional vector.
            @remarks
                A direction in 3D space represented as distances along the 3
                orthogonal axes (x, y, z). Note that positions, directions and
                scaling factors can be represented by a vector, depending on how
                you interpret the values.
        */

        class Vector3
        {

        public:
            union {

                struct
                {
                    Real x, y, z;
                };

                Real val[ 3 ];
            };

        public:
            inline Vector3() : x(0), y(0), z(0)
            {}

            inline Vector3( Real fX, Real fY, Real fZ )
                    : x( fX ), y( fY ), z( fZ )
            {}

            inline Vector3( Real afCoordinate[ 3 ] )
                    : x( afCoordinate[ 0 ] ),
                    y( afCoordinate[ 1 ] ),
                    z( afCoordinate[ 2 ] )
            {}

            inline Vector3( int afCoordinate[ 3 ] )
            {
                x = ( Real ) afCoordinate[ 0 ];
                y = ( Real ) afCoordinate[ 1 ];
                z = ( Real ) afCoordinate[ 2 ];
            }

            inline Vector3( const Real* const r )
                    : x( r[ 0 ] ), y( r[ 1 ] ), z( r[ 2 ] )
            {}

            inline Vector3( const Vector3& rkVector )
                    : x( rkVector.x ), y( rkVector.y ), z( rkVector.z )
            {}

			inline void set( Real fX, Real fY, Real fZ )
			{
				x = fX;
				y = fY;
				z = fZ;
			}

            inline Real operator [] ( size_t i ) const
            {
				COLLADABU_ASSERT( i < 3 );

                return *( &x + i );
            }

            inline Real& operator [] ( size_t i )
            {
                COLLADABU_ASSERT( i < 3 );

                return *( &x + i );
            }

            /** Assigns the value of the other vector.
                @param
                    rkVector The other vector
            */
            inline Vector3& operator = ( const Vector3& rkVector )
            {
                x = rkVector.x;
                y = rkVector.y;
                z = rkVector.z;

                return *this;
            }

            inline bool operator == ( const Vector3& rkVector ) const
            {
                return ( x == rkVector.x && y == rkVector.y && z == rkVector.z );
            }

            inline bool operator != ( const Vector3& rkVector ) const
            {
                return ( x != rkVector.x || y != rkVector.y || z != rkVector.z );
            }

            // arithmetic operations
            inline Vector3 operator + ( const Vector3& rkVector ) const
            {
                Vector3 kSum;

                kSum.x = x + rkVector.x;
                kSum.y = y + rkVector.y;
                kSum.z = z + rkVector.z;

                return kSum;
            }

            inline Vector3 operator - ( const Vector3& rkVector ) const
            {
                Vector3 kDiff;

                kDiff.x = x - rkVector.x;
                kDiff.y = y - rkVector.y;
                kDiff.z = z - rkVector.z;

                return kDiff;
            }

            inline Vector3 operator * ( Real fScalar ) const
            {
                Vector3 kProd;

                kProd.x = fScalar * x;
                kProd.y = fScalar * y;
                kProd.z = fScalar * z;

                return kProd;
            }

            inline Vector3 operator * ( const Vector3& rhs ) const
            {
                Vector3 kProd;

                kProd.x = rhs.x * x;
                kProd.y = rhs.y * y;
                kProd.z = rhs.z * z;

                return kProd;
            }

            inline Vector3 operator / ( Real fScalar ) const
            {
                COLLADABU_ASSERT( fScalar != 0.0 );

                Vector3 kDiv;

                Real fInv = 1.0 / fScalar;
                kDiv.x = x * fInv;
                kDiv.y = y * fInv;
                kDiv.z = z * fInv;

                return kDiv;
            }

            inline Vector3 operator / ( const Vector3& rhs ) const
            {
                Vector3 kDiv;

                kDiv.x = x / rhs.x;
                kDiv.y = y / rhs.y;
                kDiv.z = z / rhs.z;

                return kDiv;
            }


            inline Vector3 operator - () const
            {
                Vector3 kNeg;

                kNeg.x = -x;
                kNeg.y = -y;
                kNeg.z = -z;

                return kNeg;
            }

            inline friend Vector3 operator * ( Real fScalar, const Vector3& rkVector )
            {
                Vector3 kProd;

                kProd.x = fScalar * rkVector.x;
                kProd.y = fScalar * rkVector.y;
                kProd.z = fScalar * rkVector.z;

                return kProd;
            }

            // arithmetic updates
            inline Vector3& operator += ( const Vector3& rkVector )
            {
                x += rkVector.x;
                y += rkVector.y;
                z += rkVector.z;

                return *this;
            }

            inline Vector3& operator -= ( const Vector3& rkVector )
            {
                x -= rkVector.x;
                y -= rkVector.y;
                z -= rkVector.z;

                return *this;
            }

            inline Vector3& operator *= ( Real fScalar )
            {
                x *= fScalar;
                y *= fScalar;
                z *= fScalar;
                return *this;
            }

            inline Vector3& operator *= ( const Vector3& rkVector )
            {
                x *= rkVector.x;
                y *= rkVector.y;
                z *= rkVector.z;

                return *this;
            }

            inline Vector3& operator /= ( Real fScalar )
            {
                COLLADABU_ASSERT( fScalar != 0.0 );

                Real fInv = 1.0 / fScalar;

                x *= fInv;
                y *= fInv;
                z *= fInv;

                return *this;
            }

            inline Vector3& operator /= ( const Vector3& rkVector )
            {
                x /= rkVector.x;
                y /= rkVector.y;
                z /= rkVector.z;

                return *this;
            }


            /** Returns the length (magnitude) of the vector.
                @warning
                    This operation requires a square root and is expensive in
                    terms of CPU operations. If you don't need to know the exact
                    length (e.g. for just comparing lengths) use squaredLength()
                    instead.
            */
            inline Real length () const
            {
                return sqrt( x * x + y * y + z * z );
            }

            /** Returns the square of the length(magnitude) of the vector.
                @remarks
                    This  method is for efficiency - calculating the actual
                    length of a vector requires a square root, which is expensive
                    in terms of the operations required. This method returns the
                    square of the length of the vector, i.e. the same as the
                    length but before the square root is taken. Use this if you
                    want to find the longest / shortest vector without incurring
                    the square root.
            */
            inline Real squaredLength () const
            {
                return x * x + y * y + z * z;
            }

            /** Calculates the dot (scalar) product of this vector with another.
                @remarks
                    The dot product can be used to calculate the angle between 2
                    vectors. If both are unit vectors, the dot product is the
                    cosine of the angle; otherwise the dot product must be
                    divided by the product of the lengths of both vectors to get
                    the cosine of the angle. This result can further be used to
                    calculate the distance of a point from a plane.
                @param
                    vec Vector with which to calculate the dot product (together
                    with this one).
                @returns
                    A float representing the dot product value.
            */
            inline Real dotProduct( const Vector3& vec ) const
            {
                return x * vec.x + y * vec.y + z * vec.z;
            }

            /** Normalises the vector.
                @remarks
                    This method normalises the vector such that it's
                    length / magnitude is 1. The result is called a unit vector.
                @note
                    This function will not crash for zero-sized vectors, but there
                    will be no changes made to their components.
                @returns The previous length of the vector.
            */
            inline Real normalise()
            {
                Real fLength = sqrt( x * x + y * y + z * z );

                // Will also work for zero-sized vectors, but will change nothing

                if ( fLength > 1e-08 )
                {
                    Real fInvLength = 1.0 / fLength;
                    x *= fInvLength;
                    y *= fInvLength;
                    z *= fInvLength;
                }

                return fLength;
            }

            /** Calculates the cross-product of 2 vectors, i.e. the vector that
                lies perpendicular to them both.
                @remarks
                    The cross-product is normally used to calculate the normal
                    vector of a plane, by calculating the cross-product of 2
                    non-equivalent vectors which lie on the plane (e.g. 2 edges
                    of a triangle).
                @param
                    rkVector Vector which, together with this one, will be used to
                    calculate the cross-product.
                @returns
                    A vector which is the result of the cross-product. This
                    vector will <b>NOT</b> be normalised, to maximise efficiency
                    - call Vector3::normalise on the result if you wish this to
                    be done. As for which side the resultant vector will be on, the
                    returned vector will be on the side from which the arc from 'this'
                    to rkVector is anticlockwise, e.g. UNIT_Y.crossProduct(UNIT_Z) 
                    = UNIT_X, whilst UNIT_Z.crossProduct(UNIT_Y) = -UNIT_X.
                @par
                    For a clearer explanation, look a the left and the bottom edges
                    of your monitor's screen. Assume that the first vector is the
                    left edge and the second vector is the bottom edge, both of
                    them starting from the lower-left corner of the screen. The
                    resulting vector is going to be perpendicular to both of them
                    and will go <i>inside</i> the screen, towards the cathode tube
                    (assuming you're using a CRT monitor, of course).
            */
            inline Vector3 crossProduct( const Vector3& rkVector ) const
            {
                Vector3 kCross;

                kCross.x = y * rkVector.z - z * rkVector.y;
                kCross.y = z * rkVector.x - x * rkVector.z;
                kCross.z = x * rkVector.y - y * rkVector.x;

                return kCross;
            }

            /** Returns a vector at a point half way between this and the passed
                in vector.
            */
            inline Vector3 midPoint( const Vector3& vec ) const
            {
                return Vector3(
                           ( x + vec.x ) * 0.5,
                           ( y + vec.y ) * 0.5,
                           ( z + vec.z ) * 0.5 );
            }

            /** Returns true if the vector's scalar components are all greater
                that the ones of the vector it is compared against.
            */
            inline bool operator < ( const Vector3& rhs ) const
            {
                if ( x < rhs.x && y < rhs.y && z < rhs.z )
                    return true;

                return false;
            }

            /** Returns true if the vector's scalar components are all smaller
                that the ones of the vector it is compared against.
            */
            inline bool operator > ( const Vector3& rhs ) const
            {
                if ( x > rhs.x && y > rhs.y && z > rhs.z )
                    return true;

                return false;
            }

            /** Sets this vector's components to the minimum of its own and the
                ones of the passed in vector.
                @remarks
                    'Minimum' in this case means the combination of the lowest
                    value of x, y and z from both vectors. Lowest is taken just
                    numerically, not magnitude, so -1 < 0.
            */
            inline void makeFloor( const Vector3& cmp )
            {
                if ( cmp.x < x )
                    x = cmp.x;

                if ( cmp.y < y )
                    y = cmp.y;

                if ( cmp.z < z )
                    z = cmp.z;
            }

            /** Sets this vector's components to the maximum of its own and the
                ones of the passed in vector.
                @remarks
                    'Maximum' in this case means the combination of the highest
                    value of x, y and z from both vectors. Highest is taken just
                    numerically, not magnitude, so 1 > -3.
            */
            inline void makeCeil( const Vector3& cmp )
            {
                if ( cmp.x > x )
                    x = cmp.x;

                if ( cmp.y > y )
                    y = cmp.y;

                if ( cmp.z > z )
                    z = cmp.z;
            }

            /** Generates a vector perpendicular to this vector (eg an 'up' vector).
                @remarks
                    This method will return a vector which is perpendicular to this
                    vector. There are an infinite number of possibilities but this 
                    method will guarantee to generate one of them. If you need more 
                    control you should use the Quaternion class.
            */
            inline Vector3 perpendicular( void ) const
            {
                static const Real fSquareZero = 1e-06 * 1e-06;

                Vector3 perp = this->crossProduct( Vector3::UNIT_X );

                // Check length

                if ( perp.squaredLength() < fSquareZero )
                {
                    /* This vector is the Y axis multiplied by a scalar, so we have
                       to use another axis.
                    */
                    perp = this->crossProduct( Vector3::UNIT_Y );
                }

                return perp;
            }



            /** Returns true if this vector is zero length. */
            inline bool isZeroLength( void ) const
            {
                Real sqlen = ( x * x ) + ( y * y ) + ( z * z );
                return ( sqlen < ( 1e-06 * 1e-06 ) );

            }

            /** As normalise, except that this vector is unaffected and the
                normalised vector is returned as a copy. */
            inline Vector3 normalisedCopy( void ) const
            {
                Vector3 ret = *this;
                ret.normalise();
                return ret;
            }

            /** Calculates a reflection vector to the plane with the given normal .
            @remarks NB assumes 'this' is pointing AWAY FROM the plane, invert if it is not.
            */
            inline Vector3 reflect( const Vector3& normal ) const
            {
                return Vector3( *this - ( 2 * this->dotProduct( normal ) * normal ) );
            }


            /** Returns whether this vector is within a directional tolerance
             of another vector.
            @param rhs The vector to compare with
            @param tolerance_radian The maximum angle by which the vectors may vary and
             still be considered equal
            */
            inline bool directionEquals( const Vector3& rhs,
                                         const Real& tolerance_radian ) const
            {
                Real dot = dotProduct( rhs );
                Real angle_radian = acos( dot );

                return fabs( angle_radian ) <= tolerance_radian;

            }

            // special points
            static const Vector3 ZERO;
            static const Vector3 UNIT_X;
            static const Vector3 UNIT_Y;
            static const Vector3 UNIT_Z;
            static const Vector3 NEGATIVE_UNIT_X;
            static const Vector3 NEGATIVE_UNIT_Y;
            static const Vector3 NEGATIVE_UNIT_Z;
            static const Vector3 UNIT_SCALE;

        };
		
    }	        
}

#endif //__COLLADABU_MATH_VECTOR3_H__
