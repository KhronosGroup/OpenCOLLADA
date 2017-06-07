#include "Common.h"
#include "StringUtil.h"

using namespace opencollada;
using namespace std;

namespace opencollada_test
{
	TEST_CLASS(StringUtilTest)
	{
	public:
		TEST_METHOD(StartsWith)
		{
			Assert::IsTrue(String::StartsWith("abcdef", "a"));
			Assert::IsTrue(String::StartsWith("abcdef", "abc"));
			Assert::IsTrue(String::StartsWith("abcdef", "abcdef"));
			Assert::IsFalse(String::StartsWith("abcdef", "b"));
			Assert::IsFalse(String::StartsWith("abcdef", "abcdefg"));
		}

		TEST_METHOD(EndsWith)
		{
			Assert::IsTrue(String::EndsWith("abcdef", "f"));
			Assert::IsTrue(String::EndsWith("abcdef", "def"));
			Assert::IsTrue(String::EndsWith("abcdef", "abcdef"));
			Assert::IsFalse(String::EndsWith("abcdef", "e"));
			Assert::IsFalse(String::EndsWith("abcdef", "zabcdef"));
		}

		TEST_METHOD(Split)
		{
			Assert::IsTrue(String::Split("") == vector<string>{});
			Assert::IsTrue(String::Split("abcd") == vector<string>{"abcd"});
			Assert::IsTrue(String::Split("a\nb\tc d") == vector<string>{"a", "b", "c", "d"});
			Assert::IsTrue(String::Split("aaa\n\t bbb\t\n c_c \n\t\n\t\t\n\n   d5") == vector<string>{"aaa", "bbb", "c_c", "d5"});
		}

		TEST_METHOD(Lower)
		{
			Assert::AreEqual(string(""), String::Lower(""));
			Assert::AreEqual(
				string("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz0123456789\n\t ²&~\"#'{([-|`_\\^@°)]+=}$£¤%µ*,?;.:/!§<>"),
				String::Lower("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n\t ²&~\"#'{([-|`_\\^@°)]+=}$£¤%µ*,?;.:/!§<>")
			);
		}

		TEST_METHOD(Replace)
		{
			Assert::AreEqual(string(""), String::Replace("", "", ""));
			Assert::AreEqual(string("b"), String::Replace("", "", "b"));
			Assert::AreEqual(string(""), String::Replace("", "a", ""));
			Assert::AreEqual(string(""), String::Replace("", "a", "b"));
			Assert::AreEqual(string("a"), String::Replace("a", "", ""));
			Assert::AreEqual(string("a"), String::Replace("a", "", "b"));
			Assert::AreEqual(string("b"), String::Replace("a", "a", "b"));
			Assert::AreEqual(string(""), String::Replace("", "a", "a"));
			Assert::AreEqual(string("a"), String::Replace("a", "", "a"));
			Assert::AreEqual(string("a"), String::Replace("a", "a", "a"));
			Assert::AreEqual(string("That is a sentence."), String::Replace("This is a sentence.", "This", "That"));
			Assert::AreEqual(string("This is a word."), String::Replace("This is a sentence.", "sentence", "word"));
			Assert::AreEqual(string("This is a longer sentence."), String::Replace("This is a sentence.", "sentence", "longer sentence"));
			Assert::AreEqual(string("This_is_a_sentence."), String::Replace("This is a sentence.", " ", "_"));
			Assert::AreEqual(string("This__is__a__sentence."), String::Replace("This is a sentence.", " ", "__"));
			Assert::AreEqual(string("Thisisasentence."), String::Replace("This is a sentence.", " ", ""));
		}

		TEST_METHOD(ReplaceChar)
		{
			string str = "";
			size_t res = String::Replace(str, ' ', 'a');
			Assert::AreEqual(static_cast<size_t>(0), res);
			Assert::AreEqual(string(""), str);

			str = "This is a sentence.";
			res = String::Replace(str, ' ', '_');
			Assert::AreEqual(static_cast<size_t>(3), res);
			Assert::AreEqual(string("This_is_a_sentence."), str);

			str = "This is a sentence.";
			res = String::Replace(str, 'i', 'i');
			Assert::AreEqual(static_cast<size_t>(2), res);
			Assert::AreEqual(string("This is a sentence."), str);

			str = "This is a sentence.";
			res = String::Replace(str, '.', '!');
			Assert::AreEqual(static_cast<size_t>(1), res);
			Assert::AreEqual(string("This is a sentence!"), str);

			str = "This is a sentence.";
			res = String::Replace(str, '?', '!');
			Assert::AreEqual(static_cast<size_t>(0), res);
			Assert::AreEqual(string("This is a sentence."), str);
		}
	};
}