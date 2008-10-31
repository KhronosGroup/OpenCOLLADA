#ifndef __COLLADA_ELEMENT_ITERATOR_H__
#define __COLLADA_ELEMENT_ITERATOR_H__

#include "HelperPrerequisites.h"

namespace COLLADADomHelper {

    /** An COLLADA element iterator. Iterates over all elements that
    meet the specified search criteria.
    @par E.g. this iterator can be utilized to iterate over all
    &lt;scene&gt; elements.
    @par Note: The iterator could only be used for elements which must have
    a id attribute. Elements like instance_geometry could not be iterated
    with this implementation.
    */
    class ElementIterator
    {
    public:
        /** Creates a new iterator with the given search criteria.
        @param database The database to use for the queries.
        @param name The name or id to search.
        @param type The element type to search.
        @param file The uri/id of the document/collection to search.
        */
        ElementIterator(daeDatabase* database, int type, daeDocument* file = 0);

        /** @return true if there are more elements, otherwise false. */
        bool hasNext() const {return mIndex < mCount;}

        /** @return The next element. */
        daeElementRef getNext();

        /** @return The count of elements which meet the search criteria.
        */
        size_t getElementCount();

    protected:        
        int getType();
        daeDocument* getFile();

    private:
        /** The db to query. */
        daeDatabase* mDaeDatabase;
        /** Search criteria element type. */
        int mType;
        /** Search scope. */
        daeDocument* mFile;
        /** The count of elements. */
        size_t mCount;
        /** The current index . */
        size_t mIndex;        

        /** Search results. */
        std::vector<daeElement*> mResults;

        /** Search for elements to iterate over. */
        void doSearch();
    };

} // namespace COLLADA
#endif // __COLLADA_ELEMENT_ITERATOR_H__
