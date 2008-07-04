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
