/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaSourceInput.h"

namespace COLLADAMaya
{

    // --------------------------------------------------------
    bool SourceInput::containsSourceBase ( const Sources* sources, const COLLADASW::SourceBase* searchedSourceBase )
    {
        bool sourceFound = false;

        Sources::const_iterator sourcesIter = sources->begin();
        for ( ; sourcesIter!=sources->end() && !sourceFound; ++sourcesIter )
        {
            const SourceInput& sourceInput = *sourcesIter;
            const COLLADASW::SourceBase& sourceBase = sourceInput.mSource;
            if ( strcmp ( sourceBase.getId().c_str(), searchedSourceBase->getId().c_str() ) == 0 )
                sourceFound = true;
        }

        return sourceFound;
    }

    // --------------------------------------------------------
    bool SourceInput::eraseSourceBase ( Sources* sources, COLLADASW::SourceBase* searchedSourceBase )
    {
        bool sourceFound = false;

        Sources::iterator sourcesIter = sources->begin();
        for ( ; sourcesIter!=sources->end() && !sourceFound; ++sourcesIter )
        {
            SourceInput& sourceInput = *sourcesIter;
            COLLADASW::SourceBase& sourceBase = sourceInput.mSource;
            if ( strcmp ( sourceBase.getId().c_str(), searchedSourceBase->getId().c_str() ) == 0 )
            {
                sourceFound = true;
            }
        }

        if ( sourceFound )
        {
            sources->erase ( sourcesIter );
        }

        return sourceFound;
    }

}