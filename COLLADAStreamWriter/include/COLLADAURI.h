/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAStreamWriter.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_URI_H__
#define __COLLADASTREAMWRITER_URI_H__

#include "COLLADAPrerequisites.h"

namespace COLLADA
{
		
	/** Class to handle URIs.*/
	class URI
	{
	private:
		String mFragment;
		String mResource;
		bool mIsValid;

	public:

        /** Creates an URI of the form . Currently it is assumed to be of the form: 
		[@a resource][#@a fragment]. At least one of the parts must not be empty to create a valid URI.*/
		URI(const String& resource, const String& fragment);

        /** Creates an URI from @a uriString. Currently it is assumed to be of the form: 
        [resource][#fragment]. At least one of the parts must not be empty to create a valid URI.*/
        URI(const String& uriString);

		/** Creates an empty URI. This is not a valid URI.*/
		URI():mIsValid(false){}

		/** Sets the resource of the uri.*/
		void setResource(const String& resource);

		/** Returns the resource.*/
		const String& getResource()const{return mResource;}

		/** Sets the fragment of the uri.*/
		void setFragment(const String& fragment);

		/** Returns the fragment.*/
		const String& getFragment()const{return mFragment;}

		/** Returns if the URI is valid*/
		bool isValid()const{return mIsValid;}

		/** Returns a string representing the entire URI*/
		String getURIString()const;

	private:
		/** Checks if the uri is valid.*/
		void validate();

	};
	


} //namespace COLLADA



#endif //__COLLADASTREAMWRITER_URI_H__


