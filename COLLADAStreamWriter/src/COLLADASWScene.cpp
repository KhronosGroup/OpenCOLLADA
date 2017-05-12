/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASWScene.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{


    //---------------------------------------------------------------
    void Scene::add()
    {

		if (exportScene || exportPhysics)
		{
		
			mSW->openElement ( CSWC::CSW_ELEMENT_SCENE );
        
			if (exportPhysics)
			{
				mSW->openElement(CSWC::CSW_ELEMENT_INSTANCE_PHYSICS_SCENE);
				mSW->appendURIAttribute(CSWC::CSW_ATTRIBUTE_URL, mInstancePhysicsSceneUrl);
				mSW->closeElement();
			}

			if (exportScene)
			{
				mSW->openElement ( CSWC::CSW_ELEMENT_INSTANCE_VISUAL_SCENE );
				mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_URL, mInstanceVisualSceneUrl );
				mSW->closeElement();
			}

			mSW->closeElement();
		}
    }

} //namespace COLLADASW
