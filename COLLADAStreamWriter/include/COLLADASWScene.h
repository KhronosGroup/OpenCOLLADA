/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_SCENE_H__
#define __COLLADASTREAMWRITER_SCENE_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADABUURI.h"
#include <string>

namespace COLLADASW
{


    /** A class to add a @a \<scene\> element to the stream*/

    class Scene : public ElementWriter
    {

    private:

        /** The url of the instance visual scene.*/
        COLLADABU::URI mInstanceVisualSceneUrl;

    public:
        /** Constructor that sets the stream the scene should be written to*/
        Scene ( StreamWriter * streamWriter, COLLADABU::URI instanceURI ) 
        : ElementWriter ( streamWriter ) 
        , mInstanceVisualSceneUrl ( instanceURI )
        {}

        /** Adds the scene to the stream, i.e. performes the actual writing*/
        void add();
    };

} //namespace COLLADASW



#endif //__COLLADASTREAMWRITER_SCENE_H__
