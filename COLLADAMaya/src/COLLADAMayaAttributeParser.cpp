/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

#include <maya/MAngle.h>
#include <maya/MDataHandle.h>
#include <maya/MDistance.h>
#include <maya/MFnAttribute.h>
#include <maya/MFnComponentListData.h>
#include <maya/MFnCompoundAttribute.h>
#include <maya/MFnEnumAttribute.h>
#include <maya/MFnGenericAttribute.h>
#include <maya/MFnLightDataAttribute.h>
#include <maya/MFnMatrixData.h>
#include <maya/MFnMesh.h>
#include <maya/MFnMessageAttribute.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnUnitAttribute.h>
#include <maya/MTime.h>

namespace COLLADAMaya
{
	void AttributeParser::parseAttributes(MFnDependencyNode & fnNode, AttributeParser & parser)
	{
		MStatus status;
		unsigned int attrCount = fnNode.attributeCount(&status);
        if (!status) return;
        std::set<String> parsedAttributes;
		for (unsigned int attrIndex = 0; attrIndex < attrCount; ++attrIndex)
		{
			MObject attrObject = fnNode.attribute(attrIndex, &status);
            if (!status) continue;

			MFnAttribute fnAttr(attrObject, &status);
			if (!status) continue;

			MString attrName = fnAttr.name(&status);
            if (!status) continue;

            // Don't parse the same attribute twice.
            // This can happen with compound attributes.
            String attrNameStr = attrName.asChar();
            if (parsedAttributes.find(attrNameStr) != parsedAttributes.end()) {
                continue;
            }
            parsedAttributes.insert(attrNameStr);

			parser.parseAttribute(fnNode, attrObject, parsedAttributes);
		}
	}

    class AutoOnAfterAttribute
    {
    public:
        AutoOnAfterAttribute(AttributeParser& parser, MFnDependencyNode& node, MObject& attribute)
            : mParser(parser)
            , mNode(node)
            , mAttribute(attribute)
        {}

        ~AutoOnAfterAttribute()
        {
            mParser.onAfterAttribute(mNode, mAttribute);
        }

    private:
        AttributeParser& mParser;
        MFnDependencyNode& mNode;
        MObject& mAttribute;
    };

	void AttributeParser::parseAttribute(MFnDependencyNode & node, MObject & attr, std::set<String>& parsedAttributes)
	{
        AutoOnAfterAttribute onAfterAttribute(*this, node, attr);

        if (!onBeforeAttribute(node, attr)) {
            // Skip attribute
            return;
        }

        MStatus status;

		MFnAttribute fnAttr(attr, &status);
		if (!status) return;

		MString attrName = fnAttr.name(&status);
		if (!status) return;

		// First handle numeric compound types
		MFnNumericData::Type type;
		if (IsNumericCompoundAttribute(attr, type))
		{
			MPlug plug = node.findPlug(attr, &status);
			if (!status) return;

			parseNumeric(plug, type);

			// Mark children as parsed
			MFnCompoundAttribute fnCompoundAttribute(attr, &status);
			if (!status) return;

			unsigned int numChildren = fnCompoundAttribute.numChildren(&status);
			if (!status) return;

			for (unsigned int i = 0; i < fnCompoundAttribute.numChildren(); ++i)
			{
				MObject child = fnCompoundAttribute.child(i, &status);
				if (!status) return;

				MFnAttribute childFnAttr(child);
				parsedAttributes.insert(childFnAttr.name().asChar());
			}
		}
		// Other cases
		else if (attr.hasFn(MFn::kCompoundAttribute)) {
            parseCompoundAttribute(node, attr, parsedAttributes);
		}
		else if (attr.hasFn(MFn::kEnumAttribute)) {
            parseEnumAttribute(node, attr);
		}
		else if (attr.hasFn(MFn::kGenericAttribute)) {
			parseGenericAttribute(node, attr);
		}
		else if (attr.hasFn(MFn::kLightDataAttribute)) {
			parseLightDataAttribute(node, attr);
		}
		else if (attr.hasFn(MFn::kMatrixAttribute)) {
            parseMatrixAttribute(node, attr);
		}
		else if (attr.hasFn(MFn::kMessageAttribute)) {
            parseMessageAttribute(node, attr);
		}
		else if (attr.hasFn(MFn::kNumericAttribute)) {
			parseNumericAttribute(node, attr);
		}
		else if (attr.hasFn(MFn::kTypedAttribute)) {
			parseTypedAttribute(node, attr);
		}
		else if (attr.hasFn(MFn::kUnitAttribute)) {
            parseUnitAttribute(node, attr);
		}
	}

	void AttributeParser::parseNumericAttribute(MFnDependencyNode & node, MObject & attr)
	{
		MStatus status;
		MFnNumericAttribute fnNumAttr(attr, &status);
		if (!status) return;

		MFnNumericData::Type type = fnNumAttr.unitType(&status);
		if (!status) return;

		MPlug plug = node.findPlug(attr, &status);
		if (!status) return;

		parseNumeric(plug, type);
	}

	void AttributeParser::parseTypedAttribute(MFnDependencyNode & node, MObject & attr)
	{
		MStatus status;

		MFnTypedAttribute fnTypedAttr(attr, &status);
		if (!status) return;

		MFnData::Type type = fnTypedAttr.attrType(&status);
		if (!status) return;

		switch (type)
		{
			//! Invalid value
		case MFnData::kInvalid:
			break;

			//! Numeric, use MFnNumericData extract the node data.
		case MFnData::kNumeric:
			parseNumericData(node, attr);
			break;

			//! Plugin Blind Data, use MFnPluginData to extract the node data.
		case MFnData::kPlugin:
			// TODO
			break;

			//! Plugin Geometry, use MFnGeometryData to extract the node data.
		case MFnData::kPluginGeometry:
			// TODO
			break;

			//! String, use MFnStringData to extract the node data.
		case MFnData::kString:
			parseStringData(node, attr);
			break;

			//! Matrix, use MFnMatrixData to extract the node data.
		case MFnData::kMatrix:
			parseMatrixAttribute(node, attr);
			break;

			//! String Array, use MFnStringArrayData to extract the node data.
		case MFnData::kStringArray:
			// TODO
			break;

			//! Double Array, use MFnDoubleArrayData to extract the node data.
		case MFnData::kDoubleArray:
			// TODO
			break;

#if MAYA_API_VERSION >= 201400
			//! Float Array, use MFnFloatArrayData to extract the node data.
		case MFnData::kFloatArray:
			// TODO
			break;
#endif

			//! Int Array, use MFnIntArrayData to extract the node data.
		case MFnData::kIntArray:
			// TODO
			break;

			//! Point Array, use MFnPointArrayData to extract the node data.
		case MFnData::kPointArray:
			// TODO
			break;

			//! Vector Array, use MFnVectorArrayData to extract the node data.
		case MFnData::kVectorArray:
			// TODO
			break;

			//! Component List, use MFnComponentListData to extract the node data.
		case MFnData::kComponentList:
			parseComponentListData(node, attr);
			break;

			//! Mesh, use MFnMeshData to extract the node data.
		case MFnData::kMesh:
            parseMeshData(node, attr);
			break;

			//! Lattice, use MFnLatticeData to extract the node data.
		case MFnData::kLattice:
			// TODO
			break;

			//! Nurbs Curve, use MFnNurbsCurveData to extract the node data.
		case MFnData::kNurbsCurve:
			// TODO
			break;

			//! Nurbs Surface, use MFnNurbsSurfaceData to extract the node data.
		case MFnData::kNurbsSurface:
			// TODO
			break;

			//! Sphere, use MFnSphereData to extract the node data.
		case MFnData::kSphere:
			// TODO
			break;

			//! ArrayAttrs, use MFnArrayAttrsData to extract the node data.
		case MFnData::kDynArrayAttrs:
			// TODO
			break;

			/*! SweptGeometry, use MFnDynSweptGeometryData to extract the
			node data. This data node is in OpenMayaFX which must be
			linked to.
			*/
		case MFnData::kDynSweptGeometry:
			// TODO
			break;

			//! Subdivision Surface, use MFnSubdData to extract the node data.
		case MFnData::kSubdSurface:
			// TODO
			break;

			//! nObject data, use MFnNObjectData to extract node data
		case MFnData::kNObject:
			// TODO
			break;

			//! nId data, use MFnNIdData to extract node data
		case MFnData::kNId:
			// TODO
			break;

#if MAYA_API_VERSION >= 201200
			//! Typically used when the data can be one of several types.
		case MFnData::kAny:
			// TODO
			break;
#endif

		default:
			break;
		}
	}

    void AttributeParser::parseEnumAttribute(MFnDependencyNode & node, MObject & attr)
    {
        MStatus status;

        MFnEnumAttribute fnEnumAttribute(attr, &status);
        if (!status) return;

        MPlug plug = node.findPlug(attr, &status);
        if (!status) return;

        int enumValue = 0;
        status = plug.getValue(enumValue);
        if (!status) return;

        MString enumName = fnEnumAttribute.fieldName(enumValue, &status);
        if (!status) return;

        MString name = fnEnumAttribute.name(&status);
        if (!status) return;

        onEnum(plug, name, enumValue, enumName);
    }

    void AttributeParser::parseMessageAttribute(MFnDependencyNode & node, MObject & attr)
    {
        MStatus status;

        MFnMessageAttribute fnMessageAttribute(attr, &status);
        if (!status) return;

        MPlug plug = node.findPlug(attr, &status);
        if (!status) return;

        MFnAttribute fnAttribute(attr, &status);
        if (!status) return;

        MString name = fnAttribute.name(&status);
        if (!status) return;

        onMessage(plug, name);
    }

    void AttributeParser::parseMatrixAttribute(MFnDependencyNode & node, MObject & attribute)
    {
        MStatus status;

        MPlug plug = node.findPlug(attribute, &status);
        if (!status) return;

        MFnAttribute fnAttribute(attribute, &status);
        if (!status) return;

        MString name = fnAttribute.name(&status);
        if (!status) return;

        MFnMatrixData mxData;
        MObject object = mxData.create(&status);
        if (!status) return;

        status = plug.getValue(object);
        if (!status) return;

        status = mxData.setObject(object);
        if (!status) return;
        
        const MMatrix& matrix = mxData.matrix();

        onMatrix(plug, name, matrix);
    }

    void AttributeParser::parseCompoundAttribute(MFnDependencyNode & node, MObject & attr, std::set<String>& parsedAttributes)
    {
        MStatus status;

        MFnCompoundAttribute fnCompoundAttribute(attr, &status);
        if (!status) return;

        unsigned int numChildren = fnCompoundAttribute.numChildren(&status);
        if (!status) return;

        MPlug plug = node.findPlug(attr, &status);
        if (!status) return;

        MFnAttribute fnAttr(attr, &status);
        if (!status) return;

        MString name = fnAttr.name(&status);
        if (!status) return;

        onCompoundAttribute(plug, name);

        // Recurse children
        for (unsigned int i = 0; i < fnCompoundAttribute.numChildren(); ++i)
        {
            MObject child = fnCompoundAttribute.child(i, &status);
            if (!status) continue;

            MFnAttribute childFnAttr(child, &status);
            if (!status) continue;

            parsedAttributes.insert(childFnAttr.name().asChar());

            parseAttribute(node, child, parsedAttributes);
        }
    }

    void AttributeParser::parseUnitAttribute(MFnDependencyNode & node, MObject & attr)
    {
        MStatus status;

        MFnUnitAttribute fnAttr(attr, &status);
        if (!status) return;

        MFnUnitAttribute::Type unitType = fnAttr.unitType(&status);
        if (!status) return;

        MPlug plug = node.findPlug(attr, &status);
        if (!status) return;

        MString name = fnAttr.name(&status);
        if (!status) return;

        switch (unitType)
        {
        case MFnUnitAttribute::kAngle:
        {
            MAngle angle;
            status = plug.getValue(angle);
            if (!status) return;
            onAngle(plug, name, angle);
        }
        break;

        case MFnUnitAttribute::kDistance:
        {
            MDistance distance;
            status = plug.getValue(distance);
            if (!status) return;
            onDistance(plug, name, distance);
        }
        break;

        case MFnUnitAttribute::kTime:
        {
            MTime time;
            status = plug.getValue(time);
            if (!status) return;
            onTime(plug, name, time);
        }
        break;
        }
    }

    void AttributeParser::parseGenericAttribute(MFnDependencyNode & node, MObject & attr)
    {
        MStatus status;

        MFnGenericAttribute genericAttribute(attr, &status);
        if (!status) return;

        MPlug plug = node.findPlug(attr, &status);
		if (!status) return;

        MFn::Type type = genericAttribute.type();
    }
	
    void AttributeParser::parseLightDataAttribute(MFnDependencyNode & node, MObject & attr)
    {
        MStatus status;

        MFnLightDataAttribute lightDataAttribute(attr, &status);
        if (!status) return;

        // TODO

  //      MObject directionX = fnLightDataAttribute.child(0, &status);
  //      if (!status) return;
		//MObject directionY = fnLightDataAttribute.child(1, &status);
  //      if (!status) return;
		//MObject directionZ = fnLightDataAttribute.child(2, &status);
  //      if (!status) return;
		//MObject intensityR = fnLightDataAttribute.child(3, &status);
  //      if (!status) return;
		//MObject intensityG = fnLightDataAttribute.child(4, &status);
  //      if (!status) return;
		//MObject intensityB = fnLightDataAttribute.child(5, &status);
  //      if (!status) return;
		//MObject ambient = fnLightDataAttribute.child(6, &status);
  //      if (!status) return;
		//MObject diffuse = fnLightDataAttribute.child(7, &status);
  //      if (!status) return;
		//MObject specular = fnLightDataAttribute.child(8, &status);
  //      if (!status) return;
		//MObject shadowFraction = fnLightDataAttribute.child(9, &status);
  //      if (!status) return;
		//MObject preShadowIntensity = fnLightDataAttribute.child(10, &status);
  //      if (!status) return;
    }

	void AttributeParser::parseNumericData(MFnDependencyNode & node, MObject & attr)
	{
		MStatus status;

		MFnNumericData fnNumericData(attr, &status);
		if (!status) return;

		MPlug plug = node.findPlug(attr, &status);
		if (!status) return;

		MFnNumericData::Type type = fnNumericData.numericType(&status);

		parseNumeric(plug, type);
	}

	void AttributeParser::parseNumeric(MPlug plug, MFnNumericData::Type type)
	{
		MStatus status;

		MObject attrObj = plug.attribute(&status);
		if (!status) return;

		MFnAttribute attr(attrObj, &status);
		if (!status) return;

		MString name = attr.name(&status);
		if (!status) return;

		switch (type)
		{
		case MFnNumericData::kInvalid:			//!< Invalid data.
			break;
		case MFnNumericData::kBoolean:			//!< Boolean.
		{
			bool value;
			status = plug.getValue(value);
			if (!status) return;
			onBoolean(plug, name, value);
		}
		break;
		case MFnNumericData::kByte:				//!< One byte.
		{
			char value;
			status = plug.getValue(value);
			if (!status) return;
			onByte(plug, name, value);
		}
		break;
		case MFnNumericData::kChar:				//!< One character.
		{
			char value;
			status = plug.getValue(value);
			if (!status) return;
			onChar(plug, name, value);
		}
		break;
		case MFnNumericData::kShort:				//!< One short.
		{
			short value;
			status = plug.getValue(value);
			if (!status) return;
			onShort(plug, name, value);
		}
		break;
		case MFnNumericData::k2Short:			//!< Two shorts.
		{
			MObject object;
			status = plug.getValue(object);
			if (!status) return;
			MFnNumericData fnNumericData(object, &status);
			if (!status) return;
			short value[2];
			status = fnNumericData.getData(value[0], value[1]);
			if (!status) return;
			onShort2(plug, name, value);
		}
		break;
		case MFnNumericData::k3Short:			//!< Three shorts.
		{
			MObject object;
			status = plug.getValue(object);
			if (!status) return;
			MFnNumericData fnNumericData(object, &status);
			if (!status) return;
			short value[3];
			status = fnNumericData.getData(value[0], value[1], value[2]);
			if (!status) return;
			onShort3(plug, name, value);
		}
		break;
		case MFnNumericData::kInt:				//!< One long. Same as int since "long" is not platform-consistent.
		{
			int value;
			status = plug.getValue(value);
			if (!status) return;
			onInteger(plug, name, value);
		}
		break;
		case MFnNumericData::k2Int:				//!< Two longs. Same as 2 ints since "long" is not platform-consistent.
		{
			MObject object;
			status = plug.getValue(object);
			if (!status) return;
			MFnNumericData fnNumericData(object, &status);
			if (!status) return;
			int value[2];
			status = fnNumericData.getData(value[0], value[1]);
			if (!status) return;
			onInteger2(plug, name, value);
		}
		break;
		case MFnNumericData::k3Int:				//!< Three longs. Same as 3 ints since "long" is not platform-consistent.
		{
			MObject object;
			status = plug.getValue(object);
			if (!status) return;
			MFnNumericData fnNumericData(object, &status);
			if (!status) return;
			int value[3];
			status = fnNumericData.getData(value[0], value[1], value[2]);
			if (!status) return;
			onInteger3(plug, name, value);
		}
		break;
		case MFnNumericData::kFloat:				//!< One float.
		{
            MFn::Type apiType = attrObj.apiType();
            switch (apiType)
            {
            case MFn::kFloatAngleAttribute:
            {
                MAngle angle = plug.asMAngle(MDGContext::fsNormal, &status);
                if (!status) return;
                onAngle(plug, name, angle);
            }
            break;
            case MFn::kFloatLinearAttribute:
            {
                MDistance distance = plug.asMDistance(MDGContext::fsNormal, &status);
                if (!status) return;
                onDistance(plug, name, distance);
            }
            break;
            default:
            {
                float value = plug.asFloat(MDGContext::fsNormal, &status);
                if (!status) return;
                onFloat(plug, name, value);
            }
            break;
            }
		}
		break;
		case MFnNumericData::k2Float:			//!< Two floats.
		{
            const unsigned int numChildren = 2;

			MPlug childPlugs[numChildren];
            for (unsigned int i = 0; i < numChildren; ++i) {
                childPlugs[i] = plug.child(i, &status);
                if (!status) return;
            }

            MObject childAttr[numChildren];
            for (unsigned int i = 0; i < numChildren; ++i) {
                childAttr[i] = childPlugs[i].attribute(&status);
                if (!status) return;
            }

            MFn::Type apiType = childAttr[0].apiType();
            switch (apiType)
            {
            case MFn::kFloatAngleAttribute:
            {
                MAngle angles[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    angles[i] = childPlugs[i].asMAngle(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onAngle2(plug, name, angles);
            }
            break;
            case MFn::kFloatLinearAttribute:
            {
                MDistance distances[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    distances[i] = childPlugs[i].asMDistance(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onDistance2(plug, name, distances);
            }
            break;
            default:
            {
                float values[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    values[i] = childPlugs[i].asFloat(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onFloat2(plug, name, values);
            }
            break;
            }
		}
		break;
		case MFnNumericData::k3Float:			//!< Three floats.
		{
            const unsigned int numChildren = 3;

			MPlug childPlugs[numChildren];
            for (unsigned int i = 0; i < numChildren; ++i) {
                childPlugs[i] = plug.child(i, &status);
                if (!status) return;
            }

            MObject childAttr[numChildren];
            for (unsigned int i = 0; i < numChildren; ++i) {
                childAttr[i] = childPlugs[i].attribute(&status);
                if (!status) return;
            }

            MFn::Type apiType = childAttr[0].apiType();
            switch (apiType)
            {
            case MFn::kFloatAngleAttribute:
            {
                MAngle angles[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    angles[i] = childPlugs[i].asMAngle(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onAngle3(plug, name, angles);
            }
            break;
            case MFn::kFloatLinearAttribute:
            {
                MDistance distances[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    distances[i] = childPlugs[i].asMDistance(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onDistance3(plug, name, distances);
            }
            break;
            default:
            {
                float values[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    values[i] = childPlugs[i].asFloat(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onFloat3(plug, name, values);
            }
            break;
            }
		}
		break;
		case MFnNumericData::kDouble:			//!< One double.
		{
            MFn::Type apiType = attrObj.apiType();
            switch (apiType)
            {
            case MFn::kDoubleAngleAttribute:
            {
                MAngle angle = plug.asMAngle(MDGContext::fsNormal, &status);
                if (!status) return;
                onAngle(plug, name, angle);
            }
            break;
            case MFn::kDoubleLinearAttribute:
            {
                MDistance distance = plug.asMDistance(MDGContext::fsNormal, &status);
                if (!status) return;
                onDistance(plug, name, distance);
            }
            break;
            default:
            {
                double value = plug.asDouble(MDGContext::fsNormal, &status);
                if (!status) return;
                onDouble(plug, name, value);
            }
            break;
            }
		}
		break;
		case MFnNumericData::k2Double:			//!< Two doubles.
		{
			const unsigned int numChildren = 2;

			MPlug childPlugs[numChildren];
            for (unsigned int i = 0; i < numChildren; ++i) {
                childPlugs[i] = plug.child(i, &status);
                if (!status) return;
            }

            MObject childAttr[numChildren];
            for (unsigned int i = 0; i < numChildren; ++i) {
                childAttr[i] = childPlugs[i].attribute(&status);
                if (!status) return;
            }

            MFn::Type apiType = childAttr[0].apiType();
            switch (apiType)
            {
            case MFn::kDoubleAngleAttribute:
            {
                MAngle angles[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    angles[i] = childPlugs[i].asMAngle(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onAngle2(plug, name, angles);
            }
            break;
            case MFn::kDoubleLinearAttribute:
            {
                MDistance distances[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    distances[i] = childPlugs[i].asMDistance(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onDistance2(plug, name, distances);
            }
            break;
            default:
            {
                double values[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    values[i] = childPlugs[i].asDouble(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onDouble2(plug, name, values);
            }
            break;
            }
		}
		break;
		case MFnNumericData::k3Double:			//!< Three doubles.
		{
			const unsigned int numChildren = 3;

			MPlug childPlugs[numChildren];
            for (unsigned int i = 0; i < numChildren; ++i) {
                childPlugs[i] = plug.child(i, &status);
                if (!status) return;
            }

            MObject childAttr[numChildren];
            for (unsigned int i = 0; i < numChildren; ++i) {
                childAttr[i] = childPlugs[i].attribute(&status);
                if (!status) return;
            }

            MFn::Type apiType = childAttr[0].apiType();
            switch (apiType)
            {
            case MFn::kDoubleAngleAttribute:
            {
                MAngle angles[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    angles[i] = childPlugs[i].asMAngle(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onAngle3(plug, name, angles);
            }
            break;
            case MFn::kDoubleLinearAttribute:
            {
                MDistance distances[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    distances[i] = childPlugs[i].asMDistance(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onDistance3(plug, name, distances);
            }
            break;
            default:
            {
                double values[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    values[i] = childPlugs[i].asDouble(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onDouble3(plug, name, values);
            }
            break;
            }
		}
		break;
		case MFnNumericData::k4Double:			//!< Four doubles.
		{
			const unsigned int numChildren = 4;

			MPlug childPlugs[numChildren];
            for (unsigned int i = 0; i < numChildren; ++i) {
                childPlugs[i] = plug.child(i, &status);
                if (!status) return;
            }

            MObject childAttr[numChildren];
            for (unsigned int i = 0; i < numChildren; ++i) {
                childAttr[i] = childPlugs[i].attribute(&status);
                if (!status) return;
            }

            MFn::Type apiType = childAttr[0].apiType();
            switch (apiType)
            {
            case MFn::kDoubleAngleAttribute:
            {
                MAngle angles[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    angles[i] = childPlugs[i].asMAngle(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onAngle4(plug, name, angles);
            }
            break;
            case MFn::kDoubleLinearAttribute:
            {
                MDistance distances[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    distances[i] = childPlugs[i].asMDistance(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onDistance4(plug, name, distances);
            }
            break;
            default:
            {
                double values[numChildren];
                for (unsigned int i = 0; i < numChildren; ++i) {
                    values[i] = childPlugs[i].asDouble(MDGContext::fsNormal, &status);
                    if (!status) return;
                }
                onDouble4(plug, name, values);
            }
            break;
            }
		}
		break;
		case MFnNumericData::kAddr:				//!< An address.
			// TODO
			break;
		default:
			break;
		}
	}

	void AttributeParser::parseStringData(MFnDependencyNode & node, MObject & attr)
	{
		MStatus status;

		MPlug plug = node.findPlug(attr, &status);
		if (!status) return;

		MString value;
		status = plug.getValue(value);
		if (!status) return;

		if (value.length() == 0)
			return;

		MFnAttribute fnAttr(attr, &status);
		if (!status) return;

		MString name = fnAttr.name(&status);
		if (!status) return;
		
		onString(plug, name, value);
	}

    void AttributeParser::parseMeshData(MFnDependencyNode & node, MObject & attr)
    {
        MStatus status;

        MPlug plug = node.findPlug(attr, &status);
        if (!status) return;

        MObject meshNode;
        MPlugArray plugArray;
        bool success = plug.connectedTo(plugArray, true, false, &status);
        if (!status) return;
        if (success)
        {
            MPlug extPlug = plugArray[0];
            bool hasConnection = !extPlug.isNull(&status);
            if (!status) return;
            if (hasConnection)
            {
                meshNode = extPlug.node(&status);
                if (!status) return;
            }
        }

        /*
        MDataHandle dataHandle;
        status = plug.getValue(dataHandle);
        if (!status) return;

        MObject meshData;
        status = plug.getValue(meshData);
        if (!status) return;

        MFnMesh fnMesh(meshData, &status);
        if (!status) return;

        MDagPath dagPath = fnMesh.dagPath(&status);
        if (!status) return;

        MObject meshNode = dagPath.node(&status);
        */

        MFnAttribute fnAttr(attr, &status);
        if (!status) return;

        MString name = fnAttr.name(&status);
        if (!status) return;

        onMesh(plug, name, meshNode);
    }

    void AttributeParser::parseComponentListData (MFnDependencyNode & fnNode, MObject & attribute)
    {
        MStatus status;

        MFnComponentListData componentListData;

        MObject objectData = componentListData.create(&status);
        if (!status) return;

        MPlug plug = fnNode.findPlug(attribute, &status);
        if (!status) return;

        status = plug.getValue(objectData);
        if (!status) return;

        status = componentListData.setObject(objectData);
        if (!status) return;

        unsigned int length = componentListData.length(&status);
        if (!status) return;

        for (unsigned int i = 0; i < length; ++i) {
            MObject object = componentListData[i];
        }

        // TODO
    }

	bool AttributeParser::IsNumericCompoundAttribute(const MObject& attr, MFnNumericData::Type& type)
	{
		MFn::Type apiType = attr.apiType();
		switch (apiType)
		{
		case MFn::kAttribute2Double:
			type = MFnNumericData::k2Double;
			return true;
		case MFn::kAttribute2Float:
			type = MFnNumericData::k2Float;
			return true;
		case MFn::kAttribute2Int:
			type = MFnNumericData::k2Int;
			return true;
		case MFn::kAttribute2Short:
			type = MFnNumericData::k2Short;
			return true;
		case MFn::kAttribute3Double:
			type = MFnNumericData::k3Double;
			return true;
		case MFn::kAttribute3Float:
			type = MFnNumericData::k3Float;
			return true;
		case MFn::kAttribute3Int:
			type = MFnNumericData::k3Int;
			return true;
		case MFn::kAttribute3Short:
			type = MFnNumericData::k3Short;
			return true;
		case MFn::kAttribute4Double:
			type = MFnNumericData::k4Double;
			return true;
		}
		return false;
	}
}
