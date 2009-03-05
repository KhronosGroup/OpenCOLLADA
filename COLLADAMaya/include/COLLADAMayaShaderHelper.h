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

#ifndef __COLLADA_MAYA_SHADER_HELPER_H__
#define __COLLADA_MAYA_SHADER_HELPER_H__

#include <maya/MFnDependencyNode.h>
#include <vector>

namespace COLLADAMaya
{

    class DaeTexture
    {

    public:
        MObject textureObject;
        MObject frontObject;
        int blendMode;

        DaeTexture() : blendMode ( -1 ) {}
    };

    typedef std::vector<DaeTexture> DaeTextureList;

    /**
     * Class which helps to extract the data of the shaders.
     */
    class ShaderHelper
    {

    public:
        // Get the UV set for a procedural/file texture
        static unsigned int getAssociatedUVSet ( const MObject& shape, const MObject& textureNode );

        // Get a list of file texture node associated with the given layeredTexture node
        // Note: the returned MObject is always kNullObj.
        static MObject getLayeredTextures ( const MObject& layeredTexture, MObjectArray& fileTextures, MIntArray& blendModes );

        // Create a new shader
        static MObject createShader ( MFn::Type type, const MString& name );

        // Attach a shading network to a shading engine
        static MStatus attachShadingNetwork ( MObject shadingEngine, MObject shadingNetwork, const MString& type );

        // Attach a list of mesh components to a shading group.
        static MStatus attachMeshShader ( const MObject& shadingGroup, const MObject& mesh, const MObject& components, uint instanceNumber );
        static MStatus attachMeshShader ( const MObject& shadingGroup, const MObject& mesh, uint instanceNumber );

        // Attach a list of NURBS components to a shading group.
        static MStatus attachNURBSSurfaceShader ( const MObject& shadingGroup, const MObject& nurbsSurface, uint instanceNumber );

        // Get the shadingEngine used by a specific shader (the inverse of the above)
        static MObject getShadingEngine ( MObject shadingNetwork );

        // Find the shaders connected to this dependency node
        // Used for shader retrieval in NURBS surfaces
        static MStatus getConnectedShaders ( const MFnDependencyNode& node, MObjectArray& shaders );

        // Attach a place2dTexture node to a texture image
        static MObject create2DPlacementNode ( MObject texture );

        // Attach a bump2d node to a bump file texture node
        static MObject createBumpNode ( MObject texture );

        // Attach all the fileTexture nodes together into a layeredTexture node
        static MObject createLayeredTexture ( const DaeTextureList& textures );

        // Attach a uvChooser node between a uvSet and a texture image
        static MObject associateUVSetWithTexture ( MObject texture, MObject mesh, int uvSetIndex );

        // Find a connected/non-connected plug from a node
        static MPlug findPlug ( const MFnDependencyNode& node, const MString& plugName, MStatus* rc=NULL );
        static uint findArrayPlugEmptyIndex ( const MPlug& plug );

        // Find/Create a display layer node
        static MObject findDisplayLayer ( const char* name );

        // Handles projection type
        static int toProjectionType ( const char* type );
        static int defaultProjectionType();
        static const char* projectionTypeToString ( int type );

    private:

        /** Don't create an object of this class. */
        ShaderHelper() {};
    };
}


#endif // __COLLADA_MAYA_SHADER_HELPER_H__
