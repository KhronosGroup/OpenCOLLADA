/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADABUStableHeaders.h"
#include "Math/COLLADABUMathMatrix4.h"

namespace COLLADABU
{

    namespace Math
    {

        const Matrix4 Matrix4::ZERO(
            ISNOTIDENTITY,
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0 );

        const Matrix4 Matrix4::IDENTITY(
            ISIDENTITY,
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1 );

        const Matrix4 Matrix4::CLIPSPACE2DTOIMAGESPACE(
            ISNOTIDENTITY,
            0.5, 0, 0, 0.5,
            0, -0.5, 0, 0.5,
            0, 0, 1, 0,
            0, 0, 0, 1 );

        inline Real
        MINOR( const Matrix4& m, const size_t r0, const size_t r1, const size_t r2,
               const size_t c0, const size_t c1, const size_t c2 )
        {
            return m[ r0 ][ c0 ] * ( m[ r1 ][ c1 ] * m[ r2 ][ c2 ] - m[ r2 ][ c1 ] * m[ r1 ][ c2 ] ) -
                   m[ r0 ][ c1 ] * ( m[ r1 ][ c0 ] * m[ r2 ][ c2 ] - m[ r2 ][ c0 ] * m[ r1 ][ c2 ] ) +
                   m[ r0 ][ c2 ] * ( m[ r1 ][ c0 ] * m[ r2 ][ c1 ] - m[ r2 ][ c0 ] * m[ r1 ][ c1 ] );
        }


        Matrix4 Matrix4::adjoint() const
        {
            return Matrix4( MINOR( *this, 1, 2, 3, 1, 2, 3 ),
                            -MINOR( *this, 0, 2, 3, 1, 2, 3 ),
                            MINOR( *this, 0, 1, 3, 1, 2, 3 ),
                            -MINOR( *this, 0, 1, 2, 1, 2, 3 ),

                            -MINOR( *this, 1, 2, 3, 0, 2, 3 ),
                            MINOR( *this, 0, 2, 3, 0, 2, 3 ),
                            -MINOR( *this, 0, 1, 3, 0, 2, 3 ),
                            MINOR( *this, 0, 1, 2, 0, 2, 3 ),

                            MINOR( *this, 1, 2, 3, 0, 1, 3 ),
                            -MINOR( *this, 0, 2, 3, 0, 1, 3 ),
                            MINOR( *this, 0, 1, 3, 0, 1, 3 ),
                            -MINOR( *this, 0, 1, 2, 0, 1, 3 ),

                            -MINOR( *this, 1, 2, 3, 0, 1, 2 ),
                            MINOR( *this, 0, 2, 3, 0, 1, 2 ),
                            -MINOR( *this, 0, 1, 3, 0, 1, 2 ),
                            MINOR( *this, 0, 1, 2, 0, 1, 2 ) );
        }


        Real Matrix4::determinant() const
        {
            if ( mState == ISIDENTITY )
                return 1;

            return m[ 0 ][ 0 ] * MINOR( *this, 1, 2, 3, 1, 2, 3 ) -
                   m[ 0 ][ 1 ] * MINOR( *this, 1, 2, 3, 0, 2, 3 ) +
                   m[ 0 ][ 2 ] * MINOR( *this, 1, 2, 3, 0, 1, 3 ) -
                   m[ 0 ][ 3 ] * MINOR( *this, 1, 2, 3, 0, 1, 2 );
        }

        Matrix4 Matrix4::inverse() const
        {
            if ( mState == ISIDENTITY )
                return * this;

            return adjoint() * ( 1.0f / determinant() );
        }

        void Matrix4::setRotate( Vector3 point, Real theta, Real phi, Real alpha )
        //void setRotate(Point3d A, // rotate about a line centred on A
        {
            mState = UNKNOWN;
            Real cosAlpha, sinAlpha, cosPhi, sinPhi,
            cosTheta, sinTheta, cosPhi2, sinPhi2,
            cosTheta2, sinTheta2, c, a1, a2, a3;
            a1 = point.x;
            a2 = point.y;
            a3 = point.z;

            cosPhi = cos( phi );
            sinPhi = sin( phi );
            cosPhi2 = cosPhi * cosPhi;
            sinPhi2 = sinPhi * sinPhi;
            cosTheta = cos( theta );
            sinTheta = sin( theta );
            cosTheta2 = cosTheta * cosTheta;
            sinTheta2 = sinTheta * sinTheta;
            cosAlpha = cos( alpha );
            sinAlpha = sin( alpha );
            c = 1.0 - cosAlpha;
            m[ 0 ][ 0 ] = cosTheta2 * ( cosAlpha * cosPhi2 + sinPhi2 )
                          + cosAlpha * sinTheta2;
            m[ 1 ][ 0 ] = sinAlpha * cosPhi + c * sinPhi2 * cosTheta * sinTheta;
            m[ 2 ][ 0 ] = sinPhi * ( cosPhi * cosTheta * c - sinAlpha * sinTheta );
            m[ 0 ][ 1 ] = sinPhi2 * cosTheta * sinTheta * c - sinAlpha * cosPhi;
            m[ 1 ][ 1 ] = sinTheta2 * ( cosAlpha * cosPhi2 + sinPhi2 )
                          + cosAlpha * cosTheta2;
            m[ 2 ][ 1 ] = sinPhi * ( cosPhi * sinTheta * c + sinAlpha * cosTheta );
            m[ 0 ][ 2 ] = sinPhi * ( cosPhi * cosTheta * c + sinAlpha * sinTheta );
            m[ 1 ][ 2 ] = sinPhi * ( cosPhi * sinTheta * c - sinAlpha * cosTheta );
            m[ 2 ][ 2 ] = cosAlpha * sinPhi2 + cosPhi2;
            m[ 0 ][ 3 ] = a1 - a1 * m[ 0 ][ 0 ] - a2 * m[ 0 ][ 1 ] - a3 * m[ 0 ][ 2 ];
            m[ 1 ][ 3 ] = a2 - a1 * m[ 1 ][ 0 ] - a2 * m[ 1 ][ 1 ] - a3 * m[ 1 ][ 2 ];
            m[ 2 ][ 3 ] = a3 - a1 * m[ 2 ][ 0 ] - a2 * m[ 2 ][ 1 ] - a3 * m[ 2 ][ 2 ];
        }


        //-----------------------------------------------------------------------
        void Matrix4::makeTransform( const Vector3& position, const Vector3& scale, const Quaternion& orientation )
        {
            // Ordering:
            //    1. Scale
            //    2. Rotate
            //    3. Translate
            mState = UNKNOWN;
            Matrix3 rot3x3, scale3x3;
            orientation.toRotationMatrix( rot3x3 );
            scale3x3 = Matrix3::ZERO;
            scale3x3[ 0 ][ 0 ] = scale.x;
            scale3x3[ 1 ][ 1 ] = scale.y;
            scale3x3[ 2 ][ 2 ] = scale.z;

            // Set up final matrix with scale, rotation and translation
            *this = rot3x3 * scale3x3;
            this->setTrans( position );

            // No projection term
            m[ 3 ][ 0 ] = 0;
            m[ 3 ][ 1 ] = 0;
            m[ 3 ][ 2 ] = 0;
            m[ 3 ][ 3 ] = 1;
        }

    }
}
