#include "Common.h"
#include "Dae.h"
#include "XmlDoc.h"

using namespace opencollada;
using namespace std;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<>
			std::wstring ToString(const XmlNode & n)
			{
				wstringstream s;
				s << n.name().c_str();
				return s.str();
			}
		}
	}
}

namespace opencollada_test
{
	TEST_CLASS(XmlDocTest)
	{
	public:
		TEST_METHOD(Constructor)
		{
			XmlDoc doc;
			Assert::IsFalse(doc);
		}

		TEST_METHOD(MoveConstructor)
		{
			XmlDoc doc1;
			Assert::IsFalse(doc1);
			doc1.readFile(data_path("xml/file.dae"));
			Assert::IsTrue(doc1);

			XmlDoc doc2(move(doc1));
			Assert::IsFalse(doc1);
			Assert::IsTrue(doc2);
		}

		TEST_METHOD(Destructor)
		{
			XmlDoc doc;
			Assert::IsFalse(doc);
			doc.readFile(data_path("xml/file.dae"));
			Assert::IsTrue(doc);
			const auto & nodes = doc.root().selectNodes("//collada:COLLADA");
			Assert::AreEqual(static_cast<size_t>(1), nodes.size());
		}

		TEST_METHOD(OperatorEqual)
		{
			XmlDoc doc1;
			Assert::IsFalse(doc1);
			doc1.readFile(data_path("xml/file.dae"));
			Assert::IsTrue(doc1);

			XmlDoc doc2;
			Assert::IsFalse(doc2);
			doc2 = move(doc1);
			Assert::IsFalse(doc1);
			Assert::IsTrue(doc2);
		}

		TEST_METHOD(ReadFile)
		{
			{
				XmlDoc doc;
				Assert::IsFalse(doc);
				doc.readFile(data_path("xml/file.dae"));
				Assert::IsTrue(doc);
				doc.readFile(data_path("xml"));
				Assert::IsFalse(doc);
				doc.readFile(data_path("xml/bad_file.dae"));
				Assert::IsFalse(doc);
			}
			{
				XmlDoc doc;
				Assert::IsFalse(doc);
				doc.readFile(data_path("xml/empty.dae"));
				Assert::IsFalse(doc);
			}
			{
				XmlDoc doc;
				Assert::IsFalse(doc);
				doc.readFile(data_path("xml/compressed_file.dae"));
				Assert::IsTrue(doc);
			}
		}

		TEST_METHOD(OperatorBool)
		{
			XmlDoc doc;
			Assert::IsFalse(doc);
			doc.readFile(data_path("xml/file.dae"));
			Assert::IsTrue(doc);
		}

		TEST_METHOD(Reset)
		{
			XmlDoc doc;
			Assert::IsFalse(doc);
			doc.readFile(data_path("xml/file.dae"));
			Assert::IsTrue(doc);
			doc.reset();
			Assert::IsFalse(doc);
		}

		TEST_METHOD(Root)
		{
			XmlDoc doc;
			Assert::IsFalse(doc);
			auto root = doc.root();
			Assert::IsFalse(root);
			doc.readFile(data_path("xml/file.dae"));
			Assert::IsTrue(doc);
			root = doc.root();
			Assert::IsTrue(root);
		}

		TEST_METHOD(GetRootNamespace)
		{
			XmlDoc doc;
			Assert::IsFalse(doc);
			string ns = doc.getRootNamespace();
			Assert::IsTrue(ns.empty());
			doc.readFile(data_path("xml/file.dae"));
			Assert::IsTrue(doc);
			Assert::AreEqual(Dae::GetColladaNamespace141(), doc.getRootNamespace());
		}

		TEST_METHOD(SetTempRoot)
		{
			XmlDoc doc;
			Assert::IsFalse(doc);
			doc.readFile(data_path("xml/file.dae"));
			auto root = doc.root();
			auto node = doc.root().firstChild();
			Assert::AreNotEqual(root, node);
			{
				auto tempRootMod = doc.setTempRoot(node);
				auto new_root = doc.root();
				Assert::AreEqual(new_root, node);
				Assert::AreNotEqual(new_root, root);
			}
			auto restored_root = doc.root();
			Assert::AreNotEqual(restored_root, node);
			Assert::AreEqual(restored_root, root);
		}
	};
}