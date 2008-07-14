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

#include "COLLADAStreamWriter.h"
#include "COLLADASource.h"
#include "COLLADABaseInputElement.h"
#include "COLLADAPrimitves.h"
#include "COLLADAUtils.h"

#include "COLLADAMaxGeometriesExporter.h"
#include "COLLADAMaxGeometryExporter.h"
#include "COLLADAMaxMaterialExporter.h"
#include "COLLADAMaxExportSceneGraph.h"



namespace COLLADAMax
{


    typedef std::vector<size_t> MaterialIDList;



    //---------------------------------------------------------------
    GeometriesExporter::GeometriesExporter ( COLLADA::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter )
            : COLLADA::LibraryGeometries ( streamWriter ),
            mExportSceneGraph ( exportSceneGraph ),
            mDocumentExporter ( documentExporter )
    {}


    //---------------------------------------------------------------
    void GeometriesExporter::doExport()
    {
        doExport ( mExportSceneGraph->getRootExportNode() );
        closeLibrary();
    }



    //---------------------------------------------------------------
    void GeometriesExporter::doExport ( ExportNode* exportNode )
    {
        GeometryExporter geometryExporter ( exportNode, this, mDocumentExporter );

        geometryExporter.doExport();


        //export the geometries of the child nodes
        size_t numberOfChildren = exportNode->getNumberOfChildren();

        for ( size_t i = 0; i < numberOfChildren; ++i )
            doExport ( exportNode->getChild ( i ) );

    }



}
