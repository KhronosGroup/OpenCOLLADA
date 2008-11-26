/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "HelperStableHeaders.h"
#include "COLLADAVerticesUtil.h"
#include "COLLADAInputUtil.h"
#include "COLLADASourceUtil.h"

namespace COLLADADH 
{    
    //-----------------------------------------------------------------------
    VerticesIterator::VerticesIterator( VerticesUtil* vertices )
        : mVertices(vertices)
        , mCount(mVertices->getVertexCount())
        , mCurrent(0)
    {
    }
    //-----------------------------------------------------------------------
    VerticesIterator::VerticesIterator( const VerticesIterator& iterator )
        : mVertices(iterator.mVertices)
        , mCurrent(0)
    {
    }
    //-----------------------------------------------------------------------
    VerticesIterator::~VerticesIterator()
    {
    }
    //-----------------------------------------------------------------------
    bool VerticesIterator::hasNext() const
    {
        return mCurrent < mCount;
    }
    //-----------------------------------------------------------------------
    void VerticesIterator::getNext( double position[3], double normal[3], double color[4], double uv[2] )
    {        
        peakNext(position, normal, color, uv);
        mCurrent++;
    }
    //-----------------------------------------------------------------------
    void VerticesIterator::getNext( Vertex& vertex )
    {
        getNext(vertex.position, vertex.normal, vertex.color, vertex.uv);
    }
    //-----------------------------------------------------------------------
    void VerticesIterator::peakNext( double position[3], double normal[3], double color[4], double uv[2] )
    {
        mVertices->getVertex(mCurrent, position, normal, color, uv);
    }
    //-----------------------------------------------------------------------
    void VerticesIterator::peakNext( Vertex& vertex )
    {
        peakNext(vertex.position, vertex.normal, vertex.color, vertex.uv);
    }
    //-----------------------------------------------------------------------
    const VerticesIterator& VerticesIterator::operator=( const VerticesIterator& iterator )
    {
        mVertices = iterator.mVertices;
        mCurrent = 0;
        mCount = mVertices->getVertexCount();
        return *this;
    }    
    //-----------------------------------------------------------------------
    Vertex::Vertex()
    {
        size_t size = sizeof(double);
        memset(position, 0, 3*size);
        memset(normal, 0, 3*size);
        memset(color, 0, 4*size);
        memset(uv, 0, 2*size);
    }
    //-----------------------------------------------------------------------
    bool operator==(const Vertex& v1, const Vertex& v2)
    {
        if(v1.position[0] != v2.position[0])
            return false;
        if(v1.position[1] != v2.position[1])
            return false;
        if(v1.position[2] != v2.position[2])
            return false;

        if(v1.normal[0] != v2.normal[0])
            return false;
        if(v1.normal[1] != v2.normal[1])
            return false;
        if(v1.normal[2] != v2.normal[2])
            return false;

        if(v1.color[0] != v2.color[0])
            return false;
        if(v1.color[1] != v2.color[1])
            return false;
        if(v1.color[2] != v2.color[2])
            return false;
        if(v1.color[3] != v2.color[3])
            return false;

        if(v1.uv[0] != v2.uv[0])
            return false;
        if(v1.uv[1] != v2.uv[1])
            return false;

        return true;
    }
    //-----------------------------------------------------------------------
    bool operator<(const Vertex& v1, const Vertex& v2)
    {
        if(v1.position[0] > v2.position[0])
            return false;
        if(v1.position[1] > v2.position[1])
            return false;
        if(v1.position[2] > v2.position[2])
            return false;

        if(v1.normal[0] > v2.normal[0])
            return false;
        if(v1.normal[1] > v2.normal[1])
            return false;
        if(v1.normal[2] > v2.normal[2])
            return false;

        if(v1.color[0] > v2.color[0])
            return false;
        if(v1.color[1] > v2.color[1])
            return false;
        if(v1.color[2] > v2.color[2])
            return false;
        if(v1.color[3] > v2.color[3])
            return false;

        if(v1.uv[0] > v2.uv[0])
            return false;
        if(v1.uv[1] > v2.uv[1])
            return false;

        return true;
    }
    //-----------------------------------------------------------------------
    bool operator>(const Vertex& v1, const Vertex& v2)
    {
        if(v1.position[0] < v2.position[0])
            return false;
        if(v1.position[1] < v2.position[1])
            return false;
        if(v1.position[2] < v2.position[2])
            return false;

        if(v1.normal[0] < v2.normal[0])
            return false;
        if(v1.normal[1] < v2.normal[1])
            return false;
        if(v1.normal[2] < v2.normal[2])
            return false;

        if(v1.color[0] < v2.color[0])
            return false;
        if(v1.color[1] < v2.color[1])
            return false;
        if(v1.color[2] < v2.color[2])
            return false;
        if(v1.color[3] < v2.color[3])
            return false;

        if(v1.uv[0] < v2.uv[0])
            return false;
        if(v1.uv[1] < v2.uv[1])
            return false;

        return true;
    }
    //-----------------------------------------------------------------------
    bool operator<=(const Vertex& v1, const Vertex& v2)
    {
        if(v1.position[0] >= v2.position[0])
            return false;
        if(v1.position[1] >= v2.position[1])
            return false;
        if(v1.position[2] >= v2.position[2])
            return false;

        if(v1.normal[0] >= v2.normal[0])
            return false;
        if(v1.normal[1] >= v2.normal[1])
            return false;
        if(v1.normal[2] >= v2.normal[2])
            return false;

        if(v1.color[0] >= v2.color[0])
            return false;
        if(v1.color[1] >= v2.color[1])
            return false;
        if(v1.color[2] >= v2.color[2])
            return false;
        if(v1.color[3] >= v2.color[3])
            return false;

        if(v1.uv[0] >= v2.uv[0])
            return false;
        if(v1.uv[1] >= v2.uv[1])
            return false;

        return true;
    }
    //-----------------------------------------------------------------------
    bool operator>=(const Vertex& v1, const Vertex& v2)
    {
        if(v1.position[0] <= v2.position[0])
            return false;
        if(v1.position[1] <= v2.position[1])
            return false;
        if(v1.position[2] <= v2.position[2])
            return false;

        if(v1.normal[0] <= v2.normal[0])
            return false;
        if(v1.normal[1] <= v2.normal[1])
            return false;
        if(v1.normal[2] <= v2.normal[2])
            return false;

        if(v1.color[0] <= v2.color[0])
            return false;
        if(v1.color[1] <= v2.color[1])
            return false;
        if(v1.color[2] <= v2.color[2])
            return false;
        if(v1.color[3] <= v2.color[3])
            return false;

        if(v1.uv[0] <= v2.uv[0])
            return false;
        if(v1.uv[1] <= v2.uv[1])
            return false;

        return true;
    }    
    //-----------------------------------------------------------------------
    size_t VerticesUtil::getVertexCount( const domVerticesRef& vertices )
    {
        domInputLocalRef positions = InputUtil::getInputLocal(vertices, COMMON_PROFILE_INPUT_POSITION);
        return InputUtil::getCount(positions);
    }    
    //-----------------------------------------------------------------------
    size_t VerticesUtil::getVertexCount() const
    {
        return getVertexCount(mVertices);
    }
    //-----------------------------------------------------------------------
    VerticesUtil::VerticesUtil( const domVerticesRef& vertices )
        :mVertices(vertices)
    {

    }
    //-----------------------------------------------------------------------
    VerticesIterator VerticesUtil::getIterator()
    {
        return VerticesIterator(this);
    }
    //-----------------------------------------------------------------------
    VerticesUtil::~VerticesUtil()
    {

    }
    //-----------------------------------------------------------------------
    void VerticesUtil::getVertex( size_t index, double position[3], double normal[3], double color[4], double uv[2] )
    {
        domInputLocal_Array& inputs = mVertices->getInput_array();
        for(size_t i=0, count=inputs.getCount(); i<count && i<4; ++i)
        {
            domInputLocalRef& input = inputs.get(i);
            domListOfFloats& values = InputUtil::getFloatValues(input);
            size_t stride = InputUtil::getStride(input);
            size_t offset = index * stride;

            if(strcmp(input->getSemantic(), COMMON_PROFILE_INPUT_POSITION)==0)
            {
                position[0] = values[offset];
                position[1] = values[offset+1];
                position[2] = values[offset+2];
            }
            else if(strcmp(input->getSemantic(), COMMON_PROFILE_INPUT_NORMAL)==0)
            {
                normal[0] = values[offset];
                normal[1] = values[offset+1];
                normal[2] = values[offset+2];
            }
            else if(strcmp(input->getSemantic(), COMMON_PROFILE_INPUT_COLOR)==0)
            {
                for (size_t j = 0; j < stride; ++j)
                {
                    color[j] = values[offset + j];
                }
            }
            else if(strcmp(input->getSemantic(), COMMON_PROFILE_INPUT_UV)==0)
            {
                uv[0] = values[offset];
                uv[1] = values[offset+1];
            }
        }
    }
    //-----------------------------------------------------------------------
    void VerticesUtil::getVertex( size_t index, Vertex& vertex )
    {
        getVertex(index, vertex.position, vertex.normal, vertex.color, vertex.uv);
    }
    //-----------------------------------------------------------------------
    void VerticesUtil::setVertex( size_t index, double position[3], double normal[3], double color[4], double uv[2] )
    {
        domInputLocal_Array& inputs = mVertices->getInput_array();
        for(size_t i=0, count=inputs.getCount(); i<count && i<4; ++i)
        {
            domInputLocalRef& input = inputs.get(i);
            domListOfFloats& values = InputUtil::getFloatValues(input);
            size_t stride = InputUtil::getStride(input);
            size_t offset = index * stride;

            if(strcmp(input->getSemantic(), COMMON_PROFILE_INPUT_POSITION))
            {
                values[offset] = position[offset];
                values[offset+1] = position[offset+1];
                values[offset+2] = position[offset+2];
            }
            else if(strcmp(input->getSemantic(), COMMON_PROFILE_INPUT_NORMAL))
            {
                values[offset] = normal[offset];
                values[offset+1] = normal[offset+1];
                values[offset+2] = normal[offset+2];
            }
            else if(strcmp(input->getSemantic(), COMMON_PROFILE_INPUT_COLOR))
            {
                values[offset] = color[offset];
                values[offset+1] = color[offset+1];
                values[offset+2] = color[offset+2];
                values[offset+3] = color[offset+3];
            }
            else if(strcmp(input->getSemantic(), COMMON_PROFILE_INPUT_UV))
            {
                values[offset] = uv[offset];
                values[offset+1] = uv[offset+1];
            }
        }
    }
    //-----------------------------------------------------------------------
    void VerticesUtil::setVertex( size_t index, Vertex& vertex )
    {
        setVertex(index, vertex.position, vertex.normal, vertex.color, vertex.uv);
    }
    //-----------------------------------------------------------------------
    void VerticesUtil::deleteVertex( size_t index )
    {
        domInputLocal_Array& inputs = mVertices->getInput_array();
        for(size_t i=0, count=inputs.getCount(); i<count && i<4; ++i)
        {
            domInputLocalRef& input = inputs.get(i);
            domListOfFloats& values = InputUtil::getFloatValues(input);
            size_t stride = InputUtil::getStride(input);
            size_t offset = index * stride;

            for(int j=(int)stride-1; j>=0; --i) 
            {
                values.removeIndex(offset+j);
            }
        }
    }
    //-----------------------------------------------------------------------
    void VerticesUtil::deleteVertices( const IndexSet& indices )
    {
        // iterate over all inputs
        domInputLocal_Array& inputs = mVertices->getInput_array();
        for(size_t i=0, count=inputs.getCount(); i<count && i<4; ++i)
        {            
            domInputLocalRef& input = inputs.get(i);
            domListOfFloats& values = InputUtil::getFloatValues(input);            
            size_t stride = InputUtil::getStride(input);
            size_t oldCount = values.getCount();
            size_t oldElementCount = oldCount/stride;

            domListOfFloats newValues;
            size_t newElementCount = oldElementCount-indices.size();
            size_t newCount = newElementCount*stride;
            
            newValues.grow(newCount);

            // iterate over all values to copy them
            for(size_t j=0; j<oldElementCount; ++j)
            {
                if(indices.find(j) != indices.end())
                {
                    //skip this values
                    continue;
                }

                // iterate over the elements of the current index.
                for(size_t s=0; s<stride; ++s)
                {
                    size_t offset = j+s;
                    newValues.append(values[offset]);
                }
            }

            values = newValues;
        }
    }
} // namespace CPF
