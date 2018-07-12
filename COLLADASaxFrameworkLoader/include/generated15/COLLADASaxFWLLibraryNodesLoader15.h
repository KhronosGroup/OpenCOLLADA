/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYNODESLOADER15_H__
#define __COLLADASAXFWL_LIBRARYNODESLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryNodesLoader.h"
#include "COLLADASaxFWLNodeLoader15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryNodesLoader15 : public NodeLoader15
{
private:
LibraryNodesLoader* mLoader;

public:
LibraryNodesLoader15(LibraryNodesLoader* loader)
 : NodeLoader15(loader)
 , mLoader(loader)
{}


virtual bool begin__node( const COLLADASaxFWL15::node__AttributeData& attributeData );

virtual bool end__node();

virtual bool end__library_nodes();

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
LibraryNodesLoader15(const LibraryNodesLoader15&);
/** Disable default assignment operator. */
const LibraryNodesLoader15& operator=(const LibraryNodesLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYNODESLOADER15_H__
