/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_XREFFUNCTIONS_H__
#define __COLLADAMAX_XREFFUNCTIONS_H__

#include "COLLADAMaxPrerequisites.h"


class Animatable;
class Object;
class Mtl;

namespace COLLADAMax
{

	/** This class contains static helper functions to handle XRefs*/
    class XRefFunctions
    {
	public:

		/** Checks, if @a object is a XRef object.
		@return True, if @a object is a XRef object, false if not.*/
		static bool isXRefObject(Animatable* object);

		/** Checks, if @a object is a XRef item.
		@return True, if @a object is a XRef item, false if not.*/
		static bool isXRefItem(Animatable* object);

		/** Checks, if @a material is a XRef object.
		@return True, if @a material is a XRef object, false if not.*/
		static bool isXRefMaterial(Animatable* material);

		static String GetURL(Animatable* xref);
		static bool IsXRefCOLLADASW(Animatable* xref);
		static String GetSourceName(Animatable* xref);

		/** Recursively resolves the XRef object, i.e. it returns the object that is referenced.
		@return The resolved object. It is garanteed to be not an Xref object.*/
		static Object* getXRefObjectSource(Object* xRefObject, Tab< Modifier * > * modifiers = 0);

		/** Recursively resolves the XRef object, i.e. it returns the object that is referenced.
		@return The resolved object. It is garanteed to be not an Xref object.*/
		static Object* getXRefItemSource(Object* xRefObject);

		/** Recursively resolves the XRef material, i.e. it returns the object that is referenced.
		@return The resolved material. It is garanteed to be not an Xref material.*/
		static Mtl* getXRefMaterialSource(Mtl* xRefMaterial);

		static String GetXRefObjectName(Object* xref);

	};


}


#endif //__COLLADAMAX_XREFFUNCTIONS_H__

