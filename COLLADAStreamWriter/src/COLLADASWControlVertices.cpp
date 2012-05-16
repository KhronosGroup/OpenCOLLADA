/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWControlVertices.h"


namespace COLLADASW
{

    //------------------------------
	ControlVertices::ControlVertices( StreamWriter* streamWriter ) 
		: ElementWriter(streamWriter)
		, mInputList(streamWriter)
	{
	}

    //------------------------------
	ControlVertices::~ControlVertices()
	{
	}

	//------------------------------
	void ControlVertices::add()
	{
		mSW->openElement( CSWC::CSW_ELEMENT_CONTROL_VERTICES );
		mInputList.add();
		mSW->closeElement();
	}
} // namespace COLLADASW
