/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_MESHSPLITER_IMPL_H__
#define __DAE23DS_MESHSPLITER_IMPL_H__

#include "DAE23dsPrerequisites.h"

namespace DAE23ds
{


	//------------------------------
	template<class MeshAccessor, class _AccessorIndexType, class TriangleHandler, class _HandlerIndexType>
	MeshSpliter<MeshAccessor, _AccessorIndexType, TriangleHandler, _HandlerIndexType>::MeshSpliter( const MeshAccessor& meshAccessor, TriangleHandler& triangleHandler)
		: mMeshAccessor(meshAccessor)
		, mTriangleHandler(triangleHandler)
		, mTrianglesCount( mMeshAccessor.getTrianglesCount())
		, mHandledTriangles( mTrianglesCount, false )
	{

	}


	//------------------------------
	template<class MeshAccessor, class _AccessorIndexType, class TriangleHandler, class _HandlerIndexType>
	DAE23ds::MeshSpliter<MeshAccessor, _AccessorIndexType, TriangleHandler, _HandlerIndexType>::~MeshSpliter()
	{

	}

	//------------------------------
	template<class MeshAccessor, class _AccessorIndexType, class TriangleHandler, class _HandlerIndexType>
	bool 
		DAE23ds::MeshSpliter<MeshAccessor, _AccessorIndexType, TriangleHandler, _HandlerIndexType>::splitTest()
	{

		//testing
		AccessorIndexType count = mMeshAccessor.getTrianglesCount();
		AccessorTriangle triAccessor = mMeshAccessor.getTriangle( 0 );
		HandlerTriangle triHandler((HandlerIndexType)triAccessor.indices[0], 
			(HandlerIndexType)triAccessor.indices[1], 
			(HandlerIndexType)triAccessor.indices[2]);
		mTriangleHandler.handleTriangle(triHandler);


		for ( AccessorIndexType i = 1; i < count; ++i)
		{
			AccessorTriangle triAccessor = mMeshAccessor.getNextTriangle( );
			HandlerTriangle triHandler((HandlerIndexType)triAccessor.indices[0], 
				(HandlerIndexType)triAccessor.indices[1], 
				(HandlerIndexType)triAccessor.indices[2]);
			mTriangleHandler.handleTriangle(triHandler);
		}
		return true;
	}

	//------------------------------
	template<class MeshAccessor, class _AccessorIndexType, class TriangleHandler, class _HandlerIndexType>
	bool 
		DAE23ds::MeshSpliter<MeshAccessor, _AccessorIndexType, TriangleHandler, _HandlerIndexType>::split()
	{


		return true;
	}


} // namespace DAE23ds

#endif // __DAE23DS_MESHSPLITER_IMPL_H__
