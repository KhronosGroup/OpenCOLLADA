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
#include "COLLADAMayaSceneElement.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaDagHelper.h"

#include <maya/MFnDependencyNode.h>
#include <maya/MFnDagNode.h>


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    SceneElement::SceneElement ( const MDagPath _nodePath, Type _type )
            : mDagPath ( _nodePath )
            , mType ( _type )
            , mIsExportNode ( false )
            , mIsForced ( false )
            , mIsVisible ( false )
            , mHasSkinController ( false )
            , mHasMorphController ( false )
    {}

    //---------------------------------------------------------------
    const MDagPath SceneElement::getPath() const
    {
        return mDagPath;
    }

    //---------------------------------------------------------------
    const MObject& SceneElement::getNode()
    {
        if ( mNode.isNull() )
        {
            mNode = mDagPath.node();
        }

        return mNode;
    }

    //---------------------------------------------------------------
    SceneElement::~SceneElement()
    {
        SceneElementsList::iterator it = mChildElements.begin();

        for ( ; it!= mChildElements.end(); ++it )
        {
            SceneElement* sceneElement = *it;
            delete sceneElement;
        }

        mChildElements.clear();
    }

    // -------------------------------------------
    const String& SceneElement::getNodeName()
    {
        if ( mNodeName.empty() )
        {
            MObject _node = getNode();

            // Attach a function set
            MFnDependencyNode fn ( _node );
            mNodeName = fn.name().asChar();
        }

        return mNodeName;
    }

    // -------------------------------------------
    const SceneElement::Type& SceneElement::getType() const
    {
        if ( mType == UNDETERMINED ) mType = determineType();

        return mType;
    }

    // -------------------------------------------
    const SceneElement::Type SceneElement::determineType() const
    {
        if ( mType != UNDETERMINED ) return mType;

        MFn::Type mayaType = mDagPath.apiType();

        switch ( mayaType )
        {

        case MFn::kLookAt:

        case MFn::kParentConstraint:

        case MFn::kOrientConstraint:

        case MFn::kConstraint:

        case MFn::kAimConstraint:

        case MFn::kPoleVectorConstraint:

        case MFn::kPointConstraint:

        case MFn::kNormalConstraint:
            return CONSTRAINT;
            break;

        case MFn::kAmbientLight:

        case MFn::kSpotLight:

        case MFn::kPointLight:

        case MFn::kDirectionalLight:
            return LIGHT;
            break;

        case MFn::kMesh:
            return MESH;
            break;

        case MFn::kIkHandle:
            return IKHANDLE;
            break;

        case MFn::kCamera:
            return CAMERA;
            break;

        case MFn::kRigid:
            return PHYSIK;
            break;

        case MFn::kNurbsCurve:
            return SPLINE;
            break;

        case MFn::kNurbsSurface:
            return NURBS;
            break;

        case MFn::kEmitter:
            return EMITTER;
            break;

        case MFn::kAir:

        case MFn::kDrag:

        case MFn::kField:

        case MFn::kGravity:

        case MFn::kNewton:

        case MFn::kRadial:

        case MFn::kTurbulence:

        case MFn::kUniform:

        case MFn::kVortex:

        case MFn::kVolumeAxis:
            return UNKNOWN;
            break;

        case MFn::kTransform:
            return TRANSFORM;
            break;

        default:
            return UNKNOWN;
            break;
        }
    }

    // -----------------------------------------------
    const bool SceneElement::containsChildElement ( MDagPath searchedPath ) const
    {
        for ( uint i=0; i<mChildElements.size(); ++i )
        {
            SceneElement* childElement = mChildElements[i];

            if ( childElement->mDagPath == searchedPath ) return true;
        }

        return false;
    }

    // -----------------------------------------------
    const bool SceneElement::containsChildElement ( SceneElement* searchedSceneElement ) const
    {
        for ( uint i=0; i<mChildElements.size(); ++i )
        {
            SceneElement* childElement = mChildElements[i];

            if ( childElement->mDagPath == searchedSceneElement->getPath() ) return true;
        }

        return false;
    }

    // -----------------------------------------------
    bool SceneElement::containsParentElement ( MDagPath searchedPath )
    {
        for ( uint i=0; i<mParentElements.size(); ++i )
        {
            SceneElement* parentElement = mParentElements[i];

            if ( parentElement->mDagPath == searchedPath ) return true;
        }

        return false;
    }

    // -----------------------------------------------
    bool SceneElement::containsParentElement ( SceneElement* searchedSceneElement )
    {
        for ( uint i=0; i<mParentElements.size(); ++i )
        {
            SceneElement* parentElement = mParentElements[i];

            if ( parentElement->mDagPath == searchedSceneElement->getPath() ) return true;
        }

        return false;
    }
}