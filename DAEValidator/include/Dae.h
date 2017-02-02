#pragma once

#include "Xml.h"
#include "Uri.h"
#include "no_warning_map"
#include <set>
#include "no_warning_string"
#include <tuple>
#include "no_warning_vector"

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

		const std::map<Uri, Dae> & getExternalDAEs() const { return mExternalDAEs; }
		const std::vector<std::tuple<size_t, Uri>> & getAnyURIs() const { return mAnyURIs; }
		const std::vector<std::tuple<size_t, std::string>> & getIDREFs() const { return mIDREFs; }
		const std::set<std::string> & getIds() const;

	private:
		void readExternalFile(const std::string & path);
		void onAnyDAEURI(size_t line, const std::string & uri);
		void onAnyURI(size_t line, const std::string & uri);
		void initializeCache() const;

		Dae(const Dae&) = delete;
		const Dae& operator = (const Dae&) = delete;

	private:
		Uri mUri;
		std::map<Uri, Dae> mExternalDAEs;
		std::vector<std::tuple<size_t, Uri>> mAnyURIs;
		std::vector<std::tuple<size_t, std::string>> mIDREFs;

		mutable std::set<std::string> mIdCache;
		mutable bool mCacheInitialized = false;
	};
}