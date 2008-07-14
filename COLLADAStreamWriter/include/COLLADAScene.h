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


#ifndef __COLLADASTREAMWRITER_SCENE_H__
#define __COLLADASTREAMWRITER_SCENE_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include <string>

namespace COLLADA
{


    /** A class to add a @a \<scene\> element to the stream*/

    class Scene : public ElementWriter
    {

    public:
        /** Constructor that sets the stream the scene should be written to*/
        Scene ( StreamWriter * streamWriter ) : ElementWriter ( streamWriter ) {}

        /** Adds the scene to the stream, i.e. performes the actual writing*/
        void add();


        /** The url of the instance visual scene.*/
        String mInstanceVisualSceneUrl;
    };

} //namespace COLLADA



#endif //__COLLADASTREAMWRITER_SCENE_H__
