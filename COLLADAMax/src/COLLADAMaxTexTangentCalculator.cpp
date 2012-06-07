/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxTexTangentCalculator.h"



namespace COLLADAMax
{

	TexTangentCalculator::TexTangentCalculator( IMeshAccess* mesh )
		: mMesh(mesh)
		, mTexTangentsCount(0)
	{
	}

    //------------------------------
	TexTangentCalculator::~TexTangentCalculator()
	{
		deleteTexTangentInfo();
	}


	void TexTangentCalculator::computeTangent( Vector3 textureVertex[3], Vector3 geometryVertex[3], Vector3& texTangent )
	{
		const Vector3& w1 = textureVertex[0];
		const Vector3& w2 = textureVertex[1];
		const Vector3& w3 = textureVertex[2];

		const Vector3& v1 = geometryVertex[0];
		const Vector3& v2 = geometryVertex[1];
		const Vector3& v3 = geometryVertex[2];

		Real x1 = v2.x - v1.x;
		Real x2 = v3.x - v1.x;
		Real y1 = v2.y - v1.y;
		Real y2 = v3.y - v1.y;
		Real z1 = v2.z - v1.z;
		Real z2 = v3.z - v1.z;

		Real s1 = w2.x - w1.x;
		Real s2 = w3.x - w1.x;
		Real t1 = w2.y - w1.y;
		Real t2 = w3.y - w1.y;

		Real determinant = s1 * t2 - s2 * t1;

		if( !COLLADABU::Math::Utils::equalsZero( determinant ) )
		{
			Real r = (Real)1.0 / determinant;
			texTangent.set( (t2 * x1 - t1 * x2) * r, (t2 * y1 - t1 * y2) * r, (t2 * z1 - t1 * z2) * r);
			//	tDir.set( (s1 * x2 - s2 * x1) * r, (s1 * y2 - s2 * y1) * r, (s1 * z2 - s2 * z1) * r);
		}
		else
		{
			texTangent.set( x1, y1, z1 );
		}

		texTangent.normalise();
	}



	//---------------------------------------------------------------
	void TexTangentCalculator::calculateTriangleMeshTextangents()
	{
		mTexTangents.clear();

		//Mesh mesh = mTriObject->GetMesh();

		int numFaces = mMesh->getFaceCount();

		mIndices.reserve( numFaces * 3 );

		Vector3 geometryVertex[3];
		Vector3 textureVertex[3];
		Vector3 normalVertex[3];
		Vector3 texTangent[3];
		Vector3 computetTexTangent;
/*		Vector3 basisVectors[2];
		Vector3 basisVectors2[2];
		*/

//		MeshMap& meshMap = mTriObject->GetMesh().Map ( channelIndex );

//		TVFace* mapFaces = meshMap.tf;
//		UVVert* mapVerts = meshMap.tv;


		for ( int i = 0; i < numFaces; ++i)
		{
/*			Face& geomFace = mesh.faces[i];
			int index1 = geomFace.v[0];
			int index2 = geomFace.v[1];
			int index3 = geomFace.v[2];
*/
			int vertexIndex1 = mMesh->getPositionIndex(i, 0);
			int vertexIndex2 = mMesh->getPositionIndex(i, 1);
			int vertexIndex3 = mMesh->getPositionIndex(i, 2);

			geometryVertex[0] = mMesh->getVertex(vertexIndex1);
			geometryVertex[1] = mMesh->getVertex(vertexIndex2);
			geometryVertex[2] = mMesh->getVertex(vertexIndex3);

/*			TVFace& mapFace = mapFaces[i];
			textureVertex[0] = mapVerts[ mapFace.t[0] ];
			textureVertex[1] = mapVerts[ mapFace.t[1] ];
			textureVertex[2] = mapVerts[ mapFace.t[2] ];
*/
			int textureIndex1 = mMesh->getTexcoordIndex(i, 0);
			int textureIndex2 = mMesh->getTexcoordIndex(i, 1);
			int textureIndex3 = mMesh->getTexcoordIndex(i, 2);

			textureVertex[0] = mMesh->getTexcoord( textureIndex1 );
			textureVertex[1] = mMesh->getTexcoord( textureIndex2 );
			textureVertex[2] = mMesh->getTexcoord( textureIndex3 );

			computeTangent( textureVertex, geometryVertex, computetTexTangent );

/*			Point3 mapNormal = FNormalize( (textureVertex[1] - textureVertex[0]) ^ (textureVertex[2] - textureVertex[1]) );
			if( mapNormal.z<0 ) 
			{
				basisVectors[1] = -basisVectors[1]; //is the UV face flipped? flip the binormal
			}
*/

			int normalIndex1 = mMesh->getNormalIndex(i, 0);
			int normalIndex2 = mMesh->getNormalIndex(i, 1);
			int normalIndex3 = mMesh->getNormalIndex(i, 2);

			normalVertex[0] = mMesh->getNormal( normalIndex1 );
			normalVertex[1] = mMesh->getNormal( normalIndex2 );
			normalVertex[2] = mMesh->getNormal( normalIndex3 );

			texTangent[0] = computetTexTangent - normalVertex[0] * (normalVertex[0].dotProduct(computetTexTangent));
			texTangent[1] = computetTexTangent - normalVertex[1] * (normalVertex[1].dotProduct(computetTexTangent));
			texTangent[2] = computetTexTangent - normalVertex[2] * (normalVertex[2].dotProduct(computetTexTangent));

			mIndices.push_back(addTexTangent( vertexIndex1, normalIndex1, textureIndex1, texTangent[0] ));
			mIndices.push_back(addTexTangent( vertexIndex2, normalIndex2, textureIndex2, texTangent[1] ));
			mIndices.push_back(addTexTangent( vertexIndex3, normalIndex3, textureIndex3, texTangent[2] ));

		}

		normalizeTangentsAndCalculateBiTangents();
	}

	//---------------------------------------------------------------
	unsigned long TexTangentCalculator::addTexTangent( int vertexIndex, int normalIndex, int textureIndex, const Vector3& texTangent )
	{
		VertexIdentifier vertexIdentifier;
		vertexIdentifier.positionIndex = vertexIndex;
		vertexIdentifier.normalIndex = normalIndex;
		vertexIdentifier.textureIndex = textureIndex;
		VertexIdentifierVertexTexTangentInfoMap::iterator it = mVertexIdentifierVertexTexTangentInfoMap.find(vertexIdentifier);
		if ( it == mVertexIdentifierVertexTexTangentInfoMap.end() )
		{
			VertexTexTangentInfo* vertexTexTangentInfo = new VertexTexTangentInfo;
			vertexTexTangentInfo->tangent = texTangent;
			vertexTexTangentInfo->count = 1;
			vertexTexTangentInfo->index = mTexTangentsCount++;
			mTexTangents.push_back(vertexTexTangentInfo);
			mVertexIdentifierVertexTexTangentInfoMap.insert(std::make_pair(vertexIdentifier, vertexTexTangentInfo));
			return vertexTexTangentInfo->index;
		}
		else
		{
			VertexTexTangentInfo& vertexTexTangentInfo = *it->second;
			vertexTexTangentInfo.tangent += texTangent;
			vertexTexTangentInfo.count++;
			return vertexTexTangentInfo.index;
		}
	}

	//---------------------------------------------------------------
	void TexTangentCalculator::normalizeTangentsAndCalculateBiTangents()
	{
		VertexIdentifierVertexTexTangentInfoMap::iterator it = mVertexIdentifierVertexTexTangentInfoMap.begin();
		VertexIdentifierVertexTexTangentInfoMap::iterator endIt = mVertexIdentifierVertexTexTangentInfoMap.end();
		for ( ; it != endIt; ++it)
		{
			VertexTexTangentInfo& vertexTexTangentInfo = *it->second;
			vertexTexTangentInfo.tangent = vertexTexTangentInfo.tangent / (Real)(vertexTexTangentInfo.count);

			const VertexIdentifier& vertexIdentifier = it->first;
			Vector3 normal = mMesh->getNormal( vertexIdentifier.normalIndex );

			vertexTexTangentInfo.biTangent = vertexTexTangentInfo.tangent.crossProduct( normal );
			vertexTexTangentInfo.biTangent.normalise();
		}
	}

	//---------------------------------------------------------------
	void TexTangentCalculator::clearTexTangentData()
	{
		mTexTangents.clear();
		deleteTexTangentInfo();
		mVertexIdentifierVertexTexTangentInfoMap.clear();
	}

	//---------------------------------------------------------------
	void TexTangentCalculator::deleteTexTangentInfo()
	{
		VertexIdentifierVertexTexTangentInfoMap::iterator it = mVertexIdentifierVertexTexTangentInfoMap.begin();
		VertexIdentifierVertexTexTangentInfoMap::iterator endIt = mVertexIdentifierVertexTexTangentInfoMap.end();
		for ( ; it != endIt; ++it)
		{
			delete it->second;
		}
	}

	//---------------------------------------------------------------
	bool TexTangentCalculator::VertexIdentifier::operator<( const VertexIdentifier& rhs ) const
	{
		if ( positionIndex <  rhs.positionIndex )
			return true;

		if ( positionIndex >  rhs.positionIndex )
			return false;

		if ( normalIndex <  rhs.normalIndex )
			return true;

		if ( normalIndex >  rhs.normalIndex	 )
			return false;

		if ( textureIndex <  rhs.textureIndex )
			return true;

		if ( textureIndex >  rhs.textureIndex )
			return false;

		return false;
	}

} // namespace COLLADAMax
