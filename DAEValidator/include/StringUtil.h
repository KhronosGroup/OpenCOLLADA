#pragma once

#include <string>
#include <vector>

namespace opencollada
{
	class String
	{
	public:
		static bool EndsWith(const std::string & str, const std::string & end);
		
		// Split string by whitespace
		static std::vector<std::string> Split(const std::string & s);

		static std::string Lower(const std::string & str);

		static std::string Replace(const std::string & str, const std::string & a, const std::string & b);
	};
}