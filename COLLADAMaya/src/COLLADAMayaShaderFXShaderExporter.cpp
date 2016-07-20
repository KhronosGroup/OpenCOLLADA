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

#if MAYA_API_VERSION >= 201500

#include "COLLADAMayaShaderFXShaderExporter.h"
#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaAttributeParser.h"

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
			, mpExtra(NULL)
			, mpTechnique(NULL)
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

	class ShaderFXSamplerAndSurfaceExporter : public AttributeParser
	{
	public:
		ShaderFXSamplerAndSurfaceExporter(ShaderFXShaderExporter & shaderFXExporter)
			: mShaderFXExporter(shaderFXExporter)
		{}

	private:
		ShaderFXShaderExporter & mShaderFXExporter;

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

			// Skip irrelevant attributes
			if (shouldSkipAttribute(attrName))
				return false;

			return true;
		}

	protected:
		virtual void onString(MPlug & plug, const MString & name, const MString & value) override
		{
			MStatus status;

			if (value.length() == 0)
				return;

			MObject attr = plug.attribute(&status);
			if (!status) return;

			bool isUsedAsFilename = MFnAttribute(attr).isUsedAsFilename(&status);
			if (!status) return;

			// Filename are treated as texture filenames.
			if (!isUsedAsFilename)
				return;

			mShaderFXExporter.exportSamplerAndSurfaceInner(value);
		}
	};

	class ShaderFXAttributeExporter : public AttributeParser
	{
	public:
		ShaderFXAttributeExporter(ShaderFXShaderExporter & shaderFXExporter)
			: mShaderFXExporter(shaderFXExporter)
		{}

	private:
		ShaderFXShaderExporter & mShaderFXExporter;
        std::map<std::string, COLLADASW::TagCloser> mOpenTags;

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

			// Skip irrelevant attributes
			if (shouldSkipAttribute(attrName))
				return false;

			mOpenTags[std::string(fnAttr.name().asChar())] = mShaderFXExporter.mStreamWriter.openElement(SHADERFX_ATTRIBUTE);
			mShaderFXExporter.mStreamWriter.appendAttribute("name", attrName.asChar());

            return true;
		}

        virtual void onAfterPlug(MPlug & plug) override
		{
			MStatus status;

			MObject attr = plug.attribute(&status);
			if (!status) return;

            MFnAttribute fnAttr(attr);
            std::map<std::string, COLLADASW::TagCloser>::iterator it = mOpenTags.find(std::string(fnAttr.name().asChar()));
            if (it != mOpenTags.end())
            {
                it->second.close();
                mOpenTags.erase(it);
            }
		}

        virtual void onBoolean(MPlug & plug, const MString & name, bool value) override
		{
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_BOOL);
			mShaderFXExporter.mStreamWriter.appendText(value ? SHADERFX_TRUE : SHADERFX_FALSE);
		}

        virtual void onByte(MPlug & plug, const MString & name, char value) override
		{
			const size_t size = 5;
			char text[size];
			snprintf(text, size, "0x%X", value);
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_BYTE);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onChar(MPlug & plug, const MString & name, char value) override
		{
			char text[2] = { value, '\0' };
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_BYTE);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onShort(MPlug & plug, const MString & name, short value) override
		{
			char text[512];
			sprintf(text, "%i", value);
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_SHORT);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onShort2(MPlug & plug, const MString & name, short value[2]) override
		{
			char text[512];
			sprintf(text, "%i %i", value[0], value[1]);
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_SHORT2);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onShort3(MPlug & plug, const MString & name, short value[3]) override
		{
			char text[512];
			sprintf(text, "%i %i %i", value[0], value[1], value[2]);
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_SHORT3);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onInteger(MPlug & plug, const MString & name, int value) override
		{
			char text[512];
			sprintf(text, "%i", value);
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_LONG);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onInteger2(MPlug & plug, const MString & name, int value[2]) override
		{
			char text[512];
			sprintf(text, "%i %i", value[0], value[1]);
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_LONG2);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onInteger3(MPlug & plug, const MString & name, int value[3]) override
		{
			char text[512];
			sprintf(text, "%i %i %i", value[0], value[1], value[2]);
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_LONG3);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onFloat(MPlug & plug, const MString & name, float value) override
		{
			char text[512];
			sprintf(text, "%f", value);
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_FLOAT);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onFloat2(MPlug & plug, const MString & name, float value[2]) override
		{
			char text[512];
			sprintf(text, "%f %f", value[0], value[1]);
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_FLOAT2);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onFloat3(MPlug & plug, const MString & name, float value[3]) override
		{
			char text[512];
			sprintf(text, "%f %f %f", value[0], value[1], value[2]);
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_FLOAT3);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onDouble(MPlug & plug, const MString & name, double value) override
		{
			char text[512];
			sprintf(text, "%f", value);
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_DOUBLE);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onDouble2(MPlug & plug, const MString & name, double value[2]) override
		{
			char text[512];
			sprintf(text, "%f %f", value[0], value[1]);
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_DOUBLE2);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onDouble3(MPlug & plug, const MString & name, double value[3]) override
		{
			char text[512];
			sprintf(text, "%f %f %f", value[0], value[1], value[2]);
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_DOUBLE3);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onDouble4(MPlug & plug, const MString & name, double value[4]) override
		{
			char text[512];
			sprintf(text, "%f %f %f %f", value[0], value[1], value[2], value[3]);
			ScopedElement element(mShaderFXExporter.mStreamWriter, PARAM_TYPE_DOUBLE4);
			mShaderFXExporter.mStreamWriter.appendText(text);
		}

        virtual void onString(MPlug & plug, const MString & name, const MString & value) override
		{
			MStatus status;

			MObject attr = plug.attribute(&status);
			if (!status) return;

			if (value.length() == 0)
				return;

			bool isUsedAsFilename = MFnAttribute(attr).isUsedAsFilename(&status);
			if (!status) return;

			// Filename are treated as texture filenames.
			if (isUsedAsFilename)
			{
				// Export texture
				mShaderFXExporter.exportTexture(value);
			}
			else
			{
				// Export string
				ScopedElement string(mShaderFXExporter.mStreamWriter, PARAM_TYPE_STRING);
				mShaderFXExporter.mStreamWriter.appendText(value.asChar());
			}
		}
	};

    // ------------------------------------------------------------------------

	ShaderFXShaderExporter::ShaderFXShaderExporter(DocumentExporter & documentExporter, COLLADASW::EffectProfile & effectProfile, const String & effectId)
		: mDocumentExporter(documentExporter)
		, mStreamWriter(*documentExporter.getStreamWriter())
		, mEffectProfile(effectProfile)
		, mTextureIndex(0)
		, mEffectId(effectId)
	{}

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

		if (pHWShader == NULL)
			return;

		// Write ShaderFX attributes to COLLADA file
		// TODO: export .sfx and write file name in COLLADA file? Or try to export ShaderFX graph?
		{
			ScopedEffectProfile profile(mEffectProfile);
			{
				// Export samplers and surfaces
                ShaderFXSamplerAndSurfaceExporter SamplerAndSurfaceExporter(*this);
				AttributeParser::parseAttributes(shaderNode, SamplerAndSurfaceExporter);

				// Open a <extra><technique> section
				ScopedExtraTechnique extraTechnique(mStreamWriter, PROFILE_MAYA);
				{
					// Open a <shaderfx> section
					ScopedElement shaderfx(mStreamWriter, SHADERFX);

					// Parse attributes and export them
                    ShaderFXAttributeExporter attributeExporter(*this);
					AttributeParser::parseAttributes(shaderNode, attributeExporter);
				}
			}
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

		if (type != MFnData::kString)
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

#endif // #if MAYA_API_VERSION >= 201500