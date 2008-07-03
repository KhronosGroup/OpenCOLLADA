/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAX_EXTRA_H__
#define __COLLADAMAX_EXTRA_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAStreamWriter.h"
#include "COLLADAExtraTechnique.h"
#include "COLLADAExtra.h"


class Object;

namespace COLLADAMax
{
    /** Base class to export extra tags in max.*/

    class Extra : public COLLADA::ElementWriter
    {

    public:
        /** The technique profile name.*/
        static const String TECHNIQUE_PROFILE;

    private:
        COLLADA::Extra mExtra;
        COLLADA::Technique mTechnique;

    public:
        /** Constructor
         @param streamWriter the stream the extra tags should be written to.*/
        Extra ( COLLADA::StreamWriter * streamWriter );

        /** Destructor*/
        virtual ~Extra()
        {}


    protected:
        /** Opens a new @a  \<technique\> element.*/
        void openTechnique();

        /** closes the extra tag*/
        void closeExtra();

        /** Adds a parameter to the technique. */

        template <class T>
        void addParameter ( const String &paramName, const T &value )
        {
            mTechnique.addParameter ( paramName, value );
        }


    };


}


#endif //__COLLADAMAX_EXTRA_H__

