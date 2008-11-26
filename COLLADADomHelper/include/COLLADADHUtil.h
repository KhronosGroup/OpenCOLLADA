/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_UTIL_H__
#define __COLLADA_UTIL_H__

#include "COLLADADHStableHeaders.h"

namespace COLLADADH
{
    /** Retrieves the children of a specific type from the given daeElement.
    	@param element The element to retrieve the children from.
    	@param type The type of children to retrieve.
    	@param children The array to populate with the children.
    */
    template<class T>
        void getChildrenOfType(const daeElementRef& element, COLLADA_TYPE::TypeEnum type, daeTArray< daeSmartRef<T> >& children)
	{
		daeElementRefArray allChildren;
		element->getChildren(allChildren);
		for(size_t i=0, count=allChildren.getCount(); i<count; ++i)
		{
			const daeElementRef& child = allChildren.get(i);
			if(child->getElementType() == type)
			{
				children.append(daeSafeCast<T>(child));
			}
		}
	}

	/** Checks for a valid xs:NCName.
		1. string is one word
		2. begins with a letter or an _
	*/
	std::string checkNCName(const std::string &ncName);

	/** Checks for a valid xs:ID.
	1. string is one word
	2. begins with a letter or an _
	*/
	std::string checkID(const std::string &id);

}
#endif // #define __COLLADA_UTIL_H__
