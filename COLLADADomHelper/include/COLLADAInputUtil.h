#ifndef __COLLADA_INPUT_UTIL__
#define __COLLADA_INPUT_UTIL__

#include "HelperPrerequisites.h"

#include <set>
#include <dae.h>
#include <dom/domVertices.h>

#include "COLLADASourceUtil.h"

namespace COLLADADomHelper {

    /** Utility class for domInputLocal and domInputLocalOffset handling. */
    class InputUtil
    {
    public:
        /** Retrieves the first domInptuLocal of the specified semantic
        within the given domVertices.
        @param vertices The vertices to retrieve the input from.
        @param semantic The semantic of the input.
        @return The smart pointer to the input. Can be null.
        */
        static domInputLocalRef getInputLocal(domVerticesRef vertices, const std::string& semantic);
        
        template<class T>
        static domInputLocalOffsetRef getInputLocalOffset(daeSmartRef< T > primitives, const std::string& semantic)
        {
            domInputLocalOffset_Array& inputs = primitives->getInput_array();
            for(size_t i=0; i<inputs.getCount(); ++i)
            {
                domInputLocalOffsetRef input = inputs.get(i);
                if(strcmp(input->getSemantic(), semantic.c_str()) == 0)
                {
                    return input;
                }
            }
            return 0;
        }

        template<class T>
            static size_t getInputLocalOffsetIndex(daeSmartRef< T > primitives, const std::string& semantic)
        {
            domInputLocalOffset_Array& inputs = primitives->getInput_array();
            for(size_t i=0; i<inputs.getCount(); ++i)
            {
                domInputLocalOffsetRef input = inputs.get(i);
                if(strcmp(input->getSemantic(), semantic.c_str()) == 0)
                {
                    return i;
                }
            }
            return -1;
        }

        /** Iterates over the input array and calculates the maximum 
        offset.
        @par The maximum offset is the number of indices per 
        primitive vertex. E.g. A max offset of 3 means that
        a triangles vertex consists of 3 indices. Therefore
        a triangle consists of 3x3 indices.
        @param inputArray The input array to iterate.
        @return The maximum offset
        */
        static size_t getMaxInputLocalOffset(const domInputLocalOffset_Array& inputArray);

        /** A set of domInputLocalOffsetRef. */
        typedef std::set<domInputLocalOffsetRef> InputLocalOffsetSet;

        /** Inspects the given input array if there are inputs with
        equal offset and add them to the given input array of 
        inputs with equal offset.
        @param inputArray The input array to inspect.
        @param equalInputLocalOffsets The input array to store inputs with equal offset.
        */
        static void getMaxInputLocalWithEqualOffset(const domInputLocalOffset_Array& inputArray, InputLocalOffsetSet& equalInputLocalOffsets);
        
        template<class T>
        static domSourceRef getSource(const daeSmartRef<T>& input)
        {
            return daeSafeCast<domSource>(input->getSource().getElement());
        }        

        template<class T>
        static domListOfFloats& getFloatValues(const daeSmartRef<T>& input)
        {
            return SourceUtil::getFloatValues(getSource(input));
        }

        template<class T>
        static size_t getStride(const daeSmartRef<T>& input)
        {
            return SourceUtil::getStride(getSource(input));
        }

        template<class T>
            static size_t getCount(const daeSmartRef<T>& input)
        {
            return SourceUtil::getCount(getSource(input));
        }

        template<class T>
            static void setFloatValues(const daeSmartRef<T>& input, domListOfFloats& values)
        {
            return SourceUtil::setFloatValues(getSource(input), values);
        }

        template<class T>
            static domVerticesRef getVertices(daeSmartRef< T > primitives)
        {
            domInputLocalOffsetRef vertexInput = getInputLocalOffset(primitives, COMMON_PROFILE_INPUT_VERTEX);
            if(vertexInput == 0)
                return 0;
            return daeSafeCast<domVertices>(vertexInput->getSource().getElement());
        }
        template<class T>
            static domSourceRef getNormals(daeSmartRef< T > primitives)
        {
            domInputLocalOffsetRef normalInput = getInputLocalOffset(primitives, COMMON_PROFILE_INPUT_NORMAL);
            if(normalInput == 0)
            {
                return getPerVertexData(primitives, COMMON_PROFILE_INPUT_NORMAL);
            }
            return daeSafeCast<domSource>(normalInput->getSource().getElement());
        }
		template<class T>
		static domSourceRef getColors(daeSmartRef< T > primitives)
		{
			domInputLocalOffsetRef colorInput = getInputLocalOffset(primitives, COMMON_PROFILE_INPUT_COLOR);
			if(colorInput == 0)
            {
                return getPerVertexData(primitives, COMMON_PROFILE_INPUT_COLOR);
            }
			return daeSafeCast<domSource>(colorInput->getSource().getElement());
		}
        template<class T>
        static domSourceRef getTexCoords(daeSmartRef< T > primitives)
        {
            domInputLocalOffsetRef texcoordInput = getInputLocalOffset(primitives, COMMON_PROFILE_INPUT_TEXCOORD);
            if(texcoordInput == 0)
            {
                return getPerVertexData(primitives, COMMON_PROFILE_INPUT_TEXCOORD);
            }
            return daeSafeCast<domSource>(texcoordInput->getSource().getElement());
        }


        /** Retrieves requested data from passed primitive or null.
        @param primitives Primitives to get data from.
        @param data Data to get. E.g. COMMON_PROFILE_INPUT_NORMAL or COMMON_PROFILE_INPUT_COLOR.
        @return source element containing requested data or null if requestet data are not present.
        */
        template<class T>
        static domSourceRef getPerVertexData(daeSmartRef< T > primitives, const daeString& data)
        {
            domVerticesRef verticesRef = getVertices(primitives);
            if (verticesRef == 0) return 0;

            return getPerVertexData(*verticesRef, data);
        }

        /** Retrieves requested data from passed vertices or null.
        @param vertices Vertices to get data from.
        @param data Data to get. E.g. COMMON_PROFILE_INPUT_NORMAL or COMMON_PROFILE_INPUT_COLOR.
        @return source element containing requested data or null if requestet data are not present.
        */
        static domSourceRef getPerVertexData(domVertices& vertices, const daeString& data)
        {
            domInputLocal_Array& inputs = vertices.getInput_array();
            for (size_t i=0; i<inputs.getCount(); ++i)
            {
                domInputLocal* input = inputs.get( i );
                input->getSource().resolveElement();
                if ( strcmp( input->getSemantic(), data ) == 0 )
                {
                    return daeSafeCast<domSource>(input->getSource().getElement());
                }
            }
            return 0;
        }
    private:
        InputUtil();
        virtual ~InputUtil();
        
    };

} // namespace COLLADA
#endif // __COLLADA_INPUT_UTIL__
