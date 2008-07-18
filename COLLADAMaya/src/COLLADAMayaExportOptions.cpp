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
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaSetHelper.h"
#include "COLLADAMayaAnimationHelper.h"

namespace COLLADAMaya
{

    // Static Members
    bool ExportOptions::mBakeTransforms = false;
    bool ExportOptions::mBakeLighting = false;
    bool ExportOptions::mRelativePaths = true;

    /** True, if the texture files should be copied to the destination folder. */
    bool ExportOptions::mCopyTextures = false;

    bool ExportOptions::mExportPolygonMeshes = true;
    bool ExportOptions::mExportLights  = true;
    bool ExportOptions::mExportCameras = true;
    bool ExportOptions::mExportJointsAndSkin = true;
    bool ExportOptions::mExportAnimations = true;
    bool ExportOptions::mRemoveStaticCurves = true;
    bool ExportOptions::mExportInvisibleNodes = false;
    bool ExportOptions::mExportDefaultCameras = false;
    bool ExportOptions::mExportNormals = true;
    bool ExportOptions::mExportTexCoords = true;
    bool ExportOptions::mExportVertexColors = true;
    bool ExportOptions::mExportVertexColorAnimations = false;
    bool ExportOptions::mExportTangents = false;
    bool ExportOptions::mExportTexTangents = false;
    bool ExportOptions::mExportMaterialsOnly = false;
    bool ExportOptions::mExportCameraAsLookat = true;
    bool ExportOptions::mExportTriangles = false;
    bool ExportOptions::mExportXRefs = true;
    bool ExportOptions::mDereferenceXRefs = false;
    bool ExportOptions::mCameraXFov = false;
    bool ExportOptions::mCameraYFov = true;
    bool ExportOptions::mExportConstraints = true;
    bool ExportOptions::mExportPhysics = true;
    int ExportOptions::mExclusionSetMode = SetHelper::kExcluding;
    MStringArray ExportOptions::mExclusionSets;

    bool ExportOptions::mIsSampling = false;
    bool ExportOptions::mCurveConstrainSampling = false;
    MFloatArray ExportOptions::mSamplingFunction;

    bool CImportOptions::mIsOpenCall = false;
    bool CImportOptions::mIsReferenceCall = false;
    bool CImportOptions::mFileLoadDeferRefOptionVar = false;
    bool CImportOptions::mHasError = false;

    bool CImportOptions::mImportUpAxis = true;
    bool CImportOptions::mImportUnits = true;
    bool CImportOptions::mImportNormals = false;

    // Parse the options String
    //
    void ExportOptions::set ( const MString& optionsString )
    {
        // Reset everything to the default value
        mBakeTransforms = false;
        mBakeLighting = false;
        mRelativePaths = true;

        /** True, if the texture files should be copied to the destination folder. */
        mCopyTextures = false;

        mIsSampling = false;
        mCurveConstrainSampling = false;
        mRemoveStaticCurves = true;
        mSamplingFunction.clear();
        mExportCameraAsLookat = false;
        mExportTriangles = false;

        mExportPolygonMeshes = true;
        mExportLights = true;
        mExportCameras = true;
        mExportJointsAndSkin = true;
        mExportAnimations = true;
        mExportInvisibleNodes = false;
        mExportDefaultCameras = false;
        mExportNormals = true;
        mExportTexCoords = true;
        mExportVertexColors = true;
        mExportVertexColorAnimations = false;
        mExportTangents = false;
        mExportTexTangents = false;
        mExportMaterialsOnly = false;

        mExportXRefs = false;
        mDereferenceXRefs = true;

        mCameraXFov = false;
        mCameraYFov = true;

        // Parse option String
        if ( optionsString.length() > 0 )
        {
            MStringArray optionList;
            optionsString.split ( ';', optionList );
            uint optionCount = optionList.length();

            for ( uint i = 0; i < optionCount; ++i )
            {
                MString& currentOption = optionList[i];

                // Process option name and values.
                MStringArray decomposedOption;
                currentOption.split ( '=', decomposedOption );
                MString& optionName = decomposedOption[0];

                // For boolean values, the value is assumed to be true
                // if omitted.
                bool value = true;

                if ( decomposedOption.length() > 1 &&
                        decomposedOption[1] != "true" &&
                        decomposedOption[1] != "1" )
                    value = false;

                // Process options.
                if ( optionName == "bakeTransforms" ) mBakeTransforms = value;
                else if ( optionName == "bakeLighting" ) mBakeLighting = value;
                else if ( optionName == "relativePaths" ) mRelativePaths = value;
                else if ( optionName == "copyTextures" ) mCopyTextures = value;
                else if ( optionName == "exportPolygonMeshes" ) mExportPolygonMeshes = value;
                else if ( optionName == "exportLights" ) mExportLights = value;
                else if ( optionName == "exportCameras" ) mExportCameras = value;
                else if ( optionName == "exportJointsAndSkin" ) mExportJointsAndSkin = value;
                else if ( optionName == "exportAnimations" ) mExportAnimations = value;
                else if ( optionName == "exportInvisibleNodes" ) mExportInvisibleNodes = value;
                else if ( optionName == "exportDefaultCameras" ) mExportDefaultCameras = value;
                else if ( optionName == "exportNormals" ) mExportNormals = value;
                else if ( optionName == "exportTexCoords" ) mExportTexCoords = value;
                else if ( optionName == "exportVertexColors" ) mExportVertexColors = value;
                else if ( optionName == "exportVertexColorAnimations" ) mExportVertexColorAnimations = value;
                else if ( optionName == "exportTangents" ) mExportTangents = value;
                else if ( optionName == "exportTexTangents" ) mExportTexTangents = value;
                else if ( optionName == "exportMaterialsOnly" ) mExportMaterialsOnly = value;
                else if ( optionName == "exportCameraAsLookat" ) mExportCameraAsLookat = value;
                else if ( optionName == "exportTriangles" ) mExportTriangles = value;
                else if ( optionName == "cameraXFov" ) mCameraXFov = value;
                else if ( optionName == "cameraYFov" ) mCameraYFov = value;
                else if ( optionName == "isSampling" ) mIsSampling = value;
                else if ( optionName == "curveConstrainSampling" ) mCurveConstrainSampling = value;
                else if ( optionName == "removeStaticCurves" ) mRemoveStaticCurves = value;
                else if ( optionName == "exportConstraints" ) mExportConstraints = value;
                else if ( optionName == "exportPhysics" ) mExportPhysics = value;
                else if ( optionName == "exportXRefs" ) mExportXRefs = value;
                else if ( optionName == "dereferenceXRefs" ) mDereferenceXRefs = value;
                else if ( optionName == "exclusionSetMode" ) mExclusionSetMode = value;
                else if ( optionName == "exclusionSets" )
                {
                    mExclusionSets.clear();
                    MStringArray sets;
                    decomposedOption[1].split ( ',', sets );
                    uint setsCount = sets.length();

                    for ( uint j = 0; j < setsCount; ++j ) mExclusionSets.append ( sets[j] );
                }

                else if ( optionName == "samplingFunction" )
                {
                    mSamplingFunction.clear();
                    MStringArray floats;
                    decomposedOption[1].split ( ',', floats );
                    uint floatsCount = floats.length();

                    for ( uint j = 0; j < floatsCount; ++j ) mSamplingFunction.append ( floats[j].asFloat() );
                }
            }
        }

        // AnimationHelper handles the sampling, tell it the function.
        // It returns whether the function is valid.

        if ( mIsSampling && !AnimationHelper::setSamplingFunction ( mSamplingFunction ) )
        {
            MGlobal::displayWarning ( "Given sampling function is invalid." );
            mIsSampling = false;
            mSamplingFunction.clear();
        }

        if ( !mIsSampling )
        {
            AnimationHelper::generateSamplingFunction();
        }

        // SetHelper provides an interface for querying set membership
        // We want to set this every time, even when no sets were passed in, since this function also
        // clears out any sets that might have stuck around from last time
        SetHelper::setSets ( mExclusionSets, ( SetHelper::SetModes ) mExclusionSetMode );
    }

    //
    // Parse the options String
    //
    void CImportOptions::set ( const MString& optionsString, MPxFileTranslator::FileAccessMode mode )
    {
        // Default option values
        mImportUpAxis = true;
        mImportUnits = true;
        mImportNormals = false;

        mHasError = false;

        switch ( mode )
        {

        case MPxFileTranslator::kOpenAccessMode:
            mIsOpenCall = true;
            mIsReferenceCall = false;
            break;
#if MAYA_API_VERSION >= 650

        case MPxFileTranslator::kReferenceAccessMode:
            mIsOpenCall = false;
            mIsReferenceCall = true;
            break;
#endif

        case MPxFileTranslator::kImportAccessMode:
            mIsOpenCall = false;
            mIsReferenceCall = false;
            break;

        default:
            mIsOpenCall = false;
            break;
        }

        // Parse option String

        if ( optionsString.length() > 0 )
        {
            MStringArray optionList;
            optionsString.split ( ';', optionList );
            uint optionCount = optionList.length();

            for ( uint i = 0; i < optionCount; ++i )
            {
                MString& currentOption = optionList[i];

                // Process option name and values.
                MStringArray decomposedOption;
                currentOption.split ( '=', decomposedOption );
                MString& optionName = decomposedOption[0];

                // For boolean values, the value is assumed to be true
                // if omitted.
                bool value = true;

                if ( decomposedOption.length() > 1 && decomposedOption[1] != "true" && decomposedOption[1] != "1" )
                {
                    value = false;
                }

                // Process options.

                if ( optionName == "importUpAxis" ) mImportUpAxis = value;
                else if ( optionName == "importUnits" ) mImportUnits = value;
                else if ( optionName == "importNormals" ) mImportNormals = value;
            }
        }

        int optionValue;

        MGlobal::executeCommand ( "optionVar -q \"fileLoadDeferRef\";", optionValue );
        mFileLoadDeferRefOptionVar = optionValue != 0;
    }

}