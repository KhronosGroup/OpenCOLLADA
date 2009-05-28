/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseImporter.h"

#include "Math/COLLADABUMathUtils.h"


namespace COLLADAMaya
{

    /** The maya block size value for writing maya ascii files. */
    const size_t BaseImporter::MAYA_BLOCK_SIZE = 4000;

    /** The standard name for the collada id attribute. */
    const String BaseImporter::COLLADA_ID_ATTRIBUTE_NAME = "colladaId";

    /** The standard name for a group without name. */
    const String BaseImporter::GROUP_ID_NAME = "GroupId";
    const String BaseImporter::GROUP_PARTS_NAME = "GroupParts";


    //-----------------------------
    double BaseImporter::toLinearUnit ( const double val )
    {
        return ( val * mDocumentImporter->getLinearUnitConvertFactor () );
    }

    //-----------------------------
    float BaseImporter::toLinearUnit ( const float val )
    {
        return ( val * (float) mDocumentImporter->getLinearUnitConvertFactor () );
    }

    //-----------------------------
    MayaDM::double3 BaseImporter::toLinearUnit ( const MayaDM::double3& val )
    {
//         if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::X_UP )
//             return ( MayaDM::double3 ( toLinearUnit ( val[1]*(-1) ), toLinearUnit ( val[0] ), toLinearUnit ( val[2] ) ) );
//         else if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
//             return ( MayaDM::double3 ( toLinearUnit ( val[0] ), toLinearUnit ( val[2] ), toLinearUnit ( val[1]*(-1) ) ) );
//         else return ( MayaDM::double3 ( toLinearUnit ( val[0] ), toLinearUnit ( val[1] ), toLinearUnit ( val[2] ) ) );
        return ( MayaDM::double3 ( toLinearUnit ( val[0] ), toLinearUnit ( val[1] ), toLinearUnit ( val[2] ) ) );
    }

    //-----------------------------
    MayaDM::double3 BaseImporter::toAngularUnit ( const MayaDM::double3& val )
    {
//         if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::X_UP )
//             return ( MayaDM::double3 ( COLLADABU::Math::Utils::radToDeg ( val[1]*(-1) ), COLLADABU::Math::Utils::radToDeg ( val[0] ), COLLADABU::Math::Utils::radToDeg ( val[2] ) ) );
//         else if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
//             return ( MayaDM::double3 ( COLLADABU::Math::Utils::radToDeg ( val[0] ), COLLADABU::Math::Utils::radToDeg ( val[2] ), COLLADABU::Math::Utils::radToDeg ( val[1]*(-1) ) ) );
//         else return ( MayaDM::double3 ( COLLADABU::Math::Utils::radToDeg ( val[0] ), COLLADABU::Math::Utils::radToDeg ( val[1] ), COLLADABU::Math::Utils::radToDeg ( val[2] ) ) );
        return ( MayaDM::double3 ( COLLADABU::Math::Utils::radToDeg ( val[0] ), COLLADABU::Math::Utils::radToDeg ( val[1] ), COLLADABU::Math::Utils::radToDeg ( val[2] ) ) );
    }

    //-----------------------------
    MVector BaseImporter::toLinearUnit ( const MVector& val )
    {
//         if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::X_UP )
//             return ( MVector ( toLinearUnit ( val[1]*(-1) ), toLinearUnit ( val[0] ), toLinearUnit ( val[2] ) ) );
//         else if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
//             return ( MVector ( toLinearUnit ( val[0] ), toLinearUnit ( val[2] ), toLinearUnit ( val[1]*(-1) ) ) );
//         else return ( MVector ( toLinearUnit ( val[0] ), toLinearUnit ( val[1] ), toLinearUnit ( val[2] ) ) );
        return ( MVector ( toLinearUnit ( val[0] ), toLinearUnit ( val[1] ), toLinearUnit ( val[2] ) ) );
    }

    //-----------------------------
    void BaseImporter::toLinearUnit ( const double val0, const double val1, const double val2, COLLADABU::Math::Vector3& retVal )
    {
//         if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::X_UP )
//         {
//             retVal [0] = toLinearUnit ( val1*(-1) );
//             retVal [1] = toLinearUnit ( val0 );
//             retVal [2] = toLinearUnit ( val2 );
//         }
//         else if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
//         {
//             retVal [0] = toLinearUnit ( val0 );
//             retVal [1] = toLinearUnit ( val2 );
//             retVal [2] = toLinearUnit ( val1*(-1) );
//         }
//         else 
        {
            retVal [0] = toLinearUnit ( val0 );
            retVal [1] = toLinearUnit ( val1 );
            retVal [2] = toLinearUnit ( val2 );
        }
    }

//     //-----------------------------
//     MayaDM::double3 BaseImporter::toUpAxisTypeAxis ( const MayaDM::double3& val )
//     {
//         if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::X_UP )
//             return ( MayaDM::double3 ( val[1]*(-1), val[0], val[2] ) );
//         else if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
//             return ( MayaDM::double3 ( val[0], val[2], val[1]*(-1) ) );
//         else return ( MayaDM::double3 ( val[0], val[1], val[2] ) );
//     }
// 
//     //-----------------------------
//     MayaDM::double3 BaseImporter::toUpAxisTypeFactor ( const MayaDM::double3& val )
//     {
//         if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::X_UP )
//             return ( MayaDM::double3 ( val[1], val[0], val[2] ) );
//         else if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
//             return ( MayaDM::double3 ( val[0], val[2], val[1] ) );
//         else return ( MayaDM::double3 ( val[0], val[1], val[2] ) );
//     }

    // -----------------------------------
    void BaseImporter::convertMatrix4ToTransposedDouble4x4 ( 
        const COLLADABU::Math::Matrix4& inputMatrix, 
        double outputMatrix[][4], 
        const double tolerance )
    {
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][0],tolerance)) outputMatrix[0][0] = 0.0;
        else outputMatrix[0][0] = inputMatrix[0][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][1],tolerance)) outputMatrix[1][0] = 0.0;
        else outputMatrix[1][0] = inputMatrix[0][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][2],tolerance)) outputMatrix[2][0] = 0.0;
        else outputMatrix[2][0] = inputMatrix[0][2];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][3],tolerance)) outputMatrix[3][0] = 0.0;
        else outputMatrix[3][0] = inputMatrix[0][3];

        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][0],tolerance)) outputMatrix[0][1] = 0.0;
        else outputMatrix[0][1] = inputMatrix[1][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][1],tolerance)) outputMatrix[1][1] = 0.0;
        else outputMatrix[1][1] = inputMatrix[1][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][2],tolerance)) outputMatrix[2][1] = 0.0;
        else outputMatrix[2][1] = inputMatrix[1][2];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][3],tolerance)) outputMatrix[3][1] = 0.0;
        else outputMatrix[3][1] = inputMatrix[1][3];

        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][0],tolerance)) outputMatrix[0][2] = 0.0;
        else outputMatrix[0][2] = inputMatrix[2][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][1],tolerance)) outputMatrix[1][2] = 0.0;
        else outputMatrix[1][2] = inputMatrix[2][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][2],tolerance)) outputMatrix[2][2] = 0.0;
        else outputMatrix[2][2] = inputMatrix[2][2];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][3],tolerance)) outputMatrix[3][2] = 0.0;
        else outputMatrix[3][2] = inputMatrix[2][3];

        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][0],tolerance)) outputMatrix[0][3] = 0.0;
        else outputMatrix[0][3] = inputMatrix[3][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][1],tolerance)) outputMatrix[1][3] = 0.0;
        else outputMatrix[1][3] = inputMatrix[3][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][2],tolerance)) outputMatrix[2][3] = 0.0;
        else outputMatrix[2][3] = inputMatrix[3][2];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][3],tolerance)) outputMatrix[3][3] = 0.0;
        else outputMatrix[3][3] = inputMatrix[3][3];
    }

    //------------------------------
    double BaseImporter::getDoubleValue ( 
        const COLLADAFW::FloatOrDoubleArray &inputValuesArray, 
        const size_t position )
    {
        double inputValue = 0;

        size_t numInputValues = inputValuesArray.getValuesCount ();
        if ( position > numInputValues - 1 )
            MGlobal::displayError ("Out of range error!");

        const COLLADAFW::FloatOrDoubleArray::DataType& inputDataType = inputValuesArray.getType ();
        switch ( inputDataType )
        {
        case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE:
            {
                const COLLADAFW::DoubleArray* inputValues = inputValuesArray.getDoubleValues ();
                inputValue = (*inputValues) [position];
            }
            break;
        case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT:
            {
                const COLLADAFW::FloatArray* inputValues = inputValuesArray.getFloatValues ();
                inputValue = (double)(*inputValues) [position];
            }
            break;
        default:
            MGlobal::displayError ( "AnimationImporter::setInTangents(): inputDataType unknown data type!" );
        }

        return inputValue;
    }


} // namespace COLLADAMaya
