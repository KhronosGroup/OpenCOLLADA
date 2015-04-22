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

#include <maya/MFnAttribute.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnNumericData.h>
#include <maya/MFnTypedAttribute.h>

namespace COLLADAMaya
{
	MStatus AttributeParser::parseAttributes(MFnDependencyNode & fnNode, AttributeParser & parser)
	{
		MStatus status;
		unsigned int attrCount = fnNode.attributeCount(&status);
		for (unsigned int attrIndex = 0; attrIndex < attrCount; ++attrIndex)
		{
			MObject attrObject = fnNode.attribute(attrIndex, &status);
			MFnAttribute fnAttr(attrObject, &status);
			if (!status) continue;

			MString attrName = fnAttr.name(&status);

			if (!parser.onBeforeAttribute(fnNode, attrObject))
				continue;

			parser.parseAttribute(fnNode, attrObject);

			//if (!parser.onAfterAttribute(fnNode, attrObject))
			//	continue;
			parser.onAfterAttribute(fnNode, attrObject);
		}

		return MS::kSuccess;
	}

	MStatus AttributeParser::parseAttribute(MFnDependencyNode & node, MObject & attr)
	{
		MStatus status;

		MFnAttribute fnAttr(attr, &status);
		if (!status) return status;

		MString attrName = fnAttr.name(&status);
		if (!status) return status;

		if (attr.hasFn(MFn::kCompoundAttribute)) {
			// TODO
		}
		else if (attr.hasFn(MFn::kEnumAttribute)) {
			// TODO
		}
		else if (attr.hasFn(MFn::kGenericAttribute)) {
			// TODO
		}
		else if (attr.hasFn(MFn::kLightDataAttribute)) {
			// TODO
		}
		else if (attr.hasFn(MFn::kMatrixAttribute)) {
			// TODO
		}
		else if (attr.hasFn(MFn::kMessageAttribute)) {
			// TODO
		}
		else if (attr.hasFn(MFn::kNumericAttribute)) {
			return parseNumericAttribute(node, attr);
		}
		else if (attr.hasFn(MFn::kTypedAttribute)) {
			return parseTypedAttribute(node, attr);
		}
		else if (attr.hasFn(MFn::kUnitAttribute)) {
			// TODO
		}
		return MS::kSuccess;
	}

	MStatus AttributeParser::parseNumericAttribute(MFnDependencyNode & node, MObject & attr)
	{
		MStatus status;
		MFnNumericAttribute fnNumAttr(attr, &status);
		if (!status) return status;

		MFnNumericData::Type type = fnNumAttr.unitType(&status);
		if (!status) return status;

		MPlug plug = node.findPlug(attr, &status);
		if (!status) return status;

		return parseNumeric(plug, type);
	}

	MStatus AttributeParser::parseTypedAttribute(MFnDependencyNode & node, MObject & attr)
	{
		MStatus status;

		MFnTypedAttribute fnTypedAttr(attr, &status);
		if (!status) return status;

		MFnData::Type type = fnTypedAttr.attrType(&status);
		if (!status) return status;

		switch (type)
		{
			//! Invalid value
		case MFnData::kInvalid:
			break;

			//! Numeric, use MFnNumericData extract the node data.
		case MFnData::kNumeric:
			return parseNumericData(node, attr);
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
			return parseStringData(node, attr);
			break;

			//! Matrix, use MFnMatrixData to extract the node data.
		case MFnData::kMatrix:
			// TODO
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
			// TODO
			break;

			//! Mesh, use MFnMeshData to extract the node data.
		case MFnData::kMesh:
			// TODO
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
		return MS::kSuccess;
	}

	MStatus AttributeParser::parseNumericData(MFnDependencyNode & node, MObject & attr)
	{
		MStatus status;

		MFnNumericData fnNumericData(attr, &status);
		if (!status) return status;

		MPlug plug = node.findPlug(attr, &status);
		if (!status) return status;

		MFnNumericData::Type type = fnNumericData.numericType(&status);

		return parseNumeric(plug, type);
	}

	MStatus AttributeParser::parseNumeric(MPlug plug, MFnNumericData::Type type)
	{
		MStatus status;

		MObject attrObj = plug.attribute(&status);
		if (!status) return status;

		MFnAttribute attr(attrObj, &status);
		if (!status) return status;

		MString name = attr.name(&status);
		if (!status) return status;

		switch (type)
		{
		case MFnNumericData::kInvalid:			//!< Invalid data.
			break;
		case MFnNumericData::kBoolean:			//!< Boolean.
		{
			bool value;
			MStatus status = plug.getValue(value);
			if (!status) return status;
			return onBoolean(plug, name, value);
		}
		break;
		case MFnNumericData::kByte:				//!< One byte.
		{
			char value;
			MStatus status = plug.getValue(value);
			if (!status) return status;
			return onByte(plug, name, value);
		}
		break;
		case MFnNumericData::kChar:				//!< One character.
		{
			char value;
			MStatus status = plug.getValue(value);
			if (!status) return status;
			return onChar(plug, name, value);
		}
		break;
		case MFnNumericData::kShort:				//!< One short.
		{
			short value;
			MStatus status = plug.getValue(value);
			if (!status) return status;
			return onShort(plug, name, value);
		}
		break;
		case MFnNumericData::k2Short:			//!< Two shorts.
		{
			MStatus status;
			short value[2];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return status;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return status;
			status = plug0.getValue(value[0]);
			if (!status) return status;
			status = plug1.getValue(value[1]);
			if (!status) return status;
			return onShort2(plug, name, value);
		}
		break;
		case MFnNumericData::k3Short:			//!< Three shorts.
		{
			MStatus status;
			short value[3];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return status;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return status;
			MPlug plug2 = plug.child(2, &status);
			if (!status) return status;
			status = plug0.getValue(value[0]);
			if (!status) return status;
			status = plug1.getValue(value[1]);
			if (!status) return status;
			status = plug2.getValue(value[2]);
			if (!status) return status;
			return onShort3(plug, name, value);
		}
		break;
		case MFnNumericData::kLong:				//!< One long. Same as int since "long" is not platform-consistent.
		{
			int value;
			MStatus status = plug.getValue(value);
			if (!status) return status;
			return onLong(plug, name, value);
		}
		break;
		//case MFnNumericData::Type::kInt:		//!< One int.
		//	break;
		case MFnNumericData::k2Long:				//!< Two longs. Same as 2 ints since "long" is not platform-consistent.
		{
			MStatus status;
			int value[2];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return status;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return status;
			status = plug0.getValue(value[0]);
			if (!status) return status;
			status = plug1.getValue(value[1]);
			if (!status) return status;
			return onLong2(plug, name, value);
		}
		break;
		//case MFnNumericData::Type::k2Int:		//!< Two ints.
		//	break;
		case MFnNumericData::k3Long:				//!< Three longs. Same as 3 ints since "long" is not platform-consistent.
		{
			MStatus status;
			int value[3];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return status;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return status;
			MPlug plug2 = plug.child(2, &status);
			if (!status) return status;
			status = plug0.getValue(value[0]);
			if (!status) return status;
			status = plug1.getValue(value[1]);
			if (!status) return status;
			status = plug2.getValue(value[2]);
			if (!status) return status;
			return onLong3(plug, name, value);
		}
		break;
		//case MFnNumericData::Type::k3Int:		//!< Three ints.
		//	break;
		case MFnNumericData::kFloat:				//!< One float.
		{
			float value;
			MStatus status = plug.getValue(value);
			if (!status) return status;
			return onFloat(plug, name, value);
		}
		break;
		case MFnNumericData::k2Float:			//!< Two floats.
		{
			MStatus status;
			float value[2];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return status;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return status;
			status = plug0.getValue(value[0]);
			if (!status) return status;
			status = plug1.getValue(value[1]);
			if (!status) return status;
			return onFloat2(plug, name, value);
		}
		break;
		case MFnNumericData::k3Float:			//!< Three floats.
		{
			MStatus status;
			float value[3];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return status;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return status;
			MPlug plug2 = plug.child(2, &status);
			if (!status) return status;
			status = plug0.getValue(value[0]);
			if (!status) return status;
			status = plug1.getValue(value[1]);
			if (!status) return status;
			status = plug2.getValue(value[2]);
			if (!status) return status;
			return onFloat3(plug, name, value);
		}
		break;
		case MFnNumericData::kDouble:			//!< One double.
		{
			double value;
			MStatus status = plug.getValue(value);
			if (!status) return status;
			return onDouble(plug, name, value);
		}
		break;
		case MFnNumericData::k2Double:			//!< Two doubles.
		{
			MStatus status;
			double value[2];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return status;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return status;
			status = plug0.getValue(value[0]);
			if (!status) return status;
			status = plug1.getValue(value[1]);
			if (!status) return status;
			return onDouble2(plug, name, value);
		}
		break;
		case MFnNumericData::k3Double:			//!< Three doubles.
		{
			MStatus status;
			double value[3];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return status;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return status;
			MPlug plug2 = plug.child(2, &status);
			if (!status) return status;
			status = plug0.getValue(value[0]);
			if (!status) return status;
			status = plug1.getValue(value[1]);
			if (!status) return status;
			status = plug2.getValue(value[2]);
			if (!status) return status;
			return onDouble3(plug, name, value);
		}
		break;
		case MFnNumericData::k4Double:			//!< Four doubles.
		{
			MStatus status;
			double value[4];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return status;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return status;
			MPlug plug2 = plug.child(2, &status);
			if (!status) return status;
			MPlug plug3 = plug.child(3, &status);
			if (!status) return status;
			status = plug0.getValue(value[0]);
			if (!status) return status;
			status = plug1.getValue(value[1]);
			if (!status) return status;
			status = plug2.getValue(value[2]);
			if (!status) return status;
			status = plug3.getValue(value[3]);
			if (!status) return status;
			return onDouble4(plug, name, value);
		}
		break;
		case MFnNumericData::kAddr:				//!< An address.
			// TODO
			break;
		default:
			break;
		}
		return MS::kSuccess;
	}

	MStatus AttributeParser::parseStringData(MFnDependencyNode & node, MObject & attr)
	{
		MStatus status;

		MPlug plug = node.findPlug(attr, &status);
		if (!status) return status;

		MString value;
		status = plug.getValue(value);
		if (!status) return status;

		if (value.length() == 0)
			return MS::kFailure;

		MFnAttribute fnAttr(attr, &status);
		if (!status) return status;

		MString name = fnAttr.name(&status);
		if (!status) return status;
		
		return onString(plug, name, value);
	}
}
