/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_FORMULANEWPARAM_H__
#define __COLLADAFW_FORMULANEWPARAM_H__

#include "COLLADAFWPrerequisites.h"

#include "COLLADAFWPointerArray.h"
#include "COLLADAFWUniqueId.h"


namespace COLLADAFW
{

    /** New param as it appears in formula and kinematics */
	class FormulaNewParam 	
	{
	public:
		enum ValueType { VALUETYPE_UNKNOWN, VALUETYPE_FLOAT, VALUETYPE_INT, VALUETYPE_BOOL, VALUETYPE_SIDREF};
	private:
	
		/** Value type of the new param.*/
		ValueType mValueType;

		union Value
		{
			double _double;
			int _int;
			bool _bool;
		} mValue;
		
		/** The name of the new param (sid in COLLADA).*/
		String mName;
	public:

        /** Constructor. */
		FormulaNewParam(ValueType valueType) : mValueType(valueType){}

        /** Destructor. */
		virtual ~FormulaNewParam(){}

		/** Returns the value type of the new param.*/
		ValueType getValueType() const { return mValueType; }

		/** Sets the value type of the new param.*/
		void setValueType(ValueType valueType) { mValueType = valueType; }

		/** Returns the double value of the new param. Type must be VALUETYPE_FLOAT.*/
		double getDoubleValue() const { return mValue._double; }

		/** Sets the double value of the new param. Type will be set to VALUETYPE_FLOAT.*/
		void setDoubleValue(double doubleValue) { mValue._double = doubleValue; mValueType = VALUETYPE_FLOAT; }

		/** Returns the int value of the new param. Type must be VALUETYPE_INT.*/
		int getIntValue() const { return mValue._int; }

		/** Sets the int value of the new param. Type will be set to VALUETYPE_INT.*/
		void setIntValue(int intValue) { mValue._int = intValue; mValueType = VALUETYPE_INT; }

		/** Returns the bool value of the new param. Type must be VALUETYPE_BOOL.*/
		bool getBoolValue() const { return mValue._bool; }

		/** Sets the bool value of the new param. Type will be set to VALUETYPE_BOOL.*/
		void setBoolValue(bool boolValue) { mValue._bool = boolValue; mValueType = VALUETYPE_BOOL; }

		/** Returns the name of the new param (sid in COLLADA).*/
		const String& getName() const { return mName; }

		/** Returns the name of the new param (sid in COLLADA).*/
		void setName(const String& name) { mName = name; }

		FormulaNewParam* clone() const { return FW_NEW FormulaNewParam(*this); }

	};

	typedef PointerArray<FormulaNewParam> FormulaNewParamPointerArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_FORMULANEWPARAM_H__
