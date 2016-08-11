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

template<>
class std::less <MObject>
{
public:
	bool operator()(const MObject & l, const MObject & r) const
	{
		const int* pl = *reinterpret_cast<const int* const*>(&l);
		const int* pr = *reinterpret_cast<const int* const*>(&r);
		return pl < pr;
	}
};

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
        void exportExtraAttributes(const MObject & object);

		const MObject & getNodeRigidBody(const MObject& node) const;
        void getShapeLocalPose(const MObject& shape, MMatrix& localPose) const;
        bool getShapeVertices(const MObject& shape, std::vector<PhysXXML::Point> & vertices, MString & meshId);
        bool getShapeTriangles(const MObject& shape, std::vector<PhysXXML::Triangle> & triangles);
        void getRigidBodyGlobalPose(const MObject& rigidBody, MMatrix& globalPose);
        const MObject & getRigidSolver() const;

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

		static MMatrix GetRigidBodyTargetTM(const MObject& rigidBody);
		static MObject GetRigidBodyTarget(const MObject& rigidBody);
        static void GetRigidBodyShapes(const MObject & rigidBody, std::vector<MObject> & shapes);
        static MStatus GetPluggedObject(const MObject & object, const MString & attribute, MObject & pluggedObject);

        static const String& GetDefaultPhysicsModelId();
        static const String& GetDefaultPhysicsSceneId();
        static const String& GetDefaultInstancePhysicsModelSid();
		static const String& GetPhysXProfile();
		static const String& GetXMLNS();
		static String GetXSISchemaLocation();

		static bool HasExtraAttributes(const MObject & object);

		// Convert PhysX enum to COLLADA string
		static String CombineModeToCOLLADA(PhysXXML::CombineMode::FlagEnum flag);
		static String ShapeFlagsToCOLLADA(const Flags<PhysXXML::ShapeFlags::FlagEnum> & flags);
		static String ActorFlagsToCOLLADA(const Flags<PhysXXML::ActorFlags::FlagEnum> & flags);
		static String RigidBodyFlagsToCOLLADA(const Flags<PhysXXML::RigidBodyFlags::FlagEnum> & flags);
		static String ConstraintFlagsToCOLLADA(const Flags<PhysXXML::ConstraintFlags::FlagEnum> & flags);
		static String DriveFlagsToCOLLADA(const Flags<PhysXXML::DriveFlags::FlagEnum> & flags);

        enum Filter
        {
            All,
            Local,
            Reference
        };
        bool sceneHas(SceneElement::Type type, Filter filter = All);

		const PhysXXML::PxRigidBody* findPxRigidBody(const MObject & rigidBody) const;
		const PhysXXML::PxRigidBody* findPxRigidBody(const String & name) const;
		const PhysXXML::PxRigidBody* findPxRigidBody(uint64_t id) const;
		const PhysXXML::PxMaterial* findPxMaterial(uint64_t ref) const;
		const PhysXXML::PxMaterial* findPxMaterial(const PhysXXML::PxRigidBody & rigidBody) const;
		const PhysXXML::PxMaterial* findPxMaterial(const MObject & rigidBody) const;
		const PhysXXML::PxShape* findPxShape(const MObject & shape) const;
		const PhysXXML::PxD6Joint* findPxD6Joint(const MObject & rigidConstraint) const;

		const MObject & findMObject(const PhysXXML::PxRigidBody & rigidBody) const;
		const MObject & findMObject(const PhysXXML::PxShape & shape) const;
		const MObject & findMObject(const PhysXXML::PxD6Joint & joint) const;

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

		template<typename E>
		static String FlagsToCOLLADA(const Flags<E> & flags, const std::map<E, String> & flagToStringMap)
		{
			String colladaFlags;
			for (int i = 0; i < 32; ++i)
			{
				E flag = static_cast<E>(1 << i);
				if (flags & flag)
				{
					typename std::map<E, String>::const_iterator it = flagToStringMap.find(flag);
					if (!colladaFlags.empty())
						colladaFlags += ' ';
					colladaFlags += it->second.substr(1);
				}
			}
			return colladaFlags;
		}

    private:
        COLLADASW::StreamWriter& mStreamWriter;
        DocumentExporter& mDocumentExporter;
        COLLADABU::IDList mIdList;
        StringToStringMap mMayaIdToColladaId;
        PhysXXML::PhysXDocPtr mPhysXDoc;

		std::map<MObject, const PhysXXML::PxMaterial*> mRigidBodyToPxMaterialMap;
		std::map<const PhysXXML::PxRigidBody*, MObject> mPxRigidBodyToRigidBodyMap;
		std::map<MObject, const PhysXXML::PxRigidBody*> mRigidBodyToPxRigidBodyMap;
		std::map<const PhysXXML::PxShape*, MObject> mPxShapeToShapeMap;
		std::map<MObject, const PhysXXML::PxShape*> mShapeToPxShapeMap;
		std::map<const PhysXXML::PxD6Joint*, MObject> mPxD6JointToConstraintMap;
		std::map<MObject, const PhysXXML::PxD6Joint*> mConstraintToPxD6JointMap;
		std::map<MObject, MObject> mTargetToRigidBodyMap;
		MObject mRigidSolver;

        static String mDefaultPhysicsModelId;
        static String mDefaultPhysicsSceneId;
        static String mDefaultInstancePhysicsModelSid;
		static String mPhysXProfile;
		static String mXMLNS;
		static String mSchemaLocation;

		friend class PhysicsExportPrePass;
    };
}

#endif //__COLLADA_MAYA_PHYSX_EXPORTER_H__
