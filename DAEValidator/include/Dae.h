#pragma once

#include "COLLADABUURI.h"
#include "Xml.h"
#include <set>
#include <string>
#include <vector>

namespace opencollada
{
	class Dae : public XmlDoc
	{
		using Super = XmlDoc;

	public:
		Dae() = default;
		Dae(Dae && other);

		virtual void readFile(const std::string & path) override;

		const COLLADABU::URI & getURI() const;

	private:
		void readExternalFile(const std::string & path);
		void onAnyDAEURI(const std::string & uri);

	private:
		COLLADABU::URI mUri;
		std::set<COLLADABU::URI> mExternalDAEURIs;
		std::vector<Dae> mExternalDAEs;
	};
}