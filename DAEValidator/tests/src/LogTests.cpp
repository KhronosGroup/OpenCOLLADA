#include "Common.h"
#include "Log.h"

using namespace opencollada;
using namespace std;

namespace opencollada_test
{
	TEST_CLASS(LogTest)
	{
	public:
		static const string blabla;
		static const string noblabla;

		TEST_METHOD(StreamhookConstructor)
		{
			string test;
			streamhook hook(cout, true, [&](const string & s) {
				test = s;
			});
			cout << blabla;
			Assert::AreEqual(blabla, test);
		}

		TEST_METHOD(StreamhookDestructor)
		{
			string test;
			{
				streamhook hook(cout, true, [&](const string & s) {
					test = s;
				});
				cout << blabla;
				Assert::AreEqual(blabla, test);
			}
			cout << "no blabla";
			Assert::AreEqual(blabla, test);
		}

		TEST_METHOD(LibxmlhookGenericErrorFunc)
		{
			libxmlhook::GenericErrorFunc(nullptr, nullptr);
			libxmlhook::GenericErrorFunc(nullptr, "test");
			libxmlhook::GenericErrorFunc(nullptr, "test %i %i %i %s", 1, 2, 3, "test");
		}

		TEST_METHOD(LogConstructor)
		{
			{
				Log log(true);
				cout << blabla;
				cerr << blabla;
			}
			{
				Log log(false);
				cout << blabla;
				cerr << blabla;
			}
		}
	};

	const string LogTest::blabla = "blabla";
	const string LogTest::noblabla = "no blabla";
}