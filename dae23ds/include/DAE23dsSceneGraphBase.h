/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_SCENEGRAPHBASE_H__
#define __DAE23DS_SCENEGRAPHBASE_H__

#include "DAE23dsPrerequisites.h"
#include "DAE23dsBaseWriter.h"


namespace DAE23ds
{

	class SceneGraphBase : public BaseWriter 
	{
	private:
		typedef std::map<const COLLADAFW::InstanceGeometry*, size_t> InstanceGeometryNextInstanceNumberMap;

	protected:
		const COLLADAFW::VisualScene* mVisualScene;
		const Writer::LibraryNodesList& mLibraryNodesList;

	private:
		/** Maps each instance to the next instance number.*/
		InstanceGeometryNextInstanceNumberMap mInstanceGeometryNextInstanceNumberMap;
	
	public:

        /** Constructor. */
		SceneGraphBase( Writer* writer3ds, const COLLADAFW::VisualScene* visualScene, const Writer::LibraryNodesList& libraryNodesList );

        /** Destructor. */
		virtual ~SceneGraphBase();

	protected:

		/** Returns the next instance number for @a instance. It is used to uniquely identify instances that occur multiple times.*/
		size_t getNextInstanceNumber( const COLLADAFW::InstanceGeometry* instance);

	private:

        /** Disable default copy ctor. */
		SceneGraphBase( const SceneGraphBase& pre );

        /** Disable default assignment operator. */
		const SceneGraphBase& operator= ( const SceneGraphBase& pre );

	};

} // namespace DAE23DS

#endif // __DAE23DS_SCENEGRAPHBASE_H__
