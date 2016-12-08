#pragma once

#include <string>
#include "XmlNode.h"

namespace opencollada
{
	template<typename IteratorType>
	class XmlNodes
	{
	public:
		XmlNodes(const IteratorType & begin, const IteratorType & end)
			: mBegin(begin)
			, mEnd(end)
		{}

		IteratorType begin() const
		{
			return mBegin;
		}

		IteratorType end() const
		{
			return mEnd;
		}

		operator bool() const
		{
			return mBegin != mEnd;
		}

	private:
		IteratorType mBegin;
		IteratorType mEnd;
	};

	class XmlNodeIteratorByName
	{
	public:
		XmlNodeIteratorByName() = default;
		XmlNodeIteratorByName(const XmlNode & node, const std::string & name);

		const XmlNode & operator*() const;
		void operator++();
		bool operator != (const XmlNodeIteratorByName & other) const;

	private:
		XmlNode mNode;
		std::string mName;
	};
}