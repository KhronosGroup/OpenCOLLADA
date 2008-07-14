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

#include "COLLADAInstanceGeometry.h"


namespace COLLADA
{

    //---------------------------------------------------------------
    void InstanceGeometry::add()
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_INSTANCE_GEOMETRY );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_URL, mUrl );

        mBindMaterial.add();

        mSW->closeElement();
    }



} //namespace COLLADA
