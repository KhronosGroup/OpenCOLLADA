#ifndef __GENERATEDSAXPARSER_COLLADAPARSER_H__
#define __GENERATEDSAXPARSER_COLLADAPARSER_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserParser.h"
#include "GeneratedSaxParserStackMemoryManager.h"
#include "GeneratedSaxParserColladaParserAutoGen.h"

namespace GeneratedSaxParser
{
	class ColladaParser : public ColladaParserAutoGen
	{

	private:
		size_t mCount;

	public:
		ColladaParser(IErrorHandler* errorHandler = 0);
		virtual ~ColladaParser();


	private:
		bool endTranslate();
		bool endNode();
		bool endCOLLADA();
		bool endLibraryNodes();

		bool beginTranslate(const TranslateAttributeData& attributeData );
		bool beginNode(const NodeAttributeData& attributeData );
		bool beginCOLLADA(const COLLADAAttributeData& attributeData );
		bool beginLibraryNodes(const LibraryNodesAttributeData& attributeData );

//		bool dataTranslate(const float* data, size_t length);
		bool dataTranslate(const int* data, size_t length);

	private:
        /** Disable default copy ctor. */
		ColladaParser( const ColladaParser& pre );
        /** Disable default assignment operator. */
		const ColladaParser& operator= ( const ColladaParser& pre );
	};

} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_COLLADAPARSER_H__
