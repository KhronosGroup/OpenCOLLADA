/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "HelperStableHeaders.h"
#include "COLLADAInputUtil.h"
#include "COLLADASourceUtil.h"

namespace COLLADADomHelper {
    //-----------------------------------------------------------------------
    domInputLocalRef InputUtil::getInputLocal( domVerticesRef vertices, const std::string& semantic )
    {
        domInputLocal_Array& inputs = vertices->getInput_array();
        for(size_t i=0; i<inputs.getCount(); ++i)
        {
            domInputLocalRef input = inputs.get(i);
            if(strcmp(input->getSemantic(), semantic.c_str()) == 0)
            {
                return input;
            }
        }
        return 0;
    }
    //-----------------------------------------------------------------------
    size_t InputUtil::getMaxInputLocalOffset( const domInputLocalOffset_Array& inputArray )
    {
        size_t offset = 0;
        for(size_t i=0; i<inputArray.getCount(); ++i)
        {
            domInputLocalOffsetRef input = inputArray.get(i);
            if(input->getOffset() > offset)
            {
                offset = (size_t)input->getOffset();
            }
        }
        return offset;
    }
    //-----------------------------------------------------------------------
    void InputUtil::getMaxInputLocalWithEqualOffset( const domInputLocalOffset_Array& inputArray, InputLocalOffsetSet& equalInputLocalOffsets )
    {
        size_t count = inputArray.getCount();
        for(size_t i=0; i<count; ++i)
        {
            domInputLocalOffsetRef input = inputArray.get(i);
            for(size_t j=0; j<count; ++j)
            {
                domInputLocalOffsetRef otherInput = inputArray.get(j);
                if(input != otherInput && input->getOffset() == otherInput->getOffset())
                {
                    equalInputLocalOffsets.insert(input);
                }
            }            
        }
    }
} // namespace COLLADA
