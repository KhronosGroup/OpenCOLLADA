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
#include "COLLADAMayaShaderHelper.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaSyntax.h"

// #include "COLLADADHReader.h"
// #include "COLLADADHElementIterator.h"
// #include "COLLADADHEffectUtil.h"
// 
// #include <dom/domMaterial.h>
// #include <dom/domTypes.h>

#include <maya/MFnLambertShader.h>
#include <maya/MFnPhongShader.h>
#include <maya/MFnBlinnShader.h>

namespace COLLADAMaya
{

    //------------------------------
    MaterialImporter::MaterialImporter ( DocumentImporter* documentImporter )
    : BaseImporter ( documentImporter )
    {}

    // --------------------------
    void MaterialImporter::importMaterials()
    {
//         daeDocument* document = getDaeDocument();
//         COLLADADH::Reader reader ( *( document ) );
// 
//         COLLADADH::Reader::ElementIterator<domMaterial> materialsIter = reader.getMaterials();
//         while ( materialsIter.more() )
//         {
//             domMaterial& material = materialsIter.next();
//             importMaterial ( material );
//         }
    }

//     // --------------------------
//     void MaterialImporter::importMaterial ( domMaterial& material )
//     {
//         daeString elementName = material.getElementName();
//         xsNCName materialName = material.getName();
//         daeString materialTypeName = material.getTypeName();
//         xsID materialId = material.getId();
// 
//         domInstance_effectRef instEffect = material.getInstance_effect();
//         domInstance_effect* effect1 = instEffect.cast();
//         xsNCName effectSid = effect1->getSid();
//         xsAnyURI effectUrl = effect1->getUrl();
// 
//         if ( instEffect )
//         {
//             domEffect* effect = daeSafeCast<domEffect>( instEffect->getUrl().getElement() );
//             if ( effect )
//             {
//                 // Determine the Maya type for this standard material shader
//                 MFn::Type mayaShaderType;
// 
//                 COLLADADH::EffectUtil::ShaderType shaderType;
//                 shaderType = COLLADADH::EffectUtil::getShaderType ( effect );
//                 switch ( shaderType )
//                 {
//                 case COLLADADH::EffectUtil::CONSTANT: mayaShaderType = MFn::kSurfaceShader; break;
//                 case COLLADADH::EffectUtil::PHONG: mayaShaderType = MFn::kPhong; break;
//                 case COLLADADH::EffectUtil::BLINN: mayaShaderType = MFn::kBlinn; break;
//                 case COLLADADH::EffectUtil::LAMBERT: mayaShaderType = MFn::kLambert; break;
//                 default: mayaShaderType = MFn::kLambert;
//                 }
// 
//                 // Create the shader node
//                 xsID effectId = effect->getId();
//                 MObject shader = ShaderHelper::createShader ( mayaShaderType, effectId );
//                 MFnDependencyNode shaderFn ( shader );
//                 MFnLambertShader lambertFn ( shader );
// 
//                 // Read in the color/factor parameters, according to the material type.
//                 if ( shader.hasFn ( MFn::kSurfaceShader ) )
//                 {
// //                    importConstantShader (...); 
// 
//                     // Emission color / Incandescence
//                     domFx_color_common emission = COLLADADH::EffectUtil::getEmissiveColor ( effect, shaderType );
// 
//                     // CONSTANT material: has only one interesting color parameter, for emission.
//                     MColor outColor ( (float)emission.get(0), (float)emission.get(1), (float)emission.get(2), (float)emission.get(3) );
//                     DagHelper::setPlugValue ( shader, ATTR_OUT_COLOR, outColor );
// //                    ANIM->AddPlugAnimation(shader, "outColor", *emissionColor, kColour);
// 
//                     // Transparency / Opaque
//                     domCommon_transparent_typeRef transparentTypeRef = 
//                         COLLADADH::EffectUtil::getTransparent ( effect, shaderType );
//                     
//                     domCommon_color_or_texture_type_complexType::domColorRef domTransColorObj;
//                     domTransColorObj = transparentTypeRef->getColor();
//                     domFx_color_common& domTransColor = domTransColorObj->getValue();
//                     if ( domTransColor.getCount() < 4 ) domTransColor.set4 ( 0, 0, 0, 1 );
//                     MColor transColor ( (float)domTransColor.get(0), (float)domTransColor.get(1), (float)domTransColor.get(2), (float)domTransColor.get(3) );
// 
//                     float transparency = COLLADADH::EffectUtil::getTransparency ( effect );
//                     domFx_opaque_enum opaque = transparentTypeRef->getOpaque();
//                     const char* transparencyOutput;
//                     switch ( opaque )
//                     {
//                     case FX_OPAQUE_ENUM_RGB_ZERO:
//                         DagHelper::setPlugValue ( shader, ATTR_OUT_TRANSPARENCY, transColor * transparency ); 
//                         //ANIM->AddPlugAnimation(shader, "outTransparency", *translucencyColor, kColour);
//                         transparencyOutput = "outColor"; // For any subsequent textures.
//                         break;
//                     case FX_OPAQUE_ENUM_A_ONE:
//                     default:
//                         MColor transyColor;
//                         transyColor.r = transyColor.g = transyColor.b = 1.0f - ( transColor.a ) * transparency;
//                         DagHelper::setPlugValue ( shader, ATTR_OUT_TRANSPARENCY, transyColor ); 
//                         transparencyOutput = "outTransparency"; // For any subsequent textures.
//                         break;
//                     }
// 
//                     // TODO
// //                     PROCESS_BUCKET(FUDaeTextureChannel::EMISSION);
// //                     CONNECT_TEXTURES("outColor", "outColor");
// // 
// //                     PROCESS_BUCKET(FUDaeTextureChannel::TRANSPARENT);
// //                     if (textures.size() == 1 && effectStandard->GetTransparencyMode() == FCDEffectStandard::A_ONE)
// //                     {
// //                         // Import any animation on the translucency factor
// //                         MObject textureNode = textures.front().frontObject;
// //                         ANIM->AddPlugAnimation(textureNode, "alphaGain", *translucencyFactor, kSingle, NULL);
// //                     }
// //                     CONNECT_TEXTURES(transparencyOutput, "outTransparency");
//                 }
//                 else
//                 {
//                     // TODO
// //                     if (effectStandard->IsRefractive())
// //                     {
// //                         lambertFn.setRefractiveIndex(*refraction);
// //                         ANIM->AddPlugAnimation(shader, "refractiveIndex", *refraction, kSingle);
// //                         CDagHelper::SetPlugValue(shader, "refractions", true);
// //                     }
// 
//                     // Diffuse 
//                     domFx_color_common diffuse = COLLADADH::EffectUtil::getDiffuseColor( effect, shaderType );
//                     MColor diffColor ( (float)diffuse.get(0), (float)diffuse.get(1), (float)diffuse.get(2), (float)diffuse.get(3) );
//                     lambertFn.setColor ( diffColor );
//                     //ANIM->AddPlugAnimation(shader, "color", *diffuseColor, kColour);
//                     lambertFn.setDiffuseCoeff (1.0f);
// 
//                     // Emission color / Incandescence
//                     domFx_color_common emission = COLLADADH::EffectUtil::getEmissiveColor ( effect, shaderType );
//                     //mMaterialEmission.Set(emission.get(0), emission.get(1), emission.get(2), emission.get(3));
//                     lambertFn.setIncandescence ( MColor ( (float)emission.get(0), (float)emission.get(1), (float)emission.get(2), (float)emission.get(3) ) );
// 
//                     // Ambient
//                     domFx_color_common ambient = COLLADADH::EffectUtil::getAmbientColor ( effect, shaderType );
//                     MColor ambientColor ( (float)ambient.get(0), (float)ambient.get(1), (float)ambient.get(2), (float)ambient.get(3) );
//                     lambertFn.setAmbientColor ( ambientColor );
//                     //ANIM->AddPlugAnimation(shader, "ambientColor", *ambientColor, kColour);
// 
//                     // Transparency / Opaque
//                     domCommon_transparent_typeRef transparentTypeRef = 
//                         COLLADADH::EffectUtil::getTransparent ( effect, shaderType );
// 
//                     domCommon_color_or_texture_type_complexType::domColorRef domTransColorObj;
//                     domTransColorObj = transparentTypeRef->getColor();
//                     domFx_color_common& domTransColor = domTransColorObj->getValue();
//                     if ( domTransColor.getCount() < 4 ) domTransColor.set4 ( 0, 0, 0, 1 );
//                     MColor transColor ( (float)domTransColor.get(0), (float)domTransColor.get(1), (float)domTransColor.get(2), (float)domTransColor.get(3) );
// 
//                     float transparency = COLLADADH::EffectUtil::getTransparency ( effect );
//                     domFx_opaque_enum opaque = transparentTypeRef->getOpaque();
//                     const char* transparencyOutput;
//                     switch ( opaque )
//                     {
//                     case FX_OPAQUE_ENUM_RGB_ZERO:
//                         DagHelper::setPlugValue ( shader, ATTR_OUT_TRANSPARENCY, transColor * transparency ); 
//                         //ANIM->AddPlugAnimation(shader, "outTransparency", *translucencyColor, kColour);
//                         transparencyOutput = "outColor"; // For any subsequent textures.
//                         break;
//                     case FX_OPAQUE_ENUM_A_ONE:
//                     default:
//                         MColor transyColor;
//                         transyColor.r = transyColor.g = transyColor.b = 1.0f - ( transColor.a ) * transparency;
//                         DagHelper::setPlugValue ( shader, ATTR_OUT_TRANSPARENCY, transyColor ); 
//                         transparencyOutput = "outTransparency"; // For any subsequent textures.
//                         break;
//                     }
// 
// //                     // Phong shader parameters
// //                     if (shader.hasFn(MFn::kPhong))
// //                     {
// // 
// //                         phongFn.setSpecularColor(MConvert::ToMColor(*specularColor) * *specularFactor);
// //                         ANIM->AddPlugAnimation(shader, "specularColor", *specularColor, kColour);
// // 
// //                         phongFn.setReflectedColor(MConvert::ToMColor(*reflectivityColor));
// //                         ANIM->AddPlugAnimation(shader, "reflectedColor", *reflectivityColor, kColour);
// //                         CDagHelper::SetPlugValue(shader, "reflectivity", *reflectivityFactor);
// //                         ANIM->AddPlugAnimation(shader, "reflectivity", *reflectivityFactor, kSingle);
// // 
// //                         // Shininess should never be less than 2.0
// // 
// //                         float cospower = *shininess;
// //                         phongFn.setCosPower((cospower > 2.0f) ? cospower : 2.0f);
// //                         ANIM->AddPlugAnimation(shader, "cosinePower", *shininess, kSingle);
// //                     }
// // 
// //                     // blinn shader parameters
// //                     if (shader.hasFn(MFn::kBlinn))
// //                     {
// //                         blinnFn.setSpecularColor(MConvert::ToMColor(*specularColor) * *specularFactor);
// //                         ANIM->AddPlugAnimation(shader, "specularColor", *specularColor, kColour);
// //                         blinnFn.setReflectedColor(MConvert::ToMColor(*reflectivityColor));
// //                         ANIM->AddPlugAnimation(shader, "reflectedColor", *reflectivityColor, kColour);
// //                         CDagHelper::SetPlugValue(shader, "reflectivity", *reflectivityFactor);
// //                         ANIM->AddPlugAnimation(shader, "reflectivity", *reflectivityFactor, kSingle);
// // 
// // #ifdef BLINN_EXPONENT_MODEL
// //                         BlinnShininessToEccentricity* converter = new BlinnShininessToEccentricity();
// //                         blinnFn.setEccentricity((*converter)(effectStandard->GetShininess()));
// //                         ANIM->AddPlugAnimation(shader, "eccentricity", *shininess, kSingle, converter);
// // #else
// //                         blinnFn.setEccentricity(effectStandard->GetShininess());
// //                         ANIM->AddPlugAnimation(shader, "eccentricity", *shininess, kSingle);
// // #endif // BLINN_EXPONENT_MODEL
// //                     }
// // 
// //                     // Connect the textures in each of the buckets. If there is more than once
// //                     // texture in a bucket, use a modulated layeredTexture.
// //                     //
// //                     PROCESS_BUCKET(FUDaeTextureChannel::DIFFUSE);
// //                     CONNECT_TEXTURES("outColor", "color");
// //                     PROCESS_BUCKET(FUDaeTextureChannel::AMBIENT);
// //                     CONNECT_TEXTURES("outColor", "ambientColor");
// // 
// //                     PROCESS_BUCKET(FUDaeTextureChannel::TRANSPARENT);
// //                     if (textures.size() == 1 && effectStandard->GetTransparencyMode() == FCDEffectStandard::A_ONE)
// //                     {
// //                         // Import any animation on the translucency factor
// //                         MObject textureNode = textures.front().frontObject;
// // 
// //                         ANIM->AddPlugAnimation(textureNode, "alphaGain", *translucencyFactor, kSingle);
// //                     }
// //                     CONNECT_TEXTURES(transparencyOutput, "transparency");
// // 
// //                     PROCESS_BUCKET(FUDaeTextureChannel::EMISSION);
// //                     CONNECT_TEXTURES("outColor", "incandescence");
// //                     PROCESS_BUCKET(FUDaeTextureChannel::SPECULAR);
// //                     PROCESS_BUCKET(FUDaeTextureChannel::SPECULAR_LEVEL);
// //                     PROCESS_BUCKET(FUDaeTextureChannel::SHININESS);
// //                     CONNECT_TEXTURES("outColor", "specularColor");
// // 
// //                     // Bump textures are a little special
// //                     PROCESS_BUCKET(FUDaeTextureChannel::BUMP);
// //                     MObject bumpTexture(MObject::kNullObj);
// //                     uint bumpTextureCount = (uint) textures.size();
// //                     if (bumpTextureCount == 1) bumpTexture = textures.front().frontObject;
// //                     else if (bumpTextureCount > 1)
// //                     {
// //                         MObject layeredTexture = CShaderHelper::CreateLayeredTexture(textures);
// //                         bumpTexture = layeredTexture;
// //                     }
// //                     if (bumpTexture != MObject::kNullObj)
// //                     {
// //                         MFnDependencyNode bumpTextureFn(bumpTexture);
// //                         MPlug alphaInput = bumpTextureFn.findPlug("alphaIsLuminance");
// //                         alphaInput.setValue(1);
// // 
// //                         MObject bumpObject = CShaderHelper::CreateBumpNode(bumpTexture);
// //                         CDagHelper::Connect(bumpObject, "outNormal", shader, "normalCamera");
// // 
// //                         // Look for the bump-depth, within the ColladaMax technique.
// //                         const FCDETechnique* colladaMaxTechnique = textures.front().colladaTexture->GetExtra()->GetDefaultType()->FindTechnique(DAEMAX_MAX_PROFILE);
// //                         if (colladaMaxTechnique != NULL)
// //                         {
// //                             float amount = 1.0f;
// //                             const FCDENode* amountNode = colladaMaxTechnique->FindParameter(DAEMAX_AMOUNT_TEXTURE_PARAMETER);
// //                             if (amountNode != NULL)
// //                             {
// //                                 ANIM->AddPlugAnimation(bumpObject, "bumpDepth", const_cast<FCDAnimatedCustom*>(amountNode->GetAnimated()), kSingle);
// //                             }
// //                             amount = FUStringConversion::ToFloat(amountNode->GetContent());
// //                             CDagHelper::SetPlugValue(bumpObject, "bumpDepth", amount);
// // 
// //                             const FCDENode* interpNode = colladaMaxTechnique->FindParameter(DAEMAX_BUMP_INTERP_TEXTURE_PARAMETER);
// //                             if (interpNode != NULL)
// //                             {
// //                                 int interp = FUStringConversion::ToInt32(interpNode->GetContent());
// //                                 CDagHelper::SetPlugValue(bumpObject, "bumpInterp", interp);
// //                             }
// //                         }
// //                     }
//                 }
// 
//                 MFnPhongShader phongFn ( shader );
//                 MFnBlinnShader blinnFn ( shader );
// 
//                 COLLADADH::TextureImageList list;
//                 COLLADADH::EffectUtil::getTextureImages(effect, list, COLLADADH::EffectUtil::DIFFUSE);
//                 if (list.size() == 0)
//                 {
//                     domFx_color_common diffuse = COLLADADH::EffectUtil::getDiffuseColor(effect);
//                     lambertFn.setColor( MColor ( (float)diffuse.get(0), (float)diffuse.get(1), (float)diffuse.get(2), (float)diffuse.get(3) ) );
//                     lambertFn.setDiffuseCoeff(1.0f);
//                     //mMaterialDiffuse.Set(diffuse.get( 0 ), diffuse.get( 1 ), diffuse.get( 2 ), diffuse.get( 3 ));
//                 }
// 
// 
//                 domFx_color_common ambient = COLLADADH::EffectUtil::getAmbientColor(effect);
//                 //mMaterialAmbient.Set(ambient.get( 0 ), ambient.get( 1 ), ambient.get( 2 ), ambient.get( 3 ));
// 
//                 domFx_color_common specular = COLLADADH::EffectUtil::getSpecularColor(effect);
//                 if ( mayaShaderType = MFn::kBlinn )
//                 {
//                     blinnFn.setSpecularColor ( MColor ( (float)specular.get(0), (float)specular.get(1), (float)specular.get(2), (float)specular.get(3) ));
//                 }
//                 if ( mayaShaderType = MFn::kPhong )
//                 {
//                     phongFn.setSpecularColor ( MColor ( (float)specular.get(0), (float)specular.get(1), (float)specular.get(2), (float)specular.get(3) ));
//                 }
//                 //mMaterialSpecular.Set(specular.get( 0 ), specular.get( 1 ), specular.get( 2 ), specular.get( 3 ));
// 
//                 float shininess = COLLADADH::EffectUtil::getShininess(effect);
//                 //material->setShininess( shininess );
// 
//                 domFx_profile_abstract_Array& profileArray = effect->getFx_profile_abstract_array();
//                 for ( size_t i = 0; i < profileArray.getCount(); i++ )
//                 {
//                     domProfile_COMMON* common = daeSafeCast<domProfile_COMMON>( profileArray.get( i ) );
//                     if ( common )
//                     {
//                         domProfile_COMMON::domTechnique * technique = common->getTechnique();
//                         if ( technique )
//                         {
//                             domProfile_COMMON::domTechnique::domPhong * phong = technique->getPhong();
//                             if ( phong )
//                             {
//                                 domCommon_color_or_texture_type *diffuse = phong->getDiffuse();
//                                 if ( diffuse )
//                                 {
//                                     domCommon_color_or_texture_type::domColor * color = diffuse->getColor();
//                                     if ( color )
//                                     {
//                                         domFx_color_common & values = color->getValue();
//                                         //material.SetValues(values.get(0), values.get(1), values.get(2), Quantity_TOC_RGB);
//                                     }
//                                 }								
//                             }
//                         }
//                     }
// 
//                     else
//                         continue;
//                 }
// 
//                 // Return the shadingGroup/shadingEngine name
//                 MObject shaderGroup = ShaderHelper::getShadingEngine ( shader );
// 
//             }
//         }
//     }
// 
//     // --------------------------
// //     MObject	MaterialImporter::importStandardShader ( 
// //         FCDGeometryInstance* colladaInstance, 
// //         FCDMaterialInstance* colladaMaterialInstance, 
// //         FCDEffectStandard* effectStandard, 
// //         FCDMaterial* colladaMaterial )
// //     {
// //         if (effectStandard == NULL || colladaMaterial == NULL) return MObject::kNullObj;
// //         FCDEffect* effect = colladaMaterial->GetEffect();
// //         FCDEffectProfile* effectProfile = effect->FindProfile(FUDaeProfileType::COMMON);
// //         bool dummy = false;
// // 
// //         // Determine the Maya type for this standard material shader
// //         MFn::Type shaderType;
// //         switch (effectStandard->GetLightingType())
// //         {
// //         case FCDEffectStandard::CONSTANT: shaderType = MFn::kSurfaceShader; break;
// //         case FCDEffectStandard::LAMBERT: shaderType = MFn::kLambert; break;
// //         case FCDEffectStandard::PHONG: shaderType = MFn::kPhong; break;
// //         case FCDEffectStandard::BLINN: shaderType = MFn::kBlinn; break;
// //         default: shaderType = MFn::kLambert; break;
// //         }
// // 
// //         // Create the shader node
// //         MString shaderName = doc->ColladaNameToDagName(colladaMaterial->GetName().c_str());
// //         MObject shader = CShaderHelper::CreateShader(shaderType, shaderName);
// //         MFnDependencyNode shaderFn(shader);
// //         MFnLambertShader lambertFn(shader);
// //         MFnPhongShader phongFn(shader);
// //         MFnBlinnShader blinnFn(shader);
// // 
// //         //Synchronize the animators with the rest of the standard effect...
// //         if (colladaInstance != NULL && colladaMaterialInstance != NULL)
// //         {
// //             FCDEffectTools::SynchronizeAnimatedParams(colladaInstance, colladaMaterialInstance);
// //         }
// // 
// //         FCDParameterAnimatableColor4* translucencyColor = FCDEffectTools::GetAnimatedColor(colladaInstance, colladaMaterial, FCDEffectStandard::TranslucencyColorSemantic, &dummy);
// //         FCDParameterAnimatableFloat* translucencyFactor = FCDEffectTools::GetAnimatedFloat(colladaInstance, colladaMaterial, FCDEffectStandard::TranslucencyFactorSemantic);
// //         FCDParameterAnimatableColor4* emissionColor = FCDEffectTools::GetAnimatedColor(colladaInstance, colladaMaterial, FCDEffectStandard::EmissionColorSemantic, &dummy);
// //         FCDParameterAnimatableFloat* emissionFactor = FCDEffectTools::GetAnimatedFloat(colladaInstance, colladaMaterial, FCDEffectStandard::EmissionFactorSemantic);
// //         FCDParameterAnimatableColor4* diffuseColor = FCDEffectTools::GetAnimatedColor(colladaInstance, colladaMaterial, FCDEffectStandard::DiffuseColorSemantic, &dummy);
// //         FCDParameterAnimatableColor4* ambientColor = FCDEffectTools::GetAnimatedColor(colladaInstance, colladaMaterial, FCDEffectStandard::AmbientColorSemantic, &dummy);
// //         FCDParameterAnimatableColor4* specularColor = FCDEffectTools::GetAnimatedColor(colladaInstance, colladaMaterial, FCDEffectStandard::SpecularColorSemantic, &dummy);
// //         FCDParameterAnimatableFloat* specularFactor = FCDEffectTools::GetAnimatedFloat(colladaInstance, colladaMaterial, FCDEffectStandard::SpecularFactorSemantic);
// //         FCDParameterAnimatableColor4* reflectivityColor = FCDEffectTools::GetAnimatedColor(colladaInstance, colladaMaterial, FCDEffectStandard::ReflectivityColorSemantic, &dummy);
// //         FCDParameterAnimatableFloat* reflectivityFactor = FCDEffectTools::GetAnimatedFloat(colladaInstance, colladaMaterial, FCDEffectStandard::ReflectivityFactorSemantic);
// //         FCDParameterAnimatableFloat* shininess = FCDEffectTools::GetAnimatedFloat(colladaInstance, colladaMaterial, FCDEffectStandard::ShininessSemantic);
// //         FCDParameterAnimatableFloat* refraction = FCDEffectTools::GetAnimatedFloat(colladaInstance, colladaMaterial, FCDEffectStandard::IndexOfRefractionSemantic);
// // 
// //         // Used to setup any inputs (e.g. connected textures)
// //         // Keep track of the textures and the order as they are used to assign uv sets
// //         //
// //         DaeMaterial* material = (DaeMaterial*) colladaMaterial->GetUserHandle(); // slightly-round-about.
// //         DaeTextureList textures;
// //     }

}