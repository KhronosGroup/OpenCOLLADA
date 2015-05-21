/*
    Copyright (c) 2015 Starbreeze

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __COLLADA_MAYA_PHYSICS_EXPORTER_H__
#define __COLLADA_MAYA_PHYSICS_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaSceneElement.h"
#include <vector>
#include <time.h>
#include <maya/MFnMesh.h>
#include <maya/MDagPath.h>
#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryPhysicsModels.h"
#include "COLLADABUIDList.h"


namespace COLLADAMaya
{

    class DocumentExporter;
    class ElementWriter;

	

    /************************************************************************/
    /* This class writes the <library_geometries>.                                                                     */
    /************************************************************************/
	class PhysicsExporter : public COLLADASW::LibraryPhysicsModels
    {

    private:

        /**
        * The list of the unique collada ids.
        */
        COLLADABU::IDList mPhysicsIdList;

        /** 
         * Pointer to the document exporter. 
         */
        DocumentExporter* mDocumentExporter;

        /**
        * A collada id for every maya id.
        */
        StringToStringMap mMayaIdColladaIdMap;


    public:

		enum collisionShape
		{
			Box			= 0,
			Capsule		= 1,
			Convex_mesh = 2,
			Mesh		= 3
		};

		typedef struct BodyTarget {
			String Body;
			String Target;
		} BodyTarget;

		typedef std::map<String, BodyTarget> RB_Map;

        /* @param streamWriter The stream the output will be written to                                                                     */
        PhysicsExporter ( COLLADASW::StreamWriter* streamWriter, DocumentExporter* documentExporter );
        virtual ~PhysicsExporter();

        /** Walk through the scene graph and export all geometries. */
        void exportAllPhysics();

        /** closes the physics tags in the collada document */
        void endExport();

        /** Generate the collada id, if not done before and stores it in the scene element. */
        const String generateColladaMeshId ( const MDagPath dagPath );

        /** export physic element */
        void exportPhysics ( SceneElement* sceneElement );

        /** Returns the collada geometry id of the current physics node. */
        const String& getColladaPhysicsId ( MDagPath dagPath );

		static RB_Map& getRB_Map() { return bodyTargetMap; }

		static RB_Map bodyTargetMap;

		/** Returns if the node is a solver bullet node. */
		bool isBulletRigidBodySolverNode(MDagPath& dagPath);
		
		/** Returns if the node is a rigid bullet node. */
		bool isBulletRigidBodyNode(MDagPath& dagPath);
		
		/** Gravity field vector. */
		static MVector gravityField;

		/** Returns the gravity field from the solver bullet node. */
		void getGravityField();

    private:

        /**
        * A collada id for every maya id.
        */
        const String& findColladaPhysicsId ( const String& mayaPhysicsId );

        /** Returns the tolerance value for double value comparison. */
        const double getTolerance () const 
        {
            return mDocumentExporter->getTolerance ();
        }

        /** Exports the current scene element and all it's children. */
        void exportAllPhysics ( SceneElement* sceneElement, bool isVisible );

		/** export physic element */
		bool exportPhysicsElement(SceneElement* sceneElement);

        /** Exports all physics data of the current mesh. */
		bool exportPhysicModel(MDagPath& dagPath);

		void createShape(MDagPath& childDagPath, MTransformationMatrix mPhysicsShapeTransformMatrix, MTransformationMatrix mGraphicShapeTransformMatrix);

		void UpdateSceneElement(MObject& child, bool result, bool needExport);

		/** Export Transformation Stuff */
		void exportDecomposedTransform();
		void exportTranslation(const String name, const MPoint& translation);
		void exportTranslation(const String name, const MVector& translation);
		void exportRotation(const String name, const MEulerRotation& rotation);

	private:

		bool firstimeOpenPhysModel;

		/** Export Transformation Stuff */
		bool mIsJoint;
		bool mIsFirstRotation;

		MTransformationMatrix mFinalTransformMatrix;
		MObject mTransformObject;
    };
}

#endif //__COLLADA_MAYA_PHYSICS_EXPORTER_H__
