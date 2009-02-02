/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INDEXLIST_H__
#define __COLLADAFW_INDEXLIST_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTypes.h"


namespace COLLADAFW
{

    class IndexList
    {
    private:
        size_t mInputSetIndex;
        String mInputSetName;
        UIntValuesArray mUVCoordIndices;
        size_t mStride;
        size_t mInitialIndex;

    public:
        IndexList () 
            : mInputSetIndex (0)
            , mInputSetName ("")
            , mUVCoordIndices (0)
            , mStride (0) 
            , mInitialIndex (0)
        {}
        IndexList ( size_t inputSet, size_t stride, UIntValuesArray& uvCoordIndices ) 
            : mInputSetIndex (inputSet)
            , mInputSetName ("")
            , mUVCoordIndices (uvCoordIndices)
            , mStride (stride) 
            , mInitialIndex (0)
        {}
        virtual ~IndexList () {}

        UIntValuesArray& getIndices () { return mUVCoordIndices; }
        unsigned int getIndex ( size_t index ) const { return mUVCoordIndices [index]; }
        unsigned int getIndex ( size_t index ) { return mUVCoordIndices [index]; }
        size_t getIndicesCount () const { return mUVCoordIndices.getCount (); }
        size_t getIndicesCount () { return mUVCoordIndices.getCount (); }

        void setInputSetIndex ( size_t inputSet ) { mInputSetIndex = inputSet; }
        size_t getInputSetIndex () { return mInputSetIndex; }
        
        void setStride ( size_t stride ) { mStride = stride; }
        size_t getStride () { return mStride; }

        const COLLADAFW::String& getInputSetName () const { return mInputSetName; }
        void setInputSetName ( const COLLADAFW::String& val ) { mInputSetName = val; }

        const size_t getInitialIndex () const { return mInitialIndex; }
        void setInitialIndex ( const size_t val ) { mInitialIndex = val; }

    private:

        /** Disable default copy ctor. */
        IndexList( const IndexList& pre );

        /** Disable default assignment operator. */
        const IndexList& operator= ( const IndexList& pre );
    };


    typedef ArrayPrimitiveType<IndexList*> IndexListArray;



} // namespace COLLADAFW

#endif // __COLLADAFW_INDEXLIST_H__
