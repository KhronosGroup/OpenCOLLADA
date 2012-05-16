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
#include "COLLADAMayaReferenceManager.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaDagHelper.h"

#include "maya/MFileIO.h"
#include "maya/MFnDagNode.h"
#include "maya/MFnTransform.h"


namespace COLLADAMaya
{

    // --------------------------------------
    ReferenceManager::ReferenceManager() 
    : mReferences (0)
    , mFiles (0)
    {

    }

    // --------------------------------------
    ReferenceManager::~ReferenceManager()
    {
        deleteReferences();
        deleteFiles();
    }

    // --------------------------------------
    void ReferenceManager::deleteReferences ()
    {
        if ( mReferences.size() > 0 )
        {
            for ( uint i=0; i<mReferences.size(); ++i )
            {
                Reference* reference = mReferences[i];
                delete reference;
            }
            mReferences.clear();
        }
    }

    // --------------------------------------
    void ReferenceManager::deleteFiles ()
    {
        if ( mFiles.size() > 0 )
        {
            for ( uint i=0; i<mFiles.size(); ++i )
            {
                ReferenceFile* file = mFiles[i];
                delete file;
            }
            mFiles.clear();
        }
    }

    // --------------------------------------
    void ReferenceManager::initialize()
    {
        deleteReferences ();
        deleteFiles ();

        if ( !ExportOptions::exportXRefs() || ExportOptions::dereferenceXRefs() ) return;

#if MAYA_API_VERSION >= 600

        MStatus status;
        MStringArray referenceFilenames;
        MFileIO::getReferences ( referenceFilenames );

        uint referenceCount = referenceFilenames.length();
        mReferences.reserve( referenceCount );
        for (uint i = 0; i < referenceCount; ++i)
        {
            MString& filename = referenceFilenames[i];
            MObject referenceNode = getReferenceNode ( filename );
            if ( referenceNode != MObject::kNullObj ) processReference ( referenceNode );
        }
#endif
    }

    // --------------------------------------
    MObject	ReferenceManager::getReferenceNode ( const MString& filename )
    {
        MString referenceNodeName;
        MString command = MString ( "file -q -rfn \"" ) + filename + "\"";
        MGlobal::executeCommand ( command, referenceNodeName );
        return DagHelper::getNode ( referenceNodeName );
    }

    // --------------------------------------
    void ReferenceManager::processReference ( const MObject& referenceNode )
    {
        MStatus status;
        MFnDependencyNode referenceNodeFn ( referenceNode, &status );
        if (status != MStatus::kSuccess) return;

#if MAYA_API_VERSION >= 600
        MString referenceNodeName = MFnDependencyNode( referenceNode ).name();

        Reference* reference = new Reference();
        reference->referenceNode = referenceNode;
        mReferences.push_back ( reference );

        // Get the paths of the root transforms included in this reference
        MObjectArray subReferences;
        getRootObjects ( referenceNode, reference->paths, subReferences );
        uint pathCount = reference->paths.length();

        // Process the sub-references first
        uint subReferenceCount = subReferences.length();
        for (uint i = 0; i < subReferenceCount; ++i)
        {
            MObject& subReference = subReferences[i];
            if ( subReference != MObject::kNullObj ) processReference ( subReference );
        }

        // Retrieve the reference node's filename
        MString command = MString("reference -rfn \"") + referenceNodeFn.name() + MString("\" -q -filename;");
        MString filename;
        status = MGlobal::executeCommand ( command, filename );
        if (status != MStatus::kSuccess || filename.length() == 0) return;

        // Strip the filename of the multiple file token
        int stripIndex = filename.index('{');
        if (stripIndex != -1) filename = filename.substring(0, stripIndex - 1);

        // Avoid transform look-ups on COLLADA references.
        int extLocation = filename.rindex('.');
        if (extLocation > 0)
        {
            MString ext = filename.substring(extLocation + 1, filename.length() - 1).toLowerCase();
            if (ext == "dae" || ext == "xml") return;
        }

        // Check for already existing file information
        // Otherwise create a new file information sheet with current node names
        for ( ReferenceFileList::iterator it = mFiles.begin(); it != mFiles.end(); ++it )
        {
            if ((*it)->filename == filename) 
            { 
                reference->file = (*it); 
                break; 
            }
        }

        if ( reference->file == NULL ) reference->file = processReferenceFile(filename);

        // Get the list of the root transform's first child's unreferenced parents.
        // This is a list of the imported nodes!
        for (uint j = 0; j < pathCount; ++j)
        {
            MDagPath path = reference->paths[j];
            if (path.childCount() > 0)
            {
                path.push ( path.child(0) );
                MFnDagNode childNode ( path );
                if (!childNode.object().hasFn(MFn::kTransform)) continue;

                uint parentCount = childNode.parentCount();
                for (uint k = 0; k < parentCount; ++k)
                {
                    MFnDagNode parentNode(childNode.parent(k));
                    if (parentNode.object() == MObject::kNullObj || parentNode.isFromReferencedFile()) continue;

                    MDagPath parentPath = MDagPath::getAPathTo(parentNode.object());
                    if (parentPath.length() > 0)
                    {
                        ReferenceRootList::iterator it = 
                            reference->reroots.insert( reference->reroots.end(), ReferenceRoot() );
                        (*it).index = j;
                        (*it).reroot = parentPath;
                    }
                }
            }
        }
#endif
    }

    // --------------------------------------
    ReferenceFile* ReferenceManager::processReferenceFile(const MString& filename)
    {
        ReferenceFile* file = new ReferenceFile();
        file->filename = filename;
        mFiles.push_back(file);

#if MAYA_API_VERSION >= 800
        return file; // Versions 8.00 and 8.50 of Maya don't allow us to create references inside a plug-in.

#elif MAYA_API_VERSION >= 600

        // Get the original transformations for this file.
        // 1. Create a new reference
        MString tempFilename;
        MObject tempReferenceNode;

        {
            MString command = MString("file -r -type \"COLLADA importer\" -namespace \"_TEMP_EXP_NAMESPACE\" \"") + filename + "\";";
            MGlobal::executeCommand(command, tempFilename);

            tempFilename = getLastReferenceFilename ( tempFilename );

            MObject tempReferenceNode = getReferenceNode ( tempFilename );
            MString tempNodeName = MFnDependencyNode(tempReferenceNode).name();
            command = MString("file -loadReference \"") + tempNodeName + "\" \"" + tempFilename + "\";";
            MGlobal::executeCommand(command);
        }

        // 2. Get the original transformations for the root transforms of the temporary reference object
        MDagPathArray tempRoots;
        MObjectArray subReferences;
        getRootObjects ( tempReferenceNode, tempRoots, subReferences );
        uint tempRootCount = tempRoots.length();
        for (uint j = 0; j < tempRootCount; ++j)
        {
            MFnTransform tempT(tempRoots[j]);
            file->originalTransformations.push_back( tempT.transformation() );
        }

        // 3. Get the original node names. This will be used as the URL for export
        file->rootNames.setLength(tempRootCount);
        for (uint j = 0; j < tempRootCount; ++j)
        {
            MString& originalName = file->rootNames[j];
            originalName = tempRoots[j].partialPathName();
            originalName = originalName.substring ( originalName.index(':') + 1, originalName.length() );
        }

        // 4. Cleanup: remove this reference
        MString command = MString("file -rr \"") + tempFilename + "\";";
        MGlobal::executeCommand ( command );

#endif // MAYA >= 600

        return file;
    }

    // --------------------------------------
    MString	ReferenceManager::getLastReferenceFilename( const MString& referenceResult )
    {
#if MAYA_API_VERSION >= 650
        return referenceResult;
#else
        MStringArray filenames;
        MGlobal::executeCommand("file -q -r;", filenames);
        // TODO
//         if ( ImportOptions::isOpenMode() )
//         {
//             return (filenames.length() > 0) ? filenames[filenames.length() - 1] : "";
//         }
//         else
        {
            return referenceResult;
        }
#endif
    }

    // --------------------------------------
    void ReferenceManager::getRootObjects(
        const MObject& referenceNode, 
        MDagPathArray& rootPaths, 
        MObjectArray& subReferences)
    {
        rootPaths.clear();
        subReferences.clear();

        MFnDependencyNode referenceNodeFn(referenceNode);

        // Get the paths of all the dag nodes included in this reference
        MStringArray nodeNames;
        MString command = MString("reference -rfn \"") + referenceNodeFn.name() + "\" -q -node -dp;";
        MGlobal::executeCommand(command, nodeNames);

        uint nodeNameCount = nodeNames.length();
        MDagPathArray nodePaths;
        for (uint j = 0; j < nodeNameCount; ++j)
        {
            MObject o = DagHelper::getNode(nodeNames[j]);
            MDagPath p = DagHelper::getShortestDagPath(o);
            if (p.length() > 0)
            {
                nodePaths.append(p);
            }
            else
            {
                if (o != MObject::kNullObj && o.apiType() == MFn::kReference
                    && strstr(nodeNames[j].asChar(), "_UNKNOWN_REF_NODE") == NULL)
                {
                    subReferences.append(o);
                }
            }
        }

        // Keep only the root transform for the reference in our path arrays
        uint nodePathCount = nodePaths.length();
        for (uint j = 0; j < nodePathCount; ++j)
        {
            const MDagPath& p = nodePaths[j];
            if ( !isRootTransform ( nodePaths, p ) ) continue;
            rootPaths.append(p);
        }
    }

    // --------------------------------------
    bool ReferenceManager::isRootTransform ( const MDagPathArray& allPaths, const MDagPath& testPath )
    {
        MStatus status;
        MFnTransform transform(testPath, &status);
        if (status != MStatus::kSuccess) return false;
        uint pathCount = allPaths.length();

        uint parentCount = transform.parentCount();
        for (uint k = 0; k < parentCount; ++k)
        {
            MFnDependencyNode parentNode(transform.parent(k));
            if (!parentNode.isFromReferencedFile()) continue;

            for (uint m = 0; m < pathCount; ++m)
            {
                if ( allPaths[m].node() == parentNode.object() ) return false;
            }
        }

        return true;
    }

    // --------------------------------------
    MString ReferenceManager::getReferenceFilename ( const MDagPath& path )
    {
        MString command = MString("reference -q -f ") + path.fullPathName();
        MString filename;
        MGlobal::executeCommand(command, filename);
        return filename;
    }

    // --------------------------------------
    MString ReferenceManager::getReferenceFilename ( const MObject& dgNode )
    {
        MString command = MString("reference -q -f ") + MFnDependencyNode(dgNode).name();
        MString filename;
        MGlobal::executeCommand(command, filename);
        return filename;
    }

}