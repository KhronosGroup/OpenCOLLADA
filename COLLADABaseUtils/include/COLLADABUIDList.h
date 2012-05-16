/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_IDLIST_H__
#define __COLLADABU_IDLIST_H__

#include "COLLADABUPrerequisites.h"
#include "COLLADABUUtils.h"

#include <set>


namespace COLLADABU
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
        virtual ~IDList() {}

        /** Takes the string @a newId, checks that it is a valid id, if necessary changes it to
        a valid id and adds it to the list of ids managed by IDList. If the id already exists a number
        is added to make it unique. The resulting string is returned
        @param newId The id / String to add
        @param returnConverted If true, the converted new string is returned, otherwise the original string (@a newId) 
        probably with a number appended is returned.
        @param alwaysAddNumberSuffix If true, a number suffix will be append to the given string, also if not necessary.
        @return The unique string, added to List. 
        */
        String addId ( const String & newId, bool returnConverted = true, bool alwaysAddNumberSuffix = false );

        /**
         * Returns true, if the given id already exists in the current id set.
         */
        bool containsId ( const String& id );

    private:
        /** Disable default copy ctor. */
		IDList( const IDList& pre );
        /** Disable default assignment operator. */
		const IDList& operator= ( const IDList& pre );

	};
} // namespace COLLADABU

#endif // __COLLADABU_IDLIST_H__
