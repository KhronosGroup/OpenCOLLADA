#ifndef __COLLADA_SOURCE_UTIL_H__
#define __COLLADA_SOURCE_UTIL_H__

#include "HelperPrerequisites.h"
#include <dom/domSource.h>

namespace COLLADA {

    class SourceUtil
    {
    private:
        domSource* mSource;
        size_t mStride;
        size_t mCount;
        domListOfFloats* mValues;

    public:
        static domListOfFloats& getFloatValues(const domSourceRef& source);
        static domAccessorRef getAccessor(const domSourceRef& source);
        static size_t getStride(const domSourceRef& source);
        static size_t getCount(const domSourceRef& source);
        static void setFloatValues(const domSourceRef& source, domListOfFloats& values);

    public:
        /** Creates a new source access util.
        	@param source The source to access.
        */
        SourceUtil(domSource* source);
        virtual ~SourceUtil();

        /** Retrieves the values at the specified index.
        	@param index The index to access. Must be less than count.
        	@param values[] The array to populate with values. Size must be equal to stride.
        */
        void get(size_t index, domFloat values[]);

        /** 
        	@return The stride of the source to access.
        */
        size_t getStride() const {return mStride;}
        
        /** 
        	@return The number of elements in the source.
        */
        size_t getCount() const {return mCount;}
    };

} // namespace COLLADA
#endif // __COLLADA_SOURCE_UTIL_H__
