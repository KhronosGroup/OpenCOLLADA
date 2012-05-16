/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_LIBRARY_MATERIALS_H__
#define __COLLADASTREAMWRITER_LIBRARY_MATERIALS_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWLibrary.h"
#include "COLLADASWInstanceEffect.h"

namespace COLLADASW
{

    /** Class to simply the creation of @a \<library_materials\> and @a \<material\>'s*/
    class LibraryMaterials : public Library, public BaseExtraTechnique
    {

    private:

        /** Used to close the current material */
        TagCloser mMaterialCloser;   

    protected:

        /** The suffix for a new material. */
        static const String MATERIAL_ID_SUFFIX;

    public:

        /** Constructor
        @param streamWriter The stream the @a \<library_materials\> and @a \<material\>'s
        should be written to.
        */
        LibraryMaterials ( StreamWriter *streamWriter );

        /** Destructor*/
        virtual ~LibraryMaterials() {}

    protected:

        /** Writes the opening @a \<material\> tag and, if necessary the opening 
        @a \<library_effects\> tag.
        closeMaterial() must be use to close the opened tags.
        @param materialId the id of the material. 
        @param materialName the name of the material. */
        void openMaterial ( 
            const String &materialId = EMPTY_STRING,
            const String &materialName = EMPTY_STRING );

        /** Adds @a \<instance_effect\> element with the given URI. */
        void addInstanceEffect ( const URI &effectURL );

        /** Closes the tag opened by openEffect()*/
        void closeMaterial();

    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_LIBRARY_MATERIALS_H__
