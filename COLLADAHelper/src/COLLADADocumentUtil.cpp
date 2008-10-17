#include "HelperStableHeaders.h"
#include "COLLADADocumentUtil.h"

namespace COLLADA {

    //-----------------------------------------------------------------------
    domFloat DocumentUtil::getUnitMeter( daeDocument* doc, domFloat defaultUnitMeter )
    {
        domCOLLADA* root = daeSafeCast<domCOLLADA>(doc->getDomRoot());
        const domAssetRef asset = root->getAsset();
        if(asset == 0)
            return defaultUnitMeter;

        domAsset::domUnitRef unit = asset->getUnit();
        if(unit == 0)
            return defaultUnitMeter;

        return unit->getMeter();
    }

	//-----------------------------------------------------------------------
	daeInt DocumentUtil::createNewDocument( DAE* data, const std::string& id, daeDocument** document )
	{
		daeURI daeDocUri(*data, cdom::filePathToUri(id).c_str());
		daeDocUri.setURI(cdom::filePathToUri(id).c_str());
		daeInt result = data->getDatabase()->createDocument(daeDocUri.getURI(), document);
		return result;
	}
	//-----------------------------------------------------------------------
	void DocumentUtil::loadReferencedDocuments( daeDocument* doc )
	{
		ReferencedDocumentsLoader loader;
		loader.load(doc);
	}
	//-----------------------------------------------------------------------
	domUpAxisType DocumentUtil::getUpAxis( daeDocument* doc )
	{
		domCOLLADA* root = daeSafeCast<domCOLLADA>(doc->getDomRoot());
		const domAssetRef asset = root->getAsset();
		if(asset == 0)
			return UPAXISTYPE_Z_UP;

		domAsset::domUp_axisRef upaxis = asset->getUp_axis();
		if(upaxis == 0)
			return UPAXISTYPE_Z_UP;

		return upaxis->getValue();
	}
	//-----------------------------------------------------------------------
	ReferencedDocumentsLoader::ReferencedDocumentsLoader( void )
	{

	}

	//-----------------------------------------------------------------------
	ReferencedDocumentsLoader::~ReferencedDocumentsLoader( void )
	{

	}

	//-----------------------------------------------------------------------
	void ReferencedDocumentsLoader::load( daeDocument* doc )
	{
		domCOLLADA::domSceneRef scene = daeSafeCast<domCOLLADA>(doc->getDomRoot())->getScene();
		COLLADA::NodeTraverser traverser(*scene);
		traverser.traverse(*this);
	}

	bool ReferencedDocumentsLoader::preDetectedNode( domNode& node, int level )
	{
		return true;
	}

	bool ReferencedDocumentsLoader::postDetectedNode( domNode& node, int level )
	{
		return true;
	}

	bool ReferencedDocumentsLoader::detectedInstanceNode( domInstance_node& instance, int level )
	{
		domNodeRef node = daeSafeCast<domNode>(instance.getUrl().getElement());

		COLLADA::NodeTraverser traverser(*node);
		traverser.traverse(*this, level);

		return true;
	}

	bool ReferencedDocumentsLoader::detectedInstanceGeometry( domInstance_geometry& instance, int level )
	{		
		domGeometryRef node = daeSafeCast<domGeometry>(instance.getUrl().getElement());

		return true;
	}

	bool ReferencedDocumentsLoader::detectedInstanceLight( domInstance_light& instance, int level )
	{
		return true;
	}

	bool ReferencedDocumentsLoader::detectedInstanceCamera( domInstance_camera& instance, int level )
	{
		return true;
	}

	bool ReferencedDocumentsLoader::detectedNodeExtra( domExtra& extra, int level )
	{
		return true;
	}
}
