/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_INODE_H__
#define __COLLADA_INODE_H__

#include "HelperPrerequisites.h"

#include <dom/domTypes.h>

namespace COLLADAFW
{

    /** Declares the storage for the graphical representation of an object. */
    class INode
    {

    public:

        /** Constructor. */
        INode () {}

        /** Destructor. */
        virtual ~INode () {}

        /**
        * Gets the id attribute.
        * @return Returns a xsID of the id attribute.
        */
        virtual xsID getNodeId () = 0;
        /**
        * Gets the name attribute.
        * @return Returns a xsNCName of the name attribute.
        */
        virtual xsNCName getNodeName () = 0;
        /**
        * Gets the sid attribute.
        * @return Returns a xsNCName of the sid attribute.
        */
        virtual xsNCName getNodeSid () = 0;
        /**
        * Gets the type attribute.
        * @return Returns a domNodeType of the type attribute.
        */
        virtual domNodeType getNodeType () = 0;

        virtual xsNCName getTranslateSid () = 0;

        virtual domFloat3 getTranslation () = 0;

        virtual xsNCName getRotateSid () = 0;

        virtual domFloat4 getRotation () = 0;

        
    };
}

#endif // __COLLADA_INODE_H__