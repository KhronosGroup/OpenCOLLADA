/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWMeshPrimitive.h"
#include "COLLADAFWPolygons.h"
#include "COLLADAFWMeshPrimitiveWithFaceVertexCount.h"
#include "COLLADAFWTrifans.h"
#include "COLLADAFWTristrips.h"
#include "COLLADAFWLinestrips.h"


namespace COLLADAFW
{



    //-----------------------------
	MeshPrimitive::MeshPrimitive ( const UniqueId& uniqueId )
        : ObjectTemplate<COLLADA_TYPE::PRIMITIVE_ELEMENT>(uniqueId)
        , mPrimitiveType ( UNDEFINED_PRIMITIVE_TYPE )
	    , mFaceCount ( 0 )
		, mMaterialId(0)
		, mPositionIndices(UIntValuesArray::OWNER)
		, mNormalIndices(UIntValuesArray::OWNER)
		, mColorIndicesArray(UIntValuesArray::OWNER)
		, mUVCoordIndicesArray(UIntValuesArray::OWNER)
	{
	}

    //-----------------------------
	MeshPrimitive::MeshPrimitive( const UniqueId& uniqueId, PrimitiveType primitiveType )
        : ObjectTemplate<COLLADA_TYPE::PRIMITIVE_ELEMENT>(uniqueId)
		, mPrimitiveType ( primitiveType )
		, mFaceCount ( 0 )
		, mMaterialId(0)
		, mPositionIndices(UIntValuesArray::OWNER)
		, mNormalIndices(UIntValuesArray::OWNER)
		, mColorIndicesArray(UIntValuesArray::OWNER)
		, mUVCoordIndicesArray(UIntValuesArray::OWNER)
	{
	}

    //-----------------------------
	MeshPrimitive::~MeshPrimitive()
	{
		for ( size_t i = 0, count = mUVCoordIndicesArray.getCount(); i< count; ++i)
		{
			FW_DELETE mUVCoordIndicesArray[i];
		}

		for ( size_t i = 0, count = mColorIndicesArray.getCount(); i< count; ++i)
		{
			FW_DELETE mColorIndicesArray[i];
		}
	}

    //-----------------------------
    const int MeshPrimitive::getGroupedVerticesVertexCount( const size_t faceIndex ) const
    {
        switch ( mPrimitiveType )
        {
        case TRIANGLES:
            return 3;
            break;
        case TRIANGLE_FANS:
            return ((Trifans*)this)->getGroupedVerticesVertexCount ( faceIndex );
            break;
        case TRIANGLE_STRIPS:
            return ((Tristrips*)this)->getGroupedVerticesVertexCount ( faceIndex );
            break;
        case POINTS:
            return 1;
            break;
        case LINES:
            return 2;
            break;
        case LINE_STRIPS:
            return ((Linestrips*)this)->getGroupedVerticesVertexCount ( faceIndex );
            break;
        case POLYGONS:
        case POLYLIST:
            return ((Polygons*)this)->getGroupedVerticesVertexCount ( faceIndex );
            break;
        default:
            std::cerr << "Unknown primitive type: " << mPrimitiveType << std::endl;
            return 0;
        }
    }

    //-----------------------------
    const size_t MeshPrimitive::getGroupedVertexElementsCount () const
    {
        // Get the number of grouped vertex elements (faces, holes, tristrips or trifans).
        size_t groupedVertexElementsCount = 0;

        MeshPrimitive::PrimitiveType primitiveType = this->getPrimitiveType ();
        switch ( primitiveType )
        {
        case MeshPrimitive::TRIANGLES:
            {
                groupedVertexElementsCount = this->getFaceCount ();
                break;
            }
        case MeshPrimitive::TRIANGLE_FANS:
            {
                Trifans* trifans = (Trifans*) this;
                groupedVertexElementsCount = trifans->getTrifanCount ();
                break;
            }
        case MeshPrimitive::TRIANGLE_STRIPS:
            {
                Tristrips* tristrips = (Tristrips*) this;
                groupedVertexElementsCount = tristrips->getTristripCount ();
                break;
            }
        case MeshPrimitive::POLYGONS:
        case MeshPrimitive::POLYLIST:
            {
                Polygons* polygons = (Polygons*) this;
                Polygons::VertexCountArray& vertexCountArray =
                    polygons->getGroupedVerticesVertexCountArray ();
                groupedVertexElementsCount = vertexCountArray.getCount ();
            }
            break;
        case MeshPrimitive::LINES:
            {
                groupedVertexElementsCount = this->getFaceCount ();
                break;
            }
            break;
        case MeshPrimitive::LINE_STRIPS:
            {
                Linestrips* linestrips = (Linestrips*)this;
                groupedVertexElementsCount = linestrips->getLinestripCount ();
                break;
            }
            break;
        default:
            std::cerr << "Primitive type not supported: " << primitiveType << std::endl;
            assert ( "Primitive type not supported: " + primitiveType );
            return 0;
        }

        return groupedVertexElementsCount;
    }

}
