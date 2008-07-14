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


#include "COLLADAScene.h"
#include "COLLADASWC.h"

namespace COLLADA
{


    //---------------------------------------------------------------
    void Scene::add()
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_SCENE );
        mSW->openElement ( CSWC::COLLADA_ELEMENT_INSTANCE_VISUAL_SCENE );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_URL, mInstanceVisualSceneUrl );
        mSW->closeElement();
        mSW->closeElement();
    }

} //namespace COLLADA
