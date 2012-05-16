/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INCLUDE_H__
#define __COLLADAFW_INCLUDE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADABUURI.h"


namespace COLLADAFW
{

    /** 
    Imports source code or precompiled binary shaders into the FX Runtime by referencing an external
    resource.
    */
	class Include 	
    {
	private:

        /** Identifier for this source code block or binary shader. Required. */
        String mSid;

        /** Location where the resource can be found. Required. */
        COLLADABU::URI mUrl;
	
	public:

        /** Constructor. */
		Include();

        /** Destructor. */
		virtual ~Include();

        /** Identifier for this source code block or binary shader. Required. */
        const String getSid () const { return mSid; }

        /** Identifier for this source code block or binary shader. Required. */
        void setSid ( const String Sid ) { mSid = Sid; }

        /** Location where the resource can be found. Required. */
        const COLLADABU::URI getUrl () const { return mUrl; }

        /** Location where the resource can be found. Required. */
        void setUrl ( const COLLADABU::URI Url ) { mUrl = Url; }

	private:

        /** Disable default copy ctor. */
		Include( const Include& pre );

        /** Disable default assignment operator. */
		const Include& operator= ( const Include& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_INCLUDE_H__
