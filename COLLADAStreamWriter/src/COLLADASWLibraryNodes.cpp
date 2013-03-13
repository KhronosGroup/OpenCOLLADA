/*
	Copyright (c) 2011 Cooperative Studio Lumikuu

	This file is part of COLLADAStreamWriter.
	
	Licensed under the MIT Open Source License, 
	for details please see LICENSE file or the website
	http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryNodes.h"
#include "COLLADASWConstants.h"
#include "COLLADABUUtils.h"

namespace COLLADASW
{
	LibraryNodes::LibraryNodes ( COLLADASW::StreamWriter *streamWriter )
		: Library ( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_NODES )
	{}

	void LibraryNodes::openNode ( const String &nodeId, const String &nodeName )
	{
		// opening library here. TBH this looks weird and should
		// just be an explicit client call.
		openLibrary();
		
		// create tag closer
		mCurrentNodeCloser = mSW->openElement ( CSWC::CSW_ELEMENT_NODE );

		if ( !nodeId.empty() )
			mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, nodeId );

		if ( !nodeName.empty() )
			mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, nodeName );
	}

	void LibraryNodes::closeNode()
	{
		mCurrentNodeCloser.close();
	}

}
