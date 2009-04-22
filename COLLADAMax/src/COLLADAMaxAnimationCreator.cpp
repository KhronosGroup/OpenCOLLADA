/*
Copyright (c) 2008 NetAllied Systems GmbH

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


} // namespace COLLADAMax
