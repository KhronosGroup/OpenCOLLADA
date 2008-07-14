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

#ifndef __COLLADA_MAYA_DOCUMENT_NODE_H__
#define __COLLADA_MAYA_DOCUMENT_NODE_H__

#include <maya/MPxNode.h>

namespace COLLADAMaya
{
    /**
     * Class to represent the dae node for register on plugin.
     */

    class DocumentNode : public MPxNode
    {

    public:
        // DG attributes
        static MObject rootAttribute;
        static MObject filenameAttribute;
        static MObject entityIdAttribute;
        static MObject entityLinkAttribute;

    public:
        /** Constructor */
        DocumentNode();
        virtual ~DocumentNode();

        // Plug-in interface
        static void* creator();
        static MStatus initialize();
        static MTypeId id;

        // MPxNode interface.
        virtual Type type() const
        {
            return MPxNode::kDependNode;
        }

        /*
        // TODO
        // Document Management
        inline size_t GetDocumentCount() { return documents.size(); }
        inline DaeDoc* GetDocument(size_t index) { FUAssert(index < documents.size(), return NULL); return documents.at(index); }
        DaeDoc* FindDocument(uint logicalIndex);
        DaeDoc* FindDocument(const MString& filename);
        DaeDoc* FindDocument(FCDocument* colladaDocument);
        void ReleaseDocument(DaeDoc* document);
        void ReleaseAllEntityNodes();
        uint Synchronize();

        // Entites
        void LinkEntity(DaeDoc* document, DaeEntity* entity, MObject& node);
        DaeEntity* FindEntity(const MObject& node, DaeDoc** document=NULL);
        */
    };

}

#endif // __COLLADA_MAYA_DOCUMENT_NODE_H__

