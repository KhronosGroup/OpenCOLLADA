/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "HelperStableHeaders.h"
#include "COLLADATriangleIterator.h"
#include "COLLADAException.h"

namespace COLLADADomHelper
{
    //-----------------------------------------------------------------------
    TriangleIterator::TriangleIterator( const domPRef& p )
            : mCurrentVertexIndex( 0 )
            , mVertices( 0 )
            , mNormals( 0 )
            , mColors( 0 )
            , mTextures( 0 )
            , mP( p )
			, mHasNormals(false)
			, mHasTexCoords(false)
			, mHasColors(false)
    {
		if(p == 0) {
			return;
		}

        daeElement* parent = p->getParentElement();
        
        if(daeSafeCast<domTriangles>(parent) != 0)
        {   
            domTriangles* tris = daeSafeCast<domTriangles>(parent);
            domInputLocalOffset_Array& inputs = tris->getInput_array();
            init<domInputLocalOffset_Array, domInputLocalOffset>(inputs);
            mTriangleCount = tris->getCount();
            mVertexCount = mTriangleCount * 3;
            mType = OT_TRIANGLE_LIST;
        }
        else if(daeSafeCast<domTrifans>(parent) != 0)
        {
            domTrifans* tris = daeSafeCast<domTrifans>(parent);
            domInputLocalOffset_Array& inputs = tris->getInput_array();
            init<domInputLocalOffset_Array, domInputLocalOffset>(inputs);
            mTriangleCount = (p->getValue().getCount() / mIndexedDataOrder.size())-2;
            mVertexCount = mTriangleCount * 3;
            mType = OT_TRIANGLE_FAN;
        }
        else if(daeSafeCast<domTristrips>(parent) != 0)
        {
            domTristrips* tris = daeSafeCast<domTristrips>(parent);
            domInputLocalOffset_Array& inputs = tris->getInput_array();
            init<domInputLocalOffset_Array, domInputLocalOffset>(inputs);
            mTriangleCount = (p->getValue().getCount() / mIndexedDataOrder.size())-2;
            mVertexCount = mTriangleCount * 3;
            mType = OT_TRIANGLE_STRIP;
        }
		else if (daeSafeCast<domLines>(parent) != 0)
		{
			domLines* lines = daeSafeCast<domLines>(parent);
			domInputLocalOffset_Array& inputs = lines->getInput_array();
			init<domInputLocalOffset_Array, domInputLocalOffset>(inputs);
			mTriangleCount = lines->getCount();
			mVertexCount = mTriangleCount * 2;
			mType = OT_LINE_LIST;
		}
		else if (daeSafeCast<domLinestrips>(parent) != 0)
		{
			domLinestrips* lines = daeSafeCast<domLinestrips>(parent);
			domInputLocalOffset_Array& inputs = lines->getInput_array();
			init<domInputLocalOffset_Array, domInputLocalOffset>(inputs);
			mTriangleCount = (p->getValue().getCount() / mIndexedDataOrder.size())-1;
			mVertexCount = mTriangleCount * 2;
			mType = OT_LINE_STRIP;
		}
        else
        {
            COLLADA_EXCEPT(COLLADADomHelper::Exception::ERR_INTERNAL_ERROR, "", "TriangleIterator::TriangleIterator");
        }
    }
	//-----------------------------------------------------------------------
	TriangleIterator::TriangleIterator( const domTrianglesRef& triangles )
		: mCurrentVertexIndex( 0 )
		, mVertices( 0 )
		, mNormals( 0 )
		, mColors( 0 )
		, mTextures( 0 )
		, mP( triangles->getP() )
		, mHasNormals(false)
		, mHasTexCoords(false)
		, mHasColors(false)
	{
		domInputLocalOffset_Array& inputs = triangles->getInput_array();
		init<domInputLocalOffset_Array, domInputLocalOffset>(inputs);
		mTriangleCount = triangles->getCount();
		mVertexCount = mTriangleCount * 3;
		mType = OT_TRIANGLE_LIST;
	}
    //-----------------------------------------------------------------------
    TriangleIterator::~TriangleIterator()
    {}
    //-----------------------------------------------------------------------
    template <typename T, typename U>
    void TriangleIterator::init( const T &array )

    {
        for ( daeUInt i = 0; i < array.getCount(); i++ )
        {
            U *input = array.get( i );

            size_t offset = 0;
            if (input->getElementType() == COLLADA_TYPE::INPUTLOCALOFFSET)
            {
                offset = (size_t)(daeSafeCast<domInputLocalOffset>(input))->getOffset();

                if ( mIndexedDataOrder.size() <= offset )
                {
                    for ( size_t j = mIndexedDataOrder.size(); j <= offset; j++ )
                    {
                        mIndexedDataOrder.push_back( OTHER );
                    }
                }
            }

            int order = mIndexedDataOrder[ offset ];
            input->getSource().resolveElement();

            if (!initVertex(input, &order))
            {
                if (!initNormal(input, &order))
                {
                    if (!initColor(input, &order))
                    {
                        initTexcoord(input, &order);
                    }
                }
            }

            Order typedOrder = Order( order );
            if (input->getElementType() == COLLADA_TYPE::INPUTLOCALOFFSET)
            {
                mIndexedDataOrder[ offset ] = typedOrder;
            }
            else
            {
                if ( !strcmp( input->getSemantic(), COMMON_PROFILE_INPUT_POSITION ) == 0 )
                {
                    mPerVertexDataOrder.push_back( typedOrder );
                }
            }
            // TODO log warning when typedOrder == OTHER
        }
    }
    //-----------------------------------------------------------------------
    template <typename T>
    bool TriangleIterator::initVertex(T* const input, int* const order)
    {
        if ( strcmp( input->getSemantic(), COMMON_PROFILE_INPUT_VERTEX ) == 0 )
        {
            *order |= VERTEX;
            mVertices = daeSafeCast<domVertices>( input->getSource().getElement());

            domInputLocal_Array& inputs = mVertices->getInput_array();
            init<domInputLocal_Array, domInputLocal>(inputs);

            return true;
        }
        return false;
    }
    //-----------------------------------------------------------------------
    template <typename T>
    bool TriangleIterator::initNormal(T* const input, int* const order)
    {
        if ( strcmp( input->getSemantic(), COMMON_PROFILE_INPUT_NORMAL ) == 0 )
        {
            *order |= NORMAL;
            mNormals = daeSafeCast<domSource>( input->getSource().getElement());
            mHasNormals = true;
            return true;
        }
        return false;
    }
    //-----------------------------------------------------------------------
    template <typename T>
    bool TriangleIterator::initColor(T* const input, int* const order)
    {
        if ( strcmp( input->getSemantic(), COMMON_PROFILE_INPUT_COLOR ) == 0 )
        {
            *order |= COLOR;
            mColors = daeSafeCast<domSource>( input->getSource().getElement() );
            mHasColors = true;
            return true;
        }
        return false;
    }
    //-----------------------------------------------------------------------
    template <typename T>
    bool TriangleIterator::initTexcoord(T* const input, int* const order)
    {
        if ( strcmp( input->getSemantic(), COMMON_PROFILE_INPUT_TEXCOORD ) == 0 )
        {
            *order |= TEXCOORD;
            mTextures = daeSafeCast<domSource>( input->getSource().getElement() );
            mHasTexCoords = true;
            return true;
        }
        return false;
    }
    //-----------------------------------------------------------------------
    bool TriangleIterator::hasMoreVertex()
    {
        bool bRet = false;
		
		if (mVertices != 0 && mCurrentVertexIndex < mVertexCount ) 
		{
            bRet = true;
		}

        return bRet;
    }

    //-----------------------------------------------------------------------
    void TriangleIterator::nextVertex()
    {
        mCurrentVertexIndex++;
    }

    //-----------------------------------------------------------------------
    void TriangleIterator::getVertex( domFloat *position, domFloat *normal, domFloat *color, domFloat *tex, int &_order )
    {
        size_t numElementsToRead = mIndexedDataOrder.size();

        domListOfUInts &list = mP->getValue();
        _order = 0;
        for ( size_t i = 0; i < numElementsToRead; i++ )
        {
            size_t indexInPList = i + mCurrentVertexIndex * numElementsToRead;
            if((mType == OT_TRIANGLE_FAN || mType == OT_TRIANGLE_STRIP) && mCurrentVertexIndex > 2)
            {
                size_t currentTriangle = mCurrentVertexIndex/3;
                size_t shift = 2 * numElementsToRead * currentTriangle;
                indexInPList -= shift;
            }
			if((mType == OT_LINE_STRIP) && mCurrentVertexIndex > 1)
			{
				size_t currentTriangle = mCurrentVertexIndex/2;
				size_t shift = 1 * numElementsToRead * currentTriangle;
				indexInPList -= shift;
			}
			            
            size_t index = (size_t)list.get( indexInPList );
            Order order = mIndexedDataOrder[ i ];

            if ( order & VERTEX )
            {
                getPosition( (size_t)index, position );
                _order |= order;

                for ( size_t j = 0; j < mPerVertexDataOrder.size(); ++j )
                {
                    if ( mPerVertexDataOrder[j] & NORMAL )
                    {
                        getNormal( index, normal );
                        _order |= NORMAL;
                    }

                    else if ( mPerVertexDataOrder[j] & COLOR )
                    {
                        getColor(index, color);
                        _order |= COLOR;
                    }

                    else if ( mPerVertexDataOrder[j] & TEXCOORD )
                    {
                        getTexCoord(index, tex);
                        _order |= TEXCOORD;
                    }
                }
            }

            else if ( order & NORMAL )
            {
                getNormal( index, normal );
                _order |= order;
            }

            else if ( order & COLOR )
            {
                getColor(index, color);
                _order |= order;
            }

            else if ( order & TEXCOORD )
            {
                getTexCoord(index, tex);
                _order |= order;
            }
        }
    }
    //-----------------------------------------------------------------------
    void TriangleIterator::getPosition( const size_t index, domFloat* position )
    {
        domInputLocal_Array & is = mVertices->getInput_array();

        for ( size_t j = 0; j < is.getCount(); j++ )
        {
            domInputLocalRef input = is.get( j );
            xsNMTOKEN semantic = input->getSemantic();

            if ( strcmp( semantic, COMMON_PROFILE_INPUT_POSITION ) == 0 )
            {
                domSourceRef source( daeSafeCast<domSource>( input ->getSource().getElement() ) );
                domFloat_arrayRef floatArray = source->getFloat_array();
                domListOfFloats& values = floatArray->getValue();
                size_t count = values.getCount();

                CPFAssert( index * 3 < count , "index < count" );

                domFloat x, y, z;
                values.get3at( index * 3, x, y, z );
                position[ 0 ] = x;
                position[ 1 ] = y;
                position[ 2 ] = z;
            }
        }
    }

    //-----------------------------------------------------------------------
    void TriangleIterator::getNormal( const size_t index, domFloat* normal )
    {
        domFloat_arrayRef floatArray = mNormals->getFloat_array();
        domListOfFloats & values = floatArray->getValue();
        size_t count = values.getCount();

        CPFAssert( index * 3 < count , "index < count" );

        domFloat x, y, z;
        values.get3at( index * 3, x, y, z );
        normal[ 0 ] = x;
        normal[ 1 ] = y;
        normal[ 2 ] = z;

    }

    //-----------------------------------------------------------------------
    void TriangleIterator::getColor( const size_t index, domFloat* color )
    {
        domFloat_arrayRef floatArray = mColors->getFloat_array();
        domListOfFloats & values = floatArray ->getValue();
        size_t count = values.getCount();

        CPFAssert( index * 3 < count , "index < count" );

        domFloat r, g, b;
        values.get3at( index * 3, r, g, b);
        color[ 0 ] = r;
        color[ 1 ] = g;
        color[ 2 ] = b;


    }

    //-----------------------------------------------------------------------
    void TriangleIterator::getTexCoord( const size_t index, domFloat* texCoord )
    {
        domListOfFloats & floats = mTextures->getFloat_array() ->getValue();
		domSource::domTechnique_commonRef technique = mTextures->getTechnique_common();
		domAccessorRef accessor = technique->getAccessor();
		size_t stride = (size_t)accessor->getStride();
        size_t count = floats.getCount();

        CPFAssert( index * stride < count , "index < count" );

		for (size_t i = 0; i < stride; i++)
		{
			texCoord[ i ] = floats.get(index*stride + i);
		}

    }
    
    //-----------------------------------------------------------------------
    size_t TriangleIterator::getVertexCount( const domVerticesRef& vertices )
    {
        domInputLocal_Array & is = mVertices->getInput_array();

        for ( size_t j = 0; j < is.getCount(); j++ )
        {
            domInputLocalRef input = is.get( j );
            xsNMTOKEN semantic = input->getSemantic();

            if ( strcmp( semantic, COMMON_PROFILE_INPUT_POSITION ) == 0 )
            {
                domSourceRef source( daeSafeCast<domSource>( input ->getSource().getElement() ) );
                domFloat_arrayRef floatArray = source->getFloat_array();
                domListOfFloats& values = floatArray->getValue();
                return values.getCount()/3;               
            }
        }
        return -1;
    }    

    //-----------------------------------------------------------------------
    bool TriangleIterator::areNormalsPerVertex() const
    {
        for (size_t i=0; i<mPerVertexDataOrder.size(); ++i)
        {
            if (mPerVertexDataOrder[i] == NORMAL)
            {
                return true;
            }
        }
        return false;
    }

    //-----------------------------------------------------------------------
    bool TriangleIterator::areColorsPerVertex() const
    {
        for (size_t i=0; i<mPerVertexDataOrder.size(); ++i)
        {
            if (mPerVertexDataOrder[i] == COLOR)
            {
                return true;
            }
        }
        return false;
    }

    //-----------------------------------------------------------------------
    bool TriangleIterator::areTexCoordsPerVertex() const
    {
        for (size_t i=0; i<mPerVertexDataOrder.size(); ++i)
        {
            if (mPerVertexDataOrder[i] == TEXCOORD)
            {
                return true;
            }
        }
        return false;
    }

	//-----------------------------------------------------------------------
	unsigned int TriangleIterator::getTexCoordSize() const
	{
		if (mTextures)
		{
			domSource::domTechnique_commonRef technique = mTextures->getTechnique_common();
			domAccessorRef accessor = technique->getAccessor();
			size_t stride = (size_t)accessor->getStride();
			return ( unsigned int) stride;
		}
		return 0;
	}
}
