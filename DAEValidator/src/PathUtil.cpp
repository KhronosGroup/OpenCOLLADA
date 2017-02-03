#include "PathUtil.h"
#include "StringUtil.h"

#if defined(_WIN32)
#include <direct.h>
#define getcwd _getcwd
#include "no_warning_Windows.h"
#include "win/dirent.h"
#elif defined(__APPLE__)
#include <unistd.h>
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

	bool Path::Exists(const string & path)
	{
		struct stat st;
		return stat(path.c_str(), &st) == 0;
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

	string Path::GetWorkingDirectory()
	{
		char buffer[1024];
		if (getcwd(buffer, sizeof(buffer)))
			return buffer;
		return "";
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

	string Path::GetAbsolutePath(const std::string & path)
	{
		if (path.empty())
			return GetWorkingDirectory();

		if (path == ".")
			return GetWorkingDirectory();

		if (String::StartsWith(path, "/"))
			return RemoveDotSegments(path);

#if defined(_WIN32)
		if (isalpha(path[0]) && path.substr(1, 2) == ":\\")
			return RemoveDotSegments(path);
#endif

		return RemoveDotSegments(Join(GetWorkingDirectory(), path));
	}

	static const string dot(".");
	static const string dot_dot("..");
	static const string dot_dot_slash("../");
	static const string dot_slash("./");
	static const string slash_dot_slash("/./");
	static const string slash_dot("/.");
	static const string slash_dot_dot_slash("/../");
	static const string slash_dot_dot("/..");
	static const size_t dot_dot_slash_len = dot_dot_slash.length();
	static const size_t dot_slash_len = dot_slash.length();
	static const size_t slash_dot_slash_len = slash_dot_slash.length();
	static const size_t slash_dot_len = slash_dot.length();
	static const size_t slash_dot_dot_slash_len = slash_dot_dot_slash.length();
	static const size_t slash_dot_dot_len = slash_dot_dot.length();

	string Path::RemoveDotSegments(const string & path)
	{
		string input = path;
		string output;
		output.reserve(input.length());

#if defined(_WIN32)
		bool contains_anti_slash = String::Replace(input, '\\', '/') > 0;
#endif

		while (!input.empty())
		{
			if (String::StartsWith(input, dot_dot_slash))
			{
				input.erase(0, dot_dot_slash_len);
			}
			else if (String::StartsWith(input, dot_slash))
			{
				input.erase(0, dot_slash_len);
			}
			else if (String::StartsWith(input, slash_dot_slash))
			{
				input.replace(0, slash_dot_slash_len, "/");
			}
			else if (String::StartsWith(input, slash_dot) &&
				(input[slash_dot_len] == '/' || input[slash_dot_len] == '\0'))
			{
				input.replace(0, slash_dot_len, "/");
			}
			else if (String::StartsWith(input, slash_dot_dot_slash))
			{
				input.replace(0, slash_dot_dot_slash_len, "/");
				size_t slash_pos = output.rfind('/');
				if (slash_pos == string::npos)
					output.clear();
				else
					output.erase(output.begin() + static_cast<ptrdiff_t>(slash_pos), output.end());
			}
			else if (String::StartsWith(input, slash_dot_dot) &&
				(input[slash_dot_dot_len] == '/' || input[slash_dot_dot_len] == '\0'))
			{
				input.replace(0, slash_dot_dot_len, "/");
				size_t slash_pos = output.rfind('/');
				if (slash_pos == string::npos)
					output.clear();
				else
					output.erase(output.begin() + static_cast<ptrdiff_t>(slash_pos), output.end());
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

#if defined(_WIN32)
		if (contains_anti_slash)
			String::Replace(output, '/', '\\');
#endif

		return output;
	}

	string Path::GetFileBase(const std::string & path)
	{
		size_t base_begin = path.rfind(Separator());
		if (base_begin == string::npos)
			base_begin = 0;
		else
			++base_begin;
		string base = path.substr(base_begin);
		size_t base_end = base.rfind('.');
		if (base_end == 0)
			return base;
		return base.substr(0, base_end);
	}

	size_t Path::GetFileSize(const std::string & path)
	{
		struct stat st;
		return static_cast<size_t>(stat(path.c_str(), &st) == 0 ? st.st_size : 0);
	}
}
