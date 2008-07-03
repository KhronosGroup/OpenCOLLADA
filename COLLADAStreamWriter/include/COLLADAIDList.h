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

#ifndef __COLLADASTREAMWRITER_IDLIST_H__
#define __COLLADASTREAMWRITER_IDLIST_H__

#include "COLLADAPrerequisites.h"

#include <set>

namespace COLLADA
{

    /** A class to generate and store unique and valid ids.*/

    class IDList
    {

    public:
        /** Constructor*/
        IDList() {}

        /** Destructor*/
        ~IDList() {}

        /** Takes the string @a newId, checks that it is a valid id, if necessary changes it to
        a valid id and adds it to the list of ids managed by IDList. If the id already exists a number
        is added to make it unique. The resulting string is returned*/
        String addId ( const String & newId );


    private:
        typedef std::set<String> IDSet;

        /** A map that stores ids that are already managed by this instance of IDList.*/
        IDSet mIdSet;

    };


}

#endif // #define __COLLADASTREAMWRITER_IDLIST_H__
