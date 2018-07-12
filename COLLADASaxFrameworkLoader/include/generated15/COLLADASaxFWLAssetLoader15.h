/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_ASSETLOADER15_H__
#define __COLLADASAXFWL_ASSETLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLAssetLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class AssetLoader15 : public IParserImpl15
{
private:
AssetLoader* mLoader;

public:
AssetLoader15(AssetLoader* loader)
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

virtual bool begin__unit( const COLLADASaxFWL15::unit__AttributeData& attributeData );

virtual bool end__unit();

virtual bool begin__up_axis();

virtual bool end__up_axis();

virtual bool data__up_axis( const COLLADASaxFWL15::ENUM__up_axis_enum value );

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
AssetLoader15(const AssetLoader15&);
/** Disable default assignment operator. */
const AssetLoader15& operator=(const AssetLoader15&);
};
}
#endif // __COLLADASAXFWL_ASSETLOADER15_H__
