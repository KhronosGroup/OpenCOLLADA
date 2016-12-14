#include "XmlNodes.h"

#include <string>

using namespace std;

namespace opencollada
{
	XmlNodeIteratorByName::XmlNodeIteratorByName(const XmlNode & node, const string & name)
		: mNode(node)
		, mName(name)
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