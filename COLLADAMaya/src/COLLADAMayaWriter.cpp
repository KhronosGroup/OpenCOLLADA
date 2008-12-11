/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaWriter.h"
//#include "COLLADAMayaVisualSceneImporter.h"
#include "COLLADAMayaGeometryImporter.h"

#include "Math/COLLADABUMathMatrix4.h"


namespace COLLADAMaya
{

    //-----------------------------
    void Writer::cancel ( const String& errorMessage )
    {

    }

    //-----------------------------
    void Writer::start ()
    {

    }

    //-----------------------------
    void Writer::finish ()
    {

    }

    //-----------------------------
    bool Writer::writeVisualScene ( const COLLADAFW::VisualScene* visualScene )
    {
//         VisualSceneImporter visualSceneImporter ( mDocumentImporter );
// 
//         return visualSceneImporter.importVisualScene ( visualScene );

        return false;
    }

    //-----------------------------
    bool Writer::writeGeometry ( const COLLADAFW::Geometry* geometry )
    {
        GeometryImporter geometryImporter ( mDocumentImporter );

        return geometryImporter.importGeometry ( geometry );
    }

} // namespace COLLADADH
