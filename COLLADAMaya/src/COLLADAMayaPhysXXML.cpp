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

#include "COLLADAMayaStableHeaders.h"

#include "COLLADAMayaPhysXXML.h"
#include "COLLADASWStreamWriter.h"

using namespace COLLADASW;

namespace COLLADAMaya
{
    namespace PhysXXML
    {
        namespace Strings
        {
            const String actor0 = "actor0";
            const String actor1 = "actor1";
            const String ActorFlags = "ActorFlags";
            const String Actors = "Actors";
            const String angular = "angular";
            const String AngularDamping = "AngularDamping";
            const String AngularVelocity = "AngularVelocity";
            const String BounceThreshold = "BounceThreshold";
            const String BreakForce = "BreakForce";
            const String CMassLocalPose = "CMassLocalPose";
            const String ConstraintFlags = "ConstraintFlags";
            const String ContactDistance = "ContactDistance";
            const String ContactOffset = "ContactOffset";
            const String ContactReportThreshold = "ContactReportThreshold";
            const String ConvexMesh = "ConvexMesh";
            const String Damping = "Damping";
            const String DominanceGroup = "DominanceGroup";
            const String Drive = "Drive";
            const String DrivePosition = "DrivePosition";
            const String DriveVelocity = "DriveVelocity";
            const String DynamicFriction = "DynamicFriction";
            const String eACTOR0 = "eACTOR0";
            const String eACTOR1 = "eACTOR1";
            const String eSLERP = "eSLERP";
            const String eSWING = "eSWING";
            const String eSWING1 = "eSWING1";
            const String eSWING2 = "eSWING2";
            const String eTWIST = "eTWIST";
            const String eX = "eX";
            const String eY = "eY";
            const String eZ = "eZ";
            const String Flags = "Flags";
            const String force = "force";
            const String ForceLimit = "ForceLimit";
            const String FrictionCombineMode = "FrictionCombineMode";
            const String Id = "Id";
            const String InvInertiaScale0 = "InvInertiaScale0";
            const String InvInertiaScale1 = "InvInertiaScale1";
            const String InvMassScale0 = "InvMassScale0";
            const String InvMassScale1 = "InvMassScale1";
            const String Geometry = "Geometry";
            const String GlobalPose = "GlobalPose";
            const String HalfExtents = "HalfExtents";
            const String HalfHeight = "HalfHeight";
            const String Length = "Length";
            const String linear = "linear";
            const String LinearDamping = "LinearDamping";
            const String LinearLimit = "LinearLimit";
            const String LinearVelocity = "LinearVelocity";
            const String LocalPose = "LocalPose";
            const String Lower = "Lower";
            const String Mass = "Mass";
            const String MassSpaceInertiaTensor = "MassSpaceInertiaTensor";
            const String Materials = "Materials";
            const String MaxAngularVelocity = "MaxAngularVelocity";
            const String MaxDepenetrationVelocity = "MaxDepenetrationVelocity";
            const String MinCCDAdvanceCoefficient = "MinCCDAdvanceCoefficient";
            const String minPositionIters = "minPositionIters";
            const String minVelocityIters = "minVelocityIters";
            const String Motion = "Motion";
            const String Name = "Name";
            const String OwnerClient = "OwnerClient";
            const String PhysX30Collection = "PhysX30Collection";
            const String points = "points";
            const String ProjectionAngularTolerance = "ProjectionAngularTolerance";
            const String ProjectionLinearTolerance = "ProjectionLinearTolerance";
            const String PxBoxGeometry = "PxBoxGeometry";
            const String PxCapsuleGeometry = "PxCapsuleGeometry";
            const String PxConvexMesh = "PxConvexMesh";
            const String PxConvexMeshGeometry = "PxConvexMeshGeometry";
            const String PxD6Joint = "PxD6Joint";
            const String PxMaterial = "PxMaterial";
            const String PxMaterialRef = "PxMaterialRef";
            const String PxPlaneGeometry = "PxPlaneGeometry";
            const String PxRigidDynamic = "PxRigidDynamic";
            const String PxRigidStatic = "PxRigidStatic";
            const String PxShape = "PxShape";
            const String PxSphereGeometry = "PxSphereGeometry";
            const String PxTriangleMesh = "PxTriangleMesh";
            const String PxTriangleMeshGeometry = "PxTriangleMeshGeometry";
            const String QueryFilterData = "QueryFilterData";
            const String Radius = "Radius";
            const String Restitution = "Restitution";
            const String RestitutionCombineMode = "RestitutionCombineMode";
            const String RestOffset = "RestOffset";
            const String RigidBodyFlags = "RigidBodyFlags";
            const String Rotation = "Rotation";
            const String Scale = "Scale";
            const String Shapes = "Shapes";
            const String SimulationFilterData = "SimulationFilterData";
            const String SleepThreshold = "SleepThreshold";
            const String SolverIterationCounts = "SolverIterationCounts";
            const String Speed = "Speed";
            const String StabilizationThreshold = "StabilizationThreshold";
            const String StaticFriction = "StaticFriction";
            const String Stiffness = "Stiffness";
            const String SwingLimit = "SwingLimit";
            const String text = "text";
            const String torque = "torque";
            const String TriangleMesh = "TriangleMesh";
            const String Triangles = "Triangles";
            const String TwistLimit = "TwistLimit";
            const String Upper = "Upper";
            const String UpVector = "UpVector";
            const String Value = "Value";
            const String WakeCounter = "WakeCounter";
            const String YAngle = "YAngle";
            const String ZAngle = "ZAngle";
        }

        bool equal(xmlNode* node, const String& name)
        {
            if (!node) {
                return false;
            }
            //return _stricmp(reinterpret_cast<const char*>(node->name), name.c_str()) == 0;
            return name == reinterpret_cast<const char*>(node->name);
        }

        template<typename T>
        xmlNode* FindChild(T node, const String& name)
        {
            if (!node) {
                return NULL;
            }

            xmlNode* child = node->children;
            while (child)
            {
                if (equal(child, name)) {
                    return child;
                }
                child = child->next;
            }
            return NULL;
        }

        template<typename T>
        std::vector<xmlNode*> FindChildren(T node, const String& name)
        {
            if (!node) {
                return std::vector<xmlNode*>();
            }

            std::vector<xmlNode*> children;
            xmlNode* child = node->children;
            while (child)
            {
                if (equal(child, name)) {
                    children.push_back(child);
                }
                child = child->next;
            }
            return children;
        }

        void GetContent(xmlNode* node, double& content)
        {
            if (!node) {
                return;
            }

            node = FindChild(node, Strings::text);
            if (!node) {
                return;
            }

            if (!node->content) {
                return;
            }

            std::stringstream s;
            s << node->content;
            s >> content;
        }

        void GetContent(xmlNode* node, int& content)
        {
            if (!node) {
                return;
            }

            node = FindChild(node, Strings::text);
            if (!node) {
                return;
            }

            if (!node->content) {
                return;
            }

            std::stringstream s;
            s << node->content;
            s >> content;
        }

        void GetContent(xmlNode* node, MQuaternion& q, MVector& v)
        {
            if (!node) {
                return;
            }

            node = FindChild(node, Strings::text);
            if (!node) {
                return;
            }

            if (!node->content) {
                return;
            }

            std::stringstream s;
            s << node->content;
            s >> q.x;
            s >> q.y;
            s >> q.z;
            s >> q.w;
            s >> v.x;
            s >> v.y;
            s >> v.z;
        }

        void GetContent(xmlNode* node, int& a, int& b, int& c, int& d)
        {
            if (!node) {
                return;
            }

            node = FindChild(node, Strings::text);
            if (!node) {
                return;
            }

            if (!node->content) {
                return;
            }

            std::stringstream s;
            s << node->content;
            s >> a;
            s >> b;
            s >> c;
            s >> d;
        }

        void GetContent(xmlNode* node, String& content)
        {
            if (!node) {
                return;
            }

            node = FindChild(node, Strings::text);
            if (!node) {
                return;
            }

            if (!node->content) {
                return;
            }

            std::stringstream s;
            s << node->content;
            s >> content;
        }

        void ReplaceAll(String& str, const String& what, const String& by)
        {
            const size_t whatLength = what.length();
            const size_t byLength = by.length();
            for (size_t pos = str.find(what, 0); pos != std::string::npos; pos = str.find(what, pos + byLength))
            {
                str.replace(pos, whatLength, by);
            }
        }

        void GetContent(xmlNode* node, std::vector<PhysXXML::Point>& content)
        {
            content.clear();
            if (!node) {
                return;
            }

            node = FindChild(node, Strings::text);
            if (!node) {
                return;
            }

            if (!node->content) {
                return;
            }

            std::string contentStr = reinterpret_cast<const char*>(node->content);

            // Convert all &#x0A; and &#x09;
            ReplaceAll(contentStr, "&#x0A;", " ");
            ReplaceAll(contentStr, "&#x09;", "");
        
            std::stringstream s(contentStr);

            do {
                PhysXXML::Point p;
                s >> p.x;
                s >> p.y;
                s >> p.z;
                content.push_back(p);
            } while (!s.eof());
        }

        void GetContent(xmlNode* node, std::vector<PhysXXML::Triangle>& content)
        {
            content.clear();
            if (!node) {
                return;
            }

            node = FindChild(node, Strings::text);
            if (!node) {
                return;
            }

            if (!node->content) {
                return;
            }

            std::string contentStr = reinterpret_cast<const char*>(node->content);

            // Convert all &#x0A; and &#x09;
            ReplaceAll(contentStr, "&#x0A;", " ");
            ReplaceAll(contentStr, "&#x09;", "");

            std::stringstream s(contentStr);

            do {
                PhysXXML::Triangle t;
                s >> t.point0;
                s >> t.point1;
                s >> t.point2;
                content.push_back(t);
            } while (!s.eof());
        }

        void GetContent(xmlNode* node, MVector& content)
        {
            if (!node) {
                return;
            }

            node = FindChild(node, Strings::text);
            if (!node) {
                return;
            }

            if (!node->content) {
                return;
            }

            std::stringstream s;
            s << node->content;
            s >> content.x;
            s >> content.y;
            s >> content.z;
        }

        void GetContent(xmlNode* node, MQuaternion& content)
        {
            if (!node) {
                return;
            }

            node = FindChild(node, Strings::text);
            if (!node) {
                return;
            }

            if (!node->content) {
                return;
            }

            std::stringstream s;
            s << node->content;
            s >> content.x;
            s >> content.y;
            s >> content.z;
            s >> content.w;
        }

        UpVector::UpVector(xmlNode* node)
            : upVector(0.0, 0.0, 0.0)
        {
            GetContent(node, upVector);
        }

        void UpVector::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::UpVector);
            sw.appendValues(upVector.x, upVector.y, upVector.z);
            sw.closeElement();
        }

        Length::Length(xmlNode* node)
            : length(0.0)
        {
            GetContent(node, length);
        }

        void Length::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Length);
            sw.appendValues(length);
            sw.closeElement();
        }

        Mass::Mass(xmlNode* node)
            : mass(0.0)
        {
            GetContent(node, mass);
        }

        void Mass::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Mass);
            sw.appendValues(mass);
            sw.closeElement();
        }

        Speed::Speed(xmlNode* node)
            : speed(0.0)
        {
            GetContent(node, speed);
        }

        void Speed::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Speed);
            sw.appendValues(speed);
            sw.closeElement();
        }

        LengthMassSpeedScale::LengthMassSpeedScale(xmlNode* node)
            : length(FindChild(node, Strings::Length))
            , mass(FindChild(node, Strings::Mass))
            , speed(FindChild(node, Strings::Speed))
        {}

        void LengthMassSpeedScale::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Scale);
            length.exportElement(sw);
            mass.exportElement(sw);
            speed.exportElement(sw);
            sw.closeElement();
        }

        Id::Id(xmlNode* node)
            : id(0)
        {
            GetContent(node, id);
        }

        void Id::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Id);
            sw.appendValues(id);
            sw.closeElement();
        }

        Point::Point()
            : x(0.0)
            , y(0.0)
            , z(0.0)
        {}

        Points::Points(xmlNode* node)
        {
            GetContent(node, points);
        }

        void Points::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::points);
            sw.appendValues(&points[0].x, points.size() * 3);
            sw.closeElement();
        }

        PxConvexMesh::PxConvexMesh(xmlNode* node)
            : id(FindChild(node, Strings::Id))
            , points(FindChild(node, Strings::points))
        {}

        void PxConvexMesh::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PxConvexMesh);
            id.exportElement(sw);
            points.exportElement(sw);
            sw.closeElement();
        }

        Triangle::Triangle()
            : point0(0)
            , point1(0)
            , point2(0)
        {}

        Triangles::Triangles(xmlNode* node)
        {
            GetContent(node, triangles);
        }

        void Triangles::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Triangles);
            sw.appendValues(&triangles[0].point0, triangles.size() * 3);
            sw.closeElement();
        }

        PxTriangleMesh::PxTriangleMesh(xmlNode* node)
            : id(FindChild(node, Strings::Id))
            , points(FindChild(node, Strings::points))
            , triangles(FindChild(node, Strings::Triangles))
        {}

        void PxTriangleMesh::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PxTriangleMesh);
            id.exportElement(sw);
            points.exportElement(sw);
            triangles.exportElement(sw);
            sw.closeElement();
        }

        DynamicFriction::DynamicFriction(xmlNode* node)
            : dynamicFriction(0.0)
        {
            GetContent(node, dynamicFriction);
        }

        void DynamicFriction::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::DynamicFriction);
            sw.appendValues(dynamicFriction);
            sw.closeElement();
        }

        StaticFriction::StaticFriction(xmlNode* node)
            : staticFriction(0.0)
        {
            GetContent(node, staticFriction);
        }

        void StaticFriction::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::StaticFriction);
            sw.appendValues(staticFriction);
            sw.closeElement();
        }

        Restitution::Restitution(xmlNode* node)
            : restitution(0.0)
        {
            GetContent(node, restitution);
        }

        void Restitution::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Restitution);
            sw.appendValues(restitution);
            sw.closeElement();
        }

        FrictionCombineMode::FrictionCombineMode(xmlNode* node)
        {
            GetContent(node, frictionCombineMode);
        }

        void FrictionCombineMode::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::FrictionCombineMode);
            sw.appendValues(frictionCombineMode);
            sw.closeElement();
        }

        RestitutionCombineMode::RestitutionCombineMode(xmlNode* node)
        {
            GetContent(node, restitutionCombineMode);
        }

        void RestitutionCombineMode::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::RestitutionCombineMode);
            sw.appendValues(restitutionCombineMode);
            sw.closeElement();
        }

        PxMaterial::PxMaterial(xmlNode* node)
            : id(FindChild(node, Strings::Id))
            , dynamicFriction(FindChild(node, Strings::DynamicFriction))
            , staticFriction(FindChild(node, Strings::StaticFriction))
            , restitution(FindChild(node, Strings::Restitution))
            , frictionCombineMode(FindChild(node, Strings::FrictionCombineMode))
            , restitutionCombineMode(FindChild(node, Strings::RestitutionCombineMode))
        {}

        void PxMaterial::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PxMaterial);
            id.exportElement(sw);
            dynamicFriction.exportElement(sw);
            staticFriction.exportElement(sw);
            restitution.exportElement(sw);
            frictionCombineMode.exportElement(sw);
            restitutionCombineMode.exportElement(sw);
            sw.closeElement();
        }

        Name::Name(xmlNode* node)
        {
            GetContent(node, name);
        }

        void Name::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Name);
            sw.appendValues(name);
            sw.closeElement();
        }

        ActorFlags::ActorFlags(xmlNode* node)
        {
            GetContent(node, actorFlags);
        }

        void ActorFlags::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::ActorFlags);
            sw.appendValues(actorFlags);
            sw.closeElement();
        }

        RigidBodyFlags::RigidBodyFlags(xmlNode* node)
        {
            GetContent(node, rigidBodyFlags);
        }

        void RigidBodyFlags::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::RigidBodyFlags);
            sw.appendValues(rigidBodyFlags);
            sw.closeElement();
        }

        DominanceGroup::DominanceGroup(xmlNode* node)
            : dominanceGroup(0)
        {
            GetContent(node, dominanceGroup);
        }

        void DominanceGroup::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::DominanceGroup);
            sw.appendValues(dominanceGroup);
            sw.closeElement();
        }

        OwnerClient::OwnerClient(xmlNode* node)
            : ownerClient(0)
        {
            GetContent(node, ownerClient);
        }

        void OwnerClient::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::OwnerClient);
            sw.appendValues(ownerClient);
            sw.closeElement();
        }

        GlobalPose::GlobalPose(xmlNode* node)
        {
            GetContent(node, rotation, translation);
        }

        void GlobalPose::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::GlobalPose);
            sw.appendValues(&rotation.x, 7);
            sw.closeElement();
        }

        HalfExtents::HalfExtents(xmlNode* node)
        {
            GetContent(node, halfExtents);
        }

        void HalfExtents::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::HalfExtents);
            sw.appendValues(&halfExtents.x, 3);
            sw.closeElement();
        }

        PxBoxGeometry::PxBoxGeometry(xmlNode* node)
            : halfExtents(FindChild(node, Strings::HalfExtents))
        {}

        void PxBoxGeometry::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PxBoxGeometry);
            halfExtents.exportElement(sw);
            sw.closeElement();
        }

        Radius::Radius(xmlNode* node)
            : radius(0.0)
        {
            GetContent(node, radius);
        }

        void Radius::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Radius);
            sw.appendValues(radius);
            sw.closeElement();
        }

        HalfHeight::HalfHeight(xmlNode* node)
            : halfHeight(0.0)
        {
            GetContent(node, halfHeight);
        }

        void HalfHeight::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::HalfHeight);
            sw.appendValues(halfHeight);
            sw.closeElement();
        }

        PxCapsuleGeometry::PxCapsuleGeometry(xmlNode* node)
            : radius(FindChild(node, Strings::Radius))
            , halfHeight(FindChild(node, Strings::HalfHeight))
        {}

        void PxCapsuleGeometry::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PxCapsuleGeometry);
            radius.exportElement(sw);
            halfHeight.exportElement(sw);
            sw.closeElement();
        }

        Scale::Scale(xmlNode* node)
        {
            GetContent(node, scale);
        }

        void Scale::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Scale);
            sw.appendValues(&scale.x, 3);
            sw.closeElement();
        }

        Rotation::Rotation(xmlNode* node)
        {
            GetContent(node, rotation);
        }

        void Rotation::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Rotation);
            sw.appendValues(rotation.x, rotation.y, rotation.z, rotation.w);
            sw.closeElement();
        }

        MeshScale::MeshScale(xmlNode* node)
            : scale(FindChild(node, Strings::Scale))
            , rotation(FindChild(node, Strings::Rotation))
        {}

        void MeshScale::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Scale);
            scale.exportElement(sw);
            rotation.exportElement(sw);
            sw.closeElement();
        }

        ConvexMesh::ConvexMesh(xmlNode* node)
            : convexMesh(0)
        {
            GetContent(node, convexMesh);
        }

        void ConvexMesh::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::ConvexMesh);
            sw.appendValues(convexMesh);
            sw.closeElement();
        }

        PxConvexMeshGeometry::PxConvexMeshGeometry(xmlNode* node)
            : scale(FindChild(node, Strings::Scale))
            , convexMesh(FindChild(node, Strings::ConvexMesh))
        {}

        void PxConvexMeshGeometry::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PxConvexMeshGeometry);
            scale.exportElement(sw);
            convexMesh.exportElement(sw);
            sw.closeElement();
        }

        PxPlaneGeometry::PxPlaneGeometry(xmlNode* node)
        {}

        void PxPlaneGeometry::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PxPlaneGeometry);
            sw.closeElement();
        }

        PxSphereGeometry::PxSphereGeometry(xmlNode* node)
            : radius(FindChild(node, Strings::Radius))
        {}

        void PxSphereGeometry::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PxSphereGeometry);
            radius.exportElement(sw);
            sw.closeElement();
        }

        TriangleMesh::TriangleMesh(xmlNode* node)
            : triangleMesh(0)
        {
            GetContent(node, triangleMesh);
        }

        void TriangleMesh::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::TriangleMesh);
            sw.appendValues(triangleMesh);
            sw.closeElement();
        }

        PxTriangleMeshGeometry::PxTriangleMeshGeometry(xmlNode* node)
            : scale(FindChild(node, Strings::Scale))
            , triangleMesh(FindChild(node, Strings::TriangleMesh))
        {}

        void PxTriangleMeshGeometry::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PxTriangleMeshGeometry);
            scale.exportElement(sw);
            triangleMesh.exportElement(sw);
            sw.closeElement();
        }

        Geometry::Geometry(xmlNode* node)
            : type(Sphere)
            , boxGeometry(FindChild(node, Strings::PxBoxGeometry))
            , capsuleGeometry(FindChild(node, Strings::PxCapsuleGeometry))
            , convexMeshGeometry(FindChild(node, Strings::PxConvexMeshGeometry))
            , planeGeometry(FindChild(node, Strings::PxPlaneGeometry))
            , sphereGeometry(FindChild(node, Strings::PxSphereGeometry))
            , triangleMeshGeometry(FindChild(node, Strings::PxTriangleMeshGeometry))
        {
            if (FindChild(node, Strings::PxBoxGeometry)) {
                type = Box;
            }
            else if (FindChild(node, Strings::PxCapsuleGeometry)) {
                type = Capsule;
            }
            else if (FindChild(node, Strings::PxConvexMeshGeometry)) {
                type = ConvexMesh;
            }
            else if (FindChild(node, Strings::PxPlaneGeometry)) {
                type = Plane;
            }
            else if (FindChild(node, Strings::PxSphereGeometry)) {
                type = Sphere;
            }
            else if (FindChild(node, Strings::PxTriangleMeshGeometry)) {
                type = TriangleMesh;
            }
        }

        void Geometry::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Geometry);
            switch (type)
            {
            case Box:
                boxGeometry.exportElement(sw);
                break;
            case Capsule:
                capsuleGeometry.exportElement(sw);
                break;
            case ConvexMesh:
                convexMeshGeometry.exportElement(sw);
                break;
            case Plane:
                planeGeometry.exportElement(sw);
                break;
            case Sphere:
                sphereGeometry.exportElement(sw);
                break;
            case TriangleMesh:
                triangleMeshGeometry.exportElement(sw);
                break;
            }
            sw.closeElement();
        }

        LocalPose::LocalPose(xmlNode* node)
        {
            GetContent(node, rotation, translation);
        }

        void LocalPose::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::LocalPose);
            sw.appendValues(&rotation.x, 7);
            sw.closeElement();
        }

        SimulationFilterData::SimulationFilterData(xmlNode* node)
            : filter0(0)
            , filter1(0)
            , filter2(0)
            , filter3(0)
        {
            GetContent(node, filter0, filter1, filter2, filter3);
        }

        void SimulationFilterData::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::SimulationFilterData);
            sw.appendValues(&filter0, 4);
            sw.closeElement();
        }

        QueryFilterData::QueryFilterData(xmlNode* node)
            : filter0(0)
            , filter1(0)
            , filter2(0)
            , filter3(0)
        {
            GetContent(node, filter0, filter1, filter2, filter3);
        }

        void QueryFilterData::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::QueryFilterData);
            sw.appendValues(&filter0, 4);
            sw.closeElement();
        }

        PxMaterialRef::PxMaterialRef(xmlNode* node)
            : materialRef(0)
        {
            GetContent(node, materialRef);
        }

        void PxMaterialRef::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PxMaterialRef);
            sw.appendValues(materialRef);
            sw.closeElement();
        }

        Materials::Materials(xmlNode* node)
            : materialRef(FindChild(node, Strings::PxMaterialRef))
        {}

        void Materials::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Materials);
            materialRef.exportElement(sw);
            sw.closeElement();
        }

        ContactOffset::ContactOffset(xmlNode* node)
            : contactOffset(0.0)
        {
            GetContent(node, contactOffset);
        }

        void ContactOffset::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::ContactOffset);
            sw.appendValues(contactOffset);
            sw.closeElement();
        }

        RestOffset::RestOffset(xmlNode* node)
            : restOffset(0.0)
        {
            GetContent(node, restOffset);
        }

        void RestOffset::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::RestOffset);
            sw.appendValues(restOffset);
            sw.closeElement();
        }

        Flags::Flags(xmlNode* node)
        {
            GetContent(node, flags);
        }

        void Flags::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Flags);
            sw.appendValues(flags);
            sw.closeElement();
        }

        PxShape::PxShape(xmlNode* node)
            : geometry(FindChild(node, Strings::Geometry))
            , localPose(FindChild(node, Strings::LocalPose))
            , simulationFilterData(FindChild(node, Strings::SimulationFilterData))
            , queryFilterData(FindChild(node, Strings::QueryFilterData))
            , materials(FindChild(node, Strings::Materials))
            , contactOffset(FindChild(node, Strings::ContactOffset))
            , restOffset(FindChild(node, Strings::RestOffset))
            , flags(FindChild(node, Strings::Flags))
            , name(FindChild(node, Strings::Name))
        {}

        void PxShape::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PxShape);
            geometry.exportElement(sw);
            localPose.exportElement(sw);
            simulationFilterData.exportElement(sw);
            queryFilterData.exportElement(sw);
            //materials.exportElement(sw);
            contactOffset.exportElement(sw);
            restOffset.exportElement(sw);
            flags.exportElement(sw);
            name.exportElement(sw);
            sw.closeElement();
        }

        Shapes::Shapes(xmlNode* node)
        {
            std::vector<xmlNode*> PxShapes = FindChildren(node, Strings::PxShape);
            for (size_t i = 0; i < PxShapes.size(); ++i) {
                shapes.push_back(PxShape(PxShapes[i]));
            }
        }

        void Shapes::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Shapes);
            for (size_t i = 0; i < shapes.size(); ++i) {
                shapes[i].exportElement(sw);
            }
            sw.closeElement();
        }

        PxRigidStatic::PxRigidStatic(xmlNode* node)
            : id(FindChild(node, Strings::Id))
            , name(FindChild(node, Strings::Name))
            , actorFlags(FindChild(node, Strings::ActorFlags))
            , dominanceGroup(FindChild(node, Strings::DominanceGroup))
            , ownerClient(FindChild(node, Strings::OwnerClient))
            , globalPose(FindChild(node, Strings::GlobalPose))
            , shapes(FindChild(node, Strings::Shapes))
        {}

        void PxRigidStatic::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PxRigidStatic);
            id.exportElement(sw);
            name.exportElement(sw);
            actorFlags.exportElement(sw);
            dominanceGroup.exportElement(sw);
            ownerClient.exportElement(sw);
            globalPose.exportElement(sw);
            //shapes.exportElement(sw);
            sw.closeElement();
        }

        PxShape* PxRigidStatic::findShape(const String& shapeName)
        {
            for (size_t i = 0; i < shapes.shapes.size(); ++i) {
                PxShape& shape = shapes.shapes[i];
                if (shape.name.name == shapeName) {
                    return &shape;
                }
            }
            return NULL;
        }

        CMassLocalPose::CMassLocalPose(xmlNode* node)
        {
            GetContent(node, rotation, translation);
        }

        void CMassLocalPose::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::CMassLocalPose);
            sw.appendValues(&rotation.x, 7);
            sw.closeElement();
        }

        MassSpaceInertiaTensor::MassSpaceInertiaTensor(xmlNode* node)
        {
            GetContent(node, massSpaceInertiaTensor);
        }

        void MassSpaceInertiaTensor::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::MassSpaceInertiaTensor);
            sw.appendValues(&massSpaceInertiaTensor.x, 3);
            sw.closeElement();
        }

        LinearVelocity::LinearVelocity(xmlNode* node)
        {
            GetContent(node, linearVelocity);
        }

        void LinearVelocity::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::LinearVelocity);
            sw.appendValues(&linearVelocity.x, 3);
            sw.closeElement();
        }

        AngularVelocity::AngularVelocity(xmlNode* node)
        {
            GetContent(node, angularVelocity);
        }

        void AngularVelocity::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::AngularVelocity);
            sw.appendValues(&angularVelocity.x, 3);
            sw.closeElement();
        }

        MinCCDAdvanceCoefficient::MinCCDAdvanceCoefficient(xmlNode* node)
            : minCCDAdvanceCoefficient(0.0)
        {
            GetContent(node, minCCDAdvanceCoefficient);
        }

        void MinCCDAdvanceCoefficient::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::MinCCDAdvanceCoefficient);
            sw.appendValues(minCCDAdvanceCoefficient);
            sw.closeElement();
        }

        MaxDepenetrationVelocity::MaxDepenetrationVelocity(xmlNode* node)
            : maxDepenetrationVelocity(0.0)
        {
            GetContent(node, maxDepenetrationVelocity);
        }

        void MaxDepenetrationVelocity::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::MaxDepenetrationVelocity);
            sw.appendValues(maxDepenetrationVelocity);
            sw.closeElement();
        }

        LinearDamping::LinearDamping(xmlNode* node)
            : linearDamping(0.0)
        {
            GetContent(node, linearDamping);
        }

        void LinearDamping::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::LinearDamping);
            sw.appendValues(linearDamping);
            sw.closeElement();
        }

        AngularDamping::AngularDamping(xmlNode* node)
            : angularDamping(0.0)
        {
            GetContent(node, angularDamping);
        }

        void AngularDamping::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::AngularDamping);
            sw.appendValues(angularDamping);
            sw.closeElement();
        }

        MaxAngularVelocity::MaxAngularVelocity(xmlNode* node)
            : maxAngularVelocity(0.0)
        {
            GetContent(node, maxAngularVelocity);
        }

        void MaxAngularVelocity::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::MaxAngularVelocity);
            sw.appendValues(maxAngularVelocity);
            sw.closeElement();
        }

        SleepThreshold::SleepThreshold(xmlNode* node)
            : sleepThreshold(0.0)
        {
            GetContent(node, sleepThreshold);
        }

        void SleepThreshold::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::SleepThreshold);
            sw.appendValues(sleepThreshold);
            sw.closeElement();
        }

        StabilizationThreshold::StabilizationThreshold(xmlNode* node)
            : stabilizationThreshold(0.0)
        {
            GetContent(node, stabilizationThreshold);
        }

        void StabilizationThreshold::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::StabilizationThreshold);
            sw.appendValues(stabilizationThreshold);
            sw.closeElement();
        }

        WakeCounter::WakeCounter(xmlNode* node)
            : wakeCounter(0.0)
        {
            GetContent(node, wakeCounter);
        }

        void WakeCounter::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::WakeCounter);
            sw.appendValues(wakeCounter);
            sw.closeElement();
        }

        MinPositionIters::MinPositionIters(xmlNode* node)
            : minPositionIters(0)
        {
            GetContent(node, minPositionIters);
        }

        void MinPositionIters::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::minPositionIters);
            sw.appendValues(minPositionIters);
            sw.closeElement();
        }

        MinVelocityIters::MinVelocityIters(xmlNode* node)
            : minVelocityIters(0)
        {
            GetContent(node, minVelocityIters);
        }

        void MinVelocityIters::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::minVelocityIters);
            sw.appendValues(minVelocityIters);
            sw.closeElement();
        }

        SolverIterationCounts::SolverIterationCounts(xmlNode* node)
            : minPositionIters(FindChild(node, Strings::minPositionIters))
            , minVelocityIters(FindChild(node, Strings::minVelocityIters))
        {}

        void SolverIterationCounts::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::SolverIterationCounts);
            minPositionIters.exportElement(sw);
            minVelocityIters.exportElement(sw);
            sw.closeElement();
        }

        ContactReportThreshold::ContactReportThreshold(xmlNode* node)
            : contactReportThreshold(0.0)
        {
            GetContent(node, contactReportThreshold);
        }

        void ContactReportThreshold::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::ContactReportThreshold);
            sw.appendValues(contactReportThreshold);
            sw.closeElement();
        }

        PxRigidDynamic::PxRigidDynamic(xmlNode* node)
            : id(FindChild(node, Strings::Id))
            , name(FindChild(node, Strings::Name))
            , actorFlags(FindChild(node, Strings::ActorFlags))
            , dominanceGroup(FindChild(node, Strings::DominanceGroup))
            , ownerClient(FindChild(node, Strings::OwnerClient))
            , globalPose(FindChild(node, Strings::GlobalPose))
            , shapes(FindChild(node, Strings::Shapes))
            , cMassLocalPose(FindChild(node, Strings::CMassLocalPose))
            , mass(FindChild(node, Strings::Mass))
            , massSpaceInertiaTensor(FindChild(node, Strings::MassSpaceInertiaTensor))
            , linearVelocity(FindChild(node, Strings::LinearVelocity))
            , angularVelocity(FindChild(node, Strings::AngularVelocity))
            , minCCDAdvanceCoefficient(FindChild(node, Strings::MinCCDAdvanceCoefficient))
            , maxDepenetrationVelocity(FindChild(node, Strings::MaxDepenetrationVelocity))
            , linearDamping(FindChild(node, Strings::LinearDamping))
            , angularDamping(FindChild(node, Strings::AngularDamping))
            , rigidBodyFlags(FindChild(node, Strings::RigidBodyFlags))
            , maxAngularVelocity(FindChild(node, Strings::MaxAngularVelocity))
            , sleepThreshold(FindChild(node, Strings::SleepThreshold))
            , stabilizationThreshold(FindChild(node, Strings::StabilizationThreshold))
            , wakeCounter(FindChild(node, Strings::WakeCounter))
            , solverIterationCounts(FindChild(node, Strings::SolverIterationCounts))
            , contactReportThreshold(FindChild(node, Strings::ContactReportThreshold))
        {}

        void PxRigidDynamic::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PxRigidDynamic);
            id.exportElement(sw);
            name.exportElement(sw);
            actorFlags.exportElement(sw);
            dominanceGroup.exportElement(sw);
            ownerClient.exportElement(sw);
            globalPose.exportElement(sw);
            //shapes.exportElement(sw);
            cMassLocalPose.exportElement(sw);
            mass.exportElement(sw);
            massSpaceInertiaTensor.exportElement(sw);
            linearVelocity.exportElement(sw);
            angularVelocity.exportElement(sw);
            rigidBodyFlags.exportElement(sw);
            minCCDAdvanceCoefficient.exportElement(sw);
            maxDepenetrationVelocity.exportElement(sw);
            linearDamping.exportElement(sw);
            angularDamping.exportElement(sw);
            maxAngularVelocity.exportElement(sw);
            sleepThreshold.exportElement(sw);
            stabilizationThreshold.exportElement(sw);
            wakeCounter.exportElement(sw);
            solverIterationCounts.exportElement(sw);
            contactReportThreshold.exportElement(sw);
            sw.closeElement();
        }

        PxShape* PxRigidDynamic::findShape(const String& shapeName)
        {
            for (size_t i = 0; i < shapes.shapes.size(); ++i) {
                PxShape& shape = shapes.shapes[i];
                if (shape.name.name == shapeName) {
                    return &shape;
                }
            }
            return NULL;
        }

        Actor0::Actor0(xmlNode* node)
            : actor0(0)
        {
            GetContent(node, actor0);
        }

        void Actor0::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::actor0);
            sw.appendValues(actor0);
            sw.closeElement();
        }

        Actor1::Actor1(xmlNode* node)
            : actor1(0)
        {
            GetContent(node, actor1);
        }

        void Actor1::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::actor1);
            sw.appendValues(actor1);
            sw.closeElement();
        }

        Actors::Actors(xmlNode* node)
            : actor0(FindChild(node, Strings::actor0))
            , actor1(FindChild(node, Strings::actor1))
        {}

        void Actors::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Actors);
            actor0.exportElement(sw);
            actor1.exportElement(sw);
            sw.closeElement();
        }

        EActor0::EActor0(xmlNode* node)
        {
            GetContent(node, rotation, translation);
        }

        void EActor0::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::eACTOR0);
            sw.appendValues(&rotation.x, 7);
            sw.closeElement();
        }

        EActor1::EActor1(xmlNode* node)
        {
            GetContent(node, rotation, translation);
        }

        void EActor1::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::eACTOR1);
            sw.appendValues(&rotation.x, 7);
            sw.closeElement();
        }

        ActorLocalPose::ActorLocalPose(xmlNode* node)
            : eActor0(FindChild(node, Strings::eACTOR0))
            , eActor1(FindChild(node, Strings::eACTOR1))
        {}

        void ActorLocalPose::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::LocalPose);
            eActor0.exportElement(sw);
            eActor1.exportElement(sw);
            sw.closeElement();
        }

        Force::Force(xmlNode* node)
            : force(0.0)
        {
            GetContent(node, force);
        }

        void Force::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::force);
            sw.appendValues(force);
            sw.closeElement();
        }

        Torque::Torque(xmlNode* node)
            : torque(0.0)
        {
            GetContent(node, torque);
        }

        void Torque::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::torque);
            sw.appendValues(torque);
            sw.closeElement();
        }

        BreakForce::BreakForce(xmlNode* node)
            : force(FindChild(node, Strings::force))
            , torque(FindChild(node, Strings::torque))
        {}

        void BreakForce::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::BreakForce);
            force.exportElement(sw);
            torque.exportElement(sw);
            sw.closeElement();
        }

        ConstraintFlags::ConstraintFlags(xmlNode* node)
        {
            GetContent(node, flags);
        }
        
        void ConstraintFlags::exportElement(COLLADASW::StreamWriter& sw)
        {
            sw.openElement(Strings::ConstraintFlags);
            sw.appendValues(flags);
            sw.closeElement();
        }

        InvMassScale0::InvMassScale0(xmlNode* node)
            : invMassScale0(0.0)
        {
            GetContent(node, invMassScale0);
        }

        void InvMassScale0::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::InvMassScale0);
            sw.appendValues(invMassScale0);
            sw.closeElement();
        }

        InvMassScale1::InvMassScale1(xmlNode* node)
            : invMassScale1(0.0)
        {
            GetContent(node, invMassScale1);
        }

        void InvMassScale1::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::InvMassScale1);
            sw.appendValues(invMassScale1);
            sw.closeElement();
        }

        InvInertiaScale0::InvInertiaScale0(xmlNode* node)
            : invInertiaScale0(0.0)
        {
            GetContent(node, invInertiaScale0);
        }

        void InvInertiaScale0::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::InvInertiaScale0);
            sw.appendValues(invInertiaScale0);
            sw.closeElement();
        }

        InvInertiaScale1::InvInertiaScale1(xmlNode* node)
            : invInertiaScale1(0.0)
        {
            GetContent(node, invInertiaScale1);
        }

        void InvInertiaScale1::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::InvInertiaScale1);
            sw.appendValues(invInertiaScale1);
            sw.closeElement();
        }

        MotionX::MotionX(xmlNode* node)
        {
            GetContent(node, eX);
        }

        void MotionX::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::eX);
            sw.appendValues(eX);
            sw.closeElement();
        }

        MotionY::MotionY(xmlNode* node)
        {
            GetContent(node, eY);
        }

        void MotionY::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::eY);
            sw.appendValues(eY);
            sw.closeElement();
        }

        MotionZ::MotionZ(xmlNode* node)
        {
            GetContent(node, eZ);
        }

        void MotionZ::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::eZ);
            sw.appendValues(eZ);
            sw.closeElement();
        }

        MotionTwist::MotionTwist(xmlNode* node)
        {
            GetContent(node, eTwist);
        }

        void MotionTwist::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::eTWIST);
            sw.appendValues(eTwist);
            sw.closeElement();
        }

        MotionSwing1::MotionSwing1(xmlNode* node)
        {
            GetContent(node, eSwing1);
        }

        void MotionSwing1::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::eSWING1);
            sw.appendValues(eSwing1);
            sw.closeElement();
        }

        MotionSwing2::MotionSwing2(xmlNode* node)
        {
            GetContent(node, eSwing2);
        }

        void MotionSwing2::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::eSWING2);
            sw.appendValues(eSwing2);
            sw.closeElement();
        }

        Motion::Motion(xmlNode* node)
            : eX(FindChild(node, Strings::eX))
            , eY(FindChild(node, Strings::eY))
            , eZ(FindChild(node, Strings::eZ))
            , eTwist(FindChild(node, Strings::eTWIST))
            , eSwing1(FindChild(node, Strings::eSWING1))
            , eSwing2(FindChild(node, Strings::eSWING2))
        {}

        void Motion::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Motion);
            eX.exportElement(sw);
            eY.exportElement(sw);
            eZ.exportElement(sw);
            eTwist.exportElement(sw);
            eSwing1.exportElement(sw);
            eSwing2.exportElement(sw);
            sw.closeElement();
        }

        BounceThreshold::BounceThreshold(xmlNode* node)
            : bounceThreshold(0.0)
        {
            GetContent(node, bounceThreshold);
        }

        void BounceThreshold::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::BounceThreshold);
            sw.appendValues(bounceThreshold);
            sw.closeElement();
        }

        Stiffness::Stiffness(xmlNode* node)
            : stiffness(0.0)
        {
            GetContent(node, stiffness);
        }

        void Stiffness::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Stiffness);
            sw.appendValues(stiffness);
            sw.closeElement();
        }

        Damping::Damping(xmlNode* node)
            : damping(0.0)
        {
            GetContent(node, damping);
        }

        void Damping::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Damping);
            sw.appendValues(damping);
            sw.closeElement();
        }

        ContactDistance::ContactDistance(xmlNode* node)
            : contactDistance(0.0)
        {
            GetContent(node, contactDistance);
        }

        void ContactDistance::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::ContactDistance);
            sw.appendValues(contactDistance);
            sw.closeElement();
        }

        Value::Value(xmlNode* node)
            : value(0.0)
        {
            GetContent(node, value);
        }

        void Value::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Value);
            sw.appendValues(value);
            sw.closeElement();
        }

        LinearLimit::LinearLimit(xmlNode* node)
            : restitution(FindChild(node, Strings::Restitution))
            , bounceThreshold(FindChild(node, Strings::BounceThreshold))
            , stiffness(FindChild(node, Strings::Stiffness))
            , damping(FindChild(node, Strings::Damping))
            , contactDistance(FindChild(node, Strings::ContactDistance))
            , value(FindChild(node, Strings::Value))
        {}

        void LinearLimit::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::LinearLimit);
            restitution.exportElement(sw);
            bounceThreshold.exportElement(sw);
            stiffness.exportElement(sw);
            damping.exportElement(sw);
            contactDistance.exportElement(sw);
            value.exportElement(sw);
            sw.closeElement();
        }

        Upper::Upper(xmlNode* node)
            : upper(0.0)
        {
            GetContent(node, upper);
        }

        void Upper::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Upper);
            sw.appendValues(upper);
            sw.closeElement();
        }

        Lower::Lower(xmlNode* node)
            : lower(0.0)
        {
            GetContent(node, lower);
        }

        void Lower::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Lower);
            sw.appendValues(lower);
            sw.closeElement();
        }

        TwistLimit::TwistLimit(xmlNode* node)
            : restitution(FindChild(node, Strings::Restitution))
            , bounceThreshold(FindChild(node, Strings::BounceThreshold))
            , stiffness(FindChild(node, Strings::Stiffness))
            , damping(FindChild(node, Strings::Damping))
            , contactDistance(FindChild(node, Strings::ContactDistance))
            , upper(FindChild(node, Strings::Upper))
            , lower(FindChild(node, Strings::Lower))
        {}

        void TwistLimit::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::TwistLimit);
            restitution.exportElement(sw);
            bounceThreshold.exportElement(sw);
            stiffness.exportElement(sw);
            damping.exportElement(sw);
            contactDistance.exportElement(sw);
            upper.exportElement(sw);
            lower.exportElement(sw);
            sw.closeElement();
        }

        YAngle::YAngle(xmlNode* node)
            : yAngle(0.0)
        {
            GetContent(node, yAngle);
        }

        void YAngle::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::YAngle);
            sw.appendValues(yAngle);
            sw.closeElement();
        }

        ZAngle::ZAngle(xmlNode* node)
            : zAngle(0.0)
        {
            GetContent(node, zAngle);
        }

        void ZAngle::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::ZAngle);
            sw.appendValues(zAngle);
            sw.closeElement();
        }

        SwingLimit::SwingLimit(xmlNode* node)
            : restitution(FindChild(node, Strings::Restitution))
            , bounceThreshold(FindChild(node, Strings::BounceThreshold))
            , stiffness(FindChild(node, Strings::Stiffness))
            , damping(FindChild(node, Strings::Damping))
            , contactDistance(FindChild(node, Strings::ContactDistance))
            , yAngle(FindChild(node, Strings::YAngle))
            , zAngle(FindChild(node, Strings::ZAngle))
        {}

        void SwingLimit::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::SwingLimit);
            restitution.exportElement(sw);
            bounceThreshold.exportElement(sw);
            stiffness.exportElement(sw);
            damping.exportElement(sw);
            contactDistance.exportElement(sw);
            yAngle.exportElement(sw);
            zAngle.exportElement(sw);
            sw.closeElement();
        }

        ForceLimit::ForceLimit(xmlNode* node)
            : forceLimit(0.0)
        {
            GetContent(node, forceLimit);
        }

        void ForceLimit::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::ForceLimit);
            sw.appendValues(forceLimit);
            sw.closeElement();
        }

        DriveX::DriveX(xmlNode* node)
            : stiffness(FindChild(node, Strings::Stiffness))
            , damping(FindChild(node, Strings::Damping))
            , forceLimit(FindChild(node, Strings::ForceLimit))
            , flags(FindChild(node, Strings::Flags))
        {}

        void DriveX::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::eX);
            stiffness.exportElement(sw);
            damping.exportElement(sw);
            forceLimit.exportElement(sw);
            flags.exportElement(sw);
            sw.closeElement();
        }

        DriveY::DriveY(xmlNode* node)
            : stiffness(FindChild(node, Strings::Stiffness))
            , damping(FindChild(node, Strings::Damping))
            , forceLimit(FindChild(node, Strings::ForceLimit))
            , flags(FindChild(node, Strings::Flags))
        {}

        void DriveY::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::eY);
            stiffness.exportElement(sw);
            damping.exportElement(sw);
            forceLimit.exportElement(sw);
            flags.exportElement(sw);
            sw.closeElement();
        }

        DriveZ::DriveZ(xmlNode* node)
            : stiffness(FindChild(node, Strings::Stiffness))
            , damping(FindChild(node, Strings::Damping))
            , forceLimit(FindChild(node, Strings::ForceLimit))
            , flags(FindChild(node, Strings::Flags))
        {}

        void DriveZ::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::eZ);
            stiffness.exportElement(sw);
            damping.exportElement(sw);
            forceLimit.exportElement(sw);
            flags.exportElement(sw);
            sw.closeElement();
        }

        DriveSwing::DriveSwing(xmlNode* node)
            : stiffness(FindChild(node, Strings::Stiffness))
            , damping(FindChild(node, Strings::Damping))
            , forceLimit(FindChild(node, Strings::ForceLimit))
            , flags(FindChild(node, Strings::Flags))
        {}

        void DriveSwing::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::eSWING);
            stiffness.exportElement(sw);
            damping.exportElement(sw);
            forceLimit.exportElement(sw);
            flags.exportElement(sw);
            sw.closeElement();
        }

        DriveTwist::DriveTwist(xmlNode* node)
            : stiffness(FindChild(node, Strings::Stiffness))
            , damping(FindChild(node, Strings::Damping))
            , forceLimit(FindChild(node, Strings::ForceLimit))
            , flags(FindChild(node, Strings::Flags))
        {}

        void DriveTwist::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::eTWIST);
            stiffness.exportElement(sw);
            damping.exportElement(sw);
            forceLimit.exportElement(sw);
            flags.exportElement(sw);
            sw.closeElement();
        }

        DriveSlerp::DriveSlerp(xmlNode* node)
            : stiffness(FindChild(node, Strings::Stiffness))
            , damping(FindChild(node, Strings::Damping))
            , forceLimit(FindChild(node, Strings::ForceLimit))
        {}

        void DriveSlerp::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::eSLERP);
            stiffness.exportElement(sw);
            damping.exportElement(sw);
            forceLimit.exportElement(sw);
            sw.closeElement();
        }

        Drive::Drive(xmlNode* node)
            : driveX(FindChild(node, Strings::eX))
            , driveY(FindChild(node, Strings::eY))
            , driveZ(FindChild(node, Strings::eZ))
            , driveSwing(FindChild(node, Strings::eSWING))
            , driveTwist(FindChild(node, Strings::eTWIST))
            , driveSlerp(FindChild(node, Strings::eSLERP))
        {}

        void Drive::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::Drive);
            driveX.exportElement(sw);
            driveY.exportElement(sw);
            driveZ.exportElement(sw);
            driveSwing.exportElement(sw);
            driveTwist.exportElement(sw);
            driveSlerp.exportElement(sw);
            sw.closeElement();
        }

        DrivePosition::DrivePosition(xmlNode* node)
        {
            GetContent(node, rotation, translation);
        }

        void DrivePosition::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::DrivePosition);
            sw.appendValues(&rotation.x, 7);
            sw.closeElement();
        }

        Linear::Linear(xmlNode* node)
        {
            GetContent(node, linear);
        }

        void Linear::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::linear);
            sw.appendValues(&linear.x, 3);
            sw.closeElement();
        }

        Angular::Angular(xmlNode* node)
        {
            GetContent(node, angular);
        }

        void Angular::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::angular);
            sw.appendValues(&angular.x, 3);
            sw.closeElement();
        }

        DriveVelocity::DriveVelocity(xmlNode* node)
            : linear(FindChild(node, Strings::linear))
            , angular(FindChild(node, Strings::angular))
        {}

        void DriveVelocity::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::DriveVelocity);
            linear.exportElement(sw);
            angular.exportElement(sw);
            sw.closeElement();
        }

        ProjectionLinearTolerance::ProjectionLinearTolerance(xmlNode* node)
            : projectionLinearTolerance(0.0)
        {
            GetContent(node, projectionLinearTolerance);
        }

        void ProjectionLinearTolerance::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::ProjectionLinearTolerance);
            sw.appendValues(projectionLinearTolerance);
            sw.closeElement();
        }

        ProjectionAngularTolerance::ProjectionAngularTolerance(xmlNode* node)
            : projectionAngularTolerance(0.0)
        {
            GetContent(node, projectionAngularTolerance);
        }

        void ProjectionAngularTolerance::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::ProjectionAngularTolerance);
            sw.appendValues(projectionAngularTolerance);
            sw.closeElement();
        }

        PxD6Joint::PxD6Joint(xmlNode* node)
            : id(FindChild(node, Strings::Id))
            , actors(FindChild(node, Strings::Actors))
            , localPose(FindChild(node, Strings::LocalPose))
            , breakForce(FindChild(node, Strings::BreakForce))
            , constraintFlags(FindChild(node, Strings::ConstraintFlags))
            , invMassScale0(FindChild(node, Strings::InvMassScale0))
            , invInertiaScale0(FindChild(node, Strings::InvInertiaScale0))
            , invMassScale1(FindChild(node, Strings::InvMassScale1))
            , invInertiaScale1(FindChild(node, Strings::InvInertiaScale1))
            , name(FindChild(node, Strings::Name))
            , motion(FindChild(node, Strings::Motion))
            , linearLimit(FindChild(node, Strings::LinearLimit))
            , twistLimit(FindChild(node, Strings::TwistLimit))
            , swingLimit(FindChild(node, Strings::SwingLimit))
            , drive(FindChild(node, Strings::Drive))
            , drivePosition(FindChild(node, Strings::DrivePosition))
            , driveVelocity(FindChild(node, Strings::DriveVelocity))
            , projectionLinearTolerance(FindChild(node, Strings::ProjectionLinearTolerance))
            , projectionAngularTolerance(FindChild(node, Strings::ProjectionAngularTolerance))
        {}

        void PxD6Joint::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PxD6Joint);
            id.exportElement(sw);
            actors.exportElement(sw);
            localPose.exportElement(sw);
            breakForce.exportElement(sw);
            constraintFlags.exportElement(sw);
            invMassScale0.exportElement(sw);
            invInertiaScale0.exportElement(sw);
            invMassScale1.exportElement(sw);
            invInertiaScale1.exportElement(sw);
            name.exportElement(sw);
            motion.exportElement(sw);
            linearLimit.exportElement(sw);
            twistLimit.exportElement(sw);
            swingLimit.exportElement(sw);
            drive.exportElement(sw);
            drivePosition.exportElement(sw);
            driveVelocity.exportElement(sw);
            projectionLinearTolerance.exportElement(sw);
            projectionAngularTolerance.exportElement(sw);
            sw.closeElement();
        }

        PhysX30Collection::PhysX30Collection(xmlNode* node)
            : upVector(FindChild(node, Strings::UpVector))
            , scale(FindChild(node, Strings::Scale))
        {
            std::vector<xmlNode*> convexMeshNodes = FindChildren(node, Strings::PxConvexMesh);
            for (size_t i = 0; i < convexMeshNodes.size(); ++i) {
                convexMeshes.push_back(PxConvexMesh(convexMeshNodes[i]));
            }

            std::vector<xmlNode*> triangleMeshNodes = FindChildren(node, Strings::PxTriangleMesh);
            for (size_t i = 0; i < triangleMeshNodes.size(); ++i) {
                triangleMeshes.push_back(PxTriangleMesh(triangleMeshNodes[i]));
            }

            std::vector<xmlNode*> materialNodes = FindChildren(node, Strings::PxMaterial);
            for (size_t i = 0; i < materialNodes.size(); ++i) {
                materials.push_back(PxMaterial(materialNodes[i]));
            }

            std::vector<xmlNode*> rigidStaticNodes = FindChildren(node, Strings::PxRigidStatic);
            for (size_t i = 0; i < rigidStaticNodes.size(); ++i) {
                rigidStatics.push_back(PxRigidStatic(rigidStaticNodes[i]));
            }

            std::vector<xmlNode*> rigidDynamicNodes = FindChildren(node, Strings::PxRigidDynamic);
            for (size_t i = 0; i < rigidDynamicNodes.size(); ++i) {
                rigidDynamics.push_back(PxRigidDynamic(rigidDynamicNodes[i]));
            }

            std::vector<xmlNode*> D6JointNodes = FindChildren(node, Strings::PxD6Joint);
            for (size_t i = 0; i < D6JointNodes.size(); ++i) {
                D6Joints.push_back(PxD6Joint(D6JointNodes[i]));
            }
        }

        void PhysX30Collection::exportElement(StreamWriter& sw)
        {
            sw.openElement(Strings::PhysX30Collection);
            upVector.exportElement(sw);
            scale.exportElement(sw);
            for (size_t i = 0; i < convexMeshes.size(); ++i) {
                convexMeshes[i].exportElement(sw);
            }
            for (size_t i = 0; i < triangleMeshes.size(); ++i) {
                triangleMeshes[i].exportElement(sw);
            }
            for (size_t i = 0; i < materials.size(); ++i) {
                materials[i].exportElement(sw);
            }
            for (size_t i = 0; i < rigidStatics.size(); ++i) {
                rigidStatics[i].exportElement(sw);
            }
            for (size_t i = 0; i < rigidDynamics.size(); ++i) {
                rigidDynamics[i].exportElement(sw);
            }
            for (size_t i = 0; i < D6Joints.size(); ++i) {
                D6Joints[i].exportElement(sw);
            }
            sw.closeElement();
        }

        PhysXDoc::PhysXDoc(xmlDocPtr xml)
            : physX30Collection(FindChild(xml, Strings::PhysX30Collection))
        {}

        bool PhysXDoc::validate()
        {
            // PhysX plugin sets a name to each object based on Maya node name (not full DagPath).
            // If 2 nodes have the same name then we can't find corresponding PhysX object in the XML file.
            // A fix for this would be to set PhysX object name to node full DagPath (in PhysX plugin source code).

            for (size_t i = 0; i < physX30Collection.rigidDynamics.size(); ++i) {
                for (size_t j = 0; j < physX30Collection.rigidDynamics.size(); ++j) {
                    if (i != j &&
                        physX30Collection.rigidDynamics[i].name.name == physX30Collection.rigidDynamics[j].name.name) {
                        MGlobal::displayError((String("Duplicated dynamic rigid body name: ") + physX30Collection.rigidDynamics[i].name.name).c_str());
                        return false;
                    }
                }
                
                // Also check for duplicated shape name
                for (size_t si = 0; si < physX30Collection.rigidDynamics[i].shapes.shapes.size(); ++si) {
                    for (size_t sj = 0; sj < physX30Collection.rigidDynamics[i].shapes.shapes.size(); ++sj) {
                        if (si !=  sj &&
                            physX30Collection.rigidDynamics[i].shapes.shapes[si].name.name ==
                            physX30Collection.rigidDynamics[i].shapes.shapes[sj].name.name) {
                            MGlobal::displayError((String("Duplicated shape name: ") + physX30Collection.rigidDynamics[i].shapes.shapes[si].name.name).c_str());
                            return false;
                        }
                    }
                }
            }

            for (size_t i = 0; i < physX30Collection.rigidStatics.size(); ++i) {
                for (size_t j = 0; j < physX30Collection.rigidStatics.size(); ++j) {
                    if (i != j &&
                        physX30Collection.rigidStatics[i].name.name == physX30Collection.rigidStatics[j].name.name) {
                        MGlobal::displayError((String("Duplicated static rigid body name: ") + physX30Collection.rigidStatics[i].name.name).c_str());
                        return false;
                    }
                }
                
                // Also check for duplicated shape name
                for (size_t si = 0; si < physX30Collection.rigidStatics[i].shapes.shapes.size(); ++si) {
                    for (size_t sj = 0; sj < physX30Collection.rigidStatics[i].shapes.shapes.size(); ++sj) {
                        if (si !=  sj &&
                            physX30Collection.rigidStatics[i].shapes.shapes[si].name.name ==
                            physX30Collection.rigidStatics[i].shapes.shapes[sj].name.name) {
                            MGlobal::displayError((String("Duplicated shape name: ") + physX30Collection.rigidStatics[i].shapes.shapes[si].name.name).c_str());
                            return false;
                        }
                    }
                }
            }

            for (size_t i = 0; i < physX30Collection.D6Joints.size(); ++i) {
                for (size_t j = 0; j < physX30Collection.D6Joints.size(); ++j) {
                    if (i != j &&
                        physX30Collection.D6Joints[i].name.name == physX30Collection.D6Joints[j].name.name) {
                        MGlobal::displayError((String("Duplicated constraint name: ") + physX30Collection.D6Joints[i].name.name).c_str());
                        return false;
                    }
                }
            }

            return true;
        }

        PxConvexMesh* PhysXDoc::findConvexMesh(int id)
        {
            for (size_t i = 0; i < physX30Collection.convexMeshes.size(); ++i) {
                PxConvexMesh& convexMesh = physX30Collection.convexMeshes[i];
                if (convexMesh.id.id == id)
                    return &convexMesh;
            }
            return NULL;
        }

        PxTriangleMesh* PhysXDoc::findTriangleMesh(int id)
        {
            for (size_t i = 0; i < physX30Collection.triangleMeshes.size(); ++i) {
                PxTriangleMesh& triangleMesh = physX30Collection.triangleMeshes[i];
                if (triangleMesh.id.id == id)
                    return &triangleMesh;
            }
            return NULL;
        }

        PxMaterial* PhysXDoc::findMaterial(int ref)
        {
            for (size_t i = 0; i < physX30Collection.materials.size(); ++i) {
                PxMaterial& material = physX30Collection.materials[i];
                if (material.id.id == ref) {
                    return &material;
                }
            }
            return NULL;
        }

        PxMaterial* PhysXDoc::findMaterial(const String& bodyName, const String& shapeName)
        {
            PxShape* shape = findShape(bodyName, shapeName);
            if (shape) {
                return findMaterial(shape->materials.materialRef.materialRef);
            }
            return NULL;
        }

        PxShape* PhysXDoc::findShape(const String& bodyName, const String& shapeName)
        {
            PxRigidStatic* rigidStatic = findRigidStatic(bodyName);
            if (rigidStatic) {
                return rigidStatic->findShape(shapeName);
            }
            PxRigidDynamic* rigidDynamic = findRigidDynamic(bodyName);
            if (rigidDynamic) {
                return rigidDynamic->findShape(shapeName);
            }
            return NULL;
        }

        PxRigidStatic* PhysXDoc::findRigidStatic(const String& bodyName)
        {
            for (size_t i = 0; i < physX30Collection.rigidStatics.size(); ++i) {
                PxRigidStatic& rigid = physX30Collection.rigidStatics[i];
                if (rigid.name.name == bodyName) {
                    return &rigid;
                }
            }
            return NULL;
        }

        PxRigidDynamic* PhysXDoc::findRigidDynamic(const String& bodyName)
        {
            for (size_t i = 0; i < physX30Collection.rigidDynamics.size(); ++i) {
                PxRigidDynamic& rigid = physX30Collection.rigidDynamics[i];
                if (rigid.name.name == bodyName) {
                    return &rigid;
                }
            }
            return NULL;
        }

        PxD6Joint* PhysXDoc::findD6Joint(const String& jointName)
        {
            for (size_t i = 0; i < physX30Collection.D6Joints.size(); ++i) {
                PxD6Joint& joint = physX30Collection.D6Joints[i];
                if (joint.name.name == jointName) {
                    return &joint;
                }
            }
            return NULL;
        }

        PhysXDocPtr::PhysXDocPtr()
            : mPhysXDoc(NULL)
        {}

        PhysXDocPtr::PhysXDocPtr(xmlDocPtr xml)
        {
            if (mPhysXDoc) {
                delete mPhysXDoc;
            }
            mPhysXDoc = new PhysXDoc(xml);
        }

        PhysXDocPtr::~PhysXDocPtr()
        {
            if (mPhysXDoc) {
                delete mPhysXDoc;
            }
        }

        const PhysXDocPtr& PhysXDocPtr::operator = (xmlDocPtr xml)
        {
            if (mPhysXDoc) {
                delete mPhysXDoc;
            }
            mPhysXDoc = new PhysXDoc(xml);
            return *this;
        }

        PhysXDoc* PhysXDocPtr::operator -> () const
        {
            return mPhysXDoc;
        }

        PhysXDocPtr::operator bool() const
        {
            return mPhysXDoc != NULL;
        }
    }
}