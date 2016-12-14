#include <libxml/parser.h>
#if defined(_WIN32)
#include <array>
#include <Windows.h>
#endif

#include "Log.h"
#include "stdarg.h"

using namespace std;

namespace opencollada
{
	streamhook::streamhook(ostream & stream, bool quiet, const hookcallback & callback)
		: mStream(stream)
		, mCallback(callback)
		, mQuiet(quiet)
	{
		mStreamBuf = stream.rdbuf(this);
	}

	streamhook::~streamhook()
	{
		// Restore stream buffer
		mStream.rdbuf(mStreamBuf);
	}

	streamsize streamhook::xsputn(const char *_Ptr, streamsize _Count)
	{
		string str(_Ptr, _Count);

		if (mCallback)
		{
			mCallback(str);
		}

		if (!mQuiet)
		{
			mStream.rdbuf(mStreamBuf);
			mStream << str;
			mStream.rdbuf(this);
		}

		return _Count;
	}

	char_traits<char>::int_type streamhook::overflow(char_traits<char>::int_type v)
	{
		char ch = char_traits<char>::to_char_type(v);
		string str(&ch, 1);

		if (mCallback)
		{
			mCallback(str);
		}

		if (!mQuiet)
		{
			mStream.rdbuf(mStreamBuf);
			mStream << str;
			mStream.rdbuf(this);
		}

		return char_traits<char>::not_eof(v);
	}

	void libxmlhook::GenericErrorFunc(void *ctx, const char *msg, ...)
	{}

	unique_ptr<streamhook> Log::mCoutHook;
	unique_ptr<streamhook> Log::mCerrHook;

	void Log::Setup(bool quiet)
	{
		// mute/unmute cout and redirect to VS output
		mCoutHook.reset(new streamhook(cout, quiet, [=](const std::string & str) {
#if defined(_WIN32)
			if (!quiet)
				OutputDebugString(str.c_str());
#endif
		}));

		// mute/unmute cerr and redirect to VS output
		mCerrHook.reset(new streamhook(cerr, quiet, [=](const std::string & str) {
#if defined(_WIN32)
			if (!quiet)
				OutputDebugString(str.c_str());
#endif
		}));

		// mute/unmute libxml output
		if (quiet)
		{
			xmlSetGenericErrorFunc(nullptr, libxmlhook::GenericErrorFunc);
		}
		else
		{
			xmlSetGenericErrorFunc(nullptr, nullptr);
		}
	}
}