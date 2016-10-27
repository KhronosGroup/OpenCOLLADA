#pragma once

#include <string>

namespace opencollada
{
	class String
	{
	public:
		static bool EndsWith(const std::string & str, const std::string & end);
	};
}