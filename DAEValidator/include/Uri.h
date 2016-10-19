#include <string>

// https://tools.ietf.org/html/rfc3986

namespace opencollada
{
	class Uri
	{
	public:
		Uri() = default;
		//Uri(Uri && uri);
		Uri(const std::string & uri);
		Uri(const Uri & baseUri, const Uri & uri);
		//const Uri & operator = (const Uri & uri);

		bool isValid() const;
		const std::string & str() const;
		const std::string & scheme() const;
		const std::string & authority() const;
		const std::string & path() const;
		const std::string & query() const;
		const std::string & fragment() const;

		void clear();
		void set(const std::string & uri);
		void set(const Uri & baseUri, const Uri & uri);

		static Uri FromNativePath(const std::string & path);
		static Uri Encode(const std::string & uri);
		static bool Parse(
			const std::string & uri,
			std::string & scheme,
			std::string & authority,
			std::string & path,
			std::string & query,
			std::string & fragment);

	private:
		static bool StartsWith(const std::string & str, const std::string & with);
		static std::string MergePaths(const Uri & baseUri, const std::string & ref_path);
		// TODO make in place version
		static std::string RemoveDotSegments(const std::string & path);

	private:
		std::string mUri;
		std::string mScheme;
		std::string mAuthority;
		std::string mPath;
		std::string mQuery;
		std::string mFragment;
		bool mValid = false;
	};
}