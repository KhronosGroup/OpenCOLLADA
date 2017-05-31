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
		if (mAttr)
			return reinterpret_cast<const XmlChar*>(mAttr->name);
		return string();
	}

	string XmlAttribute::value() const
	{
		if (mAttr)
			return reinterpret_cast<const XmlChar*>(mAttr->children->content);
		return string();
	}
}