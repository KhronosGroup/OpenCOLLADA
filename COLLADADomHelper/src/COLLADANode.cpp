#include "HelperStableHeaders.h"
#include "COLLADANode.h"
#include "COLLADAExtra.h"
#include "COLLADAUtil.h"

namespace COLLADA
{
	bool isIdentity(float mMatrix[4][4])
	{
		bool isIdentity = true;
		isIdentity &= mMatrix[0][0] == 1 && mMatrix[0][1] == 0 && mMatrix[0][2] ==0 && mMatrix[0][3] ==0;
		isIdentity &= mMatrix[1][0] == 0 && mMatrix[1][1] == 1 && mMatrix[1][2] ==0 && mMatrix[1][3] ==0;
		isIdentity &= mMatrix[2][0] == 0 && mMatrix[2][1] == 0 && mMatrix[2][2] ==1 && mMatrix[2][3] ==0;
		isIdentity &= mMatrix[3][0] == 0 && mMatrix[3][1] == 0 && mMatrix[3][2] ==0 && mMatrix[3][3] ==1;
		return isIdentity;
	}
	//-----------------------------------------------------------------------
	daeElement* Node::element(daeElement *node)
	{
		bool bRet = false;

		domLibrary_nodes *libNodes = daeSafeCast<domLibrary_nodes>(node);
		domVisual_scene *visualScene = daeSafeCast<domVisual_scene>(node);
		domNode *n = daeSafeCast<domNode>(node);

		if (libNodes || visualScene || n)
		{
			if (!mNode)
				mNode = daeSafeCast<domNode>(node->createAndPlace(COLLADA_ELEMENT_NODE));

			if (mNode)
			{
				if (mId.size() > 0)
					mNode->setId(mId.c_str());
				if (mName.size() > 0)
					mNode->setName(checkNCName(mName).c_str());

				//--- add layer names to dom-node
				addLayerNamesToNode();

				bRet = true;
				if (mUseMatrix && !isIdentity(mMatrix))
				{
					domMatrix* matrix = daeSafeCast<domMatrix>(mNode->createAndPlace(COLLADA_ELEMENT_MATRIX));
					if (matrix)
					{
						domFloat4x4 m;
						m.append4(mMatrix[0][0], mMatrix[0][1], mMatrix[0][2], mMatrix[0][3]);
						m.append4(mMatrix[1][0], mMatrix[1][1], mMatrix[1][2], mMatrix[1][3]);
						m.append4(mMatrix[2][0], mMatrix[2][1], mMatrix[2][2], mMatrix[2][3]);
						m.append4(mMatrix[3][0], mMatrix[3][1], mMatrix[3][2], mMatrix[3][3]);
						matrix->setValue(m);
					}
					else
						bRet &= false;
				}

				bRet &= mApplyRotationBeforeTranslation ? createRotation() : createTranslation();
				bRet &= mApplyRotationBeforeTranslation ? createTranslation() : createRotation();
			}      

			if (!bRet && mNode)
			{
				node->removeChildElement(mNode);
				mNode = NULL;
			}
		}
		return mNode;
	}

	//-----------------------------------------------------------------------
	bool Node::createTranslation()
	{
		bool bRet = true;
		for (size_t i = 0; i < mTranslate.size(); i++)
		{
			domTranslate* translate = daeSafeCast<domTranslate>(mNode->createAndPlace(COLLADA_ELEMENT_TRANSLATE));
			if (translate)
			{
				domFloat3 &value = translate->getValue();
				value.append3(mTranslate[i].first[0], mTranslate[i].first[1], mTranslate[i].first[2]);
				if (!mTranslate[i].second.empty())
				{
					translate->setSid(mTranslate[i].second.c_str());
				}	
			}
			else
				bRet = false;
		}
		return bRet;
	}
	
	//-----------------------------------------------------------------------
	bool Node::createRotation()
	{
		bool bRet = true;
		for (size_t i = 0; i < mRotate.size(); i++)
		{
			domRotate* rotate = daeSafeCast<domRotate>(mNode->createAndPlace(COLLADA_ELEMENT_ROTATE));
			if (rotate)
			{
				domFloat4 &value = rotate->getValue();
				value.append4(mRotate[i].first[0], mRotate[i].first[1], mRotate[i].first[2], mRotate[i].first[3]);
				if (!mRotate[i].second.empty())
				{
					rotate->setSid(mRotate[i].second.c_str());
				}
			}
			else
				bRet = false;
		}
		return bRet;
	}

	//-----------------------------------------------------------------------
	bool Node::addLayerNamesToNode()
	{
		if(mLayerNames.size() == 0)
		{
			return false;
		}

		domListOfNames names;

		for (int i=0; i<mLayerNames.size(); ++i)
		{
			domName name = daeStringRef( checkNCName(mLayerNames[i]).c_str() );
			names.append( name );
		}

		mNode->setLayer(names);
		return true;
	}

	//-----------------------------------------------------------------------

	void Node::setApplyRotationBeforeTranslation(bool applyRotationBeforeTranslation)
	{
		mApplyRotationBeforeTranslation = applyRotationBeforeTranslation;
	}

	domNode* Node::addNode(COLLADA::Node &node)
	{
		bool bRet = false;

		domNode* n = daeSafeCast<domNode>(node.element(mNode));
		
		if (n)
		{
			bRet = true;
		}

		return n;
	}

	//-----------------------------------------------------------------------
	domExtra* Node::addExtra(COLLADA::Extra &extra)
	{
		bool bRet = false;

		domExtra* e = daeSafeCast<domExtra>(extra.element(mNode));
		
		if (e)
		{
			bRet = true;
		}

		return e;
	}

	//-----------------------------------------------------------------------
	void Node::addLayerName( const std::string& layerName )
	{
		if(layerName.size() > 0)
		{
			mLayerNames.push_back(layerName);
		}
	}

	//-----------------------------------------------------------------------
	domInstance_geometry* Node::instanceGeometry(domGeometry &geom, const std::vector<std::pair<std::string, domMaterial*> > &bindings)
	{
		domInstance_geometry* inst = daeSafeCast<domInstance_geometry>(mNode->createAndPlace(COLLADA_ELEMENT_INSTANCE_GEOMETRY));

		if (inst)
		{
			daeURI uri(*(geom.getDAE()));
			uri.setElement(&geom);
			uri.resolveURI();
			if (uri.isExternalReference())
				uri.makeRelativeTo(mNode->getDocumentURI());
			inst->setUrl(uri);
			//inst->getUrl().setElement(&geom);
			//inst->getUrl().resolveURI();

			if (bindings.size() > 0)
			{
				domBind_material* bindMat = daeSafeCast<domBind_material>(inst->createAndPlace(COLLADA_ELEMENT_BIND_MATERIAL));
				if (bindMat)
				{
					domBind_material::domTechnique_common *technique = daeSafeCast<domBind_material::domTechnique_common>(bindMat->createAndPlace(COLLADA_ELEMENT_TECHNIQUE_COMMON));
					if (technique)
					{
						for (size_t i = 0; i < bindings.size(); i++)
						{
							domInstance_material *instMat = daeSafeCast<domInstance_material>(technique->createAndPlace(COLLADA_ELEMENT_INSTANCE_MATERIAL));
							if (instMat)
							{
								instMat->setSymbol(bindings[i].first.c_str());
								domMaterial* mat = bindings[i].second;
								instMat->getTarget().setElement(mat);
								instMat->getTarget().resolveURI();
							}
						}
					}
				}
			}
		}

		return inst;
	}

	//-----------------------------------------------------------------------
	domInstance_geometry* Node::instanceGeometry(const std::string &url)
	{
		domInstance_geometry* inst = daeSafeCast<domInstance_geometry>(mNode->createAndPlace(COLLADA_ELEMENT_INSTANCE_GEOMETRY));
		if (inst)
		{
			//daeURI uri(url);
			//uri.setElement(&geom);
			//uri.resolveURI();
			//if (uri.isExternalReference())
			//	uri.makeRelativeTo(mNode->getDocumentURI());
			inst->setUrl(url.c_str());
		}
		return inst;
	}

	//-----------------------------------------------------------------------
	domInstance_node* Node::instanceNode(domNode &node, const std::string &instanceName/* = ""*/)
	{
		domInstance_node* inst = daeSafeCast<domInstance_node>(mNode->createAndPlace(COLLADA_ELEMENT_INSTANCE_NODE));

		if (inst)
		{
			daeURI uri(*mNode);
			uri.setElement(&node);
			uri.resolveURI();
			if (uri.isExternalReference())
				uri.makeRelativeTo(mNode->getDocumentURI());
			inst->setUrl(uri);
			if ( !instanceName.empty() )
				inst->setSid(instanceName.c_str());

			/*inst->getUrl().setElement(&node);
			inst->getUrl().resolveURI();
			if (inst->getUrl().isExternalReference())
			inst->getUrl().makeRelativeTo(mNode->getDocumentURI());*/
		}

		return inst;
	}

	//-----------------------------------------------------------------------
	domInstance_node* Node::instanceNode(const std::string &url)
	{
		domInstance_node* inst = daeSafeCast<domInstance_node>(mNode->createAndPlace(COLLADA_ELEMENT_INSTANCE_NODE));

		if (inst)
		{
			inst->setUrl(url.c_str());
		}

		return inst;
	}

	//-----------------------------------------------------------------------
	domInstance_camera* Node::instanceCamera(domCamera &camera, const std::string &instanceName/* = ""*/)
	{
		domInstance_camera* InstCam = daeSafeCast<domInstance_camera>(mNode->createAndPlace(COLLADA_ELEMENT_INSTANCE_CAMERA));

		if (InstCam)
		{
			daeURI uri(*(camera.getDAE()));
			uri.setElement(&camera);
			uri.resolveURI();
			if (uri.isExternalReference())
				uri.makeRelativeTo(mNode->getDocumentURI());
			InstCam->setUrl(uri);
			if ( !instanceName.empty() )
				InstCam->setSid(instanceName.c_str());
			//InstCam->getUrl().setElement(&camera);
			//InstCam->getUrl().resolveURI();
		}

		return InstCam;
	}

	//-----------------------------------------------------------------------
	domInstance_light* Node::instanceLight(domLight &light, const std::string &instanceName/* = ""*/)
	{
		domInstance_light* InstLight = daeSafeCast<domInstance_light>(mNode->createAndPlace(COLLADA_ELEMENT_INSTANCE_LIGHT));

		if (InstLight)
		{
			daeURI uri(*(light.getDAE()));
			uri.setElement(&light);
			uri.resolveURI();
			if (uri.isExternalReference())
				uri.makeRelativeTo(mNode->getDocumentURI());
			InstLight->setUrl(uri);
			InstLight->setSid(instanceName.c_str());
			//InstLight->getUrl().setElement(&light);
			//InstLight->getUrl().resolveURI();
		}

		return InstLight;
	}


	//-----------------------------------------------------------------------
	bool Node::copyNodeContent(domNode &node)
	{
		bool bRet = false;

		/*xsIDREF idRef = id.c_str();
		idRef.setContainer(mNode);
		idRef.resolveElement();
		daeElement* element = idRef.getElement();
		if (element)
		{*/
			daeTArray< daeSmartRef< daeElement > > array;
            node.getChildren(array);
			
			for (size_t i = 0; i < array.getCount(); i++)
			{
				daeSmartRef<daeElement> ref = array.get(i);
				daeSmartRef<daeElement> clone = ref->clone();
				mNode->placeElement(clone);
			}			
			bRet = true;
		//}

		return bRet;
	}

	//-----------------------------------------------------------------------
	void Node::addRotate(const double & x, const double & y, const double & z, const double & angle, const std::string &sid /* = "" */)
	{
		double * newDoubleArray = new double[4];
		newDoubleArray[0] = x;
		newDoubleArray[1] = y;
		newDoubleArray[2] = z;
		newDoubleArray[3] = angle;
		mRotate.push_back( std::make_pair(newDoubleArray, sid) );
	}

	//-----------------------------------------------------------------------
	void Node::addTranslate(const double & x, const double & y, const double & z, const std::string &sid /* = "" */)
	{
		double * newDoubleArray = new double[3];
		newDoubleArray[0] = x;
		newDoubleArray[1] = y;
		newDoubleArray[2] = z;
		mTranslate.push_back( std::make_pair(newDoubleArray, sid) );
	}



	//-----------------------------------------------------------------------
	Node::Node( const std::string &id, const std::string &name )
		: IElement(id)
		, mNode(NULL)
		, mName(name)
		, mUseMatrix(false)
		, mApplyRotationBeforeTranslation(true)
	{
	}

	//-----------------------------------------------------------------------
	Node::~Node( )
	{
		for ( size_t i = 0; i<mRotate.size(); ++i)
			delete[] mRotate[i].first;

		for ( size_t i = 0; i<mTranslate.size(); ++i)
			delete[] mTranslate[i].first;
	}

}
