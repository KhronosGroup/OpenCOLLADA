/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLVersionParser.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLRootParser14.h"
#include "COLLADASaxFWLRootParser15.h"

#include "GeneratedSaxParserUtils.h"

namespace COLLADASaxFWL
{
    const StringHash HASH_NAMESPACE_COLLADA_14 = 221035537;
    const StringHash HASH_NAMESPACE_COLLADA_15 = 234671633;
    const StringHash HASH_ELEMENT_COLLADA = 138479041;
    const StringHash HASH_ATTRIBUTE_XMLNS = 8340307;

    size_t XMLPARSER_BUFFERSIZE = 64*1024;

    enum LibraryFlags
    {
        COLLADA_NO_FLAGS                     = 0,    
        COLLADA_ASSET                        = 1<< 0,
        COLLADA_LIBRARY_ANIMATION_CLIPS      = 1<< 1,
        COLLADA_LIBRARY_ANIMATIONS           = 1<< 2,
        COLLADA_LIBRARY_ARTICULATED_SYSTEMS  = 1<< 3,
        COLLADA_LIBRARY_CAMERAS              = 1<< 4,
        COLLADA_LIBRARY_CONTROLLERS          = 1<< 5,
        COLLADA_LIBRARY_EFFECTS              = 1<< 6,
        COLLADA_LIBRARY_FORCE_FIELDS         = 1<< 7,
        COLLADA_LIBRARY_FORMULAS             = 1<< 8,
        COLLADA_LIBRARY_GEOMETRIES           = 1<< 9,
        COLLADA_LIBRARY_IMAGES               = 1<<10,
        COLLADA_LIBRARY_JOINTS               = 1<<11,
        COLLADA_LIBRARY_KINEMATICS_MODELS    = 1<<12,
        COLLADA_LIBRARY_KINEMATICS_SCENES    = 1<<13,
        COLLADA_LIBRARY_LIGHTS               = 1<<14,
        COLLADA_LIBRARY_MATERIALS            = 1<<15,
        COLLADA_LIBRARY_NODES                = 1<<16,
        COLLADA_LIBRARY_PHYSICS_MATERIALS    = 1<<17,
        COLLADA_LIBRARY_PHYSICS_MODELS       = 1<<18,
        COLLADA_LIBRARY_PHYSICS_SCENES       = 1<<19,
        COLLADA_LIBRARY_VISUAL_SCENES        = 1<<20,
        COLLADA_SCENE                        = 1<<21
    };

    struct LibraryFlagsFunctionMapPair14
    {
        LibraryFlags flag;
        const COLLADASaxFWL14::ColladaParserAutoGen14Private::ElementFunctionMap& functionMap;
    };

    struct LibraryFlagsFunctionMapPair15
    {
        LibraryFlags flag;
        const COLLADASaxFWL15::ColladaParserAutoGen15Private::ElementFunctionMap& functionMap;
    };


    // COLLADA 1.4
    LibraryFlagsFunctionMapPair14 COLLADA_ASSET_PAIR_14 = {COLLADA_ASSET, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__asset__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_ANIMATION_CLIPS_PAIR_14 = {COLLADA_LIBRARY_ANIMATION_CLIPS, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_animation_clips__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_ANIMATIONS_PAIR_14 = {COLLADA_LIBRARY_ANIMATIONS, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_animations__allChildren() };
    //	LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_ARTICULATED_SYSTEMS_PAIR_14 = {COLLADA_LIBRARY_ARTICULATED_SYSTEMS, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_articulated_systems__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_CAMERAS_PAIR_14 = {COLLADA_LIBRARY_CAMERAS, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_cameras__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_CONTROLLERS_PAIR_14 = {COLLADA_LIBRARY_CONTROLLERS, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_controllers__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_EFFECTS_PAIR_14 = {COLLADA_LIBRARY_EFFECTS, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_effects__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_FORCE_FIELDS_PAIR_14 = {COLLADA_LIBRARY_FORCE_FIELDS, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_force_fields__allChildren() };
    //	LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_FORMULAS_PAIR_14 = {COLLADA_LIBRARY_FORMULAS, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_formulas__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_GEOMETRIES_PAIR_14 = {COLLADA_LIBRARY_GEOMETRIES, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_geometries__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_IMAGES_PAIR_14 = {COLLADA_LIBRARY_IMAGES, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_images__allChildren() };
    //	LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_JOINTS_PAIR_14 = {COLLADA_LIBRARY_JOINTS, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_joints__allChildren() };
    //	LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_KINEMATICS_MODELS_PAIR_14 = {COLLADA_LIBRARY_KINEMATICS_MODELS, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_kinematics_models__allChildren() };
    //	LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_KINEMATICS_SCENES_PAIR_14 = {COLLADA_LIBRARY_KINEMATICS_SCENES, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_kinematics_scenes__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_LIGHTS_PAIR_14 = {COLLADA_LIBRARY_LIGHTS, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_lights__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_MATERIALS_PAIR_14 = {COLLADA_LIBRARY_MATERIALS, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_materials__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_NODES_PAIR_14 = {COLLADA_LIBRARY_NODES, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_nodes__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_PHYSICS_MATERIALS_PAIR_14 = {COLLADA_LIBRARY_PHYSICS_MATERIALS, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_physics_materials__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_PHYSICS_MODELS_PAIR_14 = {COLLADA_LIBRARY_PHYSICS_MODELS, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_physics_models__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_PHYSICS_SCENES_PAIR_14 = {COLLADA_LIBRARY_PHYSICS_SCENES, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_physics_scenes__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_LIBRARY_VISUAL_SCENES_PAIR_14 = {COLLADA_LIBRARY_VISUAL_SCENES, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__library_visual_scenes__allChildren() };
    LibraryFlagsFunctionMapPair14 COLLADA_SCENE_PAIR_14 = {COLLADA_SCENE, COLLADASaxFWL14::FunctionMapFactory::createFunctionMap__scene__allChildren() };


    // COLLADA 1.5
    LibraryFlagsFunctionMapPair15 COLLADA_ASSET_PAIR_15 = {COLLADA_ASSET, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__asset__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_ANIMATION_CLIPS_PAIR_15 = {COLLADA_LIBRARY_ANIMATION_CLIPS, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_animation_clips__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_ANIMATIONS_PAIR_15 = {COLLADA_LIBRARY_ANIMATIONS, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_animations__allChildren() };
    //	LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_ARTICULATED_SYSTEMS_PAIR_15 = {COLLADA_LIBRARY_ARTICULATED_SYSTEMS, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_articulated_systems__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_CAMERAS_PAIR_15 = {COLLADA_LIBRARY_CAMERAS, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_cameras__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_CONTROLLERS_PAIR_15 = {COLLADA_LIBRARY_CONTROLLERS, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_controllers__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_EFFECTS_PAIR_15 = {COLLADA_LIBRARY_EFFECTS, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_effects__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_FORCE_FIELDS_PAIR_15 = {COLLADA_LIBRARY_FORCE_FIELDS, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_force_fields__allChildren() };
    //	LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_FORMULAS_PAIR_15 = {COLLADA_LIBRARY_FORMULAS, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_formulas__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_GEOMETRIES_PAIR_15 = {COLLADA_LIBRARY_GEOMETRIES, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_geometries__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_IMAGES_PAIR_15 = {COLLADA_LIBRARY_IMAGES, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_images__allChildren() };
    //	LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_JOINTS_PAIR_15 = {COLLADA_LIBRARY_JOINTS, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_joints__allChildren() };
    //	LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_KINEMATICS_MODELS_PAIR_15 = {COLLADA_LIBRARY_KINEMATICS_MODELS, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_kinematics_models__allChildren() };
    //	LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_KINEMATICS_SCENES_PAIR_15 = {COLLADA_LIBRARY_KINEMATICS_SCENES, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_kinematics_scenes__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_LIGHTS_PAIR_15 = {COLLADA_LIBRARY_LIGHTS, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_lights__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_MATERIALS_PAIR_15 = {COLLADA_LIBRARY_MATERIALS, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_materials__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_NODES_PAIR_15 = {COLLADA_LIBRARY_NODES, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_nodes__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_PHYSICS_MATERIALS_PAIR_15 = {COLLADA_LIBRARY_PHYSICS_MATERIALS, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_physics_materials__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_PHYSICS_MODELS_PAIR_15 = {COLLADA_LIBRARY_PHYSICS_MODELS, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_physics_models__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_PHYSICS_SCENES_PAIR_15 = {COLLADA_LIBRARY_PHYSICS_SCENES, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_physics_scenes__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_LIBRARY_VISUAL_SCENES_PAIR_15 = {COLLADA_LIBRARY_VISUAL_SCENES, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__library_visual_scenes__allChildren() };
    LibraryFlagsFunctionMapPair15 COLLADA_SCENE_PAIR_15 = {COLLADA_SCENE, COLLADASaxFWL15::FunctionMapFactory::createFunctionMap__scene__allChildren() };


    LibraryFlagsFunctionMapPair14 libraryFlagsFunctionMapMap14[] = {COLLADA_ASSET_PAIR_14,
        COLLADA_LIBRARY_ANIMATION_CLIPS_PAIR_14,
        COLLADA_LIBRARY_ANIMATIONS_PAIR_14,
        COLLADA_LIBRARY_CAMERAS_PAIR_14,
        COLLADA_LIBRARY_CONTROLLERS_PAIR_14,
        COLLADA_LIBRARY_EFFECTS_PAIR_14,
        COLLADA_LIBRARY_FORCE_FIELDS_PAIR_14,
        COLLADA_LIBRARY_GEOMETRIES_PAIR_14,
        COLLADA_LIBRARY_IMAGES_PAIR_14,
        COLLADA_LIBRARY_LIGHTS_PAIR_14,
        COLLADA_LIBRARY_MATERIALS_PAIR_14,
        COLLADA_LIBRARY_NODES_PAIR_14,
        COLLADA_LIBRARY_PHYSICS_MATERIALS_PAIR_14,
        COLLADA_LIBRARY_PHYSICS_MODELS_PAIR_14,
        COLLADA_LIBRARY_PHYSICS_SCENES_PAIR_14,
        COLLADA_LIBRARY_VISUAL_SCENES_PAIR_14,
        COLLADA_SCENE_PAIR_14};

    LibraryFlagsFunctionMapPair15 libraryFlagsFunctionMapMap15[] = {COLLADA_ASSET_PAIR_15,
        COLLADA_LIBRARY_ANIMATION_CLIPS_PAIR_15,
        COLLADA_LIBRARY_ANIMATIONS_PAIR_15,
        COLLADA_LIBRARY_CAMERAS_PAIR_15,
        COLLADA_LIBRARY_CONTROLLERS_PAIR_15,
        COLLADA_LIBRARY_EFFECTS_PAIR_15,
        COLLADA_LIBRARY_FORCE_FIELDS_PAIR_15,
        COLLADA_LIBRARY_GEOMETRIES_PAIR_15,
        COLLADA_LIBRARY_IMAGES_PAIR_15,
        COLLADA_LIBRARY_LIGHTS_PAIR_15,
        COLLADA_LIBRARY_MATERIALS_PAIR_15,
        COLLADA_LIBRARY_NODES_PAIR_15,
        COLLADA_LIBRARY_PHYSICS_MATERIALS_PAIR_15,
        COLLADA_LIBRARY_PHYSICS_MODELS_PAIR_15,
        COLLADA_LIBRARY_PHYSICS_SCENES_PAIR_15,
        COLLADA_LIBRARY_VISUAL_SCENES_PAIR_15,
        COLLADA_SCENE_PAIR_15};

    size_t libraryFlagsFunctionMapMapSize14 = sizeof(libraryFlagsFunctionMapMap14)/sizeof(LibraryFlagsFunctionMapPair14);
    size_t libraryFlagsFunctionMapMapSize15 = sizeof(libraryFlagsFunctionMapMap15)/sizeof(LibraryFlagsFunctionMapPair15);

    template<class Flags>
    bool setInFirstUnsetInSecond(int firstFlags, int secondFlags, Flags flag)
    {
        return ( (firstFlags & flag) != 0 ) && ( (secondFlags & flag) == 0 );
    }

    //------------------------------
    template<class FlagsMapPair, class ElementFunctionMap>
    void createFunctionMap( int flags, int& parsedFlags, ElementFunctionMap& functionMap, FlagsMapPair* flagsMapMap, size_t flagsMapMapSize )
    {
        // A combination of ObjectFlags, indicating which objects will have been parsed, after load() 
        // has been called. These will be contained for sure.
        // We need this to ensure that objects that are store by the Loader ( visual scene, library nodes, 
        // effects, cameras, lights) are parsed only once.
        int afterLoadParsedObjectFlags = parsedFlags | flags;

        if ( (flags & Loader::ALL_OBJECTS_MASK ) != Loader::ALL_OBJECTS_MASK )
        {
            // we need to set a customized function map, since we don't need all COLLADA libraries 
            //determine which COLLADA elements we need to parse to get all date needed to parse objects in mObjectFlags
            int requiredFunctionMaps = 0;

            if ( (flags & Loader::ASSET_FLAG) != 0 )
            {
                requiredFunctionMaps|= COLLADA_ASSET;
            }

            if ( (flags & Loader::SCENE_FLAG) != 0 )
            {
                requiredFunctionMaps|= COLLADA_SCENE;
            }

            if ( setInFirstUnsetInSecond(flags, parsedFlags, Loader::VISUAL_SCENES_FLAG) )
            {
                requiredFunctionMaps|= COLLADA_LIBRARY_VISUAL_SCENES;
                requiredFunctionMaps|= COLLADA_LIBRARY_ANIMATIONS;
            }

            if ( setInFirstUnsetInSecond(flags, parsedFlags, Loader::LIBRARY_NODES_FLAG) )
            {
                requiredFunctionMaps|= COLLADA_LIBRARY_NODES;
                requiredFunctionMaps|= COLLADA_LIBRARY_ANIMATIONS;
            }

            if ( (flags & Loader::GEOMETRY_FLAG) != 0 )
            {
                requiredFunctionMaps|= COLLADA_LIBRARY_GEOMETRIES;
            }

            if ( (flags & Loader::MATERIAL_FLAG) != 0 )
            {
                requiredFunctionMaps|= COLLADA_LIBRARY_MATERIALS;
            }

            if ( setInFirstUnsetInSecond(flags, parsedFlags, Loader::EFFECT_FLAG) )
            {
                requiredFunctionMaps|= COLLADA_LIBRARY_EFFECTS;
                requiredFunctionMaps|= COLLADA_LIBRARY_ANIMATIONS;
            }

            if ( (flags & Loader::CAMERA_FLAG) != 0 )
            {
                requiredFunctionMaps|= COLLADA_LIBRARY_CAMERAS;
                //requiredFunctionMaps|= COLLADA_LIBRARY_ANIMATIONS;
            }

            if ( (flags & Loader::IMAGE_FLAG) != 0 )
            {
                requiredFunctionMaps|= COLLADA_LIBRARY_IMAGES;
            }

            if ( (flags & Loader::LIGHT_FLAG) != 0 )
            {
                requiredFunctionMaps|= COLLADA_LIBRARY_LIGHTS;
            }

            if ( (flags & Loader::ANIMATION_FLAG) != 0 )
            {
                requiredFunctionMaps|= COLLADA_LIBRARY_ANIMATIONS;
            }

            if ( (flags & Loader::ANIMATION_LIST_FLAG) != 0 )
            {
                requiredFunctionMaps|= COLLADA_LIBRARY_ANIMATIONS;

                requiredFunctionMaps|= COLLADA_LIBRARY_VISUAL_SCENES;
                afterLoadParsedObjectFlags |= Loader::VISUAL_SCENES_FLAG;

                requiredFunctionMaps|= COLLADA_LIBRARY_NODES;
                afterLoadParsedObjectFlags |= Loader::LIBRARY_NODES_FLAG;

                requiredFunctionMaps|= COLLADA_LIBRARY_EFFECTS;
                afterLoadParsedObjectFlags |= Loader::EFFECT_FLAG;

                //requiredFunctionMaps|= COLLADA_LIBRARY_CAMERAS;
                //requiredFunctionMaps|= COLLADA_LIBRARY_LIGHTS;
            }

            if ( (flags & Loader::CONTROLLER_FLAG) != 0 )
            {
                requiredFunctionMaps|= COLLADA_LIBRARY_CONTROLLERS;

                requiredFunctionMaps|= COLLADA_LIBRARY_VISUAL_SCENES;
                afterLoadParsedObjectFlags |= Loader::VISUAL_SCENES_FLAG;

                requiredFunctionMaps|= COLLADA_LIBRARY_NODES;
                afterLoadParsedObjectFlags |= Loader::LIBRARY_NODES_FLAG;
            }

            if ( (flags & Loader::SKIN_CONTROLLER_DATA_FLAG) != 0 )
            {
                requiredFunctionMaps|= COLLADA_LIBRARY_CONTROLLERS;
            }


            // Fills function map
            for ( size_t i = 0; i < flagsMapMapSize; ++i )
            {
                const FlagsMapPair& libraryFlagsFunctionMapPair = flagsMapMap[i];
                if ( (requiredFunctionMaps & libraryFlagsFunctionMapPair.flag) != 0 )
                {
                    functionMap.insert(libraryFlagsFunctionMapPair.functionMap.begin(), libraryFlagsFunctionMapPair.functionMap.end());
                }
            }

            parsedFlags = afterLoadParsedObjectFlags;
        }
    }

    //------------------------------
    void VersionParser::createFunctionMap14()
    {
        createFunctionMap<LibraryFlagsFunctionMapPair14, COLLADASaxFWL14::ColladaParserAutoGen14Private::ElementFunctionMap>( mFlags, mParsedFlags, mFunctionMap14, libraryFlagsFunctionMapMap14, libraryFlagsFunctionMapMapSize14 );
    }
    //------------------------------
    void VersionParser::createFunctionMap15()
    {
        createFunctionMap<LibraryFlagsFunctionMapPair15, COLLADASaxFWL15::ColladaParserAutoGen15Private::ElementFunctionMap>( mFlags, mParsedFlags, mFunctionMap15, libraryFlagsFunctionMapMap15, libraryFlagsFunctionMapMapSize15 );
    }

    //------------------------------
    VersionParser::VersionParser(GeneratedSaxParser::IErrorHandler* errorHandler,
        FileLoader* fileLoader,
        int flags,
        int& parsedFlags)
        : GeneratedSaxParser::Parser( errorHandler )
        , mFileLoader( fileLoader )
        , mFlags( flags )
        , mParsedFlags( parsedFlags )
        , mPrivateParser14( 0 )
        , mPrivateParser15( 0 )
    {

    }

    //------------------------------
    VersionParser::~VersionParser()
    {

    }

    //------------------------------
    bool VersionParser::createAndLaunchParser()
    {
        const COLLADABU::URI& fileURI = mFileLoader->getFileUri();
        String nativePath = fileURI.toNativePath();
        const char* fileName = nativePath.c_str();
#if defined(GENERATEDSAXPARSER_XMLPARSER_LIBXML)
        GeneratedSaxParser::LibxmlSaxParser versionSaxParser( this );
#elif defined(GENERATEDSAXPARSER_XMLPARSER_EXPAT)
        GeneratedSaxParser::ExpatSaxParser versionSaxParser( this, XMLPARSER_BUFFERSIZE );
#endif
        bool success = versionSaxParser.parseFile( fileName );

 //       mFileLoader->postProcess();

        delete mPrivateParser14;
        delete mPrivateParser15;

        mFileLoader->setPrivateParser( (COLLADASaxFWL14::ColladaParserAutoGen14Private*)0 );
        mFileLoader->setPrivateParser( (COLLADASaxFWL15::ColladaParserAutoGen15Private*)0 );

        return success;
    }

    //------------------------------
    bool VersionParser::createAndLaunchParser( const char* buffer, int length )
    {
        const COLLADABU::URI& uri = mFileLoader->getFileUri();
        const char* uriString = uri.originalStr().c_str();
//        const char* uriString = uri.getURIString().c_str();
#if defined(GENERATEDSAXPARSER_XMLPARSER_LIBXML)
        GeneratedSaxParser::LibxmlSaxParser versionSaxParser( this );
#elif defined(GENERATEDSAXPARSER_XMLPARSER_EXPAT)
        GeneratedSaxParser::ExpatSaxParser versionSaxParser( this, XMLPARSER_BUFFERSIZE );
#endif
        bool success = versionSaxParser.parseBuffer( uriString, buffer, length );
        
        //       mFileLoader->postProcess();
        
        delete mPrivateParser14;
        delete mPrivateParser15;
        
        mFileLoader->setPrivateParser( (COLLADASaxFWL14::ColladaParserAutoGen14Private*)0 );
        mFileLoader->setPrivateParser( (COLLADASaxFWL15::ColladaParserAutoGen15Private*)0 );
        
        return success;
    }
    
    //------------------------------
    bool VersionParser::elementBegin( const ParserChar* elementName, const ParserAttributes& attributes )
    {
        StringHashPair hashPair = GeneratedSaxParser::Utils::calculateStringHashWithNamespace( elementName );
        StringHash elementHash = hashPair.second;

        if ( elementHash == HASH_ELEMENT_COLLADA )
        {
            if ( attributes.attributes )
            {
                const ParserChar** attributeArray = attributes.attributes;
                while (true)
                {
                    const ParserChar * attribute = *attributeArray;
                    if ( !attribute )
                        break;
                    StringHashPair hashPair = GeneratedSaxParser::Utils::calculateStringHashWithNamespace(attribute);
                    attributeArray++;
                    if ( !attributeArray )
                        return false;
                    const ParserChar* attributeValue = *attributeArray;
                    attributeArray++;

                    StringHash prefix = hashPair.first;
                    StringHash name = hashPair.second;
                    if ( (prefix == 0 && name == HASH_ATTRIBUTE_XMLNS) || prefix == HASH_ATTRIBUTE_XMLNS )
                    {
                        StringHash attrVal = GeneratedSaxParser::Utils::calculateStringHash( attributeValue );
                        if ( attrVal == HASH_NAMESPACE_COLLADA_14 )
                        {
							mFileLoader->setCOLLADAVersion(COLLADA_14);
                            return parse14( elementName, attributes );
                        }
                        else if ( attrVal == HASH_NAMESPACE_COLLADA_15 )
                        {
							mFileLoader->setCOLLADAVersion(COLLADA_15);
                            return parse15( elementName, attributes );
                        }
                    }
                }
            }
            return false;
        }

        return true;
    }

    //------------------------------
    bool VersionParser::elementEnd( const ParserChar* elementName )
    {
        return true;
    }

    //------------------------------
    bool VersionParser::textData( const ParserChar* text, size_t textLength )
    {
        return true;
    }

    //------------------------------
    bool VersionParser::parse14( const ParserChar* elementName, const ParserAttributes& attributes )
    {
        createFunctionMap14();

        // note: rootParser is created with new because it is deleted in IFilePartLoader::~IFilePartLoader()
        RootParser14* rootParser = new RootParser14( mFileLoader );
        mFileLoader->setParserImpl( rootParser );
        mPrivateParser14 = new COLLADASaxFWL14::ColladaParserAutoGen14Private( rootParser, (GeneratedSaxParser::IErrorHandler*)mFileLoader->getErrorHandler() );
        mFileLoader->setPrivateParser( mPrivateParser14 );

        //privateParser.setCallbackObject( &rootParser );
		mPrivateParser14->registerUnknownElementHandler( &mFileLoader->mExtraDataElementHandler );

        if ( !mFunctionMap14.empty() )
        {
            mPrivateParser14->setElementFunctionMap( &mFunctionMap14 );
        }

        getSaxParser()->setParser( mPrivateParser14 );

        return mPrivateParser14->elementBegin( elementName, attributes );
    }
    //------------------------------
    bool VersionParser::parse15( const ParserChar* elementName, const ParserAttributes& attributes )
    {
        createFunctionMap15();

        // note: rootParser is created with new because it is deleted in IFilePartLoader::~IFilePartLoader()
        RootParser15* rootParser = new RootParser15( mFileLoader );
        mFileLoader->setParserImpl( rootParser );
        mPrivateParser15 = new COLLADASaxFWL15::ColladaParserAutoGen15Private( rootParser, (GeneratedSaxParser::IErrorHandler*)mFileLoader->getErrorHandler() );
        mFileLoader->setPrivateParser( mPrivateParser15 );

        //privateParser.setCallbackObject( &rootParser );
		mPrivateParser15->registerUnknownElementHandler( &mFileLoader->mExtraDataElementHandler );

        if ( !mFunctionMap15.empty() )
        {
            mPrivateParser15->setElementFunctionMap( &mFunctionMap15 );
        }

        getSaxParser()->setParser( mPrivateParser15 );

        return mPrivateParser15->elementBegin( elementName, attributes );
    }

	//------------------------------
	COLLADASaxFWL14::StringHash VersionParser::getElementHash( size_t level /*= 0 */ ) const
	{
		if ( mPrivateParser14 )
		{
			return mPrivateParser14->getElementHash( level );
		}
		if ( mPrivateParser15 )
		{
			return mPrivateParser15->getElementHash( level );
		}
		return 0;
	}
}
