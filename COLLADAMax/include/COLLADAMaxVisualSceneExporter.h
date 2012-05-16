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


#ifndef __COLLADAMAX_VISUALSCENEEXPORTER_H__
#define __COLLADAMAX_VISUALSCENEEXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADASWStreamWriter.h"
#include "COLLADAMaxEffectExporter.h"
#include "COLLADASWLibraryVisualScenes.h"
#include "COLLADAMaxDocumentExporter.h"

namespace COLLADASW
{

    class Node;
	class InstanceMaterialList;
}

namespace COLLADAMax
{

    class ExportSceneGraph;

    class ExportNode;

    /** Class to export the visual scene.*/

    class VisualSceneExporter : public COLLADASW::LibraryVisualScenes
    {

	public :
		static const String MATRIX_SID;
		static const String TRANSLATE_SID;
		static const String ROTATE_SID;
		static const String ROTATE_X_SID;
		static const String ROTATE_Y_SID;
		static const String ROTATE_Z_SID;
		static const String ROTATE_SCALE_AXIS_SID;
		static const String ROTATE_SCALE_AXIS_INVERSE_SID;
		static const String SCALE_SID;

		static const String MATRIX_PARAMETERS[ 1 ];
		static const String TRANSLATION_PARAMETERS[ 3 ];
		static const String ROTATION_PARAMETER[ 1 ];
		static const String ROTATION_PARAMETERS[ 4 ];


	private:
		ExportSceneGraph * mExportSceneGraph;

		const EffectMap & mEffectMap;

		/** The id of the visual scene.*/
		const String & mVisualSceneId;

		DocumentExporter * mDocumentExporter;

		/** The prefix used for node ids.*/
		static const String NODE_ID_PRAEFIX;


    public:
        /** Constructor
        @param streamWriter The stream to write the visual seen to.
        @param exportSceneGraph The scene graph of all the nodes that should be exported.
        @param sceneId The id of the scene.
        @param documentExporter
        */
        VisualSceneExporter ( COLLADASW::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, const String & sceneId, DocumentExporter * documentExporter );
        virtual ~VisualSceneExporter()
        {}

        ;

        /** Exports the library visual scene.*/
        void doExport();

		/** Fills the two dimensional array @a copy with the values contained in @a original.*/
		static void matrix3ToDouble4x4 ( double copy[][ 4 ], const Matrix3 & original );

		/** Creates an id for the NODE, derived from the node id*/
		static String getNodeId(const ExportNode& exportNode);

		/** Returns the world transformation matrix at the animation start time*/
		static Matrix3 getWorldTransform(INode* node, TimeValue time);


	private:
		/** Exports the node that instantiates the environment ambient color.*/
		void exportEnvironmentAmbientLightNode();

		/** Exports all the nodes in @a node and all its child nodes.*/
        void doExport ( ExportNode* exportNode );

        /** Exports all the transformations of a node.*/
        void exportTransformations ( ExportNode * exportNode, const COLLADASW::Node & colladaNode );

		/** Fill @a instanceMaterialList with the appropriate elements.
		@param instanceMaterialList The COLLADASW::InstanceMaterialList to fill
		@param exportNode The ExportNode which this instance material list is for. */
		void fillInstanceMaterialList(COLLADASW::InstanceMaterialList & instanceMaterialList, ExportNode * exportNode);

		void calculateObjectOffsetTransformation(INode* maxNode, Matrix3& tm);

		/** Determines the world transformation of  @a node at the animation start time.*/
		Matrix3 getWorldTransform(INode* node);

		/** If @a node references a skinned object...
		@returns True, if the nodes transformation should be exported, false otherwise*/
		bool applyFirstInstanceTransform( Matrix3& transformationMatrix, INode* node );

    };

}

#endif //__COLLADAMAX_VISUALSCENEEXPORTER_H__
