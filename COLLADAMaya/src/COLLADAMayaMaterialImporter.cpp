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
#include "MayaDMGroupId.h"
#include "MayaDMDefaultShaderList.h"
#include "MayaDMCommands.h"

#include "COLLADAFWMaterial.h"


namespace COLLADAMaya
{

    const String MaterialImporter::MATERIAL_NAME = "Material";
    const String MaterialImporter::SHADING_ENGINE_NAME = "ShadingEngine";
    const String MaterialImporter::MATERIAL_INFO_NAME = "MaterialInfo";
    const String MaterialImporter::DEFAULT_SHADER_LIST = ":defaultShaderList1";
    const String MaterialImporter::INITIAL_SHADING_ENGINE = ":initialShadingGroup";
    const String MaterialImporter::ATTR_SHADERS = "shaders";
    

    //------------------------------
    MaterialImporter::MaterialImporter ( DocumentImporter* documentImporter )
    : BaseImporter ( documentImporter )
    {}

    // --------------------------
    MaterialImporter::~MaterialImporter ()
    {
        // Delete the shadingBindings
        {
            ShadingEngineBindingMap::iterator iter = mShadingEngineBindingMap.begin ();
            while ( iter != mShadingEngineBindingMap.end () )
            {
                std::set<ShadingBinding*>& geometryInstances = iter->second;

                std::set<ShadingBinding*>::iterator iter2 = geometryInstances.begin ();
                while ( iter2 != geometryInstances.end () )
                {
                    ShadingBinding* geometryInstance = *iter2;
                    delete geometryInstance;
                    ++iter2;
                }
                ++iter;
            }
        }

        // Delete the shader datas
        {
            ShadingDataMap::iterator iter = mShaderDataMap.begin ();
            while ( iter != mShaderDataMap.end () )
            {
                ShadingData* shadingData = iter->second;
                delete shadingData;
                ++iter;
            }
        }
    }

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
        materialName = DocumentImporter::frameworkNameToMayaName ( materialName );
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
         ShadingData* shaderData = findShaderData ( referencedMaterialId );
         if ( shaderData == 0 )
         {
             // Get the unique shading engine name.
             String shadingEngineName = materialBinding.getName ();
             if ( COLLADABU::Utils::equals ( shadingEngineName, COLLADABU::Utils::EMPTY_STRING ))
                 shadingEngineName = SHADING_ENGINE_NAME;
             shadingEngineName = DocumentImporter::frameworkNameToMayaName ( shadingEngineName );
             shadingEngineName = mShadingEngineIdList.addId ( shadingEngineName );

             // Create a shading engine, if we not already have one.
             FILE* file = getDocumentImporter ()->getFile ();
             MayaDM::ShadingEngine* shadingEngine = new MayaDM::ShadingEngine ( file, shadingEngineName.c_str () );

             // Create the material info node for the shading engine.
             // createNode materialInfo -name "materialInfo2";
             String materialInfoName = MATERIAL_INFO_NAME;
             materialInfoName = DocumentImporter::frameworkNameToMayaName ( materialInfoName );
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
         ShadingBinding* shadingBinding = new ShadingBinding();
         shadingBinding->setGeometryId ( geometryId );
         shadingBinding->setTransformNodeId ( transformNodeId );
         shadingBinding->setMaterialId ( referencedMaterialId );
         mShadingEngineBindingMap [shadingEngineId].insert ( shadingBinding );
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
    void MaterialImporter::writeConnections ()
    {
        // select -noExpand :defaultShaderList1;
        // select -noExpand :initialShadingGroup;
        FILE* file = getDocumentImporter ()->getFile ();
        mayaSelect ( file, DEFAULT_SHADER_LIST, true );
        mayaSelect ( file, INITIAL_SHADING_ENGINE, true );

        // If there are some object groups, we have to connect them with the geometries.
        connectGeometryGroups();

        // Connect the material with the shading engine and the material info.
        connectShadingEngines ();

        // Connect the material with the depending geometries.
        connectGeometries ();

        // Connects the default shader list with the materials.
        connectDefaultShaderList();
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
        ShadingEngineBindingMap::iterator shadingEngineIter = mShadingEngineBindingMap.begin ();
        while ( shadingEngineIter != mShadingEngineBindingMap.end () )
        {
            size_t shadingEngineIndex = 0;

            COLLADAFW::MaterialId shadingEngineId = shadingEngineIter->first;
            std::set<ShadingBinding*>& geometryInstances = shadingEngineIter->second;

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
                    std::vector<size_t>* primitivesIndicesVec = 
                        geometryImporter->getShadingEnginePrimitiveIndices ( geometryId, shadingEngineId );

                    // Iterate over the primitiv indices.
                    size_t primitivesCount = primitivesIndicesVec->size ();
                    for ( size_t p=0; p<primitivesCount; ++p )
                    {
                        size_t primitiveIndex = (*primitivesIndicesVec) [p];
                        FILE* file = getDocumentImporter ()->getFile ();

                        if ( primitivesCount > 1 )
                        {
                            // connectAttr "|pCube2|pCubeShape1.instObjGroups" "blinn1SG.dagSetMembers" -nextAvailable;
                            connectAttr ( file, mesh->getObjectGroups ( geometryInstanceIndex, primitiveIndex ), shadingEngine->getDagSetMembers ( shadingEngineIndex ) );

                            // connectAttr "lambert2SG.memberWireframeColor" "|pCube1|pCubeShape1.instObjGroups.objectGroups[0].objectGrpColor";
                            connectAttr ( file, shadingEngine->getMemberWireframeColor (), mesh->getObjectGrpColor ( geometryInstanceIndex, primitiveIndex ) );
                        }
                        else
                        {
                            // connectAttr "|pCube1|pCubeShape1.instObjGroups" "lambert2SG.dagSetMembers" -nextAvailable;
                            connectAttr ( file, mesh->getInstObjGroups ( geometryInstanceIndex ), shadingEngine->getDagSetMembers ( shadingEngineIndex ) );
                        }
                    }

                    ++geometryInstancesIter;
                    ++shadingEngineIndex;
                }
            }

            ++ shadingEngineIter;
        }
    }

    // --------------------------
    void MaterialImporter::connectGeometryGroups ()
    {
        // If there are some object groups, we have to connect them with the geometries.
        GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();
        GeometryImporter::GroupIdAssignments groupIdAssignments = geometryImporter->getGroupIdAssignments ();
        for ( size_t i=0; i<groupIdAssignments.size (); ++i )
        {
            GeometryImporter::GroupIdAssignment& groupIdAssignment = groupIdAssignments [i];
            const MayaDM::GroupId& groupId = groupIdAssignment.getGroupId ();
            const COLLADAFW::UniqueId& geometryId = groupIdAssignment.getGeometryId ();
            size_t geometryInstanceIndex = groupIdAssignment.getGeometryInstanceIndex ();
            size_t primitiveIndex = groupIdAssignment.getPrimitiveIndex ();

            MayaDM::Mesh* mesh = geometryImporter->findMayaDMMeshNode ( geometryId );

            // connectAttr "groupId1.groupId" "|pCube1|pCubeShape1.instObjGroups.objectGroups[0].objectGroupId";
            FILE* file = getDocumentImporter ()->getFile ();
            connectAttr ( file, groupId.getGroupId (), mesh->getObjectGroupId ( geometryInstanceIndex, primitiveIndex ) );
        }
    }

    // --------------------------
    void MaterialImporter::connectDefaultShaderList ()
    {
        FILE* file = getDocumentImporter ()->getFile ();

        // connectAttr "lambert2.message" ":defaultShaderList1.shaders" -nextAvailable;
        EffectImporter* effectImporter = getDocumentImporter ()->getEffectImporter ();
        const EffectImporter::UniqueIdDependNodeMap& effectMap = effectImporter->getMayaEffectMap ();
        EffectImporter::UniqueIdDependNodeMap::const_iterator it = effectMap.begin ();

        MayaDM::DefaultShaderList defaultShaderList ( file, DEFAULT_SHADER_LIST, "", false );

        size_t shaderIndex = 0;
        while ( it != effectMap.end () )
        {
            MayaDM::DependNode* dependNode = it->second;
            connectAttr ( file, dependNode->getMessage (), defaultShaderList.getShaders (shaderIndex) );
            ++shaderIndex;
            ++it;
        }
    }

}