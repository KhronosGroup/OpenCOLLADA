/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COMMONBU_MATH_MATRIX3_H__
#define __COMMONBU_MATH_MATRIX3_H__

#include "COLLADABUMathPrerequisites.h"
#include "COLLADABUMathVector3.h"
#include <memory>
#include <string.h>

// NOTE.  The (x,y,z) coordinate system is assumed to be right-handed.
// Coordinate axis rotation matrices are of the form
//   RX =    1       0       0
//           0     cos(t) -sin(t)
//           0     sin(t)  cos(t)
// where t > 0 indicates a counterclockwise rotation in the yz-plane
//   RY =  cos(t)    0     sin(t)
//           0       1       0
//        -sin(t)    0     cos(t)
// where t > 0 indicates a counterclockwise rotation in the zx-plane
//   RZ =  cos(t) -sin(t)    0
//         sin(t)  cos(t)    0
//           0       0       1
// where t > 0 indicates a counterclockwise rotation in the xy-plane.

namespace COLLADABU
{
    namespace Math
    {
		class Vector3;
        /** A 3x3 matrix which can represent rotations around axes.
            @note
                <b>All the code is adapted from the Wild Magic 0.2 Matrix
                library (http://www.magic-software.com).</b>
            @par
                The coordinate system is assumed to be <b>right-handed</b>.
        */

        class  Matrix3
        {

        public:
            /** Default constructor.
                @note
                    It does <b>NOT</b> initialize the matrix for efficiency.
            */
            inline Matrix3 ()
            {}

            ;
            inline explicit Matrix3 ( const Real arr[ 3 ][ 3 ] )
            {
                memcpy( m, arr, 9 * sizeof( Real ) );
            }

            inline Matrix3 ( const Matrix3& rkMatrix )
            {
                memcpy( m, rkMatrix.m, 9 * sizeof( Real ) );
            }

            Matrix3 ( Real fEntry00, Real fEntry01, Real fEntry02,
                      Real fEntry10, Real fEntry11, Real fEntry12,
                      Real fEntry20, Real fEntry21, Real fEntry22 )
            {
                m[ 0 ][ 0 ] = fEntry00;
                m[ 0 ][ 1 ] = fEntry01;
                m[ 0 ][ 2 ] = fEntry02;
                m[ 1 ][ 0 ] = fEntry10;
                m[ 1 ][ 1 ] = fEntry11;
                m[ 1 ][ 2 ] = fEntry12;
                m[ 2 ][ 0 ] = fEntry20;
                m[ 2 ][ 1 ] = fEntry21;
                m[ 2 ][ 2 ] = fEntry22;
            }

            inline void setAllElements(
                Real fEntry00, Real fEntry01, Real fEntry02,
                Real fEntry10, Real fEntry11, Real fEntry12,
                Real fEntry20, Real fEntry21, Real fEntry22 )
            {
                m[ 0 ][ 0 ] = fEntry00;
                m[ 0 ][ 1 ] = fEntry01;
                m[ 0 ][ 2 ] = fEntry02;
                m[ 1 ][ 0 ] = fEntry10;
                m[ 1 ][ 1 ] = fEntry11;
                m[ 1 ][ 2 ] = fEntry12;
                m[ 2 ][ 0 ] = fEntry20;
                m[ 2 ][ 1 ] = fEntry21;
                m[ 2 ][ 2 ] = fEntry22;
            }



            // member access, allows use of construct mat[r][c]
            inline Real* operator[] ( size_t iRow ) const
            {
                return ( Real* ) m[ iRow ];
            }

            /*inline operator Real* ()
            {
            return (Real*)m[0];
            }*/

            Vector3 getColumn ( size_t iCol ) const;
            void setColumn( size_t iCol, const Vector3& vec );
            void fromAxes( const Vector3& xAxis, const Vector3& yAxis, const Vector3& zAxis );

            // assignment and comparison
            inline Matrix3& operator= ( const Matrix3& rkMatrix )
            {
                memcpy( m, rkMatrix.m, 9 * sizeof( Real ) );
                return *this;
            }

            bool operator== ( const Matrix3& rkMatrix ) const;

            inline bool operator!= ( const Matrix3& rkMatrix ) const
            {
                return !operator==( rkMatrix );
            }

            // arithmetic operations
            Matrix3 operator+ ( const Matrix3& rkMatrix ) const;
            Matrix3 operator- ( const Matrix3& rkMatrix ) const;
            Matrix3 operator* ( const Matrix3& rkMatrix ) const;
            Matrix3 operator- () const;

            // matrix * vector [3x3 * 3x1 = 3x1]
            Vector3 operator* ( const Vector3& rkVector ) const;

            // vector * matrix [1x3 * 3x3 = 1x3]
            friend Vector3 operator* ( const Vector3& rkVector,
                                       const Matrix3& rkMatrix );

            // matrix * scalar
            Matrix3 operator* ( Real fScalar ) const;

            // scalar * matrix
            friend Matrix3 operator* ( Real fScalar, const Matrix3& rkMatrix );

            // utilities
            Matrix3 transpose () const;
            bool inverse ( Matrix3& rkInverse, Real fTolerance = 1e-06 ) const;
            Matrix3 inverse ( Real fTolerance = 1e-06 ) const;
            Real determinant () const;

            // singular value decomposition
            void singularValueDecomposition ( Matrix3& rkL, Vector3& rkS,
                                              Matrix3& rkR ) const;
            void singularValueComposition ( const Matrix3& rkL,
                                            const Vector3& rkS, const Matrix3& rkR );

            // Gram-Schmidt orthonormalization (applied to columns of rotation matrix)
            void orthonormalize ();

            // orthogonal Q, diagonal D, upper triangular U stored as (u01,u02,u12)
            void qDUDecomposition ( Matrix3& rkQ, Vector3& rkD,
                                    Vector3& rkU ) const;

            Real spectralNorm () const;

            // matrix must be orthonormal
            void toAxisAngle ( Vector3& rkAxis, Real& rfAngle_radian ) const;

            void fromAxisAngle ( const Vector3& rkAxis, const Real& fRadians_radian );

            // The matrix must be orthonormal.  The decomposition is yaw*pitch*roll
            // where yaw is rotation about the Up vector, pitch is rotation about the
            // Right axis, and roll is rotation about the Direction axis.
            bool toEulerAnglesXYZ ( Real& rfYAngle_radian, Real& rfPAngle_radian,
                                    Real& rfRAngle_radian ) const;
            bool toEulerAnglesXZY ( Real& rfYAngle_radian, Real& rfPAngle_radian,
                                    Real& rfRAngle_radian ) const;
            bool toEulerAnglesYXZ ( Real& rfYAngle_radian, Real& rfPAngle_radian,
                                    Real& rfRAngle_radian ) const;
            bool toEulerAnglesYZX ( Real& rfYAngle_radian, Real& rfPAngle_radian,
                                    Real& rfRAngle_radian ) const;
            bool toEulerAnglesZXY ( Real& rfYAngle_radian, Real& rfPAngle_radian,
                                    Real& rfRAngle_radian ) const;
            bool toEulerAnglesZYX ( Real& rfYAngle_radian, Real& rfPAngle_radian,
                                    Real& rfRAngle_radian ) const;
            void fromEulerAnglesXYZ ( const Real& fYAngle_radian, const Real& fPAngle_radian, const Real& fRAngle_radian );
            void fromEulerAnglesXZY ( const Real& fYAngle_radian, const Real& fPAngle_radian, const Real& fRAngle_radian );
            void fromEulerAnglesYXZ ( const Real& fYAngle_radian, const Real& fPAngle_radian, const Real& fRAngle_radian );
            void fromEulerAnglesYZX ( const Real& fYAngle_radian, const Real& fPAngle_radian, const Real& fRAngle_radian );
            void fromEulerAnglesZXY ( const Real& fYAngle_radian, const Real& fPAngle_radian, const Real& fRAngle_radian );
            void fromEulerAnglesZYX ( const Real& fYAngle_radian, const Real& fPAngle_radian, const Real& fRAngle_radian );

            // eigensolver, matrix must be symmetric
            void eigenSolveSymmetric ( Real afEigenvalue[ 3 ],
                                       Vector3 akEigenvector[ 3 ] ) const;

            static void tensorProduct ( const Vector3& rkU, const Vector3& rkV,
                                        Matrix3& rkProduct );

            static const Real EPSILON;
            static const Matrix3 ZERO;
            static const Matrix3 IDENTITY;

        protected:
            // support for eigensolver
            void tridiagonal ( Real afDiag[ 3 ], Real afSubDiag[ 3 ] );
            bool qLAlgorithm ( Real afDiag[ 3 ], Real afSubDiag[ 3 ] );

            // support for singular value decomposition
            static const Real ms_fSvdEpsilon;
            static const unsigned int ms_iSvdMaxIterations;
            static void bidiagonalize ( Matrix3& kA, Matrix3& kL,
                                        Matrix3& kR );
            static void golubKahanStep ( Matrix3& kA, Matrix3& kL,
                                         Matrix3& kR );

            // support for spectral norm
            static Real maxCubicRoot ( Real afCoeff[ 3 ] );

            Real m[ 3 ][ 3 ];

            // for faster access

            friend class Matrix4;

        public:
            /* Returns a vector which represents the scale of the current matrix.
               see http://www.ogre3d.org/phpBB2/viewtopic.php?t=18978
            */
            inline Vector3 getScale();
        };
    }
}

#endif //__COMMONBU_MATH_MATRIX3_H__
