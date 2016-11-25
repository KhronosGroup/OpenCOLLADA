#pragma once

#include <libxml/parser.h>
#include <string>
#include <functional>
#include "XmlCommon.h"

namespace opencollada
{
	template<typename T>
	class XmlNodes;

	class XmlNode
	{
		friend class XmlDoc;
		friend class XmlNodeSet;
	public:
		XmlNode() = default;
		operator bool() const;

		XmlNode child(const std::string & name) const;
		XmlNode firstChild() const;
		std::string text() const;
		std::string name() const;
		class XmlAttribute attribute(const std::string & name) const;
		class XmlNamespace ns() const;
		class XmlNodeSet selectNodes(const std::string & xpath) const;
		class XmlNodes<class XmlNodeIteratorByName> children(const std::string & name) const;
		XmlNode next(const std::string & name) const;
		size_t line() const;

		void for_each_attribute(const std::function<void(const class XmlAttribute &)> & fn) const;

	private:
		XmlNode(xmlNodePtr node);

	private:
		xmlNodePtr mNode = nullptr;
	};
}

bool operator == (const std::string & s, const unsigned char* c);
//bool operator != (const std::string & s, const unsigned char* c);