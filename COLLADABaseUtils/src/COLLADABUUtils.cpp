/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADABUStableHeaders.h"
#include "COLLADABUUtils.h"
#include "COLLADABUPlatform.h"

#include <string.h>
#include <list>
#ifdef _WIN32
#include <Windows.h>
#endif

namespace COLLADABU
{

    const String Utils::FILE_PROTOCOL = "file:///";
    const String Utils::FILE_DELIMITER = "/";
    const char Utils::FILE_DELIMITER_CHAR = '/';

	const String Utils::EMPTY_STRING = String();

    // defines
#define MAX_FILENAME_LEN 512

    // The number of characters at the start of an absolute filename.  e.g. in DOS,
    // absolute filenames start with "X:\" so this value should be 3, in UNIX they start
    // with "\" so this value should be 1. A slash must set to '\\' for DOS or '/' for UNIX.

#if defined(COLLADABU_OS_WIN)
    #define ABSOLUTE_NAME_START 3
    #define SLASH '\\'
#elif defined(COLLADABU_OS_MAC)
    #define ABSOLUTE_NAME_START 1 // TODO Ist das so?
    #define SLASH '/' // TODO Ist das so?
#else
    #define ABSOLUTE_NAME_START 1
    #define SLASH '/'
#endif



    //---------------------------------
    String Utils::checkNCName ( const String &ncName )
    {
        String result;
        result.reserve ( ncName.length() );

        // check if first character is an alpha character
        char firstCharacter = ncName[0];

        if ( isAsciiAlphaChar ( firstCharacter )  )
            result.append ( 1, firstCharacter );
        else
            result.append ( 1, '_' );

        //replace all spaces and colons by underlines
        for ( size_t i = 1; i<ncName.length(); ++i )
        {
            char character = ncName[i];

            if ( isIDChar ( character ) )
                result.append ( 1, character );
            else
                result.append ( 1, '_' );
        }

        return result;
    }

    //---------------------------------
    String Utils::checkID ( const String &id )
    {
        return checkNCName ( id );
    }

    //---------------------------------
    String Utils::translateToXML ( const String &srcString )
    {
        String returnString = "";

        for ( unsigned int i=0; i<srcString.length(); ++i )
        {
            switch ( srcString[i])
            {
//             case '\r':
//                 returnString += "&#13";
//                 break;
            case '<':
                returnString += "&lt;";
                break;
            case '>':
                returnString += "&gt;";
                break;
            case '&':
                returnString += "&amp;";
                break;
            case '"':
                returnString += "&quot;";
                break;
            case '\'':
                returnString += "&apos;";
                break;
            default :
                returnString += srcString[i];
            }
        }

        return returnString;
    }



    //---------------------------------
    String Utils::replaceDot ( const String &text )
    {
        std::stringstream stream;

        for ( size_t i = 0; i < text.length(); ++i )
        {
            if ( text[i] == '.' )
                stream << '_';
            else
                stream << text[i];
        }

        return stream.str();
    }

    //---------------------------------
    void Utils::stringFindAndReplace ( String &source, const String searchString, const String replaceString )
    {
        size_t found = source.find ( searchString );
        if ( found != String::npos )
        {
            size_t searchStrLength = searchString.length();
            size_t replaceStrLength = replaceString.length();
            do
            {
                source.replace ( found, searchStrLength, replaceString );
                found = source.find (searchString, found + replaceStrLength );
            } while ( found != String::npos );
        }

    }

    //---------------------------------
    bool Utils::equals ( const String &str1, const String &str2 )
    {
        return ( strcmp ( str1.c_str(), str2.c_str() ) == 0 );
    }

    //--------------------------------
    bool Utils::equalsIgnoreCase ( const String& s1, const String& s2 )
    {
        String::const_iterator it1=s1.begin();
        String::const_iterator it2=s2.begin();

        // has the end of at least one of the strings been reached?
        while ( (it1!=s1.end()) && (it2!=s2.end()) )
        {
            if(::toupper(*it1) != ::toupper(*it2)) //letters differ?
                // return -1 to indicate 'smaller than', 1 otherwise
                return false;
            // proceed to the next character in each string
            ++it1;
            ++it2;
        }
        size_t size1=s1.size(), size2=s2.size();// cache lengths
        //return -1,0 or 1 according to strings' lengths
        if (size1==size2)
            return true;
        return false;
    }

    //--------------------------------
	Utils::SystemType Utils::getSystemType()
	{
#ifdef COLLADABU_OS_WIN
		return WINDOWS;
#else
		return POSIX;
#endif
	}

    //--------------------------------
    void Utils::split ( const String& text, const String& separators, std::vector<String>& words )
    {
        size_t n = text.length();
        size_t start, stop;

        start = text.find_first_not_of(separators);
        while (start < n)
        {
            stop = text.find_first_of(separators, start);
            if (stop > n) stop = n;
            words.push_back(text.substr(start, stop - start));
            start = text.find_first_not_of(separators, stop+1);
        }
    }
    
#ifdef COLLADABU_OS_WIN
	//--------------------------------
	bool Utils::createDirectoryIfNeeded( const WideString &pathString )
	{
		bool pathExists = false;


		SystemType type = getSystemType();
		if( type != WINDOWS )
			return false;

		const wchar_t* currentPath = _wgetcwd( 0, 0);
		const wchar_t* testPath = pathString.c_str();

		pathExists = _wchdir( testPath ) == 0;
		if( !pathExists )
		{
			_wmkdir( testPath );
			pathExists = _wchdir( testPath ) == 0;
		}

		_wchdir( currentPath );
		return pathExists;

	}
#endif
    
	//--------------------------------
	bool Utils::createDirectoryIfNeeded( const String &pathString )
	{
		bool pathExists = false;

#ifdef COLLADABU_OS_WIN
		SystemType type = getSystemType();
		if( type != WINDOWS )
			return false;

		const char* currentPath = _getcwd( 0, 0);
		const char* testPath = pathString.c_str();

		pathExists = _chdir( testPath ) == 0;
		if( !pathExists )
		{
			_mkdir( testPath );
			pathExists = _chdir( testPath ) == 0;
		}

		_chdir( currentPath );

#else
		SystemType type = getSystemType();
		if( type != POSIX )
			return false;

		const char* currentPath = getcwd( 0, 0);
		const char* testPath = pathString.c_str();
        pathExists = chdir( testPath ) == 0;
		if( !pathExists )
		{
            pathExists = mkdir(testPath, 0755) == false;
        }
        chdir( currentPath );
#endif
		return pathExists;
	}

#ifdef COLLADABU_OS_WIN
	//--------------------------------
	bool Utils::createDirectoryRecursive( const WideString &pathString )
	{
		if (pathString.length() == 0)
			return false;

		WideString path = pathString;

		if (path[path.length()-1] != '/' && path[path.length()-1] != '\\')
			path.push_back('\\');

		std::list<WideString> paths;
		size_t offset = WideString::npos;
		while ((offset != 0) && (offset = pathString.find_last_of(L"/\\", offset)) != WideString::npos)
		{
			paths.push_front(pathString.substr(0, offset + 1));
			if (offset != 0) --offset;
		}

		bool pathExists = true;
		const wchar_t* currentPath = _wgetcwd(0, 0);

		for (std::list<WideString>::const_iterator iPath = paths.begin(); iPath != paths.end(); ++iPath)
		{
			// if path exists
			if (_wchdir((*iPath).c_str()) == 0)
				continue;

			// path does not exist, try to create it
			_wmkdir((*iPath).c_str());
			
			if (_wchdir((*iPath).c_str()) != 0)
			{
				pathExists = false;
				break;
			}
		}

		// Restore current path
		_wchdir(currentPath);
		return pathExists;
	}
#endif
    
	//--------------------------------
	bool Utils::createDirectoryRecursive( const String &pathString )
	{
		if (pathString.length() == 0)
			return false;

		String path = pathString;

		if (path[path.length()-1] != '/' && path[path.length()-1] != '\\')
			path.push_back('\\');

		std::list<String> paths;
		size_t offset = String::npos;
		while ((offset != 0) && (offset = pathString.find_last_of("/\\", offset)) != String::npos)
		{
			paths.push_front(pathString.substr(0, offset + 1));
			if (offset !=0) --offset;
		}

		bool pathExists = true;

		SystemType type = getSystemType();

#ifdef COLLADABU_OS_WIN
		if( type != WINDOWS )
			return false;

		const char* currentPath = _getcwd(0, 0);

		for (std::list<String>::const_iterator iPath = paths.begin(); iPath != paths.end(); ++iPath)
		{
			// if path exists
			if (_chdir((*iPath).c_str()) == 0)
				continue;

			// path does not exist, try to create it
			_mkdir((*iPath).c_str());
			
			if (_chdir((*iPath).c_str()) != 0)
			{
				pathExists = false;
				break;
			}
		}

		// Restore current path
		_chdir(currentPath);
#else
		if( type != POSIX )
			return false;

		const char* currentPath = getcwd(0, 0);

		for (std::list<String>::const_iterator iPath = paths.begin(); iPath != paths.end(); ++iPath)
		{
			// if path exists
			if (chdir((*iPath).c_str()) == 0)
				continue;

			// path does not exist, try to create it
			mkdir((*iPath).c_str(), 0755);
			
			if (chdir((*iPath).c_str()) != 0)
			{
				pathExists = false;
				break;
			}
		}

		// Restore current path
		chdir(currentPath);
#endif
		return pathExists;
	}
    
#ifdef COLLADABU_OS_WIN
	//--------------------------------
	bool Utils::directoryExists( const WideString &pathString )
	{
		bool pathExists = false;


		SystemType type = getSystemType();
		if( type != WINDOWS )
			return false;

		const wchar_t* currentPath = _wgetcwd( 0, 0);
		const wchar_t* testPath = pathString.c_str();

		pathExists = _wchdir( testPath ) == 0;
		_wchdir( currentPath );
		return pathExists;

	}
#endif
    
	//--------------------------------
	bool Utils::directoryExists( const String &pathString )
	{
		bool pathExists = false;

#ifdef COLLADABU_OS_WIN
		SystemType type = getSystemType();
		if( type != WINDOWS )
			return false;

		const char* currentPath = _getcwd( 0, 0);
		const char* testPath = pathString.c_str();

		pathExists = _chdir( testPath ) == 0;
		_chdir( currentPath );
		return pathExists;
#else
		SystemType type = getSystemType();
		if( type != POSIX )
			return false;

        struct stat st;
        if(stat(pathString.c_str(),&st) == 0)
            pathExists = true;
        
#endif

		return pathExists;
	}

	//--------------------------------
	bool Utils::copyFile( const String &source, const String &destination )
	{
		bool copystatus = false;

#ifdef COLLADABU_OS_WIN
		SystemType type = getSystemType();
		if( type != WINDOWS )
			return false;

		char command[4097];
		sprintf(command,"copy \"%s\" \"%s\"", source.c_str(), destination.c_str() );
		size_t length = strlen(command);
		if( length > 4096)
			return false;

		int status = system(command);
        copystatus = (status == 0 ? true : false);
#else
		SystemType type = getSystemType();
		if( type != POSIX )
			return false;

        char command[4097];
        sprintf(command, "/bin/cp \"%s\" \"%s\"", source.c_str(), destination.c_str());
        size_t length = strlen(command);
        if( length > 4096)
            return false;
        
        
        int status = system(command);
        copystatus = (status == 0 ? true : false);
#endif

		return copystatus;
	}

    //--------------------------------
    bool Utils::deleteFile(const String &pathString)
    {
        SystemType type = getSystemType();

#ifdef COLLADABU_OS_WIN
        if (type != WINDOWS)
            return false;
        return DeleteFileA(pathString.c_str()) != FALSE;
#else
        if (type != POSIX)
            return false;
        char command[4097];
        sprintf(command, "rm -f \"%s\"", pathString.c_str());
        int status = system(command);
        return status == 0;
#endif
    }

	//--------------------------------
	bool Utils::fileExistsAndIsReadable( const String &pathString )
	{
		FILE* f = fopen( pathString.c_str(), "r");
		bool readable = (f != 0);
		if( readable )
			fclose(f);
		return readable;
	}
}
