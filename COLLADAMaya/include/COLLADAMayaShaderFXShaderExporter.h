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

namespace COLLADAMaya
{

	class ShaderFXShaderExporter
    {

    private:

        /** Pointer to the document exporter */
        //DocumentExporter* mDocumentExporter;

        /** The currently used collada effect profile to write the data. */
        COLLADASW::EffectProfile *mEffectProfile;

        /** The scope of the current shader. */
        //COLLADASW::Shader::Scope mShaderScope;

    public:

		ShaderFXShaderExporter(DocumentExporter* documentExporter);

		virtual ~ShaderFXShaderExporter() {}

        /** Export a hardware shader node. */
		void exportShaderFXShader(
            const String &effectId,
            COLLADASW::EffectProfile *effectProfile,
            MObject shadingNetwork );

        /** The scope of the current shader. */
        //const COLLADASW::Shader::Scope& getShaderScope () const { return mShaderScope; }
        //void setShaderScope ( const COLLADASW::Shader::Scope& val ) { mShaderScope = val; }

    private:

		void exportAttribute(const MFnDependencyNode & node, const MObject & attr);
		void exportNumericAttribute(const MFnDependencyNode & node, const MObject & attr);
		void exportTypedAttribute(const MFnDependencyNode & node, const MObject & attr);
		void exportNumericData(const MFnDependencyNode & node, const MObject & attr);
		void exportStringData(const MFnDependencyNode & node, const MObject & attr);

		COLLADASW::StreamWriter & mStreamWriter;
    };
}

#endif // __COLLADA_MAYA_SHADERFX_SHADER_EXPORTER_H__
