/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAPassState.h"
#include "COLLADAUtils.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    namespace PassStateFunction
    {

        Function fromString ( const char* val )
        {
            if ( Utils::equals(val, CSWC::COLLADA_FX_FUNCTION_NEVER)) return NEVER;
            else if ( Utils::equals(val, CSWC::COLLADA_FX_FUNCTION_LESS)) return LESS;
            else if ( Utils::equals(val, CSWC::COLLADA_FX_FUNCTION_EQUAL)) return EQUAL;
            else if ( Utils::equals(val, CSWC::COLLADA_FX_FUNCTION_LEQUAL)) return LESS_EQUAL;
            else if ( Utils::equals(val, CSWC::COLLADA_FX_FUNCTION_GREATER)) return GREATER;
            else if ( Utils::equals(val, CSWC::COLLADA_FX_FUNCTION_NEQUAL)) return NOT_EQUAL;
            else if ( Utils::equals(val, CSWC::COLLADA_FX_FUNCTION_GEQUAL)) return GREATER_EQUAL;
            else if ( Utils::equals(val, CSWC::COLLADA_FX_FUNCTION_ALWAYS)) return ALWAYS;
            else return INVALID;
        }

        /** Converts the render state function type to its COLLADA render state function string.
        @param fn The render state function type.
        @return The render state function string. */
        const String& toString ( Function fn )
        {
            switch (fn)
            {
            case NEVER: return CSWC::COLLADA_FX_FUNCTION_NEVER;
            case LESS: return CSWC::COLLADA_FX_FUNCTION_LESS;
            case EQUAL: return CSWC::COLLADA_FX_FUNCTION_EQUAL;
            case LESS_EQUAL: return CSWC::COLLADA_FX_FUNCTION_LEQUAL;
            case GREATER: return CSWC::COLLADA_FX_FUNCTION_GREATER;
            case NOT_EQUAL: return CSWC::COLLADA_FX_FUNCTION_NEQUAL;
            case GREATER_EQUAL: return CSWC::COLLADA_FX_FUNCTION_GEQUAL;
            case ALWAYS: return CSWC::COLLADA_FX_FUNCTION_ALWAYS;
            case INVALID:
            default: return CSWC::COLLADA_ERR_UNKNOWN_INPUT;
            }
        }

    };
}