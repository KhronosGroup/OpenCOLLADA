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

#include "COLLADAInputList.h"
#include "COLLADASWC.h"


namespace COLLADA
{

    //---------------------------------------------------------------
    void InputList::add()
    {
        // write inputs
        for ( List::iterator it = mList.begin(); it != mList.end(); ++it )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_INPUT );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SEMANTIC, getSemanticString ( it->getSemantic() ) );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SOURCE, it->getSource() );

            if ( it->getOffset() >= 0 )
                mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_OFFSET, ( unsigned long ) it->getOffset() );

            if ( it->getSet() >= 0 )
                mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SET, ( unsigned long ) it->getSet() );

            mSW->closeElement();
        }

    }


    //---------------------------------------------------------------
    const String& InputList::getSemanticString ( Semantics semantic )
    {
        switch ( semantic )
        {

        case POSITION:
            return CSWC::COLLADA_SEMANTIC_POSITION;

        case VERTEX:
            return CSWC::COLLADA_SEMANTIC_VERTEX;

        case NORMAL:
            return CSWC::COLLADA_SEMANTIC_NORMAL;

        case TEXCOORD:
            return CSWC::COLLADA_SEMANTIC_TEXCOORD;

        case COLOR:
            return CSWC::COLLADA_SEMANTIC_COLOR;

        case JOINT:
            return CSWC::COLLADA_SEMANTIC_JOINT;

        case BINDMATRIX:
            return CSWC::COLLADA_SEMANTIC_BINDMATRIX;

        case WEIGHT:
            return CSWC::COLLADA_SEMANTIC_WEIGHT;

        default:
            return CSWC::EMPTY_STRING;
        }

    }


} //namespace COLLADA
