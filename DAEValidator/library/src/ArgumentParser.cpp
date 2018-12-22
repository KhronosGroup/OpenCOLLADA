#include "ArgumentParser.h"
#include "PathUtil.h"
#include "no_warning_algorithm"
#include "no_warning_iomanip"
#include "no_warning_iostream"

using namespace std;

#ifndef _NOEXCEPT
#define NOEXCEPT noexcept
#else
#define NOEXCEPT _NOEXCEPT
#endif

namespace opencollada
{
    class MissingArgumentException : public exception
    {
    public:
        MissingArgumentException() = default;
        MissingArgumentException(const string & param)
            : mParam(param)
        {}
        
        virtual ~MissingArgumentException() NOEXCEPT
        {}
        
        virtual const char* what() const NOEXCEPT override
        {
			mWhat = "Missing argument";
			if (mParam.length() > 0)
				mWhat += ": " + mParam;
            return mWhat.c_str();
        }
        
    private:
        string mParam;
		mutable string mWhat;
    };
    
    class MissingArgumentParameterException : public exception
    {
    public:
        MissingArgumentParameterException(const string & param)
            : mParam(param)
        {}
        
        virtual ~MissingArgumentParameterException() NOEXCEPT
        {}
        
        virtual const char* what() const NOEXCEPT override
        {
			mWhat = "Missing parameter for argument " + mParam;
            return mWhat.c_str();
        }
        
    private:
        string mParam;
		mutable string mWhat;
    };
    
    class UnknowArgumentException : public exception
    {
    public:
        UnknowArgumentException(const string & param)
            : mParam(param)
        {}
        
        virtual ~UnknowArgumentException() NOEXCEPT
        {}
        
        virtual const char* what() const NOEXCEPT override
        {
			mWhat = "Unknown argument: " + mParam;
            return mWhat.c_str();
        }
        
    private:
        string mParam;
		mutable string mWhat;
    };

	Argument Argument::null;

	Argument& Argument::numParameters(size_t n)
	{
		mValues.resize(n);
		mHints.resize(n);
		return *this;
	}

	Argument& Argument::required()
	{
		mRequired = true;
		return *this;
	}

	Argument& Argument::hint(const string & s)
	{
		mHint = s;
		return *this;
	}

	Argument& Argument::hint(size_t index, const string & s)
	{
		mHints[index] = s;
		return *this;
	}

	Argument& Argument::help(const string & s)
	{
		mHelp = s;
		return *this;
	}

	size_t Argument::getNumParameters() const
	{
		return mValues.size();
	}

	bool Argument::isSet() const
	{
		return mSet;
	}

	bool Argument::isRequired() const
	{
		return mRequired;
	}

	const string & Argument::getHint() const
	{
		return mHint;
	}

	const string & Argument::getHint(size_t index) const
	{
		return mHints[index];
	}

	const string & Argument::getHelp() const
	{
		return mHelp;
	}

	void Argument::setValue(const string & str, size_t index)
	{
		mValues[index] = str;
	}

	Argument::operator bool() const
	{
		return this != &null;
	}

	void Argument::isSet(bool is_set)
	{
		mSet = is_set;
	}

	ArgumentParser::ArgumentParser(int argc, char* argv[])
	{
		mCommandLine.reserve(static_cast<size_t>(argc));
		for (int i = 0; i < argc; ++i)
		{
			mCommandLine.push_back(argv[i]);
		}
	}

	bool ArgumentParser::parseArguments()
	{
		try
		{
			auto noSwitchArgumentIt = mNoSwitchArguments.begin();
			for (size_t arg = 1; arg < mCommandLine.size();)
			{
				auto it = mArguments.find(mCommandLine[arg]);
				if (it == mArguments.end())
				{
					if (noSwitchArgumentIt != mNoSwitchArguments.end())
					{
						Argument& argument = *noSwitchArgumentIt;
						argument.setValue(mCommandLine[arg]);
						argument.isSet(true);
						++noSwitchArgumentIt;
						++arg;
						continue;
					}

                    throw UnknowArgumentException(mCommandLine[arg]);
				}

				Argument & argument = it->second;
				argument.isSet(true);
				for (size_t subArg = 0; subArg < argument.getNumParameters(); ++subArg)
				{
					size_t index = arg + subArg + 1;
					if (index >= mCommandLine.size())
					{
                        throw MissingArgumentParameterException(mCommandLine[arg]);
					}
					argument.setValue(mCommandLine[index], subArg);
				}
				arg += 1 + argument.getNumParameters();
			}

			for (const auto & argument : mArguments)
			{
				if (argument.second.isRequired() && !argument.second.isSet())
				{
                    throw MissingArgumentException(argument.first);
				}
			}

			for (const auto & argument : mNoSwitchArguments)
			{
				if (argument.isRequired() && !argument.isSet())
				{
					throw MissingArgumentException(argument.getHint());
				}
			}
		}
		catch (exception& e)
		{
			mParseError = e.what();
			return false;
		}
		return true;
	}

	string ArgumentParser::getParseError() const
	{
		return mParseError;
	}

	Argument& ArgumentParser::addArgument(const string & name)
	{
		if (name.empty())
		{
			mNoSwitchArguments.push_back(Argument());
			// Arguments with no switch are required and have one parameter.
			Argument& arg = mNoSwitchArguments.back();
			arg.required();
			arg.numParameters(1);
			return arg;
		}
		else
		{
			mArguments[name] = Argument();
			return mArguments[name];
		}
	}

	const Argument& ArgumentParser::findArgument(const string & name)
	{
		auto it = mArguments.find(name);
		if (it == mArguments.end())
			return Argument::null;
		if (!it->second.isSet())
			return Argument::null;
		return it->second;
	}

	const Argument& ArgumentParser::findArgument(size_t index)
	{
		if (index >= mNoSwitchArguments.size())
			return Argument::null;
		return mNoSwitchArguments[index];
	}

	size_t ArgumentParser::numSetArguments() const
	{
		size_t num = 0;
		for (const auto & arg : mArguments)
			if (arg.second.isSet())
				++num;
		for (const auto & arg : mNoSwitchArguments)
			if (arg.isSet())
				++num;
		return num;
	}

	string ArgumentParser::usage() const
	{
		stringstream s;
		s
			<< endl
			<< "COLLADA document validator." << endl
			<< endl
			<< "Validates COLLADA documents against COLLADA schema and performs several coherency tests." << endl
			<< endl
			<< "Usage:" << endl
			<< endl
			<< Path::GetFileBase(mCommandLine[0]);

		for (const auto & arg : mNoSwitchArguments)
		{
			s << " " << arg.getHint();
		}

		for (const auto & arg : mArguments)
		{
			s << " ";
			if (!arg.second.isRequired())
				s << '[';
			s << arg.first;
			for (size_t i = 0; i < arg.second.getNumParameters(); ++i)
			{
				s << " " << arg.second.getHint(i);
			}
			if (!arg.second.isRequired())
				s << ']';
		}

		s
			<< endl
			<< endl;

		size_t w = 0;
		for (const auto & arg : mArguments)
			w = max(w, arg.first.length());

		for (const auto & arg : mNoSwitchArguments)
			s << setw(static_cast<streamsize>(w)) << left << arg.getHint() << " " << arg.getHelp() << endl;

		for (const auto & arg : mArguments)
			s << setw(static_cast<streamsize>(w)) << left << arg.first << " " << arg.second.getHelp() << endl;

		return s.str();
	}
}