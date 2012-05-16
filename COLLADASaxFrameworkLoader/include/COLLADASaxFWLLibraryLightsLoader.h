/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYLIGHTSLOADER_H__
#define __COLLADASAXFWL_LIBRARYLIGHTSLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLXmlTypes.h"


namespace COLLADAFW
{
	class Light;
}


namespace COLLADASaxFWL
{

	/** Loads all the lights in a library lights.  */
	class LibraryLightsLoader : public FilePartLoader
	{
	private:
		/** The current light.*/
		COLLADAFW::Light* mCurrentLight;

		/** The index of the next color component to read.*/
		size_t mCurrentColorValueIndex;

	public:

        /** Constructor. */
		LibraryLightsLoader( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryLightsLoader();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();


		/** Finishes loading a library effects.*/
		virtual bool end__library_lights();

		
		/** Stores light id and name.*/
		virtual bool begin__light( const light__AttributeData& attributeData );

		/** Sends light to the writer.*/
		virtual bool end__light();


		/** We don't need to do anything here.*/
		virtual bool begin__light__technique_common(){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__light__technique_common(){return true;}


		/** Sets the light type to ambient.*/
		virtual bool begin__light__technique_common__ambient();

		/** We don't need to do anything here.*/
		virtual bool end__light__technique_common__ambient(){return true;}


		/** Add animatable float to sid tree*/
		virtual bool begin__color____TargetableFloat3( const color____TargetableFloat3__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__color____TargetableFloat3();

		/** Set the color of the light.*/
		virtual bool data__color____TargetableFloat3( const float* data, size_t length );


		/** Sets the light type to ambient.*/
		virtual bool begin__directional();

		/** We don't need to do anything here.*/
		virtual bool end__directional(){return true;}


		/** Sets the light type to ambient.*/
		virtual bool begin__point();

		/** We don't need to do anything here.*/
		virtual bool end__point(){return true;}


		/** Add animatable float to sid tree*/
		virtual bool begin__constant_attenuation( const constant_attenuation__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__constant_attenuation();

		/** Set the constant attenuation of the light.*/
		virtual bool data__constant_attenuation( float value );


		/** Add animatable float to sid tree*/
		virtual bool begin__linear_attenuation( const linear_attenuation__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__linear_attenuation();

		/** Set the linear attenuation of the light.*/
		virtual bool data__linear_attenuation( float value );


		/** Add animatable float to sid tree*/
		virtual bool begin__quadratic_attenuation( const quadratic_attenuation__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__quadratic_attenuation();

		/** Set the quadratic attenuation of the light.*/
		virtual bool data__quadratic_attenuation( float value );


		/** Sets the light type to ambient.*/
		virtual bool begin__spot();

		/** We don't need to do anything here.*/
		virtual bool end__spot(){return true;}


		/** Add animatable float to sid tree*/
		virtual bool begin__falloff_angle( const falloff_angle__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__falloff_angle();

		/** Set the fall off angle of the light.*/
		virtual bool data__falloff_angle( float value );


		/** Add animatable float to sid tree*/
		virtual bool begin__falloff_exponent( const falloff_exponent__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__falloff_exponent();

		/** Set the fall off exponent of the light.*/
		virtual bool data__falloff_exponent( float value );
	private:

        /** Disable default copy ctor. */
		LibraryLightsLoader( const LibraryLightsLoader& pre );

        /** Disable default assignment operator. */
		const LibraryLightsLoader& operator= ( const LibraryLightsLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYLIGHTSLOADER_H__
