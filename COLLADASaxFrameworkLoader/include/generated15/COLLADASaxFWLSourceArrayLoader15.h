/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_SOURCEARRAYLOADER15_H__
#define __COLLADASAXFWL_SOURCEARRAYLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSourceArrayLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class SourceArrayLoader15 : public IParserImpl15
{
private:
SourceArrayLoader* mLoader;

public:
SourceArrayLoader15(SourceArrayLoader* loader)
 : mLoader(loader)
{}


virtual bool begin__float_array( const COLLADASaxFWL15::float_array__AttributeData& attributeData );

virtual bool end__float_array();

virtual bool data__float_array( const float* data, size_t length );

virtual bool begin__source_type____technique_common();

virtual bool end__source_type____technique_common();

virtual bool begin__accessor( const COLLADASaxFWL15::accessor__AttributeData& attributeData );

virtual bool end__accessor();

virtual bool begin__param____param_type( const COLLADASaxFWL15::param____param_type__AttributeData& attributeData );

virtual bool end__param____param_type();

virtual bool data__param____param_type( const ParserChar* value, size_t length );

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
SourceArrayLoader15(const SourceArrayLoader15&);
/** Disable default assignment operator. */
const SourceArrayLoader15& operator=(const SourceArrayLoader15&);
};
}
#endif // __COLLADASAXFWL_SOURCEARRAYLOADER15_H__
