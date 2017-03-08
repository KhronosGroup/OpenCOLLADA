#pragma once

#include "XmlNodeSet.h"
#include <libxml/parser.h>
#include "no_warning_map"
#include "no_warning_string"

namespace opencollada
{
	class XmlNode;

	using XPathCacheKey = std::tuple<xmlNodePtr, std::string>;
	using XPathCache = std::map<XPathCacheKey, XmlNodeSet>;

	class XmlDoc
	{
		friend class XmlSchema;
		friend class XmlNode;

	public:
		XmlDoc() = default;
		XmlDoc(XmlDoc && other);
		virtual ~XmlDoc();

		const XmlDoc & operator = (XmlDoc && other);

		virtual void readFile(const std::string & path);

		operator bool() const;
		void reset();
		XmlNode root() const;
		XmlNode setRoot(const XmlNode & node) const;

	private:
		XmlDoc(const XmlDoc&) = delete;
		const XmlDoc& operator = (const XmlDoc & other) = delete;

		static XmlDoc & GetXmlDoc(xmlDocPtr doc);

	private:
		xmlDocPtr mDoc = nullptr;

		XPathCache mXPathCache;
	};
}