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

// TODO remove unused headers
#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaShaderFXShaderExporter.h"
#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaConversion.h"
#include "COLLADAMayaExportOptions.h"

#include "COLLADASWPass.h"
#include "COLLADASWRenderState.h"
#include "COLLADASWShader.h"
#include "COLLADASWAnnotation.h"
#include "COLLADASWOpenGLConstants.h"
#include "COLLADASWConstants.h"

#include <assert.h>

// TODO remove if not needed
#include <maya/MPxHardwareShader.h>

#include <maya/MFnAttribute.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>

namespace COLLADAMaya
{
	MString skippedAttributeNames[] = {
		"message",
		"caching",
		"isHistoricallyInteresting",
		"nodeState",
		"binMembership",
		"outColor",
		"outColorR",
		"outColorG",
		"outColorB",
		"outTransparency",
		"outTransparencyR",
		"outTransparencyG",
		"outTransparencyB",
		"outGlowColor",
		"outGlowColorR",
		"outGlowColorG",
		"outGlowColorB",
		"outMatteOpacity",
		"outMatteOpacityR",
		"outMatteOpacityG",
		"outMatteOpacityB",
		"enableHwShading",
		"varyingParameters",
		"uniformParameters",
		"savescene",
		"rebuildshader",
		"graph",
		"shaderparams",
		"oldVPcolor",
		"oldVPcolor0",
		"oldVPcolor1",
		"oldVPcolor2"
	};

	bool shouldSkipAttribute(const MString & attributeName) {
		const unsigned int skippedAttributeCount = sizeof(skippedAttributeNames) / sizeof(skippedAttributeNames[0]);
		for (unsigned int i = 0; i < skippedAttributeCount; ++i)
			if (skippedAttributeNames[i] == attributeName)
				return true;
		return false;
	}

	class ScopedExtraTechnique
	{
	public:
		ScopedExtraTechnique(COLLADASW::StreamWriter & streamWriter, const String & profile)
			: mStreamWriter(streamWriter)
			, mpExtra(nullptr)
			, mpTechnique(nullptr)
		{
			mpExtra = new COLLADASW::Extra(&mStreamWriter);
			mpExtra->openExtra();

			mpTechnique = new COLLADASW::Technique(&mStreamWriter);
			mpTechnique->openTechnique(profile);
		}

		~ScopedExtraTechnique()
		{
			mpTechnique->closeTechnique();
			mpExtra->closeExtra();
		}

	private:

		COLLADASW::StreamWriter & mStreamWriter;

		COLLADASW::Extra* mpExtra;
		COLLADASW::Technique* mpTechnique;
	};

	class ScopedElement
	{
	public:
		ScopedElement(COLLADASW::StreamWriter & streamWriter, const String & name)
		{
			mTagCloser = streamWriter.openElement(name);
		}

		~ScopedElement()
		{
			mTagCloser.close();
		}

	private:

		COLLADASW::TagCloser mTagCloser;
	};

	bool isStringAttribute(const MObject & attr)
	{
		if (!attr.hasFn(MFn::kTypedAttribute))
			return false;

		MStatus status;
		MFnTypedAttribute typedAttr(attr, &status);
		MFnData::Type type = typedAttr.attrType(&status);
		return type == MFnData::Type::kString;

		/*if (attr.hasFn(MFn::kNumericAttribute)) {
			MStatus status;
			MFnNumericAttribute numAttr(attr, &status);
			MFnNumericData::Type unit = numAttr.unitType(&status);
			switch (unit)
			{
			case MFnNumericData::Type::kChar:
				return true;
			default:
				return false;
			}
		}
		return false;*/
		/*
		//fnAttr.isUsedAsFilename()
		MFn::Type type = fnAttr.type();

		if (f)
		if (type == MFn::kMessageAttribute)
			return true;

		if (type == MFn::kAttribute)
			return true;

		return false;
		*/
	}

	bool hasValue(const MFnDependencyNode & node, const MObject & attr)
	{
		if (!isStringAttribute(attr))
			return true;

		MStatus status;
		MPlug plug = node.findPlug(attr, &status);
		
		if (!status)
			return false;

		MString value;
		status = plug.getValue(value);

		if (!status)
			return false;

		return value.length() > 0;
	}

    // ---------------------------------

	ShaderFXShaderExporter::ShaderFXShaderExporter(DocumentExporter* documentExporter)
		: mStreamWriter(*documentExporter->getStreamWriter())
		//mDocumentExporter(documentExporter)
	{}

	void ShaderFXShaderExporter::exportShaderFXShader(
        const String &effectId,
        COLLADASW::EffectProfile *effectProfile,
        MObject shaderObject )
    {
        // Set the effect profile
        mEffectProfile = effectProfile;

        MStatus status;

        MFnDependencyNode shaderNode(shaderObject, &status);
		MTypeId typeId = shaderNode.typeId(&status);
		MString typeName = shaderNode.typeName(&status);
		
		if (typeName != "ShaderfxShader")
			return;

		if (!shaderObject.hasFn(MFn::kPluginHardwareShader))
			return;

		MPxHardwareShader* pHWShader = MPxHardwareShader::getHardwareShaderPtr(shaderObject);

		if (pHWShader == nullptr)
			return;

		// Write ShaderFX attributes to COLLADA file
		// TODO: export .sfx and write file name in COLLADA file?
		{
			// Open a <extra><technique> section
			ScopedExtraTechnique extraTechnique(mStreamWriter, PROFILE_MAYA);
			{
				// Open a <shaderfx> section
				ScopedElement shaderfx(mStreamWriter, SHADERFX);

				// Parse ShaderFX attributes
				unsigned int attrCount = shaderNode.attributeCount(&status);
				for (unsigned int attrIndex = 0; attrIndex < attrCount; ++attrIndex)
				{
					MObject attrObject = shaderNode.attribute(attrIndex, &status);
					MFnAttribute fnAttr(attrObject, &status);
					
					if (!status)
						continue;

					MString attrName = fnAttr.name(&status);

					// Skip irrelevant attributes
					if (shouldSkipAttribute(attrName))
						continue;

					// Get node plug for current attribute 
					MPlug plug = shaderNode.findPlug(attrObject, &status);

					if (!status)
						continue;

					// Check attribute value (string) is not empty before creating an <attribute> section
					//if (!hasValue(shaderNode, attrObject))
					//	continue;

					exportAttribute(shaderNode, attrObject);
				}
			}
		}

		//unsigned int attrCount = shaderNode.attributeCount(&status);
		//for (unsigned int attrIndex = 0; attrIndex < attrCount; ++attrIndex) {
		//	
		//	MObject attrObject = shaderNode.attribute(attrIndex, &status);
		//	MFn::Type attrType = attrObject.apiType();
		//	MString attrTypeStr = attrObject.apiTypeStr();

		//	MFnAttribute fnAttr(attrObject, &status);

		//	if (!status)
		//		continue;

		//	/*
		//	const char* className = fnAttr.className();

		//	MStringArray categories;
		//	status = fnAttr.getCategories(categories);

		//	unsigned int catCount = categories.length();
		//	for (unsigned int catIndex = 0; catIndex < catCount; ++catIndex) {
		//		MString category = categories[catIndex];
		//		int huhu = 0;
		//	}
		//	*/

		//	//MString attrName = fnAttr.name(&status);

		//	//if (skipAttribute(attrName))
		//	//	continue;


		//	//MFn::Type type = fnAttr.type();

		//	

		//	/*
		//	MFnDependencyNode attrNode(attrObject, &status);
		//	MString attrName = attrNode.name(&status);
		//	const char* attrClassName = attrNode.className();
		//	MString pluginName = attrNode.pluginName(&status);
		//	MFn::Type type = attrNode.type();
		//	MTypeId typeId = attrNode.typeId(&status);
		//	MString typeName = attrNode.typeName(&status);
		//	*/
		//	int huhu = 0;
		//}

		//MFn

        //if ( fnNode.typeId () == cgfxShaderNode::sId )
        //{
        //    // Create a cgfx shader node
        //    cgfxShaderNode* shaderNodeCgfx = ( cgfxShaderNode* ) fnNode.userNode();

        //    // Exports the effect data of a cgfxShader node.
        //    exportCgfxShader( shaderNodeCgfx );
        //}
        //else
        //{
        //    // Writes the current effect profile into the collada document
        //    mEffectProfile->openProfile ();
        //    mEffectProfile->addProfileElements ();
        //    mEffectProfile->closeProfile ();
        //}
    }

	void ShaderFXShaderExporter::exportAttribute(const MFnDependencyNode & node, const MObject & attr)
	{
		MStatus status;
		MFnAttribute fnAttr(attr, &status);

		if (!status)
			return;

		MString attrName = fnAttr.name(&status);

		if (!status)
			return;

		ScopedElement attribute(mStreamWriter, SHADERFX_ATTRIBUTE);
		mStreamWriter.appendAttribute("name", attrName.asChar());
		{
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
				exportNumericAttribute(node, attr);
			}
			else if (attr.hasFn(MFn::kTypedAttribute)) {
				exportTypedAttribute(node, attr);
			}
			else if (attr.hasFn(MFn::kUnitAttribute)) {
				// TODO
			}
		}
	}

	void ShaderFXShaderExporter::exportNumericAttribute(const MFnDependencyNode & node, const MObject & attr)
	{
		MStatus status;
		MFnNumericAttribute fnNumAttr(attr, &status);

		if (!status)
			return;
	}

	void ShaderFXShaderExporter::exportTypedAttribute(const MFnDependencyNode & node, const MObject & attr)
	{
		MStatus status;
		MFnTypedAttribute fnTypedAttr(attr, &status);

		if (!status)
			return;

		MFnData::Type type = fnTypedAttr.attrType(&status);

		if (!status)
			return;

		switch (type)
		{
			//! Invalid value
		case MFnData::Type::kInvalid:
			break;

			//! Numeric, use MFnNumericData extract the node data.
		case MFnData::Type::kNumeric:
			exportNumericData(node, attr);
			break;

			//! Plugin Blind Data, use MFnPluginData to extract the node data.
		case MFnData::Type::kPlugin:
			// TODO
			break;

			//! Plugin Geometry, use MFnGeometryData to extract the node data.
		case MFnData::Type::kPluginGeometry:
			// TODO
			break;

			//! String, use MFnStringData to extract the node data.
		case MFnData::Type::kString:
			exportStringData(node, attr);
			break;

			//! Matrix, use MFnMatrixData to extract the node data.
		case MFnData::Type::kMatrix:
			// TODO
			break;

			//! String Array, use MFnStringArrayData to extract the node data.
		case MFnData::Type::kStringArray:
			// TODO
			break;

			//! Double Array, use MFnDoubleArrayData to extract the node data.
		case MFnData::Type::kDoubleArray:
			// TODO
			break;

			//! Float Array, use MFnFloatArrayData to extract the node data.
		case MFnData::Type::kFloatArray:
			// TODO
			break;

			//! Int Array, use MFnIntArrayData to extract the node data.
		case MFnData::Type::kIntArray:
			// TODO
			break;

			//! Point Array, use MFnPointArrayData to extract the node data.
		case MFnData::Type::kPointArray:
			// TODO
			break;

			//! Vector Array, use MFnVectorArrayData to extract the node data.
		case MFnData::Type::kVectorArray:
			// TODO
			break;

			//! Component List, use MFnComponentListData to extract the node data.
		case MFnData::Type::kComponentList:
			// TODO
			break;

			//! Mesh, use MFnMeshData to extract the node data.
		case MFnData::Type::kMesh:
			// TODO
			break;

			//! Lattice, use MFnLatticeData to extract the node data.
		case MFnData::Type::kLattice:
			// TODO
			break;

			//! Nurbs Curve, use MFnNurbsCurveData to extract the node data.
		case MFnData::Type::kNurbsCurve:
			// TODO
			break;

			//! Nurbs Surface, use MFnNurbsSurfaceData to extract the node data.
		case MFnData::Type::kNurbsSurface:
			// TODO
			break;

			//! Sphere, use MFnSphereData to extract the node data.
		case MFnData::Type::kSphere:
			// TODO
			break;

			//! ArrayAttrs, use MFnArrayAttrsData to extract the node data.
		case MFnData::Type::kDynArrayAttrs:
			// TODO
			break;

			/*! SweptGeometry, use MFnDynSweptGeometryData to extract the
			node data. This data node is in OpenMayaFX which must be
			linked to.
			*/
		case MFnData::Type::kDynSweptGeometry:
			// TODO
			break;

			//! Subdivision Surface, use MFnSubdData to extract the node data.
		case MFnData::Type::kSubdSurface:
			// TODO
			break;

			//! nObject data, use MFnNObjectData to extract node data
		case MFnData::Type::kNObject:
			// TODO
			break;

			//! nId data, use MFnNIdData to extract node data
		case MFnData::Type::kNId:
			// TODO
			break;

			//! Typically used when the data can be one of several types.
		case MFnData::Type::kAny:
			// TODO
			break;

		default:
			break;
		}
	}

	void ShaderFXShaderExporter::exportNumericData(const MFnDependencyNode & node, const MObject & attr)
	{

	}

	void ShaderFXShaderExporter::exportStringData(const MFnDependencyNode & node, const MObject & attr)
	{
		MStatus status;
		MFnStringData fnStringData(attr, &status);

		if (!status)
			return;

		MPlug plug = node.findPlug(attr, &status);

		MString value;
		status = plug.getValue(value);

		if (!status)
			return;

		bool isUsedAsFilename = MFnAttribute(attr).isUsedAsFilename(&status);
		
		if (!status)
			return;

		// filename are treated as texture filenames
		if (isUsedAsFilename)
		{
			// Export texture
		}
		else
		{
			// Export string
			ScopedElement string(mStreamWriter, SHADERFX_STRING);
			mStreamWriter.appendText(value.asChar());
		}
	}
}
