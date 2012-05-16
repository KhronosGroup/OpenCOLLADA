/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWInstanceMaterial.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    //---------------------------------------------------------------
    void InstanceMaterialList::add()
    {
        for ( List::iterator it = mList.begin(); it != mList.end(); ++it )
        {
			it->add( mSW );
        }
    }


	//---------------------------------------------------------------
	void InstanceMaterial::add( StreamWriter* sw )
	{
		sw->openElement ( CSWC::CSW_ELEMENT_INSTANCE_MATERIAL );
		sw->appendAttribute ( CSWC::CSW_ATTRIBUTE_SYMBOL, getSymbol() );
		sw->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_TARGET, getTarget() );
		for ( BindVertexInputList::iterator it = mBindVertexInputList.begin(); it != mBindVertexInputList.end(); ++it)
		{
			it->add( sw );
		}

		sw->closeElement();
	}

	//---------------------------------------------------------------
	void BindVertexInput::add( StreamWriter* sw )
	{
		sw->openElement ( CSWC::CSW_ELEMENT_BIND_VERTEX_INPUT);
		sw->appendAttribute ( CSWC::CSW_ATTRIBUTE_SEMANTIC, getSemantic() );
		sw->appendAttribute ( CSWC::CSW_ATTRIBUTE_INPUT_SEMANTIC, getInputSemantic() );
		sw->appendAttribute ( CSWC::CSW_ATTRIBUTE_INPUT_SET, getInputSet() );
		sw->closeElement();
	}
} //namespace COLLADASW
