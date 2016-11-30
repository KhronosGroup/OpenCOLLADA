#include "XmlAttribute.h"

using namespace std;

namespace opencollada
{
	XmlAttribute::XmlAttribute(xmlAttrPtr attr)
		: mAttr(attr)
	{}

	XmlAttribute::operator bool() const
	{
		return mAttr != nullptr;
	}

	string XmlAttribute::name() const
	{
		return reinterpret_cast<const XmlChar*>(mAttr->name);
	}

	string XmlAttribute::value() const
	{
		return reinterpret_cast<const XmlChar*>(mAttr->children->content);
	}
}