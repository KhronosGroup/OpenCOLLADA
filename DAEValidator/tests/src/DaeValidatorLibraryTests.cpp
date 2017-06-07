#include "Common.h"
#include "DaeValidatorLibrary.h"

using namespace opencollada;
using namespace std;

namespace opencollada_test
{
	TEST_CLASS(DaeValidatorLibraryTest)
	{
	public:
		TEST_METHOD(MainNoArg)
		{
			char* argv[] = { "DAEValidator.exe" };
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(MainBadArg)
		{
			char* argv[] = {
				"DAEValidator.exe",
				"--bad-arg"
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(MainDae)
		{
			string dae = data_path("daevalidatorlibrary/file.dae");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str())
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(MainDir)
		{
			string dae = data_path("daevalidatorlibrary/main_dir");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str())
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(MainDirNoDae)
		{
			string dae = data_path("daevalidatorlibrary/no_dae");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str())
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(MainQuiet)
		{
			string dae = data_path("daevalidatorlibrary/file.dae");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str()),
				"--quiet"
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(MainCheckSchemaAuto)
		{
			string dae = data_path("daevalidatorlibrary/file.dae");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str()),
				"--check-schema-auto"
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(MainCheckSchemaAutoError)
		{
			string dae = data_path("daevalidatorlibrary/check_schema_auto_error.dae");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str()),
				"--check-schema-auto"
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreNotEqual(0, result);
		}

		TEST_METHOD(MainCheckSchema)
		{
			string dae = data_path("daevalidatorlibrary/file.dae");
			string xsd = data_path("daevalidatorlibrary/collada_schema_1_4_1.xsd");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str()),
				"--check-schema",
				const_cast<char*>(xsd.c_str())
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(MainCheckSchemaError)
		{
			string dae = data_path("daevalidatorlibrary/check_schema_error.dae");
			string xsd = data_path("daevalidatorlibrary/collada_schema_1_4_1.xsd");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str()),
				"--check-schema",
				const_cast<char*>(xsd.c_str())
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreNotEqual(0, result);
		}

		TEST_METHOD(MainCheckUniqueIds)
		{
			string dae = data_path("daevalidatorlibrary/file.dae");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str()),
				"--check-unique-ids"
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(MainCheckUniqueIdsError)
		{
			string dae = data_path("daevalidatorlibrary/check_unique_ids_error.dae");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str()),
				"--check-unique-ids"
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreNotEqual(0, result);
		}

		TEST_METHOD(MainCheckUniqueSids)
		{
			string dae = data_path("daevalidatorlibrary/file.dae");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str()),
				"--check-unique-sids"
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(MainCheckUniqueSidsError)
		{
			string dae = data_path("daevalidatorlibrary/check_unique_sids_error.dae");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str()),
				"--check-unique-sids"
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreNotEqual(0, result);
		}

		TEST_METHOD(MainCheckLinks)
		{
			string dae = data_path("daevalidatorlibrary/file.dae");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str()),
				"--check-links"
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(MainCheckLinksError)
		{
			string dae = data_path("daevalidatorlibrary/check_links_error.dae");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str()),
				"--check-links"
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreNotEqual(0, result);
		}

		TEST_METHOD(MainRecursive)
		{
			string dae = data_path("daevalidatorlibrary/main_dir");
			char* argv[] = {
				"DAEValidator.exe",
				const_cast<char*>(dae.c_str()),
				"--recursive"
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(MainHelp)
		{
			char* argv[] = {
				"DAEValidator.exe",
				"--help"
			};
			int result = main(sizeof(argv) / sizeof(argv[0]), argv);
			Assert::AreEqual(0, result);
		}
	};
}