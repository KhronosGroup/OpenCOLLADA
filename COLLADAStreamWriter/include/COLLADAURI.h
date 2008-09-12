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
#include <vector>

namespace COLLADA
{
		
	/** Class to handle URIs.*/
	class URI
	{

    public:
    
        enum Scheme
        {
            NONE,
            FILE,
            FTP,
            HTTP,
            HTTPS
        };
    
    private:

        /** The URI scheme */
        Scheme mScheme;
        
        /** The URI scheme specific part */
        String mSchemeDelimiter;

        /** The URI user used to connect to the host */
        String mUsername;

        /** The URI password used to connect to the host */
        String mPassword;

        /** The URI the host */
        String mHostname;

        /** The URI port used to connect to the host */
        unsigned int mPort;

        /** The URI path represent the name of the filename. */
        String mPath;

        /** The URI query */
        String mQuery;

        /** The URI fragment represent the COLLADA id of the element targeted. */
        String mFragment;

        /** True, if the current URI is valid. */
        bool mIsValid;

	public:

        /** Constructor.
        Creates an URI from @a uriString. Currently it is assumed to be of the form: 
        [path][#fragment]. At least one of the parts must not be empty to create a valid URI.
        @param uriString The string val for the URI. */
        URI ( const String& uriString );

        /** Creates an URI of the form . Currently it is assumed to be of the form: 
		[@a resource][#@a fragment]. At least one of the parts must not be empty to create a valid URI.*/
		URI ( const String& path, const String& fragment );

        /** Constructor.
        @param scheme The scheme to use in the construction of the URI.
        @param username The username to use in the construction of the URI.
        @param passwd The password to use in the construction of the URI.
        @param host The host to use in the construction of the URI.
        @param port The port to use in the construction of the URI.
        @param path The path to use in the construction of the URI.
        @param query The query to use in the construction of the URI.
        @param fragment The fragment to use in the construction of the URI. */
        URI ( 
            Scheme scheme, 
            const String& username, 
            const String& passwd, 
            const String& host, 
            unsigned int port, 
            const String& path = "", 
            const String& query = "", 
            const String& fragment = "" );


        /** Constructor.
        @param scheme The scheme to use in the construction of the URI.
        @param host The host to use in the construction of the URI.
        @param path The path to use in the construction of the URI.
        @param fragment The fragment to use in the construction of the URI. */
        URI (
            Scheme scheme, 
            const String& host, 
            const String& path = "", 
            const String& fragment = "");


		/** Creates an empty URI. This is not a valid URI.*/
		URI()
        : mIsValid ( false )
        , mScheme ( URI::NONE )
        , mPort ( 0 )
        , mPath ( "" )
        , mFragment ( "" )
        {}

        /** Creates an URI from @a uriString. The Uri will be initialized with 
        * the given String (the Scheme, host and path will be extracted).
        * @param uriString The string val for the URI. */
        void initializeURI ( const String& uri );

		/** Sets the path of the uri.*/
		void setPath ( const String& path );

		/** Returns the path.*/
		const String& getPath() const { return mPath; }

		/** Sets the fragment of the uri.*/
		void setFragment(const String& fragment);

		/** Returns the fragment.*/
		const String& getFragment()const{return mFragment;}

		/** Returns if the URI is valid*/
		bool isValid()const{return mIsValid;}

		/** Returns a string representing the entire URI*/
		String getURIString()const;

        /** The URI scheme */
        const COLLADA::URI::Scheme getScheme() const { return mScheme; }
        void setScheme(COLLADA::URI::Scheme val) { mScheme = val; }

        /** The URI scheme specific part */
        const COLLADA::String getSchemeDelimiter() const { return mSchemeDelimiter; }
        void setSchemeDelimiter(COLLADA::String val) { mSchemeDelimiter = val; }

        /** The URI user used to connect to the host */
        const COLLADA::String getUsername() const { return mUsername; }
        void setUsername(COLLADA::String val) { mUsername = val; }

        /** The URI password used to connect to the host */
        const COLLADA::String getPassword() const { return mPassword; }
        void setPassword(COLLADA::String val) { mPassword = val; }

        /** The URI the host */
        const COLLADA::String getHostname() const { return mHostname; }
        void setHostname(COLLADA::String val) { mHostname = val; }

        /** The URI port used to connect to the host */
        const unsigned int getPort() const { return mPort; }
        void setPort(unsigned int val) { mPort = val; }

        /** The URI query */
        const COLLADA::String getQuery() const { return mQuery; }
        void setQuery(COLLADA::String val) { mQuery = val; }

        /** Makes an absolute path from a relative path and this URI
        @param	relativePath	The relative path
        @return The absolute path. */
        String makeAbsolute ( const String& relativePath ) const;

        /** Makes the passed in URI relative to this URI
        @param uri The relative or absolute URI */
        void makeAbsolute ( URI& uri ) const;

        /** Resolves a URI from a relative path against this URI
        @param	relativePath	The relative path.
        @return The newly contructed URI. */
        URI resolve ( const String& relativePath ) const;

        /** Retrieves an absolute path from the URI.
        @return The URI absolute path. */
        String getAbsolutePath() const;

        /** Makes a relative path from a uri
        @param	_path The path.
        @return The relative path. */
        String makeRelative ( const String& _path ) const;

        /** Retrieves the authority string from the URI. ("[userInfo@]host[:port]")
        @return The URI authority string. */
        String getAuthority() const;

        /** Retrieves the user information from the URI.
        @return The URI user information. */
        String getUserInformations() const;

        /** Retrieves an absolute URI string from the URI.
        @param fragment Whether to return a string with the fragment
        @return The URI string. */
        String getAbsoluteUri ( bool fragment = true ) const;

        /** Retrieves an relative URI string from the URI.
        @return The URI string. */
        String getRelativeUri ( const URI& uri ) const;

		/** Splits the path into ist components: directory, base file name, extension
		@param dir Is set to the directory.
		@param baseName Is set to the base name.
		@param extension Is set to the extension.*/
		void pathComponents(String& dir, String& baseName, String& extension) const {
			parsePath(mPath, dir, baseName, extension);
		}

		/** Splits the path into ist components: directory, base file name, extension
		@parm path The path to split
		@param dir Is set to the directory.
		@param baseName Is set to the base name.
		@param extension Is set to the extension.*/
		void parsePath(const String& path,
			/* out */ String& dir,
			/* out */ String& baseName,
			/* out */ String& extension) const;

		/** Returns the base file name without extension.
		URI("/foo/bar.ext").getPathFileBase == "bar"*/
		String getPathFileBase() const;

		/** Returns the file name with extension.
		URI("/foo/bar.ext").getPathFile == "bar.ext"*/
		String getPathFile() const;

		/** Returns the file name with extension.
		URI("/foo/bar.ext").getPathDirectory == "/foo"*/
		String getPathDirectory() const;

		/** Returns the file name with extension.
		URI("/foo/bar.ext").getPathExtension == "ext"*/
		String getPathExtension() const;
	private:

		/** Checks if the uri is valid.*/
		void validate();

        /** Find the scheme from its ':' delimiter.
        Returns true, if we have to continue the initialization (host and path). */
        bool findScheme ( 
            const String& uriString, 
            size_t& schemeDelimiterIndex, 
            size_t& hostIndex );

        /** Find the hostname from its '/' delimiter. 
        The absence of scheme implies the absence of hostname.
        Returns true, if we have to continue the initialization (path and fragment) */
        bool findHostname ( 
            const String& uriString, 
            size_t& schemeDelimiterIndex, 
            size_t& hostIndex, 
            size_t& hostDelimiterIndex );

        /** Find the path. */
        void findPathAndFragment ( const String& uriString, size_t& hostDelimiterIndex );

        /** Check if the current URI is a file. */
        bool isFile() const;

        /** For a relative path, extract the list of the individual 
        paths that must be traversed to get to the file. */
        void extractPathStack (
            const String& name, 
            std::vector<String>& list, 
            bool includeFilename) const;

	};
	


} //namespace COLLADA



#endif //__COLLADASTREAMWRITER_URI_H__


