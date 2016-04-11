/*
    Copyright (c) 2015 Starbreeze AB

	This file is part of COLLADAMaya.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaSceneElement.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaLightProbeExporter.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{
    //---------------------------------------------------------------
    void InstanceLightProbe::add()
    {
        COLLADASW::Extra extra(mSW);
        COLLADASW::Technique technique(mSW);
        extra.openExtra();
        {
            technique.openTechnique(COLLADAMaya::PROFILE_MAYA);
            {
                mSW->openElement(COLLADAMaya::CSW_ELEMENT_INSTANCE_LIGHT_PROBE);
                {
                    mSW->appendURIAttribute(CSWC::CSW_ATTRIBUTE_URL, mUrl);
                }
                mSW->closeElement();
            }
            technique.closeTechnique();
        }
        extra.closeExtra();
    }

    // ---------------------------------------------------
    LightProbe::LightProbe ( 
        StreamWriter* streamWriter, 
        const String& lightProbeId, 
        const String& lightProbeName)
    : ElementWriter ( streamWriter )
    , BaseExtraTechnique ( )
    , mLightProbeId ( lightProbeId )
    , mLightProbeName ( lightProbeName )
    {}

    // ---------------------------------------------------
    void LightProbe::add () const
    {
        mSW->openElement ( COLLADAMaya::CSW_ELEMENT_LIGHT_PROBE );
        mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, getLightProbeId() );
        if ( !getLightProbeName().empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, getLightProbeName() );

        //mSW->openElement ( CSWC::CSW_ELEMENT_TECHNIQUE_COMMON );
        //mSW->closeElement(); // COLLADASW_ELEMENT_TECHNIQUE_COMMON
        addExtraTechniques ( mSW );

        mSW->closeElement(); // COLLADASW_ELEMENT_LIGHT_PROBE

    }

    //---------------------------------------------------------------
    LibraryLightProbes::LibraryLightProbes ( COLLADASW::StreamWriter* streamWriter )
    : Library ( streamWriter, COLLADAMaya::CSW_ELEMENT_LIBRARY_LIGHT_PROBES )
    , BaseExtraTechnique()
    {}


    //---------------------------------------------------------------
    void LibraryLightProbes::addLightProbe ( const LightProbe& lightProbe )
    {
        openExtraLibrary(COLLADAMaya::PROFILE_MAYA);
        lightProbe.add();
    }
}

namespace COLLADAMaya
{

    //---------------------------------------------------------------
    LightProbeExporter::LightProbeExporter ( 
        COLLADASW::StreamWriter* streamWriter,
        DocumentExporter* documentExporter )
    : COLLADASW::LibraryLightProbes ( streamWriter )
    , mDocumentExporter ( documentExporter )
    {}


    //---------------------------------------------------------------
    void LightProbeExporter::exportLightProbes ( )
    {
        //if ( !ExportOptions::exportLightProbes() ) return;

        // Get the list with the transform nodes.
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

        // Export all/selected DAG nodes
        size_t length = exportNodesTree->size();
        for ( uint i = 0; i < length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];
            exportLightProbes ( sceneElement );
        }

        closeExtraLibrary();
    }

    //---------------------------------------------------------------
    void LightProbeExporter::exportLightProbes ( SceneElement* sceneElement )
    {
        // If we have a external reference, we don't need to export the data here.
        if ( !sceneElement->getIsLocal() ) return;
        if ( !sceneElement->getIsExportNode () ) return;

        // Check if it is a light probe.
        SceneElement::Type sceneElementType = sceneElement->getType();
        if ( sceneElementType == SceneElement::LIGHT_PROBE )
        {
            // Get the current dag path
            MDagPath dagPath = sceneElement->getPath();

            // Check if the current scene element isn't already exported.
            SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
            if ( sceneGraph->findExportedElement ( dagPath ) ) return;

            // Check if the current element is an instance. 
            // We don't need to export instances, because we export the original instanced element.
            bool isInstance = ( dagPath.isInstanced() && dagPath.instanceNumber() > 0 );

            // If the original instanced element isn't already exported, we have to export it now.
            if ( isInstance )
            {
                // Get the original instanced element.
                MDagPath instancedPath;
                dagPath.getPath ( instancedPath, 0 );

                // Check if the original instanced element is already exported.
                SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
                SceneElement* exportedElement = sceneGraph->findExportedElement ( instancedPath );
				if (exportedElement == 0)
				{
					// Export the original instanced element and push it in the exported scene graph. 
					if (exportLightProbe(instancedPath))
					{
						SceneElement* instancedSceneElement = sceneGraph->findElement(instancedPath);
						SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
						sceneGraph->addExportedElement(instancedSceneElement);
					}
				}
            }
            else
            {
                // Export the element and push it in the exported scene graph. 
                if ( exportLightProbe ( dagPath ) )
                {
                    SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
                    sceneGraph->addExportedElement( sceneElement );
                }
            }
        }


        // Recursive call for all the child elements
        for ( uint i=0; i<sceneElement->getChildCount(); ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );
            exportLightProbes ( childElement );
        }
    }

    // ------------------------------------
    bool LightProbeExporter::exportLightProbe ( const MDagPath& dagPath )
    {
        //if ( !ExportOptions::exportLightProbes() ) return false;

        MObject lightProbeNode = dagPath.node();

        // Get the maya light probe id.
        String mayaLightProbeId = mDocumentExporter->dagPathToColladaId ( dagPath );

        // Generate a COLLADA id for the new object
        String colladaLightProbeId;
        
        // Check if there is an extra attribute "colladaId" and use this as export id.
        MString attributeValue;
        DagHelper::getPlugValue ( lightProbeNode, COLLADA_ID_ATTRIBUTE_NAME, attributeValue );
        if ( attributeValue != EMPTY_CSTRING )
        {
            // Generate a valid collada name, if necessary.
            colladaLightProbeId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false );
        }
        else
        {
            // Generate a COLLADA id for the new object
            colladaLightProbeId = mDocumentExporter->dagPathToColladaId ( dagPath );
        }
        // Make the id unique and store it in a map.
        colladaLightProbeId = mLightProbeIdList.addId ( colladaLightProbeId );
        mMayaIdColladaIdMap [ mayaLightProbeId ] = colladaLightProbeId;

        // Get a pointer to the stream writer.
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // The light name
        String lightProbeName = mDocumentExporter->dagPathToColladaName ( dagPath );

        // Create light probe
        COLLADASW::LightProbe* lightProbe = new COLLADASW::LightProbe( streamWriter, colladaLightProbeId, lightProbeName ); 

        // Export the original maya name.
        lightProbe->addExtraTechniqueParameter ( PROFILE_MAYA, PARAMETER_MAYA_ID, mayaLightProbeId );
        
        addLightProbe ( *lightProbe );
        delete lightProbe;

        return true;
    }

    // ------------------------------------
    const String LightProbeExporter::findColladaLightProbeId ( const String& mayaLightProbeId )
    {
        const StringToStringMap::const_iterator it = mMayaIdColladaIdMap.find ( mayaLightProbeId );
        if ( it != mMayaIdColladaIdMap.end () )
        {
            return it->second;
        }
        return EMPTY_STRING;
    }

}