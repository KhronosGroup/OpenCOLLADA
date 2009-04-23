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
    const String MaterialImporter::INITIAL_SHADING_ENGINE_NAME = "initialShadingGroup";
    const String MaterialImporter::INITIAL_MATERIAL_INFO_NAME = "initialMaterialInfo";
    const String MaterialImporter::ATTR_SHADERS = "shaders";
    

    //------------------------------
    MaterialImporter::MaterialImporter ( DocumentImporter* documentImporter )
    : BaseImporter ( documentImporter )
    {}

    // --------------------------
    MaterialImporter::~MaterialImporter ()
    {
        // Delete the shader datas
        ShadingDataMap::iterator iter = mShaderDataMap.begin ();
        while ( iter != mShaderDataMap.end () )
        {
            ShadingData* shadingData = iter->second;
            delete shadingData;
            ++iter;
        }
    }

    // --------------------------
    bool MaterialImporter::importMaterial ( const COLLADAFW::Material* material )
    {
         // Check if the current material is already imported.
         const COLLADAFW::UniqueId& materialId = material->getUniqueId ();
        if ( findMayaMaterialNode ( materialId ) != 0 ) return false;

        // Get the material name.
        String materialName ( material->getName () );
        if ( COLLADABU::Utils::equals ( materialName, COLLADABU::Utils::EMPTY_STRING ) )
            materialName = MATERIAL_NAME;
        materialName = DocumentImporter::frameworkNameToMayaName ( materialName );
        materialName = mMaterialIdList.addId ( materialName );
        
        // TODO
//         // Create the shader data with the shading engine and the material info of the material.
//         MaterialImporter::ShadingData* shaderData = createShaderData ( materialId );

        // Create a material node with the name and store it in a map.
        MayaNode* mayaMaterialNode = new MayaNode ( materialId, materialName );
        mMayaMaterialNodesMap [materialId] = mayaMaterialNode;

        // Store the effect id of the current material id.
        const COLLADAFW::UniqueId& effectId = material->getInstantiatedEffect ();
        mMaterialIdEffectIdMap [materialId] = effectId;

        // Store the data also in the other direction, for faster search.
        EffectImporter* effectImporter = getDocumentImporter ()->getEffectImporter ();
        effectImporter->assignMaterial ( effectId, materialId );

        return true;
     }

    // --------------------------------------------
    MayaNode* MaterialImporter::findMayaMaterialNode ( const COLLADAFW::UniqueId& materialId ) 
    {
        UniqueIdMayaNodeMap::iterator it = mMayaMaterialNodesMap.find ( materialId );
        if ( it != mMayaMaterialNodesMap.end () )
            return it->second;

        return 0;
    }

    // -----------------------------------
     MaterialImporter::ShadingData* MaterialImporter::findShaderData ( 
         const COLLADAFW::UniqueId& materialId )
     {
         ShadingDataMap::const_iterator it = mShaderDataMap.find ( materialId );
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

     // --------------------------
     MaterialImporter::ShadingData* MaterialImporter::createShaderData ( 
         const COLLADAFW::UniqueId& materialId, 
         String shadingEngineName /*= ""*/ )
     {
         // Check if already a shading engine with the materialId exist.
         ShadingData* shadingData = findShaderData ( materialId );
         if ( shadingData != 0 ) return shadingData;

         // The initial shading engine and material info can be used instead of created.
         if ( COLLADABU::Utils::equalsIgnoreCase ( shadingEngineName, INITIAL_SHADING_ENGINE_NAME ) )
         {
             // Get the initial shading engine.
             FILE* file = getDocumentImporter ()->getFile ();
             MayaDM::ShadingEngine shadingEngine ( file, INITIAL_SHADING_ENGINE_NAME.c_str (), "", false );

             // Get the initial material info.
             MayaDM::MaterialInfo materialInfo ( file, INITIAL_MATERIAL_INFO_NAME.c_str () );

             // Create a shader data object with the shading engine and the material info 
             // and push it into the map of shading engines
             shadingData = new ShadingData ( shadingEngine, materialInfo );
             mShaderDataMap [materialId] = shadingData;
         }
         else
         {
             // Get the shading engine name.
             if ( COLLADABU::Utils::equals ( shadingEngineName, COLLADABU::Utils::EMPTY_STRING ) )
                 shadingEngineName = SHADING_ENGINE_NAME;
             shadingEngineName = DocumentImporter::frameworkNameToMayaName ( shadingEngineName );
             shadingEngineName = mShadingEngineIdList.addId ( shadingEngineName );

             // Create a shading engine, if we not already have one.
             FILE* file = getDocumentImporter ()->getFile ();
             MayaDM::ShadingEngine shadingEngine ( file, shadingEngineName.c_str () );

             // Create the material info node for the shading engine.
             // createNode materialInfo -name "materialInfo2";
             String materialInfoName = MATERIAL_INFO_NAME;
             materialInfoName = DocumentImporter::frameworkNameToMayaName ( materialInfoName );
             materialInfoName = mMaterialInfoIdList.addId ( materialInfoName ); 
             MayaDM::MaterialInfo materialInfo ( file, materialInfoName.c_str () );

             // Push it in the map of shading engines
             shadingData = new ShadingData ( shadingEngine, materialInfo );
             mShaderDataMap [materialId] = shadingData;
         }

         return shadingData;
     }

    // -----------------------------------
    void MaterialImporter::writeShaderData ( 
        const COLLADAFW::UniqueId& transformId, 
        const COLLADAFW::InstanceGeometry* instanceGeometry )
    {
         // Get the geometry id.
         const COLLADAFW::UniqueId& geometryId = instanceGeometry->getInstanciatedObjectId ();

         // Create a shading binding object for the current geometry.
         GeometryBinding geometryBinding;
         geometryBinding.setGeometryId ( geometryId );
         geometryBinding.setTransformId ( transformId );

         // Go through the bound materials
         const COLLADAFW::InstanceGeometry::MaterialBindingArray& materialBindingsArray = instanceGeometry->getMaterialBindings ();
         size_t numOfBindings = materialBindingsArray.getCount ();
         for ( size_t i=0; i<numOfBindings; ++i )
         {
             // Get the current material binding.
             const COLLADAFW::InstanceGeometry::MaterialBinding& materialBinding = materialBindingsArray [i];

             // Get the material id.
             const COLLADAFW::UniqueId& materialId = materialBinding.getReferencedMaterial ();

             // TODO We need a shading engine and a material info for every maya effect.
             // But an effect can be referenced from multiple materials!!!

             // Get the unique shading engine name and get / create the shader data.
             String shadingEngineName = materialBinding.getName ();
             ShadingData* shaderData = createShaderData ( materialId, shadingEngineName );

             // Get the shading engine id. This id is unique for one geometry.
             COLLADAFW::MaterialId shadingEngineId = materialBinding.getMaterialId ();

             // Create the materialInfo object.
             MaterialInformation materialInfo ( materialId, shadingEngineId );

             // The position of the materialId calls the primitive index.
             mGeometryBindingMaterialInfosMap [geometryBinding].push_back ( materialInfo );
         }

     }

    // --------------------------
    void MaterialImporter::writeConnections ()
    {
        // Connect the material with the shading engine and the material info.
        connectShadingEngines ();

        // Connects the shading engines with the object groups.
        connectShadingEngineObjectGroups ();

        // Connect the material with the depending geometries.
        connectGeometries ();

        // Connects the default shader list with the materials.
        connectDefaultShaderList();
    }

    // --------------------------
    void MaterialImporter::connectShadingEngines ()
    {
        // Get the current maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        ShadingDataMap::iterator shaderDataIter = mShaderDataMap.begin();
        while ( shaderDataIter != mShaderDataMap.end () )
        {
            const COLLADAFW::UniqueId& materialId = shaderDataIter->first;
            ShadingData* shaderData = shaderDataIter->second;

            const MayaDM::ShadingEngine& shadingEngine = shaderData->getShadingEngine ();
            const MayaDM::MaterialInfo& materialInfo = shaderData->getMaterialInfo ();

            // Connect the message attribute of the shading engine 
            // with the shading group of the material info.
            // connectAttr "blinn1SG.message" "materialInfo2.shadingGroup";
            connectAttr ( file, shadingEngine.getMessage (), materialInfo.getShadingGroup () );

            // Get the effect
            MayaDM::DependNode* effectNode = 0;
            EffectImporter* effectImporter = getDocumentImporter ()->getEffectImporter ();
            const COLLADAFW::UniqueId* effectId = findEffectId ( materialId );
            if ( effectId != 0 ) effectNode = effectImporter->findMayaEffect ( *effectId );
            if ( effectNode != 0 )
            {
                MayaDM::Lambert* lambertNode = ( MayaDM::Lambert* ) effectNode;

                // connectAttr "blinn1.outColor" "blinn1SG.surfaceShader";
                connectAttr ( file, lambertNode->getOutColor (), shadingEngine.getSurfaceShader () );

                // connectAttr "blinn1.message" "materialInfo2.material";
                connectAttr ( file, lambertNode->getMessage (), materialInfo.getMaterial () );
            }

            ++shaderDataIter;
        }
    }

    // --------------------------
    void MaterialImporter::connectShadingEngineObjectGroups ()
    {
        // ".instObjGroups"; // for every geometry instance
        // ".instObjGroups[x].objectGroups"; // for every mesh primitive

        // Get the current maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get a pointer to the geometry importer.
        GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();

        // Find all geometry mesh primitives, which use this effect and create the connections.
        GeometryBindingMaterialInfosMap::iterator geometryBindingIter = mGeometryBindingMaterialInfosMap.begin ();
        while ( geometryBindingIter != mGeometryBindingMaterialInfosMap.end () )
        {
            const GeometryBinding& geometryBinding = geometryBindingIter->first;
            const COLLADAFW::UniqueId& geometryId = geometryBinding.getGeometryId ();
            const COLLADAFW::UniqueId& transformId = geometryBinding.getTransformId ();

            // Get the list of materialIds for the current shading binding.
            const std::vector<MaterialInformation>& materialInfosList = geometryBindingIter->second;
            size_t numMaterialInfos = materialInfosList.size ();

            for ( size_t primitiveIndex=0; primitiveIndex<numMaterialInfos; ++primitiveIndex )
            {
                const MaterialInformation& materialInfo = materialInfosList [primitiveIndex];
                const COLLADAFW::MaterialId& shadingEngineId = materialInfo.getShadingEngineId ();
                const COLLADAFW::UniqueId& materialId = materialInfo.getMaterialId ();

                // Get the groupId objects of the current geometry in the transform.
                // The number of groupId objects depends on the number of geometry instances and 
                // on the number of primitive elements in the geometry.
                std::vector<GroupInfo>* shadingBindingGroups;
                shadingBindingGroups = geometryImporter->findShadingBindingGroups ( geometryId, transformId, shadingEngineId );
                // There has NOT to be some shading groups!
                if ( shadingBindingGroups == 0 ) continue;
                size_t numPrimitiveElements = shadingBindingGroups->size ();

                // Get the maya shading engine object.
                ShadingData* shaderData = findShaderData ( materialId );
                if ( shaderData == 0 )  {
                    MGlobal::displayError ( "No shader data exist!" );
                    std::cerr << "No shader data exist!" << endl;
                    return;
                }
                const MayaDM::ShadingEngine& shadingEngine = shaderData->getShadingEngine ();

                // If there are some object groups, we have to connect them with the shading engines.
                for ( size_t j=0; j<numPrimitiveElements; ++j )
                {
                    // Get the maya groupId object.
                    const GroupInfo& groupInfo = (*shadingBindingGroups) [j];
                    const MayaDM::GroupId& groupIdObject = groupInfo.getGroupId ();

                    // connectAttr "groupId1.message" "Material1SG.groupNodes" -nextAvailable;
                    connectNextAttr ( file, groupIdObject.getMessage (), shadingEngine.getGroupNodes () );
                }
            }

            ++geometryBindingIter;
        }
    }

    // --------------------------
    void MaterialImporter::connectGeometries ()
    {
        // ".instObjGroups"; // for every geometry instance
        // ".instObjGroups[x].objectGroups"; // for every mesh primitive

        // For every geometry instance
        //  For every transform instance
        //      For every mesh primitive 
        //          connectAttr (...)

        // Get the current maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get a pointer to the geometry importer.
        GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();

        size_t geometryInstance = 0;

        // Find all geometry mesh primitives, which use this effect and create the connections.
        GeometryBindingMaterialInfosMap::iterator geometryBindingIter = mGeometryBindingMaterialInfosMap.begin ();
        while ( geometryBindingIter != mGeometryBindingMaterialInfosMap.end () )
        {
            const GeometryBinding& geometryBinding = geometryBindingIter->first;
            const COLLADAFW::UniqueId& geometryId = geometryBinding.getGeometryId ();
            const COLLADAFW::UniqueId& transformId = geometryBinding.getTransformId ();

            // Get the list of materialIds for the current geometry binding.
            // There has to be a material info element for every mesh primitive element.
            const std::vector<MaterialInformation>& materialInfosList = geometryBindingIter->second;
            size_t numMaterialInfos = materialInfosList.size ();

            // Get all pathes of the current transformation.
            std::vector<String> transformPathes;
            visualSceneImporter->getTransformPathes ( transformPathes, transformId );

            // Get the number of transform node instances.
            size_t numTransformInstances = transformPathes.size ();
            for ( size_t transformInstance=0; transformInstance<numTransformInstances; ++transformInstance )
            {
                for ( size_t materialIndex=0; materialIndex<numMaterialInfos; ++materialIndex )
                {
                    const MaterialInformation& materialInfo = materialInfosList [materialIndex];
                    const COLLADAFW::MaterialId& shadingEngineId = materialInfo.getShadingEngineId ();
                    const COLLADAFW::UniqueId& materialId = materialInfo.getMaterialId ();
                
                    // Get the maya shading engine object.
                    ShadingData* shaderData = findShaderData ( materialId );
                    if ( shaderData == 0 )  {
                        MGlobal::displayError ( "No shader data exist!" );
                        std::cerr << "No shader data exist!" << endl;
                        continue;
                    }
                    const MayaDM::ShadingEngine& shadingEngine = shaderData->getShadingEngine ();

                    // Get the maya mesh object.
                    MayaDM::Mesh* mesh = geometryImporter->findMayaDMMeshNode ( geometryId );
                    if ( mesh == 0 )    {
                        MGlobal::displayError ( "Mesh doesn't exist! ");
                        return;
                    }
                    MayaNode* mayaMeshNode = geometryImporter->findMayaMeshNode ( geometryId );

                    // Set the current transformation path.
                    String meshName = mesh->getName ();
                    String meshPath = transformPathes [transformInstance] + "|" + meshName;
                    mesh->setName ( meshPath );

                    //std::vector<GroupInfo>* groupInfos = geometryImporter->findShadingBindingGroups ( geometryId, transformId, shadingEngineId );
                    //size_t numPrimitiveElements = groupInfos->size ();
                    //size_t numPrimitiveElements = shadingBindingGroups->size ();
                    //size_t numPrimitiveElements = numMaterialInfos;

                    // We just need connections to objectGroups, if we have multiple geometry 
                    // instances or multiple mesh primitive elements.
                    size_t numPrimitiveElements = geometryImporter->findPrimitivesCount ( geometryId );
                    if ( numPrimitiveElements > 1 )
                    //if ( numPrimitiveElements > 1 || numTransformInstances > 1 )
                    //if ( geometryImporter->getShadingBindingGroupMap ().size () > 0 )
                    {
                        // Do the connection to this shading engine for every primitive element, 
                        // which use this shading engine.
                        std::vector<size_t>* primitiveIndices = geometryImporter->getShadingEnginePrimitiveIndices ( geometryId, shadingEngineId );
                        if ( primitiveIndices != 0 )
                        {
                            for ( size_t i=0; i<primitiveIndices->size (); ++i )
                            {
                                const size_t primitiveIndex = (*primitiveIndices) [i];

                                // connectAttr "|pCube2|pCubeShape1.instObjGroups" "blinn1SG.dagSetMembers" -nextAvailable;
                                connectNextAttr ( file, mesh->getObjectGroups ( primitiveIndex ), shadingEngine.getDagSetMembers () );

                                // connectAttr "lambert2SG.memberWireframeColor" "|pCube1|pCubeShape1.instObjGroups.objectGroups[0].objectGrpColor";
                                connectAttr ( file, shadingEngine.getMemberWireframeColor (), mesh->getObjectGrpColor ( primitiveIndex ) );
                            }
                        }
                    }
                    else
                    {
                        // connectAttr "|pCube1|pCubeShape1.instObjGroups" "lambert2SG.dagSetMembers" -nextAvailable;
                        connectNextAttr ( file, mesh->getInstObjGroups (), shadingEngine.getDagSetMembers () );
                    }

                    // Get the groupId objects of the current geometry in the transform.
                    // The number of groupId objects depends on the number of geometry instances 
                    // from instance node and on the number of primitive elements in the geometry.
                    std::vector<GroupInfo>* shadingBindingGroups;
                    shadingBindingGroups = geometryImporter->findShadingBindingGroups ( geometryId, transformId, shadingEngineId );

                    // If there are some object groups, we have to connect them with the geometries.
                    if ( shadingBindingGroups != 0 ) 
                    {
                        for ( size_t i=0; i<shadingBindingGroups->size (); ++i )
                        {
                            const GroupInfo& groupInfo = (*shadingBindingGroups) [i];

                            const MayaDM::GroupId& groupId = groupInfo.getGroupId ();
                            const COLLADAFW::MaterialId& currentShadingEngineId = groupInfo.getShadingEngineId ();
                            const size_t transformInstanceIndex = groupInfo.getTransformInstanceIndex ();
                            const size_t primitiveIndex = groupInfo.getPrimitiveIndex ();

                            if ( transformInstanceIndex == transformInstance )
                            {
                                // connectAttr "groupId1.groupId" "|pCube1|pCubeShape1.instObjGroups.objectGroups[0].objectGroupId";
                                connectAttr ( file, groupId.getGroupId (), mesh->getObjectGroupId ( primitiveIndex ) );
                            }
                        }
                    }

                    // Reset the name of the mesh object.
                    mesh->setName ( meshName );
                }
                ++geometryInstance;
            }
            ++ geometryBindingIter;
        }
    }

//     // --------------------------
//     void MaterialImporter::connectGeometryGroups ()
//     {
//         // Get the current maya ascii file.
//         FILE* file = getDocumentImporter ()->getFile ();
// 
//         // If there are some object groups, we have to connect them with the geometries.
//         GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();
// 
//         // The geometry instance index counter.
//         size_t geometryInstanceIndex = 0;
// 
//         // Iterate over the groupId shading bindings.
//         const ShadingBindingGroupInfoMap shadingBindingGroupsMap = geometryImporter->getShadingBindingGroupMap ();
//         ShadingBindingGroupInfoMap::const_iterator shadingBindingIter = shadingBindingGroupsMap.begin ();
//         while ( shadingBindingIter != shadingBindingGroupsMap.end () )
//         {
//             const ShadingBinding& shadingBinding = shadingBindingIter->first;
//             const COLLADAFW::UniqueId& geometryId = shadingBinding.getGeometryId ();
//             const COLLADAFW::UniqueId& transformId = shadingBinding.getTransformId ();
//             const COLLADAFW::MaterialId& materialId = shadingBinding.getShadingEngineId ();
// 
//             // Get the maya mesh node
//             MayaDM::Mesh* mesh = geometryImporter->findMayaDMMeshNode ( geometryId );
// 
//             // Get the current groupId object.
//             const std::vector<GroupInfo>& groupInfosList = shadingBindingIter->second;
//             size_t numGroups = groupInfosList.size ();
// 
//             // Count the primitive elements.
//             size_t primitiveIndex = 0;
// 
//             // Iterate over the groups (for every primitive element)
//             for ( size_t i=0; i<numGroups; ++i )
//             {
//                 const GroupInfo& groupInfo = groupInfosList [i];
//                 const MayaDM::GroupId& groupId = groupInfo.getGroupId ();
// 
//                 // connectAttr "groupId1.groupId" "|pCube1|pCubeShape1.instObjGroups.objectGroups[0].objectGroupId";
//                 //connectAttr ( file, groupId.getGroupId (), mesh->getObjectGroupId ( geometryInstanceIndex, primitiveIndex ) );
//                 ++primitiveIndex;
//             }
// 
//             ++shadingBindingIter;
//             ++geometryInstanceIndex;
//         }
//     }

    // --------------------------
    void MaterialImporter::connectDefaultShaderList ()
    {
        // Get the current maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        EffectImporter* effectImporter = getDocumentImporter ()->getEffectImporter ();
        const EffectImporter::UniqueIdLambertMap& effectMap = effectImporter->getMayaEffectMap ();

        MayaDM::DefaultShaderList defaultShaderList ( file, DEFAULT_SHADER_LIST, "", false );

        EffectImporter::UniqueIdLambertMap::const_iterator it = effectMap.begin ();
        while ( it != effectMap.end () )
        {
            MayaDM::DependNode* dependNode = it->second;

            // connectAttr "lambert2.message" ":defaultShaderList1.shaders" -nextAvailable;
            connectNextAttr ( file, dependNode->getMessage (), defaultShaderList.getShaders () );

            ++it;
        }
    }

}