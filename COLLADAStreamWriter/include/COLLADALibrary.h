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


#ifndef __COLLADASTREAMWRITER_LIBRARY_H__
#define __COLLADASTREAMWRITER_LIBRARY_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"

namespace COLLADA
{

    /** Base class for all libraries*/

    class Library : public ElementWriter
    {

    public:
        /** Constructor
        @param streamWriter the stream writer the library should be written to
        */
        Library ( StreamWriter * streamWriter, const String & name );

        /** Destructor*/
        virtual ~Library() {}


    protected:
        /** Closes the @a \<library_geometry\> tag.
        This function should be called after the last geometry has been added*/
        void closeLibrary();

        /** Opens the library.
        This function must be called before the first geometry is added*/
        void openLibrary();

    private:
        TagCloser mLibraryCloser;    ///< Used to close the library  tag
        bool mLibraryOpen;      ///< true, if a library has been open and not closed. false otherwise.
        const String & mName;


    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_LIBRARY_H__
