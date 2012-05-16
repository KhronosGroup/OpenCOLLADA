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

#ifndef __COLLADA_MAYA_REFERENCE_MANAGER_H__
#define __COLLADA_MAYA_REFERENCE_MANAGER_H__

#include "COLLADAMayaPrerequisites.h"

#include <vector>


namespace COLLADAMaya
{

    /**
     * Represents the root references.
     */
    class ReferenceRoot
    {
    public:
        MDagPath reroot;
        uint index;
    };
    typedef std::vector<ReferenceRoot> ReferenceRootList;

    /**
     * Represents a referenced file.
     */
    class ReferenceFile
    {
    public:
        MString filename;
        MString prefix;
        uint usageCount;

        MStringArray rootNames;
        std::vector<MTransformationMatrix> originalTransformations;

        ReferenceFile() { usageCount = 0; }
    };
    typedef std::vector<ReferenceFile*> ReferenceFileList;

    /**
     * Represents a reference.
     */
    class Reference
    {

    public:
        
        ReferenceFile* file;
        MObject referenceNode;

        // NOTE: Only root transform modifications are currently supported
        // So, "paths" only contains root transform paths
        //
        MDagPathArray paths;
        ReferenceRootList reroots;

    public:
        
        Reference() { file = NULL; }

    };
    typedef std::vector<Reference*> ReferenceList;


    /**
     * 
     */
    class ReferenceManager
    {

    private:


        /** List of references of the current scene. */
        ReferenceList mReferences;

        /** List of file references of the current scene. */
        ReferenceFileList mFiles;

    public:

        /** Destructor. */
        ~ReferenceManager();

        /** Returns the one and only instance of the singleton. */
        static ReferenceManager* getInstance ()
        {
            /** Singleton implementation. */
            static ReferenceManager instance;
            return &instance;
        }

        /** Initializes the external file references of the current scene. */
        void initialize ();

        /** Retrieves the filename of a referenced node. */
        static MString getReferenceFilename ( const MDagPath& path );

        /** Retrieves the filename of a referenced node. */
        static MString getReferenceFilename ( const MObject& dgNode );

    private:

        /** Constructor. */
        ReferenceManager ();
        
        /** Delete all created references. */
        void deleteReferences ();

        /** Delete all created files. */
        void deleteFiles ();

        /**
         * Returns the node which is referenced from the file.
         * @param filename The file which references the searched node.
         * @return MObject The node, which is referenced from in the file.
         */
        MObject	getReferenceNode ( const MString& filename );

        /** Grab all the referencing information from the current scene. Used on export. */
        void processReference ( const MObject& referenceNode );

        /** Grab all the referencing information from the current scene. Used on export. */
        ReferenceFile* processReferenceFile ( const MString& filename );

        /**
         * Returns a list of the root transforms attached to a reference, given by its filename.
         * @param referenceNode Current reference node.
         * @param rootPaths List of root pathes to fill.
         * @param subReferences List of sub references to fill.
         */
        void getRootObjects ( const MObject& referenceNode, MDagPathArray& rootPaths, MObjectArray& subReferences );

        /** Returns whether the given path is a root transform in the given list of paths. */
        bool isRootTransform ( const MDagPathArray& allPaths, const MDagPath& testPath );

        /**
         * Retrieve the name of the last reference created.
         * @param referenceResult Current result.
         * @return MString The name of the last reference created
         */
        MString getLastReferenceFilename( const MString& referenceResult );

    };

}

#endif // __COLLADA_MAYA_REFERENCE_MANAGER_H__