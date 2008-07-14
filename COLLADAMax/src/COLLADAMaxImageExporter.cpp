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


#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxImageExporter.h"
#include "COLLADANode.h"

#include "COLLADAMaxExportSceneGraph.h"

namespace COLLADAMax
{


    //---------------------------------------------------------------
    ImageExporter::ImageExporter ( COLLADA::StreamWriter * streamWriter, DocumentExporter * documentExporter )
            : COLLADA::LibraryImages ( streamWriter ),
            mExportedImageMap ( documentExporter->getEffectExporter() ->getExportedImageMap() )
    {}


    //---------------------------------------------------------------
    void ImageExporter::doExport()
    {
        // export all wire frame color materials

        for ( ExportedImageMap::const_iterator it = mExportedImageMap.begin(); it != mExportedImageMap.end(); ++it )
        {
            addImage ( COLLADA::Image ( it->first, it->second ) );
        }

        closeLibrary();
    }



}
