/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_ASSETLOADER14_H__
#define __COLLADASAXFWL_ASSETLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLAssetLoader.h"
#include "COLLADASaxFWLIParserImpl14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class AssetLoader14 : public IParserImpl14
{
private:
AssetLoader* mLoader;

public:
AssetLoader14(AssetLoader* loader)
 : mLoader(loader)
{}


virtual bool end__asset();

virtual bool begin__contributor();

virtual bool end__contributor();

virtual bool begin__author();

virtual bool end__author();

virtual bool data__author( const ParserChar* data, size_t length );

virtual bool begin__authoring_tool();

virtual bool end__authoring_tool();

virtual bool data__authoring_tool( const ParserChar* data, size_t length );

virtual bool begin__comments();

virtual bool end__comments();

virtual bool data__comments( const ParserChar* data, size_t length );

virtual bool begin__copyright();

virtual bool end__copyright();

virtual bool data__copyright( const ParserChar* data, size_t length );

virtual bool begin__source_data();

virtual bool end__source_data();

virtual bool data__source_data( COLLADABU::URI value );

virtual bool begin__created();

virtual bool end__created();

virtual bool data__created( const ParserChar* data, size_t length );

virtual bool begin__keywords();

virtual bool end__keywords();

virtual bool data__keywords( const ParserChar* data, size_t length );

virtual bool begin__modified();

virtual bool end__modified();

virtual bool data__modified( const ParserChar* data, size_t length );

virtual bool begin__revision();

virtual bool end__revision();

virtual bool data__revision( const ParserChar* data, size_t length );

virtual bool begin__subject();

virtual bool end__subject();

virtual bool data__subject( const ParserChar* data, size_t length );

virtual bool begin__title();

virtual bool end__title();

virtual bool data__title( const ParserChar* data, size_t length );

virtual bool begin__unit( const COLLADASaxFWL14::unit__AttributeData& attributeData );

virtual bool end__unit();

virtual bool begin__up_axis();

virtual bool end__up_axis();

virtual bool data__up_axis( const COLLADASaxFWL14::ENUM__UpAxisType value );

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
AssetLoader14(const AssetLoader14&);
/** Disable default assignment operator. */
const AssetLoader14& operator=(const AssetLoader14&);
};
}
#endif // __COLLADASAXFWL_ASSETLOADER14_H__
