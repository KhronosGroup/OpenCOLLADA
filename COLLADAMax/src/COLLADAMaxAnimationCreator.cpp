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
#include "COLLADAMaxAnimationCreator.h"


#define COLORRGB_CONTROL_CLASS_ID     Class_ID(0x118f7c01,0xfeee238a)
#define SCALEXYZ_CONTROL_CLASS_ID     Class_ID(0x118f7c01,0xfeee238b)


namespace COLLADAMax
{

    //------------------------------
	AnimationCreator::AnimationCreator( DocumentImporter* documentImporter )
		: ImporterBase(documentImporter)
	{
	}

    //------------------------------
	AnimationCreator::~AnimationCreator()
	{
	}

	//------------------------------
	Control* AnimationCreator::createMaxFloatController( COLLADAFW::AnimationCurve* animationCurve, bool isLinear )
	{
		Class_ID controllerClassID(isLinear ? LININTERP_FLOAT_CLASS_ID : HYBRIDINTERP_FLOAT_CLASS_ID, 0);
		return createMaxController( CTRL_FLOAT_CLASS_ID, controllerClassID );
	}

	//------------------------------
	Control* AnimationCreator::createMaxTransformationController( COLLADAFW::AnimationCurve* animationCurve )
	{
		Class_ID controllerClassID(PRS_CONTROL_CLASS_ID, 0);
		return createMaxController( CTRL_MATRIX3_CLASS_ID, controllerClassID );
	}

	//------------------------------
	Control* AnimationCreator::createMaxConstantFloatController( float constantValue )
	{
		Class_ID controllerClassID(LININTERP_FLOAT_CLASS_ID, 0);
		Control* maxController = createMaxController( CTRL_FLOAT_CLASS_ID, controllerClassID );
		maxController->SetValue(0, &constantValue);
		return maxController;
	}

	//------------------------------
	Control* AnimationCreator::createMaxColorRGBAController()
	{
		// Create the controller: Point4 doesn't have a linear controller.
		//return createMaxController( CTRL_POINT3_CLASS_ID, Class_ID (HYBRIDINTERP_COLOR_CLASS_ID, 0) );
		return createMaxController( CTRL_POINT3_CLASS_ID, COLORRGB_CONTROL_CLASS_ID );
	}


	//------------------------------
	Control* AnimationCreator::createMaxScaleController()
	{
		// Create the controller: Point4 doesn't have a linear controller.
		return createMaxController( CTRL_SCALE_CLASS_ID, SCALEXYZ_CONTROL_CLASS_ID );
	}

	//------------------------------
	Control* AnimationCreator::createMaxController( SClass_ID controllerSuperClassID, Class_ID controllerClassID )
	{
		Control* maxController = (Control*)createMaxObject( controllerSuperClassID, controllerClassID);

		// TODO
		// Set the out-of-range types.
		//maxController->SetORT(ToORT(curve->GetPreInfinity()), ORT_BEFORE);
		//maxController->SetORT(ToORT(curve->GetPostInfinity()), ORT_AFTER);

		return maxController;
	}

	//------------------------------
	Control* AnimationCreator::cloneController( Control* controllerToClone, ConversionFunctorType conversionFunctor )
	{
		static Class_ID linearFloatClassId(LININTERP_FLOAT_CLASS_ID, 0);
		static Class_ID hybridFloatClassId(HYBRIDINTERP_FLOAT_CLASS_ID, 0);

#ifdef MAX_2011_OR_NEWER
		DefaultRemapDir remapDir;
		Control* clonedController = (Control*)controllerToClone->Clone(remapDir);
#else
		Control* clonedController = (Control*)controllerToClone->Clone();
#endif
		if ( (controllerToClone->SuperClassID() == CTRL_FLOAT_CLASS_ID) && (conversionFunctor) )
		{
			//we can only scale float controller
			//we only need to scale, if there is a conversion functor
			Class_ID controllerClassID = clonedController->ClassID();
	
			IKeyControl* clonedKeyController = GetKeyControlInterface( clonedController );

			if ( controllerClassID == linearFloatClassId )
			{
				int keyCount = clonedKeyController->GetNumKeys();
				for ( int i = 0; i < keyCount; ++i)
				{
					ILinFloatKey key;
					clonedKeyController->GetKey(i, &key);
					key.val = (*conversionFunctor)(key.val);
					clonedKeyController->SetKey(i, &key);
				}
			}
			else if ( controllerClassID == hybridFloatClassId )
			{
				int keyCount = clonedKeyController->GetNumKeys();
				for ( int i = 0; i < keyCount; ++i)
				{
					IBezFloatKey key;
					clonedKeyController->GetKey(i, &key);
					key.val = (*conversionFunctor)(key.val);
					key.intan = (*conversionFunctor)(key.intan);
					key.outtan = (*conversionFunctor)(key.outtan);
					clonedKeyController->SetKey(i, &key);
				}
			}
		}
		return clonedController;
	}

} // namespace COLLADAMax
