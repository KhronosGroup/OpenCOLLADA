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

		bool rootContains(const MDagPath & dagPath) const {
			for (unsigned int i = 0; i < paths.length(); ++i)
				if (paths[i] == dagPath)
					return true;
			return false;
		}

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

		const ReferenceList & getReferences() const
		{
			return mReferences;
		}

        /** Retrieves the filename of a referenced node. */
        static MString getReferenceFilename ( const MDagPath& path );

        /** Retrieves the filename of a referenced node. */
        static MString getReferenceFilename ( const MObject& dgNode );

		/**
		* Returns the node which is referenced from the file.
		* @param filename The file which references the searched node.
		* @return MObject The node, which is referenced from in the file.
		*/
		static MObject	getReferenceNode(const MString& filename);

		/**
		* Returns a list of the root transforms attached to a reference, given by its filename.
		* @param referenceNode Current reference node.
		* @param rootPaths List of root pathes to fill.
		* @param subReferences List of sub references to fill.
		*/
		static void getRootObjects(const MObject& referenceNode, MDagPathArray& rootPaths, MObjectArray& subReferences);

		/**
		* Retrieves the top level reference node of given DAG path in case of nested reference nodes.
		* @param dagPath DAG path of a node
		* @param outReferenceNode returned reference node
		* @return MS::kSuccess if succeeded. MS::kFailure if failed.
		*/
		static MStatus getTopLevelReferenceNode(const MDagPath & dagPath, MObject & outReferenceNode);

		/**
		* Retrieves the filename of given reference node.
		* @param referenceNode reference node
		* @param referenceFilename returned reference filename
		* @return MS::kSuccess if succeeded. MS::kFailure if failed.
		*/
		static MStatus getReferenceFilename(const MObject & referenceNode, MString & referenceFilename);

    private:

        /** Constructor. */
        ReferenceManager ();
        
        /** Delete all created references. */
        void deleteReferences ();

        /** Delete all created files. */
        void deleteFiles ();

        /** Grab all the referencing information from the current scene. Used on export. */
        void processReference ( const MObject& referenceNode );

        /** Grab all the referencing information from the current scene. Used on export. */
        ReferenceFile* processReferenceFile ( const MString& filename );

        /** Returns whether the given path is a root transform in the given list of paths. */
        static bool isRootTransform ( const MDagPathArray& allPaths, const MDagPath& testPath );

        /**
         * Retrieve the name of the last reference created.
         * @param referenceResult Current result.
         * @return MString The name of the last reference created
         */
        MString getLastReferenceFilename( const MString& referenceResult );

    };

}

#endif // __COLLADA_MAYA_REFERENCE_MANAGER_H__