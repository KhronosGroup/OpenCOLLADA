/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxExportNode.h"

#include <max.h>
#include <modstack.h>
#include <cs/bipexp.h>

namespace COLLADAMax
{


    //---------------------------------------------------------------
    ExportNode::ExportNode ( INode * iNode )
            : mINode ( iNode ),
            mType ( UNDETERMINED )
    {}

    //---------------------------------------------------------------
    ExportNode::ExportNode ( INode * iNode, Type type )
            : mINode ( iNode ),
            mType ( type )
    {}


    //---------------------------------------------------------------
    ExportNode::Type ExportNode::getType() const
    {
        if ( mType == UNDETERMINED )
            mType = determineType();

        return mType;
    }



    //---------------------------------------------------------------
    void ExportNode::clean()
    {
        while ( !mChildren.empty() )
        {
            delete mChildren.back();
            mChildren.pop_back();
        }
    }


    //---------------------------------------------------------------
    ExportNode::Type ExportNode::determineType ( INode * iNode )
    {
        Animatable * animatable = iNode->GetObjectRef();

        if ( animatable == 0 )
            return ExportNode::UNKNOWN;

        Animatable* base = animatable;

        // Modifiers are applied to the object, acquire the base object
        while ( base->SuperClassID() == GEN_DERIVOB_CLASS_ID )
        {
            IDerivedObject * derivedObject = ( IDerivedObject* ) base;
            base = derivedObject->GetObjRef();
        }

        SClass_ID superClassId = base->SuperClassID();

        Class_ID classId = base->ClassID();

        switch ( superClassId )
        {

        case GEOMOBJECT_CLASS_ID:
			{
				//we need this, as soon as we support bones
				// Check for a Max bone mesh

				if ( classId == BONE_OBJ_CLASSID )
					return ExportNode::BONE;

				// Check for biped
				Control* control = iNode->GetTMController();

				if ( control != NULL )
				{
					Class_ID controllerClassId = control->ClassID();

					if ( controllerClassId == BIPSLAVE_CONTROL_CLASS_ID || controllerClassId == BIPBODY_CONTROL_CLASS_ID || controllerClassId == FOOTPRINT_CLASS_ID || controllerClassId == BIPED_CLASS_ID )
						return ExportNode::BONE;
				}
				return ExportNode::MESH;
			}
		case CAMERA_CLASS_ID: 
			return CAMERA;

		case LIGHT_CLASS_ID: 
			return LIGHT;
#if 0
			//for surfaces
		case SHAPE_CLASS_ID:
			// Modifiers can act on a spline to produce a mesh
			if (p != base)
			{
				// BUG368: For some reason the CanConvertToType function stopped working.
				// This is the best option anyway, evaluate the object actually created by
				// the modifier stack.
				ObjectState os = ((IDerivedObject*)p)->Eval(0);
				return Get(node, os.obj, detectXRef);
			}
			if (classId == EDITABLE_SURF_CLASS_ID || classId == EDITABLE_CVCURVE_CLASS_ID || classId == EDITABLE_FPCURVE_CLASS_ID)
			{
				return NURBS_CURVE;
			}
			else
			{
				return SPLINE;
			}
#endif
		case HELPER_CLASS_ID: 
			return (classId.PartA() == BONE_CLASS_ID) ? BONE : HELPER;
		
		case MATERIAL_CLASS_ID: 
			return MATERIAL;

        }


        return ExportNode::UNKNOWN;
    }


    //---------------------------------------------------------------
    ExportNode::Type ExportNode::determineType() const
    {
        return determineType ( mINode );
    }


    void ExportNode::addSymbol ( Mtl * material, const String & symbol )
    {
        Symbol newSymbol;
        newSymbol.used = false;
        newSymbol.name = mIdList.addId ( symbol );
        mMeshSymbolMap[ material ] = newSymbol;
    }



    //---------------------------------------------------------------
    const String& ExportNode::getSymbolByMaterialAndSetAsUsed ( Mtl* material )
    {
        MeshSymbolMap::iterator it = mMeshSymbolMap.find ( material );

        assert ( it != mMeshSymbolMap.end() );

        it->second.used = true;

        return it->second.name;
    }
}
