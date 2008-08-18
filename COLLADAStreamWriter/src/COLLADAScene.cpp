/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAScene.h"
#include "COLLADASWC.h"

namespace COLLADA
{


    //---------------------------------------------------------------
    void Scene::add()
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_SCENE );
        mSW->openElement ( CSWC::COLLADA_ELEMENT_INSTANCE_VISUAL_SCENE );
        mSW->appendURIAttribute ( CSWC::COLLADA_ATTRIBUTE_URL, mInstanceVisualSceneUrl );
        mSW->closeElement();
        mSW->closeElement();
    }

} //namespace COLLADA
