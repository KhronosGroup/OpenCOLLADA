/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYNODESLOADER14_H__
#define __COLLADASAXFWL_LIBRARYNODESLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryNodesLoader.h"
#include "COLLADASaxFWLNodeLoader14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryNodesLoader14 : public NodeLoader14
{
private:
LibraryNodesLoader* mLoader;

public:
LibraryNodesLoader14(LibraryNodesLoader* loader)
 : NodeLoader14(loader)
 , mLoader(loader)
{}


virtual bool begin__node( const COLLADASaxFWL14::node__AttributeData& attributeData );

virtual bool end__node();

virtual bool end__library_nodes();

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
LibraryNodesLoader14(const LibraryNodesLoader14&);
/** Disable default assignment operator. */
const LibraryNodesLoader14& operator=(const LibraryNodesLoader14&);
};
}
#endif // __COLLADASAXFWL_LIBRARYNODESLOADER14_H__
