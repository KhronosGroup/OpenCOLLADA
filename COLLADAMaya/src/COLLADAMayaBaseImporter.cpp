/*
    Copyright (c) 2008 NetAllied Systems GmbH

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

    /** The standard name for the collada id attribute. */
    const String BaseImporter::COLLADA_ID_ATTRIBUTE_NAME = "colladaId";


    //-----------------------------
    double BaseImporter::toLinearUnit ( const double val )
    {
        return ( val * mDocumentImporter->getLinearUnitMeter () );
    }

    //-----------------------------
    float BaseImporter::toLinearUnit ( const float val )
    {
        return ( val * (float) mDocumentImporter->getLinearUnitMeter () );
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

} // namespace COLLADAMaya
