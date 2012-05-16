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

#ifndef __COLLADAMAX_MESHACCESS_H__
#define __COLLADAMAX_MESHACCESS_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAMaxIMeshAccess.h"

#include <max.h>


namespace COLLADAMax
{

    /** Implements IMeshAccess for a max mesh */
	class MeshAccess : public IMeshAccess
	{
	private:
		Mesh& mMesh;
		MeshNormalSpec *mNormalSpec;
		MeshMap& mTextureMap;

	public:

        /** Constructor. */
		MeshAccess( Mesh& mesh, int mapChannel) 
			: mMesh(mesh)
			, mNormalSpec(mesh.GetSpecifiedNormals())
			, mTextureMap(mesh.Map ( mapChannel ))
		{
			if ( !mNormalSpec )
			{
				mesh.SpecifyNormals();
				mNormalSpec = mesh.GetSpecifiedNormals();
			}
		}

        /** Destructor. */
		virtual ~MeshAccess(){}

		/** Returns the number of faces in the mesh.*/
		virtual int getFaceCount() { return mMesh.getNumFaces(); }

		/** Returns the number of vertices of the face with index @a faceIndex.*/
		virtual int getVertexCount( int faceIndex ) { return 3; }

		/** Returns the vertex index of the @a faceVertexIndex'th vertex of the @a faceIndex'th face.*/
		virtual int getPositionIndex( int faceIndex, int faceVertexIndex) { return mMesh.faces[faceIndex].v[faceVertexIndex]; }

		/** Returns the position of the vertex with index @a vertexIndex.*/
		virtual COLLADABU::Math::Vector3 getVertex( int vertexIndex ) 
		{
			Point3& vertex = mMesh.verts[vertexIndex];
			return COLLADABU::Math::Vector3(vertex.x, vertex.y, vertex.z);
		}

		/** Returns the normal index of the @a faceVertexIndex'th vertex of the @a faceIndex'th face.*/
		virtual int getNormalIndex( int faceIndex, int faceVertexIndex){ return mNormalSpec->GetNormalIndex ( faceIndex, faceVertexIndex ) ; }

		/** Returns the normal with index @a normalIndex.*/
		virtual COLLADABU::Math::Vector3 getNormal( int normalIndex )
		{
			Point3 & normal = mNormalSpec->Normal ( normalIndex );
			return COLLADABU::Math::Vector3(normal.x, normal.y, normal.z);
		}

		/** Returns the texcoord index of the @a faceVertexIndex'th vertex of the @a faceIndex'th face.*/
		virtual int getTexcoordIndex( int faceIndex, int faceVertexIndex) { return mTextureMap.tf[ faceIndex ].t[faceVertexIndex];}

		/** Returns the texcoord with index @a textureIndex.*/
		virtual COLLADABU::Math::Vector3 getTexcoord( int textureIndex ) 
		{
			Point3& texCoord = mTextureMap.tv[ textureIndex ];
			return COLLADABU::Math::Vector3(texCoord.x, texCoord.y, texCoord.z);
		}

	private:

        /** Disable default copy ctor. */
		MeshAccess( const MeshAccess& pre );

        /** Disable default assignment operator. */
		const MeshAccess& operator= ( const MeshAccess& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_MESHACCESS_H__
