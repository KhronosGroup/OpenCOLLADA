/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_DOCUMENT_EXPORTER_H__
#define __COLLADA_MAYA_DOCUMENT_EXPORTER_H__

#include "ColladaMayaPrerequisites.h"
#include "COLLADAStreamWriter.h"


namespace COLLADAMaya
{

    class SceneGraph;
    class MaterialExporter;
    class EffectExporter;
    class EffectTextureExporter;
    class ImageExporter;
    class GeometryExporter;
    class VisualSceneExporter;
    class AnimationExporter;
    class AnimationClipExporter;
    class AnimationSampleCache;
    class ControllerExporter;

    /**
     * The main exporter class. This class exports all data of the scene.
     */

    class DocumentExporter
    {

    private:

        /** Manages the maya scene graph */
        SceneGraph* mSceneGraph;

        /** Manages the cache for the animations. */
        AnimationSampleCache* mAnimationCache;

        /** Exports the materials. */
        MaterialExporter* mMaterialExporter;

        /** Exports the effects. */
        EffectExporter* mEffectExporter;

        /** Exports the images. */
        ImageExporter* mImageExporter;

        /** Exports the geometry. */
        GeometryExporter* mGeometryExporter;

        /** Exports the visual scene. */
        VisualSceneExporter* mVisualSceneExporter;

        /** Exports the animations. */
        AnimationExporter* mAnimationExporter;

        /** Exports the animation clips. */
        AnimationClipExporter* mAnimationClipExporter;

        /** Handles the controllers. */
        ControllerExporter* mControllerLibrary;

        /*
        CAnimCache* animCache;
        DaeAgeiaPhysicsScene* ageiaPhysicsScene;
        DaeAnimationLibrary* animationLibrary;
        DaeAnimClipLibrary* animClipLibrary;
        DaeCameraLibrary* cameraLibrary;
        DaeControllerLibrary* controllerLibrary;
        DaeEmitterLibrary* emitterLibrary;
        DaeForceFieldLibrary* forceFieldLibrary;
        DaeEntityManager* entityManager;
        DaeGeometryLibrary* geometryLibrary;
        DaeLightLibrary* lightLibrary;
        DaeMaterialLibrary* materialLibrary;
        DaeNativePhysicsScene* nativePhysicsScene;
        DaeTextureLibrary* textureLibrary;
        DaePhysicsMaterialLibrary* physicsMaterialLibrary;
        DaePhysicsModelLibrary* physicsModelLibrary;
        DaePhysicsSceneLibrary* physicsSceneLibrary;
        */

        /** The name of the collada file. */
        const String mFileName;

        /** The stream writer, to write the collada document. */
        COLLADA::StreamWriter mStreamWriter;

        /** true, if we import a collada file. */
        bool mIsImport;

        /** The id of the current scene. */
        String mSceneId;

        // Length Conversion Factor
        float mUnitFactor;

    public:

        /**
         * Constructor.
         * @param _fileName Name of the collada file.
         */
        DocumentExporter ( const String& _fileName );
        virtual ~DocumentExporter();

        /**
         * Returns a pointer to the scene graph.
         * @return SceneGraph* Pointer to the scene graph
         */
        inline SceneGraph* getSceneGraph()
        {
            return mSceneGraph;
        }

        /**
         * Returns the name of the current collada file to export.
         * @return const String& Name of the current collada file
         */
        inline const String& getFilename() const
        {
            return mFileName;
        }

        /**
        * Returns a pointer to the collada stream writer.
        * @return SceneGraph* Pointer to the collada stream writer
        */
        inline COLLADA::StreamWriter* getStreamWriter()
        {
            return &mStreamWriter;
        }

        /**
        * Returns a pointer to the animation cache.
        * @return MaterialExporter* Pointer to the animation cache
        */
        AnimationSampleCache* getAnimationCache()
        {
            return mAnimationCache;
        }

        /**
         * Returns a pointer to the material exporter.
         * @return MaterialExporter* Pointer to the material exporter
         */
        MaterialExporter* getMaterialExporter()
        {
            return mMaterialExporter;
        }

        /**
        * Returns a pointer to the effect exporter.
        * @return MaterialExporter* Pointer to the effect exporter
        */
        EffectExporter* getEffectExporter()
        {
            return mEffectExporter;
        }

        /**
        * Returns a pointer to the image exporter.
        * @return MaterialExporter* Pointer to the image exporter
        */
        ImageExporter* getImageExporter()
        {
            return mImageExporter;
        }

        /**
        * Returns a pointer to the geometry exporter.
        * @return MaterialExporter* Pointer to the geometry exporter
        */
        GeometryExporter* getGeometryExporter()
        {
            return mGeometryExporter;
        }

        /**
        * Returns a pointer to the visual scene exporter.
        * @return MaterialExporter* Pointer to the visual scene exporter
        */
        VisualSceneExporter* getVisualSceneExporter()
        {
            return mVisualSceneExporter;
        }

        /**
        * Returns a pointer to the animation exporter.
        * @return MaterialExporter* Pointer to the animation exporter
        */
        AnimationExporter* getAnimationExporter()
        {
            return mAnimationExporter;
        }

        /**
        * Returns a pointer to the animation clip exporter.
        * @return MaterialExporter* Pointer to the animation clip exporter
        */
        AnimationClipExporter* getAnimationClipExporter()
        {
            return mAnimationClipExporter;
        }

        /**
        * Returns a pointer to the controller library.
        * @return ControllerLibrary* Pointer to the controller library
        */
        ControllerExporter* getControllerLibrary()
        {
            return mControllerLibrary;
        }

        // Create COLLADA names and ids
        /**
         * Converts the given string to a valid collada string.
         * @param str String to convert
         * @param removeNamespace True, if the namespace should be removed.
         * @return MString Maya string with the converted string.
         */
        String mayaNameToColladaName ( const MString& str, bool removeNamespace=true );
        /**
         * Make an unique COLLADA Id from a dagPath.
         * @param dagPath The dag path to convert.
         * @return MString The converted collada id.
         */
        String dagPathToColladaId ( const MDagPath& dagPath );
        /**
         * Get a COLLADA suitable node name from a DAG path
         * @param dagPath The dag path to convert.
         * @return MString The converted collada name.
         */
        String dagPathToColladaName ( const MDagPath& dagPath );

        /**
         * Make a COLLADA name suitable for a DAG name.
         * @param name The name to convert.
         * @return MString Valid dag name.
         */
        String colladaNameToDagName ( const MString& name );

        /**
         * Exports all data of the current scene.
         * @param selectionOnly True, if just the selected elements should be exported.
         */
        void exportCurrentScene ( bool selectionOnly );

        /**
         * Return the id of the current scene.
         * @return const String& The current scene id.
         */
        const String& getSceneID()
        {
            return mSceneId;
        }

        /** Opens an <extra> and a <technique> tag in the collada document */
        void openTechnique ( const String &profile );

        /** Closes the <extra> and a <technique> tag in the collada document, if open */
        void closeTechnique();

        /**
         * Do all stuff to end the export.
         */
        void endExport();

        /**
         * Makes a valid NCName from the given string.
         * @param ncName Any string.
         * @return COLLADAMaya::String A valid NCName.
         */
        String DocumentExporter::checkNCName(const String &ncName);


    private:

        /** Exports the asset*/
        void exportAsset();

        /** Exports the scene*/
        void exportScene();

        /** Creates the import/export libraries */
        void createLibraries();

        /** Releases the import/export libraries */
        void releaseLibraries();

    };
}

#endif // __COLLADA_MAYA_DOCUMENT_EXPORTER_H__