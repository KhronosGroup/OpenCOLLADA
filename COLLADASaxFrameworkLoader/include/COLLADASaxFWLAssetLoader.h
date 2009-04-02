/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_ASSETLOADER_H__
#define __COLLADASAXFWL_ASSETLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"

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

        virtual bool begin__contributor(){SaxVirtualFunctionTest(begin__contributor()); return true;}
        virtual bool end__contributor(){SaxVirtualFunctionTest(end__contributor()); return true;}

        virtual bool begin__author(){SaxVirtualFunctionTest(begin__author()); return true;}
        virtual bool end__author(){SaxVirtualFunctionTest(end__author()); return true;}
        virtual bool data__author( const ParserChar* data, size_t length );

        virtual bool begin__authoring_tool(){SaxVirtualFunctionTest(begin__authoring_tool()); return true;}
        virtual bool end__authoring_tool(){SaxVirtualFunctionTest(end__authoring_tool()); return true;}
        virtual bool data__authoring_tool( const ParserChar* data, size_t length );

        virtual bool begin__comments(){SaxVirtualFunctionTest(begin__comments()); return true;}
        virtual bool end__comments(){SaxVirtualFunctionTest(end__comments()); return true;}
        virtual bool data__comments( const ParserChar* data, size_t length );

        virtual bool begin__copyright(){SaxVirtualFunctionTest(begin__copyright()); return true;}
        virtual bool end__copyright(){SaxVirtualFunctionTest(end__copyright()); return true;}
        virtual bool data__copyright( const ParserChar* data, size_t length );

        virtual bool begin__source_data(){SaxVirtualFunctionTest(begin__source_data()); return true;}
        virtual bool end__source_data(){SaxVirtualFunctionTest(end__source_data()); return true;}
        virtual bool data__source_data( COLLADABU::URI value );

        virtual bool begin__created(){SaxVirtualFunctionTest(begin__created()); return true;}
        virtual bool end__created(){SaxVirtualFunctionTest(end__created()); return true;}
        virtual bool data__created( const ParserChar* data, size_t length );

        virtual bool begin__keywords(){SaxVirtualFunctionTest(begin__keywords()); return true;}
        virtual bool end__keywords(){SaxVirtualFunctionTest(end__keywords()); return true;}
        virtual bool data__keywords( const ParserChar* data, size_t length );

        virtual bool begin__modified(){SaxVirtualFunctionTest(begin__modified()); return true;}
        virtual bool end__modified(){SaxVirtualFunctionTest(end__modified()); return true;}
        virtual bool data__modified( const ParserChar* data, size_t length );

        virtual bool begin__revision(){SaxVirtualFunctionTest(begin__revision()); return true;}
        virtual bool end__revision(){SaxVirtualFunctionTest(end__revision()); return true;}
        virtual bool data__revision( const ParserChar* data, size_t length );

        virtual bool begin__subject(){SaxVirtualFunctionTest(begin__subject()); return true;}
        virtual bool end__subject(){SaxVirtualFunctionTest(begin__subject()); return true;}
        virtual bool data__subject( const ParserChar* data, size_t length );

        virtual bool begin__title(){SaxVirtualFunctionTest(begin__title()); return true;}
        virtual bool end__title(){SaxVirtualFunctionTest(end__title()); return true;}
        virtual bool data__title( const ParserChar* data, size_t length );

        virtual bool begin__unit( const unit__AttributeData& attributeData );
        virtual bool end__unit(){SaxVirtualFunctionTest(end__unit()); return true;}

        virtual bool begin__up_axis(){SaxVirtualFunctionTest(begin__up_axis()); return true;}
        virtual bool end__up_axis(){SaxVirtualFunctionTest(end__up_axis()); return true;}
        virtual bool data__up_axis( const COLLADASaxFWL::ENUM__UpAxisType val );

	private:

        /** Disable default copy ctor. */
		AssetLoader( const AssetLoader& pre );

        /** Disable default assignment operator. */
		const AssetLoader& operator= ( const AssetLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_ASSETLOADER_H__
