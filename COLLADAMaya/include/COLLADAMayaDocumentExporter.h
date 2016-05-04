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

#ifndef __COLLADA_MAYA_DOCUMENT_EXPORTER_H__
#define __COLLADA_MAYA_DOCUMENT_EXPORTER_H__

#include "COLLADAMayaPrerequisites.h"

#include "COLLADASWStreamWriter.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWExtra.h"

#include "maya/MDistance.h"


namespace COLLADAMaya
{

    class SceneGraph;
    class MaterialExporter;
    class EffectExporter;
    class EffectTextureExporter;
    class ImageExporter;
    class GeometryExporter;
	class PhysicsExporter;
    class PhysXExporter;
    class VisualSceneExporter;
	class PhysicsSceneExporter;
    class AnimationExporter;
    class AnimationClipExporter;
    class AnimationSampleCache;
    class ControllerExporter;
    class LightExporter;
    class LightProbeExporter;
    class CameraExporter;
	class LODExporter;


    typedef std::map<String, String> StringToStringMap;

    enum PASS
    {
        VISUAL_SCENE_PASS = 0,
        FIRST_LOD_PASS,
        SECOND_LOD_PASS,
        DEFAULT = VISUAL_SCENE_PASS
    };

    /**
     * The main exporter class. This class exports all data of the scene.
     */
    class DocumentExporter
    {
	public :

		PASS mExportPass;

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

		/** Exports the geometry. */
		PhysicsExporter* mPhysicsExporter;

        /** Exports PhysX. */
        PhysXExporter* mPhysXExporter;

        /** Exports the visual scene. */
        VisualSceneExporter* mVisualSceneExporter;

		/** Exports the Physics scene */
		PhysicsSceneExporter* mPhysicsSceneExporter;

        /** Exports the animations. */
        AnimationExporter* mAnimationExporter;

        /** Exports the animation clips. */
        AnimationClipExporter* mAnimationClipExporter;

        /** Handles the controllers. */
        ControllerExporter* mControllerExporter;

        /** Exports the lights. */
        LightExporter* mLightExporter;

        /** Exports the light probes. */
        LightProbeExporter* mLightProbeExporter;

        /** Exports the cameras. */
        CameraExporter* mCameraExporter;

		/** Exports LODs. */
		LODExporter*	mLODExporter;

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
        String mFileName;

        /** The stream writer, to write the collada document. */
        COLLADASW::StreamWriter mStreamWriter;

        /** true, if we import a collada file. */
        bool mIsImport;

        /** The id of the current scene. */
        String mSceneId;

        /** Tolerance value in double to compare values. */
        double mDigitTolerance;

		std::vector<MIntArray> ParamClipVec;

    public:

        /**
         * Constructor.
         * @param _fileName Name of the collada file.
         */
        DocumentExporter ( const NativeString& fileName );
        virtual ~DocumentExporter();

        /** Returns the tolerance value for double value comparison. */
        const double getTolerance () const { return mDigitTolerance; }

        /**
        * Exports all data of the current scene.
        * @param selectionOnly True, if just the selected elements should be exported.
        */
        void exportCurrentScene ( bool selectionOnly );

        /**
         * Returns a pointer to the scene graph.
         * @return SceneGraph* Pointer to the scene graph
         */
        SceneGraph* getSceneGraph();
        const SceneGraph* getSceneGraph() const;

        /** false if all data should be exported, true if export just the selected elements */
        const bool getExportSelectedOnly () const;

        /**
         * Returns the name of the current collada file to export.
         * @return const String& Name of the current collada file
         */
        const String& getFilename() const;

        /**
        * Returns a pointer to the collada stream writer.
        * @return StreamWriter* Pointer to the collada stream writer
        */
        COLLADASW::StreamWriter* getStreamWriter();

        /**
        * Returns a pointer to the animation cache.
        * @return AnimationSampleCache* Pointer to the animation cache
        */
        AnimationSampleCache* getAnimationCache();

        /**
         * Returns a pointer to the material exporter.
         * @return MaterialExporter* Pointer to the material exporter
         */
        MaterialExporter* getMaterialExporter();

        /**
        * Returns a pointer to the effect exporter.
        * @return EffectExporter* Pointer to the effect exporter
        */
        EffectExporter* getEffectExporter();

        /**
        * Returns a pointer to the image exporter.
        * @return ImageExporter* Pointer to the image exporter
        */
        ImageExporter* getImageExporter();

        /**
        * Returns a pointer to the geometry exporter.
        * @return GeometryExporter* Pointer to the geometry exporter
        */
        GeometryExporter* getGeometryExporter();

        /**
        * Returns a pointer to the visual scene exporter.
        * @return VisualSceneExporter* Pointer to the visual scene exporter
        */
        VisualSceneExporter* getVisualSceneExporter();

        /**
         * Returns a pointer to the physics exporter.
         * @return PhysicsExporter* Pointer to the physics exporter
         */
        PhysicsExporter* getPhysicsExporter();

        /**
         * Returns a pointer to the PhysX exporter.
         * @return PhysXExporter* Pointer to the PhysX exporter
         */
        PhysXExporter* getPhysXExporter();

        /**
		* Returns a pointer to the physics scene exporter.
		* @return PhysicsSceneExporter* Pointer to the physics scene exporter
		*/
		PhysicsSceneExporter* getPhysicsSceneExporter();

        /**
        * Returns a pointer to the animation exporter.
        * @return AnimationExporter* Pointer to the animation exporter
        */
        AnimationExporter* getAnimationExporter();

        /**
        * Returns a pointer to the animation clip exporter.
        * @return AnimationClipExporter* Pointer to the animation clip exporter
        */
        AnimationClipExporter* getAnimationClipExporter();

        /**
        * Returns a pointer to the controller exporter.
        * @return ControllerExporter* Pointer to the controller exporter
        */
        ControllerExporter* getControllerExporter();

        /**
        * Returns a pointer to the light exporter.
        * @return LightExporter* Pointer to the light exporter
        */
        LightExporter* getLightExporter();

		/**
		* Returns a pointer to the LOD exporter.
		* @return LODExporter* Pointer to the lod exporter
		*/
		LODExporter* getLODExporter();

        /**
        * Returns a pointer to the light probe exporter.
        * @return LightProbeExporter* Pointer to the light probe exporter
        */
        LightProbeExporter* getLightProbeExporter();

        /**
        * Returns a pointer to the camera exporter.
        * @return CameraExporter* Pointer to the light exporter
        */
        CameraExporter* getCameraExporter();

        /**
         * Converts the given string to a valid collada string.
         * @param str String to convert
         * @param removeNamespace True, if the namespace should be removed.
		 * @param removeFirstNamespace True, if first part of namespace should be removed. (namespace1:namespace2:nodeName -> namespace2_nodeName or |namespace1:namespace2:nodeName -> _namespace2_nodeName)
         * @return MString Maya string with the converted string.
         */
		static String mayaNameToColladaName(const MString& str, bool removeNamespace = true, bool removeFirstNamespace = false);

        /**
         * Make an unique COLLADA Id from a dagPath.
         * @param dagPath The dag path to convert.
		 * @param removeFirstNamespace True, if first part of namespace should be removed. (namespace1:namespace2:nodeName -> namespace2_nodeName or |namespace1:namespace2:nodeName -> _namespace2_nodeName)
         * @return MString The converted collada id.
         */
		String dagPathToColladaId(const MDagPath& dagPath, bool removeFirstNamespace = false);

		/**
		 * Make a unique COLLADA SID from a dagPath.
		 * @param dagPath The dag path to convert.
		 * @return MString The converted COLLADA SID.
		 */
		String dagPathToColladaSid(const MDagPath & dagPath);

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
         * Return the id of the current scene.
         * @return const String& The current scene id.
         */
        const String& getSceneID();

        /**
         * Do all stuff to end the export.
         */
        void endExport();

		void saveParamClip();

		void restoreParamClip();

//         /**
//          * Exports the user defined extra data of the node.
//          * @param MObject& node The dependency node which holds the extra data
//          * @param const char* key The extra key for the extra data to export.
//          * @param const char* secondKey
//          * @param BaseExtraTechnique* baseExtraTechnique The extra technique element.
//          */
//         void exportExtraData ( 
//             const MObject& node, 
//             const char* key, 
//             const char* secondKey = 0, 
//             COLLADASW::BaseExtraTechnique* baseExtraTechnique = 0 );
// 
//         /**
//          * TODO Documentation
//          * @param const MPlug& childPlug
//          * @param const String& pathAttributeName
//          * @param COLLADASW::BaseExtraTechnique* baseExtraTechnique
//          * @param COLLADASW::Extra& extraSource
//          * @param const char* secondKey
//          */
//         bool exportExtraData ( 
//             const MPlug& childPlug, 
//             const String& pathAttributeName, 
//             COLLADASW::BaseExtraTechnique* baseExtraTechnique, 
//             COLLADASW::Extra& extraSource, 
//             const char* secondKey /*= 0*/ );

    private:

        /** Exports the asset. */
        void exportAsset();

        /** Exports the current scene. */
        void exportScene(bool exportScene, bool exportPhysics);

        /** Creates the import/export libraries */
        void createLibraries();

        /** Releases the import/export libraries */
        void releaseLibraries();

    };
}

#endif // __COLLADA_MAYA_DOCUMENT_EXPORTER_H__
