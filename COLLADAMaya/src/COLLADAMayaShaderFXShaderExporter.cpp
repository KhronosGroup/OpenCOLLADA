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
#include "COLLADAMayaShaderFXShaderExporter.h"
#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaSyntax.h"

#include <maya/MFnAttribute.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MPxHardwareShader.h>

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

	class ScopedEffectProfile
	{
	public:
		ScopedEffectProfile(COLLADASW::EffectProfile & effectProfile)
			: mEffectProfile(effectProfile)
		{
			mEffectProfile.openProfile();
		}

		~ScopedEffectProfile()
		{
			mEffectProfile.closeProfile();
		}

	private:
		COLLADASW::EffectProfile & mEffectProfile;
	};

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
			: mStreamWriter(streamWriter)
		{
			mStreamWriter.openElement(name);
		}

		~ScopedElement()
		{
			mStreamWriter.closeElement();
		}

	private:

		COLLADASW::StreamWriter & mStreamWriter;
	};

    // ------------------------------------------------------------------------

	ShaderFXShaderExporter::ShaderFXShaderExporter(DocumentExporter & documentExporter, COLLADASW::EffectProfile & effectProfile, const String & effectId)
		: mDocumentExporter(documentExporter)
		, mStreamWriter(*documentExporter.getStreamWriter())
		, mEffectProfile(effectProfile)
		, mTextureIndex(0)
		, mEffectId(effectId)
	{}

	template<typename Method>
	void ShaderFXShaderExporter::parseAttributes(const MFnDependencyNode & shaderNode, Method method)
	{
		MStatus status;
		unsigned int attrCount = shaderNode.attributeCount(&status);
		for (unsigned int attrIndex = 0; attrIndex < attrCount; ++attrIndex)
		{
			MObject attrObject = shaderNode.attribute(attrIndex, &status);
			MFnAttribute fnAttr(attrObject, &status);
			if (!status) continue;

			MString attrName = fnAttr.name(&status);

			// Skip irrelevant attributes
			if (shouldSkipAttribute(attrName))
				continue;

			// Get node plug for current attribute 
			MPlug plug = shaderNode.findPlug(attrObject, &status);
			if (!status) continue;

			(this->*method)(shaderNode, attrObject);
		}
	}

	void ShaderFXShaderExporter::exportShaderFXShader(MObject & shaderObject )
    {
        MStatus status;

        MFnDependencyNode shaderNode(shaderObject, &status);
		if (!status) return;

		MString typeName = shaderNode.typeName(&status);
		if (!status) return;
		
		if (typeName != "ShaderfxShader")
			return;

		if (!shaderObject.hasFn(MFn::kPluginHardwareShader))
			return;

		MPxHardwareShader* pHWShader = MPxHardwareShader::getHardwareShaderPtr(shaderObject);

		if (pHWShader == nullptr)
			return;

		// Write ShaderFX attributes to COLLADA file
		// TODO: export .sfx and write file name in COLLADA file? Or try to export ShaderFX graph?
		{
			ScopedEffectProfile profile(mEffectProfile);
			{
				// Export samplers and surfaces
				parseAttributes(shaderNode, &ShaderFXShaderExporter::exportSamplerAndSurface);

				// Open a <extra><technique> section
				ScopedExtraTechnique extraTechnique(mStreamWriter, PROFILE_MAYA);
				{
					// Open a <shaderfx> section
					ScopedElement shaderfx(mStreamWriter, SHADERFX);

					// Parse attributes and export them
					parseAttributes(shaderNode, &ShaderFXShaderExporter::exportAttribute);
				}
			}
		}
    }

	void ShaderFXShaderExporter::exportAttribute(const MFnDependencyNode & node, const MObject & attr)
	{
		MStatus status;

		MFnAttribute fnAttr(attr, &status);
		if (!status) return;

		MString attrName = fnAttr.name(&status);
		if (!status) return;

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
		if (!status) return;

		MFnNumericData::Type type = fnNumAttr.unitType(&status);
		if (!status) return;

		MPlug plug = node.findPlug(attr, &status);
		if (!status) return;

		exportNumeric(plug, type);
	}

	void ShaderFXShaderExporter::exportTypedAttribute(const MFnDependencyNode & node, const MObject & attr)
	{
		MStatus status;

		MFnTypedAttribute fnTypedAttr(attr, &status);
		if (!status) return;

		MFnData::Type type = fnTypedAttr.attrType(&status);
		if (!status) return;

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
		MStatus status;

		MFnNumericData fnNumericData(attr, &status);
		if (!status) return;

		MPlug plug = node.findPlug(attr, &status);
		if (!status) return;

		MFnNumericData::Type type = fnNumericData.numericType(&status);

		exportNumeric(plug, type);
	}

	void ShaderFXShaderExporter::exportNumeric(MPlug plug, MFnNumericData::Type type)
	{
		MStatus status;

		switch (type)
		{
		case MFnNumericData::Type::kInvalid:			//!< Invalid data.
			break;
		case MFnNumericData::Type::kBoolean:			//!< Boolean.
		{
			bool value;
			status = plug.getValue(value);
			if (!status) return;
			ScopedElement element(mStreamWriter, SHADERFX_BOOLEAN);
			mStreamWriter.appendText(value ? SHADERFX_TRUE : SHADERFX_FALSE);
		}
		break;
		case MFnNumericData::Type::kByte:				//!< One byte.
		{
			char value;
			status = plug.getValue(value);
			if (!status) return;
			char text[5];
			sprintf(text, "0x%X", value);
			ScopedElement element(mStreamWriter, SHADERFX_BYTE);
			mStreamWriter.appendText(text);
		}
		break;
		case MFnNumericData::Type::kChar:				//!< One character.
		{
			char text[2] = { '\0' };
			status = plug.getValue(text[0]);
			if (!status) return;
			ScopedElement element(mStreamWriter, SHADERFX_BYTE);
			mStreamWriter.appendText(text);
		}
		break;
		case MFnNumericData::Type::kShort:				//!< One short.
		{
			short value;
			status = plug.getValue(value);
			if (!status) return;
			char text[512];
			sprintf(text, "%i", value);
			ScopedElement element(mStreamWriter, SHADERFX_SHORT);
			mStreamWriter.appendText(text);
		}
		break;
		case MFnNumericData::Type::k2Short:			//!< Two shorts.
		{
			short value[2];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return;
			status = plug0.getValue(value[0]);
			if (!status) return;
			status = plug1.getValue(value[1]);
			if (!status) return;
			char text[512];
			sprintf(text, "%i %i", value[0], value[1]);
			ScopedElement element(mStreamWriter, SHADERFX_SHORT2);
			mStreamWriter.appendText(text);
		}
		break;
		case MFnNumericData::Type::k3Short:			//!< Three shorts.
		{
			short value[3];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return;
			MPlug plug2 = plug.child(2, &status);
			if (!status) return;
			status = plug0.getValue(value[0]);
			if (!status) return;
			status = plug1.getValue(value[1]);
			if (!status) return;
			status = plug2.getValue(value[2]);
			if (!status) return;
			char text[512];
			sprintf(text, "%i %i %i", value[0], value[1], value[2]);
			ScopedElement element(mStreamWriter, SHADERFX_SHORT3);
			mStreamWriter.appendText(text);
		}
		break;
		case MFnNumericData::Type::kLong:				//!< One long. Same as int since "long" is not platform-consistent.
		{
			int value;
			status = plug.getValue(value);
			if (!status) return;
			char text[512];
			sprintf(text, "%i", value);
			ScopedElement element(mStreamWriter, SHADERFX_LONG);
			mStreamWriter.appendText(text);
		}
		break;
		//case MFnNumericData::Type::kInt:		//!< One int.
		//	break;
		case MFnNumericData::Type::k2Long:				//!< Two longs. Same as 2 ints since "long" is not platform-consistent.
		{
			int value[2];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return;
			status = plug0.getValue(value[0]);
			if (!status) return;
			status = plug1.getValue(value[1]);
			if (!status) return;
			char text[512];
			sprintf(text, "%i %i", value[0], value[1]);
			ScopedElement element(mStreamWriter, SHADERFX_LONG2);
			mStreamWriter.appendText(text);
		}
		break;
		//case MFnNumericData::Type::k2Int:		//!< Two ints.
		//	break;
		case MFnNumericData::Type::k3Long:				//!< Three longs. Same as 3 ints since "long" is not platform-consistent.
		{
			int value[3];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return;
			MPlug plug2 = plug.child(2, &status);
			if (!status) return;
			status = plug0.getValue(value[0]);
			if (!status) return;
			status = plug1.getValue(value[1]);
			if (!status) return;
			status = plug2.getValue(value[2]);
			if (!status) return;
			char text[512];
			sprintf(text, "%i %i %i", value[0], value[1], value[2]);
			ScopedElement element(mStreamWriter, SHADERFX_LONG3);
			mStreamWriter.appendText(text);
		}
		break;
		//case MFnNumericData::Type::k3Int:		//!< Three ints.
		//	break;
		case MFnNumericData::Type::kFloat:				//!< One float.
		{
			float value;
			status = plug.getValue(value);
			if (!status) return;
			char text[512];
			sprintf(text, "%f", value);
			ScopedElement element(mStreamWriter, SHADERFX_FLOAT);
			mStreamWriter.appendText(text);
		}
		break;
		case MFnNumericData::Type::k2Float:			//!< Two floats.
		{
			float value[2];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return;
			status = plug0.getValue(value[0]);
			if (!status) return;
			status = plug1.getValue(value[1]);
			if (!status) return;
			char text[512];
			sprintf(text, "%f %f", value[0], value[1]);
			ScopedElement element(mStreamWriter, SHADERFX_FLOAT2);
			mStreamWriter.appendText(text);
		}
		break;
		case MFnNumericData::Type::k3Float:			//!< Three floats.
		{
			float value[3];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return;
			MPlug plug2 = plug.child(2, &status);
			if (!status) return;
			status = plug0.getValue(value[0]);
			if (!status) return;
			status = plug1.getValue(value[1]);
			if (!status) return;
			status = plug2.getValue(value[2]);
			if (!status) return;
			char text[512];
			sprintf(text, "%f %f %f", value[0], value[1], value[2]);
			ScopedElement element(mStreamWriter, SHADERFX_FLOAT3);
			mStreamWriter.appendText(text);
		}
		break;
		case MFnNumericData::Type::kDouble:			//!< One double.
		{
			double value;
			status = plug.getValue(value);
			if (!status) return;
			char text[512];
			sprintf(text, "%f", value);
			ScopedElement element(mStreamWriter, SHADERFX_DOUBLE);
			mStreamWriter.appendText(text);
		}
		break;
		case MFnNumericData::Type::k2Double:			//!< Two doubles.
		{
			double value[2];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return;
			status = plug0.getValue(value[0]);
			if (!status) return;
			status = plug1.getValue(value[1]);
			if (!status) return;
			char text[512];
			sprintf(text, "%f %f", value[0], value[1]);
			ScopedElement element(mStreamWriter, SHADERFX_DOUBLE2);
			mStreamWriter.appendText(text);
		}
		break;
		case MFnNumericData::Type::k3Double:			//!< Three doubles.
		{
			double value[3];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return;
			MPlug plug2 = plug.child(2, &status);
			if (!status) return;
			status = plug0.getValue(value[0]);
			if (!status) return;
			status = plug1.getValue(value[1]);
			if (!status) return;
			status = plug2.getValue(value[2]);
			if (!status) return;
			char text[512];
			sprintf(text, "%f %f %f", value[0], value[1], value[2]);
			ScopedElement element(mStreamWriter, SHADERFX_DOUBLE3);
			mStreamWriter.appendText(text);
		}
		break;
		case MFnNumericData::Type::k4Double:			//!< Four doubles.
		{
			double value[4];
			MPlug plug0 = plug.child(0, &status);
			if (!status) return;
			MPlug plug1 = plug.child(1, &status);
			if (!status) return;
			MPlug plug2 = plug.child(2, &status);
			if (!status) return;
			MPlug plug3 = plug.child(3, &status);
			if (!status) return;
			status = plug0.getValue(value[0]);
			if (!status) return;
			status = plug1.getValue(value[1]);
			if (!status) return;
			status = plug2.getValue(value[2]);
			if (!status) return;
			status = plug3.getValue(value[3]);
			if (!status) return;
			char text[512];
			sprintf(text, "%f %f %f %f", value[0], value[1], value[2], value[3]);
			ScopedElement element(mStreamWriter, SHADERFX_DOUBLE4);
			mStreamWriter.appendText(text);
		}
		break;
		case MFnNumericData::Type::kAddr:				//!< An address.
			// TODO
			break;
		default:
			break;
		}
	}

	void ShaderFXShaderExporter::exportStringData(const MFnDependencyNode & node, const MObject & attr)
	{
		MStatus status;

		MPlug plug = node.findPlug(attr, &status);
		if (!status) return;

		MString value;
		status = plug.getValue(value);
		if (!status) return;

		if (value.length() == 0)
			return;

		bool isUsedAsFilename = MFnAttribute(attr).isUsedAsFilename(&status);
		if (!status) return;

		// Filename are treated as texture filenames.
		if (isUsedAsFilename)
		{
			// Export texture
			exportTexture(value);
		}
		else
		{
			// Export string
			ScopedElement string(mStreamWriter, SHADERFX_STRING);
			mStreamWriter.appendText(value.asChar());
		}
	}

	void ShaderFXShaderExporter::exportSamplerAndSurface(const MFnDependencyNode & node, const MObject & attr)
	{
		MStatus status;

		if (!attr.hasFn(MFn::kTypedAttribute))
			return;

		MFnTypedAttribute fnTypedAttr(attr, &status);
		if (!status) return;

		MFnData::Type type = fnTypedAttr.attrType(&status);
		if (!status) return;

		if (type != MFnData::Type::kString)
			return;

		MPlug plug = node.findPlug(attr, &status);

		MString value;
		status = plug.getValue(value);
		if (!status) return;

		if (value.length() == 0)
			return;

		bool isUsedAsFilename = MFnAttribute(attr).isUsedAsFilename(&status);
		if (!status) return;

		// Filename are treated as texture filenames.
		if (!isUsedAsFilename)
			return;
		
		exportSamplerAndSurfaceInner(value);
	}

	void ShaderFXShaderExporter::exportSamplerAndSurfaceInner(const MString & filename)
	{
		EffectExporter & effectExporter = *mDocumentExporter.getEffectExporter();
		EffectTextureExporter & textureExporter = *effectExporter.getTextureExporter();

		// Take the filename for the unique image name
		URI fileURI(URI::nativePathToUri(filename.asChar()));
		if (fileURI.getScheme().empty())
			fileURI.setScheme(COLLADASW::URI::SCHEME_FILE);

		String mayaImageId = DocumentExporter::mayaNameToColladaName(fileURI.getPathFileBase().c_str());

		String colladaImageId = effectExporter.findColladaImageId(mayaImageId);
		if (colladaImageId.empty())
		{
			// Generate a COLLADA id for the new image object
			colladaImageId = DocumentExporter::mayaNameToColladaName(fileURI.getPathFileBase().c_str());

			// Make the id unique and store it in a map for refernences.
			colladaImageId = textureExporter.getImageIdList().addId(colladaImageId);
			textureExporter.getMayaIdColladaImageId()[mayaImageId] = colladaImageId;
		}

		// Export the image
		COLLADASW::Image* colladaImage = textureExporter.exportImage(mayaImageId, colladaImageId, fileURI);

		// Get the image id of the exported collada image
		colladaImageId = colladaImage->getImageId();

		String samplerSid = colladaImageId + COLLADASW::Sampler::SAMPLER_SID_SUFFIX;
		String surfaceSid = colladaImageId + COLLADASW::Sampler::SURFACE_SID_SUFFIX;

		// Create the collada sampler object
		// TODO handle other sampler types
		COLLADASW::Sampler sampler(COLLADASW::Sampler::SAMPLER_TYPE_2D, samplerSid, surfaceSid);

		// TODO get wrap mode in ShaderFX graph
		//sampler.setWrapS(COLLADASW::Sampler::WRAP_MODE_WRAP);
		//sampler.setWrapT(COLLADASW::Sampler::WRAP_MODE_WRAP);
		//sampler.setWrapP(COLLADASW::Sampler::WRAP_MODE_WRAP);

		// No filtering option in ShaderFX. Default to linear.
		//sampler.setMinFilter(COLLADASW::Sampler::SAMPLER_FILTER_LINEAR);
		//sampler.setMagFilter(COLLADASW::Sampler::SAMPLER_FILTER_LINEAR);
		//sampler.setMipFilter(COLLADASW::Sampler::SAMPLER_FILTER_LINEAR);

		// Set the image reference
		sampler.setImageId(colladaImageId);

		sampler.setFormat(EffectTextureExporter::FORMAT);

		// Add the parameter.
		sampler.addInNewParam(&mStreamWriter);
	}

	void ShaderFXShaderExporter::exportTexture(const MString & filename)
	{
		EffectExporter & effectExporter = *mDocumentExporter.getEffectExporter();
		EffectTextureExporter & textureExporter = *effectExporter.getTextureExporter();

		// Take the filename for the unique image name
		URI fileURI(URI::nativePathToUri(filename.asChar()));
		if (fileURI.getScheme().empty())
			fileURI.setScheme(COLLADASW::URI::SCHEME_FILE);

		effectExporter.exportTexturedParameter(mEffectId, &mEffectProfile, mTextureIndex, fileURI);
	}
}
