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

        // Writes the current effect profile into the collada document
        mEffectProfile->openProfile ();

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
            // Exports the effect data of a cgfxShader node.
            exportCgfxShader( fnNode );
        }

        mEffectProfile->addProfileElements ();
        mEffectProfile->closeProfile ();

//        exportStandardShader( effectId, effectProfile, shaderNode );
    }

    // ---------------------------------
    void HwShaderExporter::exportCgfxShader( MFnDependencyNode& fnNode )
    {
        mEffectProfile->setProfileType ( COLLADA::EffectProfile::CG );
        mEffectProfile->openProfile ();

        // Get a pointer to the current stream writer
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Create a cgfx shader node
        cgfxShaderNode* shaderNodeCgfx = ( cgfxShaderNode* ) fnNode.userNode();

        // Get the filename of the current cgfx file
        MString shaderFxFile = shaderNodeCgfx->shaderFxFile();
        String shaderFxFileName = shaderFxFile.asChar(); // check3d.cgfx
        setShaderFxFileUri ( COLLADA::URI ( shaderFxFileName ) );

        // Export the effects parameter
        CGeffect cgEffect = shaderNodeCgfx->effect();
        exportEffectParameters ( cgEffect );

//         cgfxAttrDefList* effectAttributes = cgfxAttrDef::attrsFromEffect ( cgEffect, cgTechnique );
//         cout << "effectAttributes: " << endl;
//         MString sResult, sTemp;
//         cgfxAttrDefList::iterator effectIt;
//         for ( effectIt=effectAttributes->begin(); effectIt; ++effectIt )
//         {
//             cgfxAttrDef* effectAttribute = *effectIt;
//             setNewParam ( shaderNodeCgfx, effectAttribute );
//         }


        // Find if effect parameter is used by any program of the selected technique
        CGtechnique cgTechnique = cgGetFirstTechnique ( cgEffect );
        while ( cgTechnique )
        {
            exportTechnique ( cgTechnique );
            cgTechnique = cgGetNextTechnique ( cgTechnique );
        }

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
        mEffectProfile->closeTechnique();

    }

    // --------------------------------------
    void HwShaderExporter::exportShaderProgramData ( 
        CGstateassignment& cgStateAssignment, 
        bool readCode )
    {
        // Get the current stream writer
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Write the render states.
        CGstate cgState = cgGetStateAssignmentState ( cgStateAssignment );
        const char* cgStateNameC = cgGetStateName ( cgState );
        String cgStateName ( cgStateNameC );
        CGtype cgStateType = cgGetStateType ( cgState );
        if ( cgStateType != CG_PROGRAM_TYPE ) return;

        // Create a shader and export it
        COLLADA::Shader shader ( streamWriter, cgStateName );
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

        // Get the code sid
        COLLADA::URI fileURI = getShaderFxFileUri ();
        String codeSid = fileURI.getPathFileBase ();

        // Add the sources, if not done before.
        if ( mEffectProfile->getCode().empty() )
        {
            // "technique" is a reserved word in cgfx, so we can search for it and copy all to this for sources
            const char* programSourceCG = cgGetProgramString ( cgProgram, CG_PROGRAM_SOURCE );
            String sourceString = getProgramSourceString ( programSourceCG );

            mEffectProfile->setCode ( sourceString, codeSid );
        }

        // Set a reference to the sources.
        const char* programEntryString = cgGetProgramString ( cgProgram, CG_PROGRAM_ENTRY ); // VShader || goochVS
        if ( programEntryString != NULL )
        {
            COLLADA::URI fileURI = getShaderFxFileUri();
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
        int valueCount )
    {
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        COLLADA::ParamBase param ( streamWriter, renderStateName );
        param.openParam();
        for ( int j=0; j<valueCount; ++j )
            param.appendAttribute( COLLADA::CSWC::COLLADA_ATTRIBUTE_VALUE, COLLADA::Utils::toString ( values[j] ) );
        param.closeParam();
    }

    // --------------------------------------
    void HwShaderExporter::exportPass ( CGpass& cgPass )
    {
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Write the pass into the collada file
        COLLADA::Pass colladaPass ( streamWriter );
        const char* cgPassName = cgGetPassName ( cgPass );
        if ( cgPassName == NULL ) cgPassName = "";
        colladaPass.openPass ( cgPassName );

        // Go through the pass's state assignments and write it into the collada file.
        CGstateassignment cgStateAssignment = cgGetFirstStateAssignment ( cgPass );
        while ( cgStateAssignment )
        {
            // Export the current pass state
            exportPassState ( cgStateAssignment );

            // Get the next state assignment
            cgStateAssignment = cgGetNextStateAssignment( cgStateAssignment );            
        }

        colladaPass.closePass();
    }

    // --------------------------------------
    void HwShaderExporter::exportPassState ( CGstateassignment& cgStateAssignment )
    {
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Write the render states.
        CGstate cgState = cgGetStateAssignmentState ( cgStateAssignment );
        const char* cgStateNameC = cgGetStateName ( cgState );
        String cgStateName ( cgStateNameC );
        CGtype cgStateType = cgGetStateType ( cgState );

        COLLADA::RenderState renderState;
        COLLADA::PassState::State passState = renderState.cgStateToColladaTranslation( cgStateNameC );
        const String& renderStateName = renderState.colladaToCgStateTranslation( passState );

        int numDependents = cgGetNumDependentStateAssignmentParameters ( cgStateAssignment );

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
                    param.appendAttribute ( COLLADA::CSWC::COLLADA_ATTRIBUTE_VALUE, cgStateEnum );
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
                // Export the shader program data into the collada file
                exportShaderProgramData ( cgStateAssignment );
                break;
            } 
        default:
            assert ( "Parameter type not supported! " + cgStateType );
//            printf("UNEXPECTED CASE: 0x%x (%d)\n", cgStateType, cgStateType);
            break;

        }
    }

    // --------------------------------------
    void HwShaderExporter::exportEffectParameters ( CGeffect& cgEffect )
    {
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Write the parameters
        CGparameter cgParameter = cgGetFirstEffectParameter ( cgEffect );
        while (cgParameter)
        {
            const char* paramName = cgGetParameterName ( cgParameter );
            CGresource resource = cgGetParameterBaseResource ( cgParameter );
            CGtype paramType = cgGetParameterBaseType ( cgParameter );

            switch ( paramType )
            {
            case CG_BOOL:
            case CG_BOOL1:
            case CG_BOOL2:
            case CG_BOOL3:
            case CG_BOOL4:
            {
                // TODO
                assert ( "Parameter type not supported! " + paramType );
                break;
            }
            case CG_INT:
            case CG_INT1:
            case CG_INT2:
            case CG_INT3:
            case CG_INT4:
            {
                // TODO
                assert ( "Parameter type not supported! " + paramType );
                break;
            }
            case CG_FLOAT:
            case CG_FLOAT1:
            case CG_FLOAT2:
            case CG_FLOAT3:
            case CG_FLOAT4:
            {
                COLLADA::NewParamFloat newParam ( streamWriter );
                newParam.openParam ( paramName );
                const char *semantic = cgGetParameterSemantic( cgParameter );
                if ( semantic && strlen(semantic) ) newParam.addSemantic ( semantic );
                exportAnnotations ( cgParameter, &newParam );
                int numberOfValuesReturned = 0;
                CGenum valueType = CG_DEFAULT; // CG_CONSTANT
                const double* values1 = cgGetParameterValues( cgParameter, valueType, &numberOfValuesReturned );
                for ( int i=0; i<numberOfValuesReturned; ++i )
                    newParam.appendValues ( values1[i] );
                newParam.closeParam();
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
    void HwShaderExporter::exportSamplerStateAssignments ( 
        const CGparameter& cgParameter, 
        CGparameter& cgTextureParam )
    {
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        CGstateassignment cgStateAssignment = cgGetFirstSamplerStateAssignment ( cgParameter );
        while ( cgStateAssignment )
        {
            // Write the render states.
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const char* cgStateNameC = cgGetStateName ( cgState );
            String cgStateName ( cgStateNameC );
            CGtype cgStateType = cgGetStateType ( cgState );

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
                    COLLADA::ParamBase param ( streamWriter, cgStateName );
                    param.openParam();
                    for ( int j=0; j<valueCount; ++j )
                        param.appendValues( values[j] );
                    param.closeParam();
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
                    COLLADA::ParamBase param ( streamWriter, cgStateName );
                    param.openParam();
                    for ( int j=0; j<valueCount; ++j )
                    {
                        const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[j] );
                        param.appendValues ( String ( cgStateEnum ) );
                    }
                    param.closeParam();
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
                    COLLADA::ParamBase param ( streamWriter, cgStateName );
                    param.openParam();
                    for ( int j=0; j<valueCount; ++j )
                        param.appendValues( values[j] );
                    param.closeParam();
                    break;
                }
            case CG_STRING:
                {
                    const char* val = cgGetStringStateAssignmentValue( cgStateAssignment );
                    COLLADA::ParamBase param ( streamWriter, cgStateName );
                    param.openParam();
                    param.appendValues( String ( val ) );
                    param.closeParam();
                    break;
                }
            case CG_TEXTURE:
                {
                    cgTextureParam = cgGetTextureStateAssignmentValue ( cgStateAssignment );
                    const char* textureName = cgGetParameterName( cgTextureParam );
                    streamWriter->appendTextElement( COLLADA::CSWC::COLLADA_ELEMENT_SOURCE, textureName );
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
                    COLLADA::ParamBase param ( streamWriter, cgStateName );
                    param.openParam();
                    param.appendValues( String ( samplerName ) );
                    param.closeParam();
                    break;
                }
            case CG_PROGRAM_TYPE:   
                {
                    // Export the shader program data into the collada file
                    exportShaderProgramData ( cgStateAssignment );
                    break;
                } 
            default:
                assert ( "Parameter type not supported! " + cgStateType );
                break;
            }

            cgStateAssignment = cgGetNextStateAssignment ( cgStateAssignment );
        }
    }

    // --------------------------------------
    void HwShaderExporter::exportSampler ( CGparameter& cgParameter )
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

    //------------------------------------------------------
    void HwShaderExporter::setNewParam ( const cgfxShaderNode* shaderNodeCgfx, const cgfxAttrDef* attribute )
    {
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
        String attributeName = attribute->fName.asChar();
        const char* suffix = attribute->getExtraAttrSuffix ();
        String semantic = attribute->fSemantic.asChar();
        String description = attribute->fDescription.asChar();
        double* minimum = attribute->fNumericMin;
        double* maximum = attribute->fNumericMin;

        cgfxAttrDef::cgfxAttrType attributeType = attribute->fType;
        switch ( attributeType )
        {
        case cgfxAttrDef::kAttrTypeBool:
            {
                COLLADA::NewParamBool newParam ( streamWriter );
                newParam.openParam ( attributeName );
                prepareParam ( newParam, attribute );
                newParam.appendValues ( attribute->fNumericDef && attribute->fNumericDef[0] );
                newParam.closeParam ();
                break;
            }
        case cgfxAttrDef::kAttrTypeInt:
            {
                COLLADA::NewParamInt newParam ( streamWriter );
                newParam.openParam ( attributeName );
                prepareParam ( newParam, attribute );
                newParam.appendValues ( (int) attribute->fNumericDef[0] );
                newParam.closeParam();
                break;
            }
        case cgfxAttrDef::kAttrTypeString:
            {
                COLLADA::NewParamString newParam ( streamWriter );
                newParam.openParam ( attributeName );
                prepareParam ( newParam, attribute );
                newParam.appendValues ( String ( attribute->fStringDef.asChar() ) );
                newParam.closeParam();
                break;
            }
        case cgfxAttrDef::kAttrTypeFloat:
            {
                COLLADA::NewParamFloat newParam ( streamWriter );
                newParam.openParam ( attributeName );
                prepareParam ( newParam, attribute );
                newParam.appendValues ( attribute->fNumericDef[0] );
                newParam.closeParam();
                break;
            }
        case cgfxAttrDef::kAttrTypeVector2:
            {
                COLLADA::NewParamFloat2 newParam ( streamWriter );
                newParam.openParam ( attributeName );
                prepareParam ( newParam, attribute );
                for ( int i=0; i<attribute->fSize; ++i )
                {
                    double val = attribute->fNumericDef[i];
                    newParam.appendValues( val );
                }
                newParam.closeParam();
                break;
            }
        case cgfxAttrDef::kAttrTypeVector3:
        case cgfxAttrDef::kAttrTypeColor3:
            {
                COLLADA::NewParamFloat3 newParam ( streamWriter );
                newParam.openParam ( attributeName );
                prepareParam ( newParam, attribute );
                for ( int i=0; i<attribute->fSize; ++i )
                {
                    if ( attribute->fNumericDef!=NULL && attribute->fNumericDef[i]!=NULL )  
                    {
                        double val = attribute->fNumericDef[i];
                        newParam.appendValues( val );
                    }
                }
                newParam.closeParam();
                break;
            }
        case cgfxAttrDef::kAttrTypeVector4:
        case cgfxAttrDef::kAttrTypeColor4:
            {
                COLLADA::NewParamFloat4 newParam ( streamWriter );
                newParam.openParam ( attributeName );
                prepareParam ( newParam, attribute );
                for ( int i=0; i<attribute->fSize; ++i )
                {
                    double val = attribute->fNumericDef[i];
                    newParam.appendValues( val );
                }
                newParam.closeParam ();
                break;
            }
        case cgfxAttrDef::kAttrTypeWorldDir:
        case cgfxAttrDef::kAttrTypeWorldPos:
            {
                // Read the value
                double tmp[4];
                for ( int i=0; i<attribute->fSize; ++i )
                {
                    tmp[i] = attribute->fNumericDef[i];
                }
                if (attribute->fSize == 3) tmp[3] = 1.0;

                // Find the coordinate space, and whether it is a point or a vector
                int base = cgfxAttrDef::kAttrTypeFirstPos;
                if (attribute->fType <= cgfxAttrDef::kAttrTypeLastDir) 
                    base = cgfxAttrDef::kAttrTypeFirstDir;
                int space = attribute->fType - base;

                // Compute the transform matrix
                MMatrix mat;
                switch (space)
                {
                    /* case 0:	object space, handled in view dependent method */
                case 1:	/* world space  - do nothing, identity */ break;
                    /* case 2: eye space, unsupported yet */
                    /* case 3: clip space, unsupported yet */
                    /* case 4: screen space, unsupported yet */
                }

                if ( base == cgfxAttrDef::kAttrTypeFirstPos )
                {
                    MPoint point(tmp[0], tmp[1], tmp[2], tmp[3]);
                    point *= mat;
                    tmp[0] = point.x;
                    tmp[1] = point.y;
                    tmp[2] = point.z;
                    tmp[3] = point.w;
                }
                else
                {
                    MVector vec(tmp[0], tmp[1], tmp[2]);
                    vec *= mat;
                    tmp[0] = vec.x;
                    tmp[1] = vec.y;
                    tmp[2] = vec.z;
                    tmp[3] = 1;
                }

                COLLADA::NewParamFloat4 newParam ( streamWriter );
                newParam.openParam ( attributeName );
                prepareParam ( newParam, attribute );
                newParam.appendValues( tmp[0], tmp[1], tmp[2], tmp[3] );
                newParam.closeParam();
                break;
            }
        case cgfxAttrDef::kAttrTypeMatrix:
        case cgfxAttrDef::kAttrTypeWorldMatrix:
        case cgfxAttrDef::kAttrTypeViewMatrix:
        case cgfxAttrDef::kAttrTypeProjectionMatrix:
        case cgfxAttrDef::kAttrTypeWorldViewMatrix:
        case cgfxAttrDef::kAttrTypeWorldViewProjectionMatrix:
            {
                COLLADA::NewParamFloat4x4 newParam ( streamWriter );
                newParam.openParam ( attributeName );
                prepareParam ( newParam, attribute );

                MMatrix mayaMatrix;
                double* p = &mayaMatrix.matrix[0][0];
                for ( int k=0; k<attribute->fSize; ++k )
                {
                    p[k] = attribute->fNumericDef[k];
                }

                MMatrix wMatrix, vMatrix, pMatrix, sMatrix;
                MMatrix wvMatrix, wvpMatrix, wvpsMatrix;
                {
                    float tmp[4][4];

                    wMatrix.setToIdentity();

                    glGetFloatv(GL_MODELVIEW_MATRIX, &tmp[0][0]);
                    wvMatrix = MMatrix(tmp);

                    vMatrix = wMatrix.inverse() * wvMatrix;

                    glGetFloatv(GL_PROJECTION_MATRIX, &tmp[0][0]);
                    pMatrix = MMatrix(tmp);

                    wvpMatrix = wvMatrix * pMatrix;

                    float vpt[4];
                    float depth[2];

                    glGetFloatv(GL_VIEWPORT, vpt);
                    glGetFloatv(GL_DEPTH_RANGE, depth);

                    // Construct the NDC -> screen space matrix
                    //
                    float x0, y0, z0, w, h, d;

                    x0 = vpt[0];
                    y0 = vpt[1];
                    z0 = depth[0];
                    w  = vpt[2];
                    h  = vpt[3];
                    d  = depth[1] - z0;

                    // Make a reference to ease the typing
                    //
                    double* s = &sMatrix.matrix[0][0];

                    s[ 0] = w/2;	s[ 1] = 0.0;	s[ 2] = 0.0;	s[ 3] = 0.0;
                    s[ 4] = 0.0;	s[ 5] = h/2;	s[ 6] = 0.0;	s[ 7] = 0.0;
                    s[ 8] = 0.0;	s[ 9] = 0.0;	s[10] = d/2;	s[11] = 0.0;
                    s[12] = x0+w/2;	s[13] = y0+h/2;	s[14] = z0+d/2;	s[15] = 1.0;

                    wvpsMatrix = wvpMatrix * sMatrix;
                }		

                switch ( attribute->fType )
                {
                case cgfxAttrDef::kAttrTypeWorldMatrix:
                    mayaMatrix = wMatrix; break;
                case cgfxAttrDef::kAttrTypeViewMatrix:
                    mayaMatrix = vMatrix; break;
                case cgfxAttrDef::kAttrTypeProjectionMatrix:
                    mayaMatrix = pMatrix; break;
                case cgfxAttrDef::kAttrTypeWorldViewMatrix:
                    mayaMatrix = wvMatrix; break;
                case cgfxAttrDef::kAttrTypeWorldViewProjectionMatrix:
                    mayaMatrix = wvpMatrix; break;
                default:
                    break;
                }

                if (attribute->fInvertMatrix)
                    mayaMatrix = mayaMatrix.inverse();

                if (!attribute->fTransposeMatrix)
                    mayaMatrix = mayaMatrix.transpose();

                double matrix[4][4];
                convertMMatrixToDouble4x4 ( matrix, mayaMatrix );
                newParam.appendValues( matrix );
                newParam.closeParam();
                break;
            }
        case cgfxAttrDef::kAttrTypeColor1DTexture:
        case cgfxAttrDef::kAttrTypeColor2DTexture:
        case cgfxAttrDef::kAttrTypeColor3DTexture:
        case cgfxAttrDef::kAttrTypeColor2DRectTexture:
        case cgfxAttrDef::kAttrTypeNormalTexture:
        case cgfxAttrDef::kAttrTypeBumpTexture:
        case cgfxAttrDef::kAttrTypeCubeTexture:
        case cgfxAttrDef::kAttrTypeEnvTexture:
        case cgfxAttrDef::kAttrTypeNormalizationTexture:
            {
                // -------------------------------
                MObject oNode = shaderNodeCgfx->thisMObject();
                MFnDependencyNode oNodeFn ( oNode );
                String oNodeName = oNodeFn.name().asChar(); // cgfxShader1

                MPlug plug;
                if ( DagHelper::getPlugConnectedTo( oNode, attributeName, plug ) )
                {
                    String plugName = plug.name().asChar(); // file1.outColor
                    MObject textureNode = plug.node();

                    COLLADA::Surface::SurfaceType surfaceType;
                    COLLADA::Sampler::SamplerType samplerType;
                    COLLADA::ValueType::ColladaType samplerValueType;

                    switch ( attributeType )
                    {
                    case cgfxAttrDef::kAttrTypeColor1DTexture:
                        surfaceType = COLLADA::Surface::SURFACE_TYPE_1D;
                        samplerType = COLLADA::Sampler::SAMPLER_TYPE_1D;
                        samplerValueType = COLLADA::ValueType::SAMPLER_1D;
                        break;
                    case cgfxAttrDef::kAttrTypeColor2DTexture:
                    case cgfxAttrDef::kAttrTypeNormalTexture:
                    case cgfxAttrDef::kAttrTypeBumpTexture:
                        surfaceType = COLLADA::Surface::SURFACE_TYPE_2D;
                        samplerType = COLLADA::Sampler::SAMPLER_TYPE_2D;
                        samplerValueType = COLLADA::ValueType::SAMPLER_2D;
                        break;
                    case cgfxAttrDef::kAttrTypeColor3DTexture:
                        surfaceType = COLLADA::Surface::SURFACE_TYPE_3D;
                        samplerType = COLLADA::Sampler::SAMPLER_TYPE_3D;
                        samplerValueType = COLLADA::ValueType::SAMPLER_3D;
                        break;
                    case cgfxAttrDef::kAttrTypeColor2DRectTexture:
                        surfaceType = COLLADA::Surface::SURFACE_TYPE_RECT;
                        samplerType = COLLADA::Sampler::SAMPLER_TYPE_RECT;
                        samplerValueType = COLLADA::ValueType::SAMPLER_RECT;
                        break;
                    case cgfxAttrDef::kAttrTypeCubeTexture:
                    case cgfxAttrDef::kAttrTypeEnvTexture:
                    case cgfxAttrDef::kAttrTypeNormalizationTexture:
                        surfaceType = COLLADA::Surface::SURFACE_TYPE_CUBE;
                        samplerType = COLLADA::Sampler::SAMPLER_TYPE_CUBE;
                        samplerValueType = COLLADA::ValueType::SAMPLER_CUBE;
                        break;
                    default:
                        surfaceType = COLLADA::Surface::SURFACE_TYPE_UNTYPED;
                        samplerType = COLLADA::Sampler::SAMPLER_TYPE_UNSPECIFIED;
                        samplerValueType = COLLADA::ValueType::VALUE_TYPE_UNSPECIFIED;
                    }

                    // Write the params elements
                    setNewParamTexture( attribute, textureNode, surfaceType, samplerType, samplerValueType );

                }
            }
        }
    }

    // --------------------------------------
    template<class Type>
    void HwShaderExporter::prepareParam ( Type &newParam, const cgfxAttrDef* attribute )
    {
        String attributeName = attribute->fName.asChar();
        cgfxAttrDef::cgfxAttrType attributeType = attribute->fType;
        const char* suffix = attribute->getExtraAttrSuffix ();
        String semantic = attribute->fSemantic.asChar();
        String description = attribute->fDescription.asChar();
        double* minimum = attribute->fNumericMin;
        double* maximum = attribute->fNumericMin;

        if ( !semantic.empty() ) newParam.addSemantic ( semantic );

        if ( !description.empty() ) 
            newParam.addAnnotation ( 
            COLLADA::CSWC::COLLADA_FX_ANNOTATION_UI_NAME, 
            COLLADA::ValueType::STRING, description );

        if ( minimum != NULL )
            newParam.addAnnotation ( 
            COLLADA::CSWC::COLLADA_FX_ANNOTATION_UI_MIN, 
            COLLADA::ValueType::FLOAT, *minimum );

        if ( maximum != NULL )
            newParam.addAnnotation ( 
            COLLADA::CSWC::COLLADA_FX_ANNOTATION_UI_MAX, 
            COLLADA::ValueType::FLOAT, *maximum );

        if ( attributeType == cgfxAttrDef::kAttrTypeColor3 ||
             attributeType == cgfxAttrDef::kAttrTypeColor4 )
            newParam.addAnnotation ( COLLADA::CSWC::COLLADA_FX_ANNOTATION_UI_TYPE, 
            COLLADA::ValueType::STRING, COLLADA::CSWC::COLLADA_FX_UI_TYPE_COLOR );
    }

    // --------------------------------------
    void HwShaderExporter::setNewParamTexture( 
        const cgfxAttrDef* attribute, 
        MObject textureNode, 
        COLLADA::Surface::SurfaceType surfaceType, 
        COLLADA::Sampler::SamplerType samplerType, 
        COLLADA::ValueType::ColladaType samplerValueType )
    {
        // Get a pointer to the current stream writer.
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the image id
        MFnDependencyNode pluNodeFn ( textureNode );
        String imageId = pluNodeFn.name().asChar(); // file1

        // Get the current attribute name
        String attributeName = attribute->fName.asChar();

        // Create the surface
        String surfaceSid = attributeName + COLLADA::Surface::SURFACE_SID_SUFFIX;
        COLLADA::Surface surface ( surfaceType, surfaceSid );
        surface.setFormat ( "A8R8G8B8" );

        // Create the surface init option
        COLLADA::SurfaceInitOption initOption ( COLLADA::SurfaceInitOption::INIT_FROM );
        initOption.setImageReference ( imageId );
        surface.setInitOption ( initOption );

        // Add the surface <newparam>
        COLLADA::NewParamSurface paramSurface ( streamWriter );
        paramSurface.openParam ( surfaceSid );
        prepareParam ( paramSurface, attribute );
        surface.add ( streamWriter );
        paramSurface.closeParam ();

        // Create the sampler and add the sampler <newparam>
        COLLADA::Sampler sampler ( samplerType, surfaceSid );
        String suffix = COLLADA::Sampler::SAMPLER_SID_SUFFIX;
        String samplerSid = attributeName + COLLADA::Sampler::SAMPLER_SID_SUFFIX;
        COLLADA::NewParamSampler paramSampler ( streamWriter );
        paramSampler.setParamType( samplerValueType );
        paramSampler.openParam ( samplerSid );
        prepareParam ( paramSampler, attribute );
        sampler.add ( streamWriter );
        paramSampler.closeParam ();

        // Export the image
        EffectTextureExporter* textureExporter = 
            mDocumentExporter->getEffectExporter()->getTextureExporter();
        textureExporter->exportImage ( textureNode );
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