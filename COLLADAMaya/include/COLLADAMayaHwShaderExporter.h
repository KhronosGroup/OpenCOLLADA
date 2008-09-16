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

#include "ColladaMayaPrerequisites.h"
#include "COLLADAMayaDocumentExporter.h"

#include "COLLADAParamBase.h"
#include "COLLADAParamTemplate.h"
#include "COLLADAValueType.h"
#include "COLLADAEffectProfile.h"

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

    public:

        HwShaderExporter ( DocumentExporter* documentExporter ) : mDocumentExporter ( documentExporter ) {}

        virtual ~HwShaderExporter () {}

        /** Export a hardware shader node. */
        void exportPluginHwShaderNode (
            const String &effectId, 
            COLLADA::EffectProfile *effectProfile,
            MObject shadingNetwork );

    private:

        /** Set the filename of the current shader to export. */
        void setShaderFxFileUri ( const COLLADA::URI& shaderFxFileName );

        /** Returns the filename of the current shader fx file. */
        const COLLADA::URI& getShaderFxFileUri () const;

        /** Exports the effect data of a cgfxShader node. */
        void exportCgfxShader ( MFnDependencyNode &fnNode );

        /** Export the effects parameter. */
        void exportEffectParameters ( CGeffect &cgEffect );

        /** Export the current sampler. */
        void exportSampler( CGparameter& cgParameter );

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

        /** Export the current sampler state assignments. */
        void exportSamplerStateAssignments( 
            const CGparameter &cgParameter, 
            CGparameter &cgTextureParam );

        /** Exports the annotation data of the given parameter. */
        void exportAnnotations ( const CGparameter &cgParameter, COLLADA::ParamBase* param );

        /** Write the current technique and all sub-elements into the current collada document. */
        void exportTechnique ( const CGtechnique& cgTechnique );

        /** Write the pass data into the collada file. */
        void exportPass ( CGpass &cgPass );

        /** Export the current pass state. */
        void exportPassState ( CGstateassignment &cgStateAssignment );

        /** Write the render states parameter. */
        template <class Type>
        void exportRenderStateParam ( const String &renderStateName, const Type *values, int valueCount );

        /** Export the shader program data into the collada file. */
        void exportShaderProgramData ( CGstateassignment& cgStateAssignment, bool readCode=false );

        /** Gernerate the program source string. */
        String getProgramSourceString( const char* programSourceCG );

        /** Adds a <newparam> of the given attribute to the collada document. */
        void setNewParam ( const cgfxShaderNode* shaderNodeCgfx, const cgfxAttrDef* attribute );

        /** Adds the <newparam> element of the attributes texture. */
        void setNewParamTexture( 
            const cgfxAttrDef* attribute, 
            MObject textureNode, 
            COLLADA::Surface::SurfaceType surfaceType, 
            COLLADA::Sampler::SamplerType samplerType, 
            COLLADA::ValueType::ColladaType samplerValueType );

        /** Set the semantic and the annotation to the parameter. */
        template<class Type>
        void prepareParam ( Type &newParam, const cgfxAttrDef *attribute );

    };
}

#endif // __COLLADA_MAYA_HW_SHADER_EXPORTER_H__