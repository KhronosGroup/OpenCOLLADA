#include "StringUtil.h"
#include "no_warning_algorithm"
#include "no_warning_sstream"

using namespace std;

namespace opencollada
{
	bool String::StartsWith(const std::string & str, const std::string & start)
	{
		return str.substr(0, start.length()) == start;
	}

	bool String::EndsWith(const string & str, const string & end)
	{
		if (end.length() > str.length())
			return false;
		return equal(end.rbegin(), end.rend(), str.rbegin());
	}

	// Split string by whitespace
	vector<string> String::Split(const string & s)
	{
		if (s.empty())
			return vector<string>();

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
		transform(res.begin(), res.end(), res.begin(), [](const string::value_type & c) { return static_cast<string::value_type>(::tolower(c)); });
		return res;
	}

	string String::Replace(const string & str, const string & search_str, const string & replace_str)
	{
		if (str.empty() && search_str.empty())
			return replace_str;

		if (search_str.empty())
			return str;

		string res(str);

		size_t search_len = search_str.length();
		size_t replace_len = replace_str.length();

		for (size_t found = res.find(search_str); found != string::npos; found = res.find(search_str, found + replace_len))
			res.replace(found, search_len, replace_str);

		return res;
	}

	size_t String::Replace(string & str, char a, char b)
	{
		size_t count = 0;
		for (auto pos = str.find(a); pos != string::npos; pos = str.find(a, pos + 1))
		{
			str[pos] = b;
			++count;
		}
		return count;
	}
}