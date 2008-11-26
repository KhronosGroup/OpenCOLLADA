/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_P_UTIL_H__
#define __COLLADA_P_UTIL_H__

#include <dom/domConstants.h>
#include "COLLADADHStableHeaders.h"
#include "COLLADADHInputUtil.h"
#include "COLLADADHUtil.h"
#include "COLLADADHVerticesUtil.h"

namespace COLLADADH
{
    /** An iterator over the indices of a primitives. E.g. triangles.
    */
    template<class T>
    class IndicesIterator
    {
    private:
        T* mPrimitives;
        long mIndicesPerVertex;
        long mVertexOffset;
        long mNormalOffset;
        long mColorOffset;
        long mTexCoordOffset;
        domP_Array mPArray;

        size_t mCurrentP;
        size_t mCurrentVertex;

        size_t mVertexCount;

        bool mHasPerVertexNormals;
        bool mHasPerVertexColors;
        bool mHasPerVertexTexCoords;

    public:
        /** Creates an index iterator for the given primitives.
        */
        IndicesIterator(T* primitives)
            : mPrimitives(primitives)
            , mIndicesPerVertex(-1)
            , mVertexOffset(-1)
            , mNormalOffset(-1)
            , mColorOffset(-1)
            , mTexCoordOffset(-1)
            , mCurrentP(0)
            , mCurrentVertex(0)
            , mVertexCount(0)
            , mHasPerVertexNormals(false)
            , mHasPerVertexColors(false)
            , mHasPerVertexTexCoords(false)
        {
			setPArray(mPrimitives);
            init();
        }

		IndicesIterator(domP* indices)
			: mPrimitives((T*)indices->getParent())
			, mIndicesPerVertex(-1)
			, mVertexOffset(-1)
			, mNormalOffset(-1)
			, mColorOffset(-1)
			, mTexCoordOffset(-1)
			, mCurrentP(0)
			, mCurrentVertex(0)
			, mVertexCount(0)
		{
			setPArray(indices);
			init();
		}


        /** 
        	@return true if there are more indices.
        */
        bool hasNext() const 
        {
            if(mCurrentP >= mPArray.getCount())
                return false;

            const domPRef& p = mPArray.get(mCurrentP);
            if(mCurrentVertex*mIndicesPerVertex >= p->getValue().getCount())
                return false;

            return true;
        }


        /** Retrieves the next indices for vertex, normal, color and 
            texture coordinate and advances to the next indices. If
            the next indices belong to a new/next primitive (&lt;p&gt;)
            list the function returns true.
        	@param vertexIndex The vertex index. If invalid -1.
        	@param normalIndex The normal index. If invalid -1.
        	@param colorIndex The color index. If invalid -1.
        	@param texcoordIndex The texture coordinate index. If invalid -1.
        	@return true if a the next indices belong to the next primitive.
        */
        bool getNext(long& vertexIndex, long& normalIndex, long& colorIndex, long& texcoordIndex)
        {
            // peak the current value
            peakNext(vertexIndex, normalIndex, colorIndex, texcoordIndex);

            // advance pointer
            const domPRef& p = mPArray.get(mCurrentP);
            mCurrentVertex++;
            if(mCurrentVertex*mIndicesPerVertex >= p->getValue().getCount())
            {
                mCurrentVertex = 0;
                mCurrentP++;                
                return true;
            }
            return false;
        }

        /** Retrieves the current indices for vertex, normal, color and 
            texture coordinate.
            @param vertexIndex The vertex index. If invalid -1.
            @param normalIndex The normal index. If invalid -1.
            @param colorIndex The color index. If invalid -1.
            @param texcoordIndex The texture coordinate index. If invalid -1.
        */
        void peakNext(long& vertexIndex, long& normalIndex, long& colorIndex, long& texcoordIndex)
        {
            const domPRef& p = mPArray.get(mCurrentP);
            domListOfUInts& indices = p->getValue();
            size_t index = mCurrentVertex * mIndicesPerVertex;
            if(hasVertex())
            {
                vertexIndex = indices.get(index+mVertexOffset);
            }

            if(hasNormal())
            {
                if (mHasPerVertexNormals)
                {
                    normalIndex = indices.get(index+mVertexOffset);
                }
                else
                {
                    normalIndex = indices.get(index+mNormalOffset);
                }
            }
            
            if(hasColor())
            {
                if (mHasPerVertexColors)
                {
                    colorIndex = indices.get(index+mVertexOffset);
                }
                else
                {
                    colorIndex = indices.get(index+mColorOffset);
                }
            }
            
            if(hasTexCoord())
            {
                if (mHasPerVertexTexCoords)
                {
                    texcoordIndex = indices.get(index+mVertexOffset);
                }
                else
                {
                    texcoordIndex = indices.get(index+mTexCoordOffset);
                }
            }            
        }

        /** 
        	@return true if the primitives has vertex.
        */
        bool hasVertex() const {return mVertexOffset >= 0?true:false;}
        /** 
        @return true if the primitives has normal.
        */
        bool hasNormal() const {return (mNormalOffset >= 0) || mHasPerVertexNormals ? true:false;}
        /** 
        @return true if the primitives has color.
        */
        bool hasColor() const {return (mColorOffset >= 0) || mHasPerVertexColors ? true:false;}
        /** 
        @return true if the primitives has texture coordinate.
        */
        bool hasTexCoord() const {return (mTexCoordOffset >= 0) || mHasPerVertexTexCoords ? true:false;}

        /** 
        	@return The overall vertex count for the primitive.
        */
        size_t getVertexCount() const {return mVertexCount;}

        bool hasPerVertexNormals() const { return mHasPerVertexNormals; }
        bool hasPerVertexColors() const { return mHasPerVertexColors; }
        bool hasPerVertexTexCoords() const { return mHasPerVertexTexCoords; }

    private:
		void setPArray(T* primitives)
		{
			getChildrenOfType<domP>(mPrimitives, COLLADA_TYPE::P, mPArray);
		}
		void setPArray(domP* indices)
		{
			mPArray.append(indices);
		}

        void init()
        {            
            mIndicesPerVertex = (long)InputUtil::getMaxInputLocalOffset( mPrimitives->getInput_array() ) + 1;          
            
            domInputLocalOffset_Array& inputs = mPrimitives->getInput_array();
            for(long i=0, count=(long)inputs.getCount(); i<count; ++i)
            {
                const domInputLocalOffsetRef& input = inputs.get(i);
                if(strcmp(input->getSemantic(), COMMON_PROFILE_INPUT_VERTEX) == 0)
                {
                    mVertexOffset = i;

                    domVertices* vertices = daeSafeCast<domVertices>(input->getSource().getElement());
                    if (vertices)
                    {
                        if (InputUtil::getPerVertexData(*vertices, COMMON_PROFILE_INPUT_NORMAL))
                        {
                            mHasPerVertexNormals = true;
                        }
                        if (InputUtil::getPerVertexData(*vertices, COMMON_PROFILE_INPUT_COLOR))
                        {
                            mHasPerVertexColors = true;
                        }
                        if (InputUtil::getPerVertexData(*vertices, COMMON_PROFILE_INPUT_TEXCOORD))
                        {
                            mHasPerVertexTexCoords = true;
                        }
                    }
                }
                else if(strcmp(input->getSemantic(), COMMON_PROFILE_INPUT_NORMAL) == 0)
                {
                    mNormalOffset = i;
                }
                else if(strcmp(input->getSemantic(), COMMON_PROFILE_INPUT_COLOR) == 0)
                {
                    mColorOffset = i;
                }
                else if(strcmp(input->getSemantic(), COMMON_PROFILE_INPUT_TEXCOORD) == 0)
                {
                    mTexCoordOffset = i;
                }
            }            

            for(size_t p=0,pcount=mPArray.getCount(); p<pcount; ++p)
            {
                const domPRef& indices = mPArray.get(p);
                mVertexCount += indices->getValue().getCount()/mIndicesPerVertex;
            }
        }
    };
    
    typedef std::set<size_t> SizeTSet;

    template<class T>
        void getUsedIndices( const daeSmartRef<T>& primitives, SizeTSet &vertexIndices, SizeTSet &normalIndices, SizeTSet &colorIndices=SizeTSet(), SizeTSet &texcoordIndices=SizeTSet() )
    {
        IndicesIterator<T> it(primitives);
        while(it.hasNext())
        {
            long vertexIndex;
            long normalIndex;
            long colorIndex;
            long texcoordIndex;
            it.getNext(vertexIndex, normalIndex, colorIndex, texcoordIndex);
            if(it.hasVertex())
            {
                vertexIndices.insert(vertexIndex);
            }
            if(it.hasNormal())
            {
                normalIndices.insert(normalIndex);
            }
            if(it.hasColor())
            {
                colorIndices.insert(colorIndex);
            }
            if(it.hasTexCoord())
            {
                texcoordIndices.insert(texcoordIndex);
            }            
        }
    }    
}

#endif
