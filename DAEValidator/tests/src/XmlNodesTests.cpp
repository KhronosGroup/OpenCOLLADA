#include "Common.h"
#include "XmlDoc.h"
#include "XmlNodes.h"

using namespace opencollada;
using namespace std;

namespace opencollada_test
{
	TEST_CLASS(XmlNodesTest)
	{
	public:
		TEST_METHOD(Constructor)
		{
			{
				auto b = XmlNodeIteratorByName();
				auto e = XmlNodeIteratorByName();
				XmlNodes<XmlNodeIteratorByName> nodes(b, e);
				Assert::IsFalse(nodes);
			}
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/file.dae"));
				auto b = XmlNodeIteratorByName(doc.root());
				auto e = XmlNodeIteratorByName();
				XmlNodes<XmlNodeIteratorByName> nodes(b, e);
				Assert::IsTrue(nodes);
			}
		}

		TEST_METHOD(Begin)
		{
			{
				auto b = XmlNodeIteratorByName();
				auto e = XmlNodeIteratorByName();
				XmlNodes<XmlNodeIteratorByName> nodes(b, e);
				Assert::IsFalse(*nodes.begin());
			}
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/file.dae"));
				auto b = XmlNodeIteratorByName(doc.root());
				auto e = XmlNodeIteratorByName();
				XmlNodes<XmlNodeIteratorByName> nodes(b, e);
				Assert::IsTrue(*nodes.begin() == doc.root());
			}
		}

		TEST_METHOD(End)
		{
			{
				auto b = XmlNodeIteratorByName();
				auto e = XmlNodeIteratorByName();
				XmlNodes<XmlNodeIteratorByName> nodes(b, e);
				Assert::IsFalse(*nodes.end());
			}
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/file.dae"));
				auto b = XmlNodeIteratorByName(doc.root());
				auto e = XmlNodeIteratorByName();
				XmlNodes<XmlNodeIteratorByName> nodes(b, e);
				Assert::IsFalse(*nodes.end());
			}
		}

		TEST_METHOD(OperatorBool)
		{
			{
				auto b = XmlNodeIteratorByName();
				auto e = XmlNodeIteratorByName();
				XmlNodes<XmlNodeIteratorByName> nodes(b, e);
				Assert::IsFalse(nodes);
			}
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/file.dae"));
				auto b = XmlNodeIteratorByName(doc.root());
				auto e = XmlNodeIteratorByName();
				XmlNodes<XmlNodeIteratorByName> nodes(b, e);
				Assert::IsTrue(nodes);
			}
		}

		TEST_METHOD(XmlNodeIteratorByNameDefaultConstructor)
		{
			XmlNodeIteratorByName it;
			Assert::IsFalse(*it);
		}

		TEST_METHOD(XmlNodeIteratorByNameConstructor)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));
			auto it = XmlNodeIteratorByName(doc.root());
			Assert::IsTrue(*it);
		}

		TEST_METHOD(XmlNodeIteratorByNameDereferenceOperator)
		{
			{
				XmlNodeIteratorByName it;
				Assert::IsFalse(*it);
			}
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/file.dae"));
				auto it = XmlNodeIteratorByName(doc.root());
				Assert::IsTrue(*it);
			}
		}

		TEST_METHOD(XmlNodeIteratorByNameIncrementOperator)
		{
			{
				XmlNodeIteratorByName it;
				Assert::IsFalse(*it);
				++it;
				Assert::IsFalse(*it);
			}
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/file.dae"));
				{
					auto it = XmlNodeIteratorByName(doc.root());
					Assert::IsTrue(*it);
					++it;
					Assert::IsFalse(*it);
				}
				{
					const auto & skin_sources = doc.root().selectNodes("//collada:skin/collada:source");
					auto it = XmlNodeIteratorByName(skin_sources[0]);
					Assert::IsTrue(*it); ++it;
					Assert::IsTrue(*it); ++it;
					Assert::IsTrue(*it); ++it;
					Assert::IsFalse(*it);
				}
			}
		}

		TEST_METHOD(XmlNodeIteratorByNameOperatorIsNotEqual)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));

			const auto & skin_sources = doc.root().selectNodes("//collada:skin/collada:source");

			auto root = XmlNodeIteratorByName(doc.root());
			auto null = XmlNodeIteratorByName();
			auto source = XmlNodeIteratorByName(skin_sources[0]);

			Assert::IsFalse(root != root);
			Assert::IsFalse(null != null);
			Assert::IsFalse(source != source);
			Assert::IsTrue(root != null);
			Assert::IsTrue(root != source);
			Assert::IsTrue(source != null);
			++source;
			Assert::IsTrue(root != source);
			Assert::IsTrue(source != null);
			++source;
			Assert::IsTrue(root != source);
			Assert::IsTrue(source != null);
			++source;
			Assert::IsTrue(root != source);
			Assert::IsFalse(source != null);
		}
	};
}