/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INSTANCEEFFECT_H__
#define __COLLADAFW_INSTANCEEFFECT_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWUniqueId.h"


namespace COLLADAFW
{

    /** 
    Instantiates a COLLADA material resource.
    <instance_effect> instantiates an effect definition from the <library_effects> and customize its
    parameters.
    The url attribute references the effect.
    <setparam>s assign values to specific effect and profile parameters that will be unique to the instance.
    <technique_hint>s indicate the desired or last-used technique inside an effect profile. This allows the
    user to maintain the same look-and-feel of the effect instance as the last time that the user used it. Some
    runtime render engines may choose new techniques on the fly, but it is important for some effects and for
    DCC consistency to maintain the same visual appearance during authoring.
    */
	class InstanceEffect 
    {
	private:
	
        /** Identifier for this source code block or binary shader. Required. */
        String mSid;

        /**
        * The name attribute is the text string name of this element. 
        * Optional attribute.
        */
        String mName;

        /** The unique id of the instantiated effect.*/
        UniqueId mInstanciatedEffectId;

	public:

        /** Constructor. */
		InstanceEffect();

        /** Destructor. */
		virtual ~InstanceEffect();

        /** Identifier for this source code block or binary shader. Required. */
        const String getSid () const { return mSid; }

        /** Identifier for this source code block or binary shader. Required. */
        void setSid ( const String Sid ) { mSid = Sid; }

        /**
        * The name attribute is the text string name of this element. 
        * Optional attribute.
        */
        const String getName () const { return mName; }

        /**
        * The name attribute is the text string name of this element. 
        * Optional attribute.
        */
        void setName ( const String Name ) { mName = Name; }

        /** The unique id of the instantiated effect.*/
        const COLLADAFW::UniqueId getInstanciatedEffectId () const { return mInstanciatedEffectId; }

        /** The unique id of the instantiated effect.*/
        void setInstanciatedEffectId ( const UniqueId InstanciatedEffectId ) { mInstanciatedEffectId = InstanciatedEffectId; }

	private:

        /** Disable default copy ctor. */
		InstanceEffect( const InstanceEffect& pre );

        /** Disable default assignment operator. */
		const InstanceEffect& operator= ( const InstanceEffect& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCEEFFECT_H__
