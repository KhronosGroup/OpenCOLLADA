/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_SCENE_H__
#define __COLLADASTREAMWRITER_SCENE_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include <string>

namespace COLLADA
{


    /** A class to add a @a \<scene\> element to the stream*/

    class Scene : public ElementWriter
    {

    public:
        /** Constructor that sets the stream the scene should be written to*/
        Scene ( StreamWriter * streamWriter ) : ElementWriter ( streamWriter ) {}

        /** Adds the scene to the stream, i.e. performes the actual writing*/
        void add();


        /** The url of the instance visual scene.*/
        String mInstanceVisualSceneUrl;
    };

} //namespace COLLADA



#endif //__COLLADASTREAMWRITER_SCENE_H__
