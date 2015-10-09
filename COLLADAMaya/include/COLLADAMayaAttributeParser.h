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

#ifndef __COLLADA_MAYA_ATTRIBUTE_PARSER_H__
#define __COLLADA_MAYA_ATTRIBUTE_PARSER_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaPlatform.h"

#include <maya/MFnDependencyNode.h>
#include <maya/MFnNumericData.h>

namespace COLLADAMaya
{

	/**
	 * Helper class used to parse a node's attributes.
	 */
    class AttributeParser
    {
	public:

		/**
		 * Parse attributes of fnNode and call corresponding callbacks of AttributeParser object.
		 * @param fnNode Parsed node
		 * @param parser Object inheriting AttributeParser class and implementing some of the onXXX() methods.
		 */
		static MStatus parseAttributes(MFnDependencyNode & fnNode, AttributeParser & parser);

	protected:
		/**
		 * Callback called before parsing an attribute.
		 * @param fnNode Parsed node.
		 * @param attribute Parsed attribute.
		 * @return MStatus::kFailure to skip attribute. MStatus::kSuccess to continue attribute parsing.
		 */
		virtual MStatus onBeforeAttribute	(MFnDependencyNode & fnNode, MObject & attribute)			{ return MS::kSuccess; }

		/**
		 * Callback called after parsing an attribute.
		 * @param fnNode Parsed node.
		 * @param attribute Parsed attribute.
		 */
		virtual MStatus onAfterAttribute	(MFnDependencyNode & fnNode, MObject & attribute)			{ return MS::kSuccess; }

		/**
		 * Callbacks called when parsing an attribute of given type.
		 * @param plug Node plug associated to current attribute.
		 * @param name Current attribute name.
		 * @param value Current attribute plug value.
		 */
		virtual MStatus onBoolean			(MPlug & plug, const MString & name, bool value)			                    { return MS::kSuccess; }
		virtual MStatus onByte				(MPlug & plug, const MString & name, char value)			                    { return MS::kSuccess; }
		virtual MStatus onChar				(MPlug & plug, const MString & name, char value)			                    { return MS::kSuccess; }
		virtual MStatus onShort				(MPlug & plug, const MString & name, short value)			                    { return MS::kSuccess; }
		virtual MStatus onShort2			(MPlug & plug, const MString & name, short value[2])		                    { return MS::kSuccess; }
		virtual MStatus onShort3			(MPlug & plug, const MString & name, short value[3])		                    { return MS::kSuccess; }
		virtual MStatus onLong				(MPlug & plug, const MString & name, int value)				                    { return MS::kSuccess; }
		virtual MStatus onLong2				(MPlug & plug, const MString & name, int value[2])			                    { return MS::kSuccess; }
		virtual MStatus onLong3				(MPlug & plug, const MString & name, int value[3])			                    { return MS::kSuccess; }
		virtual MStatus onFloat				(MPlug & plug, const MString & name, float value)			                    { return MS::kSuccess; }
		virtual MStatus onFloat2			(MPlug & plug, const MString & name, float value[2])		                    { return MS::kSuccess; }
		virtual MStatus onFloat3			(MPlug & plug, const MString & name, float value[3])		                    { return MS::kSuccess; }
		virtual MStatus onDouble			(MPlug & plug, const MString & name, double value)			                    { return MS::kSuccess; }
		virtual MStatus onDouble2			(MPlug & plug, const MString & name, double value[2])		                    { return MS::kSuccess; }
		virtual MStatus onDouble3			(MPlug & plug, const MString & name, double value[3])		                    { return MS::kSuccess; }
		virtual MStatus onDouble4			(MPlug & plug, const MString & name, double value[4])		                    { return MS::kSuccess; }
		virtual MStatus onString			(MPlug & plug, const MString & name, const MString & value)	                    { return MS::kSuccess; }
        virtual MStatus onEnum              (MPlug & plug, const MString & name, int enumValue, const MString & enumName)   { return MS::kSuccess; }
        virtual MStatus onMesh              (MPlug & plug, const MString & name, MObject & meshObject)                      { return MS::kSuccess; }
        virtual MStatus onConnection        (MPlug & plug, const MString & name, MPlug & externalPlug)                      { return MS::kSuccess; }
        virtual MStatus onCompoundAttribute (MPlug & plug, const MString & name)                                            { return MS::kSuccess; }
        virtual MStatus onAngle             (MPlug & plug, const MString & name, MAngle & angle)                            { return MS::kSuccess; }
        virtual MStatus onDistance          (MPlug & plug, const MString & name, MDistance & distance)                      { return MS::kSuccess; }
        virtual MStatus onTime              (MPlug & plug, const MString & name, MTime & time)                              { return MS::kSuccess; }

	private:
        MStatus parseAttribute          (MFnDependencyNode & fnNode, MObject & attribute);
		MStatus parseNumericAttribute	(MFnDependencyNode & fnNode, MObject & attribute);
		MStatus parseTypedAttribute		(MFnDependencyNode & fnNode, MObject & attribute);
        MStatus parseEnumAttribute      (MFnDependencyNode & fnNode, MObject & attribute);
        MStatus parseMessageAttribute   (MFnDependencyNode & fnNode, MObject & attribute);
        MStatus parseMatrixAttribute    (MFnDependencyNode & fnNode, MObject & attribute);
        MStatus parseCompoundAttribute  (MFnDependencyNode & fnNode, MObject & attribute);
        MStatus parseUnitAttribute      (MFnDependencyNode & fnNode, MObject & attribute);
		MStatus parseNumericData		(MFnDependencyNode & fnNode, MObject & attribute);
		MStatus parseNumeric			(MPlug plug, MFnNumericData::Type type);
		MStatus parseStringData			(MFnDependencyNode & fnNode, MObject & attribute);
        MStatus parseMeshData           (MFnDependencyNode & fnNode, MObject & attribute);

        friend class AutoOnAfterAttribute;
    };
}

#endif // __COLLADA_MAYA_ATTRIBUTE_PARSER_H__
