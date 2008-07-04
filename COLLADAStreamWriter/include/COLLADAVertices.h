/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
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
