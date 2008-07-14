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

#ifndef __COLLADA_MAYA_ANIMATION_CLIP_EXPORTER_H__
#define __COLLADA_MAYA_ANIMATION_CLIP_EXPORTER_H__

#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaAnimationTools.h"

#include "COLLADALibraryAnimationClips.h"


namespace COLLADAMaya
{

    // ----------------------------------------------------------
    /**
    * Class to export the animation clips.
    */

    class AnimationClipExporter : public COLLADA::LibraryAnimationClips
    {

    public:

        /** Constructor */
        AnimationClipExporter ( COLLADA::StreamWriter* _streamWriter );
        virtual ~AnimationClipExporter() {};

        /** Exports all animation clips from the member animation list. */
        void exportAnimationClips ( const AnimationClipList* animationClips );
    };
}


#endif // __COLLADA_MAYA_ANIMATION_CLIP_EXPORTER_H__
