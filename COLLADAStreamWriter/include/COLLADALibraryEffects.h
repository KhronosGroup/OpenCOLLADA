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

#ifndef __COLLADASTREAMWRITER_EFFECTS_H__
#define __COLLADASTREAMWRITER_EFFECTS_H__

#include "COLLADAPrerequisites.h"
#include "COLLADALibrary.h"
#include "COLLADAEffectProfile.h"

namespace COLLADA
{

    /** Class to simply the creation of @a \<library_Effects\> and @a \<effect\>'s*/

    class LibraryEffects : public Library
    {

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_Effects\> and @a \<effect\>'s
        should be written to.
        */
        LibraryEffects ( StreamWriter * streamWriter );

        /** Destructor*/
        virtual ~LibraryEffects() {}

    protected:
        /** Writes the opening @a \<effect\> tag and, if necessary the opening @a \<library_effects\> tag.
        closeVisualScene() must be use to close the opened tags.
        @param id the id of the effect*/
        void openEffect ( const String & id = EMPTY_STRING );

        /** Add @a effectProfile to the current effect*/
        void addEffectProfile ( const EffectProfile & effectProfile )
        {
            effectProfile.add();
        };

        /** Closes the tag opened by openEffect()*/
        void closeEffect();


    private:
        TagCloser mCurrentEffectCloser;    //!< Used to close the current effect
    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_EFFECTS_H__
