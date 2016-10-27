#include "PathUtil.h"
#include "StringUtil.h"

#if defined(_WIN32)
#include <Windows.h>
#endif

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

	bool Path::IsDirectory(const string & path)
	{
		struct stat st = { 0 };
		if (stat(path.c_str(), &st) == 0)
			if ((st.st_mode & S_IFDIR) != 0)
				return true;
		return false;
	}
}