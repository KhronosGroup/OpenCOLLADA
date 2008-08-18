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

        // Get a pointer to the animation exporter.
        AnimationExporter* animExpo = mDocumentExporter->getAnimationExporter();

        // Set the orthographic and perspective-specific parameters
        bool isOrthographic = cameraFn.isOrtho ( &status ); CHECK_MSTATUS(status);
        if (isOrthographic)
        {
            // Create a orthographic projection optic
            optics = new COLLADA::OrthographicOptic ( streamWriter );

            double width = cameraFn.orthoWidth(&status); CHECK_MSTATUS(status);
            optics->setAspectRatio( (float) cameraFn.aspectRatio( &status ) ); CHECK_MSTATUS(status);
            if ( animExpo->addNodeAnimation( cameraFn.object(), XMAG_SID, ATTR_ORTHOGRAPHIC_WIDTH, kSingle ) )
                optics->setXMag ( (float) width / 2.0f, XMAG_SID );
            else optics->setXMag ( (float) width / 2.0f );
        }
        else
        {
            // Create a perspective projection optic
            optics = new COLLADA::PerspectiveOptic ( streamWriter );

            if ( ExportOptions::cameraYFov() )
            {
                FocalLengthConverter* converter = new FocalLengthConverter ( (float) cameraFn.verticalFilmAperture() );
                float verticalFilmAperture = (float) cameraFn.verticalFilmAperture();
                float focalLength = (*converter) ( ( float ) cameraFn.focalLength ( &status ) ); CHECK_MSTATUS(status);
                if ( animExpo->addNodeAnimation( cameraFn.object(), YFOV_SID, ATTR_FOCAL_LENGTH, kSingle, EMPTY_PARAMETER, -1, false, converter ) )
                    optics->setYFov ( focalLength, YFOV_SID ); 
                else optics->setYFov ( focalLength ); 
            }
            if ( ExportOptions::cameraXFov() || !ExportOptions::cameraYFov() )
            {
                FocalLengthConverter* converter = new FocalLengthConverter( (float) (cameraFn.horizontalFilmAperture() * cameraFn.lensSqueezeRatio()));
                float focalLength = (*converter) ( ( float ) cameraFn.focalLength ( &status ) ); CHECK_MSTATUS(status);
                if ( animExpo->addNodeAnimation( cameraFn.object(), XFOV_SID, ATTR_FOCAL_LENGTH, kSingle, EMPTY_PARAMETER, -1, false, converter ) )
                    optics->setXFov ( focalLength, XFOV_SID ); 
                else optics->setXFov ( focalLength ); 
            }
            if ( !ExportOptions::cameraXFov() || !ExportOptions::cameraYFov() )
            {
                optics->setAspectRatio ( (float) cameraFn.aspectRatio(&status) ); CHECK_MSTATUS(status);
            }
        }

        // Add the camera common parameters.
        // Convert the  maya internal unit type from centimeters into the working units of the current scene!
        double zNear = MDistance::internalToUI ( cameraFn.nearClippingPlane ( &status ) ); CHECK_MSTATUS ( status );
        if ( animExpo->addNodeAnimation( cameraFn.object(), NEAR_CLIP_SID, ATTR_NEAR_CLIP_PLANE, kSingle | kLength ) )
            optics->setZNear ( (float) zNear, NEAR_CLIP_SID ); 
        else optics->setZNear ( (float) zNear ); 

        // Convert the  maya internal unit type from centimeters into the working units of the current scene!
        double zFar = MDistance::internalToUI ( cameraFn.farClippingPlane ( &status ) ); CHECK_MSTATUS ( status );
        if ( animExpo->addNodeAnimation( cameraFn.object(), FAR_CLIP_SID, ATTR_FAR_CLIP_PLANE, kSingle | kLength ) )
            optics->setZFar ( (float) zFar, FAR_CLIP_SID ); 
        else optics->setZFar ( (float) zFar ); 

        // Generate a COLLADA id for the new camera object
        String cameraId = mDocumentExporter->dagPathToColladaId ( dagPath );
        String cameraName = mDocumentExporter->dagPathToColladaName ( dagPath );

        // Create the camera
        COLLADA::Camera camera ( streamWriter, optics, cameraId, cameraName );

        // Add the Maya-specific parameters
        double vAperture = cameraFn.verticalFilmAperture ( &status ) * 2.54f; CHECK_MSTATUS(status);
        if ( animExpo->addNodeAnimation( cameraFn.object(), VERTICAL_APERTURE_SID, ATTR_VERTICAL_FILM_APERTURE, 
            kSingle | kLength, EMPTY_PARAMETER, -1, false, new ConversionScaleFunctor(2.54f) ) )
            camera.addExtraTechniqueParameter( MAYA_PROFILE, MAYA_VAPERTURE_PARAMETER, vAperture, VERTICAL_APERTURE_SID );
        else camera.addExtraTechniqueParameter( MAYA_PROFILE, MAYA_VAPERTURE_PARAMETER, vAperture );

         double hAperture = cameraFn.horizontalFilmAperture ( &status ) * 2.54f; CHECK_MSTATUS(status);
         if ( animExpo->addNodeAnimation( cameraFn.object(), HORIZONTAL_APERTURE_SID, ATTR_HORIZONTAL_FILM_APERTURE, 
             kSingle | kLength, EMPTY_PARAMETER, -1, false, new ConversionScaleFunctor(2.54f) ) )
             camera.addExtraTechniqueParameter( MAYA_PROFILE, MAYA_HAPERTURE_PARAMETER, hAperture, HORIZONTAL_APERTURE_SID );
         else camera.addExtraTechniqueParameter( MAYA_PROFILE, MAYA_HAPERTURE_PARAMETER, hAperture );
 
         double lensSqueeze = cameraFn.lensSqueezeRatio ( &status ); CHECK_MSTATUS(status);
         if ( animExpo->addNodeAnimation( cameraFn.object(), LENS_SQUEEZE_SID, ATTR_LENS_SQUEEZE_RATIO, kSingle ) ) 
             camera.addExtraTechniqueParameter( MAYA_PROFILE, MAYA_LENS_SQUEEZE_PARAMETER, lensSqueeze, LENS_SQUEEZE_SID );
         else camera.addExtraTechniqueParameter( MAYA_PROFILE, MAYA_LENS_SQUEEZE_PARAMETER, lensSqueeze );

        int filmFit = cameraFn.filmFit ( &status ); CHECK_MSTATUS(status);
        camera.addExtraTechniqueParameter( MAYA_PROFILE, MAYA_FILM_FIT_PARAMETER, filmFit ); 

        double filmFitOffset = cameraFn.filmFitOffset ();
        if ( animExpo->addNodeAnimation( cameraFn.object(), FILM_FIT_OFFSET_SID, ATTR_FILM_FIT_OFFSET, kSingle ) ) 
         camera.addExtraTechniqueParameter( MAYA_PROFILE, MAYA_FILM_FIT_OFFSET_PARAMETER, filmFitOffset, FILM_FIT_OFFSET_SID ); 
        else camera.addExtraTechniqueParameter( MAYA_PROFILE, MAYA_FILM_FIT_OFFSET_PARAMETER, filmFitOffset ); 

        double filmOffsetX = cameraFn.horizontalFilmOffset ();
        if ( animExpo->addNodeAnimation( cameraFn.object(), HORIZONTAL_FILM_OFFSET_SID, ATTR_HORIZONTAL_FILM_OFFSET, kSingle, XYZ_PARAMETERS ) ) 
            camera.addExtraTechniqueParameter( MAYA_PROFILE, MAYA_FILM_OFFSET_X_PARAMETER, filmOffsetX, HORIZONTAL_FILM_OFFSET_SID ); 
        else camera.addExtraTechniqueParameter( MAYA_PROFILE, MAYA_FILM_OFFSET_X_PARAMETER, filmOffsetX ); 

        double filmOffsetY = cameraFn.verticalFilmOffset ();
        if ( animExpo->addNodeAnimation( cameraFn.object(), VERTICAL_FILM_OFFSET_SID, ATTR_FILM_FIT_OFFSET, kSingle, XYZ_PARAMETERS ) ) 
            camera.addExtraTechniqueParameter( MAYA_PROFILE, MAYA_FILM_OFFSET_Y_PARAMETER, filmOffsetY, VERTICAL_FILM_OFFSET_SID ); 
        else camera.addExtraTechniqueParameter( MAYA_PROFILE, MAYA_FILM_OFFSET_Y_PARAMETER, filmOffsetY ); 

        // Write the camera data in the collada document.
        addCamera ( camera );

        return true;
    }

}