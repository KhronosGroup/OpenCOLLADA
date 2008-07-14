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

#include "COLLADAStreamWriter.h"
#include "COLLADALibrary.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    Library::Library ( COLLADA::StreamWriter *streamWriter, const String &name )
            : ElementWriter ( streamWriter ),
            mLibraryOpen ( false ),
            mName ( name )
    {}


    //---------------------------------------------------------------
    void Library::openLibrary()
    {
        if ( !mLibraryOpen )
        {
            mLibraryCloser = mSW->openElement ( mName );
            mLibraryOpen = true;
        }
    }


    //---------------------------------------------------------------
    void Library::closeLibrary()
    {
        if ( mLibraryOpen )
            mLibraryCloser.close();

        mLibraryOpen = false;
    }


} //namespace COLLADA
