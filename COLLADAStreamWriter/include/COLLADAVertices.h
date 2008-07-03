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

#ifndef __COLLADASTREAMWRITER_VERTEX_H__
#define __COLLADASTREAMWRITER_VERTEX_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include "COLLADAInputList.h"

namespace COLLADA
{

    class Vertices : public ElementWriter
    {

    public:
        Vertices ( StreamWriter* streamWriter )
                : ElementWriter ( streamWriter ),
                mInputList ( streamWriter ),
                mNodeId ( "" ),
                mNodeName ( "" )
        {}

        /** Returns a reference to the id of the vertex element*/
        const String& getId() const
        {
            return mNodeId;
        }

        /** Sets the id of the vertex element*/
        void setId ( const String& id )
        {
            mNodeId = id;
        }

        /** Returns a reference to the name of the vertex element*/
        const String& getNodeName() const
        {
            return mNodeName;
        }

        /** Sets the id of the vertex element*/
        void setNodeName ( const String& nodeName )
        {
            mNodeName = nodeName;
        }

        /** Returns a reference to the inputlist */
        InputList& getInputList()
        {
            return mInputList;
        }

        /** Adds the vertex to the stream*/
        void add();

    private:
        /** The id of the vertex element*/
        String mNodeId;

        /** The name of the vertex node*/
        String mNodeName;

        /** List of all the inputs*/
        InputList mInputList;

    };


} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_VERTEX_H__
