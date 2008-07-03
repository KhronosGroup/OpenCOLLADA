/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
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