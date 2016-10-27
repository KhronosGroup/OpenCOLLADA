#pragma once

#include "Dae.h"

#include <functional>
#include <list>
#include <string>

namespace opencollada
{
	class DaeValidator
	{
	public:
		DaeValidator(const std::list<std::string> & daePaths);

		int checkAll() const;
		int checkSchema(const std::string & schema_uri = std::string()) const;
		int checkUniqueIds() const;

	private:
		static int CheckAll(const Dae & dae);
		static int CheckSchema(const Dae & dae);
		static int CheckUniqueIds(const Dae & dae);

		int for_each_dae(const std::function<int(const Dae &)> & task) const;
		static int ValidateAgainstFile(const Dae & dae, const std::string & xsdPath);
		static int ValidateAgainstSchema(const Dae & dae, const XmlSchema & schema);

	private:
		std::vector<std::string> mDaePaths;
	};
}