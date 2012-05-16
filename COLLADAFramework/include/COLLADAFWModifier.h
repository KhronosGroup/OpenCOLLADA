/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_MODIFIER_H__
#define __COLLADAFW_MODIFIER_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** 
    Provides additional information about the volatility or linkage of a <newparam> declaration.
    Allows COLLADA FX parameter declarations to specify constant, external, or uniform parameters.
    */
	class Modifier 	
    {
    public:

        /** Contains a linkage modifier. Not every linkage modifier is supported by every FX runtime. 
        Valid modifiers are: */
        enum LinkageModifier
        {
            MODIFIER_CONST,
            MODIFIER_UNIFORM,
            MODIFIER_VARYING,
            MODIFIER_STATIC,
            MODIFIER_VOLATILE,
            MODIFIER_EXTERN,
            MODIFIER_SHARED, 
            MODIFIER_UNKNOWN
        };

	private:
	
        /** The linkage modifier. */
        LinkageModifier mLinkageModifier;

	public:

        /** Constructor. */
        Modifier () : mLinkageModifier ( MODIFIER_UNKNOWN ) {}

        /** Constructor. */
		Modifier ( const LinkageModifier& linkageModifier )
            : mLinkageModifier ( linkageModifier )
        {}

        /** Destructor. */
        virtual ~Modifier() {}

        /** The linkage modifier. */
        const Modifier::LinkageModifier getLinkageModifier () const { return mLinkageModifier; }

	private:

        /** Disable default copy ctor. */
		Modifier( const Modifier& pre );

        /** Disable default assignment operator. */
		const Modifier& operator= ( const Modifier& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_MODIFIER_H__
