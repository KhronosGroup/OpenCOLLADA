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


#include "COLLADAMaxStableHeaders.h"

#include "COLLADAMaxXRefFunctions.h"

#include <max.h>
#include "COLLADAMaxXRefIncludes.h"

namespace COLLADAMax
{

	//---------------------------------------------------------------
	bool XRefFunctions::isXRefObject(Animatable* object)
	{
#ifdef MAX_8_OR_NEWER
		return IXRefObject8::Is_IXRefObject8(* object);
#else
		return (object->SuperClassID() == SYSTEM_CLASS_ID && object->ClassID().PartA() == XREFOBJ_CLASS_ID);
#endif
	}


	//---------------------------------------------------------------
	bool XRefFunctions::isXRefItem(Animatable* object)
	{
#ifdef MAX_8_OR_NEWER
		return IXRefItem::IsIXRefItem(* object);
#else
		// no xref items in max7
		return false;
#endif
	}


	//---------------------------------------------------------------
	bool XRefFunctions::isXRefMaterial(Animatable* material)
	{
#ifdef MAX_8_OR_NEWER
		return IXRefMaterial::Is_IXRefMaterial(*material);
#else
		// not supported
		(void)material;
		return false;
#endif
	}

#if 0
	//---------------------------------------------------------------
	fstring XRefFunctions::GetURL(Animatable* xref)
	{
		if (!IsXRefObject(xref) && !IsXRefMaterial(xref)) return FS("");

		fstring maxUrl;
#ifdef USE_MAX_8
		{
			IXRefItem* x = IXRefItem::GetInterface(*xref);
			maxUrl = (x != NULL) ? x->GetSrcFileName() : emptyFString;
		}
#elif USE_MAX_7
		{
			IXRefObject* x = (IXRefObject*) xref;
			maxUrl = TO_FSTRING(x->GetFileName(FALSE).data());
		}
#endif 

		size_t xrefTokenIndex = maxUrl.find(FC(".xreffile"));
		if (xrefTokenIndex != fstring::npos)
		{
			// Remove the ".xreffile.max" suffix. The old extension should still be there.
			maxUrl.erase(xrefTokenIndex);
		}

		// Replace the extension by .dae
		return maxUrl;
	}
#endif

#if 0
	//---------------------------------------------------------------
	bool XRefFunctions::IsXRefCOLLADASW(Animatable* xref)
	{
		// Not performant, but the simplest method is to look at the extension of the filename.
		FUUri uri(XRefFunctions::GetURL(xref));
		fstring extension = FUFileManager::GetFileExtension(uri.GetPath());
		return IsEquivalentI(extension, FC("dae")) || IsEquivalentI(extension, FC("xml"));
	}
#endif

#if 0
	//---------------------------------------------------------------
	fm::string XRefFunctions::GetSourceName(Animatable* xref)
	{
#if USE_MAX_8
		IXRefItem* x = IXRefItem::GetInterface(* xref);
		if (x == NULL)
			return "";

		return fm::string(x->GetSrcItemName());

#elif USE_MAX_7
		if (IsXRefObject(xref))
		{
			IXRefObject* xobj = (IXRefObject*)xref;
			return fm::string(xobj->GetObjName(FALSE).data());
		}
		else
		{
			return "(not xref)";
		}
#endif
	}
#endif

	//---------------------------------------------------------------
	Object* XRefFunctions::getXRefObjectSource(Object* xRefObject, Tab< Modifier * > * modifiers)
	{
		if ( !isXRefObject(xRefObject) ) 
			return xRefObject; // this is the source
#ifdef MAX_8_OR_NEWER

		IXRefObject8* xRefObjectInterface = IXRefObject8::GetInterface(* xRefObject);
		if ( !xRefObjectInterface ) 
			return 0;

		// resolve nested
		Object* source = xRefObjectInterface->GetSourceObject(false, modifiers);

#else
		XRefObject_REDEFINITION* xobj = (XRefObject_REDEFINITION*)xRefObject;
		Object* source = xobj->obj;

#endif
		return source;
	}


	//---------------------------------------------------------------
	Object* XRefFunctions::getXRefItemSource(Object* xRefObject)
	{
		if ( !isXRefItem(xRefObject) ) 
			return (IDerivedObject*) xRefObject; // this is the source
#ifdef MAX_8_OR_NEWER

		IXRefItem * xRefObjectInterface = IXRefItem::GetInterface(* xRefObject);
		if ( !xRefObjectInterface ) 
			return 0;

		// resolve nested
		IDerivedObject* source = (IDerivedObject*) xRefObjectInterface->GetSrcItem(false);
		
		INode* bb1 = source->GetWorldSpaceObjectNode();


		int h1h = 5;

#else
		// no xref items in max7
		Object* source = xRefObject;
#endif
		return source;
	}



#if 0
	//---------------------------------------------------------------
	fm::string XRefFunctions::GetXRefObjectName(Object* xref)
	{
		if (!IsXRefObject(xref)) return emptyString; // this is the source
#if USE_MAX_8

		IXRefObject8* xobj = IXRefObject8::GetInterface(*xref);
		if (xobj == NULL) return emptyString;
		IXRefItem* item = IXRefItem::GetInterface(*xref);
		if (item == NULL) return emptyString;
		return item->GetSrcItemName();
#elif USE_MAX_7

		XRefObject_REDEFINITION* xobj = (XRefObject_REDEFINITION*)xref;
		return xobj->xrefObj.data();
#endif
	}
#endif

	//---------------------------------------------------------------
	Mtl* XRefFunctions::getXRefMaterialSource(Mtl* xRefMaterial)
	{
#ifdef MAX_8_OR_NEWER

		if (!isXRefMaterial(xRefMaterial))
		{
			// this is the source
			return xRefMaterial;
		}

		IXRefMaterial* xRefMaterialInterface = IXRefMaterial::GetInterface(* xRefMaterial);
		if ( !xRefMaterialInterface )
			return 0;

		// resolve nested
		Mtl* source = xRefMaterialInterface->GetSourceMaterial(true);
		return source;

#else
		// not supported in Max 7
		return xRefMaterial;
#endif
	}

}
