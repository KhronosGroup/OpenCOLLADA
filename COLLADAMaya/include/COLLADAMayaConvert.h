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

/*
* Interfaces between the collada classes and the Maya compatible structures
*/

#ifndef __COLLADA_MAYA_CONVERT_H__
#define __COLLADA_MAYA_CONVERT_H__

#ifndef _MFnAnimCurve
#include <maya/MFnAnimCurve.h>
#endif // _MFnAnimCurve

#include "ColladaMayaPrerequisites.h"
#include <COLLADAMayaPlatform.h>

namespace COLLADAMaya
{

    namespace MConvert
    {
        // Fills the two dimensional array @a copy with the values contained in @a original
        void convertMMatrixToDouble4x4 ( double copy[][4], const MMatrix& original );

        const char* toChar ( const MString& m );
    }
}

#endif // __COLLADA_MAYA_CONVERT_H__
