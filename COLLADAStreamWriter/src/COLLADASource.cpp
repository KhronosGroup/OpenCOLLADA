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


#include "COLLADASource.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    void SourceBase::prepareBaseToAppendValues ( const String *arrayName )
    {
        mSourceCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_SOURCE );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, mNodeId );
        mSW->openElement ( *arrayName );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, mArrayId );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_COUNT, mAccessorCount * mAccessorStride );
    }

    //---------------------------------------------------------------
    void SourceBase::finishBase ( const String* parameterTypeName, bool closeSourceElement )
    {
        closeArray();

        addBaseTechnique ( parameterTypeName );

        if ( closeSourceElement ) closeSource();
    }

    //---------------------------------------------------------------
    void SourceBase::closeArray()
    {
        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void SourceBase::closeSource()
    {
        mSourceCloser.close();
    }

    //---------------------------------------------------------------
    void SourceBase::addBaseTechnique ( const String* parameterTypeName )
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_TECHNIQUE_COMMON );
        mSW->openElement ( CSWC::COLLADA_ELEMENT_ACCESSOR );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SOURCE, "#" + mArrayId );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_COUNT, mAccessorCount );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_STRIDE, mAccessorStride );

        for ( ParameterNameList::iterator it = mParameterNameList.begin(); it != mParameterNameList.end(); ++it )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_PARAM );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, *it );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_TYPE, *parameterTypeName );
            mSW->closeElement();
        }

        mSW->closeElement();

        mSW->closeElement();
    }


} //namespace COLLADA
