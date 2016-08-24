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
		 * Callback called before parsing a plug.
		 * @param plug Parsed plug.
		 * @return false to skip plug. true to continue attribute parsing.
		 */
		virtual bool onBeforePlug(MPlug & plug) { return true; }

		/**
		 * Callback called after parsing a plug.
		 * @param plug Parsed plug.
		 */
		virtual void onAfterPlug(MPlug & plug) { }

		/**
		 * Callbacks called when parsing a plug of given type.
		 * @param plug Node plug associated to current attribute.
		 * @param name Current attribute name.
		 * @param value Current plug value.
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
        virtual void onAngle                (MPlug & plug, const MString & name, const MAngle & angle)                      { }
        virtual void onAngle2               (MPlug & plug, const MString & name, const MAngle angles[2])                    { }
        virtual void onAngle3               (MPlug & plug, const MString & name, const MAngle angles[3])                    { }
        virtual void onAngle4               (MPlug & plug, const MString & name, const MAngle angles[4])                    { }
        virtual void onDistance             (MPlug & plug, const MString & name, const MDistance & distance)                { }
        virtual void onDistance2            (MPlug & plug, const MString & name, const MDistance distances[2])              { }
        virtual void onDistance3            (MPlug & plug, const MString & name, const MDistance distances[3])              { }
        virtual void onDistance4            (MPlug & plug, const MString & name, const MDistance distances[4])              { }
        virtual void onTime                 (MPlug & plug, const MString & name, MTime & time)                              { }
        virtual void onMessage              (MPlug & plug, const MString & name)                                            { }
        virtual void onMatrix               (MPlug & plug, const MString & name, const MMatrix& value)                      { }

	private:
		void parsePlug				(MPlug & plug);
		void parseNumericPlug		(MPlug & plug);
		void parseTypedPlug			(MPlug & plug);
		void parseEnumPlug			(MPlug & plug);
		void parseMessagePlug		(MPlug & plug);
		void parseMatrixPlug		(MPlug & plug);
		void parseCompoundPlug		(MPlug & plug);
		void parseUnitPlug			(MPlug & plug);
		void parseGenericPlug		(MPlug & plug);
		void parseLightDataPlug		(MPlug & plug);
		void parseNumericData		(MPlug & plug);
		void parseNumeric			(MPlug plug, MFnNumericData::Type type);
		void parseStringData		(MPlug & plug);
		void parseMeshData			(MPlug & plug);
		void parseComponentListData	(MPlug & plug);

		static bool IsNumericCompoundAttribute(const MObject& attribute, MFnNumericData::Type& type);

		friend class AutoOnAfterPlug;
    };
}

#endif // __COLLADA_MAYA_ATTRIBUTE_PARSER_H__
