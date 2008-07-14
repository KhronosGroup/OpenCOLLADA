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


#ifndef __COLLADAMAX_GEOMETRIESEXPORTER_H__
#define __COLLADAMAX_GEOMETRIESEXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryGeometries.h"

#include "COLLADAMaxDocumentExporter.h"

namespace COLLADAMax
{

    class ExportSceneGraph;

    class ExportNode;

    /** Class to exports all nodes in an export scene graph.*/

    class GeometriesExporter : public COLLADA::LibraryGeometries
    {

    private:
        /** The export scene graph to export.*/
        ExportSceneGraph * mExportSceneGraph;

        /** The document exporter used to export the document.*/
        DocumentExporter * mDocumentExporter;

        /** Prefix of the symbol names.*/
        static const String SYMBOL_NAME_PREFIX;

    public:
        /** Constructor
        @param streamWriter The stream the animation should be written to
        @param exportSceneGraph The scene graph to export
        @param documentExporter The document exporter this exporter belongs to
        */
        GeometriesExporter ( COLLADA::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter );

        /** Exports all geometries in the export scene graph.*/
        void doExport();


    private:
        GeometriesExporter ( const GeometriesExporter & geometriesExporter );
        GeometriesExporter &operator= ( const GeometriesExporter & geometriesExporter );

        friend class GeometryExporter;

        /** Exports all the geometries in @a node and all its child nodes.*/
        void doExport ( ExportNode* exportNode );

    };

}

#endif //__COLLADAMAX_GEOMETRIESEXPORTER_H__




