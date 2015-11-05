/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_URI_H__
#define __COLLADABU_URI_H__

#include "COLLADABUPrerequisites.h"
#include "COLLADABUUtils.h"


namespace COLLADABU
{
	/**
	* The @c URI is a simple class designed to aid in the parsing and resolution
	* of URI references inside COLLADASW elements.
	* A @c URI is created for every @c anyURL and @c IDREF in the COLLADASW schema.
	* For example, the <instance> element has the url= attribute of type @c anyURL, and the
	* <controller> element has the target= attribute of type @c IDREF.
	* The @c URI class contains a URI string; the @c set() method breaks the string into
	* its components including scheme, authority, path (directory), and fragment.
	* It also has the capability to attempt to resolve this reference
	* into a @c daeElement, through the method @c resolveElement().
	* If a @c URI is stored within a @c daeElement, it fills
	* its container field to point to the containing element.
	*
	* The main API on the @c URI, @c resolveElement(), uses a @c URIResolver
	* to search for the @c daeElement inside a @c daeDatabase.
	*
	* URIs are resolved hierarchically, where each URI is resolved based on
	* the following criteria via itself and its element's base URI, which represents the
	* URI of the document that contains the element, retrieved by
	* <tt>daeElement::getBaseURI().</tt>
	* If no base URI is provided, then the application URI
	* is used as a base.
	*
	* The URI resolution order for the COLLADASW DOM is as follows:
	* - Absolute URI is specified (see definition below):
	*   The URI ignores its parent/base URI when validating.
	* - Relative URI is specified:
	*   The URI uses the base URI to provide the scheme, authority, and base path.
	*    This URI's path is appended to the path given the the base URI.
	*    This URI's file and ID are used.
	* - Each level of URI is resolved in this way against the base URI of the
	*    containing file until the top level is reached.  Then the application URI
	*    is used as the default.
	*
	* <b>Definition of Absolute URI:</b>
	* For the purposes of the COLLADASW DOM, a URI is considered absolute
	* if it starts by specifying a scheme.
	* For example,
	* - file:///c:/data/foo.dae#myScene is an absolute URI.
	* - foo.dae#myScene is relative.
	* - foo.dae is a top-level file reference and is relative.
	* If the URI does not include a pound sign (#), the <tt><i>fragment</i></tt> is empty.
	*/
	class URI
	{
	public:
		/**
		* An enum describing the status of the URI resolution process.
		* This is pretty much entirely useless now. Just use the various accessors
		* to query the state of the uri.
		*/
		enum ResolveState{
			/** No URI specified */
			uri_empty,
			/** URI specified but unresolved */
			uri_loaded,
			/** Resolution pending */
			uri_pending,
			/** Resolution successful */
			uri_success,
			/** Failure due to unsupported URI scheme */
			uri_failed_unsupported_protocol,
			/** Failure because the file was not found */
			uri_failed_file_not_found,
			/** Failure because the fragment was not found */
			uri_failed_id_not_found,
			/** Failure due to an invalid fragment */
			uri_failed_invalid_id,
			/** A flag specifying that the URI should be resolved locally to its own document */
			uri_resolve_local,
			/** A flag specifying that the URI should be resolved using this relative URI */
			uri_resolve_relative,
			/** A flag specifying that the URI should be resolved using this absolute URI */
			uri_resolve_absolute,
			/** Failure due to an invalid reference */
			uri_failed_invalid_reference,
			/** Failure due to an external error */
			uri_failed_externalization,
			/** Failure due to missing document */
			uri_failed_missing_container,
			/** Failure because automatic loading of a document is turned off */
			uri_failed_external_document
		};

	public:
		static const String SCHEME_FILE;
		static const String SCHEME_HTTP;
		static const String SCHEME_HTTPS;

		static const URI INVALID;

	private:
		/** Resolved version of the URI */
		String mUriString;

		/** Original URI before resolution */
		String mOriginalURIString;

		/** scheme component */
		String mScheme;
		/** authority component */
		String mAuthority;
		/** path component */
		String mPath;
		/** query component */
		String mQuery;
		/** fragment component */
		String mFragment;
		/** Indicates, if the URi is valid*/
		bool mIsValid;

	public:
		/**
		* Destructor
		*/
		~URI();

		/**
		* Constructs a URI object from a URI passed in as a string.
		* @param dae The DAE associated with this URI.
		* @param URIString Passed to set() automatically.
		* @param nofrag If true, the fragment part of the URI is stripped off before construction.
		*/
		URI(const String& URIString, bool nofrag = false);

        /**
        * Constructs a URI object from a URI passed in as a null terminated C string.
        * @param uriString Passed to set() automatically.
        */
        URI(const char* uriString);

        /**
        * Constructs a URI object from a URI passed in as a non-terminated C string.
        * @param uriString Passed to set() automatically.
        * @param length Length of given string.
        */
        URI(const char* uriString, size_t length);

        /** Constructs an URI of the form:
		[@a resource][#@a fragment]. At least one of the parts must not be empty to create a valid URI.*/
		URI ( const String& path, const String& fragment );

		/**
		* Constructs a URI object using a <tt><i>baseURI</i></tt> and a <tt><i>mUriString.</i></tt>
		* Calls set(URIString), and @c validate(baseURI).
		* @param baseURI Base URI to resolve against.
		* @param URIString String designating this URI.
		*/
		URI(const URI& baseURI, const String& URIString);

		/**
		* Constructs a URI object based on a simple copy from an existing @c URI.
		* @param constructFromURI  URI to copy into this one.
		*/
		URI(const URI& constructFromURI, bool nofrag = false);

		/**
		* Constructs an invalid URI object
		*/
		URI();

		/** Returns if the URi is valid.*/
		bool isValid() const { return mIsValid; }

		// Returns the fully resolved URI as a string
		const String& getURIString() const;

		// Returns the URI as originally set (i.e. not resolved against the base URI)
		const String& originalStr() const;

		// Setter function for setting the full uri.
		void set(const String& uriStr, const URI* baseURI = 0);

        // Setter function for setting the full uri.
        // @param uriStr Null terminated C string.
        void set(const char* uriStr, const URI* baseURI = 0);

        // Setter function for setting the full uri.
        // @param uriStr Non-terminated C string.
        // @param length Length of uriStr.
        void set(const char* uriStr, size_t length, const URI* baseURI = 0);

		// Setter function for setting the individual uri components.
		void set(const String& scheme,
			const String& authority,
			const String& path,
			const String& query,
			const String& fragment,
			const URI* baseURI = 0);


		// String based component accessors.
		const String& scheme() const;
		const String& authority() const;
		const String& path() const;
		const String& query() const;
		const String& fragment() const;
		const String& id() const; // Alias for fragment()

		// Component setter functions. If you're going to be calling multiple setters, as in
		//   uri.path(path);
		//   uri.fragment(frag);
		// it'd be more efficient to call uri.set once instead.
		void setScheme(const String& scheme);
		void setAuthority(const String& authority);
		void setPath(const String& path);
		void setQuery(const String& query);
		void setFragment(const String& fragment);
		void setId(const String& id); // Alias for uri.fragment(frag)

		// Retrieves the individual path components. For example, in a uri of the form
		// file:/folder/file.dae, dir = /folder/, baseName = file, ext = .dae
		void pathComponents(String& dir, String& baseName, String& ext) const;

		// Individual path component accessors. If you need access to multiple path
		// components, calling pathComponents() will be faster.
		String getPathDir() const;      // URI("/folder/file.dae").getPathDir() == "/folder/"
		String getPathFileBase() const; // URI("/folder/file.dae").getPathFileBase() == "file"
		String getPathExtension() const;      // URI("/folder/file.dae").getPathExtension() == ".dae"
		String getPathFile() const;     // URI("/folder/file.dae").getPathFile() == "file.dae"

		const String& getScheme() const { return mScheme;}
		const String& getProtocol() const { return getScheme();} // Alias for getScheme()
		const String& getAuthority() const { return mAuthority; }
		const String& getPath() const { return mPath; }
		const String& getQuery() const { return mQuery; }
		const String& getFragment() const { return mFragment; }
		const String& getID() const { return getFragment(); } // Alias for getFragment()


		// Path component setter.
		void setPath(const String& dir, const String& baseName, const String& ext);

		// Individual path component setters. If you're going to be calling multiple setters,
		// it'd be more efficient to call set() instead.
		void setPathDir(const String& dir);
		void setPathFileBase(const String& baseName);
		void setPathExtension(const String& ext);
		void setPathFile(const String& file);

		/**
		* Copies the URI specified in <tt><i>from</i></tt> into @c this.
		* Performs a simple copy without validating the URI.
		* @param from URI to copy from.
		*/
		void copyFrom(const URI& from);

		/**
		Makes the "originalURI" in this URI relative to some other uri
		@param uri the URI to make "this" relative to.
		@param ignoreCase If set to false, file paths are considered to be case sensitive, if set to true
		they are considered to be case insensitive.
		@note this is experimental and not fully tested, please don't use in critical code yet.
		*/
		bool makeRelativeTo ( const URI& uri, bool ignoreCase = false );

		/**
		Returns this URI relative to some  @a uri
		@param uri the URI to return "this" relative to.
		@param ignoreCase If set to false, file paths are considered to be case sensitive, if set to true
		they are considered to be case insensitive.
		@note this is experimental and not fully tested, please don't use in critical code yet.
		*/
		URI getRelativeTo ( const URI& uri, bool& success, bool ignoreCase = false ) const;

		/**
		* Comparison operator.
		* @return Returns true if URI's are equal.
		*/
		inline bool operator==(const URI& other) const 
        {
			return mUriString == other.mUriString;
		}

		URI& operator=(const URI& other);
		URI& operator=(const String& uri);

        /**
        * Performs RFC2396 path normalization.
        * @param path Path to be normalized.
        */
        static void normalizeURIPath(char* path);


        /** This function takes a file path in the OS's native format and converts it to
        // a URI reference. If a relative path is given, a relative URI reference is
        // returned. If an absolute path is given, a relative URI reference containing 
        // a fully specified path is returned. Spaces are encoded as %20. The 'type'
        // parameter indicates the format of the nativePath.
        //
        // Examples - Windows
        //   nativePathToUri("C:\myFolder\myFile.dae") --> "/C:/myFolder/myFile.dae"
        //   nativePathToUri("\myFolder\myFile.dae") --> "/myFolder/myFile.dae"
        //   nativePathToUri("..\myFolder\myFile.dae") --> "../myFolder/myFile.dae"
        //   nativePathToUri("\\otherComputer\myFile.dae") --> "//otherComputer/myFile.dae"
        //
        // Examples - Linux/Mac
        //   nativePathToUri("/myFolder/myFile.dae") --> "/myFolder/myFile.dae"
        //   nativePathToUri("../myFolder/myFile.dae") --> "../myFolder/myFile.dae"
        //   nativePathToUri("/my folder/my file.dae") --> "/my%20folder/my%20file.dae" */
        static String nativePathToUri (
            const String& nativePath,
            Utils::SystemType type = Utils::getSystemType() );

        /** This function takes a URI reference and converts it to an OS file path. Conversion
        // can fail if the URI reference is ill-formed, or if the URI contains a scheme other
        // than "file", in which case an empty string is returned. The 'type' parameter
        // indicates the format of the returned native path.
        //
        // Examples - Windows
        //   uriToNativePath("../folder/file.dae") --> "..\folder\file.dae"
        //   uriToNativePath("/folder/file.dae") --> "\folder\file.dae"
        //   uriToNativePath("file:/C:/folder/file.dae") --> "C:\folder\file.dae"
        //   uriToNativePath("file://otherComputer/file.dae") --> "\\otherComputer\file.dae"
        //   uriToNativePath("http://www.slashdot.org") --> "" (it's not a file scheme URI!)
        //
        // Examples - Linux/Mac
        //   uriToNativePath("../folder/file.dae") --> "../folder/file.dae"
        //   uriToNativePath("file:/folder/file.dae") --> "/folder/file.dae"
        //   uriToNativePath("http://www.slashdot.org") --> "" (it's not a file scheme URI!) */
        String toNativePath(Utils::SystemType type = Utils::getSystemType()) const;

		/** Decodes the current URI (replace the %hexadecimal value with special characters). */
		static String uriDecode(const String & sSrc);

		/** Encodes the current URI (replace the special characters with %hexadecimal value). */
		static String uriEncode ( const String & sSrc );

		/* Comparison operator for use in maps.*/
		bool operator<(const URI& rhs)const;

		/** Conversion to size_t for usage in a hash map.*/
		operator size_t() const;

    private:

		/**
		* Resets this URI; frees all string references
		* and returns <tt><i>state</i></tt> to @c empty.
		*/
		void reset();

		/**
		* Provides a shared initialization for all constructors
		*/
		void initialize();

		/** Parses @a path and splits it in its components.*/
		static void parsePath(const String& path,
			/* out */ String& dir,
			/* out */ String& baseName,
			/* out */ String& extension);



        // Returns true if parsing succeeded, false otherwise. 
        // Parsing can fail if the uri reference isn't properly formed.
		static bool parseUriRef(const String& uriRef,
			String& scheme,
			String& authority,
			String& path,
			String& query,
			String& fragment);


		/** Checks if th eURI is valid.*/
		void validate(const URI* baseURI);

		/** Checks if the URI is valid, i.e. it must have path or fragment*/
		void validate();

		static String assembleUri(const String& scheme,
			const String& authority,
			const String& path,
			const String& query,
			const String& fragment,
			bool forceLibxmlCompatible = false);

		void setURI(String _URIString, const URI* baseURI);

    };


	

}


#endif //__COLLADAFW_URI_H__
