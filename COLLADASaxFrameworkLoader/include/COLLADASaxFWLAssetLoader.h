/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_ASSETLOADER_H__
#define __COLLADASAXFWL_ASSETLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLXmlTypes.h"

#include "COLLADAFWFileInfo.h"
#include "COLLADAFWIWriter.h"


namespace COLLADASaxFWL
{

    /** TODO Documentation */
    class AssetLoader : public FilePartLoader
    {
	private:
	
        /** Pointer to the asset this loader creates.*/
        COLLADAFW::FileInfo* mAsset;

    public:

        /** Constructor. */
		AssetLoader ( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~AssetLoader ();

        /** Sax callback function for the end of the collada document asset information.*/
        virtual bool end__asset();

        virtual bool begin__contributor(){return true;}
        virtual bool end__contributor(){return true;}

        virtual bool begin__author(){return true;}
        virtual bool end__author(){return true;}
        virtual bool data__author( const ParserChar* data, size_t length );

        virtual bool begin__authoring_tool(){return true;}
        virtual bool end__authoring_tool(){return true;}
        virtual bool data__authoring_tool( const ParserChar* data, size_t length );

        virtual bool begin__comments(){return true;}
        virtual bool end__comments(){return true;}
        virtual bool data__comments( const ParserChar* data, size_t length );

        virtual bool begin__copyright(){return true;}
        virtual bool end__copyright(){return true;}
        virtual bool data__copyright( const ParserChar* data, size_t length );

        virtual bool begin__source_data(){return true;}
        virtual bool end__source_data(){return true;}
        virtual bool data__source_data( COLLADABU::URI value );

        virtual bool begin__created(){return true;}
        virtual bool end__created(){return true;}
        virtual bool data__created( const ParserChar* data, size_t length );

        virtual bool begin__keywords(){return true;}
        virtual bool end__keywords(){return true;}
        virtual bool data__keywords( const ParserChar* data, size_t length );

        virtual bool begin__modified(){return true;}
        virtual bool end__modified(){return true;}
        virtual bool data__modified( const ParserChar* data, size_t length );

        virtual bool begin__revision(){return true;}
        virtual bool end__revision(){return true;}
        virtual bool data__revision( const ParserChar* data, size_t length );

        virtual bool begin__subject(){return true;}
        virtual bool end__subject(){return true;}
        virtual bool data__subject( const ParserChar* data, size_t length );

        virtual bool begin__title(){return true;}
        virtual bool end__title(){return true;}
        virtual bool data__title( const ParserChar* data, size_t length );

        virtual bool begin__unit( const unit__AttributeData& attributeData );
        virtual bool end__unit(){return true;}

        virtual bool begin__up_axis(){return true;}
        virtual bool end__up_axis(){return true;}
        virtual bool data__up_axis( const ENUM__UpAxisType val );

	private:

        /** Disable default copy ctor. */
		AssetLoader( const AssetLoader& pre );

        /** Disable default assignment operator. */
		const AssetLoader& operator= ( const AssetLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_ASSETLOADER_H__
