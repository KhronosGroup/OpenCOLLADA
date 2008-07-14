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


#include "COLLADAExtra.h"
#include "COLLADASWC.h"

namespace COLLADA
{
    //---------------------------------------------------------------
    void Extra::openExtra ( const String &extraId, const String &extraName, const String &extraType )
    {
        mExtraCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_EXTRA );

        if ( !extraId.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, extraId );

        if ( !extraName.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, extraName );

        if ( !extraType.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_TYPE, extraType );
    }

    //---------------------------------------------------------------
    void Extra::closeExtra()
    {
        mExtraCloser.close();
    }

} //namespace COLLADA
