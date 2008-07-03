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

#ifndef __COLLADASTREAMWRITER_INSTANCE_GEOMETRY_H__
#define __COLLADASTREAMWRITER_INSTANCE_GEOMETRY_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include "COLLADABindMaterial.h"

#include <string>

namespace COLLADA
{

    class InstanceGeometry : public ElementWriter
    {

    public:
        InstanceGeometry ( StreamWriter * streamWriter ) : ElementWriter ( streamWriter ), mBindMaterial ( streamWriter ) {}

        /** Sets the url of the instance geometry*/
        void setUrl ( const String url )
        {
            mUrl=url;
        }

        /** Returns the url of the instance geometry*/
        const String & getUrl()
        {
            return mUrl;
        }

        BindMaterial & getBindMaterial()
        {
            return mBindMaterial;
        }

        /** Adds the instance geometry to the stream*/
        void add();

    private:
        BindMaterial mBindMaterial;

        /** The URL of the location of the object to instantiate.*/
        String mUrl;
    };


} //namespace COLLADA




#endif //__COLLADASTREAMWRITER_INSTANCE_GEOMETRY_H__

