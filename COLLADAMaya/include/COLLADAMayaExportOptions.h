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

        /****************************/
        /** General export options  */
        /****************************/

		/** True, if we want to encode xsd:name with UCS2 to have valid xml. */
		static bool mEncodedNames;

		/** DAE ModelPathName when exporting into two separate files */
		static MString mDAEmodelName;

		/** True, if we want to export LOD from LODGroup. */
		static bool mLOD;

        /** True, if we should a write transform matrix. */
        static bool mBakeTransforms;

        /** True, if we should write relative pathes to external file references. */
        static bool mRelativePaths;

		/** True, if we should keep source files tree. */
		static bool mPreserveSourceTree;

        /** True, if the texture files should be copied to the destination folder. */
        static bool mCopyTextures;
        static bool mExportTriangles;

        /** True, if file references to cgfx files should be exported 
        (instead of directly writing the contant of the file). */
        static bool mExportCgfxFileReferences;

        static bool mIsSampling;
        static bool mCurveConstrainSampling;
        static bool mRemoveStaticCurves;

        /****************************/
        /**     Filter export       */
        /****************************/
		static bool mExportPhysics;
        static bool mExportConvexMeshGeometries;
        static bool mExportPolygonMeshes;
        static bool mExportLights;
        static bool mExportCameras;
		static bool mExportJoints;
		static bool mExportSkin;
		static bool mExportAnimationsOnly;
		static bool mExportSeparateFile;
		static bool mExportAnimations;
		static bool mExportOptimizedBezierAnimations;
        static bool mExportInvisibleNodes;
        static bool mExportDefaultCameras;
        static bool mExportTexCoords;
        static bool mExportNormals;
        static bool mExportNormalsPerVertex;
        static bool mExportVertexColors;
        static bool mExportVertexColorsPerVertex;
        static bool mExportTexTangents;
        static bool mExportTangents;
        static bool mExportReferencedMaterials;
        static bool mExportMaterialsOnly;

        /****************************/
        /**     XRef options        */
        /****************************/

        static bool mExportXRefs;
        static bool mDereferenceXRefs;

        /****************************/
        /**     Camera options      */
        /****************************/

        static bool mExportCameraAsLookat;
        static bool mCameraXFov;
        static bool mCameraYFov;

        /****************************/
        /**     Precision options   */
        /****************************/

        static bool mDoublePrecision;

    public:

        /** Parse the options String and reset all options to their default values. */
        static void set ( const MString &optionsString );

        /****************************/
        /** General export options  */
        /****************************/
		static MString getDAEmodelName();
		static bool exportLOD();
		static bool exportEncodedNames();

        /** Should the transforms be baked into a single matrix, as opposed to decomposed into 
        primitive collada transforms (e.g. translate, rotate, scale)? Default: FALSE */
        static bool bakeTransforms();
        static bool relativePaths();
		static bool preserveSourceTree();

        /** True, if the texture files should be copied to the destination folder. */
        static bool copyTextures();
        static bool exportTriangles();

        /** If true, a reference to the used cgfx files will be included in the exported dae file. 
        Otherwise, the code of the used cgfx file will be implemented.*/
        static bool exportCgfxFileReferences ();
        static bool isSampling();
        static bool curveConstrainSampling();
        static bool removeStaticCurves();

        /****************************/
        /**     Filter export       */
        /****************************/

		static bool exportPhysics();
        static void setExportPhysics(bool value);
        static bool exportConvexMeshGeometries();
        static bool exportPolygonMeshes();
        static bool exportLights();
        static bool exportCameras();
        static bool exportJoints();
		static bool exportSkin();
		static bool exportAnimationsOnly();
		static bool exportSeparateFile();
        static bool exportAnimations();
		static bool exportOptimizedBezierAnimations();
        static bool exportInvisibleNodes();
        static bool exportDefaultCameras();
        static bool exportTexCoords();
        static bool exportNormals();
        static bool exportNormalsPerVertex();
        static bool exportVertexColors();
        static bool exportVertexColorsPerVertex();
        static bool exportTexTangents();
        static bool exportTangents();
        static bool exportReferencedMaterials ();
        static bool exportMaterialsOnly ();

        /****************************/
        /**     XRef options        */
        /****************************/

        static bool exportXRefs();
        static bool dereferenceXRefs();

        /****************************/
        /**     Camera options      */
        /****************************/

        static bool exportCameraAsLookat();
        static bool cameraXFov();
        static bool cameraYFov();

        /****************************/
        /**     Precision options   */
        /****************************/

        static bool doublePrecision();

    };

}

#endif // __COLLADA_MAYA_EXPORT_OPTIONS_H__
