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


#ifndef __COLLADASTREAMWRITER_ELEMENT_WRITER_H__
#define __COLLADASTREAMWRITER_ELEMENT_WRITER_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAStreamWriter.h"

namespace COLLADA
{
    /** The base class of all classes that write elements to the stream*/

    class ElementWriter
    {

    public:
        /** Constructor
        @param streamWriter The stream writer that should be used to write to the stream*/
        ElementWriter ( StreamWriter * streamWriter ) : mSW ( streamWriter ) {}

        static const String EMPTY_STRING;

    protected:
        StreamWriter * mSW;


    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_ELEMENT_WRITER_H__
