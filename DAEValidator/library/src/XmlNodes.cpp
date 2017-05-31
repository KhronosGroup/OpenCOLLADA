#include "XmlNodes.h"

#include "no_warning_string"

using namespace std;

namespace opencollada
{
	XmlNodeIteratorByName::XmlNodeIteratorByName(const XmlNode & node)
		: mNode(node)
		, mName(node ? node.name() : string())
	{}

	const XmlNode & XmlNodeIteratorByName::operator*() const
	{
		return mNode;
	}

	void XmlNodeIteratorByName::operator++()
	{
		mNode = mNode.next(mName.c_str());
	}

	bool XmlNodeIteratorByName::operator != (const XmlNodeIteratorByName & other) const
	{
		return mNode != other.mNode;
	}
}