#include "DaeValidator.h"
#include "COLLADASWConstants.h"
#include <iostream>
#include <set>

using namespace COLLADASW;
using namespace std;

namespace opencollada
{
	const char* colladaNamespace141 = "http://www.collada.org/2005/11/COLLADASchema";
	extern unsigned char collada_schema_1_4_1_xsd[];
	extern size_t collada_schema_1_4_1_xsd_size;

	const char* colladaNamespace15 = "http://www.collada.org/2008/03/COLLADASchema";
	extern unsigned char collada_schema_1_5_xsd[];
	extern size_t collada_schema_1_5_xsd_size;

	DaeValidator::DaeValidator(const Dae & dae)
		: mDae(dae)
	{}

	int DaeValidator::checkAll() const
	{
		int result = 0;
		result |= checkSchema();
		result |= checkUniqueIds();
		return result;
	}

	// Split string by whitespace
	vector<string> Split(const string & s)
	{
		vector<string> parts;
		istringstream iss(s);
		while (iss && !iss.eof())
		{
			string sub;
			iss >> sub;
			parts.emplace_back(sub);
		}
		return parts;
	}

	int DaeValidator::checkSchema() const
	{
		// Get root <COLLADA> element
		auto collada = mDae.root();
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
		int result = 0;
		auto href = xmlns.href();
		if (href == colladaNamespace141)
		{
			result |= validateAgainstMemory(reinterpret_cast<const char*>(collada_schema_1_4_1_xsd), collada_schema_1_4_1_xsd_size);
		}
		else if (href == colladaNamespace15)
		{
			result |= validateAgainstMemory(reinterpret_cast<const char*>(collada_schema_1_5_xsd), collada_schema_1_5_xsd_size);
		}
		else
		{
			cerr << "Can't determine COLLADA version used by input file" << endl;
			return 1;
		}

		set<string> xsdURLs;

		// Find xsi:schemaLocation attributes in dae and try to validate against specified xsd documents
		auto elements = mDae.root().selectNodes("//*[@xsi:schemaLocation]");
		for (const auto & element : elements)
		{
			if (auto schemaLocation = element.attribute("schemaLocation"))
			{
				vector<string> parts = Split(schemaLocation.value());
				// Parse pairs of namespace/xsd and take second element
				for (size_t i = 1; i < parts.size(); i += 2)
				{
					xsdURLs.insert(parts[i]);
				}
			}
		}

		for (const auto & URL : xsdURLs)
		{
			int tmpResult = validateAgainstFile(URL);
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

	int DaeValidator::checkUniqueIds() const
	{
		int result = 0;
		XmlNodeSet nodes = mDae.root().selectNodes("//*[@id]");
		set<string> ids;
		for (const auto & node : nodes)
		{
			string id = node.attribute(CSWC::CSW_ATTRIBUTE_ID).value();
			if (ids.find(id) != ids.end())
			{
				cerr << "Duplicated id: " << id << endl;
				result |= 1;
			}
			else
			{
				ids.insert(id);
			}
		}
		return result;
	}

	int DaeValidator::validateAgainstMemory(const char* p, size_t size) const
	{
		// Open xsd
		cout << "Validating against COLLADA schema" << endl;
		XmlSchema xsd;
		xsd.readMemory(p, size);
		if (!xsd)
		{
			cerr << "Error loading COLLADA schema" << endl;
			return 1;
		}

		// Validate dae against xsd
		if (!xsd.validate(mDae))
		{
			cerr << "DAE is not valid" << endl;
			return 1;
		}

		return 0;
	}

	int DaeValidator::validateAgainstFile(const string & xsdPath) const
	{
		// Open xsd
		cout << "Validating against " << xsdPath << endl;
		XmlSchema xsd;
		xsd.readFile(xsdPath.c_str());
		if (!xsd)
		{
			cerr << "Error loading " << xsdPath << endl;
			return 2;
		}

		// Validate dae against xsd
		if (!xsd.validate(mDae))
		{
			cerr << "DAE is not valid" << endl;
			return 1;
		}

		return 0;
	}
}