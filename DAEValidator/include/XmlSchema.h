#pragma once

#include <libxml/xmlschemas.h>
#include <string>

namespace opencollada
{
	class XmlSchema
	{
	public:
		XmlSchema() = default;
		~XmlSchema();

		void readFile(const std::string & url);
		void readMemory(const char* xsd, size_t size);
		bool validate(const class XmlDoc & doc) const;

		operator bool() const;

	private:
		XmlSchema(const XmlSchema&) = delete;
		const XmlSchema& operator = (const XmlSchema & other) = delete;

	private:
		xmlSchemaPtr mSchema = nullptr;
	};
}