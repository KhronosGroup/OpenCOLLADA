/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
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

