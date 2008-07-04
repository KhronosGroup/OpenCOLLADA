/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/


#include "COLLADASource.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    void SourceBase::prepareBaseToAppendValues ( const String *arrayName )
    {
        mSourceCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_SOURCE );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, mId );
        mSW->openElement ( *arrayName );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, mArrayId );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_COUNT, mAccessorCount * mAccessorStride );
    }

    //---------------------------------------------------------------
    void SourceBase::finishBase ( const String* parameterTypeName, bool closeSourceElement )
    {
        closeArray();

        addBaseTechnique ( parameterTypeName );

        if ( closeSourceElement ) closeSource();
    }

    //---------------------------------------------------------------
    void SourceBase::closeArray()
    {
        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void SourceBase::closeSource()
    {
        mSourceCloser.close();
    }

    //---------------------------------------------------------------
    void SourceBase::addBaseTechnique ( const String* parameterTypeName )
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_TECHNIQUE_COMMON );
        mSW->openElement ( CSWC::COLLADA_ELEMENT_ACCESSOR );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SOURCE, "#" + mArrayId );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_COUNT, mAccessorCount );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_STRIDE, mAccessorStride );

        for ( ParameterNameList::iterator it = mParameterNameList.begin(); it != mParameterNameList.end(); ++it )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_PARAM );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, *it );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_TYPE, *parameterTypeName );
            mSW->closeElement();
        }

        mSW->closeElement();

        mSW->closeElement();
    }


} //namespace COLLADA
