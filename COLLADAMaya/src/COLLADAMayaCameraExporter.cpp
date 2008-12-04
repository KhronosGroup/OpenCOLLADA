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
#include "COLLADAMayaAnimationExporter.h"
#include "COLLADAMayaSyntax.h"

#include <maya/MFnCamera.h>


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    CameraExporter::CameraExporter ( 
        COLLADASW::StreamWriter* streamWriter,
        DocumentExporter* documentExporter )
    : COLLADASW::LibraryCameras ( streamWriter )
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
        size_t length = exportNodesTree->size();
        for ( size_t i=0; i<length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];
            exportCameras ( sceneElement );
        }

        closeLibrary();
    }

    //---------------------------------------------------------------
    void CameraExporter::exportCameras ( SceneElement* sceneElement )
    {
        // If we have a external reference, we don't need to export the data here.
        if ( !sceneElement->getIsLocal() ) return;

        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();

        // Check for instance
        bool isInstance = ( dagPath.isInstanced() && dagPath.instanceNumber() > 0 );

        // Check if it is a camera and an export node
        if ( sceneElement->getType() == SceneElement::CAMERA &&
             sceneElement->getIsExportNode() && !isInstance )
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
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Figure out the type of camera optic and create it
        COLLADASW::BaseOptic* optics = NULL;

        // Get a pointer to the animation exporter.
        AnimationExporter* anim = mDocumentExporter->getAnimationExporter();
        bool animated = false;

        // Set the orthographic and perspective-specific parameters
        bool isOrthographic = cameraFn.isOrtho ( &status ); CHECK_MSTATUS(status);
        if (isOrthographic)
        {
            // Create a orthographic projection optic
            optics = new COLLADASW::OrthographicOptic ( streamWriter );

            double width = cameraFn.orthoWidth(&status); CHECK_MSTATUS(status);
            optics->setAspectRatio( (float) cameraFn.aspectRatio( &status ) ); CHECK_MSTATUS(status);

            animated = anim->addNodeAnimation( cameraFn.object(), XMAG_SID, ATTR_ORTHOGRAPHIC_WIDTH, kSingle );
            optics->setXMag ( (float) width / 2.0f, animated );
        }
        else
        {
            // Create a perspective projection optic
            optics = new COLLADASW::PerspectiveOptic ( streamWriter );

            bool setXFov = ExportOptions::cameraXFov();
            bool setYFov = ExportOptions::cameraYFov();

            if ( ExportOptions::cameraYFov() )
            {
                FocalLengthConverter* converter = new FocalLengthConverter ( (float) cameraFn.verticalFilmAperture() );
//                 float verticalFilmAperture = (float) cameraFn.verticalFilmAperture();
//                 float focalLength = (*converter) ( ( float ) cameraFn.focalLength ( &status ) ); CHECK_MSTATUS(status);
                float verticalFieldOfViewRad = ( float ) cameraFn.verticalFieldOfView ( &status );
                float verticalFieldOfViewDeg = COLLADABU::Math::Utils::radToDegF ( verticalFieldOfViewRad );
                animated = anim->addNodeAnimation( cameraFn.object(), YFOV_SID, ATTR_FOCAL_LENGTH, kSingle, EMPTY_PARAMETER, false, -1, false, converter );
                optics->setYFov ( verticalFieldOfViewDeg, animated ); 
//                optics->setYFov ( focalLength, animated ); 
            }
            if ( ExportOptions::cameraXFov() || !ExportOptions::cameraYFov() )
            {
                FocalLengthConverter* converter = new FocalLengthConverter( (float) (cameraFn.horizontalFilmAperture() * cameraFn.lensSqueezeRatio()));
//                 float fl = cameraFn.focalLength ( &status );
//                 float focalLength = (*converter) ( ( float ) cameraFn.focalLength ( &status ) ); CHECK_MSTATUS(status);
                float horizontalFieldOfViewRad = ( float ) cameraFn.horizontalFieldOfView ( &status );
                float horizontalFieldOfViewDeg = COLLADABU::Math::Utils::radToDegF ( horizontalFieldOfViewRad );
                animated = anim->addNodeAnimation( cameraFn.object(), XFOV_SID, ATTR_FOCAL_LENGTH, kSingle, EMPTY_PARAMETER, false, -1, false, converter );
                optics->setXFov ( horizontalFieldOfViewDeg, animated ); 
//                optics->setXFov ( focalLength, animated ); 
            }
            if ( !ExportOptions::cameraXFov() || !ExportOptions::cameraYFov() )
            {
                optics->setAspectRatio ( (float) cameraFn.aspectRatio(&status) ); CHECK_MSTATUS(status);
            }
        }

        // Add the camera common parameters.
        // Convert the  maya internal unit type from centimeters into the working units of the current scene!
        double zNear = MDistance::internalToUI ( cameraFn.nearClippingPlane ( &status ) ); CHECK_MSTATUS ( status );
        animated = anim->addNodeAnimation( cameraFn.object(), NEAR_CLIP_SID, ATTR_NEAR_CLIP_PLANE, ( SampleType ) ( kSingle | kLength ), EMPTY_PARAMETER, true );
        optics->setZNear ( (float) zNear, animated ); 

        // Convert the  maya internal unit type from centimeters into the working units of the current scene!
        double zFar = MDistance::internalToUI ( cameraFn.farClippingPlane ( &status ) ); CHECK_MSTATUS ( status );
        animated = anim->addNodeAnimation( cameraFn.object(), FAR_CLIP_SID, ATTR_FAR_CLIP_PLANE, ( SampleType ) ( kSingle | kLength ), EMPTY_PARAMETER, true );
        optics->setZFar ( (float) zFar, animated ); 

        // Generate a COLLADA id for the new camera object
        String cameraId = mDocumentExporter->dagPathToColladaId ( dagPath );
        String cameraName = mDocumentExporter->dagPathToColladaName ( dagPath );

        // Create the camera
        COLLADASW::Camera camera ( streamWriter, optics, cameraId, cameraName );
        String paramSid = "";

        // Add the Maya-specific parameters
        double vAperture = cameraFn.verticalFilmAperture ( &status ) * 2.54f; CHECK_MSTATUS(status);
        animated = anim->addNodeAnimation( cameraFn.object(), VERTICAL_APERTURE_SID, ATTR_VERTICAL_FILM_APERTURE, 
            ( SampleType ) ( kSingle | kLength ), EMPTY_PARAMETER, false, -1, false, new ConversionScaleFunctor(2.54f) );
        paramSid = ""; if ( animated ) paramSid = VERTICAL_APERTURE_SID;
        camera.addExtraTechniqueParameter( COLLADASW::CSWC::CSW_PROFILE_MAYA, MAYA_VAPERTURE_PARAMETER, vAperture, paramSid );

        double hAperture = cameraFn.horizontalFilmAperture ( &status ) * 2.54f; CHECK_MSTATUS(status);
        animated = anim->addNodeAnimation( cameraFn.object(), HORIZONTAL_APERTURE_SID, ATTR_HORIZONTAL_FILM_APERTURE, 
            ( SampleType ) ( kSingle | kLength ), EMPTY_PARAMETER, false, -1, false, new ConversionScaleFunctor(2.54f) );
        paramSid = ""; if ( animated ) paramSid = HORIZONTAL_APERTURE_SID;
        camera.addExtraTechniqueParameter( COLLADASW::CSWC::CSW_PROFILE_MAYA, MAYA_HAPERTURE_PARAMETER, hAperture, paramSid );
 
        double lensSqueeze = cameraFn.lensSqueezeRatio ( &status ); CHECK_MSTATUS(status);
        animated = anim->addNodeAnimation( cameraFn.object(), LENS_SQUEEZE_SID, ATTR_LENS_SQUEEZE_RATIO, kSingle );
        paramSid = ""; if ( animated ) paramSid = LENS_SQUEEZE_SID;
        camera.addExtraTechniqueParameter( COLLADASW::CSWC::CSW_PROFILE_MAYA, MAYA_LENS_SQUEEZE_PARAMETER, lensSqueeze, paramSid );

        int filmFit = cameraFn.filmFit ( &status ); CHECK_MSTATUS(status);
        camera.addExtraTechniqueParameter( COLLADASW::CSWC::CSW_PROFILE_MAYA, MAYA_FILM_FIT_PARAMETER, filmFit ); 

        double filmFitOffset = cameraFn.filmFitOffset ();
        animated = anim->addNodeAnimation( cameraFn.object(), FILM_FIT_OFFSET_SID, ATTR_FILM_FIT_OFFSET, kSingle );
        paramSid = ""; if ( animated ) paramSid = FILM_FIT_OFFSET_SID;
        camera.addExtraTechniqueParameter( COLLADASW::CSWC::CSW_PROFILE_MAYA, MAYA_FILM_FIT_OFFSET_PARAMETER, filmFitOffset, paramSid ); 

        double filmOffsetX = cameraFn.horizontalFilmOffset ();
        animated = anim->addNodeAnimation( cameraFn.object(), HORIZONTAL_FILM_OFFSET_SID, ATTR_HORIZONTAL_FILM_OFFSET, kSingle, XYZ_PARAMETERS );
        paramSid = ""; if ( animated ) paramSid = HORIZONTAL_FILM_OFFSET_SID;
        camera.addExtraTechniqueParameter( COLLADASW::CSWC::CSW_PROFILE_MAYA, MAYA_FILM_OFFSET_X_PARAMETER, filmOffsetX, paramSid ); 

        double filmOffsetY = cameraFn.verticalFilmOffset ();
        animated = anim->addNodeAnimation( cameraFn.object(), VERTICAL_FILM_OFFSET_SID, ATTR_FILM_FIT_OFFSET, kSingle, XYZ_PARAMETERS );
        paramSid = ""; if ( animated ) paramSid = VERTICAL_FILM_OFFSET_SID;
        camera.addExtraTechniqueParameter( COLLADASW::CSWC::CSW_PROFILE_MAYA, MAYA_FILM_OFFSET_Y_PARAMETER, filmOffsetY, paramSid ); 

        // Write the camera data in the collada document.
        addCamera ( camera );

        return true;
    }

}