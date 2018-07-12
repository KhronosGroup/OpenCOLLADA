/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_MATERIAL_H__
#define __COLLADAFW_MATERIAL_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"
#include "COLLADAFWUniqueId.h"


namespace COLLADAFW
{

    /** Represents a material. Material instantiate effects and have the ability to overwrite certain 
	parameters of the instantiated effect.*/
	class Material : public ObjectTemplate<COLLADA_TYPE::MATERIAL>
	{
	private:
	
        /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;

		/** The unique id of the effect instantiated in this material.*/
		UniqueId mInstantiatedEffect;

        /** The text string name of this element. Optional. */
        String mName; 

	public:

        /** Constructor. */
		Material ( const UniqueId& uniqueId );

        /** Destructor. */
		virtual ~Material ();

        /**
        * The original object id, if it in the original file format exist. 
        */
        const String& getOriginalId () const { return mOriginalId; }

        /**
        * The original object id, if it in the original file format exist. 
        */
        void setOriginalId ( const String& val ) { mOriginalId = val; }

        /** The text string name of this element. Optional. */
        const String& getName () const { return mName; }

        /** The text string name of this element. Optional. */
        void setName ( const String& Name ) { mName = Name; }

		/** Return the unique id of the referenced effect.*/
		const UniqueId& getInstantiatedEffect() const { return mInstantiatedEffect; }

		/** Sets the unique id of the referenced effect.*/
		void setInstantiatedEffect( const UniqueId& val) { mInstantiatedEffect = val; }

	private:

        /** Disable default copy ctor. */
//		Material( const Material& pre );

        /** Disable default assignment operator. */
//		const Material& operator= ( const Material& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_MATERIAL_H__
