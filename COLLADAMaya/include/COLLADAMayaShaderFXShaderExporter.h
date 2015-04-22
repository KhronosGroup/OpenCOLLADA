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

#if MAYA_API_VERSION >= 201500

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaDocumentExporter.h"

#include "COLLADASWEffectProfile.h"

#include <maya/MFnDependencyNode.h>
#include <maya/MFnNumericData.h>

namespace COLLADAMaya
{

	class ShaderFXShaderExporter
    {
		friend class ShaderFXAttributeExporter;
		friend class ShaderFXSamplerAndSurfaceExporter;

    private:

        /** Document exporter */
        DocumentExporter& mDocumentExporter;

		/** Stream writer */
		COLLADASW::StreamWriter & mStreamWriter;

        /** The currently used collada effect profile to write the data. */
        COLLADASW::EffectProfile& mEffectProfile;

		/** Current texture index */
		int mTextureIndex;

		/** Current effect id */
		String mEffectId;

    public:

		ShaderFXShaderExporter(DocumentExporter & documentExporter, COLLADASW::EffectProfile & effectProfile, const String & effectId);

		virtual ~ShaderFXShaderExporter() {}

        /** Export a ShaderFX shader node. */
		void exportShaderFXShader(MObject & shaderObject );


    private:

		template<typename Method>
		void parseAttributes(const MFnDependencyNode & node, Method method);

		void exportSamplerAndSurface(const MFnDependencyNode & node, const MObject & attr);
		void exportSamplerAndSurfaceInner(const MString & filename);
		void exportTexture(const MString & filename);
    };
}
#endif // #if MAYA_API_VERSION >= 201500

#endif // __COLLADA_MAYA_SHADERFX_SHADER_EXPORTER_H__
