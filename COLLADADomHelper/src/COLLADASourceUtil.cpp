/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "HelperStableHeaders.h"
#include "COLLADASourceUtil.h"

namespace COLLADADomHelper {

    //-----------------------------------------------------------------------
    domListOfFloats& SourceUtil::getFloatValues( const domSourceRef& source )
    {
        domFloat_arrayRef array = source->getFloat_array();
        return array->getValue();
    }
    //-----------------------------------------------------------------------
    void SourceUtil::setFloatValues( const domSourceRef& source, domListOfFloats& values )
    {
        domFloat_arrayRef array = source->getFloat_array();
        array->setValue(values);
    }
    //-----------------------------------------------------------------------
    domAccessorRef SourceUtil::getAccessor( const domSourceRef& source )
    {
        domSource::domTechnique_commonRef technique = source->getTechnique_common();
        return technique->getAccessor();
    }
    //-----------------------------------------------------------------------
    size_t SourceUtil::getStride( const domSourceRef& source )
    {
        domAccessorRef accessor = getAccessor(source);
        return (size_t)accessor->getStride();
    }
    //-----------------------------------------------------------------------
    size_t SourceUtil::getCount( const domSourceRef& source )
    {
        domAccessorRef accessor = getAccessor(source);
        return (size_t)accessor->getCount();
    }
    //-----------------------------------------------------------------------
    SourceUtil::SourceUtil( domSource* source )
        : mSource(source)
        , mStride(0)
        , mCount(0)
    {
        mStride = getStride(source);
        mCount = getCount(source);
        mValues = &getFloatValues(mSource);
    }
    //-----------------------------------------------------------------------
    SourceUtil::~SourceUtil()
    {

    }
    //-----------------------------------------------------------------------
    void SourceUtil::get( size_t index, domFloat values[] )
    {
        size_t i = index*mStride;
        for(size_t s=0; s<mStride; ++s)
        {
            values[s] = mValues->get(i+s);
        }
    }
} // namespace COLLADA
