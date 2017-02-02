#pragma once

#include "no_warning_string"
#include "no_warning_vector"

namespace opencollada
{
	class String
	{
	public:
		static bool StartsWith(const std::string & str, const std::string & start);
		static bool EndsWith(const std::string & str, const std::string & end);
		
		// Split string by whitespace
		static std::vector<std::string> Split(const std::string & s);

		static std::string Lower(const std::string & str);

		static std::string Replace(const std::string & str, const std::string & a, const std::string & b);
		static size_t Replace(std::string & str, char a, char b);
	};
}