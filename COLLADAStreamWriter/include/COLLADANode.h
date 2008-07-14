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


#ifndef __COLLADASTREAMWRITER_NODE_H__
#define __COLLADASTREAMWRITER_NODE_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include "COLLADAExtraTechnique.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    /** A class to write a @a \<node\> element to the stream.*/

    class Node : public ElementWriter, public BaseExtraTechnique
    {

    public:
        Node ( StreamWriter* streamWriter )
                : ElementWriter ( streamWriter ),
                mType ( DEFAULT ),
                mNodeId ( "" ),
                mNodeName ( "" )
        {}

        /** The node types*/
        enum Type
        {
            DEFAULT,
            NODE,
            JOINT // Joints are called bones in 3dsMax. A joint is a scene node that is used in skinning.
        };

        /** Returns a reference to the id of the node*/
        const String& getId() const
        {
            return mNodeId;
        }

        /** Sets the id of the node*/
        void setId ( const String& id )
        {
            mNodeId = id;
        }

        /** Returns a reference to the name of the node*/
        const String& getNodeName() const
        {
            return mNodeName;
        }

        /** Sets the name of the node*/
        void setNodeName ( const String& nodeName )
        {
            mNodeName = nodeName;
        }

        /** Returns the type of the node*/
        Type getType() const
        {
            return mType;
        }

        /** Sets the type of the node*/
        void setType ( Type type )
        {
            mType = type;
        }

        /** Opens the node
        It should be closed using close()*/
        void start();

        /** Adds a translation with sid @a sid*/
        void addTranslate ( const String& sid, double x, double y, double z ) const ;

        /** Adds a translation*/
        void addTranslate ( double x, double y, double z ) const ;

        /** Adds a rotation with sid @a sid*/
        void addRotate ( const String& sid, double x, double y, double z, double angle ) const ;

        /** Adds a rotation around the x-axis with sid @a sid */
        void addRotateX ( const String& sid, double angle ) const
        {
            addRotate ( sid, 1, 0, 0, angle );
        }

        /** Adds a rotation around the y-axis with sid @a sid */
        void addRotateY ( const String& sid, double angle )  const
        {
            addRotate ( sid, 0, 1, 0, angle );
        }

        /** Adds a rotation around the Z-axis with sid @a sid */
        void addRotateZ ( const String& sid, double angle ) const
        {
            addRotate ( sid, 0, 0, 1, angle );
        }

        /** Adds a rotation*/
        void addRotate ( double x, double y, double z, double angle ) const ;

        /** Adds a matrix with sid @a sid*/
        void addMatrix ( const String& sid, double matrix[4][4] ) const ;

        /** Adds a matrix*/
        void addMatrix ( double matrix[4][4] ) const ;

        /** Adds a scale with sid @a sid*/
        void addScale ( const String& sid, double x, double y, double z )  const;

        /** Adds a scale*/
        void addScale ( double x, double y, double z ) const;

        /** Adds the skew of the current mesh element. */
        void addSkew ( const String& sid, const float angle,
                       const float rotateAxis[3], const float aroundAxis[3] ) const;

        /** Closes the node
        It must have been opened using open()*/
        void end() ;

    private:
        /** Closer to close the node*/
        TagCloser mNodeCloser;

        /** The id of the node*/
        String mNodeId;

        /** The name of the node*/
        String mNodeName;

        /** The type of the node*/
        Type mType;

    };


} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_NODE_H__
