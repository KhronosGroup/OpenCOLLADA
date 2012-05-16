/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxImporterBase.h"

#include "COLLADAFWUniqueId.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWVisualScene.h"


namespace COLLADAMax
{

	const String ImporterBase::EMPTY_STRING = "";

	ImporterBase::ImporterBase( DocumentImporter* documentImporter)
		:	mDocumentImporter(documentImporter)
	{
	}

    //------------------------------
	ImporterBase::~ImporterBase()
	{
	}

	//------------------------------
	void* ImporterBase::createMaxObject( SClass_ID superClassId, Class_ID classId )
	{
		return mDocumentImporter->createMaxObject( superClassId, classId );
	}

	//------------------------------
	Interface* ImporterBase::getMaxInterface()
	{
		return mDocumentImporter->getMaxInterface();
	}

	//------------------------------
	ImpInterface* ImporterBase::getMaxImportInterface()
	{
		return mDocumentImporter->getMaxImportInterface();
	}

	//------------------------------
	void ImporterBase::printMessage( const String& message )
	{
		mDocumentImporter->printMessage(message);
	}

	//------------------------------
	double ImporterBase::getElapsedTime()const
	{
		return mDocumentImporter->getElapsedTime();
	}

	//------------------------------
	DummyObject* ImporterBase::getDummyObject()
	{
		return mDocumentImporter->getDummyObject();
	}

	//------------------------------
	void ImporterBase::addUniqueIdObjectINodePair( const COLLADAFW::UniqueId& uniqueId, INode* node )
	{
		mDocumentImporter->getUniqueIdObjectINodeMap().insert(std::pair<COLLADAFW::UniqueId, INode*>(uniqueId, node) );
	}

	//------------------------------
	void ImporterBase::addUniqueIdReferencingImpNodePair( const COLLADAFW::UniqueId& uniqueId, ImpNode* node )
	{
		mDocumentImporter->getUniqueIdReferencingImpNodeMap().insert(std::pair<COLLADAFW::UniqueId, ImpNode*>(uniqueId, node) );
	}

	//------------------------------
	void ImporterBase::removeUniqueIdReferencingImpNodePair( const COLLADAFW::UniqueId& uniqueId, ImpNode* node )
	{
		DocumentImporter::UniqueIdImpNodeMultiMap& uniqueIdReferencingImpNodeMap = mDocumentImporter->getUniqueIdReferencingImpNodeMap();

		DocumentImporter::UniqueIdImpNodeMultiMap::iterator rangeBegin = uniqueIdReferencingImpNodeMap.lower_bound(uniqueId);
		DocumentImporter::UniqueIdImpNodeMultiMap::iterator rangeEnd = uniqueIdReferencingImpNodeMap.upper_bound(uniqueId);

		for (DocumentImporter::UniqueIdImpNodeMultiMap::iterator it = rangeBegin; it != rangeEnd; ++it)
		{
			if ( it->second == node )
			{
				uniqueIdReferencingImpNodeMap.erase(it);
				break;
			}
		}
	}

	//------------------------------
	void ImporterBase::getObjectINodesByUniqueId( const COLLADAFW::UniqueId& uniqueId, COLLADAMax::INodeList& nodelist )
	{
		const DocumentImporter::UniqueIdINodeMultiMap& uniqueIdINodeMap = mDocumentImporter->getUniqueIdObjectINodeMap();

		DocumentImporter::UniqueIdINodeMultiMap::const_iterator rangeBegin = uniqueIdINodeMap.lower_bound(uniqueId);
		DocumentImporter::UniqueIdINodeMultiMap::const_iterator rangeEnd = uniqueIdINodeMap.upper_bound(uniqueId);

		for (DocumentImporter::UniqueIdINodeMultiMap::const_iterator it = rangeBegin; it != rangeEnd; ++it)
			nodelist.push_back(it->second);
	}

	//------------------------------
	DocumentImporter::UniqueIdINodeMultiMapConstIterator ImporterBase::getUniqueIdObjectINodesBegin() const
	{
		const DocumentImporter::UniqueIdINodeMultiMap& uniqueIdINodeMap = mDocumentImporter->getUniqueIdObjectINodeMap();
		return uniqueIdINodeMap.begin();
	}

	//------------------------------
	DocumentImporter::UniqueIdINodeMultiMapConstIterator ImporterBase::getUniqueIdObjectINodesEnd() const
	{
		const DocumentImporter::UniqueIdINodeMultiMap& uniqueIdINodeMap = mDocumentImporter->getUniqueIdObjectINodeMap();
		return uniqueIdINodeMap.end();
	}

	//------------------------------
	ImpNode* ImporterBase::getReferencingImpNodesByUniqueId( const COLLADAFW::UniqueId& uniqueId )
	{
		const DocumentImporter::UniqueIdImpNodeMultiMap& uniqueIdReferencingImpNodeMap = mDocumentImporter->getUniqueIdReferencingImpNodeMap();

		DocumentImporter::UniqueIdImpNodeMultiMap::const_iterator it = uniqueIdReferencingImpNodeMap.find(uniqueId);
		if ( it == uniqueIdReferencingImpNodeMap.end() )
			return 0;
		else
			return it->second;
	}


	//------------------------------
	void ImporterBase::addUniqueIdObjectPair( const COLLADAFW::UniqueId& uniqueId, Object* object )
	{
		mDocumentImporter->getUniqueIdObjectMap()[uniqueId] = object;
	}


	//------------------------------
	void ImporterBase::addUniqueIdINodePair( const COLLADAFW::UniqueId& uniqueId, INode* iNode )
	{
		mDocumentImporter->getUniqueIdINodeMap()[uniqueId] = iNode;
	}

	//------------------------------
	void ImporterBase::addObjectINodeUniqueIdPair( INode* iNode, const COLLADAFW::UniqueId& uniqueId )
	{
		mDocumentImporter->getObjectINodeUniqueIdMap()[iNode] = uniqueId;
	}

	//------------------------------
	void ImporterBase::addUniqueIdFWNodePair( const COLLADAFW::UniqueId& uniqueId, const COLLADAFW::Node* node )
	{
		mDocumentImporter->getUniqueIdFWNodeMap()[uniqueId] = node;
	}

	//------------------------------
	void ImporterBase::addUniqueIdFWMaterialPair( const COLLADAFW::UniqueId& uniqueId, const COLLADAFW::Material& material )
	{
		mDocumentImporter->getUniqueIdFWMaterialMap().insert(std::pair<COLLADAFW::UniqueId, COLLADAFW::Material>(uniqueId, material));
	}

	//------------------------------
	void ImporterBase::addUniqueIdFWEffectPair( const COLLADAFW::UniqueId& uniqueId, const COLLADAFW::Effect& effect )
	{
		mDocumentImporter->getUniqueIdFWEffectMap().insert(std::pair<COLLADAFW::UniqueId, COLLADAFW::Effect>(uniqueId, effect));;
	}

	//------------------------------
	void ImporterBase::addUniqueIdFWImagePair( const COLLADAFW::UniqueId& uniqueId, const COLLADAFW::Image& Image )
	{
		mDocumentImporter->getUniqueIdFWImageMap().insert(std::pair<COLLADAFW::UniqueId, COLLADAFW::Image>(uniqueId, Image));;
	}

	//------------------------------
	DocumentImporter::NodeMaterialBindingsPair& ImporterBase::createAndAddNodeMaterialBindingsPair( INode* node )
	{
		DocumentImporter::NodeMaterialBindingsPair newPair;
		newPair.maxNode = node;
		DocumentImporter::NodeMaterialBindingsList& list = mDocumentImporter->getNodeMaterialBindingsList();
		list.push_back(newPair);
		return *list.rbegin();
	}

	//------------------------------
	void ImporterBase::addLibraryNodes( const COLLADAFW::LibraryNodes* libraryNodes )
	{
		mDocumentImporter->getLibraryNodesList().push_back(libraryNodes);
	}

	//------------------------------
	void ImporterBase::addVisualScene( const COLLADAFW::VisualScene* visualScene )
	{
		DocumentImporter::UniqueIdVisualSceneMap& map = mDocumentImporter->getUniqueIdVisualSceneMap();
		map[ visualScene->getUniqueId() ] = visualScene;
	}

	//------------------------------
	void ImporterBase::addClonedINodeOriginalINodePair( INode* clonedNode, INode* originalNode )
	{
		DocumentImporter::INodeINodePairList& inodeInodePairList = mDocumentImporter->getClonedINodeOriginalINodePairList();
		inodeInodePairList.push_back(std::pair<INode*, INode*>(clonedNode, originalNode));
	}

	//------------------------------
	void ImporterBase::addObjectObjectNamePair( Object* object, const String& name )
	{
		DocumentImporter::ObjectObjectNameMap& objectObjectNameMap = mDocumentImporter->getObjectObjectNameMap();
		objectObjectNameMap.insert(std::pair<Object*, String>(object, name));
	}

	//------------------------------
	void ImporterBase::addVertexColorObjects(const COLLADAFW::UniqueId& vertexColorObjectuniqueId)
	{
		DocumentImporter::UniqueIdList& vertexColorObjects = mDocumentImporter->getVertexColorObjects();
		vertexColorObjects.push_back(vertexColorObjectuniqueId);
	}

	//------------------------------
	void ImporterBase::addMaxControllerToAnimationUniqueId( const COLLADAFW::UniqueId& animationUniqueId, Control* maxController )
	{
		DocumentImporter::UniqueIdMaxControllerListMap& map = mDocumentImporter->getAnimationUniqueIdMaxControllerListMap();
		map[ animationUniqueId ].push_back( maxController );
	}

	//------------------------------
	void ImporterBase::addAnimationList( const COLLADAFW::AnimationList& animationList )
	{
		DocumentImporter::UniqueIdAnimationListMap&  map = mDocumentImporter->getUniqueIdAnimationListMap();
		map[ animationList.getUniqueId() ] = new COLLADAFW::AnimationList( animationList );
	}

	//------------------------------
	Object* ImporterBase::getObjectByUniqueId( const COLLADAFW::UniqueId& uniqueId )
	{
		const DocumentImporter::UniqueIdObjectMap& uniqueIdObjectMap = mDocumentImporter->getUniqueIdObjectMap();
		DocumentImporter::UniqueIdObjectMap::const_iterator it = uniqueIdObjectMap.find(uniqueId);
		if ( it == uniqueIdObjectMap.end() )
			return 0;
		else
			return it->second;
	}

	//------------------------------
	INode* ImporterBase::getINodeByUniqueId( const COLLADAFW::UniqueId& uniqueId )
	{
		const DocumentImporter::UniqueIdINodeMap& uniqueIdINodeMap = mDocumentImporter->getUniqueIdINodeMap();
		DocumentImporter::UniqueIdINodeMap::const_iterator it = uniqueIdINodeMap.find(uniqueId);
		if ( it == uniqueIdINodeMap.end() )
			return 0;
		else
			return it->second;
	}

	//------------------------------
	const COLLADAFW::UniqueId& ImporterBase::getUniqueIdByObjectINode( INode* iNode )
	{
		const DocumentImporter::ObjectINodeUniqueIdMap& objectINodeUniqueIdMap = mDocumentImporter->getObjectINodeUniqueIdMap();
		DocumentImporter::ObjectINodeUniqueIdMap::const_iterator it = objectINodeUniqueIdMap.find(iNode);
		if ( it == objectINodeUniqueIdMap.end() )
			return COLLADAFW::UniqueId::INVALID;
		else
			return it->second;
	}


	//------------------------------
	const COLLADAFW::Node* ImporterBase::getFWNodeByUniqueId( const COLLADAFW::UniqueId& uniqueId )
	{
		const DocumentImporter::UniqueIdFWNodeMap& uniqueIdFWNodeMap = mDocumentImporter->getUniqueIdFWNodeMap();
		DocumentImporter::UniqueIdFWNodeMap::const_iterator it = uniqueIdFWNodeMap.find(uniqueId);
		if ( it == uniqueIdFWNodeMap.end() )
			return 0;
		else
			return it->second;
	}

	//------------------------------
	const DocumentImporter::UniqueIdFWNodeMap& ImporterBase::getUniqueIdFWNodeMap( )
	{
		return mDocumentImporter->getUniqueIdFWNodeMap();
	}

	//------------------------------
	const COLLADAFW::Material* ImporterBase::getFWMaterialByUniqueId( const COLLADAFW::UniqueId& uniqueId )
	{
		const DocumentImporter::UniqueIdFWMaterialMap& uniqueIdFWMaterialMap = mDocumentImporter->getUniqueIdFWMaterialMap();
		DocumentImporter::UniqueIdFWMaterialMap::const_iterator it = uniqueIdFWMaterialMap.find(uniqueId);
		if ( it == uniqueIdFWMaterialMap.end() )
			return 0;
		else
			return &it->second;
	}

	//------------------------------
	const COLLADAFW::Effect* ImporterBase::getFWEffectByUniqueId( const COLLADAFW::UniqueId& uniqueId )
	{
		const DocumentImporter::UniqueIdFWEffectMap& uniqueIdFWEffectMap = mDocumentImporter->getUniqueIdFWEffectMap();
		DocumentImporter::UniqueIdFWEffectMap::const_iterator it = uniqueIdFWEffectMap.find(uniqueId);
		if ( it == uniqueIdFWEffectMap.end() )
			return 0;
		else
			return &it->second;
	}

	//------------------------------
	const COLLADAFW::Image* ImporterBase::getFWImageByUniqueId( const COLLADAFW::UniqueId& uniqueId )
	{
		const DocumentImporter::UniqueIdFWImageMap& uniqueIdFWImageMap = mDocumentImporter->getUniqueIdFWImageMap();
		DocumentImporter::UniqueIdFWImageMap::const_iterator it = uniqueIdFWImageMap.find(uniqueId);
		if ( it == uniqueIdFWImageMap.end() )
			return 0;
		else
			return &it->second;
	}

	//------------------------------
	const DocumentImporter::NodeMaterialBindingsList& ImporterBase::getNodeMaterialBindings()
	{
		return mDocumentImporter->getNodeMaterialBindingsList();
	}

	//------------------------------
	DocumentImporter::FWMaterialIdMaxMtlIdMap& ImporterBase::getMaterialIdMapByGeometryUniqueId( const COLLADAFW::UniqueId& uniqueId )
	{
		return mDocumentImporter->getGeometryMaterialIdMapMap()[uniqueId];
	}

	//------------------------------
	DocumentImporter::SetMapChannelMap& ImporterBase::getSetMapChannelByGeometryUniqueId( const COLLADAFW::UniqueId& uniqueId )
	{
		return mDocumentImporter->getGeometrySetMapChannelMap()[uniqueId];
	}

	//------------------------------
	const COLLADAFW::VisualScene* ImporterBase::getVisualSceneByUniqueId( const COLLADAFW::UniqueId& visualSceneUniqueId )
	{
		const DocumentImporter::UniqueIdVisualSceneMap& map = mDocumentImporter->getUniqueIdVisualSceneMap();
		DocumentImporter::UniqueIdVisualSceneMap::const_iterator it = map.find( visualSceneUniqueId );
		if ( it == map.end() )
		{
			return 0;
		}
		else
		{
			return it->second;
		}
	}

	//------------------------------
	const DocumentImporter::INodeINodePairList& ImporterBase::getClonedINodeOriginalINodePairList()
	{
		return mDocumentImporter->getClonedINodeOriginalINodePairList();
	}

	//------------------------------
	const String& ImporterBase::getObjectNameByObject( Object* object ) const
	{
		const DocumentImporter::ObjectObjectNameMap& objectObjectNameMap = mDocumentImporter->getObjectObjectNameMap();
		DocumentImporter::ObjectObjectNameMap::const_iterator it = objectObjectNameMap.find(object);
		if ( it == objectObjectNameMap.end() )
			return EMPTY_STRING;
		else
			return it->second;
	}

	//------------------------------
	const DocumentImporter::MaxControllerList& ImporterBase::getMaxControllerListByAnimationUniqueId( const COLLADAFW::UniqueId& animationUniqueId ) const
	{
		DocumentImporter::UniqueIdMaxControllerListMap& map = mDocumentImporter->getAnimationUniqueIdMaxControllerListMap();
		return map[ animationUniqueId ];
	}

	//------------------------------
	const COLLADAFW::AnimationList* ImporterBase::getAnimationListByUniqueId( const COLLADAFW::UniqueId& animationListUniqueId ) const
	{
		const DocumentImporter::UniqueIdAnimationListMap&  map = mDocumentImporter->getUniqueIdAnimationListMap();
		DocumentImporter::UniqueIdAnimationListMap::const_iterator it = map.find( animationListUniqueId );
		if ( it == map.end() )
		{
			return 0;
		}
		else
		{
			return it->second;
		}
	}

	//------------------------------
	void ImporterBase::addUniqueIdControllerPair( const COLLADAFW::UniqueId& controllerData, const COLLADAFW::Controller* controller )
	{
		mDocumentImporter->getUniqueIdControllerMap().insert(std::make_pair(controllerData, controller));
	}

	//------------------------------
	void ImporterBase::addMorphController( const COLLADAFW::MorphController* morphController )
	{
		mDocumentImporter->getUniqueIdMorphControllerMap().insert(std::make_pair(morphController->getUniqueId(), morphController));
	}

	//------------------------------
	const COLLADAFW::MorphController* ImporterBase::getMorphControllerByUniqueId( const COLLADAFW::UniqueId& morphControllerUniqueId ) const
	{
		const DocumentImporter::UniqueIdMorphControllerMap&  map = mDocumentImporter->getUniqueIdMorphControllerMap();
		DocumentImporter::UniqueIdMorphControllerMap::const_iterator it = map.find( morphControllerUniqueId );
		if ( it == map.end() )
		{
			return 0;
		}
		else
		{
			return it->second;
		}
	}

	//------------------------------
	void ImporterBase::addSkinController( const COLLADAFW::SkinController* skinController )
	{
		mDocumentImporter->getUniqueIdSkinControllerMap().insert(std::make_pair(skinController->getUniqueId(), skinController));
	}

	//------------------------------
	const COLLADAFW::SkinController* ImporterBase::getSkinControllerByUniqueId( const COLLADAFW::UniqueId& skinControllerUniqueId ) const
	{
		const DocumentImporter::UniqueIdSkinControllerMap&  map = mDocumentImporter->getUniqueIdSkinControllerMap();
		DocumentImporter::UniqueIdSkinControllerMap::const_iterator it = map.find( skinControllerUniqueId );
		if ( it == map.end() )
		{
			return 0;
		}
		else
		{
			return it->second;
		}
	}


	//------------------------------
	const COLLADAFW::AnimationList* ImporterBase::getAnimationList( const COLLADAFW::Animatable* animatable )
	{
		if ( !animatable )
		{
			return 0;
		}

		const COLLADAFW::UniqueId& referencedAnimationListUniqueId = animatable->getAnimationList();

		if ( !referencedAnimationListUniqueId.isValid() )
		{
			return 0;
		}

		return getAnimationListByUniqueId( referencedAnimationListUniqueId );
	}

	//------------------------------
	const DocumentImporter::UniqueIdList& ImporterBase::getVertexColorObjects()
	{
		return mDocumentImporter->getVertexColorObjects();
	}

	//---------------------------------------------------------------
	void ImporterBase::Matrix4ToMaxMatrix3 ( Matrix3 & copy,  const COLLADABU::Math::Matrix4& original )
	{
		Point4 column;
		column[ 0 ] = (float)original.getElement(0,0);
		column[ 1 ] = (float)original.getElement(0,1);
		column[ 2 ] = (float)original.getElement(0,2);
		column[ 3 ] = convertSpaceUnit((float)original.getElement(0,3));
		copy.SetColumn(0, column);

		column[ 0 ] = (float)original.getElement(1,0);
		column[ 1 ] = (float)original.getElement(1,1);
		column[ 2 ] = (float)original.getElement(1,2);
		column[ 3 ] = convertSpaceUnit((float)original.getElement(1,3));
		copy.SetColumn(1, column);

		column[ 0 ] = (float)original.getElement(2,0);
		column[ 1 ] = (float)original.getElement(2,1);
		column[ 2 ] = (float)original.getElement(2,2);
		column[ 3 ] = convertSpaceUnit((float)original.getElement(2,3));
		copy.SetColumn(2, column);
	}

	//------------------------------
	float ImporterBase::convertSpaceUnit( float originalValue )
	{
		return mDocumentImporter->convertSpaceUnit(originalValue);
	}

	//------------------------------
	const SkyLightParameters* ImporterBase::getSkyLightParametersByUniqueId( const COLLADAFW::UniqueId& uniqueId )
	{
		const DocumentImporter::UniqueIdSkyLightMap&  map = mDocumentImporter->getUniqueIdSkyLightMap();
		DocumentImporter::UniqueIdSkyLightMap::const_iterator it = map.find( uniqueId );
		if ( it == map.end() )
		{
			return 0;
		}
		else
		{
			return &it->second;
		}
	}

	//------------------------------
	void ImporterBase::addUniqueIdSkyLightParametersPair( const COLLADAFW::UniqueId& lihgtUniqueId, const SkyLightParameters& skyLightParameters )
	{
		mDocumentImporter->getUniqueIdSkyLightMap()[lihgtUniqueId] = skyLightParameters;
	}

} // namespace COLLADAMax
