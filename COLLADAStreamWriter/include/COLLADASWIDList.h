/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADASWStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_IDLIST_H__
#define __COLLADASTREAMWRITER_IDLIST_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWUtils.h"

#include <set>

namespace COLLADASW
{

    /** A class to generate and store unique and valid ids.*/

    class IDList
    {
	private:
		typedef std::set<String> IDSet;

		typedef String (*StringConversionFunction)(const String&);

	private:
		/** Conversion function used to convert added Values*/
		StringConversionFunction mConversionFunction;

		/** A map that stores ids that are already managed by this instance of IDList.*/
		IDSet mIdSet;

    public:
        /** Constructor*/
		IDList(StringConversionFunction conversionFunction = Utils::checkID);

        /** Destructor*/
        ~IDList() {}

        /** Takes the string @a newId, checks that it is a valid id, if necessary changes it to
        a valid id and adds it to the list of ids managed by IDList. If the id already exists a number
        is added to make it unique. The resulting string is returned
		@param newId The id / String to add
		@param returnConverted If true, the converted new string is returned, otherwise the original string (@a newId) 
		probably with a number appended is returned.
		@return The unique string, added to List. 
		*/
        String addId ( const String & newId, bool returnConverted = true);

    };


}

#endif // #define __COLLADASTREAMWRITER_IDLIST_H__
