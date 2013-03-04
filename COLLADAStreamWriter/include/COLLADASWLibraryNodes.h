/*
	Copyright (c) 2011 Nathan Letwory

	This file is part of COLLADAStreamWriter.

	Licensed under the MIT Open Source License, 
	for details please see LICENSE file or the website
	http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_LIBRARY_NODES_H__
#define __COLLADASTREAMWRITER_LIBRARY_NODES_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWLibrary.h"

namespace COLLADASW
{

	/** Class to simplify the creation of @a \<library_nodes\> and @a \<node\>'s*/

	class LibraryNodes : public Library
	{

	public:
		/** Constructor
		@param streamWriter The stream the @a \<library_nodes\> and @a \<node\>'s
		should be written to.
		*/
		LibraryNodes ( StreamWriter* streamWriter );

		/** Destructor*/
		virtual ~LibraryNodes() {}

	protected:
		/** Writes the opening @a \<node\> tag and, if necessary the opening @a \<library_nodes\> tag.
		closeNode() must be use to close the opened tags.
		@param id the id of the node*/
		void openNode ( const String& nodeId = EMPTY_STRING, const String& nodeName = EMPTY_STRING );

		/** Closes the tag opened by openNode()*/
		void closeNode();

	private:
		TagCloser mCurrentNodeCloser;  //!< Current <node> tag closer.
	};

}

#endif //__COLLADASTREAMWRITER_LIBRARY_NODES_H__
