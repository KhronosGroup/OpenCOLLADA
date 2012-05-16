/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADABUStableHeaders.h"
#include "Math/COLLADABUMathQuaternion.h"
#include "Math/COLLADABUMathMatrix3.h"
#include "Math/COLLADABUMathMatrix4.h"
#include "Math/COLLADABUMathVector3.h"


namespace COLLADABU
{

    namespace Math
    {

        const Real Quaternion::ms_fEpsilon = 1e-03;
        const Quaternion Quaternion::ZERO( 0.0, 0.0, 0.0, 0.0 );
        const Quaternion Quaternion::IDENTITY( 1.0, 0.0, 0.0, 0.0 );

        //-----------------------------------------------------------------------
        void Quaternion::fromRotationMatrix ( const Matrix3& kRot )
        {
            // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
            // article "Quaternion Calculus and Fast Animation".

            Real fTrace = kRot[ 0 ][ 0 ] + kRot[ 1 ][ 1 ] + kRot[ 2 ][ 2 ];
            Real fRoot;

            if ( fTrace > 0.0 )
            {
                // |w| > 1/2, may as well choose w > 1/2
                fRoot = sqrt( fTrace + 1.0 );  // 2w
                w = 0.5 * fRoot;
                fRoot = 0.5 / fRoot;  // 1/(4w)
                x = ( kRot[ 2 ][ 1 ] - kRot[ 1 ][ 2 ] ) * fRoot;
                y = ( kRot[ 0 ][ 2 ] - kRot[ 2 ][ 0 ] ) * fRoot;
                z = ( kRot[ 1 ][ 0 ] - kRot[ 0 ][ 1 ] ) * fRoot;
            }

            else
            {
                // |w| <= 1/2
                static size_t s_iNext[ 3 ] = { 1, 2, 0 };
                size_t i = 0;

                if ( kRot[ 1 ][ 1 ] > kRot[ 0 ][ 0 ] )
                    i = 1;

                if ( kRot[ 2 ][ 2 ] > kRot[ i ][ i ] )
                    i = 2;

                size_t j = s_iNext[ i ];

                size_t k = s_iNext[ j ];

                fRoot = sqrt( kRot[ i ][ i ] - kRot[ j ][ j ] - kRot[ k ][ k ] + 1.0 );

                Real* apkQuat[ 3 ] = { &x, &y, &z };

                *apkQuat[ i ] = 0.5 * fRoot;

                fRoot = 0.5 / fRoot;

                w = ( kRot[ k ][ j ] - kRot[ j ][ k ] ) * fRoot;

                *apkQuat[ j ] = ( kRot[ j ][ i ] + kRot[ i ][ j ] ) * fRoot;

                *apkQuat[ k ] = ( kRot[ k ][ i ] + kRot[ i ][ k ] ) * fRoot;
            }
        }

        //-----------------------------------------------------------------------
        void Quaternion::toRotationMatrix ( Matrix3& kRot ) const
        {
            Real fTx = 2.0 * x;
            Real fTy = 2.0 * y;
            Real fTz = 2.0 * z;
            Real fTwx = fTx * w;
            Real fTwy = fTy * w;
            Real fTwz = fTz * w;
            Real fTxx = fTx * x;
            Real fTxy = fTy * x;
            Real fTxz = fTz * x;
            Real fTyy = fTy * y;
            Real fTyz = fTz * y;
            Real fTzz = fTz * z;

            kRot[ 0 ][ 0 ] = 1.0 - ( fTyy + fTzz );
            kRot[ 0 ][ 1 ] = fTxy - fTwz;
            kRot[ 0 ][ 2 ] = fTxz + fTwy;
            kRot[ 1 ][ 0 ] = fTxy + fTwz;
            kRot[ 1 ][ 1 ] = 1.0 - ( fTxx + fTzz );
            kRot[ 1 ][ 2 ] = fTyz - fTwx;
            kRot[ 2 ][ 0 ] = fTxz - fTwy;
            kRot[ 2 ][ 1 ] = fTyz + fTwx;
            kRot[ 2 ][ 2 ] = 1.0 - ( fTxx + fTyy );
        }

        //-----------------------------------------------------------------------
        void Quaternion::fromAngleAxis ( const Real& rfAngle_radian,
                                         const Vector3& rkAxis )
        {
            // assert:  axis[] is unit length
            //
            // The quaternion representing the rotation is
            //   q = cos(A/2)+sin(A/2)*(x*i+y*j+z*k)

            Real fHalfAngle_radian ( 0.5 * rfAngle_radian );
            Real fSin = sin( fHalfAngle_radian );
            w = cos( fHalfAngle_radian );
            x = fSin * rkAxis.x;
            y = fSin * rkAxis.y;
            z = fSin * rkAxis.z;
        }

        //-----------------------------------------------------------------------
        void Quaternion::toAngleAxis ( Real& rfAngle_radian, Vector3& rkAxis ) const
        {
            // The quaternion representing the rotation is
            //   q = cos(A/2)+sin(A/2)*(x*i+y*j+z*k)

            Real fSqrLength = x * x + y * y + z * z;

            if ( fSqrLength > 0.0 )
            {
                rfAngle_radian = 2.0 * acos( w );
                Real fInvLength = 1/sqrt( fSqrLength );
                rkAxis.x = x * fInvLength;
                rkAxis.y = y * fInvLength;
                rkAxis.z = z * fInvLength;
            }

            else
            {
                // angle is 0 (mod 2*pi), so any axis will do
                rfAngle_radian = 0.0;
                rkAxis.x = 1.0;
                rkAxis.y = 0.0;
                rkAxis.z = 0.0;
            }
        }

        //-----------------------------------------------------------------------
        void Quaternion::fromAxes ( const Vector3* akAxis )
        {
            Matrix3 kRot;

            for ( size_t iCol = 0; iCol < 3; iCol++ )
            {
                kRot[ 0 ][ iCol ] = akAxis[ iCol ].x;
                kRot[ 1 ][ iCol ] = akAxis[ iCol ].y;
                kRot[ 2 ][ iCol ] = akAxis[ iCol ].z;
            }

            fromRotationMatrix( kRot );
        }

        //-----------------------------------------------------------------------
        void Quaternion::fromAxes ( const Vector3& xaxis, const Vector3& yaxis, const Vector3& zaxis )
        {
            Matrix3 kRot;

            kRot[ 0 ][ 0 ] = xaxis.x;
            kRot[ 1 ][ 0 ] = xaxis.y;
            kRot[ 2 ][ 0 ] = xaxis.z;

            kRot[ 0 ][ 1 ] = yaxis.x;
            kRot[ 1 ][ 1 ] = yaxis.y;
            kRot[ 2 ][ 1 ] = yaxis.z;

            kRot[ 0 ][ 2 ] = zaxis.x;
            kRot[ 1 ][ 2 ] = zaxis.y;
            kRot[ 2 ][ 2 ] = zaxis.z;

            fromRotationMatrix( kRot );

        }

        //-----------------------------------------------------------------------
        void Quaternion::toAxes ( Vector3* akAxis ) const
        {
            Matrix3 kRot;

            toRotationMatrix( kRot );

            for ( size_t iCol = 0; iCol < 3; iCol++ )
            {
                akAxis[ iCol ].x = kRot[ 0 ][ iCol ];
                akAxis[ iCol ].y = kRot[ 1 ][ iCol ];
                akAxis[ iCol ].z = kRot[ 2 ][ iCol ];
            }
        }

        //-----------------------------------------------------------------------
        Vector3 Quaternion::xAxis( void ) const
        {
            Real fTy = 2.0 * y;
            Real fTz = 2.0 * z;
            Real fTwy = fTy * w;
            Real fTwz = fTz * w;
            Real fTxy = fTy * x;
            Real fTxz = fTz * x;
            Real fTyy = fTy * y;
            Real fTzz = fTz * z;

            return Vector3( 1.0 -( fTyy + fTzz ), fTxy + fTwz, fTxz - fTwy );
        }

        //-----------------------------------------------------------------------
        Vector3 Quaternion::yAxis( void ) const
        {
            Real fTx = 2.0 * x;
            Real fTy = 2.0 * y;
            Real fTz = 2.0 * z;
            Real fTwx = fTx * w;
            Real fTwz = fTz * w;
            Real fTxx = fTx * x;
            Real fTxy = fTy * x;
            Real fTyz = fTz * y;
            Real fTzz = fTz * z;

            return Vector3( fTxy -fTwz, 1.0 - ( fTxx + fTzz ), fTyz + fTwx );
        }

        //-----------------------------------------------------------------------
        Vector3 Quaternion::zAxis( void ) const
        {
            Real fTx = 2.0 * x;
            Real fTy = 2.0 * y;
            Real fTz = 2.0 * z;
            Real fTwx = fTx * w;
            Real fTwy = fTy * w;
            Real fTxx = fTx * x;
            Real fTxz = fTz * x;
            Real fTyy = fTy * y;
            Real fTyz = fTz * y;

            return Vector3( fTxz + fTwy, fTyz - fTwx, 1.0 - ( fTxx + fTyy ) );
        }

        //-----------------------------------------------------------------------
        void Quaternion::toAxes ( Vector3& xaxis, Vector3& yaxis, Vector3& zaxis ) const
        {
            Matrix3 kRot;

            toRotationMatrix( kRot );

            xaxis.x = kRot[ 0 ][ 0 ];
            xaxis.y = kRot[ 1 ][ 0 ];
            xaxis.z = kRot[ 2 ][ 0 ];

            yaxis.x = kRot[ 0 ][ 1 ];
            yaxis.y = kRot[ 1 ][ 1 ];
            yaxis.z = kRot[ 2 ][ 1 ];

            zaxis.x = kRot[ 0 ][ 2 ];
            zaxis.y = kRot[ 1 ][ 2 ];
            zaxis.z = kRot[ 2 ][ 2 ];
        }

        //-----------------------------------------------------------------------
        Quaternion Quaternion::operator+ ( const Quaternion& rkQ ) const
        {
            return Quaternion( w + rkQ.w, x + rkQ.x, y + rkQ.y, z + rkQ.z );
        }

        //-----------------------------------------------------------------------
        Quaternion Quaternion::operator- ( const Quaternion& rkQ ) const
        {
            return Quaternion( w -rkQ.w, x - rkQ.x, y - rkQ.y, z - rkQ.z );
        }

        //-----------------------------------------------------------------------
        Quaternion Quaternion::operator* ( const Quaternion& rkQ ) const
        {
            // NOTE:  Multiplication is not generally commutative, so in most
            // cases p*q != q*p.

            return Quaternion
                   (
                       w * rkQ.w - x * rkQ.x - y * rkQ.y - z * rkQ.z,
                       w * rkQ.x + x * rkQ.w + y * rkQ.z - z * rkQ.y,
                       w * rkQ.y + y * rkQ.w + z * rkQ.x - x * rkQ.z,
                       w * rkQ.z + z * rkQ.w + x * rkQ.y - y * rkQ.x
                   );
        }

        //-----------------------------------------------------------------------
        Quaternion Quaternion::operator* ( Real fScalar ) const
        {
            return Quaternion( fScalar * w, fScalar * x, fScalar * y, fScalar * z );
        }

        //-----------------------------------------------------------------------
        Quaternion operator* ( Real fScalar, const Quaternion& rkQ )
        {
            return Quaternion( fScalar * rkQ.w, fScalar * rkQ.x, fScalar * rkQ.y,
                               fScalar * rkQ.z );
        }

        //-----------------------------------------------------------------------
        Quaternion Quaternion::operator- () const
        {
            return Quaternion( -w, -x, -y, -z );
        }

        //-----------------------------------------------------------------------
        Real Quaternion::dot ( const Quaternion& rkQ ) const
        {
            return w * rkQ.w + x * rkQ.x + y * rkQ.y + z * rkQ.z;
        }

        //-----------------------------------------------------------------------
        Real Quaternion::norm () const
        {
            return w * w + x * x + y * y + z * z;
        }

        //-----------------------------------------------------------------------
        Quaternion Quaternion::inverse () const
        {
            Real fNorm = w * w + x * x + y * y + z * z;

            if ( fNorm > 0.0 )
            {
                Real fInvNorm = 1.0 / fNorm;
                return Quaternion( w * fInvNorm, -x * fInvNorm, -y * fInvNorm, -z * fInvNorm );
            }

            else
            {
                // return an invalid result to flag the error
                return ZERO;
            }
        }

        //-----------------------------------------------------------------------
        Quaternion Quaternion::unitInverse () const
        {
            // assert:  'this' is unit length
            return Quaternion( w, -x, -y, -z );
        }

        //-----------------------------------------------------------------------
        Quaternion Quaternion::exp () const
        {
            // If q = A*(x*i+y*j+z*k) where (x,y,z) is unit length, then
            // exp(q) = cos(A)+sin(A)*(x*i+y*j+z*k).  If sin(A) is near zero,
            // use exp(q) = cos(A)+A*(x*i+y*j+z*k) since A/sin(A) has limit 1.

            Real fAngle_radian = sqrt( x * x + y * y + z * z );
            Real fSin = sin( fAngle_radian );

            Quaternion kResult;
            kResult.w = cos( fAngle_radian );

            if ( abs( fSin ) >= ms_fEpsilon )
            {
                Real fCoeff = fSin / fAngle_radian;
                kResult.x = fCoeff * x;
                kResult.y = fCoeff * y;
                kResult.z = fCoeff * z;
            }

            else
            {
                kResult.x = x;
                kResult.y = y;
                kResult.z = z;
            }

            return kResult;
        }

        //-----------------------------------------------------------------------
        Quaternion Quaternion::log () const
        {
            // If q = cos(A)+sin(A)*(x*i+y*j+z*k) where (x,y,z) is unit length, then
            // log(q) = A*(x*i+y*j+z*k).  If sin(A) is near zero, use log(q) =
            // sin(A)*(x*i+y*j+z*k) since sin(A)/A has limit 1.

            Quaternion kResult;
            kResult.w = 0.0;

            if ( abs( w ) < 1.0 )
            {
                Real fAngle_radian ( acos( w ) );
                Real fSin = sin( fAngle_radian );

                if ( abs( fSin ) >= ms_fEpsilon )
                {
                    Real fCoeff = fAngle_radian / fSin;
                    kResult.x = fCoeff * x;
                    kResult.y = fCoeff * y;
                    kResult.z = fCoeff * z;
                    return kResult;
                }
            }

            kResult.x = x;
            kResult.y = y;
            kResult.z = z;

            return kResult;
        }

        //-----------------------------------------------------------------------
        Vector3 Quaternion::operator* ( const Vector3& v ) const
        {
            // nVidia SDK implementation
            Vector3 uv, uuv;
            Vector3 qvec( x, y, z );
            uv = qvec.crossProduct( v );
            uuv = qvec.crossProduct( uv );
            uv *= ( 2.0f * w );
            uuv *= 2.0f;

            return v + uv + uuv;

        }


        //-----------------------------------------------------------------------
        void Quaternion::intermediate ( const Quaternion& rkQ0,
                                        const Quaternion& rkQ1, const Quaternion& rkQ2,
                                        Quaternion& rkA, Quaternion& rkB )
        {
            // assert:  q0, q1, q2 are unit quaternions

            Quaternion kQ0inv = rkQ0.unitInverse();
            Quaternion kQ1inv = rkQ1.unitInverse();
            Quaternion rkP0 = kQ0inv * rkQ1;
            Quaternion rkP1 = kQ1inv * rkQ2;
            Quaternion kArg = 0.25 * ( rkP0.log() - rkP1.log() );
            Quaternion kMinusArg = -kArg;

            rkA = rkQ1 * kArg.exp();
            rkB = rkQ1 * kMinusArg.exp();
        }


        //-----------------------------------------------------------------------
        Real Quaternion::normalise( void )
        {
            Real len = norm();
            Real factor = 1.0f / sqrt( len );
            *this = *this * factor;
            return len;
        }

        //-----------------------------------------------------------------------
        Real Quaternion::getRoll( void ) const
        {
            return  atan2( 2 * ( x * y + w * z ), w * w + x * x - y * y - z * z ) ;
        }

        //-----------------------------------------------------------------------
        Real Quaternion::getPitch( void ) const
        {
            return  atan2( 2 * ( y * z + w * x ), w * w - x * x - y * y + z * z );
        }

        //-----------------------------------------------------------------------
        Real Quaternion::getYaw( void ) const
        {
            return  asin( -2 * ( x * z - w * y ) ) ;
        }

        //-----------------------------------------------------------------------
        Quaternion Quaternion::nlerp( Real fT, const Quaternion& rkP,
                                      const Quaternion& rkQ, bool shortestPath )
        {
            Quaternion result;
            Real fCos = rkP.dot( rkQ );

            if ( fCos < 0.0f && shortestPath )
            {
                result = rkP + fT * ( ( -rkQ ) - rkP );
            }

            else
            {
                result = rkP + fT * ( rkQ - rkP );
            }

            result.normalise();
            return result;
        }
    }
}
