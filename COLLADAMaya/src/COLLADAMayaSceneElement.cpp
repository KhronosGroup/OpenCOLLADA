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
#include "COLLADAMayaSceneElement.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaDagHelper.h"

#include <maya/MFnDependencyNode.h>
#include <maya/MFnDagNode.h>


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    SceneElement::SceneElement ( const MDagPath _nodePath, Type _type )
            : mDagPath ( _nodePath ), mType ( _type ), isExportNode ( false )
    {}

    //---------------------------------------------------------------
    const MDagPath SceneElement::getPath() const
    {
        return mDagPath;
    }

    //---------------------------------------------------------------
    MObject SceneElement::getNode()
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
    MString SceneElement::getNodeName()
    {
        if ( mNodeName == NULL )
        {
            MObject _node = this->getNode();

            // Attach a function set
            MFnDependencyNode fn ( _node );
            mNodeName = fn.name();
        }

        return mNodeName;
    }

    // -------------------------------------------
    SceneElement::Type SceneElement::getType() const
    {
        if ( mType == UNDETERMINED ) mType = determineType();

        return mType;
    }

    // -------------------------------------------
    SceneElement::Type SceneElement::determineType() const
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

            if ( ExportOptions::exportJointsAndSkin() )
            {
                // TODO
                //    doc->GetAnimationCache()->SampleIKHandle(dagPath);
            }

            return UNKNOWN;

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
    bool SceneElement::containsChildElement ( MDagPath searchedPath )
    {
        for ( uint i=0; i<mChildElements.size(); ++i )
        {
            SceneElement* childElement = mChildElements[i];

            if ( childElement->mDagPath == searchedPath ) return true;
        }

        return false;
    }

    // -----------------------------------------------
    bool SceneElement::containsChildElement ( SceneElement* searchedSceneElement )
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