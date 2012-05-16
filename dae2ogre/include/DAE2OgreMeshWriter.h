/*
Copyright (c) 2009 NetAllied Systems GmbH

This file is part of dae2ogre.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2OGRE_MESHWRITER_H__
#define __DAE2OGRE_MESHWRITER_H__

#include "DAE2OgrePrerequisites.h"
#include "DAE2OgreBaseWriter.h"
#include "DAE2OgreSerializer.h"

#include "OgreVertexElement.h"

#include "COLLADAFWMeshPrimitive.h"
#include "COLLADAFWArrayPrimitiveType.h"
#include "COLLADAFWMeshVertexData.h"

#include <map>

namespace COLLADAFW
{
	class Mesh;
}

namespace DAE2Ogre
{

	class MeshWriter : public BaseWriter, public OgreSerializer
	{
	private:
		struct Tuple
		{
			Tuple( unsigned int positionI, unsigned int normalI, unsigned int textureI, unsigned int colorI)
				: positionIndex( positionI), normalIndex(normalI), textureIndex(textureI), colorIndex(colorI){}
			unsigned int positionIndex;
			unsigned int normalIndex;
			unsigned int textureIndex;
			unsigned int colorIndex;
			bool operator<(const Tuple& rhs) const;
		};

		typedef COLLADAFW::ArrayPrimitiveType<float> FloatList;
		typedef COLLADAFW::ArrayPrimitiveType<double> DoubleList;
		typedef COLLADAFW::ArrayPrimitiveType<int> IntList;
		typedef COLLADAFW::ArrayPrimitiveType<unsigned int> UIntList;
		typedef std::map<Tuple, int> TupleIndexMap;
		typedef std::vector<String> StringList;

	private:
		const COLLADAFW::Mesh* mMesh;
		TupleIndexMap mTupleMap;
		int mNextTupleIndex;
		size_t mMeshSize;
		size_t mSubmeshCount;
		size_t mSubmeshNameTableSize;

		// float minx, miny, minz
		float mMeshBoundsMin[ 3 ];
		float mMeshBoundsMax[ 3 ];

		bool mMeshBoundsSet;


		const COLLADAFW::MeshVertexData& mMeshPositions;
		const COLLADAFW::MeshVertexData& mMeshNormals;
		const COLLADAFW::MeshVertexData& mMeshUVCoordinates;
		const COLLADAFW::MeshVertexData& mMeshColors;

		DoubleList mOgrPositions;
		DoubleList mOgreNormals;
		DoubleList mOgreUVCoordinates;
		DoubleList mOgreColors;
		UIntList mOgreIndices;

		bool mHasNormals;
		bool mHasUVCoords;

		COLLADABU::Math::Matrix3 mCurrentRotationMatrix;
		COLLADABU::Math::Vector3 mCurrentTranslationVector;
	
		StringList mSubMeshNames;

	public:

        /** Constructor. */
		MeshWriter( OgreWriter* ogreWriter, const COLLADAFW::Mesh* mesh );

        /** Destructor. */
		virtual ~MeshWriter();

		bool write();

	private:

        /** Disable default copy ctor. */
		MeshWriter( const MeshWriter& pre );

        /** Disable default assignment operator. */
		const MeshWriter& operator= ( const MeshWriter& pre );
	
		void writeSubMesh(COLLADAFW::MeshPrimitive* meshPrimitive, const COLLADABU::Math::Matrix4& matrix);

		void addTupleIndex( const Tuple& tuple);

		void writeGeometry( );
		size_t getVertexSizeInByte() const;
		void writeVertexElement( unsigned short source, size_t offset, Ogre::VertexElementType type, Ogre::VertexElementSemantic semantic, unsigned short index );
		void writeVertexBuffer( );
		size_t calcSubMeshSize( int numIndices, const String& submeshName );
		void calcMeshSize( );
		void writeSubMeshOperation( COLLADAFW::MeshPrimitive::PrimitiveType primitiveType );
		void calculateMeshBounds();
		void writeSubMeshNameTableEntry( const String& name, uint16 index );
		void writeBoundsInfo( );
		void writeSubMeshNameTable( );
		size_t calcSubMeshNameSize( const String& subMeshName );
	};


} // namespace DAE2Ogre

#endif // __DAE2OGRE_MESHWRITER_H__
