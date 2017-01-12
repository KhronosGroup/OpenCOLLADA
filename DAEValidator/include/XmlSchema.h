#pragma once

#include <libxml/xmlschemas.h>
#include <string>
#include "Uri.h"

namespace opencollada
{
	class XmlSchema
	{
	public:
		XmlSchema() = default;
		XmlSchema(XmlSchema && other) = default;
		~XmlSchema();

		void readFile(const std::string & url);
		bool validate(const class XmlDoc & doc) const;

		operator bool() const;

		const Uri & getURI() const { return mUri; }
		bool failedToLoad() const;

	private:
		XmlSchema(const XmlSchema&) = delete;
		const XmlSchema& operator = (const XmlSchema & other) = delete;

	private:
		xmlSchemaPtr mSchema = nullptr;
		Uri mUri;
	};
}