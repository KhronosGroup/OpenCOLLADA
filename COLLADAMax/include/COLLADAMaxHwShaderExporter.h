/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAX_HW_SHADER_EXPORTER_H__
#define __COLLADA_MAX_HW_SHADER_EXPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxDocumentExporter.h"

#include "COLLADASWParamBase.h"
#include "COLLADASWParamTemplate.h"
#include "COLLADASWValueType.h"
#include "COLLADASWEffectProfile.h"
#include "COLLADASWShader.h"


namespace COLLADAMax
{

    class HwShaderExporter
    {

    private:

        /** Pointer to the document exporter */
        DocumentExporter* mDocumentExporter;

        /** The currently used collada effect profile to write the data. */
        COLLADASW::EffectProfile *mEffectProfile;

        /** The scope of the current shader. */
        COLLADASW::Shader::Scope mShaderScope;

    public:

        HwShaderExporter ( DocumentExporter* documentExporter ) : mDocumentExporter ( documentExporter ) {}

        virtual ~HwShaderExporter () {}

        /** Export a hardware shader node. */
        void exportPluginHwShaderNode (
            const String &effectId,
            COLLADASW::EffectProfile *effectProfile,
            ExportNode* exportNode,
            StdMat2* material,
            float weight );

        /** The scope of the current shader. */
        const COLLADASW::Shader::Scope& getShaderScope () const { return mShaderScope; }
        void setShaderScope ( const COLLADASW::Shader::Scope& val ) { mShaderScope = val; }

        /** Export the current sampler. */
        void exportSampler ( 
            const char* paramName,
            const PBBitmap* bitmap
            );

    private:

        /** Export animated parameters */
        void exportParameterAnimations(
            const String &effectId,
            StdMat2* material );

        /** Exports the effect data of a cgfxShader node. */
        void exportCgfxShader (
            COLLADASW::EffectProfile *effectProfile,
            StdMat2* material, 
            float weight
            );

        /** Export the effects parameter. */
        void exportEffectParameters ( 
            StdMat2* material );

        ///** Create the annotation data of the given parameter and push it in the list. */
        //void getAnnotations ( 
        //    std::vector<COLLADASW::Annotation>& annotations, 
        //    const CGparameter &cgParameter );

        ///** Export the current texture element. */
        void setTexture (
            const PBBitmap * bitmap, 
            COLLADASW::Sampler& sampler
            );

        ///** Returns the type data of the current resource. */
        //void getResourceType(
        //    const CGparameter& cgTextureParam,
        //    COLLADASW::Sampler::SamplerType &samplerType,
        //    COLLADASW::ValueType::ColladaType &samplerValueType );

        ///** Exports the given parameter with all his annotations, the semantic and the given values. */
        template<class Type>
        void exportParam (
            //const CGparameter& cgParameter,
            const char* paramName,
            COLLADASW::ParamBase *param,
            const Type* paramValues,
            const int numOfValues );

        void exportParam (
            //const CGparameter& cgParameter,
            const char* paramName,
            COLLADASW::ParamBase* param,
            const String& paramValue );

        ///** Exports the annotation data of the given parameter. */
        //void exportAnnotations ( const CGparameter &cgParameter, COLLADASW::ParamBase *param );

        ///** Exports the semantic data of the given parameter. */
        //void exportSemantic( const CGparameter &cgParameter, COLLADASW::ParamBase *param );

        ///** Write the current technique and all sub-elements into the current collada document. */
        //void exportTechnique ( const CGtechnique &cgTechnique );

        ///** Write the pass data into the collada file. */
        //void exportPass ( const CGpass &cgPass );

        ///** Exports the vertex and the fragment shader. */
        //void exportShaders ( const CGpass& cgPass );

        ///** Export the current pass state. */
        //void exportPassRenderState ( const CGstateassignment &cgStateAssignment );

        ///** Write the render states parameter. */
        //template <class Type>
        //void exportRenderStateParam ( const String &renderStateName, const Type *values, const int valueCount );
        //void exportRenderStateParam ( const String &renderStateName, const CGbool *values, const int valueCount );

        ///** Export the shader program data into the collada file. */
        //void exportShaderProgramData ( const CGstateassignment& cgStateAssignment, const bool readCode=false );

        
        /** Generate the program source string. */
        String getProgramSourceString( const char* programSourceCG );

    };
}

#endif // __COLLADA_MAX_HW_SHADER_EXPORTER_H__
