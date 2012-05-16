/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_SOURCE_INPUT_H__
#define __COLLADA_MAYA_SOURCE_INPUT_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADASWSource.h"
#include "COLLADASWInputList.h"


namespace COLLADAMaya
{
    class SourceInput;

    typedef std::vector<SourceInput> Sources;

    /** A generic Input attribute */
    class SourceInput
    {

    private:

        /** Collada source */
        COLLADASW::SourceBase mSource;

        /** Index list. */
        std::vector<int> mIndices;

        /** The number of vertex indices. */
        uint mNumVertexIndices;

        /** Index of the current vertex source. */
        int mIdx;

        /** Type of the source. */
		COLLADASW::InputSemantic::Semantics mType;

    public:

        /** Constructor */
        SourceInput ( COLLADASW::SourceBase& source, COLLADASW::InputSemantic::Semantics type, int idx = -1 )
            : mSource ( source )
            , mType ( type )
            , mIdx ( idx ) 
            , mNumVertexIndices (0)
            , mIndices (0)
        {}

        /** Destructor */
        virtual ~SourceInput() {}

        /** Collada source */
        const COLLADASW::SourceBase& getSource() const { return mSource; }
        void setSource(COLLADASW::SourceBase val) { mSource = val; }

        /** Index list. */
        const std::vector<int>& getIndices() const { return mIndices; }
        std::vector<int>& getIndices() { return mIndices; }
        void setIndices(std::vector<int> val) { mIndices = val; }

        /** The number of vertex indices. */
        const size_t getNumVertexIndices() const { return mIndices.size(); } //mNumVertexIndices; }
        void setNumVertexIndices(uint val) { mNumVertexIndices = val; }
        void incrementNumVertexIndices() { ++mNumVertexIndices; }

        /** Type of the source. */
        const COLLADASW::InputSemantic::Semantics& getType() const { return mType; }
        void setType(COLLADASW::InputSemantic::Semantics val) { mType = val; }

        /** Index of the current vertex source. */
        const int getIdx() const { return mIdx; }
        void setIdx(int val) { mIdx = val; }

        /**
        * Returns true, if the given list contains the given SourceInput.
        */
        static bool containsSourceBase ( const Sources* sources, const COLLADASW::SourceBase* searchedSourceBase );

        /**
        * Returns true, if the given list contains the given SourceInput and erased successful.
        */
        static bool eraseSourceBase ( Sources* sources, COLLADASW::SourceBase* searchedSourceBase );
    };

}

#endif //__COLLADA_MAYA_SOURCE_INPUT_H__
