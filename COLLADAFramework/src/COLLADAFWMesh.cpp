/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWMesh.h"
#include "COLLADAFWTristrips.h"
#include "COLLADAFWLinestrips.h"

namespace COLLADAFW
{

    //----------------------------------
    Mesh::Mesh( const UniqueId& uniqueId )
        : Geometry ( uniqueId, Geometry::GEO_TYPE_MESH )
        , mMeshPrimitives(MeshPrimitiveArray::OWNER)
    {

    }

    //----------------------------------
	Mesh::~Mesh()
	{
		for ( size_t i = 0, count = mMeshPrimitives.getCount(); i < count; ++i)
			delete mMeshPrimitives[i];
	}

    //----------------------------------
	size_t Mesh::getTrianglesTriangleCount()
	{
		return getPrimitiveCount(MeshPrimitive::TRIANGLES);
	}

	//---------------------------------------------------------------
	size_t Mesh::getTristripsTriangleCount()
	{
		return getFaceCount(MeshPrimitive::TRIANGLE_STRIPS);
	}

	//---------------------------------------------------------------
	size_t Mesh::getTrifansTriangleCount()
	{
		return getFaceCount(MeshPrimitive::TRIANGLE_FANS);
	}

	//---------------------------------------------------------------
	size_t Mesh::getPolygonsPolygonCount()
	{
		return getPrimitiveCount(MeshPrimitive::POLYGONS);
	}


	//---------------------------------------------------------------
	size_t Mesh::getPrimitiveCount( MeshPrimitive::PrimitiveType primitiveType )
	{
		size_t primitiveCount = 0;
		for ( size_t i = 0, count = mMeshPrimitives.getCount(); i < count; ++i)
		{
			MeshPrimitive* primitive = mMeshPrimitives[i];

			if ( primitive && ( primitive->getPrimitiveType() == primitiveType ) )
			{
				switch ( primitiveType )
				{
				case MeshPrimitive::TRIANGLES:
                case MeshPrimitive::LINES:
				case MeshPrimitive::POLYGONS:
					primitiveCount += primitive->getFaceCount();
					break;
				case MeshPrimitive::TRIANGLE_STRIPS:
					{
						Tristrips* tristrips = (Tristrips*)primitive;
						primitiveCount += tristrips->getTristripCount();
					}
                    break;
				case MeshPrimitive::TRIANGLE_FANS:
					{

						// TODO not implemented
						//Tristrips* tristrips = (Tristrips*)primitive;
						//primitiveCount += tristrips->getTristripCount();
					}
                    break;
                case MeshPrimitive::LINE_STRIPS:
                    {
                        Linestrips* linestrips = (Linestrips*)primitive;
                        primitiveCount += linestrips->getLinestripCount ();
                    }
                    break;
				case MeshPrimitive::UNDEFINED_PRIMITIVE_TYPE:
				default:
					break;
				}
			}
		}
		return primitiveCount;
	}

    //----------------------------------
	size_t Mesh::getFaceCount( MeshPrimitive::PrimitiveType primitiveType )
	{
		size_t faceCount = 0;
		for ( size_t i = 0, count = mMeshPrimitives.getCount(); i < count; ++i)
		{
			MeshPrimitive* primitive = mMeshPrimitives[i];

			if ( primitive && ( primitive->getPrimitiveType() == primitiveType ) )
				faceCount += primitive->getFaceCount();
		}
		return faceCount;
	}


	//---------------------------------------------------------------
	size_t Mesh::getTrianglesCount()
	{
		return getPrimitiveCount(MeshPrimitive::TRIANGLES);
	}

	//---------------------------------------------------------------
	size_t Mesh::getTristripsCount()
	{
		return getPrimitiveCount(MeshPrimitive::TRIANGLE_STRIPS);
	}

	//---------------------------------------------------------------
	size_t Mesh::getTrifansCount()
	{
		return getPrimitiveCount(MeshPrimitive::TRIANGLE_FANS);
	}

	//---------------------------------------------------------------
	size_t Mesh::getPolygonsCount()
	{
		return getPrimitiveCount(MeshPrimitive::POLYGONS);
	}


	//---------------------------------------------------------------
	size_t Mesh::getMeshPrimitiveCount( MeshPrimitive::PrimitiveType primitiveType )
	{
		size_t primitiveCount = 0;
		for ( size_t i = 0, count = mMeshPrimitives.getCount(); i < count; ++i)
		{
			MeshPrimitive* primitive = mMeshPrimitives[i];

			if ( primitive && ( primitive->getPrimitiveType() == primitiveType ) )
				primitiveCount++;
		}
		return primitiveCount;
	}

    //----------------------------------
	bool Mesh::hasNormals( )const
	{
		return getNormals().getValuesCount() != 0;
	}

    //----------------------------------
    const size_t Mesh::getNormalsCount() const
    {
        // The number of normals in the current mesh.
        size_t numNormals = 0;

        // We have to go through every mesh primitive.
        const MeshPrimitiveArray& meshPrimitives = this->getMeshPrimitives ();
        size_t count = meshPrimitives.getCount ();
        for ( size_t i=0; i<count; ++i )
        {
            // Get the current primitive element.
            const MeshPrimitive* meshPrimitive = meshPrimitives [ i ];

            // Get the normal indices of the current primitive.
            const UIntValuesArray& normalIndices = meshPrimitive->getNormalIndices ();

            switch ( meshPrimitive->getPrimitiveType () )
            {
            case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
            case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
                {
                    COLLADAFW::MeshPrimitiveWithFaceVertexCount<unsigned int>* trifans = (COLLADAFW::MeshPrimitiveWithFaceVertexCount<unsigned int>*) meshPrimitive;
                    COLLADAFW::MeshPrimitiveWithFaceVertexCount<unsigned int>::VertexCountArray& vertexCountArray = trifans->getGroupedVerticesVertexCountArray ();
                    size_t groupedVtxCount = vertexCountArray.getCount ();
                    for ( size_t groupedVtxIndex=0; groupedVtxIndex<groupedVtxCount; ++groupedVtxIndex )
                    {
                        // Iterate over the indices and write their normal values into the maya file.
                        size_t indexCount = vertexCountArray[groupedVtxIndex]; //normalIndices.getCount();
                        numNormals += (indexCount - 2) * 3;
                    }
                }
                break;
            default:
                {
                    // Add the normals to the sum of normals
                    numNormals += normalIndices.getCount ();
                }
            }
        }

        return numNormals;
    }

    //----------------------------------
    const size_t Mesh::getFacesCount() const
    {
        // The number of faces in the current mesh.
        size_t numFaces = 0;

        // We have to go through every mesh primitive.
        const MeshPrimitiveArray& meshPrimitives = this->getMeshPrimitives ();
        size_t count = meshPrimitives.getCount ();
        for ( size_t i=0; i<count; ++i )
        {
            // Get the current primitive element.
            const MeshPrimitive* meshPrimitive = meshPrimitives [ i ];

            // Add the face count to the sum of faces
            numFaces += meshPrimitive->getFaceCount ();
        }

        return numFaces;
    }

} // namespace COLLADAFW
