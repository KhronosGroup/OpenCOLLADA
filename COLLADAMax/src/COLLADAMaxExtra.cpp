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

#include "COLLADAMaxExtra.h"



namespace COLLADAMax
{


    const String Extra::TECHNIQUE_PROFILE = "MAX3D";


    //---------------------------------------------------------------
    Extra::Extra ( COLLADA::StreamWriter * streamWriter )
            : COLLADA::ElementWriter ( streamWriter ),
            mExtra ( streamWriter ),
            mTechnique ( streamWriter )
    {}


    //---------------------------------------------------------------
    void Extra::openTechnique()
    {
        mExtra.openExtra();
        mTechnique.openTechnique ( TECHNIQUE_PROFILE );
    }

    //---------------------------------------------------------------
    void Extra::closeExtra()
    {
        mExtra.closeExtra();
    }
}
