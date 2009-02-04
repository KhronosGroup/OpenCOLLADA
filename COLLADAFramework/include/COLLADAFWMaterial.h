/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_MATERIAL_H__
#define __COLLADAFW_MATERIAL_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"


namespace COLLADAFW
{

    /** TODO Documentation */
	class Material : public ObjectTemplate<COLLADA_TYPE::MATERIAL>
	{
	private:
	
        /** The text string name of this element. Optional. */
        String mName; 

	public:

        /** Constructor. */
		Material ( ObjectId objectId );

        /** Destructor. */
		virtual ~Material ();

        /** The text string name of this element. Optional. */
        const String& getName () const { return mName; }

        /** The text string name of this element. Optional. */
        void setName ( const String& Name ) { mName = Name; }

	private:

        /** Disable default copy ctor. */
		Material( const Material& pre );

        /** Disable default assignment operator. */
		const Material& operator= ( const Material& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_MATERIAL_H__
