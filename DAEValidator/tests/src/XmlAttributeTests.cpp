#include "Common.h"
#include "Dae.h"
#include "XmlAttribute.h"

using namespace opencollada;
using namespace std;

namespace opencollada_test
{
	TEST_CLASS(XmlAttributeTest)
	{
	public:
		TEST_METHOD(Constructor)
		{
			XmlAttribute attr;
			Assert::IsFalse(attr);
		}

		TEST_METHOD(OperatorBool)
		{
			Dae dae;
			dae.readFile(data_path("xml/file.dae"));
			Assert::IsTrue(dae);

			auto root = dae.root();
			const auto & nodes = root.selectNodes("//collada:float_array[@id='float_array_0']");
			Assert::AreEqual(static_cast<size_t>(1), nodes.size());

			auto node = nodes[0];
			Assert::IsTrue(node);

			auto count = node.attribute("count");
			Assert::IsTrue(count);

			auto bad_attr = node.attribute("bad_attr");
			Assert::IsFalse(bad_attr);
		}

		TEST_METHOD(Name)
		{
			Dae dae;
			dae.readFile(data_path("xml/file.dae"));
			Assert::IsTrue(dae);

			auto root = dae.root();
			const auto & nodes = root.selectNodes("//collada:float_array[@id='float_array_0']");
			Assert::AreEqual(static_cast<size_t>(1), nodes.size());

			auto node = nodes[0];
			Assert::IsTrue(node);

			auto count = node.attribute("count");
			Assert::IsTrue(count);
			Assert::AreEqual(string("count"), count.name());

			auto bad_attr = node.attribute("bad_attr");
			Assert::IsFalse(bad_attr);
			Assert::AreEqual(string(), bad_attr.name());
		}

		TEST_METHOD(Value)
		{
			Dae dae;
			dae.readFile(data_path("xml/file.dae"));
			Assert::IsTrue(dae);

			auto root = dae.root();
			const auto & nodes = root.selectNodes("//collada:float_array[@id='float_array_0']");
			Assert::AreEqual(static_cast<size_t>(1), nodes.size());

			auto node = nodes[0];
			Assert::IsTrue(node);

			auto count = node.attribute("count");
			Assert::IsTrue(count);
			Assert::AreEqual(string("1"), count.value());

			auto bad_attr = node.attribute("bad_attr");
			Assert::IsFalse(bad_attr);
			Assert::AreEqual(string(), bad_attr.value());
		}
	};
}