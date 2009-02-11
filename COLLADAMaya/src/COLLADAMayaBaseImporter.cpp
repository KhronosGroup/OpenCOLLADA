#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseImporter.h"

namespace COLLADAMaya
{

    //-----------------------------
    MayaDM::double3 BaseImporter::toLinearUnit ( const MayaDM::double3& val )
    {
        if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::X_UP )
            return ( MayaDM::double3 ( toLinearUnit ( val[1] ), toLinearUnit ( val[0]*(-1) ), toLinearUnit ( val[2] ) ) );
        else if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
            return ( MayaDM::double3 ( toLinearUnit ( val[0] ), toLinearUnit ( val[2] ), toLinearUnit ( val[1]*(-1) ) ) );
        else return ( MayaDM::double3 ( toLinearUnit ( val[0] ), toLinearUnit ( val[1] ), toLinearUnit ( val[2] ) ) );
    }

    //-----------------------------
    MVector BaseImporter::toLinearUnit ( const MVector& val )
    {
        if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::X_UP )
            return ( MVector ( toLinearUnit ( val[1] ), toLinearUnit ( val[0]*(-1) ), toLinearUnit ( val[2] ) ) );
        else if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
            return ( MVector ( toLinearUnit ( val[0] ), toLinearUnit ( val[2] ), toLinearUnit ( val[1]*(-1) ) ) );
        else return ( MVector ( toLinearUnit ( val[0] ), toLinearUnit ( val[1] ), toLinearUnit ( val[2] ) ) );
    }

    //-----------------------------
    void BaseImporter::toLinearUnit ( const double val0, const double val1, const double val2, COLLADABU::Math::Vector3& retVal )
    {
        if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::X_UP )
        {
            retVal [0] = toLinearUnit ( val1 );
            retVal [1] = toLinearUnit ( val0*(-1) );
            retVal [2] = toLinearUnit ( val2 );
        }
        else if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
        {
            retVal [0] = toLinearUnit ( val0 );
            retVal [1] = toLinearUnit ( val2 );
            retVal [2] = toLinearUnit ( val1*(-1) );
        }
        else 
        {
            retVal [0] = toLinearUnit ( val0 );
            retVal [1] = toLinearUnit ( val1 );
            retVal [2] = toLinearUnit ( val2 );
        }
    }

} // namespace COLLADAMaya
