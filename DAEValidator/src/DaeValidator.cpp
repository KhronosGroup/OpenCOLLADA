#include "DaeValidator.h"
#include "PathUtil.h"
#include "Strings.h"
#include "StringUtil.h"
#include <iostream>
#include <set>
#include <sstream>

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

	int DaeValidator::checkAll()
	{
		return for_each_dae([&](const Dae & dae) {
			return checkAll(dae);
		});
	}

	int DaeValidator::checkAll(const Dae & dae)
	{
		return
			checkSchema(dae) |
			checkUniqueIds(dae);
	}

	int DaeValidator::checkSchema(const string & schema_uri)
	{
		if (schema_uri.empty())
		{
			return for_each_dae([&](const Dae & dae) {
				return checkSchema(dae);
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

	struct SubDoc
	{
		XmlNode node;
		string xsdPath;
	};

	int DaeValidator::checkSchema(const Dae & dae)
	{
		int result = 0;

		// Get root <COLLADA> element
		auto collada = dae.root();
		if (!collada)
		{
			cerr << "Can't find document root" << endl;
			return 1;
		}

		if (collada.name() != Strings::COLLADA)
		{
			cerr << "Root element is not <" << Strings::COLLADA << ">" << endl;
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

		vector<SubDoc> subDocs;

		// Find xsi:schemaLocation attributes in dae and try to validate against specified xsd documents
		auto elements = dae.root().selectNodes("//*[@xsi:schemaLocation]");
		for (const auto & element : elements)
		{
			if (auto schemaLocation = element.attribute("schemaLocation"))
			{
				vector<string> parts = String::Split(schemaLocation.value());
				// Parse pairs of namespace/xsd
				for (size_t i = 1; i < parts.size(); i += 2)
				{
					const string & ns = parts[i - 1];
					const string & xsdUri = parts[i];

					if (ns != colladaNamespace141 && ns != colladaNamespace15)
					{
						SubDoc subDoc;
						if (element.ns().href() == colladaNamespace141 || element.ns().href() == colladaNamespace15)
							subDoc.node = element.firstChild();
						else
							subDoc.node = element;
						
						subDoc.xsdPath = xsdUri;
						subDocs.push_back(subDoc);

						// "insert" does nothing if element already exists.
						mSchemas.insert(pair<string, XmlSchema>(xsdUri, XmlSchema()));
					}
				}
			}
		}

		// Preload uninitialized .xsd files
		for (auto & p : mSchemas)
		{
			const auto & schemaUri = p.first;
			auto & schema = p.second;

			if (!schema)
			{
				schema.readFile(p.first);
				if (!schema)
				{
					Uri xsdUri(schemaUri);
					if (xsdUri.isValid())
					{
						// Try local file
						string localPath = Path::Join(Path::GetExecutableDirectory(), xsdUri.pathFile());
						schema.readFile(localPath);
						if (schema)
						{
							cout << "Using " << localPath << endl;
						}
					}

					if (!schema)
					{
						cerr << "Error loading " << schemaUri << endl;
						result |= 1;
					}
				}
			}
		}

		// Validate "sub documents"
		for (const auto & subDoc : subDocs)
		{
			auto it = mSchemas.find(subDoc.xsdPath);
			if (it != mSchemas.end() && it->second)
			{
				auto old = dae.setRoot(subDoc.node);
				result |= ValidateAgainstSchema(dae, it->second);
				dae.setRoot(old);
			}
			else
			{
				cerr << "Cannot validate " << dae.getURI() << " at line " << subDoc.node.line() << endl;
			}
		}

		return result;
	}

	int DaeValidator::checkUniqueIds()
	{
		return for_each_dae([&](const Dae & dae) {
			return checkUniqueIds(dae);
		});
	}

	int DaeValidator::checkUniqueIds(const Dae & dae)
	{
		int result = 0;
		XmlNodeSet nodes = dae.root().selectNodes("//*[@id]");
		set<IdLine> ids;
		for (const auto & node : nodes)
		{
			IdLine id_line(
				node.attribute(Strings::id).value(),
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
			Uri xsdUri(xsdPath);
			if (!xsdUri.isValid())
			{
				cerr << "Error loading " << xsdPath << endl;
				return 2;
			}
			// Try local file
			string localPath = Path::Join(Path::GetExecutableDirectory(), xsdUri.pathFile());
			xsd.readFile(localPath);
			if (!xsd)
			{
				cerr << "Error loading " << xsdPath << endl;
				return 2;
			}
			cout << "Using " << localPath << endl;
		}
		return ValidateAgainstSchema(dae, xsd);
	}

	int DaeValidator::ValidateAgainstSchema(const Dae & dae, const XmlSchema & schema)
	{
		return schema.validate(dae) ? 0 : 1;
	}
}
