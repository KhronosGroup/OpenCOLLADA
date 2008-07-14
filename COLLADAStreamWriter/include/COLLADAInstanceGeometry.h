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


#ifndef __COLLADASTREAMWRITER_INSTANCE_GEOMETRY_H__
#define __COLLADASTREAMWRITER_INSTANCE_GEOMETRY_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include "COLLADABindMaterial.h"

#include <string>

namespace COLLADA
{

    /** Class to write an @a \<instance_geometry\> element to the stream*/
	class InstanceGeometry : public ElementWriter
    {

    private:

        /** To bind the materials. */
        BindMaterial mBindMaterial;

        /** The URL of the location of the object to instantiate.*/
        String mUrl;

    public:

		/** Constructor
		@param The stream the instance geometry should be written to
		*/
		InstanceGeometry ( StreamWriter * streamWriter ) 
            : ElementWriter ( streamWriter ), mBindMaterial ( streamWriter ) {}

		/** Destructor*/
		~InstanceGeometry(){}

        /** Sets the url of the instance geometry*/
        void setUrl ( const String url )
        {
            mUrl=url;
        }

        /** Returns the url of the instance geometry*/
        const String& getUrl()
        {
            return mUrl;
        }

        BindMaterial& getBindMaterial()
        {
            return mBindMaterial;
        }

        /** Adds the instance geometry to the stream*/
        void add();

    };


} //namespace COLLADA




#endif //__COLLADASTREAMWRITER_INSTANCE_GEOMETRY_H__

