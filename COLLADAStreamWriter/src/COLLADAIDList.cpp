/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
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

        String idCanditate;

        size_t numberSuffix = 0;

        do
        {
            numberSuffix++;
            idCanditate = newIdChecked + Utils::toString ( numberSuffix );
        }

        while ( mIdSet.find ( idCanditate ) != mIdSet.end() );

        mIdSet.insert ( idCanditate );

        return idCanditate;

    }




}