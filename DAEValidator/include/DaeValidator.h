#pragma once

#include "Dae.h"

#include <functional>
#include <list>
#include <map>
#include <string>

namespace opencollada
{
	class DaeValidator
	{
	public:
		DaeValidator(const std::list<std::string> & daePaths);

		int checkAll();
		int checkSchema(const std::string & schema_uri = std::string());
		int checkUniqueIds();

	private:
		int checkSchema(const Dae & dae);
		int checkAll(const Dae & dae);
		int checkUniqueIds(const Dae & dae);

		int for_each_dae(const std::function<int(const Dae &)> & task) const;
		static int ValidateAgainstFile(const Dae & dae, const std::string & xsdPath);
		static int ValidateAgainstSchema(const Dae & dae, const XmlSchema & schema);

	private:
		std::vector<std::string> mDaePaths;
		// namespace to XmlSchema
		std::map<std::string, XmlSchema> mSchemas;
	};
}