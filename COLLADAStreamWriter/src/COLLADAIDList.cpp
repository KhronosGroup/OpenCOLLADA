/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAIDList.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    String IDList::addId ( const String & newId )
    {
        String newIdChecked = Utils::checkID ( newId );

        IDSet::iterator it = mIdSet.find ( newIdChecked );
        if ( it == mIdSet.end() )
        {
            mIdSet.insert ( newIdChecked );
            return newIdChecked;
        }

        String idCandidate;
        size_t numberSuffix = 0;
        do
        {
            numberSuffix++;
            idCandidate = newIdChecked + "_" + Utils::toString ( numberSuffix );
        }
        while ( mIdSet.find ( idCandidate ) != mIdSet.end() );

        mIdSet.insert ( idCandidate );

        return idCandidate;

    }


}