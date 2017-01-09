#pragma once

#include <libxml/xmlschemas.h>
#include <string>

namespace opencollada
{
	class XmlSchema
	{
	public:
		XmlSchema() = default;
		XmlSchema(XmlSchema && other) = default;
		~XmlSchema();

		void readFile(const std::string & url);
		void readMemory(const char* xsd, size_t size);
		bool validate(const class XmlDoc & doc) const;

		operator bool() const;

		size_t nbErrors() const { return mNbErrors; }

	private:
		XmlSchema(const XmlSchema&) = delete;
		const XmlSchema& operator = (const XmlSchema & other) = delete;

		static void schemaValidityError(void *ctx, const char *msg, ...);

	private:
		xmlSchemaPtr mSchema = nullptr;
		size_t mNbErrors = 0;
	};
}