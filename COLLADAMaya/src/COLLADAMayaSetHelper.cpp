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
    bool SetHelper::setSets ( const MStringArray& sets, SetModes desiredMode )
    {
        setObjects.clear();

        MItDependencyNodes setIter ( MFn::kSet );

        while ( !setIter.isDone() )
        {
            MFnSet currentSet ( setIter.item() );

            for ( unsigned int i = 0; i < sets.length(); ++i )
            {
                if ( strstr ( currentSet.name().asChar(), sets[i].asChar() ) != NULL )
                {
                    setObjects.push_back ( setIter.item() );
                    break;
                }
            }

            setIter.next();
        }

        setMode = desiredMode;

        return true;
    }

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