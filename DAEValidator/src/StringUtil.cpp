#include "StringUtil.h"
#include <sstream>
#include <algorithm>

using namespace std;

namespace opencollada
{
	bool String::EndsWith(const string & str, const string & end)
	{
		if (end.length() > str.length())
			return false;
		return equal(end.rbegin(), end.rend(), str.rbegin());
	}

	// Split string by whitespace
	vector<string> String::Split(const string & s)
	{
		vector<string> parts;
		istringstream iss(s);
		while (iss && !iss.eof())
		{
			string sub;
			iss >> sub;
			parts.emplace_back(sub);
		}
		return parts;
	}

	string String::Lower(const string & str)
	{
		string res = str;
        transform(res.begin(), res.end(), res.begin(), ::tolower);
		return res;
	}

	string String::Replace(const string & str, const string & search_str, const string & replace_str)
	{
		string res(str);

		size_t search_len = search_str.length();
		size_t replace_len = replace_str.length();

		for (size_t found = res.find(search_str); found != string::npos; found = res.find(search_str, found + replace_len))
			res.replace(found, search_len, replace_str);

		return res;
	}
}