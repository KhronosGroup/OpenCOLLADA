/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#ifndef __COLLADA_MAYA_VISUAL_SCENE_EXPORTER_H__
#define __COLLADA_MAYA_VISUAL_SCENE_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADALibraryVisualScenes.h"
#include "COLLADAStreamWriter.h"
#include "COLLADANode.h"

#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaSceneElement.h"

#include <maya/MDagPath.h>
#include <maya/MFnTransform.h>


class DocumentExporter;

namespace COLLADAMaya
{

    /**
     * Exports the data of the visual scene.
     */

    class VisualSceneExporter : public COLLADA::LibraryVisualScenes
    {

    private:

        /** Flag, if the current node is a joint. */
        bool isJoint;

        /** Flag, if we handle the first rotation. */
        bool mIsFirstRotation;

        /** The id of the current scene. */
        const String& mSceneId;

        /** Pointer to the document exporter. */
        DocumentExporter* mDocumentExporter;

        /** Flag if the visual scene library is already added. */
        bool visualSceneAdded;

        /** A pointer to the actual visual scene node. */
        COLLADA::Node* mVisualSceneNode;

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
        VisualSceneExporter ( COLLADA::StreamWriter* streamWriter,
                              DocumentExporter* documentExporter,
                              const String& sceneId = "" );
        /**
         * Destructor.
         */
        virtual ~VisualSceneExporter() {};

        /** Exports the visual scene with the transforms of all included elements */
        void exportVisualScenes();

    private:

        /**
         * Exports all the nodes in a node and all its child nodes recursive.
         * @param sceneElement The node to export.
         * @param isLocal todo
         */
        bool exportVisualSceneNodes ( SceneElement* sceneElement, bool& isLocal );

        /**
         * Creates and opens a visual scene node of type node and writes the transforms
         * and the references to the geometries and materials of the current scene element.
         * @param sceneNode The collada node to write.
         * @param sceneElement The node to export.
         */
        bool exportNodeVisualSceneNode ( COLLADA::Node* sceneNode, const SceneElement* sceneElement );

        /**
        * Creates and opens a visual scene node of type joint and writes the transforms
        * and the references to the geometries and materials of the current scene element.
        * @param sceneNode The collada node.
        * @param dagPath The node to export.
        */
        bool exportJointVisualSceneNode ( COLLADA::Node* sceneNode, const SceneElement* sceneElement );

        /**
        * Creates and opens a visual scene node and writes the transforms
        * and the references to the geometries and materials of the current scene element.
        * @param sceneNode The collada node to write.
        * @param sceneElement The node to export.
        */
        bool exportVisualSceneNode ( COLLADA::Node* sceneNode, const SceneElement* sceneElement );

        /**
         * Initializes the transform objects.
         * @param dagPath The path to the transform object.
         * @return bool True, if the initialisation was successfull.
         */
        bool initializeTransform ( const MDagPath &dagPath );

        /**
         * Prepares a new the visual scene node.
         * @param dagPath The
         */
        void openVisualSceneNode ( const MDagPath &dagPath );

        /**
         * Compute local space parameters and export them. These parameters are:
         * - Eye position
         * - Interest point
         * - Up-axis direction
         */
        void exportLookatTransform();

        /** Exports all transforms */
        void exportDecomposedTransform();

        /** Exports the translation */
        void exportTranslation ( const String name, const MPoint& translation, bool animation );
        void exportTranslation ( const String name, const MVector& translation, bool animation );

        /** Exports the translation in matrix style */
        void exportMatrixTransform();

        /** Exports the Rotation */
        void exportRotation ( const String name, const MEulerRotation& rotation );

        /** Exports the scale */
        void exportScale();

        /** Exports the skew */
        void exportSkew ( double* shear );

        /** Exports the visibility technique tag and the visibility animation.  */
        void exportVisibility ( COLLADA::Node* sceneNode );
    };

}

#endif //__COLLADA_MAYA_VISUAL_SCENE_EXPORTER_H__
