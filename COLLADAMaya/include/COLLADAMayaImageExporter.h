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

#ifndef __COLLADA_MAYA_IMAGE_EXPORTER_H__
#define __COLLADA_MAYA_IMAGE_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAStreamWriter.h"
#include "COLLADALibraryImages.h"

#include "COLLADAMayaEffectTextureExporter.h"
#include "COLLADAMayaDocumentExporter.h"


namespace COLLADAMaya
{

    /** This class writes the <library_images>. It uses informations created my an effect exporter*/

    class ImageExporter : public COLLADA::LibraryImages
    {

    public:
        /**
        @param streamWriter The stream the output will be written to
        @param documentExporter The document exporter this material exporter is used in*/
        ImageExporter ( COLLADA::StreamWriter* streamWriter );
        virtual ~ImageExporter() {};

        /** Exports the given list of images. */
        void exportImages ( const ImageMap* imageMap );
    };

}

#endif //__COLLADA_MAYA_IMAGE_EXPORTER_H__
