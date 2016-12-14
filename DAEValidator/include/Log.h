#pragma once

#include <functional>
#include <iostream>
#include <memory>
#include <string>

namespace opencollada
{
	class streamhook : public std::streambuf
	{
	public:
		typedef std::function<void(const std::string &)> hookcallback;

		streamhook(std::ostream & stream, bool quiet, const hookcallback & callback = hookcallback());
		~streamhook();

	protected:
		// override xsputn and make it forward data to the callback function
		std::streamsize xsputn(const char *_Ptr, std::streamsize _Count);
		// override overflow and make it forward data to the callback function
		std::char_traits<char>::int_type overflow(std::char_traits<char>::int_type v);

	private:
		std::ostream& mStream;
		std::streambuf* mStreamBuf;
		std::function<void(const std::string &)> mCallback;
		bool mQuiet = false;
	};

	class libxmlhook
	{
	public:
		static void GenericErrorFunc(void *ctx, const char *msg, ...);
	};

	class Log
	{
	public:
		static void Setup(bool quiet);

	private:
		static std::unique_ptr<streamhook> mCoutHook;
		static std::unique_ptr<streamhook> mCerrHook;
	};
}