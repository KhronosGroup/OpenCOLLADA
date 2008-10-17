/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADASWStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWIDList.h"

namespace COLLADASW
{

	IDList::IDList(StringConversionFunction conversionFunction ) 
		: mConversionFunction(conversionFunction)
	{}


    String IDList::addId ( const String & newId, bool returnConverted )
    {
        String newIdChecked = mConversionFunction( newId );

        IDSet::iterator it = mIdSet.find ( newIdChecked );
        if ( it == mIdSet.end() )
        {
            mIdSet.insert ( newIdChecked );
			return returnConverted ? newIdChecked : newId;
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

		return returnConverted ? idCandidate : newId + "_" + Utils::toString ( numberSuffix );
    }


}