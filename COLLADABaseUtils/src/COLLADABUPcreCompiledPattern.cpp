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

#include <cassert>

#ifdef COLLADABU_USE_PCRE_PRECOMPILED
#	if !( PCRE_MAJOR == 7) || !( PCRE_MINOR == 9 )
#		error "Your version of pcre does not fit the pcre version to precompile the pattern in OpenCOLLADA."
#	endif
#endif


namespace COLLADABU
{

    //------------------------------
	PcreCompiledPattern::PcreCompiledPattern( const char* pattern, const char* compiledPattern )
		:
#ifdef COLLADABU_USE_PCRE_PRECOMPILED
		mCompiledPattern( (pcre*) compiledPattern ) 
		, mFreePattern( false )
#else
		mCompiledPattern( compilePattern(pattern) ) 
		, mFreePattern( true )
#endif
	{
	}

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
		assert( compiledPattern );
		return compiledPattern;
	}
} // namespace COLLADABU
