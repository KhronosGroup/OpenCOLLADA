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
#include "COLLADALibraryMaterials.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    const String LibraryMaterials::MATERIAL_ID_SUFFIX = "-material";


    //---------------------------------------------------------------
    LibraryMaterials::LibraryMaterials ( COLLADA::StreamWriter * streamWriter )
            : Library ( streamWriter,CSWC::COLLADA_ELEMENT_LIBRARY_MATERIALS )
    {}


    //---------------------------------------------------------------
    void LibraryMaterials::addInstanceEffect ( const String & effectURL, const String & materialId, const String & materialName )
    {
        openLibrary();
        mSW->openElement ( CSWC::COLLADA_ELEMENT_MATERIAL );

        if ( !materialId.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, materialId );

        if ( !materialName.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, materialName );

        mSW->openElement ( CSWC::COLLADA_ELEMENT_INSTANCE_EFFECT );

        if ( !effectURL.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_URL, effectURL );

        mSW->closeElement();

        mSW->closeElement();
    }


} //namespace COLLADA
