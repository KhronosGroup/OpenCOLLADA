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

    //----------------------------------
    MObject ShaderHelper::getLayeredTextures ( 
        const MObject& layeredTexture,
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

    //----------------------------------
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

    //----------------------------------
    MStatus ShaderHelper::getConnectedShaders ( 
        const MFnDependencyNode& node, 
        MObjectArray& shaders )
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

    //----------------------------------
    MPlug ShaderHelper::findPlug ( 
        const MFnDependencyNode& node, 
        const MString& plugName, 
        MStatus* rc )
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

    //----------------------------------
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

    //----------------------------------
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

    //----------------------------------
    int ShaderHelper::defaultProjectionType()
    {
        // According to the documentation, "PLANAR" is the default value
        return 1;
    }

    //----------------------------------
    uint ShaderHelper::getAssociatedUVSet(const MObject& shape, const MObject& textureNode)
    {
        // Rather than trying to find all the node types which may be derived
        // off texture2d, then handling optionally handling placement nodes,
        // we can simply walk backwards along the uvCoord attributes until
        // we find a uvChooser.
        MStatus status;
        MObject node = textureNode;
        while(node.apiType() != MFn::kUvChooser)
        {
            MFnDependencyNode dgFn(node);
            MPlug plug = dgFn.findPlug(MString("uvCoord"), &status);
            if (status == MS::kSuccess && plug.isConnected())
            {
                // Get the connection - there can be at most one input to a plug
                //
                MPlugArray connections;
                plug.connectedTo(connections, true, false);
                if (connections.length() > 0)
                {
                    node = connections[ 0].node();
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }

        // Did we find a uvChooser?
        //
        if (node.apiType() == MFn::kUvChooser)
        {
            // Find the uvSet connection to this shape
            //
            MFnDependencyNode dgFn(node);
            MPlug plug = dgFn.findPlug(MString("uvSets"), &status);
            if (status == MS::kSuccess && plug.isArray())
            {
                // Iterate over all the elements in this array looking for
                // one which connects to our shape
                //
                uint numUVSets = plug.evaluateNumElements();
                for (uint i = 0; i < numUVSets; i++)
                {
                    MPlug uvSetPlug = plug.elementByPhysicalIndex(i, &status);
                    if (status && uvSetPlug.isConnected())
                    {
                        // Get the connection - there can be at most one input to a plug
                        //
                        MPlugArray connections;
                        uvSetPlug.connectedTo(connections, true, false);
                        if (connections.length() > 0 && connections[0].node() == shape)
                        {
                            // connected through name element
                            MPlug uvSetElement= connections[0].parent();
                            MPlug uvSetArray = uvSetElement.array();
                            if (uvSetArray.isArray())
                            {
                                uint logicalIndex = uvSetElement.logicalIndex();
                                for (uint child = 0; child < uvSetArray.numElements(); ++child)
                                {
                                    MPlug childPlug = uvSetArray.elementByPhysicalIndex(child);
                                    if (childPlug.logicalIndex() == logicalIndex)
                                    {
                                        return child;
                                    }
                                }
                            } 
                        }
                    }
                }
            }
        }


        // [KThacker] Another weird thing. MFnMesh keeps an internal list of uvSet names.
        // This is not necessarily in the physical order of the plugs under uvSet (elementByPhysicalIndex),
        // or the logical order (through MEL uvSet[<logical index>]).
        // When no uvChooser is present it uses the first uvSet name from the list
        // to define which uvSet to use as default, if the name is different it uses a uvChooser.
        // Got this problem after importing a file from FBX.
        //
        // So we get the list of names and search through the plugs in physical order
        // to get the correct physical index to return.

        MFnMesh mesh(shape);
        MStringArray setNames;
        mesh.getUVSetNames(setNames);

        MPlug uvSetPlug = mesh.findPlug("uvSet");

        for (uint i = 0; i < uvSetPlug.numElements(); ++i)
        {
            // get uvSet[<index>]
            MPlug uvSetElememtPlug = uvSetPlug.elementByPhysicalIndex(i);

            // get uvSet[<index>].uvSetName
            MPlug uvSetNamePlug = uvSetElememtPlug.child(0);

            // get value of plug (uvSet's name)
            MString uvSetName;

            uvSetNamePlug.getValue(uvSetName);

            if (uvSetName==setNames[0])
                return i;

        }

        // we don't want to get here, because it'll end up with wrong results.
        return 0;
    }
}