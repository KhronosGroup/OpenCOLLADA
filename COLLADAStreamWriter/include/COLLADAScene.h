/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
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
