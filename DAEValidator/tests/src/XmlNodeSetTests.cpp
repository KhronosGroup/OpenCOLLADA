#include "Common.h"
#include "XmlDoc.h"
#include "XmlNodeSet.h"

using namespace opencollada;
using namespace std;

namespace opencollada_test
{
	TEST_CLASS(XmlNodeSetTest)
	{
	public:
		TEST_METHOD(DefaultConstructor)
		{
			XmlNodeSet nodes;
			Assert::IsTrue(nodes.empty());
		}

		TEST_METHOD(MoveConstructor)
		{
			{
				XmlNodeSet nodes;
				Assert::IsTrue(nodes.empty());
				XmlNodeSet moved = move(nodes);
				Assert::IsTrue(nodes.empty());
				Assert::IsTrue(moved.empty());
			}
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/file.dae"));
				Assert::IsTrue(doc);
				const XmlNodeSet & nodes = doc.root().selectNodes("//collada:node");
				Assert::AreEqual(static_cast<size_t>(4), nodes.size());
			}
		}

		TEST_METHOD(Destructor)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));
			Assert::IsTrue(doc);
			const XmlNodeSet & nodes = doc.root().selectNodes("//collada:node");
			Assert::AreEqual(static_cast<size_t>(4), nodes.size());
		}

		TEST_METHOD(OperatorEqual)
		{
			MoveConstructor();
		}

		void IteratorCommon()
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));
			Assert::IsTrue(doc);
			const XmlNodeSet & nodes = doc.root().selectNodes("//collada:node");
			Assert::AreEqual(static_cast<size_t>(4), nodes.size());

			for (XmlNodeSet::iterator it = nodes.begin(); it != nodes.end(); ++it)
			{
				XmlNode node = *it;
				Assert::AreEqual("node", node.name().c_str());
			}
		}

		TEST_METHOD(IteratorOperatorMul)
		{
			IteratorCommon();

			XmlNodeSet nodes;
			XmlNodeSet::iterator it = nodes.begin();
			XmlNode node = *it;
			Assert::IsFalse(node);
		}

		TEST_METHOD(IteratorOperatorPreIncrement)
		{
			IteratorCommon();
		}

		TEST_METHOD(IteratorOperatorIsNotEqual)
		{
			IteratorCommon();
		}

		TEST_METHOD(Empty)
		{
			{
				XmlNodeSet nodes;
				Assert::IsTrue(nodes.empty());
			}
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/file.dae"));
				const XmlNodeSet & nodes = doc.root().selectNodes("//collada:node");
				Assert::IsFalse(nodes.empty());
			}
		}

		TEST_METHOD(Begin)
		{
			IteratorCommon();
		}

		TEST_METHOD(End)
		{
			IteratorCommon();
		}

		TEST_METHOD(Size)
		{
			{
				XmlNodeSet nodes;
				Assert::AreEqual(static_cast<size_t>(0), nodes.size());
			}
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/file.dae"));
				const XmlNodeSet & nodes = doc.root().selectNodes("//collada:node");
				Assert::AreEqual(static_cast<size_t>(4), nodes.size());
			}
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/xml_node_set.dae"));
				const XmlNodeSet & init_froms = doc.root().selectNodes("//collada:image/collada:init_from");
				Assert::AreEqual(static_cast<size_t>(0), init_froms.size());
			}
		}

		TEST_METHOD(OperatorBracket)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));
			const XmlNodeSet & nodes = doc.root().selectNodes("//collada:asset/*");
			Assert::AreEqual(static_cast<size_t>(2), nodes.size());
			Assert::AreEqual("created", nodes[0].name().c_str());
			Assert::AreEqual("modified", nodes[1].name().c_str());
			Assert::IsFalse(nodes[INT_MAX]);
		}
	};
}