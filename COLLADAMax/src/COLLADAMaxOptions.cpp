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


#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxOptions.h"

namespace COLLADAMax
{


    Options::Options()
    {

        mNormals = true;
        mTriangulate = false;
        mXrefs = false;
        mTangents = false;
        mAnimations = false;
        mSampleAnimation = false;
        mCreateClip = false;
        mBakeMatrices = false;
        mRelativePaths = true;
        mSelectionOnly = false;

        mAnimationStart = TIME_INITIAL_POSE;
        mAnimationEnd = TIME_PosInfinity;

    }



}
