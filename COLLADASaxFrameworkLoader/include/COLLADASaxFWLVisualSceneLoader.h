/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_VISUALSCENELOADER_H__
#define __COLLADASAXFWL_VISUALSCENELOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"

#include "COLLADAFWNode.h"


namespace COLLADAFW
{ 
	class VisualScene;
}

namespace COLLADASaxFWL
{

    /** Imports the entire visual scene and sends it to the writer. */
	class VisualSceneLoader : public FilePartLoader 
		{
	private:
		/** Stack of nodes.*/
		typedef std::stack<COLLADAFW::Node*> NodeStack;

		/** Pointer to the visual scene this loader creates.*/
		COLLADAFW::VisualScene* mVisualScene;

		/** Stack of nodes to traverse back in node hierarchy. Array and contents will be delete in destructor.*/
		NodeStack mNodeStack;

	public:

        /** Constructor. */
		VisualSceneLoader(IFilePartLoader* callingFilePartLoader);

        /** Destructor. */
		virtual ~VisualSceneLoader();

	private:

        /** Disable default copy ctor. */
		VisualSceneLoader( const VisualSceneLoader& pre );

        /** Disable default assignment operator. */
		const VisualSceneLoader& operator= ( const VisualSceneLoader& pre );

		bool beginNode( const char* nodeName );

		bool endNode();

		virtual bool begin__visual_scene__node( const visual_scene__node__AttributeData& attributeData );

		virtual bool end__visual_scene__node();

		virtual bool end__visual_scene();



	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_VISUALSCENELOADER_H__
