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
#ifndef __COLLADA_MAYA_SCENE_ELEMENT_H__
#define __COLLADA_MAYA_SCENE_ELEMENT_H__

#include "COLLADAMayaStableHeaders.h"
#include "ColladaMayaPrerequisites.h"

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
            SPLINE,
            NURBS,
            EMITTER,
            CONSTRAINT,
            BONE
        };

    private:

        /** Persistent information for DAG nodes */
        const MDagPath mDagPath;

        /** Transient information */
        MObject mNode;

        /** The unique id of the node */
        String mNodeId;

        /** The name of the node */
        String mNodeName;

        /** std::vector with parent elements */
        SceneElementsList mParentElements;

        /** std::vector with child elements */
        SceneElementsList mChildElements;

        /** The type of the node*/
        mutable Type mType;

        /** true, if the node should be exported */
        bool isExportNode;

        /** true, if the node is a mesh node from type MFn::kSkinClusterFilter or MFn::kJointCluster. */
        bool isForced;

        /** true, if it is a visible node */
        bool isVisible;

    public:

        /** Constructor. */
        SceneElement ( const MDagPath _nodePath, Type _type=UNDETERMINED );
        virtual ~SceneElement();

        const MDagPath getPath() const; /** returns the node path */
        const MObject& getNode();

        /** Returns the type of the node*/
        const Type& getType() const;
        void setType ( const Type& _type )
        {
            mType = _type;
        }

        /** Set the unique id of the export node to @a id*/
        void setId ( const String& id )
        {
            mNodeId = id;
        }

        /** Set the unique id of the export node to @a id*/
        void setNodeName ( const String& name )
        {
            mNodeName = name;
        }

        const String& getNodeName();

        /** Adds @a exportNode to its children*/
        void addParentElement ( SceneElement* exportElement )
        {
            mParentElements.push_back ( exportElement );
        }

        /** Returns the number of child nodes*/
        const size_t getParentCount() const
        {
            return mParentElements.size();
        }

        /** Returns the @a i'th  child*/
        SceneElement* getParent ( size_t index=0 ) const
        {
            return mParentElements[index];
        }

        bool containsParentElement ( SceneElement* searchedSceneElement );
        bool containsParentElement ( MDagPath searchedPath );

        /** Adds @a exportNode to its children*/
        void addChildElement ( SceneElement* exportNode )
        {
            mChildElements.push_back ( exportNode );
        }

        /** Returns the number of child nodes*/
        const size_t getChildCount() const
        {
            return mChildElements.size();
        }

        /** Returns the @a i'th  child*/
        SceneElement* getChild ( size_t i ) const
        {
            return mChildElements[i];
        }

        const bool containsChildElement ( SceneElement* searchedSceneElement ) const;
        const bool containsChildElement ( MDagPath searchedPath ) const;

        /** Set the export flag on the current scene element. */
        void setIsExportNode ( const bool _isExportNode )
        {
            isExportNode = _isExportNode;
        }

        const bool getIsExportNode() const
        {
            return isExportNode;
        }

        /** Set the forced flag on the current scene element. */
        void setIsForced ( const bool _isForced )
        {
            isForced = _isForced;
        }

        const bool getIsForced() const
        {
            return isForced;
        }

        /** Set the visible flag on the current scene element. */
        void setIsVisible ( const bool _isVisible )
        {
            isVisible= _isVisible;
        }

        const bool getIsVisible() const
        {
            return isVisible;
        }

    private:

        /** Returns the type of the node*/
        const Type determineType() const;
    };
}

#endif // __COLLADA_MAYA_SCENE_ELEMENT_H__
