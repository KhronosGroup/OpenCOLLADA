/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_MAYATRANSFORM_H__
#define __COLLADAMAYA_MAYATRANSFORM_H__

#include "COLLADAMayaPrerequisites.h"


namespace COLLADAMaya
{

    /*
    *	Helper class, to handle the transformations.
    */
    class MayaTransform
    {
    public:

        typedef size_t TransformPhase;

        MayaTransform () 
            : phase (0)
            , translate1 ( 0,0,0 ) 
            , translate1Vec (0)
            , numTranslate1 (0)
            , rotation ( 0,0,0 )
            , axisPhaseRotate1 ( 0,0,0 )
            , axisPhaseRotate2 ( 0,0,0 )
            , axisPhaseRotate3 ( 0,0,0 )
            , translate2 ( 0,0,0 ) 
            , translate2Vec (0)
            , numTranslate2 (0)
            , skew ( 0,0,0 )
            , scale ( 1,1,1 ) 
            , translate3 ( 0,0,0 ) 
            , translate3Vec (0)
            , numTranslate3 (0)
        {}
        virtual ~MayaTransform () {}

        static const size_t PHASE_TRANS1            = 1;
        static const size_t PHASE_JOINT_ORIENT1     = 2;
        static const size_t PHASE_JOINT_ORIENT2     = 3;
        static const size_t PHASE_JOINT_ORIENT3     = 4;
        static const size_t PHASE_ROTATE1           = 5;
        static const size_t PHASE_ROTATE2           = 6;
        static const size_t PHASE_ROTATE3           = 7;
        static const size_t PHASE_ROTATE_ORIENT1    = 8;
        static const size_t PHASE_ROTATE_ORIENT2    = 9;
        static const size_t PHASE_ROTATE_ORIENT3    = 10;
        static const size_t PHASE_TRANS2            = 11;
        static const size_t PHASE_SCALE             = 12;
        static const size_t PHASE_TRANS3            = 13;

        MVector translate1; // = 0,0,0
        std::vector<MVector> translate1Vec;
        size_t numTranslate1;

        MEulerRotation jointOrient; // = 0,0,0
        COLLADABU::Math::Vector3 axisPhaseJointOrient1, axisPhaseJointOrient2, axisPhaseJointOrient3;

        MEulerRotation rotation; // = 0,0,0
        COLLADABU::Math::Vector3 axisPhaseRotate1, axisPhaseRotate2, axisPhaseRotate3;

        MEulerRotation rotateOrient; // = 0,0,0
        COLLADABU::Math::Vector3 axisPhaseRotateOrient1, axisPhaseRotateOrient2, axisPhaseRotateOrient3;

        MVector translate2; // = 0,0,0
        std::vector<MVector> translate2Vec;
        size_t numTranslate2;

        MVector skew; // = 0,0,0
        MVector scale; // = 1,1,1

        MVector translate3; // = 0,0,0
        std::vector<MVector> translate3Vec;
        size_t numTranslate3;

        // 5 phases
        TransformPhase phase;
    };


} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_MAYATRANSFORM_H__
