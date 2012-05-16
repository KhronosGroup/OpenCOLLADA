/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_CODE_H__
#define __COLLADAFW_CODE_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** 
    Provides an inline block of source code.
    Source code can be inlined into the <effect> declaration to be used to compile shaders.
    */
	class Code 	
    {
	private:
	
        /** A text string value containing the subidentifier of this element. This value must be
        unique within the scope of the parent element. An identifier for the source code
        to allow the block to be locally referenced by other elements. Optional. */
        String mSid;

        /** The code block. */
        String mCode;

	public:

        /** Constructor. */
        Code() {};

        /** Destructor. */
        virtual ~Code () {};

        /** A text string value containing the subidentifier of this element. This value must be
        unique within the scope of the parent element. An identifier for the source code
        to allow the block to be locally referenced by other elements. Optional. */
        const String getSid () const { return mSid; }

        /** A text string value containing the subidentifier of this element. This value must be
        unique within the scope of the parent element. An identifier for the source code
        to allow the block to be locally referenced by other elements. Optional. */
        void setSid ( const String Sid ) { mSid = Sid; }

        /** The code block. */
        const String getCode () const { return mCode; }

        /** The code block. */
        void setCode ( const String Code ) { mCode = Code; }

    private:

        /** Disable default copy ctor. */
		Code( const Code& pre );

        /** Disable default assignment operator. */
		const Code& operator= ( const Code& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_CODE_H__
