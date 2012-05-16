/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SHADERELEMENT_H__
#define __COLLADAFW_SHADERELEMENT_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** TODO Documentation */
	class ShaderElement 	
    {
    public:

        enum Type
        {
            SHADER_TYPE_CONSTANT, 
            SHADER_TYPE_PHONG, 
            SHADER_TYPE_LAMBERT,
            SHADER_TYPE_BLINN
        };

	private:
	
        /** The type of the current shader. */
        Type mType;

	public:

        /** Constructor. */
        ShaderElement ( Type type ) : mType ( type ) {}

        /** Destructor. */
        virtual ~ShaderElement () {}

        /** The type of the current shader. */
        const ShaderElement::Type getType () const { return mType; }

        /** The type of the current shader. */
        void setType ( const ShaderElement::Type Type ) { mType = Type; }

    private:

        /** Disable default copy ctor. */
		ShaderElement( const ShaderElement& pre );

        /** Disable default assignment operator. */
		const ShaderElement& operator= ( const ShaderElement& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SHADERELEMENT_H__
