#pragma once

#include <libxml/parser.h>
#include <string>
#include "XmlCommon.h"

namespace opencollada
{
	class XmlNamespace
	{
		friend class XmlNode;
	public:
		XmlNamespace() = default;
		operator bool() const;

		std::string href() const;

	private:
		XmlNamespace(xmlNsPtr ns);

	private:
		xmlNsPtr mNs = nullptr;
	};
}