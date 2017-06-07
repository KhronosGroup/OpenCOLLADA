#include "Common.h"
#include "ArgumentParser.h"

using namespace opencollada;
using namespace std;

namespace opencollada_test
{
	TEST_CLASS(ArgumentParserTest)
	{
	public:
		TEST_METHOD(Constructor0)
		{
			char** argv = nullptr;
			int argc = 0;
			ArgumentParser argparse(argc, argv);
		}

		TEST_METHOD(Constructor1)
		{
			char* argv[] = {
				"arg0"
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
		}

		TEST_METHOD(Constructor10)
		{
			char* argv[] = {
				"arg0",
				"arg1",
				"arg2",
				"arg3",
				"arg4",
				"arg5",
				"arg6",
				"arg7",
				"arg8",
				"arg9"
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
		}

		TEST_METHOD(ParseArgument)
		{
			char* argv[] = {
				"exe",
				"arg0",
				"switch0",
				"switch1", "param0",
				"switch2", "param0", "param1", "param2"
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
			argparse.addArgument();
			argparse.addArgument("switch0");
			argparse.addArgument("switch1").numParameters(1);
			argparse.addArgument("switch2").numParameters(3);
			Assert::IsTrue(argparse.parseArguments());
		}

		TEST_METHOD(ParseArgumentUnknownArgument)
		{
			char* argv[] = {
				"exe",
				"arg0"
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
			argparse.addArgument("switch0");
			Assert::IsFalse(argparse.parseArguments());
			Assert::AreEqual("Unknown argument: arg0", argparse.getParseError().c_str());
		}

		TEST_METHOD(ParseArgumentMissingArgumentParameter)
		{
			char* argv[] = {
				"exe",
				"switch0"
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
			argparse.addArgument("switch0").numParameters(1);
			Assert::IsFalse(argparse.parseArguments());
			Assert::AreEqual("Missing parameter for argument switch0", argparse.getParseError().c_str());
		}

		TEST_METHOD(ParseArgumentMissingArgument)
		{
			char* argv[] = {
				"exe",
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
			argparse.addArgument("switch0").required();
			Assert::IsFalse(argparse.parseArguments());
			Assert::AreEqual("Missing argument: switch0", argparse.getParseError().c_str());
		}

		TEST_METHOD(ParseArgumentMissingNoSwitchArgumentNoHint)
		{
			char* argv[] = {
				"exe",
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
			argparse.addArgument().required();
			Assert::IsFalse(argparse.parseArguments());
			Assert::AreEqual("Missing argument", argparse.getParseError().c_str());
		}

		TEST_METHOD(ParseArgumentMissingNoSwitchArgument)
		{
			char* argv[] = {
				"exe",
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
			argparse.addArgument().required().hint("arg");
			Assert::IsFalse(argparse.parseArguments());
			Assert::AreEqual("Missing argument: arg", argparse.getParseError().c_str());
		}

		TEST_METHOD(GetParseErrorWithoutError)
		{
			char* argv[] = {
				"exe",
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
			Assert::IsTrue(argparse.parseArguments());
			Assert::AreEqual("", argparse.getParseError().c_str());
		}

		TEST_METHOD(GetParseErrorWithError)
		{
			char* argv[] = {
				"exe",
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
			argparse.addArgument().required();
			Assert::IsFalse(argparse.parseArguments());
			Assert::AreNotEqual("", argparse.getParseError().c_str());
		}

		TEST_METHOD(AddArgument)
		{
			char* argv[] = {
				"exe",
				"arg",
				"arg0",
				"arg1"
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
			argparse.addArgument();
			argparse.addArgument("arg0");
			argparse.addArgument("arg0");
			argparse.addArgument("arg1");
			Assert::IsTrue(argparse.parseArguments());
		}

		TEST_METHOD(FindArgument)
		{
			char* argv[] = {
				"exe",
				"arg",
				"arg0"
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
			argparse.addArgument();
			argparse.addArgument("arg0");
			argparse.addArgument("arg0");
			argparse.addArgument("arg1");
			Assert::IsTrue(argparse.parseArguments());
			Assert::IsFalse(argparse.findArgument("unknown"));
			Assert::IsFalse(argparse.findArgument("arg1"));
			Assert::IsTrue(argparse.findArgument("arg0"));
			Assert::IsTrue(argparse.findArgument(0));
			Assert::IsFalse(argparse.findArgument(1));
		}

		TEST_METHOD(NumSetArguments0)
		{
			char* argv[] = {
				"exe"
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
			Assert::IsTrue(argparse.parseArguments());
			Assert::AreEqual(static_cast<size_t>(0), argparse.numSetArguments());
		}

		TEST_METHOD(NumSetArguments2)
		{
			char* argv[] = {
				"exe",
				"arg",
				"switch", "param"
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
			argparse.addArgument();
			argparse.addArgument("switch").numParameters(1);
			Assert::IsTrue(argparse.parseArguments());
			Assert::AreEqual(static_cast<size_t>(2), argparse.numSetArguments());
		}

		TEST_METHOD(Usage)
		{
			char* argv[] = {
				"ExecutableName"
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
			argparse.addArgument().hint("arg0_hint");
			argparse.addArgument("arg1");
			argparse.addArgument("arg2").help("Help for arg2.");
			argparse.addArgument("arg3").help("Help for arg3.").hint("Hint for arg3.");
			argparse.addArgument("long_arg4").help("Help for arg4.").hint("Hint for arg4.").numParameters(1).hint(0, "param");
			argparse.addArgument("arg5").help("Help for arg5.").hint("Hint for arg5.").numParameters(2).hint(0, "param1").hint(1, "param2");
			argparse.addArgument("arg6").help("Help for arg6.").hint("Hint for arg6.").numParameters(3).hint(0, "param1").hint(1, "param2").hint(2, "param3").required();
			argparse.parseArguments();
			string usage = argparse.usage();
			Assert::AreEqual("\nCOLLADA document validator.\n\nValidates COLLADA documents against COLLADA schema and performs several coherency tests.\n\nUsage:\n\nExecutableName arg0_hint [arg1] [arg2] [arg3] [arg5 param1 param2] arg6 param1 param2 param3 [long_arg4 param]\n\narg0_hint \narg1      \narg2      Help for arg2.\narg3      Help for arg3.\narg5      Help for arg5.\narg6      Help for arg6.\nlong_arg4 Help for arg4.\n", usage.c_str());
		}

		TEST_METHOD(GetValue)
		{
			char* argv[] = {
				"exe",
				"switch", "param"
			};
			int argc = sizeof(argv) / sizeof(argv[0]);
			ArgumentParser argparse(argc, argv);
			argparse.addArgument("switch").numParameters(1);
			Assert::IsTrue(argparse.parseArguments());
			Assert::AreEqual(static_cast<size_t>(1), argparse.numSetArguments());
			Assert::AreEqual(argparse.findArgument("switch").getValue<string>().c_str(), "param");
		}
	};
}