/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	  This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __[!output NAMESPACE_UPPER]_[!output CLASS_NAME_UPPER]_H__
#define __[!output NAMESPACE_UPPER]_[!output CLASS_NAME_UPPER]_H__

#include "COLLADASWPrerequisites.h"
[!if USE_BASE_NAMESPACE && BASE_CLASS_NAME != ""]
#include "[!output BASE_NAMESPACE][!output BASE_CLASS_NAME].h"
[!endif]
[!if !USE_BASE_NAMESPACE && BASE_CLASS_NAME != ""]
#include "[!output NAMESPACE][!output BASE_CLASS_NAME].h"
[!endif]


namespace [!output NAMESPACE]
{

    /** TODO Documentation */
	class [!output CLASS_NAME] [!if BASE_CLASS_NAME != ""][!output ACCESS_STRING] [!output COMPLETE_BASE_CLASS] 
	[!endif]	
	{
	private:
	
	public:

        /** Constructor. */
		[!output CLASS_NAME]();

        /** Destructor. */
		virtual ~[!output CLASS_NAME]();

	private:

        /** Disable default copy ctor. */
		[!output CLASS_NAME]( const [!output CLASS_NAME]& pre );

        /** Disable default assignment operator. */
		const [!output CLASS_NAME]& operator= ( const [!output CLASS_NAME]& pre );

	};

} // namespace [!output NAMESPACE_UPPER]

#endif // __[!output NAMESPACE_UPPER]_[!output CLASS_NAME_UPPER]_H__
