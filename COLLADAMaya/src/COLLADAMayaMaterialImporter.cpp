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
#include "COLLADAMayaMaterialImporter.h"
#include "COLLADAMayaEffectImporter.h"
#include "COLLADAMayaGeometryImporter.h"
#include "COLLADAMayaVisualSceneImporter.h"

#include "MayaDMMesh.h"
#include "MayaDMLambert.h"


namespace COLLADAMaya
{

    const String MaterialImporter::MATERIAL_NAME = "Material";
    const String MaterialImporter::SHADING_ENGINE_NAME = "ShadingEngine";
    const String MaterialImporter::MATERIAL_INFO_NAME = "MaterialInfo";


    //------------------------------
    MaterialImporter::MaterialImporter ( DocumentImporter* documentImporter )
    : BaseImporter ( documentImporter )
    {}

    // --------------------------
    bool MaterialImporter::importMaterial ( const COLLADAFW::Material* material )
    {
        // Check if the current material is already imported.
        const COLLADAFW::UniqueId& materialId = material->getUniqueId ();
        if ( findMayaMaterial ( materialId ) != 0 ) return false;

        // Get the material name.
        String materialName ( material->getName () );
        if ( COLLADABU::Utils::equals ( materialName, COLLADABU::Utils::EMPTY_STRING ) )
            materialName = MATERIAL_NAME;
        materialName = mMaterialIdList.addId ( materialName );
        
        // Store the material name.
        mMayaMaterialNamesMap [materialId] = materialName;

        // Store the effect id of the current material id.
        const COLLADAFW::UniqueId& effectId = material->getInstantiatedEffect ();
        mMaterialIdEffectIdMap [materialId] = effectId;

        return true;
     }

     // --------------------------
     MayaDM::DependNode* MaterialImporter::findMayaMaterial ( const COLLADAFW::UniqueId& materialId ) const
     {
         UniqueIdMayaMaterialMap::const_iterator it = mMayaMaterialMap.find ( materialId );
         if ( it != mMayaMaterialMap.end () )
         {
             return it->second;
         }
         return 0;
     }

     // --------------------------
     void MaterialImporter::appendMaterial ( const COLLADAFW::UniqueId& id, MayaDM::DependNode* materialNode )
     {
         mMayaMaterialMap [id] = materialNode;
     }

     // -----------------------------------
     MaterialImporter::ShadingData* MaterialImporter::findShaderData ( 
         const COLLADAFW::UniqueId& val )
     {
         ShadingDataMap::const_iterator it = mShaderDataMap.find ( val );
         if ( it == mShaderDataMap.end () )
         {
             return 0;
         }

         return it->second;
     }

     // -----------------------------------
     const COLLADAFW::UniqueId* MaterialImporter::findEffectId ( const COLLADAFW::UniqueId& materialId )
     {
         UniqueIdUniqueIdMap::const_iterator it = mMaterialIdEffectIdMap.find ( materialId );
         if ( it == mMaterialIdEffectIdMap.end () )
         {
             return 0;
         }

         return &(it->second);
     }

     // -----------------------------------
     void MaterialImporter::appendShaderData ( 
         const COLLADAFW::UniqueId& materialId, 
         MayaDM::ShadingEngine* shadingEngine, 
         MayaDM::MaterialInfo* materialInfo )
     {
         mShaderDataMap [materialId] = new ShadingData ( shadingEngine, materialInfo );
     }

     // -----------------------------------
     void MaterialImporter::writeShaderData ( 
         const COLLADAFW::InstanceGeometry::MaterialBinding& materialBinding, 
         const COLLADAFW::UniqueId& transformNodeId, 
         const COLLADAFW::InstanceGeometry* instanceGeometry )
     {
         // Get the material id.
         const COLLADAFW::UniqueId& referencedMaterialId = materialBinding.getReferencedMaterial ();

         // Check if already a shading engine with the materialId exist.
         MayaDM::ShadingEngine* shadingEngine;
         MayaDM::MaterialInfo* materialInfo;
         String shadingEngineName;
         ShadingData* shaderData = findShaderData ( referencedMaterialId );
         if ( shaderData == 0 )
         {
             // Get the unique shading engine name.
             shadingEngineName = materialBinding.getName ();
             if ( COLLADABU::Utils::equals ( shadingEngineName, COLLADABU::Utils::EMPTY_STRING ))
                 shadingEngineName = SHADING_ENGINE_NAME;
             shadingEngineName = mShadingEngineIdList.addId ( shadingEngineName );

             // Create a shading engine, if we not already have one.
             FILE* file = getDocumentImporter ()->getFile ();
             shadingEngine = new MayaDM::ShadingEngine ( file, shadingEngineName.c_str () );

             // Create the material info node for the shading engine.
             // createNode materialInfo -name "materialInfo2";
             String materialInfoName = MATERIAL_INFO_NAME;
             materialInfoName = mMaterialInfoIdList.addId ( materialInfoName ); 
             MayaDM::MaterialInfo* materialInfo = new MayaDM::MaterialInfo ( file, materialInfoName.c_str () );

             // Push it in the map of shading engines
             appendShaderData ( referencedMaterialId, shadingEngine, materialInfo );
         }

         // of geometry ids of the current shader engine.
         const COLLADAFW::UniqueId& geometryId = instanceGeometry->getInstanciatedObjectId ();

         // Get the material id and the shading engine name.
         COLLADAFW::MaterialId shadingEngineId = materialBinding.getMaterialId ();

         // Push the geometry id of the current instance in the list 
         ShadingBinding* geometryInstance = new ShadingBinding();
         geometryInstance->setGeometryId ( geometryId );
         geometryInstance->setTransformNodeId ( transformNodeId );
         geometryInstance->setMaterialId ( referencedMaterialId );
         mShadingEngineGeometryInstancesMap [shadingEngineId].insert ( geometryInstance );
     }

    // --------------------------
    void MaterialImporter::writeConnections ()
    {
        // Connect the material with the shading engine and the material info.
        connectShadingEngines ();

        connectGeometries();

    }

    // --------------------------
    size_t MaterialImporter::getGeometryInstanceIndex ( 
        const COLLADAFW::UniqueId& geometryId, 
        const COLLADAFW::UniqueId& transformNodeId )
    {
        size_t meshInstanceIndex = 0;

        // Get all visual scene nodes, which use this geometry and make the parent connections.
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        const UniqueIdVec* transformNodes = visualSceneImporter->findGeometryTransformIds ( geometryId );
        size_t numNodeInstances = transformNodes->size ();

        bool found = false;
        for ( size_t index=0; index<numNodeInstances && !found; ++index )
        {
            const COLLADAFW::UniqueId& nodeId = (*transformNodes) [index];
            if ( nodeId == transformNodeId ) 
            {
                meshInstanceIndex = index;
                found = true;
            }
        }
        return meshInstanceIndex;
    }

    // --------------------------
    void MaterialImporter::connectShadingEngines ()
    {
        ShadingDataMap::iterator shaderDataIter = mShaderDataMap.begin();
        while ( shaderDataIter != mShaderDataMap.end () )
        {
            const COLLADAFW::UniqueId& materialId = shaderDataIter->first;
            ShadingData* shaderData = shaderDataIter->second;

            MayaDM::ShadingEngine* shadingEngine = shaderData->getShadingEngine ();
            MayaDM::MaterialInfo* materialInfo = shaderData->getMaterialInfo ();

            // Connect the message attribute of the shading engine 
            // with the shading group of the material info.
            // connectAttr "blinn1SG.message" "materialInfo2.shadingGroup";
            FILE* file = getDocumentImporter ()->getFile ();
            connectAttr ( file, shadingEngine->getMessage (), materialInfo->getShadingGroup () );

            // Get the effect
            MayaDM::DependNode* effectNode = 0;
            EffectImporter* effectImporter = getDocumentImporter ()->getEffectImporter ();
            const COLLADAFW::UniqueId* effectId = findEffectId ( materialId );
            if ( effectId != 0 )
                effectNode = effectImporter->findMayaEffect ( *effectId );
            if ( effectNode != 0 )
            {
                String nodeType = effectNode->getType ();
                if ( COLLADABU::Utils::equalsIgnoreCase ( nodeType, "lambert" ) )
                {
                    MayaDM::Lambert* lambertNode = ( MayaDM::Lambert* ) effectNode;

                    // connectAttr "blinn1.outColor" "blinn1SG.surfaceShader";
                    connectAttr ( file, lambertNode->getOutColor (), shadingEngine->getSurfaceShader () );

                    // connectAttr "blinn1.message" "materialInfo2.material";
                    connectAttr ( file, lambertNode->getMessage (), materialInfo->getMaterial () );
                }
            }

            ++shaderDataIter;
        }
    }

    // --------------------------
    void MaterialImporter::connectGeometries ()
    {
        // Find all geometry mesh primitives, which use this effect and create the connections.
        ShadingEngineBindingMap::iterator shadingEngineToGeometriesIter = mShadingEngineGeometryInstancesMap.begin ();
        while ( shadingEngineToGeometriesIter != mShadingEngineGeometryInstancesMap.end () )
        {
            size_t shadingEngineIndex = 0;

            COLLADAFW::MaterialId shadingEngineId = shadingEngineToGeometriesIter->first;
            std::set<ShadingBinding*>& geometryInstances = shadingEngineToGeometriesIter->second;

            std::set<ShadingBinding*>::iterator geometryInstancesIter = geometryInstances.begin ();
            while ( geometryInstancesIter != geometryInstances.end () )
            {
                ShadingBinding* geometryInstance = *geometryInstancesIter;
                const COLLADAFW::UniqueId& geometryId = geometryInstance->getGeometryId ();
                const COLLADAFW::UniqueId& transformNodeId = geometryInstance->getTransformNodeId ();
                const COLLADAFW::UniqueId& materialId = geometryInstance->getMaterialId ();

                // Get the shader data.
                ShadingData* shaderData = findShaderData ( materialId );
                if ( shaderData != 0 )
                {
                    // ".instObjGroups"; // for every geometry instance
                    // ".instObjGroups[0].objectGroups"; // for every mesh primitive

                    // Find the index of the transform node of the current geometry instance.
                    // This is the geometry instance index we use to set the current connection to.
                    size_t geometryInstanceIndex = getGeometryInstanceIndex ( geometryId, transformNodeId );

                    // Get the mesh.
                    GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();
                    MayaDM::Mesh* mesh = geometryImporter->findMayaDMMeshNode ( geometryId );

                    // Get the maya shading engine.
                    MayaDM::ShadingEngine* shadingEngine = shaderData->getShadingEngine ();

                    // Get the index values for the current geometry's primitive elements, 
                    // which use the current shading engine.
                    std::vector<size_t>* primitivesIndicesVec = geometryImporter->getShadingEnginePrimitiveIndices ( geometryId, shadingEngineId );

                    // Iterate over the primitiv indices.
                    size_t primitivesCount = primitivesIndicesVec->size ();
                    for ( size_t p=0; p<primitivesCount; ++p )
                    {
                        size_t primitiveIndex = (*primitivesIndicesVec) [p];

                        // connectAttr "|pCube2|pCubeShape1.instObjGroups" "blinn1SG.dagSetMembers" -nextAvailable;
                        FILE* file = getDocumentImporter ()->getFile ();
                        connectAttr ( file, mesh->getObjectGroups ( geometryInstanceIndex, primitiveIndex ), shadingEngine->getDagSetMembers ( shadingEngineIndex ) );
                    }

                    ++geometryInstancesIter;
                    ++shadingEngineIndex;
                }
            }

            ++ shadingEngineToGeometriesIter;
        }
    }
}