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
#include "COLLADAMayaHwShaderExporter.h"
#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaConversion.h"
#include "COLLADAMayaExportOptions.h"

#include "COLLADASWPass.h"
#include "COLLADASWRenderState.h"
#include "COLLADASWShader.h"
#include "COLLADASWAnnotation.h"
#include "COLLADASWOpenGLConstants.h"
#include "COLLADASWConstants.h"

#include <maya/MFileIO.h>

#if defined(WIN64) && MAYA_API_VERSION >= 201600 && !defined(WIN32)
/* define WIN32 to work around CFGX WIN64 compilation */
#define WIN32
#endif

#include "cgfxShaderNode.h"

#include "cgfxFindImage.h"

#include <assert.h>


namespace COLLADAMaya
{

    // ---------------------------------
    bool HwShaderExporter::exportPluginHwShaderNode (
        const String &effectId,
        COLLADASW::EffectProfile *effectProfile,
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
        if ( fnNode.typeId () == cgfxShaderNode::sId )
        {
            // Create a cgfx shader node
            cgfxShaderNode* shaderNodeCgfx = ( cgfxShaderNode* ) fnNode.userNode();

            // Exports the effect data of a cgfxShader node.
            return exportCgfxShader( shaderNodeCgfx );
        }
        else
        {
            // Writes the current effect profile into the collada document
            mEffectProfile->openProfile ();
            mEffectProfile->addProfileElements ();
            mEffectProfile->closeProfile ();

			return true;
        }
    }

    // ---------------------------------
    bool HwShaderExporter::exportCgfxShader ( cgfxShaderNode* shaderNodeCgfx )
    {
		// Disabled for Maya2012, the raw CGeffect is no-longer directly accessible from the cgfxShaderNode class.
#if MAYA_API_VERSION < 201200
        // Set the current shader scope to CG
        setShaderScope ( COLLADASW::Shader::SCOPE_CG );

        // Writes the current effect profile into the collada document
        mEffectProfile->setProfileType ( COLLADASW::EffectProfile::CG );
        mEffectProfile->openProfile ();

        // Get a pointer to the current stream writer
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the filename of the current cgfx file
        MString shaderFxFile = cgfxFindFile(shaderNodeCgfx->shaderFxFile());
        String shaderFxFileName = shaderFxFile.asChar (); // check3d.cgfx
        COLLADASW::URI  shaderFxFileUri ( COLLADASW::URI::nativePathToUri ( shaderFxFileName ) );
        setShaderFxFileUri ( shaderFxFileUri );

        // Get the current CGeffect
        CGeffect cgEffect = shaderNodeCgfx->effect();

        // Set the current include file
        if ( ExportOptions::exportCgfxFileReferences () )
        {
            if ( shaderFxFileUri.getScheme ().empty () )
                shaderFxFileUri.setScheme ( COLLADASW::URI::SCHEME_FILE );

            if ( ExportOptions::relativePaths() )
            {
                // Get the URI of the COLLADA file.
                String targetColladaFile = mDocumentExporter->getFilename();
                COLLADASW::URI targetColladaUri ( COLLADASW::URI::nativePathToUri ( targetColladaFile ) );
                if ( targetColladaUri.getScheme ().empty () )
                    targetColladaUri.setScheme ( COLLADASW::URI::SCHEME_FILE );

                // Get the texture URI relative to the COLLADA file URI.
                bool success = false;
                COLLADASW::URI targetUri = shaderFxFileUri.getRelativeTo( targetColladaUri, success );
                if ( !success ) 
                {
                    String message = "Not able to generate a relative path from " 
                        + shaderFxFileUri.getURIString() + " to " + targetColladaUri.getURIString() 
                        + ". An absolute path will be written! ";
                    MGlobal::displayError ( message.c_str() );
                    targetUri = shaderFxFileUri;
                }

                mEffectProfile->setInclude ( targetUri, shaderFxFileUri.getPathFileBase() );
            }
            else
            {
                mEffectProfile->setInclude ( shaderFxFileUri, shaderFxFileUri.getPathFileBase() );
            }
        }
        else
        {
            // Add the source code
            CGcontext cgContext = cgGetEffectContext ( cgEffect );
            CGprogram cgProgram = cgGetFirstProgram ( cgContext );
            const char* programSourceCG = cgGetProgramString ( cgProgram, CG_PROGRAM_SOURCE );
            String sourceString = getProgramSourceString ( programSourceCG );
            // Get the code sid
            String codeSid = shaderFxFileUri.getPathFileBase ();
            // Set the code into the collada effect profile
            mEffectProfile->setCode ( sourceString, codeSid );
        }

        // Add the source code and the include file
        mEffectProfile->addProfileElements ();

        // Export the effects parameter
        MObject shaderNode = shaderNodeCgfx->thisMObject();
        exportEffectParameters ( shaderNode, cgEffect );

        // Find if effect parameter is used by any program of the selected technique
        CGtechnique cgTechnique = cgGetFirstTechnique ( cgEffect );
        while ( cgTechnique )
        {
            exportTechnique ( cgTechnique );
            cgTechnique = cgGetNextTechnique ( cgTechnique );
        }
        mEffectProfile->closeProfile ();
#else // MAYA_API_VERSION < 201200
        // Set the current shader scope to CG
        setShaderScope ( COLLADASW::Shader::SCOPE_CG );

		// Get the current CGeffect
		const cgfxRCPtr<const cgfxEffect>& cgEffect = shaderNodeCgfx->effect();
		if (cgEffect.isNull())
		{
			MGlobal::displayError("cgEffect is null.");
			return false;
		}

        // Writes the current effect profile into the collada document
        mEffectProfile->setProfileType ( COLLADASW::EffectProfile::CG );
        mEffectProfile->openProfile ();

        // Get a pointer to the current stream writer
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the filename of the current cgfx file
        MString shaderFxFile = cgfxFindFile(shaderNodeCgfx->shaderFxFile());
        String shaderFxFileName = shaderFxFile.asChar (); // check3d.cgfx
		COLLADASW::URI shaderFxFileUri(COLLADASW::URI::nativePathToUri(shaderFxFileName));
		
		if (ExportOptions::relativePaths())
		{
			MString mayaSourceFile = MFileIO::currentFile();
			COLLADASW::URI mayaSourceFileUri(COLLADASW::URI::nativePathToUri(mayaSourceFile.asChar()));
			shaderFxFileUri.makeRelativeTo(mayaSourceFileUri);
		}
        
		setShaderFxFileUri ( shaderFxFileUri );

        // Set the current include file
        if ( ExportOptions::exportCgfxFileReferences () )
            mEffectProfile->setInclude ( shaderFxFileUri, shaderFxFileUri.getPathFileBase() );
        else
        {
#if 1
            String sourceString = "dummy.";
            // Get the code sid
            String codeSid = shaderFxFileUri.getPathFileBase ();
            // Set the code into the collada effect profile
            mEffectProfile->setCode ( sourceString, codeSid );
#else //1
            // Add the source code
            CGcontext cgContext = cgGetEffectContext ( cgEffect );
            CGprogram cgProgram = cgGetFirstProgram ( cgContext );
            const char* programSourceCG = cgGetProgramString ( cgProgram, CG_PROGRAM_SOURCE );
            String sourceString = getProgramSourceString ( programSourceCG );
            // Get the code sid
            String codeSid = shaderFxFileUri.getPathFileBase ();
            // Set the code into the collada effect profile
            mEffectProfile->setCode ( sourceString, codeSid );
#endif //1
        }

        // Add the source code and the include file
        mEffectProfile->addProfileElements ();

        // Export the effects parameter
        MObject shaderNode = shaderNodeCgfx->thisMObject();

		MaterialExporter::mSurfaceSidList.clear();
		exportEffectParameters ( shaderNode, cgEffect );

        // Find if effect parameter is used by any program of the selected technique
        const cgfxTechnique* technique = cgEffect->getFirstTechnique();
        while( technique )
        {
            exportTechnique ( technique );
            technique = technique->getNext();
        }
#endif // MAYA_API_VERSION < 201200

		return true;
    }

#if MAYA_API_VERSION >= 201200
    void HwShaderExporter::exportTechnique (
        const cgfxTechnique* technique
        )
    {
        mEffectProfile->setTechniqueSid ( technique->getName().asChar() );
        String techniqueName = technique->getName().asChar();
        // Open the current technique element
        mEffectProfile->openTechnique ( techniqueName );

        // Go through the passes and write it into the collada file.
        const cgfxPass* pass = technique->getFirstPass();
        while ( pass )
        {
            CGpass cgPass = pass->getCgPass();
            exportPass ( cgPass );
            pass = pass->getNext();
        }

        // Close the current technique element
        mEffectProfile->closeTechnique ();
    }
#endif//MAYA_API_VERSION >= 201200

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
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Write the render states.
        CGstate cgState = cgGetStateAssignmentState ( cgStateAssignment );
        const char* cgStateNameC = cgGetStateName ( cgState );
        String cgStateName ( cgStateNameC );
        CGtype cgStateType = cgGetStateType ( cgState );
        if ( cgStateType != CG_PROGRAM_TYPE ) return;

        // The state name depend on the current shader scope
        COLLADASW::Shader::Stage shaderStage = COLLADASW::Shader::getStageTypeByName ( cgStateName );

        // Create a shader and export it
        COLLADASW::Shader shader ( streamWriter, mShaderScope, shaderStage );
        shader.openShader();

        // Get the program
        CGprogram cgProgram	= cgGetProgramStateAssignmentValue ( cgStateAssignment );

//        const char* programCompiledString = cgGetProgramString ( cgProgram, CG_COMPILED_PROGRAM );
//        const char* programProfileString = cgGetProgramString ( cgProgram, CG_PROGRAM_PROFILE ); // arbvp1

        // Set the current programs profile
        CGprofile cgProgramProfile = cgGetProgramProfile( cgProgram );
        const char* profileString = cgGetProfileString ( cgProgramProfile ); // arbvp1
        if ( profileString != NULL )
            shader.addCompilerTarget ( profileString );

        // Set a reference to the sources.
        const char* programEntryString = cgGetProgramString ( cgProgram, CG_PROGRAM_ENTRY ); // VShader || goochVS
        if ( programEntryString != NULL )
        {
            // Get the code sid
            COLLADASW::URI fileURI = getShaderFxFileUri ();
            String codeSid = fileURI.getPathFileBase ();
            shader.addName ( programEntryString, codeSid );
        }
        
        if ( !ExportOptions::exportCgfxFileReferences () )
        {
            // Add the global bind parameters
            CGparameter progParam = cgGetFirstParameter ( cgProgram, CG_GLOBAL ); // CG_PROGRAM=IN || CG_GLOBAL
            while ( progParam )
            {
                const char* paramName = cgGetParameterName ( progParam ); // VShader
                CGtype paramType = cgGetParameterBaseType ( progParam );

                CGbool isUsed = cgIsParameterUsed ( progParam, cgProgram );
                CGbool isReferenced = cgIsParameterReferenced ( progParam );
                if ( isUsed && !COLLADASW::Utils::equals( paramName, programEntryString ) )
                {
                    // Get the connected parameter
                    CGparameter connectedParam = cgGetConnectedParameter ( progParam );
                    if ( connectedParam ) 
                    {
                        COLLADASW::ParamBase bindParam ( streamWriter, &COLLADASW::CSWC::CSW_ELEMENT_BIND );
                        bindParam.openParam ();
                        bindParam.appendAttribute( COLLADASW::CSWC::CSW_ATTRIBUTE_SYMBOL, paramName );

                        const char* connectedParamName = cgGetParameterName ( connectedParam ); 

                        COLLADASW::ParamBase param ( streamWriter );
                        param.openParam ( connectedParamName );
                        param.closeParam ();
                        bindParam.closeParam ();
                    }
                }

                progParam = cgGetNextParameter ( progParam );
            }

            // Add the program specific bind parameters
            progParam = cgGetFirstParameter ( cgProgram, CG_PROGRAM );
            while ( progParam )
            {
                const char* paramName = cgGetParameterName ( progParam ); // VShader
                CGtype paramType = cgGetParameterBaseType ( progParam );

                CGbool isUsed = cgIsParameterUsed ( progParam, cgProgram );
                CGbool isReferenced = cgIsParameterReferenced ( progParam );
                if ( isUsed && !COLLADASW::Utils::equals( paramName, "IN" ) )
                {
                    // Get the connected parameter
                    CGparameter connectedParam = cgGetConnectedParameter ( progParam );
                    if ( connectedParam ) 
                    {
                        COLLADASW::ParamBase bindParam ( streamWriter, &COLLADASW::CSWC::CSW_ELEMENT_BIND );
                        bindParam.openParam ();
                        bindParam.appendAttribute( COLLADASW::CSWC::CSW_ATTRIBUTE_SYMBOL, paramName );

                        const char* connectedParamName = cgGetParameterName ( connectedParam ); 

                        COLLADASW::ParamBase param ( streamWriter );
                        param.openParam ( connectedParamName );
                        param.closeParam ();
                        bindParam.closeParam ();
                    }
                }

                progParam = cgGetNextParameter ( progParam );
            }
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
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        COLLADASW::ParamBase param ( streamWriter, &renderStateName );
        param.openParam();
        for ( int j=0; j<valueCount; ++j )
            param.appendAttribute( COLLADASW::CSWC::CSW_ATTRIBUTE_VALUE,
                                    COLLADASW::Utils::toString ( values[j] ) );
        param.closeParam();
    }

    // --------------------------------------
    void HwShaderExporter::exportRenderStateParam (
        const String& renderStateName,
        const CGbool* values,
        const int valueCount )
    {
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        COLLADASW::ParamBase param ( streamWriter, &renderStateName );
        param.openParam();
        for ( int j=0; j<valueCount; ++j )
        {
            if ( values[j] > 0 )
                param.appendAttribute( COLLADASW::CSWC::CSW_ATTRIBUTE_VALUE, "true" );
            else
                param.appendAttribute( COLLADASW::CSWC::CSW_ATTRIBUTE_VALUE, "false" );
        }
        param.closeParam();
    }

    // --------------------------------------
    void HwShaderExporter::exportPass ( const CGpass& cgPass )
    {
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Write the pass into the collada file
        COLLADASW::Pass colladaPass ( streamWriter );
        const char* cgPassName = cgGetPassName ( cgPass );
        if ( cgPassName == NULL ) cgPassName = EMPTY_CSTRING;
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
            COLLADASW::CSWC::CSW_FX_SHADER_STAGE_VERTEXPROGRAM.c_str() );
        if ( cgStateAssignment )
            exportShaderProgramData ( cgStateAssignment );

        // Export the fragment stage assignment
        cgStateAssignment = cgGetNamedStateAssignment ( cgPass,
            COLLADASW::CSWC::CSW_FX_SHADER_STAGE_FRAGMENTPROGRAM.c_str() );
        if ( cgStateAssignment )
            exportShaderProgramData ( cgStateAssignment );
    }

    // --------------------------------------
    void HwShaderExporter::exportPassRenderState ( const CGstateassignment& cgStateAssignment )
    {
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Write the render states.
        CGstate cgState = cgGetStateAssignmentState ( cgStateAssignment );
        const char* cgStateNameC = cgGetStateName ( cgState );
        String cgStateName ( cgStateNameC );
        CGtype cgStateType = cgGetStateType ( cgState );

        COLLADASW::RenderState::PassState passState =
            COLLADASW::RenderState::getRenderStateFromCgName( cgStateNameC );
        const String& renderStateName = COLLADASW::RenderState::getColladaRenderStateName ( passState );

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

                COLLADASW::ParamBase param ( streamWriter, &renderStateName );
                param.openParam ();
                for ( int j=0; j<valueCount; ++j )
                {
                    const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[j] );
                    COLLADASW::RenderState::PassStateFunction passStateFunction =
                        COLLADASW::RenderState::getPassStateFunction ( cgStateEnum );
                    const String renderStateFunctionName =
                        COLLADASW::RenderState::getColladaPassStateString ( passStateFunction );
                    param.appendAttribute ( COLLADASW::CSWC::CSW_ATTRIBUTE_VALUE, renderStateFunctionName );
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
                COLLADASW::ParamBase param ( streamWriter, &renderStateName );
                param.openParam();
                param.appendAttribute( COLLADASW::CSWC::CSW_ATTRIBUTE_VALUE, val );
                param.closeParam();
                break;
            }
        case CG_TEXTURE:
            {
                CGparameter textureParam = cgGetTextureStateAssignmentValue ( cgStateAssignment );
                const char* textureName = cgGetParameterName( textureParam );
                COLLADASW::ParamBase param ( streamWriter, &renderStateName );
                param.openParam();
                param.appendAttribute( COLLADASW::CSWC::CSW_ATTRIBUTE_VALUE, textureName );
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
                COLLADASW::ParamBase param ( streamWriter, &renderStateName );
                param.openParam();
                param.appendAttribute( COLLADASW::CSWC::CSW_ATTRIBUTE_VALUE, samplerName );
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
//            assert ( "Parameter type not supported! " + cgStateType );
//            printf("UNEXPECTED CASE: 0x%x (%d)\n", cgStateType, cgStateType);
            break;

        }
    }

    // --------------------------------------
    void HwShaderExporter::exportEffectParameters ( 
        MObject shaderNode,
#if MAYA_API_VERSION < 201200
        const CGeffect& cgEffect
#else // MAYA_API_VERSION < 201200
        const cgfxRCPtr<const cgfxEffect>& cgEffect
#endif // MAYA_API_VERSION < 201200
        )
    {
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Write the parameters
#if MAYA_API_VERSION < 201200
        CGparameter cgParameter = cgGetFirstEffectParameter ( cgEffect );
        while (cgParameter)
        {
#else // MAYA_API_VERSION < 201200	
        cgfxRCPtr<cgfxAttrDefList> effectAttributes = cgEffect->attrsFromEffect();
        cgfxAttrDefList::iterator effectIt;
        for ( effectIt=effectAttributes->begin(); effectIt; ++effectIt )
        {
            cgfxAttrDef* effectAttribute = *effectIt;
            CGparameter cgParameter = effectAttribute->fParameterHandle;
#endif // MAYA_API_VERSION < 201200
            const char* paramName = cgGetParameterName ( cgParameter );
            CGresource resource = cgGetParameterBaseResource ( cgParameter );
            CGtype paramBaseType = cgGetParameterBaseType ( cgParameter );
            CGtype paramType = cgGetParameterType ( cgParameter );

            /* TYPE is int, float, or double or a sampler. */
            switch ( paramBaseType )
            {
            case CG_BOOL:
            {
                // Create the parameter
                COLLADASW::NewParam<> newParam ( streamWriter );

                // Set the collada value type
                switch ( paramType )
                {
                case CG_BOOL: // The bool type represents Boolean values. Objects of bool type are either true or false.
                case CG_BOOL1: // Single-element, packed, bool array (vector type).
                    newParam.setParamType ( COLLADASW::ValueType::BOOL ); break;
                case CG_BOOL2: // Two-element, packed, bool array (vector type).
                    newParam.setParamType ( COLLADASW::ValueType::BOOL2 ); break;
                case CG_BOOL3: // Three-element, packed, bool array (vector type).
                    newParam.setParamType ( COLLADASW::ValueType::BOOL3 ); break;
                case CG_BOOL4: // Four-element, packed, bool array (vector type).
                    newParam.setParamType ( COLLADASW::ValueType::BOOL4 ); break;
                default:
                    {
                        MGlobal::displayWarning ( "Parameter type not supported! " + paramType );
                        newParam.setParamType ( COLLADASW::ValueType::VALUE_TYPE_UNSPECIFIED ); break;
                    }
                }

                // Get the values
                int numOfValues = 0;
                CGenum valueType = CG_DEFAULT; // CG_CONSTANT
                const double* paramValues = cgGetParameterValues ( cgParameter, valueType, &numOfValues );

                // Export the parameter data.
                exportParam ( cgParameter, &newParam, paramValues, numOfValues );

                break;
            }
            case CG_INT:
            {
                // Create the parameter
                COLLADASW::NewParam<> newParam ( streamWriter );

                // Set the collada value type
                switch ( paramType )
                {
                case CG_INT:
                case CG_INT1:
                    newParam.setParamType ( COLLADASW::ValueType::INT ); break;
                case CG_INT2:
                    newParam.setParamType ( COLLADASW::ValueType::INT2 ); break;
                case CG_INT3:
                    newParam.setParamType ( COLLADASW::ValueType::INT3 ); break;
                case CG_INT4:
                    newParam.setParamType ( COLLADASW::ValueType::INT4 ); break;
                default:
                    {
                        MGlobal::displayWarning ( "Parameter type not supported! " + paramType );
                        newParam.setParamType ( COLLADASW::ValueType::VALUE_TYPE_UNSPECIFIED ); break;
                    }
                }

//                 // Determine the number of values.
//                 int nrows = cgGetParameterRows ( cgParameter );
//                 int ncols = cgGetParameterColumns ( cgParameter );
//                 int asize = cgGetArrayTotalSize ( cgParameter );
//                 int numOfValues = nrows*ncols;
//
//                 if (asize > 0) numOfValues *= asize;
// 
//                 // Get the values
//                 int* paramValues = 0;
//                 cgGetParameterValueir ( cgParameter, numOfValues, paramValues );

                // Get the values
                int numOfValues = 0;
                CGenum valueType = CG_DEFAULT; // CG_CONSTANT
                const double* paramValues = cgGetParameterValues ( cgParameter, valueType, &numOfValues );

                // Export the parameter data.
                exportParam ( cgParameter, &newParam, paramValues, numOfValues );

                break;
            }
            case CG_FLOAT:
            {
                // Create the parameter
                COLLADASW::NewParam<> newParam ( streamWriter );

                // Set the collada value type
                switch ( paramType )
                {
                case CG_FLOAT:
                case CG_HALF:
                    newParam.setParamType ( COLLADASW::ValueType::FLOAT ); break;
                case CG_FLOAT2:
                case CG_HALF2:
                    newParam.setParamType ( COLLADASW::ValueType::FLOAT2 ); break;
                case CG_FLOAT3:
                case CG_HALF3:
                    newParam.setParamType ( COLLADASW::ValueType::FLOAT3 ); break;
                case CG_FLOAT4:
                case CG_HALF4:
                    newParam.setParamType ( COLLADASW::ValueType::FLOAT4 ); break;
                case CG_FLOAT3x3:
                case CG_HALF3x3:
                    newParam.setParamType ( COLLADASW::ValueType::FLOAT3x3 ); break;
                case CG_FLOAT4x4:
                case CG_HALF4x4:
                    newParam.setParamType ( COLLADASW::ValueType::FLOAT4x4 ); break;
                case CG_ARRAY:
                case CG_STRUCT:
                default:
                    {
                        MGlobal::displayWarning ( "Parameter type not supported! " + paramType );
                        newParam.setParamType ( COLLADASW::ValueType::VALUE_TYPE_UNSPECIFIED ); break;
                    }
                }

                // Get the values
                int numOfValues = 0;
                CGenum valueType = CG_DEFAULT; // CG_CONSTANT
                const double* paramValues = cgGetParameterValues( cgParameter, valueType, &numOfValues );

                // Export the parameter data.
                exportParam ( cgParameter, &newParam, paramValues, numOfValues );

                break;
            }
            case CG_STRING:
                {

					
                    // Create the parameter
                    COLLADASW::NewParam<> newParam ( streamWriter );

                    // Get the value
                    const char* paramValue = cgGetStringParameterValue ( cgParameter ); 
                    String paramString = (String) paramValue;
					MGlobal::displayWarning(("CG String Parameter type: ") + MString(paramString.c_str()) + MString(" not supported!"));

                    // Export the parameter data.
                   // exportParam ( cgParameter, &newParam, paramString );

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
                    exportSampler ( shaderNode, cgParameter, true );
                    break;
                }
            default:
                MGlobal::displayWarning ( "Parameter type not supported! " + paramType );
                break;
           }

            cgParameter = cgGetNextParameter(cgParameter);
        }
    }

    // --------------------------------------
    template <class Type>
    void HwShaderExporter::exportParam (
        const CGparameter& cgParameter,
        COLLADASW::ParamBase* param,
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
    void HwShaderExporter::exportParam (
        const CGparameter& cgParameter,
        COLLADASW::ParamBase* param,
        const String& paramValue )
    {
        const char* paramName = cgGetParameterName ( cgParameter );
        param->openParam ( paramName );

        exportAnnotations ( cgParameter, param );
        exportSemantic ( cgParameter, param );

        param->appendValues ( paramValue );

        param->closeParam();
    }

    // --------------------------------------
    void HwShaderExporter::exportAnnotations (
        const CGparameter& cgParameter, 
        COLLADASW::ParamBase* param )
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
                    param->addAnnotation ( annotationName, COLLADASW::ValueType::BOOL, values, nvalues );
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
                    param->addAnnotation ( annotationName, COLLADASW::ValueType::BOOL, values, nvalues );
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
                    param->addAnnotation ( annotationName, COLLADASW::ValueType::FLOAT, values, nvalues );
                    break;
                }
            case CG_HALF4x4:
            case CG_FLOAT4x4:
                {
                    // TODO
//                    assert ( "Annotation type not supported! " + cgAnnoType );
                    break;
                }
            case CG_STRING:
                {
                    const char* val = cgGetStringAnnotationValue ( cgAnno );
                    param->addAnnotation ( annotationName, COLLADASW::ValueType::STRING, String ( val ) );
                    break;
                }
            default:
 //               assert ( "Annotation type not supported! " + cgAnnoType );
                break;
            }

            cgAnno = cgGetNextAnnotation ( cgAnno );
        }
    }

    // --------------------------------------
    void HwShaderExporter::exportSemantic ( const CGparameter& cgParameter, COLLADASW::ParamBase* param )
    {
        const char *semantic = cgGetParameterSemantic( cgParameter );

        if ( semantic && strlen(semantic) )
            param->addSemantic ( semantic );
    }

    // --------------------------------------
    void HwShaderExporter::exportSampler ( 
        MObject shaderNode, 
        const CGparameter& cgParameter, 
        const bool writeNewParam )
    {
        if ( cgGetParameterClass ( cgParameter ) != CG_PARAMETERCLASS_SAMPLER ) return;

        // Get a pointer to the current stream writer.
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // The texture parameter (a sampler must have a texture)
        CGparameter cgTextureParam = NULL;
        CGstateassignment cgStateAssignment;
        int valueCount = 0;

        // Look for the "source" state assignment
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADASW::CSWC::CSW_ELEMENT_TEXTURE.c_str() );
        if ( cgStateAssignment )
        {
            cgTextureParam = cgGetTextureStateAssignmentValue ( cgStateAssignment );
            // We directly set the surface sid and the referenced texture resource.
            //const char* textureName = cgGetParameterName ( cgTextureParam );
            //sampler.setSource ( textureName );
        }
        if ( cgTextureParam == 0 )
        {
            MGlobal::displayError ( "No surface for the current sampler! Data not valid!" );
            return;
        }

        // Get the name of the current parameter
        const char* samplerSid = cgGetParameterName ( cgParameter );
		
        // Name of the current texture
        const char* surfaceSid = cgGetParameterName( cgTextureParam );
		
        // Create the collada sampler object
        COLLADASW::Sampler sampler ( COLLADASW::Sampler::SAMPLER_TYPE_UNSPECIFIED, samplerSid, surfaceSid );

        // Look for the wraps
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADASW::CSWC::CSW_ELEMENT_WRAP_S.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );
            const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[0] );
            sampler.setWrapS ( COLLADASW::OPEN_GL::getWrapModeFromOpenGL ( cgStateEnum ) );
        }
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADASW::CSWC::CSW_ELEMENT_WRAP_T.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );
            const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[0] );
            sampler.setWrapT ( COLLADASW::OPEN_GL::getWrapModeFromOpenGL ( cgStateEnum ) );
        }
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADASW::CSWC::CSW_ELEMENT_WRAP_P.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );
            const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[0] );
            sampler.setWrapP ( COLLADASW::OPEN_GL::getWrapModeFromOpenGL ( cgStateEnum ) );
        }

        // Look for the filters
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADASW::CSWC::CSW_ELEMENT_MAGFILTER.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );
            const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[0] );
            sampler.setMagFilter( COLLADASW::OPEN_GL::getSamplerFilterFromOpenGL ( cgStateEnum ) );
        }
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADASW::CSWC::CSW_ELEMENT_MINFILTER.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );
            const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[0] );
            sampler.setMinFilter( COLLADASW::OPEN_GL::getSamplerFilterFromOpenGL ( cgStateEnum ) );
        }
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADASW::CSWC::CSW_ELEMENT_MIPFILTER.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );
            const char* cgStateEnum = cgGetStateEnumerantName ( cgState, values[0] );
            sampler.setMipFilter( COLLADASW::OPEN_GL::getSamplerFilterFromOpenGL ( cgStateEnum ) );
        }

        // Look for the border color
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADASW::CSWC::CSW_ELEMENT_BORDER_COLOR.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const float* values = cgGetFloatStateAssignmentValues ( cgStateAssignment, &valueCount );
            if ( valueCount == 3 )
                sampler.setBorderColor ( COLLADASW::Color ( values[0], values[1], values[2] ) );
            else if ( valueCount == 4 )
                sampler.setBorderColor ( COLLADASW::Color ( values[0], values[1], values[2], values[3] ) );
        }

        // Look for the mipmaps
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADASW::CSWC::CSW_ELEMENT_MIPMAP_MAXLEVEL.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const int* values = cgGetIntStateAssignmentValues ( cgStateAssignment, &valueCount );
            sampler.setMipmapMaxlevel ( ( unsigned char ) ( values[0] ) );
        }
        cgStateAssignment = cgGetNamedSamplerStateAssignment ( cgParameter, COLLADASW::CSWC::CSW_ELEMENT_MIPMAP_BIAS.c_str() );
        if ( cgStateAssignment )
        {
            CGstate cgState = cgGetSamplerStateAssignmentState ( cgStateAssignment );
            const float* values = cgGetFloatStateAssignmentValues ( cgStateAssignment, &valueCount );
            sampler.setMipmapBias ( values[0] );
        }

        // TODO Look for extra tags
//        exportSamplerStateAssignments (cgParameter, cgTextureParam, surfaceType, samplerType, samplerValueType);

        // Get the type of the resource ( 1D, 2D, 3D, CUBE )
        //COLLADASW::Surface::SurfaceType surfaceType = COLLADASW::Surface::SURFACE_TYPE_UNSPECIFIED;
        COLLADASW::Sampler::SamplerType samplerType = COLLADASW::Sampler::SAMPLER_TYPE_UNSPECIFIED;
        COLLADASW::ValueType::ColladaType samplerValueType = COLLADASW::ValueType::VALUE_TYPE_UNSPECIFIED;

        // Get the type of the resource, if is set.
        getResourceType ( cgTextureParam, samplerType, samplerValueType );

        // Set the sampler type
        sampler.setSamplerType ( samplerType );

        // Add the texture, if exist
        setTexture ( shaderNode, sampler, cgTextureParam );

        if ( writeNewParam )
        {
            // Get the surface annotations.
            std::vector<COLLADASW::Annotation> surfaceAnnotations;
            getAnnotations( surfaceAnnotations, cgTextureParam );

            // Get the sampler annotations.
            std::vector<COLLADASW::Annotation> samplerAnnotations;
            getAnnotations( samplerAnnotations, cgParameter );

            // Add the parameter.
			sampler.addInNewParam(streamWriter, &surfaceAnnotations, &samplerAnnotations, (MaterialExporter::mSurfaceSidList.find(surfaceSid) == MaterialExporter::mSurfaceSidList.end()));
        }
        else
        {
            // Add the parameter.
			sampler.addInSetParam(streamWriter, 0, 0, (MaterialExporter::mSurfaceSidList.find(surfaceSid) == MaterialExporter::mSurfaceSidList.end()));
        }

		MaterialExporter::SidSet::iterator it = MaterialExporter::mSurfaceSidList.find(surfaceSid);
		if (it == MaterialExporter::mSurfaceSidList.end())
		{
			MaterialExporter::mSurfaceSidList.insert(surfaceSid);
		}

    }

    // --------------------------------------
    void HwShaderExporter::getAnnotations (
        std::vector<COLLADASW::Annotation>& annotations, 
        const CGparameter& cgParameter )
    {
        // Get a pointer to the current stream writer.
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        CGannotation cgAnno = cgGetFirstParameterAnnotation ( cgParameter );
        while ( cgAnno )
        {
            COLLADASW::ValueType::ColladaType valueType = COLLADASW::ValueType::VALUE_TYPE_UNSPECIFIED;
            int nvalues = -1;

            CGtype cgAnnoType = cgGetAnnotationType( cgAnno );
            const char* cgAnnoName = cgGetAnnotationName( cgAnno );
            String annotationName ( cgAnnoName );
            switch ( cgAnnoType )
            {
            case CG_BOOL:
            case CG_BOOL1:
                {
                    valueType = COLLADASW::ValueType::BOOL;
                    const CGbool* values = cgGetBoolAnnotationValues( cgAnno, &nvalues );
                    COLLADASW::Annotation annotation ( streamWriter, annotationName, valueType, values, nvalues );
                    annotations.push_back ( annotation );
                    break;
                }
            case CG_BOOL2:
                {
                    valueType = COLLADASW::ValueType::BOOL2;
                    const CGbool* values = cgGetBoolAnnotationValues( cgAnno, &nvalues );
                    COLLADASW::Annotation annotation ( streamWriter, annotationName, valueType, values, nvalues );
                    annotations.push_back ( annotation );
                    break;
                }
            case CG_BOOL3:
                {
                    valueType = COLLADASW::ValueType::BOOL3;
                    const CGbool* values = cgGetBoolAnnotationValues( cgAnno, &nvalues );
                    COLLADASW::Annotation annotation ( streamWriter, annotationName, valueType, values, nvalues );
                    annotations.push_back ( annotation );
                    break;
                }
            case CG_BOOL4:
                {
                    valueType = COLLADASW::ValueType::BOOL4;
                    const CGbool* values = cgGetBoolAnnotationValues( cgAnno, &nvalues );
                    COLLADASW::Annotation annotation ( streamWriter, annotationName, valueType, values, nvalues );
                    annotations.push_back ( annotation );
                    break;
                }
            case CG_INT:
            case CG_INT1:
                {
                    valueType = COLLADASW::ValueType::INT;
                    const int* values = cgGetIntAnnotationValues( cgAnno, &nvalues );
                    COLLADASW::Annotation annotation ( streamWriter, annotationName, valueType, values, nvalues );
                    annotations.push_back ( annotation );
                    break;
                }
            case CG_INT2:
                {
                    valueType = COLLADASW::ValueType::INT2;
                    const int* values = cgGetIntAnnotationValues( cgAnno, &nvalues );
                    COLLADASW::Annotation annotation ( streamWriter, annotationName, valueType, values, nvalues );
                    annotations.push_back ( annotation );
                    break;
                }
            case CG_INT3:
                {
                    valueType = COLLADASW::ValueType::INT3;
                    const int* values = cgGetIntAnnotationValues( cgAnno, &nvalues );
                    COLLADASW::Annotation annotation ( streamWriter, annotationName, valueType, values, nvalues );
                    annotations.push_back ( annotation );
                    break;
                }
            case CG_INT4:
                {
                    valueType = COLLADASW::ValueType::INT4;
                    const int* values = cgGetIntAnnotationValues( cgAnno, &nvalues );
                    COLLADASW::Annotation annotation ( streamWriter, annotationName, valueType, values, nvalues );
                    annotations.push_back ( annotation );
                    break;
                }
            case CG_FLOAT:
            case CG_FLOAT1:
                {
                    valueType = COLLADASW::ValueType::FLOAT;
                    const float* values = cgGetFloatAnnotationValues ( cgAnno, &nvalues );
                    COLLADASW::Annotation annotation ( streamWriter, annotationName, valueType, values, nvalues );
                    annotations.push_back ( annotation );
                    break;
                }
            case CG_FLOAT2:
                {
                    valueType = COLLADASW::ValueType::FLOAT2;
                    const float* values = cgGetFloatAnnotationValues ( cgAnno, &nvalues );
                    COLLADASW::Annotation annotation ( streamWriter, annotationName, valueType, values, nvalues );
                    annotations.push_back ( annotation );
                    break;
                }
            case CG_FLOAT3:
                {
                    valueType = COLLADASW::ValueType::FLOAT3;
                    const float* values = cgGetFloatAnnotationValues ( cgAnno, &nvalues );
                    COLLADASW::Annotation annotation ( streamWriter, annotationName, valueType, values, nvalues );
                    annotations.push_back ( annotation );
                    break;
                }
            case CG_FLOAT4:
                {
                    valueType = COLLADASW::ValueType::FLOAT4;
                    const float* values = cgGetFloatAnnotationValues ( cgAnno, &nvalues );
                    COLLADASW::Annotation annotation ( streamWriter, annotationName, valueType, values, nvalues );
                    annotations.push_back ( annotation );
                    break;
                }
            case CG_FLOAT4x4:
                {
                    valueType = COLLADASW::ValueType::FLOAT4x4;
                    const float* values = cgGetFloatAnnotationValues ( cgAnno, &nvalues );
                    COLLADASW::Annotation annotation ( streamWriter, annotationName, valueType, values, nvalues );
                    annotations.push_back ( annotation );
                    break;
                }
            case CG_HALF:
            case CG_HALF2:
            case CG_HALF3:
            case CG_HALF4:
            case CG_HALF4x4:
                {
//                    assert ( "Annotation type not supported! " + cgAnnoType );
                    break;
                }
            case CG_STRING:
                {
                    valueType = COLLADASW::ValueType::STRING;
                    const char* values = cgGetStringAnnotationValue ( cgAnno );
                    COLLADASW::Annotation annotation ( streamWriter, annotationName, valueType, values );
                    annotations.push_back ( annotation );
                    break;
                }
            default:
//                assert ( "Annotation type not supported! " + cgAnnoType );
                break;
            }

            cgAnno = cgGetNextAnnotation ( cgAnno );
        }
    }

    // --------------------------------------
    void HwShaderExporter::setTexture (
        MObject shaderNode, 
        COLLADASW::Sampler& sampler,
        const CGparameter& cgTextureParam )
    {
        CGtype paramType = cgGetParameterBaseType( cgTextureParam );
        if ( paramType != CG_TEXTURE ) return;

        // Set the texture format.
        sampler.setFormat ( EffectTextureExporter::FORMAT );

        // Get the necessary exporters.
        EffectExporter* effectExporter = mDocumentExporter->getEffectExporter ();
        EffectTextureExporter* textureExporter = effectExporter->getTextureExporter();

        // The file name to connect to.
        String fileName = EMPTY_STRING;

        // Check if there is a resource from the user interface input.
        const char* attributeName = sampler.getSamplerSid ().c_str ();
        MPlug plug;
        if ( DagHelper::getPlugConnectedTo( shaderNode, attributeName, plug ) )
        {
            String plugName = plug.name().asChar(); // file1.outColor
            MObject textureNode = plug.node();

            // Get the image id
            MFnDependencyNode fnTextureNode ( textureNode );
            String fnPlugName = fnTextureNode.name().asChar(); // file1

            // Get the file texture name
            MPlug filenamePlug = fnTextureNode.findPlug ( ATTR_FILE_TEXTURE_NAME );
            MString mayaFileName;
            filenamePlug.getValue ( mayaFileName );
            if ( mayaFileName.length() == 0 ) return;
            fileName = mayaFileName.asChar ();
        }
        else
        {
            // Get the name of the resource for default value
            CGannotation resourceNameAnnotation = cgGetNamedParameterAnnotation( cgTextureParam, COLLADASW::CSWC::CSW_FX_ANNOTATION_RESOURCE_NAME.c_str() );
            if ( resourceNameAnnotation )
            {
                // Get the name of the annotation
                const char* annotationValue = cgGetStringAnnotationValue ( resourceNameAnnotation );
                String annotationString = String ( annotationValue );

                // Get the filename, if not already done.
                fileName = annotationString;
            }
        }

        // Export, if we have a file name.
        if ( !fileName.empty () )
        {
            // Get the image path
            // Take the filename for the unique image name
            COLLADASW::URI sourceFileUri(COLLADASW::URI::nativePathToUri(fileName));
            if ( sourceFileUri.getScheme ().empty () )
                sourceFileUri.setScheme ( COLLADASW::URI::SCHEME_FILE );
            String mayaImageId = DocumentExporter::mayaNameToColladaName ( sourceFileUri.getPathFileBase().c_str () );

            // Get the image id of the maya image 
            String colladaImageId = effectExporter->findColladaImageId ( mayaImageId );
            if ( colladaImageId.empty () )
            {
                // Generate a COLLADA id for the new light object
                colladaImageId = DocumentExporter::mayaNameToColladaName ( sourceFileUri.getPathFileBase().c_str () );

                // Make the id unique and store it in a map for refernences.
                EffectTextureExporter* textureExporter = effectExporter->getTextureExporter ();
                colladaImageId = textureExporter->getImageIdList ().addId ( colladaImageId );
                textureExporter->getMayaIdColladaImageId () [mayaImageId] = colladaImageId;
            }

            // Export the image
            COLLADASW::Image* colladaImage = textureExporter->exportImage ( mayaImageId, colladaImageId, sourceFileUri );

            // Get the image id of the exported collada image
            colladaImageId = colladaImage->getImageId();

            // Set the image reference
            sampler.setImageId ( colladaImageId );
        }
    }

    // --------------------------------------
    void HwShaderExporter::setShaderFxFileUri( const COLLADASW::URI& shaderFxFileName )
    {
        mShaderFxFileUri = shaderFxFileName;
    }

    // --------------------------------------
    const COLLADASW::URI& HwShaderExporter::getShaderFxFileUri() const
    {
        return mShaderFxFileUri;
    }

    // --------------------------------------
    void HwShaderExporter::getResourceType(
        const CGparameter& cgTextureParam,
        COLLADASW::Sampler::SamplerType &samplerType,
        COLLADASW::ValueType::ColladaType &samplerValueType )
    {
        // Get the type of the resource for default value
        CGannotation resourceTypeAnnotation =
            cgGetNamedParameterAnnotation( cgTextureParam,
            COLLADASW::CSWC::CSW_FX_ANNOTATION_RESOURCE_TYPE.c_str() );
        if ( resourceTypeAnnotation )
        {
            // Get the name of the annotation
            const char* annotationValue = cgGetStringAnnotationValue ( resourceTypeAnnotation );
            String resourceTypeString ( annotationValue );

            if ( COLLADASW::Utils::equalsIgnoreCase ( resourceTypeString, COLLADASW::CSWC::CSW_SURFACE_TYPE_1D ) )
            {
                //surfaceType = COLLADASW::Surface::SURFACE_TYPE_1D;
                samplerType = COLLADASW::Sampler::SAMPLER_TYPE_1D;
                samplerValueType = COLLADASW::ValueType::SAMPLER_1D;
            }
            else if ( COLLADASW::Utils::equalsIgnoreCase ( resourceTypeString, COLLADASW::CSWC::CSW_SURFACE_TYPE_2D ) )
            {
                //surfaceType = COLLADASW::Surface::SURFACE_TYPE_2D;
                samplerType = COLLADASW::Sampler::SAMPLER_TYPE_2D;
                samplerValueType = COLLADASW::ValueType::SAMPLER_2D;
            }
            else if ( COLLADASW::Utils::equalsIgnoreCase ( resourceTypeString, COLLADASW::CSWC::CSW_SURFACE_TYPE_3D ) )
            {
                //surfaceType = COLLADASW::Surface::SURFACE_TYPE_3D;
                samplerType = COLLADASW::Sampler::SAMPLER_TYPE_3D;
                samplerValueType = COLLADASW::ValueType::SAMPLER_3D;
            }
            else if ( COLLADASW::Utils::equalsIgnoreCase ( resourceTypeString, COLLADASW::CSWC::CSW_SURFACE_TYPE_CUBE ) )
            {
                //surfaceType = COLLADASW::Surface::SURFACE_TYPE_CUBE;
                samplerType = COLLADASW::Sampler::SAMPLER_TYPE_CUBE;
                samplerValueType = COLLADASW::ValueType::SAMPLER_CUBE;
            }
            else if ( COLLADASW::Utils::equalsIgnoreCase ( resourceTypeString, COLLADASW::CSWC::CSW_SURFACE_TYPE_RECT ) )
            {
                //surfaceType = COLLADASW::Surface::SURFACE_TYPE_RECT;
                samplerType = COLLADASW::Sampler::SAMPLER_TYPE_RECT;
                samplerValueType = COLLADASW::ValueType::SAMPLER_RECT;
            }
        }
    }

    // --------------------------------------
    String HwShaderExporter::getProgramSourceString ( const char* programSourceCG )
    {
        // Generate the source string
        String sourceString ( programSourceCG );

        COLLADASW::Utils::translateToXML ( sourceString );

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
        size_t techniqueStart = sourceString.find ( COLLADASW::CSWC::CSW_ELEMENT_TECHNIQUE );

        // Get the substring from the beginning to the first "technique" element
        String withoutTechniqueString = sourceString.substr ( 0, techniqueStart );

        // TODO Don't believe, that the "technique" element is always the last...
//         String withTechniqueString = sourceString.substr ( techniqueStart+COLLADASW::CSWC::CSW_ELEMENT_TECHNIQUE.length() );
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
