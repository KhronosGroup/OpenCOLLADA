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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaSetHelper.h"

#include <maya/MStringArray.h>
#include <maya/MDagPath.h>
#include <maya/MItDependencyNodes.h>
#include <maya/MFnSet.h>
#include <maya/MFnDagNode.h>
#include <maya/MSelectionList.h>

namespace COLLADAMaya
{
    std::vector<MObjectHandle> SetHelper::setObjects;
    SetHelper::SetModes SetHelper::setMode;

    // ------------------------------------------------------
    // Unlike Maya's default behavior, we want to consider set membership to be inheritable
    bool SetHelper::isMemberOfSet ( const MDagPath& dagPath, MFnSet& Set )
    {
        if ( Set.isMember ( dagPath ) )
        {
            return true;
        }

        else
        {
            MFnDagNode dagNode ( dagPath );
            MSelectionList setMembers;
            Set.getMembers ( setMembers, true );

            for ( unsigned int i = 0; i < setMembers.length(); ++i )
            {
                MObject memberObject;

                if ( setMembers.getDependNode ( i, memberObject ) )
                {
                    if ( dagNode.isChildOf ( memberObject ) )
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    // ------------------------------------------------------
    bool SetHelper::isExcluded ( const MDagPath& dagPath )
    {
        MFnDagNode dagNode ( dagPath );

        if ( dagNode.name() == "world" )
            return false;

        bool bContainedInSet = false;

        for ( unsigned int i = 0; i < SetHelper::setObjects.size(); ++i )
        {
#  if MAYA_API_VERSION < 600
            MObject o = SetHelper::setObjects[i];
#  else
            MObject o = SetHelper::setObjects[i].object();
#  endif
            MFnSet currentSet ( o );

            if ( isMemberOfSet ( dagPath, currentSet ) )
            {
                bContainedInSet = true;
                break;
            }
        }

        if ( setMode == kExcluding )
        {
            return bContainedInSet;
        }

        else if ( setMode == kIncludeOnly )
        {
            return !bContainedInSet;
        }

        else
        {
            return false;
        }
    }

}