#include "Macros.h"

#if IS_GNUC_AND_GNUC_VERSION_LT(5,1,1)
#include <cstring>
#endif

#include "XmlDoc.h"
#include "XmlNode.h"
#include "XmlNamespace.h"

#include "no_warning_fstream"
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
		auto size = 0;
		if (r == 0)
			size = st.st_size;

		if (size <= 4) return;

		vector<char> content(static_cast<size_t>(size));
		ifile.read(content.data(), size);

#if IS_MSVC_AND_MSVC_VERSION_LT(1900)
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
#if IS_GNUC_AND_GNUC_VERSION_LT(5,1,1)
			z_stream zInfo;
			memset(&zInfo, 0, sizeof(zInfo));
#else
			z_stream zInfo {};
#endif
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

	string XmlDoc::getRootNamespace() const
	{
		if (auto r = root())
			if (auto n = r.ns())
				return n.href();
		return "";
	}

	XmlDoc::TempRootMod XmlDoc::setTempRoot(const XmlNode & node) const
	{
		TempRootMod trm(mDoc->children);
		mDoc->children = node.mNode;
		mDoc->last = mDoc->children;
		return trm;
	}

	XmlDoc::TempRootMod::TempRootMod(const XmlNode & old_root)
		: mOldDocChildren(old_root.mNode->doc->children)
		, mOldDocLast(old_root.mNode->doc->last)
	{}

	XmlDoc::TempRootMod::TempRootMod(TempRootMod && other)
	{
		swap(mOldDocChildren, other.mOldDocChildren);
		swap(mOldDocLast, other.mOldDocLast);
	}

	XmlDoc::TempRootMod::~TempRootMod()
	{
		// Restore old root
		if (mOldDocChildren)
		{
			const XmlDoc & doc = mOldDocChildren.doc();
			doc.mDoc->children = mOldDocChildren.mNode;
			doc.mDoc->last = mOldDocLast.mNode;
		}
	}

	XmlDoc & XmlDoc::GetXmlDoc(xmlDocPtr doc)
	{
		return *static_cast<XmlDoc*>(doc->_private);
	}
}
