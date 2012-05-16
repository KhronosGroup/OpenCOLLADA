/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADABUStableHeaders.h"
#include "COLLADABUNativeString.h"
#include "COLLADABUStringUtils.h"
#include "COLLADABUPlatform.h"

#include <string>

#ifdef COLLADABU_OS_WIN
#include <Windows.h>
#endif

namespace COLLADABU
{


	NativeString::NativeString(const String& str, Encoding encoding ) : std::string()
	{
		if ( encoding == ENCODING_NATIVE )
		{
			this->assign(str);
		}
		else
		{
			fromWideString(StringUtils::utf8String2WideString(str));
		}
	}

	NativeString::NativeString( const char * s, Encoding encoding /*= ENCODING_NATIVE*/ )
	{
		if ( encoding == ENCODING_NATIVE )
		{
			this->assign(s);
		}
		else
		{
			fromWideString(StringUtils::utf8String2WideString(String(s)));
		}
	}


	void NativeString::fromWideString( const WideString& wideString )
	{
#ifdef COLLADABU_OS_WIN
		int multibyteLength = WideCharToMultiByte( CP_ACP, 0, (LPCWSTR)wideString.c_str(), -1, 0, 0, 0, 0 );

		char * dest = new char[ multibyteLength ];
		WideCharToMultiByte( CP_ACP, 0, (LPCWSTR)wideString.c_str(), -1, dest, multibyteLength, 0, 0 );
		this->assign( dest );
		delete[] dest;
#elif defined (COLLADABU_OS_LINUX) || defined (COLLADABU_OS_MAC)
//# error check if this really works on linux
		size_t maxStringLength = wcstombs( 0, wideString.c_str(), 0 ) + 1; // wideString.length()*MB_CUR_MAX + 1;
		char* dest = new char[ maxStringLength ];
		wcstombs( dest, wideString.c_str(), maxStringLength );

		this->assign( dest );
		delete[] dest;
#else
#    error "No StringUtil::toString defined for your platform"
#endif
	}

	WideString NativeString::toWideString() const
	{
#ifdef COLLADABU_OS_WIN
		wchar_t * dest = new wchar_t[ length() + 1 ];
		int nDest = MultiByteToWideChar ( CP_ACP, 0, c_str(), ( int ) length(),
			dest, ( int ) length() );
		dest[ nDest ] = 0; // null termination
		WideString returnValue( dest );
		delete[] dest;
		return returnValue;
#elif defined (COLLADABU_OS_LINUX) || defined (COLLADABU_OS_MAC)
//# error check if this really works on linux

		size_t maxStringLength = length() + 1;
		wchar_t* dest = new wchar_t[ maxStringLength ];
		mbstowcs( dest, this->c_str(), maxStringLength );

		WideString returnValue( dest );

		delete[] dest;

		return returnValue;

#else
#    error "Not StringUtil::toWideString defined for your platform"
		// this functions doesn'nt  seem to work
		//   return fromUtf8( string );
#endif
	}


	String NativeString::toUtf8String() const
	{
		return StringUtils::wideString2utf8String(toWideString());
	}


} //namespace COLLADA
