/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_IPARSERIMPL_H__
#define __COLLADASAXFWL_IPARSERIMPL_H__

#include "COLLADASaxFWLPrerequisites.h"


namespace COLLADASaxFWL
{

    /**
     * A tagging interface common to all classes inheriting one of the generated parsers.
     */
    class IParserImpl
    {
    private:
        COLLADAVersion mCOLLADAVersion;
    public:
        IParserImpl( COLLADAVersion version ) : mCOLLADAVersion(version){}
        virtual ~IParserImpl(){}
        COLLADAVersion getCOLLADAVersion(){return mCOLLADAVersion;}
    };
}

#endif // __COLLADASAXFWL_IPARSERIMPL_H__
