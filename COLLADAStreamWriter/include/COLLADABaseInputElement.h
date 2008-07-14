/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/
#ifndef __COLLADASTREAMWRITER_BASE_INPUT_ELEMENT_H__
#define __COLLADASTREAMWRITER_BASE_INPUT_ELEMENT_H__

#include "COLLADAPrerequisites.h"
#include "COLLADABaseElement.h"
#include "COLLADAInputList.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    /** Template class representing a base input element. */
    class BaseInputElement : public BaseElement
    {

    private:

        /** List of all the inputs*/
        InputList mInputList;

    public:

        /**
         * Constructor.
         * @param streamWriter Pointer to the stream.
         */
        BaseInputElement ( StreamWriter* streamWriter, const String& elementName )
        : BaseElement ( streamWriter, elementName )
        , mInputList ( streamWriter )
        {}

        /**
         * Destructor.
         */
        virtual ~BaseInputElement() {};

        /** Returns a reference to the input list */
        InputList& getInputList()
        {
            return mInputList;
        }

        /** Adds the element to the stream */
        void add();

    };

    //---------------------------------------------------------------

    /**
     * Template class to define the typedefs.
     */
    template<const String& elementName>
    class BaseInputElementTemplate : public BaseInputElement
    {
    public:
        BaseInputElementTemplate ( StreamWriter* streamWriter ) 
            : BaseInputElement( streamWriter, elementName ) {};
    };

    //---------------------------------------------------------------

    /** Vertices input element for the geometry. */
    typedef BaseInputElementTemplate<CSWC::COLLADA_ELEMENT_VERTICES> Vertices;

    /** Joints input element for the controller. */
    typedef BaseInputElementTemplate<CSWC::COLLADA_ELEMENT_JOINTS> JointsElement;


} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_BASE_INPUT_ELEMENT_H__
