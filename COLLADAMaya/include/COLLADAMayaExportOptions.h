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

#ifndef __COLLADA_MAYA_EXPORT_OPTIONS_H__
#define __COLLADA_MAYA_EXPORT_OPTIONS_H__

#include <maya/MPxFileTranslator.h>


namespace COLLADAMaya
{
    /**
     * COLLADA Export options
     * Class which manages the export options.
     * All options are stored statically to allow easy retrieval
     * from any class. At some point we may want to
     * modify this class to use a singleton pattern...
     */
    class ExportOptions
    {

    private:
        static bool mBakeTransforms;
        static bool mBakeLighting;
        static bool mRelativePaths;

        /** True, if the texture files should be copied to the destination folder. */
        static bool mCopyTextures;

        static bool mExportPolygonMeshes;
        static bool mExportLights;
        static bool mExportCameras;
        static bool mExportJointsAndSkin;
        static bool mExportAnimations;
        static bool mExportCameraAsLookat;
        static bool mExportTriangles;
        static bool mExportInvisibleNodes;
        static bool mExportDefaultCameras;
        static bool mExportNormals;
        static bool mExportNormalsPerVertex;
        static bool mExportTexCoords;
        static bool mExportVertexColors;
        static bool mExportVertexColorsPerVertex;
        static bool mExportVertexColorAnimations;
        static bool mExportTangents;
        static bool mExportTexTangents;
        static bool mExportMaterialsOnly;
        static bool mExportConstraints;
        static bool mRemoveStaticCurves;
        static bool mExportPhysics;
        static bool mExportXRefs;
        static bool mDereferenceXRefs;
        static bool mCameraXFov;
        static bool mCameraYFov;

        static int mExclusionSetMode;
        static MStringArray mExclusionSets;

        static bool mIsSampling;
        static bool mCurveConstrainSampling;
        static MFloatArray mSamplingFunction;

    public:

        /** Parse the options String and reset all options to their default values. */
        static void set ( const MString &optionsString );

        /** Should the transforms be baked into a single matrix,
        as opposed to decomposed into primitive collada
        transforms (e.g. translate, rotate, scale)?
        Default: FALSE */
        static bool bakeTransforms();

        static bool exportPolygonMeshes();

        static bool bakeLighting();

        static bool isSampling();

        static bool curveConstrainSampling();

        static bool removeStaticCurves();

        static bool exportCameraAsLookat();

        static bool relativePaths();

        // Export filters
        static bool exportLights();

        static bool exportCameras();

        static bool exportJointsAndSkin();

        static bool exportAnimations();

        static bool exportTriangles();

        static bool exportInvisibleNodes();

        static bool exportDefaultCameras();

        static bool exportNormals();

        static bool exportNormalsPerVertex();

        static bool exportTexCoords();

        static bool exportVertexColors();

        static bool exportVertexColorsPerVertex();

        static bool exportVertexColorAnimations();

        static bool exportTangents();

        static bool exportTexTangents();

        // DF Export Filters
        static bool exportConstraints();

        static bool exportPhysics();

        static MStringArray getExclusionSets();

        // XRef options
        static bool exportXRefs();

        static bool dereferenceXRefs();

        // Camera options
        static bool cameraXFov();

        static bool cameraYFov();

        /** True, if the texture files should be copied to the destination folder. */
        static bool copyTextures();

    };

}

#endif // __COLLADA_MAYA_EXPORT_OPTIONS_H__
