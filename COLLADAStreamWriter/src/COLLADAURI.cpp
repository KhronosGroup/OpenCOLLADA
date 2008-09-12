/*
	Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.

	Licensed under the MIT Open Source License, 
	for details please see LICENSE file or the website
	http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAURI.h"
#include "COLLADAUtils.h"

#include <boost/algorithm/string/case_conv.hpp>
//using namespace boost::filesystem;


namespace COLLADA
{

#ifdef WIN32
#define FOLDER_CHAR '\\'
#define UNWANTED_FOLDER_CHAR '/'
#define FOLDER_STRING "\\"
#define UNWANTED_FOLDER_STRING "/"
#else
#define FOLDER_CHAR '/'
#define UNWANTED_FOLDER_CHAR '\\'
#define FOLDER_STRING "/"
#define UNWANTED_FOLDER_STRING "\\"
#endif

	//---------------------------------------------------------------
	URI::URI ( const String& uri )
    : mIsValid ( false )
    , mScheme ( URI::NONE )
    , mPort ( 0 )
    , mPath ( "" )
	{
        initializeURI ( uri );

//         // Find the mFragment.
// 		size_t last = uriString.find_last_of('#');
// 		if ( last == uriString.npos )
// 		{
// 			mPath = COLLADA::Utils::UriEncode(uriString);
// 			mIsValid = mPath.empty() ? false : true;
// 			return;
// 		}
// 
// 		mPath = COLLADA::Utils::UriEncode ( uriString.substr(0, last) );
// 		mFragment.assign(uriString, last + 1, uriString.length() - last);
// 		validate();
	}

    //---------------------------------------------------------------
    void URI::initializeURI ( const String& uri )
    {
        if ( uri.empty() ) return;

        String uriString = uri;

        // Replace all '\\' characters by '/' so the mPath is only using them
        Utils::stringFindAndReplace( uriString, "\\", "/" );

        size_t schemeDelimiterIndex = 0;
        size_t hostIndex = 0;
        size_t hostDelimiterIndex = 0;

        // Find the mScheme from its ':' delimiter
        if ( findScheme ( uriString, schemeDelimiterIndex, hostIndex ) )
        {
            // Find the hostname from its '/' delimiter. 
            if ( findHostname ( uriString, schemeDelimiterIndex, hostIndex, hostDelimiterIndex ) )
            {
                // Find the mPath and the fragment.
                findPathAndFragment ( uriString, hostDelimiterIndex );
            }
        }
    }

	//---------------------------------------------------------------
	URI::URI( const String& path, const String& fragment )
    : mIsValid ( false )
    , mScheme ( URI::FILE )
    , mPort ( 0 )
    , mPath ( path )
    , mFragment ( fragment )
	, mSchemeDelimiter ( "://" )
	{
        if ( mPath.empty() ) 
		{
			mScheme = URI::NONE;
			mSchemeDelimiter = "";
		}

        Utils::stringFindAndReplace ( mPath, "\\", "/" );
        if (mPath.length() > 2 && path[1] == ':') 
            mPath.insert ( mPath.begin(), '/');

		validate();
	}

    //---------------------------------------------------------------
    URI::URI ( 
        Scheme scheme, 
        const String& host, 
        const String& path, 
        const String& fragment )
    : mScheme ( scheme )
    , mHostname ( host )
    , mPort ( 0 )
    , mPath ( path )
    , mFragment ( fragment )
    {
        Utils::stringFindAndReplace ( mPath, "\\", "/" );
        if (mPath.length() > 2 && path[1] == ':') 
            mPath.insert ( mPath.begin(), '/');

        validate();
    }

    //---------------------------------------------------------------
    URI::URI ( 
        Scheme scheme,
        const String& user, 
        const String& passwd, 
        const String& host, 
        unsigned int port,
        const String& path, 
        const String& query,
        const String& fragment)
    : mScheme ( scheme )
    , mUsername( user ) 
    , mPassword( passwd ) 
    , mHostname ( host )
    , mPort ( port )
    , mPath ( path )
    , mFragment ( fragment )
    , mQuery ( query ) 
    {
        Utils::stringFindAndReplace ( mPath, "\\", "/" );
        if (mPath.length() > 2 && path[1] == ':') 
            mPath.insert ( mPath.begin(), '/');

        validate();
    }


	//---------------------------------------------------------------
	String URI::getURIString() const
	{
		String uriString = mPath;

		if ( !mFragment.empty())
			uriString += '#' + mFragment;

		return uriString;
	}

	//---------------------------------------------------------------
	void URI::setPath ( const String& path )
	{
        if ( !path.empty() ) mScheme = URI::FILE;
        mPath = COLLADA::Utils::UriEncode ( path ); 
		validate();
	}


	//---------------------------------------------------------------
	void URI::validate()
	{
		mIsValid = !mPath.empty() || !mFragment.empty();
	}

    //---------------------------------------------------------------
	void URI::setFragment( const String& _fragment )
	{
		mFragment = _fragment;
		validate();
	}

    //---------------------------------------------------------------
    bool URI::findScheme ( const String &uriString, size_t &schemeDelimiterIndex, size_t &hostIndex )
    {
        schemeDelimiterIndex = uriString.find ( ':' );

        if (schemeDelimiterIndex != String::npos && schemeDelimiterIndex > 1)
        {
            String _scheme = uriString.substr(0, schemeDelimiterIndex);

            if ( Utils::equals (_scheme, "FILE") || Utils::equals (_scheme, "file"))
            {
                mScheme = URI::FILE;
            }
            else if (Utils::equals (_scheme, "FTP") || Utils::equals (_scheme, "ftp"))
            {
                mScheme = URI::FTP;
            }
            else if (Utils::equals (_scheme, "HTTP") || Utils::equals (_scheme, "http"))
            {
                mScheme = URI::HTTP;
            }
            else if (Utils::equals (_scheme, "HTTPS") || Utils::equals (_scheme, "https"))
            {
                mScheme = URI::HTTPS;
            }
            else
            {
#ifdef WIN32
                // Scheme not supported (could be a NFS mPath)
                assert ( "Scheme not supported!" );
                return false;
#endif // WIN32
            }

            mSchemeDelimiter = uriString.substr(schemeDelimiterIndex, 3);
            hostIndex = schemeDelimiterIndex + 3;
        }
        else
        {
#ifdef WIN32
            // Check for windows file mPath
            if (schemeDelimiterIndex == 1)
            {
                mPath = "/" + uriString;
#else
            // Check for file mPath
            if (schemeDelimiterIndex == String::npos && uriString[0] == '/')
            {
                mPath = uriString;
#endif
                mSchemeDelimiter = "://";

                // We got a file mPath
                mScheme = URI::FILE;

                // Check for mFragment
                size_t fragmentIndex = mPath.find('#');
                if (fragmentIndex != String::npos)
                {
                    // Extract mFragment
                    mFragment = mPath.substr(fragmentIndex + 1);
                    mPath = mPath.substr(0, fragmentIndex);
                }

                // Our URI is parsed
                return false;
            }
#ifdef WIN32
            // Check for windows UNC mPath
            else if (schemeDelimiterIndex == String::npos && uriString[0] == '/' && uriString[1] == '/')
            {
                // We got a UNC mPath
                mScheme = URI::FILE;
                mSchemeDelimiter = "://";
                hostIndex = 2;
            }
#endif
            else
            {
                // We couldn't detect any mScheme
                mScheme = URI::NONE;
            }
        }

        // We have to parse more parts of the URI.
        return true;
    }

    //---------------------------------------------------------------
    bool URI::findHostname ( 
        const String &uriString, 
        size_t &schemeDelimiterIndex, 
        size_t &hostIndex, 
        size_t &hostDelimiterIndex )
    {
        // Find the mHostname from its '/' delimiter. 
        // The absence of mScheme implies the absence of hostname.
        hostDelimiterIndex = 0;
        if (mScheme != URI::NONE)
        {
            hostDelimiterIndex = uriString.find('/', hostIndex);

            // If we have a URI, then the first piece is always the host.
            if (hostDelimiterIndex == String::npos) hostDelimiterIndex = uriString.length();

            if (hostDelimiterIndex > hostIndex)
            {
                mHostname = uriString.substr(hostIndex, hostDelimiterIndex - hostIndex);

                // Check for mPort
                size_t portIndex = mHostname.find(':');
                if (portIndex != String::npos)
                {
                    String _port = mHostname.substr(portIndex + 1);
                    mPort = atoi(_port.c_str());
                    mHostname = mHostname.substr(0, portIndex);
                }

                if (mHostname.empty() && (uriString.size() > hostDelimiterIndex + 1) && (uriString[hostDelimiterIndex+1] == '/'))
                {
                    // public bug #44 says need file://// for networked paths
                    hostIndex++;

                    while ((uriString.size() > hostDelimiterIndex + 1) && (uriString[hostDelimiterIndex] == '/'))
                    {
                        hostDelimiterIndex++;
                    }

                    size_t realHostDelimiterIndex = uriString.find('/', hostDelimiterIndex);
                    if (realHostDelimiterIndex == String::npos)
                    {
                        // This should not happen, so assume that we have a full filename
                        mScheme = URI::FILE;
                        mPath = uriString;
                        return false;
                    }

                    mHostname = uriString.substr(hostDelimiterIndex, realHostDelimiterIndex - hostDelimiterIndex);
                    hostDelimiterIndex = realHostDelimiterIndex;
                }

                // Check for bad URIs that don't include enough slashes.
                if (mHostname.size() > 1 && (mHostname[1] == ':' || mHostname[1] == '|'))
                {
                    mHostname.clear();
                    hostDelimiterIndex = schemeDelimiterIndex + 2;
                }
            }
        }

        // We have to parse more parts of the URI.
        return true;
    }

    //---------------------------------------------------------------
    void URI::findPathAndFragment ( const String& uriString, size_t &hostDelimiterIndex )
    {
        // Find the mPath
        size_t queryDelimiter = uriString.find('?');
        size_t fragmentDelimiter = uriString.find('#');

        if (queryDelimiter != String::npos) 
            mQuery = uriString.substr(queryDelimiter + 1, fragmentDelimiter - queryDelimiter);
        if (fragmentDelimiter != String::npos) 
            mFragment = uriString.substr(fragmentDelimiter + 1);

        if (queryDelimiter == String::npos && fragmentDelimiter == String::npos)
        {
            mPath = uriString.substr(hostDelimiterIndex);
        }
        else if (queryDelimiter == String::npos && fragmentDelimiter != String::npos)
        {
            mPath = uriString.substr(hostDelimiterIndex, fragmentDelimiter - hostDelimiterIndex);
        }
        else
        {
            mPath = uriString.substr(hostDelimiterIndex, queryDelimiter - hostDelimiterIndex);
        }

        if (mPath.size() > 1 && mPath[1] == '|') mPath[1] = ':';
        else if (mPath.size() > 2 && mPath[2] == '|') mPath[2] = ':';

//         if ( !isFile() )
//         {
//             mPath.append("/");
//         }

        mPath = COLLADA::Utils::UriEncode ( mPath );
    }

    //---------------------------------------------------------------
    bool URI::isFile() const
    {
        return mPath.length() > 1 && mPath[mPath.length()-1] != '/';
    }

    //---------------------------------------------------------------
    String URI::getAbsolutePath() const
    {
        if (mScheme == URI::FILE)
        {
            if (getHostname().empty())
            {
#ifdef WIN32
                // Check if we have a drive letter
                if (mPath[0] == '/' && mPath[3] == '/')
                {
                    String absolutePath;
                    String uri = mPath;

                    // Replace all '/' by '\\' to be compliant with Windows mPath
                    Utils::stringFindAndReplace( uri, UNWANTED_FOLDER_STRING, FOLDER_STRING );

                    // First letter is a drive letter
                    char driveLetter[2];
                    driveLetter[0] = uri[1];
                    driveLetter[1] = '\0';
                    boost::to_upper(driveLetter);

                    absolutePath.append(1, driveLetter[0]);
                    absolutePath.append(uri.substr(2));

                    return absolutePath;
                }
                else 
                {
                    String uri = mPath.substr(1);
                    // Replace all '/' by '\\' to be compliant with Windows mPath
                    Utils::stringFindAndReplace( uri, UNWANTED_FOLDER_STRING, FOLDER_STRING );
                    return uri;
                }
#else
                return mPath;
#endif
            }
        }

        String outString;

        if (mScheme == URI::FTP)
        {
            outString.append("ftp");
        }
        else if (mScheme == URI::HTTP)
        {
            outString.append("http");
        }
        else if (mScheme == URI::HTTPS)
        {
            outString.append("https");
        }


        if (mScheme == URI::FILE)
        {
            if (Utils::equals(getHostname(), "localhost"))
            {
                outString = mPath;
                Utils::stringFindAndReplace( outString, UNWANTED_FOLDER_STRING, FOLDER_STRING );
                return outString;
            }
            // UNC mScheme
            outString.append("\\\\");
        }
        else
        {
            outString.append(mSchemeDelimiter);
        }

        outString.append(getAuthority());
        outString.append(mPath);

        if (mScheme == URI::FILE && !getHostname().empty())
        {
            Utils::stringFindAndReplace( outString, UNWANTED_FOLDER_STRING, FOLDER_STRING );
        }

        // A query can be necessary to specify the actual file...
        if ((mScheme == URI::HTTP || mScheme == URI::HTTPS) 
            && !getQuery().empty())
        {
            outString.append("?");
            outString.append(getQuery());
        }

        return outString;
    }

    //---------------------------------------------------------------
    String URI::getAuthority() const
    {
        String authority;
        String userInformations = getUserInformations();

        if (!userInformations.empty())
        {
            authority.append(userInformations);
            authority.append("@");
        }

        authority.append(getHostname());

        if (getPort() != 0)
        {
            authority.append(":");
            authority.append(Utils::toString(getPort()));
        }

        return authority;
    }

    //---------------------------------------------------------------
    String URI::getUserInformations() const
    {
        // Return a formated string (user[@password])
        if (getUsername().empty()) return "";
        if (getPassword().empty()) return getUsername();
        return getUsername() + ":" + getPassword();
    }

    //---------------------------------------------------------------
    String URI::makeAbsolute ( const String& relativePath ) const
    {
        if ( relativePath.empty() ) return relativePath;
        URI uri ( relativePath );

        makeAbsolute(uri);

        return uri.getAbsolutePath();
    }

    //---------------------------------------------------------------
    void URI::makeAbsolute ( URI& uri ) const
    {
        String filePath = uri.getPath();

        if (uri.getScheme() != URI::NONE)
        {
            return;
        }
        else
        {
            // Since path is relative to this one
            uri.setScheme ( this->mScheme );
            uri.setSchemeDelimiter ( this->mSchemeDelimiter );
            uri.setHostname ( this->mHostname );
            uri.setPort ( this->mPort );
        }

#ifdef WIN32
        if (filePath.size() > 1 && filePath[1] == '|') filePath[1] = ':';
#endif // WIN32


        if (uri.getScheme() == FILE || uri.getScheme() == NONE)
        {
            if ( (!filePath.empty() && (filePath[0] == '\\' || filePath[0] == '/')) || 
                (filePath.size() > 1 && filePath[1] == ':') )
            {
#ifdef WIN32
                // In win32 we need to add the drive to the path
                if ( mPath.size() > 1 )
                {
                    String path = mPath.substr(0, 3);
                    path.append(filePath);
                    Utils::stringFindAndReplace ( path, "\\", "/" );
                    uri.setPath ( path );
                }
#endif

                // Path is already absolute
                return;
            }
        }

        if ( mScheme == HTTP )
        {
            // path is already absolute.
            if (filePath[0] == '/')
            {
                return;
            }
        }


        // Relative file path
        std::vector<String> documentPaths, localPaths;
        extractPathStack ( mPath, documentPaths, false);
        extractPathStack ( filePath, localPaths, true);

        for (std::vector<String>::iterator it = localPaths.begin(); it != localPaths.end(); ++it)
        {
            if ((*it) == ".") {}	// Do nothing
            else if ((*it) == "..")
            {
                // Pop one path out
                if (!documentPaths.empty()) documentPaths.pop_back();
            }
            else // Traverse this path
            {
                documentPaths.push_back(*it);
            }
        }

        // Recreate the absolute filename
        String outPath;

        for (std::vector<String>::iterator it = documentPaths.begin(); it != documentPaths.end(); ++it)
        {
            outPath.append("/");
            outPath.append(*it);
        }

        uri.setPath ( outPath );
    }

    //---------------------------------------------------------------
    URI URI::resolve ( const String& relativePath ) const
    {
        String absolute = makeAbsolute(relativePath);
        return URI(absolute);
    }

    //---------------------------------------------------------------
    void URI::extractPathStack (
        const String& name, 
        std::vector<String>& list, 
        bool includeFilename) const
    {
        list.clear();
        list.reserve(6);

        String split = name;
        Utils::stringFindAndReplace( split, "\\", "/" );

        while (!split.empty())
        {
            // Extract out the next path
            size_t slashIndex = split.find('/');
            if (slashIndex != String::npos && slashIndex != 0)
            {
                list.push_back(split.substr(0, slashIndex));
                split.erase(0, slashIndex + 1);
            }
            else if (slashIndex != 0)
            {
                if (includeFilename) list.push_back(split);
                split.clear();
            }
            else
            {
                split.erase(0, 1);
            }
        }
    }

    //---------------------------------------------------------------
    String URI::makeRelative ( const String& _path ) const
    {
        String filePath = _path;

        if ( !filePath.empty() )
        {
            // First ensure that we have an absolute file path
            filePath = makeAbsolute ( filePath );
            URI uri (filePath) ;
            uri.setScheme( this->getScheme() );

            filePath = uri.getPath();

            if ( !Utils::equals( getHostname(), uri.getHostname() ) )
            {
                // If it's not the same host so we use the absolute path
                return _path;
            }

            // Relative file path
            std::vector<String> documentPaths, localPaths;
            extractPathStack ( mPath, documentPaths, false );
            extractPathStack ( filePath, localPaths, true );

            if (getHostname().empty() && getScheme() == uri.getScheme() && getScheme() == URI::FILE)
            {
                if ( !Utils::equals ( documentPaths.front(), localPaths.front() ) )
                {
                    // We're not on the same drive, return absolute path
                    return _path;
                }

#ifdef WIN32
                // Pop drive from the path stacks
                documentPaths.erase ( documentPaths.begin() );
                localPaths.erase ( documentPaths.begin() );
#endif // WIN32

                // If the next folder is different return absolute path
                if ( documentPaths.empty() || localPaths.empty() || 
                    !Utils::equals ( documentPaths.front(), localPaths.front() ) )
                {
                    return _path;
                }
            }

            // Extract the filename from the stack
            String filename = localPaths.back();
            localPaths.pop_back();

            // Look for commonality in the path stacks
            size_t documentPathCount = documentPaths.size();
            size_t filePathCount = localPaths.size();
            size_t matchIndex = 0;

            for (; matchIndex < filePathCount && matchIndex < documentPathCount; ++matchIndex)
            {
                if ( !Utils::equals ( documentPaths[matchIndex], localPaths[matchIndex]) ) break;
            }

            if (matchIndex > 0)
            {
                // There are some similar parts, so generate the relative filename
                String relativePath;

                if (documentPathCount > matchIndex)
                {
                    // Backtrack the document's path
                    for (size_t i = matchIndex; i < documentPathCount; ++i)
                    {
                        relativePath += "../";
                    }
                }
                else
                {
                    relativePath = "./";
                }

                // Add the file's relative path
                for (size_t i = matchIndex; i < filePathCount; ++i)
                {
                    relativePath += localPaths[i] + "/";
                }

                filePath = relativePath + filename;
            }
        }

        Utils::stringFindAndReplace( filePath, UNWANTED_FOLDER_STRING, FOLDER_STRING );

        return filePath;
    }


    //---------------------------------------------------------------
    String URI::getAbsoluteUri ( bool _fragment ) const
    {
        String outString;

        if (mScheme == URI::FILE)
        {
            outString.append("file");
        }
        else if (mScheme == URI::FTP)
        {
            outString.append("ftp");
        }
        else if (mScheme == URI::HTTP)
        {
            outString.append("http");
        }
        else if (mScheme == URI::HTTPS)
        {
            outString.append("https");
        }

        outString.append(mSchemeDelimiter);
        outString.append(getAuthority());
        outString.append(mPath);

        if ( !mQuery.empty() )
        {
            outString.append("?");
            outString.append(mQuery);
        }

        if (_fragment && !mFragment.empty())
        {
            outString.append("#");
            outString.append(mFragment);
        }

        return outString;
    }

    //---------------------------------------------------------------
    String URI::getRelativeUri ( const URI& uri ) const
    {
        String relativePath = uri.makeRelative(getAbsolutePath());

        // If we got an absolute uri
        if (relativePath.size() > 0 && relativePath[0] != '.')
        {
            return getAbsoluteUri();
        }

        if (!mQuery.empty())
        {
            relativePath.append("?");
            relativePath.append(mQuery);
        }

        if (!mFragment.empty())
        {
            relativePath.append("#");
            relativePath.append(mFragment);
        }

#ifdef WIN32
        Utils::stringFindAndReplace ( relativePath, "\\", "/" );
#endif // WIN32
        return relativePath;
    }


	void URI::parsePath(const String& path,
		/* out */ String& dir,
		/* out */ String& baseName,
		/* out */ String& extension) const
	{
		size_t dotPosition = path.find_last_of(".");
		size_t lastSlashPosition = path.find_last_of("/");
		size_t lastBackSlashPosition = path.find_last_of("\\");
		size_t baseNameBegin = std::max(lastSlashPosition == path.npos ? 0 : lastSlashPosition, lastBackSlashPosition == path.npos ? 0 : lastBackSlashPosition);

		dir.assign(path, 0, baseNameBegin);
		baseName.assign(path, baseNameBegin + 1, dotPosition - baseNameBegin - 1);
		extension.assign(path, dotPosition + 1, path.npos);
	}

	//---------------------------------------------------------------
	String URI::getPathFileBase() const
	{
		String dir, baseName, extension;
		pathComponents(dir, baseName, extension);
		return baseName;
	}

	//---------------------------------------------------------------
	String URI::getPathExtension() const
	{
		String dir, baseName, extension;
		pathComponents(dir, baseName, extension);
		return extension;
	}

	//---------------------------------------------------------------
	String URI::getPathFile() const
	{
		String dir, baseName, extension;
		pathComponents(dir, baseName, extension);
		return baseName + "." + extension;
	}

	//---------------------------------------------------------------
	String URI::getPathDirectory() const
	{
		String dir, baseName, extension;
		pathComponents(dir, baseName, extension);
		return dir;
	}

} //namespace COLLADA

