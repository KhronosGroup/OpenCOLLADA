/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWTranslate.h"

namespace COLLADAFW
{

	//--------------------------------------------------------------------
	Translate::Translate() 
		: Transformation(Transformation::TRANSLATE),
		mTranslationVector(COLLADABU::Math::Vector3::ZERO)
	{	}

	//--------------------------------------------------------------------
	Translate::Translate( const COLLADABU::Math::Vector3& translationVector )
		: Transformation(Transformation::TRANSLATE),
		mTranslationVector(translationVector)
	{}

	//--------------------------------------------------------------------
	Translate::Translate( double x, double y, double z )
		: Transformation(Transformation::TRANSLATE),
		mTranslationVector(x, y, z)
	{}


	//--------------------------------------------------------------------
	Translate::~Translate()
	{
	}

} // namespace COLLADAFW
