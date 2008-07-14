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


#ifndef __COLLADASTREAMWRITER_LIBRARY_MATERIALS_H__
#define __COLLADASTREAMWRITER_LIBRARY_MATERIALS_H__

#include "COLLADAPrerequisites.h"
#include "COLLADALibrary.h"

namespace COLLADA
{

    /** Class to simply the creation of @a \<library_materials\> and @a \<material\>'s*/

    class LibraryMaterials : public Library
    {

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_materials\> and @a \<material\>'s
        should be written to.
        */
        LibraryMaterials ( StreamWriter * streamWriter );

        /** Destructor*/
        virtual ~LibraryMaterials() {}

    protected:
        /** Adds @a \<material\> element and @a \<instance_effect\> element.
        If not already opened, it opens @a \<library_materials\>*/
        void addInstanceEffect ( const String & effectURL = EMPTY_STRING,
                                 const String & materialId = EMPTY_STRING,
                                 const String & materialName = EMPTY_STRING );


        static const String MATERIAL_ID_SUFFIX;

    private:
    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_LIBRARY_MATERIALS_H__