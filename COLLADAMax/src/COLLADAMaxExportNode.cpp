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

#include "COLLADAMaxExportNode.h"
#include "COLLADAMaxControllerExporter.h"

#include "COLLADAMaxXRefFunctions.h"

#include <max.h>
#include <modstack.h>
#include <cs/bipexp.h>
#include <surf_api.h>

namespace COLLADAMax
{


    //---------------------------------------------------------------
    ExportNode::ExportNode ( INode * iNode, ExportNode* parent  )
            : mINode ( iNode ),
			mParent(parent),
            mType ( UNDETERMINED ),
			mFlags(NONE),
			mControllerList(0)
    {
		determineType();
	}

    //---------------------------------------------------------------
    ExportNode::ExportNode ( INode * iNode, ExportNode* parent , Type type )
            : mINode ( iNode ),
			mParent(parent),
            mType ( type ),
			mFlags(NONE),
			mControllerList(0)
    {
		determineType();
	}


    //---------------------------------------------------------------
    void ExportNode::clean()
    {
        while ( !mChildren.empty() )
        {
            delete mChildren.back();
            mChildren.pop_back();
        }
		delete mControllerList;
    }

    //---------------------------------------------------------------
    ExportNode::Type ExportNode::determineType ( INode * iNode )
    {
        Animatable * animatable = iNode->GetObjectRef();

        if ( !animatable )
            return ExportNode::UNKNOWN;

        Animatable* base = animatable;

		String gg = iNode->GetName();


		// check for an XRef
		if (XRefFunctions::isXRefItem(base))
		{
			setIsXRefObject();
			// replace the current animatable by the x-ref object
			base = XRefFunctions::getXRefItemSource((Object*)base);
			if ( !base ) 
				return ExportNode::UNKNOWN;
		}
		else if (XRefFunctions::isXRefMaterial(base))
		{
			setIsXRefMaterial();
			base = XRefFunctions::getXRefMaterialSource((Mtl*)base);
			if ( !base ) 
				return ExportNode::UNKNOWN;
		}


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
				// Check for a Max bone mesh
				if ( classId == BONE_OBJ_CLASSID )
					return ExportNode::BONE;

				// Check for biped
				Control* control = iNode->GetTMController();

				if ( control )
				{
					Class_ID controllerClassId = control->ClassID();

					if (   controllerClassId == BIPSLAVE_CONTROL_CLASS_ID 
						|| controllerClassId == BIPBODY_CONTROL_CLASS_ID 
						|| controllerClassId == FOOTPRINT_CLASS_ID 
#ifdef MAX_2008_OR_NEWER
						|| controllerClassId == BIPED_CLASS_ID 
#endif 
						)
						return ExportNode::BONE;
				}
				return ExportNode::MESH;
			}
		case CAMERA_CLASS_ID: 
			return CAMERA;

		case LIGHT_CLASS_ID: 
			return LIGHT;
			//for surfaces
		case SHAPE_CLASS_ID:
			// Modifiers can act on a spline to produce a mesh
			if (animatable != base)
			{
				// We use a mesh here
				return MESH;
				// BUG368: For some reason the CanConvertToType function stopped working.
				// This is the best option anyway, evaluate the object actually created by
				// the modifier stack.
				ObjectState os = ((IDerivedObject*)animatable)->Eval(0);
//				return Get(node, os.obj, detectXRef);
			}
			if (classId == EDITABLE_SURF_CLASS_ID || classId == EDITABLE_CVCURVE_CLASS_ID || classId == EDITABLE_FPCURVE_CLASS_ID)
			{
				return MESH;
				// We do not support NURBS here and use mesh instead
				//return NURBS_CURVE;
			}
			else
			{
				return SPLINE;
			}
		case HELPER_CLASS_ID: 
			return (classId.PartA() == BONE_CLASS_ID) ? BONE : HELPER;
		
		case MATERIAL_CLASS_ID: 
			return MATERIAL;

        }
        return ExportNode::UNKNOWN;
    }


    //---------------------------------------------------------------
    void ExportNode::determineType() 
    {
        mType = determineType ( mINode );
    }

	//---------------------------------------------------------------
    void ExportNode::addSymbol ( Mtl * material, const String & symbol )
    {
		// TODO: should be tested with multiple (composite?) materials
		bool found = false;

		MeshSymbolMap::const_iterator it = mMeshSymbolMap.find( material );
		if ( it!=mMeshSymbolMap.end() )
		{
			if ( it->second.name==symbol )
			{
				found = true;
			}
		}

		if (!found)
		{
			Symbol newSymbol;
			newSymbol.used = false;
			newSymbol.name = mSymbolList.addId ( symbol );
			mMeshSymbolMap[ material ] = newSymbol;
		}
    }



    //---------------------------------------------------------------
    const String& ExportNode::getSymbolByMaterialAndSetAsUsed ( Mtl* material )
    {
        MeshSymbolMap::iterator it = mMeshSymbolMap.find ( material );

        assert ( it != mMeshSymbolMap.end() );

        it->second.used = true;

        return it->second.name;
    }

	//---------------------------------------------------------------
	void ExportNode::createControllerList()
	{
		if ( !mControllerList )
			mControllerList = new ControllerList(*this);
	}

	//---------------------------------------------------------------
	Object* ExportNode::getInitialPose() const
	{
		Object* initialPose = 0;

		if ( mControllerList )
			initialPose = mControllerList->getInitialPose();

		if ( !initialPose )
			initialPose  = mINode->GetObjectRef();

		if ( getIsXRefObject() )
			return XRefFunctions::getXRefItemSource(initialPose);
		else
			return initialPose;
	}


	//---------------------------------------------------------------
	Object* ExportNode::getFinalPose() const
	{
		if ( !hasControllers() )
			return 0;
		return mControllerList->getController(0)->getPoseAfter();
	}


	//---------------------------------------------------------------
	String ExportNode::getLastControllerId() const
	{
		if ( !hasControllers() )
			return COLLADASW::Utils::EMPTY_STRING;

		size_t controllerCount = mControllerList->getControllerCount();
		return ControllerExporter::getControllerId(*this, controllerCount, mControllerList->getController(0)->getType());
	}

	//---------------------------------------------------------------
	Controller* ExportNode::getLastController() const
	{
		if ( !hasControllers() )
			return 0;
		return  mControllerList->getController(0);
	}
}
