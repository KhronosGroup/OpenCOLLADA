/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaAttributeParser.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaLightExporter.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaAnimationExporter.h"

#include <maya/MFnAttribute.h>
#include <maya/MFnLight.h>
#include <maya/MFnNonAmbientLight.h>
#include <maya/MFnAmbientLight.h>
#include <maya/MFnSpotLight.h>


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    LightExporter::LightExporter ( 
        COLLADASW::StreamWriter* streamWriter,
        DocumentExporter* documentExporter )
    : COLLADASW::LibraryLights ( streamWriter )
    , mDocumentExporter ( documentExporter )
    {}


    //---------------------------------------------------------------
    void LightExporter::exportLights ( )
    {
        if ( !ExportOptions::exportLights() ) return;

        // Get the list with the transform nodes.
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

        // Export all/selected DAG nodes
        size_t length = exportNodesTree->size();
        for ( uint i = 0; i < length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];
            exportLights ( sceneElement );
        }

        closeLibrary();
    }

    //---------------------------------------------------------------
    void LightExporter::exportLights ( SceneElement* sceneElement )
    {
        // If we have a external reference, we don't need to export the data here.
        if ( !sceneElement->getIsLocal() ) return;
        if ( !sceneElement->getIsExportNode () ) return;

        // Check if it is a light.
        SceneElement::Type sceneElementType = sceneElement->getType();
        if ( sceneElementType == SceneElement::LIGHT )
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
					if (exportLight(instancedPath))
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
                if ( exportLight ( dagPath ) )
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
            exportLights ( childElement );
        }
    }

    // ------------------------------------
    bool LightExporter::exportLight ( const MDagPath& dagPath )
    {
        if ( !ExportOptions::exportLights() ) return false;

        MObject lightNode = dagPath.node();

        // Retrieve the Maya light object
        MStatus status;
        MFnLight lightFn(lightNode, &status); CHECK_STAT(status);
        if (status != MStatus::kSuccess) return false;

        // Get the maya light id.
        String mayaLightId = mDocumentExporter->dagPathToColladaId ( dagPath );

        // Generate a COLLADA id for the new object
        String colladaLightId;
        
        // Check if there is an extra attribute "colladaId" and use this as export id.
        MString attributeValue;
        DagHelper::getPlugValue ( lightNode, COLLADA_ID_ATTRIBUTE_NAME, attributeValue );
        if ( attributeValue != EMPTY_CSTRING )
        {
            // Generate a valid collada name, if necessary.
            colladaLightId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false );
        }
        else
        {
            // Generate a COLLADA id for the new object
            colladaLightId = mDocumentExporter->dagPathToColladaId ( dagPath );
        }
        // Make the id unique and store it in a map.
        colladaLightId = mLightIdList.addId ( colladaLightId );
        mMayaIdColladaIdMap [ mayaLightId ] = colladaLightId;

        // Get a pointer to the stream writer.
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // The light name
        String lightName = mDocumentExporter->dagPathToColladaName ( dagPath );

        // Figure out the type of light and create it
        COLLADASW::Light* light = NULL;
        MFn::Type type = lightNode.apiType();
        switch (type)
        {
        case MFn::kAmbientLight: 
            light = new COLLADASW::AmbientLight( streamWriter, colladaLightId, lightName ); 
            break; 
        case MFn::kDirectionalLight: 
            light = new COLLADASW::DirectionalLight( streamWriter, colladaLightId, lightName ); 
            break;
        case MFn::kSpotLight: 
            light = new COLLADASW::SpotLight( streamWriter, colladaLightId, lightName ); 
            break;
        case MFn::kPointLight: // Intentional pass-through
        default: 
            light = new COLLADASW::PointLight( streamWriter, colladaLightId, lightName ); 
            break;
        }

        // Export the original maya name.
        light->addExtraTechniqueParameter ( PROFILE_MAYA, PARAMETER_MAYA_ID, mayaLightId );

        // Get a pointer to the animation exporter.
        AnimationExporter* anim = mDocumentExporter->getAnimationExporter();
        bool animated = false;
        
        // Color/Intensity are the common attributes of all lights
        MColor mayaColor = lightFn.color ( &status ); CHECK_STAT(status);
        COLLADASW::Color lightColor ( mayaColor.r, mayaColor.g, mayaColor.b, mayaColor.a );
        animated = anim->addNodeAnimation ( lightNode, ATTR_COLOR, kColour, RGBA_PARAMETERS );
        light->setColor( lightColor, animated );

        float intensity = lightFn.intensity ( &status ); CHECK_STAT(status);
        animated = anim->addNodeAnimation ( lightNode, ATTR_INTENSITY, kSingle );
        light->setIntensity( intensity, animated );
		
		// Export light intensity
		light->addExtraTechniqueParameter(PROFILE_MAYA, ATTR_INTENSITY, intensity);


        // Add the type specific attributes
        if (lightNode.hasFn(MFn::kNonAmbientLight))
        {
            // Needed Point and Spot light types parameters: Attenuation and Attenuation_Scale
            // Attenuation in COLLADA is equal to Decay in Maya.
            MFnNonAmbientLight naLightFn(lightNode);
            int decayRate = naLightFn.decayRate(&status); CHECK_STAT(status);
            decayRate = std::min ( decayRate, 2 ); 
            decayRate = std::max ( decayRate, 0 );

            light->setConstantAttenuation ( ( decayRate == 0 ) ? 1.0f : 0.0f);
            light->setLinearAttenuation ( ( decayRate == 1 ) ? 1.0f : 0.0f);
            light->setQuadraticAttenuation ( ( decayRate == 2 ) ? 1.0f : 0.0f);
        }
        else if (lightNode.hasFn(MFn::kAmbientLight))
        {
            MFnAmbientLight ambientLightFn ( lightNode );
            float ambientShade = ambientLightFn.ambientShade();
            String paramSid = EMPTY_STRING;
            animated = anim->addNodeAnimation ( lightNode, ATTR_AMBIENT_SHADE, kSingle );
            if ( animated ) paramSid = ATTR_AMBIENT_SHADE;
            light->addExtraTechniqueParameter ( PROFILE_MAYA, MAYA_AMBIENTSHADE_LIGHT_PARAMETER, ambientShade, paramSid );
        }

        if (lightNode.hasFn(MFn::kSpotLight))
        {
            // Put in the needed spot light type attributes : Falloff, Falloff_Scale and Angle
            MFnSpotLight spotFn(lightNode);

            float fallOffAngle = COLLADABU::Math::Utils::radToDegF ( (float)spotFn.coneAngle( &status ) ); CHECK_STAT(status);
            animated = anim->addNodeAnimation ( lightNode, ATTR_CONE_ANGLE, ( SampleType ) ( kSingle | kAngle ) );
            light->setFallOffAngle ( fallOffAngle, animated );

            light->setFallOffExponent ( 1.0f );

            float penumbraValue = COLLADABU::Math::Utils::radToDegF ( (float)spotFn.penumbraAngle( &status ) ); CHECK_STAT(status);
            animated = anim->addNodeAnimation ( lightNode, ATTR_PENUMBRA_ANGLE, ( SampleType ) ( kSingle | kAngle ) );


			// Export spot setting
			float dropOff = (float)spotFn.dropOff(&status); CHECK_STAT(status);
			light->addExtraTechniqueParameter(PROFILE_MAYA, MAYA_PENUMBRA_LIGHT_PARAMETER, penumbraValue);
			light->addExtraTechniqueParameter(PROFILE_MAYA, MAYA_DROPOFF_LIGHT_PARAMETER, dropOff);


			// TODO
//            FCDLightTools::LoadPenumbra(light, penumbraValue, colladaLight->GetOuterAngle().GetAnimated());

            // TODO
//             animated = anim->addNodeAnimation ( lightNode, ATTR_DROP_OFF, kSingle );
//             light->setDropOff ( (float) spotFn.dropOff ( &status ), animated ); CHECK_MSTATUS(status);
        }
        
        SceneElement* sceneElement = NULL;
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        sceneElement = sceneGraph->findElement(dagPath);
        exportExtraAttributes(sceneElement, light);

        addLight ( *light );
        delete light;

        return true;
    }

    //---------------------------------------------------------------
    void LightExporter::exportExtraAttributes(const SceneElement* sceneElement, COLLADASW::Light* light)
    {
        class ExtraAttributeExporter : public AttributeParser
        {
        public:
            ExtraAttributeExporter(COLLADASW::Light& light)
                : mLight(light)
            {}

        private:
            COLLADASW::Light& mLight;

        protected:
			virtual bool onBeforePlug(MPlug & plug) override
			{
				MStatus status;

				MObject attr = plug.attribute(&status);
				if (!status) return false;

                MFnAttribute fnAttr(attr, &status);
                if (!status) return false;

                MString attrName = fnAttr.name(&status);
                if (!status) return false;

                bool isDynamic = fnAttr.isDynamic(&status);
                if (!status) return false;

                if (!isDynamic)
                    return false;

                bool isHidden = fnAttr.isHidden(&status);
                if (!status) return false;

                if (isHidden)
                    return false;

                return true;
            }

            virtual void onBoolean(MPlug & plug, const MString & name, bool value) override
            {
				mLight.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value, "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
            }

            virtual void onInteger(MPlug & plug, const MString & name, int value) override
            {
				mLight.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value, "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
            }

            virtual void onInteger2(MPlug & plug, const MString & name, int value[2]) override
            {
				mLight.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value[0], value[1], "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
            }

            virtual void onInteger3(MPlug & plug, const MString & name, int value[3]) override
            {
				mLight.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value[0], value[1], value[2], "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
            }

            virtual void onFloat(MPlug & plug, const MString & name, float value) override
            {
				mLight.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value, "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
            }

            virtual void onFloat2(MPlug & plug, const MString & name, float value[2]) override
            {
				mLight.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value[0], value[1], "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
            }

            virtual void onFloat3(MPlug & plug, const MString & name, float value[3]) override
            {
				mLight.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value[0], value[1], value[2], "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
            }

            virtual void onDouble(MPlug & plug, const MString & name, double value) override
            {
				mLight.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value, "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
            }

            virtual void onDouble2(MPlug & plug, const MString & name, double value[2]) override
            {
				mLight.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value[0], value[1], "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
            }

            virtual void onDouble3(MPlug & plug, const MString & name, double value[3]) override
            {
				mLight.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value[0], value[1], value[2], "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
            }

            virtual void onDouble4(MPlug & plug, const MString & name, double value[4]) override
            {
				mLight.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value[0], value[1], value[2], value[3], "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
            }

            virtual void onString(MPlug & plug, const MString & name, const MString & value) override
            {
				mLight.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), COLLADABU::StringUtils::translateToXML(String(value.asChar())), "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
            }

            virtual void onEnum(MPlug & plug, const MString & name, int enumValue, const MString & enumName) override
            {
                // TODO export all possible enum values to be able to re-import them?
				mLight.addExtraTechniqueEnumParameter(PROFILE_MAYA, name.asChar(), COLLADABU::StringUtils::translateToXML(String(enumName.asChar())), "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
            }
        };

        MObject nodeObject = sceneElement->getNode();

        MStatus status;
        MFnDependencyNode fnNode(nodeObject, &status);
        if (!status) return;

        ExtraAttributeExporter extraAttributeExporter(*light);
        AttributeParser::parseAttributes(fnNode, extraAttributeExporter);
    }

    // ------------------------------------
    const String LightExporter::findColladaLightId ( const String& mayaLightId )
    {
        const StringToStringMap::const_iterator it = mMayaIdColladaIdMap.find ( mayaLightId );
        if ( it != mMayaIdColladaIdMap.end () )
        {
            return it->second;
        }
        return EMPTY_STRING;
    }

}