#include "GeneratedSaxParserColladaParserAutoGen.h"
#include "GeneratedSaxParserUtils.h"
#include "GeneratedSaxParserIErrorHandler.h"

#include <cassert>

namespace GeneratedSaxParser
{

	const char* ColladaParserAutoGen::PARENT_CHILD_ELEMENT_SEPARATOR = "__";


	const char* ColladaParserAutoGen::NAME_ELEMENT_COLLADA = "COLLADA";
	const char* ColladaParserAutoGen::NAME_ELEMENT_LIBRARY_NODES = "library_nodes";
	const char* ColladaParserAutoGen::NAME_ELEMENT_VISUAL_SCENE = "visual_scene";
	const char* ColladaParserAutoGen::NAME_ELEMENT_NODE = "node";
	const char* ColladaParserAutoGen::NAME_ELEMENT_TRANSLATE = "translate";

	const char* ColladaParserAutoGen::NAME_ATTRIBUTE_XMLNS = "xmlns";
	const char* ColladaParserAutoGen::NAME_ATTRIBUTE_VERSION = "version";
	const char* ColladaParserAutoGen::NAME_ATTRIBUTE_NUMBER = "number";
	const char* ColladaParserAutoGen::NAME_ATTRIBUTE_NUMBER2 = "number2";
	const char* ColladaParserAutoGen::NAME_ATTRIBUTE_TYPE = "type";

	const char* ColladaParserAutoGen::NAME_TYPE_NODE = "NODE";
	const char* ColladaParserAutoGen::NAME_TYPE_JOINT = "JOINT";


	const ColladaParserAutoGen::TranslateAttributeData ColladaParserAutoGen::TranslateAttributeData::DEFAULT;
	const ColladaParserAutoGen::TranslateValidationData ColladaParserAutoGen::TranslateValidationData::DEFAULT;

	const ColladaParserAutoGen::NodeAttributeData ColladaParserAutoGen::NodeAttributeData::DEFAULT;
	const ColladaParserAutoGen::NodeValidationData ColladaParserAutoGen::NodeValidationData::DEFAULT;

	const ColladaParserAutoGen::COLLADAAttributeData ColladaParserAutoGen::COLLADAAttributeData::DEFAULT = {0,0,0, NUMBER2_6, TYPE_NODE};
	const ColladaParserAutoGen::COLLADAAttributeData::Number2EnumPair ColladaParserAutoGen::COLLADAAttributeData::NUMBER2_ENUM_MAP[NUMBER2_COUNT] =
	{
		Number2EnumPair(2, NUMBER2_2),
		Number2EnumPair(4, NUMBER2_4),
		Number2EnumPair(6, NUMBER2_6),
		Number2EnumPair(9, NUMBER2_9)
	};
	const ColladaParserAutoGen::COLLADAAttributeData::TypeEnumPair ColladaParserAutoGen::COLLADAAttributeData::TYPE_ENUM_MAP[TYPE_COUNT] =
	{
		TypeEnumPair(HASH_TYPE_NODE, TYPE_NODE),
		TypeEnumPair(HASH_TYPE_JOINT, TYPE_JOINT),
	};
	const ColladaParserAutoGen::COLLADAValidationData ColladaParserAutoGen::COLLADAValidationData::DEFAULT;

	const ColladaParserAutoGen::LibraryNodesAttributeData ColladaParserAutoGen::LibraryNodesAttributeData::DEFAULT;
	const ColladaParserAutoGen::LibraryNodesValidationData ColladaParserAutoGen::LibraryNodesValidationData::DEFAULT;

	//--------------------------------------------------------------------
	ColladaParserAutoGen::ColladaParserAutoGen(IErrorHandler* errorHandler)
		: ParserTemplate<ColladaParserAutoGen>(errorHandler)
	{
		initFunctionMap();
		initNameMap();
	}

	//--------------------------------------------------------------------
	ColladaParserAutoGen::~ColladaParserAutoGen()
	{
	}

	//--------------------------------------------------------------------
	bool ColladaParserAutoGen::validateBeginTranslate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
	{
		TranslateValidationData* validationData = 0;
		if ( mValidate )
			validationData = newData<TranslateValidationData>(validationDataPtr);

		TranslateAttributeData* attributeData = newData<TranslateAttributeData>(attributeDataPtr);

		if ( mElementDataStack.empty() )
			return false;

		ElementData& elementData = mElementDataStack.top();

		switch ( elementData.elementHash )
		{
		case HASH_ELEMENT_NODE:
			{
				NodeValidationData* nodeValidationData = static_cast<NodeValidationData*>(elementData.validationData);
			}
			break;
		case HASH_ELEMENT_VISUAL_SCENE:
			break;
		default:
			return false;
		}

		return true;
	}


	//--------------------------------------------------------------------
	bool ColladaParserAutoGen::validateBeginNode(const ParserAttributes& attributes, void ** attributeDataPtr,  void ** validationDataPtr  )
	{
		NodeValidationData* validationData = 0;
		if ( mValidate )
			validationData = newData<NodeValidationData>(validationDataPtr);

		NodeAttributeData* attributeData = newData<NodeAttributeData>(attributeDataPtr);

		if ( mElementDataStack.empty() )
			return false;

		ElementData& elementData = mElementDataStack.top();
/*
		switch ( elementData.elementHash )
		{
		case HASH_LIBRARY_NODES:
			{
				LibraryNodesValidationData* libraryNodesValidationData = static_cast<LibraryNodesValidationData*>(elementData.validationData);

			}
			break;
		case HASH_ELEMENT_NODE:
			{
				NodeValidationData* nodeValidationData = static_cast<NodeValidationData*>(elementData.validationData);

			}
			break;
		case HASH_ELEMENT_VISUAL_SCENE:
			break;
		default:
			return false;
		}
*/
		return true;
	}


	//--------------------------------------------------------------------
	bool ColladaParserAutoGen::validateBeginCOLLADA(const ParserAttributes& attributes, void ** attributeDataPtr,  void ** validationDataPtr  )
	{
		COLLADAValidationData* validationData = 0;
		if ( mValidate )
			validationData = newData<COLLADAValidationData>(validationDataPtr);

		COLLADAAttributeData* attributeData = newData<COLLADAAttributeData>(attributeDataPtr);

		const ParserChar** attributeArray = attributes.attributes;
		while (true)
		{
			const ParserChar * attributeName = *attributeArray;
			if ( !attributeName ) 
				break;

			StringHash hash = Utils::calculateStringHash(attributeName);
			attributeArray++;
			assert(attributeArray);
			const ParserChar* attributeValue = *attributeArray;
			attributeArray++;
			switch ( hash )
			{
			case HASH_ATTRIBUTE_XMLNS:
				{
	/*				if ( mValidate )
					{
						if ( validationData->flags & COLLADAValidationData::HAS_XMLNS )
							return false;
						validationData->flags |= COLLADAValidationData::HAS_XMLNS;
					}
					*/
					attributeData->xmlns = attributeValue;
					break;
				}
			case HASH_ATTRIBUTE_VERSION:
				{
	/*				if ( mValidate )
					{
						if ( validationData->flags & COLLADAValidationData::HAS_VERSION )
							return false;
						validationData->flags |= COLLADAValidationData::HAS_VERSION;
					}*/
					attributeData->version = attributeValue;
					break;
				}
			case HASH_ATTRIBUTE_NUMBER:
				{
					bool failed;
					attributeData->number = Utils::toUnsignedLong(attributeValue, failed);
					if ( failed && handleError(ParserError::SEVERITY_ERROR, 
											   ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,
											   HASH_ELEMENT_COLLADA,
											   HASH_ATTRIBUTE_NUMBER2,
											   attributeValue))
						return false;
					break;
				}
			case HASH_ATTRIBUTE_NUMBER2:
				{
					bool failed;
					attributeData->number2 = Utils::toEnum<COLLADAAttributeData::Number2Enum, 
														   unsigned long, 
				         		                           COLLADAAttributeData::NUMBER2_COUNT>
						                                   (attributeValue, 
						                                    failed, 
						                                    COLLADAAttributeData::NUMBER2_ENUM_MAP, 
						                                    Utils::toUnsignedLong);

					if ( failed && handleError(ParserError::SEVERITY_ERROR, 
											   ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,
											   HASH_ELEMENT_COLLADA,
											   HASH_ATTRIBUTE_NUMBER2,
											   attributeValue))
						return false;
					break;
				}
			case HASH_ATTRIBUTE_TYPE:
				{
					bool failed;
					attributeData->type = Utils::toEnum<COLLADAAttributeData::TypeEnum, 
														   StringHash, 
						                                   COLLADAAttributeData::TYPE_COUNT>
						                                   (attributeValue, 
						                                    failed, 
						                                    COLLADAAttributeData::TYPE_ENUM_MAP, 
						                                    Utils::calculateStringHash);

					if ( failed && handleError(ParserError::SEVERITY_ERROR, 
										       ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,
											   HASH_ELEMENT_COLLADA,
											   HASH_ATTRIBUTE_TYPE,
											   attributeValue))
						return false;
					break;
				}
			default:
				if ( handleError(ParserError::SEVERITY_ERROR, 
					             ParserError::ERROR_UNKNOWN_ATTRIBUTE,
					             HASH_ELEMENT_COLLADA,
					             0,
					             attributeName))
					return false;
			}
		}

		if ( !mElementDataStack.empty() && handleError(ParserError::SEVERITY_ERROR,
			                                           ParserError::ERROR_ELEMENT_MUST_BE_ROOT,
                                                       HASH_ELEMENT_COLLADA,
													   0,
													   0 ) )
			{
				return false;
			}

		return true;
	}

	//--------------------------------------------------------------------
	bool ColladaParserAutoGen::validateBeginLibraryNodes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
	{
		LibraryNodesValidationData* validationData = 0;
		if ( mValidate )
			validationData = newData<LibraryNodesValidationData>(validationDataPtr);

		LibraryNodesAttributeData* attributeData = newData<LibraryNodesAttributeData>(attributeDataPtr);

		if ( mElementDataStack.empty() )
			return false;
		ElementData& elementData = mElementDataStack.top();
	
		switch ( elementData.elementHash )
		{
		case HASH_ELEMENT_COLLADA:
			{
				COLLADAValidationData* colladaValidationData = static_cast<COLLADAValidationData*>(elementData.validationData);
			}
			break;
		default:
			return false;
		}
		return true;
	}

	bool ColladaParserAutoGen::validateEndTranslate()
	{
		return intDataEnd(&ColladaParserAutoGen::dataTranslate);
	}


	//--------------------------------------------------------------------
	bool ColladaParserAutoGen::validateEndNode()
	{
		return true;
	}

	//--------------------------------------------------------------------
	bool ColladaParserAutoGen::validateEndCOLLADA()
	{
		return true;
	}

	bool ColladaParserAutoGen::validateEndLibraryNodes()
	{
		return true;
	}



	void ColladaParserAutoGen::initFunctionMap()
	{
		mElementFunctionMap[HASH_ELEMENT_TRANSLATE] = FunctionStruct(&ColladaParserAutoGen::beginTranslate, 
														     &ColladaParserAutoGen::dataTranslate, 
     														 &ColladaParserAutoGen::endTranslate, 
														     &ColladaParserAutoGen::validateBeginTranslate,
														     &ColladaParserAutoGen::validateEndTranslate);
		mElementFunctionMap[HASH_ELEMENT_NODE] = FunctionStruct(&ColladaParserAutoGen::beginNode, 
														&ColladaParserAutoGen::dataNode, 
														&ColladaParserAutoGen::endNode, 
														&ColladaParserAutoGen::validateBeginNode,
														&ColladaParserAutoGen::validateEndNode);
		mElementFunctionMap[HASH_ELEMENT_COLLADA] = FunctionStruct(&ColladaParserAutoGen::beginCOLLADA, 
														   &ColladaParserAutoGen::dataCOLLADA, 
														   &ColladaParserAutoGen::endCOLLADA, 
														   &ColladaParserAutoGen::validateBeginCOLLADA,
														   &ColladaParserAutoGen::validateEndCOLLADA);
		mElementFunctionMap[HASH_ELEMENT_LIBRARY_NODES] = FunctionStruct(&ColladaParserAutoGen::beginLibraryNodes, 
																 &ColladaParserAutoGen::dataLibraryNodes, 
			                                                     &ColladaParserAutoGen::endLibraryNodes, 
																 &ColladaParserAutoGen::validateBeginLibraryNodes,
																 &ColladaParserAutoGen::validateEndLibraryNodes);
	}

	void ColladaParserAutoGen::initNameMap()
	{
		mHashNameMap[HASH_ELEMENT_TRANSLATE] = NAME_ELEMENT_TRANSLATE;
		mHashNameMap[HASH_ELEMENT_NODE] = NAME_ELEMENT_NODE;
		mHashNameMap[HASH_ELEMENT_COLLADA] = NAME_ELEMENT_COLLADA;
		mHashNameMap[HASH_ELEMENT_LIBRARY_NODES] = NAME_ELEMENT_LIBRARY_NODES;

		mHashNameMap[HASH_ATTRIBUTE_XMLNS] = NAME_ATTRIBUTE_XMLNS;
		mHashNameMap[HASH_ATTRIBUTE_VERSION] = NAME_ATTRIBUTE_VERSION;
		mHashNameMap[HASH_ATTRIBUTE_NUMBER] = NAME_ATTRIBUTE_NUMBER;
		mHashNameMap[HASH_ATTRIBUTE_NUMBER2] = NAME_ATTRIBUTE_NUMBER2;
		mHashNameMap[HASH_ATTRIBUTE_TYPE] = NAME_ATTRIBUTE_TYPE;

		mHashNameMap[HASH_TYPE_NODE] = NAME_TYPE_NODE;
		mHashNameMap[HASH_TYPE_JOINT] = NAME_TYPE_JOINT;		
	}



} // namespace GeneratedSaxParser
