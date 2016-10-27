#include "PathUtil.h"
#include "StringUtil.h"

using namespace std;

namespace opencollada
{
	string Path::mSeparator(
#if defined(_WIN32)
		"\\"
#else
		"/"
#endif
	);

	const string & Path::Separator()
	{
		return mSeparator;
	}

	string Path::Join(const string & path_a, const string & path_b)
	{
		string res = path_a;
		if (!String::EndsWith(res, Separator()))
			res.append(Separator());
		return res.append(path_b);
	}
}