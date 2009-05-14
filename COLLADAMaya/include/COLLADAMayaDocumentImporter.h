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

#ifndef __COLLADA_MAYA_DOCUMENT_IMPORTER_H__
#define __COLLADA_MAYA_DOCUMENT_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaNode.h"
#include "COLLADAMayaSaxParserErrorHandler.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWFileInfo.h"
#include "COLLADAFWInstanceVisualScene.h"

#include "COLLADASaxFWLLoader.h"

#include "MayaDMMesh.h"

#include <set>


namespace COLLADAMaya
{
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
     *      - Copy materials
     * 1.3) Read scene (is always at the end of a collada document)
     * 
     * 2.) Between first and second parsing:
     * 2.1) Import referenced visual scene
     * 2.3) Import referenced library nodes
     * 2.4) Import node instances
     * 2.5) Import materials
     *
     * 3.) Second parsing:
     * 3.1) Import all data directly, the order doesn't matter:
     *      - Import effects
     *      - Import cameras 
     *      - Import lights
     *      - Import images 
     *      - Import animations
     * 4.) After second parsing:
     * 4.1) Make all connections, the order doesn't matter:
     *      - materials / effects
     *      - lights
     *      - animations
     */
    class DocumentImporter : public COLLADAFW::IWriter 
    {

    private:

        static const String ASCII_PATH_EXTENSION;
        static const String ASCII_PATH_EXTENSION_DEBUG;

        static const int BUFFERSIZE;

        /**
         * An enum for the steps to do. See main documentation.
         */
        enum ParseSteps
        {
            NO_PARSING = 0,
            FIRST_PARSING,
            IMPORT_ASSET,
            COPY_FIRST_ELEMENTS,          // no order: scene, visual scene, library nodes, materials
//            READ_SCENE,
//             COPY_VISUAL_SCENE,
//             COPY_LIBRARY_NODES,
//             COPY_MATERIALS,
            AFTER_FIRST_PARSING,
//             IMPORT_VISUAL_SCENE,
//             IMPORT_LIBRARY_NODES,
//             IMPORT_NODE_INSTANCES,
//             IMPORT_MATERIALS,
            SECOND_PARSING, 
            AFTER_SECOND_PARSING
        };

    private:

        /** The current parsing step. */
        ParseSteps mParseStep;

        /** The sax loader. */
        COLLADASaxFWL::Loader mSaxLoader;

        /** The URI of the visual scene to use. */
        COLLADAFW::InstanceVisualScene mInstanceVisualScene;

        /** A copy of the framework's visual scene elements. */
        std::vector<COLLADAFW::VisualScene*> mVisualScenesList;

        /** A copy of the framework's library nodes elements. */
        std::vector<COLLADAFW::LibraryNodes*> mLibraryNodesList;

        /** A copy of the framework's library nodes elements. */
        std::vector<COLLADAFW::Material*> mMaterialsList;

        /** The buffer for fprintf. */
        char *mBuffer; // 2MB Puffer!!

        /** The name of the collada file. */
        String mColladaFileName;

        /** The name of the current maya ascii file. */
        COLLADABU::URI mMayaAsciiFileURI;

        /** The id of the current scene. */
        String mSceneId;

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

        /** Pointer to the visual scene importer. */
        VisualSceneImporter* mVisualSceneImporter;

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
        SaxParserErrorHandler mSaxParserErrorHandler;

    public:

        /** Constructor. */
        DocumentImporter ( const String& fileName );

        /** Destructor. */
        virtual ~DocumentImporter ();

        /** The current maya ascii file to import the data. */
        FILE* getFile () const { return mFile; }
        void setFile ( FILE* val ) { mFile = val; }

        /** Imports the current scene. */
        void importCurrentScene ();

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
        * Returns the name of the current maya ascii file to export.
        * @return const String& The current maya ascii file
        */
        const COLLADABU::URI& getMayaAsciiFileURI () const;

        /** Returns the tolerance value for double value comparison. */
        const double getTolerance () const { return mDigitTolerance; }

        /** Pointer to the visual scene importer. */
        VisualSceneImporter* getVisualSceneImporter () { return mVisualSceneImporter; }
        const VisualSceneImporter* getVisualSceneImporter () const { return mVisualSceneImporter; }

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
        
        /** This method will be called if an error in the loading process occurred and the loader 
        cannot continue to to load. The writer should undo all operations that have been performed.
        @param errorMessage A message containing informations about the error that occurred.
        */
        virtual void cancel ( const String& errorMessage );

        /** This is the method called. The writer hast to prepare to receive data.*/
        virtual void start ();

        /** 
        * This method is called after the last write method. No other methods will be called after this.
        * After the read of the collada document, the connections can be written into the maya file.
        */
        virtual void finish ();

        /** Start the import of the model.
        @return True on success, false otherwise. */
        bool import();

        /** When this method is called, the writer must write the global document asset.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeGlobalAsset ( const COLLADAFW::FileInfo* asset );

        /** Returns the type of the current up axis. */
        const COLLADAFW::FileInfo::UpAxisType& getUpAxisType () const { return mUpAxisType; }

        /**
        * How many real-world meters in one distance unit as a floating-point number.
        * For example, 1.0 for the name "meter"; 1000 for the name "kilometer";
        * 0.3048 for the name "foot".
        */
        const double getLinearUnitConvertFactor () const { return mLinearUnitConvertFactor; }

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
        void importVisualScene ();

        /** When this method is called, the writer must write the geometry.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeGeometry ( const COLLADAFW::Geometry* geometry );

        /** When this method is called, the writer must handle all nodes contained in the 
        library nodes.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeLibraryNodes ( const COLLADAFW::LibraryNodes* libraryNodes );
        void importLibraryNodes ();

        /** When this method is called, the writer must write the material.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeMaterial ( const COLLADAFW::Material* material );
        void importMaterials ();

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

        /**
         * Replace offending characters by some that are supported within maya.
         */
        static String frameworkNameToMayaName ( const String& name );

    private:

        /** Imports the current scene. */
        void exportScene();

        /** Parse the current collada file and creates the parsing libraries: 
        we want access to the libraries during import/export time. */
        void createLibraries();

        /** Releases the import/export libraries */
        void releaseLibraries();

    };
}

#endif // __COLLADA_MAYA_DOCUMENT_IMPORTER_H__