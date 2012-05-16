/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE23dsStableHeaders.h"
#include "DAE23dsMeshSpliterDumper.h"


namespace DAE23ds
{

    //------------------------------
	MeshSpliterDumper::MeshSpliterDumper()
		: mFlusher( "c:\\temp\\dump.txt", 1024*1024*2)
		, mCharacterBuffer( 1024*1024*4, &mFlusher)
	{
	}
	
    //------------------------------
	MeshSpliterDumper::~MeshSpliterDumper()
	{
	}

	//------------------------------
	void MeshSpliterDumper::handleTriangle( const TriangleType& triangle )
	{
		mCharacterBuffer.copyToBufferAsChar( triangle.indices[0] );
		mCharacterBuffer.copyToBuffer( ", " );
		mCharacterBuffer.copyToBufferAsChar( triangle.indices[1] );
		mCharacterBuffer.copyToBuffer( ", " );
		mCharacterBuffer.copyToBufferAsChar( triangle.indices[2] );
		mCharacterBuffer.copyToBuffer( "\n" );
	}

	//------------------------------
	void MeshSpliterDumper::handleNewBlock()
	{
		mCharacterBuffer.copyToBuffer( "New block\n" );
	}
} // namespace DAE23ds
