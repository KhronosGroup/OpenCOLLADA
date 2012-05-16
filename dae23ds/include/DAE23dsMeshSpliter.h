/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_MESHSPLITER_H__
#define __DAE23DS_MESHSPLITER_H__

#include "DAE23dsPrerequisites.h"
#include "DAE23dsBitSet.h"

namespace COLLADAFW
{
	class Mesh;
}

namespace DAE23ds
{

	template<class MeshAccessor, class _AccessorIndexType, class TriangleHandler, class _HandlerIndexType>
	class MeshSpliter 	
	{
	public:
		typedef _AccessorIndexType AccessorIndexType;
		typedef _HandlerIndexType HandlerIndexType;

		typedef Triangle<AccessorIndexType> AccessorTriangle; 
		typedef Triangle<HandlerIndexType> HandlerTriangle; 
	private:

		/** The mesh accessor of the mesh to split. */
		const MeshAccessor& mMeshAccessor;

		/** The triangle handler that handles the triangles and chunks. */
		TriangleHandler& mTriangleHandler;

		/** The number of triangles in the mesh.*/
		AccessorIndexType mTrianglesCount;

		/** bitset to store which triangle has already been handled true = "is exported"*/
		BitSet mHandledTriangles;

		/** Maximal number of tringles per block.*/
		size_t mMaxTrianglesPerBlock;
	
	public:
        /** Constructor. */
		MeshSpliter( const MeshAccessor& meshAccessor, TriangleHandler& triangleHandler);

        /** Destructor. */
		virtual ~MeshSpliter();

		/** Performances the splitting of the mesh.*/
		bool split();

		/** Performances the splitting of the mesh.*/
		bool splitTest();

	private:

        /** Disable default copy ctor. */
		MeshSpliter( const MeshSpliter& pre );

        /** Disable default assignment operator. */
		const MeshSpliter& operator= ( const MeshSpliter& pre );

	};

} // namespace DAE23ds


#include "DAE23dsMeshSpliter_impl.h"

#endif // __DAE23DS_MESHSPLITER_H__
