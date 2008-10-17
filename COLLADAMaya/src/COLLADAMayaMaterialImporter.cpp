/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
#include "COLLADAMayaMaterialImporter.h"

#include "COLLADAReader.h"
#include "COLLADAElementIterator.h"
#include "COLLADAEffectUtil.h"

#include "dom/domMaterial.h"

namespace COLLADAMaya
{

    //------------------------------
    MaterialImporter::MaterialImporter ( DocumentImporter* documentImporter )
    : mDocumentImporter ( documentImporter )
    {}


    // --------------------------
    void MaterialImporter::importMaterials()
    {
        const domCOLLADA* colladaDoc = mDocumentImporter->getColladaDocument();
        daeDocument* daeDoc = mDocumentImporter->getDaeDocument();

        COLLADA::Reader reader ( *daeDoc );

        COLLADA::Reader::ElementIterator<domMaterial> materialsIter = reader.getMaterials();
        while ( materialsIter.more() )
        {
            domMaterial& material = materialsIter.next();
            importMaterial ( material );
        }
    }

    // --------------------------
    void MaterialImporter::importMaterial ( domMaterial& material )
    {
        daeString elementName = material.getElementName();
        xsNCName materialName = material.getName();
        daeString materialTypeName = material.getTypeName();
        xsID materialId = material.getId();

        domInstance_effectRef instEffect = material.getInstance_effect();
        domInstance_effect* effect1 = instEffect.cast();
        xsNCName effectSid = effect1->getSid();
        xsAnyURI effectUrl = effect1->getUrl();

        if ( instEffect )
        {
            domEffect* effect = daeSafeCast<domEffect>( instEffect->getUrl().getElement() );
            if ( effect )
            {
                float opacity = COLLADA::EffectUtil::getTransparency(effect);

                COLLADA::TextureImageList list;
                COLLADA::EffectUtil::getTextureImages(effect, list, COLLADA::EffectUtil::DIFFUSE);
                if (list.size() == 0)
                {
                    domFx_color_common diffuse = COLLADA::EffectUtil::getDiffuseColor(effect);
                    //mMaterialDiffuse.Set(diffuse.get( 0 ), diffuse.get( 1 ), diffuse.get( 2 ), diffuse.get( 3 ));
                }

                domFx_color_common emission = COLLADA::EffectUtil::getEmissiveColor(effect);
                //mMaterialEmission.Set(emission.get( 0 ), emission.get( 1 ), emission.get( 2 ), emission.get( 3 ));

                domFx_color_common ambient = COLLADA::EffectUtil::getAmbientColor(effect);
                //mMaterialAmbient.Set(ambient.get( 0 ), ambient.get( 1 ), ambient.get( 2 ), ambient.get( 3 ));

                domFx_color_common specular = COLLADA::EffectUtil::getSpecularColor(effect);
                //mMaterialSpecular.Set(specular.get( 0 ), specular.get( 1 ), specular.get( 2 ), specular.get( 3 ));

                float shininess = COLLADA::EffectUtil::getShininess(effect);
                //material->setShininess( shininess );

                domFx_profile_abstract_Array& profileArray = effect->getFx_profile_abstract_array();
                for ( size_t i = 0; i < profileArray.getCount(); i++ )
                {
                    domProfile_COMMON* common = daeSafeCast<domProfile_COMMON>( profileArray.get( i ) );
                    if ( common )
                    {
                        domProfile_COMMON::domTechnique * technique = common->getTechnique();
                        if ( technique )
                        {
                            domProfile_COMMON::domTechnique::domPhong * phong = technique->getPhong();
                            if ( phong )
                            {
                                domCommon_color_or_texture_type *diffuse = phong->getDiffuse();
                                if ( diffuse )
                                {
                                    domCommon_color_or_texture_type::domColor * color = diffuse->getColor();
                                    if ( color )
                                    {
                                        domFx_color_common & values = color->getValue();
                                        //material.SetValues(values.get(0), values.get(1), values.get(2), Quantity_TOC_RGB);
                                    }
                                }								
                            }
                        }
                    }

                    else
                        continue;
                }
            }
        }

    }

    // --------------------------
//     MObject	MaterialImporter::importStandardShader ( 
//         FCDGeometryInstance* colladaInstance, 
//         FCDMaterialInstance* colladaMaterialInstance, 
//         FCDEffectStandard* effectStandard, 
//         FCDMaterial* colladaMaterial )
//     {
//         if (effectStandard == NULL || colladaMaterial == NULL) return MObject::kNullObj;
//         FCDEffect* effect = colladaMaterial->GetEffect();
//         FCDEffectProfile* effectProfile = effect->FindProfile(FUDaeProfileType::COMMON);
//         bool dummy = false;
// 
//         // Determine the Maya type for this standard material shader
//         MFn::Type shaderType;
//         switch (effectStandard->GetLightingType())
//         {
//         case FCDEffectStandard::CONSTANT: shaderType = MFn::kSurfaceShader; break;
//         case FCDEffectStandard::LAMBERT: shaderType = MFn::kLambert; break;
//         case FCDEffectStandard::PHONG: shaderType = MFn::kPhong; break;
//         case FCDEffectStandard::BLINN: shaderType = MFn::kBlinn; break;
//         default: shaderType = MFn::kLambert; break;
//         }
// 
//         // Create the shader node
//         MString shaderName = doc->ColladaNameToDagName(colladaMaterial->GetName().c_str());
//         MObject shader = CShaderHelper::CreateShader(shaderType, shaderName);
//         MFnDependencyNode shaderFn(shader);
//         MFnLambertShader lambertFn(shader);
//         MFnPhongShader phongFn(shader);
//         MFnBlinnShader blinnFn(shader);
// 
//         //Synchronize the animators with the rest of the standard effect...
//         if (colladaInstance != NULL && colladaMaterialInstance != NULL)
//         {
//             FCDEffectTools::SynchronizeAnimatedParams(colladaInstance, colladaMaterialInstance);
//         }
// 
//         FCDParameterAnimatableColor4* translucencyColor = FCDEffectTools::GetAnimatedColor(colladaInstance, colladaMaterial, FCDEffectStandard::TranslucencyColorSemantic, &dummy);
//         FCDParameterAnimatableFloat* translucencyFactor = FCDEffectTools::GetAnimatedFloat(colladaInstance, colladaMaterial, FCDEffectStandard::TranslucencyFactorSemantic);
//         FCDParameterAnimatableColor4* emissionColor = FCDEffectTools::GetAnimatedColor(colladaInstance, colladaMaterial, FCDEffectStandard::EmissionColorSemantic, &dummy);
//         FCDParameterAnimatableFloat* emissionFactor = FCDEffectTools::GetAnimatedFloat(colladaInstance, colladaMaterial, FCDEffectStandard::EmissionFactorSemantic);
//         FCDParameterAnimatableColor4* diffuseColor = FCDEffectTools::GetAnimatedColor(colladaInstance, colladaMaterial, FCDEffectStandard::DiffuseColorSemantic, &dummy);
//         FCDParameterAnimatableColor4* ambientColor = FCDEffectTools::GetAnimatedColor(colladaInstance, colladaMaterial, FCDEffectStandard::AmbientColorSemantic, &dummy);
//         FCDParameterAnimatableColor4* specularColor = FCDEffectTools::GetAnimatedColor(colladaInstance, colladaMaterial, FCDEffectStandard::SpecularColorSemantic, &dummy);
//         FCDParameterAnimatableFloat* specularFactor = FCDEffectTools::GetAnimatedFloat(colladaInstance, colladaMaterial, FCDEffectStandard::SpecularFactorSemantic);
//         FCDParameterAnimatableColor4* reflectivityColor = FCDEffectTools::GetAnimatedColor(colladaInstance, colladaMaterial, FCDEffectStandard::ReflectivityColorSemantic, &dummy);
//         FCDParameterAnimatableFloat* reflectivityFactor = FCDEffectTools::GetAnimatedFloat(colladaInstance, colladaMaterial, FCDEffectStandard::ReflectivityFactorSemantic);
//         FCDParameterAnimatableFloat* shininess = FCDEffectTools::GetAnimatedFloat(colladaInstance, colladaMaterial, FCDEffectStandard::ShininessSemantic);
//         FCDParameterAnimatableFloat* refraction = FCDEffectTools::GetAnimatedFloat(colladaInstance, colladaMaterial, FCDEffectStandard::IndexOfRefractionSemantic);
// 
//         // Used to setup any inputs (e.g. connected textures)
//         // Keep track of the textures and the order as they are used to assign uv sets
//         //
//         DaeMaterial* material = (DaeMaterial*) colladaMaterial->GetUserHandle(); // slightly-round-about.
//         DaeTextureList textures;
//     }

}