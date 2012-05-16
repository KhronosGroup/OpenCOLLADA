/*
Copyright (c) 2009 NetAllied Systems GmbH

This file is part of dae2ogre.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2OgreStableHeaders.h"
#include "DAE2OgreMeshWriter.h"
#include "DAE2OgreOgreWriter.h"

#include "OgreVertexElement.h"
#include "OgreMeshFileFormat.h"

#include "COLLADAFWMesh.h"
#include "COLLADAFWUniqueId.h"
#include "COLLADAFWTriangles.h"
#include "COLLADAFWTrifans.h"
#include "COLLADAFWTristrips.h"

#include "COLLADABUPlatform.h"

#ifdef COLLADABU_OS_WIN
#	include <windows.h>
#endif

namespace DAE2Ogre
{
	String material("BaseWhite");

    //------------------------------
	MeshWriter::MeshWriter( OgreWriter* ogreWriter, const COLLADAFW::Mesh* mesh )
		: BaseWriter(ogreWriter)
		, mMesh(mesh)
		, mNextTupleIndex(0)
		, mMeshSize(0)
		, mSubmeshCount(0)
		, mSubmeshNameTableSize(STREAM_OVERHEAD_SIZE)
		, mMeshBoundsSet(false)
		, mHasNormals( false )
		, mHasUVCoords( false )
		, mMeshPositions( mesh->getPositions() )
		, mMeshNormals( mesh->getNormals() )
		, mMeshUVCoordinates( mesh->getUVCoords() )
		, mMeshColors( mesh->getColors() )
		, mOgrPositions(FloatList::RELEASE_MEMORY)
	    , mOgreNormals(FloatList::RELEASE_MEMORY)
	    , mOgreUVCoordinates(FloatList::RELEASE_MEMORY)
	    , mOgreColors(FloatList::RELEASE_MEMORY)
	    , mOgreIndices(IntList::RELEASE_MEMORY)
	{
		 mVersion = "[MeshSerializer_v1.30]";
		 calcMeshSize();
		 mMeshBoundsMin[0] = -100;
		 mMeshBoundsMin[1] = -100;
		 mMeshBoundsMin[2] = -100;
		 mMeshBoundsMax[0] = 100;
		 mMeshBoundsMax[1] = 100;
		 mMeshBoundsMax[2] = 100;
	}

    //------------------------------
	MeshWriter::~MeshWriter()
	{
	}

	//------------------------------
	bool MeshWriter::Tuple::operator<( const Tuple& rhs ) const
	{
		if ( positionIndex < rhs.positionIndex )
			return true;

		if ( positionIndex > rhs.positionIndex )
			return false;

		if ( normalIndex < rhs.normalIndex )
			return true;

		if ( normalIndex > rhs.normalIndex )
			return false;

		if ( textureIndex < rhs.textureIndex )
			return true;

		if ( textureIndex > rhs.textureIndex )
			return false;

		if ( colorIndex < rhs.colorIndex )
			return true;

		if ( colorIndex > rhs.colorIndex )
			return false;

		return false;
	}


	//------------------------------
	bool MeshWriter::write()
	{
		determineEndianness( ENDIAN_NATIVE );

		const String path = getOutputFile().toNativePath();
		mpfFile = fopen( path.c_str(), "wb" );

		if ( !mpfFile )
		{
			return false;
		}


		// Header
		writeFileHeader();

		// Since we do not know the mesh size at this point, we write 0 and overwirte the size in the file 
		// later
		fpos_t filePos = getPos();
		writeChunkHeader( Ogre::M_MESH, 0 );

		// bool skeletallyAnimated
		bool skelAnim = false; //mesh->hasSkeleton();

		writeBools( &skelAnim, 1 );
		// Decide on endian mode

		const COLLADAFW::UniqueId& meshUniqueId = mMesh->getUniqueId();
		const OgreWriter::GeometryUniqueIdInstanceGeometryInfoMap& instanceGeometryMap = getGeometryUniqueIdInstanceGeometryInfoMap();
		OgreWriter::GeometryUniqueIdInstanceGeometryInfoMap::const_iterator lowerBound = instanceGeometryMap.lower_bound(meshUniqueId);
		OgreWriter::GeometryUniqueIdInstanceGeometryInfoMap::const_iterator upperBound = instanceGeometryMap.upper_bound(meshUniqueId);

		for ( OgreWriter::GeometryUniqueIdInstanceGeometryInfoMap::const_iterator it = lowerBound; it != upperBound; ++it)
		{
			const OgreWriter::InstanceGeometryInfo& instanceGeometryInfo = it->second;
			const COLLADABU::Math::Matrix4& worldMatrix = instanceGeometryInfo.worldMatrix;
			const COLLADAFW::MeshPrimitiveArray& meshPrimitives = mMesh->getMeshPrimitives();
			const COLLADAFW::InstanceGeometry* instanceGeometry = instanceGeometryInfo.fwInstanceGeometry;

			worldMatrix.extract3x3Matrix(mCurrentRotationMatrix );
			mCurrentTranslationVector.set(worldMatrix[0][3], worldMatrix[1][3], worldMatrix[2][3]);
			
			for ( size_t i = 0, count = meshPrimitives.getCount(); i < count; ++i )
			{
				COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives[i];
				writeSubMesh(meshPrimitive, worldMatrix);
			}
		}

		// Write bounds information
		writeBoundsInfo( );

		// Write submesh name table
		writeSubMeshNameTable( );

		mMeshSize += mSubmeshNameTableSize;


		setPos( filePos );
		writeChunkHeader( Ogre::M_MESH, mMeshSize );
		
		fclose( mpfFile );
		return true;
	}

	//-----------------------------------------------------------------------
	void MeshWriter::writeSubMeshNameTable( )
	{
		// Header
		writeChunkHeader( Ogre::M_SUBMESH_NAME_TABLE, mSubmeshNameTableSize );

		for ( size_t i = 0, count = mSubMeshNames.size(); i < count; ++i )
		{
			const String& subMeshName = mSubMeshNames[i];
			writeSubMeshNameTableEntry( subMeshName, (uint16)i );
		}
	}

	//-----------------------------------------------------------------------
	void MeshWriter::writeSubMeshNameTableEntry( const String& name, uint16 index )
	{
		// Header
		writeChunkHeader( Ogre::M_SUBMESH_NAME_TABLE_ELEMENT, STREAM_OVERHEAD_SIZE +
			sizeof( unsigned short ) + ( unsigned long ) name.length() + 1 );

		// write the index
		writeShorts( &index, 1 );
		// name
		writeString( name );
	}


	//-----------------------------------------------------------------------
	void MeshWriter::writeBoundsInfo(  )
	{
		// Usage Header
		size_t size = STREAM_OVERHEAD_SIZE;

		size += sizeof( float ) * 7;
		writeChunkHeader( Ogre::M_MESH_BOUNDS, size );

		writeFloats( mMeshBoundsMin, 3 );
		writeFloats( mMeshBoundsMax, 3 );
		// float radius
		float diagonal[ 3 ];
		diagonal[ 0 ] = mMeshBoundsMax[ 0 ] - mMeshBoundsMin[ 0 ];
		diagonal[ 1 ] = mMeshBoundsMax[ 1 ] - mMeshBoundsMin[ 1 ];
		diagonal[ 2 ] = mMeshBoundsMax[ 2 ] - mMeshBoundsMin[ 2 ];
		float diameter = ( float ) sqrt( pow( diagonal[ 0 ], 2 ) + pow( diagonal[ 1 ], 2 ) + pow( diagonal[ 2 ], 2 ) );
		float radius = diameter / 2;
		writeFloats( &radius, 1 );
	}

	//-----------------------------------------------------------------------
	void MeshWriter::calcMeshSize( )
	{
		mMeshSize += STREAM_OVERHEAD_SIZE;

		// Num shared vertices
		mMeshSize += sizeof( uint32 );

		// Edge list
		//mMeshSize += calcEdgeListSize(mesh);
	}

	//------------------------------
	void MeshWriter::addTupleIndex( const Tuple& tuple )
	{
		TupleIndexMap::const_iterator it = mTupleMap.find(tuple);
		if ( it == mTupleMap.end() )
		{
			mOgreIndices.append( mTupleMap[tuple] = mNextTupleIndex++ );

			if ( mMeshPositions.getType() == COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE )
			{
				const double* positionsArray = mMeshPositions.getDoubleValues()->getData();
				positionsArray += 3*tuple.positionIndex;
				COLLADABU::Math::Vector3 position(positionsArray[0], positionsArray[1], positionsArray[2]);
				position = mCurrentRotationMatrix * position + mCurrentTranslationVector;
				mOgrPositions.append((float)position.x);
				mOgrPositions.append((float)position.y);
				mOgrPositions.append((float)position.z);
			}
			else
			{
				const float* positionsArray = mMeshPositions.getFloatValues()->getData();
				positionsArray += 3*tuple.positionIndex;
				COLLADABU::Math::Vector3 position(positionsArray[0], positionsArray[1], positionsArray[2]);
				position = mCurrentRotationMatrix * position + mCurrentTranslationVector;
				mOgrPositions.append((float)position.x);
				mOgrPositions.append((float)position.y);
				mOgrPositions.append((float)position.z);
			}

			if ( mHasNormals )
			{
				if ( mMeshNormals.getType() == COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE )
				{
					const double* normalsArray = mMeshNormals.getDoubleValues()->getData();
					normalsArray += 3*tuple.normalIndex;
					COLLADABU::Math::Vector3 normal(normalsArray[0], normalsArray[1], normalsArray[2]);
					normal = mCurrentRotationMatrix * normal;
					normal.normalise();
					mOgreNormals.append((float)normal.x);
					mOgreNormals.append((float)normal.y);
					mOgreNormals.append((float)normal.z);
				}
				else
				{
					const float* normalsArray = mMeshNormals.getFloatValues()->getData();
					normalsArray += 3*tuple.normalIndex;
					COLLADABU::Math::Vector3 normal(normalsArray[0], normalsArray[1], normalsArray[2]);
					normal = mCurrentRotationMatrix * normal;
					normal.normalise();
					mOgreNormals.append((float)normal.x);
					mOgreNormals.append((float)normal.y);
					mOgreNormals.append((float)normal.z);
				}
			}

			if ( mHasUVCoords )
			{
				if ( mMeshUVCoordinates.getType() == COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE )
				{
					const double* uVCoordinateArray = mMeshUVCoordinates.getDoubleValues()->getData();
					uVCoordinateArray += mMeshUVCoordinates.getStride(0)*tuple.textureIndex;
					mOgreUVCoordinates.append((float)uVCoordinateArray[0]);
					mOgreUVCoordinates.append((float)uVCoordinateArray[1]);
				}
				else
				{
					const float* uVCoordinateArray = mMeshUVCoordinates.getFloatValues()->getData();
					uVCoordinateArray += mMeshUVCoordinates.getStride(0)*tuple.textureIndex;
					mOgreUVCoordinates.append((float)uVCoordinateArray[0]);
					mOgreUVCoordinates.append((float)uVCoordinateArray[1]);
				}
			}

		}
		else
		{
			mOgreIndices.append(it->second);
		}
	}

	//------------------------------
	void MeshWriter::writeSubMesh( COLLADAFW::MeshPrimitive* meshPrimitive, const COLLADABU::Math::Matrix4& matrix )
	{
		mSubmeshCount++;
		String subMeshName = "subMesh" + COLLADABU::Utils::toString(mSubmeshCount);
		mSubMeshNames.push_back( subMeshName );		

		int numIndices = 0;

		const COLLADAFW::UIntValuesArray& positionIndices =  meshPrimitive->getPositionIndices();
		size_t positionIndicesCount  = positionIndices.getCount();

		const COLLADAFW::UIntValuesArray& normalIndices =  meshPrimitive->getNormalIndices();
		size_t normalIndicesCount = normalIndices.getCount();
		mHasNormals = (normalIndicesCount != 0);


		const COLLADAFW::UIntValuesArray* uvIndices;
		size_t uvIndicesCount = 0;
		const COLLADAFW::IndexListArray& uVIndicesList = meshPrimitive->getUVCoordIndicesArray();
		if ( !uVIndicesList.empty() )
		{
			uvIndices = &uVIndicesList[0]->getIndices();
			uvIndicesCount = uvIndices->getCount();
			mHasUVCoords = (uvIndicesCount != 0);
		}
		else
		{
			mHasUVCoords = false;
		}


		assert( !mHasNormals || (positionIndicesCount == normalIndicesCount));
		assert( !mHasUVCoords || (positionIndicesCount == uvIndicesCount));

		switch (meshPrimitive->getPrimitiveType())
		{
		case COLLADAFW::MeshPrimitive::TRIANGLES:
			{
				const COLLADAFW::Triangles* triangles = (const COLLADAFW::Triangles*) meshPrimitive;
				numIndices = (int)positionIndicesCount;

				for ( int j = 0; j < numIndices; ++j )
				{
					unsigned int positionIndex = positionIndices[j];

					unsigned int normalIndex = 0;
					if ( mHasNormals )
						normalIndex = normalIndices[j];

					unsigned int uvIndex = 0;
					if ( mHasUVCoords )
						uvIndex = (*uvIndices)[j];

					Tuple tuple( positionIndex, normalIndex, uvIndex, 0);
					addTupleIndex(tuple);
				}
			}
			break;
		default:
			break;
		}

		// Header
		size_t subMeshSize = calcSubMeshSize( numIndices, subMeshName );
		writeChunkHeader( Ogre::M_SUBMESH, subMeshSize );

		mMeshSize += subMeshSize;

		mSubmeshNameTableSize += calcSubMeshNameSize(subMeshName);

		writeString(material);

		// bool useSharedVertices
		bool useSharedVertices = false;
		writeBools( &useSharedVertices, 1 );

		// index count (number of triangles * 3)
		uint32 tmp = (uint32)numIndices;
		writeInts( &tmp, 1 );

		// bool indexes32Bit
		bool indexes32Bit = true;
		writeBools( &indexes32Bit, 1 );

		// unsigned short* faceVertexIndices ((indexCount)
		const uint32* pIdx32 = mOgreIndices.getData();
		writeInts( pIdx32, numIndices );

		int& vertexCount = mNextTupleIndex;

		// M_GEOMETRY stream (Optional: present only if useSharedVertices = false)
		writeGeometry( );

		writeSubMeshOperation( meshPrimitive->getPrimitiveType() );

		calculateMeshBounds();

		mNextTupleIndex = 0;
		mOgrPositions.clear();
		mOgreNormals.clear();
		mOgreUVCoordinates.clear();
		mOgreColors.clear();
		mOgreIndices.clear();
		mTupleMap.clear();
	}

	//-----------------------------------------------------------------------
	size_t MeshWriter::calcSubMeshNameSize( const String& subMeshName )
	{
		size_t size = 0;
		// size of the index + header size for each element chunk
		size += STREAM_OVERHEAD_SIZE + sizeof( uint16 );

		// name
		size += subMeshName.length() + 1;

		return size;
	}

	//-----------------------------------------------------------------------
	void MeshWriter::writeGeometry( )
	{
		int vertexCount = mNextTupleIndex;
		// calc size

		// base
		size_t size = STREAM_OVERHEAD_SIZE + sizeof( unsigned int );

		// vertex elements
		size_t vertexElements = 1;
		if ( mHasNormals )
		{
			vertexElements++;
		}

		if ( mHasUVCoords )
		{
			vertexElements++;
		}

		size += ( STREAM_OVERHEAD_SIZE + vertexElements * ( STREAM_OVERHEAD_SIZE + sizeof( unsigned short ) * 5 ) );

		int vertexBuferSizeInBytes = (int)getVertexSizeInByte() * vertexCount;

		// 1 buffer
		size += ( STREAM_OVERHEAD_SIZE * 2 ) + ( sizeof( unsigned short ) * 2 ) + vertexBuferSizeInBytes;

		// Header
		writeChunkHeader( Ogre::M_GEOMETRY, size );

		uint32 vertexCountTmp = static_cast<uint32>( vertexCount );
		writeInts( &vertexCountTmp, 1 );

		// Vertex declaration
		size = STREAM_OVERHEAD_SIZE + vertexElements * ( STREAM_OVERHEAD_SIZE + sizeof( unsigned short ) * 5 );
		writeChunkHeader( Ogre::M_GEOMETRY_VERTEX_DECLARATION, size );

//		SimpleIndexedGeometry::VertexElementList::const_iterator vei, veiend;
//		veiend = geo->getVertexElementList().end();
		unsigned short tmp;
		size = STREAM_OVERHEAD_SIZE + sizeof( unsigned short ) * 5;

		short offset = 0;
		writeVertexElement( 0, offset, Ogre::VET_FLOAT3, Ogre::VES_POSITION, 0 );
		offset += (short)Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT3 );

		if ( mHasNormals )
		{
			writeVertexElement( 0, offset, Ogre::VET_FLOAT3, Ogre::VES_NORMAL, 0 );
			offset += (short)Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT3 );
		}

		// todo we don not support uvs yet
		if ( mHasUVCoords && false )
		{
			writeVertexElement( 0, offset, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES, 0 );
			offset += (short)Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT2 );
		}

		// Buffers and bindings
		size = ( STREAM_OVERHEAD_SIZE * 2 ) + ( sizeof( unsigned short ) * 2 ) + vertexBuferSizeInBytes;

		writeChunkHeader( Ogre::M_GEOMETRY_VERTEX_BUFFER, size );

		// unsigned short bindIndex; // Index to bind this buffer to
		tmp = 0;

		writeShorts( &tmp, 1 );

		// unsigned short vertexSize; // Per-vertex size, must agree with declaration at this index
		tmp = static_cast<unsigned short>( getVertexSizeInByte() );

		writeShorts( &tmp, 1 );

		// Data
		size = STREAM_OVERHEAD_SIZE + vertexBuferSizeInBytes;

		writeChunkHeader( Ogre::M_GEOMETRY_VERTEX_BUFFER_DATA, size );

		if ( mFlipEndian )
		{
			// not implemented
			assert(false);
		}

		else
		{
			writeVertexBuffer( );
		}
	}

	//-----------------------------------------------------------------------
	void MeshWriter::writeVertexElement( unsigned short source, size_t offset, Ogre::VertexElementType type, Ogre::VertexElementSemantic semantic, unsigned short index )
	{
		size_t size = STREAM_OVERHEAD_SIZE + sizeof( unsigned short ) * 5;
		unsigned short tmp;
		writeChunkHeader( Ogre::M_GEOMETRY_VERTEX_ELEMENT, size );
		// unsigned short source;   // buffer bind source
		tmp = source;
		writeShorts( &tmp, 1 );
		// unsigned short type;     // VertexElementType
		tmp = static_cast<unsigned short>( type );
		writeShorts( &tmp, 1 );
		// unsigned short semantic; // VertexElementSemantic
		tmp = static_cast<unsigned short>( semantic );
		writeShorts( &tmp, 1 );
		// unsigned short offset; // start offset in buffer in bytes
		tmp = static_cast<unsigned short>( offset );
		writeShorts( &tmp, 1 );
		// unsigned short index; // index of the semantic (for colours and texture coords)
		tmp = index;
		writeShorts( &tmp, 1 );
	}


	//-----------------------------------------------------------------------
	size_t MeshWriter::getVertexSizeInByte() const
	{
		size_t vertexSize = Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT3 );

		if ( mHasNormals )
		{
			vertexSize += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT3 );
		}

		//if (  )
		//	vertexSize += Ogre::VertexElement::getTypeSize( Ogre::VET_COLOUR_ARGB );

		// todo support uv coordinates
		if ( mHasUVCoords && false)
		{
			vertexSize += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT2 );
		}

		return vertexSize;
	}


	//-----------------------------------------------------------------------
	void MeshWriter::writeVertexBuffer( )
	{
		const double * positions = mOgrPositions.getData();
		const double * normals = mOgreNormals.getData();
		// no support for color yet
		const double * colors = 0;
		const double * uvcoordinates = mOgreUVCoordinates.getData();
		size_t vertexCount = (size_t)mNextTupleIndex;

		for ( size_t v = 0; v < vertexCount; ++v )
		{
			size_t count = 3;
			size_t offset = v * count;
			writeFloats( positions + offset, count );

			if ( mHasNormals )
			{
				count = 3;
				offset = v * count;
				writeFloats( normals + offset, count );
			}

/*			if ( colors != 0 )
			{
				count = 4;
				offset = v * count;
				writeFloats( colors + offset, count );
			}
			*/

			// todo we don not support uvs yet
			if ( mHasUVCoords && false )
			{
				count = 2;
				offset = v * count;
				writeFloats( uvcoordinates + offset, count );
			}
		}
	}


	//-----------------------------------------------------------------------
	size_t MeshWriter::calcSubMeshSize( int numIndices, const String& submeshName )
	{
		int vertexCount = mNextTupleIndex;

		size_t size = STREAM_OVERHEAD_SIZE;

		// Material name

//		if ( material == 0 || strcmp( material, "" ) == 0 )
//		{
			// fallback if material not set.
//			material = OgreMaterialWriter::DEFAULT_MATERIAL.c_str();
//		}

		
		size += material.length() + 1;

		// bool useSharedVertices
		size += sizeof( bool );

		// unsigned int indexCount
		size += sizeof( unsigned int );

		// bool indexes32bit
		size += sizeof( bool );

		// unsigned int* faceVertexIndices
		size += sizeof( unsigned int ) * numIndices;

		// Geometry
		{
			size += STREAM_OVERHEAD_SIZE;

			// Num vertices
			size += sizeof( unsigned int );

			//vertexbuffer size
			size += getVertexSizeInByte() * vertexCount;
		}

		size += 0; //calcSubMeshTextureAliasesSize(pSub);
		size += STREAM_OVERHEAD_SIZE + sizeof( uint16 );

		// Bone assignments
		/*
		if (!pSub->mBoneAssignments.empty())
		{
		SubMesh::VertexBoneAssignmentList::const_iterator vi;
		for (vi = pSub->mBoneAssignments.begin();
		vi != pSub->mBoneAssignments.end(); ++vi)
		{
		size += calcBoneAssignmentSize();
		}
		}
		*/

		return size;
	}
	

	//-----------------------------------------------------------------------
	void MeshWriter::writeSubMeshOperation( COLLADAFW::MeshPrimitive::PrimitiveType primitiveType )
	{
		// Header
		size_t csubMeshOperationSize = STREAM_OVERHEAD_SIZE + sizeof( uint16 );

		writeChunkHeader( Ogre::M_SUBMESH_OPERATION, csubMeshOperationSize );

		// unsigned short operationType
		unsigned short opType = 0;

		switch ( primitiveType )
		{
		case COLLADAFW::MeshPrimitive::TRIANGLES:
			opType = static_cast<unsigned short>( Ogre::OT_TRIANGLE_LIST );
			break;
		case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
			opType = static_cast<unsigned short>( Ogre::OT_TRIANGLE_FAN );
			break;
		case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
			opType = static_cast<unsigned short>( Ogre::OT_TRIANGLE_STRIP );
			break;
		}
		writeShorts( &opType, 1 );
	}

	//-----------------------------------------------------------------------
	void MeshWriter::calculateMeshBounds()
	{
		size_t count = mOgrPositions.getCount();
		for ( size_t i = 0; i < count; i += 3)
		{
			double* position = &mOgrPositions[i];
			if ( mMeshBoundsSet )
			{
				if ( position[0] < mMeshBoundsMin[ 0 ] )
					mMeshBoundsMin[ 0 ] = ( float ) position[0];

				if ( position[1] < mMeshBoundsMin[ 1 ] )
					mMeshBoundsMin[ 1 ] = ( float ) position[1];

				if ( position[2] < mMeshBoundsMin[ 2 ] )
					mMeshBoundsMin[ 2 ] = ( float ) position[2];

				if ( position[0] > mMeshBoundsMax[ 0 ] )
					mMeshBoundsMax[ 0 ] = ( float ) position[0];

				if ( position[1] > mMeshBoundsMax[ 1 ] )
					mMeshBoundsMax[ 1 ] = ( float ) position[1];

				if ( position[2] > mMeshBoundsMax[ 2 ] )
					mMeshBoundsMax[ 2 ] = ( float ) position[2];
			}
			else
			{
				mMeshBoundsMin[ 0 ] = ( float ) position[0];
				mMeshBoundsMin[ 1 ] = ( float ) position[1];
				mMeshBoundsMin[ 2 ] = ( float ) position[2];
				mMeshBoundsMax[ 0 ] = ( float ) position[0];
				mMeshBoundsMax[ 1 ] = ( float ) position[1];
				mMeshBoundsMax[ 2 ] = ( float ) position[2];
				mMeshBoundsSet = true;
			}
		}
	}

} // namespace DAE2Ogre
