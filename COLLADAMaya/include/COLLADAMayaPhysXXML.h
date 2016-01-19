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

#pragma once

#include "COLLADAMayaPrerequisites.h"
#include "COLLADASWStreamWriter.h"

#include <libxml/parser.h>

namespace COLLADAMaya
{
    namespace PhysXXML
    {
        struct UpVector
        {
            UpVector(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MVector upVector;
        };

        struct Length
        {
            Length(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double length;
        };

        struct Mass
        {
            Mass(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double mass;
        };

        struct Speed
        {
            Speed(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double speed;
        };

        struct LengthMassSpeedScale
        {
            LengthMassSpeedScale(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Length length;
            Mass mass;
            Speed speed;
        };

        struct Id
        {
            Id(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            int id;
        };

        struct Point
        {
            Point();

            double x;
            double y;
            double z;
        };

        struct Points
        {
            Points(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            std::vector<Point> points;
        };

        struct PxConvexMesh
        {
            PxConvexMesh(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Id id;
            Points points;
        };

        struct Triangle
        {
            Triangle();

            int point0;
            int point1;
            int point2;
        };

        struct Triangles
        {
            Triangles(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            std::vector<Triangle> triangles;
        };

        struct PxTriangleMesh
        {
            PxTriangleMesh(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Id id;
            Points points;
            Triangles triangles;
        };

        struct DynamicFriction
        {
            DynamicFriction(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double dynamicFriction;
        };

        struct StaticFriction
        {
            StaticFriction(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double staticFriction;
        };

        struct Restitution
        {
            Restitution(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double restitution;
        };

        struct FrictionCombineMode
        {
            FrictionCombineMode(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            String frictionCombineMode;
        };

        struct RestitutionCombineMode
        {
            RestitutionCombineMode(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            String restitutionCombineMode;
        };

        struct PxMaterial
        {
            PxMaterial(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Id id;
            DynamicFriction dynamicFriction;
            StaticFriction staticFriction;
            Restitution restitution;
            FrictionCombineMode frictionCombineMode;
            RestitutionCombineMode restitutionCombineMode;
        };

        struct Name
        {
            Name(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            String name;
        };

        struct ActorFlags
        {
            ActorFlags(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            String actorFlags;
        };

        struct RigidBodyFlags
        {
            RigidBodyFlags(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            String rigidBodyFlags;
        };

        struct DominanceGroup
        {
            DominanceGroup(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            int dominanceGroup;
        };

        struct OwnerClient
        {
            OwnerClient(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            int ownerClient;
        };

        struct GlobalPose
        {
            GlobalPose(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MQuaternion rotation;
            MVector translation;
        };

        struct HalfExtents
        {
            HalfExtents(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MVector halfExtents;
        };

        struct PxBoxGeometry
        {
            PxBoxGeometry(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            HalfExtents halfExtents;
        };

        struct Radius
        {
            Radius(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double radius;
        };

        struct HalfHeight
        {
            HalfHeight(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double halfHeight;
        };

        struct PxCapsuleGeometry
        {
            PxCapsuleGeometry(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Radius radius;
            HalfHeight halfHeight;
        };

        struct Scale
        {
            Scale(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MVector scale;
        };

        struct Rotation
        {
            Rotation(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MQuaternion rotation;
        };

        struct MeshScale
        {
            MeshScale(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Scale scale;
            Rotation rotation;
        };

        struct ConvexMesh
        {
            ConvexMesh(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            int convexMesh;
        };

        struct PxConvexMeshGeometry
        {
            PxConvexMeshGeometry(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MeshScale scale;
            ConvexMesh convexMesh;
        };

        struct PxPlaneGeometry
        {
            PxPlaneGeometry(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
        };

        struct PxSphereGeometry
        {
            PxSphereGeometry(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Radius radius;
        };

        struct TriangleMesh
        {
            TriangleMesh(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            int triangleMesh;
        };

        struct PxTriangleMeshGeometry
        {
            PxTriangleMeshGeometry(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MeshScale scale;
            TriangleMesh triangleMesh;
        };

        struct Geometry
        {
            Geometry(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);

            enum Type {
                Box,
                Capsule,
                ConvexMesh,
                Plane,
                Sphere,
                TriangleMesh
            };

            Type type;
            PxBoxGeometry boxGeometry;
            PxCapsuleGeometry capsuleGeometry;
            PxConvexMeshGeometry convexMeshGeometry;
            PxPlaneGeometry planeGeometry;
            PxSphereGeometry sphereGeometry;
            PxTriangleMeshGeometry triangleMeshGeometry;
        };

        struct LocalPose
        {
            LocalPose(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MQuaternion rotation;
            MVector translation;
        };

        struct SimulationFilterData
        {
            SimulationFilterData(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            int filter0;
            int filter1;
            int filter2;
            int filter3;
        };

        struct QueryFilterData
        {
            QueryFilterData(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            int filter0;
            int filter1;
            int filter2;
            int filter3;
        };

        struct PxMaterialRef
        {
            PxMaterialRef(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            int materialRef;
        };

        struct Materials
        {
            Materials(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            PxMaterialRef materialRef;
        };

        struct ContactOffset
        {
            ContactOffset(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double contactOffset;
        };

        struct RestOffset
        {
            RestOffset(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double restOffset;
        };

        struct Flags
        {
            Flags(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            String flags;
        };

        struct PxShape
        {
            PxShape(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);

            Geometry geometry;
            LocalPose localPose;
            SimulationFilterData simulationFilterData;
            QueryFilterData queryFilterData;
            Materials materials;
            ContactOffset contactOffset;
            RestOffset restOffset;
            Flags flags;
            Name name;
        };

        struct Shapes
        {
            Shapes(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            std::vector<PxShape> shapes;
        };

        struct PxRigidStatic
        {
            PxRigidStatic(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            PxShape* findShape(const String& shapeName);
            Id id;
            Name name;
            ActorFlags actorFlags;
            DominanceGroup dominanceGroup;
            OwnerClient ownerClient;
            GlobalPose globalPose;
            Shapes shapes;
        };

        struct CMassLocalPose
        {
            CMassLocalPose(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MQuaternion rotation;
            MVector translation;
        };

        struct MassSpaceInertiaTensor
        {
            MassSpaceInertiaTensor(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MVector massSpaceInertiaTensor;
        };

        struct LinearVelocity
        {
            LinearVelocity(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MVector linearVelocity;
        };

        struct AngularVelocity
        {
            AngularVelocity(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MVector angularVelocity;
        };

        struct MinCCDAdvanceCoefficient
        {
            MinCCDAdvanceCoefficient(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double minCCDAdvanceCoefficient;
        };

        struct MaxDepenetrationVelocity
        {
            MaxDepenetrationVelocity(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double maxDepenetrationVelocity;
        };

        struct LinearDamping
        {
            LinearDamping(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double linearDamping;
        };

        struct AngularDamping
        {
            AngularDamping(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double angularDamping;
        };

        struct MaxAngularVelocity
        {
            MaxAngularVelocity(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double maxAngularVelocity;
        };

        struct SleepThreshold
        {
            SleepThreshold(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double sleepThreshold;
        };

        struct StabilizationThreshold
        {
            StabilizationThreshold(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double stabilizationThreshold;
        };

        struct WakeCounter
        {
            WakeCounter(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double wakeCounter;
        };

        struct MinPositionIters
        {
            MinPositionIters(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            int minPositionIters;
        };

        struct MinVelocityIters
        {
            MinVelocityIters(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            int minVelocityIters;
        };

        struct SolverIterationCounts
        {
            SolverIterationCounts(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MinPositionIters minPositionIters;
            MinVelocityIters minVelocityIters;
        };

        struct ContactReportThreshold
        {
            ContactReportThreshold(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double contactReportThreshold;
        };

        struct PxRigidDynamic
        {
            PxRigidDynamic(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            PxShape* findShape(const String& shapeName);
            Id id;
            Name name;
            ActorFlags actorFlags;
            DominanceGroup dominanceGroup;
            OwnerClient ownerClient;
            GlobalPose globalPose;
            Shapes shapes;
            CMassLocalPose cMassLocalPose;
            Mass mass;
            MassSpaceInertiaTensor massSpaceInertiaTensor;
            LinearVelocity linearVelocity;
            AngularVelocity angularVelocity;
            RigidBodyFlags rigidBodyFlags;
            MinCCDAdvanceCoefficient minCCDAdvanceCoefficient;
            MaxDepenetrationVelocity maxDepenetrationVelocity;
            LinearDamping linearDamping;
            AngularDamping angularDamping;
            MaxAngularVelocity maxAngularVelocity;
            SleepThreshold sleepThreshold;
            StabilizationThreshold stabilizationThreshold;
            WakeCounter wakeCounter;
            SolverIterationCounts solverIterationCounts;
            ContactReportThreshold contactReportThreshold;
        };

        struct Actor0
        {
            Actor0(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            int actor0;
        };

        struct Actor1
        {
            Actor1(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            int actor1;
        };

        struct Actors
        {
            Actors(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Actor0 actor0;
            Actor1 actor1;
        };

        struct EActor0
        {
            EActor0(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MQuaternion rotation;
            MVector translation;
        };

        struct EActor1
        {
            EActor1(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MQuaternion rotation;
            MVector translation;
        };

        struct ActorLocalPose
        {
            ActorLocalPose(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            EActor0 eActor0;
            EActor1 eActor1;
        };

        struct Force
        {
            Force(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double force;
        };

        struct Torque
        {
            Torque(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double torque;
        };

        struct BreakForce
        {
            BreakForce(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Force force;
            Torque torque;
        };

        struct ConstraintFlags
        {
            ConstraintFlags(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            String flags;
        };

        struct InvMassScale0
        {
            InvMassScale0(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double invMassScale0;
        };

        struct InvMassScale1
        {
            InvMassScale1(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double invMassScale1;
        };

        struct InvInertiaScale0
        {
            InvInertiaScale0(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double invInertiaScale0;
        };

        struct InvInertiaScale1
        {
            InvInertiaScale1(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double invInertiaScale1;
        };

        struct MotionX
        {
            MotionX(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            String eX;
        };

        struct MotionY
        {
            MotionY(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            String eY;
        };

        struct MotionZ
        {
            MotionZ(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            String eZ;
        };

        struct MotionTwist
        {
            MotionTwist(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            String eTwist;
        };

        struct MotionSwing1
        {
            MotionSwing1(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            String eSwing1;
        };

        struct MotionSwing2
        {
            MotionSwing2(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            String eSwing2;
        };

        struct Motion
        {
            Motion(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MotionX eX;
            MotionY eY;
            MotionZ eZ;
            MotionTwist eTwist;
            MotionSwing1 eSwing1;
            MotionSwing2 eSwing2;
        };

        struct BounceThreshold
        {
            BounceThreshold(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double bounceThreshold;
        };

        struct Stiffness
        {
            Stiffness(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double stiffness;
        };

        struct Damping
        {
            Damping(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double damping;
        };

        struct ContactDistance
        {
            ContactDistance(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double contactDistance;
        };

        struct Value
        {
            Value(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double value;
        };

        struct LinearLimit
        {
            LinearLimit(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Restitution restitution;
            BounceThreshold bounceThreshold;
            Stiffness stiffness;
            Damping damping;
            ContactDistance contactDistance;
            Value value;
        };

        struct Upper
        {
            Upper(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double upper;
        };

        struct Lower
        {
            Lower(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double lower;
        };

        struct TwistLimit
        {
            TwistLimit(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Restitution restitution;
            BounceThreshold bounceThreshold;
            Stiffness stiffness;
            Damping damping;
            ContactDistance contactDistance;
            Upper upper;
            Lower lower;
        };

        struct YAngle
        {
            YAngle(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double yAngle;
        };

        struct ZAngle
        {
            ZAngle(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double zAngle;
        };

        struct SwingLimit
        {
            SwingLimit(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Restitution restitution;
            BounceThreshold bounceThreshold;
            Stiffness stiffness;
            Damping damping;
            ContactDistance contactDistance;
            YAngle yAngle;
            ZAngle zAngle;
        };

        struct ForceLimit
        {
            ForceLimit(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double forceLimit;
        };

        struct DriveX
        {
            DriveX(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Stiffness stiffness;
            Damping damping;
            ForceLimit forceLimit;
            Flags flags;
        };

        struct DriveY
        {
            DriveY(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Stiffness stiffness;
            Damping damping;
            ForceLimit forceLimit;
            Flags flags;
        };

        struct DriveZ
        {
            DriveZ(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Stiffness stiffness;
            Damping damping;
            ForceLimit forceLimit;
            Flags flags;
        };

        struct DriveSwing
        {
            DriveSwing(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Stiffness stiffness;
            Damping damping;
            ForceLimit forceLimit;
            Flags flags;
        };

        struct DriveTwist
        {
            DriveTwist(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Stiffness stiffness;
            Damping damping;
            ForceLimit forceLimit;
            Flags flags;
        };

        struct DriveSlerp
        {
            DriveSlerp(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Stiffness stiffness;
            Damping damping;
            ForceLimit forceLimit;
        };

        struct Drive
        {
            Drive(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            DriveX driveX;
            DriveY driveY;
            DriveZ driveZ;
            DriveSwing driveSwing;
            DriveTwist driveTwist;
            DriveSlerp driveSlerp;
        };

        struct DrivePosition
        {
            DrivePosition(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MQuaternion rotation;
            MVector translation;
        };

        struct Linear
        {
            Linear(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MVector linear;
        };

        struct Angular
        {
            Angular(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            MVector angular;
        };

        struct DriveVelocity
        {
            DriveVelocity(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Linear linear;
            Angular angular;
        };

        struct ProjectionLinearTolerance
        {
            ProjectionLinearTolerance(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double projectionLinearTolerance;
        };

        struct ProjectionAngularTolerance
        {
            ProjectionAngularTolerance(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            double projectionAngularTolerance;
        };

        struct PxD6Joint
        {
            PxD6Joint(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            Id id;
            Actors actors;
            ActorLocalPose localPose;
            BreakForce breakForce;
            ConstraintFlags constraintFlags;
            InvMassScale0 invMassScale0;
            InvInertiaScale0 invInertiaScale0;
            InvMassScale1 invMassScale1;
            InvInertiaScale1 invInertiaScale1;
            Name name;
            Motion motion;
            LinearLimit linearLimit;
            TwistLimit twistLimit;
            SwingLimit swingLimit;
            Drive drive;
            DrivePosition drivePosition;
            DriveVelocity driveVelocity;
            ProjectionLinearTolerance projectionLinearTolerance;
            ProjectionAngularTolerance projectionAngularTolerance;
        };

        struct PhysX30Collection
        {
            PhysX30Collection(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw);
            UpVector upVector;
            LengthMassSpeedScale scale;
            std::vector<PxConvexMesh> convexMeshes;
            std::vector<PxTriangleMesh> triangleMeshes;
            std::vector<PxMaterial> materials;
            std::vector<PxRigidStatic> rigidStatics;
            std::vector<PxRigidDynamic> rigidDynamics;
            std::vector<PxD6Joint> D6Joints;
        };

        struct PhysXDoc
        {
            PhysXDoc(xmlDocPtr xml);
            PhysX30Collection physX30Collection;
            bool validate();

            PxConvexMesh* findConvexMesh(int id);
            PxTriangleMesh* findTriangleMesh(int id);
            PxMaterial* findMaterial(int ref);
            PxMaterial* findMaterial(const String& bodyName, const String& shapeName);
            PxShape* findShape(const String& bodyName, const String& shapeName);
            PxRigidStatic* findRigidStatic(const String& bodyName);
            PxRigidDynamic* findRigidDynamic(const String& bodyName);
            PxD6Joint* findD6Joint(const String& jointName);
        };

        class PhysXDocPtr
        {
        public:
            PhysXDocPtr();
            PhysXDocPtr(xmlDocPtr xml);
            ~PhysXDocPtr();

            const PhysXDocPtr& operator = (xmlDocPtr xml);

            PhysXDoc* operator -> () const;

            operator bool() const;

        private:
            PhysXDoc* mPhysXDoc;
        };
    }
}