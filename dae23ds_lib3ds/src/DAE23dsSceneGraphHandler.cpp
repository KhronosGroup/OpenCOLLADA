/*
	Copyright (c) 2010 yaoyansi<yaoyansi2@yahoo.com.cn>

	This file is part of dae23ds_lib3ds.

	Licensed under the MIT Open Source License, 
	for details please see LICENSE file or the website
	http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE23dsStableHeaders.h"
#include "DAE23dsSceneGraphHandler.h"
//#include "DAE23dsMeshBase.h"
#include <lib3ds.h>

namespace DAE23ds
{
	//------------------------------
	SceneGraphHandler::SceneGraphHandler( const COLLADAFW::VisualScene* visualScene )
		: mVisualScene( visualScene )
	{
	}

	//------------------------------
	SceneGraphHandler::~SceneGraphHandler()
	{
	}	

	//------------------------------
	bool SceneGraphHandler::handle()
	{
		NodeInfo nodeInfo( COLLADABU::Math::Matrix4::IDENTITY );
		mNodeInfoStack.push( nodeInfo );

		handleNodes( mVisualScene->getRootNodes());

		return true;
	}

	//------------------------------
	bool SceneGraphHandler::handleNodes( const COLLADAFW::NodePointerArray& nodesToWriter)
	{
		for ( size_t i = 0, count = nodesToWriter.getCount(); i < count; ++i)
		{
			handleNode(nodesToWriter[i]);
		}
		return true;
	}

	//------------------------------
	bool SceneGraphHandler::handleNode(const COLLADAFW::Node* nodeToWriter)
	{
		const NodeInfo& parentNodeInfo = mNodeInfoStack.top();
		const COLLADABU::Math::Matrix4& parentWorldMatrix = parentNodeInfo.worldTransformation;
		COLLADABU::Math::Matrix4 worldMatrix = parentWorldMatrix * nodeToWriter->getTransformationMatrix();
		NodeInfo nodeInfo( worldMatrix );
		mNodeInfoStack.push(nodeInfo);

		handleInstanceGeometries( nodeToWriter, worldMatrix );
		handleInstanceLights( nodeToWriter, worldMatrix );

		handleNodes(nodeToWriter->getChildNodes());

		handleInstanceNodes( nodeToWriter->getInstanceNodes() );

		mNodeInfoStack.pop();
		return true;
	}

	//------------------------------
	void SceneGraphHandler::handleInstanceGeometries( const COLLADAFW::Node* node, const COLLADABU::Math::Matrix4& matrix )
	{
		const COLLADAFW::InstanceGeometryPointerArray& instanceGeometries = node->getInstanceGeometries();
		for ( size_t i = 0, count = instanceGeometries.getCount(); i < count; ++i)
		{
			COLLADAFW::InstanceGeometry* instanceGeometry = instanceGeometries[i];

 			Writer::InstanceGeometryInfo instanceGeometryInfo( instanceGeometry, matrix/*, getNextInstanceNumber(instanceGeometry) */);

			const COLLADAFW::UniqueId& meshUniqueId = instanceGeometry->getInstanciatedObjectId();

// 			std::cout <<"----------------------------------------------"<<std::endl;
// 			std::cout <<"instanceGeometry(name="<<instanceGeometry->getName()
// 				<<",objid="<<instanceGeometry->getObjectId()
// 				<<",clsid="<<instanceGeometry->getClassId()
// 				<<",uid="<<instanceGeometry->getUniqueId().toAscii()
// 				<<",iobjid="<<instanceGeometry->getInstanciatedObjectId().toAscii()
// 				<<std::endl;
// 			std::cout<<"meshdata(uid="<<meshdata.meshUniqueId.getClassId()<<","
// 				<<meshdata.meshUniqueId.getObjectId()<<","
// 				<<meshdata.meshUniqueId.toAscii()<<","
// 				<<meshdata.name<<","
// 				<<std::endl;

			const COLLADAFW::MaterialBindingArray & mba = instanceGeometry->getMaterialBindings();
			for(size_t i=0; i<mba.getCount(); ++i)
			{
				std::cout <<"material id="<<mba[i].getMaterialId()<<","
					<<"name="<<mba[i].getName()<<","
					<<"ReferencedMat="<<mba[i].getReferencedMaterial().toAscii()
					<<std::endl;
			}

 			addInstanceGeometryInstanceGeometryInfoPair(instanceGeometry->getInstanciatedObjectId(), instanceGeometryInfo);
		}
	}

	//------------------------------
	void SceneGraphHandler::handleInstanceNodes( const COLLADAFW::InstanceNodePointerArray& instanceNodes)
	{
		std::cout <<"SceneGraphHandler::handleInstanceNodes(size="<<instanceNodes.getCount()<<")"<<std::endl;

		for ( size_t i = 0, count = instanceNodes.getCount(); i < count; ++i)
		{
			const COLLADAFW::InstanceNode* instanceNode = instanceNodes[i];
			const COLLADAFW::UniqueId& referencedNodeUniqueId = instanceNode->getInstanciatedObjectId();
			
			std::cout <<"instance node(name="<<instanceNode->getName()
				<<",uid="<<instanceNode->getUniqueId().toAscii()
				<<",oid="<<instanceNode->getObjectId()
				<<",iid="<<instanceNode->getInstanciatedObjectId().toAscii()
				<<std::endl;


			Writer::UniqueIdNodeMap::const_iterator it = Writer::getInstance()->getUniqueIdNodeMap().find( referencedNodeUniqueId );
			if ( it != Writer::getInstance()->getUniqueIdNodeMap().end() )
			{
				const COLLADAFW::Node* referencedNode = it->second;
				handleNode( referencedNode );
			}
		}
	}

	//------------------------------------
	void SceneGraphHandler::handleInstanceLights( const COLLADAFW::Node* node, const COLLADABU::Math::Matrix4& matrix )
	{
		const COLLADAFW::InstanceLightPointerArray& instanceLights = node->getInstanceLights();
		for ( size_t i = 0, count = instanceLights.getCount(); i < count; ++i)
		{
			COLLADAFW::InstanceLight* instanceLight = instanceLights[i];

			const COLLADAFW::UniqueId& uid = instanceLight->getInstanciatedObjectId();

			std::cout <<"----------------------------------------------"<<std::endl;
			std::cout<<"light uid="<< uid.toAscii()<<std::endl;

			std::map<COLLADAFW::UniqueId, const COLLADAFW::Light*>::const_iterator it
				 = Writer::getInstance()->lightMap.find(uid);
			if(it==Writer::getInstance()->lightMap.end())//not found
				continue;


			const COLLADAFW::Light *light = it->second;
			std::cout<<"light name="<< light->getName()<<std::endl;
			std::cout<<"light type="<< light->getLightType()<<std::endl;
			std::cout<<"light color="<< light->getColor().getRed()<<","<< light->getColor().getGreen()<<","<<light->getColor().getBlue()<<std::endl;
			std::cout<<"light const attenuation="<< light->getConstantAttenuation().getValue()<<std::endl;
			std::cout<<"light linear attenuation="<< light->getLinearAttenuation().getValue()<<std::endl;
			std::cout<<"light quadratic attenuation="<< light->getQuadraticAttenuation().getValue()<<std::endl;
			std::cout<<"light fallOffAngle="<< light->getFallOffAngle().getValue()<<std::endl;
			std::cout<<"light fallOffExp="<< light->getFallOffExponent().getValue()<<std::endl;

			COLLADABU::Math::Vector3 translation(matrix.getTrans());
			//----------------------------------------------
			Lib3dsLight *_3dslight = lib3ds_light_new(light->getName().c_str());
			{
				//_3dslight->object_flags=
				_3dslight->spot_light = (light->getLightType()==COLLADAFW::Light::SPOT_LIGHT)?true:false;
				//_3dslight->see_cone=
				_3dslight->color[0]=light->getColor().getRed();
				_3dslight->color[1]=light->getColor().getGreen();
				_3dslight->color[2]=light->getColor().getBlue();

				//_3dslight->position[0]=_3dslight->position[1]=_3dslight->position[2]=0.0;
				_3dslight->position[0]=translation.x;
				_3dslight->position[1]=translation.y;
				_3dslight->position[2]=translation.z;
				
				_3dslight->target[0]=_3dslight->target[1]=_3dslight->target[2]=0.0;
				//_3dslight->roll
				//_3dslight->off
				//_3dslight->outer_range
				//_3dslight->inner_range
				//_3dslight->multiplier
				_3dslight->attenuation = light->getLinearAttenuation().getValue();
				//_3dslight->rectangular_spot =
				//_3dslight->shadowed
				//_3dslight->shadow_bias
				//_3dslight->shadow_filter
				//_3dslight->shadow_size
				_3dslight->spot_aspect = light->getFallOffAngle().getValue();
				//_3dslight->use_projector
				//_3dslight->projector
				//_3dslight->spot_overshoot
				//_3dslight->ray_shadows
				//_3dslight->ray_bias
				//_3dslight->hotspot=
				_3dslight->falloff = light->getFallOffExponent().getValue();
			}

			//----------------------------------------------
			if(light->getLightType()==COLLADAFW::Light::SPOT_LIGHT)
			{
				Lib3dsSpotlightNode* node = lib3ds_node_new_spotlight(_3dslight);
				for(size_t i=0; i<4; ++i) 
				{
					for(size_t j=0; j<4; ++j) 
					{
						node->base.matrix[i][j] = matrix.getElement(i,j);
						std::cout << node->base.matrix[i][j]<<", ";
					}
					std::cout <<std::endl;
				}
				lib3ds_file_insert_light(Writer::getInstance()->get3dsFile(), _3dslight, -1);
			}
			else if(light->getLightType()==COLLADAFW::Light::POINT_LIGHT)
			{
				Lib3dsOmnilightNode*  node = lib3ds_node_new_omnilight(_3dslight);
				for(size_t i=0; i<4; ++i) 
				{
					for(size_t j=0; j<4; ++j) 
					{
						node->base.matrix[i][j] = matrix.getElement(i,j);
						std::cout << node->base.matrix[i][j]<<", ";
					}
					std::cout <<std::endl;
				}
				lib3ds_file_insert_light(Writer::getInstance()->get3dsFile(), _3dslight, -1);
			}else{
				lib3ds_file_insert_light(Writer::getInstance()->get3dsFile(), _3dslight, -1);
			}

		}
	}
	void SceneGraphHandler::addInstanceGeometryInstanceGeometryInfoPair( const COLLADAFW::UniqueId& geoId, const Writer::InstanceGeometryInfo& instanceGeoInfo )
	{
		if ( !Writer::getInstance()->getApplyTransformationsToMeshes() )
		{
			// if we apply transformations to meshes, we need each instance as often as it occurs
			Writer::InstanceGeometryInfoSet& set = Writer::getInstance()->getInstanceGeometryInfoSet();
			if ( set.count(instanceGeoInfo) != 0 )
			{
				return;
			}
			else
			{
				set.insert( instanceGeoInfo );
			}
		}

		Writer::GeometryUniqueIdInstanceGeometryInfoMap& map 
			= Writer::getInstance()->getGeometryUniqueIdInstanceGeometryInfoMap();
		map.insert(std::make_pair(geoId, instanceGeoInfo));
	}

} // namespace DAE23ds
