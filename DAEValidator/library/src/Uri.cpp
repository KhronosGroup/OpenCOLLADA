#include "PathUtil.h"
#include "StringUtil.h"
#include "Uri.h"
#include <cctype>
#include "no_warning_regex"

using namespace std;

namespace opencollada
{
	Uri::Uri(const string & uri)
	{
		set(uri);
	}

	Uri::Uri(const Uri & baseUri, const Uri & uri)
	{
		set(baseUri, uri);
	}

	bool Uri::operator == (const Uri & uri) const
	{
		return mUri == uri.mUri;
	}

	bool Uri::operator != (const Uri & uri) const
	{
		return !this->operator==(uri);
	}

	bool Uri::operator < (const Uri & uri) const
	{
		return less<string>()(mUri, uri.str());
	}

	bool Uri::empty() const
	{
		return mUri.empty();
	}

	bool Uri::isValid() const
	{
		return mValid;
	}

	const string & Uri::str() const
	{
		return mUri;
	}

	const string & Uri::scheme() const
	{
		return mScheme;
	}

	const string & Uri::authority() const
	{
		return mAuthority;
	}

	const string & Uri::path() const
	{
		return mPath;
	}

	const string & Uri::query() const
	{
		return mQuery;
	}

	const string & Uri::fragment() const
	{
		return mFragment;
	}

	void Uri::setScheme(const std::string & scheme)
	{
		mScheme = scheme;
		rebuild_fast();
	}

	void Uri::setFragment(const string & fragment)
	{
		mFragment = fragment;
		rebuild_fast();
	}

	void Uri::setPathFile(const string & filename)
	{
		auto pf = pathFile();
		if (!pf.empty())
		{
			auto pos = mPath.rfind(pf);
			mPath.replace(pos, pf.length(), filename);
			rebuild_fast();
		}
	}

	// https://techtavern.wordpress.com/2009/04/06/regex-that-matches-path-filename-and-extension/
	static const regex parse_path_regex("^(.*/)?(?:$|(.+?)(?:(\\.[^.]*$)|$))");

	string Uri::pathFile() const
	{
		smatch matches;
		if (!regex_match(mPath, matches, parse_path_regex))
			return string();

		string base = matches.str(2);
		string ext = matches.str(3);

		return base + ext;
	}

	string Uri::nativePath() const
	{
		if (!mScheme.empty() && mScheme != "file")
			return string();

		string currentPath(mPath);
		string native_path;
#if _WIN32
		if (!mAuthority.empty())
			native_path += string("\\\\") + mAuthority; // UNC path

		// Replace two leading slashes with one leading slash, so that
		// ///otherComputer/file.dae becomes //otherComputer/file.dae and
		// //folder/file.dae becomes /folder/file.dae
		if (currentPath.length() >= 2 && currentPath[0] == '/' && currentPath[1] == '/')
			currentPath.erase(0, 1);

		// Convert "/C:/" to "C:/"
		if (currentPath.length() >= 3 && currentPath[0] == '/' && currentPath[2] == ':')
			currentPath.erase(0, 1);

		// Convert forward slashes to back slashes
		currentPath = String::Replace(currentPath, "/", "\\");
#endif
		native_path += currentPath;

		// Replace % encoded characters
		return Uri::Decode(native_path);
	}

	void Uri::clear()
	{
		mUri.clear();
		mScheme.clear();
		mAuthority.clear();
		mPath.clear();
		mQuery.clear();
		mFragment.clear();
		mValid = false;
	}

	void Uri::set(const string & uri)
	{
		clear();
		mUri = uri;
		mValid = Parse(uri, mScheme, mAuthority, mPath, mQuery, mFragment);
	}

	void Uri::set(const Uri & base, const Uri & ref)
	{
		clear();
		if (!ref.mScheme.empty())
		{
			mScheme = ref.mScheme;
			mAuthority = ref.mAuthority;
			mPath = Path::RemoveDotSegments(ref.mPath);
			mQuery = ref.mQuery;
		}
		else
		{
			if (!ref.mAuthority.empty())
			{
				mAuthority = ref.mAuthority;
				mPath = Path::RemoveDotSegments(ref.mPath);
				mQuery = ref.mQuery;
			}
			else
			{
				if (ref.mPath.empty())
				{
					mPath = base.mPath;
					if (!ref.mQuery.empty())
						mQuery = ref.mQuery;
					else
						mQuery = base.mQuery;
				}
				else
				{
					if (String::StartsWith(ref.mPath, "/"))
						mPath = Path::RemoveDotSegments(ref.mPath);
					else
					{
						mPath = MergePaths(base, ref.mPath);
						mPath = Path::RemoveDotSegments(mPath);
					}
					mQuery = ref.mQuery;
				}
				mAuthority = base.mAuthority;
			}
			mScheme = base.mScheme;
		}
		mFragment = ref.mFragment;
		rebuild_fast();
	}

	Uri Uri::FromNativePath(const string & path)
	{
		string uri = Path::GetAbsolutePath(path);
#ifdef _WIN32		
		// Convert c: to /c:
		if (uri.length() >= 2 && isalpha(uri[0]) && uri[1] == ':')
			uri.insert(0, 1, '/');

		// Replace \ by /
		uri = String::Replace(uri, "\\", "/");
#endif
		Uri res = Encode(uri);
		res.setScheme("file");
		return res;
	}

	string Uri::Decode(const std::string & str)
	{
		// Hexadecimal character to decimal value table.
		// Examples:
		// char '0' = 0x30 -> 0
		// char 'A' = 0x41 -> 10
		// char 'a' = 0x61 -> 10
		// char 'G' = 0x47 -> err -> invalid  hexadecimal character
		static const signed char err = -1;
		static const signed char hex_to_dec[] =
		{
			//0   1   2   3    4   5   6   7    8   9   A   B    C   D   E   F
			err,err,err,err, err,err,err,err, err,err,err,err, err,err,err,err, // 0
			err,err,err,err, err,err,err,err, err,err,err,err, err,err,err,err, // 1
			err,err,err,err, err,err,err,err, err,err,err,err, err,err,err,err, // 2
			  0,  1,  2,  3,   4,  5,  6,  7,   8,  9,err,err, err,err,err,err, // 3

			err, 10, 11, 12,  13, 14, 15,err, err,err,err,err, err,err,err,err, // 4
			err,err,err,err, err,err,err,err, err,err,err,err, err,err,err,err, // 5
			err, 10, 11, 12,  13, 14, 15,err, err,err,err,err, err,err,err,err, // 6
			err,err,err,err, err,err,err,err, err,err,err,err, err,err,err,err, // 7

			err,err,err,err, err,err,err,err, err,err,err,err, err,err,err,err, // 8
			err,err,err,err, err,err,err,err, err,err,err,err, err,err,err,err, // 9
			err,err,err,err, err,err,err,err, err,err,err,err, err,err,err,err, // A
			err,err,err,err, err,err,err,err, err,err,err,err, err,err,err,err, // B

			err,err,err,err, err,err,err,err, err,err,err,err, err,err,err,err, // C
			err,err,err,err, err,err,err,err, err,err,err,err, err,err,err,err, // D
			err,err,err,err, err,err,err,err, err,err,err,err, err,err,err,err, // E
			err,err,err,err, err,err,err,err, err,err,err,err, err,err,err,err  // F
		};

		const size_t str_len = str.length();
		const size_t last_decodable_pos = min(str_len, str_len - 2);

		string res;
		res.reserve(str_len);
		size_t i = 0;
		while (i < last_decodable_pos)
		{
			if (str[i] == '%')
			{
				auto dec1 = hex_to_dec[static_cast<int>(str[i + 1])];
				auto dec2 = hex_to_dec[static_cast<int>(str[i + 2])];
				if (dec1 != err && dec2 != err)
				{
					res.append(1, static_cast<string::value_type>((dec1 << 4) + dec2));
					i += 3;
					continue;
				}
			}
			res.append(1, str[i++]);
		}

		while (i < str_len)
		{
			res.append(1, str[i++]);
		}

		return res;
	}

	string Uri::Encode(const string & str)
	{
		static const char dec_to_hex[] = "0123456789ABCDEF";

		string uri;
		uri.reserve(str.length() * 3);
		for (auto c : str)
		{
			if (c > 32)
				uri += c;
			else
			{
				uri += '%';
				uri += dec_to_hex[c >> 4];
				uri += dec_to_hex[c & 0x0F];
			}
		}
		return uri;
	}

	// scheme: = $1
	// scheme = $2
	// //authority = $3
	// authority = $4
	// path = $5
	// ?query = $6
	// query = $7
	// #fragment = $8
	// fragment = $9
	static const regex uri_regex("^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\\?([^#]*))?(#(.*))?");

	bool Uri::Parse(
		const string & uri,
		string & scheme,
		string & authority,
		string & path,
		string & query,
		string & fragment)
	{
		smatch matches;
		if (!regex_match(uri, matches, uri_regex))
			return false;

		scheme = matches.str(2);
		authority = matches.str(4);
		path = matches.str(5);
		query = matches.str(7);
		fragment = matches.str(9);

		return true;
	}

	string Uri::MergePaths(const Uri & base, const string & ref_path)
	{
		if (!base.mAuthority.empty() && base.mPath.empty())
			return string("/") + ref_path;
		else
		{
			size_t slash_pos = base.mPath.rfind('/');
			if (slash_pos != string::npos)
				return base.mPath.substr(0, slash_pos + 1) + ref_path;
			else
				return ref_path;
		}
	}

	void Uri::rebuild_fast()
	{
		mUri.clear();
		if (!mScheme.empty())
			mUri += mScheme + "://";
		if (!mAuthority.empty())
			mUri += mAuthority;
		if (!mPath.empty())
			mUri += mPath;
		if (!mQuery.empty())
			mUri += '?' + mQuery;
		if (!mFragment.empty())
			mUri += '#' + mFragment;
		mValid = true;
	}
}

ostream & operator << (ostream & o, const opencollada::Uri & uri)
{
	return o << uri.str();
}