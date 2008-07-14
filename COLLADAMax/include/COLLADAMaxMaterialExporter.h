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


#ifndef __COLLADAMAX_MATERIAL_EXPORTER_H__
#define __COLLADAMAX_MATERIAL_EXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryMaterials.h"

#include "COLLADAMaxDocumentExporter.h"
#include "COLLADAMaxEffectExporter.h"
#include "COLLADAMaxTypes.h"

namespace COLLADAMax
{

    class ExportSceneGraph;

    class ExportNode;

    /** This class writes the @a \<library_materials\>. It uses informations created my an effect exporter*/

    class MaterialExporter : public COLLADA::LibraryMaterials
    {

    private:
        /** maps already exported wire frame colors to the corresponding COLLADA effect id*/
        const WireFrameColorEffectList * mWireFrameColorEffectList;

        /** The document exporter*/
        DocumentExporter * mDocumentExporter;

        /** List of the the ids used by all of the effects*/
        ExportedEffectIdList mExportedEffectIdList;

    public:
        /**
        @param streamWriter The stream the output will be written to.
        @param documentExporter The document exporter this material exporter is used in.*/
        MaterialExporter ( COLLADA::StreamWriter * streamWriter, DocumentExporter * documentExporter );

        /** Destructor*/
        virtual ~MaterialExporter()
        {}


        /** Export the library materials.*/
        void doExport();

        /** Creates an id that should be used as id for a material that instantiates the effect that has id @a id.*/
        static String getMaterialIdFromEffectId ( const String & effectId );

        /** Returns a pointer to the material with matID @a materialId.*/
        static Mtl* GetSubMaterialById ( Mtl* mtl, int materialId );

        /** Returns a reference to the Effect ID list.*/
        ExportedEffectIdList & getEffectIdList()
        {
            return mExportedEffectIdList;
        }

    private:
        MaterialExporter ( const MaterialExporter & materialExporter );
        MaterialExporter & operator= ( const MaterialExporter & materialExporter );

    };

}

#endif //__COLLADAMAX_MATERIAL_EXPORTER_H__
