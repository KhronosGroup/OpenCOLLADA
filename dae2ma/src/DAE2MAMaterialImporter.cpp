/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MAMaterialImporter.h"
#include "DAE2MAEffectImporter.h"
#include "DAE2MAGeometryImporter.h"
#include "DAE2MAVisualSceneImporter.h"
#include "DAE2MAControllerImporter.h"

#include "MayaDMMesh.h"
#include "MayaDMLambert.h"
#include "MayaDMGroupId.h"
#include "MayaDMDefaultShaderList.h"
#include "MayaDMCommands.h"
#include "MayaDMPartition.h"

#include "COLLADAFWMaterial.h"


namespace DAE2MA
{

    const String MaterialImporter::MATERIAL_NAME = "material";
    const String MaterialImporter::SHADING_ENGINE_NAME = "shadingEngine";
    const String MaterialImporter::MATERIAL_INFO_NAME = "materialInfo";
    const String MaterialImporter::DEFAULT_SHADER_LIST = ":defaultShaderList1";
    const String MaterialImporter::DEFAULT_RENDER_PARTITION = ":renderPartition";
    const String MaterialImporter::INITIAL_SHADING_ENGINE_NAME = "initialShadingGroup";
    const String MaterialImporter::INITIAL_MATERIAL_INFO_NAME = "initialMaterialInfo";
    const String MaterialImporter::INITIAL_MATERIAL_NAME = "lambert1";
    const String MaterialImporter::ATTR_SHADERS = "shaders";
    const String MaterialImporter::UV_CHOOSER_NAME = "uvChooser";


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
        mShaderDataMap.clear ();

        UniqueIdMayaNodeMap::iterator it = mMayaMaterialNodesMap.begin ();
        while ( it != mMayaMaterialNodesMap.end () )
        {
            MayaNode* mayaNode = it->second;
            delete mayaNode;
            ++it;
        }
        mMayaMaterialNodesMap.clear ();
    }

    // --------------------------
    bool MaterialImporter::importMaterial ( const COLLADAFW::Material* material )
    {
        // Check if the current material is already imported.
        const COLLADAFW::UniqueId& materialId = material->getUniqueId ();
        if ( findMayaMaterialNode ( materialId ) != 0 ) return false;

        // Get the material name.
        String materialName ( material->getName () );
        if ( materialName.empty () ) materialName = MATERIAL_NAME;
        materialName = DocumentImporter::frameworkNameToMayaName ( materialName );
        const ExtraDataCallbackHandler& callbackHandler = getDocumentImporter ()->getMayaIdCallbackHandler ();
        String originalMayaId = getOriginalMayaId ( callbackHandler, materialId, COLLADASaxFWL15::HASH_ELEMENT_MATERIAL );
        if ( !originalMayaId.empty () ) materialName = originalMayaId;
        materialName = generateUniqueDependNodeName ( materialName );

//         // TODO Doesn't work on file import, just on file open!
//         // If the name of the material is "lambert1", we want to import a shared node!
//         bool returnConverted = true;
//         if ( COLLADABU::Utils::equals ( materialName, INITIAL_MATERIAL_NAME ) ) returnConverted = false;
//         materialName = generateUniqueDependNodeName ( materialName, returnConverted );
        
        // Add the original id attribute of the material.
        String colladaMaterialId = material->getOriginalId ();
        mMaterialIdOriginalColladaId [ materialId ] = colladaMaterialId;

        // Create a material node with the name and store it in a map.
        MayaNode* mayaMaterialNode = new MayaNode ( materialId, materialName );
        mMayaMaterialNodesMap [materialId] = mayaMaterialNode;

        // Store the effect id of the current material id.
        const COLLADAFW::UniqueId& effectId = material->getInstantiatedEffect ();
        mMaterialIdEffectIdMap [materialId] = effectId;

        // Push the material id in the list of materials for this effect.
        // Store the data also in the other direction, for faster search.
        EffectImporter* effectImporter = getDocumentImporter ()->getEffectImporter ();
        effectImporter->assignMaterial ( effectId, materialId );

        return true;
    }

    // --------------------------------------------
    void MaterialImporter::createUVChoosers ()
    {
        // An uv-chooser will be generated, if
        // 1.) a material uses a texture and
        // 2.) the material is used by one or more primitive element of one or more geometries and
        // 3.) the primitive element of the geometry has more than one uv-set and
        // 4.) the scenegraph uses this texture with an uv-set-index, which is not the first one.

        // We need one uv-chooser for every texture in a material, if the points above are right. 
        // If there exist multiple instances of the geometry, we can't change the uv-mapping in maya!
        // If the material is referenced for multiple times (multiple geometries use the material),
        // we use for every reference just the next index of the material's texture's uv-chooser's uv-set.

        GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();
        EffectImporter* effectImporter = getDocumentImporter ()->getEffectImporter ();

        std::map<COLLADAFW::UniqueId, std::vector<BindingInputSet> >::iterator it = mBindingTexCoordInputSetsMap.begin ();
        while ( it != mBindingTexCoordInputSetsMap.end () )
        {
            const COLLADAFW::UniqueId& materialId = it->first;
            std::vector<BindingInputSet>& bindVertexInputSets = it->second;
            for ( size_t i=0; i<bindVertexInputSets.size (); ++i )
            {
                BindingInputSet& bindVertexInputSet = bindVertexInputSets [i];

                // Get the uv-sets of the geometry.
                const COLLADAFW::UniqueId& sourceId = bindVertexInputSet.getInstanciatedObjectId ();
                const COLLADAFW::UniqueId& transformId = bindVertexInputSet.getTransformNodeId ();
                const COLLADAFW::UniqueId* controllerId = bindVertexInputSet.getControllerId ();

                // 1.) We just have to create an uv-chooser, if we have more than one uv-set in the current geometry.
                const COLLADAFW::UniqueId* geometryId = geometryImporter->findGeometryId ( sourceId, transformId, controllerId );
                if ( geometryId == 0 )
                {
                    std::cerr << "No geometry for the current source id!" << std::endl;
                    return;
                }               
                bindVertexInputSet.setGeometryId ( *geometryId );

                // Get the material and the shading engine.
                const COLLADAFW::UniqueId& materialId = bindVertexInputSet.getMaterialId ();
                const COLLADAFW::MaterialId& shadingEngineId = bindVertexInputSet.getShadingEngineId ();

                // Get the texture coordinates input sets for the current geometry 
                // (one primitive input set for every primitive element in the geometry).
                const std::vector<GeometryImporter::PrimitiveInputSet>* texCoordInputSets = 0;
                texCoordInputSets = geometryImporter->findTexCoordInputSets ( *geometryId );
                if ( texCoordInputSets == 0 ) continue;

                // Search the primitive input elements, which use the current shading engine.
                for ( size_t j=0; j<texCoordInputSets->size (); ++j )
                {
                    //const GeometryImporter::PrimitiveInputSet texCoordInputSet = geometryImporter->findTexCoordInputSet ( geometryId, primitiveIndex, inputSetIndex );
                    const GeometryImporter::PrimitiveInputSet texCoordInputSet = (*texCoordInputSets) [j];
                    const COLLADAFW::MaterialId& currentShadingEngineId = texCoordInputSet.getShadingEngineId ();
                    if ( shadingEngineId == currentShadingEngineId )
                    {
                        // Check if we have the right inputSet index.
                        const size_t inputSetIndex = bindVertexInputSet.getInputSetIndex ();
                        const size_t currentInputSetIndex = texCoordInputSet.getInputSetIndex ();
                        if ( inputSetIndex != currentInputSetIndex ) continue;

                        // Get the physical index of the inputSetIndex element.
                        const String currentUvSetName = texCoordInputSet.getInputSetName ();
                        if ( geometryImporter->findGeometryUvSetIndex ( *geometryId, currentUvSetName ) == 0 ) continue;

                        const size_t physicalIndex = texCoordInputSet.getPhysicalIndex ();
                        bindVertexInputSet.setPhysicalIndex ( physicalIndex );
                        const COLLADAFW::TextureMapId& textureMapId = bindVertexInputSet.getTextureMapId ();

                        // Get the texture infos from the material and create one uv-chooser for every texture.
                        // Just if there exist a geometry, which use this material and has more than one 
                        // uv-set and uses another uv-set than the first one!
                        const COLLADAFW::UniqueId* effectId = findEffectId ( materialId );

                        // Get the texture infos of the current effect with the textureMapId.
                        const EffectImporter::TextureInfo* textureInfo = effectImporter->findTextureInfo ( *effectId, textureMapId );
                        if ( textureInfo == 0 ) continue;

                        // Create the necessary uv choosers.
                        const MayaDM::UvChooser* uvChooser = findUvChooser ( materialId, textureMapId );
                        if ( uvChooser == 0 ) 
                        {
                            // Get the maya ascii file.
                            FILE* file = getDocumentImporter ()->getFile ();

                            // Generate a valid unique name
                            String uvChooserName = UV_CHOOSER_NAME;
                            uvChooserName = generateUniqueDependNodeName ( uvChooserName );

                            // Create an uv chooser for every primitive element which bounds a texture.
                            // createNode uvChooser -n "uvChooser1";
                            MayaDM::UvChooser chooser ( file, uvChooserName );
                            bindVertexInputSet.setUvChooser ( chooser );
                        }
                        else bindVertexInputSet.setUvChooser ( *uvChooser );
                    }
                }
            }
            ++it;
        }
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
    const String& MaterialImporter::findOriginalColladaId ( const COLLADAFW::UniqueId& materialId )
    {
        const UniqueIdStringMap::const_iterator it = mMaterialIdOriginalColladaId.find ( materialId );
        if ( it != mMaterialIdOriginalColladaId.end () )
        {
            return it->second;
        }
        return EMPTY_STRING;
    }

    // --------------------------------------------
    const std::vector<MaterialImporter::BindingInputSet>* MaterialImporter::findBindingTexCoordInputSets ( 
        const COLLADAFW::UniqueId& materialId )
    {
        std::map<COLLADAFW::UniqueId, std::vector<BindingInputSet> >::const_iterator it = mBindingTexCoordInputSetsMap.find ( materialId );
        if ( it != mBindingTexCoordInputSetsMap.end () )
        {
            return &it->second;
        }
        return 0;
    }

    // --------------------------------------------
    const MaterialImporter::BindingInputSet* MaterialImporter::findBindingTexCoordInputSet ( 
        const COLLADAFW::UniqueId& sourceId,
        const COLLADAFW::UniqueId& materialId, 
        const size_t inputSetIndex )
    {
        const std::vector<BindingInputSet>* bindingInputSets = findBindingTexCoordInputSets ( materialId );
        if ( bindingInputSets == 0 ) return 0;

        std::vector<BindingInputSet>::const_iterator it = bindingInputSets->begin ();
        while ( it != bindingInputSets->end () )
        {
            const BindingInputSet& bindingInputSet = *it;
            if ( bindingInputSet.getInstanciatedObjectId () == sourceId && 
                 bindingInputSet.getInputSetIndex () == inputSetIndex )
                return &bindingInputSet;
            ++it;
        }
        return 0;
    }

    // --------------------------------------------
    const MayaDM::UvChooser* MaterialImporter::findUvChooser ( 
        const COLLADAFW::UniqueId& materialId, 
        const COLLADAFW::TextureMapId& textureMapId )
    {
        std::map<COLLADAFW::UniqueId, std::vector<BindingInputSet> >::const_iterator it = mBindingTexCoordInputSetsMap.begin ();
        while ( it != mBindingTexCoordInputSetsMap.end () )
        {
            const std::vector<BindingInputSet>& bindingInputSets = it->second;
            std::vector<BindingInputSet>::const_iterator it2 = bindingInputSets.begin ();
            while ( it2 != bindingInputSets.end () )
            {
                const BindingInputSet& bindingInputSet = *it2;
                if ( bindingInputSet.getMaterialId () == materialId && 
                     bindingInputSet.getTextureMapId () == textureMapId )
                {
                    const MayaDM::UvChooser* uvChooser = bindingInputSet.getUvChooser ();
                    return uvChooser;
                }
                ++it2;
            }
            ++it;
        }

        return 0;
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

        // Connect the uv-set mapping.
        connectUVChooser ();
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

            // Create the default object (not in the maya file!).
            MayaDM::Partition defaultRenderPartition ( file, DEFAULT_RENDER_PARTITION, EMPTY_STRING, false, false );
            // References to the partition nodes this set is a member of. 
            // connectAttr "ShadingEngine_1.pa" ":renderPartition.st" -na;
            connectNextAttr ( file, shadingEngine.getPartition (), defaultRenderPartition.getSets () );

            // Get the effect
            MayaDM::DependNode* effectNode = 0;
            EffectImporter* effectImporter = getDocumentImporter ()->getEffectImporter ();
            const COLLADAFW::UniqueId* effectId = findEffectId ( materialId );
            if ( effectId != 0 ) 
            {
                const MayaEffectList* mayaEffectList = effectImporter->findMayaEffects ( *effectId );
                if ( mayaEffectList != 0 )
                {
                    for ( size_t i=0; i<mayaEffectList->size (); ++i )
                    {
                        MayaDM::Lambert* effectNode = (*mayaEffectList) [i];

                        // connectAttr "blinn1.outColor" "blinn1SG.surfaceShader";
                        connectAttr ( file, effectNode->getOutColor (), shadingEngine.getSurfaceShader () );

                        // connectAttr "blinn1.message" "materialInfo2.material";
                        connectAttr ( file, effectNode->getMessage (), materialInfo.getMaterial () );
                    }
                }
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
        GeometryMaterialBindingsMap::iterator geometryBindingIter = mGeometryMaterialBindingsMap.begin ();
        while ( geometryBindingIter != mGeometryMaterialBindingsMap.end () )
        {
            const GeometryBinding& geometryBinding = geometryBindingIter->first;
            const COLLADAFW::UniqueId& transformId = geometryBinding.getTransformId ();
            const COLLADAFW::UniqueId* controllerId = geometryBinding.getControllerId ();

            // Get the sourceId. Is either a geometryId or a controllerId.
            const COLLADAFW::UniqueId& sourceId = geometryBinding.getSourceId ();
            const COLLADAFW::UniqueId* geometryId = geometryImporter->findGeometryId ( sourceId, transformId, controllerId );
            if ( geometryId == 0 )
            {
                ++geometryBindingIter;
                continue;
            }

            // Go through the bound materials. One material binding for every primitive element.
            const COLLADAFW::MaterialBindingArray* materialBindingsArray = geometryBindingIter->second;
            size_t numMaterialBindings = materialBindingsArray->getCount ();
            for ( size_t primitiveIndex=0; primitiveIndex<numMaterialBindings; ++primitiveIndex )
            {
                // Get the current material binding.
                const COLLADAFW::MaterialBinding& materialBinding = (*materialBindingsArray) [primitiveIndex];

                // Get the bind_vertex_input element.
                const COLLADAFW::TextureCoordinateBindingArray& texCoordBindingArray = materialBinding.getTextureCoordinateBindingArray ();
                size_t numTexCoordBindings = texCoordBindingArray.getCount ();
                for ( size_t j=0; j<numTexCoordBindings; ++j )
                {
                    const COLLADAFW::TextureCoordinateBinding& texCoordBinding = texCoordBindingArray [j];
                    const COLLADAFW::TextureMapId textureMapId = texCoordBinding.getTextureMapId ();
                    const size_t textureMapIndex = texCoordBinding.getSetIndex ();
                }

                // Get the material id.
                const COLLADAFW::UniqueId& materialId = materialBinding.getReferencedMaterial ();

                // Get the shading engine id. This id is unique for one geometry.
                const COLLADAFW::MaterialId shadingEngineId = materialBinding.getMaterialId ();

                // Get the groupId objects of the current geometry in the transform.
                // The number of groupId objects depends on the number of geometry instances and 
                // on the number of primitive elements in the geometry.
                std::vector<GroupInfo>* shadingBindingGroups;
                shadingBindingGroups = geometryImporter->findShadingBindingGroups ( *geometryId, transformId, shadingEngineId );
                // There has NOT to be some shading groups!
                if ( shadingBindingGroups == 0 ) continue;
                size_t numPrimitiveElements = shadingBindingGroups->size ();

                // Get the maya shading engine object.
                ShadingData* shaderData = findShaderData ( materialId );
                if ( shaderData == 0 )  {
                    std::cerr << "No shader data exist!" << std::endl;
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
        ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();

        // If we have one or more controllers, the material groupIds have to 
        // connect to the geometry object groups on a later index position.
        size_t objectGroupsInitialIndex = 0;
        size_t geometryInstance = 0;

        // Find all geometry mesh primitives, which use this effect and create the connections.
        GeometryMaterialBindingsMap::iterator geometryBindingIter = mGeometryMaterialBindingsMap.begin ();
        while ( geometryBindingIter != mGeometryMaterialBindingsMap.end () )
        {
            const GeometryBinding& geometryBinding = geometryBindingIter->first;
            const COLLADAFW::UniqueId& sourceId = geometryBinding.getSourceId ();
            const COLLADAFW::UniqueId& transformId = geometryBinding.getTransformId ();
            const COLLADAFW::UniqueId* controllerId = geometryBinding.getControllerId ();

            // Handle controller
            COLLADAFW::UniqueId geometryId;
            GeometryImporter::MeshControllerData* meshControllerData = 0;
            if ( controllerId )
            {
                // Get the geometryId of the current controller element.
                meshControllerData = geometryImporter->findMeshControllerDataByControllerAndTransformId ( sourceId, transformId );
                if ( meshControllerData == 0 )
                {
                    std::cerr << "No meshControllerData exist for the current geometry and transform!" << std::endl;
                    ++geometryBindingIter;
                    continue;
                }
                geometryId = meshControllerData->getGeometryId ();

                // If we have one or more controllers, the material groupIds have to 
                // connect to the geometry object groups on a later index position.
                // But just, if the current controller is the first instance and not an 
                if ( meshControllerData->getIsInitialInstance () )
                    objectGroupsInitialIndex = controllerImporter->findObjectGroupsInitialIndex ( *controllerId );
                else objectGroupsInitialIndex = 0;
            }
            else 
            {
                geometryId = sourceId;
            }

            // Get for every primitive element the shading engine to bind the material.
            const std::vector<GeometryImporter::GeometryShadingEngine>* geometryShadingEngines = geometryImporter->findGeomtryShadingEngines ( geometryId );
            if ( geometryShadingEngines == 0 )
            {
                std::cerr << "No shading engine for the current geometry!" << std::endl;
                ++geometryBindingIter;
                continue;
            }

            // Go through the bound materials. One material binding for every primitive element.
            const COLLADAFW::MaterialBindingArray* materialBindingsArray = geometryBindingIter->second;
            size_t numMaterialBindings = materialBindingsArray->getCount ();

            // Get all pathes of the current transformation.
            std::vector<String> transformPathes;
            visualSceneImporter->getTransformPathes ( transformPathes, transformId );

            // Get the number of transform node instances.
            size_t numTransformInstances = transformPathes.size ();
            for ( size_t transformInstance=0; transformInstance<numTransformInstances; ++transformInstance )
            {
                // There can be some bind_material elements in the scene graph, where no primitive 
                // element in the geometry exist to bind the material to. Then we don't need a 
                // geometry binding connection.

                // To avoid dublicate assignements, store the connected groups in a map.
                std::map<String, size_t> connectedGroupsMap;

                size_t numPrimitiveElements = geometryShadingEngines->size ();
                for ( size_t i=0; i<numPrimitiveElements; ++i )
                {
                    const GeometryImporter::GeometryShadingEngine& geometryShadingEngine = (*geometryShadingEngines) [i];
                    size_t materialIndex = geometryShadingEngine.mPrimitiveIndex;
                    const COLLADAFW::MaterialId& shadingEngineId = geometryShadingEngine.mShadingEngineId;

                    // Get the material info with the current shading engine.
                    const COLLADAFW::MaterialBinding* materialBinding = 0;
                    for ( size_t m=0; m<numMaterialBindings; ++m )
                    {
                        if ( shadingEngineId == (*materialBindingsArray) [m].getMaterialId () )
                            materialBinding = &(*materialBindingsArray) [m];
                    }
                    if ( materialBinding == 0 )
                    {
                        std::cerr << "No material info for the current shading engine!" << std::endl;
                        continue;
                    }
                    const COLLADAFW::UniqueId& materialId = materialBinding->getReferencedMaterial ();

                    // Get the maya shading engine object.
                    ShadingData* shaderData = findShaderData ( materialId );
                    if ( shaderData == 0 )  {
                        std::cerr << "No shader data exist!" << std::endl;
                        continue;
                    }
                    const MayaDM::ShadingEngine& shadingEngine = shaderData->getShadingEngine ();

                    // Get the maya mesh object.
                    MayaDM::Mesh* mesh = 0;
                    if ( meshControllerData )
                    {
                        // Use the controller mesh node.
                        mesh = &meshControllerData->getControllerMeshNode ();
                    }
                    else 
                    {
                        // Get the mesh from the normal mayaDMMeshNode list.
                        mesh = geometryImporter->findMayaDMMeshNode ( geometryId );
                    }
                    if ( mesh == 0 )    
                    {
                        std::cerr << "Mesh doesn't exist!" << std::endl;
                        return;
                    }

                    // Set the current transformation path.
                    String meshName = mesh->getName ();
                    if ( numTransformInstances >= 1 )
                    {
                        // Get the name with path of the current transformation.
                        size_t pos = meshName.find_last_of ( "|" );
                        String name = meshName.substr ( pos+1 );
                        String meshPath = transformPathes [transformInstance] + "|" + name;
                        mesh->setName ( meshPath );
                    }

                    // We just need connections to objectGroups, if we have multiple geometry 
                    // instances or multiple mesh primitive elements.
                    if ( numPrimitiveElements > 1 )
                    {
                        // connectAttr "|pCube2|pCubeShape1.instObjGroups" "blinn1SG.dagSetMembers" -nextAvailable;
                        connectNextAttr ( file, mesh->getObjectGroups ( objectGroupsInitialIndex+materialIndex ), shadingEngine.getDagSetMembers () );

                        // connectAttr "lambert2SG.memberWireframeColor" "|pCube1|pCubeShape1.instObjGroups.objectGroups[0].objectGrpColor";
                        connectAttr ( file, shadingEngine.getMemberWireframeColor (), mesh->getObjectGrpColor ( objectGroupsInitialIndex+materialIndex ) );
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
                            const size_t transformInstanceIndex = groupInfo.getTransformInstanceIndex ();
                            if ( transformInstanceIndex == transformInstance )
                            {
                                // Check if the connection already exist.
                                std::map<String, size_t>::const_iterator it = connectedGroupsMap.find ( groupId.getName () );
                                if ( it == connectedGroupsMap.end () )
                                {
                                    // connectAttr "groupId1.groupId" "|pCube1|pCubeShape1.instObjGroups.objectGroups[0].objectGroupId";
                                    const size_t primitiveIndex = groupInfo.getPrimitiveIndex ();
                                    const size_t index = objectGroupsInitialIndex+primitiveIndex;
                                    connectAttr ( file, groupId.getGroupId (), mesh->getObjectGroupId ( index ) );

                                    // To avoid dublicate assignements, store the connected groups 
                                    // with the geometry primitive index value in a map.
                                    connectedGroupsMap [ groupId.getName () ] = (unsigned int)index;
                                }
                            }
                        }
                    }

                    // Reset the name of the mesh object.
                    if ( numTransformInstances >= 1 )
                    {
                        mesh->setName ( meshName );
                    }
                }
                ++geometryInstance;
            }
            ++geometryBindingIter;
        }
    }

    // --------------------------
    void MaterialImporter::connectDefaultShaderList ()
    {
        // Get the current maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        EffectImporter* effectImporter = getDocumentImporter ()->getEffectImporter ();
        const EffectImporter::UniqueIdMayaEffectsMap& effectMap = effectImporter->getMaterialIdMayaEffectMap ();

        // Create the default object (not in the maya file!).
        MayaDM::DefaultShaderList defaultShaderList ( file, DEFAULT_SHADER_LIST, EMPTY_STRING, false, false );

        EffectImporter::UniqueIdMayaEffectsMap::const_iterator it = effectMap.begin ();
        while ( it != effectMap.end () )
        {
            const COLLADAFW::UniqueId& effectId = it->first;
            const MayaEffectList* mayaEffectList = effectImporter->findMayaEffects ( effectId );
            if ( mayaEffectList != 0 )
            {
                for ( size_t i=0; i<mayaEffectList->size (); ++i )
                {
                    MayaDM::Lambert* effectNode = (*mayaEffectList) [i];

                    // connectAttr "lambert2.message" ":defaultShaderList1.shaders" -nextAvailable;
                    connectNextAttr ( file, effectNode->getMessage (), defaultShaderList.getShaders () );
                }
            }

            ++it;
        }
    }

    // --------------------------
    void MaterialImporter::connectUVChooser ()
    {
        // Get the current maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get a pointer to the geometry importer.
        GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();
        MaterialImporter* materialImporter = getDocumentImporter ()->getMaterialImporter ();
        EffectImporter* effectImporter = getDocumentImporter ()->getEffectImporter ();

        std::map<COLLADAFW::UniqueId, std::vector<BindingInputSet> >::iterator it = mBindingTexCoordInputSetsMap.begin ();
        while ( it != mBindingTexCoordInputSetsMap.end () )
        {
            const COLLADAFW::UniqueId& materialId = it->first;
            std::vector<BindingInputSet>& bindVertexInputSets = it->second;
            for ( size_t i=0; i<bindVertexInputSets.size (); ++i )
            {
                BindingInputSet& bindVertexInputSet = bindVertexInputSets [i];

                // Get the uv-sets of the geometry.
                const COLLADAFW::UniqueId& sourceId = bindVertexInputSet.getInstanciatedObjectId ();
                const COLLADAFW::UniqueId& transformId = bindVertexInputSet.getTransformNodeId ();
                const COLLADAFW::UniqueId* controllerId = bindVertexInputSet.getControllerId ();

                // Get the geometry id.
                COLLADAFW::UniqueId geometryId = bindVertexInputSet.getGeometryId ();
                GeometryImporter::MeshControllerData* meshControllerData = 0;
                if ( controllerId )
                {
                    // Get the geometryId of the current controller element.
                    meshControllerData = geometryImporter->findMeshControllerDataByControllerAndTransformId ( sourceId, transformId );
                    if ( meshControllerData == 0 )
                    {
                        std::cerr << "No meshControllerData exist for the current geometry and transform!" << std::endl;
                        continue;
                    }
                }

                // Get the maya mesh object.
                MayaDM::Mesh* mesh = 0;
                if ( meshControllerData ) mesh = &meshControllerData->getControllerMeshNode ();
                else mesh = geometryImporter->findMayaDMMeshNode ( geometryId );
                if ( mesh == 0 )    
                {
                    std::cerr << "Mesh doesn't exist!" << std::endl;
                    continue;
                }

                // Get the material and the shading engine.
                const COLLADAFW::UniqueId& materialId = bindVertexInputSet.getMaterialId ();
                const COLLADAFW::MaterialId& shadingEngineId = bindVertexInputSet.getShadingEngineId ();
                const size_t inputSetIndex = bindVertexInputSet.getInputSetIndex ();
                const COLLADAFW::TextureMapId& textureMapId = bindVertexInputSet.getTextureMapId ();

                // Get the effectId from the current materialId to make the connections
                const COLLADAFW::UniqueId* effectId = materialImporter->findEffectId ( materialId );

                // The textur infos.
                const EffectImporter::TextureInfo* textureInfo = effectImporter->findTextureInfo ( *effectId, textureMapId );
                if ( textureInfo == 0 ) continue;

                // Get the set index of the current input element.
                const BindingInputSet* bindingInputSet = findBindingTexCoordInputSet ( sourceId, materialId, inputSetIndex );
                if ( bindingInputSet == 0 ) 
                {
                    std::cerr << "No input element for the current source and primitive element!" << std::endl;
                    continue;
                }

                // Get the uv-chooser.
                const MayaDM::UvChooser* uvChooser = bindingInputSet->getUvChooser ();
                if ( !uvChooser ) continue;

                // Binding of the chooser to the geometries which use the material.
                bool hasGeometryConnected = chooserIsGeometryConnected ( geometryId, uvChooser->getName () );;
                if ( !hasGeometryConnected )
                {
                    // Get the physical index of the inputSetIndex element.
                    const size_t physicalIndex = bindVertexInputSet.getPhysicalIndex ();

                    // Count the number of already connected geometries.
                    size_t numConnections = getNumGeometryConnections ( uvChooser->getName () );

                    // connectAttr "cube.uvst[1].uvsn" "uvChooser1.uvs[0]";
                    connectAttr ( file, mesh->getUvSetName (physicalIndex), uvChooser->getUvSets (numConnections) );

                    // Set the bound chooser in the map.
                    mChooserGeometryConnections [geometryId].push_back ( uvChooser->getName () );
                }

                // Binding of the chooser to the maya texture placement node.
                bool hasMaterialConnection = chooserIsMaterialConnected ( materialId, uvChooser->getName () );
                if ( !hasMaterialConnection )
                {
                    // connectAttr "uvChooser1.outVertexUvOne" "place2dTexture1.vertexUvOne";
                    // connectAttr "uvChooser1.outVertexUvTwo" "place2dTexture1.vertexUvTwo";
                    // connectAttr "uvChooser1.outVertexUvThree" "place2dTexture1.vertexUvThree";
                    // connectAttr "uvChooser1.outVertexCameraOne" "place2dTexture1.vertexCameraOne";
                    // connectAttr "uvChooser1.outUv" "place2dTexture1.uvCoord";
                    // connectAttr "cube.uvSet[1].uvSetName" "uvChooser1.uvSets[0]";
                    const MayaDM::Place2dTexture& texturePlacementNode = textureInfo->getTexturePlacementNode ();
                    connectAttr ( file, uvChooser->getOutVertexUvOne (), texturePlacementNode.getVertexUvOne () );
                    connectAttr ( file, uvChooser->getOutVertexUvTwo (), texturePlacementNode.getVertexUvTwo () );
                    connectAttr ( file, uvChooser->getOutVertexUvThree (), texturePlacementNode.getVertexUvThree () );
                    connectAttr ( file, uvChooser->getOutVertexCameraOne (), texturePlacementNode.getVertexCameraOne () );
                    connectAttr ( file, uvChooser->getOutUv (), texturePlacementNode.getUvCoord () );

                    // Set the bound chooser in the map.
                    mChooserMaterialConnections [materialId].push_back ( uvChooser->getName () );
                }
            }

            ++it;
        }
    }

    // --------------------------
    const bool MaterialImporter::chooserIsMaterialConnected ( 
        const COLLADAFW::UniqueId& materialId, 
        const String& uvChooserName ) const 
    {
        std::map<COLLADAFW::UniqueId, std::vector<String> >::const_iterator it = mChooserMaterialConnections.find ( materialId );
        if ( it != mChooserMaterialConnections.end () )
        {
            const std::vector<String>& boundChoosers = it->second;
            std::vector<String>::const_iterator it2 = boundChoosers.begin ();
            while ( it2 != boundChoosers.end () )
            {
                if ( COLLADABU::Utils::equals ( *it2, uvChooserName ) ) 
                    return true;
                ++it2;
            }
            ++it;
        }

        return false;
    }

    // --------------------------
    const bool MaterialImporter::chooserIsGeometryConnected ( 
        const COLLADAFW::UniqueId& geometryId, 
        const String& uvChooserName ) const 
    {
        std::map<COLLADAFW::UniqueId, std::vector<String> >::const_iterator it = mChooserGeometryConnections.find ( geometryId );
        if ( it != mChooserGeometryConnections.end () )
        {
            const std::vector<String>& boundChoosers = it->second;
            std::vector<String>::const_iterator it2 = boundChoosers.begin ();
            while ( it2 != boundChoosers.end () )
            {
                if ( COLLADABU::Utils::equals ( *it2, uvChooserName ) ) 
                    return true;
                ++it2;
            }
        }

        return false;
    }

    // --------------------------
    const size_t MaterialImporter::getNumGeometryConnections ( 
        const String& uvChooserName ) const 
    {
        size_t numConnections = 0;

        std::map<COLLADAFW::UniqueId, std::vector<String> >::const_iterator it = mChooserGeometryConnections.begin ();
        while ( it != mChooserGeometryConnections.end () )
        {
            const std::vector<String>& boundChoosers = it->second;
            std::vector<String>::const_iterator it2 = boundChoosers.begin ();
            while ( it2 != boundChoosers.end () )
            {
                if ( COLLADABU::Utils::equals ( *it2, uvChooserName ) ) 
                    ++numConnections;
                ++it2;
            }
            ++it;
        }

        return numConnections;
    }

}