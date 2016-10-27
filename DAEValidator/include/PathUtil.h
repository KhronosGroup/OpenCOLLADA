#pragma once

#include <string>

namespace opencollada
{
	class Path
	{
	public:
		static const std::string & Separator();
		static std::string Join(const std::string & path_a, const std::string & path_b);
		static bool IsDirectory(const std::string & path);

	private:
		static std::string mSeparator;
	};
}