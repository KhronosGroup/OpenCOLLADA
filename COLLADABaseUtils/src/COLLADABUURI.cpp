/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADABUStableHeaders.h"
#include "COLLADABUURI.h"
#include "COLLADABUStringUtils.h"
#include "COLLADABUPcreCompiledPattern.h"
#include "COLLADABUHashFunctions.h"

#include <algorithm>
#include "pcre.h"

namespace COLLADABU
{


	const int regExpMatchesVectorLength = 30;    /* should be a multiple of 3 */


	const String URI::SCHEME_FILE = "file";
	const String URI::SCHEME_HTTP = "http";
	const String URI::SCHEME_HTTPS = "https";
	
	const URI URI::INVALID = URI();



	const char HEX2DEC[256] = 
	{
		/*       0  1  2  3   4  5  6  7   8  9  A  B   C  D  E  F */
		/* 0 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
		/* 1 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
		/* 2 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
		/* 3 */  0, 1, 2, 3,  4, 5, 6, 7,  8, 9,-1,-1, -1,-1,-1,-1,

		/* 4 */ -1,10,11,12, 13,14,15,-1, -1,-1,-1,-1, -1,-1,-1,-1,
		/* 5 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
		/* 6 */ -1,10,11,12, 13,14,15,-1, -1,-1,-1,-1, -1,-1,-1,-1,
		/* 7 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,

		/* 8 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
		/* 9 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
		/* A */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
		/* B */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,

		/* C */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
		/* D */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
		/* E */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
		/* F */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1
	};



	//---------------------------------
	String URI::uriEncode ( const String & sSrc )
	{
		const char DEC2HEX[16 + 1] = "0123456789ABCDEF";
		const unsigned char * pSrc = ( const unsigned char * ) sSrc.c_str();
		const int SRC_LEN = ( const int ) sSrc.length();
		unsigned char * const pStart = new unsigned char[SRC_LEN * 3];
		unsigned char * pEnd = pStart;
		const unsigned char * const SRC_END = pSrc + SRC_LEN;

		for ( ; pSrc < SRC_END; ++pSrc )
		{
			if ( *pSrc > 32 && *pSrc < 128)
				*pEnd++ = *pSrc;
			else
			{
				// escape this char
				*pEnd++ = '%';
				*pEnd++ = DEC2HEX[*pSrc >> 4];
				*pEnd++ = DEC2HEX[*pSrc & 0x0F];
			}
		}

		String sResult ( ( char * ) pStart, ( char * ) pEnd );

		delete [] pStart;
		return sResult;
	}


	String URI::uriDecode(const String & sSrc)
	{
		// Note from RFC1630: "Sequences which start with a percent
		// sign but are not followed by two hexadecimal characters
		// (0-9, A-F) are reserved for future extension"

		const unsigned char * pSrc = (const unsigned char *)sSrc.c_str();
		const size_t SRC_LEN = sSrc.length();
		const unsigned char * const SRC_END = pSrc + SRC_LEN;
		// last decodable '%'
		const unsigned char * const SRC_LAST_DEC = SRC_END - 2;

		char * const pStart = new char[SRC_LEN];
		char * pEnd = pStart;

		while (pSrc < SRC_LAST_DEC)
		{
			if (*pSrc == '%')
			{
				char dec1, dec2;
				if (    (char)(-1) != (dec1 = HEX2DEC[*(pSrc + 1)])
				     && (char)(-1) != (dec2 = HEX2DEC[*(pSrc + 2)]))
				{
					*pEnd++ = (dec1 << 4) + dec2;
					pSrc += 3;
					continue;
				}
			}

			*pEnd++ = *pSrc++;
		}

		// the last 2- chars
		while (pSrc < SRC_END)
			*pEnd++ = *pSrc++;

		std::string sResult(pStart, pEnd);
		delete [] pStart;
		return sResult;
	}


	void setStringFromMatches(String& matchString, const String& entireString, int *resultPositions, int index)
	{
		int& startPosition = resultPositions[2*index];
		int& endPosition = resultPositions[2*index+1];
		if ( startPosition >= 0)
		{
			matchString.assign( entireString, startPosition, endPosition - startPosition);
		}
	}


	void URI::initialize()
	{
		reset();
	}

	URI::~URI() { }


	URI::URI(const String& uriStr, bool nofrag)
		: mIsValid(false)
	{
		initialize();

		if (nofrag) {
			size_t pos = uriStr.find_last_of('#');
			if (pos != String::npos) {
				set(uriStr.substr(0, pos));
				return;
			}
		}

		set(uriStr);
	}


    URI::URI(const char* uriString)
		: mIsValid(false)
	{
		initialize();
        if (uriString) {
            set(uriString);
        }
    }


    URI::URI(const char* uriString, size_t length)
		: mIsValid(false)
	{
		initialize();
        if (uriString && length > 0) {
            set(uriString, length);
        }
    }


    URI::URI( const String& path, const String& fragment )
		: mIsValid(false)
	{
		initialize();
		set("", "", path, "", fragment);
	}


	URI::URI()
        : mIsValid( false)
	{
		initialize();
	}

	URI::URI(const URI& baseURI, const String& uriStr)
		: mIsValid(false)
	{
		initialize();
		set(uriStr, &baseURI);
	}

	URI::URI(const URI& copyFrom_, bool nofrag) 
		: mIsValid(false)
	{
		initialize();
		if (nofrag) {
			const String& uriStr = copyFrom_.getURIString();
			size_t pos = uriStr.find_last_of('#');
			if (pos != String::npos) {
				set(uriStr.substr(0, pos));
				return;
			}
			set(uriStr);
		}
		else
		{
			mUriString = copyFrom_.mUriString;
			mOriginalURIString = copyFrom_.mOriginalURIString;
			mScheme = copyFrom_.mScheme;
			mAuthority = copyFrom_.mAuthority;
			mPath = copyFrom_.mPath;
			mQuery = copyFrom_.mQuery;
			mFragment = copyFrom_.mFragment;
			mIsValid = copyFrom_.mIsValid;
		}
	}

	void URI::copyFrom(const URI& copyFrom)
	{
//		set(copyFrom.originalStr());
		mUriString = copyFrom.mUriString;
		mOriginalURIString = copyFrom.mOriginalURIString;
		mScheme = copyFrom.mScheme;
		mAuthority = copyFrom.mAuthority;
		mPath = copyFrom.mPath;
		mQuery = copyFrom.mQuery;
		mFragment = copyFrom.mFragment;
		mIsValid = copyFrom.mIsValid;
	}

	URI& URI::operator=(const URI& other) {
		copyFrom(other);
		return *this;
	}

	URI& URI::operator=(const String& uriStr) {
		set(uriStr);
		return *this;
	}

	void URI::reset() 
	{
		// Clear everything 
		mUriString.clear();
		mOriginalURIString.clear();
		mScheme.clear();
		mAuthority.clear();
		mPath.clear();
		mQuery.clear();
		mFragment.clear();
	}


	const String& URI::getURIString() const {
		return mUriString;
	}

	const String& URI::originalStr() const {
		return mOriginalURIString;
	}

	void URI::parsePath(const String& path,
		/* out */ String& dir,
		/* out */ String& baseName,
		/* out */ String& extension) {
			// !!!steveT Currently, if we have a file name that begins with a '.', as in
			// ".emacs", that will be treated as having no base name with an extension
			// of ".emacs". We might want to change this behavior, so that the base name
			// is considered ".emacs" and the extension is empty. I think this is more
			// in line with what path parsers in other libraries/languages do, and it
			// more accurately reflects the intended structure of the file name.

			// The following implementation cannot handle paths like this:
			// /tmp/se.3/file

			// regular expression: "(.*/)?(.*)?"
			static const PcreCompiledPattern findDirCompiledPattern("(.*/)?(.*)?");

			pcre* findDir = findDirCompiledPattern.getCompiledPattern();


			// regular expression: "([^.]*)?(\.(.*))?"
			static const PcreCompiledPattern findExtCompiledPattern("([^.]*)?(\\.(.*))?");
			pcre* findExt = findExtCompiledPattern.getCompiledPattern();
			
			String tmpFile;
			dir.clear();
			baseName.clear();
			extension.clear();

			int dirMatches[regExpMatchesVectorLength];

			int  dirResult = pcre_exec(
										findDir,           /* the compiled pattern */
										0,                 /* no extra data - we didn't study the pattern */
										path.c_str(),      /* the subject string */
										(int)path.size(),  /* the length of the subject */
										0,                 /* start at offset 0 in the subject */
										0,                 /* default options */
										dirMatches,     /* output vector for substring information */
										regExpMatchesVectorLength); /* number of elements in the output vector */

			if ( dirResult >= 0 )
			{	
				setStringFromMatches(dir, path, dirMatches, 1);
				setStringFromMatches(tmpFile, path, dirMatches, 2);

				int extMatches[regExpMatchesVectorLength];

				int  extResult = pcre_exec(
											findExt,           /* the compiled pattern */
											0,                 /* no extra data - we didn't study the pattern */
											tmpFile.c_str(),      /* the subject string */
											(int)tmpFile.size(),  /* the length of the subject */
											0,                 /* start at offset 0 in the subject */
											0,                 /* default options */
											extMatches,     /* output vector for substring information */
											regExpMatchesVectorLength); /* number of elements in the output vector */

				
				if ( extResult >= 0 )
				{
					setStringFromMatches(baseName, tmpFile, extMatches, 1);
					setStringFromMatches(extension, tmpFile, extMatches, 3);
				}
			}
	}

	void URI::set(const String& uriStr_, const URI* baseURI) {
		// We make a copy of the uriStr so that set(mOriginalURIString, ...) works properly.
		String uriStr = uriStr_;
		reset();
		mOriginalURIString = uriStr;

		if (!parseUriRef(uriStr, mScheme, mAuthority, mPath, mQuery, mFragment)) 
		{
			reset();
			return;
		}
		else
		{
			mIsValid = true;
		}

		validate(baseURI);
	}

    void URI::set(const char* uriStr_, const URI* baseURI) {
        // We make a copy of the uriStr so that set(mOriginalURIString, ...) works properly.
        String uriStr = uriStr_;
        reset();
        mOriginalURIString = uriStr;

        if (!parseUriRef(uriStr, mScheme, mAuthority, mPath, mQuery, mFragment)) 
        {
            reset();
            return;
        }
        else
        {
            mIsValid = true;
        }

        validate(baseURI);
    }

    void URI::set(const char* uriStr_, size_t length, const URI* baseURI) {
        // We make a copy of the uriStr so that set(mOriginalURIString, ...) works properly.
        String uriStr(uriStr_, length);
        reset();
        mOriginalURIString = uriStr;

        if (!parseUriRef(uriStr, mScheme, mAuthority, mPath, mQuery, mFragment)) 
        {
            reset();
            return;
        }
        else
        {
            mIsValid = true;
        }

        validate(baseURI);
    }

	void URI::set(const String& scheme_,
		const String& authority_,
		const String& path_,
		const String& query_,
		const String& fragment_,
		const URI* baseURI)
	{
		set(assembleUri(scheme_, authority_, path_, query_, fragment_), baseURI);
	}


	const String& URI::scheme() const { return mScheme; }
	const String& URI::authority() const { return mAuthority; }
	const String& URI::path() const { return mPath; }
	const String& URI::query() const { return mQuery; }
	const String& URI::fragment() const { return mFragment; }
	const String& URI::id() const { return fragment(); }


	namespace {
		String addSlashToEnd(const String& s) {
			return (!s.empty() && s[s.length()-1] != '/')  ?  s + '/' : s;
		}
	}

	void URI::pathComponents(String& dir, String& baseName, String& ext) const {
		parsePath(mPath, dir, baseName, ext);
	}

	String URI::getPathDir() const {
		String dir, base, ext;
		parsePath(mPath, dir, base, ext);
		return dir;
	}

	String URI::getPathFileBase() const {
		String dir, base, ext;
		parsePath(mPath, dir, base, ext);
		return base;
	}

	String URI::getPathExtension() const {
		String dir, base, ext;
		parsePath(mPath, dir, base, ext);
		return ext;
	}

	String URI::getPathFile() const {
		String dir, base, ext;
		parsePath(mPath, dir, base, ext);
		String pathFile = base;
		if ( !ext.empty() )
			pathFile += "." + ext;
		return pathFile;
	}

	void URI::setPath(const String& dir, const String& baseName, const String& ext) {
        //FR:Is this a bug or intention, but ext in OpenCOLLADA originaly seems to expect "." here
        //We relax this by just add "." when not present
        if (ext.length() > 0) {
            if (ext.c_str()[0] != '.') {
                setPath(addSlashToEnd(dir) + baseName + "." + ext);
                return;
            }
        }
        
		setPath(addSlashToEnd(dir) + baseName + ext);
	}

	void URI::setPathDir(const String& dir) {
		String tmp, base, ext;
		parsePath(mPath, tmp, base, ext);
		setPath(addSlashToEnd(dir), base, ext);
	}

	void URI::setPathFileBase(const String& baseName) {
		String dir, tmp, ext;
		parsePath(mPath, dir, tmp, ext);
		setPath(dir, baseName, ext);
	}

	void URI::setPathExtension(const String& ext) 
	{
		String dir, base, tmp;
		parsePath(mPath, dir, base, tmp);
		setPath(dir, base, ext);
	}

	void URI::setPathFile(const String& file) {
		String dir, base, ext;
		parsePath(mPath, dir, base, ext);
		setPath(dir, file, "");
	}


	void URI::setScheme(const String& scheme_) { set(scheme_, mAuthority, mPath, mQuery, mFragment); };
	void URI::setAuthority(const String& authority_) { set(mScheme, authority_, mPath, mQuery, mFragment); }
	void URI::setPath(const String& path_) { set(mScheme, mAuthority, path_, mQuery, mFragment); }
	void URI::setQuery(const String& query_) { set(mScheme, mAuthority, mPath, query_, mFragment); }
	void URI::setFragment(const String& fragment_) { set(mScheme, mAuthority, mPath, mQuery, fragment_); }
	void URI::setId(const String& id) { setFragment(id); }


	namespace {
		void normalize(String& path) {
            String tmp (path);
			URI::normalizeURIPath(const_cast<char*>(tmp.c_str()));
            path.assign ( tmp.c_str () );
		}
	}

	void URI::validate()
	{
		mIsValid = !mPath.empty() || !mFragment.empty();
	}

	void URI::validate(const URI* baseURI)
	{
		// If no base URI was supplied, use the container's document URI. If there's
		// no container or the container doesn't have a doc URI, use the application
		// base URI.
/*		if (!baseURI) {
			if (container)
			{
				if (container->getDocument())
				{
					if (container->getDocument()->isZAERootDocument())
						baseURI = &container->getDocument()->getExtractedFileURI();
					else
						baseURI = container->getDocumentURI();
				}
			}
			if (!baseURI)
				baseURI = &dae->getBaseURI();
			if (this == baseURI)
				return;
		}
*/
		// This is rewritten according to the updated rfc 3986
		if (!mScheme.empty()) // if defined(R.scheme) then
		{
			// Everything stays the same except path which we normalize
			// T.scheme    = R.scheme;
			// T.authority = R.authority;
			// T.path      = remove_dot_segments(R.path);
			// T.query     = R.query;
			normalize(mPath);
		}
		else
		{
			if (!mAuthority.empty()) // if defined(R.authority) then
			{
				// Authority and query stay the same, path is normalized
				// T.authority = R.authority;
				// T.path      = remove_dot_segments(R.path);
				// T.query     = R.query;
				normalize(mPath);
			}
			else
			{
				if (mPath.empty())  // if (R.path == "") then
				{
					if ( baseURI )
					{
						// T.path = Base.path;
						mPath = baseURI->mPath;

						//if defined(R.query) then
						//   T.query = R.query;
						//else
						//   T.query = Base.query;
						//endif;
						if (mQuery.empty())
							mQuery = baseURI->mQuery;
					}
				}
				else
				{
					if (mPath[0] == '/')  // if (R.path starts-with "/") then
					{
						// T.path = remove_dot_segments(R.path);
						normalize(mPath);
					}
					else
					{
						// T.path = merge(Base.path, R.path);
						if ( baseURI )
						{
							if (!baseURI->mAuthority.empty() && baseURI->mPath.empty()) // authority defined, path empty
							{
								mPath.insert(0, "/");
							}
							else 
							{
								String dir, baseName, ext;
								parsePath(baseURI->mPath, dir, baseName, ext);
								mPath = dir + mPath;
							}
							// T.path = remove_dot_segments(T.path);
							normalize(mPath);
						}
					}
					// T.query = R.query;
				}
				// T.authority = Base.authority;
				if ( baseURI )
					mAuthority = baseURI->mAuthority;
			}
			// T.scheme = Base.scheme;
			if ( baseURI )
				mScheme = baseURI->mScheme;
		}
		// T.fragment = R.fragment;

		// Reassemble all this into a String version of the URI
		mUriString = assembleUri(mScheme, mAuthority, mPath, mQuery, mFragment);

		validate();
	}



	// This code is loosely based on the RFC 2396 normalization code from
	// libXML. Specifically it does the RFC steps 6.c->6.g from section 5.2
	// The path is modified in place, there is no error return.
	void URI::normalizeURIPath(char* path)
	{
		char *cur, // location we are currently processing
			*out; // Everything from this back we are done with

		// Return if the path pointer is null

		if ( !path ) 
			return;

		// Skip any initial / characters to get us to the start of the first segment

		for(cur=path; *cur == '/'; cur++);

		// Return if we hit the end of the String

		if (*cur == 0) return;

		// Keep everything we've seen so far.

		out = cur;

		// Analyze each segment in sequence for cases (c) and (d).

		while (*cur != 0) 
		{
			// (c) All occurrences of "./", where "." is a complete path segment, are removed from the buffer String.

			if ((*cur == '.') && (*(cur+1) == '/')) 
			{
				cur += 2;
				// If there were multiple slashes, skip them too
				while (*cur == '/') cur++;
				continue;
			}

			// (d) If the buffer String ends with "." as a complete path segment, that "." is removed.

			if ((*cur == '.') && (*(cur+1) == 0))
				break;

			// If we passed the above tests copy the segment to the output side

			while (*cur != '/' && *cur != 0)
			{
				*(out++) = *(cur++);
			}

			if(*cur != 0)
			{
				// Skip any occurrences of // at the end of the segment

				while ((*cur == '/') && (*(cur+1) == '/')) cur++;

				// Bring the last character in the segment (/ or a null terminator) into the output

				*(out++) = *(cur++);
			}
		}

		*out = 0;

		// Restart at the beginning of the first segment for the next part

		for(cur=path; *cur == '/'; cur++);
		if (*cur == 0) return;

		// Analyze each segment in sequence for cases (e) and (f).
		//
		// e) All occurrences of "<segment>/../", where <segment> is a
		//    complete path segment not equal to "..", are removed from the
		//    buffer String.  Removal of these path segments is performed
		//    iteratively, removing the leftmost matching pattern on each
		//    iteration, until no matching pattern remains.
		//
		// f) If the buffer String ends with "<segment>/..", where <segment>
		//    is a complete path segment not equal to "..", that
		//    "<segment>/.." is removed.
		//
		// To satisfy the "iterative" clause in (e), we need to collapse the
		// String every time we find something that needs to be removed.  Thus,
		// we don't need to keep two pointers into the String: we only need a
		// "current position" pointer.
		//
		while (true)
		{
			char *segp, *tmp;

			// At the beginning of each iteration of this loop, "cur" points to
			// the first character of the segment we want to examine.

			// Find the end of the current segment.  

			for(segp = cur;(*segp != '/') && (*segp != 0); ++segp);

			// If this is the last segment, we're done (we need at least two
			// segments to meet the criteria for the (e) and (f) cases).

			if (*segp == 0)
				break;

			// If the first segment is "..", or if the next segment _isn't_ "..",
			// keep this segment and try the next one.

			++segp;
			if (((*cur == '.') && (cur[1] == '.') && (segp == cur+3))
				|| ((*segp != '.') || (segp[1] != '.')
				|| ((segp[2] != '/') && (segp[2] != 0)))) 
			{
				cur = segp;
				continue;
			}

			// If we get here, remove this segment and the next one and back up
			// to the previous segment (if there is one), to implement the
			// "iteratively" clause.  It's pretty much impossible to back up
			// while maintaining two pointers into the buffer, so just compact
			// the whole buffer now.

			// If this is the end of the buffer, we're done.

			if (segp[2] == 0) 
			{
				*cur = 0;
				break;
			}

			// Strings overlap during this copy, but not in a bad way, just avoid using strcpy

			tmp = cur;
			segp += 3;
			while ((*(tmp++) = *(segp++)) != 0);

			// If there are no previous segments, then keep going from here.

			segp = cur;
			while ((segp > path) && (*(--segp) == '/'));

			if (segp == path)
				continue;

			// "segp" is pointing to the end of a previous segment; find it's
			// start.  We need to back up to the previous segment and start
			// over with that to handle things like "foo/bar/../..".  If we
			// don't do this, then on the first pass we'll remove the "bar/..",
			// but be pointing at the second ".." so we won't realize we can also
			// remove the "foo/..".

			for(cur = segp;(cur > path) && (*(cur-1) != '/'); cur--);
		}

		*out = 0;

		// g) If the resulting buffer String still begins with one or more
		//    complete path segments of "..", then the reference is
		//    considered to be in error. Implementations may handle this
		//    error by retaining these components in the resolved path (i.e.,
		//    treating them as part of the final URI), by removing them from
		//    the resolved path (i.e., discarding relative levels above the
		//    root), or by avoiding traversal of the reference.
		//
		// We discard them from the final path.

		if (*path == '/') 
		{
			for(cur=path; (*cur == '/') && (cur[1] == '.') && (cur[2] == '.') && ((cur[3] == '/') || (cur[3] == 0)); cur += 3);

			if (cur != path) 
			{
				for(out=path; *cur != 0; *(out++) = *(cur++));

				*out = 0;
			}
		}
		return;
	}

	// This function will take a resolved URI and create a version of it that is relative to
	// another existing URI.  The new URI is stored in the "originalURI"
	bool URI::makeRelativeTo ( const URI& relativeToURI, bool ignoreCase)
	{
		// Can only do this function if both URIs have the same scheme and authority
		if (mScheme != relativeToURI.mScheme  ||  mAuthority != relativeToURI.mAuthority)
			return false;

		// advance till we find a segment that doesn't match
		WideString thisPathWideSring = StringUtils::utf8String2WideString(getPath());
		WideString relativeToPathWideSring = StringUtils::utf8String2WideString(relativeToURI.getPath());
		const wchar_t *this_path        = thisPathWideSring.c_str();
		const wchar_t *relativeTo_path  = relativeToPathWideSring.c_str();
		const wchar_t *this_slash       = this_path;
		const wchar_t *relativeTo_slash = relativeTo_path;
/*		const char *this_path        = getPath().c_str();
		const char *relativeTo_path  = relativeToURI.getPath().c_str();
		const char *this_slash       = this_path;
		const char *relativeTo_slash = relativeTo_path;
*/
		while( *this_path )
		{

			if  ( ignoreCase )
			{
				wchar_t characters[3];
				characters[0] = *this_path;
				characters[1] = *relativeTo_path;
				characters[2] = 0;


				std::transform(
					characters,
					characters+2,
					characters,
					tolower );

				if  ( characters[0] != characters[1] ) 
					break;
			}
			else
			{
				if (*this_path != *relativeTo_path) 
					break;
			}

			if(*this_path == '/')
			{
				this_slash = this_path;
				relativeTo_slash = relativeTo_path;
			}
			this_path++;
			relativeTo_path++;
		}

		// Decide how many ../ segments are needed (Filepath should always end in a /)
		int segment_count = 0;
		relativeTo_slash++;
		while(*relativeTo_slash != 0)
		{
			if(*relativeTo_slash == '/')
				segment_count ++;
			relativeTo_slash++;
		}
		this_slash++;

		String newPath;
		if ( segment_count == 0 )
		{
			newPath = "./";
		}
		else
		{
			for (int i = 0; i < segment_count; i++)
				newPath += "../";
		}
		WideString thisSlashWideString(this_slash);
		newPath += StringUtils::wideString2utf8String(thisSlashWideString);

		set("", "", newPath, mQuery, mFragment, 0/*relativeToURI*/);
		return true;
	}

	//---------------------------------------------------------------
	URI URI::getRelativeTo ( const URI& uri, bool& success,  bool ignoreCase ) const
	{
		URI relative(*this);
		success = relative.makeRelativeTo ( uri, ignoreCase );
		return relative;
	}

    //---------------------------------------------------------------
	bool URI::parseUriRef (
        const String& uriRef,
		String& scheme,
		String& authority,
		String& path,
		String& query,
		String& fragment) 
	{

		// For performance reasons we treat the special case of an URI containing only a fragment
		// separately, by checking if the uriRef starts with an "#" and treat the rest as
		// the fragment
		if ( !uriRef.empty() && uriRef[0] == '#')
		{
			fragment.assign( uriRef, 1, uriRef.length() - 1 );
			return true;
		}


		// This regular expression for parsing URI references comes from the URI spec:
		//   http://tools.ietf.org/html/rfc3986#appendix-B
		// regular expression: "^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?"
		static const PcreCompiledPattern matchUriCompiledPattern("^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\\?([^#]*))?(#(.*))?");
		pcre* matchUri = matchUriCompiledPattern.getCompiledPattern();


		int uriMatches[regExpMatchesVectorLength];

		int  uriResult = pcre_exec(
									matchUri,					/* the compiled pattern */
									0,							/* no extra data - we didn't study the pattern */
									uriRef.c_str(),				/* the subject string */
									(int)uriRef.size(),			/* the length of the subject */
									0,							/* start at offset 0 in the subject */
									0,							/* default options */
									uriMatches,				/* output vector for substring information */
									regExpMatchesVectorLength);		/* number of elements in the output vector */


		if ( uriResult >= 0 )
		{
			setStringFromMatches(scheme, uriRef, uriMatches, 2);
			setStringFromMatches(authority, uriRef, uriMatches, 4);
			setStringFromMatches(path, uriRef, uriMatches, 5);
			setStringFromMatches(query, uriRef, uriMatches, 6);
			setStringFromMatches(fragment, uriRef, uriMatches, 9);
			return true;
		}

		return false;
	}

	namespace {
		String safeSubstr(const String& s, size_t offset, size_t length) {
			String result = s.substr(offset, std::min(length, s.length() - offset));
			result.resize(length, '\0');
			return result;
		}
	}

	String URI::assembleUri(const String& scheme,
		const String& authority,
		const String& path,
		const String& query,
		const String& fragment,
		bool forceLibxmlCompatible) {
			String p = safeSubstr(path, 0, 3);
			bool libxmlHack = forceLibxmlCompatible && ( strcmp(scheme.c_str(), "file") == 0 );
			bool uncPath = false;

			// we calculate the length of the uri string to preallocate memory
			size_t uriLength = 0;

			if (!scheme.empty())
				uriLength += scheme.length() + 3 /*"://"*/;

			if (!authority.empty())
			{
				if (libxmlHack) {
					// We have a UNC path URI of the form file://otherMachine/file.dae.
					// Convert it to file://///otherMachine/file.dae, which is how libxml
					// does UNC paths.
					uriLength += 3 /*"///"*/ + authority.length();
					uncPath = true;
				}
				else {
					uriLength += authority.length();
				}
			}

			if (!uncPath && libxmlHack && Utils::getSystemType() == Utils::WINDOWS) {
				// We have to be delicate in how we pass absolute path URIs to libxml on Windows.
				// If the path is an absolute path with no drive letter, add an extra slash to
				// appease libxml.
				if (p[0] == '/' && p[1] != '/' && p[2] != ':') {
					uriLength += 1 /*"/"*/;
				}
			}
			uriLength += path.length();

			if (!query.empty())
				uriLength += 1 /*"?"*/ + query.length();
			if (!fragment.empty())
				uriLength += 1 /*"#"*/ + fragment.length();

			// done with pre calculating size 
			// start to assemble the string

			String uri;
			uri.reserve(uriLength);

			if (!scheme.empty())
				uri += scheme + "://";

			if (!authority.empty())
			{
				if (libxmlHack) {
					// We have a UNC path URI of the form file://otherMachine/file.dae.
					// Convert it to file://///otherMachine/file.dae, which is how libxml
					// does UNC paths.
					uri += "///" + authority;
					uncPath = true;
				}
				else {
					uri += authority;
				}
			}

			if (!uncPath && libxmlHack && Utils::getSystemType() == Utils::WINDOWS) {
				// We have to be delicate in how we pass absolute path URIs to libxml on Windows.
				// If the path is an absolute path with no drive letter, add an extra slash to
				// appease libxml.
				if (p[0] == '/' && p[1] != '/' && p[2] != ':') {
					uri += "/";
				}
			}
			uri += path;

			if (!query.empty())
				uri += "?" + query;
			if (!fragment.empty())
				uri += "#" + fragment;

			return uri;
	}

	String URI::nativePathToUri(const String& nativePath, Utils::SystemType type) 
	{
		String uri = nativePath;

		if (type == Utils::WINDOWS) {
			// Convert "c:\" to "/c:/"
			if (uri.length() >= 2  &&  StringUtils::isAsciiAlphaChar(uri[0])  &&  uri[1] == ':')
				uri.insert(0, "/");
			// Convert backslashes to forward slashes
			Utils::stringFindAndReplace(uri, "\\", "/");
		}

		// Encode the uri string to a valid uri
        uri = URI::uriEncode ( uri );

		return uri;
	}

	String URI::toNativePath(Utils::SystemType type) const
    {
//		String scheme, authority, path, query, fragment;
//		parseUriRef(uriRef, scheme, authority, path, query, fragment);

		// Make sure we have a file scheme URI, or that it doesn't have a scheme
		if (!mScheme.empty()  &&  mScheme != "file")
			return "";

		String filePath;
        String currentPath ( mPath );

		if (type == Utils::WINDOWS) {
			if (!mAuthority.empty())
				filePath += String("\\\\") + mAuthority; // UNC path

			// Replace two leading slashes with one leading slash, so that
			// ///otherComputer/file.dae becomes //otherComputer/file.dae and
			// //folder/file.dae becomes /folder/file.dae
			if (currentPath.length() >= 2  &&  currentPath[0] == '/'  &&  currentPath[1] == '/')
				currentPath.erase(0, 1);

			// Convert "/C:/" to "C:/"
			if (currentPath.length() >= 3  &&  currentPath[0] == '/'  &&  currentPath[2] == ':')
				currentPath.erase(0, 1);

			// Convert forward slashes to back slashes
			Utils::stringFindAndReplace(currentPath, "/", "\\");
		}

		filePath += currentPath;

		// Replace % encoded characters
		filePath = URI::uriDecode ( filePath );

		return filePath;
	}

	bool URI::operator<( const URI& rhs ) const
	{
		if ( getURIString() < rhs.getURIString() )
			return true;
		return false;
	}

	URI::operator size_t()const
	{
		return 	calculateHash( *this );
	}
}

