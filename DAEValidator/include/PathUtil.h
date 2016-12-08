#pragma once

#include <list>
#include <string>

namespace opencollada
{
	class Path
	{
	public:
		static const std::string & Separator();
		static std::string Join(const std::string & path_a, const std::string & path_b);
		static bool IsDirectory(const std::string & path);
		static std::string GetExecutablePath();
		static std::string GetExecutableDirectory();
		static std::list<std::string> ListDaes(const std::string & path, bool recursive);

	private:
		static std::string mSeparator;
	};
}