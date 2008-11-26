/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADADHStableHeaders.h"
#include "COLLADADHReader.h"

namespace COLLADADH
{
	//-----------------------------------------------------------------------
	Reader::Reader(daeDocument &doc)
		:	mDoc(doc)
	{
	}

	//-----------------------------------------------------------------------
	Reader::~Reader()
	{
	}

	//-----------------------------------------------------------------------
	Reader::ElementIterator<domVisual_scene> Reader::getVisualScenes()
	{
		domCOLLADA *domRoot = daeSafeCast<domCOLLADA>( mDoc.getDomRoot() );
		domLibrary_visual_scenes_Array vsa = domRoot->getLibrary_visual_scenes_array();
		std::vector<domVisual_scene*> array;
		for (size_t i = 0; i < vsa.getCount(); i++)
		{
			domLibrary_visual_scenesRef ref = vsa.get(i);
			const domVisual_scene_Array vs = ref->getVisual_scene_array();
			for (size_t j = 0; j < vs.getCount(); j++)
			{
				array.push_back(vs.get(j));
			}
		}
		return ElementIterator<domVisual_scene>(array);
	}	

	//------------------------------
	Reader::ElementIterator<domMaterial> Reader::getMaterials()
	{
		domCOLLADA *domRoot = daeSafeCast<domCOLLADA>( mDoc.getDomRoot() );
		domLibrary_materials_Array mats = domRoot->getLibrary_materials_array();
		std::vector<domMaterial*> array;
		for (size_t i = 0; i < mats.getCount(); i++)
		{
			domLibrary_materialsRef ref = mats.get(i);
			const domMaterial_Array mat = ref->getMaterial_array();
			for (size_t j = 0; j < mat.getCount(); j++)
			{
				array.push_back(mat.get(j));
			}
		}
		return ElementIterator<domMaterial>(array);
	}

    //------------------------------
	Reader::ElementIterator<domLibrary_nodes> Reader::getLibNodes()
	{

		domCOLLADA *domRoot = daeSafeCast<domCOLLADA>( mDoc.getDomRoot() );
		domLibrary_nodes_Array mats = domRoot->getLibrary_nodes_array();
		std::vector<domLibrary_nodes*> array;
		for (size_t i = 0; i < mats.getCount(); i++)
		{
			array.push_back(mats.get(i));
			
		}
		return ElementIterator<domLibrary_nodes>(array);
	}

}
