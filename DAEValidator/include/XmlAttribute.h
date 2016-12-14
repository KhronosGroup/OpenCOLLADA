#pragma once

#include <libxml/parser.h>
#include <string>
#include "XmlCommon.h"

namespace opencollada
{
	class XmlAttribute
	{
		friend class XmlNode;
	public:
		XmlAttribute() = default;
		operator bool() const;

		std::string name() const;
		std::string value() const;

	private:
		XmlAttribute(xmlAttrPtr attr);

	private:
		xmlAttrPtr mAttr = nullptr;
	};
}