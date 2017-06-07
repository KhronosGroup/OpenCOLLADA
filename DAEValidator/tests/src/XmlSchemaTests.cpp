#include "Common.h"
#include "XmlDoc.h"
#include "XmlSchema.h"

using namespace opencollada;
using namespace std;

namespace opencollada_test
{
	TEST_CLASS(XmlSchemaTest)
	{
	public:
		TEST_METHOD(DefaultConstructor)
		{
			XmlSchema schema;
			Assert::IsFalse(schema);
		}

		TEST_METHOD(MoveConstructor)
		{
			XmlSchema s1;
			s1.readFile(data_path("xml/COLLADAPhysX3Schema.xsd"));
			Assert::IsTrue(s1);

			XmlSchema s2 = move(s1);
			Assert::IsFalse(s1);
			Assert::IsTrue(s2);
		}

		TEST_METHOD(Destructor)
		{
			XmlSchema s;
			s.readFile(data_path("xml/COLLADAPhysX3Schema.xsd"));
			Assert::IsTrue(s);
		}

		TEST_METHOD(ReadFile)
		{
			{
				XmlSchema s;
				Assert::IsFalse(s);
				s.readFile(data_path("xml/COLLADAPhysX3Schema.xsd"));
				Assert::IsTrue(s);
			}
			{
				XmlSchema s;
				Assert::IsFalse(s);
				s.readFile(data_path("xml/unknown.xsd"));
				Assert::IsFalse(s);
			}
		}

		TEST_METHOD(Validate)
		{
			XmlSchema s;
			s.readFile(data_path("xml/COLLADAPhysX3Schema.xsd"));
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/file.dae"));
				Assert::IsTrue(s.validate(doc));
			}
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/schema_collada_error.dae"));
				Assert::IsFalse(s.validate(doc));
			}
			{
				XmlDoc doc;
				doc.readFile(data_path("xml/schema_other_error.dae"));
				Assert::IsFalse(s.validate(doc));
			}
		}

		TEST_METHOD(OperatorBool)
		{
			XmlSchema s1;
			Assert::IsFalse(s1);
			s1.readFile(data_path("xml/COLLADAPhysX3Schema.xsd"));
			Assert::IsTrue(s1);

			XmlSchema s2 = move(s1);
			Assert::IsFalse(s1);
			Assert::IsTrue(s2);
		}

		TEST_METHOD(GetUri)
		{
			XmlSchema s;
			Assert::AreEqual("", s.getURI().str().c_str());
			s.readFile(data_path("xml/COLLADAPhysX3Schema.xsd"));
			Assert::AreEqual("../../data/xml/COLLADAPhysX3Schema.xsd", s.getURI().str().c_str());
		}

		TEST_METHOD(FailedToLoad)
		{
			{
				XmlSchema s;
				Assert::IsFalse(s.failedToLoad());
				s.readFile(data_path("xml/COLLADAPhysX3Schema.xsd"));
				Assert::IsFalse(s.failedToLoad());
			}
			{
				XmlSchema s;
				Assert::IsFalse(s.failedToLoad());
				s.readFile(data_path("xml/unknown.xsd"));
				Assert::IsTrue(s.failedToLoad());
			}
		}
	};
}