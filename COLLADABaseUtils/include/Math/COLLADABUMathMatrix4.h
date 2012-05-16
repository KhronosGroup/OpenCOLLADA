/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_MATH_MATRIX4_H__
#define __COLLADABU_MATH_MATRIX4_H__

#include "COLLADABUMathVector3.h"
#include "COLLADABUMathMatrix3.h"
#include "COLLADABUMathUtils.h"

namespace COLLADABU
{

    namespace Math
    {
        /** Class encapsulating a standard 4x4 homogenous matrix.
        @remarks
        Math uses column vectors when applying matrix multiplications,
        This means a vector is represented as a single column, 4-row
        matrix. This has the effect that the tranformations implemented
        by the matrices happens right-to-left e.g. if vector V is to be
        transformed by M1 then M2 then M3, the calculation would be
        M3 * M2 * M1 * V. The order that matrices are concatenated is
        vital since matrix multiplication is not cummatative, i.e. you
        can get a different result if you concatenate in the wrong order.
        @par
        The use of column vectors and right-to-left ordering is the
        standard in most mathematical texts, and id the same as used in
        OpenGL. It is, however, the opposite of Direct3D, which has
        inexplicably chosen to differ from the accepted standard and uses
        row vectors and left-to-right matrix multiplication.
        @par
        Math deals with the differences between D3D and OpenGL etc.
        internally when operating through different render systems. Math
        users only need to conform to standard maths conventions, i.e.
        right-to-left matrix multiplication, (Math transposes matrices it
        passes to D3D to compensate).
        @par
        The generic form M * V which shows the layout of the matrix 
        entries is shown below:
        <pre>
        [ m[0][0]  m[0][1]  m[0][2]  m[0][3] ]   {x}
        | m[1][0]  m[1][1]  m[1][2]  m[1][3] | * {y}
        | m[2][0]  m[2][1]  m[2][2]  m[2][3] |   {z}
        [ m[3][0]  m[3][1]  m[3][2]  m[3][3] ]   {1}
        </pre>
        */

        class  Matrix4
        {


        public:
            /** Default constructor.
            @note
            It does <b>NOT</b> initialize the matrix for efficiency.
            */
            inline Matrix4()
                    : mState( UNKNOWN )
            {}

            inline Matrix4(
                Real m00, Real m01, Real m02, Real m03,
                Real m10, Real m11, Real m12, Real m13,
                Real m20, Real m21, Real m22, Real m23,
                Real m30, Real m31, Real m32, Real m33 )
            {
                setAllElements(
                    m00, m01, m02, m03,
                    m10, m11, m12, m13,
                    m20, m21, m22, m23,
                    m30, m31, m32, m33 );
            }

            inline Matrix4 ( const Real m[4][4] )
            {
                setAllElements(
                    m[0][0], m[0][1], m[0][2], m[0][3],
                    m[1][0], m[1][1], m[1][2], m[1][3],
                    m[2][0], m[2][1], m[2][2], m[2][3],
                    m[3][0], m[3][1], m[3][2], m[3][3] );
            }


            // matrix from delmia
            inline Matrix4( double* dblMatrix )
                    : mState( UNKNOWN )
            {
                m[ 0 ][ 0 ] = dblMatrix[ 0 ];
                m[ 1 ][ 0 ] = dblMatrix[ 1 ];
                m[ 2 ][ 0 ] = dblMatrix[ 2 ];
                m[ 3 ][ 0 ] = dblMatrix[ 3 ];
                m[ 0 ][ 1 ] = dblMatrix[ 4 ];
                m[ 1 ][ 1 ] = dblMatrix[ 5 ];
                m[ 2 ][ 1 ] = dblMatrix[ 6 ];
                m[ 3 ][ 1 ] = dblMatrix[ 7 ];
                m[ 0 ][ 2 ] = dblMatrix[ 8 ];
                m[ 1 ][ 2 ] = dblMatrix[ 9 ];
                m[ 2 ][ 2 ] = dblMatrix[ 10 ];
                m[ 3 ][ 2 ] = dblMatrix[ 11 ];
                m[ 0 ][ 3 ] = dblMatrix[ 12 ];
                m[ 1 ][ 3 ] = dblMatrix[ 13 ];
                m[ 2 ][ 3 ] = dblMatrix[ 14 ];
                m[ 3 ][ 3 ] = dblMatrix[ 15 ];
            }

            inline const Real & getElement( int index ) const
            {
                return _m[ index ];
            }

            inline const Real & getElement( int i, int j ) const
            {
                return m[ i ][ j ];
            }


			inline void setElement( int i, int j, Real value )
			{
				mState = UNKNOWN;
				m[ i ][ j ] = value;
			}

			inline void setElement( size_t i, size_t j, Real value )
			{
				mState = UNKNOWN;
				m[ i ][ j ] = value;
			}

			inline void setElement( int i, Real value )
			{
				mState = UNKNOWN;
				_m[ i ] = value;
			}

			inline void setElement( size_t i, Real value )
			{
				mState = UNKNOWN;
				_m[ i ] = value;
			}

			/** Creates a standard 4x4 transformation matrix with a zero translation part from a rotation/scaling 3x3 matrix.
            */

            inline Matrix4( const Matrix3& m3x3 )
                    : mState( UNKNOWN )
            {
                operator=( IDENTITY );
                operator=( m3x3 );
            }

            /** Creates a standard 4x4 transformation matrix with a zero translation part from a rotation/scaling Quaternion.
            */

            inline Matrix4( const Quaternion& rot )
                    : mState( UNKNOWN )
            {
                Matrix3 m3x3;
                rot.toRotationMatrix( m3x3 );
                operator=( IDENTITY );
                operator=( m3x3 );
            }


            inline void setAllElements(
                Real m00, Real m01, Real m02, Real m03,
                Real m10, Real m11, Real m12, Real m13,
                Real m20, Real m21, Real m22, Real m23,
                Real m30, Real m31, Real m32, Real m33 )
            {
                mState = UNKNOWN;
                m[ 0 ][ 0 ] = m00;
                m[ 0 ][ 1 ] = m01;
                m[ 0 ][ 2 ] = m02;
                m[ 0 ][ 3 ] = m03;
                m[ 1 ][ 0 ] = m10;
                m[ 1 ][ 1 ] = m11;
                m[ 1 ][ 2 ] = m12;
                m[ 1 ][ 3 ] = m13;
                m[ 2 ][ 0 ] = m20;
                m[ 2 ][ 1 ] = m21;
                m[ 2 ][ 2 ] = m22;
                m[ 2 ][ 3 ] = m23;
                m[ 3 ][ 0 ] = m30;
                m[ 3 ][ 1 ] = m31;
                m[ 3 ][ 2 ] = m32;
                m[ 3 ][ 3 ] = m33;
            }



            /*  inline Real* operator [] ( size_t iRow )
              {
               assert( iRow < 4 );
               mState = UNKNOWN;
               return m[ iRow ];
              }
            */
            inline const Real *const operator [] ( size_t iRow ) const
            {
                COLLADABU_ASSERT( iRow < 4 );
                return m[ iRow ];
            }

            inline Matrix4 concatenate( const Matrix4 &m2 ) const
            {
                Matrix4 r;
                r.m[ 0 ][ 0 ] = m[ 0 ][ 0 ] * m2.m[ 0 ][ 0 ] + m[ 0 ][ 1 ] * m2.m[ 1 ][ 0 ] + m[ 0 ][ 2 ] * m2.m[ 2 ][ 0 ] + m[ 0 ][ 3 ] * m2.m[ 3 ][ 0 ];
                r.m[ 0 ][ 1 ] = m[ 0 ][ 0 ] * m2.m[ 0 ][ 1 ] + m[ 0 ][ 1 ] * m2.m[ 1 ][ 1 ] + m[ 0 ][ 2 ] * m2.m[ 2 ][ 1 ] + m[ 0 ][ 3 ] * m2.m[ 3 ][ 1 ];
                r.m[ 0 ][ 2 ] = m[ 0 ][ 0 ] * m2.m[ 0 ][ 2 ] + m[ 0 ][ 1 ] * m2.m[ 1 ][ 2 ] + m[ 0 ][ 2 ] * m2.m[ 2 ][ 2 ] + m[ 0 ][ 3 ] * m2.m[ 3 ][ 2 ];
                r.m[ 0 ][ 3 ] = m[ 0 ][ 0 ] * m2.m[ 0 ][ 3 ] + m[ 0 ][ 1 ] * m2.m[ 1 ][ 3 ] + m[ 0 ][ 2 ] * m2.m[ 2 ][ 3 ] + m[ 0 ][ 3 ] * m2.m[ 3 ][ 3 ];

                r.m[ 1 ][ 0 ] = m[ 1 ][ 0 ] * m2.m[ 0 ][ 0 ] + m[ 1 ][ 1 ] * m2.m[ 1 ][ 0 ] + m[ 1 ][ 2 ] * m2.m[ 2 ][ 0 ] + m[ 1 ][ 3 ] * m2.m[ 3 ][ 0 ];
                r.m[ 1 ][ 1 ] = m[ 1 ][ 0 ] * m2.m[ 0 ][ 1 ] + m[ 1 ][ 1 ] * m2.m[ 1 ][ 1 ] + m[ 1 ][ 2 ] * m2.m[ 2 ][ 1 ] + m[ 1 ][ 3 ] * m2.m[ 3 ][ 1 ];
                r.m[ 1 ][ 2 ] = m[ 1 ][ 0 ] * m2.m[ 0 ][ 2 ] + m[ 1 ][ 1 ] * m2.m[ 1 ][ 2 ] + m[ 1 ][ 2 ] * m2.m[ 2 ][ 2 ] + m[ 1 ][ 3 ] * m2.m[ 3 ][ 2 ];
                r.m[ 1 ][ 3 ] = m[ 1 ][ 0 ] * m2.m[ 0 ][ 3 ] + m[ 1 ][ 1 ] * m2.m[ 1 ][ 3 ] + m[ 1 ][ 2 ] * m2.m[ 2 ][ 3 ] + m[ 1 ][ 3 ] * m2.m[ 3 ][ 3 ];

                r.m[ 2 ][ 0 ] = m[ 2 ][ 0 ] * m2.m[ 0 ][ 0 ] + m[ 2 ][ 1 ] * m2.m[ 1 ][ 0 ] + m[ 2 ][ 2 ] * m2.m[ 2 ][ 0 ] + m[ 2 ][ 3 ] * m2.m[ 3 ][ 0 ];
                r.m[ 2 ][ 1 ] = m[ 2 ][ 0 ] * m2.m[ 0 ][ 1 ] + m[ 2 ][ 1 ] * m2.m[ 1 ][ 1 ] + m[ 2 ][ 2 ] * m2.m[ 2 ][ 1 ] + m[ 2 ][ 3 ] * m2.m[ 3 ][ 1 ];
                r.m[ 2 ][ 2 ] = m[ 2 ][ 0 ] * m2.m[ 0 ][ 2 ] + m[ 2 ][ 1 ] * m2.m[ 1 ][ 2 ] + m[ 2 ][ 2 ] * m2.m[ 2 ][ 2 ] + m[ 2 ][ 3 ] * m2.m[ 3 ][ 2 ];
                r.m[ 2 ][ 3 ] = m[ 2 ][ 0 ] * m2.m[ 0 ][ 3 ] + m[ 2 ][ 1 ] * m2.m[ 1 ][ 3 ] + m[ 2 ][ 2 ] * m2.m[ 2 ][ 3 ] + m[ 2 ][ 3 ] * m2.m[ 3 ][ 3 ];

                r.m[ 3 ][ 0 ] = m[ 3 ][ 0 ] * m2.m[ 0 ][ 0 ] + m[ 3 ][ 1 ] * m2.m[ 1 ][ 0 ] + m[ 3 ][ 2 ] * m2.m[ 2 ][ 0 ] + m[ 3 ][ 3 ] * m2.m[ 3 ][ 0 ];
                r.m[ 3 ][ 1 ] = m[ 3 ][ 0 ] * m2.m[ 0 ][ 1 ] + m[ 3 ][ 1 ] * m2.m[ 1 ][ 1 ] + m[ 3 ][ 2 ] * m2.m[ 2 ][ 1 ] + m[ 3 ][ 3 ] * m2.m[ 3 ][ 1 ];
                r.m[ 3 ][ 2 ] = m[ 3 ][ 0 ] * m2.m[ 0 ][ 2 ] + m[ 3 ][ 1 ] * m2.m[ 1 ][ 2 ] + m[ 3 ][ 2 ] * m2.m[ 2 ][ 2 ] + m[ 3 ][ 3 ] * m2.m[ 3 ][ 2 ];
                r.m[ 3 ][ 3 ] = m[ 3 ][ 0 ] * m2.m[ 0 ][ 3 ] + m[ 3 ][ 1 ] * m2.m[ 1 ][ 3 ] + m[ 3 ][ 2 ] * m2.m[ 2 ][ 3 ] + m[ 3 ][ 3 ] * m2.m[ 3 ][ 3 ];

                return r;
            }

            /** Matrix concatenation using '*'.
            */
            inline Matrix4 operator * ( const Matrix4 &m2 ) const
            {
                if ( mState == ISIDENTITY )
                    return m2;

                if ( m2.mState == ISIDENTITY )
                    return * this;

                return concatenate( m2 );
            }

            /** Vector transformation using '*'.
            @remarks
            Transforms the given 3-D vector by the matrix, projecting the 
            result back into <i>w</i> = 1.
            @note
            This means that the initial <i>w</i> is considered to be 1.0,
            and then all the tree elements of the resulting 3-D vector are
            divided by the resulting <i>w</i>.
            */
            inline Vector3 operator * ( const Vector3 &v ) const
            {
                if ( mState == ISIDENTITY )
                    return v;

                Vector3 r;

                Real fInvW = 1.0 / ( m[ 3 ][ 0 ] * v.x + m[ 3 ][ 1 ] * v.y + m[ 3 ][ 2 ] * v.z + m[ 3 ][ 3 ] );

                r.x = ( m[ 0 ][ 0 ] * v.x + m[ 0 ][ 1 ] * v.y + m[ 0 ][ 2 ] * v.z + m[ 0 ][ 3 ] ) * fInvW;

                r.y = ( m[ 1 ][ 0 ] * v.x + m[ 1 ][ 1 ] * v.y + m[ 1 ][ 2 ] * v.z + m[ 1 ][ 3 ] ) * fInvW;

                r.z = ( m[ 2 ][ 0 ] * v.x + m[ 2 ][ 1 ] * v.y + m[ 2 ][ 2 ] * v.z + m[ 2 ][ 3 ] ) * fInvW;

                return r;
            }



            /** Matrix addition.
            */
            inline Matrix4 operator + ( const Matrix4 &m2 ) const
            {
                Matrix4 r;

                r.m[ 0 ][ 0 ] = m[ 0 ][ 0 ] + m2.m[ 0 ][ 0 ];
                r.m[ 0 ][ 1 ] = m[ 0 ][ 1 ] + m2.m[ 0 ][ 1 ];
                r.m[ 0 ][ 2 ] = m[ 0 ][ 2 ] + m2.m[ 0 ][ 2 ];
                r.m[ 0 ][ 3 ] = m[ 0 ][ 3 ] + m2.m[ 0 ][ 3 ];

                r.m[ 1 ][ 0 ] = m[ 1 ][ 0 ] + m2.m[ 1 ][ 0 ];
                r.m[ 1 ][ 1 ] = m[ 1 ][ 1 ] + m2.m[ 1 ][ 1 ];
                r.m[ 1 ][ 2 ] = m[ 1 ][ 2 ] + m2.m[ 1 ][ 2 ];
                r.m[ 1 ][ 3 ] = m[ 1 ][ 3 ] + m2.m[ 1 ][ 3 ];

                r.m[ 2 ][ 0 ] = m[ 2 ][ 0 ] + m2.m[ 2 ][ 0 ];
                r.m[ 2 ][ 1 ] = m[ 2 ][ 1 ] + m2.m[ 2 ][ 1 ];
                r.m[ 2 ][ 2 ] = m[ 2 ][ 2 ] + m2.m[ 2 ][ 2 ];
                r.m[ 2 ][ 3 ] = m[ 2 ][ 3 ] + m2.m[ 2 ][ 3 ];

                r.m[ 3 ][ 0 ] = m[ 3 ][ 0 ] + m2.m[ 3 ][ 0 ];
                r.m[ 3 ][ 1 ] = m[ 3 ][ 1 ] + m2.m[ 3 ][ 1 ];
                r.m[ 3 ][ 2 ] = m[ 3 ][ 2 ] + m2.m[ 3 ][ 2 ];
                r.m[ 3 ][ 3 ] = m[ 3 ][ 3 ] + m2.m[ 3 ][ 3 ];

                return r;
            }

            /** Matrix subtraction.
            */
            inline Matrix4 operator - ( const Matrix4 &m2 ) const
            {
                Matrix4 r;
                r.m[ 0 ][ 0 ] = m[ 0 ][ 0 ] - m2.m[ 0 ][ 0 ];
                r.m[ 0 ][ 1 ] = m[ 0 ][ 1 ] - m2.m[ 0 ][ 1 ];
                r.m[ 0 ][ 2 ] = m[ 0 ][ 2 ] - m2.m[ 0 ][ 2 ];
                r.m[ 0 ][ 3 ] = m[ 0 ][ 3 ] - m2.m[ 0 ][ 3 ];

                r.m[ 1 ][ 0 ] = m[ 1 ][ 0 ] - m2.m[ 1 ][ 0 ];
                r.m[ 1 ][ 1 ] = m[ 1 ][ 1 ] - m2.m[ 1 ][ 1 ];
                r.m[ 1 ][ 2 ] = m[ 1 ][ 2 ] - m2.m[ 1 ][ 2 ];
                r.m[ 1 ][ 3 ] = m[ 1 ][ 3 ] - m2.m[ 1 ][ 3 ];

                r.m[ 2 ][ 0 ] = m[ 2 ][ 0 ] - m2.m[ 2 ][ 0 ];
                r.m[ 2 ][ 1 ] = m[ 2 ][ 1 ] - m2.m[ 2 ][ 1 ];
                r.m[ 2 ][ 2 ] = m[ 2 ][ 2 ] - m2.m[ 2 ][ 2 ];
                r.m[ 2 ][ 3 ] = m[ 2 ][ 3 ] - m2.m[ 2 ][ 3 ];

                r.m[ 3 ][ 0 ] = m[ 3 ][ 0 ] - m2.m[ 3 ][ 0 ];
                r.m[ 3 ][ 1 ] = m[ 3 ][ 1 ] - m2.m[ 3 ][ 1 ];
                r.m[ 3 ][ 2 ] = m[ 3 ][ 2 ] - m2.m[ 3 ][ 2 ];
                r.m[ 3 ][ 3 ] = m[ 3 ][ 3 ] - m2.m[ 3 ][ 3 ];

                return r;
            }

            /** Tests 2 matrices for equality.
            */
            inline bool operator == ( const Matrix4& m2 ) const
            {
                if ( mState == ISIDENTITY && m2.mState == ISIDENTITY )
                    return true;

                return isEqualTo( m2 );
            }

            /** Tests 2 matrices for inequality.
            */
            inline bool operator != ( const Matrix4& m2 ) const
            {
                if ( ( mState != UNKNOWN ) && ( m2.mState != UNKNOWN ) && ( mState != m2.mState ) )
                    return true;

                return !isEqualTo( m2 );
            }

            /** Tests if the matrix is the identity matrix. This is the prefered method to check for identity*/
            inline bool isIdentiy() const
            {
                if ( mState == UNKNOWN )
                    mState = isEqualTo( IDENTITY ) ? ISIDENTITY : ISNOTIDENTITY;

                return mState == ISIDENTITY;
            }

            /** Assignment from 3x3 matrix.
            */
            inline void operator = ( const Matrix3& mat3 )
            {
                mState = UNKNOWN;
                m[ 0 ][ 0 ] = mat3.m[ 0 ][ 0 ];
                m[ 0 ][ 1 ] = mat3.m[ 0 ][ 1 ];
                m[ 0 ][ 2 ] = mat3.m[ 0 ][ 2 ];
                m[ 1 ][ 0 ] = mat3.m[ 1 ][ 0 ];
                m[ 1 ][ 1 ] = mat3.m[ 1 ][ 1 ];
                m[ 1 ][ 2 ] = mat3.m[ 1 ][ 2 ];
                m[ 2 ][ 0 ] = mat3.m[ 2 ][ 0 ];
                m[ 2 ][ 1 ] = mat3.m[ 2 ][ 1 ];
                m[ 2 ][ 2 ] = mat3.m[ 2 ][ 2 ];
            }

            inline Matrix4 transpose( void ) const
            {
                return Matrix4( m[ 0 ][ 0 ], m[ 1 ][ 0 ], m[ 2 ][ 0 ], m[ 3 ][ 0 ],
                                m[ 0 ][ 1 ], m[ 1 ][ 1 ], m[ 2 ][ 1 ], m[ 3 ][ 1 ],
                                m[ 0 ][ 2 ], m[ 1 ][ 2 ], m[ 2 ][ 2 ], m[ 3 ][ 2 ],
                                m[ 0 ][ 3 ], m[ 1 ][ 3 ], m[ 2 ][ 3 ], m[ 3 ][ 3 ] );
            }

            /*
            -----------------------------------------------------------------------
            Translation Transformation
            -----------------------------------------------------------------------
            */
            /** Sets the translation transformation part of the matrix.
            */
            inline void setTrans( const Vector3& v )
            {
                mState = UNKNOWN;
                m[ 0 ][ 3 ] = v.x;
                m[ 1 ][ 3 ] = v.y;
                m[ 2 ][ 3 ] = v.z;
            }

            /** Extracts the translation transformation part of the matrix.
            */
            inline Vector3 getTrans() const
            {
                return Vector3( m[ 0 ][ 3 ], m[ 1 ][ 3 ], m[ 2 ][ 3 ] );
            }


            /** Builds a translation matrix
            */
            inline void makeTrans( const Vector3& v )
            {
                makeTrans( v.x, v.y, v.z );
            }

            inline void makeTrans( Real tx, Real ty, Real tz )
            {
                setAllElements(
                    1.0, 0.0, 0.0, tx,
                    0.0, 1.0, 0.0, ty,
                    0.0, 0.0, 1.0, tz,
                    0.0, 0.0, 0.0, 1.0 );
            }


			/** Builds a scale matrix
			*/
			inline void makeScale( const Vector3& v )
			{
				makeScale( v.x, v.y, v.z );
			}

			/** Builds a scale matrix
			*/
			inline void makeScale( Real sx, Real sy, Real sz )
			{
				setAllElements(
					 sx, 0.0, 0.0, 0.0,
					0.0,  sy, 0.0, 0.0,
					0.0, 0.0,  sz, 0.0,
					0.0, 0.0, 0.0, 1.0 );
			}

			/** Gets a translation matrix.
            */
            inline static Matrix4 getTrans( const Vector3& v )
            {
                return getTrans( v.x, v.y, v.z );
            }

            /** Gets a translation matrix - variation for not using a vector.
            */
            inline static Matrix4 getTrans( Real t_x, Real t_y, Real t_z )
            {
                Matrix4 r(
                    1.0, 0.0, 0.0, t_x,
                    0.0, 1.0, 0.0, t_y,
                    0.0, 0.0, 1.0, t_z,
                    0.0, 0.0, 0.0, 1.0 );
                return r;
            }

            /** Scales the translation Part my @a scaleFactor*/
            inline void scaleTrans( Real scaleFactor )
            {
                m[ 0 ][ 3 ] = m[ 0 ][ 3 ] * scaleFactor;
                m[ 1 ][ 3 ] = m[ 1 ][ 3 ] * scaleFactor;
                m[ 2 ][ 3 ] = m[ 2 ][ 3 ] * scaleFactor;

            }

            /*
            -----------------------------------------------------------------------
            Scale Transformation
            -----------------------------------------------------------------------
            */
            /** Sets the scale part of the matrix.
            */
            inline void setScale( const Vector3& v )
            {
                mState = UNKNOWN;
                m[ 0 ][ 0 ] = v.x;
                m[ 1 ][ 1 ] = v.y;
                m[ 2 ][ 2 ] = v.z;
            }

            /** Gets a scale matrix.
            */
            inline static Matrix4 getScale( const Vector3& v )
            {
                return getScale( v.x, v.y, v.z );
            }

            /** Gets a scale matrix - variation for not using a vector.
            */
            inline static Matrix4 getScale( Real s_x, Real s_y, Real s_z )
            {
                Matrix4 r(
                    s_x, 0.0, 0.0, 0.0,
                    0.0, s_y, 0.0, 0.0,
                    0.0, 0.0, s_z, 0.0,
                    0.0, 0.0, 0.0, 1.0 );
                return r;
            }

            /* Returns a vector which represents the scale of the current matrix.
            see http://www.ogre3d.org/phpBB2/viewtopic.php?t=18978
            */
            inline Vector3 getScale() const
            {
                Vector3 col1( m[ 0 ][ 0 ], m[ 1 ][ 0 ], m[ 2 ][ 0 ] );
                Vector3 col2( m[ 0 ][ 1 ], m[ 1 ][ 1 ], m[ 2 ][ 1 ] );
                Vector3 col3( m[ 0 ][ 2 ], m[ 1 ][ 2 ], m[ 2 ][ 2 ] );

                Real scaleX = col1.length();
                Real scaleY = col2.length();
                Real scaleZ = col3.length();
                return Vector3( scaleX, scaleY, scaleZ );
            }

            /** Extracts the rotation / scaling part of the Matrix as a 3x3 matrix.
            @param m3x3 Destination Matrix3
            */
            inline void extract3x3Matrix( Matrix3& m3x3 ) const
            {
                m3x3.m[ 0 ][ 0 ] = m[ 0 ][ 0 ];
                m3x3.m[ 0 ][ 1 ] = m[ 0 ][ 1 ];
                m3x3.m[ 0 ][ 2 ] = m[ 0 ][ 2 ];
                m3x3.m[ 1 ][ 0 ] = m[ 1 ][ 0 ];
                m3x3.m[ 1 ][ 1 ] = m[ 1 ][ 1 ];
                m3x3.m[ 1 ][ 2 ] = m[ 1 ][ 2 ];
                m3x3.m[ 2 ][ 0 ] = m[ 2 ][ 0 ];
                m3x3.m[ 2 ][ 1 ] = m[ 2 ][ 1 ];
                m3x3.m[ 2 ][ 2 ] = m[ 2 ][ 2 ];

            }

            /** Extracts the rotation / scaling part as a quaternion from the Matrix.
            */
            inline Quaternion extractQuaternion() const
            {
                Matrix3 m3x3;
                extract3x3Matrix( m3x3 );
                return Quaternion( m3x3 );
            }

            void setRotate( Vector3 point, Real theta, Real phi, Real alpha );

            static const Matrix4 ZERO;
            static const Matrix4 IDENTITY;
            /** Useful little matrix which takes 2D clipspace {-1, 1} to {0,1}
            and inverts the Y. */
            static const Matrix4 CLIPSPACE2DTOIMAGESPACE;

            inline Matrix4 operator*( Real scalar )
            {
                return Matrix4(
                           scalar * m[ 0 ][ 0 ], scalar * m[ 0 ][ 1 ], scalar * m[ 0 ][ 2 ], scalar * m[ 0 ][ 3 ],
                           scalar * m[ 1 ][ 0 ], scalar * m[ 1 ][ 1 ], scalar * m[ 1 ][ 2 ], scalar * m[ 1 ][ 3 ],
                           scalar * m[ 2 ][ 0 ], scalar * m[ 2 ][ 1 ], scalar * m[ 2 ][ 2 ], scalar * m[ 2 ][ 3 ],
                           scalar * m[ 3 ][ 0 ], scalar * m[ 3 ][ 1 ], scalar * m[ 3 ][ 2 ], scalar * m[ 3 ][ 3 ] );
            }

            Matrix4 adjoint() const;
            Real determinant() const;
            Matrix4 inverse() const;
            void makeTransform( const Vector3& position, const Vector3& scale, const Quaternion& orientation );

        private:
            enum State
            {
                UNKNOWN,
                ISIDENTITY,
                ISNOTIDENTITY
            };

            /** Indicates if this matrix is known to be identity or not identity or if the state is unknown*/
            mutable State mState;

            /// The matrix entries, indexed by [row][col].
            union {
                Real m[ 4 ][ 4 ];
                Real _m[ 16 ];
            };

            /** This constructor allows to set the state of the matrix, i.e. if it is an identity matrix or not*/
            inline Matrix4(
                State state,
                Real m00, Real m01, Real m02, Real m03,
                Real m10, Real m11, Real m12, Real m13,
                Real m20, Real m21, Real m22, Real m23,
                Real m30, Real m31, Real m32, Real m33 )
                    : mState( state )
            {
                m[ 0 ][ 0 ] = m00;
                m[ 0 ][ 1 ] = m01;
                m[ 0 ][ 2 ] = m02;
                m[ 0 ][ 3 ] = m03;
                m[ 1 ][ 0 ] = m10;
                m[ 1 ][ 1 ] = m11;
                m[ 1 ][ 2 ] = m12;
                m[ 1 ][ 3 ] = m13;
                m[ 2 ][ 0 ] = m20;
                m[ 2 ][ 1 ] = m21;
                m[ 2 ][ 2 ] = m22;
                m[ 2 ][ 3 ] = m23;
                m[ 3 ][ 0 ] = m30;
                m[ 3 ][ 1 ] = m31;
                m[ 3 ][ 2 ] = m32;
                m[ 3 ][ 3 ] = m33;
            }


            /** Tests 2 matrices for equality. The test is performed, independent of the values of mState
            */
            inline bool isEqualTo( const Matrix4& m2 ) const
            {
                if (
                    m[ 0 ][ 0 ] != m2.m[ 0 ][ 0 ] || m[ 0 ][ 1 ] != m2.m[ 0 ][ 1 ] || m[ 0 ][ 2 ] != m2.m[ 0 ][ 2 ] || m[ 0 ][ 3 ] != m2.m[ 0 ][ 3 ] ||
                    m[ 1 ][ 0 ] != m2.m[ 1 ][ 0 ] || m[ 1 ][ 1 ] != m2.m[ 1 ][ 1 ] || m[ 1 ][ 2 ] != m2.m[ 1 ][ 2 ] || m[ 1 ][ 3 ] != m2.m[ 1 ][ 3 ] ||
                    m[ 2 ][ 0 ] != m2.m[ 2 ][ 0 ] || m[ 2 ][ 1 ] != m2.m[ 2 ][ 1 ] || m[ 2 ][ 2 ] != m2.m[ 2 ][ 2 ] || m[ 2 ][ 3 ] != m2.m[ 2 ][ 3 ] ||
                    m[ 3 ][ 0 ] != m2.m[ 3 ][ 0 ] || m[ 3 ][ 1 ] != m2.m[ 3 ][ 1 ] || m[ 3 ][ 2 ] != m2.m[ 3 ][ 2 ] || m[ 3 ][ 3 ] != m2.m[ 3 ][ 3 ] )
                    return false;

                return true;
            }



        };


    }
}

#endif //__COLLADABU_MATH_MATRIX4_H__
