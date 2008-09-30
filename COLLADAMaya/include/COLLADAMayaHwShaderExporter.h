/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_HW_SHADER_EXPORTER_H__
#define __COLLADA_MAYA_HW_SHADER_EXPORTER_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaDocumentExporter.h"

#include "COLLADAParamBase.h"
#include "COLLADAParamTemplate.h"
#include "COLLADAValueType.h"
#include "COLLADAEffectProfile.h"
#include "COLLADAShader.h"

#include "cgfxAttrDef.h"

#include <maya/MFnDependencyNode.h>

namespace COLLADAMaya
{

    class HwShaderExporter
    {

    private:

        /** Pointer to the document exporter */
        DocumentExporter* mDocumentExporter;

        /** The filename of the current shader to export. */
        COLLADA::URI mShaderFxFileUri;

        /** The currently used collada effect profile to write the data. */
        COLLADA::EffectProfile *mEffectProfile;

        /** The scope of the current shader. */
        COLLADA::Shader::Scope mShaderScope;

    public:

        HwShaderExporter ( DocumentExporter* documentExporter ) : mDocumentExporter ( documentExporter ) {}

        virtual ~HwShaderExporter () {}

        /** Export a hardware shader node. */
        void exportPluginHwShaderNode (
            const String &effectId,
            COLLADA::EffectProfile *effectProfile,
            MObject shadingNetwork );

        /** The scope of the current shader. */
        const COLLADA::Shader::Scope& getShaderScope () const { return mShaderScope; }
        void setShaderScope ( const COLLADA::Shader::Scope& val ) { mShaderScope = val; }

    private:

        /** Set the filename of the current shader to export. */
        void setShaderFxFileUri ( const COLLADA::URI& shaderFxFileName );

        /** Returns the filename of the current shader fx file. */
        const COLLADA::URI& getShaderFxFileUri () const;

        /** Exports the effect data of a cgfxShader node. */
        void exportCgfxShader ( cgfxShaderNode* shaderNodeCgfx );

        /** Export the effects parameter. */
        void exportEffectParameters ( const CGeffect &cgEffect );

        /** Export the current sampler. */
        void exportSampler( const CGparameter& cgParameter );

        /** Export the current texture element. */
        void exportTexture(
            const CGparameter& cgTextureParam,
            const COLLADA::Surface::SurfaceType& surfaceType );

        /** Returns the type data of the current resource. */
        void getResourceType(
            const CGparameter& cgTextureParam,
            COLLADA::Surface::SurfaceType &surfaceType,
            COLLADA::Sampler::SamplerType &samplerType,
            COLLADA::ValueType::ColladaType &samplerValueType );

        /** Exports the given parameter with all his annotations, the semantic and the given values. */
        template<class Type>
        void exportParam (
            const CGparameter& cgParameter,
            COLLADA::ParamBase *param,
            const Type* paramValues,
            const int numOfValues );

        /** Exports the annotation data of the given parameter. */
        void exportAnnotations ( const CGparameter &cgParameter, COLLADA::ParamBase *param );

        /** Exports the semantic data of the given parameter. */
        void exportSemantic( const CGparameter &cgParameter, COLLADA::ParamBase *param );

        /** Write the current technique and all sub-elements into the current collada document. */
        void exportTechnique ( const CGtechnique &cgTechnique );

        /** Write the pass data into the collada file. */
        void exportPass ( const CGpass &cgPass );

        /** Exports the vertex and the fragment shader. */
        void exportShaders ( const CGpass& cgPass );

        /** Export the current pass state. */
        void exportPassRenderState ( const CGstateassignment &cgStateAssignment );

        /** Write the render states parameter. */
        template <class Type>
        void exportRenderStateParam ( const String &renderStateName, const Type *values, const int valueCount );
        void exportRenderStateParam ( const String &renderStateName, const CGbool *values, const int valueCount );

        /** Export the shader program data into the collada file. */
        void exportShaderProgramData ( const CGstateassignment& cgStateAssignment, const bool readCode=false );

        /** Gernerate the program source string. */
        String getProgramSourceString( const char* programSourceCG );

    };
}

#endif // __COLLADA_MAYA_HW_SHADER_EXPORTER_H__
