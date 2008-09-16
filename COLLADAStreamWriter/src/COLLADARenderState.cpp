/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADARenderState.h"
#include "COLLADARenderStateStatic.h"

namespace COLLADA
{

    // -------------------------------
    PassState::State RenderState::cgStateToColladaTranslation( const char* cgName )
    {
        // sanity checks
        if (cgName == NULL || cgName[0] == '\0') return PassState::INVALID;

        const size_t arrayLength = getTotalRenderStateCount();

        // skip to interesting part of the array
        size_t i = 0;
        while ( i<arrayLength && tolower(CG_RENDER_STATE_NAMES[i][0]) != tolower(cgName[0]) ) i++;

        // try to match the string (not case sensitive)
        for ( ; i<arrayLength && tolower(CG_RENDER_STATE_NAMES[i][0]) == tolower(cgName[0]); i++ )
        {
            if ( Utils::equals ( CG_RENDER_STATE_NAMES[i], cgName ) )
                return CG_RENDER_STATES_XREF[i];
        }

        // past the interesting part, we didn't find it.
        return PassState::INVALID;
    }

    // -------------------------------
    const String RenderState::colladaToCgStateTranslation ( PassState::State stateType )
    {
        size_t len = getTotalRenderStateCount();
        for ( size_t i = 0; i < len; i++ )
        {
            if (CG_RENDER_STATES_XREF[i] == stateType)
                return CG_RENDER_STATE_NAMES[i];
        }
        return NULL;
    }

    // -------------------------------
    size_t RenderState::getTotalRenderStateCount()
    {
        return sizeof ( CG_RENDER_STATE_NAMES ) / sizeof ( *CG_RENDER_STATE_NAMES );
    }

}