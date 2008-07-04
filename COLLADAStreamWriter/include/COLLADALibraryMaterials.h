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