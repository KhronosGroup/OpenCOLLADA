/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_EFFECTS_H__
#define __COLLADASTREAMWRITER_EFFECTS_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWLibrary.h"
#include "COLLADASWEffectProfile.h"

namespace COLLADASW
{

    /** Class to simply the creation of @a \<library_Effects\> and @a \<effect\>'s*/

    class LibraryEffects : public Library
    {

    private:

         /** Used to close the current effect */
        TagCloser mCurrentEffectCloser;   

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_Effects\> and @a \<effect\>'s
        should be written to.
        */
        LibraryEffects ( StreamWriter * streamWriter );

        /** Destructor*/
        virtual ~LibraryEffects() {}

    protected:

        /** Writes the opening @a \<effect\> tag and, if necessary the opening 
        @a \<library_effects\> tag.
        closeVisualScene() must be use to close the opened tags.
        @param id the id of the effect. */
        void openEffect ( const String& id = EMPTY_STRING );

        /** Add @a effectProfile to the current effect*/
        void addEffectProfile ( EffectProfile& effectProfile );

        /** Closes the tag opened by openEffect()*/
        void closeEffect();

    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_EFFECTS_H__
