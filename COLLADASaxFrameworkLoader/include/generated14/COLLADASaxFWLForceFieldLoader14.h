/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_FORCEFIELDLOADER14_H__
#define __COLLADASAXFWL_FORCEFIELDLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLForceFieldLoader.h"
#include "COLLADASaxFWLIParserImpl14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class ForceFieldLoader14 : public IParserImpl14
{
private:
ForceFieldLoader* mLoader;

public:
ForceFieldLoader14(ForceFieldLoader* loader)
 : mLoader(loader)
{}


virtual bool begin__force_field( const COLLADASaxFWL14::force_field__AttributeData& attributeData );

virtual bool end__force_field();


private:
/** Disable default copy ctor. */
ForceFieldLoader14(const ForceFieldLoader14&);
/** Disable default assignment operator. */
const ForceFieldLoader14& operator=(const ForceFieldLoader14&);
};
}
#endif // __COLLADASAXFWL_FORCEFIELDLOADER14_H__
