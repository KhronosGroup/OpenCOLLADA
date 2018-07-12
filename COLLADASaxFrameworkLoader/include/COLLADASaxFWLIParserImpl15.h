/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_IPARSERIMPL15_H__
#define __COLLADASAXFWL_IPARSERIMPL15_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLIParserImpl.h"
#include "COLLADASaxFWLColladaParserAutoGen15.h"

namespace COLLADASaxFWL
{

    /** Tagging interface for objects inheriting generated code for COLLADA 1.5. */
    class IParserImpl15 : public IParserImpl, public COLLADASaxFWL15::ColladaParserAutoGen15
    {
    public:
        IParserImpl15();
        COLLADASaxFWL15::ColladaParserAutoGen15* getGeneratedParser() {return this;}
    };
}

#endif // __COLLADASAXFWL_IPARSERIMPL15_H__
