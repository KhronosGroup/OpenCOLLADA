#include "XmlSchema.h"
#include "XmlDoc.h"

#include <string>
using namespace std;

namespace opencollada
{
	XmlSchema::XmlSchema(XmlSchema && other)
	{
		swap(mSchema, other.mSchema);
	}

	XmlSchema::~XmlSchema()
	{
		if (mSchema)
		{
			xmlSchemaFree(mSchema);
			mSchema = nullptr;
		}
	}

	void XmlSchema::readFile(const string & url)
	{
		if (xmlSchemaParserCtxtPtr ctxt = xmlSchemaNewParserCtxt(url.c_str()))
		{
			mSchema = xmlSchemaParse(ctxt);
			xmlSchemaFreeParserCtxt(ctxt);
		}
	}

	void XmlSchema::readMemory(const char* xsd, size_t size)
	{
		if (xmlSchemaParserCtxtPtr ctxt = xmlSchemaNewMemParserCtxt(xsd, static_cast<int>(size)))
		{
			mSchema = xmlSchemaParse(ctxt);
			xmlSchemaFreeParserCtxt(ctxt);
		}
	}

	bool XmlSchema::validate(const XmlDoc & doc) const
	{
		int result = 1;
		if (xmlSchemaValidCtxtPtr ctxt = xmlSchemaNewValidCtxt(mSchema))
		{
			result = xmlSchemaValidateDoc(ctxt, doc.mDoc);
			xmlSchemaFreeValidCtxt(ctxt);
		}
		return result == 0;
	}

	XmlSchema::operator bool() const
	{
		return mSchema != nullptr;
	}
}