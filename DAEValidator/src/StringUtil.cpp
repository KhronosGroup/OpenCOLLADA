#include "StringUtil.h"

using namespace std;

namespace opencollada
{
	bool String::EndsWith(const string & str, const string & end)
	{
		if (end.length() > str.length())
			return false;
		return equal(end.rbegin(), end.rend(), str.rbegin());
	}
}