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
#include "COLLADALibraryAnimationClips.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    ColladaAnimationClip::ColladaAnimationClip ( const String& animationClipId )
            : mAnimationClipId ( animationClipId ), mStartTime ( -1.0f ), mEndTime ( -1.0f )
    {}

    //---------------------------------------------------------------
    ColladaAnimationClip::ColladaAnimationClip ( const String& animationClipId, float &startTime, float &endTime )
            : mAnimationClipId ( animationClipId ), mStartTime ( startTime ), mEndTime ( endTime )
    {}

    //---------------------------------------------------------------
    ColladaAnimationClip::ColladaAnimationClip ( float &startTime, float &endTime )
            : mAnimationClipId ( ElementWriter::EMPTY_STRING ), mStartTime ( startTime ), mEndTime ( endTime )
    {}

    //---------------------------------------------------------------
    LibraryAnimationClips::LibraryAnimationClips ( COLLADA::StreamWriter* streamWriter )
            : Library ( streamWriter, CSWC::COLLADA_ELEMENT_LIBRARY_ANIMATION_CLIPS )
    {}


    //---------------------------------------------------------------
    void LibraryAnimationClips::addAnimationClip ( const ColladaAnimationClip& animationClip )
    {
        // Opens the library, if it is not already open.
        openLibrary();
        mSW->openElement ( CSWC::COLLADA_ELEMENT_ANIMATION_CLIP );

        if ( !animationClip.getAnimationClipId().empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, animationClip.getAnimationClipId() );

        if ( animationClip.getStartTime() != ( -1.0f ) )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_START, animationClip.getStartTime() );

        if ( animationClip.getEndTime() != ( -1.0f ) )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_END, animationClip.getEndTime() );

        const AnimationInstances instancedAnimations = animationClip.getInstancedAnimations();

        AnimationInstances::const_iterator instancedAnimationsIter = instancedAnimations.begin();

        for ( ; instancedAnimationsIter != instancedAnimations.end(); ++instancedAnimationsIter )
        {
            String instanceName = *instancedAnimationsIter;
            mSW->openElement ( CSWC::COLLADA_ELEMENT_INSTANCE_ANIMATION );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_URL, "#" + instanceName );
            mSW->closeElement();
        }

        mSW->closeElement();
    }


} //namespace COLLADA
