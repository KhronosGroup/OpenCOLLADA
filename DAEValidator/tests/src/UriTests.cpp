#include "Common.h"
#include "Uri.h"

using namespace opencollada;
using namespace std;

namespace opencollada_test
{
	static const char* codes[] = {
		"%00", "%01", "%02", "%03", "%04", "%05", "%06", "%07", "%08", "%09", "%0A", "%0B", "%0C", "%0D", "%0E", "%0F",
		"%10", "%11", "%12", "%13", "%14", "%15", "%16", "%17", "%18", "%19", "%1A", "%1B", "%1C", "%1D", "%1E", "%1F",
		"%20", "%21", "%22", "%23", "%24", "%25", "%26", "%27", "%28", "%29", "%2A", "%2B", "%2C", "%2D", "%2E", "%2F",
		"%30", "%31", "%32", "%33", "%34", "%35", "%36", "%37", "%38", "%39", "%3A", "%3B", "%3C", "%3D", "%3E", "%3F",
		"%40", "%41", "%42", "%43", "%44", "%45", "%46", "%47", "%48", "%49", "%4A", "%4B", "%4C", "%4D", "%4E", "%4F",
		"%50", "%51", "%52", "%53", "%54", "%55", "%56", "%57", "%58", "%59", "%5A", "%5B", "%5C", "%5D", "%5E", "%5F",
		"%60", "%61", "%62", "%63", "%64", "%65", "%66", "%67", "%68", "%69", "%6A", "%6B", "%6C", "%6D", "%6E", "%6F",
		"%70", "%71", "%72", "%73", "%74", "%75", "%76", "%77", "%78", "%79", "%7A", "%7B", "%7C", "%7D", "%7E", "%7F",
		"%80", "%81", "%82", "%83", "%84", "%85", "%86", "%87", "%88", "%89", "%8A", "%8B", "%8C", "%8D", "%8E", "%8F",
		"%90", "%91", "%92", "%93", "%94", "%95", "%96", "%97", "%98", "%99", "%9A", "%9B", "%9C", "%9D", "%9E", "%9F",
		"%A0", "%A1", "%A2", "%A3", "%A4", "%A5", "%A6", "%A7", "%A8", "%A9", "%AA", "%AB", "%AC", "%AD", "%AE", "%AF",
		"%B0", "%B1", "%B2", "%B3", "%B4", "%B5", "%B6", "%B7", "%B8", "%B9", "%BA", "%BB", "%BC", "%BD", "%BE", "%BF",
		"%C0", "%C1", "%C2", "%C3", "%C4", "%C5", "%C6", "%C7", "%C8", "%C9", "%CA", "%CB", "%CC", "%CD", "%CE", "%CF",
		"%D0", "%D1", "%D2", "%D3", "%D4", "%D5", "%D6", "%D7", "%D8", "%D9", "%DA", "%DB", "%DC", "%DD", "%DE", "%DF",
		"%E0", "%E1", "%E2", "%E3", "%E4", "%E5", "%E6", "%E7", "%E8", "%E9", "%EA", "%EB", "%EC", "%ED", "%EE", "%EF",
		"%F0", "%F1", "%F2", "%F3", "%F4", "%F5", "%F6", "%F7", "%F8", "%F9", "%FA", "%FB", "%FC", "%FD", "%FE", "%FF",
	};

	TEST_CLASS(UriTest)
	{
	public:
		TEST_METHOD(DefaultConstructor)
		{
			Uri uri;
			Assert::IsTrue(uri.empty());
			Assert::IsFalse(uri.isValid());
		}

		TEST_METHOD(ConstructorString)
		{
			{
				Uri uri("");
				Assert::IsTrue(uri.empty());
				Assert::IsTrue(uri.isValid());
			}
			{
				Uri uri("scheme://user:password@host:port/path/file.ext?query#fragment");
				Assert::IsFalse(uri.empty());
				Assert::IsTrue(uri.isValid());
				Assert::AreEqual(string("scheme"), uri.scheme());
				Assert::AreEqual(string("user:password@host:port"), uri.authority());
				Assert::AreEqual(string("/path/file.ext"), uri.path());
				Assert::AreEqual(string("file.ext"), uri.pathFile());
				Assert::AreEqual(string("query"), uri.query());
				Assert::AreEqual(string("fragment"), uri.fragment());
			}
		}

		TEST_METHOD(ConstructorUriUri)
		{
			{
				Uri a, b;
				Uri uri(a, b);
				Assert::IsTrue(uri.empty());
				Assert::IsTrue(uri.isValid());
			}
			{
				Uri base = "scheme://user:password@host:port/path1/";
				Uri rel = "../path2/file.ext?query#fragment";
				Uri uri(base, rel);
				Assert::IsFalse(uri.empty());
				Assert::IsTrue(uri.isValid());
				Assert::AreEqual(string("scheme"), uri.scheme());
				Assert::AreEqual(string("user:password@host:port"), uri.authority());
				Assert::AreEqual(string("/path2/file.ext"), uri.path());
				Assert::AreEqual(string("file.ext"), uri.pathFile());
				Assert::AreEqual(string("query"), uri.query());
				Assert::AreEqual(string("fragment"), uri.fragment());
			}
		}

		TEST_METHOD(OperatorIsEqual)
		{
			Assert::IsTrue(Uri() == Uri());
			Assert::IsTrue(Uri("") == Uri(""));
			Assert::IsTrue(Uri("scheme://user:password@host:port/path/file.ext?query#fragment") == Uri("scheme://user:password@host:port/path/file.ext?query#fragment"));
			Assert::IsFalse(Uri("a") == Uri("b"));
		}

		TEST_METHOD(OperatorIsNotEqual)
		{
			Assert::IsFalse(Uri() != Uri());
			Assert::IsFalse(Uri("") != Uri(""));
			Assert::IsFalse(Uri("scheme://user:password@host:port/path/file.ext?query#fragment") != Uri("scheme://user:password@host:port/path/file.ext?query#fragment"));
			Assert::IsTrue(Uri("a") != Uri("b"));
		}

		TEST_METHOD(OperatorIsLess)
		{
			Assert::IsFalse(Uri() < Uri());
			Assert::IsFalse(Uri("") < Uri(""));
			Assert::IsFalse(Uri("scheme://user:password@host:port/path/file.ext?query#fragment") < Uri("scheme://user:password@host:port/path/file.ext?query#fragment"));
			Assert::IsTrue(Uri("a") < Uri("b"));
			Assert::IsFalse(Uri("b") < Uri("a"));
		}

		TEST_METHOD(Empty)
		{
			Assert::IsTrue(Uri().empty());
			Assert::IsTrue(Uri("").empty());
			Assert::IsFalse(Uri("scheme://user:password@host:port/path/file.ext?query#fragment").empty());
		}

		TEST_METHOD(IsValid)
		{
			Assert::IsFalse(Uri().isValid());
			Assert::IsTrue(Uri("").isValid());
			Assert::IsTrue(Uri("scheme://user:password@host:port/path/file.ext?query#fragment").isValid());
			Uri uri("scheme://user:password@host:port/path/file.ext?query#fragment");
			uri.clear();
			Assert::IsFalse(uri.isValid());
		}

		TEST_METHOD(Str)
		{
			Assert::AreEqual(string(), Uri().str());
			Assert::AreEqual(string(""), Uri("").str());
			Assert::AreEqual(string("scheme://user:password@host:port/path/file.ext?query#fragment"), Uri("scheme://user:password@host:port/path/file.ext?query#fragment").str());
		}

		TEST_METHOD(Scheme)
		{
			Assert::AreEqual(string(), Uri().scheme());
			Assert::AreEqual(string(""), Uri("").scheme());
			Assert::AreEqual(string("scheme"), Uri("scheme://user:password@host:port/path/file.ext?query#fragment").scheme());
		}

		TEST_METHOD(Authority)
		{
			Assert::AreEqual(string(), Uri().authority());
			Assert::AreEqual(string(""), Uri("").authority());
			Assert::AreEqual(string("user:password@host:port"), Uri("scheme://user:password@host:port/path/file.ext?query#fragment").authority());
		}

		TEST_METHOD(Path)
		{
			Assert::AreEqual(string(), Uri().path());
			Assert::AreEqual(string(""), Uri("").path());
			Assert::AreEqual(string("/path/file.ext"), Uri("scheme://user:password@host:port/path/file.ext?query#fragment").path());
		}

		TEST_METHOD(Query)
		{
			Assert::AreEqual(string(), Uri().query());
			Assert::AreEqual(string(""), Uri("").query());
			Assert::AreEqual(string("query"), Uri("scheme://user:password@host:port/path/file.ext?query#fragment").query());
		}

		TEST_METHOD(Fragment)
		{
			Assert::AreEqual(string(), Uri().fragment());
			Assert::AreEqual(string(""), Uri("").fragment());
			Assert::AreEqual(string("fragment"), Uri("scheme://user:password@host:port/path/file.ext?query#fragment").fragment());
		}

		TEST_METHOD(SetScheme)
		{
			Uri uri = "scheme://user:password@host:port/path/file.ext?query#fragment";
			Assert::AreEqual(string("scheme"), uri.scheme());
			uri.setScheme("file");
			Assert::AreEqual(string("file"), uri.scheme());
			uri.setScheme("");
			Assert::AreEqual(string(""), uri.scheme());
		}

		TEST_METHOD(SetFragment)
		{
			Uri uri = "scheme://user:password@host:port/path/file.ext?query#fragment";
			Assert::AreEqual(string("fragment"), uri.fragment());
			uri.setFragment("id");
			Assert::AreEqual(string("id"), uri.fragment());
			uri.setFragment("");
			Assert::AreEqual(string(""), uri.fragment());
		}

		TEST_METHOD(SetPathFile)
		{
			Uri uri = "scheme://user:password@host:port/path/file.ext?query#fragment";
			Assert::AreEqual(string("file.ext"), uri.pathFile());
			uri.setPathFile(".other");
			Assert::AreEqual(string(".other"), uri.pathFile());
			uri.setPathFile("");
			Assert::AreEqual(string(""), uri.pathFile());
		}

		TEST_METHOD(PathFile)
		{
			Assert::AreEqual(string(), Uri().pathFile());
			Assert::AreEqual(string(""), Uri("").pathFile());
			Assert::AreEqual(string("file.ext"), Uri("scheme://user:password@host:port/path/file.ext?query#fragment").pathFile());
		}

		TEST_METHOD(NativePath)
		{
			Assert::AreEqual(string(), Uri().nativePath());
			Assert::AreEqual(string(), Uri("").nativePath());
			Assert::AreEqual(string(), Uri("scheme://user:password@host:port/path/file.ext?query#fragment").nativePath());
#if _WIN32
			Assert::AreEqual(string("C:\\path\\file.ext"), Uri("file:///C:/path/file.ext?query#fragment").nativePath());
			Assert::AreEqual(string("..\\path\\file.ext"), Uri("../path/file.ext?query#fragment").nativePath());
			Assert::AreEqual(string("\\\\computer\\path\\file.ext"), Uri("file://///computer/path/file.ext?query#fragment").nativePath());
			Assert::AreEqual(string("\\\\computer\\path\\file.ext"), Uri("file://computer/path/file.ext?query#fragment").nativePath());
#endif
		}

		TEST_METHOD(Clear)
		{
			Uri uri;
			Assert::IsTrue(uri.empty());
			uri.clear();
			Assert::IsTrue(uri.empty());
			uri.set("");
			Assert::IsTrue(uri.empty());
			uri.clear();
			Assert::IsTrue(uri.empty());
			uri.set("a");
			Assert::IsFalse(uri.empty());
			uri.clear();
			Assert::IsTrue(uri.empty());
		}

		TEST_METHOD(SetString)
		{
			Uri uri;

			Assert::IsTrue(uri.empty());
			Assert::IsFalse(uri.isValid());
			Assert::AreEqual(string(), uri.scheme());
			Assert::AreEqual(string(), uri.authority());
			Assert::AreEqual(string(), uri.path());
			Assert::AreEqual(string(), uri.pathFile());
			Assert::AreEqual(string(), uri.query());
			Assert::AreEqual(string(), uri.fragment());

			uri.set("scheme://user:password@host:port/path/file.ext?query#fragment");

			Assert::IsFalse(uri.empty());
			Assert::IsTrue(uri.isValid());
			Assert::AreEqual(string("scheme"), uri.scheme());
			Assert::AreEqual(string("user:password@host:port"), uri.authority());
			Assert::AreEqual(string("/path/file.ext"), uri.path());
			Assert::AreEqual(string("file.ext"), uri.pathFile());
			Assert::AreEqual(string("query"), uri.query());
			Assert::AreEqual(string("fragment"), uri.fragment());
		}

		TEST_METHOD(SetUriUri)
		{
			Uri uri;

			Assert::IsTrue(uri.empty());
			Assert::IsFalse(uri.isValid());
			Assert::AreEqual(string(), uri.scheme());
			Assert::AreEqual(string(), uri.authority());
			Assert::AreEqual(string(), uri.path());
			Assert::AreEqual(string(), uri.pathFile());
			Assert::AreEqual(string(), uri.query());
			Assert::AreEqual(string(), uri.fragment());

			Uri base = "scheme://user:password@host:port/path1/";
			Uri rel = "../path2/file.ext?query#fragment";
			uri.set(base, rel);

			Assert::IsFalse(uri.empty());
			Assert::IsTrue(uri.isValid());
			Assert::AreEqual(string("scheme"), uri.scheme());
			Assert::AreEqual(string("user:password@host:port"), uri.authority());
			Assert::AreEqual(string("/path2/file.ext"), uri.path());
			Assert::AreEqual(string("file.ext"), uri.pathFile());
			Assert::AreEqual(string("query"), uri.query());
			Assert::AreEqual(string("fragment"), uri.fragment());

			rel.set("file://authority/path/file.ext?query#fragment");
			uri.set(base, rel);
			Assert::IsFalse(uri.empty());
			Assert::IsTrue(uri.isValid());
			Assert::AreEqual(string("file"), uri.scheme());
			Assert::AreEqual(string("authority"), uri.authority());
			Assert::AreEqual(string("/path/file.ext"), uri.path());
			Assert::AreEqual(string("file.ext"), uri.pathFile());
			Assert::AreEqual(string("query"), uri.query());
			Assert::AreEqual(string("fragment"), uri.fragment());

			rel.set("//authority/path/file.ext?query#fragment");
			uri.set(base, rel);
			Assert::IsFalse(uri.empty());
			Assert::IsTrue(uri.isValid());
			Assert::AreEqual(string("scheme"), uri.scheme());
			Assert::AreEqual(string("authority"), uri.authority());
			Assert::AreEqual(string("/path/file.ext"), uri.path());
			Assert::AreEqual(string("file.ext"), uri.pathFile());
			Assert::AreEqual(string("query"), uri.query());
			Assert::AreEqual(string("fragment"), uri.fragment());

			rel.set("?query#fragment");
			uri.set(base, rel);
			Assert::IsFalse(uri.empty());
			Assert::IsTrue(uri.isValid());
			Assert::AreEqual(string("scheme"), uri.scheme());
			Assert::AreEqual(string("user:password@host:port"), uri.authority());
			Assert::AreEqual(string("/path1/"), uri.path());
			Assert::AreEqual(string(""), uri.pathFile());
			Assert::AreEqual(string("query"), uri.query());
			Assert::AreEqual(string("fragment"), uri.fragment());

			rel.set("/path/");
			uri.set(base, rel);
			Assert::IsFalse(uri.empty());
			Assert::IsTrue(uri.isValid());
			Assert::AreEqual(string("scheme"), uri.scheme());
			Assert::AreEqual(string("user:password@host:port"), uri.authority());
			Assert::AreEqual(string("/path/"), uri.path());
			Assert::AreEqual(string(""), uri.pathFile());
			Assert::AreEqual(string(""), uri.query());
			Assert::AreEqual(string(""), uri.fragment());
		}

		TEST_METHOD(FromNativePath)
		{
#if _WIN32
			Assert::IsTrue(
				Uri::FromNativePath("C:\\path\\file.ext") ==
				Uri("file:///C:/path/file.ext")
			);
#endif
		}

		TEST_METHOD(Decode)
		{
			for (char c = 0; c >= 0; ++c)
			{
				string expected;
				expected += c;
				string encoded = codes[c];
				string decoded = Uri::Decode(encoded);
				Assert::AreEqual(expected, decoded);
			}
		}

		TEST_METHOD(Encode)
		{
			for (char c = 0; c <= 32; ++c)
			{
				string expected = codes[c];
				string decoded;
				decoded += c;
				string encoded = Uri::Encode(decoded);
				Assert::AreEqual(expected, encoded);
			}

			for (char c = 33; c >= 0; ++c)
			{
				string expected;
				expected += c;
				string encoded = Uri::Encode(expected);
				Assert::AreEqual(expected, encoded);
			}
		}

		TEST_METHOD(Parse)
		{
			string scheme;
			string authority;
			string path;
			string query;
			string fragment;
			Assert::IsTrue(Uri::Parse("scheme://user:password@host:port/path/file.ext?query#fragment", scheme, authority, path, query, fragment));
			Assert::AreEqual(string("scheme"), scheme);
			Assert::AreEqual(string("user:password@host:port"), authority);
			Assert::AreEqual(string("/path/file.ext"), path);
			Assert::AreEqual(string("query"), query);
			Assert::AreEqual(string("fragment"), fragment);
		}

		TEST_METHOD(MergePaths)
		{
			Uri base = "scheme://host";
			Uri rel = "./path";

			Uri uri;
			uri.set(base, rel);
			Assert::AreEqual("scheme://host/path", uri.str().c_str());

			base.set("scheme://host/path1");
			rel.set("./path2");
			uri.set(base, rel);
			Assert::AreEqual("scheme://host/path2", uri.str().c_str());

			base.set("scheme://host/path1/");
			rel.set("./path2");
			uri.set(base, rel);
			Assert::AreEqual("scheme://host/path1/path2", uri.str().c_str());

			base.set("scheme://host/path1/");
			rel.set("./path2/");
			uri.set(base, rel);
			Assert::AreEqual("scheme://host/path1/path2/", uri.str().c_str());

			base.set("scheme://host");
			rel.set("./path2");
			uri.set(base, rel);
			Assert::AreEqual("scheme://host/path2", uri.str().c_str());

			base.set("scheme://");
			rel.set("/path2");
			uri.set(base, rel);
			Assert::AreEqual("scheme:///path2", uri.str().c_str());

			base.set("");
			rel.set("./path");
			uri.set(base, rel);
			Assert::AreEqual("path", uri.str().c_str());
		}

		TEST_METHOD(OstreamOperatorRightShift)
		{
			Uri uri = "scheme://user:password@host:port/path/file.ext?query#fragment";
			stringstream ss;
			ss << uri;
			Assert::AreEqual("scheme://user:password@host:port/path/file.ext?query#fragment", ss.str().c_str());
		}

		TEST_METHOD(RebuildFast)
		{
			Uri uri = "scheme://user:password@host:port/path/file.ext?query#fragment";
			uri.setFragment("new_fragment");
			Assert::AreEqual("scheme://user:password@host:port/path/file.ext?query#new_fragment", uri.str().c_str());
		}
	};
}