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
#ifndef __COLLADA_MAYA_PHYSX_EXPORTER_H__
#define __COLLADA_MAYA_PHYSX_EXPORTER_H__

#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaPhysXXML.h"
#include "COLLADAMayaSceneElement.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADASWLibraryPhysicsModels.h"

namespace COLLADAMaya
{
    // Unit for mass: kg
    // Unit for density: g/cm3

    class MStringComp
    {
    public:
        bool operator()(const MString & a, const MString & b) const
        {
            return strcmp(a.asChar(), b.asChar()) < 0;
        }
    };

    class PhysXRigidConstraint
    {
    public:
        static void GetSwingConeAndTwistMinLimit(const MObject & rigidConstraint, MVector & min);
        static void GetSwingConeAndTwistMaxLimit(const MObject & rigidConstraint, MVector & max);
        static void GetLinearMinLimit           (const MObject & rigidConstraint, MVector & min);
        static void GetLinearMaxLimit           (const MObject & rigidConstraint, MVector & max);
        static void GetSpringAngularStiffness   (const MObject & rigidConstraint, double & stiffness);
        static void GetSpringAngularDamping     (const MObject & rigidConstraint, double & damping);
        static void GetSpringAngularTargetValue (const MObject & rigidConstraint, double & targetValue);
        static void GetSpringLinearStiffness    (const MObject & rigidConstraint, double & stiffness);
        static void GetSpringLinearDamping      (const MObject & rigidConstraint, double & damping);
        static void GetSpringLinearTargetValue  (const MObject & rigidConstraint, double & targetValue);
    };

    class PhysXShape
    {
    public:
        static void GetType(const MObject & shape, MString & type);
        static void GetInMesh(const MObject & shape, MObject & mesh);
        static void GetConnectedInMesh(const MObject & shape, MObject & mesh);
    };

	class PhysXExporter
    {
    public:
        PhysXExporter(COLLADASW::StreamWriter& streamWriter, DocumentExporter& documentExporter);

        static bool CheckPhysXPluginVersion();
        static MString GetRequiredPhysXPluginVersion();
        static MString GetInstalledPhysXPluginVersion();

        bool generatePhysXXML();
        bool needsConvexHullOf(const SceneElement & element, MObject & shape);
        bool exportPhysicsLibraries();

        COLLADASW::StreamWriter& getStreamWriter();
        DocumentExporter& getDocumentExporter();

		void exportTranslationWithoutConversion(const MVector & translation, const String & sid = "");
        void exportTranslation(const MVector & translation, const String & sid = "");
        void exportRotation(const MEulerRotation & rotation, const String & sid = "");
        void exportAttributes(const MObject & object, const std::set<MString, MStringComp> & attributes);
        void exportMaterialPhysXXML(const MObject& material);
        void exportShapePhysXXML(const MObject& rigidBody, const MObject& shape);
        void exportRigidBodyPhysXXML(const MObject& shape);
        void exportRigidConstraintPhysXXML(const MObject& constraint);

		MObject getNodeRigidBody(const MObject& node);
        MObject getShapeRigidBody(const MObject& shape);
        void getShapeLocalPose(const MObject& rigidBody, const MObject& shape, MMatrix& localPose);
        bool getShapeVertices(const MObject& shape, std::vector<PhysXXML::Point> & vertices, MString & meshId);
        bool getShapeTriangles(const MObject& shape, std::vector<PhysXXML::Triangle> & triangles);
        void getRigidBodyGlobalPose(const MObject& rigidBody, MMatrix& globalPose);
        void getRigidBodyTarget(const MObject& rigidBody, MObject& target);
        bool getRigidSolver(MObject & rigidSolver);

        MStatus getMeshURI(const MObject & mesh, URI & meshURI);

        String generateColladaId(const MDagPath & dagPath);
        String generateColladaName(const MDagPath & dagPath);

        // Stop parsing if callback returns false
        template<class T>
        void parseSceneElements(T & callbackObject)
        {
            SceneGraph& sceneGraph = *mDocumentExporter.getSceneGraph();
            SceneElementsList& exportNodesTree = *sceneGraph.getExportNodesTree();

            // Export all/selected DAG nodes
            for (size_t i = 0; i < exportNodesTree.size(); ++i)
            {
                SceneElement& sceneElement = *exportNodesTree[i];
                if (!parseSceneElement(sceneElement, callbackObject))
                {
                    return;
                }
            }
        }

        // in kg
        static double GetRigidBodyMass(const MObject & rigidBody);
        static double GetShapeMass(const MObject & shape);

        // in cm3
        static double GetRigidBodyVolume(const MObject & rigidBody);
        static double GetShapeVolume(const MObject & shape);

        static void GetRigidBodyShapes(const MObject & rigidBody, std::vector<MObject> & shapes);
        static MStatus GetPluggedObject(const MObject & object, const MString & attribute, MObject & pluggedObject);

        static const String& GetDefaultPhysicsModelId();
        static const String& GetDefaultPhysicsSceneId();
        static const String& GetDefaultInstancePhysicsModelSid();
        static const String& GetProfile();
        static const String& GetProfileXML();

        enum Filter
        {
            All,
            Local,
            Reference
        };
        bool sceneHas(SceneElement::Type type, Filter filter = All);

        PhysXXML::PxRigidStatic* findPxRigidStatic(const String& name);
        PhysXXML::PxMaterial* findPxMaterial(uint64_t ref);
		PhysXXML::PxMaterial* findPxMaterial(const MObject& rigidBody);
		PhysXXML::PxShape* findPxShape(const MObject& rigidBody, const MObject& shape);
		PhysXXML::PxRigidStatic* findPxRigidStatic(uint64_t id);
		PhysXXML::PxRigidStatic* findPxRigidStatic(const MObject& rigidBody);
		PhysXXML::PxRigidDynamic* findPxRigidDynamic(uint64_t id);
		PhysXXML::PxRigidDynamic* findPxRigidDynamic(const MObject& rigidBody);
		PhysXXML::PxD6Joint* findPxD6Joint(const MObject& rigidConstraint);

    private:
        void exportRotate(const MVector & axis, double angle, const String & sid = "");

        static bool ElementHas(const SceneElement & element, SceneElement::Type type, Filter filter);

        const String & findColladaId(const String & mayaId);

        template<class T>
        bool parseSceneElement(SceneElement& element, T & callbackObject)
        {
            if (!callbackObject(element))
            {
                return false;
            }

            // Recursive call for all the child elements
            for (uint i = 0; i<element.getChildCount(); ++i)
            {
                SceneElement& childElement = *element.getChild(i);
                if (!parseSceneElement(childElement, callbackObject))
                {
                    return false;
                }
            }

            return true;
        }

    private:
        COLLADASW::StreamWriter& mStreamWriter;
        DocumentExporter& mDocumentExporter;
        COLLADABU::IDList mIdList;
        StringToStringMap mMayaIdToColladaId;
        PhysXXML::PhysXDocPtr mPhysXDoc;

        static String mDefaultPhysicsModelId;
        static String mDefaultPhysicsSceneId;
        static String mDefaultInstancePhysicsModelSid;
        static String mProfile;
        static String mProfileXML;
    };
}

#endif //__COLLADA_MAYA_PHYSX_EXPORTER_H__
