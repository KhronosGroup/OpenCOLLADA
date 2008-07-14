/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_DOCUMENT_EXPORTER_H__
#define __COLLADAMAX_DOCUMENT_EXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAStreamWriter.h"
#include "COLLADAMaxExportSceneGraph.h"
#include "COLLADAMaxOptions.h"

class Interface;

namespace COLLADAMax
{

    class EffectExporter;

    class MaterialExporter;

    class AnimationExporter;

    class DocumentExporter
    {

    private:
        /** The effect exporter used by the document exporter.*/
        EffectExporter * mEffectExporter;

        /** The material exporter used by the document exporter.*/
        MaterialExporter * mMaterialExporter;

        /** The Animation exporter used by the document exporter.*/
        AnimationExporter * mAnimationExporter;

        /** The options used by the exporter.*/
        Options mOptions;

        Interface* mMaxInterface;

        /** The stream writer used to write the COLLADA file.*/
        COLLADA::StreamWriter mStreamWriter;

        /** The scene graph which nodes will be exported.*/
        ExportSceneGraph mExportSceneGraph;

        /** The id of the @a \<scene\> element.*/
        static const String SCENE_ID;

    public:
        /** Constructor
        @param i the max interface
        @param filepath The file path the COLLADA document should be written to*/
        DocumentExporter ( Interface* i, const String &filepath );

        /** Returns a pointer to the max interface.*/
        inline Interface* getMaxInterface()
        {
            return mMaxInterface;
        }

        /** Exports the scene currently loaded in max.*/
        void exportCurrentMaxScene();

        /** Returns a pointer to the effect exporter used by the document exporter.*/
        const EffectExporter * const getEffectExporter() const
        {
            return mEffectExporter;
        }

        /** Returns a pointer to the material exporter used by the document exporter.*/
        MaterialExporter * getMaterialExporter()
        {
            return mMaterialExporter;
        }

        /** Returns a pointer to the animation exporter used by the document exporter.*/
        AnimationExporter * getAnimationExporter()
        {
            return mAnimationExporter;
        }

        /** Returns the options.*/
        const Options & getOptions() const
        {
            return mOptions;
        }

    private:
        DocumentExporter ( const DocumentExporter & documentExporter );
        DocumentExporter & operator= ( const DocumentExporter & documentExporter );

        /** Creates the scene graph of the nodes, that should be exported.*/
        bool createExportSceneGraph();

        /** Creates all the importers that are reused by other exporters.*/
        void createExporters();

        /** Exports the asset.*/
        void exportAsset();

        /** Exports all the geometries contained in the export scene graph.*/
        void exportGeometries();

        /** Exports all the effects used by the nodes in the export scene graph.*/
        void exportEffects();

        /** Exports all the materials used by the nodes in the export scene graph.*/
        void exportMaterials();

        /** Exports all the images used by the exported textures.*/
        void exportImages();

        /** Exports all the nodes contained in the export scene graph.*/
        void exportVisualScenes();

        /** Exports all animations contained in all animatable elements.*/
        void exportAnimations();

        /** Exports the scene.*/
        void exportScene();

        /** Deletes all exporters created by createExporters().*/
        void deleteExporters();

        /** Returns the value of the environment variable @a variableName.*/
        String getEnvironmentVariable ( const String & variableName );

    };
}


#endif // __COLLADAMAX_DOCUMENT_EXPORTER_H__
