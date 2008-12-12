#ifndef __GENERATEDSAXPARSER_COLLADAPARSER_AUTOGEN_H__
#define __GENERATEDSAXPARSER_COLLADAPARSER_AUTOGEN_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserTypes.h"
#include "GeneratedSaxParserParserTemplate.h"



namespace GeneratedSaxParser
{
	class ColladaParserAutoGen : public ParserTemplate<ColladaParserAutoGen>
	{
	public:

		static const char* PARENT_CHILD_ELEMENT_SEPARATOR;

	public:

		static const StringHash HASH_ELEMENT_COLLADA = 138479041;
		static const StringHash HASH_ELEMENT_LIBRARY_NODES = 230609443;
		static const StringHash HASH_ELEMENT_VISUAL_SCENE = 129577413;
		static const StringHash HASH_ELEMENT_NODE = 480677;
		static const StringHash HASH_ELEMENT_TRANSLATE = 140137253;

		static const StringHash HASH_ATTRIBUTE_XMLNS = 8340307;
		static const StringHash HASH_ATTRIBUTE_VERSION = 214540334;
		static const StringHash HASH_ATTRIBUTE_NUMBER = 123484354;
		static const StringHash HASH_ATTRIBUTE_NUMBER2 = 96701474;
		static const StringHash HASH_ATTRIBUTE_TYPE = 508005;

		static const StringHash HASH_TYPE_NODE = 340869;
		static const StringHash HASH_TYPE_JOINT = 5193268;


		static const char* NAME_ELEMENT_COLLADA;
		static const char* NAME_ELEMENT_LIBRARY_NODES;
		static const char* NAME_ELEMENT_VISUAL_SCENE;
		static const char* NAME_ELEMENT_NODE;
		static const char* NAME_ELEMENT_TRANSLATE;

		static const char* NAME_ATTRIBUTE_XMLNS;
		static const char* NAME_ATTRIBUTE_VERSION;
		static const char* NAME_ATTRIBUTE_NUMBER;
		static const char* NAME_ATTRIBUTE_NUMBER2;
		static const char* NAME_ATTRIBUTE_TYPE;

		static const char* NAME_TYPE_NODE;
		static const char* NAME_TYPE_JOINT;



		struct TranslateAttributeData
		{	
			static const TranslateAttributeData DEFAULT;
		};

		struct TranslateValidationData
		{
			static const TranslateValidationData DEFAULT;
		};

		struct NodeAttributeData
		{	
			static const NodeAttributeData DEFAULT;
		};

		struct NodeValidationData
		{
			static const NodeValidationData DEFAULT;
			int choice1Count;
		};


		struct COLLADAAttributeData
		{	
			enum Number2Enum
			{
				NUMBER2_2 = 0,
				NUMBER2_4,
				NUMBER2_6,
				NUMBER2_9,
				NUMBER2_COUNT
			};
			enum TypeEnum
			{
				TYPE_NODE = 0,
				TYPE_JOINT,
				TYPE_COUNT
			};

			typedef std::pair<unsigned long, Number2Enum>  Number2EnumPair;
			typedef std::pair<StringHash, TypeEnum>  TypeEnumPair;

			static const Number2EnumPair NUMBER2_ENUM_MAP[NUMBER2_COUNT];
			static const TypeEnumPair TYPE_ENUM_MAP[TYPE_COUNT];
			
			static const COLLADAAttributeData DEFAULT;
			
			const ParserChar* xmlns;
			const ParserChar* version;	
			unsigned long number;
			Number2Enum number2;
			TypeEnum type;

		};

		struct COLLADAValidationData
		{
			static const COLLADAValidationData DEFAULT;
			enum Flags
			{
				NONE         = 0,
				HAS_XMLNS    = 1<<0,
				HAS_VERSION  = 1<<1,
			};
			int flags;
		};

		struct LibraryNodesAttributeData
		{
			static const LibraryNodesAttributeData DEFAULT;
		};

		struct LibraryNodesValidationData
		{
			static const LibraryNodesValidationData DEFAULT;
		};


	public:
		ColladaParserAutoGen(IErrorHandler* errorHandler);
		virtual ~ColladaParserAutoGen();


	private:
		bool validateBeginTranslate(const ParserAttributes& attributes, void ** attributeDataPtr,  void ** validationDataPtr  );
		bool validateBeginNode(const ParserAttributes& attributes, void ** attributeDataPtr,  void ** validationDataPtr  );
		bool validateBeginCOLLADA(const ParserAttributes& attributes, void ** attributeDataPtr,  void ** validationDataPtr  );
		bool validateBeginLibraryNodes(const ParserAttributes& attributes, void ** attributeDataPtr,  void ** validationDataPtr  );

		bool validateEndTranslate();
		bool validateEndNode();
		bool validateEndCOLLADA();
		bool validateEndLibraryNodes();

/*		begin__translate
		begin__COLLADA__library_nodes__node__translate
		*/

		bool beginTranslate(void* attributeData ) {return beginTranslate(*static_cast<TranslateAttributeData*>(attributeData));}
		bool beginNode(void* attributeData ) {return beginNode(*static_cast<NodeAttributeData*>(attributeData));}
		bool beginCOLLADA(void *attributeData ){return beginCOLLADA(*static_cast<COLLADAAttributeData*>(attributeData));}
		bool beginLibraryNodes(void *attributeData ){return beginLibraryNodes(*static_cast<LibraryNodesAttributeData*>(attributeData));}


		bool dataTranslate(const ParserChar* text, size_t textLength ){return characterData2IntData(text, textLength, &ColladaParserAutoGen::dataTranslate);} 
		bool dataNode(const ParserChar* text, size_t textLength ){return true;}
		bool dataCOLLADA(const ParserChar* text, size_t textLength ){return true;}
		bool dataLibraryNodes(const ParserChar* text, size_t textLength ){return true;}


		//abstract functions that need to implemented 
	protected:

		virtual bool endTranslate()=0;
		virtual bool endNode()=0;
		virtual bool endCOLLADA()=0;
		virtual bool endLibraryNodes()=0;

		virtual bool beginTranslate(const TranslateAttributeData& attributeData )=0;
		virtual bool beginNode(const NodeAttributeData& attributeData )=0;
		virtual bool beginCOLLADA(const COLLADAAttributeData& attributeData )=0;
		virtual bool beginLibraryNodes(const LibraryNodesAttributeData& attributeData )=0;

//		virtual bool dataTranslate(const float* data, size_t length)=0;
		virtual bool dataTranslate(const int* data, size_t length)=0;


	private:
        /** Disable default copy ctor. */
		ColladaParserAutoGen( const ColladaParserAutoGen& pre );
        /** Disable default assignment operator. */
		const ColladaParserAutoGen& operator= ( const ColladaParserAutoGen& pre );

		void initFunctionMap();

		void initNameMap();

	};

} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_COLLADAPARSER_AUTOGEN_H__
