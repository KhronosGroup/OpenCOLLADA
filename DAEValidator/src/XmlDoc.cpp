#include "XmlDoc.h"
#include "XmlNode.h"

#include <fstream>
#include "no_warning_vector"
#include <sys/stat.h>

using namespace std;

#include "zlib.h"

namespace opencollada
{
	XmlDoc::XmlDoc(XmlDoc && other)
	{
		*this = move(other);
	}

	XmlDoc::~XmlDoc()
	{
		reset();
	}

	const XmlDoc & XmlDoc::operator = (XmlDoc && other)
	{
		swap(mDoc, other.mDoc);
		return *this;
	}

	void XmlDoc::readFile(const string & path)
	{
		reset();

		ifstream ifile(path, ios_base::binary);

		if (!ifile.is_open()) return;
		
		struct stat st;
		int r = stat(path.c_str(), &st);
		auto size = r == 0 ? st.st_size : 0;

		if (size <= 4) return;

		vector<char> content(static_cast<size_t>(size));
		ifile.read(content.data(), size);

#if defined(_MSC_VER) && _MSC_VER < 1900
		typedef unsigned int uint32_t;
#endif
		uint32_t signature = *reinterpret_cast<const uint32_t*>(content.data());

		// Uncompressed document
		// 1f8b08
		if ((signature & 0x00FFFFFF) != 0x00088b1f)
		{
			mDoc = xmlReadMemory(content.data(), size, path.c_str(), NULL, 0);
		}
		// Compressed document (gzip only)
		else
		{
			vector<char> decompressed_content(*reinterpret_cast<const uint32_t*>(content.data() + content.size() - 4));
			z_stream zInfo {};
			zInfo.total_in = zInfo.avail_in = static_cast<uInt>(content.size());
			zInfo.total_out = zInfo.avail_out = static_cast<uInt>(decompressed_content.size());
			zInfo.next_in = reinterpret_cast<Bytef*>(content.data());
			zInfo.next_out = reinterpret_cast<Bytef*>(decompressed_content.data());

			int nErr = inflateInit2(&zInfo, 16 + MAX_WBITS);
			if (nErr == Z_OK)
			{
				nErr = inflate(&zInfo, Z_FINISH);
			}
			inflateEnd(&zInfo);

			if (nErr == Z_STREAM_END)
				mDoc = xmlReadMemory(decompressed_content.data(), static_cast<int>(decompressed_content.size()), path.c_str(), NULL, 0);
		}

		if (mDoc)
			mDoc->_private = this;
	}

	XmlDoc::operator bool() const
	{
		return mDoc != nullptr;
	}

	void XmlDoc::reset()
	{
		mXPathCache.clear();

		if (mDoc)
		{
			xmlFreeDoc(mDoc);
			mDoc = nullptr;
		}
	}

	XmlNode XmlDoc::root() const
	{
		return xmlDocGetRootElement(mDoc);
	}

	XmlNode XmlDoc::setRoot(const XmlNode & node) const
	{
		return XmlNode(xmlDocSetRootElement(mDoc, node.mNode));
	}

	XmlDoc & XmlDoc::GetXmlDoc(xmlDocPtr doc)
	{
		return *static_cast<XmlDoc*>(doc->_private);
	}
}
