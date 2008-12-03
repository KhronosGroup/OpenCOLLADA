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
	class Material : public Object<COLLADA_TYPE::MATERIAL>
	{
	private:
	
        /** A text string containing the unique identifier of the element. This value must be
        unique within the instance document. Optional. */
        String mId;

        /** The text string name of this element. Optional. */
        String mName; 

	public:

        /** Constructor. */
		Material ( ObjectId objectId );

        /** Destructor. */
		virtual ~Material ();

        /** A text string containing the unique identifier of the element. This value must be
        unique within the instance document. Optional. */
        const String getId () const { return mId; }

        /** A text string containing the unique identifier of the element. This value must be
        unique within the instance document. Optional. */
        void setId ( const String Id ) { mId = Id; }

        /** The text string name of this element. Optional. */
        const String getName () const { return mName; }

        /** The text string name of this element. Optional. */
        void setName ( const String Name ) { mName = Name; }

	private:

        /** Disable default copy ctor. */
		Material( const Material& pre );

        /** Disable default assignment operator. */
		const Material& operator= ( const Material& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_MATERIAL_H__
