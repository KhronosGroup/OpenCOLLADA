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
#include "COLLADALibraryVisualScenes.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    LibraryVisualScenes::LibraryVisualScenes ( COLLADA::StreamWriter *streamWriter )
            : Library ( streamWriter, CSWC::COLLADA_ELEMENT_LIBRARY_VISUAL_SCENES )
    {}


    //---------------------------------------------------------------
    void LibraryVisualScenes::openVisualScene ( const String &nodeId, const String &nodeName )
    {
        openLibrary();
        mCurrentVisualSceneCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_VISUAL_SCENE );

        if ( !nodeId.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, nodeId );

        if ( !nodeName.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, nodeName );
    }


    //---------------------------------------------------------------
    void LibraryVisualScenes::closeVisualScene()
    {
        mCurrentVisualSceneCloser.close();
    }

} //namespace COLLADA
