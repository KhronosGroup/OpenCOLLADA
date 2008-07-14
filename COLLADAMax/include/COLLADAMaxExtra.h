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


#ifndef __COLLADAMAX_EXTRA_H__
#define __COLLADAMAX_EXTRA_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAStreamWriter.h"
#include "COLLADAExtraTechnique.h"
#include "COLLADAExtra.h"


class Object;

namespace COLLADAMax
{
    /** Base class to export extra tags in max.*/

    class Extra : public COLLADA::ElementWriter
    {

    public:
        /** The technique profile name.*/
        static const String TECHNIQUE_PROFILE;

    private:
        COLLADA::Extra mExtra;
        COLLADA::Technique mTechnique;

    public:
        /** Constructor
         @param streamWriter the stream the extra tags should be written to.*/
        Extra ( COLLADA::StreamWriter * streamWriter );

        /** Destructor*/
        virtual ~Extra()
        {}


    protected:
        /** Opens a new @a  \<technique\> element.*/
        void openTechnique();

        /** closes the extra tag*/
        void closeExtra();

        /** Adds a parameter to the technique. */

        template <class T>
        void addParameter ( const String &paramName, const T &value )
        {
            mTechnique.addParameter ( paramName, value );
        }


    };


}


#endif //__COLLADAMAX_EXTRA_H__

