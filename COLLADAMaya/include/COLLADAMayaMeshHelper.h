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

#ifndef __COLLADA_MAYA_MESH_HELPER_H__
#define __COLLADA_MAYA_MESH_HELPER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADASource.h"

#include <maya/MPlug.h>
#include <maya/MIntArray.h>

namespace COLLADAMaya
{

    struct ColourSet
    {
        MString name;
        MObject polyColorPerVertexNode;
        MPlug arrayPlug;
        MIntArray indices;
        bool isBlankSet;
        bool isVertexColor;
        int whiteColorIndex;
    };

    typedef std::vector<ColourSet*> ColourSetList;

    class MeshHelper
    {

    public:
        /** Find all the history nodes of a specific type */
        static void getHistoryNodes ( const MObject& mesh, MFn::Type nodeType, MObjectArray& historyNodes );

        /** Get the mesh's color sets information (Maya 7.0+) */
        static void getMeshValidColorSets ( const MObject& mesh, ColourSetList& colorSets );

    private:

        /** Don't create an object of this class. */
        MeshHelper() {};

    };
}

#endif // __COLLADA_MAYA_MESH_HELPER_H__
