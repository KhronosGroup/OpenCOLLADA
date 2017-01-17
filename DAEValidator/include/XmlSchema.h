#pragma once

#include <libxml/xmlschemas.h>
#include <string>

namespace opencollada
{
	class XmlSchema
	{
	public:
		XmlSchema() = default;
		// Move constructor can not be defaulted with vs2012
		XmlSchema(XmlSchema && other);
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