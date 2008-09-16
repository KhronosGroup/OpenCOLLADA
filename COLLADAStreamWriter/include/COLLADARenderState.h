/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_RENDER_STATE_H__
#define __COLLADASTREAMWRITER_RENDER_STATE_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAStreamWriter.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"
#include "COLLADAPassState.h"

namespace COLLADA
{

    /** Declares the storage for the graphical representation of an object. */
    class RenderState
    {
    private:

    public:
        static const String CG_RENDER_STATE_NAMES[];
        static const PassState::State CG_RENDER_STATES_XREF[];

    public:

        /** Constructor. */
        RenderState () {}

        /** Destructor. */
        ~RenderState () {}

        /** Returns the enumeration type of the current CG state. */
        PassState::State cgStateToColladaTranslation ( const char* cgName );

        /** Returns the collada name of the current CG state. */
        const String colladaToCgStateTranslation ( PassState::State stateType );

        /** Returns the render state count. */
        size_t getTotalRenderStateCount();


    };
}

#endif // __COLLADASTREAMWRITER_RENDER_STATE_H__