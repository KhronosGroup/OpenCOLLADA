#include "Common.h"
#include  "XmlDoc.h"
#include "XmlNamespace.h"

using namespace opencollada;
using namespace std;

namespace opencollada_test
{
	TEST_CLASS(XmlNamespaceTest)
	{
	public:
		TEST_METHOD(Constructor)
		{
			XmlNamespace ns;
			Assert::IsFalse(ns);
		}

		TEST_METHOD(OperatorBool)
		{
			{
				XmlNamespace ns;
				Assert::IsFalse(ns);
			}
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/file.dae"));
				auto ns = doc.root().ns();
				Assert::IsTrue(ns);
				Assert::AreEqual("http://www.collada.org/2005/11/COLLADASchema", ns.href().c_str());
			}
		}

		TEST_METHOD(Href)
		{
			{
				XmlNamespace ns;
				Assert::IsFalse(ns);
				Assert::AreEqual("", ns.href().c_str());
			}
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/file.dae"));
				auto ns = doc.root().ns();
				Assert::IsTrue(ns);
				Assert::AreEqual("http://www.collada.org/2005/11/COLLADASchema", ns.href().c_str());
			}
		}
	};
}