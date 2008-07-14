/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_EXTRA_H__
#define __COLLADASTREAMWRITER_EXTRA_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include <map>

namespace COLLADA
{

    /** A class to add an Asset to the stream.*/

    class Extra : public ElementWriter
    {

    public:
        /** Constructor
        @param streamWriter The stream the asset should be written to.*/
        Extra ( StreamWriter* streamWriter ) : ElementWriter ( streamWriter ) {}

        /** Destructor*/
        virtual ~Extra() {}

        /** Opens the extra tag. */
        void openExtra ( const String &extraId="", const String &extraName="", const String &extraType="" );

        /** Closes the extra tag */
        void closeExtra();

    private:

        /** Used to close the current extra. */
        TagCloser mExtraCloser;
    };

} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_EXTRA_H__
