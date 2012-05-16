/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_MAYATRANSFORM_H__
#define __DAE2MA_MAYATRANSFORM_H__

#include "DAE2MAPrerequisites.h"


namespace DAE2MA
{

    /*
    *	Helper class, to handle the transformations.
    */
    class MayaTransform
    {
    public:

        enum RotationOrder {
            kXYZ, 
            kYZX, 
            kZXY, 
            kXZY, 
            kYXZ, 
            kZYX
        };

        typedef size_t TransformPhase;

    public:
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

        COLLADABU::Math::Vector3 translate1; // = 0,0,0
        std::vector<COLLADABU::Math::Vector3> translate1Vec;
        size_t numTranslate1;

        COLLADABU::Math::Vector3 jointOrient; // = 0,0,0
        COLLADABU::Math::Vector3 axisPhaseJointOrient1, axisPhaseJointOrient2, axisPhaseJointOrient3;

        COLLADABU::Math::Vector3 rotation; // = 0,0,0
        COLLADABU::Math::Vector3 axisPhaseRotate1, axisPhaseRotate2, axisPhaseRotate3;

        COLLADABU::Math::Vector3 rotateOrient; // = 0,0,0
        COLLADABU::Math::Vector3 axisPhaseRotateOrient1, axisPhaseRotateOrient2, axisPhaseRotateOrient3;

        COLLADABU::Math::Vector3 translate2; // = 0,0,0
        std::vector<COLLADABU::Math::Vector3> translate2Vec;
        size_t numTranslate2;

        COLLADABU::Math::Vector3 skew; // = 0,0,0
        COLLADABU::Math::Vector3 scale; // = 1,1,1

        COLLADABU::Math::Vector3 translate3; // = 0,0,0
        std::vector<COLLADABU::Math::Vector3> translate3Vec;
        size_t numTranslate3;

        // 5 phases
        TransformPhase phase;
    };


} // namespace DAE2MA

#endif // __DAE2MA_MAYATRANSFORM_H__
