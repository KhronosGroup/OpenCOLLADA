#include "PathUtil.h"
#include "StringUtil.h"

#if defined(_WIN32)
#include <Windows.h>
#include "win/dirent.h"
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#include <sys/stat.h>
#include <dirent.h>
#else
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
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
		struct stat st;
		if (stat(path.c_str(), &st) == 0)
			if ((st.st_mode & S_IFDIR) != 0)
				return true;
		return false;
	}

	string Path::GetExecutablePath()
	{
#if defined(_WIN32)
		vector<string::value_type> path;
		path.resize(MAX_PATH);
		GetModuleFileName(NULL, &path.front(), static_cast<DWORD>(path.size()));
		while (GetLastError() == ERROR_INSUFFICIENT_BUFFER) {
			path.resize(path.size() * 2);
			GetModuleFileNameA(NULL, &path.front(), static_cast<DWORD>(path.size()));
		}
		return string(&path.front());
#elif defined(__APPLE__)
		uint32_t size = 0;
		_NSGetExecutablePath(nullptr, &size);
		string path;
		path.resize(size - 1);
		if (_NSGetExecutablePath(&path.front(), &size) == 0)
			return path;
		return string();
#else
		static const char* proc_self_exe = "/proc/self/exe";
		struct stat st;
		if (stat(proc_self_exe, &st) == 0)
		{
			string path;
			path.resize(st.st_size);
			if (readlink(proc_self_exe, &path.front(), st.st_size) != -1)
				return path;
		}
		return string();
#endif
	}

	string Path::GetExecutableDirectory()
	{
		string exePath = GetExecutablePath();
		if (exePath.length() > 0)
		{
			size_t sep = exePath.rfind(Path::Separator());
			if (sep != string::npos)
			{
				return exePath.substr(0, sep);
			}
		}
		return string();
	}

	list<string> Path::ListDaes(const string & path, bool recursive)
	{
		list<string> daes;
		DIR* dir = nullptr;
		struct dirent* ent = nullptr;
		list<string> dirs;
		dirs.push_back(path);
		while (dirs.size() > 0)
		{
			if ((dir = opendir(dirs.front().c_str())) != nullptr) {
				while ((ent = readdir(dir)) != nullptr) {
					string d_name = ent->d_name;
					if (recursive &&
						(ent->d_type & DT_DIR) &&
						d_name != "." &&
						d_name != "..")
					{
						dirs.push_back(Path::Join(dirs.front(), ent->d_name));
					}
					else if (String::EndsWith(String::Lower(ent->d_name), ".dae"))
					{
						daes.push_back(Path::Join(dirs.front(), ent->d_name));
					}
				}
				closedir(dir);
			}
			dirs.pop_front();
		}
		return daes;
	}
}
