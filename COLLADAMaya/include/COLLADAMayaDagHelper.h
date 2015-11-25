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

#ifndef __COLLADA_MAYA_DAG_HELPER_H__
#define __COLLADA_MAYA_DAG_HELPER_H__

#ifndef _MFnNumericData
#include <maya/MFnNumericData.h>
#endif // _MFnNumericData

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaPlatform.h"

namespace COLLADAMaya
{

    class DagHelper
    {

    public:
        // Handle node connections
        static MObject  getNodeConnectedTo ( const MObject& node, const String& attribute );
        static MObject  getSourceNodeConnectedTo ( const MObject& node, const MString& attribute );
        static bool   getPlugConnectedTo ( const MObject& node, const String& attribute, MPlug& plug );
        static MObject  getSourceNodeConnectedTo ( const MPlug& inPlug );
        static bool   getPlugConnectedTo ( const MPlug& inPlug, MPlug& plug );
        static bool   getPlugArrayConnectedTo ( const MObject& node, const MString& attribute, MPlug& plug );
        static MObject  getNodeConnectedTo ( const MPlug& plug );
        static int   getNextAvailableIndex ( const MObject& object, const MString& attribute, int startIndex = 0 );
        static int   getNextAvailableIndex ( const MPlug& p, int startIndex = 0 );
        static bool   connect ( const MObject& source, const MString& sourceAttribute, const MObject& destination, const MString& destinationAttribute );
        static bool   connect ( const MObject& source, const MString& sourceAttribute, const MPlug& destination );
        static bool   connect ( const MPlug& source, const MObject& destination, const MString& destinationAttribute );
        static bool   connect ( const MPlug& source, const MPlug& destination );
        static bool   connectToList ( const MObject& source, const MString& sourceAttribute, const MObject& destination, const MString& destinationAttribute, int* index = NULL );
        static bool   connectToList ( const MPlug& source, const MObject& destination, const MString& destinationAttribute, int* index = NULL );
        static bool   hasConnection ( const MPlug& plug, bool asSource = true, bool asDestination = true );

        // Get/set the bind pose for a transform
        static MMatrix  getBindPoseInverse ( const MObject& controller, const MObject& influence );
        static MStatus  setBindPoseInverse ( const MObject& node, const MMatrix& bindPoseInverse );

        // Find a child plug
        static MPlug  getChildPlug ( const MPlug& parent, const MString& name, MStatus* rc=NULL );
        static int   getChildPlugIndex ( const MPlug& parent, const MString& name, MStatus* rc=NULL ); // Useful for performance reasons when iterating over many plugs

        // Get/set a plug's value
        static bool   getPlugValue ( const MObject& node, const String& attributeName, double &value );
        static bool   getPlugValue ( const MObject& node, const String& attributeName, float &value );
        static bool   getPlugValue ( const MObject& node, const String& attributeName, MEulerRotation& value );
        static bool   getPlugValue ( const MObject& node, const String& attributeName, bool& value );
        static bool   getPlugValue ( const MObject& node, const String& attributeName, int& value );
        static bool   getPlugValue ( const MObject& node, const String& attributeName, MMatrix& value );
        static bool   getPlugValue ( const MObject& node, const String& attributeName, MColor& value );
        static bool   getPlugValue ( const MObject& node, const String& attributeName, MString& value );
        static bool   getPlugValue ( const MObject& node, const String& attributeName, MVector& value );
        static bool   getPlugValue ( const MObject& node, const String& attributeName, int& enumValue, MString& enumName );
        static bool   getPlugValue ( const MObject& node, const String& attributeName, MObject& value );
        static bool   getPlugValue ( const MPlug& plug, bool& value );
        static bool   getPlugValue ( const MPlug& plug, MMatrix& value );
        static bool   getPlugValue ( const MPlug& plug, MColor& value );
        static bool   getPlugValue ( const MPlug& plug, int& value );
        static bool   getPlugValue ( const MPlug& plug, uint32& value );
        static bool   getPlugValue ( const MPlug& plug, short& value );
        static bool   getPlugValue ( const MPlug& plug, uint16& value );
        static bool   getPlugValue ( const MPlug& plug, char& value );
        static bool   getPlugValue ( const MPlug& plug, uint8& value );
        static bool   getPlugValue ( const MPlug& plug, float& x );
        static bool   getPlugValue ( const MPlug& plug, float& x, float& y );
        static bool   getPlugValue ( const MPlug& plug, float& x, float& y, float& z );
        static bool   getPlugValue ( const MPlug& plug, MVector& value );
        static bool   getPlugValue ( const MPlug& plug, int& enumValue, MString& enumName );
        static bool   getPlugValue ( const MPlug& plug, MObject& value );
        static void   getPlugValue ( const MObject& node, const String& attributeName, MStringArray& output, MStatus* status = NULL );
        static void   getPlugValue ( const MPlug& plug, MStringArray& output, MStatus* status = NULL );

        static bool   setPlugValue ( MPlug& plug, const MVector& value );
        static bool   setPlugValue ( MPlug& plug, const MMatrix& value );
        static bool   setPlugValue ( MPlug& plug, const MColor& value );
        static bool   setPlugValue ( MPlug& plug, const String& value );
#ifdef UNICODE
        static bool   setPlugValue ( MPlug& plug, const String& value );
#endif // UNICODE
        static bool   setPlugValue ( MPlug& plug, const MString& value )
        {
            return plug.setValue ( const_cast<MString&> ( value ) ) == MStatus::kSuccess;
        }

        static bool   setPlugValue ( MPlug& plug, float value );
        static bool   setPlugValue ( MPlug& plug, double value );
        static bool   setPlugValue ( MPlug& plug, float x, float y );
        static bool   setPlugValue ( MPlug& plug, int value );
#if defined(WIN32)
        static bool   setPlugValue ( MPlug& plug, int32 value )
        {
            return setPlugValue ( plug, ( int ) value );
        }

#endif // windows-only.
        static bool setPlugValue ( MPlug& plug, bool value );
        static bool setPlugValue ( MPlug& plug, MStringArray& stringArray );

        // Helper to avoid the findPlug.
        template <class ValueType>
        static bool setPlugValue ( 
            const MObject& node, 
            const char* attributeName, 
            const ValueType& value )
        {
            MPlug p = MFnDependencyNode ( node ).findPlug ( attributeName );
            return setPlugValue ( p, value );
        }

        // set an array plug size before creating the element plugs
        static void setArrayPlugSize ( MPlug& plug, uint size );

        // Attempt to translate a String path/name into a dag path or node
        static MDagPath getShortestDagPath ( const MObject& node );
        static MObject getNode ( const MString& name );

        // Create an animation curve for the given plug
        static MObject createAnimationCurve ( const MObject& node, const char* attributeName, const char* curveType );
        static MObject createAnimationCurve ( const MPlug& plug, const char* curveType );
        static bool plugHasAnimation ( const MPlug& plug );
        static MObject createExpression ( const MPlug& plug, const MString& expression );

        // Create a String-typed attribute on a given node
        static MObject createAttribute ( const MObject& node, const char* attributeName, const char* attributeShortName, MFnData::Type type, const char *value );
        static MObject createAttribute ( const MObject& node, const char* attributeName, const char* attributeShortName, MFnNumericData::Type type, const char *value );
        static MPlug addAttribute ( const MObject& node, const MObject& attribute );

        // get the first empty item in the named array plug
        static unsigned getFirstEmptyElementId ( const MPlug& parent );

    private:

        /** Don't create an object of this class. */
        DagHelper() {};
    };
}

#endif // __COLLADA_MAYA_DAG_HELPER_H__
