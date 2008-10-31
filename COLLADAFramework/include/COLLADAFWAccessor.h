/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ACCESSOR_H__
#define __COLLADAFW_ACCESSOR_H__

#include "COLLADAFWPrerequisites.h"

namespace COLLADAFW
{

    /** Declares the storage for the graphical representation of an object. */
    class Accessor
    {

    public:

        /** Constructor. */
        Accessor () {}

        /** Destructor. */
        virtual ~Accessor () {}

    };
}

#endif // __COLLADAFW_ACCESSOR_H__