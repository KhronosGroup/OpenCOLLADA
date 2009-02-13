/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYLIGHTSLOADER_H__
#define __COLLADASAXFWL_LIBRARYLIGHTSLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"

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
		virtual bool begin__technique_common__ambient();

		/** We don't need to do anything here.*/
		virtual bool end__technique_common__ambient(){return true;}


		/** We don't need to do anything here.*/
		virtual bool begin__ambient__color( const ambient__color__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__ambient__color();

		/** Set the color of the light.*/
		virtual bool data__ambient__color( const double* data, size_t length );


		/** Sets the light type to ambient.*/
		virtual bool begin__directional();

		/** We don't need to do anything here.*/
		virtual bool end__directional(){return true;}


		/** We don't need to do anything here.*/
		virtual bool begin__directional__color( const directional__color__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__directional__color();

		/** Set the color of the light.*/
		virtual bool data__directional__color( const double* data, size_t length );


		/** Sets the light type to ambient.*/
		virtual bool begin__point();

		/** We don't need to do anything here.*/
		virtual bool end__point(){return true;}


		/** We don't need to do anything here.*/
		virtual bool begin__point__color( const point__color__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__point__color();

		/** Set the color of the light.*/
		virtual bool data__point__color( const double* data, size_t length );


		/** We don't need to do anything here.*/
		virtual bool begin__point__constant_attenuation( const constant_attenuation__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__point__constant_attenuation(){return true;}

		/** Set the constant attenuation of the light.*/
		virtual bool data__point__constant_attenuation( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__point__linear_attenuation( const linear_attenuation__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__point__linear_attenuation(){return true;}

		/** Set the linear attenuation of the light.*/
		virtual bool data__point__linear_attenuation( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__point__quadratic_attenuation( const quadratic_attenuation__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__point__quadratic_attenuation(){return true;}

		/** Set the quadratic attenuation of the light.*/
		virtual bool data__point__quadratic_attenuation( double value );


		/** Sets the light type to ambient.*/
		virtual bool begin__spot();

		/** We don't need to do anything here.*/
		virtual bool end__spot(){return true;}


		/** We don't need to do anything here.*/
		virtual bool begin__spot__color( const spot__color__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__spot__color();

		/** Set the color of the light.*/
		virtual bool data__spot__color( const double* data, size_t length );


		/** We don't need to do anything here.*/
		virtual bool begin__spot__constant_attenuation( const constant_attenuation__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__spot__constant_attenuation(){return true;}

		/** Set the constant attenuation of the light.*/
		virtual bool data__spot__constant_attenuation( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__spot__linear_attenuation( const linear_attenuation__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__spot__linear_attenuation(){return true;}

		/** Set the linear attenuation of the light.*/
		virtual bool data__spot__linear_attenuation( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__spot__quadratic_attenuation( const quadratic_attenuation__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__spot__quadratic_attenuation(){return true;}

		/** Set the quadratic attenuation of the light.*/
		virtual bool data__spot__quadratic_attenuation( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__falloff_angle( const falloff_angle__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__falloff_angle(){return true;}

		/** Set the fall off angle of the light.*/
		virtual bool data__falloff_angle( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__falloff_exponent( const falloff_exponent__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__falloff_exponent(){return true;}

		/** Set the fall off exponent of the light.*/
		virtual bool data__falloff_exponent( double value );
	private:

        /** Disable default copy ctor. */
		LibraryLightsLoader( const LibraryLightsLoader& pre );

        /** Disable default assignment operator. */
		const LibraryLightsLoader& operator= ( const LibraryLightsLoader& pre );

		/** Sets the color of the current light.*/
		bool dataColor( const double* data, size_t length );

		/** Finalizes import of color.*/
		bool endColor();
	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYLIGHTSLOADER_H__
