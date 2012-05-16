/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_MESHSPLITERDUMPER_H__
#define __DAE23DS_MESHSPLITERDUMPER_H__

#include "DAE23dsPrerequisites.h"
#include "CommonCharacterBuffer.h"
#include "CommonFWriteBufferFlusher.h"

#include "DAE23dsTriangle.h"


namespace DAE23ds
{

	class MeshSpliterDumper 	
	{
	public:
		typedef Triangle<short> TriangleType;

	private:

		Common::FWriteBufferFlusher mFlusher;

		Common::CharacterBuffer mCharacterBuffer;
	
	public:

        /** Constructor. */
		MeshSpliterDumper();

        /** Destructor. */
		virtual ~MeshSpliterDumper();

		void handleTriangle( const TriangleType& triangle);

		void handleNewBlock();

	private:

        /** Disable default copy ctor. */
		MeshSpliterDumper( const MeshSpliterDumper& pre );

        /** Disable default assignment operator. */
		const MeshSpliterDumper& operator= ( const MeshSpliterDumper& pre );

	};

} // namespace DAE23ds

#endif // __DAE23DS_MESHSPLITERDUMPER_H__
