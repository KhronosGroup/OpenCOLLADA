#include "HelperStableHeaders.h"
#include "COLLADANodeTraverser.h"

namespace COLLADADomHelper
{
	//-----------------------------------------------------------------------
	NodeTraverser::NodeTraverser(daeElement &nodeContainer)
		: mNodeContainer(nodeContainer)
		, mOnlyThisLevel(false)
	{
	}

	//-----------------------------------------------------------------------
	NodeTraverser::~NodeTraverser()
	{
	}

	//-----------------------------------------------------------------------
	bool NodeTraverser::traverse(NodeTraverser::TraverserListener &listener, int level)
	{
		bool bRet = false;

        domCOLLADA::domScene* scene = daeSafeCast<domCOLLADA::domScene>(&mNodeContainer);
		domVisual_scene* vs = daeSafeCast<domVisual_scene>(&mNodeContainer);
		domNode* node = daeSafeCast<domNode>(&mNodeContainer);
		domLibrary_nodes *libNodes = daeSafeCast<domLibrary_nodes>(&mNodeContainer);

        if(scene)
        {
            bRet = traverseScene(*scene, ++level, listener);
        }
		else if (vs)
		{
			bRet = traverseVisualScene(*vs, ++level, listener);
		}
		else if (node)
		{
			bRet = traverseNode(*node, ++level, listener);
		}
		else if (libNodes)
		{
			bRet = traverseLibraryNodes(*libNodes, ++level, listener);		
		}

		return bRet;
	}
    //-----------------------------------------------------------------------
    bool NodeTraverser::traverseScene( domCOLLADA::domScene &scene, int level, TraverserListener &listener )
    {
        domInstanceWithExtraRef vsceneInstance = scene.getInstance_visual_scene();
        //vsceneInstance->getDAE()->resolveAll();
       
        domVisual_sceneRef vscene = daeSafeCast<domVisual_scene>(vsceneInstance->getUrl().getElement());
        if(vscene==0)
            return false;

        return traverseVisualScene(*vscene, level, listener);
    }
	//-----------------------------------------------------------------------
	bool NodeTraverser::traverseVisualScene(domVisual_scene &vs, int level, TraverserListener &listener)
	{
		bool bRet = true;

		const domNode_Array &array = vs.getNode_array();
		for (size_t i = 0; i < array.getCount(); i++)
		{
			domNode* node = array.get(i);
			if (listener.preDetectedNode(*node, level))
			{
				if (traverseNode(*node, level + 1, listener))
				{
					if (!listener.postDetectedNode(*node, level))
					{
						bRet &= false;			
						break;
					}
				}
				else
				{
					bRet &= false;			
					break;
				}
			}
			else
			{
				bRet &= false;			
				break;
			}
		}

		return bRet;
	}

	//-----------------------------------------------------------------------
	bool NodeTraverser::traverseNode(domNode &node, int level, TraverserListener &listener)
	{
		bool bRet = true;


		const domInstance_camera_Array &instanceCameraArray = node.getInstance_camera_array();
		for (size_t i = 0; i < instanceCameraArray.getCount(); i++)
		{
			domInstance_camera* instance = instanceCameraArray.get(i);
			bRet &= listener.detectedInstanceCamera(*instance, level);			
		}


		const domInstance_controller_Array &instanceControllerArray = node.getInstance_controller_array();
		for (size_t i = 0; i < instanceControllerArray.getCount(); i++)
		{
			domInstance_controller* instance = instanceControllerArray.get(i);
			bRet &= listener.detectedInstanceController(*instance, level);			
		}


		const domInstance_geometry_Array &instanceGeometryArray = node.getInstance_geometry_array();
		for (size_t i = 0; i < instanceGeometryArray.getCount(); i++)
		{
			domInstance_geometry* instance = instanceGeometryArray.get(i);
			bRet &= listener.detectedInstanceGeometry(*instance, level);			
		}


		const domInstance_light_Array &instanceLightArray = node.getInstance_light_array();
		for (size_t i = 0; i < instanceLightArray.getCount(); i++)
		{
			domInstance_light* instance = instanceLightArray.get(i);
			bRet &= listener.detectedInstanceLight(*instance, level);			
		}

		const domInstance_node_Array &instanceNodeArray = node.getInstance_node_array();
		for (size_t i = 0; i < instanceNodeArray.getCount(); i++)
		{
			domInstance_node* instance = instanceNodeArray.get(i);
			bRet &= listener.detectedInstanceNode(*instance, level);			
		}


		if (!mOnlyThisLevel)
		{
			const domNode_Array &nodeArray = node.getNode_array();
			for (size_t i = 0; i < nodeArray.getCount(); i++)
			{
				domNode* node = nodeArray.get(i);
				if (listener.preDetectedNode(*node, level))
				{
					if (traverseNode(*node, level + 1, listener))
					{
						if (!listener.postDetectedNode(*node, level))
						{
							bRet &= false;			
							break;
						}
					}
					else
					{
						bRet &= false;			
						break;
					}
				}
				else
				{
					bRet &= false;			
					break;
				}
			}
		}

		const domExtra_Array &extraArray = node.getExtra_array();
		for (size_t i = 0; i < extraArray.getCount(); i++)
		{
			domExtra* extra = extraArray.get(i);
			bRet &= listener.detectedNodeExtra(*extra, level);
		}

		return bRet;
	}

	//-----------------------------------------------------------------------
	bool NodeTraverser::traverseLibraryNodes(domLibrary_nodes &libNodes, int level, TraverserListener &listener)
	{
		bool bRet = true;

		const domNode_Array &array = libNodes.getNode_array();
		for (size_t i = 0; i < array.getCount(); i++)
		{
			domNode* node = array.get(i);
			if (listener.preDetectedNode(*node, level))
			{
				if (traverseNode(*node, level + 1, listener))
				{
					if (!listener.postDetectedNode(*node, level))
					{
						bRet &= false;			
						break;
					}
				}
				else
				{
					bRet &= false;			
					break;
				}
			}
			else
			{
				bRet &= false;			
				break;
			}
		}

		return bRet;
	}

	//-----------------------------------------------------------------------
	void NodeTraverser::setOnlyThisLevel( bool onlyThisLevel )
	{
		mOnlyThisLevel = onlyThisLevel;
	}

}
