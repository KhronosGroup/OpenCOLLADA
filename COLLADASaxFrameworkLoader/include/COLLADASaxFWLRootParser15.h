/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_ROOTPARSER15_H__
#define __COLLADASAXFWL_ROOTPARSER15_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLIParserImpl15.h"
#include "COLLADASaxFWLExtraDataLoader.h"


namespace COLLADASaxFWL
{
    class FileLoader;

    /**
    * Inherits all generated public parsers and delegates calls to actual implementations.
    */
    class RootParser15 : public IParserImpl15, public ExtraDataLoader
    {
    private:

        /** FileLoader which does actual work. */
        FileLoader* mFileLoader;

    public:

        RootParser15( FileLoader* fileLoader );

        /** FileLoader which does actual work. */
        FileLoader* getFileLoader () { return mFileLoader; }
        const FileLoader* getFileLoader () const { return mFileLoader; }

        /** Informs about the end of reading the COLLADA file. */
        virtual bool end__COLLADA();

        /** Sax callback function for the beginning of the COLLADA document asset information.*/
        virtual bool begin__asset();

        /** Starts loading the scene.*/
        virtual bool begin__scene();

        /** Starts loading a visual scene.*/
        virtual bool begin__geometry( const COLLADASaxFWL15::geometry__AttributeData& attributeData );

        /** Starts loading a visual scene.*/
        virtual bool begin__visual_scene( const COLLADASaxFWL15::visual_scene__AttributeData& attributeData );

        /** Starts loading a library nodes.*/
        virtual bool begin__library_nodes( const COLLADASaxFWL15::library_nodes__AttributeData& attributeData );

        /** Starts loading a library materials.*/
        virtual bool begin__library_materials( const COLLADASaxFWL15::library_materials__AttributeData& attributeData );

        /** Starts loading a library effects.*/
        virtual bool begin__library_effects( const COLLADASaxFWL15::library_effects__AttributeData& attributeData );

        /** Starts loading a library cameras.*/
        virtual bool begin__library_cameras( const COLLADASaxFWL15::library_cameras__AttributeData& attributeData );

        /** Starts loading a library lights.*/
        virtual bool begin__library_lights( const COLLADASaxFWL15::library_lights__AttributeData& attributeData );

        /** Starts loading a library images.*/
        virtual bool begin__library_images( const COLLADASaxFWL15::library_images__AttributeData& attributeData );

        /** Starts loading a library animations.*/
        virtual bool begin__library_animations( const COLLADASaxFWL15::library_animations__AttributeData& attributeData );

        /** Starts loading a library animations.*/
        virtual bool begin__library_controllers( const COLLADASaxFWL15::library_controllers__AttributeData& attributeData );

        /** Starts loading a library formulas.*/
        virtual bool begin__library_formulas( const COLLADASaxFWL15::library_formulas__AttributeData& attributeData );

		/** Starts loading a library joints.*/
		virtual bool begin__library_joints( const COLLADASaxFWL15::library_joints__AttributeData& attributeData );

		/** Starts loading a library kinematics models.*/
		virtual bool begin__library_kinematics_models( const COLLADASaxFWL15::library_kinematics_models__AttributeData& attributeData );

		/** Starts loading a library articulated systems.*/
		virtual bool begin__library_articulated_systems( const COLLADASaxFWL15::library_articulated_systems__AttributeData& attributeData );

		/** Starts loading a library kinematics scenes.*/
		virtual bool begin__library_kinematics_scenes( const COLLADASaxFWL15::library_kinematics_scenes__AttributeData& attributeData );

        /** Starts loading an extra tag. */
        virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

    private:
        /** Disable default c-ctor and assignment op. */
        RootParser15( const RootParser15& );
        const RootParser15& operator=( const RootParser15& );

		template<class Loader, class Loader15>
		Loader* beginCommon( );

		template<class Loader, class Loader15>
		Loader* beginCommonWithId( const char * id);

		template<class Loader, class Loader15>
		Loader* beginCommonCTorWithId(  const char * id );

    };
}

#endif // __COLLADASAXFWL_ROOTPARSER15_H__
