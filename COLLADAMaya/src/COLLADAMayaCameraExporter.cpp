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
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaCameraExporter.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaConversion.h"

#include <maya/MFnCamera.h>


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    CameraExporter::CameraExporter ( 
        COLLADA::StreamWriter* streamWriter,
        DocumentExporter* documentExporter )
    : COLLADA::LibraryCameras ( streamWriter )
    , mDocumentExporter ( documentExporter )
    {}


    //---------------------------------------------------------------
    void CameraExporter::exportCameras ( )
    {
        if ( !ExportOptions::exportCameras() ) return;

        // Get the list with the transform nodes.
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

        // Export all/selected DAG nodes
        uint length = exportNodesTree->size();
        for ( uint i = 0; i < length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];
            exportCameras ( sceneElement );
        }

        closeLibrary();
    }

    //---------------------------------------------------------------
    void CameraExporter::exportCameras ( SceneElement* sceneElement )
    {
        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();

        // Check if it is a camera and an export node
        if ( sceneElement->getType() == SceneElement::CAMERA &&
             sceneElement->getIsExportNode() )
        {
            // Export the geometry 
            bool exported = exportCamera ( dagPath );

            // Push it in the list of exported elements.
            if ( exported )
                mDocumentExporter->getSceneGraph()->addExportedElement( sceneElement );
        }


        // Recursive call for all the child elements
        for ( uint i=0; i<sceneElement->getChildCount(); ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );
            exportCameras ( childElement );
        }
    }

    // --------------------------------------------------------
    bool CameraExporter::exportCamera ( const MDagPath& dagPath )
    {
        if ( !ExportOptions::exportCameras() ) return false;

        MObject cameraNode = dagPath.node();

        // Retrieve the Maya camera object
        MStatus status;
        MFnCamera cameraFn(cameraNode, &status); CHECK_MSTATUS(status);
        if (status != MStatus::kSuccess) return false;

        // Get the stream writer
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Figure out the type of camera optic and create it
        COLLADA::BaseOptic* optics = NULL;

        // Set the orthographic and perspective-specific parameters
        bool isOrthographic = cameraFn.isOrtho(&status); CHECK_MSTATUS(status);
        if (isOrthographic)
        {
            // Create a orthographic projection optic
            optics = new COLLADA::OrthographicOptic ( streamWriter );

            double width = cameraFn.orthoWidth(&status); CHECK_MSTATUS(status);
            optics->setXMag ( (float) width / 2.0f );
            optics->setAspectRatio( (float) cameraFn.aspectRatio( &status ) ); CHECK_MSTATUS(status);
//            ANIM->AddPlugAnimation(cameraFn.object(), "orthographicWidth", colladaCamera->GetMagX(), kSingle);
        }
        else
        {
            // Create a perspective projection optic
            optics = new COLLADA::PerspectiveOptic ( streamWriter );

            if ( ExportOptions::cameraYFov() )
            {
                FocalLengthConverter* converter = new FocalLengthConverter((float) cameraFn.verticalFilmAperture());
                optics->setYFov ( (*converter) ( (float)cameraFn.focalLength(&status) ) ); CHECK_MSTATUS(status);
//                ANIM->AddPlugAnimation(cameraFn.object(), "focalLength", colladaCamera->getYFov(), kSingle, converter);
            }
            if ( ExportOptions::cameraXFov() || !ExportOptions::cameraYFov() )
            {
                FocalLengthConverter* converter = new FocalLengthConverter( (float)(cameraFn.horizontalFilmAperture() * cameraFn.lensSqueezeRatio()));
                optics->setXFov ( (*converter) ( (float)cameraFn.focalLength(&status) ) ); CHECK_MSTATUS(status);
//                ANIM->AddPlugAnimation(cameraFn.object(), "focalLength", colladaCamera->GetFovX(), kSingle, converter);
            }
            if ( !ExportOptions::cameraXFov() || !ExportOptions::cameraYFov() )
            {
                optics->setAspectRatio ( (float)cameraFn.aspectRatio(&status) ); CHECK_MSTATUS(status);
            }
        }

        // Add the camera common parameters.
        optics->setZNear ( (float)cameraFn.nearClippingPlane(&status) ); CHECK_MSTATUS(status);
//        ANIM->AddPlugAnimation(cameraFn.object(), "nearClipPlane", colladaCamera->GetNearZ(), kSingle | kLength);

        optics->setZFar ( (float)cameraFn.farClippingPlane(&status) ); CHECK_MSTATUS(status);
//        ANIM->AddPlugAnimation(cameraFn.object(), "farClipPlane", colladaCamera->GetFarZ(), kSingle | kLength);

        // Generate a COLLADA id for the new camera object
        String cameraId = mDocumentExporter->dagPathToColladaId ( dagPath );
        String cameraName = mDocumentExporter->dagPathToColladaName ( dagPath );

        // Create the camera
        COLLADA::Camera camera ( streamWriter, optics, cameraId, cameraName );

        // Add the Maya-specific parameters
//         FCDETechnique* colladaMayaTechnique = colladaCamera->GetExtra()->GetDefaultType()->AddTechnique(DAEMAYA_MAYA_PROFILE);
// 
//         float vAperture = (float) cameraFn.verticalFilmAperture(&status) * 2.54f; CHECK_MSTATUS(status);
//         FCDENode* vApertureNode = colladaMayaTechnique->AddParameter(DAEMAYA_VAPERTURE_PARAMETER, vAperture);
//         ANIM->AddPlugAnimation(cameraFn.object(), "verticalFilmAperture", vApertureNode->GetAnimated(), 
//             kSingle | kLength, new FCDConversionScaleFunctor(2.54f));
// 
//         float hAperture = (float) cameraFn.horizontalFilmAperture(&status) * 2.54f; CHECK_MSTATUS(status);
//         FCDENode* hApertureNode = colladaMayaTechnique->AddParameter(DAEMAYA_HAPERTURE_PARAMETER, hAperture);
//         ANIM->AddPlugAnimation(cameraFn.object(), "horizontalFilmAperture", hApertureNode->GetAnimated(),
//             kSingle | kLength, new FCDConversionScaleFunctor(2.54f));
// 
//         float lensSqueeze = (float) cameraFn.lensSqueezeRatio(&status); CHECK_MSTATUS(status);
//         FCDENode* lensSqueezeNode = colladaMayaTechnique->AddParameter(DAEMAYA_LENSSQUEEZE_PARAMETER, lensSqueeze);
//         ANIM->AddPlugAnimation(cameraFn.object(), "lensSqueezeRatio", lensSqueezeNode->GetAnimated(), kSingle);
// 
//         colladaMayaTechnique->AddParameter(DAEMAYA_CAMERA_FILMFIT, (int32) cameraFn.filmFit(&status)); CHECK_MSTATUS(status);
// 
//         FCDENode* filmFitOffset = colladaMayaTechnique->AddParameter(DAEMAYA_CAMERA_FILMFITOFFSET, (float) cameraFn.filmFitOffset());
//         ANIM->AddPlugAnimation(cameraFn.object(), "filmFitOffset", filmFitOffset->GetAnimated(), kSingle);
// 
//         FCDENode* filmOffsetX = colladaMayaTechnique->AddParameter(DAEMAYA_CAMERA_FILMOFFSETX, (float) cameraFn.horizontalFilmOffset());
//         ANIM->AddPlugAnimation(cameraFn.object(), "horizontalFilmOffset", filmOffsetX->GetAnimated(), kSingle);
// 
//         FCDENode* filmOffsetY = colladaMayaTechnique->AddParameter(DAEMAYA_CAMERA_FILMOFFSETY, (float) cameraFn.verticalFilmOffset());
//         ANIM->AddPlugAnimation(cameraFn.object(), "verticalFilmOffset", filmOffsetY->GetAnimated(), kSingle);
        
        addCamera ( camera );

        return true;
    }

}