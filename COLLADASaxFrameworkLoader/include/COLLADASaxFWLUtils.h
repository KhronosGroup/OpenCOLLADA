/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_UTILS_H__
#define __COLLADASAXFWL_UTILS_H__

#include "COLLADASaxFWLPrerequisites.h"

#include "COLLADAFWPrerequisites.h"


namespace COLLADASaxFWL
{

    
	/** Deletes the contents of the std vector @a list by calling FW_DELETE. @a ListType must be a pointer.
	The objects in vector must have been created using FW_NEW.*/
	template<class ListType>
	void deleteVectorFW( const std::vector<ListType>& list )
	{
		for ( size_t i = 0, count = list.size(); i < count; ++i)
		{
			ListType listItem = list[i];
			FW_DELETE listItem;
		}
	}


	/** Deletes the contents of the std vector @a list by calling delete. @a ListType must be a pointer.
	The objects in vector must have been created using new.*/
	template<class ListType>
	void deleteVector( const std::vector<ListType>& list )
	{
		for ( size_t i = 0, count = list.size(); i < count; ++i)
		{
			ListType listItem = list[i];
			delete listItem;
		}
	}

	/** Deletes the values of the Map @a map by calling delete. The value of the map must be a pointer.
	The values in map must have been created using new.*/
	template<class MapType>
	void deleteMap( const MapType& map )
	{
		typename MapType::const_iterator it = map.begin();
		for ( ; it != map.end(); ++it)
		{
			delete it->second;
		}
	}


} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_UTILS_H__
