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
		static void parseAttributes(MFnDependencyNode & fnNode, AttributeParser & parser);

	protected:
		/**
		 * Callback called before parsing an attribute.
		 * @param fnNode Parsed node.
		 * @param attribute Parsed attribute.
		 * @return false to skip attribute. true to continue attribute parsing.
		 */
		virtual bool onBeforeAttribute	(MFnDependencyNode & fnNode, MObject & attribute)   { return true; }

		/**
		 * Callback called after parsing an attribute.
		 * @param fnNode Parsed node.
		 * @param attribute Parsed attribute.
		 */
		virtual void onAfterAttribute	(MFnDependencyNode & fnNode, MObject & attribute)   { }

		/**
		 * Callbacks called when parsing an attribute of given type.
		 * @param plug Node plug associated to current attribute.
		 * @param name Current attribute name.
		 * @param value Current attribute plug value.
		 */
		virtual void onBoolean			    (MPlug & plug, const MString & name, bool value)			                    { }
		virtual void onByte				    (MPlug & plug, const MString & name, char value)			                    { }
		virtual void onChar				    (MPlug & plug, const MString & name, char value)			                    { }
		virtual void onShort			    (MPlug & plug, const MString & name, short value)			                    { }
		virtual void onShort2			    (MPlug & plug, const MString & name, short value[2])		                    { }
		virtual void onShort3			    (MPlug & plug, const MString & name, short value[3])		                    { }
		virtual void onInteger				(MPlug & plug, const MString & name, int value)				                    { }
		virtual void onInteger2				(MPlug & plug, const MString & name, int value[2])			                    { }
		virtual void onInteger3				(MPlug & plug, const MString & name, int value[3])			                    { }
		virtual void onFloat				(MPlug & plug, const MString & name, float value)			                    { }
		virtual void onFloat2			    (MPlug & plug, const MString & name, float value[2])		                    { }
		virtual void onFloat3			    (MPlug & plug, const MString & name, float value[3])		                    { }
		virtual void onDouble			    (MPlug & plug, const MString & name, double value)			                    { }
		virtual void onDouble2			    (MPlug & plug, const MString & name, double value[2])		                    { }
		virtual void onDouble3			    (MPlug & plug, const MString & name, double value[3])		                    { }
		virtual void onDouble4			    (MPlug & plug, const MString & name, double value[4])		                    { }
		virtual void onString			    (MPlug & plug, const MString & name, const MString & value)	                    { }
        virtual void onEnum                 (MPlug & plug, const MString & name, int enumValue, const MString & enumName)   { }
        virtual void onMesh                 (MPlug & plug, const MString & name, MObject & meshObject)                      { }
        virtual void onConnection           (MPlug & plug, const MString & name, MPlug & externalPlug)                      { }
        virtual void onCompoundAttribute    (MPlug & plug, const MString & name)                                            { }
        virtual void onAngle                (MPlug & plug, const MString & name, MAngle & angle)                            { }
        virtual void onDistance             (MPlug & plug, const MString & name, MDistance & distance)                      { }
        virtual void onTime                 (MPlug & plug, const MString & name, MTime & time)                              { }

	private:
        void parseAttribute         (MFnDependencyNode & fnNode, MObject & attribute, std::set<String>& parsedAttributes);
		void parseNumericAttribute	(MFnDependencyNode & fnNode, MObject & attribute);
		void parseTypedAttribute    (MFnDependencyNode & fnNode, MObject & attribute);
        void parseEnumAttribute     (MFnDependencyNode & fnNode, MObject & attribute);
        void parseMessageAttribute  (MFnDependencyNode & fnNode, MObject & attribute);
        void parseMatrixAttribute   (MFnDependencyNode & fnNode, MObject & attribute);
        void parseCompoundAttribute (MFnDependencyNode & fnNode, MObject & attribute, std::set<String>& parsedAttributes);
        void parseUnitAttribute     (MFnDependencyNode & fnNode, MObject & attribute);
		void parseNumericData       (MFnDependencyNode & fnNode, MObject & attribute);
		void parseNumeric           (MPlug plug, MFnNumericData::Type type);
		void parseStringData        (MFnDependencyNode & fnNode, MObject & attribute);
        void parseMeshData          (MFnDependencyNode & fnNode, MObject & attribute);

		static bool IsNumericCompoundAttribute(const MObject& attribute, MFnNumericData::Type& type);

        friend class AutoOnAfterAttribute;
    };
}

#endif // __COLLADA_MAYA_ATTRIBUTE_PARSER_H__
