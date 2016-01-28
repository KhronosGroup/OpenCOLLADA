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

#include "COLLADAMayaAttributeParser.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaGeometryExporter.h"
#include "COLLADAMayaPhysXExporter.h"
#include "COLLADAMayaRotateHelper.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaVisualSceneExporter.h"
#include "COLLADASWConstants.h"
#include "Math/COLLADABUMathUtils.h"

#include <libxml/tree.h>
#include <maya/MAngle.h>
#include <maya/MDistance.h>
#include <maya/MFnAttribute.h>
#define MNoPluginEntry
#define MNoVersionString
#include <maya/MFnPlugin.h>
#include <maya/MFnTransform.h>
#include <maya/MString.h>
#include <maya/MTime.h>

double infinite()
{
    union ieee754 {
#if defined(_MSC_VER)
        // int64_t only available since Visual Studio 2010
        __int64 i;
#else
        int64_t i;
#endif
        double d;
    };
    ieee754 inf;
    inf.i = 0x7FF0000000000000;
    return inf.d;
}

bool isInf(double d)
{
    return
        d == infinite() ||
        d == -infinite();
}

using namespace COLLADASW;

// Note:
// Maya matrix: row major vectors, T1 x T2 x T3...
// DAE matrix/transforms: column major vectors, ...T3 x T2 x T1
// -> reverse order

namespace COLLADAMaya
{
    // Helper class used to open and auto close an element.
    class Element
    {
    public:
        Element(PhysXExporter& exporter, const String & name)
            : mPhysXExporter(exporter)
        {
            mPhysXExporter.getStreamWriter().openElement(name);
        }

        virtual ~Element()
        {
            mPhysXExporter.getStreamWriter().closeElement();
        }

    protected:
        StreamWriter& getStreamWriter()
        {
            return mPhysXExporter.getStreamWriter();
        }

        DocumentExporter& getDocumentExporter()
        {
            return mPhysXExporter.getDocumentExporter();
        }

        PhysXExporter& getPhysXExporter()
        {
            return mPhysXExporter;
        }

    private:
        PhysXExporter& mPhysXExporter;
    };
    
    class AttributeExporter : public AttributeParser
    {
    public:
        AttributeExporter(PhysXExporter& exporter, const std::set<MString, MStringComp> & attributes)
            : mPhysXExporter(exporter)
            , mAttributes(attributes)
        {}

    protected:
        virtual bool onBeforeAttribute(MFnDependencyNode & node, MObject & attr) override
        {
            MStatus status;
            MFnAttribute fnAttr(attr, &status);
            if (!status) return false;

            MString attrName = fnAttr.name(&status);
            if (!status) return false;

            std::set<MString, MStringComp>::const_iterator it = mAttributes.find(attrName);
            if (it == mAttributes.end()) {
                return false;
            }

            return true;
        }

        virtual void onBoolean(MPlug & plug, const MString & name, bool value) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(value);
        }

        virtual void onByte(MPlug & plug, const MString & name, char value) override
        {
            String nameStr(name.asChar());
			const size_t size = 5;
			char text[size];
			snprintf(text, size, "0x%X", value);
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(text);
        }

        virtual void onChar(MPlug & plug, const MString & name, char value) override
        {
            String nameStr(name.asChar());
            char text[] = { value, '\0' };
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(text);
        }

        virtual void onShort(MPlug & plug, const MString & name, short value) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(value);
        }

        virtual void onShort2(MPlug & plug, const MString & name, short value[2]) override
        {
            String nameStr(name.asChar());
            int values[3] = { value[0], value[1] };
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(values, 2);
        }

        virtual void onShort3(MPlug & plug, const MString & name, short value[3]) override
        {

            String nameStr(name.asChar());
            int values[3] = { value[0], value[1], value[2] };
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(values, 3);
        }

        virtual void onInteger(MPlug & plug, const MString & name, int value) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(value);
        }

        virtual void onInteger2(MPlug & plug, const MString & name, int value[2]) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(value, 2);
        }

        virtual void onInteger3(MPlug & plug, const MString & name, int value[3]) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(value, 3);
        }

        virtual void onFloat(MPlug & plug, const MString & name, float value) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(value);
        }

        virtual void onFloat2(MPlug & plug, const MString & name, float value[2]) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(value, 2);
        }

        virtual void onFloat3(MPlug & plug, const MString & name, float value[3]) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(value, 3);
        }

        virtual void onDouble(MPlug & plug, const MString & name, double value) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(value);
        }

        virtual void onDouble2(MPlug & plug, const MString & name, double value[2]) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(value, 2);
        }

        virtual void onDouble3(MPlug & plug, const MString & name, double value[3]) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(value, 3);
        }

        virtual void onDouble4(MPlug & plug, const MString & name, double value[4]) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(value, 4);
        }

        virtual void onString(MPlug & plug, const MString & name, const MString & value) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendText(value.asChar());
        }

        virtual void onEnum(MPlug & plug, const MString & name, int enumValue, const MString & enumName) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendText(enumName.asChar());
        }

        virtual void onMesh(MPlug & plug, const MString & name, MObject & meshObject) override
        {
            String nameStr(name.asChar());
            URI meshURI;
            mPhysXExporter.getMeshURI(meshObject, meshURI);
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendURIAttribute(CSWC::CSW_ATTRIBUTE_URL, meshURI);
        }

        virtual void onAngle(MPlug & plug, const MString & name, const MAngle & angle) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(
                angle.asDegrees());
        }

        virtual void onAngle2(MPlug & plug, const MString & name, const MAngle angle[2]) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(
                angle[0].asDegrees(),
                angle[1].asDegrees());
        }

        virtual void onAngle3(MPlug & plug, const MString & name, const MAngle angle[3]) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(
                angle[0].asDegrees(),
                angle[1].asDegrees(),
                angle[2].asDegrees());
        }

        virtual void onAngle4(MPlug & plug, const MString & name, const MAngle angle[4]) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(
                angle[0].asDegrees(),
                angle[1].asDegrees(),
                angle[2].asDegrees(),
                angle[3].asDegrees());
        }

        virtual void onDistance(MPlug & plug, const MString & name, const MDistance & distance) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(
                MDistance::internalToUI(distance.asCentimeters()));
        }

        virtual void onDistance2(MPlug & plug, const MString & name, const MDistance distance[2]) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(
                MDistance::internalToUI(distance[0].asCentimeters()),
                MDistance::internalToUI(distance[1].asCentimeters()));
        }

        virtual void onDistance3(MPlug & plug, const MString & name, const MDistance distance[3]) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(
                MDistance::internalToUI(distance[0].asCentimeters()),
                MDistance::internalToUI(distance[1].asCentimeters()),
                MDistance::internalToUI(distance[2].asCentimeters()));
        }

        virtual void onDistance4(MPlug & plug, const MString & name, const MDistance distance[4]) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(
                MDistance::internalToUI(distance[0].asCentimeters()),
                MDistance::internalToUI(distance[1].asCentimeters()),
                MDistance::internalToUI(distance[2].asCentimeters()),
                MDistance::internalToUI(distance[3].asCentimeters()));
        }

        virtual void onTime(MPlug & plug, const MString & name, MTime & time) override
        {
            String nameStr(name.asChar());
            Element e(mPhysXExporter, nameStr);
            mPhysXExporter.getStreamWriter().appendValues(time.as(MTime::kSeconds));
        }

    private:
        PhysXExporter& mPhysXExporter;
        const std::set<MString, MStringComp>& mAttributes;
        int mAttributeLevel;
    };

    void PhysXRigidConstraint::GetSwingConeAndTwistMinLimit(const MObject & rigidConstraint, MVector & min)
    {
        int dummy = 0;
        MString motionSwingY;
        MString motionSwingZ;
        MString motionTwist;
        DagHelper::getPlugValue(rigidConstraint, ATTR_MOTION_SWING_Y, dummy, motionSwingY);
        DagHelper::getPlugValue(rigidConstraint, ATTR_MOTION_SWING_Z, dummy, motionSwingZ);
        DagHelper::getPlugValue(rigidConstraint, ATTR_MOTION_TWIST, dummy, motionTwist);

        if (motionSwingY == LOCKED) {
            min.x = 0.0;
        }
        else if (motionSwingY == LIMITED) {
            double limit = 0.0;
            DagHelper::getPlugValue(rigidConstraint, ATTR_SWING_1_LIMIT_VALUE, limit);
            limit = COLLADABU::Math::Utils::radToDeg(limit);
            min.x = -limit;
        }
        else if (motionSwingY == FREE) {
            min.x = -infinite();
        }

        if (motionSwingZ == LOCKED) {
            min.y = 0.0;
        }
        else if (motionSwingZ == LIMITED) {
            double limit = 0.0;
            DagHelper::getPlugValue(rigidConstraint, ATTR_SWING_2_LIMIT_VALUE, limit);
            limit = COLLADABU::Math::Utils::radToDeg(limit);
            min.y = -limit;
        }
        else if (motionSwingZ == FREE) {
            min.y = -infinite();
        }

        if (motionTwist == LOCKED) {
            min.z = 0.0;
        }
        else if (motionTwist == LIMITED) {
            double limit = 0.0;
            DagHelper::getPlugValue(rigidConstraint, ATTR_TWIST_LOW_LIMIT_VALUE, limit);
            limit = COLLADABU::Math::Utils::radToDeg(limit);
            min.z = limit;
        }
        else if (motionTwist == FREE) {
            min.z = -infinite();
        }
    }

    void PhysXRigidConstraint::GetSwingConeAndTwistMaxLimit(const MObject & rigidConstraint, MVector & max)
    {
        int dummy = 0;
        MString motionSwingY;
        MString motionSwingZ;
        MString motionTwist;
        DagHelper::getPlugValue(rigidConstraint, ATTR_MOTION_SWING_Y, dummy, motionSwingY);
        DagHelper::getPlugValue(rigidConstraint, ATTR_MOTION_SWING_Z, dummy, motionSwingZ);
        DagHelper::getPlugValue(rigidConstraint, ATTR_MOTION_TWIST, dummy, motionTwist);

        if (motionSwingY == LOCKED) {
            max.x = 0.0;
        }
        else if (motionSwingY == LIMITED) {
            double limit = 0.0;
            DagHelper::getPlugValue(rigidConstraint, ATTR_SWING_1_LIMIT_VALUE, limit);
            limit = COLLADABU::Math::Utils::radToDeg(limit);
            max.x = limit;
        }
        else if (motionSwingY == FREE) {
            max.x = infinite();
        }

        if (motionSwingZ == LOCKED) {
            max.y = 0.0;
        }
        else if (motionSwingZ == LIMITED) {
            double limit = 0.0;
            DagHelper::getPlugValue(rigidConstraint, ATTR_SWING_2_LIMIT_VALUE, limit);
            limit = COLLADABU::Math::Utils::radToDeg(limit);
            max.y = limit;
        }
        else if (motionSwingZ == FREE) {
            max.y = infinite();
        }

        if (motionTwist == LOCKED) {
            max.z = 0.0;
        }
        else if (motionTwist == LIMITED) {
            double limit = 0.0;
            DagHelper::getPlugValue(rigidConstraint, ATTR_TWIST_HIGH_LIMIT_VALUE, limit);
            limit = COLLADABU::Math::Utils::radToDeg(limit);
            max.z = limit;
        }
        else if (motionTwist == FREE) {
            max.z = infinite();
        }
    }
    
    void PhysXRigidConstraint::GetLinearMinLimit(const MObject & rigidConstraint, MVector & min)
    {
        int dummy = 0;
        MString motionX;
        MString motionY;
        MString motionZ;
        DagHelper::getPlugValue(rigidConstraint, ATTR_MOTION_X, dummy, motionX);
        DagHelper::getPlugValue(rigidConstraint, ATTR_MOTION_Y, dummy, motionY);
        DagHelper::getPlugValue(rigidConstraint, ATTR_MOTION_Z, dummy, motionZ);

        if (motionX == LOCKED) {
            min.x = 0.0;
        }
        else if (motionX == LIMITED) {
            double limit = 0.0;
            DagHelper::getPlugValue(rigidConstraint, ATTR_LINEAR_LIMIT_VALUE, limit);
            limit = MDistance::internalToUI(limit);
            min.x = -limit;
        }
        else if (motionX == FREE) {
            min.x = -infinite();
        }

        if (motionY == LOCKED) {
            min.y = 0.0;
        }
        else if (motionY == LIMITED) {
            double limit = 0.0;
            DagHelper::getPlugValue(rigidConstraint, ATTR_LINEAR_LIMIT_VALUE, limit);
            limit = MDistance::internalToUI(limit);
            min.y = -limit;
        }
        else if (motionY == FREE) {
            min.y = -infinite();
        }

        if (motionZ == LOCKED) {
            min.z = 0.0;
        }
        else if (motionZ == LIMITED) {
            double limit = 0.0;
            DagHelper::getPlugValue(rigidConstraint, ATTR_LINEAR_LIMIT_VALUE, limit);
            limit = MDistance::internalToUI(limit);
            min.z = -limit;
        }
        else if (motionZ == FREE) {
            min.z = -infinite();
        }
    }

    void PhysXRigidConstraint::GetLinearMaxLimit(const MObject & rigidConstraint, MVector & max)
    {
        int dummy = 0;
        MString motionX;
        MString motionY;
        MString motionZ;
        DagHelper::getPlugValue(rigidConstraint, ATTR_MOTION_X, dummy, motionX);
        DagHelper::getPlugValue(rigidConstraint, ATTR_MOTION_Y, dummy, motionY);
        DagHelper::getPlugValue(rigidConstraint, ATTR_MOTION_Z, dummy, motionZ);

        if (motionX == LOCKED) {
            max.x = 0.0;
        }
        else if (motionX == LIMITED) {
            double limit = 0.0;
            DagHelper::getPlugValue(rigidConstraint, ATTR_LINEAR_LIMIT_VALUE, limit);
            limit = MDistance::internalToUI(limit);
            max.x = limit;
        }
        else if (motionX == FREE) {
            max.x = infinite();
        }

        if (motionY == LOCKED) {
            max.y = 0.0;
        }
        else if (motionY == LIMITED) {
            double limit = 0.0;
            DagHelper::getPlugValue(rigidConstraint, ATTR_LINEAR_LIMIT_VALUE, limit);
            limit = MDistance::internalToUI(limit);
            max.y = limit;
        }
        else if (motionY == FREE) {
            max.y = infinite();
        }

        if (motionZ == LOCKED) {
            max.z = 0.0;
        }
        else if (motionZ == LIMITED) {
            double limit = 0.0;
            DagHelper::getPlugValue(rigidConstraint, ATTR_LINEAR_LIMIT_VALUE, limit);
            limit = MDistance::internalToUI(limit);
            max.z = limit;
        }
        else if (motionZ == FREE) {
            max.z = infinite();
        }
    }

    void PhysXRigidConstraint::GetSpringAngularStiffness(const MObject & rigidConstraint, double & stiffness)
    {
        DagHelper::getPlugValue(rigidConstraint, ATTR_DRIVE_SPRING_SWING, stiffness);
        stiffness = COLLADABU::Math::Utils::radToDeg(stiffness);
    }

    void PhysXRigidConstraint::GetSpringAngularDamping(const MObject & rigidConstraint, double & damping)
    {
        DagHelper::getPlugValue(rigidConstraint, ATTR_DRIVE_DAMPING_SWING, damping);
        damping = COLLADABU::Math::Utils::radToDeg(damping);
    }

    void PhysXRigidConstraint::GetSpringAngularTargetValue(const MObject & rigidConstraint, double & targetValue)
    {
        DagHelper::getPlugValue(rigidConstraint, ATTR_GOAL_ORIENTATION_X, targetValue);
        targetValue = COLLADABU::Math::Utils::radToDeg(targetValue);
    }

    void PhysXRigidConstraint::GetSpringLinearStiffness(const MObject & rigidConstraint, double & stiffness)
    {
        DagHelper::getPlugValue(rigidConstraint, ATTR_DRIVE_SPRING_X, stiffness);
    }

    void PhysXRigidConstraint::GetSpringLinearDamping(const MObject & rigidConstraint, double & damping)
    {
        DagHelper::getPlugValue(rigidConstraint, ATTR_DRIVE_DAMPING_X, damping);
    }

    void PhysXRigidConstraint::GetSpringLinearTargetValue(const MObject & rigidConstraint, double & targetValue)
    {
        DagHelper::getPlugValue(rigidConstraint, ATTR_GOAL_POSITION_X, targetValue);
        targetValue = MDistance::internalToUI(targetValue);
    }

    void PhysXShape::GetType(const MObject & shape, MString & type)
    {
        int dummy = 0;
        DagHelper::getPlugValue(shape, ATTR_SHAPE_TYPE, dummy, type);
    }

    void PhysXShape::GetInMesh(const MObject & shape, MObject & mesh)
    {
        DagHelper::getPlugValue(shape, ATTR_IN_MESH, mesh);
    }

    void PhysXShape::GetConnectedInMesh(const MObject & shape, MObject & mesh)
    {
        PhysXExporter::GetPluggedObject(shape, ATTR_IN_MESH, mesh);
    }

    PhysXXML::PxMaterial* PhysXExporter::findPxMaterial(const MObject& rigidBody)
    {
        int dummy = 0;
        MString simulationType;
        DagHelper::getPlugValue(rigidBody, ATTR_SIMULATION_TYPE, dummy, simulationType);

        PhysXXML::GlobalPose* pGlobalPose = NULL;

        if (simulationType == SIMULATION_TYPE_STATIC) {
            PhysXXML::PxRigidStatic* pxRigidStatic = findPxRigidStatic(rigidBody);
            if (pxRigidStatic && pxRigidStatic->shapes.shapes.size() > 0) {
                // All shapes in a rigid body have the same material
                return findPxMaterial(pxRigidStatic->shapes.shapes[0].materials.materialRef.materialRef);
            }
        }
        else {
            PhysXXML::PxRigidDynamic* pxRigidDynamic = findPxRigidDynamic(rigidBody);
            if (pxRigidDynamic && pxRigidDynamic->shapes.shapes.size() > 0) {
                // All shapes in a rigid body have the same material
                return findPxMaterial(pxRigidDynamic->shapes.shapes[0].materials.materialRef.materialRef);
            }
        }
        return NULL;
    }

    PhysXXML::PxMaterial* PhysXExporter::findPxMaterial(int ref)
    {
        return mPhysXDoc->findMaterial(ref);
    }

    PhysXXML::PxShape* PhysXExporter::findPxShape(const MObject& rigidBody, const MObject& shape)
    {
        // Shape node
        MFnDagNode shapeNode(shape);
        MString shapeName = shapeNode.fullPathName();

        // Rigid body target
        MObject target;
        getRigidBodyTarget(rigidBody, target);
        MFnDagNode targetNode(target);
        MString targetName = targetNode.fullPathName();

        return mPhysXDoc->findShape(targetName.asChar(), shapeName.asChar());
    }

    PhysXXML::PxRigidStatic* PhysXExporter::findPxRigidStatic(const MObject& rigidBody)
    {
        MObject target;
        getRigidBodyTarget(rigidBody, target);
        MFnDagNode targetNode(target);
        MString targetName = targetNode.fullPathName();
        return findPxRigidStatic(targetName.asChar());
    }

    PhysXXML::PxRigidStatic* PhysXExporter::findPxRigidStatic(const String& name)
    {
        return mPhysXDoc->findRigidStatic(name);
    }

    PhysXXML::PxRigidDynamic* PhysXExporter::findPxRigidDynamic(const MObject& rigidBody)
    {
        MObject target;
        getRigidBodyTarget(rigidBody, target);
        MFnDagNode targetNode(target);
        MString targetName = targetNode.fullPathName();
        return mPhysXDoc->findRigidDynamic(targetName.asChar());
    }

    PhysXXML::PxD6Joint* PhysXExporter::findPxD6Joint(const MObject& rigidConstraint)
    {
        MFnDagNode constraintNode(rigidConstraint);
        MString constraintName = constraintNode.fullPathName();
        return mPhysXDoc->findD6Joint(constraintName.asChar());
    }

    MObject PhysXExporter::getShapeRigidBody(const MObject& shape)
    {
        class FindShapeRigidBody
        {
        public:
            FindShapeRigidBody(PhysXExporter & exporter, const MObject& shape)
                : mPhysXExporter(exporter)
                , mShape(shape)
            {}

            bool operator()(SceneElement & element)
            {
                if (element.getType() == SceneElement::PHYSX_RIGID_BODY &&
                    element.getIsLocal())
                {
                    std::vector<MObject> shapes;
                    PhysXExporter::GetRigidBodyShapes(element.getNode(), shapes);

                    for (std::vector<MObject>::const_iterator it = shapes.begin(); it != shapes.end(); ++it)
                    {
                        if (*it == mShape)
                        {
                            mRigidBody = element.getNode();
                            // Stop parsing
                            return false;
                        }
                    }
                }
                return true;
            }

            MObject getRigidBody() const
            {
                return mRigidBody;
            }

        private:
            PhysXExporter & mPhysXExporter;
            MObject mShape;
            MObject mRigidBody;
        };

        FindShapeRigidBody parser(*this, shape);
        parseSceneElements(parser);
        return parser.getRigidBody();
    }

    void PhysXExporter::getShapeLocalPose(const MObject& rigidBody, const MObject& shape, MMatrix& localPose)
    {
        PhysXXML::PxShape* pxShape = findPxShape(rigidBody, shape);
        if (!pxShape)
            return;

        MTransformationMatrix tm;

        tm.setRotationQuaternion(
            pxShape->localPose.rotation.x,
            pxShape->localPose.rotation.y,
            pxShape->localPose.rotation.z,
            pxShape->localPose.rotation.w);
        
        MVector translation(
            MDistance::uiToInternal(pxShape->localPose.translation.x),
            MDistance::uiToInternal(pxShape->localPose.translation.y),
            MDistance::uiToInternal(pxShape->localPose.translation.z)
            );

        tm.setTranslation(translation, MSpace::kTransform);

        localPose = tm.asMatrix();
    }

    bool PhysXExporter::getShapeVertices(const MObject& shape, std::vector<PhysXXML::Point> & vertices, MString & meshId)
    {
        MObject rigidBody = getShapeRigidBody(shape);
        if (rigidBody.isNull()) return false;

        PhysXXML::PxShape* pxShape = findPxShape(rigidBody, shape);
        if (pxShape == NULL) return false;

        if (pxShape->geometry.type == PhysXXML::Geometry::ConvexMesh)
        {
            if (PhysXXML::PxConvexMesh* convexMesh = mPhysXDoc->findConvexMesh(pxShape->geometry.convexMeshGeometry.convexMesh.convexMesh))
            {
                vertices = convexMesh->points.points;
                meshId = convexMesh->id.id;
                return true;
            }
        }
        else if (pxShape->geometry.type == PhysXXML::Geometry::TriangleMesh)
        {
            if (PhysXXML::PxTriangleMesh* triangleMesh = mPhysXDoc->findTriangleMesh(pxShape->geometry.triangleMeshGeometry.triangleMesh.triangleMesh))
            {
                vertices = triangleMesh->points.points;
                meshId = triangleMesh->id.id;
                return true;
            }
        }
        return false;
    }

    bool PhysXExporter::getShapeTriangles(const MObject& shape, std::vector<PhysXXML::Triangle> & triangles)
    {
        MObject rigidBody = getShapeRigidBody(shape);
        if (rigidBody.isNull()) return false;

        PhysXXML::PxShape* pxShape = findPxShape(rigidBody, shape);
        if (pxShape == NULL) return false;

        if (pxShape->geometry.type == PhysXXML::Geometry::TriangleMesh)
        {
            if (PhysXXML::PxTriangleMesh* triangleMesh = mPhysXDoc->findTriangleMesh(pxShape->geometry.triangleMeshGeometry.triangleMesh.triangleMesh))
            {
                triangles = triangleMesh->triangles.triangles;
                return true;
            }
        }
        return false;
    }

    void PhysXExporter::getRigidBodyGlobalPose(const MObject& rigidBody, MMatrix& globalPose)
    {
        int dummy = 0;
        MString simulationType;
        DagHelper::getPlugValue(rigidBody, ATTR_SIMULATION_TYPE, dummy, simulationType);

        PhysXXML::GlobalPose* pGlobalPose = NULL;

        if (simulationType == SIMULATION_TYPE_STATIC) {
            PhysXXML::PxRigidStatic* pxRigidStatic = findPxRigidStatic(rigidBody);
            if (pxRigidStatic) {
                pGlobalPose = &pxRigidStatic->globalPose;
            }
        }
        else {
            PhysXXML::PxRigidDynamic* pxRigidDynamic = findPxRigidDynamic(rigidBody);
            if (pxRigidDynamic) {
                pGlobalPose = &pxRigidDynamic->globalPose;
            }
        }

        if (!pGlobalPose)
            return;

        MTransformationMatrix tm;

        tm.setRotationQuaternion(
            pGlobalPose->rotation.x,
            pGlobalPose->rotation.y,
            pGlobalPose->rotation.z,
            pGlobalPose->rotation.w);

        MVector translation(
            MDistance::uiToInternal(pGlobalPose->translation.x),
            MDistance::uiToInternal(pGlobalPose->translation.y),
            MDistance::uiToInternal(pGlobalPose->translation.z)
            );

        tm.setTranslation(translation, MSpace::kTransform);

        globalPose = tm.asMatrix();
    }

    void PhysXExporter::getRigidBodyTarget(const MObject& rigidBody, MObject& target)
    {
        target = MObject::kNullObj;

        PhysXExporter::GetPluggedObject(rigidBody, ATTR_TARGET, target);

        // If target is null then use rigidBody as target
        if (target.isNull())
        {
            target = rigidBody;
        }
    }
        
    bool PhysXExporter::getRigidSolver(MObject & rigidSolver)
    {
        class RigidSolverParser
        {
        public:            
            bool operator()(SceneElement & element)
            {
                if (element.getType() == SceneElement::PHYSX_RIGID_SOLVER &&
                    element.getIsLocal())
                {
                    mRigidSolver = element.getNode();
                    return false;
                }
                return true;
            }
            
            const MObject & getRigidSolver()
            {
                return mRigidSolver;
            }
            
        private:
            MObject mRigidSolver;
        } parser;
        parseSceneElements(parser);
        rigidSolver = parser.getRigidSolver();
        return !rigidSolver.isNull();
    }

    class Dynamic : public Element
    {
    public:
        Dynamic(PhysXExporter& exporter, bool value)
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_DYNAMIC)
        {
            getStreamWriter().appendValues(value);
        }
    };

    class Mass : public Element
    {
    public:
        Mass(PhysXExporter& exporter, double mass)
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_MASS)
        {
            getStreamWriter().appendValues(mass);
        }
    };

    class MassFrame : public Element
    {
    public:
        MassFrame(PhysXExporter& exporter, const MVector & translation, const String & sid = "")
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_MASS_FRAME)
        {
            getPhysXExporter().exportTranslation(translation, sid);
        }
    };

    class Inertia : public Element
    {
    public:
        Inertia(PhysXExporter& exporter, const MVector & inertia)
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_INERTIA)
        {
            getStreamWriter().appendValues(inertia.x, inertia.y, inertia.z);
        }
    };

    class Restitution : public Element
    {
    public:
        Restitution(PhysXExporter& exporter, double restitution)
            : Element(exporter, CSWC::CSW_ELEMENT_RESTITUTION)
        {
            getStreamWriter().appendValues(restitution);
        }
    };

    class DynamicFriction : public Element
    {
    public:
        DynamicFriction(PhysXExporter& exporter, double dynamicFriction)
            : Element(exporter, CSWC::CSW_ELEMENT_DYNAMIC_FRICTION)
        {
            getStreamWriter().appendValues(dynamicFriction);
        }
    };

    class StaticFriction : public Element
    {
    public:
        StaticFriction(PhysXExporter& exporter, double staticFriction)
            : Element(exporter, CSWC::CSW_ELEMENT_STATIC_FRICTION)
        {
            getStreamWriter().appendValues(staticFriction);
        }
    };

    class PhysicsMaterialTechnique : public Element
    {
    public:
        PhysicsMaterialTechnique(PhysXExporter& exporter, const MObject& rigidBody, const String& profile)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE)
        {
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_PROFILE, profile);
            if (profile == PhysXExporter::GetProfileXML()) {
                exporter.exportMaterialPhysXXML(rigidBody);
            }
        }
    };

    class PhysicsMaterialExtra : public Element
    {
    public:
        PhysicsMaterialExtra(PhysXExporter& exporter, const MObject& rigidBody)
            : Element(exporter, CSWC::CSW_ELEMENT_EXTRA)
        {
            exportTechnique(rigidBody, PhysXExporter::GetProfileXML());
        }

    private:
        void exportTechnique(const MObject& rigidBody, const String& profile)
        {
            PhysicsMaterialTechnique e(getPhysXExporter(), rigidBody, profile);
        }
    };

    class PhysicsMaterialTechniqueCommon : public Element
    {
    public:
        PhysicsMaterialTechniqueCommon(PhysXExporter& exporter, const MObject& rigidBody)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE_COMMON)
        {
            exportRestitution(rigidBody);
            exportDynamicFriction(rigidBody);
            exportStaticFriction(rigidBody);
        }

    private:
        void exportRestitution(const MObject & rigidBody)
        {
            double restitution = 0.0;
            DagHelper::getPlugValue(rigidBody, ATTR_BOUNCINESS, restitution);
            if (restitution != 0.0)
            {
                Restitution e(getPhysXExporter(), restitution);
            }
        }

        void exportDynamicFriction(const MObject & rigidBody)
        {
            double dynamicFriction = 0.0;
            DagHelper::getPlugValue(rigidBody, ATTR_DYNAMIC_FRICTION, dynamicFriction);
            if (dynamicFriction != 0.0)
            {
                DynamicFriction e(getPhysXExporter(), dynamicFriction);
            }
        }

        void exportStaticFriction(const MObject & rigidBody)
        {
            double staticFriction = 0.0;
            DagHelper::getPlugValue(rigidBody, ATTR_STATIC_FRICTION, staticFriction);
            if (staticFriction != 0.0)
            {
                StaticFriction e(getPhysXExporter(), staticFriction);
            }
        }
    };

    class PhysicsMaterial : public Element
    {
    public:
        PhysicsMaterial(PhysXExporter& exporter, const MObject & rigidBody)
            : Element(exporter, CSWC::CSW_ELEMENT_PHYSICS_MATERIAL)
        {
            MDagPath rigidBodyDagPath;
            MDagPath::getAPathTo(rigidBody, rigidBodyDagPath);

            String rigidBodyId = getPhysXExporter().generateColladaId(rigidBodyDagPath);
            String materialId = rigidBodyId + "_material";

            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_ID, materialId);

            exportTechniqueCommon(rigidBody);
            exportExtra(rigidBody);
        }

    private:
        void exportTechniqueCommon(const MObject& rigidBody)
        {
            PhysicsMaterialTechniqueCommon e(getPhysXExporter(), rigidBody);
        }

        void exportExtra(const MObject& rigidBody)
        {
            PhysicsMaterialExtra e(getPhysXExporter(), rigidBody);
        }
    };

    class Hollow : public Element
    {
    public:
        Hollow(PhysXExporter& exporter, bool hollow)
            : Element(exporter, CSWC::CSW_ELEMENT_HOLLOW)
        {
            getStreamWriter().appendValues(hollow);
        }
    };

    class HalfExtents : public Element
    {
    public:
        HalfExtents(PhysXExporter& exporter, const MVector & halfExtents)
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_BOX_EXTENTS)
        {
            getStreamWriter().appendValues(halfExtents.x, halfExtents.y, halfExtents.z);
        }
    };

    class ShapeBox : public Element
    {
    public:
        ShapeBox(PhysXExporter& exporter, const MObject & shape)
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_BOX)
        {
            exportHalfExtents(shape);
        }

    private:
        void exportHalfExtents(const MObject & shape)
        {
            double inflate = 0.0;
            DagHelper::getPlugValue(shape, ATTR_INFLATE, inflate);
            inflate = MDistance::internalToUI(inflate);

            MVector size;
            DagHelper::getPlugValue(shape, ATTR_SIZE, size);
            size.x = MDistance::internalToUI(size.x) + inflate * 2.0;
            size.y = MDistance::internalToUI(size.y) + inflate * 2.0;
            size.z = MDistance::internalToUI(size.z) + inflate * 2.0;
            HalfExtents e(getPhysXExporter(), size / 2.0);
        }
    };

    class CapsuleRadius : public Element
    {
    public:
        CapsuleRadius(PhysXExporter& exporter, double radiusX, double radiusZ)
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_CAPSULE_RADIUS)
        {
            getStreamWriter().appendValues(radiusX, radiusZ);
        }
    };

    class SphereRadius : public Element
    {
    public:
        SphereRadius(PhysXExporter& exporter, double radius)
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_CAPSULE_RADIUS)
        {
            getStreamWriter().appendValues(radius);
        }
    };

    class ShapeSphere : public Element
    {
    public:
        ShapeSphere(PhysXExporter& exporter, const MObject & shape)
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_SPHERE)
        {
            exportRadius(shape);
        }

    private:
        void exportRadius(const MObject & shape)
        {
            double inflate = 0.0;
            DagHelper::getPlugValue(shape, ATTR_INFLATE, inflate);
            inflate = MDistance::internalToUI(inflate);

            double radius;
            DagHelper::getPlugValue(shape, ATTR_RADIUS, radius);
            radius = MDistance::internalToUI(radius) + inflate;
            SphereRadius e(getPhysXExporter(), radius);
        }
    };

    class Height : public Element
    {
    public:
        Height(PhysXExporter& exporter, double height)
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_CAPSULE_HEIGHT)
        {
            getStreamWriter().appendValues(height);
        }
    };

    class ShapeCapsule : public Element
    {
    public:
        ShapeCapsule(PhysXExporter& exporter, const MObject & shape)
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_CAPSULE)
        {
            exportRadius(shape);
            exportHeight(shape);
        }

    private:
        void exportRadius(const MObject & shape)
        {
            double inflate = 0.0;
            DagHelper::getPlugValue(shape, ATTR_INFLATE, inflate);
            inflate = MDistance::internalToUI(inflate);

            double radius;
            DagHelper::getPlugValue(shape, ATTR_RADIUS, radius);
            radius = MDistance::internalToUI(radius) + inflate;
            CapsuleRadius e(getPhysXExporter(), radius, radius);
        }

        void exportHeight(const MObject & shape)
        {
            double height;
            DagHelper::getPlugValue(shape, ATTR_HEIGHT, height);
            height = MDistance::internalToUI(height);
            Height e(getPhysXExporter(), height);
        }
    };

    class InstanceGeometry : public Element
    {
    public:
        InstanceGeometry(PhysXExporter& exporter, const URI & geometryURI)
            : Element(exporter, CSWC::CSW_ELEMENT_INSTANCE_GEOMETRY)
        {
            getStreamWriter().appendURIAttribute(CSWC::CSW_ATTRIBUTE_URL, geometryURI);
        }
    };

    class Density : public Element
    {
    public:
        Density(PhysXExporter& exporter, double density)
            : Element(exporter, CSWC::CSW_ELEMENT_DENSITY)
        {
            getStreamWriter().appendValues(density);
        }
    };

    class LocalPose : public Element
    {
    public:
        LocalPose(PhysXExporter& exporter, const MQuaternion& rotation, const MVector& translation)
            : Element(exporter, LOCAL_POSE)
        {
            double localPose[] = { rotation.x, rotation.y, rotation.z, rotation.w, translation.x, translation.y, translation.z };
            getStreamWriter().appendValues(localPose, sizeof(localPose) / sizeof(localPose[0]));
        }
    };

    class ShapeTechnique : public Element
    {
    public:
        ShapeTechnique(PhysXExporter& exporter, const MObject& rigidBody, const MObject& shape, const String & profile)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE)
        {
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_PROFILE, profile);
            //exportLocalPose(shape);
            if (profile == PhysXExporter::GetProfile()) {
                exporter.exportAttributes(shape, GetAttributes());
            }
            else if (profile == PhysXExporter::GetProfileXML()) {
                exporter.exportShapePhysXXML(rigidBody, shape);
            }
        }

    private:
        static const std::set<MString, MStringComp>& GetAttributes()
        {
            if (mAttributes.size() == 0)
            {
                // Attributes we want to export in <extra> section
                mAttributes.insert(ATTR_SHAPE_TYPE);
                mAttributes.insert(ATTR_SIZE);
                mAttributes.insert(ATTR_RADIUS);
                mAttributes.insert(ATTR_HEIGHT);
                mAttributes.insert(ATTR_BEST_FIT);
                mAttributes.insert(ATTR_OUT_PHYSICS_SHAPE);
                mAttributes.insert(ATTR_CONNECT_TO_CLOTH_SPHERE);
                mAttributes.insert(ATTR_INFLATE);
                mAttributes.insert(ATTR_USE_MASS_OR_DENSITY);
                mAttributes.insert(ATTR_MASS);
                mAttributes.insert(ATTR_DENSITY);
            }
            return mAttributes;
        }

    private:
        static std::set<MString, MStringComp> mAttributes;
    };
    std::set<MString, MStringComp> ShapeTechnique::mAttributes;

    class ShapeExtra : public Element
    {
    public:
        ShapeExtra(PhysXExporter& exporter, const MObject& rigidBody, const MObject& shape)
            : Element(exporter, CSWC::CSW_ELEMENT_EXTRA)
        {
            exportProfile(rigidBody, shape, PhysXExporter::GetProfile());
            exportProfile(rigidBody, shape, PhysXExporter::GetProfileXML());
        }

    private:
        void exportProfile(const MObject& rigidBody, const MObject& shape, const String& profile)
        {
            ShapeTechnique e(getPhysXExporter(), rigidBody, shape, profile);
        }
    };

    class Shape : public Element
    {
    public:
        Shape(PhysXExporter& exporter, const MObject& rigidBody, const MObject & shape)
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE)
        {
            exportHollow(shape);

            int dummy = 0;
            MString useMassOrDensity;
            DagHelper::getPlugValue(shape, ATTR_USE_MASS_OR_DENSITY, dummy, useMassOrDensity);
            if (useMassOrDensity == USE_MASS_OR_DENSITY_MASS)
            {
                exportMass(shape);
            }
            else //if (useMassOrDensity == USE_MASS_OR_DENSITY_DENSITY)
            {
                exportDensity(shape);
            }

            //no <physics_material> exported for shapes. Use rigid body's one.

            MString shapeType;
            PhysXShape::GetType(shape, shapeType);
            if (shapeType == SHAPE_TYPE_BOX)
            {
                exportBox(shape);
            }
            else if (shapeType == SHAPE_TYPE_SPHERE)
            {
                exportSphere(shape);
            }
            else if (shapeType == SHAPE_TYPE_CAPSULE)
            {
                exportCapsule(shape);
            }
            else if (shapeType == SHAPE_TYPE_CONVEX_HULL)
            {
                exportConvexHull(shape);
            }
            else if (shapeType == SHAPE_TYPE_TRIANGLE_MESH)
            {
                exportTriangleMesh(shape);
            }
            else if (shapeType == SHAPE_TYPE_CLOTH_SPHERES)
            {
                exportSphere(shape);
            }

            exportRotateTranslate(rigidBody, shape);
            exportExtra(rigidBody, shape);
        }

    private:
        void exportHollow(const MObject & shape)
        {
            //Hollow hollow(getPhysXExporter(), false);
        }

        void exportMass(const MObject & shape)
        {
            double mass = 0.0;
            DagHelper::getPlugValue(shape, ATTR_MASS, mass);
            Mass e(getPhysXExporter(), mass);
        }

        void exportDensity(const MObject & shape)
        {
            double density = 0.0;
            DagHelper::getPlugValue(shape, ATTR_DENSITY, density);
            Density e(getPhysXExporter(), density);
        }

        void exportBox(const MObject & shape)
        {
            ShapeBox e(getPhysXExporter(), shape);
        }

        void exportSphere(const MObject & shape)
        {
            ShapeSphere e(getPhysXExporter(), shape);
        }

        void exportCapsule(const MObject & shape)
        {
            ShapeCapsule e(getPhysXExporter(), shape);
        }

        void exportConvexHull(const MObject & shape)
        {
            // TODO PhysX: apply "inflate" attribute to convex hull geometry.
            // Note: apply inflation like done for box shape. See ShapeBox::exportHalfExtents().
            // However "inflate" attribute is limited to [0; 0.839] for some unknown reason.
            exportInstanceGeometry(shape, "_");
        }

        void exportTriangleMesh(const MObject & shape)
        {
            exportInstanceGeometry(shape);
        }

        void exportInstanceGeometry(const MObject & shape, const String & URISuffix = "")
        {
            // Get geometry URI
            MObject meshObject;
            PhysXShape::GetConnectedInMesh(shape, meshObject);

            if (meshObject.isNull() || !ExportOptions::exportPolygonMeshes())
            {
                // If connected mesh doesn't exist anymore then we use the PhysX shape internal geometry
                // This should rarely happen but this is possible...
                // Also use shape internal geometry if we don't export polygon meshes.
                meshObject = shape;
            }

            URI geometryURI;
            getPhysXExporter().getMeshURI(meshObject, geometryURI);
            if (URISuffix.length() > 0) {
                geometryURI.setFragment(geometryURI.getFragment() + URISuffix);
            }
            InstanceGeometry e(getPhysXExporter(), geometryURI);
        }

        void exportRotateTranslate(const MObject& rigidBody, const MObject & shape)
        {
            // Get shape local pose.
            MMatrix localPose = MMatrix::identity;
            getPhysXExporter().getShapeLocalPose(rigidBody, shape, localPose);

            // Rigidbody world pose
            MMatrix globalPose = MMatrix::identity;
            getPhysXExporter().getRigidBodyGlobalPose(rigidBody, globalPose);
            
            // Parent world pose
            MObject parent;
            MFnDagNode rigidBodyNode(rigidBody);
            parent = rigidBodyNode.parent(0);
            MDagPath parentDagPath;
            MDagPath::getAPathTo(parent, parentDagPath);
            MMatrix parentGlobalPose = parentDagPath.inclusiveMatrix();

            MMatrix DAEShapeLocalPose = localPose * globalPose * parentGlobalPose.inverse();

            int dummy = 0;
            MString shapeType;
            DagHelper::getPlugValue(shape, ATTR_SHAPE_TYPE, dummy, shapeType);
            if (shapeType == SHAPE_TYPE_CAPSULE) {
                // PhysX capsules are X axis oriented. COLLADA capsules are Y axis oriented.
                MTransformationMatrix rotation;
                rotation.rotateBy(MEulerRotation(0.0, 0.0, -M_PI / 2.0, MEulerRotation::kXYZ), MSpace::kTransform);
                MMatrix rotationMatrix = rotation.asMatrix();
                DAEShapeLocalPose = DAEShapeLocalPose * rotationMatrix;
            }

            MTransformationMatrix transform(DAEShapeLocalPose);

            MVector translation = transform.getTranslation(MSpace::kTransform);
            MVector rotatePivotTranslation = transform.rotatePivotTranslation(MSpace::kTransform);
            MPoint rotatePivot = transform.rotatePivot(MSpace::kTransform);
            MEulerRotation rotation = transform.eulerRotation();
            rotation.order = static_cast<MEulerRotation::RotationOrder>(static_cast<int>(transform.rotationOrder()) - MTransformationMatrix::kXYZ + MEulerRotation::kXYZ);

            getPhysXExporter().exportTranslation(translation, ATTR_TRANSLATE);
            getPhysXExporter().exportTranslation(rotatePivotTranslation, ATTR_ROTATE_PIVOT_TRANSLATION);
            getPhysXExporter().exportTranslation(rotatePivot, ATTR_ROTATE_PIVOT);
            getPhysXExporter().exportRotation(rotation, ATTR_ROTATE);
            getPhysXExporter().exportTranslation(rotatePivot * -1, ATTR_ROTATE_PIVOT_INVERSE);
        }

        void exportExtra(const MObject& rigidBody, const MObject & shape)
        {
            ShapeExtra e(getPhysXExporter(), rigidBody, shape);
        }
    };

    class Enabled : public Element
    {
    public:
        Enabled(PhysXExporter& exporter, bool enabled)
            : Element(exporter, CSWC::CSW_ELEMENT_ENABLED)
        {
            getStreamWriter().appendValues(enabled);
        }
    };

    class Interpenetrate : public Element
    {
    public:
        Interpenetrate(PhysXExporter& exporter, bool interpenetrate)
            : Element(exporter, CSWC::CSW_ELEMENT_INTERPENETRATE)
        {
            getStreamWriter().appendValues(interpenetrate);
        }
    };

    class Min : public Element
    {
    public:
        Min(PhysXExporter& exporter, const MVector & min)
            : Element(exporter, CSWC::CSW_ELEMENT_MIN)
        {
            for (uint i = 0; i < 3; ++i)
            {
                if (isInf(min(i))) {
                    getStreamWriter().appendValues("-INF");
                }
                else {
                    getStreamWriter().appendValues(min(i));
                }
            }
        }
    };

    class Max : public Element
    {
    public:
        Max(PhysXExporter& exporter, const MVector & max)
            : Element(exporter, CSWC::CSW_ELEMENT_MAX)
        {
            for (uint i = 0; i < 3; ++i)
            {
                if (isInf(max(i))) {
                    getStreamWriter().appendValues("INF");
                }
                else {
                    getStreamWriter().appendValues(max(i));
                }
            }
        }
    };

    class SwingConeAndTwist : public Element
    {
    public:
        SwingConeAndTwist(PhysXExporter& exporter,
            const MVector & min,
            const MVector & max)
            : Element(exporter, CSWC::CSW_ELEMENT_SWING_CONE_AND_TWIST)
        {
            exportMin(min);
            exportMax(max);
        }

    private:
        void exportMin(const MVector & min)
        {
            if (min != MVector::zero)
            {
                Min e(getPhysXExporter(), min);
            }
        }

        void exportMax(const MVector & max)
        {
            if (max != MVector::zero)
            {
                Max e(getPhysXExporter(), max);
            }
        }
    };

    class LimitsLinear : public Element
    {
    public:
        LimitsLinear(PhysXExporter& exporter,
            const MVector & min,
            const MVector & max)
            : Element(exporter, CSWC::CSW_ELEMENT_LINEAR)
        {
            exportMin(min);
            exportMax(max);
        }

    private:
        void exportMin(const MVector & min)
        {
            if (min != MVector::zero)
            {
                Min e(getPhysXExporter(), min);
            }
        }

        void exportMax(const MVector & max)
        {
            if (max != MVector::zero)
            {
                Max e(getPhysXExporter(), max);
            }
        }
    };

    class Limits : public Element
    {
    public:
        Limits(PhysXExporter& exporter,
            const MVector & swingConeAndTwistMin,
            const MVector & swingConeAndTwistMax,
            const MVector & linearMin,
            const MVector & linearMax)
            : Element(exporter, CSWC::CSW_ELEMENT_LIMITS)
        {
            exportSwingConeAndTwist(swingConeAndTwistMin, swingConeAndTwistMax);
            exportLinear(linearMin, linearMax);
        }

    private:
        void exportSwingConeAndTwist(
            const MVector & min,
            const MVector & max)
        {
            if (min != MVector::zero ||
                max != MVector::zero)
            {
                SwingConeAndTwist e(getPhysXExporter(), min, max);
            }
        }

        void exportLinear(
            const MVector & min,
            const MVector & max)
        {
            if (min != MVector::zero ||
                max != MVector::zero)
            {
                LimitsLinear e(getPhysXExporter(), min, max);
            }
        }
    };

    class Stiffness : public Element
    {
    public:
        Stiffness(PhysXExporter& exporter, double stiffness, const String & sid = "")
            : Element(exporter, CSWC::CSW_ELEMENT_STIFFNESS)
        {
            if (!sid.empty()) {
                getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
            }
            getStreamWriter().appendValues(stiffness);
        }
    };

    class Damping : public Element
    {
    public:
        Damping(PhysXExporter& exporter, double damping, const String & sid = "")
            : Element(exporter, CSWC::CSW_ELEMENT_DAMPING)
        {
            if (!sid.empty()) {
                getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
            }
            getStreamWriter().appendValues(damping);
        }
    };

    class TargetValue : public Element
    {
    public:
        TargetValue(PhysXExporter& exporter, double targetValue, const String & sid = "")
            : Element(exporter, CSWC::CSW_ELEMENT_TARGET_VALUE)
        {
            if (!sid.empty()) {
                getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
            }
            getStreamWriter().appendValues(targetValue);
        }
    };

    class SpringLinear : public Element
    {
    public:
        SpringLinear(PhysXExporter& exporter,
            double stiffness,
            double damping,
            double targetValue)
            : Element(exporter, CSWC::CSW_ELEMENT_LINEAR)
        {
            exportStiffness(stiffness);
            exportDamping(damping);
            exportTargetValue(targetValue);
        }

    private:
        void exportStiffness(double stiffness)
        {
            if (stiffness != 1.0)
            {
                Stiffness e(getPhysXExporter(), stiffness);
            }
        }

        void exportDamping(double damping)
        {
            if (damping != 0.0)
            {
                Damping e(getPhysXExporter(), damping);
            }
        }

        void exportTargetValue(double targetValue)
        {
            if (targetValue != 0.0)
            {
                TargetValue e(getPhysXExporter(), targetValue);
            }
        }
    };

    class Angular : public Element
    {
    public:
        Angular(PhysXExporter& exporter,
            double stiffness,
            double damping,
            double targetValue)
            : Element(exporter, CSWC::CSW_ELEMENT_ANGULAR)
        {
            exportStiffness(stiffness);
            exportDamping(damping);
            exportTargetValue(targetValue);
        }

    private:
        void exportStiffness(double stiffness)
        {
            if (stiffness != 1.0)
            {
                Stiffness e(getPhysXExporter(), stiffness);
            }
        }

        void exportDamping(double damping)
        {
            if (damping != 0.0)
            {
                Damping e(getPhysXExporter(), damping);
            }
        }

        void exportTargetValue(double targetValue)
        {
            if (targetValue != 0.0)
            {
                TargetValue e(getPhysXExporter(), targetValue);
            }
        }
    };

    class Spring : public Element
    {
    public:
        Spring(PhysXExporter& exporter,
            double angularStiffness,
            double angularDamping,
            double angularTargetValue,
            double linearStiffness,
            double linearDamping,
            double linearTargetValue)
            : Element(exporter, CSWC::CSW_ELEMENT_SPRING)
        {
            exportAngular(angularStiffness, angularDamping, angularTargetValue);
            exportLinear(linearStiffness, linearDamping, linearTargetValue);
        }

    private:
        void exportLinear(
            double stiffness,
            double damping,
            double targetValue)
        {
            if (stiffness != 1.0 ||
                damping != 0.0 ||
                targetValue != 0.0)
            {
                SpringLinear e(getPhysXExporter(), stiffness, damping, targetValue);
            }
        }

        void exportAngular(
            double stiffness,
            double damping,
            double targetValue)
        {
            if (stiffness != 1.0 ||
                damping != 0.0 ||
                targetValue != 0.0)
            {
                Angular e(getPhysXExporter(), stiffness, damping, targetValue);
            }
        }
    };

    class RigidBodyTechniqueCommon : public Element
    {
    public:
        RigidBodyTechniqueCommon(PhysXExporter& exporter, const MObject & rigidBody)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE_COMMON)
        {
            exportDynamic(rigidBody);
            exportMass(rigidBody);
            exportMassFrame(rigidBody);
            exportInertia(rigidBody);
            exportPhysicsMaterial(rigidBody);
            exportShapes(rigidBody);
        }

    private:
        void exportDynamic(const MObject & rigidBody)
        {
            int dummy = 0;
            MString simulationType;
            DagHelper::getPlugValue(rigidBody, ATTR_SIMULATION_TYPE, dummy, simulationType);
            Dynamic e(getPhysXExporter(), simulationType != SIMULATION_TYPE_STATIC);
        }

        void exportMass(const MObject & rigidBody)
        {
            double mass = getPhysXExporter().GetRigidBodyMass(rigidBody);
            Mass e(getPhysXExporter(), mass);
        }

        void exportMassFrame(const MObject & rigidBody)
        {
            int dummy = 0;
            MString centerOfMassMode;
            DagHelper::getPlugValue(rigidBody, ATTR_CENTER_OF_MASS_MODE, dummy, centerOfMassMode);

            MString overrideMassOrDensityStr;
            DagHelper::getPlugValue(rigidBody, ATTR_OVERRIDE_MASS_OR_DENSITY, dummy, overrideMassOrDensityStr);
            bool overrideMassOrDensity = overrideMassOrDensityStr != OVERRIDE_MASS_OR_DENSITY_DISABLED;

            MVector translation = MVector::zero;
            if (centerOfMassMode == CENTER_OF_MASS_MODE_CALCULATE_FROM_SHAPES)
            {
                std::vector<MObject> physicsShapes;
                getPhysXExporter().GetRigidBodyShapes(rigidBody, physicsShapes);

                double totalFactor = 0.0;
                for (size_t i = 0; i < physicsShapes.size(); ++i)
                {
                    const MObject & shape = physicsShapes[i];
                    MDagPath shapeDagPath;
                    MDagPath::getAPathTo(shape, shapeDagPath);
                    MFnTransform shapeTransform(shapeDagPath.transform());
                    double shapeFactor = overrideMassOrDensity ? getPhysXExporter().GetShapeVolume(shape) : getPhysXExporter().GetShapeMass(shape);
                    translation += shapeTransform.getTranslation(MSpace::kObject) * shapeFactor;
                    totalFactor += shapeFactor;
                }
                if (totalFactor > 0.0)
                {
                    translation /= totalFactor;
                }
            }
            else //if (centerOfMassMode == CENTER_OF_MASS_MODE_MANUAL_OVERRIDE)
            {
                DagHelper::getPlugValue(rigidBody, ATTR_CENTER_OF_MASS_OVERRIDE, translation);
            }

            if (translation != MVector::zero)
            {
                MassFrame e(getPhysXExporter(), translation, ATTR_TRANSLATE);
            }
        }

        void exportInertia(const MObject & rigidBody)
        {
            /*
            Bounding box inertia matrix =

            m(b²+c²)/12     0               0
            0               m(a²+c²)/12     0
            0               0               m(a²+b²)/12

            m -> mass
            a, b, c -> edge lengths
            */

            MVector bb = MVector::zero;
            DagHelper::getPlugValue(rigidBody, ATTR_BOUNDING_BOX_SIZE, bb);

            // Convert to DAE unit
            bb.x = MDistance::internalToUI(bb.x);
            bb.y = MDistance::internalToUI(bb.y);
            bb.z = MDistance::internalToUI(bb.z);

            double mass = getPhysXExporter().GetRigidBodyMass(rigidBody);

            MVector inertiaMatrixDiagonal = MVector::zero;
            inertiaMatrixDiagonal.x = mass * (bb.y * bb.y + bb.z * bb.z) / 12.0;
            inertiaMatrixDiagonal.y = mass * (bb.x * bb.x + bb.z * bb.z) / 12.0;
            inertiaMatrixDiagonal.z = mass * (bb.x * bb.x + bb.y * bb.y) / 12.0;

            Inertia e(getPhysXExporter(), inertiaMatrixDiagonal);
        }

        void exportPhysicsMaterial(const MObject & rigidBody)
        {
            PhysicsMaterial e(getPhysXExporter(), rigidBody);
        }

        void exportShapes(const MObject & rigidBody)
        {
            std::vector<MObject> physicsShapes;
            getPhysXExporter().GetRigidBodyShapes(rigidBody, physicsShapes);

            for (size_t i = 0; i < physicsShapes.size(); ++i)
            {
                const MObject & shape = physicsShapes[i];

                Shape e(getPhysXExporter(), rigidBody, shape);
            }
        }
    };

    class RigidConstraintTechniqueCommon : public Element
    {
    public:
        RigidConstraintTechniqueCommon(PhysXExporter& exporter, const MObject & rigidConstraint)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE_COMMON)
        {
            exportEnabled(rigidConstraint);
            exportInterpenetrate(rigidConstraint);
            exportLimits(rigidConstraint);
            exportSpring(rigidConstraint);
        }

    private:
        void exportEnabled(const MObject & rigidConstraint)
        {
            bool isEnabled = true;
            DagHelper::getPlugValue(rigidConstraint, ATTR_CONSTRAIN, isEnabled);
            if (!isEnabled)
            {
                Enabled e(getPhysXExporter(), isEnabled);
            }
        }

        void exportInterpenetrate(const MObject & rigidConstraint)
        {
            bool interpenetrate = false;
            DagHelper::getPlugValue(rigidConstraint, ATTR_INTERPENETRATE, interpenetrate);
            if (interpenetrate)
            {
                Interpenetrate e(getPhysXExporter(), interpenetrate);
            }
        }

        void exportLimits(const MObject & rigidConstraint)
        {
            MVector swingConeAndTwistMin, swingConeAndTwistMax, linearMin, linearMax;
            PhysXRigidConstraint::GetSwingConeAndTwistMinLimit(rigidConstraint, swingConeAndTwistMin);
            PhysXRigidConstraint::GetSwingConeAndTwistMaxLimit(rigidConstraint, swingConeAndTwistMax);
            PhysXRigidConstraint::GetLinearMinLimit(rigidConstraint, linearMin);
            PhysXRigidConstraint::GetLinearMaxLimit(rigidConstraint, linearMax);
            if (swingConeAndTwistMin != MVector::zero ||
                swingConeAndTwistMax != MVector::zero ||
                linearMin != MVector::zero ||
                linearMax != MVector::zero)
            {
                Limits e(getPhysXExporter(),
                    swingConeAndTwistMin,
                    swingConeAndTwistMax,
                    linearMin,
                    linearMax);
            }
        }

        void exportSpring(const MObject & rigidConstraint)
        {
            double linearStiffness = 1.0;
            double linearDamping = 0.0;
            double linearTargetValue = 0.0;
            double angularStiffness = 1.0;
            double angularDamping = 0.0;
            double angularTargetValue = 0.0;
            PhysXRigidConstraint::GetSpringLinearStiffness(rigidConstraint, linearStiffness);
            PhysXRigidConstraint::GetSpringLinearDamping(rigidConstraint, linearDamping);
            PhysXRigidConstraint::GetSpringLinearTargetValue(rigidConstraint, linearTargetValue);
            PhysXRigidConstraint::GetSpringAngularStiffness(rigidConstraint, angularStiffness);
            PhysXRigidConstraint::GetSpringAngularDamping(rigidConstraint, angularDamping);
            PhysXRigidConstraint::GetSpringAngularTargetValue(rigidConstraint, angularTargetValue);
            if (linearStiffness != 1.0 ||
                linearDamping != 0.0 ||
                linearTargetValue != 0.0 ||
                angularStiffness != 1.0 ||
                angularDamping != 0.0 ||
                angularTargetValue != 0.0)
            {
                Spring e(getPhysXExporter(),
                    angularStiffness,
                    angularDamping,
                    angularTargetValue,
                    linearStiffness,
                    linearDamping,
                    linearTargetValue);
            }
        }
    };

    class RigidBodyTechnique : public Element
    {
    public:
        RigidBodyTechnique(PhysXExporter& exporter, const MObject & rigidBody, const String & profile)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE)
        {
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_PROFILE, profile);
            
            if (profile == PhysXExporter::GetProfile()) {
                exporter.exportAttributes(rigidBody, GetAttributes());
            }
            else if (profile == PhysXExporter::GetProfileXML()) {
                exporter.exportRigidBodyPhysXXML(rigidBody);
            }
        }

    private:
        static const std::set<MString, MStringComp>& GetAttributes()
        {
            if (mAttributes.size() == 0)
            {
                // Attributes we want to export in <extra> section
                mAttributes.insert(ATTR_SIMULATION_TYPE);
                mAttributes.insert(ATTR_SWITCH_TO_DYNAMIC);
                mAttributes.insert(ATTR_SWITCH_AT_FRAME);
                mAttributes.insert(ATTR_ENABLE_GRAVITY);
                mAttributes.insert(ATTR_FORCE_TO_SLEEP);
                mAttributes.insert(ATTR_OVERRIDE_MASS_OR_DENSITY);
                mAttributes.insert(ATTR_MASS);
                mAttributes.insert(ATTR_DENSITY);
                mAttributes.insert(ATTR_BOUNCINESS);
                mAttributes.insert(ATTR_STATIC_FRICTION);
                mAttributes.insert(ATTR_DYNAMIC_FRICTION);
                mAttributes.insert(ATTR_OVERRIDE_GLOBAL_ITERATION_COUNT);
                mAttributes.insert(ATTR_POSITION_ITERATION_COUNT);
                mAttributes.insert(ATTR_VELOCITY_ITERATION_COUNT);
                mAttributes.insert(ATTR_CONTACT_SHELL_OVERRIDE);
                mAttributes.insert(ATTR_CONTACT_SHELL_DEPTH);
                mAttributes.insert(ATTR_CONTACT_SHELL_OFFSET);
                mAttributes.insert(ATTR_SLEEP_THRESHOLDS_OVERRIDE);
                mAttributes.insert(ATTR_SLEEP_ENERGY_THRESHOLD);
                mAttributes.insert(ATTR_LINEAR_DAMPING);
                mAttributes.insert(ATTR_ANGULAR_DAMPING);
                mAttributes.insert(ATTR_CENTER_OF_MASS_MODE);
                mAttributes.insert(ATTR_CENTER_OF_MASS_OVERRIDE);
                mAttributes.insert(ATTR_INITIAL_VELOCITY);
                mAttributes.insert(ATTR_INITIAL_SPIN);
                mAttributes.insert(ATTR_INITIAL_POSITION);
                mAttributes.insert(ATTR_INITIAL_ORIENTATION);
                mAttributes.insert(ATTR_ENABLE_CCD);
                mAttributes.insert(ATTR_CCD_MOTION_THRESHOLD);
            }
            return mAttributes;
        }

    private:
        static std::set<MString, MStringComp> mAttributes;
    };
    std::set<MString, MStringComp> RigidBodyTechnique::mAttributes;

    class RigidBodyExtra : public Element
    {
    public:
        RigidBodyExtra(PhysXExporter& exporter, const MObject & rigidBody)
            : Element(exporter, CSWC::CSW_ELEMENT_EXTRA)
        {
            exportProfile(rigidBody, PhysXExporter::GetProfile());
            exportProfile(rigidBody, PhysXExporter::GetProfileXML());
        }

    private:
        void exportProfile(const MObject& rigidBody, const String& profile)
        {
            RigidBodyTechnique e(getPhysXExporter(), rigidBody, profile);
        }
    };

    class RigidBody : public Element
    {
    public:
        RigidBody(PhysXExporter& exporter, const MObject & rigidBody, const String & sid, const String & name = "")
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY)
        {
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
            if (name.length() > 0) {
                getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_NAME, name);
            }

            exportTechniqueCommon(rigidBody);
            exportExtra(rigidBody);
        }

    private:
        void exportTechniqueCommon(const MObject & rigidBody)
        {
            RigidBodyTechniqueCommon e(getPhysXExporter(), rigidBody);
        }

        void exportExtra(const MObject & rigidBody)
        {
            RigidBodyExtra e(getPhysXExporter(), rigidBody);
        }
    };

    class RefAttachment : public Element
    {
    public:
        RefAttachment(PhysXExporter& exporter, const MObject & rigidConstraint, const URI & rigidBodyURI)
            : Element(exporter, CSWC::CSW_ELEMENT_REF_ATTACHMENT)
        {
            if (rigidBodyURI.isValid()) {
                getStreamWriter().appendURIAttribute(CSWC::CSW_ATTRIBUTE_RIGID_BODY, rigidBodyURI);
            }
            exportRotateTranslate(rigidConstraint);
        }

    private:
        void exportRotateTranslate(const MObject & rigidConstraint)
        {
            // get attached rigid body (parent)
            MObject ref;
            PhysXExporter::GetPluggedObject(rigidConstraint, ATTR_RIGID_BODY_1, ref);

            MMatrix refLocalToWorld = MMatrix::identity;
            if (!ref.isNull())
            {
                MDagPath refDagPath;
                MDagPath::getAPathTo(ref, refDagPath);
                refLocalToWorld = refDagPath.inclusiveMatrix();
            }

            MDagPath constraintDagPath;
            MDagPath::getAPathTo(rigidConstraint, constraintDagPath);

            MMatrix constraintLocalToWorld = constraintDagPath.inclusiveMatrix();
            MMatrix constraintLocalToRef = constraintLocalToWorld * refLocalToWorld.inverse();

            MTransformationMatrix constraintLocalToRefTM(constraintLocalToRef);
            MVector translation = constraintLocalToRefTM.getTranslation(MSpace::kTransform);
            double angles[3];
            MTransformationMatrix::RotationOrder rotationOrder;
            constraintLocalToRefTM.getRotation(angles, rotationOrder);
            MEulerRotation rotation;
            rotation.x = angles[0];
            rotation.y = angles[1];
            rotation.z = angles[2];
            rotation.order = static_cast<MEulerRotation::RotationOrder>(
                static_cast<int>(rotationOrder)-MTransformationMatrix::kXYZ + MEulerRotation::kXYZ
                );

            getPhysXExporter().exportTranslation(translation, ATTR_TRANSLATE);
            getPhysXExporter().exportRotation(rotation, ATTR_ROTATE);
        }
    };

    class Attachment : public Element
    {
    public:
        Attachment(PhysXExporter& exporter, const MObject & rigidConstraint, const URI & rigidBodyURI)
            : Element(exporter, CSWC::CSW_ELEMENT_ATTACHMENT)
        {
            if (rigidBodyURI.isValid()) {
                getStreamWriter().appendURIAttribute(CSWC::CSW_ATTRIBUTE_RIGID_BODY, rigidBodyURI);
            }
            exportRotateTranslate(rigidConstraint);
        }

    private:
        void exportRotateTranslate(const MObject & rigidConstraint)
        {
            // get attached rigid body (child)
            MObject attachment;
            PhysXExporter::GetPluggedObject(rigidConstraint, ATTR_RIGID_BODY_2, attachment);

            MDagPath constraintDagPath;
            MDagPath attachmentDagPath;
            
            MDagPath::getAPathTo(rigidConstraint, constraintDagPath);
            MDagPath::getAPathTo(attachment, attachmentDagPath);

            MMatrix constraintLocalToWorld = constraintDagPath.inclusiveMatrix();
            MMatrix attachmentLocalToWorld = attachmentDagPath.inclusiveMatrix();

            MTransformationMatrix constraintLocalToWorldTM(constraintLocalToWorld);
            MTransformationMatrix attachmentLocalToWorldTM(attachmentLocalToWorld);
            
            int dummy = 0;
            MString orientationMode;
            DagHelper::getPlugValue(rigidConstraint, ATTR_ORIENTATION_MODE, dummy, orientationMode);
            if (orientationMode == TARGET_ORIGIN)
            {
                // World space target origin
                MVector targetOrigin = attachmentLocalToWorldTM.translation(MSpace::kTransform);

                // World space constraint origin
                MVector constraintOrigin = constraintLocalToWorldTM.translation(MSpace::kTransform);

                MVector x = targetOrigin - constraintOrigin;

                // if target origin and constraint origin are at the same place, we'll get wrong results
                if (x.length() < getPhysXExporter().getDocumentExporter().getTolerance()) {
                    MGlobal::displayWarning("constraint origin and target origin too close");
                }

                x.normalize();

                MVector z = constraintLocalToWorld[2];
                
                MVector y = z ^ x;
                y.normalize();

                z = x ^ y;
                z.normalize();
                
                MMatrix adjustedConstraintLocalToWorld = MMatrix::identity;
                adjustedConstraintLocalToWorld(0, 0) = x.x;
                adjustedConstraintLocalToWorld(0, 1) = x.y;
                adjustedConstraintLocalToWorld(0, 2) = x.z;
                adjustedConstraintLocalToWorld(1, 0) = y.x;
                adjustedConstraintLocalToWorld(1, 1) = y.y;
                adjustedConstraintLocalToWorld(1, 2) = y.z;
                adjustedConstraintLocalToWorld(2, 0) = z.x;
                adjustedConstraintLocalToWorld(2, 1) = z.y;
                adjustedConstraintLocalToWorld(2, 2) = z.z;
                adjustedConstraintLocalToWorld(3, 0) = constraintOrigin.x;
                adjustedConstraintLocalToWorld(3, 1) = constraintOrigin.y;
                adjustedConstraintLocalToWorld(3, 2) = constraintOrigin.z;

                MMatrix constraintLocalToAttachment = adjustedConstraintLocalToWorld * attachmentLocalToWorld.inverse();
                MTransformationMatrix constraintLocalToAttachmentTM(constraintLocalToAttachment);
                MVector translation = constraintLocalToAttachmentTM.getTranslation(MSpace::kTransform);

                double angles[3];
                MTransformationMatrix::RotationOrder rotationOrder;
                constraintLocalToAttachmentTM.getRotation(angles, rotationOrder);
                MEulerRotation rotation;
                rotation.x = angles[0];
                rotation.y = angles[1];
                rotation.z = angles[2];
                rotation.order = static_cast<MEulerRotation::RotationOrder>(
                    static_cast<int>(rotationOrder)-MTransformationMatrix::kXYZ + MEulerRotation::kXYZ
                    );

                getPhysXExporter().exportTranslation(translation, ATTR_TRANSLATE);
                getPhysXExporter().exportRotation(rotation, ATTR_ROTATE);
            }
            else if (orientationMode == CENTERED)
            {
                // TODO
            }
        }
    };

    class RigidConstraintTechnique : public Element
    {
    public:
        RigidConstraintTechnique(PhysXExporter& exporter, const MObject & rigidConstraint, const String & profile)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE)
        {
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_PROFILE, profile);
            if (profile == PhysXExporter::GetProfile()) {
                exporter.exportAttributes(rigidConstraint, GetAttributes());
            }
            else if (profile == PhysXExporter::GetProfileXML()) {
                exporter.exportRigidConstraintPhysXXML(rigidConstraint);
            }
        }

    private:
        static const std::set<MString, MStringComp>& GetAttributes()
        {
            if (mAttributes.size() == 0)
            {
                // Attributes we want to export in <extra> section
                mAttributes.insert(ATTR_CONSTRAIN);
                mAttributes.insert(ATTR_USE_ACCELERATION);
                mAttributes.insert(ATTR_INTERPENETRATE);
                mAttributes.insert(ATTR_TRANSLATE);
                mAttributes.insert(ATTR_ROTATE);
                mAttributes.insert(ATTR_RADIUS_SCALE);
                mAttributes.insert(ATTR_ORIENTATION_MODE);
                mAttributes.insert(ATTR_MOTION_SWING_Y);
                mAttributes.insert(ATTR_MOTION_SWING_Z);
                mAttributes.insert(ATTR_SWING_1_LIMIT_VALUE);
                mAttributes.insert(ATTR_SWING_1_LIMIT_RESTITUTION);
                mAttributes.insert(ATTR_SWING_1_LIMIT_SPRING);
                mAttributes.insert(ATTR_SWING_1_LIMIT_DAMPING);
                mAttributes.insert(ATTR_SWING_2_LIMIT_VALUE);
                mAttributes.insert(ATTR_SWING_2_LIMIT_RESTITUTION);
                mAttributes.insert(ATTR_SWING_2_LIMIT_SPRING);
                mAttributes.insert(ATTR_SWING_2_LIMIT_DAMPING);
                mAttributes.insert(ATTR_MOTION_TWIST);
                mAttributes.insert(ATTR_TWIST_LOW_LIMIT_VALUE);
                mAttributes.insert(ATTR_TWIST_LOW_LIMIT_RESTITUTION);
                mAttributes.insert(ATTR_TWIST_LOW_LIMIT_SPRING);
                mAttributes.insert(ATTR_TWIST_LOW_LIMIT_DAMPING);
                mAttributes.insert(ATTR_TWIST_HIGH_LIMIT_VALUE);
                mAttributes.insert(ATTR_TWIST_HIGH_LIMIT_RESTITUTION);
                mAttributes.insert(ATTR_TWIST_HIGH_LIMIT_SPRING);
                mAttributes.insert(ATTR_TWIST_HIGH_LIMIT_DAMPING);
                mAttributes.insert(ATTR_MOTION_X);
                mAttributes.insert(ATTR_MOTION_Y);
                mAttributes.insert(ATTR_MOTION_Z);
                mAttributes.insert(ATTR_LINEAR_LIMIT_VALUE);
                mAttributes.insert(ATTR_LINEAR_LIMIT_RESTITUTION);
                mAttributes.insert(ATTR_LINEAR_LIMIT_SPRING);
                mAttributes.insert(ATTR_LINEAR_LIMIT_DAMPING);
                mAttributes.insert(ATTR_DRIVE_DAMPING_X);
                mAttributes.insert(ATTR_DRIVE_DAMPING_Y);
                mAttributes.insert(ATTR_DRIVE_DAMPING_Z);
                mAttributes.insert(ATTR_DRIVE_DAMPING_SWING);
                mAttributes.insert(ATTR_DRIVE_DAMPING_TWIST);
                mAttributes.insert(ATTR_DRIVE_DAMPING_SLERP);
                mAttributes.insert(ATTR_GOAL_SPACE);
                mAttributes.insert(ATTR_GOAL_POSITION);
                mAttributes.insert(ATTR_GOAL_ORIENTATION);
                mAttributes.insert(ATTR_DRIVE_SPRING_X);
                mAttributes.insert(ATTR_DRIVE_SPRING_Y);
                mAttributes.insert(ATTR_DRIVE_SPRING_Z);
                mAttributes.insert(ATTR_DRIVE_SPRING_SWING);
                mAttributes.insert(ATTR_DRIVE_SPRING_TWIST);
                mAttributes.insert(ATTR_DRIVE_SPRING_SLERP);
                mAttributes.insert(ATTR_BREAKABLE_FORCE);
                mAttributes.insert(ATTR_MAX_FORCE);
                mAttributes.insert(ATTR_BREAKABLE_TORQUE);
                mAttributes.insert(ATTR_MAX_TORQUE);
                mAttributes.insert(ATTR_REVERSE);
                mAttributes.insert(ATTR_PROJECTION_MODE);
                mAttributes.insert(ATTR_PROJECTION_DISTANCE);
                mAttributes.insert(ATTR_PROJECTION_ANGLE);
                mAttributes.insert(ATTR_ANGULAR_DRIVE_MODE);
            }
            return mAttributes;
        }

    private:
        static std::set<MString, MStringComp> mAttributes;
    };
    std::set<MString, MStringComp> RigidConstraintTechnique::mAttributes;

    class RigidConstraintExtra : public Element
    {
    public:
        RigidConstraintExtra(PhysXExporter& exporter, const MObject & rigidConstraint)
            : Element(exporter, CSWC::CSW_ELEMENT_EXTRA)
        {
            exportTechnique(rigidConstraint, PhysXExporter::GetProfile());
            exportTechnique(rigidConstraint, PhysXExporter::GetProfileXML());
        }

    private:
        void exportTechnique(const MObject& rigidConstraint, const String& profile)
        {
            RigidConstraintTechnique e(getPhysXExporter(), rigidConstraint, profile);
        }
    };

    class RigidConstraint : public Element
    {
    public:
        RigidConstraint(PhysXExporter& exporter, const MObject & rigidConstraint, const String & sid, const String & name = "")
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_CONSTRAINT)
        {
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
            if (name.length() > 0) {
                getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_NAME, name);
            }

            exportRefAttachment(rigidConstraint);
            exportAttachment(rigidConstraint);
            exportTechniqueCommon(rigidConstraint);
            exportExtra(rigidConstraint);
        }

    private:
        void exportRefAttachment(const MObject & rigidConstraint)
        {
            MObject rigidBody;
            PhysXExporter::GetPluggedObject(rigidConstraint, ATTR_RIGID_BODY_1, rigidBody);

            URI rigidBodyURI;
            if (rigidBody.isNull())
            {
                rigidBodyURI.set("NULL");
            }
            else
            {
                MDagPath rigidBodyDagPath;
                MDagPath::getAPathTo(rigidBody, rigidBodyDagPath);

                String rigidBodyId = getPhysXExporter().generateColladaId(rigidBodyDagPath);
                rigidBodyURI = getPhysXExporter().getDocumentExporter().getVisualSceneExporter()->getSceneElementURI(rigidBodyDagPath, rigidBodyId);
            }

            RefAttachment e(getPhysXExporter(), rigidConstraint, rigidBodyURI);
        }

        void exportAttachment(const MObject & rigidConstraint)
        {
            MObject rigidBody;
            PhysXExporter::GetPluggedObject(rigidConstraint, ATTR_RIGID_BODY_2, rigidBody);

            MDagPath rigidBodyDagPath;
            MDagPath::getAPathTo(rigidBody, rigidBodyDagPath);

            String rigidBodyId = getPhysXExporter().generateColladaId(rigidBodyDagPath);
            URI rigidBodyURI = getPhysXExporter().getDocumentExporter().getVisualSceneExporter()->getSceneElementURI(rigidBodyDagPath, rigidBodyId);

            Attachment e(getPhysXExporter(), rigidConstraint, rigidBodyURI);
        }

        void exportTechniqueCommon(const MObject & rigidConstraint)
        {
            RigidConstraintTechniqueCommon e(getPhysXExporter(), rigidConstraint);
        }

        void exportExtra(const MObject & rigidConstraint)
        {
            RigidConstraintExtra e(getPhysXExporter(), rigidConstraint);
        }
    };

    class AngularVelocity : public Element
    {
    public:
        AngularVelocity(PhysXExporter & exporter, const MVector & velocity)
            : Element(exporter, CSWC::CSW_ELEMENT_ANGULAR_VELOCITY)
        {
            getStreamWriter().appendValues(velocity.x, velocity.y, velocity.z);
        }
    };

    class Velocity : public Element
    {
    public:
        Velocity(PhysXExporter & exporter, const MVector & velocity)
            : Element(exporter, CSWC::CSW_ELEMENT_VELOCITY)
        {
            getStreamWriter().appendValues(velocity.x, velocity.y, velocity.z);
        }
    };

    class InstanceRigidBodyTechniqueCommon : public Element
    {
    public:
        InstanceRigidBodyTechniqueCommon(PhysXExporter& exporter, const MVector & angularVelocity, const MVector& velocity)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE_COMMON)
        {
            exportAngularVelocity(angularVelocity);
            exportVelocity(velocity);

            // Don't export other elements, use rigid_body's ones.
        }

    private:
        void exportAngularVelocity(const MVector& angularVelocity)
        {
            if (angularVelocity != MVector::zero)
            {
                AngularVelocity e(getPhysXExporter(), angularVelocity);
            }
        }

        void exportVelocity(const MVector& velocity)
        {
            if (velocity != MVector::zero)
            {
                Velocity e(getPhysXExporter(), velocity);
            }
        }
    };

    class InstanceRigidBody : public Element
    {
    public:
        InstanceRigidBody(PhysXExporter& exporter, const MObject & rigidBody, const String& instanceRigidBodySID, const String & rigidBodySID, const URI & targetURI)
            : Element(exporter, CSWC::CSW_ELEMENT_INSTANCE_RIGID_BODY)
        {
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_SID, instanceRigidBodySID);
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_BODY, rigidBodySID);
            getStreamWriter().appendURIAttribute(CSWC::CSW_ATTRIBUTE_TARGET, targetURI);

            MVector initialSpin = MVector::zero;
            DagHelper::getPlugValue(rigidBody, ATTR_INITIAL_SPIN, initialSpin);
            initialSpin.x = COLLADABU::Math::Utils::radToDeg(initialSpin.x);
            initialSpin.y = COLLADABU::Math::Utils::radToDeg(initialSpin.y);
            initialSpin.z = COLLADABU::Math::Utils::radToDeg(initialSpin.z);

            MVector initialVelocity = MVector::zero;
            DagHelper::getPlugValue(rigidBody, ATTR_INITIAL_VELOCITY, initialVelocity);
            initialVelocity.x = MDistance::internalToUI(initialVelocity.x);
            initialVelocity.y = MDistance::internalToUI(initialVelocity.y);
            initialVelocity.z = MDistance::internalToUI(initialVelocity.z);

            exportTechniqueCommon(initialSpin, initialVelocity);
        }

    private:
        void exportTechniqueCommon(const MVector& angularVelocity, const MVector& velocity)
        {
            if (angularVelocity != MVector::zero ||
                velocity != MVector::zero)
            {
                InstanceRigidBodyTechniqueCommon e(getPhysXExporter(), angularVelocity, velocity);
            }
        }
    };

    class InstanceRigidConstraint : public Element
    {
    public:
        InstanceRigidConstraint(PhysXExporter & exporter, const String& instanceConstraintSid, const String & constraintSid)
            : Element(exporter, CSWC::CSW_ELEMENT_INSTANCE_RIGID_CONSTRAINT)
        {
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_SID, instanceConstraintSid);
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_CONSTRAINT, constraintSid);
        }
    };

    class InstancePhysicsModel : public Element
    {
    public:
        InstancePhysicsModel(PhysXExporter& exporter, const String& sid, const URI& uri)
            : Element(exporter, CSWC::CSW_ELEMENT_INSTANCE_PHYSICS_MODEL)
        {
            if (!sid.empty()) {
                getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
            }
            getStreamWriter().appendURIAttribute(CSWC::CSW_ATTRIBUTE_URL, uri);

            exportInstanceRigidBodies();
            exportInstanceRigidConstraints();
        }

    private:
        class RigidBodyParser
        {
        public:
            RigidBodyParser(PhysXExporter & exporter)
            : mPhysXExporter(exporter)
            , mInstanceRigidBodyIndex(0)
            {}
            
            bool operator()(SceneElement & element)
            {
                if (element.getType() == SceneElement::PHYSX_RIGID_BODY &&
                    element.getIsLocal())
                {
                    const MObject & rigidBody = element.getNode();
                    
                    MObject target;
                    mPhysXExporter.getRigidBodyTarget(rigidBody, target);
                    MDagPath targetDagPath;
                    MDagPath::getAPathTo(target, targetDagPath);
                    SceneElement* targetElement = mPhysXExporter.getDocumentExporter().getSceneGraph()->findElement(targetDagPath);
                    if (targetElement)
                    {
                        String rigidBodySid = mPhysXExporter.generateColladaId(element.getPath());
                        std::stringstream s;
                        s << "_" << mInstanceRigidBodyIndex++;
                        String instanceRigidBodySid = rigidBodySid + s.str();
                        URI targetURI = mPhysXExporter.getDocumentExporter().getVisualSceneExporter()->getSceneElementURI(targetElement);
                        InstanceRigidBody e(mPhysXExporter, rigidBody, instanceRigidBodySid, rigidBodySid, targetURI);
                    }
                }
                return true;
            }
            
        private:
            PhysXExporter & mPhysXExporter;
            int mInstanceRigidBodyIndex;
        };
        
        void exportInstanceRigidBodies()
        {
            PhysXExporter& exporter = getPhysXExporter();

            // Export ground plane if enabled
            MObject rigidSolver;
            if (exporter.getRigidSolver(rigidSolver))
            {
                String name = GROUND_PLANE_NAME;
                String sid = name;

                bool useGroundPlane = false;
                DagHelper::getPlugValue(rigidSolver, ATTR_USE_GROUND_PLANE, useGroundPlane);
                PhysXXML::PxRigidStatic* groundPlane = exporter.findPxRigidStatic(name);
                if (useGroundPlane && groundPlane)
                {
                    // Can't use Element class since ground plane has no associated MObject.
                    // So export everything manually...

                    StreamWriter& sw = getStreamWriter();
                    sw.openElement(CSWC::CSW_ELEMENT_INSTANCE_RIGID_BODY);
                    sw.appendAttribute(CSWC::CSW_ATTRIBUTE_SID, name);
                    sw.appendAttribute(CSWC::CSW_ATTRIBUTE_BODY, name);
                    // No target
                    sw.appendAttribute(CSWC::CSW_ATTRIBUTE_TARGET, "#");
                    sw.closeElement();
                }
            }

            RigidBodyParser rigidBodyParser(exporter);
            exporter.parseSceneElements(rigidBodyParser);
        }

        class RigidConstraintParser
        {
        public:
            RigidConstraintParser(PhysXExporter & exporter)
            : mPhysXExporter(exporter)
            , mInstanceRigidConstraintIndex(0)
            {}
            
            bool operator()(SceneElement & element)
            {
                if (element.getType() == SceneElement::PHYSX_RIGID_CONSTRAINT &&
                    element.getIsLocal())
                {
                    const MObject & rigidConstraint = element.getNode();
                    
                    String rigidConstraintSid = mPhysXExporter.generateColladaId(element.getPath());
                    std::stringstream s;
                    s << "_" << mInstanceRigidConstraintIndex++;
                    String instanceRigidConstraintSid = rigidConstraintSid + s.str();
                    InstanceRigidConstraint e(mPhysXExporter, instanceRigidConstraintSid, rigidConstraintSid);
                }
                return true;
            }
            
        private:
            PhysXExporter & mPhysXExporter;
            int mInstanceRigidConstraintIndex;
        };
        
        void exportInstanceRigidConstraints()
        {
            RigidConstraintParser rigidConstraintParser(getPhysXExporter());
            getPhysXExporter().parseSceneElements(rigidConstraintParser);
        }
    };

    class PhysicsModel : public Element
    {
    public:
        PhysicsModel(PhysXExporter& exporter, const String & id)
            : Element(exporter, CSWC::CSW_ELEMENT_PHYSICS_MODEL)
        {
            if (!id.empty()) {
                getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_ID, id);
            }
            exportRigidBodies();
            exportRigidConstraints();
            //exportInstancePhysicsModels();
        }

    private:
        class RigidBodyParser
        {
        public:
            RigidBodyParser(PhysXExporter & exporter)
            : mPhysXExporter(exporter)
            {}
            
            bool operator()(SceneElement & element)
            {
                if (element.getType() == SceneElement::PHYSX_RIGID_BODY &&
                    element.getIsLocal())
                {
                    String rigidBodySid = mPhysXExporter.generateColladaId(element.getPath());
                    String rigidBodyName = mPhysXExporter.generateColladaName(element.getPath());
                    
                    const MObject & rigidBody = element.getNode();
                    
                    RigidBody e(mPhysXExporter, rigidBody, rigidBodySid, rigidBodyName);
                }
                return true;
            }
            
        private:
            PhysXExporter & mPhysXExporter;
        };
        
        void exportRigidBodies()
        {
            PhysXExporter& exporter = getPhysXExporter();

            // Export ground plane if enabled
            MObject rigidSolver;
            if (exporter.getRigidSolver(rigidSolver))
            {
                String name = GROUND_PLANE_NAME;
                String sid = name;

                bool useGroundPlane = false;
                DagHelper::getPlugValue(rigidSolver, ATTR_USE_GROUND_PLANE, useGroundPlane);
                PhysXXML::PxRigidStatic* groundPlane = exporter.findPxRigidStatic(name);
                if (useGroundPlane && groundPlane)
                {
                    // Can't use Element class since ground plane has no associated MObject.
                    // So export everything manually...

                    StreamWriter& sw = getStreamWriter();
                    sw.openElement(CSWC::CSW_ELEMENT_RIGID_BODY);
                    sw.appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
                    sw.appendAttribute(CSWC::CSW_ATTRIBUTE_NAME, name);
                    {
                        sw.openElement(CSWC::CSW_ELEMENT_TECHNIQUE_COMMON);
                        {
                            sw.openElement(CSWC::CSW_ELEMENT_RIGID_BODY_DYNAMIC);
                            sw.appendValues(false);
                            sw.closeElement();

                            PhysXXML::PxMaterial* mat = exporter.findPxMaterial(groundPlane->shapes.shapes[0].materials.materialRef.materialRef);
                            if (mat)
                            {
                                sw.openElement(CSWC::CSW_ELEMENT_PHYSICS_MATERIAL);
                                sw.appendAttribute(CSWC::CSW_ATTRIBUTE_ID, name + "_material");
                                {
                                    sw.openElement(CSWC::CSW_ELEMENT_TECHNIQUE_COMMON);
                                    {
                                        sw.openElement(CSWC::CSW_ELEMENT_RESTITUTION);
                                        sw.appendValues(mat->restitution.restitution);
                                        sw.closeElement();

                                        sw.openElement(CSWC::CSW_ELEMENT_DYNAMIC_FRICTION);
                                        sw.appendValues(mat->dynamicFriction.dynamicFriction);
                                        sw.closeElement();

                                        sw.openElement(CSWC::CSW_ELEMENT_STATIC_FRICTION);
                                        sw.appendValues(mat->staticFriction.staticFriction);
                                        sw.closeElement();
                                    }
                                    sw.closeElement();

                                    sw.openElement(CSWC::CSW_ELEMENT_EXTRA);
                                    {
                                        sw.openElement(CSWC::CSW_ELEMENT_TECHNIQUE);
                                        sw.appendAttribute(CSWC::CSW_ATTRIBUTE_PROFILE, PhysXExporter::GetProfileXML());
                                        {
                                            mat->exportElement(sw);
                                        }
                                        sw.closeElement();
                                    }
                                    sw.closeElement();
                                }
                                sw.closeElement();
                            }

                            sw.openElement(CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE);
                            {
                                PhysXXML::PxShape& shape = groundPlane->shapes.shapes[0];

                                sw.openElement(CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_PLANE);
                                {
                                    double groundPlanePosition = 0.0f;
                                    DagHelper::getPlugValue(rigidSolver, ATTR_GROUND_PLANE_POSITION, groundPlanePosition);
                                    groundPlanePosition = MDistance::internalToUI(groundPlanePosition);

                                    // Plane equation
                                    double a = 0.0f;
                                    double b = 1.0f;
                                    double c = 0.0f;
                                    double d = -groundPlanePosition;

                                    sw.openElement(CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_PLANE_EQUATION);
                                    sw.appendValues(a, b, c, d);
                                    sw.closeElement();
                                    
                                }
                                sw.closeElement();

                                sw.openElement(CSWC::CSW_ELEMENT_EXTRA);
                                {
                                    sw.openElement(CSWC::CSW_ELEMENT_TECHNIQUE);
                                    sw.appendAttribute(CSWC::CSW_ATTRIBUTE_PROFILE, PhysXExporter::GetProfileXML());
                                    {
                                        shape.exportElement(sw);
                                    }
                                    sw.closeElement();
                                }
                                sw.closeElement();
                            }
                            sw.closeElement();
                        }
                        sw.closeElement();

                        sw.openElement(CSWC::CSW_ELEMENT_EXTRA);
                        {
                            sw.openElement(CSWC::CSW_ELEMENT_TECHNIQUE);
                            sw.appendAttribute(CSWC::CSW_ATTRIBUTE_PROFILE, PhysXExporter::GetProfileXML());
                            {
                                groundPlane->exportElement(sw);
                            }
                            sw.closeElement();
                        }
                        sw.closeElement();
                    }
                    sw.closeElement();
                }
            }

            // Export the other rigid bodies
            RigidBodyParser rigidBodyParser(exporter);
            exporter.parseSceneElements(rigidBodyParser);
        }

        class RigidConstraintParser
        {
        public:
            RigidConstraintParser(PhysXExporter & exporter)
            : mPhysXExporter(exporter)
            {}
            
            bool operator()(SceneElement & element)
            {
                if (element.getType() == SceneElement::PHYSX_RIGID_CONSTRAINT &&
                    element.getIsLocal())
                {
                    String rigidConstraintSid = mPhysXExporter.generateColladaId(element.getPath());
                    String rigidConstraintName = mPhysXExporter.generateColladaName(element.getPath());
                    
                    const MObject & rigidConstraint = element.getNode();
                    
                    RigidConstraint e(mPhysXExporter, rigidConstraint, rigidConstraintSid, rigidConstraintName);
                }
                return true;
            }
            
        private:
            PhysXExporter & mPhysXExporter;
        };
        
        void exportRigidConstraints()
        {
            RigidConstraintParser rigidConstraintParser(getPhysXExporter());
            getPhysXExporter().parseSceneElements(rigidConstraintParser);
        }
    };

    class LibraryPhysicsModels : public Element
    {
    public:
        LibraryPhysicsModels(PhysXExporter& exporter)
            : Element(exporter, CSWC::CSW_ELEMENT_LIBRARY_PHYSICS_MODELS)
        {
            PhysicsModel e(exporter, PhysXExporter::GetDefaultPhysicsModelId());
        }
    };

    class Gravity : public Element
    {
    public:
        Gravity(PhysXExporter & exporter, const MVector & gravity)
            : Element(exporter, CSWC::CSW_ELEMENT_GRAVITY)
        {
            getStreamWriter().appendValues(gravity.x, gravity.y, gravity.z);
        }
    };

    class PhysicsSceneTechniqueCommon : public Element
    {
    public:
        PhysicsSceneTechniqueCommon(PhysXExporter & exporter)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE_COMMON)
        {
            MObject rigidSolver;
            if (exporter.getRigidSolver(rigidSolver))
            {
                exportGravity(rigidSolver);
                exportTimeStep(rigidSolver);
            }
        }

    private:
        void exportGravity(const MObject & rigidSolver)
        {
            bool gravityEnabled = false;
            DagHelper::getPlugValue(rigidSolver, ATTR_GRAVITY, gravityEnabled);
            if (gravityEnabled)
            {
                double gravityMagnitude = 9.18;
                DagHelper::getPlugValue(rigidSolver, ATTR_GRAVITY_MAGNITUDE, gravityMagnitude);

                MVector gravityDirection(0.0, -1.0, 0.0);
                DagHelper::getPlugValue(rigidSolver, ATTR_GRAVITY_DIRECTION, gravityDirection);
                
                gravityDirection.x = MDistance::internalToUI(gravityDirection.x);
                gravityDirection.y = MDistance::internalToUI(gravityDirection.y);
                gravityDirection.z = MDistance::internalToUI(gravityDirection.z);

                Gravity e(getPhysXExporter(), gravityDirection * gravityMagnitude);
            }
        }

        void exportTimeStep(const MObject & rigidSolver)
        {
            
        }
    };

    class PhysicsScene : public Element
    {
    public:
        PhysicsScene(PhysXExporter& exporter, const String & id)
            : Element(exporter, CSWC::CSW_ELEMENT_PHYSICS_SCENE)
        {
            if (!id.empty()) {
                getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_ID, id);
            }
            exportInstancePhysicsModels();
            exportTechniqueCommon();
        }

    private:
        void exportInstancePhysicsModels()
        {
            // Local physics model
            if (getPhysXExporter().sceneHas(SceneElement::PHYSX_RIGID_BODY, PhysXExporter::Local) ||
                getPhysXExporter().sceneHas(SceneElement::PHYSX_RIGID_CONSTRAINT, PhysXExporter::Local))
            {
                String physicsModelId = PhysXExporter::GetDefaultPhysicsModelId();
                
                URI uri;
                uri.set("");
                uri.setFragment(physicsModelId);

                InstancePhysicsModel e(getPhysXExporter(), PhysXExporter::GetDefaultInstancePhysicsModelSid(), uri);
            }
        }

        void exportTechniqueCommon()
        {
            PhysicsSceneTechniqueCommon e(getPhysXExporter());
        }
    };

    class LibraryPhysicsScenes : public Element
    {
    public:
        LibraryPhysicsScenes(PhysXExporter& exporter)
            : Element(exporter, CSWC::CSW_ELEMENT_LIBRARY_PHYSICS_SCENES)
        {
            PhysicsScene e(exporter, PhysXExporter::GetDefaultPhysicsSceneId());
        }
    };

    class Translate : public Element
    {
    public:
        Translate(PhysXExporter& exporter, const MVector & translation, const String & sid = "")
            : Element(exporter, CSWC::CSW_ELEMENT_TRANSLATE)
        {
            if (sid.length() > 0)
                getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
            getStreamWriter().appendValues(translation.x, translation.y, translation.z);
        }
    };

    class Rotate : public Element
    {
    public:
        Rotate(PhysXExporter& exporter, const MVector & axis, double angle, const String & sid = "")
            : Element(exporter, CSWC::CSW_ELEMENT_ROTATE)
        {
            if (sid.length() > 0) {
                getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
            }
            getStreamWriter().appendValues(axis.x, axis.y, axis.z, angle);
        }
    };

    String PhysXExporter::mDefaultPhysicsModelId = "collada_physics_model";
    String PhysXExporter::mDefaultPhysicsSceneId = "collada_physics_scene";
    String PhysXExporter::mDefaultInstancePhysicsModelSid = "instancePhysicsModel";
    String PhysXExporter::mProfile = "OpenCOLLADAMayaPhysX";
    String PhysXExporter::mProfileXML = "OpenCOLLADAMayaPhysXXML";

    PhysXExporter::PhysXExporter(StreamWriter& streamWriter, DocumentExporter& documentExporter)
        : mStreamWriter(streamWriter)
        , mDocumentExporter(documentExporter)
    {}
    
    class RigidBodyParser
    {
    public:
        RigidBodyParser(const SceneElement & meshElement)
        : mMeshElement(meshElement)
        , mNeedsConvexHullOfMeshElement(false)
        {}
        
        bool operator()(SceneElement & element)
        {
            if (element.getType() == SceneElement::PHYSX_RIGID_BODY)
            {
                std::vector<MObject> shapes;
                PhysXExporter::GetRigidBodyShapes(element.getNode(), shapes);
                
                for (size_t i = 0; i < shapes.size(); ++i)
                {
                    const MObject & shape = shapes[i];
                    int dummy = 0;
                    MString shapeType;
                    DagHelper::getPlugValue(shape, ATTR_SHAPE_TYPE, dummy, shapeType);
                    if (shapeType == SHAPE_TYPE_CONVEX_HULL)
                    {
                        MObject connectedMesh;
                        PhysXShape::GetConnectedInMesh(shape, connectedMesh);
                        
                        if (mMeshElement.getNode() == connectedMesh ||
                            mMeshElement.getNode() == shape)
                        {
                            mNeedsConvexHullOfMeshElement = true;
                            mShape = shape;
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        
        bool needsConvexHullOfMeshElement() const
        {
            return mNeedsConvexHullOfMeshElement;
        }

        const MObject& getShape() const
        {
            return mShape;
        }
        
    private:
        const SceneElement & mMeshElement;
        bool mNeedsConvexHullOfMeshElement;
        MObject mShape;
    };

    bool PhysXExporter::needsConvexHullOf(const SceneElement & meshElement, MObject& shape)
    {
        if (!ExportOptions::exportPhysics())
            return false;
        
        RigidBodyParser parser(meshElement);
        parseSceneElements(parser);
        shape = parser.getShape();
        return parser.needsConvexHullOfMeshElement();
    }

    class AutoDeleteFile
    {
    public:
        AutoDeleteFile(const String& filePath)
            : mFilePath(filePath)
        {}

        ~AutoDeleteFile()
        {
            if (!mFilePath.empty()) {
                COLLADABU::Utils::deleteFile(mFilePath);
            }
        }

    private:
        String mFilePath;
    };

    class AutoXmlFreeDoc
    {
    public:
        AutoXmlFreeDoc(xmlDocPtr xml)
            : mXml(xml)
        {}

        ~AutoXmlFreeDoc()
        {
            if (mXml) {
                xmlFreeDoc(mXml);
            }
        }

    private:
        xmlDocPtr mXml;
    };

    class AutoRestorePhysXExportOptions
    {
    public:
        AutoRestorePhysXExportOptions()
            : mError(false)
        {
            mOptions.push_back(Option("apexClothingExport_APBs", Integer));
            mOptions.push_back(Option("validatePhysXSceneBeforeExport", Integer));
            mOptions.push_back(Option("PhysXExport_useFolderName", Integer));
            mOptions.push_back(Option("apexExport_RemoveNamespaceForJoint", Integer));
            mOptions.push_back(Option("apexClothingExport_VisibleOnly", Integer));
            mOptions.push_back(Option("PhysXExport_exportPxProjFile", Integer));
            mOptions.push_back(Option("PhysXExport_exportPhysX", Integer));
            mOptions.push_back(Option("PhysXExport_outputUnit", String));
            mOptions.push_back(Option("PhysXExport_customScaling", Integer));
            mOptions.push_back(Option("PhysXExport_outputScale", Double));

            for (size_t i = 0; i < mOptions.size(); ++i) {
                switch (mOptions[i].type)
                {
                case Integer:
                {
                    int oldValue = 0;
                    MStatus status = MGlobal::executeCommand("optionVar -q \"" + mOptions[i].name + "\"", oldValue);
                    if (!status) mError |= true;
                    MString oldValueStr("");
                    oldValueStr += oldValue;
                    mOldValues.push_back(oldValueStr);
                    break;
                }
                case Double:
                {
                    double oldValue = 0.0;
                    MStatus status = MGlobal::executeCommand("optionVar -q \"" + mOptions[i].name + "\"", oldValue);
                    if (!status) mError |= true;
                    MString oldValueStr("");
                    oldValueStr += oldValue;
                    mOldValues.push_back(oldValueStr);
                    break;
                }
                case String:
                {
                    MString oldValue;
                    MStatus status = MGlobal::executeCommand("optionVar -q \"" + mOptions[i].name + "\"", oldValue);
                    if (!status) mError |= true;
                    mOldValues.push_back(oldValue);
                    break;
                }
                }
            }
        }

        ~AutoRestorePhysXExportOptions()
        {
            for (size_t i = 0; i < mOptions.size(); ++i) {
                MString command = "optionVar -";
                switch (mOptions[i].type)
                {
                case Integer:   command += "i"; break;
                case Double:     command += "f"; break;
                case String:    command += "s"; break;
                }
                MGlobal::executeCommand(command + "v \"" + mOptions[i].name + "\" " + mOldValues[i]);
            }
        }

        bool error() const
        {
            return mError;
        }

    private:
        enum OptionType
        {
            Integer,
            Double,
            String
        };

        struct Option
        {
            Option(const MString& name_, OptionType type_)
                : name(name_)
                , type(type_)
            {}

            MString name;
            OptionType type;
        };
        std::vector<Option> mOptions;
        std::vector<MString> mOldValues;
        bool mError;
    };

    bool PhysXExporter::generatePhysXXML()
    {
        MStatus status;

        // Backup export options
        AutoRestorePhysXExportOptions autoRestorePhysXExportOptions;

        // PhysX internal data is in centimeters and we need to export to UI unit.
        MDistance unitDistance = MDistance(1.0, MDistance::uiUnit());
        double asCentimeters = unitDistance.asCentimeters();
        double centimetersToUIUnit = 1.0 / asCentimeters;
        MString centimetersToUIUnitStr = "";
        centimetersToUIUnitStr += centimetersToUIUnit;

        // Set export options
        status = MGlobal::executeCommand("optionVar -iv \"apexClothingExport_APBs\" 2");
        if (!status) return false;
        status = MGlobal::executeCommand("optionVar -iv \"validatePhysXSceneBeforeExport\" 0");
        if (!status) return false;
        status = MGlobal::executeCommand("optionVar -iv \"PhysXExport_useFolderName\" 0");
        if (!status) return false;
        status = MGlobal::executeCommand("optionVar -iv \"apexExport_RemoveNamespaceForJoint\" 0");
        if (!status) return false;
        status = MGlobal::executeCommand("optionVar -iv \"apexClothingExport_VisibleOnly\" 0");
        if (!status) return false;
        status = MGlobal::executeCommand("optionVar -iv \"PhysXExport_exportPxProjFile\" 0");
        if (!status) return false;
        status = MGlobal::executeCommand("optionVar -iv \"PhysXExport_exportPhysX\" 1");
        if (!status) return false;
        status = MGlobal::executeCommand("optionVar -sv \"PhysXExport_outputUnit\" \"meter\""); // Has no effect
        if (!status) return false;
        status = MGlobal::executeCommand("optionVar -iv \"PhysXExport_customScaling\" true");
        if (!status) return false;
        status = MGlobal::executeCommand("optionVar -fv \"PhysXExport_outputScale\" " + centimetersToUIUnitStr);
        if (!status) return false;

        String filePath = mDocumentExporter.getFilename();
        std::stringstream exportCommand;
        exportCommand << "file -force -options \"none=0;\" -type \"PhysX\" -pr";
        if (mDocumentExporter.getSceneGraph()->getExportSelectedOnly()) {
            exportCommand << " -es";
        }
        else {
            exportCommand << " -ea";
        }

        // Generate temp file name
        size_t extPos = filePath.find_last_of('.');
        String filePathNoExt = filePath.substr(0, extPos);
        String tempFilePath = filePathNoExt + ".xml";
        std::ifstream tempFile(tempFilePath.c_str());
        int index = 0;
        while (tempFile.is_open()) {
            std::stringstream s;
            s << index++;
            tempFilePath = filePathNoExt + s.str() + ".xml";
            tempFile.close();
            tempFile.open(tempFilePath.c_str());
        }

        // Set .pxproj as extension but plugin will export a .xml file
        String pxProjPath = tempFilePath;
        extPos = pxProjPath.find_last_of('.');
        pxProjPath.replace(extPos, pxProjPath.length() - extPos, ".pxproj");

        exportCommand << " \"" << pxProjPath << "\";";
        status = MGlobal::executeCommand(exportCommand.str().c_str());
        if (!status) return false;

        // delete .xml file when we are done with it.
        AutoDeleteFile autoDeleteFile(tempFilePath);

        // Read .xml file

        // Is this necessary?
        LIBXML_TEST_VERSION;

        std::ifstream file(tempFilePath.c_str());
        if (!file.is_open()) {
            return false;
        }

        std::stringstream fileContentStream;
        fileContentStream << file.rdbuf();
        std::string fileContent(fileContentStream.str());

        int length = static_cast<int>(fileContent.length());
        xmlDocPtr xml = xmlReadMemory(fileContent.c_str(), length, "noname.xml", NULL, 0);
        if (xml == NULL) {
            return false;
        }

        AutoXmlFreeDoc autoXmlFreeDoc(xml);

        // Init our PhysX xml tree
        mPhysXDoc = xml;

        // Check for duplicated names
        if (!mPhysXDoc->validate()) {
            MGlobal::displayError("Error while exporting PhysX scene: duplicated names found.");
            return false;
        }

        xmlCleanupParser();

        return true;
    }

    bool PhysXExporter::exportPhysicsLibraries()
    {
        // Check PhysX plugin version.
        MObject pluginObject = MFnPlugin::findPlugin("physx");
        
        if (pluginObject.isNull()) {
            return false;
        }

        MFnPlugin fnPlugin(pluginObject);

        // Export to .xml format first using PhysX plugin exporter.
        // Produced file contains information not accessible with Maya API.
        if (!mPhysXDoc) {
            MGlobal::displayError("Can't generate PhysX XML data. PhysX will not be exported.");
            return false;
        }

        bool hasPhysicsScene = false;

        if (!ExportOptions::exportPhysics()) {
            return hasPhysicsScene;
        }

        if (sceneHas(SceneElement::PHYSX_RIGID_BODY, Local) ||
            sceneHas(SceneElement::PHYSX_RIGID_CONSTRAINT, Local)) {
            LibraryPhysicsModels(*this);
        }
        
        if (sceneHas(SceneElement::PHYSX_RIGID_SOLVER, Local)) {
            hasPhysicsScene = true;
            LibraryPhysicsScenes(*this);
        }

        return hasPhysicsScene;
    }

    StreamWriter& PhysXExporter::getStreamWriter()
    {
        return mStreamWriter;
    }

    DocumentExporter& PhysXExporter::getDocumentExporter()
    {
        return mDocumentExporter;
    }

    void PhysXExporter::exportTranslation(const MVector & translation, const String & sid)
    {
        if (!(COLLADABU::Math::Utils::equalsZero(translation.x, mDocumentExporter.getTolerance()) &&
            COLLADABU::Math::Utils::equalsZero(translation.y, mDocumentExporter.getTolerance()) &&
            COLLADABU::Math::Utils::equalsZero(translation.z, mDocumentExporter.getTolerance())))
        {
            // Convert from Maya internal unit (cm) to export unit
            MVector convertedTranslation;
            convertedTranslation.x = MDistance::internalToUI(translation.x);
            convertedTranslation.y = MDistance::internalToUI(translation.y);
            convertedTranslation.z = MDistance::internalToUI(translation.z);

            Translate(*this, convertedTranslation, sid);
        }
    }

    void PhysXExporter::exportRotation(const MEulerRotation & rotation, const String & sid)
    {
        RotateHelper rotateHelper(rotation);
        const std::vector<std::vector<double> >& rotationMatrix = rotateHelper.getRotationMatrix();
        const std::vector<String>& rotationParameters = rotateHelper.getRotationParameters();

        // Go through the axes for the rotations.
        for (uint i = 0; i < 3; ++i)
        {
            if (!COLLADABU::Math::Utils::equalsZero(rotationMatrix[i][3], mDocumentExporter.getTolerance()))
            {
                exportRotate(MVector(
                    COLLADABU::Math::Utils::equalsZero(rotationMatrix[i][0], mDocumentExporter.getTolerance()) ? 0.0 : rotationMatrix[i][0],
                    COLLADABU::Math::Utils::equalsZero(rotationMatrix[i][1], mDocumentExporter.getTolerance()) ? 0.0 : rotationMatrix[i][1],
                    COLLADABU::Math::Utils::equalsZero(rotationMatrix[i][2], mDocumentExporter.getTolerance()) ? 0.0 : rotationMatrix[i][2]),
                    COLLADABU::Math::Utils::equalsZero(rotationMatrix[i][3], mDocumentExporter.getTolerance()) ? 0.0 : rotationMatrix[i][3],
                    sid + rotationParameters[i]
                    );
            }
        }
    }

    void PhysXExporter::exportAttributes(const MObject & object, const std::set<MString, MStringComp> & attributes)
    {
        AttributeExporter attributeExporter(*this, attributes);
        MFnDependencyNode fnDependencyNode(object);
        AttributeParser::parseAttributes(fnDependencyNode, attributeExporter);
    }

    void PhysXExporter::exportMaterialPhysXXML(const MObject& rigidBody)
    {
        PhysXXML::PxMaterial* pxMaterial = findPxMaterial(rigidBody);
        if (pxMaterial) {
            pxMaterial->exportElement(mStreamWriter);
        }
    }

    void PhysXExporter::exportShapePhysXXML(const MObject& rigidBody, const MObject& shape)
    {
        PhysXXML::PxShape* pxShape = findPxShape(rigidBody, shape);
        if (pxShape) {
            pxShape->exportElement(mStreamWriter);
        }
    }

    void PhysXExporter::exportRigidBodyPhysXXML(const MObject& rigidBody)
    {
        int dummy = 0;
        MString simulationType;
        DagHelper::getPlugValue(rigidBody, ATTR_SIMULATION_TYPE, dummy, simulationType);

        if (simulationType == SIMULATION_TYPE_STATIC) {
            PhysXXML::PxRigidStatic* pxRigidStatic = findPxRigidStatic(rigidBody);
            if (pxRigidStatic) {
                pxRigidStatic->exportElement(mStreamWriter);
            }
        }
        else {
            PhysXXML::PxRigidDynamic* pxRigidDynamic = findPxRigidDynamic(rigidBody);
            if (pxRigidDynamic) {
                pxRigidDynamic->exportElement(mStreamWriter);
            }
        }
    }

    void PhysXExporter::exportRigidConstraintPhysXXML(const MObject& rigidConstraint)
    {
        PhysXXML::PxD6Joint* pxConstraint = findPxD6Joint(rigidConstraint);
        if (pxConstraint) {
            pxConstraint->exportElement(mStreamWriter);
        }
    }

    void PhysXExporter::exportRotate(const MVector & axis, double angle, const String & sid)
    {
        Rotate(*this, axis, angle, sid);
    }

    bool PhysXExporter::sceneHas(SceneElement::Type type, PhysXExporter::Filter filter)
    {
        SceneGraph& sceneGraph = *mDocumentExporter.getSceneGraph();
        SceneElementsList& exportNodesTree = *sceneGraph.getExportNodesTree();

        // Parse all/selected DAG nodes
        for (size_t i = 0; i < exportNodesTree.size(); ++i)
        {
            SceneElement& sceneElement = *exportNodesTree[i];
            if (ElementHas(sceneElement, type, filter)) {
                return true;
            }
        }
        return false;
    }

    bool PhysXExporter::ElementHas(const SceneElement & element, SceneElement::Type type, PhysXExporter::Filter filter)
    {
        if (element.getType() == type) {
            switch (filter)
            {
            case All:
                return true;
            case Local:
                return element.getIsLocal();
            case Reference:
                return !element.getIsLocal();
            }
        }

        // Recursive call for all the child elements
        for (uint i = 0; i<element.getChildCount(); ++i)
        {
            const SceneElement& childElement = *element.getChild(i);
            if (ElementHas(childElement, type, filter)) {
                return true;
            }
        }
        return false;
    }

    String PhysXExporter::generateColladaId(const MDagPath & dagPath)
    {
        // Get the maya mesh id.
        String mayaId = mDocumentExporter.dagPathToColladaId(dagPath);

        // Generate a COLLADA id for the new object.
        String colladaId = findColladaId(mayaId);

        // Check, if the unique id for the current geometry is already generated.
        if (!colladaId.empty()) return colladaId;

        // Get the node of the current mesh
        colladaId = mDocumentExporter.dagPathToColladaName(dagPath);

        // Make the id unique and store it in a map.
        colladaId = mIdList.addId(colladaId);
        mMayaIdToColladaId[mayaId] = colladaId;

        return colladaId;
    }

    String PhysXExporter::generateColladaName(const MDagPath & dagPath)
    {
        return mDocumentExporter.dagPathToColladaName(dagPath);
    }

    const String& PhysXExporter::GetDefaultPhysicsModelId()
    {
        return mDefaultPhysicsModelId;
    }

    const String& PhysXExporter::GetDefaultPhysicsSceneId()
    {
        return mDefaultPhysicsSceneId;
    }

    const String& PhysXExporter::GetDefaultInstancePhysicsModelSid()
    {
        return mDefaultInstancePhysicsModelSid;
    }

    const String& PhysXExporter::GetProfile()
    {
        return mProfile;
    }

    const String& PhysXExporter::GetProfileXML()
    {
        return mProfileXML;
    }

    const String & PhysXExporter::findColladaId(const String & mayaId)
    {
        const StringToStringMap::const_iterator it = mMayaIdToColladaId.find(mayaId);
        if (it != mMayaIdToColladaId.end()) {
            return it->second;
        }
        return EMPTY_STRING;
    }

    void PhysXExporter::GetRigidBodyShapes(const MObject & rigidBody, std::vector<MObject> & shapes)
    {
        MFnDependencyNode rigidBodyNode(rigidBody);
        MPlug plug = rigidBodyNode.findPlug(ATTR_PHYSICS_SHAPES);
        uint numConnectedElements = plug.numConnectedElements();
        
        for (uint i = 0; i < numConnectedElements; ++i)
        {
            MPlug elementPlug = plug.connectionByPhysicalIndex(i);
            MPlugArray connections;
            if (elementPlug.connectedTo(connections, true, false))
            {
                shapes.push_back(connections[0].node());
            }
        }
    }

    // in kg
    double PhysXExporter::GetRigidBodyMass(const MObject & rigidBody)
    {
        int dummy = 0;
        MString overrideMassOrDensity;
        DagHelper::getPlugValue(rigidBody, ATTR_OVERRIDE_MASS_OR_DENSITY, dummy, overrideMassOrDensity);

        double mass = 0.0;
        if (overrideMassOrDensity == OVERRIDE_MASS_OR_DENSITY_MASS)
        {
            // Mass attribute is in kg
            DagHelper::getPlugValue(rigidBody, ATTR_MASS, mass);
        }
        else if (overrideMassOrDensity == OVERRIDE_MASS_OR_DENSITY_DENSITY)
        {
            // Density attribute is in g/cm3
            double density = 0.0;
            DagHelper::getPlugValue(rigidBody, ATTR_DENSITY, density);
            // Volume in cm3
            mass = density * GetRigidBodyVolume(rigidBody);
            // Convert g to kg
            mass /= 1000.0;
        }
        else //if (overrideMassOrDensity == OVERRIDE_MASS_OR_DENSITY_DISABLED)
        {
            std::vector<MObject> shapes;
            GetRigidBodyShapes(rigidBody, shapes);
            for (size_t i = 0; i < shapes.size(); ++i)
            {
                mass += GetShapeMass(shapes[i]);
            }
        }
        return mass;
    }

    // in kg
    double PhysXExporter::GetShapeMass(const MObject & shape)
    {
        int dummy = 0;
        MString useMassOrDensity;
        DagHelper::getPlugValue(shape, ATTR_USE_MASS_OR_DENSITY, dummy, useMassOrDensity);

        double mass = 0.0;
        if (useMassOrDensity == USE_MASS_OR_DENSITY_MASS)
        {
            // Mass in kg
            DagHelper::getPlugValue(shape, ATTR_MASS, mass);
        }
        else //if (useMassOrDensity == USE_MASS_OR_DENSITY_DENSITY)
        {
            // Density in g/cm3
            double density = 0.0;
            DagHelper::getPlugValue(shape, ATTR_DENSITY, density);
            mass = density * GetShapeVolume(shape);
            // Convert g to kg
            mass /= 1000.0;
        }

        return mass;
    }

    // cm3
    double PhysXExporter::GetRigidBodyVolume(const MObject & rigidBody)
    {
        std::vector<MObject> shapes;
        GetRigidBodyShapes(rigidBody, shapes);
        double volume = 0.0;
        for (size_t i = 0; i < shapes.size(); ++i)
        {
            volume += GetShapeVolume(shapes[i]);
        }
        return volume;
    }

    // cm3
    double PhysXExporter::GetShapeVolume(const MObject & shape)
    {
        int dummy = 0;
        MString shapeType;
        DagHelper::getPlugValue(shape, ATTR_SHAPE_TYPE, dummy, shapeType);
        
        double volume = 0.0;

        if (shapeType == SHAPE_TYPE_BOX)
        {
            MVector size = MVector::zero;
            DagHelper::getPlugValue(shape, ATTR_SIZE, size);
            volume = size.x * size.y * size.z;
        }
        else if (shapeType == SHAPE_TYPE_CAPSULE)
        {
            double radius = 0.0;
            double height = 0.0;
            DagHelper::getPlugValue(shape, ATTR_RADIUS, radius);
            DagHelper::getPlugValue(shape, ATTR_HEIGHT, height);
            volume = M_PI * radius * radius * (4.0 / 3.0 * radius + height);
        }
        else if (
            shapeType == SHAPE_TYPE_CLOTH_SPHERES ||
            shapeType == SHAPE_TYPE_SPHERE
            )
        {
            double radius = 0.0;
            DagHelper::getPlugValue(shape, ATTR_RADIUS, radius);
            volume = 4.0 / 3.0 * M_PI * radius * radius * radius;
        }
        else if (shapeType == SHAPE_TYPE_CONVEX_HULL)
        {
            // Get convex mesh (not connected mesh)
            MObject mesh;
            PhysXShape::GetInMesh(shape, mesh);

            // Parse triangles
            MItMeshPolygon itMeshPolygon(mesh);
            for (itMeshPolygon.reset(); !itMeshPolygon.isDone(); itMeshPolygon.next())
            {
                int numTriangles = 0;
                itMeshPolygon.numTriangles(numTriangles);
                for (int triangleIndex = 0; triangleIndex < numTriangles; ++triangleIndex)
                {
                    MPointArray vertexList;
                    MIntArray vertexIndexList;
                    itMeshPolygon.getTriangle(triangleIndex, vertexList, vertexIndexList);
                    
                    MPoint a, b, c;
                    a = vertexList[0];
                    b = vertexList[1];
                    c = vertexList[2];

                    MVector vab, vbc, vca;
                    vab = b - a;
                    vbc = c - b;
                    vca = a - c;
                    double ab, bc, ca;
                    ab = vab.length();
                    bc = vbc.length();
                    ca = vca.length();
                    // Use Heron's formula to calculate triangular pyramid signed volume
                    // base triangle perimeter
                    double p = 0.5 * (ab + bc + ca);
                    // base triangle area
                    double area = sqrt(p * (p-ab) * (p-bc) * (p-ca));
                    MVector vac;
                    vac = c - a;
                    // triangle plane normal
                    MVector n = vab ^ vac;
                    n.normalize();
                    // triangle plane equation constant
                    double d = -a.x*n.x - a.y*n.y - a.z*n.z;
                    // pyramid height
                    double h = d;
                    // pyramid volume
                    double subVolume = 1.0/3.0 * area * h;
                    subVolume *= -1;
                    // add to total volume
                    volume += subVolume;
                }
            }
        }
        else
        {
            MVector bbSize = MVector::zero;
            DagHelper::getPlugValue(shape, ATTR_BOUNDING_BOX_SIZE, bbSize);
            volume = bbSize.x * bbSize.y * bbSize.z;
        }

        return volume;
    }

    MStatus PhysXExporter::GetPluggedObject(const MObject & object, const MString & attribute, MObject & pluggedObject)
    {
        MStatus status;

        MFnDependencyNode node(object, &status);
        if (!status) return status;

        MPlug plug = node.findPlug(attribute, &status);
        if (!status) return status;

        MPlugArray plugArray;
        bool hasConnection = plug.connectedTo(plugArray, true, false, &status);
        if (!status) return status;
        if (hasConnection)
        {
            MPlug externalPlug = plugArray[0];
            bool externalPlugNull = externalPlug.isNull(&status);
            if (!status) return status;
            if (!externalPlugNull)
            {
                pluggedObject = externalPlug.node(&status);
                if (!status) return status;
            }
        }
        return MS::kSuccess;
    }

    MStatus PhysXExporter::getMeshURI(const MObject & mesh, URI & meshURI)
    {
        MStatus status;

        MFnDagNode meshDagNode(mesh, &status);
        if (!status) return status;

        MDagPath meshDagPath;
        status = meshDagNode.getPath(meshDagPath);
        if (!status) return status;

        String geometryId = mDocumentExporter.getGeometryExporter()->generateColladaMeshId(meshDagPath);
        meshURI = getDocumentExporter().getVisualSceneExporter()->getSceneElementURI(meshDagPath, geometryId);

        return status;
    }
}
