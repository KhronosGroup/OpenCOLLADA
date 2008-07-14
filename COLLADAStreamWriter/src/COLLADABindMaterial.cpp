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


#include "COLLADABindMaterial.h"
#include "COLLADAInstanceMaterial.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    void BindMaterial::add()
    {
        if ( !mInstanceMaterialList.empty() )
        {
            mBindMaterialCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_BIND_MATERIAL );
            mSW->openElement ( CSWC::COLLADA_ELEMENT_TECHNIQUE_COMMON );

            mInstanceMaterialList.add();

            mBindMaterialCloser.close();
        }
    }


} //namespace COLLADA
