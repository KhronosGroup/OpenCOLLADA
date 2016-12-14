#include "XmlNodeSet.h"
#include "XmlNode.h"

namespace opencollada
{
	XmlNodeSet::XmlNodeSet(XmlNodeSet&& other)
	{
		std::swap(mXPathObject, other.mXPathObject);
	}

	XmlNodeSet::~XmlNodeSet()
	{
		if (mXPathObject)
		{
			xmlXPathFreeObject(mXPathObject);
			mXPathObject = nullptr;
		}
	}

	XmlNodeSet::XmlNodeSet(xmlXPathObjectPtr xpathObject)
		: mXPathObject(xpathObject)
	{}

	XmlNodeSet::operator bool() const
	{
		return mXPathObject != nullptr;
	}

	XmlNode XmlNodeSet::iterator::operator*() const
	{
		if (!mNodeSet)
			return XmlNode();
		return XmlNode(xmlXPathNodeSetItem(mNodeSet, mIndex));
	}

	void XmlNodeSet::iterator::operator++()
	{
		++mIndex;
		if (mIndex == mNodeSet->nodeNr)
		{
			mNodeSet = nullptr;
			mIndex = 0;
		}
	}

	bool XmlNodeSet::iterator::operator != (const iterator & other) const
	{
		return mNodeSet != other.mNodeSet || mIndex != other.mIndex;
	}

	XmlNodeSet::iterator::iterator(xmlNodeSetPtr nodeSet)
		: mNodeSet(nodeSet)
	{}

	XmlNodeSet::iterator XmlNodeSet::begin() const
	{
		if (!mXPathObject)
			return iterator();
		if (!mXPathObject->nodesetval)
			return iterator();
		if (mXPathObject->nodesetval->nodeNr == 0)
			return iterator();
		return iterator(mXPathObject->nodesetval);
	}

	XmlNodeSet::iterator XmlNodeSet::end() const
	{
		return iterator();
	}

	size_t XmlNodeSet::size() const
	{
		if (!mXPathObject)
			return 0;
		return xmlXPathNodeSetGetLength(mXPathObject->nodesetval);
	}

	XmlNode XmlNodeSet::operator[](int index) const
	{
		if (index >= static_cast<int>(size()))
			return XmlNode();

		return XmlNode(xmlXPathNodeSetItem(mXPathObject->nodesetval, index));
	}
}
