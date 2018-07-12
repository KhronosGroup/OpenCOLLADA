/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_SOURCEARRAYLOADER14_H__
#define __COLLADASAXFWL_SOURCEARRAYLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSourceArrayLoader.h"
#include "COLLADASaxFWLIParserImpl14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class SourceArrayLoader14 : public IParserImpl14
{
private:
SourceArrayLoader* mLoader;

public:
SourceArrayLoader14(SourceArrayLoader* loader)
 : mLoader(loader)
{}


virtual bool begin__float_array( const COLLADASaxFWL14::float_array__AttributeData& attributeData );

virtual bool end__float_array();

virtual bool data__float_array( const float* data, size_t length );

virtual bool begin__animation__source__technique_common();

virtual bool end__animation__source__technique_common();

virtual bool begin__accessor( const COLLADASaxFWL14::accessor__AttributeData& attributeData );

virtual bool end__accessor();

virtual bool begin__param( const COLLADASaxFWL14::param__AttributeData& attributeData );

virtual bool end__param();

virtual bool data__param( const ParserChar* value, size_t length );

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
SourceArrayLoader14(const SourceArrayLoader14&);
/** Disable default assignment operator. */
const SourceArrayLoader14& operator=(const SourceArrayLoader14&);
};
}
#endif // __COLLADASAXFWL_SOURCEARRAYLOADER14_H__
