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
#include "COLLADAMayaConvert.h"
#include "COLLADAMathUtils.h"

namespace COLLADAMaya
{

    namespace MConvert
    {
        //---------------------------------------------------------------
        void convertMMatrixToDouble4x4 ( double copy[][4], const MMatrix& original )
        {
            if (COLLADA::MathUtils::equalsZero(original[0][0])) copy[0][0] = 0.0;
            else copy[0][0] = original[0][0];
            if (COLLADA::MathUtils::equalsZero(original[0][1])) copy[1][0] = 0.0;
            else copy[1][0] = original[0][1];
            if (COLLADA::MathUtils::equalsZero(original[0][2])) copy[2][0] = 0.0;
            else copy[2][0] = original[0][2];
            copy[3][0] = 0;

            if (COLLADA::MathUtils::equalsZero(original[1][0])) copy[0][1] = 0.0;
            else copy[0][1] = original[1][0];
            if (COLLADA::MathUtils::equalsZero(original[1][1])) copy[1][1] = 0.0;
            else copy[1][1] = original[1][1];
            if (COLLADA::MathUtils::equalsZero(original[1][2])) copy[2][1] = 0.0;
            else copy[2][1] = original[1][2];
            copy[3][1] = 0;

            if (COLLADA::MathUtils::equalsZero(original[2][0])) copy[0][2] = 0.0;
            else copy[0][2] = original[2][0];
            if (COLLADA::MathUtils::equalsZero(original[2][1])) copy[1][2] = 0.0;
            else copy[1][2] = original[2][1];
            if (COLLADA::MathUtils::equalsZero(original[2][2])) copy[2][2] = 0.0;
            else copy[2][2] = original[2][2];
            copy[3][2] = 0;

            if (COLLADA::MathUtils::equalsZero(original[3][0])) copy[0][3] = 0.0;
            else copy[0][3] = original[3][0];
            if (COLLADA::MathUtils::equalsZero(original[3][1])) copy[1][3] = 0.0;
            else copy[1][3] = original[3][1];
            if (COLLADA::MathUtils::equalsZero(original[3][2])) copy[2][3] = 0.0;
            else copy[2][3] = original[3][2];
            copy[3][3] = 1;
        }

        //---------------------------------------------------------------
        const char* toChar ( const MString& m )
        {
#if MAYA_API_VERSION >= 850
            return ( char* ) m.asWChar();
#else // MAYA_API_VERSION >= 850
            return m.asChar();
#endif // MAYA_API_VERSION >= 850
        }
    }

}