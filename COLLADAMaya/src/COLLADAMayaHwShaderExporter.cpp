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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaHwShaderExporter.h"
#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaConversion.h"

#include "COLLADAPass.h"
#include "COLLADARenderState.h"
#include "COLLADAShader.h"
#include "COLLADAAnnotation.h"
#include "COLLADAOpenGLConstants.h"

#include "cgfxShaderNode.h"
#include "cgfxFindImage.h"

#include <assert.h>


namespace COLLADAMaya
{

    // ---------------------------------
    void HwShaderExporter::exportPluginHwShaderNode (
        const String &effectId, 
        COLLADA::EffectProfile *effectProfile,
        MObject shaderNode )
    {
        // Set the effect profile
        mEffectProfile = effectProfile;

        // Look through the scene for cgfxShader nodes whose effect is NULL
        // but whose shader attribute is not empty.
        MStatus status;

        MString workspace;
        status = MGlobal::executeCommand(MString("workspace -q -rd;"), workspace);
        if (!status) workspace.clear();
        String workspaceName = workspace.asChar();

        MFnDependencyNode fnNode ( shaderNode );
        if ( fnNode.typeId() == cgfxShaderNode::sId ) 
        {
            // Create a cgfx shader node
            cgfxShaderNode* shaderNodeCgfx = ( cgfxShaderNode* ) fnNode.userNode();

            // Exports the effect data of a cgfxShader node.
            exportCgfxShader( shaderNodeCgfx );
        }
        else
        {
            // Writes the current effect profile into the collada document
            mEffectProfile->openProfile ();
            mEffectProfile->addProfileElements ();
            mEffectProfile->closeProfile ();
//          exportStandardShader( effectId, effectProfile, shaderNode );
        }

    }

    // ---------------------------------
    void HwShaderExporter::exportCgfxShader ( cgfxShaderNode* shaderNodeCgfx )
    {
        // Set the current shader scope to CG
        setShaderScope ( COLLADA::Shader::SCOPE_CG );

        // Writes the current effect profile into the collada document
        mEffectProfile->setProfileType ( COLLADA::EffectProfile::CG );
        mEffectProfile->openProfile ();

        // Get a pointer to the current stream writer
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the filename of the current cgfx file
        MString shaderFxFile = shaderNodeCgfx->shaderFxFile();
        String shaderFxFileName = shaderFxFile.asChar (); // check3d.cgfx
        COLLADA::URI  shaderFxFileUri ( shaderFxFileName );
        setShaderFxFileUri ( shaderFxFileUri );

        // Set the current include file
//        mEffectProfile->setInclude ( shaderFxFileUri, shaderFxFileUri.getPathFileBase() );

        // Get the current CGeffect
        CGeffect cgEffect = shaderNodeCgfx->effect();

        // Add the source code
        CGcontext cgContext = cgGetEffectContext ( cgEffect );
        CGprogram cgProgram = cgGetFirstProgram ( cgContext );
        const char* programSourceCG = cgGetProgramString ( cgProgram, CG_PROGRAM_SOURCE );
        String sourceString = getProgramSourceString ( programSourceCG );
        // Get the code sid
        String codeSid = shaderFxFileUri.getPathFileBase ();
        // Set the code into the collada effect profile
        mEffectProfile->setCode ( sourceString, codeSid );

        // Add the source code and the include file
        mEffectProfile->addProfileElements ();

        // Export the effects parameter
        exportEffectParameters ( cgEffect );

        // Find if effect parameter is used by any program of the selected technique
        CGtechnique cgTechnique = cgGetFirstTechnique ( cgEffect );
        while ( cgTechnique )
        {
            exportTechnique ( cgTechnique );
            cgTechnique = cgGetNextTechnique ( cgTechnique );
        }

        // Close the current profile
        mEffectProfile->closeProfile ();
    }

    // --------------------------------
    void HwShaderExporter::exportTechnique ( 
        const CGtechnique& cgTechnique )
    {
        mEffectProfile->setTechniqueSid ( cgGetTechniqueName ( cgTechnique ) );
        String techniqueName = cgGetTechniqueName ( cgTechnique );

        // Open the current technique element
        mEffectProfile->openTechnique ( techniqueName );

        // Go through the passes and write it into the collada file.
        CGpass cgPass = cgGetFirstPass ( cgTechnique );
        while ( cgPass ) 
        {
            exportPass ( cgPass );
            cgPass = cgGetNextPass ( cgPass );
        }

        // Close the current technique element
        mEffectProfile->closeTechnique ();

    }

    // --------------------------------------
    void HwShaderExporter::exportShaderProgramData ( 
        const CGstateassignment& cgStateAssignment, 
        const bool readCode )
    {
        // Get the current stream writer
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
        
        // Write the render states.
        CGstate cgState = cgGetStateAssignmentState ( cgStateAssignment );
        const char* cgStateNameC = cgGetStateName ( cgState );
        String cgStateName ( cgStateNameC );
        CGtype cgStateType = cgGetStateType ( cgState );
        if ( cgStateType != CG_PROGRAM_TYPE ) return;
        
        // The state name depend on the current shader scope 
        COLLADA::Shader::Stage shaderStage = COLLADA::Shader::getStageTypeByName ( cgStateName );
        
        // Create a shader and export it
        COLLADA::Shader shader ( streamWriter, mShaderScope, shaderStage );
        shader.openShader();
        
        // Get the program
        CGprogram cgProgram	= cgGetProgramStateAssignmentValue ( cgStateAssignment );

//        const char* programCompiledString = cgGetProgramString ( cgProgram, CG_COMPILED_PROGRAM );
//        const char* programProfileString = cgGetProgramString ( cgProgram, CG_PROGRAM_PROFILE ); // arbvp1

        // Set the current programs profile
        CGprofile cgProgramProfile = cgGetProgramProfile( cgProgram );
        const char* profileString = cgGetProfileString ( cgProgramProfile ); // arbvp1
        CGdomain cgProfileDomain = cgGetProfileDomain( cgProgramProfile );
        if ( profileString != NULL )
            shader.addCompilerTarget ( profileString );

        // Set a reference to the sources.
        const char* programEntryString = cgGetProgramString ( cgProgram, CG_PROGRAM_ENTRY ); // VShader || goochVS
        if ( programEntryString != NULL )
        {
            // Get the code sid
            COLLADA::URI fileURI = getShaderFxFileUri ();
            String codeSid = fileURI.getPathFileBase ();
            shader.addName ( programEntryString, codeSid );
        }

        // Add the bind parameters
        CGparameter progParam = cgGetFirstParameter ( cgProgram, CG_GLOBAL ); // CG_PROGRAM=IN || CG_GLOBAL
        while ( progParam )
        {
            const char* paramName = cgGetParameterName ( progParam ); // VShader
            CGtype paramType = cgGetParameterBaseType ( progParam );

            CGbool isUsed = cgIsParameterUsed ( progParam, cgProgram );
            if ( isUsed && !COLLADA::Utils::equals( paramName, programEntryString ) )
            {
                COLLADA::ParamBase bindParam ( streamWriter, COLLADA::CSWC::COLLADA_ELEMENT_BIND );
                bindParam.openParam ();
                bindParam.appendAttribute( COLLADA::CSWC::COLLADA_ATTRIBUTE_SYMBOL, paramName );
                COLLADA::ParamBase param ( streamWriter );
                param.openParam ( paramName );
                param.closeParam ();
                bindParam.closeParam ();
            }

            progParam = cgGetNextParameter ( progParam );
        }

        shader.closeShader();
    }

    // --------------------------------------
    template <class Type>
    void HwShaderExporter::exportRenderStateParam ( 
        const String& renderStateName, 
        const Type* values, 
        const int valueCount )
    {
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        COLLADA::ParamBase param ( streamWriter, renderStateName );
        param.openParam();
        for ( int j=0; j<valueCount; ++j )
            param.appendAttribute( COLLADA::CSWC::COLLADA_ATTRIBUTE_VALUE, 
                                    COLLADA::Utils::toString ( values[j] ) );
        param.closeParam();
    }

    // --------------------------------------
    void HwShaderExporter::exportRenderStateParam ( 
        const String& renderStateName, 
        const CGbool* values, 
        const int valueCount )
    {
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        COLLADA::ParamBase param ( streamWriter, renderStateName );
        param.openParam();
        for ( int j=0; j<valueCount; ++j )
        {
            if ( values[j] > 0 )
                param.appendAttribute( COLLADA::CSWC::COLLADA_ATTRIBUTE_VALUE, "true" );
            else
                param.appendAttribute( COLLADA::CSWC::COLLADA_ATTRIBUTE_VALUE, "false" );
        }
        param.closeParam();
    }

    // --------------------------------------
    void HwShaderExporter::exportPass ( const CGpass& cgPass )
    {
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Write the pass into the collada file
        COLLADA::Pass colladaPass ( streamWriter );
        const char* cgPassName = cgGetPassName ( cgPass );
        if ( cgPassName == NULL ) cgPassName = "";
        colladaPass.openPass ( cgPassName );

        // Go through the pass's render state assignments and write it into the collada file.
        // The shaders will be exported last.
        CGstateassignment cgStateAssignment = cgGetFirstStateAssignment ( cgPass );
        while ( cgStateAssignment )
        {
            // Export the current pass render state
            exportPassRenderState ( cgStateAssignment );

            // Get the next state assignment
            cgStateAssignment = cgGetNextStateAssignment( cgStateAssignment );            
        }

        // Export the shaders
        exportShaders ( cgPass );

        // Close the collada pass element
        colladaPass.closePass();
    }

    // --------------------------------------
    void HwShaderExporter::exportShaders ( const CGpass& cgPass )
    {
        CGstateassignment cgStateAssignment;

        // Export the vertex stage assignment
        cgStateAssignment = cgGetNamedStateAssignment ( cgPass, 
            COLLADA::CSWC::COLLADA_FX_SHADER_STAGE_VERTEXPROGRAM.c_str() );
        exportShaderProgramData ( cgStateAssignment );

        // Export the fragment stage assignment
        cgStateAssignment = cgGetNamedStateAssignment ( cgPass, 
            COLLADA::CSWC::COLLADA_FX_SHADER_STAGE_FRAGMENTPROGRAM.c_str() );
        exportShaderProgramData ( cgStateAssignment );
    }

    // --------------------------------------
    void HwShaderExporter::exportPassRenderState ( const CGstateassignment& cgStateAssignment )
    {
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Write the render states.
        CGstate cgState = cgGetStateAssignmentState ( cgStateAssignment );
        const char* cgStateNameC = cgGetStateName ( cgState );
        String cgStateName ( cgStateNameC );
        CGtype cgStateType = cgGetStateType ( cgState );

        COLLADA::RenderState::PassState passState = 
            COLLADA::RenderState::getRenderStateFromCgName( cgStateNameC );
        const String& renderStateName = COLLADA::RenderState::getColladaRenderStateName ( passState );

        switch ( cgStateType )
        {
        case CG_BOOL:
        case CG_BOOL1:
        case CG_BOOL2:
        case CG_BOOL3:
        case CG_BOOL4:
            {
                int valueCount = 0;
                const CGbool* values = cgGetBoolStateAssignmentValues( cgStateAssignment, &valueCount );
                exportRenderStateParam ( renderStateName, values, valueCount );
                break;
            } 
        case CG_INT:
        case CG_INT1:
        case CG_INT2:
        case CG_INT3:
        case CG_INT4:
            {
                int valueCount = 0;
                const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );

                COLLADA::ParamBase param ( streamWriter, renderStateName );
                param.openParam ();
                for ( int j=0; j<valueCount; ++j )
                {
                    const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[j] );
                    COLLADA::RenderState::PassStateFunction passStateFunction = 
                        COLLADA::RenderState::getPassStateFunction ( cgStateEnum );
                    const String renderStateFunctionName = 
                        COLLADA::RenderState::getColladaPassStateString ( passStateFunction );
                    param.appendAttribute ( COLLADA::CSWC::COLLADA_ATTRIBUTE_VALUE, renderStateFunctionName );
                }
                param.closeParam ();
                break;
            } 
        case CG_FLOAT:
        case CG_FLOAT1:
        case CG_FLOAT2:
        case CG_FLOAT3:
        case CG_FLOAT4:
            {
                int valueCount = 0;
                const float* values = cgGetFloatStateAssignmentValues( cgStateAssignment, &valueCount );
                exportRenderStateParam( renderStateName, values, valueCount );
                break;
            }
        case CG_STRING:
            {
                const char* val = cgGetStringStateAssignmentValue( cgStateAssignment );
                COLLADA::ParamBase param ( streamWriter, renderStateName );
                param.openParam();
                param.appendAttribute( COLLADA::CSWC::COLLADA_ATTRIBUTE_VALUE, val );
                param.closeParam();
                break;
            }
        case CG_TEXTURE:
            {
                CGparameter textureParam = cgGetTextureStateAssignmentValue ( cgStateAssignment );
                const char* textureName = cgGetParameterName( textureParam );
                COLLADA::ParamBase param ( streamWriter, renderStateName );
                param.openParam();
                param.appendAttribute( COLLADA::CSWC::COLLADA_ATTRIBUTE_VALUE, textureName );
                param.closeParam();
                break;
            }
        case CG_SAMPLER1D:
        case CG_SAMPLER2D:
        case CG_SAMPLER3D:
        case CG_SAMPLERCUBE:
        case CG_SAMPLERRECT:
            {
                CGparameter samplerParam = cgGetSamplerStateAssignmentValue ( cgStateAssignment );
                const char* samplerName = cgGetParameterName( samplerParam );
                COLLADA::ParamBase param ( streamWriter, renderStateName );
                param.openParam();
                param.appendAttribute( COLLADA::CSWC::COLLADA_ATTRIBUTE_VALUE, samplerName );
                param.closeParam();
                break;
            }
        case CG_PROGRAM_TYPE:   
            {
                // Nothing to do here, the shaders will be exported later.
//                 // Export the shader program data into the collada file
//                 exportShaderProgramData ( cgStateAssignment );
                break;
            } 
        default:
            assert ( "Parameter type not supported! " + cgStateType );
//            printf("UNEXPECTED CASE: 0x%x (%d)\n", cgStateType, cgStateType);
            break;

        }
    }

    // --------------------------------------
    void HwShaderExporter::exportEffectParameters ( const CGeffect& cgEffect )
    {
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Write the parameters
        CGparameter cgParameter = cgGetFirstEffectParameter ( cgEffect );
        while (cgParameter)
        {
            const char* paramName = cgGetParameterName ( cgParameter );
            CGresource resource = cgGetParameterBaseResource ( cgParameter );
            CGtype paramBaseType = cgGetParameterBaseType ( cgParameter );
            CGtype paramType = cgGetParameterType ( cgParameter );

            /* TYPE is int, float, or double or a sampler. */
            switch ( paramBaseType )
            {
            case CG_BOOL:
            {
                // TODO
                assert ( "Parameter type not supported! " + paramType );
                break;
            }
            case CG_INT:
            {
                // TODO
                // Create the parameter
                COLLADA::NewParam<int> newParam ( streamWriter );

                // Get the values
                int numOfValues = 0;
                CGenum valueType = CG_DEFAULT; // CG_CONSTANT || CG_CURRENT
                const double* paramValues = cgGetParameterValues( cgParameter, valueType, &numOfValues );

                assert ( "Parameter type not supported! " + paramType );
                break;
            }
            case CG_FLOAT:
            {
                // Create the parameter
                COLLADA::NewParam<double> newParam ( streamWriter );

                // Get the values
                int numOfValues = 0;
                CGenum valueType = CG_DEFAULT; // CG_CONSTANT
                const double* paramValues = cgGetParameterValues( cgParameter, valueType, &numOfValues );

                // Set the collada value type
                switch ( paramType )
                {
                case CG_FLOAT:
                case CG_HALF:
                    newParam.setParamType ( COLLADA::ValueType::FLOAT ); break;
                case CG_FLOAT2:
                case CG_HALF2:
                    newParam.setParamType ( COLLADA::ValueType::FLOAT2 ); break;
                case CG_FLOAT3:
                case CG_HALF3:
                    newParam.setParamType ( COLLADA::ValueType::FLOAT3 ); break;
                case CG_FLOAT4:
                case CG_HALF4:
                    newParam.setParamType ( COLLADA::ValueType::FLOAT4 ); break;
                case CG_FLOAT3x3:
                case CG_HALF3x3:
                    newParam.setParamType ( COLLADA::ValueType::FLOAT3x3 ); break;
                case CG_FLOAT4x4: 
                case CG_HALF4x4:
                    newParam.setParamType ( COLLADA::ValueType::FLOAT4x4 ); break;
                case CG_ARRAY:
                case CG_STRUCT:
                default:
                    newParam.setParamType ( COLLADA::ValueType::VALUE_TYPE_UNSPECIFIED ); break;
                }

                // Export the parameter data.
                exportParam ( cgParameter, &newParam, paramValues, numOfValues );

                break;  
            }
            case CG_STRING:
                {
                    // TODO
                    assert ( "Parameter type not supported! " + paramType );
                    break;
                }
            case CG_TEXTURE:
                {
                    // Nothing to do. Will be done with the sampler.
                    break;
                }
            case CG_SAMPLER1D:
            case CG_SAMPLER2D:
            case CG_SAMPLER3D:
            case CG_SAMPLERCUBE:
            case CG_SAMPLERRECT:
                {
                    // Create the sampler and add it into the collada document
                    exportSampler ( cgParameter );
                    break;
                }
            default:
                assert ( "Parameter type not supported! " + paramType );
                break;
           }

            cgParameter = cgGetNextParameter(cgParameter);
        }
    }

    // --------------------------------------
    template <class Type>
    void HwShaderExporter::exportParam ( 
        const CGparameter& cgParameter, 
        COLLADA::ParamBase* param, 
        const Type* paramValues, 
        const int numOfValues )
    {
        const char* paramName = cgGetParameterName ( cgParameter );
        param->openParam ( paramName );

        exportAnnotations ( cgParameter, param );
        exportSemantic ( cgParameter, param );

        for ( int i=0; i<numOfValues; ++i )
            param->appendValues ( paramValues[i] );

        param->closeParam();
    }

    // --------------------------------------
    void HwShaderExporter::exportAnnotations ( 
        const CGparameter& cgParameter, COLLADA::ParamBase* param )
    {
        CGannotation cgAnno = cgGetFirstParameterAnnotation ( cgParameter );
        while ( cgAnno )
        {
            CGtype cgAnnoType = cgGetAnnotationType( cgAnno );
            const char* cgAnnoName = cgGetAnnotationName( cgAnno );
            String annotationName ( cgAnnoName );
            switch ( cgAnnoType )
            {
            case CG_BOOL:
            case CG_BOOL1:
            case CG_BOOL2:
            case CG_BOOL3:
            case CG_BOOL4:
                {
                    int nvalues = 0;
                    const CGbool* values = cgGetBoolAnnotationValues( cgAnno, &nvalues );
                    param->addAnnotation ( annotationName, COLLADA::ValueType::BOOL, values, nvalues );
                    break;
                }
            case CG_INT:
            case CG_INT1:
            case CG_INT2:
            case CG_INT3:
            case CG_INT4:
                {
                    int nvalues = 0;
                    const int* values = cgGetIntAnnotationValues( cgAnno, &nvalues );
                    param->addAnnotation ( annotationName, COLLADA::ValueType::BOOL, values, nvalues );
                    break;
                }
            case CG_HALF:
            case CG_HALF2:
            case CG_HALF3:
            case CG_HALF4:
            case CG_FLOAT:
            case CG_FLOAT1:
            case CG_FLOAT2:
            case CG_FLOAT3:
            case CG_FLOAT4:
                {
                    int nvalues = 0;
                    const float* values = cgGetFloatAnnotationValues ( cgAnno, &nvalues );
                    param->addAnnotation ( annotationName, COLLADA::ValueType::FLOAT, values, nvalues );
                    break;
                }
            case CG_HALF4x4:
            case CG_FLOAT4x4:
                {
                    // TODO
                    assert ( "Annotation type not supported! " + cgAnnoType );
                    break;
                }
            case CG_STRING:
                {
                    const char* val = cgGetStringAnnotationValue ( cgAnno );
                    param->addAnnotation ( annotationName, COLLADA::ValueType::STRING, String ( val ) );
                    break;
                }
            default:
                assert ( "Annotation type not supported! " + cgAnnoType );
                break;
            }

            cgAnno = cgGetNextAnnotation ( cgAnno );
        }
    }

    // --------------------------------------
    void HwShaderExporter::exportSemantic ( const CGparameter& cgParameter, COLLADA::ParamBase* param )
    {
        const char *semantic = cgGetParameterSemantic( cgParameter );

        if ( semantic && strlen(semantic) ) 
            param->addSemantic ( semantic );
    }

    // --------------------------------------
    void HwShaderExporter::exportSampler ( const CGparameter& cgParameter )
    {
        if ( cgGetParameterClass ( cgParameter ) != CG_PARAMETERCLASS_SAMPLER ) return;

        // Get a pointer to the current stream writer.
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the name of the current parameter
        const char* paramName = cgGetParameterName ( cgParameter );

        // Create the collada sampler object
        COLLADA::Sampler sampler ( COLLADA::Sampler::SAMPLER_TYPE_UNSPECIFIED );

        // The texture parameter (a sampler must have a texture)
        CGparameter cgTextureParam = NULL;
        CGstateassignment cgStateAssignment;
        int valueCount = 0;

        // Look for the "source" state assignment
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADA::CSWC::COLLADA_ELEMENT_TEXTURE.c_str() );
        if ( cgStateAssignment )
        {
            cgTextureParam = cgGetTextureStateAssignmentValue ( cgStateAssignment );
            const char* textureName = cgGetParameterName ( cgTextureParam );
            sampler.setSource ( textureName );
        }

        // Look for the wraps
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADA::CSWC::COLLADA_ELEMENT_WRAP_S.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );
            const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[0] );
            sampler.setWrapS ( COLLADA::OPEN_GL::getWrapModeFromOpenGL ( cgStateEnum ) );
        }
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADA::CSWC::COLLADA_ELEMENT_WRAP_T.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );
            const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[0] );
            sampler.setWrapT ( COLLADA::OPEN_GL::getWrapModeFromOpenGL ( cgStateEnum ) );
        }
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADA::CSWC::COLLADA_ELEMENT_WRAP_P.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );
            const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[0] );
            sampler.setWrapP ( COLLADA::OPEN_GL::getWrapModeFromOpenGL ( cgStateEnum ) );
        }

        // Look for the filters
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADA::CSWC::COLLADA_ELEMENT_MAGFILTER.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );
            const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[0] );
            sampler.setMagFilter( COLLADA::OPEN_GL::getSamplerFilterFromOpenGL ( cgStateEnum ) );
        }
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADA::CSWC::COLLADA_ELEMENT_MINFILTER.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );
            const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[0] );
            sampler.setMinFilter( COLLADA::OPEN_GL::getSamplerFilterFromOpenGL ( cgStateEnum ) );
        }
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADA::CSWC::COLLADA_ELEMENT_MIPFILTER.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );
            const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[0] );
            sampler.setMipFilter( COLLADA::OPEN_GL::getSamplerFilterFromOpenGL ( cgStateEnum ) );
        }

        // Look for the border color
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADA::CSWC::COLLADA_ELEMENT_BORDER_COLOR.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const float* values = cgGetFloatStateAssignmentValues ( cgStateAssignment, &valueCount );
            if ( valueCount == 3 ) 
                sampler.setBorderColor ( COLLADA::Color ( values[0], values[1], values[2] ) );
            else if ( valueCount == 4 ) 
                sampler.setBorderColor ( COLLADA::Color ( values[0], values[1], values[2], values[3] ) );
        }

        // Look for the mipmaps
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADA::CSWC::COLLADA_ELEMENT_MIPMAP_MAXLEVEL.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );
            sampler.setMipmapMaxlevel ( ( unsigned char ) ( values[0] ) );
        }
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADA::CSWC::COLLADA_ELEMENT_MIPMAP_BIAS.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const float* values = cgGetFloatStateAssignmentValues ( cgStateAssignment, &valueCount );
            sampler.setMipmapBias ( values[0] );
        }

        // TODO Look for extra tags
//        exportSamplerStateAssignments (cgParameter, cgTextureParam, surfaceType, samplerType, samplerValueType);

        // Get the type of the resource ( 1D, 2D, 3D, CUBE )
        COLLADA::Surface::SurfaceType surfaceType = COLLADA::Surface::SURFACE_TYPE_UNSPECIFIED;
        COLLADA::Sampler::SamplerType samplerType = COLLADA::Sampler::SAMPLER_TYPE_UNSPECIFIED;
        COLLADA::ValueType::ColladaType samplerValueType = COLLADA::ValueType::VALUE_TYPE_UNSPECIFIED;

        if ( cgTextureParam )
        {
            // Get the type of the resource, if is set.
            getResourceType ( cgTextureParam, surfaceType, samplerType, samplerValueType );

            // Set the sampler type
            sampler.setSamplerType ( samplerType );

            // Add the texture, if exist
            exportTexture ( cgTextureParam, surfaceType );
        }

        // Open the samplers newparam
        COLLADA::NewParamSampler paramSampler ( streamWriter );
        paramSampler.setParamType( samplerValueType );
        paramSampler.openParam ( paramName );
        exportAnnotations ( cgParameter, &paramSampler );

        // Write the sampler data into the collada file.
        sampler.add ( streamWriter );
        paramSampler.closeParam ();

    }

    // --------------------------------------
    void HwShaderExporter::exportTexture ( 
        const CGparameter& cgTextureParam, 
        const COLLADA::Surface::SurfaceType& surfaceType )
    {
        CGtype paramType = cgGetParameterBaseType( cgTextureParam );
        if ( paramType != CG_TEXTURE ) return;

        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Name of the current texture
        const char* cgTextureName = cgGetParameterName( cgTextureParam );

        // Create the surface
        COLLADA::Surface surface ( surfaceType, cgTextureName );
        surface.setFormat ( "A8R8G8B8" );

        // Create the surface init option
        COLLADA::SurfaceInitOption initOption ( COLLADA::SurfaceInitOption::INIT_FROM );

        // Get the name of the resource for default value
        CGannotation resourceNameAnnotation = 
            cgGetNamedParameterAnnotation( cgTextureParam, 
            COLLADA::CSWC::COLLADA_FX_ANNOTATION_RESOURCE_NAME.c_str() );
        if ( resourceNameAnnotation )
        {
            // Get the name of the annotation
            const char* annotationValue = cgGetStringAnnotationValue ( resourceNameAnnotation );

            // Get the image path
            COLLADA::URI shaderFxFileUri = getShaderFxFileUri();

            // Take the filename for the unique image name 
            COLLADA::URI sourceUri ( shaderFxFileUri, String ( annotationValue ) );
            String imageId = sourceUri.getPathFileBase();

            // Export the image
            EffectTextureExporter* textureExporter = 
                mDocumentExporter->getEffectExporter()->getTextureExporter();
            COLLADA::Image* colladaImage = textureExporter->exportImage ( imageId, sourceUri.getURIString() );

            // Get the image id of the exported collada image 
            imageId = colladaImage->getImageId();

            // Set the image reference
            initOption.setImageReference ( imageId );
        }
        surface.setInitOption ( initOption );

        // Add the surface <newparam>
        COLLADA::NewParamSurface paramSurface ( streamWriter );
        paramSurface.openParam ( cgTextureName );
        exportAnnotations( cgTextureParam, &paramSurface );
        surface.add ( streamWriter );
        paramSurface.closeParam ();
    }

    // --------------------------------------
    void HwShaderExporter::setShaderFxFileUri( const COLLADA::URI& shaderFxFileName )
    {
        mShaderFxFileUri = shaderFxFileName;
    }

    // --------------------------------------
    const COLLADA::URI& HwShaderExporter::getShaderFxFileUri() const
    {
        return mShaderFxFileUri;
    }

    // --------------------------------------
    void HwShaderExporter::getResourceType( 
        const CGparameter& cgTextureParam, 
        COLLADA::Surface::SurfaceType &surfaceType, 
        COLLADA::Sampler::SamplerType &samplerType, 
        COLLADA::ValueType::ColladaType &samplerValueType )
    {
        // Get the type of the resource for default value
        CGannotation resourceTypeAnnotation = 
            cgGetNamedParameterAnnotation( cgTextureParam, 
            COLLADA::CSWC::COLLADA_FX_ANNOTATION_RESOURCE_TYPE.c_str() );
        if ( resourceTypeAnnotation )
        {
            // Get the name of the annotation
            const char* annotationValue = cgGetStringAnnotationValue ( resourceTypeAnnotation );
            String resourceTypeString ( annotationValue );

            if ( COLLADA::Utils::equalsIgnoreCase ( resourceTypeString, COLLADA::CSWC::COLLADA_SURFACE_TYPE_1D ) )
            {
                surfaceType = COLLADA::Surface::SURFACE_TYPE_1D;
                samplerType = COLLADA::Sampler::SAMPLER_TYPE_1D;
                samplerValueType = COLLADA::ValueType::SAMPLER_1D;
            }
            else if ( COLLADA::Utils::equalsIgnoreCase ( resourceTypeString, COLLADA::CSWC::COLLADA_SURFACE_TYPE_2D ) )
            {
                surfaceType = COLLADA::Surface::SURFACE_TYPE_2D;
                samplerType = COLLADA::Sampler::SAMPLER_TYPE_2D;
                samplerValueType = COLLADA::ValueType::SAMPLER_2D;
            }
            else if ( COLLADA::Utils::equalsIgnoreCase ( resourceTypeString, COLLADA::CSWC::COLLADA_SURFACE_TYPE_3D ) )
            {
                surfaceType = COLLADA::Surface::SURFACE_TYPE_3D;
                samplerType = COLLADA::Sampler::SAMPLER_TYPE_3D;
                samplerValueType = COLLADA::ValueType::SAMPLER_3D;
            }
            else if ( COLLADA::Utils::equalsIgnoreCase ( resourceTypeString, COLLADA::CSWC::COLLADA_SURFACE_TYPE_CUBE ) )
            {
                surfaceType = COLLADA::Surface::SURFACE_TYPE_CUBE;
                samplerType = COLLADA::Sampler::SAMPLER_TYPE_CUBE;
                samplerValueType = COLLADA::ValueType::SAMPLER_CUBE;
            }
            else if ( COLLADA::Utils::equalsIgnoreCase ( resourceTypeString, COLLADA::CSWC::COLLADA_SURFACE_TYPE_RECT ) )
            {
                surfaceType = COLLADA::Surface::SURFACE_TYPE_RECT;
                samplerType = COLLADA::Sampler::SAMPLER_TYPE_RECT;
                samplerValueType = COLLADA::ValueType::SAMPLER_RECT;
            }
        }
    }

    // --------------------------------------
    String HwShaderExporter::getProgramSourceString ( const char* programSourceCG )
    {
        // Generate the source string
        String sourceString ( programSourceCG );

        COLLADA::Utils::translateToXML ( sourceString );

//         // Remove the comments /** */
//         String uncommentedString = sourceString;
//         size_t commentStart = uncommentedString.find ( "/*" );
//         while ( commentStart != String::npos )
//         {
//             size_t commentEnd = uncommentedString.find ( "*/" );
//             String startString = uncommentedString.substr ( 0, commentStart );
//             String endString = uncommentedString.substr ( commentEnd+2 );
//             uncommentedString = startString + endString;
//             commentStart = uncommentedString.find ( "/*" );
//         }
//         sourceString = uncommentedString;
// 
//         // Remove the // comments (valid until line end)
//         uncommentedString = sourceString;
//         commentStart = uncommentedString.find ( "//" );
//         while ( commentStart != String::npos )
//         {
//             size_t commentEnd = uncommentedString.find ( '\n' );
//             String commentString = uncommentedString.substr ( commentStart );
//             String startString = uncommentedString.substr ( 0, commentStart );
//             String endString = uncommentedString.substr ( commentEnd+2 );
//             uncommentedString = startString + endString;
//             commentStart = uncommentedString.find ( "//" );
//         }
//         sourceString = uncommentedString;

        // TODO Remove all techniques.

        // Find the position of the first "technique" element
        size_t techniqueStart = sourceString.find ( COLLADA::CSWC::COLLADA_ELEMENT_TECHNIQUE );

        // Get the substring from the beginning to the first "technique" element 
        String withoutTechniqueString = sourceString.substr ( 0, techniqueStart );

        // TODO Don't believe, that the "technique" element is always the last...
//         String withTechniqueString = sourceString.substr ( techniqueStart+COLLADA::CSWC::COLLADA_ELEMENT_TECHNIQUE.length() );
//         
//         size_t numOfOpenBraces = 0;
// 
//         size_t braceOpenPos = withTechniqueString.find ( "{" );
//         if ( braceOpenPos != String::npos )
//         {
//             numOfOpenBraces += 1;
//             size_t braceClosePos = withTechniqueString.find ( "}" );
// 
//             String nextOpenString = withTechniqueString.substr ( braceOpenPos );
//             size_t nextBraceOpenPos = nextOpenString.find ( "{" );
// 
//             if ( nextBraceOpenPos < braceClosePos )
//             {
//                 numOfOpenBraces += 1;
//             }
//             else
//             {
//                 withoutTechniqueString += 
//             }
//         }

        return withoutTechniqueString;
    }

}