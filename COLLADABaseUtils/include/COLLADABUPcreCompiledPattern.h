/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_PCRECOMPILEDPATTERN_H__
#define __COLLADABU_PCRECOMPILEDPATTERN_H__

#include "COLLADABUPrerequisites.h"

struct real_pcre;
typedef struct real_pcre pcre;


namespace COLLADABU
{

    /** Class to manage pre compiled pcre patterns. Depending on the preprocessor flag COLLADABU_USE_PCRE_PRECOMPILED
	it either simple stores a precompiled pattern given to the constructor or it compiles and deletes a pattern.
	If COLLADABU_USE_PCRE_PRECOMPILED is set, the version of pcre must fit the version used to pre compile the pattern
	in OpenCOLLADA.
	*/
	class PcreCompiledPattern 	
	{
	private:
		/** The compiled pattern.*/
		pcre *mCompiledPattern;

		/** True, if we need to free the pattern in the destructor, false otherwise.*/
		bool mFreePattern;

	public:

		/** The compiled pattern is created by compiling @a pattern. The behavior of this constructor is independent of  
		COLLADABU_USE_PCRE_PRECOMPILED.*/
		PcreCompiledPattern( const char* pattern );

        /** Destructor. */
		virtual ~PcreCompiledPattern();

		/** Returns the compiled pattern. */
		pcre* getCompiledPattern() const;

	private:

        /** Disable default copy ctor. */
		PcreCompiledPattern( const PcreCompiledPattern& pre );

        /** Disable default assignment operator. */
		const PcreCompiledPattern& operator= ( const PcreCompiledPattern& pre );

		/** Compiles the pattern.*/
		pcre* compilePattern( const char* pattern );

	};

} // namespace COLLADABU

#endif // __COLLADABU_PCRECOMPILEDPATTERN_H__
