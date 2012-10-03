/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_DOCUMENT_EXPORTER_H__
#define __COLLADAMAX_DOCUMENT_EXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADASWStreamWriter.h"
#include "COLLADAMaxExportSceneGraph.h"
#include "COLLADAMaxOptions.h"

class Interface;

namespace COLLADAMax
{

    class EffectExporter;

    class MaterialExporter;

    class AnimationExporter;

    typedef std::map<String, String> StringToStringMap;

	/** Class that uniquely identifies object.*/
	class ObjectIdentifier
	{
	private:
		/** Pointer to the object.*/
		void* mObject;

		/** Additional number to identify multiple objects with same pointer, e.g. objects in a modifier stack.
		The mIdentificationNumber can serve as the number in the stack.*/
		int mIdentificationNumber;
	public:
		ObjectIdentifier(void* object) : mObject(object),mIdentificationNumber(0){}
		ObjectIdentifier(void* object, int identificationNumber) :mObject(object),mIdentificationNumber(identificationNumber){}
		bool operator<(const ObjectIdentifier& other)const;
	};

    class DocumentExporter
    {
	private:
		typedef std::map<ObjectIdentifier, ExportNode*> ObjectExportNodeMap;

    private:

        /** The effect exporter used by the document exporter.*/
        EffectExporter * mEffectExporter;

        /** The material exporter used by the document exporter.*/
        MaterialExporter * mMaterialExporter;

        /** The Animation exporter used by the document exporter.*/
        AnimationExporter * mAnimationExporter;

		/** The options used by the exporter.*/
		Options mOptions;

		/** The options used by the exporter.*/
		bool mExportOnlySelected;

        Interface* mMaxInterface;

        /** The stream writer used to write the COLLADASW file.*/
        COLLADASW::StreamWriter mStreamWriter;

		/** The uri of the main output file.*/
		COLLADASW::URI mOutputFileUri;

        /** The scene graph which nodes will be exported.*/
        ExportSceneGraph* mExportSceneGraph;

		/** Indicates, if the ExportSceneGraph should be deleted on destruction or not.*/
		bool mDeleteExportSceneGraph;

        /** The id of the @a \<scene\> element.*/
        static const String SCENE_ID;

		static const String AUTHORING_TOOL;

		/** A map, that hold all already exported objects with their ids*/
		ObjectExportNodeMap mExportedObjects;

    public:
        /** Constructor
        @param i the max interface
        @param filepath The file path the COLLADASW document should be written to*/
        DocumentExporter ( Interface* i, const NativeString &filepath, COLLADABU::IDList& xRefExportFileNames, bool exportOnlySelected  );


		/** Constructor. 
		@param i the max interface.
		@param exportSceneGraph The scene graph to export.
		@param filepath The file path the COLLADASW document should be written to
		@param options The options to use during export.*/
		DocumentExporter ( Interface * i, ExportSceneGraph* exportSceneGraph, const NativeString &filepath, const Options& options, bool exportOnlySelected );

		~DocumentExporter();

		/** Returns the path of the COLLADASW file created for the max file with URi @a sourceFile.*/
		String getXRefOutputPath(const ExportSceneGraph::XRefSceneGraph& xRefSceneGraph) const;

		/** Returns the URI of the COLLADASW file created for the max file with URi @a sourceFile relative
		to the main COLLADASW file.*/
		COLLADASW::URI DocumentExporter::getXRefOutputURI( const ExportSceneGraph::XRefSceneGraph& xRefSceneGraph ) const;

        /** Returns a pointer to the max interface.*/
        inline Interface* getMaxInterface()
        {
            return mMaxInterface;
        }

        /** Exports the scene currently loaded in max and all its XRef scenes. Before export, it creates an 
		ExportSceneGraph of the scene and all XRef scenes.*/
        void exportRootMaxScene();

		/** Exports the scene currently loaded in max and all its XRef scenes. Expects that the ExportSceneGraph has
		already been created.*/
		void exportMaxScene();

        /** Returns a pointer to the effect exporter used by the document exporter.*/
        const EffectExporter * const getEffectExporter() const
        {
            return mEffectExporter;
        }

		/** Returns a pointer to the effect exporter used by the document exporter.*/
		EffectExporter * const getEffectExporter() 
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

        /**
        * Returns a pointer to the collada stream writer.
        * @return StreamWriter* Pointer to the collada stream writer
        */
        COLLADASW::StreamWriter & getStreamWriter() { return mStreamWriter; };

		/** The uri of the main output file.*/
		const COLLADASW::URI& getOutputFileUri()const { return mOutputFileUri; }

		/** Shows the export options dialog.
		@param suppressPrompts If set to true, no dialog is shows (for scripting).*/
		bool showExportOptions(bool suppressPrompts);

		/** Returns if @a object has already been exported*/
		bool isExportedObject(ObjectIdentifier& object);

		/** Inserts @a object with id @a objectId to the list of exported objects*/
		void insertExportedObject(ObjectIdentifier& object, ExportNode* objectExportNode);

		/** Returns the id of the the already exported object @a object. 
		If @a object has not been exported, an empty string is returned*/
		ExportNode* getExportedObjectExportNode(ObjectIdentifier& object);

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

		/** Exports all the controllers contained in the export scene graph.*/
		void exportControllers();

		/** Exports all the cameras contained in the export scene graph.*/
		void exportCameras();

		/** Exports all the lights contained in the export scene graph.*/
		void exportLights();

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
