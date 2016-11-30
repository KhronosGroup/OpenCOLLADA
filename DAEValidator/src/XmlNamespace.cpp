#include "XmlNamespace.h"

using namespace std;

namespace opencollada
{
	XmlNamespace::XmlNamespace(xmlNsPtr ns)
		: mNs(ns)
	{}

	XmlNamespace::operator bool() const
	{
		return mNs != nullptr;
	}

	string XmlNamespace::href() const
	{
		return reinterpret_cast<const XmlChar*>(mNs->href);
	}
}