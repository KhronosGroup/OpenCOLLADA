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
#include "COLLADAMayaSceneElement.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaDocumentExporter.h"

#include <maya/MFnDependencyNode.h>
#include <maya/MFnDagNode.h>


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    SceneElement::SceneElement ( const MDagPath _nodePath, Type _type )
            : mDagPath ( _nodePath )
            , mType ( _type )
            , mIsExportNode ( false )
            , mIsLocal ( true )
            , mIsForced ( false )
            , mIsVisible ( false )
            , mHasJoint ( false )
            , mInstantiatedSceneElement ( NULL )
            , mBindShapeMatrix ( MMatrix::identity )
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
            mNodeName = DocumentExporter::mayaNameToColladaName ( fn.name() );
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