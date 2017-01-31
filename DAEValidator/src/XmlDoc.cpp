#include "XmlDoc.h"
#include "XmlNode.h"

using namespace std;

namespace opencollada
{
	XmlDoc::XmlDoc(XmlDoc && other)
	{
		swap(mDoc, other.mDoc);
	}

	XmlDoc::~XmlDoc()
	{
		if (mDoc)
		{
			xmlFreeDoc(mDoc);
			mDoc = nullptr;
		}
	}

	void XmlDoc::readFile(const string & path)
	{
		mDoc = xmlReadFile(path.c_str(), NULL, 0);
	}

	XmlDoc::operator bool() const
	{
		return mDoc != nullptr;
	}

	XmlNode XmlDoc::root() const
	{
		return xmlDocGetRootElement(mDoc);
	}

	XmlNode XmlDoc::setRoot(const XmlNode & node) const
	{
		return XmlNode(xmlDocSetRootElement(mDoc, node.mNode));
	}
}