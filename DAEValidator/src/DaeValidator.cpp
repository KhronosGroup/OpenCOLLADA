#include "DaeValidator.h"
#include "COLLADASWConstants.h"
#include "PathUtil.h"
#include "StringUtil.h"
#include <iostream>
#include <set>

using namespace COLLADASW;
using namespace std;

namespace opencollada
{
	class IdLine
	{
	public:
		IdLine(const string & id, size_t line)
			: mId(id)
			, mLine(line)
		{}

		bool operator < (const IdLine & other) const
		{
			return mId < other.mId;
		}

		const string & getId() const
		{
			return mId;
		}

		size_t getLine() const
		{
			return mLine;
		}

	private:
		string mId;
		size_t mLine = string::npos;
	};
}

namespace std
{
	template<>
	struct less<opencollada::IdLine>
	{
		bool operator () (const opencollada::IdLine& a, const opencollada::IdLine& b) const
		{
			return a < b;
		}
	};
}

namespace opencollada
{
	extern const char* colladaNamespace141;
	extern const char* colladaSchemaFileName141;
	extern XmlSchema colladaSchema141;

	extern const char* colladaNamespace15;
	extern const char* colladaSchemaFileName15;
	extern XmlSchema colladaSchema15;

	DaeValidator::DaeValidator(const list<string> & daePaths)
	{
		mDaePaths.reserve(daePaths.size());
		mDaePaths.insert(mDaePaths.end(), daePaths.begin(), daePaths.end());
	}

	int DaeValidator::for_each_dae(const function<int(const Dae &)> & task) const
	{
		int result = 0;
		for (const auto & daePath : mDaePaths)
		{
			Dae dae;
			dae.readFile(daePath);
			if (dae)
			{
				result |= task(dae);
			}
			else
			{
				result |= 1;
				cerr << "Error loading " << daePath << endl;
			}
		}
		return result;
	}

	int DaeValidator::checkAll() const
	{
		return for_each_dae([&](const Dae & dae) {
			return CheckAll(dae);
		});
	}

	int DaeValidator::CheckAll(const Dae & dae)
	{
		return
			CheckSchema(dae) |
			CheckUniqueIds(dae);
	}

	int DaeValidator::checkSchema(const string & schema_uri) const
	{
		if (schema_uri.empty())
		{
			return for_each_dae([&](const Dae & dae) {
				return CheckSchema(dae);
			});
		}

		XmlSchema schema;
		schema.readFile(schema_uri);
		if (schema)
		{
			return for_each_dae([&](const Dae & dae) {
				return ValidateAgainstSchema(dae, schema);
			});
		}

		cerr << "Error loading " << schema_uri << endl;
		return 1;
	}

	int DaeValidator::CheckSchema(const Dae & dae)
	{
		int result = 0;

		// Get root <COLLADA> element
		auto collada = dae.root();
		if (!collada)
		{
			cerr << "Can't find document root" << endl;
			return 1;
		}

		if (collada.name() != "COLLADA")
		{
			cerr << "Root element is not <COLLADA>" << endl;
			return 1;
		}

		// Get COLLADA namespace
		auto xmlns = collada.ns();
		if (!xmlns)
		{
			cerr << "COLLADA element has no namespace" << endl;
			return 1;
		}

		// Determine COLLADA version used by input dae file
		auto href = xmlns.href();
		if (href == colladaNamespace141)
		{
			result |= ValidateAgainstSchema(dae, colladaSchema141);
		}
		else if (href == colladaNamespace15)
		{
			result |= ValidateAgainstSchema(dae, colladaSchema15);
		}
		else
		{
			cerr << "Can't determine COLLADA version used by input file" << endl;
			return 1;
		}

		set<string> xsdURLs;

		// Find xsi:schemaLocation attributes in dae and try to validate against specified xsd documents
		auto elements = dae.root().selectNodes("//*[@xsi:schemaLocation]");
		for (const auto & element : elements)
		{
			if (auto schemaLocation = element.attribute("schemaLocation"))
			{
				vector<string> parts = String::Split(schemaLocation.value());
				// Parse pairs of namespace/xsd and take second element
				for (size_t i = 1; i < parts.size(); i += 2)
				{
					xsdURLs.insert(parts[i]);
				}
			}
		}

		for (const auto & URL : xsdURLs)
		{
			int tmpResult = ValidateAgainstFile(dae, URL);
			if (tmpResult == 2)
			{
				std::cout
					<< "Warning: can't load \"" << URL << "\"." << endl
					<< "Some parts of the document will not be validated." << endl;
			}
			else
			{
				result |= tmpResult;
			}
		}

		return result;
	}

	ostream & operator << (ostream & o, const COLLADABU::URI & uri)
	{
		o << uri.getURIString();
		return o;
	}

	int DaeValidator::checkUniqueIds() const
	{
		return for_each_dae([&](const Dae & dae) {
			return CheckUniqueIds(dae);
		});
	}

	int DaeValidator::CheckUniqueIds(const Dae & dae)
	{
		int result = 0;
		XmlNodeSet nodes = dae.root().selectNodes("//*[@id]");
		set<IdLine> ids;
		for (const auto & node : nodes)
		{
			IdLine id_line(
				node.attribute(CSWC::CSW_ATTRIBUTE_ID).value(),
				node.line()
			);
			auto it = ids.find(id_line);
			if (it != ids.end())
			{
				cerr << dae.getURI() << ":" << node.line() << ": Duplicated id \"" << id_line.getId() << "\". See first declaration at line " << it->getLine() << "." << endl;
				result |= 1;
			}
			else
			{
				ids.insert(id_line);
			}
		}
		return result;
	}

	int DaeValidator::ValidateAgainstFile(const Dae & dae, const string & xsdPath)
	{
		// Open xsd
		XmlSchema xsd;
		xsd.readFile(xsdPath.c_str());
		if (!xsd)
		{
			cerr << "Error loading " << xsdPath << endl;
			return 2;
		}
		return ValidateAgainstSchema(dae, xsd);
	}

	int DaeValidator::ValidateAgainstSchema(const Dae & dae, const XmlSchema & schema)
	{
		return schema.validate(dae) ? 0 : 1;
	}
}
