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
#include "COLLADAMayaMaterialExporter.h"
#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaShaderHelper.h"

#include <maya/MItMeshPolygon.h>
#include <maya/MItDag.h>
#include <maya/MFnSet.h>
#include <maya/MFnMesh.h>

#include "COLLADANode.h"

namespace COLLADAMaya
{

    //---------------------------------------------------------------
    MaterialExporter::MaterialExporter ( COLLADA::StreamWriter* streamWriter,
                                         DocumentExporter* _documentExporter )
            : COLLADA::LibraryMaterials ( streamWriter ),
            mDocumentExporter ( _documentExporter ),
            mExportedMaterials ( NULL ),
            mWriteMaterials ( false ),
            materialMapInitialized ( false )
    {}

    //---------------------------------------------------------------
    MaterialMap* MaterialExporter::exportMaterials ( bool writeMaterials )
    {
        mWriteMaterials = writeMaterials;

        // Get all shaders, which are in the default shader list.
        // Unfortunately, you will not get the default initialShadingGroup elements, which are
        // directly connected to an object, if no other material (shader) is connected to the object.
        exportMaterialsByShaderPlug();

        // Now go through scene graph and find all shaders, connected to the meshes.
        // So you can find the default shaders of an object.
        exportMaterialsBySceneGraph();

        // Set the flag, that the material std::map is initialised
        materialMapInitialized = true;

        // Close the tags in the collada document
        closeLibrary();

        // Return the material list
        return &mMaterialMap;
    }

    //------------------------------------------------------
    // Get all shaders, which are in the default shader list.
    // Unfortunately, you will not get the default initialShadingGroup elements, which are
    void MaterialExporter::exportMaterialsByShaderPlug()
    {
        // Get all shaders, which are in the default shader list.
        MObject defaultShaderList = DagHelper::getNode ( "defaultShaderList1" );
        MPlug defaultShadersPlug = MFnDependencyNode ( defaultShaderList ).findPlug ( "shaders" );

        uint shaderCount = defaultShadersPlug.evaluateNumElements();
        for ( uint i = 0; i < shaderCount; ++i )
        {
            MObject shader = DagHelper::getNodeConnectedTo ( defaultShadersPlug.elementByPhysicalIndex ( i ) );
            MFnDependencyNode shadingEngineFn ( shader );

            bool isFromReferencedFile = shadingEngineFn.isFromReferencedFile();
            bool isDefaulNode = shadingEngineFn.isDefaultNode();

            if ( !isFromReferencedFile && !isDefaulNode )
            {
                MObject shadingEngine = ShaderHelper::getShadingEngine ( shader );
                exportMaterial ( shadingEngine );
            }
        }
    }

    //------------------------------------------------------
    // Now go through scene graph and find all shaders, connected to the meshes.
    // So you can find the default shaders of an object.
    void MaterialExporter::exportMaterialsBySceneGraph()
    {
        // Get the list with the transform nodes.
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

        // Export all/selected DAG nodes
        uint length = exportNodesTree->size();
        for ( uint i = 0; i < length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];
            const MDagPath dagPath = sceneElement->getPath();

            uint childCount = sceneElement->getChildCount();
            for ( uint i=0; i<childCount; ++i )
            {
                SceneElement* childSceneElement = sceneElement->getChild ( i );

                exportConnectedMaterials ( childSceneElement );
            }
        }
    }

    //---------------------------------------------------------------
    void MaterialExporter::exportConnectedMaterials ( SceneElement* sceneElement )
    {
        // Check if it is a mesh object and an export node
        if ( sceneElement->getType() == SceneElement::MESH &&
                sceneElement->getIsExportNode() )
        {
            MDagPath dagPath = sceneElement->getPath();

            // Attach a function set
            MStatus status;
            MFnMesh fnMesh ( dagPath.node(), &status );

            if ( status != MStatus::kSuccess ) return;

            // Find how many shaders are used by this instance of the mesh
            MObjectArray shaders;
            MIntArray shaderIndices;
            unsigned instanceNumber = dagPath.instanceNumber();
            fnMesh.getConnectedShaders ( instanceNumber, shaders, shaderIndices );

            // Find the polygons that correspond to each materials and export them
            uint realShaderCount = ( uint ) shaders.length();
            uint numShaders = ( uint ) max ( ( size_t ) 1, ( size_t ) shaders.length() );

            for ( uint shaderPosition = 0; shaderPosition < numShaders; ++shaderPosition )
            {
                if ( shaderPosition < realShaderCount )
                {
                    // Add shader-specific parameters (TexCoords sets).
                    // Add symbolic name for the material used on this polygon set.
                    MObject shadingEngine = shaders[shaderPosition];
                    exportMaterial ( shadingEngine );
                }
            }
        }

        // recursive call for all the child elements
        for ( uint i=0; i<sceneElement->getChildCount(); ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );
            exportConnectedMaterials ( childElement );
        }
    }

    //---------------------------------------------------------------
    // Writes the material of the shading engine into the collada document
    // and adds the material into the materials list.
    //
    void MaterialExporter::exportMaterial ( MObject shadingEngine )
    {
        MObject shader = DagHelper::getSourceNodeConnectedTo ( shadingEngine, "surfaceShader" );

        // Find the actual shader node, since this function received shading sets as input
        MStatus status;
        MFnDependencyNode shaderNode ( shader, &status );
        if ( status != MStatus::kSuccess ) return;

        // Get the name of the current material
        String materialId = mDocumentExporter->mayaNameToColladaName ( shaderNode.name(), true );

        // Have we seen this shader before?
        MaterialMap::iterator materialMapIter;
        materialMapIter = mMaterialMap.find ( materialId );
        if ( materialMapIter == mMaterialMap.end() )
        {
            // This is a new shading engine
            mMaterialMap[materialId] = shader;
        }

        // Check if the material should be written
        if ( mWriteMaterials )
        {
            // Have we exported this shader already?
            std::vector<String>::iterator exportedMaterialsIter;
            exportedMaterialsIter = find ( mExportedMaterials.begin(), mExportedMaterials.end(), materialId );

            if ( exportedMaterialsIter == mExportedMaterials.end() )
            {
                // Write the material with the effect URL into the collada file
                String effectURL = materialId + EffectExporter::EFFECT_ID_SUFFIX;
                addInstanceEffect ( COLLADA::URI ( "", effectURL ), materialId, materialId );

                // Push the if of the exported material into the list for the exported materials
                mExportedMaterials.push_back ( materialId );
            }
        }
    }

    //---------------------------------------------------------------
    /** Returns the std::map with all the materials */
    MaterialMap* MaterialExporter::getExportedMaterialsMap()
    {
        if ( !materialMapInitialized ) exportMaterials ( false );

        return &mMaterialMap;
    }
}