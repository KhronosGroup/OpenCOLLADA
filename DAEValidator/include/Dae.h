#pragma once

#include "Xml.h"
#include "Uri.h"
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <vector>

namespace opencollada
{
	class Dae : public XmlDoc
	{
		using Super = XmlDoc;

	public:
		Dae() = default;
		Dae(Dae && other);
		const Dae & operator = (Dae && other);

		virtual void readFile(const std::string & path) override;

		const Uri & getURI() const { return mUri; }

		const auto & getExternalDAEs() const { return mExternalDAEs; }
		const auto & getAnyURIs() const { return mAnyURIs; }
		const auto & getIDREFs() const { return mIDREFs; }
		const std::set<std::string> & getIds() const;
		const std::vector<std::tuple<size_t, std::string>> & getLineIds() const;

	private:
		void readExternalFile(const std::string & path);
		void onAnyDAEURI(size_t line, const std::string & uri);
		void onAnyURI(size_t line, const std::string & uri);
		void initializeIdCache() const;

		Dae(const Dae&) = delete;
		const Dae& operator = (const Dae&) = delete;

	private:
		Uri mUri;
		std::map<Uri, Dae> mExternalDAEs;
		std::vector<std::tuple<size_t, Uri>> mAnyURIs;
		std::vector<std::tuple<size_t, std::string>> mIDREFs;
		mutable std::set<std::string> mIdCache;
		mutable std::vector<std::tuple<size_t, std::string>> mLineIdCache;
		mutable bool mIdCacheInitialized = false;
	};
}