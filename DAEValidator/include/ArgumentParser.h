#pragma once

#include <functional>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace opencollada
{
	class Argument
	{
		friend class ArgumentParser;
	public:
		Argument& numParameters(size_t n);
		Argument& required();
		Argument& action(const std::function<void(const std::string & param)> & toDo);

		size_t getNumParameters() const;
		bool isSet() const;
		bool isRequired() const;

		template<typename T>
		T getValue(int index = 0) const
		{
			T value;
			std::stringstream ss;
			ss << mValues[index];
			ss >> value;
			return value;
		}

		operator bool() const;

	private:
		void isSet(bool is_set);
		void setValue(const std::string & str, size_t index = 0);

	private:
		static Argument null;
		std::vector<std::string> mValues;
		std::function<void(const std::string & param)> mToDo;
		bool mSet = false;
		bool mRequired = false;
	};
    
    template<>
    inline std::string Argument::getValue<std::string>(int index) const
    {
        return mValues[index];
    }

	class ArgumentParser
	{
	public:
		ArgumentParser(int argc, char* argv[]);

		bool parseArguments();

		Argument& addArgument(const std::string & name = "");
		const Argument& findArgument(const std::string & name);
		const Argument& findArgument(size_t index);
		size_t numSetArguments() const;

	private:
		std::map<std::string, Argument> mArguments;
		std::vector<Argument> mNoSwitchArguments;
		std::vector<std::string> mCommandLine;
	};
}