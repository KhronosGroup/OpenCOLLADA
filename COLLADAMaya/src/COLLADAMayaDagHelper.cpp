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

#include "COLLADAMayaDagHelper.h"
#include <assert.h>
#include <maya/MFnAttribute.h>
#include <maya/MFnComponentListData.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MFnEnumAttribute.h>
#include <maya/MFnMatrixData.h>
#include <maya/MFnNumericData.h>
#include <maya/MFnSet.h>
#include <maya/MFnSingleIndexedComponent.h>
#include <maya/MFnSkinCluster.h>
#include <maya/MItDependencyGraph.h>
#include <maya/MDGModifier.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnStringArrayData.h>
#include <maya/MSelectionList.h>
#include <maya/MFnDagNode.h>

namespace COLLADAMaya
{

    //---------------------------------------------------
    //
    // Find a node connected to a node's attribute
    //
    MObject DagHelper::getNodeConnectedTo ( const MObject& node, const String& attribute )
    {
        MPlug plug;

        if ( getPlugConnectedTo ( node, attribute, plug ) )
        {
            return plug.node();
        }

        else
        {
            return MObject::kNullObj;
        }
    }

    //---------------------------------------------------
    MObject DagHelper::getSourceNodeConnectedTo ( const MObject& node, const MString& attribute )
    {
        MStatus status;
        MFnDependencyNode dgFn ( node );
        MPlug plug = dgFn.findPlug ( attribute, &status );
        if ( status == MS::kSuccess && plug.isConnected() )
        {
            // Get the connection - there can be at most one input to a plug
            MPlugArray connections;
            plug.connectedTo ( connections, true, false );
            size_t length = connections.length();
            if ( connections.length() > 0 )
            {
                return connections[0].node();
            }
        }

        return MObject::kNullObj;
    }

    //---------------------------------------------------
    MObject DagHelper::getSourceNodeConnectedTo ( const MPlug& inPlug )
    {
        MStatus status;
        MPlugArray connections;
        inPlug.connectedTo ( connections, true, false );

        if ( connections.length() > 0 )
        {
            return connections[0].node();
        }

        return MObject::kNullObj;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugConnectedTo ( const MObject& node, const String& attribute, MPlug& connectedPlug )
    {
        MStatus status;
        MFnDependencyNode dgFn ( node );
        MPlug plug = dgFn.findPlug ( attribute.c_str(), &status );

        if ( status == MS::kSuccess && plug.isConnected() )
        {
            // Get the connection - there can be at most one input to a plug
            MPlugArray connections;
            plug.connectedTo ( connections, true, true );

            if ( connections.length() > 0 )
            {
                connectedPlug = connections[0];
                return true;
            }
        }

        return false;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugConnectedTo ( const MPlug& inPlug, MPlug& plug )
    {
        MStatus status;

        MPlugArray connections;
        inPlug.connectedTo ( connections, true, true );

        if ( connections.length() > 0 )
        {
            plug = connections[0];
            return true;
        }

        return false;
    }

    //---------------------------------------------------
    //
    // Get the node connected to a plug
    //
    MObject DagHelper::getNodeConnectedTo ( const MPlug& plug )
    {
        MStatus status;
        MPlugArray connections;
        plug.connectedTo ( connections, true, true, &status );
        if ( status != MStatus::kSuccess ) return MObject::kNullObj;
        if ( connections.length() <= 0 ) return MObject::kNullObj;

        return connections[0].node();
    }

    //---------------------------------------------------
    //
    // Find a node connected to a node's array attribute
    //
    bool DagHelper::getPlugArrayConnectedTo ( const MObject& node, const MString& attribute, MPlug& connectedPlug )
    {
        MStatus status;
        MFnDependencyNode dgFn ( node );
        MPlug plug = dgFn.findPlug ( attribute, &status );

        if ( status != MS::kSuccess )
        {
            MGlobal::displayWarning ( MString ( "couldn't find plug on attribute " ) +
                                      attribute + MString ( " on object " ) + dgFn.name() );
            return false;
        }

        if ( plug.numElements() < 1 )
        {
            MGlobal::displayWarning ( MString ( "plug array doesn't have any connection on attribute " ) +
                                      attribute + MString ( " on object " ) + dgFn.name() );
            return false;
        }

        MPlug firstElementPlug = plug.connectionByPhysicalIndex ( 0 );

        // Get the connection - there can be at most one input to a plug
        //
        MPlugArray connections;
        firstElementPlug.connectedTo ( connections, true, true );

        if ( connections.length() == 0 )
        {
            MGlobal::displayWarning ( MString ( "plug connected to an empty array on attribute " ) +
                                      attribute + MString ( " on object " ) + dgFn.name() );
            return false;
        }

        connectedPlug = connections[0];

        return true;
    }

    //---------------------------------------------------
    bool DagHelper::connect ( const MObject& source, const MString& sourceAttribute, const MObject& destination, const MString& destinationAttribute )
    {
        MStatus status;
        MFnDependencyNode srcFn ( source );
        MFnDependencyNode destFn ( destination );

        MPlug src = srcFn.findPlug ( sourceAttribute, &status );

        if ( status != MStatus::kSuccess ) return false;

        MPlug dest = destFn.findPlug ( destinationAttribute, &status );

        if ( status != MStatus::kSuccess ) return false;

        MDGModifier modifier;

        modifier.connect ( src, dest );

        status = modifier.doIt();

        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::connect ( const MObject& source, const MString& sourceAttribute, const MPlug& destination )
    {
        MStatus status;
        MFnDependencyNode srcFn ( source );

        MPlug src = srcFn.findPlug ( sourceAttribute, &status );

        if ( status != MStatus::kSuccess ) return false;

        MDGModifier modifier;

        modifier.connect ( src, destination );

        status = modifier.doIt();

        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::connect ( const MPlug& source, const MObject& destination, const MString& destinationAttribute )
    {
        MStatus status;
        MFnDependencyNode destFn ( destination );

        MPlug dst = destFn.findPlug ( destinationAttribute, &status );

        if ( status != MStatus::kSuccess ) return false;

        MDGModifier modifier;

        status = modifier.connect ( source, dst );

        if ( status != MStatus::kSuccess ) return false;

        status = modifier.doIt();

        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::connect ( const MPlug& source, const MPlug& destination )
    {
        MDGModifier modifier;
        modifier.connect ( source, destination );
        MStatus status = modifier.doIt();

        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::connectToList ( const MObject& source, const MString& sourceAttribute, const MObject& destination, const MString& destinationAttribute, int* index )
    {
        MStatus status;
        MFnDependencyNode srcFn ( source );

        MPlug src = srcFn.findPlug ( sourceAttribute, &status );

        if ( status != MStatus::kSuccess ) return false;

        return connectToList ( src, destination, destinationAttribute, index );
    }

    //---------------------------------------------------
    bool DagHelper::connectToList ( const MPlug& source, const MObject& destination, const MString& destinationAttribute, int* _index )
    {
        MStatus status;
        MFnDependencyNode destFn ( destination );
        MPlug dest = destFn.findPlug ( destinationAttribute, &status );

        if ( status != MStatus::kSuccess ) return false;

        if ( !dest.isArray() ) return false;

        int index = ( _index != NULL ) ? *_index : -1;

        if ( index < 0 )
        {
            index = getNextAvailableIndex ( dest, ( int ) dest.evaluateNumElements() );

            if ( _index != NULL ) *_index = index;
        }

        MPlug d = dest.elementByLogicalIndex ( index );

        MDGModifier modifier;
        modifier.connect ( source, d );
        status = modifier.doIt();
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    int DagHelper::getNextAvailableIndex ( const MObject& object, const MString& attribute, int startIndex )
    {
        MPlug p = MFnDependencyNode ( object ).findPlug ( attribute );

        if ( p.node().isNull() ) return -1;

        return getNextAvailableIndex ( p, startIndex );
    }

    //---------------------------------------------------
    int DagHelper::getNextAvailableIndex ( const MPlug& p, int startIndex )
    {
        if ( startIndex < 0 ) startIndex = 0;

        // Look for the next available plug
        for ( uint i = ( uint ) startIndex; i < ( uint ) startIndex + 100; ++i )
        {
            MPlug possibleDestination = p.elementByLogicalIndex ( i );

            if ( !DagHelper::hasConnection ( possibleDestination ) )
            {
                return i;
            }
        }

        return -1;
    }

    //---------------------------------------------------
    bool DagHelper::hasConnection ( const MPlug& plug, bool asSource, bool asDestination )
    {
        MPlugArray plugs;
        plug.connectedTo ( plugs, asDestination, asSource );
        if ( plugs.length() > 0 ) return true;

        return plug.numConnectedChildren() > 0;
    }

    //---------------------------------------------------
    // Retrieve the bind pose for a controller/joint std::pair
    //
    MMatrix DagHelper::getBindPoseInverse ( const MObject& controller, const MObject& influence )
    {
        MStatus status;
        if ( controller.apiType() == MFn::kSkinClusterFilter )
        {
            MFnSkinCluster controllerFn ( controller );

			MFnDependencyNode fn(influence);
			String nodeName = fn.name().asChar();

            // Find the correct index for the pre-bind matrix
            uint index = controllerFn.indexForInfluenceObject ( MDagPath::getAPathTo ( influence ), &status );
			if (status != MStatus::kSuccess) 
			{
				MFnDependencyNode influenceNode(influence);
				MPlug bindPosePlug = influenceNode.findPlug("bindPose", &status);

				if (status == MStatus::kSuccess)
				{
					MMatrix ret;
					//this joint has been skinned but his influence has been removed so we need to retrieve his BindPose
					if (!DagHelper::getPlugValue(bindPosePlug, ret))
					{
						return MMatrix::identity;
					}

					ret = ret.inverse();
					return ret;
				}
			}

            MPlug preBindMatrixPlug = controllerFn.findPlug ( "bindPreMatrix", &status );
            preBindMatrixPlug = preBindMatrixPlug.elementByLogicalIndex ( index, &status );
            if ( status != MStatus::kSuccess ) return MMatrix::identity;

            // Get the plug's matrix
            MMatrix ret;
            if ( !DagHelper::getPlugValue ( preBindMatrixPlug, ret ) ) return MMatrix::identity;

            return ret;
        }

        else if ( controller.apiType() == MFn::kJointCluster )
        {
            MMatrix ret;
            DagHelper::getPlugValue ( influence, "bindPose", ret );
            return ret.inverse();
        }

        else return MMatrix::identity;
    }

    //---------------------------------------------------
    // set the bind pose for a transform
    //
    MStatus DagHelper::setBindPoseInverse ( const MObject& node, const MMatrix& bindPoseInverse )
    {
        MStatus status;
        MFnDependencyNode dgFn ( node );
        MPlug bindPosePlug = dgFn.findPlug ( "bindPose", &status );
        if ( status != MS::kSuccess )
        {
            MGlobal::displayWarning ( MString ( "No bindPose found on node " ) + dgFn.name() );
            return status;
        }

        MFnMatrixData matrixFn;
        MObject val = matrixFn.create ( bindPoseInverse.inverse(), &status );
        MObject invval = matrixFn.create ( bindPoseInverse, &status );
        if ( status != MS::kSuccess )
        {
            MGlobal::displayWarning ( MString ( "Error setting bindPose on node " ) + dgFn.name() );
            return status;
        }

        // set the bind pose on the joint itself
        bindPosePlug.setValue ( val );

        // Now, perhaps more significantly, see if there's a
        // skinCluster using this bone and update its bind
        // pose (as the joint bind pose is not connected to
        // the skin - it's set at bind time from the joint's
        // current position, and our importer may not want to
        // disturb the current scene state just to put bones
        // in a bind position before creating skin clusters)
        MObject _node ( node );
        MItDependencyGraph it ( _node, MFn::kSkinClusterFilter );
        while ( !it.isDone() )
        {
            MPlug plug = it.thisPlug();
            unsigned int idx = plug.logicalIndex();
            MFnDependencyNode skinFn ( plug.node() );
            MPlug skinBindPosePlug = skinFn.findPlug ( "bindPreMatrix", &status );

            if ( status == MS::kSuccess )
            {
                // The skinCluster stores inverse inclusive matrix
                // so notice we use invval (the MObject created off
                // the inverse matrix here)
                skinBindPosePlug = skinBindPosePlug.elementByLogicalIndex ( idx );
                skinBindPosePlug.setValue ( invval );
            }

            it.next();
        }

        return status;
    }

    //---------------------------------------------------
    MPlug DagHelper::getChildPlug ( const MPlug& parent, const MString& name, MStatus* rc )
    {
        MStatus st;
        uint childCount = parent.numChildren ( &st );
        if ( st != MStatus::kSuccess )
        {
            if ( rc != NULL ) *rc = st;
            return parent;
        }

        // Check shortNames first
        for ( uint i = 0; i < childCount; ++i )
        {
            MPlug child = parent.child ( i, &st );
            if ( st != MStatus::kSuccess )
            {
                if ( rc != NULL ) *rc = st;
                return parent;
            }

            MFnAttribute attributeFn ( child.attribute() );
            MString n = attributeFn.shortName();
            if ( n == name )
            {
                if ( rc != NULL ) *rc = MStatus::kSuccess;
                return child;
            }
        }

        // Check longNames second, use shortNames!
        for ( uint i = 0; i < childCount; ++i )
        {
            MPlug child = parent.child ( i, &st );
            if ( st != MStatus::kSuccess )
            {
                if ( rc != NULL ) *rc = st;
                return parent;
            }

            MFnAttribute attributeFn ( child.attribute() );
            MString n = attributeFn.name();
            if ( n == name )
            {
                if ( rc != NULL ) *rc = MStatus::kSuccess;
                return child;
            }
        }

        if ( rc != NULL ) *rc = MStatus::kNotFound;
        return parent;
    }

    //---------------------------------------------------
    int DagHelper::getChildPlugIndex ( const MPlug& parent, const MString& name, MStatus* rc )
    {
        MStatus st;
        uint childCount = parent.numChildren ( &st );
        CHECK_STATUS_AND_RETURN ( st, -1 );

        // Check shortNames first
        for ( uint i = 0; i < childCount; ++i )
        {
            MPlug child = parent.child ( i, &st );
            CHECK_STATUS_AND_RETURN ( st, -1 );

            MFnAttribute attributeFn ( child.attribute() );
            MString n = attributeFn.shortName();

            if ( n == name )
            {
                if ( rc != NULL ) *rc = MStatus::kSuccess;

                return i;
            }
        }

        // Check longNames second, use shortNames!
        for ( uint i = 0; i < childCount; ++i )
        {
            MPlug child = parent.child ( i, &st );
            CHECK_STATUS_AND_RETURN ( st, -1 );

            MFnAttribute attributeFn ( child.attribute() );
            MString n = attributeFn.name();

            if ( n == name )
            {
                if ( rc != NULL ) *rc = MStatus::kSuccess;

                return i;
            }
        }

        if ( rc != NULL ) *rc = MStatus::kNotFound;

        return -1;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MObject& node, const String& attributeName, double &value )
    {
        MStatus status;
        MPlug plug = MFnDependencyNode ( node ).findPlug ( attributeName.c_str(), &status );
        if ( status != MStatus::kSuccess ) return false;

        status = plug.getValue ( value );
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MObject& node, const String& attributeName, float &value )
    {
        MStatus status;
        MPlug plug = MFnDependencyNode ( node ).findPlug ( attributeName.c_str(), &status );
        if ( status != MStatus::kSuccess ) return false;

        status = plug.getValue ( value );
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MPlug& plug, float& x )
    {
        MStatus status;
        status = plug.getValue ( x );
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MPlug& plug, int& value )
    {
        MDGContext context = MDGContext::fsNormal;

        MStatus status;
        status = plug.getValue ( value );
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MPlug& plug, uint32& value )
    {
        MStatus status;
        int temp;
        status = plug.getValue ( temp );
        value = static_cast<uint32> ( temp );
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MPlug& plug, short& value )
    {
        MStatus status;
        status = plug.getValue ( value );
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MPlug& plug, uint16& value )
    {
        MStatus status;
        short temp;
        status = plug.getValue ( temp );
        value = static_cast<uint16> ( temp );
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MPlug& plug, char& value )
    {
        MStatus status;
        status = plug.getValue ( value );
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MPlug& plug, uint8& value )
    {
        MStatus status;
        char temp;
        status = plug.getValue ( temp );
        value = static_cast<uint8> ( temp );
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MObject& node, const String& attributeName, MEulerRotation& value )
    {
        MStatus status;
        MPlug plug = MFnDependencyNode ( node ).findPlug ( attributeName.c_str(), &status );
        if ( status != MStatus::kSuccess ) return false;

        if ( plug.isCompound() && plug.numChildren() >= 3 )
        {
            status = plug.child ( 0 ).getValue ( value.x );
            if ( status != MStatus::kSuccess ) return false;

            status = plug.child ( 1 ).getValue ( value.y );
            if ( status != MStatus::kSuccess ) return false;

            status = plug.child ( 2 ).getValue ( value.z );
            if ( status != MStatus::kSuccess ) return false;

            return true;
        }

        else return false;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MObject& node, const String& attributeName, bool& value )
    {
        MStatus status;
        MPlug plug = MFnDependencyNode ( node ).findPlug ( attributeName.c_str(), &status );
        if ( status != MStatus::kSuccess ) return false;

        status = plug.getValue ( value );
        if ( status != MStatus::kSuccess ) return false;

        return true;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MPlug& plug, bool& value )
    {
        MStatus status;
        status = plug.getValue ( value );
        if ( status != MStatus::kSuccess ) return false;

        return true;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MObject& node, const String& attributeName, int& value )
    {
        MStatus status;
        MPlug plug = MFnDependencyNode ( node ).findPlug ( attributeName.c_str(), &status );
        if ( status != MStatus::kSuccess ) return false;

        status = plug.getValue ( value );
        if ( status != MStatus::kSuccess ) return false;

        return true;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MObject& node, const String& attributeName, MMatrix& value )
    {
        MStatus status;
        MPlug plug = MFnDependencyNode ( node ).findPlug ( attributeName.c_str(), &status );
        if ( status != MStatus::kSuccess ) return false;

        return getPlugValue ( plug, value );
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MPlug& plug, MMatrix& value )
    {
        MStatus status;

        MFnMatrixData mxData;
        MObject object = mxData.create();
        status = plug.getValue ( object );
        if ( status != MStatus::kSuccess ) return false;

        mxData.setObject ( object );
        // MFnMatrixData mxData(o, &status);
        if ( status != MStatus::kSuccess ) return false;

        value = mxData.matrix();

        return true;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MObject& node, const String& attributeName, MColor& value )
    {
        MStatus status;
        MPlug plug = MFnDependencyNode ( node ).findPlug ( attributeName.c_str(), &status );
        if ( status != MStatus::kSuccess ) return false;

        return getPlugValue ( plug, value );
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MPlug& plug, MColor& value )
    {
        MStatus status;
        if ( plug.isCompound() && plug.numChildren() >= 3 )
        {
            status = plug.child ( 0 ).getValue ( value.r );
            if ( status != MStatus::kSuccess ) return false;

            status = plug.child ( 1 ).getValue ( value.g );
            if ( status != MStatus::kSuccess ) return false;

            status = plug.child ( 2 ).getValue ( value.b );
            if ( status != MStatus::kSuccess ) return false;

            if ( plug.numChildren() >= 4 )
            {
                status = plug.child ( 3 ).getValue ( value.a );
                if ( status != MStatus::kSuccess ) return false;
            }
            else value.a = 1.0f;

            return true;
        }

        else return false;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MObject& node, const String& attributeName, MString& value )
    {
        MStatus status;
        MPlug plug = MFnDependencyNode ( node ).findPlug ( attributeName.c_str(), &status );
        if ( status != MStatus::kSuccess ) return false;

        return plug.getValue ( value );
    }

    //---------------------------------------------------
    void DagHelper::getPlugValue (
        const MObject& node,
        const String& attributeName,
        MStringArray& output,
        MStatus* status )
    {
        MPlug plug = MFnDependencyNode ( node ).findPlug ( attributeName.c_str(), status );
        getPlugValue ( plug, output, status );
    }

    //---------------------------------------------------
    void DagHelper::getPlugValue ( const MPlug& plug, MStringArray& output, MStatus* status )
    {
        MObject str_obj;
        plug.getValue ( str_obj );
        MFnStringArrayData f_astr ( str_obj, status );
        unsigned int len = f_astr.length();
        for ( unsigned int i = 0; i < len; ++i )
        {
            const MString& val = f_astr[i];
            output.append ( val );
        }
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MPlug& plug, float& x, float& y )
    {
        MObject obj;
        plug.getValue ( obj );
        MStatus status;
        MFnNumericData fcolor ( obj, &status );
        if ( !status ) return 0;

        fcolor.getData ( x , y );
        return 1;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MPlug& plug, float& x, float& y, float& z )
    {
        MObject obj;
        plug.getValue ( obj );
        MStatus status;
        MFnNumericData fcolor ( obj, &status );
        if ( !status ) return 0;

        fcolor.getData ( x , y , z );

        return 1;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MObject& node, const String& attributeName, MVector& value )
    {
        MStatus status;
        MPlug plug = MFnDependencyNode ( node ).findPlug ( attributeName.c_str(), &status );
        if ( status != MStatus::kSuccess ) return false;

        return getPlugValue ( plug, value );
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue(const MObject& node, const String& attributeName, int& enumValue, MString& enumName)
    {
        MStatus status;
        MPlug plug = MFnDependencyNode(node).findPlug(attributeName.c_str(), &status);
        if (!status) return false;
        return getPlugValue(plug, enumValue, enumName);
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue(const MObject& node, const String& attributeName, MObject& value)
    {
        MStatus status;
        MPlug plug = MFnDependencyNode(node).findPlug(attributeName.c_str(), &status);
        if (!status) return false;
        return getPlugValue(plug, value);
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue ( const MPlug& plug, MVector& value )
    {
        MObject obj;
        plug.getValue ( obj );

        MStatus status = plug.getValue ( obj );
		COLLADABU_ASSERT ( status );
        MFnNumericData data ( obj );

        double x, y, z;
        status = data.getData ( x, y, z );
		COLLADABU_ASSERT ( status );
        value = MVector ( x,y,z );

        return true;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue(const MPlug& plug, int& enumValue, MString& enumName)
    {
        MStatus status;

        MObject attr;
        attr = plug.attribute(&status);
        if (!status) return false;

        MFnEnumAttribute fnEnum(attr, &status);
        if (!status) return false;

        status = plug.getValue(enumValue);
        if (!status) return false;

        enumName = fnEnum.fieldName(enumValue, &status);
        if (!status) return status;

        return true;
    }

    //---------------------------------------------------
    bool DagHelper::getPlugValue(const MPlug& plug, MObject& value)
    {
        MStatus status = plug.getValue(value);
        if (!status) return false;
        return true;
    }

    //---------------------------------------------------
    bool DagHelper::setPlugValue ( MPlug& plug, const MVector& value )
    {
        MStatus status;
        MFnNumericData dataCreator;

        MObject float3Data = dataCreator.create ( MFnNumericData::k3Float, &status );
        if ( status != MStatus::kSuccess ) return false;

        dataCreator.setData ( ( float ) value.x, ( float ) value.y, ( float ) value.z );
        status = plug.setValue ( float3Data );
        if ( status != MStatus::kSuccess ) return false;

        return true;
    }

    //---------------------------------------------------
    bool DagHelper::setPlugValue ( MPlug& plug, const MColor& value )
    {
        MStatus status;
        if ( plug.isCompound() && plug.numChildren() >= 3 )
        {
            MPlug rPlug = plug.child ( 0, &status );
            if ( status != MStatus::kSuccess ) return false;

            status = rPlug.setValue ( value.r );
            if ( status != MStatus::kSuccess ) return false;

            MPlug gPlug = plug.child ( 1, &status );
            if ( status != MStatus::kSuccess ) return false;

            status = gPlug.setValue ( value.g );
            if ( status != MStatus::kSuccess ) return false;

            MPlug bPlug = plug.child ( 2, &status );
            if ( status != MStatus::kSuccess ) return false;

            status = bPlug.setValue ( value.b );
            if ( status != MStatus::kSuccess ) return false;

            if ( plug.numChildren() >= 4 )
            {
                MPlug aPlug = plug.child ( 3, &status );
                if ( status != MStatus::kSuccess ) return false;

                status = aPlug.setValue ( value.a );
                if ( status != MStatus::kSuccess ) return false;
            }
        }

        return true;
    }

    //---------------------------------------------------
    bool DagHelper::setPlugValue ( MPlug& plug, const MMatrix& value )
    {
        MStatus status;
        MFnMatrixData dataCreator;

        MObject matrixData = dataCreator.create ( value, &status );
        if ( status != MStatus::kSuccess ) return false;

        status = plug.setValue ( matrixData );
        if ( status != MStatus::kSuccess ) return false;

        return true;
    }

    //---------------------------------------------------
    bool DagHelper::setPlugValue ( MPlug& plug, const String& value )
    {
        MStatus status;
        status = plug.setValue ( value.c_str() );
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
#ifdef UNICODE
    bool DagHelper::setPlugValue ( MPlug& plug, const String& value )
    {
        MStatus status;
        status = plug.setValue ( MString ( value.c_str() ) );
        return status == MStatus::kSuccess;
    }

#endif // UNICODE

    //---------------------------------------------------
    bool DagHelper::setPlugValue ( MPlug& plug, float value )
    {
        MStatus status;
        status = plug.setValue ( value );
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::setPlugValue ( MPlug& plug, double value )
    {
        MStatus status;
        status = plug.setValue ( value );
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::setPlugValue ( MPlug& plug, float x, float y )
    {
        MFnNumericData data;
        MObject obj = data.create ( MFnNumericData::k2Float );
        data.setData ( x, y );
        return plug.setValue ( obj );
    }

    //---------------------------------------------------
    bool DagHelper::setPlugValue ( MPlug& plug, int value )
    {
        MStatus status;
        status = plug.setValue ( value );
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::setPlugValue ( MPlug& plug, bool value )
    {
        MStatus status;
        status = plug.setValue ( value );
        return status == MStatus::kSuccess;
    }

    //---------------------------------------------------
    bool DagHelper::setPlugValue ( MPlug& plug, MStringArray& stringArray )
    {
        MObject obj;
        MFnStringArrayData fstr;
        obj = fstr.create ( stringArray );
        return plug.setValue ( obj );
    }

    //---------------------------------------------------
    void DagHelper::setArrayPlugSize ( MPlug& plug, uint size )
    {
        if ( plug.node().isNull() ) return;

#if MAYA_API_VERSION >= 800
        MStatus status = plug.setNumElements ( size );
        CHECK_STAT ( status );

#else
        MObject node = plug.node();
        MString plugPath = plug.info();
        if ( node.hasFn ( MFn::kDagNode ) )
        {
            MFnDagNode dagFn ( node );
            int dot = plugPath.index ( '.' );
            plugPath = dagFn.fullPathName() + plugPath.substring ( dot, plugPath.length() );
        }

        MString command = MString ( "setAttr -s " ) + size + " \"" + plugPath + "\";";

        MGlobal::executeCommand ( command );
#endif // MAYA 8.00+
    }

    //---------------------------------------------------
    // Creates a typed attribute. Used for maya "notes" attributes.
    MObject DagHelper::createAttribute (
    	const MObject& node,
    	const char* attributeName,
    	const char* attributeShortName,
    	MFnNumericData::Type type,
    	const char *value )
    {
        // Before creating a new attribute: verify that an old one doesn't already exist
        MStatus status;
        MObject attribute;
        MFnDependencyNode nodeFn ( node );
        MPlug plug = nodeFn.findPlug ( attributeShortName, status );

        if ( status != MStatus::kSuccess )
        {
            MFnNumericAttribute attr;
            MStatus status;
            attribute = attr.create ( attributeName,attributeShortName,type,0,&status );
            if ( status != MStatus::kSuccess ) return MObject::kNullObj;

            attr.setStorable ( true );
            attr.setKeyable ( false );
            attr.setCached ( true );
            attr.setReadable ( true );
            attr.setWritable ( true );
            status = nodeFn.addAttribute ( attribute, MFnDependencyNode::kLocalDynamicAttr );
            if ( status != MStatus::kSuccess ) return MObject::kNullObj;

            plug = nodeFn.findPlug ( attribute, &status );
            if ( status != MStatus::kSuccess ) return MObject::kNullObj;
        }

        status = plug.setValue ( value );
        if ( status != MStatus::kSuccess ) return MObject::kNullObj;

        return attribute;
    }

    //---------------------------------------------------
    MObject DagHelper::createAttribute (
        const MObject& node,
        const char* attributeName,
        const char* attributeShortName,
        MFnData::Type type,
        const char *value )
    {
        // Before creating a new attribute: verify that an old one doesn't already exist
        MStatus status;
        MObject attribute;
        MFnDependencyNode nodeFn ( node );
        MPlug plug = nodeFn.findPlug ( attributeShortName, status );

        if ( status != MStatus::kSuccess )
        {
            MFnTypedAttribute attr;
            MStatus status;
            attribute = attr.create ( attributeName,attributeShortName,type,&status );
            if ( status != MStatus::kSuccess ) return MObject::kNullObj;

            attr.setStorable ( true );
            attr.setKeyable ( false );
            attr.setCached ( true );
            attr.setReadable ( true );
            attr.setWritable ( true );
            status = nodeFn.addAttribute ( attribute, MFnDependencyNode::kLocalDynamicAttr );
            if ( status != MStatus::kSuccess ) return MObject::kNullObj;

            plug = nodeFn.findPlug ( attribute, &status );
            if ( status != MStatus::kSuccess ) return MObject::kNullObj;
        }

        status = plug.setValue ( value );
        if ( status != MStatus::kSuccess ) return MObject::kNullObj;

        return attribute;
    }

    //---------------------------------------------------
    MPlug DagHelper::addAttribute ( const MObject& node, const MObject& attribute )
    {
        MPlug plug;
        MFnAttribute attributeFn ( attribute );
        MFnDependencyNode depFn ( node );
        MStatus status = depFn.addAttribute ( attribute, MFnDependencyNode::kLocalDynamicAttr );
        if ( status == MStatus::kSuccess )
        {
            plug = depFn.findPlug ( attribute );
        }

        return plug;
    }

    //---------------------------------------------------
    // Get a dag path or node from a String
    MDagPath DagHelper::getShortestDagPath ( const MObject& node )
    {
        MDagPathArray paths;
        MDagPath::getAllPathsTo ( node, paths );
        MDagPath shortestPath;
        if ( paths.length() > 0 )
        {
            shortestPath = paths[0];
            for ( uint i = 1; i < paths.length(); ++i )
            {
                if ( shortestPath.length() > paths[i].length() )
                {
                    shortestPath = paths[i];
                }
            }
        }

        return shortestPath;
    }

    //---------------------------------------------------
    MObject DagHelper::getNode ( const MString& name )
    {
        MSelectionList selection;
        selection.add ( name );

        MObject nodeObject;
        selection.getDependNode ( 0, nodeObject );

        return nodeObject;
    }

    //---------------------------------------------------
    MObject DagHelper::createAnimationCurve ( const MObject& node, const char* attributeName, const char* curveType )
    {
        MFnDependencyNode fn ( node );
        return createAnimationCurve ( fn.findPlug ( attributeName ), curveType );
    }

    //---------------------------------------------------
    MObject DagHelper::createAnimationCurve ( const MPlug& plug, const char* curveType )
    {
        MStatus rc;
        MFnDependencyNode curveFn;
        curveFn.create ( curveType, &rc );

        if ( rc == MStatus::kSuccess )
        {
            DagHelper::connect ( curveFn.object(), "output", plug );
        }

        return curveFn.object();
    }

    //---------------------------------------------------
    MObject DagHelper::createExpression ( const MPlug& plug, const MString& expression )
    {
        MFnDependencyNode expressionFn;
        MObject expressionObj = expressionFn.create ( "expression" );
        DagHelper::setPlugValue ( expressionObj, "expression", expression );

        MPlug output = expressionFn.findPlug ( "output" );
        MPlug firstOutput = output.elementByLogicalIndex ( 0 );
        DagHelper::connect ( firstOutput, plug );
        return expressionObj;
    }

    //---------------------------------------------------
    bool DagHelper::plugHasAnimation ( const MPlug& plug )
    {
        MPlugArray connections;
        plug.connectedTo ( connections, true, false );
        unsigned int connectionsCount = connections.length();

        for ( unsigned int i = 0; i < connectionsCount; i++ )
        {
            MPlug connectedToPlug = connections[i];
            MObject nodeObj = connectedToPlug.node();
            MFnDependencyNode nodeFn ( nodeObj );
            MString typeName = nodeFn.typeName();

            if ( ( typeName == "animCurveTU" ) || ( typeName == "animCurveTL" )
                    || ( typeName == "animCurveTA" ) )
            {
                return true;
            }
        }

        return false;
    }

    //---------------------------------------------------
    // get the first empty item in the named array plug
    unsigned DagHelper::getFirstEmptyElementId ( const MPlug& parent )
    {
        unsigned num_element = 1;

        if ( parent.numElements() > num_element ) num_element = parent.numElements();

        for ( unsigned i = 0; i< num_element; i++ )
        {
            if ( !parent.elementByLogicalIndex ( i ).isConnected() ) return i;
        }

        return parent.numElements() +1;
    }
}
