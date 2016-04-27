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

#ifndef __COLLADA_MAYA_SCENE_ELEMENT_H__
#define __COLLADA_MAYA_SCENE_ELEMENT_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaPrerequisites.h"

#include <set>


namespace COLLADAMaya
{

    class SceneElement;

    /** List of scene element. */
    typedef std::vector<SceneElement*> SceneElementsList;


    /**
     * This class should be the base class for all the FCollada 'user-handle' structures.
     */
    class SceneElement
    {

    public:

        enum Type
        {
            UNDETERMINED,
            UNKNOWN,
            TRANSFORM,
            MESH,
            IKHANDLE, // Inverse Kinematic
            CAMERA,
            LIGHT,
            PHYSIK,
			PHYSIK_BULLET,
            PHYSX_RIGID_SOLVER,
            PHYSX_RIGID_BODY,
            PHYSX_RIGID_CONSTRAINT,
            PHYSX_SHAPE,
            SPLINE,
            NURBS,
            EMITTER,
            CONSTRAINT,
            BONE,
            LIGHT_PROBE,
			LOD
        };

    private:

        /** Persistent information for DAG nodes */
        const MDagPath mDagPath;

        /** Transient information */
        mutable MObject mNode;

        /** The unique id of the node */
        String mNodeId;

        /** The name of the node */
        mutable String mNodeName;

        /** std::vector with parent elements */
        SceneElementsList mParentElements;

        /** std::vector with child elements */
        SceneElementsList mChildElements;

        /** Pointer to the instantiated scene element, if it exist. */
        SceneElement* mInstantiatedSceneElement;

        /** The type of the node*/
        mutable Type mType;

        /** true, if the node should be exported */
        bool mIsExportNode;

        /** false, if the node has a file reference */
        bool mIsLocal;

        /** true, if the node is a mesh node from type MFn::kSkinClusterFilter or MFn::kJointCluster. */
        bool mIsForced;

        /** true, if it is a visible node */
        bool mIsVisible;

        /** True, if the transform element has joints. */
        bool mHasJoint;

		/** true, if the node is used as physics Node */
		bool mIsPhysicsNode;

        /** Set the list of skeleton-Ids. It indicates where a skin
            controller is to start to search for the joint nodes
            it needs. This element is meaningless for morph controllers. */
        std::set<URI> mSkeletonURIs;

        /** Holds for every skin controller dag path the bind shape matrix. */
        MMatrix mBindShapeMatrix;

    public:

        /** Constructor. */
        SceneElement ( const MDagPath _nodePath, Type _type=UNDETERMINED );
        virtual ~SceneElement ();

        /** Returns the node path */
        const MDagPath& getPath () const;

        /** Returns the node */
		const MObject& getNode () const;

        /** Returns the type of the node*/
		const Type& getType() const;
        void setType ( const Type& _type )
        {
            mType = _type;
        }

        /** Set the unique id of the export node to @a id*/
        void setNodeId ( const String& id )
        {
            mNodeId = id;
        }

        /** Set the unique id of the export node to @a id*/
        const String& getNodeId () const
        {
            return mNodeId;
        }

        /** Set the unique id of the export node to @a id*/
        void setNodeName ( const String& name )
        {
            mNodeName = name;
        }

        const String& getNodeName () const;

        /** Adds @a exportNode to its children*/
        void addParentElement ( SceneElement* exportElement )
        {
            mParentElements.push_back ( exportElement );
        }

        /** Returns the number of child nodes*/
        const size_t getParentCount () const
        {
            return mParentElements.size();
        }

        /** Returns the @a i'th  child*/
        SceneElement* getParent ( size_t index=0 ) const
        {
            return mParentElements[index];
        }

        /** True, if the node has the element as parent. */
        bool containsParentElement ( SceneElement* searchedSceneElement );

        /** True, if the node has the element as parent. */
        bool containsParentElement ( MDagPath searchedPath );

        /** Adds @a exportNode to its children*/
        void addChildElement ( SceneElement* exportNode )
        {
            mChildElements.push_back ( exportNode );
        }

        /** Returns the number of child nodes*/
        const size_t getChildCount () const
        {
            return mChildElements.size();
        }

        /** Returns the @a i'th  child*/
        SceneElement* getChild ( size_t i ) const
        {
            return mChildElements[i];
        }

        /** True, if the node has the element as child. */
        const bool containsChildElement ( SceneElement* searchedSceneElement ) const;

        /** True, if the node has the element as child. */
        const bool containsChildElement ( MDagPath searchedPath ) const;

        /** Pointer to the instantiated scene element, if it exist. */
        SceneElement* getInstantiatedSceneElement() const
        {
            return mInstantiatedSceneElement;
        }

        /** Pointer to the instantiated scene element, if it exist. */
        void setInstantiatedSceneElement ( SceneElement* val )
        {
            mInstantiatedSceneElement = val;
        }

        /** Set the export flag on the current scene element. */
        void setIsExportNode ( const bool _isExportNode )
        {
            mIsExportNode = _isExportNode;
        }

        /** Set the export flag on the current scene element. */
        const bool getIsExportNode () const
        {
            return mIsExportNode;
        }

        /** false, if the node has a file reference */
        const bool getIsLocal () const { return mIsLocal; }

        /** false, if the node has a file reference */
        void setIsLocal ( const bool val ) { mIsLocal = val; }

        /** Set the forced flag on the current scene element. */
        void setIsForced ( const bool _isForced )
        {
            mIsForced = _isForced;
        }

        /** Set the forced flag on the current scene element. */
        const bool getIsForced() const
        {
            return mIsForced;
        }

        /** Set the visible flag on the current scene element. */
        void setIsVisible ( const bool _isVisible )
        {
            mIsVisible= _isVisible;
        }

        /** Set the visible flag on the current scene element. */
        const bool getIsVisible () const
        {
            return mIsVisible;
        }

        /**
         * True, if the transform element has joints.
         * @param hasJoint True, if the transform element has joints.
         */
        void setHasJoint ( bool hasJoint ) { mHasJoint = hasJoint; }

        /**
         * True, if the transform element has joints.
         * @return bool True, if the transform element has joints.
         */
        bool getHasJoint () { return mHasJoint; }

		/** Set physicsNode on the current scene element. */
		void setIsPhysicsNode(bool val)
		{
			mIsPhysicsNode = val;
		}

		/**
		* True, if the element is used as a Physics Node.
		* @return bool True, if the element is used as a Physics Node.
		*/
		bool getIsPhysicsNode() const
		{
			return mIsPhysicsNode;
		}

        /** Set the skeleton uri. It indicates where a skin
        controller is to start to search for the joint nodes
        it needs. This element is meaningless for morph controllers. */
        const std::set<URI>& getSkeletonURIs () const { return mSkeletonURIs; }

        /** Set the skeleton uri. It indicates where a skin
        controller is to start to search for the joint nodes
        it needs. This element is meaningless for morph controllers. */
        void addSkeletonURI ( const URI& val ) { mSkeletonURIs.insert ( val ); }

        /** Holds for every skin controller dag path the bind shape matrix. */
        const MMatrix& getBindShapeMatrix () const { return mBindShapeMatrix; }
        void setBindShapeMatrix ( const MMatrix& val ) { mBindShapeMatrix = val; }

    private:

        /** Returns the type of the node*/
        const Type determineType() const;
    };
}

#endif // __COLLADA_MAYA_SCENE_ELEMENT_H__
