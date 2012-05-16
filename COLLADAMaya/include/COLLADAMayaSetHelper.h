/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
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

