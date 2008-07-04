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