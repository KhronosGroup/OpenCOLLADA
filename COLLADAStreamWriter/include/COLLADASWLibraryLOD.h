/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_LIBRARY_LOD_H__
#define __COLLADASTREAMWRITER_LIBRARY_LOD_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWLibrary.h"
//#include "COLLADASWLight.h"

namespace COLLADASW
{

    /** Class to simply the creation of @a \<library_lod\> and @a \<lod\>'s*/
	class LibraryLOD : public Library, public BaseExtraTechnique
    {

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_lod\> and @a \<lod\>'s
        should be written to.
        */
		LibraryLOD(StreamWriter* streamWriter);

        /** Destructor*/
		virtual ~LibraryLOD() {}

    protected:
        /** Adds @a \<lod\> element. If not already opened, it opens @a \<library_lod\>*/
//        void addLod ( const Light& light );

    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_LIBRARY_LOD_H__
