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
#ifndef __COLLADA_MAYA_SET_HELPER_H__
#define __COLLADA_MAYA_SET_HELPER_H__

#if MAYA_API_VERSION < 600
typedef MObject MObjectHandle;
#else
# include <maya/MObjectHandle.h>
#endif

#include <vector>

class MStringArray;

class MDagPath;

class MFnSet;

namespace COLLADAMaya
{
    /**
     * todo Doku
     */

    class SetHelper
    {

    public:
        enum SetModes
        {
            kExcluding,
            kIncludeOnly
        };

        static bool setSets ( const MStringArray& sets, SetModes desiredMode );
        static bool isExcluded ( const MDagPath& dagPath );

    private:

        /** Don't create an object of this class. */
        SetHelper() {};

        /** Unlike Maya's default behavior, we want to consider set membership to be inheritable. */
        static bool isMemberOfSet ( const MDagPath& dagPath, MFnSet& Set );

    private:

        static std::vector<MObjectHandle> setObjects;
        static SetModes setMode;
    };
}

#endif // __COLLADA_MAYA_SET_HELPER_H__

