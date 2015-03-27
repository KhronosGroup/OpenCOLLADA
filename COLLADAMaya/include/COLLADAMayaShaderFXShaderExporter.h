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

#ifndef __COLLADA_MAYA_SHADERFX_SHADER_EXPORTER_H__
#define __COLLADA_MAYA_SHADERFX_SHADER_EXPORTER_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaDocumentExporter.h"

#include "COLLADASWParamBase.h"
#include "COLLADASWParamTemplate.h"
#include "COLLADASWValueType.h"
#include "COLLADASWEffectProfile.h"
#include "COLLADASWShader.h"

#include <maya/MFnDependencyNode.h>
#include <maya/MFnNumericData.h>

namespace COLLADAMaya
{

	class ShaderFXShaderExporter
    {

    private:

        /** Document exporter */
        DocumentExporter& mDocumentExporter;

		/** Stream writer */
		COLLADASW::StreamWriter & mStreamWriter;

        /** The currently used collada effect profile to write the data. */
        COLLADASW::EffectProfile& mEffectProfile;

        /** The scope of the current shader. */
        //COLLADASW::Shader::Scope mShaderScope;

		int mTextureIndex;

		String mEffectId;

    public:

		ShaderFXShaderExporter(DocumentExporter & documentExporter, COLLADASW::EffectProfile & effectProfile, const String & effectId);

		virtual ~ShaderFXShaderExporter() {}

        /** Export a hardware shader node. */
		void exportShaderFXShader(
            //const String &effectId,
            MObject & shadingNetwork );

        /** The scope of the current shader. */
        //const COLLADASW::Shader::Scope& getShaderScope () const { return mShaderScope; }
        //void setShaderScope ( const COLLADASW::Shader::Scope& val ) { mShaderScope = val; }

    private:

		//typedef void (ShaderFXShaderExporter::*ParseAttributeMethod)(const MFnDependencyNode &, const MObject&);
		//void parseAttributes(const MFnDependencyNode & node, ParseAttributeMethod method);
		template<typename Method>
		void parseAttributes(const MFnDependencyNode & node, Method method);

		void exportSamplerAndSurface(const MFnDependencyNode & node, const MObject & attr);
		void exportSamplerAndSurfaceInner(const MString & filename);
		void exportAttribute(const MFnDependencyNode & node, const MObject & attr);
		void exportNumericAttribute(const MFnDependencyNode & node, const MObject & attr);
		void exportTypedAttribute(const MFnDependencyNode & node, const MObject & attr);
		void exportNumericData(const MFnDependencyNode & node, const MObject & attr);
		void exportNumeric(MPlug plug, MFnNumericData::Type type);
		void exportStringData(const MFnDependencyNode & node, const MObject & attr);
		void exportTexture(const MFnDependencyNode & node, const MString & filename, const MString & attrName);
    };
}

#endif // __COLLADA_MAYA_SHADERFX_SHADER_EXPORTER_H__
