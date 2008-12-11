/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaGeometryImporter.h"

#include <maya/MFnMesh.h>
#include <maya/MFnTransform.h>
#include <maya/MDagModifier.h>

#pragma warning(disable:4172)

#include "MayaDMMesh.h"
#include "MayaDMTransform.h"
#include "MayaDMPolyCube.h"

namespace COLLADAMaya
{
    
    // --------------------------------------------
    GeometryImporter::GeometryImporter( DocumentImporter* documentImporter ) 
    : BaseImporter ( documentImporter )
    , mTransformObject ( MObject::kNullObj )
    {}

    // --------------------------------------------
    bool GeometryImporter::importGeometry ( const COLLADAFW::Geometry* geometry )
    {
        if ( geometry == 0 ) return false;

        mGeometry = geometry;

        const COLLADAFW::GeometricElement* geometricElement = geometry->getGeometricElement ();
        COLLADAFW::GeometricElement::GeometricType type = geometricElement->getType ();
        switch ( type )
        {
        case COLLADAFW::GeometricElement::GEO_TYPE_CONVEX_MESH:
            std::cerr << "Import of convex_mesh not supported!" << std::endl;
            return false;
        case COLLADAFW::GeometricElement::GEO_TYPE_SPLINE:
            std::cerr << "Import of spline not supported!" << std::endl;
            return false;
        case COLLADAFW::GeometricElement::GEO_TYPE_MESH:
            {
                COLLADAFW::Mesh* mesh = ( COLLADAFW::Mesh* ) geometricElement;
                importMesh ( mesh );
                break;
            }
        default:
            return false;
        }

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::importMesh ( const COLLADAFW::Mesh* mesh )
    {
        // TODO 
        FILE* file = 0;
        errno_t err = fopen_s ( &file, "c:\\temp\\cube_test.ma", "w+" );
        if ( err != 0 )
        {
            return false;
        }

        writeHeader(file);

        const COLLADAFW::Geometry* geometry = mesh->getGeometry ();

        String id = geometry->getId ();
        String name = geometry->getName ();

        const COLLADAFW::GeometricElement* geometricElement = geometry->getGeometricElement ();
        COLLADAFW::GeometricElement::GeometricType type = geometricElement->getType ();

        MayaDM::Transform transformNode ( file, "pCube1", "" );
        MayaDM::Mesh meshNode ( file, "pCubeShape1", transformNode.getName () );
        
        {
            // positions
            const COLLADAFW::MeshPositions& positions = mesh->getPositions ();
            const COLLADAFW::MeshFloatDoubleInputs::DataType type = positions.getType ();
            switch ( type )
            {
            case COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_FLOAT:
                {
                    const COLLADAFW::ArrayPrimitiveType<float>* values = positions.getFloatPositions ();
                    size_t count = positions.getPositionsCount ();
                    for ( size_t i=0, index=0; i<count; i+=3, ++index )
                    {
                        meshNode.setVrts ( index, MayaDM::float3 ( (*values)[i], (*values)[i+1], (*values)[i+3] ) );
                    }
                }
                break;
            case COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_DOUBLE:
                {
                    const COLLADAFW::ArrayPrimitiveType<double>* values = positions.getDoublePositions ();
                    size_t count = positions.getPositionsCount ();
                    for ( size_t i=0, index=0; i<count; i+=3, ++index )
                    {
                        meshNode.setVrts ( index, MayaDM::float3 ( (float)(*values)[i], (float)(*values)[i+1], (float)(*values)[i+3] ) );
                    }
                }
                break;
            default:
                std::cerr << "No valid data type for positions: " << type << std::endl;
                return false;
            }
        }


        {
            // normals
            const COLLADAFW::MeshNormals& normals = mesh->getNormals ();
            const COLLADAFW::MeshFloatDoubleInputs::DataType type = normals.getType ();
            switch ( type )
            {
            case COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_FLOAT:
                {
                    const COLLADAFW::ArrayPrimitiveType<float>* values = normals.getFloatNormals ();
                    size_t count = normals.getNormalsCount ();
                    for ( size_t i=0, index=0; i<count; i+=3, ++index )
                    {
                        meshNode.setNormals ( index, MayaDM::float3 ( (*values)[i], (*values)[i+1], (*values)[i+3] ) );
                    }
                }
                break;
            case COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_DOUBLE:
                {
                    const COLLADAFW::ArrayPrimitiveType<double>* values = normals.getDoubleNormals ();
                    size_t count = normals.getNormalsCount ();
                    for ( size_t i=0, index=0; i<count; i+=3, ++index )
                    {
                        meshNode.setNormals ( index, MayaDM::float3 ( (float)(*values)[i], (float)(*values)[i+1], (float)(*values)[i+3] ) );
                    }
                }
                break;
            default:
                std::cerr << "No valid data type for normals: " << type << std::endl;
                return false;
            }
        }

        {
            // uv corrdinates
            const COLLADAFW::MeshUVCoords& uvCoords = mesh->getUVCoords ();
            size_t stride = uvCoords.getStride ();
            const COLLADAFW::MeshFloatDoubleInputs::DataType type = uvCoords.getType ();
            switch ( type )
            {
            case COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_FLOAT:
                {
                    const COLLADAFW::ArrayPrimitiveType<float>* values = uvCoords.getFloatUVCoords ();
                    size_t count = uvCoords.getUVCoordsCount ();
                    for ( size_t i=0, index=0; i<count; i+=stride, ++index )
                    {
                        meshNode.setUvSetPoints ( 0, index, MayaDM::float2 ( (*values)[i], (*values)[i+1] ) );
                    }
                }
                break;
            case COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_DOUBLE:
                {
                    const COLLADAFW::ArrayPrimitiveType<double>* values = uvCoords.getDoubleUVCoords ();
                    size_t count = uvCoords.getUVCoordsCount ();
                    for ( size_t i=0, index=0; i<count; i+=stride, ++index )
                    {
                        meshNode.setUvSetPoints ( 0, index, MayaDM::float2 ( (float)(*values)[i], (float)(*values)[i+1] ) );
                    }
                }
                break;
            default:
                std::cerr << "No valid data type for uv coordinates: " << type << std::endl;
                return false;
            }

        }

        {
            // TODO Create Edges and fill the polyFaces !

            // TODO No implementation for multiple primitive elements!

            const COLLADAFW::PrimitiveElementsArray& primitiveElementsArray = mesh->getPrimitiveElements ();
            size_t count = primitiveElementsArray.getCount ();
            for ( size_t i=0; i<count; ++i )
            {
                COLLADAFW::PrimitiveElement* primitiveElement = primitiveElementsArray [ i ];

                // Look, if there are already some edges defined...
                COLLADAFW::UIntValuesArray& edgeIndices = primitiveElement->getEdgeIndices ();
                size_t numEdgeIndices = edgeIndices.getCount ();
                if ( numEdgeIndices == 0 )
                {
                    // TODO Initialize an array of edge values.
                    // Geht nicht mehr, bin platt, denken klappt heut nicht mehr, sorry!
                    primitiveElement->initializeEdgeIndices ( edgeIndices );
                }

                // TODO Write the edges and the faces...
            }
        }

//         {
//             // Faces ERROR Get the indices from the edges, not from positions!!!
// 
//             // TODO No implementation for multiple primitive elements!
// 
//             const COLLADAFW::PrimitiveElementsArray& primitiveElementsArray = mesh->getPrimitiveElements ();
//             size_t count = primitiveElementsArray.getCount ();
//             for ( size_t i=0; i<count; ++i )
//             {
//                 COLLADAFW::PrimitiveElement* primitiveElement = primitiveElementsArray [ i ];
//                 COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();
//                 size_t numPositionIndices = positionIndices.getCount ();
// 
//                 // Get the array with the face vertex counts.
//                 COLLADAFW::UIntValuesArray& faceVertexCountArray = primitiveElement->getFaceVertexCountArray ();
//                 unsigned int faceVertexIndex = 0; 
// 
//                 // Create the poly faces
//                 size_t faceCount = primitiveElement->getFaceCount ();
//                 MayaDM::polyFaces* faces = new MayaDM::polyFaces [ faceCount ];
// 
//                 // Iterate over the faces
//                 for ( size_t faceIndex=0; faceIndex<faceCount; ++faceIndex )
//                 {
//                     unsigned int faceVertexCount = faceVertexCountArray [ faceIndex ];
//                     faces[faceIndex].f.faceEdgeCount = faceVertexCount;
//                     faces[faceIndex].f.edgeIdValue = new int [ faceVertexCount ];
// 
//                     // TODO Optimize!
//                     for ( size_t k=0; k<faceVertexCount; ++k )
//                     {
//                         faces[faceIndex].f.edgeIdValue[k] = positionIndices[faceVertexIndex++];
//                     }
// 
//                     meshNode.setFace( faceIndex, faces[faceIndex]);
//                 }
//             }
//         }

        // Close the file
        fclose(file);

        return true;
    }


}