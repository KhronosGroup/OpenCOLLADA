/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_DOCUMENT_IMPORTER_H__
#define __DAE2MA_DOCUMENT_IMPORTER_H__

#include "DAE2MAStableHeaders.h"
#include "DAE2MAPrerequisites.h"
#include "DAE2MANode.h"
#include "DAE2MASaxErrorHandler.h"
#include "DAE2MAExtraDataCallbackHandler.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWFileInfo.h"
#include "COLLADAFWInstanceVisualScene.h"
#include "COLLADAFWFormula.h"
#include "COLLADAFWEffect.h"

#include "COLLADASaxFWLLoader.h"

#include "MayaDMMesh.h"

#include "COLLADABUIDList.h"

#include <set>


namespace DAE2MA
{
    class NodeImporter;
    class VisualSceneImporter;
    class GeometryImporter;
    class MaterialImporter;
    class EffectImporter;
    class CameraImporter;
    class LightImporter;
    class ImageImporter;
    class AnimationImporter;
    class ControllerImporter;


    /** 
     * The main importer class. This class imports all data of the scene. 
     * 
     * We have to parse the document always for two times. Once to get the used visual scene,
     * which is always in the current scene. This element is always at the end of a collada 
     * document, why we have to parse always twice. The order to handle the parsed data:
     * 
     * 1.) First parsing:
     * 1.1) Import asset
     * 1.2) Copy some of the elements, so we don't need to parse once more again. 
     *      Following elements should be copied, the order doesn't matter:
     *      - Copy visual scene
     *      - Copy library nodes
     *      - Copy controllers
     *      - Copy materials
     *      - Copy images
     *      - Copy animation lists
     * 1.3) Read scene (is always at the end of a collada document)
     * 
     * 2.) Between first and second parsing:
     * 2.1) Import referenced visual scene
     * 2.3) Import referenced library nodes
     * 2.4) Import node instances
     * 2.5) Import morph controllers
     * 2.6) Import (not just the referenced) materials
     * 2.7) Import (not just the referenced) effects (now we know the image list...)
     * 2.8) Import referenced images
     * 2.9) Detect scale animations
     *
     * 3.) Second parsing:
     * 3.1) Import all data directly, the order doesn't matter:
     *      - Import referenced geometries
     *      - Import (not just the referenced) cameras 
     *      - Import (not just the referenced) lights
     *      - Import (not just the referenced) animations (in depend on scale animations)
     *      - Import referenced skinControllerDatas
     * 4.) After second parsing:
     * 4.1) Make all connections, the order doesn't matter:
     *      - controller
     *      - materials / effects
     *      - lights
     *      - effects
     *      - geometries
     *      - animations
     */
    class DocumentImporter : public COLLADAFW::IWriter 
    {

    private:

        /** This names are reserved. Maya nodes can't have this names! */
        static const String RESERVED_NAMES[];
        static const size_t NUM_RESERVED_NAMES;

        /** The Buffersize for the document to write. */
        static const int BUFFERSIZE;

        /**
         * An enum for the steps to do. See main documentation.
         */
        enum ParseSteps
        {
            NO_PARSING = 0,
            FIRST_PARSING,
            IMPORT_ASSET,
            COPY_ELEMENTS, // no order: scene, visual scene, library nodes, materials, animationLists, writeController
            ELEMENTS_COPIED,
            VISUAL_SCENE_IMPORTED,
            SECOND_PARSING, 
            ANIMATIONS_IMPORTED,
            GEOMETRY_IMPORTED,
            MAKE_CONNECTIONS
        };

    private:

        /** The maya version of the current maya document. */
        const char* mMayaVersion;

        /** The current parsing step. */
        ParseSteps mParseStep;

        /** The sax loader. */
//        COLLADASaxFWL::Loader mSaxLoader;

        /** The callback handler to parse the extra data elements. */
        ExtraDataCallbackHandler mMayaIdCallbackHandler;

        /** The URI of the visual scene to use. */
        COLLADAFW::InstanceVisualScene* mInstanceVisualScene;

        /** A copy of the framework's visual scene elements. */
        std::vector<COLLADAFW::VisualScene*> mVisualScenesList;

        /** A copy of the framework's library nodes elements. */
        std::vector<COLLADAFW::LibraryNodes*> mLibraryNodesList;

        /** A copy of the framework's library materials elements. */
        std::vector<COLLADAFW::Material*> mMaterialsList;

        /** A copy of the framework's library effects elements. */
        std::vector<COLLADAFW::Effect*> mEffectsList;

        /** A copy of the framework's animation list elements. */
        std::vector<COLLADAFW::AnimationList*> mAnimationListsList;

        /** The buffer for fprintf. */
        char *mBuffer; // 2MB Puffer!!

        /** The name of the collada file. */
        String mColladaFileName;

        /** The name of the current maya ascii file. */
        COLLADABU::URI mMayaAsciiFileURI;

        /** The current maya ascii file to import the data. */
        FILE* mFile;

        /** The LC_NUMERIC locale that was set before the Streamwriter was instantiated. */
        String mLocale;			

        /** Tolerance value in double to compare values. */
        double mDigitTolerance;

        /**
        * How many real-world meters in one distance unit as a floating-point number.
        * For example, 1.0 for the name "meter"; 1000 for the name "kilometer";
        * 0.3048 for the name "foot".
         */
        double mLinearUnitConvertFactor;
        COLLADAFW::FileInfo::UpAxisType mUpAxisType;

        /**
         * This unit convert factor calculates always the centimeter unit, because this is 
         * the maya internal unit.
         * This is need for conversion of the skin controller bind shape and geometry (?) matrix
         * translate values conversion, because maya doesn't calculate the right values on linear
         * unit switching.
         */
        double mLinearUnitMayaBindShapeBugConvertFactor;

        /** Pointer to the visual scene importer. */
        VisualSceneImporter* mVisualSceneImporter;

        /** Pointer to the node importer. 
        Used to store the mapping between unique node ids and the framework nodes. */
        NodeImporter* mNodeImporter;

        /** Pointer to the geometry importer. */
        GeometryImporter* mGeometryImporter;

        /** Pointer to the geometry importer. */
        MaterialImporter* mMaterialImporter;

        /** Pointer to the geometry importer. */
        EffectImporter* mEffectImporter;

        /** Pointer to the camera importer. */
        CameraImporter* mCameraImporter;

        /** Pointer to the light importer. */
        LightImporter* mLightImporter;

        /** Pointer to the image importer. */
        ImageImporter* mImageImporter;

        /** Pointer to the animation importer. */
        AnimationImporter* mAnimationImporter;

        /** Pointer to the controller importer. */
        ControllerImporter* mControllerImporter;

        /** The variable tells, how many times the document is read. */
        size_t mNumDocumentParses;

        /** The error handler for the sax parser. */
        SaxErrorHandler mSaxParserErrorHandler;

        /**
        * The list of all unique ids of maya nodes (dag nodes and depend nodes). 
        * A list of names which are either used up to multiple times for dag nodes in the scene 
        * graph or just once for any other maya depend object (materials, shading groups, material 
        * infos, animations, blend shapes, skin clusters, textures ). Used to avoid dublicate names. 
        */
        COLLADABU::IDList mGlobalNodeIdList;

        /**
        * The list of unique ids of maya depend nodes. Depend nodes are: materials, shading groups, 
        * material infos, animations, blend shapes, skin clusters, textures. Used to avoid dublicate 
        * names. 
        */
        COLLADABU::IDList mDependNodeIdList;

        /**
         * A list of names which are used up to multiple times for dag nodes in the scene graph.
         * Used to avoid dublicate names. 
         */
        std::set<String> mDagNodeIdSet;

    public:

        /** Constructor. */
        DocumentImporter ( 
            const String& importFileName, 
            const String& mayaAsciiFileName, 
            const char* mayaVersion = MAYA_VERSION_DEFAULT );

        /** Destructor. */
        virtual ~DocumentImporter ();

        /** Imports the current scene. */
        void importCurrentScene ();

        /** The callback handler to parse the extra data elements. */
        const ExtraDataCallbackHandler& getMayaIdCallbackHandler () const { return mMayaIdCallbackHandler; }

        /** The current maya ascii file to import the data. */
        FILE* getFile () const { return mFile; }

        /** Returns the tolerance value for double value comparison. */
        const double getTolerance () const { return mDigitTolerance; }

        /** Pointer to the visual scene importer. */
        VisualSceneImporter* getVisualSceneImporter () { return mVisualSceneImporter; }
        const VisualSceneImporter* getVisualSceneImporter () const { return mVisualSceneImporter; }

        /** Pointer to the node importer. 
        Used to store the mapping between unique node ids and the framework nodes. */
        NodeImporter* getNodeImporter () { return mNodeImporter; }
        const NodeImporter* getNodeImporter () const { return mNodeImporter; }

        /** Pointer to the geometry importer. */
        GeometryImporter* getGeometryImporter () { return mGeometryImporter; }
        const GeometryImporter* getGeometryImporter () const { return mGeometryImporter; }

        /** Pointer to the geometry importer. */
        MaterialImporter* getMaterialImporter () { return mMaterialImporter; }
        const MaterialImporter* getMaterialImporter () const { return mMaterialImporter; }

        /** Pointer to the geometry importer. */
        EffectImporter* getEffectImporter () { return mEffectImporter; }
        const EffectImporter* getEffectImporter () const { return mEffectImporter; }

        /** Pointer to the camera importer. */
        CameraImporter* getCameraImporter () { return mCameraImporter; }
        const CameraImporter* getCameraImporter () const { return mCameraImporter; }

        /** Pointer to the light importer. */
        LightImporter* getLightImporter () { return mLightImporter; }
        const LightImporter* getLightImporter () const { return mLightImporter; }

        /** Pointer to the image importer. */
        ImageImporter* getImageImporter () { return mImageImporter; }
        const ImageImporter* getImageImporter () const { return mImageImporter; }

        /** Pointer to the animation importer. */
        AnimationImporter* getAnimationImporter () { return mAnimationImporter; }
        const AnimationImporter* getAnimationImporter () const { return mAnimationImporter; }
        
        /** Pointer to the controller importer. */
        ControllerImporter* getControllerImporter () { return mControllerImporter; }
        const ControllerImporter* getControllerImporter () const { return mControllerImporter; }

        /** This method will be called if an error in the loading process occurred and the loader 
        cannot continue to to load. The writer should undo all operations that have been performed.
        @param errorMessage A message containing informations about the error that occurred.
        */
        virtual void cancel ( const String& errorMessage );

        /** This is the method called. The writer hast to prepare to receive data.*/
        virtual void start();

		/** Initializes the document importer.*/
		void initialize();

        /** 
        * This method is called after the last write method. No other methods will be called after this.
        * After the read of the collada document, the connections can be written into the maya file.
        */
        virtual void finish ();

        /**
         * Makes all the necessary connections.
         */
        void writeConnections ();

        /** When this method is called, the writer must write the global document asset.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeGlobalAsset ( const COLLADAFW::FileInfo* asset );

        /**
        * How many real-world meters in one distance unit as a floating-point number.
        * For example, 1.0 for the name "meter"; 1000 for the name "kilometer";
        * 0.3048 for the name "foot".
        */
        const double getLinearUnitConvertFactor () const { return mLinearUnitConvertFactor; }

        /**
        * This unit convert factor calculates always the centimeter unit, because this is 
        * the maya internal unit.
        * This is need for conversion of the skin controller bind shape and geometry (?) matrix
        * translate values conversion, because maya doesn't calculate the right values on linear
        * unit switching.
        */
        const double getLinearUnitMayaBindShapeBugConvertFactor () const { return mLinearUnitMayaBindShapeBugConvertFactor; }

        /** When this method is called, the writer must write the scene.
        @return The writer should return true, if writing succeeded, false otherwise.
        <instance_physics_scene> 0 or more
        <instance_visual_scene> 0 or 1
        <instance_kinematics_scene> 0 or 1
        */
        virtual bool writeScene ( const COLLADAFW::Scene* scene );

        /** When this method is called, the writer must write the entire visual scene.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeVisualScene ( const COLLADAFW::VisualScene* visualScene );

        /** When this method is called, the writer must write the geometry.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeGeometry ( const COLLADAFW::Geometry* geometry );

        /** When this method is called, the writer must handle all nodes contained in the 
        library nodes.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeLibraryNodes ( const COLLADAFW::LibraryNodes* libraryNodes );

        /** When this method is called, the writer must write the material.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeMaterial ( const COLLADAFW::Material* material );
 
        /** When this method is called, the writer must write the effect.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeEffect ( const COLLADAFW::Effect* effect );

        /** When this method is called, the writer must write the camera.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeCamera( const COLLADAFW::Camera* camera );

        /** When this method is called, the writer must write the light.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeLight( const COLLADAFW::Light* camera );

        /** When this method is called, the writer must write the image.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeImage( const COLLADAFW::Image* image );

        /** When this method is called, the writer must write the Animation.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeAnimation( const COLLADAFW::Animation* animation );

        /** When this method is called, the writer must write the AnimationList.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeAnimationList( const COLLADAFW::AnimationList* animationList );

        /** When this method is called, the writer must write the skin controller data.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeSkinControllerData( const COLLADAFW::SkinControllerData* skinControllerData );

        /** When this method is called, the writer must write the controller.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeController( const COLLADAFW::Controller* Controller );

		/** When this method is called, the writer must write the formulas. All the formulas of the entire
		COLLADA file are contained in @a formulas.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeFormulas( const COLLADAFW::Formulas* formulas );

		virtual bool writeKinematicsScene( const COLLADAFW::KinematicsScene* kinematicsScene );

        /**
         * Replace offending characters by some that are supported within maya.
         */
        static String frameworkNameToMayaName ( const String& name );

        /**
        * The list of all unique ids of maya nodes (dag nodes and depend nodes). 
        * A list of names which are either used up to multiple times for dag nodes in the scene 
        * graph or just once for any other maya depend object (materials, shading groups, material 
        * infos, animations, blend shapes, skin clusters, textures ). Used to avoid dublicate names. 
        */
        String addGlobalNodeId ( 
            const String& newId, 
            bool returnConverted = true, 
            bool alwaysAddNumberSuffix = false );

        /**
        * The list of unique ids of maya depend nodes. Depend nodes are: materials, shading groups, 
        * material infos, animations, blend shapes, skin clusters, textures. Used to avoid dublicate 
        * names. 
        */
        String addDependNodeId ( 
            const String& newId, 
            bool returnConverted = true, 
            bool alwaysAddNumberSuffix = false );

        /**
        * The list of unique ids of maya depend nodes. Depend nodes are: materials, shading groups, 
        * material infos, animations, blend shapes, skin clusters, textures. Used to avoid dublicate 
        * names. 
        */
        bool containsDependNodeId ( const String& id );

        /**
        * A list of names which are used up to multiple times for dag nodes in the scene graph.
        * Used to avoid duplicate names. 
        */
        void addDagNodeId ( const String& newId );

        /**
        * A list of names which are used up to multiple times for dag nodes in the scene graph.
        * Used to avoid duplicate names. 
        */
        bool containsDagNodeId ( const String& id );

        /**
         * Returns the framework material with the given id.
         */
        const COLLADAFW::Material* getMaterialById ( const COLLADAFW::UniqueId& materialId );

    private:

        /** Reads the collada document. */
        void readColladaDocument ();

        /** Create the maya ascii file (where with which name???) */
        bool createMayaAsciiFile ();
        void closeMayaAsciiFile ();

        /**
        * Returns the name of the current collada file to export.
        * @return const String& Name of the current collada file
        */
        const String& getColladaFilename () const;

        /**
        * After we have imported the geometries, we can create the necessary uv-choosers.
        * We can't create them earlier, about we need to know, if the geometry has more than 
        * one uv-set (texture coordinates).
        */
        void createUvChoosers ();

        /** Convert the value to a valid maya unit value in depend on the current precision. */
        double toMayaUnitValue ( double unitValue );

        /** Maps unique ids of nodes to the frame word node itself. */
        void importNodes ();

        /**
        * Import the data of the visual scene.
        */
        void importVisualScene ();

        /**
        * First import materials, then effects and after this images.
        * The order of the import is relevant, about we have to know which effects are used 
        * by this material. After the import of the effects, we know which images we need.
        * We have to import this before we write the animations in the second parsing, about
        * to know the animated effects.
        */
        void importMaterials ();

        /**
        * First import materials, then effects and after this images.
        * The order of the import is relevant, about we have to know which effects are used 
        * by this material. After the import of the effects, we know which images we need.
        * We have to import this before we write the animations in the second parsing, about
        * to know the animated effects.
        */
        void importEffects ();

        /**
        * First import materials, then effects and after this images.
        * The order of the import is relevant, about we have to know which effects are used 
        * by this material. After the import of the effects, we know which images we need.
        * We have to import this before we write the animations in the second parsing, about
        * to know the animated effects.
        */
        void importImages ();

        /**
        * Imports the morph controllers.
        */
        void importMorphControllers ();

        /**
         * After we have imported the visual scene, we can detect the scale animations.
         * 
         * We need the information about scale animations to adjust the physical dimension of a 
         * scale animation. To get this info, we have to get the transformations of the transform 
         * animations and have to check for scale animations. Scale animations must have a physical 
         * dimension number (double) instead of length (distance)!
         * The transformations exist after the first parsing, after the visual scene is imported.
         * So we have to store the animation lists in the first parsing. After the visual scene 
         * import we can iterate over the animation lists and determine the scale animations. After 
         * we know the scale animations, we can import the animations with the correct physical 
         * dimension. After we have imported all animations, we can write the animation connections
         * from the stored animation lists.
         */
        void detectScaleAnimations ();

        void importAnimationLists ();

        /**
        * Get the minimum and the maximum time values of the animations to get the start 
        * time and the end time of the animation. This times we have to set as the 
        * "playbackOptions" in the "sceneConfigurationScriptNode".
        */
        void importPlaybackOptions ();

        /**
        * The list of all unique ids of maya nodes (dag nodes and depend nodes). 
        * A list of names which are either used up to multiple times for dag nodes in the scene 
        * graph or just once for any other maya depend object (materials, shading groups, material 
        * infos, animations, blend shapes, skin clusters, textures ). Used to avoid duplicate names. 
        */
        bool containsGlobalNodeId ( const String& id );

        /** 
         * Recursive call to find the node with the given id in the given node list. 
         */
        const COLLADAFW::Node* findNode ( 
            const COLLADAFW::UniqueId& nodeId,
            const COLLADAFW::NodePointerArray &nodes );

        /** Imports the current scene. */
        void exportScene();

        /** Parse the current collada file and creates the parsing libraries: 
        we want access to the libraries during import/export time. */
        void createLibraries();

        /** Releases the import/export libraries */
        void releaseLibraries();

    };
}

#endif // __DAE2MA_DOCUMENT_IMPORTER_H__