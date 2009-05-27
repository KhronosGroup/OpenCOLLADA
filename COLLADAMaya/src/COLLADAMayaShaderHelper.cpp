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

#include <maya/MFnAttribute.h>
#include <maya/MFnMesh.h>
//Hack to circumvent bad code in Maya7.0

class MFnNurbsSurface;
#include <maya/MFnNurbsSurface.h>
#include <maya/MItDependencyGraph.h>
#include <maya/MItDependencyNodes.h>
#include <maya/MSelectionList.h>
#include <maya/MFnComponentListData.h>

#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaShaderHelper.h"
#include "COLLADAMayaSyntax.h"

namespace COLLADAMaya
{

    MObject ShaderHelper::getLayeredTextures ( const MObject& layeredTexture,
            MObjectArray& fileTextures,
            MIntArray& blendModes )
    {
        MFnDependencyNode layeredTextureFn ( layeredTexture );
        MStatus rc;

        MPlug inputs = findPlug ( layeredTextureFn, "inputs", &rc );
        CHECK_STATUS ( rc, MString ( "Unable to locate inputs array plug on layeredTexture: " ) + layeredTextureFn.name() );

        uint elementCount = inputs.numElements();

        for ( int i = ( int ) ( elementCount - 1 ); i >= 0; --i )
        {
            MPlug input = inputs.elementByPhysicalIndex ( i, &rc );
            CHECK_STATUS ( rc, MString ( "Unable to locate input#" ) + i + MString ( " on layeredTexture: " ) + layeredTextureFn.name() );

            MPlug colorInput = DagHelper::getChildPlug ( input, "c", &rc ); // "color"
            CHECK_STATUS ( rc, MString ( "Unable to locate input#" ) + i + MString ( "'s color child plug on layeredTexture: " ) + layeredTextureFn.name() );

            MObject connection = DagHelper::getNodeConnectedTo ( colorInput );

            if ( connection != MObject::kNullObj )
            {
                fileTextures.append ( connection );

                MPlug blendMode = DagHelper::getChildPlug ( input, "bm", &rc ); // "blendMode"
                CHECK_STATUS ( rc, MString ( "Unable to locate input#" ) + i + MString ( "'s blend mode child plug on layeredTexture: " ) + layeredTextureFn.name() );

                int mode;
                blendMode.getValue ( mode );
                blendModes.append ( mode );
            }
        }

        return layeredTexture;
    }

    //
    // Get the shadingEngine used by a specific shader (the inverse of the above)
    //
    MObject ShaderHelper::getShadingEngine ( MObject shadingNetwork )
    {
        MStatus rc = MStatus::kSuccess;
        MItDependencyGraph it ( shadingNetwork,
                                MFn::kShadingEngine,
                                MItDependencyGraph::kDownstream,
                                MItDependencyGraph::kBreadthFirst,
                                MItDependencyGraph::kNodeLevel, &rc );
        return ( rc == MStatus::kSuccess ? it.thisNode() : MObject::kNullObj );
    }

    MStatus ShaderHelper::getConnectedShaders ( const MFnDependencyNode& node, MObjectArray& shaders )
    {
        MPlugArray nodePlugs;
        node.getConnections ( nodePlugs );

        for ( uint i = 0; i < nodePlugs.length(); i++ )
        {
            const MPlug& nodePlug = nodePlugs[i];
            MPlugArray nodeDestinations;
            nodePlug.connectedTo ( nodeDestinations, false, true );

            for ( uint j = 0; j < nodeDestinations.length(); j++ )
            {
                if ( nodeDestinations[j].node().apiType() == MFn::kShadingEngine )
                {
                    shaders.append ( nodeDestinations[j].node() );
                }
            }
        }

        return ( shaders.length() > 0 ? MStatus::kSuccess : MStatus::kFailure );
    }

    MPlug ShaderHelper::findPlug ( const MFnDependencyNode& node, const MString& plugName, MStatus* rc )
    {
        MStatus st;
        MPlug p = node.findPlug ( plugName, &st );

        if ( st == MStatus::kSuccess )
        {
            if ( rc != NULL ) *rc = MStatus::kSuccess;

            return p;
        }

        MPlugArray plugs;

        st = node.getConnections ( plugs );

        if ( st != MStatus::kSuccess )
        {
            if ( rc != NULL ) *rc = st;

            return p;
        }

        for ( unsigned int i = 0; i < plugs.length(); ++i )
        {
            p = plugs[i];
            MFnAttribute attribute ( p.attribute() );

            if ( attribute.name() ==  plugName )
            {
                if ( rc != NULL ) *rc = MStatus::kSuccess;

                return p;
            }
        }

        if ( rc != NULL ) *rc = MStatus::kNotFound;

        return p;
    }

    uint ShaderHelper::findArrayPlugEmptyIndex ( const MPlug& plug )
    {
        MStatus rc;
        uint index;

        uint count = plug.numElements();

        for ( index = 0; index < count; ++index )
        {
            MPlug connection = plug.elementByLogicalIndex ( index, &rc );

            if ( rc == MStatus::kSuccess && !connection.isConnected() ) break;
        }

        return index;
    }

    MObject ShaderHelper::findDisplayLayer ( const char* name )
    {
        MStatus rc;
        MDGModifier dgModifier;
        MFnDependencyNode layerNode;

        // Find the layer manager
        MFnDependencyNode layerManager;

        for ( MItDependencyNodes dependencyIt; !dependencyIt.isDone(); dependencyIt.next() )
        {
            MFnDependencyNode node ( dependencyIt.item() );

            if ( node.name() == "layerManager" )
            {
                layerManager.setObject ( node.object() );
                break;
            }
        }

        if ( layerManager.object() == MObject::kNullObj )
        {
            MGlobal::displayError ( "Unable to find default layer manager." );
            return MObject::kNullObj;
        }

        // Look for a display layer with this name
        MPlug layerListPlug = findPlug ( layerManager, "displayLayerId", &rc );

        CHECK_STATUS ( rc, "Unable to find default layer manager's id plug array." );

        uint layerListPlugCount = layerListPlug.numElements();

        for ( uint i = 0; i < layerListPlugCount; ++i )
        {
            MPlug layerPlug = layerListPlug.elementByPhysicalIndex ( i, &rc );
            CHECK_STATUS ( rc, "Unable to find default layer manager's physical id plug." );

            MObject connection = DagHelper::getNodeConnectedTo ( layerPlug );
            MFnDependencyNode connectedNode ( connection );

            if ( connectedNode.name() ==  name )
            {
                return connection;
            }
        }

        // Create a new layer node and get its "identification" plug
        layerNode.create ( "displayLayer", name, &rc );

        CHECK_STATUS ( rc, MString ( "Unable to create new display layer: " ) + name );

        MPlug dst = findPlug ( layerNode, "identification", &rc );

        CHECK_STATUS ( rc, MString ( "Unable to get new display layer's identification plug: " ) + name );

        // Connect the layer node to the layer manager's list of layers
        uint logicalIndex = findArrayPlugEmptyIndex ( layerListPlug );

        MPlug src = layerListPlug.elementByLogicalIndex ( logicalIndex, &rc );

        CHECK_STATUS ( rc, "Unable to find default layer manager's correct id plug." );

        dgModifier.connect ( src, dst );

        dgModifier.doIt();

        // Set the ID value unto the display manager child plug.
        // Fixes SourceForge 1425745: Layer information is missing from the UI on import.
        DagHelper::setPlugValue ( src, ( int ) logicalIndex ); // Arbitary size

        return layerNode.object();
    }

    static const int g_projectionTypeValueCount = 9;
    static const char* g_projectionTypeValues[g_projectionTypeValueCount] = { ( "NONE" ), ( "PLANAR" ), ( "SPHERICAL" ), ( "CYLINDRICAL" ), ( "BALL" ), ( "CUBIC" ), ( "TRIPLANAR" ), ( "CONCENTRIC" ), ( "PERSPECTIVE" ) };
    int ShaderHelper::toProjectionType ( const char* type )
    {
        for ( int i = 0; i < g_projectionTypeValueCount; ++i )
        {
            if ( strcmp ( type, g_projectionTypeValues[i] ) == 0 ) return i;
        }

        // According to the documentation, "PLANAR" is the default value
        return defaultProjectionType();
    }

    const char* ShaderHelper::projectionTypeToString ( int type )
    {
        if ( type >= 0 && type < g_projectionTypeValueCount )
        {
            return g_projectionTypeValues[type];
        }

        else
        {
            return g_projectionTypeValues[defaultProjectionType() ];
        }
    }

    int ShaderHelper::defaultProjectionType()
    {
        // According to the documentation, "PLANAR" is the default value
        return 1;
    }
}