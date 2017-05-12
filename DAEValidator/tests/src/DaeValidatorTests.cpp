#include "Common.h"
#include "DaeValidator.h"
#include "PathUtil.h"

using namespace opencollada;
using namespace std;

namespace opencollada_test
{
	TEST_CLASS(DaeValidatorTest)
	{
	public:
		TEST_METHOD(Constructor)
		{
			list<string> daes{Path::GetAbsolutePath(data_path("daevalidator/file.dae"))};
			DaeValidator v(daes);
			Assert::AreEqual(0, v.checkAll());
		}

		TEST_METHOD(CheckAll)
		{
			list<string> daes{ Path::GetAbsolutePath(data_path("daevalidator/file.dae")) };
			DaeValidator v(daes);
			Assert::AreEqual(0, v.checkAll());
		}

		TEST_METHOD(CheckSchema)
		{
			{
				list<string> daes{ Path::GetAbsolutePath(data_path("daevalidator/schema_ok.dae")) };
				DaeValidator v(daes);
				Assert::AreEqual(0, v.checkSchema());
			}
			{
				list<string> daes{ Path::GetAbsolutePath(data_path("daevalidator/schema_error.dae")) };
				DaeValidator v(daes);
				Assert::AreNotEqual(0, v.checkSchema());
			}
			{
				list<string> daes{ Path::GetAbsolutePath(data_path("daevalidator/schema_ok.dae")) };
				DaeValidator v(daes);
				Assert::AreEqual(1, v.checkSchema(data_path("daevalidator/bad.xsd")));
			}
			{
				list<string> daes{ Path::GetAbsolutePath(data_path("daevalidator/collada_1.5.dae")) };
				DaeValidator v(daes);
				Assert::AreEqual(1, v.checkSchema());
			}
			{
				list<string> daes{ Path::GetAbsolutePath(data_path("daevalidator/collada_no_version.dae")) };
				DaeValidator v(daes);
				Assert::AreEqual(1, v.checkSchema());
			}
			{
				list<string> daes{ Path::GetAbsolutePath(data_path("daevalidator/check_schema.dae")) };
				DaeValidator v(daes);
				Assert::AreEqual(0, v.checkSchema());
			}
			{
				list<string> daes{ Path::GetAbsolutePath(data_path("daevalidator/check_missing_schema.dae")) };
				DaeValidator v(daes);
				Assert::AreEqual(1, v.checkSchema());
				Assert::AreEqual(1, v.checkSchema());
			}
		}

		TEST_METHOD(CheckUniqueIds)
		{
			{
				list<string> daes{ Path::GetAbsolutePath(data_path("daevalidator/unique_ids_ok.dae")) };
				DaeValidator v(daes);
				Assert::AreEqual(0, v.checkUniqueIds());
			}
			{
				list<string> daes{ Path::GetAbsolutePath(data_path("daevalidator/unique_ids_error.dae")) };
				DaeValidator v(daes);
				Assert::AreNotEqual(0, v.checkUniqueIds());
			}
		}

		TEST_METHOD(CheckUniqueSids)
		{
			{
				list<string> daes{ Path::GetAbsolutePath(data_path("daevalidator/unique_sids_ok.dae")) };
				DaeValidator v(daes);
				Assert::AreEqual(0, v.checkUniqueSids());
			}
			{
				list<string> daes{ Path::GetAbsolutePath(data_path("daevalidator/unique_sids_error.dae")) };
				DaeValidator v(daes);
				Assert::AreNotEqual(0, v.checkUniqueSids());
			}
		}

		TEST_METHOD(CheckLinks)
		{
			{
				list<string> daes{ Path::GetAbsolutePath(data_path("daevalidator/links_ok.dae")) };
				DaeValidator v(daes);
				Assert::AreEqual(0, v.checkLinks());
			}
			{
				list<string> daes{ Path::GetAbsolutePath(data_path("daevalidator/links_error.dae")) };
				DaeValidator v(daes);
				Assert::AreNotEqual(0, v.checkLinks());
			}
		}
	};
}