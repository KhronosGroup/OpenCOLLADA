#pragma once

#include "XmlNode.h"
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
		std::string getRootNamespace() const;

		class TempRootMod
		{
		public:
			TempRootMod(const XmlNode & old_root);
			TempRootMod(TempRootMod && other);
			~TempRootMod();

		private:
			TempRootMod(const TempRootMod&) = delete;
			const TempRootMod & operator = (const TempRootMod&) = delete;

		private:
			XmlNode mOldDocChildren;
			XmlNode mOldDocLast;
		};

		// Temporarily changes document's root node.
		// Original root is restored when TempRootMod object is destroyed.
		TempRootMod setTempRoot(const XmlNode & node) const;

	private:
		XmlDoc(const XmlDoc&) = delete;
		const XmlDoc& operator = (const XmlDoc & other) = delete;

		static XmlDoc & GetXmlDoc(xmlDocPtr doc);

	private:
		xmlDocPtr mDoc = nullptr;

		XPathCache mXPathCache;
	};
}