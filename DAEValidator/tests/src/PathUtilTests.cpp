#include "Common.h"
#include "PathUtil.h"

using namespace opencollada;
using namespace std;

namespace opencollada_test
{
	TEST_CLASS(PathUtilTest)
	{
	public:
		TEST_METHOD(Separator)
		{
#if _WIN32
			Assert::AreEqual(
				Path::Separator(),
				string("\\")
			);
#endif
		}

		TEST_METHOD(Join)
		{
			string a("a");
			string b("b");

			Assert::AreEqual(
				Path::Join(a, b),
				a + Path::Separator() + b
			);

			string a_anti_slash("a\\");

			Assert::AreEqual(
				Path::Join(a_anti_slash, b),
				a_anti_slash + b
			);
		}

		TEST_METHOD(IsDirectory)
		{
			Assert::IsTrue(Path::IsDirectory(data_path("path_util")));
			Assert::IsFalse(Path::IsDirectory(data_path("path_util/dummy")));
			Assert::IsFalse(Path::IsDirectory(data_path("path_util/unknown")));
		}

		TEST_METHOD(Exists)
		{
			Assert::IsTrue(Path::Exists(data_path("path_util")));
			Assert::IsTrue(Path::Exists(data_path("path_util/dummy")));
			Assert::IsFalse(Path::Exists(data_path("path_util/unknown")));
		}

		TEST_METHOD(GetExecutablePath)
		{
#if _WIN32
			Assert::AreNotEqual(
				Path::GetExecutablePath().find("\\COMMON7\\IDE\\COMMONEXTENSIONS\\MICROSOFT\\TESTWINDOW\\vstest.executionengine.exe"),
				string::npos
				);
#endif
		}

		TEST_METHOD(GetExecutableDirectory)
		{
			Assert::AreNotEqual(
				Path::GetExecutableDirectory().find("\\COMMON7\\IDE\\COMMONEXTENSIONS\\MICROSOFT\\TESTWINDOW"),
				string::npos
			);
		}

		TEST_METHOD(GetWorkingDirectory)
		{
			Assert::AreNotEqual(
				Path::GetWorkingDirectory().find(
#if defined(_DEBUG)
					"DAEValidator\\tests\\bin\\Debug"
#else
					"DAEValidator\\tests\\bin\\Release"
#endif
					),
				string::npos
			);
		}

		TEST_METHOD(ListDaes)
		{
			// non-recursive mode
			auto daes = Path::ListDaes(data_path("path_util"), false);
			Assert::AreEqual(static_cast<size_t>(1), daes.size());

			// recursive mode
			daes = Path::ListDaes(data_path("path_util"), true);
			Assert::AreEqual(static_cast<size_t>(4), daes.size());
		}

		TEST_METHOD(GetAbsolutePath)
		{
			Assert::AreEqual(Path::GetWorkingDirectory(), Path::GetAbsolutePath(""));
			Assert::AreEqual(Path::GetWorkingDirectory(), Path::GetAbsolutePath("."));
			Assert::AreEqual(string("/"), Path::GetAbsolutePath("/"));
			Assert::AreEqual(string("/bbb"), Path::GetAbsolutePath("/aaa/../bbb"));
#if _WIN32
			Assert::AreEqual(string("C:\\"), Path::GetAbsolutePath("C:\\"));
			Assert::AreEqual(string("C:\\aaa\\ccc"), Path::GetAbsolutePath("C:\\aaa\\bbb\\..\\ccc"));
#endif
			Assert::AreEqual(Path::Join(Path::GetWorkingDirectory(), string("aaa")), Path::GetAbsolutePath("aaa"));
			Assert::AreEqual(Path::Join(Path::GetWorkingDirectory(), string("bbb")), Path::GetAbsolutePath("aaa/../bbb"));
		}

		TEST_METHOD(RemoveDotSegments)
		{
			Assert::AreEqual(string(""), Path::RemoveDotSegments(""));
			Assert::AreEqual(string(""), Path::RemoveDotSegments("."));
			Assert::AreEqual(string(""), Path::RemoveDotSegments("./"));
			Assert::AreEqual(string("a"), Path::RemoveDotSegments("./a"));
			Assert::AreEqual(string("a/"), Path::RemoveDotSegments("./a/"));
			Assert::AreEqual(string("a/b"), Path::RemoveDotSegments("./a/b"));
			Assert::AreEqual(string("a/b/"), Path::RemoveDotSegments("./a/b/"));
			Assert::AreEqual(string("a/b/"), Path::RemoveDotSegments("./a/b/."));
			Assert::AreEqual(string("a/b/"), Path::RemoveDotSegments("./a/b/./"));
			Assert::AreEqual(string("a/b/"), Path::RemoveDotSegments("./a/b/./."));
			Assert::AreEqual(string("a/b/c"), Path::RemoveDotSegments("./a/b/././c"));
			Assert::AreEqual(string(""), Path::RemoveDotSegments(".."));
			Assert::AreEqual(string(""), Path::RemoveDotSegments("../"));
			Assert::AreEqual(string("a"), Path::RemoveDotSegments("../a"));
			Assert::AreEqual(string("a/"), Path::RemoveDotSegments("../a/"));
			Assert::AreEqual(string("a/b"), Path::RemoveDotSegments("../a/b"));
			Assert::AreEqual(string("a/b/"), Path::RemoveDotSegments("../a/b/"));
			Assert::AreEqual(string("a/"), Path::RemoveDotSegments("../a/b/.."));
			Assert::AreEqual(string("a/"), Path::RemoveDotSegments("../a/b/../"));
			Assert::AreEqual(string("/"), Path::RemoveDotSegments("../a/b/../.."));
			Assert::AreEqual(string("/c"), Path::RemoveDotSegments("../a/b/../../c"));
			Assert::AreEqual(string("/a/b"), Path::RemoveDotSegments("/a/b"));
			Assert::AreEqual(string("/a/c"), Path::RemoveDotSegments("/a/b/../c"));
			Assert::AreEqual(string("/"), Path::RemoveDotSegments("/a/b/../.."));
			Assert::AreEqual(string("/"), Path::RemoveDotSegments("/a/b/../../"));
			Assert::AreEqual(string("/c/d"), Path::RemoveDotSegments("/a/b/../../c/d"));
			Assert::AreEqual(string("/a/b/e"), Path::RemoveDotSegments("/a/b/./c/../d/./../e"));
#if _WIN32
			Assert::AreEqual(string("\\a\\b\\e"), Path::RemoveDotSegments("\\a\\b\\.\\c\\..\\d\\.\\..\\e"));
#endif
		}

		TEST_METHOD(GetFileBase)
		{
#if _WIN32
			Assert::AreEqual(string("file"), Path::GetFileBase("C:\\dir\\file.ext"));
			Assert::AreEqual(string(".file"), Path::GetFileBase(".\\path\\.file"));
#endif
			Assert::AreEqual(string("file"), Path::GetFileBase("file"));
			Assert::AreEqual(string("file"), Path::GetFileBase("file.ext"));
		}

		TEST_METHOD(GetFileSize)
		{
			Assert::AreEqual(static_cast<size_t>(4), Path::GetFileSize(data_path("path_util/root.txt")));
			Assert::AreEqual(static_cast<size_t>(0), Path::GetFileSize(data_path("path_util/dummy")));
			Assert::AreEqual(static_cast<size_t>(0), Path::GetFileSize(data_path("path_util/unknown")));
		}
	};
}