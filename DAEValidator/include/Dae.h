#pragma once

#include "Xml.h"
#include "Uri.h"
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

		const Uri & getURI() const;

	private:
		void readExternalFile(const std::string & path);
		void onAnyDAEURI(const std::string & uri);

		Dae(const Dae&) = delete;
		const Dae& operator = (const Dae&) = delete;

	private:
		Uri mUri;
		std::set<Uri> mExternalDAEURIs;
		std::vector<Dae> mExternalDAEs;
	};
}