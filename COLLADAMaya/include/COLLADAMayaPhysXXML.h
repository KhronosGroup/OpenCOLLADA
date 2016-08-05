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

#if defined(_MSC_VER) && _MSC_VER < 1600
// int64_t only available since Visual Studio 2010
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif

namespace COLLADAMaya
{
	template<typename E>
	class Flags
	{
	public:
		Flags()
			: mBitfield(0)
		{}

		Flags(int bitfield)
			: mBitfield(bitfield)
		{}

		void clear()
		{
			mBitfield = 0;
		}

		Flags operator & (E flag) const
		{
			return mBitfield & static_cast<int>(flag);
		}

		bool isSet(E flag) const
		{
			return (mBitfield & static_cast<int>(flag)) != 0;
		}

		void operator |= (E flag)
		{
			mBitfield |= static_cast<int>(flag);
		}

		operator bool() const
		{
			return mBitfield != 0;
		}

		operator int() const
		{
			return mBitfield;
		}

		bool operator == (const Flags & other) const
		{
			return mBitfield == other.mBitfield;
		}

		bool operator != (const Flags & other) const
		{
			return mBitfield != other.mBitfield;
		}

	private:
		int mBitfield;
	};

    namespace PhysXXML
    {
        struct UpVector
        {
            UpVector(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            MVector upVector;
        };

        struct Length
        {
            Length(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double length;
        };

        struct Mass
        {
            Mass(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double mass;
        };

        struct Speed
        {
            Speed(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double speed;
        };

        struct LengthMassSpeedScale
        {
            LengthMassSpeedScale(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            Length length;
            Mass mass;
            Speed speed;
        };

        struct Id
        {
            Id(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            uint64_t id;
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
			void exportElement(COLLADASW::StreamWriter& sw) const;
            std::vector<Point> points;
        };

        struct PxConvexMesh
        {
            PxConvexMesh(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
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
			void exportElement(COLLADASW::StreamWriter& sw) const;
            std::vector<Triangle> triangles;
        };

        struct PxTriangleMesh
        {
            PxTriangleMesh(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            Id id;
            Points points;
            Triangles triangles;
        };

        struct DynamicFriction
        {
            DynamicFriction(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double dynamicFriction;
        };

        struct StaticFriction
        {
            StaticFriction(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double staticFriction;
        };

        struct Restitution
        {
            Restitution(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double restitution;
        };

		struct CombineMode
		{
			enum FlagEnum
			{
				Average = 1,
				Min = 2,
				Multiply = 4,
				Max = 8
			};

			static const std::map<String, FlagEnum> & GetStringToFlagMap();
			static const std::map<FlagEnum, String> & GetFlagToStringMap();

		private:
			static std::map<String, FlagEnum> mStringToFlagMap;
			static std::map<FlagEnum, String> mFlagToStringMap;
			static std::map<String, FlagEnum> InitializeStringToFlagMap();
			static std::map<FlagEnum, String> InitializeFlagToStringMap();
		};

        struct FrictionCombineMode
        {
            FrictionCombineMode(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            CombineMode::FlagEnum frictionCombineMode;
        };

        struct RestitutionCombineMode
        {
            RestitutionCombineMode(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
			CombineMode::FlagEnum restitutionCombineMode;
        };

        struct PxMaterial
        {
            PxMaterial(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
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
			void exportElement(COLLADASW::StreamWriter& sw) const;
            String name;
        };

        struct ActorFlags
        {
			enum FlagEnum
			{
				Visualization = 1,
				DisableGravity = 2,
				SendSleepNotifies = 4,
				DisableSimulation = 8
			};

            ActorFlags(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            Flags<FlagEnum> actorFlags;

			static const std::map<FlagEnum, String> & GetFlagToStringMap();

		private:
			static std::map<String, FlagEnum> mStringToFlagMap;
			static std::map<FlagEnum, String> mFlagToStringMap;
			static std::map<String, FlagEnum> InitializeStringToFlagMap();
			static std::map<FlagEnum, String> InitializeFlagToStringMap();
        };

        struct RigidBodyFlags
        {
			enum FlagEnum
			{
				Kinematic = 1,
				UseKinematicTargetForSceneQueries = 2,
				EnabledCCD = 4,
				EnabledCCDFriction = 8
			};

            RigidBodyFlags(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            Flags<FlagEnum> rigidBodyFlags;

			static const std::map<FlagEnum, String> & GetFlagToStringMap();

		private:
			static std::map<String, FlagEnum> mStringToFlagMap;
			static std::map<FlagEnum, String> mFlagToStringMap;
			static std::map<String, FlagEnum> InitializeStringToFlagMap();
			static std::map<FlagEnum, String> InitializeFlagToStringMap();
        };

        struct DominanceGroup
        {
            DominanceGroup(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            int dominanceGroup;
        };

        struct OwnerClient
        {
            OwnerClient(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            int ownerClient;
        };

        struct GlobalPose
        {
            GlobalPose(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            MQuaternion rotation;
            MVector translation;
        };

        struct HalfExtents
        {
            HalfExtents(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            MVector halfExtents;
        };

        struct PxBoxGeometry
        {
            PxBoxGeometry(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            HalfExtents halfExtents;
        };

        struct Radius
        {
            Radius(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double radius;
        };

        struct HalfHeight
        {
            HalfHeight(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double halfHeight;
        };

        struct PxCapsuleGeometry
        {
            PxCapsuleGeometry(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            Radius radius;
            HalfHeight halfHeight;
        };

        struct Scale
        {
            Scale(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            MVector scale;
        };

        struct Rotation
        {
            Rotation(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            MQuaternion rotation;
        };

        struct MeshScale
        {
            MeshScale(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            Scale scale;
            Rotation rotation;
        };

        struct ConvexMesh
        {
            ConvexMesh(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            uint64_t convexMesh;
        };

        struct PxConvexMeshGeometry
        {
            PxConvexMeshGeometry(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            MeshScale scale;
            ConvexMesh convexMesh;
        };

        struct PxPlaneGeometry
        {
            PxPlaneGeometry(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
        };

        struct PxSphereGeometry
        {
            PxSphereGeometry(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            Radius radius;
        };

        struct TriangleMesh
        {
            TriangleMesh(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            uint64_t triangleMesh;
        };

        struct PxTriangleMeshGeometry
        {
            PxTriangleMeshGeometry(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            MeshScale scale;
            TriangleMesh triangleMesh;
        };

        struct Geometry
        {
            Geometry(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;

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
			void exportElement(COLLADASW::StreamWriter& sw) const;
            MQuaternion rotation;
            MVector translation;
        };

        struct SimulationFilterData
        {
            SimulationFilterData(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            int filter0;
            int filter1;
            int filter2;
            int filter3;
        };

        struct QueryFilterData
        {
            QueryFilterData(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            int filter0;
            int filter1;
            int filter2;
            int filter3;
        };

        struct PxMaterialRef
        {
            PxMaterialRef(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            uint64_t materialRef;
        };

        struct Materials
        {
            Materials(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            PxMaterialRef materialRef;
        };

        struct ContactOffset
        {
            ContactOffset(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double contactOffset;
        };

        struct RestOffset
        {
            RestOffset(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double restOffset;
        };

        struct ShapeFlags
        {
			enum FlagEnum
			{
				SimulationShape = 1,
				SceneQueryShape = 2,
				TriggerShape = 4,
				Visualization = 8,
				ParticleDrain = 16
			};

            ShapeFlags(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            Flags<FlagEnum> flags;

			static const std::map<FlagEnum, String> & GetFlagToStringMap();

		private:
			static std::map<String, FlagEnum> mStringToFlagMap;
			static std::map<FlagEnum, String> mFlagToStringMap;
			static std::map<String, FlagEnum> InitializeStringToFlagMap();
			static std::map<FlagEnum, String> InitializeFlagToStringMap();
        };

        struct PxShape
        {
            PxShape(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;

            Geometry geometry;
            LocalPose localPose;
            SimulationFilterData simulationFilterData;
            QueryFilterData queryFilterData;
            Materials materials;
            ContactOffset contactOffset;
            RestOffset restOffset;
            ShapeFlags flags;
            Name name;
        };

        struct Shapes
        {
            Shapes(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            std::vector<PxShape> shapes;
        };

		struct PxRigidBody
		{
			enum Type
			{
				Static,
				Dynamic
			};

			PxRigidBody(xmlNode* node);
			PxShape* findShape(const String& shapeName);
			virtual void exportElement(COLLADASW::StreamWriter& sw) const = 0;
			virtual Type getType() const = 0;
			Id id;
			Name name;
			ActorFlags actorFlags;
			DominanceGroup dominanceGroup;
			OwnerClient ownerClient;
			GlobalPose globalPose;
			Shapes shapes;
		};

		struct PxRigidStatic : public PxRigidBody
        {
            PxRigidStatic(xmlNode* node);
			virtual void exportElement(COLLADASW::StreamWriter& sw) const override;
			virtual Type getType() const override;
        };

        struct CMassLocalPose
        {
            CMassLocalPose(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            MQuaternion rotation;
            MVector translation;
        };

        struct MassSpaceInertiaTensor
        {
            MassSpaceInertiaTensor(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            MVector massSpaceInertiaTensor;
        };

        struct LinearVelocity
        {
            LinearVelocity(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            MVector linearVelocity;
        };

        struct AngularVelocity
        {
            AngularVelocity(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            MVector angularVelocity;
        };

        struct MinCCDAdvanceCoefficient
        {
            MinCCDAdvanceCoefficient(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double minCCDAdvanceCoefficient;
        };

        struct MaxDepenetrationVelocity
        {
            MaxDepenetrationVelocity(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double maxDepenetrationVelocity;
        };

        struct LinearDamping
        {
            LinearDamping(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double linearDamping;
        };

        struct AngularDamping
        {
            AngularDamping(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double angularDamping;
        };

        struct MaxAngularVelocity
        {
            MaxAngularVelocity(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double maxAngularVelocity;
        };

        struct SleepThreshold
        {
            SleepThreshold(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double sleepThreshold;
        };

        struct StabilizationThreshold
        {
            StabilizationThreshold(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double stabilizationThreshold;
        };

        struct WakeCounter
        {
            WakeCounter(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double wakeCounter;
        };

        struct MinPositionIters
        {
            MinPositionIters(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            int minPositionIters;
        };

        struct MinVelocityIters
        {
            MinVelocityIters(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            int minVelocityIters;
        };

        struct SolverIterationCounts
        {
            SolverIterationCounts(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            MinPositionIters minPositionIters;
            MinVelocityIters minVelocityIters;
        };

        struct ContactReportThreshold
        {
            ContactReportThreshold(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double contactReportThreshold;
        };

        struct PxRigidDynamic : public PxRigidBody
        {
            PxRigidDynamic(xmlNode* node);
			virtual void exportElement(COLLADASW::StreamWriter& sw) const override;
			virtual Type getType() const override;
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
			void exportElement(COLLADASW::StreamWriter& sw) const;
            uint64_t actor0;
        };

        struct Actor1
        {
            Actor1(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            uint64_t actor1;
        };

        struct Actors
        {
            Actors(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            Actor0 actor0;
            Actor1 actor1;
        };

        struct EActor0
        {
            EActor0(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            MQuaternion rotation;
            MVector translation;
        };

        struct EActor1
        {
            EActor1(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            MQuaternion rotation;
            MVector translation;
        };

        struct ActorLocalPose
        {
            ActorLocalPose(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            EActor0 eActor0;
            EActor1 eActor1;
        };

        struct Force
        {
            Force(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double force;
        };

        struct Torque
        {
            Torque(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double torque;
        };

        struct BreakForce
        {
            BreakForce(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            Force force;
            Torque torque;
        };

        struct ConstraintFlags
        {
			enum FlagEnum
			{
				Broken = 1,
				ProjectToActor0 = 2,
				ProjectToActor1 = 4,
				Projection = 8,
				CollisionEnabled = 16,
				Reporting = 32,
				Visualization = 64,
				DriveLimitsAreForces = 128,
				ImprovedSlerp = 256
			};

            ConstraintFlags(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            Flags<FlagEnum> flags;

			static const std::map<FlagEnum, String> & GetFlagToStringMap();

		private:
			static std::map<String, FlagEnum> mStringToFlagMap;
			static std::map<FlagEnum, String> mFlagToStringMap;
			static std::map<String, FlagEnum> InitializeStringToFlagMap();
			static std::map<FlagEnum, String> InitializeFlagToStringMap();
        };

        struct InvMassScale0
        {
            InvMassScale0(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double invMassScale0;
        };

        struct InvMassScale1
        {
            InvMassScale1(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
            double invMassScale1;
        };

        struct InvInertiaScale0
        {
            InvInertiaScale0(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            double invInertiaScale0;
        };

        struct InvInertiaScale1
        {
            InvInertiaScale1(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            double invInertiaScale1;
        };

		struct MotionFlags
		{
			enum FlagEnum
			{
				Locked = 1,
				Limited = 2,
				Free = 4
			};

			static const std::map<String, FlagEnum> & GetStringToFlagMap();
			static const std::map<FlagEnum, String> & GetFlagToStringMap();

		private:
			static std::map<String, FlagEnum> mStringToFlagMap;
			static std::map<FlagEnum, String> mFlagToStringMap;
			static std::map<String, FlagEnum> InitializeStringToFlagMap();
			static std::map<FlagEnum, String> InitializeFlagToStringMap();
		};

        struct MotionX
        {
            MotionX(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            MotionFlags::FlagEnum eX;
        };

        struct MotionY
        {
            MotionY(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
			MotionFlags::FlagEnum eY;
        };

        struct MotionZ
        {
            MotionZ(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
			MotionFlags::FlagEnum eZ;
        };

        struct MotionTwist
        {
            MotionTwist(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
			MotionFlags::FlagEnum eTwist;
        };

        struct MotionSwing1
        {
            MotionSwing1(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
			MotionFlags::FlagEnum eSwing1;
        };

        struct MotionSwing2
        {
            MotionSwing2(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
			MotionFlags::FlagEnum eSwing2;
        };

        struct Motion
        {
            Motion(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
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
            void exportElement(COLLADASW::StreamWriter& sw) const;
            double bounceThreshold;
        };

        struct Stiffness
        {
            Stiffness(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            double stiffness;
        };

        struct Damping
        {
            Damping(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            double damping;
        };

        struct ContactDistance
        {
            ContactDistance(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            double contactDistance;
        };

        struct Value
        {
            Value(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            double value;
        };

        struct LinearLimit
        {
            LinearLimit(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
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
            void exportElement(COLLADASW::StreamWriter& sw) const;
            double upper;
        };

        struct Lower
        {
            Lower(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            double lower;
        };

        struct TwistLimit
        {
            TwistLimit(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
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
            void exportElement(COLLADASW::StreamWriter& sw) const;
            double yAngle;
        };

        struct ZAngle
        {
            ZAngle(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            double zAngle;
        };

        struct SwingLimit
        {
            SwingLimit(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
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
            void exportElement(COLLADASW::StreamWriter& sw) const;
            double forceLimit;
        };

		struct DriveFlags
		{
			enum FlagEnum
			{
				Acceleration = 1
			};

			DriveFlags(xmlNode* node);
			void exportElement(COLLADASW::StreamWriter& sw) const;
			Flags<FlagEnum> flags;

			static const std::map<FlagEnum, String> & GetFlagToStringMap();

		private:
			static std::map<String, FlagEnum> mStringToFlagMap;
			static std::map<FlagEnum, String> mFlagToStringMap;
			static std::map<String, FlagEnum> InitializeStringToFlagMap();
			static std::map<FlagEnum, String> InitializeFlagToStringMap();
		};

        struct DriveX
        {
            DriveX(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            Stiffness stiffness;
            Damping damping;
            ForceLimit forceLimit;
            DriveFlags flags;
        };

        struct DriveY
        {
            DriveY(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            Stiffness stiffness;
            Damping damping;
            ForceLimit forceLimit;
			DriveFlags flags;
        };

        struct DriveZ
        {
            DriveZ(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            Stiffness stiffness;
            Damping damping;
            ForceLimit forceLimit;
			DriveFlags flags;
        };

        struct DriveSwing
        {
            DriveSwing(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            Stiffness stiffness;
            Damping damping;
            ForceLimit forceLimit;
			DriveFlags flags;
        };

        struct DriveTwist
        {
            DriveTwist(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            Stiffness stiffness;
            Damping damping;
            ForceLimit forceLimit;
			DriveFlags flags;
        };

        struct DriveSlerp
        {
            DriveSlerp(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            Stiffness stiffness;
            Damping damping;
            ForceLimit forceLimit;
			DriveFlags flags;
        };

        struct Drive
        {
            Drive(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
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
            void exportElement(COLLADASW::StreamWriter& sw) const;
            MQuaternion rotation;
            MVector translation;
        };

        struct Linear
        {
            Linear(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            MVector linear;
        };

        struct Angular
        {
            Angular(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            MVector angular;
        };

        struct DriveVelocity
        {
            DriveVelocity(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            Linear linear;
            Angular angular;
        };

        struct ProjectionLinearTolerance
        {
            ProjectionLinearTolerance(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            double projectionLinearTolerance;
        };

        struct ProjectionAngularTolerance
        {
            ProjectionAngularTolerance(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
            double projectionAngularTolerance;
        };

        struct PxD6Joint
        {
            PxD6Joint(xmlNode* node);
            void exportElement(COLLADASW::StreamWriter& sw) const;
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
            void exportElement(COLLADASW::StreamWriter& sw) const;
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

            PxConvexMesh* findConvexMesh(uint64_t id);
            PxTriangleMesh* findTriangleMesh(uint64_t id);
            PxMaterial* findMaterial(uint64_t ref);
            PxMaterial* findMaterial(const String& shapeName);
			PxShape* findShape(const String & shapeName);
			PxRigidBody* findRigidBody(const String & bodyName);
			PxRigidBody* findRigidBody(uint64_t id);
			PxRigidStatic* findRigidStatic(uint64_t id);
            PxRigidStatic* findRigidStatic(const String& bodyName);
			PxRigidDynamic* findRigidDynamic(uint64_t id);
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