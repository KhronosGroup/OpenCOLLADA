/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_MESHHANDLER_H__
#define __DAE23DS_MESHHANDLER_H__

#include "DAE23dsPrerequisites.h"
#include "DAE23dsBaseWriter.h"


namespace DAE23ds
{

	class MeshHandler : public BaseWriter 
	{
	private:
		const COLLADAFW::Mesh* mMesh;
	
	public:

        /** Constructor. */
		MeshHandler(Writer* writer3ds, const COLLADAFW::Mesh* mesh);

        /** Destructor. */
		virtual ~MeshHandler();

		bool handle(); 

	private:

        /** Disable default copy ctor. */
		MeshHandler( const MeshHandler& pre );

        /** Disable default assignment operator. */
		const MeshHandler& operator= ( const MeshHandler& pre );

	};

} // namespace DAE23DS

#endif // __DAE23DS_MESHHANDLER_H__
