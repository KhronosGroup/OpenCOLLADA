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
#include "COLLADALibraryImages.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    Image::Image ( const String& fileName, const String& imageId, const String& imageName )
            : BaseExtraTechnique(), mFileName ( fileName ),
            mImageId ( imageId ),
            mImageName ( imageName )
    {}


    //---------------------------------------------------------------
    LibraryImages::LibraryImages ( COLLADA::StreamWriter* streamWriter )
            : Library ( streamWriter,CSWC::COLLADA_ELEMENT_LIBRARY_IMAGES )
    {}


    //---------------------------------------------------------------
    void LibraryImages::addImage ( const Image& image )
    {
        openLibrary();
        mSW->openElement ( CSWC::COLLADA_ELEMENT_IMAGE );

        if ( !image.getImageId().empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, image.getImageId() );

        if ( !image.getImageName().empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, image.getImageName() );

        mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_INIT_FROM, image.getFileName() );

        image.addTextureExtraTechniques ( *mSW );

        mSW->closeElement();
    }


} //namespace COLLADA
