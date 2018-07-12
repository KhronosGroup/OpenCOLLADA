/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_IPARSERIMPL14_H__
#define __COLLADASAXFWL_IPARSERIMPL14_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLIParserImpl.h"
#include "COLLADASaxFWLColladaParserAutoGen14.h"

namespace COLLADASaxFWL
{

    /** Tagging interface for objects inheriting generated code for COLLADA 1.4. */
    class IParserImpl14 : public IParserImpl, public COLLADASaxFWL14::ColladaParserAutoGen14
    {
    public:
        IParserImpl14();
        COLLADASaxFWL14::ColladaParserAutoGen14* getGeneratedParser() {return this;}
    };
}

#endif // __COLLADASAXFWL_IPARSERIMPL14_H__
