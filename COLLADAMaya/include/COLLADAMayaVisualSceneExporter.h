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

#ifndef __COLLADA_MAYA_VISUAL_SCENE_EXPORTER_H__
#define __COLLADA_MAYA_VISUAL_SCENE_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADASWLibraryVisualScenes.h"
#include "COLLADASWStreamWriter.h"
#include "COLLADASWNode.h"
#include "COLLADASWInstanceMaterial.h"

#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaSceneElement.h"

#include "COLLADABUIDList.h"

#include <maya/MDagPath.h>
#include <maya/MFnTransform.h>


class DocumentExporter;

namespace COLLADAMaya
{

    /**
     * Exports the transform data of the visual scene.
     * 
     * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     * All transform components with units will be in maya's internal units 
     * (radians for rotations and centimeters for translations).
     * We have to translate them into the working units of the current scene!
     * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     */

    class VisualSceneExporter : public COLLADASW::LibraryVisualScenes
    {

    private:

        /**
        * The list of the unique collada ids.
        */
        COLLADABU::IDList mNodeIdList;

        /** Flag, if the current node is a joint. */
        bool mIsJoint;

        /** Flag, if we handle the first rotation. 
        Make sure to export the rotation order correctly by always enforcing
        the elements of the first rotation. */
        bool mIsFirstRotation;

        /** The id of the current scene. */
        const String& mSceneId;

        /** Pointer to the document exporter. */
        DocumentExporter* mDocumentExporter;

        /** Flag if the visual scene library is already added. */
        bool mVisualSceneAdded;

        /** A pointer to the actual visual scene node. */
        COLLADASW::Node* mVisualSceneNode;

        /** Pointer to the current scene element. */
        SceneElement* mSceneElement;

        /** The path of the current node. */
        MDagPath mDagPath;

        /** The current transform object. */
        MObject mTransformObject;

        /** The current transform matrix. */
        MTransformationMatrix mTransformMatrix;

    public:

        /**
         * Constructor
         * @param streamWriter Pointer to the collada stream writer.
         * @param documentExporter Pointer to the main document exporter.
         * @param sceneId Name of the current scene to export. Has an empty string as default value.
         */
        VisualSceneExporter ( COLLADASW::StreamWriter* streamWriter,
                              DocumentExporter* documentExporter,
                              const String& sceneId = "" );
        /**
         * Destructor.
         */
        virtual ~VisualSceneExporter() {};

        /** Exports the visual scene with the transforms of all included elements */
        bool exportVisualScenes();

    private:

        /**
         * Exports all the nodes in a node and all its child nodes recursive.
         * @param sceneElement The node to export.
         */
        bool exportVisualSceneNodes ( SceneElement* sceneElement );

        /**
         * Creates and opens a visual scene node of type node and writes the transforms
         * and the references to the geometries and materials of the current scene element.
         * @param sceneNode The collada node to write.
         * @param sceneElement The node to export.
         */
        bool exportNodeVisualSceneNode ( COLLADASW::Node* sceneNode, const SceneElement* sceneElement );

        /**
        * Creates and opens a visual scene node of type joint and writes the transforms
        * and the references to the geometries and materials of the current scene element.
        * @param sceneNode The collada node.
        * @param dagPath The node to export.
        */
        bool exportJointVisualSceneNode ( COLLADASW::Node* sceneNode, const SceneElement* sceneElement );

        /**
        * Creates and opens a visual scene node and writes the transforms
        * and the references to the geometries and materials of the current scene element.
        * @param sceneNode The collada node to write.
        * @param sceneElement The node to export.
        */
        bool exportVisualSceneNode ( COLLADASW::Node* sceneNode, const SceneElement* sceneElement );

        void exportChildNodeInstances( const SceneElement* sceneElement );
        /**
         * Exports the geometry instances of the given transform scene element.
         * @param childElement The transform scene element.
         */
        void exportGeometryInstance( SceneElement* sceneElement );

        /**
        * Exports the skin controller instances of the given transform scene element.
        * @param childElement The transform scene element.
         */
        void exportControllerInstance( 
            SceneElement* childElement, 
            const bool hasSkinController, 
            const bool hasMorphController );

        /**
        * Exports the light instances of the given transform scene element.
        * @param childElement The transform scene element.
         */
        void exportLightInstance ( const SceneElement* childElement );

        /**
         * Creates the uri for the scene element. Checks for instances 
         * and creates the right element.
         */
        COLLADASW::URI getSceneElementURI ( const SceneElement* sceneElement, const String& elementId = "" );

        /**
        * Exports the camera instances of the given transform scene element.
        * @param childElement The transform scene element.
        */
        void exportCameraInstance ( const SceneElement* childElement );

        /**
         * Exports the material instances.
         * @param instanceMaterialList The instance list to fill.
         * @param childDagPath The path of the current node to export the material instances.
         * @param instanceNumber The current instance number of the shape.
         */
        void exportMaterialList( 
            COLLADASW::InstanceMaterialList &instanceMaterialList, 
            const MDagPath &dagPath );
        
        /**
         * Initializes the transform objects.
         * @param dagPath The path to the transform object.
         * @return bool True, if the initialisation was successfull.
         */
        bool initializeTransform ( const MDagPath &dagPath );

        /**
         * Prepares a new the visual scene node.
         * @param sceneElement The scene element of the node.
         */
        void openVisualSceneNode ( const SceneElement *sceneElement );

        /**
         * Compute local space parameters and export them. These parameters are:
         * - Eye position
         * - Interest point
         * - Up-axis direction
         */
        void exportLookatTransform ();

        /** Exports all transforms */
        void exportDecomposedTransform ();

        /** Exports the translation */
        void exportTranslation ( const String name, const MPoint& translation, bool animation );
        void exportTranslation ( const String name, const MVector& translation, bool animation );

        /** Exports the translation in matrix style */
        void exportMatrixTransform ();

        /** Exports the Rotation */
        void exportRotation ( const String name, const MEulerRotation& rotation );

        /** Exports the scale */
        void exportScale();

        /** Exports the skew */
        void exportSkew ( double* shear );

        /**
         * Exports the visibility technique tag and the visibility animation.
         * A hidden visual scene node will not be rendered but will
         * still affect the world. This parameter is a floating-point value
         * because it is animated. It should be intepreted as a Boolean value.
         * @param sceneNode The collada scene node to export the values.
         */
        void exportVisibility ( COLLADASW::Node* sceneNode );

        /**
         * @todo documentation
         * @param sceneElement
         * @param instantiate
         * @return bool
         */
        bool enterDagNode( const SceneElement* sceneElement, bool instantiate );

        /**
         * Exports a node instance of the current scene element.
         * @param sceneElement The scene element to instantiate.
         */
        void exportNodeInstance ( const SceneElement* sceneElement );

    };

}

#endif //__COLLADA_MAYA_VISUAL_SCENE_EXPORTER_H__
