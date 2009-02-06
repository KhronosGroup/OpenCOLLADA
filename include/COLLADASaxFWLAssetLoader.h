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
        virtual bool end__COLLADA__asset() 
        {
            bool success = writer()->writeGlobalAsset ( mAsset );
            delete mAsset;
            finish();
            return success;
        }

        virtual bool begin__contributor(){return true;}
        virtual bool end__contributor(){return true;}

        virtual bool begin__author(){return true;}
        virtual bool end__author(){return true;}
        virtual bool data__author( const ParserChar* data, size_t length )
        {
            mAsset->appendValuePair ( "author", String ( (char*) data, length ) );
            return true;
        }

        virtual bool begin__authoring_tool(){return true;}
        virtual bool end__authoring_tool(){return true;}
        virtual bool data__authoring_tool( const ParserChar* data, size_t length )
        {
            mAsset->appendValuePair ( "authoring_tool", String ( (char*) data, length ) );
            return true;
        }

        virtual bool begin__comments(){return true;}
        virtual bool end__comments(){return true;}
        virtual bool data__comments( const ParserChar* data, size_t length )
        {
            mAsset->appendValuePair ( "comments", String ( (char*) data, length ) );
            return true;
        }

        virtual bool begin__copyright(){return true;}
        virtual bool end__copyright(){return true;}
        virtual bool data__copyright( const ParserChar* data, size_t length )
        {
            mAsset->appendValuePair ( "copyright", String ( (char*) data, length ) );
            return true;
        }

        virtual bool begin__source_data(){return true;}
        virtual bool end__source_data(){return true;}
        virtual bool data__source_data( const ParserChar* data, size_t length )
        {
            mAsset->appendValuePair ( "source", String ( (char*) data, length ) );
            return true;
        }

        virtual bool begin__created(){return true;}
        virtual bool end__created(){return true;}
        virtual bool data__created( const ParserChar* data, size_t length )
        {
            mAsset->appendValuePair ( "created", String ( (char*) data, length ) );
            return true;
        }

        virtual bool begin__keywords(){return true;}
        virtual bool end__keywords(){return true;}
        virtual bool data__keywords( const ParserChar* data, size_t length )
        {
            mAsset->appendValuePair ( "keywords", String ( (char*) data, length ) );
            return true;
        }

        virtual bool begin__modified(){return true;}
        virtual bool end__modified(){return true;}
        virtual bool data__modified( const ParserChar* data, size_t length )
        {
            mAsset->appendValuePair ( "modified", String ( (char*) data, length ) );
            return true;
        }

        virtual bool begin__revision(){return true;}
        virtual bool end__revision(){return true;}
        virtual bool data__revision( const ParserChar* data, size_t length )
        {
            mAsset->appendValuePair ( "revision", String ( (char*) data, length ) );
            return true;
        }

        virtual bool begin__subject(){return true;}
        virtual bool end__subject(){return true;}
        virtual bool data__subject( const ParserChar* data, size_t length )
        {
            mAsset->appendValuePair ( "subject", String ( (char*) data, length ) );
            return true;
        }

        virtual bool begin__title(){return true;}
        virtual bool end__title(){return true;}
        virtual bool data__title( const ParserChar* data, size_t length )
        {
            mAsset->appendValuePair ( "title", String ( (char*) data, length ) );
            return true;
        }

        virtual bool begin__unit( const unit__AttributeData& attributeData )
        {
            mAsset->getUnit().mLinearUnit = String ( (char*) attributeData.name );
            mAsset->getUnit().mLinearUnitMeter = attributeData.meter;
            return true;
        }
        virtual bool end__unit(){return true;}

        virtual bool begin__up_axis(){return true;}
        virtual bool end__up_axis(){return true;}
        virtual bool data__up_axis( const COLLADASaxFWL::UpAxisType val )
        {
            switch ( val )
            {
            case COLLADASaxFWL::UpAxisType__X_UP:
                mAsset->setUpAxisType ( COLLADAFW::FileInfo::X_UP_STRING );
                break;
            case COLLADASaxFWL::UpAxisType__Y_UP:
                mAsset->setUpAxisType ( COLLADAFW::FileInfo::Y_UP_STRING );
                break;
            case COLLADASaxFWL::UpAxisType__Z_UP:
                mAsset->setUpAxisType ( COLLADAFW::FileInfo::Z_UP_STRING );
                break;
            default:
                mAsset->setUpAxisType ( COLLADAFW::FileInfo::Y_UP_STRING );
            }
            return true;
        }

	private:

        /** Disable default copy ctor. */
		AssetLoader( const AssetLoader& pre );

        /** Disable default assignment operator. */
		const AssetLoader& operator= ( const AssetLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_ASSETLOADER_H__
