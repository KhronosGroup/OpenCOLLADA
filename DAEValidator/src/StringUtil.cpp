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
		transform(res.begin(), res.end(), res.begin(), tolower);
		return res;
	}
}