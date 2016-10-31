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

#ifndef __COLLADA_MAYA_HW_SHADER_EXPORTER_H__
#define __COLLADA_MAYA_HW_SHADER_EXPORTER_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaDocumentExporter.h"

#include "COLLADASWParamBase.h"
#include "COLLADASWParamTemplate.h"
#include "COLLADASWValueType.h"
#include "COLLADASWEffectProfile.h"
#include "COLLADASWShader.h"

#include "cgfxAttrDef.h"

#include <maya/MFnDependencyNode.h>

#if MAYA_API_VERSION >= 201200
class cgfxTechnique;
#endif // MAYA_API_VERSION >= 201200

namespace COLLADAMaya
{

    class HwShaderExporter
    {

    private:

        /** Pointer to the document exporter */
        DocumentExporter* mDocumentExporter;

        /** The filename of the current shader to export. */
        COLLADASW::URI mShaderFxFileUri;

        /** The currently used collada effect profile to write the data. */
        COLLADASW::EffectProfile *mEffectProfile;

        /** The scope of the current shader. */
        COLLADASW::Shader::Scope mShaderScope;

    public:

        HwShaderExporter ( DocumentExporter* documentExporter ) : mDocumentExporter ( documentExporter ) {}

        virtual ~HwShaderExporter () {}

        /** Export a hardware shader node. */
        bool exportPluginHwShaderNode (
            const String &effectId,
            COLLADASW::EffectProfile *effectProfile,
            MObject shadingNetwork );

        /** The scope of the current shader. */
        const COLLADASW::Shader::Scope& getShaderScope () const { return mShaderScope; }
        void setShaderScope ( const COLLADASW::Shader::Scope& val ) { mShaderScope = val; }

        /** Export the current sampler. */
        void exportSampler ( 
            MObject shaderNode, 
            const CGparameter& cgParameter,
            const bool writeNewParam );

        /** Set the filename of the current shader to export. */
        void setShaderFxFileUri ( const COLLADASW::URI& shaderFxFileName );

    private:

        /** Returns the filename of the current shader fx file. */
        const COLLADASW::URI& getShaderFxFileUri () const;

        /** Exports the effect data of a cgfxShader node. */
        bool exportCgfxShader ( cgfxShaderNode* shaderNodeCgfx );

        /** Export the effects parameter. */
        void exportEffectParameters ( 
            MObject shaderNode, 
#if MAYA_API_VERSION < 201200
            const CGeffect &cgEffect
#else // MAYA_API_VERSION < 201200
            const cgfxRCPtr<const cgfxEffect>& cgEffect
#endif // MAYA_API_VERSION < 201200
            );

        /** Create the annotation data of the given parameter and push it in the list. */
        void getAnnotations ( 
            std::vector<COLLADASW::Annotation>& annotations, 
            const CGparameter &cgParameter );

        /** Export the current texture element. */
        void setTexture (
            MObject shaderNode, 
            COLLADASW::Sampler& sampler, 
            const CGparameter& cgTextureParam );

        /** Returns the type data of the current resource. */
        void getResourceType(
            const CGparameter& cgTextureParam,
            COLLADASW::Sampler::SamplerType &samplerType,
            COLLADASW::ValueType::ColladaType &samplerValueType );

        /** Exports the given parameter with all his annotations, the semantic and the given values. */
        template<class Type>
        void exportParam (
            const CGparameter& cgParameter,
            COLLADASW::ParamBase *param,
            const Type* paramValues,
            const int numOfValues );

        void exportParam (
            const CGparameter& cgParameter,
            COLLADASW::ParamBase* param,
            const String& paramValue );

        /** Exports the annotation data of the given parameter. */
        void exportAnnotations ( const CGparameter &cgParameter, COLLADASW::ParamBase *param );

        /** Exports the semantic data of the given parameter. */
        void exportSemantic( const CGparameter &cgParameter, COLLADASW::ParamBase *param );
#if MAYA_API_VERSION >= 201200
        /** Write the current technique and all sub-elements into the current collada document. */
        void exportTechnique( const cgfxTechnique* technique );
#endif // MAYA_API_VERSION >= 201200

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
