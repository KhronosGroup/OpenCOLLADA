#pragma once

#include <libxml/parser.h>
#include <string>

namespace opencollada
{
	class XmlNode;

	class XmlDoc
	{
		friend class XmlSchema;
	public:
		XmlDoc() = default;
		XmlDoc(XmlDoc && other);
		virtual ~XmlDoc();

		virtual void readFile(const std::string & path);

		operator bool() const;

		XmlNode root() const;

		XmlNode setRoot(const XmlNode & node) const;

	private:
		XmlDoc(const XmlDoc&) = delete;
		const XmlDoc& operator = (const XmlDoc & other) = delete;

	private:
		xmlDocPtr mDoc = nullptr;
	};
}