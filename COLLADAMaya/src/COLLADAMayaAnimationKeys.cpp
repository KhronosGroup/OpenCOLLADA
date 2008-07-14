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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaAnimationKeys.h"


namespace COLLADAMaya
{

    // --------------------------------------------
    AnimationMKey::AnimationMKey ( uint _dimension )
            : dimension ( _dimension )
    {
        output = new float[dimension];
    }

    // --------------------------------------------
    AnimationMKey::~AnimationMKey()
    {
        delete output;
    }

    // --------------------------------------------
    AnimationMKeyBezier::AnimationMKeyBezier ( uint dimension )
            : AnimationMKey ( dimension )
    {
        inTangent = new TangentPoint[dimension];
        outTangent = new TangentPoint[dimension];
    }

    // --------------------------------------------
    AnimationMKeyBezier::~AnimationMKeyBezier()
    {
        delete[] inTangent;
        delete[] outTangent;
    }

    // --------------------------------------------
    AnimationMKeyTCB::AnimationMKeyTCB ( uint dimension )
            : AnimationMKey ( dimension )
    {
        tension = new float[dimension];
        continuity = new float[dimension];
        bias = new float[dimension];
        easeIn = new float[dimension];
        easeOut = new float[dimension];
    }

    // --------------------------------------------
    AnimationMKeyTCB::~AnimationMKeyTCB()
    {
        delete tension;
        delete continuity;
        delete bias;
        delete easeIn;
        delete easeOut;
    }
}