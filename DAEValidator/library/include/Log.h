#pragma once

#include "no_warning_functional"
#include "no_warning_iostream"
#include "no_warning_memory"
#include "no_warning_string"

namespace opencollada
{
	class streamhook : public std::streambuf
	{
	public:
		using hookcallback = std::function<void(const std::string &)>;

		streamhook(std::ostream & stream, bool quiet, const hookcallback & callback = hookcallback());
		~streamhook();

	protected:
		// override xsputn and make it forward data to the callback function
		std::streamsize xsputn(const char *_Ptr, std::streamsize _Count);
		// override overflow and make it forward data to the callback function
		std::char_traits<char>::int_type overflow(std::char_traits<char>::int_type v);

	private:
		const streamhook& operator = (const streamhook&) = delete;

	private:
		std::ostream& mStream;
		std::streambuf* mStreamBuf;
		hookcallback mCallback;
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
		Log(bool quiet);

	private:
		Log(const Log &) = delete;
		const Log & operator = (const Log &) = delete;

		std::unique_ptr<streamhook> mCoutHook;
		std::unique_ptr<streamhook> mCerrHook;
	};
}