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


#ifndef __COLLADASTREAMWRITER_EXTRA_H__
#define __COLLADASTREAMWRITER_EXTRA_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include <map>

namespace COLLADA
{

    /** A class to add an Asset to the stream.*/

    class Extra : public ElementWriter
    {

    public:
        /** Constructor
        @param streamWriter The stream the asset should be written to.*/
        Extra ( StreamWriter* streamWriter ) : ElementWriter ( streamWriter ) {}

        /** Destructor*/
        virtual ~Extra() {}

        /** Opens the extra tag. */
        void openExtra ( const String &extraId="", const String &extraName="", const String &extraType="" );

        /** Closes the extra tag */
        void closeExtra();

    private:

        /** Used to close the current extra. */
        TagCloser mExtraCloser;
    };

} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_EXTRA_H__
