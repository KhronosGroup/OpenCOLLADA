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
        String mName;
        UIntValuesArray mIndices;
        size_t mStride;
        size_t mSetIndex;
        size_t mInitialIndex;

    public:
        IndexList () 
            : mSetIndex (0)
            , mName ("")
            , mIndices (0)
            , mStride (0) 
            , mInitialIndex (0)
        {}
        IndexList ( size_t setIndex, size_t stride, UIntValuesArray& indices )
            : mSetIndex (setIndex)
            , mName ("")
            , mIndices (indices)
            , mStride (stride) 
            , mInitialIndex (0)
        {}
        virtual ~IndexList () {}

        UIntValuesArray& getIndices () { return mIndices; }
        unsigned int getIndex ( size_t index ) const { return mIndices [index]; }
        unsigned int getIndex ( size_t index ) { return mIndices [index]; }
        size_t getIndicesCount () const { return mIndices.getCount (); }
        size_t getIndicesCount () { return mIndices.getCount (); }

        void setSetIndex ( size_t inputSet ) { mSetIndex = inputSet; }
        size_t getSetIndex () { return mSetIndex; }
        
        void setStride ( size_t stride ) { mStride = stride; }
        size_t getStride () { return mStride; }

        const COLLADAFW::String& getName () const { return mName; }
        void setName ( const COLLADAFW::String& val ) { mName = val; }

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
