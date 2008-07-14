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


#ifndef __COLLADASTREAMWRITER_LIBRARY_IMAGES_H__
#define __COLLADASTREAMWRITER_LIBRARY_IMAGES_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAExtraTechnique.h"
#include "COLLADALibrary.h"

namespace COLLADA
{
    /** A class that hold all information about an @a \<image\> element.*/

    class Image : public BaseExtraTechnique
    {

    public:
        /** Constructor
        @param fileName The file name of the image.
        @param imageId The id of the image.
        @param imageName The name of the image.
        */
        Image ( const String& fileName,
                const String& imageId,
                const String& imageName = ElementWriter::EMPTY_STRING );

        /** Destructor*/
        virtual ~Image() {}

        /** Returns a reference to the file name*/
        const String& getFileName() const
        {
            return mFileName;
        }

        /** Returns a reference to the image id*/
        const String& getImageId() const
        {
            return mImageId;
        }

        /** Returns a reference to the image name*/
        const String& getImageName() const
        {
            return mImageName;
        }

    private:
        /** The file name of the image.*/
        String mFileName;

        /** The id of the image.*/
        String mImageId;

        /** The name of the image.*/
        String mImageName;
    };


    /** Class to simply the creation of @a \<library_images\> and @a \<images\>'s*/

    class LibraryImages : public Library
    {

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_images\> and @a \<images\>'s
        should be written to.
        */
        LibraryImages ( StreamWriter* streamWriter );

        /** Destructor*/
        virtual ~LibraryImages() {}

    protected:
        /** Adds @a \<image\> element. If not already opened, it opens @a \<library_images\>*/
        void addImage ( const Image& image );

    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_LIBRARY_IMAGES_H__