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


#ifndef __COLLADASTREAMWRITER_BIND_MATERIAL_H__
#define __COLLADASTREAMWRITER_BIND_MATERIAL_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include "COLLADAInstanceMaterial.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    /** A class to write a @a \<bind_material\> element*/
    class BindMaterial : public ElementWriter
    {

    private:

        /** Set this class a friend, so it can call the add() method.  */
        friend class InstanceGeometry;
        friend class InstanceController;

        /** Points to the currently opened material. */
        TagCloser mBindMaterialCloser;

        /** List of all the instance materials*/
        InstanceMaterialList mInstanceMaterialList;

    public:

        /**
         * Constructor
         * @param streamWriter The stream writer the @a \<bind_material\> element should be written to.
         */
        BindMaterial ( StreamWriter * streamWriter )
                : ElementWriter ( streamWriter ),
                mInstanceMaterialList ( streamWriter ) {}

        /**
         * Returns a reference to list of instance material objects. 
         * Use this together with InstanceMaterialList::push_back() to add instance materials.
         * @return InstanceMaterialList& Returns a reference to list of instance material objects. 
         */
        InstanceMaterialList& getInstanceMaterialList()
        {
            return mInstanceMaterialList;
        }

    private:

        /** Adds the BindMaterial to the stream*/
        void add();

    };

} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_BIND_MATERIAL_H__
