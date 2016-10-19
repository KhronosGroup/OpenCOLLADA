#include "Uri.h"
#include <cctype>
#include <regex>

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

	//const Uri & Uri::operator=(const Uri & uri)
	//{
	//	mUri = uri.mUri;
	//	return *this;
	//}

	bool Uri::isValid() const
	{
		return mValid;
	}

	const string & Uri::str() const
	{
		return mUri;
	}

	const std::string & Uri::scheme() const
	{
		return mScheme;
	}

	const std::string & Uri::authority() const
	{
		return mAuthority;
	}

	const std::string & Uri::path() const
	{
		return mPath;
	}

	const std::string & Uri::query() const
	{
		return mQuery;
	}

	const std::string & Uri::fragment() const
	{
		return mFragment;
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
		mValid = Parse(uri, mScheme, mAuthority, mPath, mQuery, mFragment);
	}

	void Uri::set(const Uri & base, const Uri & ref)
	{
		clear();
		if (!ref.mScheme.empty())
		{
			mScheme = ref.mScheme;
			mAuthority = ref.mAuthority;
			mPath = RemoveDotSegments(ref.mPath);
			mQuery = ref.mQuery;
		}
		else
		{
			if (!ref.mAuthority.empty())
			{
				//mAuthority = uri.mAuthority;
				mPath = RemoveDotSegments(ref.mPath);
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
					if (StartsWith(ref.mPath, "/"))
						mPath = RemoveDotSegments(ref.mPath);
					else
					{
						mPath = MergePaths(base, ref.mPath);
						mPath = RemoveDotSegments(mPath);
					}
					mQuery = ref.mQuery;
				}
				mAuthority = base.mAuthority;
			}
			mScheme = base.mScheme;
		}
		mFragment = ref.mFragment;
	}

	Uri Uri::FromNativePath(const string & path)
	{
#ifdef _WIN32
		string tmp = path;
		
		// Convert c: to /c:
		if (tmp.length() >= 2 && isalpha(tmp[0]) && tmp[1] == ':')
			tmp.insert(0, 1, '/');

		// Replace \ by /
		for (size_t pos = tmp.find('\\'); pos != string::npos; pos = tmp.find('\\', pos))
			tmp.replace(pos, 1, 1, '/');

		string uri = tmp;
#else
		string uri = path;
#endif
		return Encode(uri);
	}

	Uri Uri::Encode(const string & str)
	{
		static char hex[] = "0123456789ABCDEF";

		Uri uri;
		uri.mUri.reserve(str.length() * 3);
		for (auto c : str)
		{
			if (c > 32 && c < 128)
				uri.mUri += c;
			else
			{
				uri.mUri += '%';
				uri.mUri += hex[c >> 4];
				uri.mUri += hex[c & 0x0F];
			}
		}
		return uri;
	}

	bool Uri::Parse(
		const string & uri,
		string & scheme,
		string & authority,
		string & path,
		string & query,
		string & fragment)
	{
		// scheme: = $1
		// scheme = $2
		// //authority = $3
		// authority = $4
		// path = $5
		// ?query = $6
		// query = $7
		// #fragment = $8
		// fragment = $9
		static regex uri_regex("^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\\?([^#]*))?(#(.*))?");
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

	bool Uri::StartsWith(const std::string & str, const std::string & with)
	{
		return str.substr(0, with.length()) == with;
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

	string Uri::RemoveDotSegments(const string & path)
	{
		static string dot(".");
		static string dot_dot("..");
		static string dot_dot_slash("../");
		static string dot_slash("./");
		static string slash_dot_slash("/./");
		static string slash_dot("/.");
		static string slash_dot_dot_slash("/../");
		static string slash_dot_dot("/..");
		static size_t dot_dot_slash_len = dot_dot_slash.length();
		static size_t dot_slash_len = dot_slash.length();
		static size_t slash_dot_slash_len = slash_dot_slash.length();
		static size_t slash_dot_len = slash_dot.length();
		static size_t slash_dot_dot_slash_len = slash_dot_dot_slash.length();
		static size_t slash_dot_dot_len = slash_dot_dot.length();

		string input = path;
		string output;
		output.reserve(input.length());

		while (!input.empty())
		{
			if (StartsWith(input, dot_dot_slash))
			{
				input.erase(0, dot_dot_slash_len);
			}
			else if (StartsWith(input, dot_slash))
			{
				input.erase(0, dot_slash_len);
			}
			else if (StartsWith(input, slash_dot_slash))
			{
				input.replace(0, slash_dot_slash_len, "/");
			}
			else if (StartsWith(input, slash_dot) &&
				(input[slash_dot_len] == '/' || input[slash_dot_len] == '\0'))
			{
				input.replace(0, slash_dot_len, "/");
			}
			else if (StartsWith(input, slash_dot_dot_slash))
			{
				input.replace(0, slash_dot_dot_slash_len, "/");
				size_t slash_pos = output.rfind('/');
				if (slash_pos == string::npos)
					output.clear();
				else
					output.erase(output.begin() + slash_pos, output.end());
			}
			else if (StartsWith(input, slash_dot_dot) &&
				(input[slash_dot_dot_len] == '/' || input[slash_dot_dot_len] == '\0'))
			{
				input.replace(0, slash_dot_dot_len, "/");
				size_t slash_pos = output.rfind('/');
				if (slash_pos == string::npos)
					output.clear();
				else
					output.erase(output.begin() + slash_pos, output.end());
			}
			else if (input == dot || input == dot_dot)
			{
				input.clear();
			}
			else
			{
				size_t begin = input.find('/');
				if (begin == 0)
					begin = 0;
				size_t end = input.find('/', 1);
				output.append(input.substr(0, end));
				input.erase(0, end);
			}
		}
		return output;
	}
}