/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADABUStableHeaders.h"
#include "COLLADABUPcreCompiledPattern.h"

#include "pcre.h"

namespace COLLADABU
{

	//------------------------------
	PcreCompiledPattern::PcreCompiledPattern( const char* pattern )
		:
		mCompiledPattern( compilePattern(pattern) ) 
		, mFreePattern( true )
	{
	}


    //------------------------------
	PcreCompiledPattern::~PcreCompiledPattern()
	{
		if ( mFreePattern )
		{
			pcre_free(mCompiledPattern);
		}
	}

	//------------------------------
	pcre* PcreCompiledPattern::compilePattern( const char* pattern )
	{
		const char *error;
		int erroffset;
		pcre* compiledPattern = pcre_compile(
							    pattern,              /* the pattern */
						        0,                    /* default options */
			                    &error,               /* for error message */
			                    &erroffset,           /* for error offset */
			                    0);                /* use default character tables */
		COLLADABU_ASSERT( compiledPattern );
		return compiledPattern;
	}

	//------------------------------
	pcre* PcreCompiledPattern::getCompiledPattern() const
	{
		return mCompiledPattern;
	}

} // namespace COLLADABU
