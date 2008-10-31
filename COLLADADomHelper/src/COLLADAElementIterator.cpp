#include "HelperStableHeaders.h"
#include "COLLADAElementIterator.h"

namespace COLLADADomHelper {
    //-----------------------------------------------------------------------
    ElementIterator::ElementIterator( daeDatabase* database, int type, daeDocument* file )
        :mDaeDatabase(database)
        ,mType(type)
        ,mFile(file)
        ,mCount(0)
        ,mIndex(0)
    {
        mCount = getElementCount();
    }
    //-----------------------------------------------------------------------
    daeElementRef ElementIterator::getNext()
    {
        daeElement* element = 0;
        if (mIndex < mCount)
        {
            element = mResults[mIndex];
        }
        mIndex++;
        return element;
    }
    //-----------------------------------------------------------------------
    size_t ElementIterator::getElementCount()
    {
        if ( mCount == 0 )
        {
            doSearch();
            mCount = mResults.size();
        }
        return mCount;
    }    
    //-----------------------------------------------------------------------
    int ElementIterator::getType()
    {
        return mType;
    }
    //-----------------------------------------------------------------------
    daeDocument* ElementIterator::getFile()
    {

        return mFile;
    }

    //-----------------------------------------------------------------------
    void ElementIterator::doSearch()
    {
        mDaeDatabase->typeLookup(mType, mResults, mFile);
    }
} // namespace COLLADA
