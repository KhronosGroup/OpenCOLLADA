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

#ifndef __COLLADASTREAMWRITER_LIBRARY_MATERIALS_H__
#define __COLLADASTREAMWRITER_LIBRARY_MATERIALS_H__

#include "COLLADAPrerequisites.h"
#include "COLLADALibrary.h"

namespace COLLADA
{

    /** Class to simply the creation of @a \<library_materials\> and @a \<material\>'s*/

    class LibraryMaterials : public Library
    {

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_materials\> and @a \<material\>'s
        should be written to.
        */
        LibraryMaterials ( StreamWriter * streamWriter );

        /** Destructor*/
        virtual ~LibraryMaterials() {}

    protected:
        /** Adds @a \<material\> element and @a \<instance_effect\> element.
        If not already opened, it opens @a \<library_materials\>*/
        void addInstanceEffect ( const String & effectURL = EMPTY_STRING,
                                 const String & materialId = EMPTY_STRING,
                                 const String & materialName = EMPTY_STRING );


        static const String MATERIAL_ID_SUFFIX;

    private:
    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_LIBRARY_MATERIALS_H__