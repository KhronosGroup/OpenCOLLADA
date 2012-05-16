/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_ROOTPARSER14_H__
#define __COLLADASAXFWL_ROOTPARSER14_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLIParserImpl14.h"
#include "COLLADASaxFWLExtraDataLoader.h"


namespace COLLADASaxFWL
{
    class FileLoader;

    /**
    * Inherits all generated public parsers and delegates calls to actual implementations.
    */
    class RootParser14 : public IParserImpl14, public ExtraDataLoader
    {
    private:

        /** FileLoader which does actual work. */
        FileLoader* mFileLoader;

    public:

        RootParser14( FileLoader* fileLoader );

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
        virtual bool begin__geometry( const COLLADASaxFWL14::geometry__AttributeData& attributeData );

        /** Starts loading a visual scene.*/
        virtual bool begin__visual_scene( const COLLADASaxFWL14::visual_scene__AttributeData& attributeData );

        /** Starts loading a library nodes.*/
        virtual bool begin__library_nodes( const COLLADASaxFWL14::library_nodes__AttributeData& attributeData );

        /** Starts loading a library materials.*/
        virtual bool begin__library_materials( const COLLADASaxFWL14::library_materials__AttributeData& attributeData );

        /** Starts loading a library effects.*/
        virtual bool begin__library_effects( const COLLADASaxFWL14::library_effects__AttributeData& attributeData );

        /** Starts loading a library cameras.*/
        virtual bool begin__library_cameras( const COLLADASaxFWL14::library_cameras__AttributeData& attributeData );

        /** Starts loading a library lights.*/
        virtual bool begin__library_lights( const COLLADASaxFWL14::library_lights__AttributeData& attributeData );

        /** Starts loading a library images.*/
        virtual bool begin__library_images( const COLLADASaxFWL14::library_images__AttributeData& attributeData );

        /** Starts loading a library animations.*/
        virtual bool begin__library_animations( const COLLADASaxFWL14::library_animations__AttributeData& attributeData );

        /** Starts loading a library animations.*/
        virtual bool begin__library_controllers( const COLLADASaxFWL14::library_controllers__AttributeData& attributeData );

        /** Starts loading an extra tag. */
        virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

    private:
        /** Disable default c-ctor and assignment op. */
        RootParser14( const RootParser14& );
        const RootParser14& operator=( const RootParser14& );

		template<class Loader, class Loader14>
		Loader* beginCommon();

		template<class Loader, class Loader14>
		Loader* beginCommonWithId( const char * id);

		template<class Loader, class Loader14>
		Loader* beginCommonCTorWithId(  const char * id );


    };
}

#endif // __COLLADASAXFWL_ROOTPARSER14_H__
