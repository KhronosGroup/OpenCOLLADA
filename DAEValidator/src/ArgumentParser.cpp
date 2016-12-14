#include "ArgumentParser.h"
#include <iostream>

using namespace std;

#ifdef _MSC_VER
#define NOEXCEPT _NOEXCEPT
#else
#define NOEXCEPT noexcept
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
            stringstream ss;
            ss << "Missing argument";
            if (mParam.length() > 0)
            {
                ss << ": " << mParam;
            }
			mWhat = ss.str();
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
            stringstream ss;
            ss << "Missing parameter for argument " << mParam;
			mWhat = ss.str();
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
            stringstream ss;
            ss << "Unknown argument: " << mParam;
			mWhat = ss.str();
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
		return *this;
	}

	Argument& Argument::required()
	{
		mRequired = true;
		return *this;
	}

	Argument& Argument::action(const std::function<void(const std::string & param)> & toDo)
	{
		mToDo = toDo;
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

	void Argument::setValue(const string & str, size_t index)
	{
		mValues[index] = str;
		if (mToDo)
		{
			mToDo(str);
		}
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
		mCommandLine.reserve(argc);
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
                    throw MissingArgumentException();
				}
			}
		}
		catch (exception& e)
		{
			cerr << "Command line error:" << endl;
			cerr << e.what() << endl;
			return false;
		}
		return true;
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
}