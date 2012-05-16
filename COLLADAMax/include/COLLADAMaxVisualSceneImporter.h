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

#ifndef __COLLADAMAX_VISUALSCENEIMPORTER_H__
#define __COLLADAMAX_VISUALSCENEIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxNodeImporter.h"
#include "COLLADAFWNode.h"

#include "dummy.h"

namespace COLLADAFW
{
	class VisualScene;
};


namespace COLLADAMax
{

    /** this class imports a visual scene into the max scene graph. */
	class VisualSceneImporter : public NodeImporter
	{
	private:
		/** The visual scene that should be imported.*/
		const COLLADAFW::VisualScene* mVisualScene;
	

	public:

        /** Constructor. */
		VisualSceneImporter(DocumentImporter* documentImporter, const COLLADAFW::VisualScene* visualScene);

		/** Performs the import of the scene graph.
		@return True on success, false otherwise.*/
		bool import();

        /** Destructor. */
		virtual ~VisualSceneImporter();

	private:

        /** Disable default copy ctor. */
		VisualSceneImporter( const VisualSceneImporter& pre );

        /** Disable default assignment operator. */
		const VisualSceneImporter& operator= ( const VisualSceneImporter& pre );
	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_VISUALSCENEIMPORTER_H__
