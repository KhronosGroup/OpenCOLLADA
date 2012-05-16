/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_VISUALSCENELOADER_H__
#define __COLLADASAXFWL_VISUALSCENELOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLNodeLoader.h"
#include "COLLADASaxFWLFilePartLoader.h"

#include "COLLADAFWNode.h"


namespace COLLADAFW
{ 
	class VisualScene;
}

namespace COLLADASaxFWL
{

    /** Imports the entire visual scene and sends it to the writer. */
	class VisualSceneLoader : public FilePartLoader, public NodeLoader
	{
	private:

		/** Pointer to the visual scene this loader creates.*/
		COLLADAFW::VisualScene* mVisualScene;

        /** Flag for the extra data, to know the parsing position. */
        bool mInNode;

	public:

        /** Constructor. */
		VisualSceneLoader(IFilePartLoader* callingFilePartLoader, const char* id);

        /** Destructor. */
		virtual ~VisualSceneLoader();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();


        /** Sax callback function for the beginning of nodes, as child of a visual scene.*/
		virtual bool begin__visual_scene__node( const node__AttributeData& attributeData );

		/** Sax callback function for the ending of nodes, as child of a visual scene.*/
		virtual bool end__visual_scene__node();

		/** Sax callback function for the ending of a visual scene.*/
		virtual bool end__visual_scene();

    private:

        /** Disable default copy ctor. */
        VisualSceneLoader( const VisualSceneLoader& pre );

        /** Disable default assignment operator. */
        const VisualSceneLoader& operator= ( const VisualSceneLoader& pre );

        /** Appends the root node to the array of root nodes of the visual scene,*/
        void handleRootNode( COLLADAFW::Node* rootNode );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_VISUALSCENELOADER_H__
