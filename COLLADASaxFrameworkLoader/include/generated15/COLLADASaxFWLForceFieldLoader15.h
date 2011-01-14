/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_FORCEFIELDLOADER15_H__
#define __COLLADASAXFWL_FORCEFIELDLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLForceFieldLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class ForceFieldLoader15 : public IParserImpl15
{
private:
ForceFieldLoader* mLoader;

public:
ForceFieldLoader15(ForceFieldLoader* loader)
 : mLoader(loader)
{}


virtual bool begin__force_field( const COLLADASaxFWL15::force_field__AttributeData& attributeData );

virtual bool end__force_field();


private:
/** Disable default copy ctor. */
ForceFieldLoader15(const ForceFieldLoader15&);
/** Disable default assignment operator. */
const ForceFieldLoader15& operator=(const ForceFieldLoader15&);
};
}
#endif // __COLLADASAXFWL_FORCEFIELDLOADER15_H__
