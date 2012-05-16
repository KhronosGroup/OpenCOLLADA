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

#ifndef __COLLADAMAX_IMESHACCESS_H__
#define __COLLADAMAX_IMESHACCESS_H__

#include "COLLADAMaxPrerequisites.h"

#include "Math/COLLADABUMathVector3.h"

namespace COLLADAMax
{

    /** Interface to access mesh data. Used by TexTangentCalculator */
	class IMeshAccess 	
	{
	private:
	
	public:

        /** Constructor. */
		IMeshAccess() {}

        /** Destructor. */
		virtual ~IMeshAccess(){}

		/** Returns the number of faces in the mesh.*/
		virtual int getFaceCount() = 0;

		/** Returns the number of vertices of the face with index @a faceIndex.*/
		virtual int getVertexCount( int faceIndex ) = 0;

		/** Returns the vertex index of the @a faceVertexIndex'th vertex of the @a faceIndex'th face.*/
		virtual int getPositionIndex( int faceIndex, int faceVertexIndex) = 0;

		/** Returns the position of the vertex with index @a vertexIndex.*/
		virtual COLLADABU::Math::Vector3 getVertex( int vertexIndex ) = 0;

		/** Returns the normal index of the @a faceVertexIndex'th vertex of the @a faceIndex'th face.*/
		virtual int getNormalIndex( int faceIndex, int faceVertexIndex) = 0;

		/** Returns the normal with index @a normalIndex.*/
		virtual COLLADABU::Math::Vector3 getNormal( int normalIndex ) = 0;

		/** Returns the texcoord index of the @a faceVertexIndex'th vertex of the @a faceIndex'th face.*/
		virtual int getTexcoordIndex( int faceIndex, int faceVertexIndex) = 0;

		/** Returns the texcoord with index @a textureIndex.*/
		virtual COLLADABU::Math::Vector3 getTexcoord( int textureIndex ) = 0;


	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_IMESHACCESS_H__
