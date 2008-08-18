/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAStreamWriter.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAURI.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

	//---------------------------------------------------------------
	URI::URI( const String& uriString )
	{
		size_t last = uriString.find_last_of('#');
			
		if ( last == uriString.npos )
		{
			mResource = COLLADA::Utils::UriEncode(uriString);
			mIsValid = mResource.empty() ? false : true;
			return;
		}

		mResource = COLLADA::Utils::UriEncode(uriString.substr(0, last));
		mFragment.assign(uriString, last + 1, uriString.length() - last);
		validate();
	}

	//---------------------------------------------------------------
	URI::URI( const String& resource, const String& fragment )
	{
		mResource = resource;
		mFragment = fragment;
		validate();
	}

	//---------------------------------------------------------------
	String URI::getURIString() const
	{
		String uriString = mResource;

		if ( !mFragment.empty())
			uriString += '#' + mFragment;

		return uriString;
	}

	//---------------------------------------------------------------
	void URI::setResource( const String& resource )
	{
		mResource = COLLADA::Utils::UriEncode(resource); 
		validate();
	}


	//---------------------------------------------------------------
	void URI::validate()
	{
		mIsValid = !mResource.empty() || !mFragment.empty();
	}

	void URI::setFragment( const String& fragment )
	{
		mFragment = fragment;
		validate();
	}

} //namespace COLLADA

