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
        int64_t i;
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
	MVector uiToInternal(const MVector & v)
	{
		return MVector(
			MDistance::uiToInternal(v.x),
			MDistance::uiToInternal(v.y),
			MDistance::uiToInternal(v.z));
	}

	MMatrix PxTransformToMMatrix(const MVector & t, const MQuaternion & r)
	{
		MTransformationMatrix tm;
		tm.setRotationQuaternion(r.x, r.y, r.z, r.w);
		tm.setTranslation(uiToInternal(t), MSpace::kTransform);
		return tm.asMatrix();
	}

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
		virtual bool onBeforePlug(MPlug & plug) override
		{
			MStatus status;

			MObject attr = plug.attribute(&status);
			if (!status) return false;

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

    const PhysXXML::PxMaterial* PhysXExporter::findPxMaterial(const MObject & rigidBody) const
    {
		std::map<MObject, const PhysXXML::PxMaterial*>::const_iterator it = mRigidBodyToPxMaterialMap.find(rigidBody);
		if (it != mRigidBodyToPxMaterialMap.end())
		{
			return it->second;
		}
		return NULL;
    }

	const PhysXXML::PxMaterial* PhysXExporter::findPxMaterial(uint64_t ref) const
    {
        return mPhysXDoc->findMaterial(ref);
    }

	const PhysXXML::PxMaterial* PhysXExporter::findPxMaterial(const PhysXXML::PxRigidBody & rigidBody) const
	{
		if (rigidBody.shapes.shapes.size() > 0)
		{
			return findPxMaterial(rigidBody.shapes.shapes[0].materials.materialRef.materialRef);
		}
		return NULL;
	}

	const PhysXXML::PxShape* PhysXExporter::findPxShape(const MObject & shape) const
	{
		std::map<MObject, const PhysXXML::PxShape*>::const_iterator it = mShapeToPxShapeMap.find(shape);
		if (it != mShapeToPxShapeMap.end())
		{
			return it->second;
		}
		return NULL;
	}

	const PhysXXML::PxRigidBody* PhysXExporter::findPxRigidBody(const MObject & rigidBody) const
	{
		std::map<MObject, const PhysXXML::PxRigidBody*>::const_iterator it = mRigidBodyToPxRigidBodyMap.find(rigidBody);
		if (it != mRigidBodyToPxRigidBodyMap.end())
		{
			return it->second;
		}
		return NULL;
	}

	const PhysXXML::PxRigidBody* PhysXExporter::findPxRigidBody(const String & name) const
	{
		return mPhysXDoc->findRigidBody(name);
	}

	const PhysXXML::PxRigidBody* PhysXExporter::findPxRigidBody(uint64_t id) const
	{
		return mPhysXDoc->findRigidBody(id);
	}

    const PhysXXML::PxD6Joint* PhysXExporter::findPxD6Joint(const MObject & rigidConstraint) const
    {
		std::map<MObject, const PhysXXML::PxD6Joint*>::const_iterator it = mConstraintToPxD6JointMap.find(rigidConstraint);
		if (it != mConstraintToPxD6JointMap.end())
		{
			return it->second;
		}
		return NULL;
    }

	const MObject & PhysXExporter::findMObject(const PhysXXML::PxRigidBody & rigidBody) const
	{
		std::map<const PhysXXML::PxRigidBody*, MObject>::const_iterator it = mPxRigidBodyToRigidBodyMap.find(&rigidBody);
		if (it != mPxRigidBodyToRigidBodyMap.end())
		{
			return it->second;
		}
		return MObject::kNullObj;
	}

	const MObject & PhysXExporter::findMObject(const PhysXXML::PxShape & shape) const
	{
		std::map<const PhysXXML::PxShape*, MObject>::const_iterator it = mPxShapeToShapeMap.find(&shape);
		if (it != mPxShapeToShapeMap.end())
		{
			return it->second;
		}
		return MObject::kNullObj;
	}

	const MObject & PhysXExporter::findMObject(const PhysXXML::PxD6Joint & joint) const
	{
		std::map<const PhysXXML::PxD6Joint*, MObject>::const_iterator it = mPxD6JointToConstraintMap.find(&joint);
		if (it != mPxD6JointToConstraintMap.end())
		{
			return it->second;
		}
		return MObject::kNullObj;
	}

	const MObject & PhysXExporter::getNodeRigidBody(const MObject& node) const
	{
		std::map<MObject, MObject>::const_iterator it = mTargetToRigidBodyMap.find(node);
		if (it != mTargetToRigidBodyMap.end())
		{
			return it->second;
		}
		return MObject::kNullObj;
	}

    void PhysXExporter::getShapeLocalPose(/*const MObject& rigidBody, */const MObject& shape, MMatrix& localPose) const
    {
        const PhysXXML::PxShape* pxShape = findPxShape(/*rigidBody, */shape);
        if (!pxShape)
            return;
		localPose = PxTransformToMMatrix(pxShape->localPose.translation, pxShape->localPose.rotation);
    }

	bool PhysXExporter::getShapeVertices(const MObject& shape, std::vector<PhysXXML::Point> & vertices, MString & meshId)
    {
		const PhysXXML::PxShape* pxShape = findPxShape(shape);
        if (pxShape == NULL) return false;

		if (pxShape->geometry.type == PhysXXML::Geometry::ConvexMesh)
        {
			if (PhysXXML::PxConvexMesh* convexMesh = mPhysXDoc->findConvexMesh(pxShape->geometry.convexMeshGeometry.convexMesh.convexMesh))
            {
                vertices = convexMesh->points.points;
                std::stringstream s;
                s << convexMesh->id.id;
                meshId = s.str().c_str();
                return true;
            }
        }
		else if (pxShape->geometry.type == PhysXXML::Geometry::TriangleMesh)
        {
			if (PhysXXML::PxTriangleMesh* triangleMesh = mPhysXDoc->findTriangleMesh(pxShape->geometry.triangleMeshGeometry.triangleMesh.triangleMesh))
            {
                vertices = triangleMesh->points.points;
                std::stringstream s;
                s << triangleMesh->id.id;
                meshId = s.str().c_str();
                return true;
            }
        }
        return false;
    }

	bool PhysXExporter::getShapeTriangles(const MObject& shape, std::vector<PhysXXML::Triangle> & triangles)
    {
		const PhysXXML::PxShape* pxShape = findPxShape(shape);
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
		if (const PhysXXML::PxRigidBody* pxRigidBody = findPxRigidBody(rigidBody))
		{
			globalPose = PxTransformToMMatrix(pxRigidBody->globalPose.translation, pxRigidBody->globalPose.rotation);
		}
    }
        
    const MObject & PhysXExporter::getRigidSolver() const
    {
		return mRigidSolver;
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
		MassFrame(PhysXExporter& exporter, const MVector & t, const MQuaternion & r, const String & tSid = "", const String & rSid = "")
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_MASS_FRAME)
        {
			getPhysXExporter().exportTranslationWithoutConversion(t, tSid);
			getPhysXExporter().exportRotation(r.asEulerRotation(), rSid);
        }

		static bool AreDefaultValues(const MVector & t, const MQuaternion & r)
		{
			return t == MVector::zero && r == MQuaternion::identity;
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

		static double DefaultValue()
		{
			return 0.0;
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

		static double DefaultValue()
		{
			return 0.0;
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

		static double DefaultValue()
		{
			return 0.0;
		}
    };

	class FrictionCombineMode : public Element
	{
	public:
		FrictionCombineMode(PhysXExporter & exporter, const PhysXXML::CombineMode::FlagEnum & combineMode)
			: Element(exporter, CSWC::CSW_ELEMENT_FRICTION_COMBINE_MODE)
		{
			getStreamWriter().appendValues(PhysXExporter::CombineModeToCOLLADA(combineMode));
		}

		static PhysXXML::CombineMode::FlagEnum DefaultValue()
		{
			return PhysXXML::CombineMode::Average;
		}
	};

	class RestitutionCombineMode : public Element
	{
	public:
		RestitutionCombineMode(PhysXExporter & exporter, const PhysXXML::CombineMode::FlagEnum & combineMode)
			: Element(exporter, CSWC::CSW_ELEMENT_RESTITUTION_COMBINE_MODE)
		{
			getStreamWriter().appendValues(PhysXExporter::CombineModeToCOLLADA(combineMode));
		}

		static PhysXXML::CombineMode::FlagEnum DefaultValue()
		{
			return PhysXXML::CombineMode::Average;
		}
	};

	class PxMaterial : public Element
	{
	public:
		PxMaterial(PhysXExporter & exporter, const PhysXXML::PxMaterial & mat)
			: Element(exporter, CSWC::CSW_ELEMENT_PX_MATERIAL)
		{
			getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_XMLNS, PhysXExporter::GetXMLNS());
			getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_XSI_SCHEMALOCATION, PhysXExporter::GetXSISchemaLocation());

			exportFrictionCombineMode(mat);
			exportRestitutionCombineMode(mat);
		}

		static bool HasDefaultValues(const PhysXXML::PxMaterial & mat)
		{
			return
				mat.frictionCombineMode.frictionCombineMode == FrictionCombineMode::DefaultValue() &&
				mat.restitutionCombineMode.restitutionCombineMode == RestitutionCombineMode::DefaultValue();
		}

	private:
		void exportFrictionCombineMode(const PhysXXML::PxMaterial & mat)
		{
			if (mat.frictionCombineMode.frictionCombineMode != FrictionCombineMode::DefaultValue())
			{
				FrictionCombineMode e(getPhysXExporter(), mat.frictionCombineMode.frictionCombineMode);
			}
		}

		void exportRestitutionCombineMode(const PhysXXML::PxMaterial & mat)
		{
			if (mat.restitutionCombineMode.restitutionCombineMode != RestitutionCombineMode::DefaultValue())
			{
				RestitutionCombineMode e(getPhysXExporter(), mat.restitutionCombineMode.restitutionCombineMode);
			}
		}
	};

    class PhysicsMaterialTechnique : public Element
    {
    public:
		PhysicsMaterialTechnique(PhysXExporter& exporter, const PhysXXML::PxMaterial & material, const String& profile)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE)
        {
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_PROFILE, profile);
			if (profile == PhysXExporter::GetPhysXProfile())
			{
				exportPxMaterial(material);
			}
        }

		static bool HasDefaultValues(const PhysXXML::PxMaterial & mat, const String & profile)
		{
			if (profile == PhysXExporter::GetPhysXProfile())
			{
				return PxMaterial::HasDefaultValues(mat);
			}
			return false;
		}

	private:
		void exportPxMaterial(const PhysXXML::PxMaterial & mat)
		{
			if (!PxMaterial::HasDefaultValues(mat))
			{
				PxMaterial e(getPhysXExporter(), mat);
			}
		}
    };

    class PhysicsMaterialExtra : public Element
    {
    public:
		PhysicsMaterialExtra(PhysXExporter& exporter, const PhysXXML::PxMaterial & material)
            : Element(exporter, CSWC::CSW_ELEMENT_EXTRA)
        {
			exportTechnique(material, PhysXExporter::GetPhysXProfile());
        }

		static bool HasDefaultValues(const PhysXXML::PxMaterial & mat)
		{
			return PhysicsMaterialTechnique::HasDefaultValues(mat, PhysXExporter::GetPhysXProfile());
		}

    private:
		void exportTechnique(const PhysXXML::PxMaterial & material, const String & profile)
		{
			if (!PhysicsMaterialTechnique::HasDefaultValues(material, profile))
			{
				PhysicsMaterialTechnique e(getPhysXExporter(), material, profile);
			}
		}

		void deprecated_exportTechnique(const PhysXXML::PxMaterial & material, const String& profile)
        {
			if (!PhysicsMaterialTechnique::HasDefaultValues(material, profile))
			{
				PhysicsMaterialTechnique e(getPhysXExporter(), material, profile);
			}
        }
    };

    class PhysicsMaterialTechniqueCommon : public Element
    {
    public:
		PhysicsMaterialTechniqueCommon(PhysXExporter& exporter, const PhysXXML::PxMaterial & material)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE_COMMON)
        {
			exportDynamicFriction(material);
            exportRestitution(material);
            exportStaticFriction(material);
        }

    private:
		void exportRestitution(const PhysXXML::PxMaterial & material)
        {
			if (material.restitution.restitution != Restitution::DefaultValue())
			{
				Restitution e(getPhysXExporter(), material.restitution.restitution);
			}
        }

		void exportDynamicFriction(const PhysXXML::PxMaterial & material)
        {
			if (material.dynamicFriction.dynamicFriction != DynamicFriction::DefaultValue())
			{
				DynamicFriction e(getPhysXExporter(), material.dynamicFriction.dynamicFriction);
			}
        }

		void exportStaticFriction(const PhysXXML::PxMaterial & material)
        {
			if (material.staticFriction.staticFriction != StaticFriction::DefaultValue())
			{
				StaticFriction e(getPhysXExporter(), material.staticFriction.staticFriction);
			}
        }
    };

    class PhysicsMaterial : public Element
    {
    public:
		PhysicsMaterial(PhysXExporter& exporter, const PhysXXML::PxMaterial & material, const String & id)
            : Element(exporter, CSWC::CSW_ELEMENT_PHYSICS_MATERIAL)
        {
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_ID, id);

			exportTechniqueCommon(material);
			exportExtra(material);
        }

    private:
		void exportTechniqueCommon(const PhysXXML::PxMaterial & material)
        {
            PhysicsMaterialTechniqueCommon e(getPhysXExporter(), material);
        }

		void exportExtra(const PhysXXML::PxMaterial & material)
        {
			if (!PhysicsMaterialExtra::HasDefaultValues(material))
			{
				PhysicsMaterialExtra e(getPhysXExporter(), material);
			}
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
		ShapeBox(PhysXExporter& exporter, const PhysXXML::PxShape & shape)
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_BOX)
        {
            exportHalfExtents(shape);
        }

    private:
		void exportHalfExtents(const PhysXXML::PxShape & shape)
        {
			HalfExtents e(getPhysXExporter(), shape.geometry.boxGeometry.halfExtents.halfExtents);
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
		ShapeSphere(PhysXExporter& exporter, const PhysXXML::PxShape & shape)
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_SPHERE)
        {
            exportRadius(shape);
        }

    private:
		void exportRadius(const PhysXXML::PxShape & shape)
        {
			SphereRadius e(getPhysXExporter(), shape.geometry.sphereGeometry.radius.radius);
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
		ShapeCapsule(PhysXExporter& exporter, const PhysXXML::PxShape & shape)
            : Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_CAPSULE)
        {
			exportRadius(shape);
			exportHeight(shape);
        }

    private:
		void exportRadius(const PhysXXML::PxShape & shape)
        {
            CapsuleRadius e(getPhysXExporter(), shape.geometry.capsuleGeometry.radius.radius, shape.geometry.capsuleGeometry.radius.radius);
        }

		void exportHeight(const PhysXXML::PxShape & shape)
        {
			Height e(getPhysXExporter(), shape.geometry.capsuleGeometry.halfHeight.halfHeight * 2.0);
        }
    };

	class Equation : public Element
	{
	public:
		Equation(PhysXExporter& exporter, double a, double b, double c, double d)
			: Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_PLANE_EQUATION)
		{
			getStreamWriter().appendValues(a, b, c, d);
		}
	};

	class ShapePlane : public Element
	{
	public:
		ShapePlane(PhysXExporter& exporter, double a, double b, double c, double d)
			: Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_PLANE)
		{
			exportEquation(a, b, c, d);
		}

	private:
		void exportEquation(double a, double b, double c, double d)
		{
			Equation e(getPhysXExporter(), a, b, c, d);
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
            : Element(exporter, CSWC::CSW_ELEMENT_LOCAL_POSE)
        {
            double localPose[] = { rotation.x, rotation.y, rotation.z, rotation.w, translation.x, translation.y, translation.z };
            getStreamWriter().appendValues(localPose, sizeof(localPose) / sizeof(localPose[0]));
        }
    };

	class SimulationFilterData : public Element
	{
	public:
		SimulationFilterData(PhysXExporter & exporter, int f0, int f1, int f2, int f3)
			: Element(exporter, CSWC::CSW_ELEMENT_SIMULATION_FILTER_DATA)
		{
			getStreamWriter().appendValues(f0, f1, f2, f3);
		}

		static bool AreDefaultValues(int f0, int f1, int f2, int f3)
		{
			return f0 == 0 && f1 == 0 && f2 == 0 && f3 == 0;
		}
	};

	class QueryFilterData : public Element
	{
	public:
		QueryFilterData(PhysXExporter & exporter, int f0, int f1, int f2, int f3)
			: Element(exporter, CSWC::CSW_ELEMENT_QUERY_FILTER_DATA)
		{
			getStreamWriter().appendValues(f0, f1, f2, f3);
		}

		static bool AreDefaultValues(int f0, int f1, int f2, int f3)
		{
			return f0 == 0 && f1 == 0 && f2 == 0 && f3 == 0;
		}
	};

	class ContactOffset : public Element
	{
	public:
		ContactOffset(PhysXExporter & exporter, double contactOffset)
			: Element(exporter, CSWC::CSW_ELEMENT_CONTACT_OFFSET)
		{
			getStreamWriter().appendValues(contactOffset);
		}

		static double DefaultValue()
		{
			return 0.02;
		}
	};

	class RestOffset : public Element
	{
	public:
		RestOffset(PhysXExporter & exporter, double restOffset)
			: Element(exporter, CSWC::CSW_ELEMENT_REST_OFFSET)
		{
			getStreamWriter().appendValues(restOffset);
		}

		static double DefaultValue()
		{
			return 0.0;
		}
	};

	class ShapeFlags : public Element
	{
	public:
		ShapeFlags(PhysXExporter & exporter, const Flags<PhysXXML::ShapeFlags::FlagEnum> & flags)
			: Element(exporter, CSWC::CSW_ELEMENT_SHAPE_FLAGS)
		{
			getStreamWriter().appendText(PhysXExporter::ShapeFlagsToCOLLADA(flags));
		}

		static Flags<PhysXXML::ShapeFlags::FlagEnum> DefaultValue()
		{
			return Flags<PhysXXML::ShapeFlags::FlagEnum>(
				PhysXXML::ShapeFlags::Visualization |
				PhysXXML::ShapeFlags::SimulationShape |
				PhysXXML::ShapeFlags::SceneQueryShape);
		}
	};

	class DebugName : public Element
	{
	public:
		DebugName(PhysXExporter & exporter, const String & name)
			: Element(exporter, CSWC::CSW_ELEMENT_NAME)
		{
			getStreamWriter().appendText(name);
		}

		static String DefaultValue()
		{
			return "";
		}
	};

	class PxShape : public Element
	{
	public:
		PxShape(PhysXExporter& exporter, const PhysXXML::PxShape & shape)
			: Element(exporter, CSWC::CSW_ELEMENT_PX_SHAPE)
		{
			getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_XMLNS, PhysXExporter::GetXMLNS());
			getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_XSI_SCHEMALOCATION, PhysXExporter::GetXSISchemaLocation());

			exportLocalPose(shape);
			exportSimulationFilterData(shape);
			exportQueryFilterData(shape);
			exportContactOffset(shape);
			exportRestOffset(shape);
			exportShapeFlags(shape);
			exportName(shape);
		}

		static bool HasDefaultValues(const PhysXXML::PxShape & shape)
		{
			// Always export local pose
			return false;
		}

	private:
		void exportLocalPose(const PhysXXML::PxShape & shape)
		{
			LocalPose e(getPhysXExporter(), shape.localPose.rotation, shape.localPose.translation);
		}

		void exportSimulationFilterData(const PhysXXML::PxShape & shape)
		{
			if (!SimulationFilterData::AreDefaultValues(
				shape.simulationFilterData.filter0,
				shape.simulationFilterData.filter1,
				shape.simulationFilterData.filter2,
				shape.simulationFilterData.filter3))
			{
				SimulationFilterData e(
					getPhysXExporter(),
					shape.simulationFilterData.filter0,
					shape.simulationFilterData.filter1,
					shape.simulationFilterData.filter2,
					shape.simulationFilterData.filter3
					);
			}
		}

		void exportQueryFilterData(const PhysXXML::PxShape & shape)
		{
			if (!QueryFilterData::AreDefaultValues(
				shape.queryFilterData.filter0,
				shape.queryFilterData.filter1,
				shape.queryFilterData.filter2,
				shape.queryFilterData.filter3))
			{
				QueryFilterData e(
					getPhysXExporter(),
					shape.queryFilterData.filter0,
					shape.queryFilterData.filter1,
					shape.queryFilterData.filter2,
					shape.queryFilterData.filter3
					);
			}
		}

		void exportContactOffset(const PhysXXML::PxShape & shape)
		{
			if (shape.contactOffset.contactOffset != ContactOffset::DefaultValue())
			{
				ContactOffset e(getPhysXExporter(), shape.contactOffset.contactOffset);
			}
		}

		void exportRestOffset(const PhysXXML::PxShape & shape)
		{
			if (shape.restOffset.restOffset != RestOffset::DefaultValue())
			{
				RestOffset e(getPhysXExporter(), shape.restOffset.restOffset);
			}
		}

		void exportShapeFlags(const PhysXXML::PxShape & shape)
		{
			if (shape.flags.flags != ShapeFlags::DefaultValue())
			{
				ShapeFlags e(getPhysXExporter(), shape.flags.flags);
			}
		}

		void exportName(const PhysXXML::PxShape & shape)
		{
			if (shape.name.name != DebugName::DefaultValue())
			{
				DebugName e(getPhysXExporter(), shape.name.name);
			}
		}
	};

    class ShapeTechnique : public Element
    {
    public:
		ShapeTechnique(PhysXExporter& exporter, const MObject& shape, const PhysXXML::PxShape & pxShape, const String & profile)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE)
        {
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_PROFILE, profile);
            if (profile == PROFILE_MAYA) {
                exporter.exportExtraAttributes(shape);
            }
			else if (profile == PhysXExporter::GetPhysXProfile()) {
				exportPxShape(pxShape);
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

		void exportPxShape(const PhysXXML::PxShape & shape)
		{
			if (!PxShape::HasDefaultValues(shape))
			{
				PxShape e(getPhysXExporter(), shape);
			}
		}

    private:
        static std::set<MString, MStringComp> mAttributes;
    };
    std::set<MString, MStringComp> ShapeTechnique::mAttributes;

    class ShapeExtra : public Element
    {
    public:
		ShapeExtra(PhysXExporter& exporter, const MObject& shape, const PhysXXML::PxShape & pxShape)
            : Element(exporter, CSWC::CSW_ELEMENT_EXTRA)
        {
			if (PhysXExporter::HasExtraAttributes(shape)) {
				exportProfile(shape, pxShape, PROFILE_MAYA);
			}

			exportProfile(shape, pxShape, PhysXExporter::GetPhysXProfile());
        }

    private:
		void exportProfile(const MObject& shape, const PhysXXML::PxShape & pxShape, const String& profile)
        {
            ShapeTechnique e(getPhysXExporter(), shape, pxShape, profile);
        }
    };

    class Shape : public Element
    {
    public:
		Shape(PhysXExporter& exporter,
			const MObject & rigidBody,
			const PhysXXML::PxRigidBody & pxRigidBody,
			const MObject & shape,
			const PhysXXML::PxShape & pxShape)
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

			switch (pxShape.geometry.type)
			{
			case PhysXXML::Geometry::Box:				exportBox(pxShape);						break;
			case PhysXXML::Geometry::Sphere:			exportSphere(pxShape);					break;
			case PhysXXML::Geometry::Capsule:			exportCapsule(pxShape);					break;
			case PhysXXML::Geometry::ConvexMesh:		exportConvexHull(rigidBody, shape);		break;
			case PhysXXML::Geometry::TriangleMesh:      exportTriangleMesh(rigidBody, shape);	break;
			case PhysXXML::Geometry::Plane:             exportPlane(pxShape);					break;
			}

			exportRotateTranslate(rigidBody, pxRigidBody, shape, pxShape);
			exportExtra(shape, pxShape);
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
			// g/cm3 to kg/m3
            Density e(getPhysXExporter(), density * 1000.0);
        }

		void exportBox(const PhysXXML::PxShape & shape)
        {
            ShapeBox e(getPhysXExporter(), shape);
        }

		void exportSphere(const PhysXXML::PxShape & shape)
        {
			ShapeSphere e(getPhysXExporter(), shape);
        }

		void exportCapsule(const PhysXXML::PxShape & shape)
        {
			ShapeCapsule e(getPhysXExporter(), shape);
        }

		void exportConvexHull(const MObject & rigidBody, const MObject & shape)
        {
            // TODO PhysX: apply "inflate" attribute to convex hull geometry.
            // Note: apply inflation like done for box shape. See ShapeBox::exportHalfExtents().
            // However "inflate" attribute is limited to [0; 0.839] for some unknown reason.
			exportInstanceGeometry(rigidBody, shape, "_");
        }

		void exportTriangleMesh(const MObject & rigidBody, const MObject & shape)
        {
			exportInstanceGeometry(rigidBody, shape);
        }

		void exportPlane(const PhysXXML::PxShape & shape)
		{
			// Plane equation. PhysX plane normal is along X axis. Normal and distance are calculated from shape transform.
			double a = 1.0;
			double b = 0.0;
			double c = 0.0;
			double d = 0.0;

			ShapePlane e(getPhysXExporter(), a, b, c, d);
		}

		void exportInstanceGeometry(const MObject & rigidBody, const MObject & shape, const String & URISuffix = "")
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

		void exportRotateTranslate(
			const MObject& rigidBody,
			const PhysXXML::PxRigidBody & pxRigidBody,
			const MObject & shape,
			const PhysXXML::PxShape & pxShape)
        {
            // Get shape local pose.
			MMatrix localPose = PxTransformToMMatrix(pxShape.localPose.translation, pxShape.localPose.rotation);

            // Rigid body world pose
			MMatrix globalPose = PxTransformToMMatrix(pxRigidBody.globalPose.translation, pxRigidBody.globalPose.rotation);

			// Target world pose
			MMatrix targetGlobalPose = PhysXExporter::GetRigidBodyTargetTM(rigidBody);

            MMatrix DAEShapeLocalPose = localPose * globalPose * targetGlobalPose.inverse();

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

		void exportExtra(const MObject & shape, const PhysXXML::PxShape & pxShape)
        {
            ShapeExtra e(getPhysXExporter(), shape, pxShape);
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

		static bool DefaultValue()
		{
			return false;
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

		static const MVector & DefaultValue()
		{
			return MVector::zero;
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

		static const MVector & DefaultValue()
		{
			return MVector::zero;
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

		static bool AreDefaultValues(const MVector & min, const MVector & max)
		{
			return min == Min::DefaultValue() &&
				max == Max::DefaultValue();
		}

    private:
		void exportMin(const MVector & min)
        {
            if (min != Min::DefaultValue())
            {
                Min e(getPhysXExporter(), min);
            }
        }

		void exportMax(const MVector & max)
        {
			if (max != Max::DefaultValue())
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

		static bool AreDefaultValues(const MVector & min, const MVector & max)
		{
			return min == Min::DefaultValue() && max == Max::DefaultValue();
		}

    private:
        void exportMin(const MVector & min)
        {
			if (min != Min::DefaultValue())
            {
                Min e(getPhysXExporter(), min);
            }
        }

        void exportMax(const MVector & max)
        {
            if (max != Max::DefaultValue())
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

		static bool AreDefaultValues(
			const MVector & swingConeAndTwistMin,
			const MVector & swingConeAndTwistMax,
			const MVector & linearMin,
			const MVector & linearMax)
		{
			return SwingConeAndTwist::AreDefaultValues(swingConeAndTwistMin, swingConeAndTwistMax) &&
				LimitsLinear::AreDefaultValues(linearMin, linearMax);
		}

    private:
		void exportSwingConeAndTwist(
			const MVector & min,
            const MVector & max)
        {
			if (!SwingConeAndTwist::AreDefaultValues(min, max))
            {
                SwingConeAndTwist e(getPhysXExporter(), min, max);
            }
        }

		void exportLinear(
			const MVector & min,
            const MVector & max)
        {
			if (!LimitsLinear::AreDefaultValues(min, max))
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

		static double DefaultValue()
		{
			return 1.0;
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

		static double DefaultValue()
		{
			return 0.0;
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

		static double DefaultValue()
		{
			return 0.0;
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

		static bool AreDefaultValues(double stiffness, double damping, double targetValue)
		{
			return stiffness == Stiffness::DefaultValue() &&
				damping == Damping::DefaultValue() &&
				targetValue == TargetValue::DefaultValue();
		}

    private:
        void exportStiffness(double stiffness)
        {
            if (stiffness != Stiffness::DefaultValue())
            {
                Stiffness e(getPhysXExporter(), stiffness);
            }
        }

        void exportDamping(double damping)
        {
            if (damping != Damping::DefaultValue())
            {
                Damping e(getPhysXExporter(), damping);
            }
        }

        void exportTargetValue(double targetValue)
        {
            if (targetValue != TargetValue::DefaultValue())
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

		static bool AreDefaultValues(double stiffness, double damping, double targetValue)
		{
			return stiffness == Stiffness::DefaultValue() &&
				damping == Damping::DefaultValue() &&
				targetValue == TargetValue::DefaultValue();
		}

    private:
        void exportStiffness(double stiffness)
        {
            if (stiffness != Stiffness::DefaultValue())
            {
                Stiffness e(getPhysXExporter(), stiffness);
            }
        }

        void exportDamping(double damping)
        {
            if (damping != Damping::DefaultValue())
            {
                Damping e(getPhysXExporter(), damping);
            }
        }

        void exportTargetValue(double targetValue)
        {
            if (targetValue != TargetValue::DefaultValue())
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

		static bool AreDefaultValues(
			double angularStiffness,
			double angularDamping,
			double angularTargetValue,
			double linearStiffness,
			double linearDamping,
			double linearTargetValue)
		{
			return Angular::AreDefaultValues(angularStiffness, angularDamping, angularTargetValue) &&
				SpringLinear::AreDefaultValues(linearStiffness, linearDamping, linearTargetValue);
		}

    private:
        void exportLinear(
            double stiffness,
            double damping,
            double targetValue)
        {
            if (!SpringLinear::AreDefaultValues(stiffness, damping, targetValue))
            {
                SpringLinear e(getPhysXExporter(), stiffness, damping, targetValue);
            }
        }

        void exportAngular(
            double stiffness,
            double damping,
            double targetValue)
        {
            if (!Angular::AreDefaultValues(stiffness, damping, targetValue))
            {
                Angular e(getPhysXExporter(), stiffness, damping, targetValue);
            }
        }
    };

    class RigidBodyTechniqueCommon : public Element
    {
    public:
		RigidBodyTechniqueCommon(PhysXExporter& exporter, const MObject & rigidBody, const PhysXXML::PxRigidBody & pxRigidBody, const String & rigidBodySid)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE_COMMON)
        {
            exportDynamic(pxRigidBody);
            exportMass(rigidBody, pxRigidBody);
            exportMassFrame(rigidBody, pxRigidBody);
            exportInertia(rigidBody, pxRigidBody);
            exportPhysicsMaterial(pxRigidBody, rigidBodySid);
            exportShapes(rigidBody, pxRigidBody);
        }

    private:
		void exportDynamic(const PhysXXML::PxRigidBody & rigidBody)
        {
			Dynamic e(getPhysXExporter(), rigidBody.getType() == PhysXXML::PxRigidBody::Dynamic);
        }

		void exportMass(const MObject & rigidBody, const PhysXXML::PxRigidBody & pxRigidBody)
        {
			int dummy = 0;
			MString overrideMassOrDensityStr;
			DagHelper::getPlugValue(rigidBody, ATTR_OVERRIDE_MASS_OR_DENSITY, dummy, overrideMassOrDensityStr);
			bool overrideMassOrDensity = overrideMassOrDensityStr != OVERRIDE_MASS_OR_DENSITY_DISABLED;

			if (overrideMassOrDensity)
			{
				if (pxRigidBody.getType() == PhysXXML::PxRigidBody::Dynamic)
				{
					const PhysXXML::PxRigidDynamic & rigidDynamic = static_cast<const PhysXXML::PxRigidDynamic&>(pxRigidBody);
					// PhysX mass is in grams. COLLADA uses kilograms.
					Mass e(getPhysXExporter(), rigidDynamic.mass.mass / 1000.0);
				}
				else
				{
					double mass = getPhysXExporter().GetRigidBodyMass(rigidBody);
					Mass e(getPhysXExporter(), mass);
				}
			}
        }

		void exportMassFrame(const MObject & rigidBody, const PhysXXML::PxRigidBody & pxRigidBody)
        {
			MVector translation = MVector::zero;
			MQuaternion rotation = MQuaternion::identity;

			if (pxRigidBody.getType() == PhysXXML::PxRigidBody::Dynamic)
			{
				const PhysXXML::PxRigidDynamic & dyn = static_cast<const PhysXXML::PxRigidDynamic&>(pxRigidBody);

				MMatrix targetWorld = PhysXExporter::GetRigidBodyTargetTM(rigidBody);
				MMatrix cMassLocal = PxTransformToMMatrix(dyn.cMassLocalPose.translation, dyn.cMassLocalPose.rotation);
				MMatrix rigidBodyWorld = PxTransformToMMatrix(dyn.globalPose.translation, dyn.globalPose.rotation);

				// Center of mass relative to target
				cMassLocal = cMassLocal * rigidBodyWorld * targetWorld.inverse();

				MTransformationMatrix transform(cMassLocal);

				translation = transform.getTranslation(MSpace::kTransform);

				MEulerRotation euler = transform.eulerRotation();
				euler.order = static_cast<MEulerRotation::RotationOrder>(static_cast<int>(transform.rotationOrder()) - MTransformationMatrix::kXYZ + MEulerRotation::kXYZ);
				rotation = euler.asQuaternion();
			}
			else
			{
				int dummy = 0;
				MString centerOfMassMode;
				DagHelper::getPlugValue(rigidBody, ATTR_CENTER_OF_MASS_MODE, dummy, centerOfMassMode);

				MString overrideMassOrDensityStr;
				DagHelper::getPlugValue(rigidBody, ATTR_OVERRIDE_MASS_OR_DENSITY, dummy, overrideMassOrDensityStr);
				bool overrideMassOrDensity = overrideMassOrDensityStr != OVERRIDE_MASS_OR_DENSITY_DISABLED;

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
			}

			if (!MassFrame::AreDefaultValues(translation, rotation))
			{
				MassFrame e(getPhysXExporter(), translation, rotation, ATTR_TRANSLATE, ATTR_ROTATE);
			}
        }

		void exportInertia(const MObject & rigidBody, const PhysXXML::PxRigidBody & pxRigidBody)
        {
			MVector inertiaMatrixDiagonal = MVector::one;

			if (pxRigidBody.getType() == PhysXXML::PxRigidBody::Dynamic)
			{
				const PhysXXML::PxRigidDynamic & dyn = static_cast<const PhysXXML::PxRigidDynamic&>(pxRigidBody);
				// g to kg
				inertiaMatrixDiagonal = dyn.massSpaceInertiaTensor.massSpaceInertiaTensor / 1000.0;
			}
			else
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

				inertiaMatrixDiagonal.x = mass * (bb.y * bb.y + bb.z * bb.z) / 12.0;
				inertiaMatrixDiagonal.y = mass * (bb.x * bb.x + bb.z * bb.z) / 12.0;
				inertiaMatrixDiagonal.z = mass * (bb.x * bb.x + bb.y * bb.y) / 12.0;
			}

            Inertia e(getPhysXExporter(), inertiaMatrixDiagonal);
        }

		void exportPhysicsMaterial(const PhysXXML::PxRigidBody & rigidBody, const String & rigidBodySid)
        {
			if (const PhysXXML::PxMaterial* material = getPhysXExporter().findPxMaterial(rigidBody))
			{
				String id = rigidBodySid + "_material";
				PhysicsMaterial e(getPhysXExporter(), *material, id);
			}
        }

        void exportShapes(const MObject & rigidBody, const PhysXXML::PxRigidBody & pxRigidBody)
        {
			for (size_t i = 0; i < pxRigidBody.shapes.shapes.size(); ++i)
			{
				MObject shape = getPhysXExporter().findMObject(pxRigidBody.shapes.shapes[i]);
				Shape e(getPhysXExporter(), rigidBody, pxRigidBody, shape, pxRigidBody.shapes.shapes[i]);
			}
        }
    };

    class RigidConstraintTechniqueCommon : public Element
    {
    public:
		RigidConstraintTechniqueCommon(PhysXExporter& exporter, const MObject & rigidConstraint, const PhysXXML::PxD6Joint & joint)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE_COMMON)
        {
            exportEnabled(rigidConstraint);
            exportInterpenetrate(joint);
            exportLimits(joint);
            exportSpring(joint);
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

		void exportInterpenetrate(const PhysXXML::PxD6Joint & joint)
        {
			bool interpenetrate = !joint.constraintFlags.flags.isSet(PhysXXML::ConstraintFlags::CollisionEnabled);
			if (interpenetrate == Interpenetrate::DefaultValue())
			{
				Interpenetrate e(getPhysXExporter(), interpenetrate);
			}
        }

		void exportLimits(const PhysXXML::PxD6Joint & joint)
        {
            MVector swingConeAndTwistMin = MVector::zero;
			MVector swingConeAndTwistMax = MVector::zero;
			MVector linearMin = MVector::zero;
			MVector linearMax = MVector::zero;

			if (joint.motion.eSwing1.eSwing1 == PhysXXML::MotionFlags::Locked)
			{
				swingConeAndTwistMin.x = 0.0;
				swingConeAndTwistMax.x = 0.0;
			}
			else if (joint.motion.eSwing1.eSwing1 == PhysXXML::MotionFlags::Free)
			{
				swingConeAndTwistMin.x = -infinite();
				swingConeAndTwistMax.x = infinite();
			}
			else
			{
				swingConeAndTwistMin.x = COLLADABU::Math::Utils::radToDeg(-joint.swingLimit.yAngle.yAngle);
				swingConeAndTwistMax.x = COLLADABU::Math::Utils::radToDeg(joint.swingLimit.yAngle.yAngle);
			}

			if (joint.motion.eSwing2.eSwing2 == PhysXXML::MotionFlags::Locked)
			{
				swingConeAndTwistMin.y = 0.0;
				swingConeAndTwistMax.y = 0.0;
			}
			else if (joint.motion.eSwing2.eSwing2 == PhysXXML::MotionFlags::Free)
			{
				swingConeAndTwistMin.y = -infinite();
				swingConeAndTwistMax.y = infinite();
			}
			else
			{
				swingConeAndTwistMin.y = COLLADABU::Math::Utils::radToDeg(-joint.swingLimit.zAngle.zAngle);
				swingConeAndTwistMax.y = COLLADABU::Math::Utils::radToDeg(joint.swingLimit.zAngle.zAngle);
			}

			if (joint.motion.eTwist.eTwist == PhysXXML::MotionFlags::Locked)
			{
				swingConeAndTwistMin.z = 0.0;
				swingConeAndTwistMax.z = 0.0;
			}
			else if (joint.motion.eTwist.eTwist == PhysXXML::MotionFlags::Free)
			{
				swingConeAndTwistMin.z = -infinite();
				swingConeAndTwistMax.z = infinite();
			}
			else
			{
				swingConeAndTwistMin.z = COLLADABU::Math::Utils::radToDeg(joint.twistLimit.lower.lower);
				swingConeAndTwistMax.z = COLLADABU::Math::Utils::radToDeg(joint.twistLimit.upper.upper);
			}

			if (joint.motion.eX.eX == PhysXXML::MotionFlags::Locked)
			{
				linearMin.x = 0.0;
				linearMax.x = 0.0;
			}
			else if (joint.motion.eX.eX == PhysXXML::MotionFlags::Free)
			{
				linearMin.x = -infinite();
				linearMax.x = infinite();
			}
			else
			{
				linearMin.x = -joint.linearLimit.value.value;
				linearMax.x = joint.linearLimit.value.value;
			}

			if (joint.motion.eY.eY == PhysXXML::MotionFlags::Locked)
			{
				linearMin.y = 0.0;
				linearMax.y = 0.0;
			}
			else if (joint.motion.eY.eY == PhysXXML::MotionFlags::Free)
			{
				linearMin.y = -infinite();
				linearMax.y = infinite();
			}
			else
			{
				linearMin.y = -joint.linearLimit.value.value;
				linearMax.y = joint.linearLimit.value.value;
			}

			if (joint.motion.eZ.eZ == PhysXXML::MotionFlags::Locked)
			{
				linearMin.z = 0.0;
				linearMax.z = 0.0;
			}
			else if (joint.motion.eZ.eZ == PhysXXML::MotionFlags::Free)
			{
				linearMin.z = -infinite();
				linearMax.z = infinite();
			}
			else
			{
				linearMin.z = -joint.linearLimit.value.value;
				linearMax.z = joint.linearLimit.value.value;
			}

            if (!Limits::AreDefaultValues(swingConeAndTwistMin, swingConeAndTwistMax, linearMin, linearMax))
            {
                Limits e(getPhysXExporter(),
                    swingConeAndTwistMin,
                    swingConeAndTwistMax,
                    linearMin,
                    linearMax);
            }
        }

		void exportSpring(const PhysXXML::PxD6Joint & joint)
        {
			double linearStiffness = joint.linearLimit.stiffness.stiffness;
			double linearDamping = joint.linearLimit.damping.damping;
            double linearTargetValue = 0.0;
			double angularStiffness = joint.swingLimit.stiffness.stiffness;
			double angularDamping = joint.swingLimit.damping.damping;
            double angularTargetValue = 0.0;

            if (!Spring::AreDefaultValues(
				linearStiffness,
                linearDamping,
                linearTargetValue,
                angularStiffness,
                angularDamping,
                angularTargetValue))
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

	class ActorFlags : public Element
	{
	public:
		ActorFlags(PhysXExporter & exporter, const Flags<PhysXXML::ActorFlags::FlagEnum> & flags)
			: Element(exporter, CSWC::CSW_ELEMENT_ACTOR_FLAGS)
		{
			getStreamWriter().appendValues(PhysXExporter::ActorFlagsToCOLLADA(flags));
		}

		static Flags<PhysXXML::ActorFlags::FlagEnum> DefaultValue()
		{
			return Flags<PhysXXML::ActorFlags::FlagEnum>(PhysXXML::ActorFlags::Visualization);
		}
	};

	class DominanceGroup : public Element
	{
	public:
		DominanceGroup(PhysXExporter & exporter, int dominanceGroup)
			: Element(exporter, CSWC::CSW_ELEMENT_DOMINANCE_GROUP)
		{
			getStreamWriter().appendValues(dominanceGroup);
		}

		static int DefaultValue()
		{
			return 0;
		}
	};
	
	class OwnerClient : public Element
	{
	public:
		OwnerClient(PhysXExporter & exporter, int ownerClient)
			: Element(exporter, CSWC::CSW_ELEMENT_OWNER_CLIENT)
		{
			getStreamWriter().appendValues(ownerClient);
		}

		static int DefaultValue()
		{
			return 0;
		}
	};

	class RigidBodyFlags : public Element
	{
	public:
		RigidBodyFlags(PhysXExporter & exporter, const Flags<PhysXXML::RigidBodyFlags::FlagEnum> & flags)
			: Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY_FLAGS)
		{
			getStreamWriter().appendValues(PhysXExporter::RigidBodyFlagsToCOLLADA(flags));
		}

		static Flags<PhysXXML::RigidBodyFlags::FlagEnum> DefaultValue()
		{
			return Flags<PhysXXML::RigidBodyFlags::FlagEnum>();
		}
	};
	
	class MinCCDAdvanceCoefficient : public Element
	{
	public:
		MinCCDAdvanceCoefficient(PhysXExporter & exporter, double minCCDAdvanceCoefficient)
			: Element(exporter, CSWC::CSW_ELEMENT_MIN_CCD_ADVANCE_COEFFICIENT)
		{
			getStreamWriter().appendValues(minCCDAdvanceCoefficient);
		}

		static double DefaultValue()
		{
			return 0.15;
		}
	};

	class MaxDepenetrationVelocity : public Element
	{
	public:
		MaxDepenetrationVelocity(PhysXExporter & exporter, double maxDepenetrationVelocity)
			: Element(exporter, CSWC::CSW_ELEMENT_MAX_DEPENETRATION_VELOCITY)
		{
			getStreamWriter().appendValues(maxDepenetrationVelocity);
		}

		static double DefaultValue()
		{
			return infinite();
		}
	};

	class LinearDamping : public Element
	{
	public:
		LinearDamping(PhysXExporter & exporter, double linearDamping)
			: Element(exporter, CSWC::CSW_ELEMENT_LINEAR_DAMPING)
		{
			getStreamWriter().appendValues(linearDamping);
		}

		static double DefaultValue()
		{
			return 0.0;
		}
	};

	class AngularDamping : public Element
	{
	public:
		AngularDamping(PhysXExporter & exporter, double angularDamping)
			: Element(exporter, CSWC::CSW_ELEMENT_ANGULAR_DAMPING)
		{
			getStreamWriter().appendValues(angularDamping);
		}

		static double DefaultValue()
		{
			return 0.0;
		}
	};

	class MaxAngularVelocity : public Element
	{
	public:
		MaxAngularVelocity(PhysXExporter & exporter, double maxAngularDamping)
			: Element(exporter, CSWC::CSW_ELEMENT_MAX_ANGULAR_VELOCITY)
		{
			getStreamWriter().appendValues(maxAngularDamping);
		}

		static double DefaultValue()
		{
			return 7.0;
		}
	};

	class SleepThreshold : public Element
	{
	public:
		SleepThreshold(PhysXExporter & exporter, double sleepThreshold)
			: Element(exporter, CSWC::CSW_ELEMENT_SLEEP_THRESHOLD)
		{
			getStreamWriter().appendValues(sleepThreshold);
		}

		static double DefaultValue()
		{
			return 5e-5;
		}
	};

	class StabilizationThreshold : public Element
	{
	public:
		StabilizationThreshold(PhysXExporter & exporter, double stabilizationThreshold)
			: Element(exporter, CSWC::CSW_ELEMENT_STABILIZATION_THRESHOLD)
		{
			getStreamWriter().appendValues(stabilizationThreshold);
		}

		static double DefaultValue()
		{
			return 1e-5;
		}
	};

	class WakeCounter : public Element
	{
	public:
		WakeCounter(PhysXExporter & exporter, double wakeCounter)
			: Element(exporter, CSWC::CSW_ELEMENT_WAKE_COUNTER)
		{
			getStreamWriter().appendValues(wakeCounter);
		}

		static double DefaultValue()
		{
			return 0.4;
		}
	};

	class MinPositionIters : public Element
	{
	public:
		MinPositionIters(PhysXExporter & exporter, int minPositionIters)
			: Element(exporter, CSWC::CSW_ELEMENT_MIN_POSITION_ITERS)
		{
			getStreamWriter().appendValues(minPositionIters);
		}

		static int DefaultValue()
		{
			return 4;
		}
	};

	class MinVelocityIters : public Element
	{
	public:
		MinVelocityIters(PhysXExporter & exporter, int minVelocityIters)
			: Element(exporter, CSWC::CSW_ELEMENT_MIN_VELOCITY_ITERS)
		{
			getStreamWriter().appendValues(minVelocityIters);
		}

		static int DefaultValue()
		{
			return 1;
		}
	};

	class ContactReportThreshold : public Element
	{
	public:
		ContactReportThreshold(PhysXExporter & exporter, double contactReportThreshold)
			: Element(exporter, CSWC::CSW_ELEMENT_CONTACT_REPORT_THRESHOLD)
		{
			getStreamWriter().appendValues(contactReportThreshold);
		}

		static double DefaultValue()
		{
			return infinite();
		}
	};

	class GlobalPose : public Element
	{
	public:
		GlobalPose(PhysXExporter& exporter, const MQuaternion & rotation, const MVector & translation)
			: Element(exporter, CSWC::CSW_ELEMENT_GLOBAL_POSE)
		{
			double pose [] = { rotation.x, rotation.y, rotation.z, rotation.w, translation.x, translation.y, translation.z };
			getStreamWriter().appendValues(pose, sizeof(pose) / sizeof(pose[0]));
		}
	};

	class PxRigidBody : public Element
	{
	public:
		PxRigidBody(PhysXExporter& exporter, const PhysXXML::PxRigidBody & rb)
			: Element(exporter, CSWC::CSW_ELEMENT_PX_RIGID_BODY)
		{
			getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_XMLNS, PhysXExporter::GetXMLNS());
			getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_XSI_SCHEMALOCATION, PhysXExporter::GetXSISchemaLocation());

			exportGlobalPose(rb);
			exportActorFlags(rb);
			exportDominanceGroup(rb);
			exportOwnerClient(rb);
			if (rb.getType() == PhysXXML::PxRigidBody::Dynamic)
			{
				const PhysXXML::PxRigidDynamic & rd = static_cast<const PhysXXML::PxRigidDynamic&>(rb);
				exportRigidBodyFlags(rd);
				exportMinCCDAdvanceCoefficient(rd);
				exportMaxDepenetrationVelocity(rd);
				exportLinearDamping(rd);
				exportAngularDamping(rd);
				exportMaxAngularVelocity(rd);
				exportSleepThreshold(rd);
				exportStabilizationThreshold(rd);
				exportWakeCounter(rd);
				exportMinPositionIters(rd);
				exportMinVelocityIters(rd);
				exportContactReportThreshold(rd);
			}
		}

		static bool HasDefaultValues(const PhysXXML::PxRigidBody & rb)
		{
			// Always export global pose
			return false;
		}

	private:
		void exportGlobalPose(const PhysXXML::PxRigidBody & pxRigidBody)
		{
			GlobalPose e(getPhysXExporter(), pxRigidBody.globalPose.rotation, pxRigidBody.globalPose.translation);
		}

		void exportActorFlags(const PhysXXML::PxRigidBody & pxRigidBody)
		{
			if (pxRigidBody.actorFlags.actorFlags != ActorFlags::DefaultValue())
			{
				ActorFlags e(getPhysXExporter(), pxRigidBody.actorFlags.actorFlags);
			}
		}

		void exportDominanceGroup(const PhysXXML::PxRigidBody & pxRigidBody)
		{
			if (pxRigidBody.dominanceGroup.dominanceGroup != DominanceGroup::DefaultValue())
			{
				DominanceGroup e(getPhysXExporter(), pxRigidBody.dominanceGroup.dominanceGroup);
			}
		}

		void exportOwnerClient(const PhysXXML::PxRigidBody & pxRigidBody)
		{
			if (pxRigidBody.ownerClient.ownerClient != OwnerClient::DefaultValue())
			{
				OwnerClient e(getPhysXExporter(), pxRigidBody.ownerClient.ownerClient);
			}
		}

		void exportRigidBodyFlags(const PhysXXML::PxRigidDynamic & pxRigidDynamic)
		{
			if (pxRigidDynamic.rigidBodyFlags.rigidBodyFlags != RigidBodyFlags::DefaultValue())
			{
				RigidBodyFlags e(getPhysXExporter(), pxRigidDynamic.rigidBodyFlags.rigidBodyFlags);
			}
		}

		void exportMinCCDAdvanceCoefficient(const PhysXXML::PxRigidDynamic & pxRigidDynamic)
		{
			if (pxRigidDynamic.minCCDAdvanceCoefficient.minCCDAdvanceCoefficient != MinCCDAdvanceCoefficient::DefaultValue())
			{
				MinCCDAdvanceCoefficient e(getPhysXExporter(), pxRigidDynamic.minCCDAdvanceCoefficient.minCCDAdvanceCoefficient);
			}
		}

		void exportMaxDepenetrationVelocity(const PhysXXML::PxRigidDynamic & pxRigidDynamic)
		{
			if (pxRigidDynamic.maxDepenetrationVelocity.maxDepenetrationVelocity != MaxDepenetrationVelocity::DefaultValue())
			{
				MaxDepenetrationVelocity e(getPhysXExporter(), pxRigidDynamic.maxDepenetrationVelocity.maxDepenetrationVelocity);
			}
		}

		void exportLinearDamping(const PhysXXML::PxRigidDynamic & pxRigidDynamic)
		{
			if (pxRigidDynamic.linearDamping.linearDamping != LinearDamping::DefaultValue())
			{
				LinearDamping e(getPhysXExporter(), pxRigidDynamic.linearDamping.linearDamping);
			}
		}

		void exportAngularDamping(const PhysXXML::PxRigidDynamic & pxRigidDynamic)
		{
			if (pxRigidDynamic.angularDamping.angularDamping != AngularDamping::DefaultValue())
			{
				AngularDamping e(getPhysXExporter(), pxRigidDynamic.angularDamping.angularDamping);
			}
		}

		void exportMaxAngularVelocity(const PhysXXML::PxRigidDynamic & pxRigidDynamic)
		{
			if (pxRigidDynamic.maxAngularVelocity.maxAngularVelocity != MaxAngularVelocity::DefaultValue())
			{
				MaxAngularVelocity e(getPhysXExporter(), pxRigidDynamic.maxAngularVelocity.maxAngularVelocity);
			}
		}

		void exportSleepThreshold(const PhysXXML::PxRigidDynamic & pxRigidDynamic)
		{
			if (pxRigidDynamic.sleepThreshold.sleepThreshold != SleepThreshold::DefaultValue())
			{
				SleepThreshold e(getPhysXExporter(), pxRigidDynamic.sleepThreshold.sleepThreshold);
			}
		}

		void exportStabilizationThreshold(const PhysXXML::PxRigidDynamic & pxRigidDynamic)
		{
			if (pxRigidDynamic.stabilizationThreshold.stabilizationThreshold != StabilizationThreshold::DefaultValue())
			{
				StabilizationThreshold e(getPhysXExporter(), pxRigidDynamic.stabilizationThreshold.stabilizationThreshold);
			}
		}

		void exportWakeCounter(const PhysXXML::PxRigidDynamic & pxRigidDynamic)
		{
			if (pxRigidDynamic.wakeCounter.wakeCounter != WakeCounter::DefaultValue())
			{
				WakeCounter e(getPhysXExporter(), pxRigidDynamic.wakeCounter.wakeCounter);
			}
		}

		void exportMinPositionIters(const PhysXXML::PxRigidDynamic & pxRigidDynamic)
		{
			if (pxRigidDynamic.solverIterationCounts.minPositionIters.minPositionIters != MinPositionIters::DefaultValue())
			{
				MinPositionIters e(getPhysXExporter(), pxRigidDynamic.solverIterationCounts.minPositionIters.minPositionIters);
			}
		}

		void exportMinVelocityIters(const PhysXXML::PxRigidDynamic & pxRigidDynamic)
		{
			if (pxRigidDynamic.solverIterationCounts.minVelocityIters.minVelocityIters != MinVelocityIters::DefaultValue())
			{
				MinVelocityIters e(getPhysXExporter(), pxRigidDynamic.solverIterationCounts.minVelocityIters.minVelocityIters);
			}
		}

		void exportContactReportThreshold(const PhysXXML::PxRigidDynamic & pxRigidDynamic)
		{
			if (pxRigidDynamic.contactReportThreshold.contactReportThreshold != ContactReportThreshold::DefaultValue())
			{
				ContactReportThreshold e(getPhysXExporter(), pxRigidDynamic.contactReportThreshold.contactReportThreshold);
			}
		}
	};

    class RigidBodyTechnique : public Element
    {
    public:
		RigidBodyTechnique(PhysXExporter& exporter, const MObject & rigidBody, const PhysXXML::PxRigidBody & pxRigidBody, const String & profile)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE)
        {
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_PROFILE, profile);
            
            if (profile == PROFILE_MAYA) {
				exporter.exportExtraAttributes(rigidBody);
			}
			else if (profile == PhysXExporter::GetPhysXProfile()) {
				exportPxRigidBody(pxRigidBody);
			}
        }

		static bool HasDefaultValues(const PhysXXML::PxRigidBody & rb, const String & profile)
		{
			if (profile == PhysXExporter::GetPhysXProfile())
			{
				return PxRigidBody::HasDefaultValues(rb);
			}
			return false;
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

		void exportPxRigidBody(const PhysXXML::PxRigidBody & rb)
		{
			if (!PxRigidBody::HasDefaultValues(rb))
			{
				PxRigidBody e(getPhysXExporter(), rb);
			}
		}

    private:
        static std::set<MString, MStringComp> mAttributes;
    };
    std::set<MString, MStringComp> RigidBodyTechnique::mAttributes;

    class RigidBodyExtra : public Element
    {
    public:
		RigidBodyExtra(PhysXExporter& exporter, const MObject & rigidBody, const PhysXXML::PxRigidBody & pxRigidBody)
            : Element(exporter, CSWC::CSW_ELEMENT_EXTRA)
        {
			if (PhysXExporter::HasExtraAttributes(rigidBody)) {
				exportProfile(rigidBody, pxRigidBody, PROFILE_MAYA);
			}
			exportProfile(rigidBody, pxRigidBody, PhysXExporter::GetPhysXProfile());
        }

    private:
		void exportProfile(const MObject& rigidBody, const PhysXXML::PxRigidBody & pxRigidBody, const String& profile)
        {
			if (!RigidBodyTechnique::HasDefaultValues(pxRigidBody, profile))
			{
				RigidBodyTechnique e(getPhysXExporter(), rigidBody, pxRigidBody, profile);
			}
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

			const PhysXXML::PxRigidBody* pxRigidBody = exporter.findPxRigidBody(rigidBody);
			if (pxRigidBody)
			{
				exportTechniqueCommon(rigidBody, *pxRigidBody, sid);
				exportExtra(rigidBody, *pxRigidBody);
			}
        }

		RigidBody(PhysXExporter& exporter, const PhysXXML::PxRigidBody & pxRigidBody, const String & sid, const String & name = "")
			: Element(exporter, CSWC::CSW_ELEMENT_RIGID_BODY)
		{
			MObject rigidBody;
			getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
			if (name.length() > 0) {
				getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_NAME, name);
			}

			exportTechniqueCommon(rigidBody, pxRigidBody, sid);
			exportExtra(rigidBody, pxRigidBody);
		}

    private:
		void exportTechniqueCommon(const MObject & rigidBody, const PhysXXML::PxRigidBody & pxRigidBody, const String & sid)
        {
			RigidBodyTechniqueCommon e(getPhysXExporter(), rigidBody, pxRigidBody, sid);
        }

		void exportExtra(const MObject & rigidBody, const PhysXXML::PxRigidBody & pxRigidBody)
        {
            RigidBodyExtra e(getPhysXExporter(), rigidBody, pxRigidBody);
        }
    };

	class IAttachment
	{
	public:
		void exportRotateTranslate(PhysXExporter & exporter, uint64_t actor, const MVector & localPoseActorTranslation, const MQuaternion & localPoseActorRotation)
		{
			const PhysXXML::PxRigidBody* pxRigidBody = exporter.findPxRigidBody(actor);

			MVector translation = uiToInternal(localPoseActorTranslation);
			MEulerRotation rotation = localPoseActorRotation.asEulerRotation();

			if (pxRigidBody)
			{
				MObject target = DagHelper::getNode(pxRigidBody->name.name.c_str());
				MObject rigidBody = exporter.getNodeRigidBody(target);
				if (!rigidBody.isNull())
				{
					MMatrix targetWorld = PhysXExporter::GetRigidBodyTargetTM(rigidBody);
					MMatrix constraintLocal = PxTransformToMMatrix(localPoseActorTranslation, localPoseActorRotation);
					MMatrix rigidBodyWorld = PxTransformToMMatrix(pxRigidBody->globalPose.translation, pxRigidBody->globalPose.rotation);

					constraintLocal = constraintLocal * rigidBodyWorld * targetWorld.inverse();

					MTransformationMatrix tm(constraintLocal);
					translation = tm.getTranslation(MSpace::kTransform);
					rotation = tm.eulerRotation();
					rotation.order = static_cast<MEulerRotation::RotationOrder>(static_cast<int>(tm.rotationOrder()) - MTransformationMatrix::kXYZ + MEulerRotation::kXYZ);
				}
			}

			exporter.exportTranslation(translation, ATTR_TRANSLATE);
			exporter.exportRotation(rotation, ATTR_ROTATE);
		}
	};

    class RefAttachment : public Element, public IAttachment
    {
    public:
		RefAttachment(PhysXExporter& exporter, const PhysXXML::PxD6Joint & joint, const URI & rigidBodyURI)
            : Element(exporter, CSWC::CSW_ELEMENT_REF_ATTACHMENT)
        {
            getStreamWriter().appendURIAttribute(CSWC::CSW_ATTRIBUTE_RIGID_BODY, rigidBodyURI);
            exportRotateTranslate(joint);
        }

    private:
		void exportRotateTranslate(const PhysXXML::PxD6Joint & joint)
        {
			IAttachment::exportRotateTranslate(getPhysXExporter(), joint.actors.actor0.actor0, joint.localPose.eActor0.translation, joint.localPose.eActor0.rotation);
        }
    };

    class Attachment : public Element, public IAttachment
    {
    public:
		Attachment(PhysXExporter& exporter, const PhysXXML::PxD6Joint & joint, const URI & rigidBodyURI)
            : Element(exporter, CSWC::CSW_ELEMENT_ATTACHMENT)
        {
            getStreamWriter().appendURIAttribute(CSWC::CSW_ATTRIBUTE_RIGID_BODY, rigidBodyURI);
            exportRotateTranslate(joint);
        }

    private:
		void exportRotateTranslate(const PhysXXML::PxD6Joint & joint)
        {
			IAttachment::exportRotateTranslate(getPhysXExporter(), joint.actors.actor1.actor1, joint.localPose.eActor1.translation, joint.localPose.eActor1.rotation);
        }
    };

	class BreakForce : public Element
	{
	public:
		BreakForce(PhysXExporter & exporter, double breakForce)
			: Element(exporter, CSWC::CSW_ELEMENT_BREAK_FORCE)
		{
			getStreamWriter().appendValues(breakForce);
		}

		static double DefaultValue()
		{
			return infinite();
		}
	};
	
	class BreakTorque : public Element
	{
	public:
		BreakTorque(PhysXExporter & exporter, double breakTorque)
			: Element(exporter, CSWC::CSW_ELEMENT_BREAK_TORQUE)
		{
			getStreamWriter().appendValues(breakTorque);
		}

		static double DefaultValue()
		{
			return infinite();
		}
	};

	class ConstraintFlags : public Element
	{
	public:
		ConstraintFlags(PhysXExporter & exporter, const Flags<PhysXXML::ConstraintFlags::FlagEnum> & flags)
			: Element(exporter, CSWC::CSW_ELEMENT_CONSTRAINT_FLAGS)
		{
			getStreamWriter().appendValues(PhysXExporter::ConstraintFlagsToCOLLADA(flags));
		}

		static Flags<PhysXXML::ConstraintFlags::FlagEnum> DefaultValue()
		{
			return Flags<PhysXXML::ConstraintFlags::FlagEnum>();
		}
	};

	class InvMassScale0 : public Element
	{
	public:
		InvMassScale0(PhysXExporter & exporter, double invMassScale0)
			: Element(exporter, CSWC::CSW_ELEMENT_INV_MASS_SCALE_0)
		{
			getStreamWriter().appendValues(invMassScale0);
		}

		static double DefaultValue()
		{
			return 1.0;
		}
	};

	class InvInertiaScale0 : public Element
	{
	public:
		InvInertiaScale0(PhysXExporter & exporter, double invInertiaScale0)
			: Element(exporter, CSWC::CSW_ELEMENT_INV_INERTIA_SCALE_0)
		{
			getStreamWriter().appendValues(invInertiaScale0);
		}

		static double DefaultValue()
		{
			return 1.0;
		}
	};

	class InvMassScale1 : public Element
	{
	public:
		InvMassScale1(PhysXExporter & exporter, double invMassScale1)
			: Element(exporter, CSWC::CSW_ELEMENT_INV_MASS_SCALE_1)
		{
			getStreamWriter().appendValues(invMassScale1);
		}

		static double DefaultValue()
		{
			return 1.0;
		}
	};

	class InvInertiaScale1 : public Element
	{
	public:
		InvInertiaScale1(PhysXExporter & exporter, double invInertiaScale1)
			: Element(exporter, CSWC::CSW_ELEMENT_INV_INERTIA_SCALE_1)
		{
			getStreamWriter().appendValues(invInertiaScale1);
		}

		static double DefaultValue()
		{
			return 1.0;
		}
	};

	class ProjectionLinearTolerance : public Element
	{
	public:
		ProjectionLinearTolerance(PhysXExporter & exporter, double projectionLinearTolerance)
			: Element(exporter, CSWC::CSW_ELEMENT_PROJECTION_LINEAR_TOLERANCE)
		{
			getStreamWriter().appendValues(projectionLinearTolerance);
		}

		static double DefaultValue()
		{
			return 1e10;
		}
	};

	class ProjectionAngularTolerance : public Element
	{
	public:
		ProjectionAngularTolerance(PhysXExporter & exporter, double projectionAngularTolerance)
			: Element(exporter, CSWC::CSW_ELEMENT_PROJECTION_ANGULAR_TOLERANCE)
		{
			getStreamWriter().appendValues(COLLADABU::Math::Utils::radToDeg(projectionAngularTolerance));
		}

		static double DefaultValue()
		{
			return M_PI;
		}
	};

	class BounceThreshold : public Element
	{
	public:
		BounceThreshold(PhysXExporter & exporter, double bounceThreshold)
			: Element(exporter, CSWC::CSW_ELEMENT_BOUNCE_THRESHOLD)
		{
			getStreamWriter().appendValues(bounceThreshold);
		}

		static double DefaultValue()
		{
			return 0.0;
		}
	};

	class ContactDistance : public Element
	{
	public:
		ContactDistance(PhysXExporter & exporter, double contactDistance)
			: Element(exporter, CSWC::CSW_ELEMENT_CONTACT_DISTANCE)
		{
			getStreamWriter().appendValues(contactDistance);
		}

		static double DefaultValue()
		{
			return 0.0;
		}
	};

	class LimitsLinearExtra : public Element
	{
	public:
		LimitsLinearExtra(PhysXExporter & exporter, const PhysXXML::PxD6Joint & joint)
			: Element(exporter, CSWC::CSW_ELEMENT_LINEAR_EXTRA)
		{
			exportRestitution(joint);
			exportBounceThreshold(joint);
			exportContactDistance(joint);
		}

		static bool HasDefaultValues(const PhysXXML::PxD6Joint & joint)
		{
			return
				joint.linearLimit.restitution.restitution == Restitution::DefaultValue() &&
				joint.linearLimit.bounceThreshold.bounceThreshold == BounceThreshold::DefaultValue() &&
				joint.linearLimit.contactDistance.contactDistance == ContactDistance::DefaultValue();
		}

	private:
		void exportRestitution(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.linearLimit.restitution.restitution != Restitution::DefaultValue())
			{
				Restitution e(getPhysXExporter(), joint.linearLimit.restitution.restitution);
			}
		}

		void exportBounceThreshold(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.linearLimit.bounceThreshold.bounceThreshold != BounceThreshold::DefaultValue())
			{
				BounceThreshold e(getPhysXExporter(), joint.linearLimit.bounceThreshold.bounceThreshold);
			}
		}

		void exportContactDistance(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.linearLimit.contactDistance.contactDistance != ContactDistance::DefaultValue())
			{
				ContactDistance e(getPhysXExporter(), joint.linearLimit.contactDistance.contactDistance);
			}
		}
	};

	class Restitution2 : public Element
	{
	public:
		Restitution2(PhysXExporter & exporter, double swingRestitution, double twistRestitution)
			: Element(exporter, CSWC::CSW_ELEMENT_RESTITUTION)
		{
			getStreamWriter().appendValues(swingRestitution, twistRestitution);
		}

		static bool AreDefaultValues(double swingRestitution, double twistRestitution)
		{
			return swingRestitution == Restitution::DefaultValue() && twistRestitution == Restitution::DefaultValue();
		}
	};

	class BounceThreshold2 : public Element
	{
	public:
		BounceThreshold2(PhysXExporter & exporter, double swingBounceThreshold, double twistBounceThreshold)
			: Element(exporter, CSWC::CSW_ELEMENT_BOUNCE_THRESHOLD)
		{
			getStreamWriter().appendValues(swingBounceThreshold, twistBounceThreshold);
		}

		static bool AreDefaultValues(double swingBounceThreshold, double twistBounceThreshold)
		{
			return swingBounceThreshold == BounceThreshold::DefaultValue() && twistBounceThreshold == BounceThreshold::DefaultValue();
		}
	};

	class ContactDistance2 : public Element
	{
	public:
		ContactDistance2(PhysXExporter & exporter, double swingContactDistance, double twistContactDistance)
			: Element(exporter, CSWC::CSW_ELEMENT_CONTACT_DISTANCE)
		{
			getStreamWriter().appendValues(swingContactDistance, twistContactDistance);
		}

		static bool AreDefaultValues(double swingContactDistance, double twistContactDistance)
		{
			return swingContactDistance == ContactDistance::DefaultValue() && twistContactDistance == ContactDistance::DefaultValue();
		}
	};

	class SwingConeAndTwistExtra : public Element
	{
	public:
		SwingConeAndTwistExtra(PhysXExporter & exporter, const PhysXXML::PxD6Joint & joint)
			: Element(exporter, CSWC::CSW_ELEMENT_SWING_CONE_AND_TWIST_EXTRA)
		{
			exportRestitution(joint);
			exportBounceThreshold(joint);
			exportContactDistance(joint);
		}

		static bool HasDefaultValues(const PhysXXML::PxD6Joint & joint)
		{
			return
				Restitution2::AreDefaultValues(joint.swingLimit.restitution.restitution, joint.twistLimit.restitution.restitution) &&
				BounceThreshold2::AreDefaultValues(joint.swingLimit.bounceThreshold.bounceThreshold, joint.twistLimit.bounceThreshold.bounceThreshold) &&
				ContactDistance2::AreDefaultValues(joint.swingLimit.contactDistance.contactDistance, joint.twistLimit.contactDistance.contactDistance);
		}

	private:
		void exportRestitution(const PhysXXML::PxD6Joint & joint)
		{
			if (!Restitution2::AreDefaultValues(joint.swingLimit.restitution.restitution, joint.twistLimit.restitution.restitution))
			{
				Restitution2 e(getPhysXExporter(), joint.swingLimit.restitution.restitution, joint.twistLimit.restitution.restitution);
			}
		}

		void exportBounceThreshold(const PhysXXML::PxD6Joint & joint)
		{
			if (!BounceThreshold2::AreDefaultValues(joint.swingLimit.bounceThreshold.bounceThreshold, joint.twistLimit.bounceThreshold.bounceThreshold))
			{
				BounceThreshold2 e(getPhysXExporter(), joint.swingLimit.bounceThreshold.bounceThreshold, joint.twistLimit.bounceThreshold.bounceThreshold);
			}
		}

		void exportContactDistance(const PhysXXML::PxD6Joint & joint)
		{
			if (!ContactDistance2::AreDefaultValues(joint.swingLimit.contactDistance.contactDistance, joint.twistLimit.contactDistance.contactDistance))
			{
				ContactDistance2 e(getPhysXExporter(), joint.swingLimit.contactDistance.contactDistance, joint.twistLimit.contactDistance.contactDistance);
			}
		}
	};

	class LimitsExtra : public Element
	{
	public:
		LimitsExtra(PhysXExporter & exporter, const PhysXXML::PxD6Joint & joint)
			: Element(exporter, CSWC::CSW_ELEMENT_LIMITS_EXTRA)
		{
			exportLinearExtra(joint);
			exportSwingConeAndTwistExtra(joint);
		}

		static bool HasDefaultValues(const PhysXXML::PxD6Joint & joint)
		{
			return LimitsLinearExtra::HasDefaultValues(joint) &&
				SwingConeAndTwistExtra::HasDefaultValues(joint);
		}

	private:
		void exportLinearExtra(const PhysXXML::PxD6Joint & joint)
		{
			if (!LimitsLinearExtra::HasDefaultValues(joint))
			{
				LimitsLinearExtra e(getPhysXExporter(), joint);
			}
		}

		void exportSwingConeAndTwistExtra(const PhysXXML::PxD6Joint & joint)
		{
			if (!SwingConeAndTwistExtra::HasDefaultValues(joint))
			{
				SwingConeAndTwistExtra e(getPhysXExporter(), joint);
			}
		}
	};

	class SpringAngularExtra : public Element
	{
	public:
		SpringAngularExtra(PhysXExporter & exporter, const PhysXXML::PxD6Joint & joint)
			: Element(exporter, CSWC::CSW_ELEMENT_ANGULAR_EXTRA)
		{
			exportStiffness(joint);
			exportDamping(joint);
		}

		static bool HasDefaultValues(const PhysXXML::PxD6Joint & joint)
		{
			return joint.twistLimit.stiffness.stiffness == Stiffness::DefaultValue() &&
				joint.twistLimit.damping.damping == Damping::DefaultValue();
		}

	private:
		void exportStiffness(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.twistLimit.stiffness.stiffness != Stiffness::DefaultValue())
			{
				Stiffness e(getPhysXExporter(), joint.twistLimit.stiffness.stiffness);
			}
		}

		void exportDamping(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.twistLimit.damping.damping != Damping::DefaultValue())
			{
				Damping e(getPhysXExporter(), joint.twistLimit.damping.damping);
			}
		}
	};

	class SpringExtra : public Element
	{
	public:
		SpringExtra(PhysXExporter & exporter, const PhysXXML::PxD6Joint & joint)
			: Element(exporter, CSWC::CSW_ELEMENT_SPRING_EXTRA)
		{
			exportAngularExtra(joint);
		}

		static bool HasDefaultValues(const PhysXXML::PxD6Joint & joint)
		{
			return SpringAngularExtra::HasDefaultValues(joint);
		}

	private:
		void exportAngularExtra(const PhysXXML::PxD6Joint & joint)
		{
			if (!SpringAngularExtra::HasDefaultValues(joint))
			{
				SpringAngularExtra e(getPhysXExporter(), joint);
			}
		}
	};

	class ForceLimit : public Element
	{
	public:
		ForceLimit(PhysXExporter & exporter, double forceLimit)
			: Element(exporter, CSWC::CSW_ELEMENT_FORCE_LIMIT)
		{
			getStreamWriter().appendValues(forceLimit);
		}

		static double DefaultValue()
		{
			return infinite();
		}
	};

	class DriveFlags : public Element
	{
	public:
		DriveFlags(PhysXExporter & exporter, const Flags<PhysXXML::DriveFlags::FlagEnum> & flags)
			: Element(exporter, CSWC::CSW_ELEMENT_DRIVE_FLAGS)
		{
			getStreamWriter().appendValues(PhysXExporter::DriveFlagsToCOLLADA(flags));
		}

		static Flags<PhysXXML::DriveFlags::FlagEnum> DefaultValue()
		{
			return Flags<PhysXXML::DriveFlags::FlagEnum>();
		}
	};

	class LinearX : public Element
	{
	public:
		LinearX(PhysXExporter & exporter, const PhysXXML::PxD6Joint & joint)
			: Element(exporter, CSWC::CSW_ELEMENT_LINEAR_X)
		{
			exportStiffness(joint);
			exportDamping(joint);
			exportForceLimit(joint);
			exportDriveFlags(joint);
		}

		static bool HasDefaultValues(const PhysXXML::PxD6Joint & joint)
		{
			return joint.drive.driveX.stiffness.stiffness == Stiffness::DefaultValue() &&
				joint.drive.driveX.damping.damping == Damping::DefaultValue() &&
				joint.drive.driveX.forceLimit.forceLimit == ForceLimit::DefaultValue() &&
				joint.drive.driveX.flags.flags == DriveFlags::DefaultValue();
		}

	private:
		void exportStiffness(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveX.stiffness.stiffness != Stiffness::DefaultValue())
			{
				Stiffness e(getPhysXExporter(), joint.drive.driveX.stiffness.stiffness);
			}
		}

		void exportDamping(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveX.damping.damping != Damping::DefaultValue())
			{
				Damping e(getPhysXExporter(), joint.drive.driveX.damping.damping);
			}
		}

		void exportForceLimit(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveX.forceLimit.forceLimit != ForceLimit::DefaultValue())
			{
				ForceLimit e(getPhysXExporter(), joint.drive.driveX.forceLimit.forceLimit);
			}
		}

		void exportDriveFlags(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveX.flags.flags != DriveFlags::DefaultValue())
			{
				DriveFlags e(getPhysXExporter(), joint.drive.driveX.flags.flags);
			}
		}
	};
	
	class LinearY : public Element
	{
	public:
		LinearY(PhysXExporter & exporter, const PhysXXML::PxD6Joint & joint)
			: Element(exporter, CSWC::CSW_ELEMENT_LINEAR_Y)
		{
			exportStiffness(joint);
			exportDamping(joint);
			exportForceLimit(joint);
			exportDriveFlags(joint);
		}

		static bool HasDefaultValues(const PhysXXML::PxD6Joint & joint)
		{
			return joint.drive.driveY.stiffness.stiffness == Stiffness::DefaultValue() &&
				joint.drive.driveY.damping.damping == Damping::DefaultValue() &&
				joint.drive.driveY.forceLimit.forceLimit == ForceLimit::DefaultValue() &&
				joint.drive.driveY.flags.flags == DriveFlags::DefaultValue();
		}

	private:
		void exportStiffness(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveY.stiffness.stiffness != Stiffness::DefaultValue())
			{
				Stiffness e(getPhysXExporter(), joint.drive.driveY.stiffness.stiffness);
			}
		}

		void exportDamping(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveY.damping.damping != Damping::DefaultValue())
			{
				Damping e(getPhysXExporter(), joint.drive.driveY.damping.damping);
			}
		}

		void exportForceLimit(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveY.forceLimit.forceLimit != ForceLimit::DefaultValue())
			{
				ForceLimit e(getPhysXExporter(), joint.drive.driveY.forceLimit.forceLimit);
			}
		}

		void exportDriveFlags(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveY.flags.flags != DriveFlags::DefaultValue())
			{
				DriveFlags e(getPhysXExporter(), joint.drive.driveY.flags.flags);
			}
		}
	};

	class LinearZ : public Element
	{
	public:
		LinearZ(PhysXExporter & exporter, const PhysXXML::PxD6Joint & joint)
			: Element(exporter, CSWC::CSW_ELEMENT_LINEAR_Z)
		{
			exportStiffness(joint);
			exportDamping(joint);
			exportForceLimit(joint);
			exportDriveFlags(joint);
		}

		static bool HasDefaultValues(const PhysXXML::PxD6Joint & joint)
		{
			return joint.drive.driveZ.stiffness.stiffness == Stiffness::DefaultValue() &&
				joint.drive.driveZ.damping.damping == Damping::DefaultValue() &&
				joint.drive.driveZ.forceLimit.forceLimit == ForceLimit::DefaultValue() &&
				joint.drive.driveZ.flags.flags == DriveFlags::DefaultValue();
		}

	private:
		void exportStiffness(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveZ.stiffness.stiffness != Stiffness::DefaultValue())
			{
				Stiffness e(getPhysXExporter(), joint.drive.driveZ.stiffness.stiffness);
			}
		}

		void exportDamping(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveZ.damping.damping != Damping::DefaultValue())
			{
				Damping e(getPhysXExporter(), joint.drive.driveZ.damping.damping);
			}
		}

		void exportForceLimit(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveZ.forceLimit.forceLimit != ForceLimit::DefaultValue())
			{
				ForceLimit e(getPhysXExporter(), joint.drive.driveZ.forceLimit.forceLimit);
			}
		}

		void exportDriveFlags(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveZ.flags.flags != DriveFlags::DefaultValue())
			{
				DriveFlags e(getPhysXExporter(), joint.drive.driveZ.flags.flags);
			}
		}
	};

	class Swing : public Element
	{
	public:
		Swing(PhysXExporter & exporter, const PhysXXML::PxD6Joint & joint)
			: Element(exporter, CSWC::CSW_ELEMENT_SWING)
		{
			exportStiffness(joint);
			exportDamping(joint);
			exportForceLimit(joint);
			exportDriveFlags(joint);
		}

		static bool HasDefaultValues(const PhysXXML::PxD6Joint & joint)
		{
			return joint.drive.driveSwing.stiffness.stiffness == Stiffness::DefaultValue() &&
				joint.drive.driveSwing.damping.damping == Damping::DefaultValue() &&
				joint.drive.driveSwing.forceLimit.forceLimit == ForceLimit::DefaultValue() &&
				joint.drive.driveSwing.flags.flags == DriveFlags::DefaultValue();
		}

	private:
		void exportStiffness(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveSwing.stiffness.stiffness != Stiffness::DefaultValue())
			{
				Stiffness e(getPhysXExporter(), joint.drive.driveSwing.stiffness.stiffness);
			}
		}

		void exportDamping(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveSwing.damping.damping != Damping::DefaultValue())
			{
				Damping e(getPhysXExporter(), joint.drive.driveSwing.damping.damping);
			}
		}

		void exportForceLimit(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveSwing.forceLimit.forceLimit != ForceLimit::DefaultValue())
			{
				ForceLimit e(getPhysXExporter(), joint.drive.driveSwing.forceLimit.forceLimit);
			}
		}

		void exportDriveFlags(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveSwing.flags.flags != DriveFlags::DefaultValue())
			{
				DriveFlags e(getPhysXExporter(), joint.drive.driveSwing.flags.flags);
			}
		}
	};

	class Twist : public Element
	{
	public:
		Twist(PhysXExporter & exporter, const PhysXXML::PxD6Joint & joint)
			: Element(exporter, CSWC::CSW_ELEMENT_TWIST)
		{
			exportStiffness(joint);
			exportDamping(joint);
			exportForceLimit(joint);
			exportDriveFlags(joint);
		}

		static bool HasDefaultValues(const PhysXXML::PxD6Joint & joint)
		{
			return joint.drive.driveTwist.stiffness.stiffness == Stiffness::DefaultValue() &&
				joint.drive.driveTwist.damping.damping == Damping::DefaultValue() &&
				joint.drive.driveTwist.forceLimit.forceLimit == ForceLimit::DefaultValue() &&
				joint.drive.driveTwist.flags.flags == DriveFlags::DefaultValue();
		}

	private:
		void exportStiffness(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveTwist.stiffness.stiffness != Stiffness::DefaultValue())
			{
				Stiffness e(getPhysXExporter(), joint.drive.driveTwist.stiffness.stiffness);
			}
		}

		void exportDamping(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveTwist.damping.damping != Damping::DefaultValue())
			{
				Damping e(getPhysXExporter(), joint.drive.driveTwist.damping.damping);
			}
		}

		void exportForceLimit(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveTwist.forceLimit.forceLimit != ForceLimit::DefaultValue())
			{
				ForceLimit e(getPhysXExporter(), joint.drive.driveTwist.forceLimit.forceLimit);
			}
		}

		void exportDriveFlags(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveTwist.flags.flags != DriveFlags::DefaultValue())
			{
				DriveFlags e(getPhysXExporter(), joint.drive.driveTwist.flags.flags);
			}
		}
	};

	class Slerp : public Element
	{
	public:
		Slerp(PhysXExporter & exporter, const PhysXXML::PxD6Joint & joint)
			: Element(exporter, CSWC::CSW_ELEMENT_SLERP)
		{
			exportStiffness(joint);
			exportDamping(joint);
			exportForceLimit(joint);
			exportDriveFlags(joint);
		}

		static bool HasDefaultValues(const PhysXXML::PxD6Joint & joint)
		{
			return joint.drive.driveSlerp.stiffness.stiffness == Stiffness::DefaultValue() &&
				joint.drive.driveSlerp.damping.damping == Damping::DefaultValue() &&
				joint.drive.driveSlerp.forceLimit.forceLimit == ForceLimit::DefaultValue();
		}

	private:
		void exportStiffness(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveSlerp.stiffness.stiffness != Stiffness::DefaultValue())
			{
				Stiffness e(getPhysXExporter(), joint.drive.driveSlerp.stiffness.stiffness);
			}
		}

		void exportDamping(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveSlerp.damping.damping != Damping::DefaultValue())
			{
				Damping e(getPhysXExporter(), joint.drive.driveSlerp.damping.damping);
			}
		}

		void exportForceLimit(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveSlerp.forceLimit.forceLimit != ForceLimit::DefaultValue())
			{
				ForceLimit e(getPhysXExporter(), joint.drive.driveSlerp.forceLimit.forceLimit);
			}
		}

		void exportDriveFlags(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.drive.driveSlerp.flags.flags != DriveFlags::DefaultValue())
			{
				DriveFlags e(getPhysXExporter(), joint.drive.driveSlerp.flags.flags);
			}
		}
	};

	class LinearVelocity : public Element
	{
	public:
		LinearVelocity(PhysXExporter & exporter, const MVector & linearVelocity)
			: Element(exporter, CSWC::CSW_ELEMENT_LINEAR_VELOCITY)
		{
			getStreamWriter().appendValues(linearVelocity.x, linearVelocity.y, linearVelocity.z);
		}

		static const MVector & DefaultValue()
		{
			return MVector::zero;
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

		static const MVector & DefaultValue()
		{
			return MVector::zero;
		}
	};

	class Drive : public Element
	{
	public:
		Drive(PhysXExporter & exporter, const PhysXXML::PxD6Joint & joint)
			: Element(exporter, CSWC::CSW_ELEMENT_DRIVE)
		{
			exportLinearX(joint);
			exportLinearY(joint);
			exportLinearZ(joint);
			exportSwing(joint);
			exportTwist(joint);
			exportSlerp(joint);
			exportRotateTranslate(joint);
			exportLinearVelocity(joint);
			exportAngularVelocity(joint);
		}

		static bool HasDefaultValues(const PhysXXML::PxD6Joint & joint)
		{
			return LinearX::HasDefaultValues(joint) &&
				LinearY::HasDefaultValues(joint) &&
				LinearZ::HasDefaultValues(joint) &&
				Swing::HasDefaultValues(joint) &&
				Twist::HasDefaultValues(joint) &&
				Slerp::HasDefaultValues(joint) &&
				joint.drivePosition.translation == MVector::zero &&
				joint.drivePosition.rotation == MQuaternion::identity &&
				joint.driveVelocity.linear.linear == LinearVelocity::DefaultValue() &&
				joint.driveVelocity.angular.angular == AngularVelocity::DefaultValue();
		}

	private:
		void exportLinearX(const PhysXXML::PxD6Joint & joint)
		{
			if (!LinearX::HasDefaultValues(joint))
			{
				LinearX e(getPhysXExporter(), joint);
			}
		}

		void exportLinearY(const PhysXXML::PxD6Joint & joint)
		{
			if (!LinearY::HasDefaultValues(joint))
			{
				LinearY e(getPhysXExporter(), joint);
			}
		}

		void exportLinearZ(const PhysXXML::PxD6Joint & joint)
		{
			if (!LinearZ::HasDefaultValues(joint))
			{
				LinearZ e(getPhysXExporter(), joint);
			}
		}

		void exportSwing(const PhysXXML::PxD6Joint & joint)
		{
			if (!Swing::HasDefaultValues(joint))
			{
				Swing e(getPhysXExporter(), joint);
			}
		}

		void exportTwist(const PhysXXML::PxD6Joint & joint)
		{
			if (!Twist::HasDefaultValues(joint))
			{
				Twist e(getPhysXExporter(), joint);
			}
		}

		void exportSlerp(const PhysXXML::PxD6Joint & joint)
		{
			if (!Slerp::HasDefaultValues(joint))
			{
				Slerp e(getPhysXExporter(), joint);
			}
		}

		void exportRotateTranslate(const PhysXXML::PxD6Joint & joint)
		{
			MVector translation = joint.drivePosition.translation;
			MEulerRotation rotation = joint.drivePosition.rotation.asEulerRotation();

			getPhysXExporter().exportTranslationWithoutConversion(translation, ATTR_TRANSLATE);
			getPhysXExporter().exportRotation(rotation, ATTR_ROTATE);
		}

		void exportLinearVelocity(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.driveVelocity.linear.linear != LinearVelocity::DefaultValue())
			{
				LinearVelocity e(getPhysXExporter(), joint.driveVelocity.linear.linear);
			}
		}

		void exportAngularVelocity(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.driveVelocity.angular.angular != AngularVelocity::DefaultValue())
			{
				AngularVelocity e(getPhysXExporter(), joint.driveVelocity.angular.angular);
			}
		}
	};

	class LocalPose0 : public Element
	{
	public:
		LocalPose0(PhysXExporter& exporter, const MQuaternion& rotation, const MVector& translation)
			: Element(exporter, CSWC::CSW_ELEMENT_LOCAL_POSE_0)
		{
			double localPose[] = { rotation.x, rotation.y, rotation.z, rotation.w, translation.x, translation.y, translation.z };
			getStreamWriter().appendValues(localPose, sizeof(localPose) / sizeof(localPose[0]));
		}
	};

	class LocalPose1 : public Element
	{
	public:
		LocalPose1(PhysXExporter& exporter, const MQuaternion& rotation, const MVector& translation)
			: Element(exporter, CSWC::CSW_ELEMENT_LOCAL_POSE_1)
		{
			double localPose[] = { rotation.x, rotation.y, rotation.z, rotation.w, translation.x, translation.y, translation.z };
			getStreamWriter().appendValues(localPose, sizeof(localPose) / sizeof(localPose[0]));
		}
	};

	class PxD6Joint : public Element
	{
	public:
		PxD6Joint(PhysXExporter& exporter, const PhysXXML::PxD6Joint & joint)
			: Element(exporter, CSWC::CSW_ELEMENT_PX_D6JOINT)
		{
			getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_XMLNS, PhysXExporter::GetXMLNS());
			getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_XSI_SCHEMALOCATION, PhysXExporter::GetXSISchemaLocation());

			exportLocalPose0(joint);
			exportLocalPose1(joint);
			exportBreakForce(joint);
			exportBreakTorque(joint);
			exportConstraintFlags(joint);
			exportInvMassScale0(joint);
			exportInvInertiaScale0(joint);
			exportInvMassScale1(joint);
			exportInvInertiaScale1(joint);
			exportProjectionLinearTolerance(joint);
			exportProjectionAngularTolerance(joint);
			exportLimitsExtra(joint);
			exportSpringExtra(joint);
			exportDrive(joint);
		}

		static bool HasDefaultValues(const PhysXXML::PxD6Joint & joint)
		{
			// Always export local pose 0 and 1
			return false;
		}

	private:
		void exportLocalPose0(const PhysXXML::PxD6Joint & joint)
		{
			LocalPose0 e(getPhysXExporter(), joint.localPose.eActor0.rotation, joint.localPose.eActor0.translation);
		}

		void exportLocalPose1(const PhysXXML::PxD6Joint & joint)
		{
			LocalPose1 e(getPhysXExporter(), joint.localPose.eActor1.rotation, joint.localPose.eActor1.translation);
		}

		void exportBreakForce(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.breakForce.force.force != BreakForce::DefaultValue())
			{
				BreakForce e(getPhysXExporter(), joint.breakForce.force.force);
			}
		}

		void exportBreakTorque(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.breakForce.torque.torque != BreakTorque::DefaultValue())
			{
				BreakTorque e(getPhysXExporter(), joint.breakForce.torque.torque);
			}
		}

		void exportConstraintFlags(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.constraintFlags.flags != ConstraintFlags::DefaultValue())
			{
				ConstraintFlags e(getPhysXExporter(), joint.constraintFlags.flags);
			}
		}

		void exportInvMassScale0(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.invMassScale0.invMassScale0 != InvMassScale0::DefaultValue())
			{
				InvMassScale0 e(getPhysXExporter(), joint.invMassScale0.invMassScale0);
			}
		}

		void exportInvInertiaScale0(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.invInertiaScale0.invInertiaScale0 != InvInertiaScale0::DefaultValue())
			{
				InvInertiaScale0 e(getPhysXExporter(), joint.invInertiaScale0.invInertiaScale0);
			}
		}

		void exportInvMassScale1(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.invMassScale1.invMassScale1 != InvMassScale1::DefaultValue())
			{
				InvMassScale1 e(getPhysXExporter(), joint.invMassScale1.invMassScale1);
			}
		}

		void exportInvInertiaScale1(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.invInertiaScale1.invInertiaScale1 != InvInertiaScale1::DefaultValue())
			{
				InvInertiaScale1 e(getPhysXExporter(), joint.invInertiaScale1.invInertiaScale1);
			}
		}

		void exportProjectionLinearTolerance(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.projectionLinearTolerance.projectionLinearTolerance != ProjectionLinearTolerance::DefaultValue())
			{
				ProjectionLinearTolerance e(getPhysXExporter(), joint.projectionLinearTolerance.projectionLinearTolerance);
			}
		}

		void exportProjectionAngularTolerance(const PhysXXML::PxD6Joint & joint)
		{
			if (joint.projectionAngularTolerance.projectionAngularTolerance != ProjectionAngularTolerance::DefaultValue())
			{
				ProjectionAngularTolerance e(getPhysXExporter(), joint.projectionAngularTolerance.projectionAngularTolerance);
			}
		}

		void exportLimitsExtra(const PhysXXML::PxD6Joint & joint)
		{
			if (!LimitsExtra::HasDefaultValues(joint))
			{
				LimitsExtra e(getPhysXExporter(), joint);
			}
		}

		void exportSpringExtra(const PhysXXML::PxD6Joint & joint)
		{
			if (!SpringExtra::HasDefaultValues(joint))
			{
				SpringExtra e(getPhysXExporter(), joint);
			}
		}

		void exportDrive(const PhysXXML::PxD6Joint & joint)
		{
			if (!Drive::HasDefaultValues(joint))
			{
				Drive e(getPhysXExporter(), joint);
			}
		}
	};

    class RigidConstraintTechnique : public Element
    {
    public:
		RigidConstraintTechnique(PhysXExporter& exporter, const MObject & rigidConstraint, const PhysXXML::PxD6Joint & joint, const String & profile)
            : Element(exporter, CSWC::CSW_ELEMENT_TECHNIQUE)
        {
            getStreamWriter().appendAttribute(CSWC::CSW_ATTRIBUTE_PROFILE, profile);
			if (profile == PROFILE_MAYA) {
				exporter.exportExtraAttributes(rigidConstraint);
			}
			else if (profile == PhysXExporter::GetPhysXProfile()) {
				exportPxD6Joint(joint);
			}
        }

		static bool HasDefaultValues(const PhysXXML::PxD6Joint & joint, const String & profile)
		{
			if (profile == PhysXExporter::GetPhysXProfile())
			{
				return PxD6Joint::HasDefaultValues(joint);
			}
			return false;
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

		void exportPxD6Joint(const PhysXXML::PxD6Joint & joint)
		{
			if (!PxD6Joint::HasDefaultValues(joint))
			{
				PxD6Joint e(getPhysXExporter(), joint);
			}
		}

    private:
        static std::set<MString, MStringComp> mAttributes;
    };
    std::set<MString, MStringComp> RigidConstraintTechnique::mAttributes;

    class RigidConstraintExtra : public Element
    {
    public:
		RigidConstraintExtra(PhysXExporter& exporter, const MObject & rigidConstraint, const PhysXXML::PxD6Joint & joint)
            : Element(exporter, CSWC::CSW_ELEMENT_EXTRA)
        {
			if (PhysXExporter::HasExtraAttributes(rigidConstraint)) {
				exportTechnique(rigidConstraint, joint, PROFILE_MAYA);
			}
			exportTechnique(rigidConstraint, joint, PhysXExporter::GetPhysXProfile());
        }

    private:
		void exportTechnique(const MObject& rigidConstraint, const PhysXXML::PxD6Joint & joint, const String& profile)
        {
			if (!RigidConstraintTechnique::HasDefaultValues(joint, profile))
			{
				RigidConstraintTechnique e(getPhysXExporter(), rigidConstraint, joint, profile);
			}
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

			const PhysXXML::PxD6Joint* joint = exporter.findPxD6Joint(rigidConstraint);
			if (joint)
			{
				exportRefAttachment(*joint);
				exportAttachment(*joint);
				exportTechniqueCommon(rigidConstraint, *joint);
				exportExtra(rigidConstraint, *joint);
			}
        }

    private:
		void exportRefAttachment(const PhysXXML::PxD6Joint & joint)
        {
			MObject rigidBody;
			if (const PhysXXML::PxRigidBody* pxRigidBody = getPhysXExporter().findPxRigidBody(joint.actors.actor0.actor0))
			{
				MObject target = DagHelper::getNode(pxRigidBody->name.name.c_str());
				rigidBody = getPhysXExporter().getNodeRigidBody(target);
			}
			
            URI rigidBodyURI;
            if (rigidBody.isNull())
            {
                rigidBodyURI.set("");
            }
            else
            {
                MDagPath rigidBodyDagPath;
                MDagPath::getAPathTo(rigidBody, rigidBodyDagPath);

                String rigidBodyId = getPhysXExporter().generateColladaId(rigidBodyDagPath);
                rigidBodyURI = getPhysXExporter().getDocumentExporter().getVisualSceneExporter()->getSceneElementURI(rigidBodyDagPath, rigidBodyId);
            }

            RefAttachment e(getPhysXExporter(), joint, rigidBodyURI);
        }

		void exportAttachment(const PhysXXML::PxD6Joint & joint)
        {
			const PhysXXML::PxRigidBody* pxRigidBody = getPhysXExporter().findPxRigidBody(joint.actors.actor1.actor1);
			if (!pxRigidBody)
				return;

			MObject target = DagHelper::getNode(pxRigidBody->name.name.c_str());
			MObject rigidBody = getPhysXExporter().getNodeRigidBody(target);

            MDagPath rigidBodyDagPath;
            MDagPath::getAPathTo(rigidBody, rigidBodyDagPath);

            String rigidBodyId = getPhysXExporter().generateColladaId(rigidBodyDagPath);
            URI rigidBodyURI = getPhysXExporter().getDocumentExporter().getVisualSceneExporter()->getSceneElementURI(rigidBodyDagPath, rigidBodyId);

            Attachment e(getPhysXExporter(), joint, rigidBodyURI);
        }

		void exportTechniqueCommon(const MObject & rigidConstraint, const PhysXXML::PxD6Joint & joint)
        {
            RigidConstraintTechniqueCommon e(getPhysXExporter(), rigidConstraint, joint);
        }

		void exportExtra(const MObject & rigidConstraint, const PhysXXML::PxD6Joint & joint)
        {
            RigidConstraintExtra e(getPhysXExporter(), rigidConstraint, joint);
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

		static const MVector & DefaultValue()
		{
			return MVector::zero;
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
        }

		static bool AreDefaultValues(const MVector & angularVelocity, const MVector & velocity)
		{
			return
				angularVelocity == AngularVelocity::DefaultValue() &&
				velocity == Velocity::DefaultValue();
		}

    private:
        void exportAngularVelocity(const MVector& angularVelocity)
        {
            if (angularVelocity != AngularVelocity::DefaultValue())
            {
                AngularVelocity e(getPhysXExporter(), angularVelocity);
            }
        }

        void exportVelocity(const MVector& velocity)
        {
            if (velocity != Velocity::DefaultValue())
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

			if (!rigidBody.isNull())
			{
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
        }

    private:
        void exportTechniqueCommon(const MVector& angularVelocity, const MVector& velocity)
        {
            if (!InstanceRigidBodyTechniqueCommon::AreDefaultValues(angularVelocity, velocity))
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
                    
                    MObject target = PhysXExporter::GetRigidBodyTarget(rigidBody);
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
            MObject rigidSolver = exporter.getRigidSolver();
            if (!rigidSolver.isNull())
            {
                String name = GROUND_PLANE_NAME;
                String sid = name;

                bool useGroundPlane = false;
                DagHelper::getPlugValue(rigidSolver, ATTR_USE_GROUND_PLANE, useGroundPlane);
				const PhysXXML::PxRigidBody* groundPlane = exporter.findPxRigidBody(name);
                if (useGroundPlane && groundPlane)
                {
					InstanceRigidBody e(exporter, MObject::kNullObj, name, name, "");
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
			MObject rigidSolver = exporter.getRigidSolver();
            if (!rigidSolver.isNull())
            {
                String name = GROUND_PLANE_NAME;
                String sid = name;

                bool useGroundPlane = false;
                DagHelper::getPlugValue(rigidSolver, ATTR_USE_GROUND_PLANE, useGroundPlane);
				const PhysXXML::PxRigidBody* groundPlane = exporter.findPxRigidBody(name);
                if (useGroundPlane && groundPlane)
                {
					RigidBody e(exporter, *groundPlane, sid, name);
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
			MObject rigidSolver = exporter.getRigidSolver();
            if (!rigidSolver.isNull())
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
	String PhysXExporter::mPhysXProfile = "PhysX_3.x";
	String PhysXExporter::mXMLNS = "http://www.collada.org/2005/11/COLLADASchema_PhysX_3.x";
	String PhysXExporter::mSchemaLocation = "collada_schema_1_4_1_PhysX_3.x.xsd";

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

    bool ExtractPhysXPluginVersionNumbers(
		const MString & mversion,
        int & major,
        int & minor,
        int & a,
        int & b)
    {
        String version = mversion.asChar();

        size_t p1 = version.find('(');
        if (p1 == String::npos) return false;
        ++p1;
        if (p1 >= version.length()) return false;

        size_t p2 = version.find(')', p1);
        if (p2 == String::npos) return false;

        MString mnumbers = version.substr(p1, p2 - p1).c_str();
        MStringArray numbers;
        mnumbers.split('.', numbers);
        if (numbers.length() != 4) return false;

        std::stringstream s;
        s << numbers[0] << ' ' << numbers[1] << ' ' << numbers[2] << ' ' << numbers[3];
        s >> major >> minor >> a >> b;

        return true;
    }

    bool PhysXExporter::CheckPhysXPluginVersion()
    {
        MObject pluginObject = MFnPlugin::findPlugin("physx");

        if (pluginObject.isNull()) {
            return false;
        }

        MFnPlugin fnPlugin(pluginObject);

        MStatus status;
        MString mversion = fnPlugin.version(&status);
        if (!status) return false;

        int requ_major = 0;
        int requ_minor = 0;
        int requ_a = 0;
        int requ_b = 0;

        int curr_major = 0;
        int curr_minor = 0;
        int curr_a = 0;
        int curr_b = 0;

        if (!ExtractPhysXPluginVersionNumbers(GetRequiredPhysXPluginVersion(), requ_major, requ_minor, requ_a, requ_b)) {
            return false;
        }

        if (!ExtractPhysXPluginVersionNumbers(GetInstalledPhysXPluginVersion(), curr_major, curr_minor, curr_a, curr_b)) {
            return false;
        }

		if (curr_major > requ_major) return false;
		if (curr_major < requ_major) return false;
		if (curr_minor > requ_minor) return true;
		if (curr_minor < requ_minor) return false;
		if (curr_a > requ_a) return true;
		if (curr_a < requ_a) return false;
		if (curr_b >= requ_b) return true;
		if (curr_b < requ_b) return false;

        return true;
    }

    MString PhysXExporter::GetRequiredPhysXPluginVersion()
    {
        return MString("PhysxForMaya (3.3.10708.21402) , compiled 7/8/2015 9:40:44 PM");
    }

    MString PhysXExporter::GetInstalledPhysXPluginVersion()
    {
        static MString na = "N/A";

        MObject pluginObject = MFnPlugin::findPlugin("physx");
        if (pluginObject.isNull()) {
            return na;
        }

        MFnPlugin fnPlugin(pluginObject);

        MStatus status;
        MString version = fnPlugin.version(&status);
        if (!status) return na;

        return version;
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
            mOptions.push_back(Option("PhysXExport_UseJointLongName", Integer));
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

	class PhysicsExportPrePass
	{
	public:
		PhysicsExportPrePass(PhysXExporter & exporter)
			: mExporter(exporter)
		{}

		bool operator()(SceneElement& e)
		{
			const MObject & object = e.getNode();

			switch (e.getType())
			{
			case SceneElement::PHYSX_RIGID_BODY:
			{
				MObject target = PhysXExporter::GetRigidBodyTarget(e.getNode());
				MFnDagNode targetNode(target);
				MString targetName = targetNode.fullPathName();

				mExporter.mTargetToRigidBodyMap[target] = object;

				if (const PhysXXML::PxRigidBody* pxRigidBody = mExporter.mPhysXDoc->findRigidBody(targetName.asChar()))
				{
					mExporter.mRigidBodyToPxRigidBodyMap[object] = pxRigidBody;
					mExporter.mPxRigidBodyToRigidBodyMap[pxRigidBody] = object;

					if (pxRigidBody->shapes.shapes.size() > 0)
					{
						if (const PhysXXML::PxMaterial* pxMaterial = mExporter.mPhysXDoc->findMaterial(pxRigidBody->shapes.shapes[0].materials.materialRef.materialRef))
						{
							mExporter.mRigidBodyToPxMaterialMap[object] = pxMaterial;
						}
					}
				}
			}
			break;
			case SceneElement::PHYSX_SHAPE:
			{
				MFnDagNode shapeNode(e.getNode());
				MString shapeName = shapeNode.fullPathName();
				if (const PhysXXML::PxShape* pxShape = mExporter.mPhysXDoc->findShape(shapeName.asChar())) {
					mExporter.mShapeToPxShapeMap[object] = pxShape;
					mExporter.mPxShapeToShapeMap[pxShape] = object;
				}
			}
			break;
			case SceneElement::PHYSX_RIGID_CONSTRAINT:
			{
				MFnDagNode constraintNode(e.getNode());
				MString constraintName = constraintNode.fullPathName();
				if (const PhysXXML::PxD6Joint* joint = mExporter.mPhysXDoc->findD6Joint(constraintName.asChar())) {
					mExporter.mConstraintToPxD6JointMap[object] = joint;
					mExporter.mPxD6JointToConstraintMap[joint] = object;
				}
			}
			break;
			case SceneElement::PHYSX_RIGID_SOLVER:
			{
				mExporter.mRigidSolver = e.getNode();
			}
			break;
			default:
				break;
			}
			return true;
		}

	private:
		PhysXExporter & mExporter;
	};

    bool PhysXExporter::generatePhysXXML()
    {
        MStatus status;

        // Backup export options
        AutoRestorePhysXExportOptions autoRestorePhysXExportOptions;

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
        status = MGlobal::executeCommand("optionVar -iv \"PhysXExport_UseJointLongName\" 1");
        if (!status) return false;
        status = MGlobal::executeCommand("optionVar -iv \"PhysXExport_exportPxProjFile\" 0");
        if (!status) return false;
        status = MGlobal::executeCommand("optionVar -iv \"PhysXExport_exportPhysX\" 1");
        if (!status) return false;
        status = MGlobal::executeCommand("optionVar -sv \"PhysXExport_outputUnit\" \"meter\"");
        if (!status) return false;
        status = MGlobal::executeCommand("optionVar -iv \"PhysXExport_customScaling\" true");
        if (!status) return false;
        status = MGlobal::executeCommand("optionVar -fv \"PhysXExport_outputScale\" 1.0");
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
        pxProjPath.replace(extPos, pxProjPath.length() - extPos, ".PxProj");

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

		// Initialize physics exporter internal data
		PhysicsExportPrePass prepass(*this);
		parseSceneElements(prepass);

        return true;
    }

    bool PhysXExporter::exportPhysicsLibraries()
    {
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
            {
                LibraryPhysicsModels(*this);
            }
            {
                LibraryPhysicsScenes(*this);
            }
            hasPhysicsScene = true;
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

	void PhysXExporter::exportTranslationWithoutConversion(const MVector & translation, const String & sid)
	{
		if (!(COLLADABU::Math::Utils::equalsZero(translation.x, mDocumentExporter.getTolerance()) &&
			COLLADABU::Math::Utils::equalsZero(translation.y, mDocumentExporter.getTolerance()) &&
			COLLADABU::Math::Utils::equalsZero(translation.z, mDocumentExporter.getTolerance())))
		{
			Translate(*this, translation, sid);
		}
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

	namespace local
	{
		class ExtraAttributeExporter : public AttributeParser
		{
		public:
			ExtraAttributeExporter(COLLADASW::StreamWriter& streamWriter, const MObject & obj)
				: mStreamWriter(streamWriter)
				, mObject(obj)
			{}

		private:
			COLLADASW::StreamWriter & mStreamWriter;
			MObject mObject;

		protected:
			virtual bool onBeforePlug(MPlug & plug) override
			{
				MStatus status;

				MObject attr = plug.attribute(&status);
				if (!status) return false;

				MFnAttribute fnAttr(attr, &status);
				if (!status) return false;

				MString attrName = fnAttr.name(&status);
				if (!status) return false;

				bool isDynamic = fnAttr.isDynamic(&status);
				if (!status) return false;

				if (!isDynamic)
					return false;

				bool isHidden = fnAttr.isHidden(&status);
				if (!status) return false;

				if (isHidden)
					return false;

				return true;
			}

			template<typename ValueType>
			void exportExtraAttribute(const String & name, const String & type, const ValueType & value)
			{
				mStreamWriter.openElement(CSWC::CSW_ELEMENT_PARAM);
				mStreamWriter.appendAttribute(CSWC::CSW_ATTRIBUTE_NAME, name);
				mStreamWriter.appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
				mStreamWriter.appendValues(value);
				mStreamWriter.closeElement();
			}

			template<typename ValueType>
			void exportExtraAttribute(const String & name, const String & type, const ValueType & value0, const ValueType & value1)
			{
				mStreamWriter.openElement(CSWC::CSW_ELEMENT_PARAM);
				mStreamWriter.appendAttribute(CSWC::CSW_ATTRIBUTE_NAME, name);
				mStreamWriter.appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
				mStreamWriter.appendValues(value0, value1);
				mStreamWriter.closeElement();
			}

			template<typename ValueType>
			void exportExtraAttribute(const String & name, const String & type, const ValueType & value0, const ValueType & value1, const ValueType & value2)
			{
				mStreamWriter.openElement(CSWC::CSW_ELEMENT_PARAM);
				mStreamWriter.appendAttribute(CSWC::CSW_ATTRIBUTE_NAME, name);
				mStreamWriter.appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
				mStreamWriter.appendValues(value0, value1, value2);
				mStreamWriter.closeElement();
			}

			template<typename ValueType>
			void exportExtraAttribute(const String & name, const String & type, const ValueType & value0, const ValueType & value1, const ValueType & value2, const ValueType & value3)
			{
				mStreamWriter.openElement(CSWC::CSW_ELEMENT_PARAM);
				mStreamWriter.appendAttribute(CSWC::CSW_ATTRIBUTE_NAME, name);
				mStreamWriter.appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
				mStreamWriter.appendValues(value0, value1, value2, value3);
				mStreamWriter.closeElement();
			}

			virtual void onBoolean(MPlug & plug, const MString & name, bool value) override
			{
				exportExtraAttribute(name.asChar(), CSWC::CSW_VALUE_TYPE_BOOL, value);
			}

			virtual void onInteger(MPlug & plug, const MString & name, int value) override
			{
				exportExtraAttribute(name.asChar(), CSWC::CSW_VALUE_TYPE_INT, value);
			}

			virtual void onInteger2(MPlug & plug, const MString & name, int value[2]) override
			{
				exportExtraAttribute(name.asChar(), CSWC::CSW_VALUE_TYPE_INT2, value[0], value[1]);
			}

			virtual void onInteger3(MPlug & plug, const MString & name, int value[3]) override
			{
				exportExtraAttribute(name.asChar(), CSWC::CSW_VALUE_TYPE_INT3, value[0], value[1], value[2]);
			}

			virtual void onFloat(MPlug & plug, const MString & name, float value) override
			{
				exportExtraAttribute(name.asChar(), CSWC::CSW_VALUE_TYPE_FLOAT, value);
			}

			virtual void onFloat2(MPlug & plug, const MString & name, float value[2]) override
			{
				exportExtraAttribute(name.asChar(), CSWC::CSW_VALUE_TYPE_FLOAT2, value[0], value[1]);
			}

			virtual void onFloat3(MPlug & plug, const MString & name, float value[3]) override
			{
				exportExtraAttribute(name.asChar(), CSWC::CSW_VALUE_TYPE_FLOAT3, value[0], value[1], value[2]);
			}

			virtual void onDouble(MPlug & plug, const MString & name, double value) override
			{
				exportExtraAttribute(name.asChar(), CSWC::CSW_VALUE_TYPE_DOUBLE, value);
			}

			virtual void onDouble2(MPlug & plug, const MString & name, double value[2]) override
			{
				exportExtraAttribute(name.asChar(), CSWC::CSW_VALUE_TYPE_DOUBLE2, value[0], value[1]);
			}

			virtual void onDouble3(MPlug & plug, const MString & name, double value[3]) override
			{
				exportExtraAttribute(name.asChar(), CSWC::CSW_VALUE_TYPE_DOUBLE3, value[0], value[1], value[2]);
			}

			virtual void onDouble4(MPlug & plug, const MString & name, double value[4]) override
			{
				exportExtraAttribute(name.asChar(), CSWC::CSW_VALUE_TYPE_DOUBLE4, value[0], value[1], value[2], value[3]);
			}

			virtual void onString(MPlug & plug, const MString & name, const MString & value) override
			{
				exportExtraAttribute(name.asChar(), CSWC::CSW_VALUE_TYPE_STRING, value.asChar());
			}

			virtual void onEnum(MPlug & plug, const MString & name, int enumValue, const MString & enumName) override
			{
				// TODO export all possible enum values to be able to re-import them?
				exportExtraAttribute(name.asChar(), CSWC::CSW_VALUE_TYPE_STRING, COLLADABU::StringUtils::translateToXML(String(enumName.asChar())));
			}
		};
	}

    void PhysXExporter::exportExtraAttributes(const MObject & object)
    {
        local::ExtraAttributeExporter extraAttributeExporter(mStreamWriter, object);
		MFnDependencyNode node(object);
        AttributeParser::parseAttributes(node, extraAttributeExporter);
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

	const String & PhysXExporter::GetPhysXProfile()
	{
		return mPhysXProfile;
	}

	const String& PhysXExporter::GetXMLNS()
	{
		return mXMLNS;
	}

	String PhysXExporter::GetXSISchemaLocation()
	{
		return mXMLNS + " " + mSchemaLocation;
	}

	namespace local
	{
		class ExtraAttributeParser : public AttributeParser
		{
		public:
			ExtraAttributeParser(const MObject & obj)
				: mHasExtraAttributes(false)
			{}

			bool hasExtraAttributes() const { return mHasExtraAttributes; }

		private:
			bool mHasExtraAttributes;

		protected:
			virtual bool onBeforePlug(MPlug & plug) override
			{
				MStatus status;

				MObject attr = plug.attribute(&status);
				if (!status) return false;

				MFnAttribute fnAttr(attr, &status);
				if (!status) return false;

				MString attrName = fnAttr.name(&status);
				if (!status) return false;

				bool isDynamic = fnAttr.isDynamic(&status);
				if (!status) return false;

				if (!isDynamic)
					return false;

				bool isHidden = fnAttr.isHidden(&status);
				if (!status) return false;

				if (isHidden)
					return false;

				mHasExtraAttributes = true;

				// No need to continue parsing
				return false;
			}
		};
	}

	bool PhysXExporter::HasExtraAttributes(const MObject & object)
	{
		local::ExtraAttributeParser parser(object);
		MFnDependencyNode node(object);
		AttributeParser::parseAttributes(node, parser);
		return parser.hasExtraAttributes();
	}

	String PhysXExporter::CombineModeToCOLLADA(PhysXXML::CombineMode::FlagEnum flag)
	{
		return FlagsToCOLLADA(Flags<PhysXXML::CombineMode::FlagEnum>(flag), PhysXXML::CombineMode::GetFlagToStringMap());
	}

	String PhysXExporter::ShapeFlagsToCOLLADA(const Flags<PhysXXML::ShapeFlags::FlagEnum> & flags)
	{
		return FlagsToCOLLADA(flags, PhysXXML::ShapeFlags::GetFlagToStringMap());
	}

	String PhysXExporter::ActorFlagsToCOLLADA(const Flags<PhysXXML::ActorFlags::FlagEnum> & flags)
	{
		return FlagsToCOLLADA(flags, PhysXXML::ActorFlags::GetFlagToStringMap());
	}

	String PhysXExporter::RigidBodyFlagsToCOLLADA(const Flags<PhysXXML::RigidBodyFlags::FlagEnum> & flags)
	{
		return FlagsToCOLLADA(flags, PhysXXML::RigidBodyFlags::GetFlagToStringMap());
	}

	String PhysXExporter::ConstraintFlagsToCOLLADA(const Flags<PhysXXML::ConstraintFlags::FlagEnum> & flags)
	{
		return FlagsToCOLLADA(flags, PhysXXML::ConstraintFlags::GetFlagToStringMap());
	}

	String PhysXExporter::DriveFlagsToCOLLADA(const Flags<PhysXXML::DriveFlags::FlagEnum> & flags)
	{
		return FlagsToCOLLADA(flags, PhysXXML::DriveFlags::GetFlagToStringMap());
	}

    const String & PhysXExporter::findColladaId(const String & mayaId)
    {
        const StringToStringMap::const_iterator it = mMayaIdToColladaId.find(mayaId);
        if (it != mMayaIdToColladaId.end()) {
            return it->second;
        }
        return EMPTY_STRING;
    }

	MMatrix PhysXExporter::GetRigidBodyTargetTM(const MObject& rigidBody)
	{
		MObject target = GetRigidBodyTarget(rigidBody);
		MDagPath targetDagPath;
		MDagPath::getAPathTo(target, targetDagPath);
		return targetDagPath.inclusiveMatrix();
	}

	MObject PhysXExporter::GetRigidBodyTarget(const MObject& rigidBody)
	{
		MObject target;
		PhysXExporter::GetPluggedObject(rigidBody, ATTR_TARGET, target);

		// If target is null then use rigidBody as target
		if (target.isNull())
		{
			target = rigidBody;
		}
		return target;
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
