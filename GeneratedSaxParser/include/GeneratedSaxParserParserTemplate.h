/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_COLLADAPARSERTEMPLATE_H__
#define __GENERATEDSAXPARSER_COLLADAPARSERTEMPLATE_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserParser.h"
#include "GeneratedSaxParserStackMemoryManager.h"
#include "GeneratedSaxParserUtils.h"
#include "GeneratedSaxParserParserTemplateBase.h"
#include "GeneratedSaxParserIUnknownElementHandler.h"
#include "GeneratedSaxParserINamespaceHandler.h"
#include "GeneratedSaxParserNamespaceStack.h"


#include <map>
#include <stack>
#include <string.h>



namespace GeneratedSaxParser
{

	/** The base template for the auto generated classes.
	@param DerivedClass The derived class itself
	@param ImplClass The class that receives the events from the parser, i.e. the
	class that contains the memebers that need to be implemented by the user.*/
	template<class DerivedClass, class ImplClass>
	class ParserTemplate : public ParserTemplateBase
	{
	public:

		typedef bool ( ImplClass::*floatDataFunctionPtr ) (const float* text, size_t textLength );
		typedef bool ( ImplClass::*doubleDataFunctionPtr ) (const double* text, size_t textLength );

		typedef bool ( ImplClass::*sint8DataFunctionPtr ) (const sint8* text, size_t textLength );
		typedef bool ( ImplClass::*uint8DataFunctionPtr ) (const uint8* text, size_t textLength );

		typedef bool ( ImplClass::*sint16DataFunctionPtr ) (const sint16* text, size_t textLength );
		typedef bool ( ImplClass::*uint16DataFunctionPtr ) (const uint16* text, size_t textLength );

		typedef bool ( ImplClass::*sint32DataFunctionPtr ) (const sint32* text, size_t textLength );
		typedef bool ( ImplClass::*uint32DataFunctionPtr ) (const uint32* text, size_t textLength );

		typedef bool ( ImplClass::*sint64DataFunctionPtr ) (const sint64* text, size_t textLength );
		typedef bool ( ImplClass::*uint64DataFunctionPtr ) (const uint64* text, size_t textLength );

		typedef bool ( ImplClass::*boolDataFunctionPtr ) (const bool* text, size_t textLength );

        typedef bool ( ImplClass::*stringListDataFunctionPtr ) (const ParserString* text, size_t textLength );

	protected:
		typedef bool ( DerivedClass::*ElementBeginFunctionPtr ) ( void* attributeData );
		typedef bool ( DerivedClass::*TextDataFunctionPtr ) ( const ParserChar* text, size_t textLength );
		typedef bool ( DerivedClass::*ElementEndFunctionPtr ) ();
		typedef bool ( DerivedClass::*ElementValidateBeginFunctionPtr ) ( const ParserAttributes& attributes, void ** attributeDataPtr,  void ** validationDataPtr );
		typedef bool ( DerivedClass::*ElementValidateEndFunctionPtr ) ( );
        typedef bool ( DerivedClass::*FreeAttributesFunctionPtr ) ( void* attributeData );


		struct FunctionStruct
		{
			FunctionStruct()
				: beginFunction(0),
				textDataFunction(0),
				endFunction(0),
				validateBeginFunction(0),
				validateEndFunction(0),
				freeAttributesFunction(0)
			{}

			FunctionStruct( ElementBeginFunctionPtr _beginFunction,
				TextDataFunctionPtr _textDataFunction,
				ElementEndFunctionPtr _endFunction,
				ElementValidateBeginFunctionPtr _validateBeginFunction,
				ElementValidateEndFunctionPtr _validateEndFunction,
                FreeAttributesFunctionPtr _freeAttributesFunction)
				: beginFunction(_beginFunction),
				textDataFunction(_textDataFunction),
				endFunction(_endFunction),
				validateBeginFunction(_validateBeginFunction),
				validateEndFunction(_validateEndFunction),
                freeAttributesFunction(_freeAttributesFunction)
			{}

			ElementBeginFunctionPtr beginFunction;
			TextDataFunctionPtr textDataFunction;
			ElementEndFunctionPtr endFunction;
			ElementValidateBeginFunctionPtr validateBeginFunction;
			ElementValidateEndFunctionPtr validateEndFunction;
            FreeAttributesFunctionPtr freeAttributesFunction;
		};

    public:
		typedef std::map<StringHash, FunctionStruct> ElementFunctionMap;
        typedef std::map<StringHash, INamespaceHandler*> NamespaceHandlerMap;


	protected:
        /** Map of element hashes to generated methods. Contains pointers to all methods. */
		ElementFunctionMap mElementFunctionMap;
        /** Currently used function map. To ignore elements. */
        const ElementFunctionMap* mCurrentElementFunctionMap;
        /** Currently used client implementation. */
		ImplClass* mImpl;
        /** Currently used handler for unknown elements. */
        IUnknownElementHandler* mUnknownHandler;

        /** Currently registered namespace handlers. */
        NamespaceHandlerMap mNamespaceHandlers;
        /** Currently used namespace handler. */
        INamespaceHandler* mActiveNamespaceHandler;

        /** Stack of XML namespace declarations. */
        NamespacesStack mNamespacesStack;
        /** Generated-Element-Hash to XML-Namespace-Hash. */
        NamespacePrefixesMap mElementToNamespaceMap;
        /** If true, generated methods are called even when xml namespace is wrong. */
        bool mLaxNamespaceHandling;

    private:
		/** Number of elements that have been opened and should be ignored due to mCurrentElementFunctionMap. */
		size_t mIgnoreElements;
        /** Number of elements that have been opened and are unknown. */
        size_t mUnknownElements;
        /** Number of elements that have been opened and are in a different namespace. */
        size_t mNamespaceElements;


	public:
		ParserTemplate(ImplClass* impl, IErrorHandler* errorHandler)
			:
		  ParserTemplateBase(errorHandler),
              mCurrentElementFunctionMap(&mElementFunctionMap),
			  mImpl(impl),
              mUnknownHandler(0),
              mActiveNamespaceHandler(0),
              mLaxNamespaceHandling(false),
			  mIgnoreElements(0),
              mUnknownElements(0),
              mNamespaceElements(0)
		  {};
		virtual ~ParserTemplate(){};

		/** Sets the object, that should receive all the callbacks from now on.*/
		void setCallbackObject(ImplClass* impl){ mImpl = impl; }

        /** Registers a handler for unknown elements. Only the last registered will be used. */
        void registerUnknownElementHandler(IUnknownElementHandler* handler) {mUnknownHandler = handler;}

        /** Registers a handler for given namespace. */
        void registerNamespaceHandler( const StringHash& namespaceHash, INamespaceHandler* handler );

        /** Unregisters handler for given namespace. */
        void unregisterNamespaceHandler( const StringHash& namespaceHash );

        /** Returns currently used ElementFunctionMap. */
        const ElementFunctionMap* getElementFunctionMap() {return mCurrentElementFunctionMap;}

        /** Sets a new ElementFunctionMap. May be used to retrieve certain data first. */
        void setElementFunctionMap(const ElementFunctionMap* map) {mCurrentElementFunctionMap = map;}

        /** Returns complete ElementFunctionMap (the one containing all function pointers). */
        const ElementFunctionMap& getCompleteElementFunctionMap() {return mElementFunctionMap;}

        /** Returns whether lax namespace handling is turned on. */
        bool isLaxNamespaceHandling() {return mLaxNamespaceHandling;}
        /** Enables/Disables lax namespace handling. */
        void setLaxNamespaceHandling(bool value) {mLaxNamespaceHandling=value;}

    public:
		bool elementBegin(const ParserChar* elementName, const ParserAttributes& attributes );

		bool elementEnd(const ParserChar* elementName );

		bool textData(const ParserChar* text, size_t textLength);

    protected:
        virtual bool findElementHash( ElementData& elementData ) = 0;
        virtual bool isXsAnyAllowed( const StringHash& elementHash ) = 0;
        virtual bool isDifferentNamespaceAllowed() = 0;

        /** Checks for xmlns and xmlns:<name> attributes to add them to mNamespacesStack. */
        void parseNamespaceDeclarations( const ParserAttributes& attributes );

	protected:
		template<class DataType,
				 DataType (*toData)( const ParserChar**, const ParserChar*, bool& )
        >
		bool characterData2Data(const ParserChar* text,
                size_t textLength,
                DataType (DerivedClass::*toDataWithPrefix)( const ParserChar*, const ParserChar*, const ParserChar**, const ParserChar*, bool& ),
                bool ( ImplClass::*dataFunction ) ( const DataType*, size_t )
#ifdef GENERATEDSAXPARSER_VALIDATION
                ,
                ParserError::ErrorType (*listValidationFunc)( const DataType*, size_t ) = 0,
                size_t* wholeListLength = 0,
                ParserError::ErrorType (*itemTypeValidationFunc)( DataType ) = 0
#endif
                );

        bool characterData2StringData(const ParserChar* text,
            size_t textLength,
            stringListDataFunctionPtr stringListDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const ParserString*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( ParserString ) = 0
#endif
            );

        bool characterData2BoolData(const ParserChar* text,
            size_t textLength,
            boolDataFunctionPtr boolDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const bool*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( bool ) = 0
#endif
            );

		bool characterData2FloatData( const ParserChar* text,
            size_t textLength,
            floatDataFunctionPtr floatDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const float*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( float ) = 0
#endif
            );
		bool characterData2DoubleData( const ParserChar* text,
            size_t textLength,
            doubleDataFunctionPtr doubleDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const double*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( double ) = 0
#endif
            );

		bool characterData2Sint8Data( const ParserChar* text,
            size_t textLength,
            sint8DataFunctionPtr charDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const sint8*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint8 ) = 0
#endif
            );
		bool characterData2Uint8Data( const ParserChar* text,
            size_t textLength,
            uint8DataFunctionPtr unsignedCharDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const uint8*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint8 ) = 0
#endif
            );

		bool characterData2Sint16Data( const ParserChar* text,
            size_t textLength,
            sint16DataFunctionPtr shortDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const sint16*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint16 ) = 0
#endif
            );
		bool characterData2Uint16Data( const ParserChar* text,
            size_t textLength,
            uint16DataFunctionPtr unsignedShortDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const uint16*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint16 ) = 0
#endif
            );

		bool characterData2Sint32Data( const ParserChar* text,
            size_t textLength,
            sint32DataFunctionPtr intDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const sint32*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint32 ) = 0
#endif
            );
		bool characterData2Uint32Data( const ParserChar* text,
            size_t textLength,
            uint32DataFunctionPtr unsignedIntDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const uint32*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint32 ) = 0
#endif
            );

		bool characterData2Sint64Data( const ParserChar* text,
            size_t textLength,
            sint64DataFunctionPtr longDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const sint64*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint64 ) = 0
#endif
            );
		bool characterData2Uint64Data( const ParserChar* text,
            size_t textLength,
            uint64DataFunctionPtr unsignedLongDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const uint64*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint64 ) = 0
#endif
            );

        template<class DataType, DataType (*toData)( const ParserChar**, const ParserChar*, bool& )>
		bool dataEnd(
            bool ( ImplClass::*dataFunction ) ( const DataType*, size_t )
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const DataType*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( DataType ) = 0
#endif
            );

        bool stringListDataEnd(
            stringListDataFunctionPtr stringListDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const ParserString*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( ParserString ) = 0
#endif
            );
        bool boolDataEnd(
            boolDataFunctionPtr boolDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const bool*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( bool ) = 0
#endif
            );
		bool floatDataEnd(
            floatDataFunctionPtr floatDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const float*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( float ) = 0
#endif
            );
        bool doubleDataEnd(
            doubleDataFunctionPtr doubleDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const double*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( double ) = 0
#endif
            );

		bool sint8DataEnd(
            sint8DataFunctionPtr charDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const sint8*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint8 ) = 0
#endif
            );
		bool uint8DataEnd(
            uint8DataFunctionPtr unsignedCharDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const uint8*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint8 ) = 0
#endif
            );

		bool sint16DataEnd(
            sint16DataFunctionPtr shortDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const sint16*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint16 ) = 0
#endif
            );
		bool uint16DataEnd(
            uint16DataFunctionPtr unsignedShortDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const uint16*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint16 ) = 0
#endif
            );

		bool sint32DataEnd(
            sint32DataFunctionPtr intDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const sint32*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint32 ) = 0
#endif
            );
		bool uint32DataEnd(
            uint32DataFunctionPtr unsignedIntDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const uint32*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint32 ) = 0
#endif
            );

		bool sint64DataEnd(
            sint64DataFunctionPtr longDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const sint64*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint64 ) = 0
#endif
            );
		bool uint64DataEnd(
            uint64DataFunctionPtr unsignedLongDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const uint64*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint64 ) = 0
#endif
            );


        /**
        * Converts buffer representing a xs:list to a buffer containing the list as C++ item type.
        * Input buffer must contain all data from XML file. This method does not support partial buffers.
        * @tparam DataType C++ list item type.
        * @tparam toData Function which does actual conversion.
        * @param text Buffer containing xs:list as text.
        * @param textLength Length of input buffer.
        * @param list Output parameter. Must be freed by caller.
        * @param itemTypeValidationFunc Function pointer to validate each item of the list.
        * @param elementHash Hash of current element. Used for error handling if validation of list item failed.
        * @param attributeHash Hash of current attribute. Used for error handling if validation of list item failed.
        * @return True on success, false on failure.
        */
        template<typename DataType,
            DataType (*toData)(const ParserChar** buffer, bool& failed)>
            bool characterData2List(const ParserChar* text, XSList<DataType>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
                ParserError::ErrorType (*itemTypeValidationFunc)(DataType) = 0,
                StringHash elementHash = 0,
                StringHash attributeHash = 0
#endif
                );

        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2StringList(const ParserChar* text, XSList<ParserString>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*itemTypeValidationFunc)(ParserString) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0
#endif
            );
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2BoolList(const ParserChar* text, XSList<bool>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*itemTypeValidationFunc)(bool) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0
#endif
            );
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2FloatList(const ParserChar* text, XSList<float>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*itemTypeValidationFunc)(float) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0
#endif
            );
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2DoubleList(const ParserChar* text, XSList<double>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*itemTypeValidationFunc)(double) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0
#endif
            );

        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Sint8List(const ParserChar* text, XSList<sint8>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*itemTypeValidationFunc)(sint8) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0
#endif
            );
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Sint16List(const ParserChar* text, XSList<sint16>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*itemTypeValidationFunc)(sint16) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0
#endif
            );
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Sint32List(const ParserChar* text, XSList<sint32>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*itemTypeValidationFunc)(sint32) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0
#endif
            );
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Sint64List(const ParserChar* text, XSList<sint64>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*itemTypeValidationFunc)(sint64) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0
#endif
            );

        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Uint8List(const ParserChar* text, XSList<uint8>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*itemTypeValidationFunc)(uint8) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0
#endif
            );
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Uint16List(const ParserChar* text, XSList<uint16>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*itemTypeValidationFunc)(uint16) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0
#endif
            );
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Uint32List(const ParserChar* text, XSList<uint32>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*itemTypeValidationFunc)(uint32) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0
#endif
            );
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Uint64List(const ParserChar* text, XSList<uint64>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*itemTypeValidationFunc)(uint64) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0
#endif
            );

        /**
         * Converts a string into a list of enums.
         * @see characterData2Data
         */
        template<class EnumType, class BaseType, EnumType EnumMapCount>
        bool characterData2EnumData(const ParserChar* text, size_t textLength,
            bool ( ImplClass::*dataFunction ) ( const EnumType*, size_t ),
            const std::pair<BaseType, EnumType>* enumMap,
            BaseType (*baseConversionFunctionPtr)( const ParserChar**, const ParserChar*, bool& )
            ,
            EnumType (*toEnum)(const ParserChar**,
                const ParserChar*,
                bool&,
                const std::pair<BaseType, EnumType>*,
                BaseType (*baseConversionFunctionPtr)(const ParserChar**, const ParserChar*, bool&)
            ),
            EnumType (DerivedClass::*toEnumDataWithPrefix)(
                const ParserChar*, const ParserChar*, const ParserChar**, const ParserChar*, bool&,
                const std::pair<BaseType, EnumType>*,
                BaseType (*baseConversionFunctionPtr)(const ParserChar**, const ParserChar*, bool&)
            )
        );

        /**
         * Converts last part of a buffer into a list of enums.
         * @see dataEnd
         */
        template<class EnumType, class BaseType, EnumType EnumMapCount
        >
        bool dataEnumEnd(bool ( ImplClass::*dataFunction ) (const EnumType*, size_t),
            const std::pair<BaseType, EnumType>* enumMap,
            BaseType (*baseConversionFunctionPtr)(const ParserChar**, const ParserChar*, bool&),
            EnumType (*toEnum)( const ParserChar**,
            const ParserChar*,
            bool&,
            const std::pair<BaseType, EnumType>*,
            BaseType (*baseConversionFunctionPtr)(const ParserChar**, const ParserChar*, bool&))
        );


    private:
		/** Disable default copy ctor. */
		ParserTemplate( const ParserTemplate& pre );
		/** Disable default assignment operator. */
		const ParserTemplate& operator= ( const ParserTemplate& pre );

	};

    //--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	template<class DataType,
		     DataType (*toData)( const ParserChar**, const ParserChar*, bool& )
    >
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Data(
            const ParserChar* text,
            size_t textLength,
            DataType (DerivedClass::*toDataWithPrefix)( const ParserChar*, const ParserChar*, const ParserChar**, const ParserChar*, bool& ),
            bool ( ImplClass::*dataFunction ) ( const DataType*, size_t )
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*listValidationFunc)( const DataType*, size_t ),
            size_t* wholeListLength,
            ParserError::ErrorType (*itemTypeValidationFunc)( DataType )
#endif
            )
	{
        size_t dataBufferIndex = 0;
		const ParserChar* dataBufferPos = text;
		const ParserChar* bufferEnd = text + textLength;
		const ParserChar* lastDataBufferIndex = dataBufferPos;

		// handle incomplete fragment from last call to textData
		DataType fragmentData = 0;
        bool haveToDeleteParsedFragmentData = false;
		if ( mLastIncompleteFragmentInCharacterData )
		{
			bool failed = false;

			fragmentData = (static_cast<DerivedClass*>(this)->*toDataWithPrefix)(mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, &dataBufferPos, bufferEnd, failed);
			if ( failed )
			{
				if ( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
					             ParserError::ERROR_TEXTDATA_PARSING_FAILED,
					             0,
					             mLastIncompleteFragmentInCharacterData))
				{
                    mStackMemoryManager.deleteObject(); // haveToDeleteParsedFragmentData
                    mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
                    mLastIncompleteFragmentInCharacterData = 0;
                    mEndOfDataInCurrentObjectOnStack = 0;
					return false;
				}
				else
				{
                    mStackMemoryManager.deleteObject(); // haveToDeleteParsedFragmentData
                    mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
                    mLastIncompleteFragmentInCharacterData = 0;
                    mEndOfDataInCurrentObjectOnStack = 0;
                    // TODO check if this is correct
					return true;
				}
			}
            haveToDeleteParsedFragmentData = true;
#ifdef GENERATEDSAXPARSER_VALIDATION
            if ( itemTypeValidationFunc != 0)
            {
                ParserError::ErrorType simpleTypeValidationResult = (itemTypeValidationFunc)(fragmentData);
                if ( simpleTypeValidationResult != ParserError::SIMPLE_TYPE_VALIDATION_OK )
                {
                    ParserChar msg[21];
                    Utils::fillErrorMsg(msg, mLastIncompleteFragmentInCharacterData, 20);
                    if( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
                        simpleTypeValidationResult,
                        0,
                        msg) )
                    {
                        mStackMemoryManager.deleteObject(); // haveToDeleteParsedFragmentData
                        mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
                        mLastIncompleteFragmentInCharacterData = 0;
                        mEndOfDataInCurrentObjectOnStack = 0;
                        return false;
                    }
                }
            }
#endif
			dataBufferIndex = 1;
		}

        // we only need to start the general parsing 
        size_t callsToDataFunc = 0;
        if ( dataBufferPos != bufferEnd )
        {
		    DataType* typedBuffer = (DataType*)mStackMemoryManager.newObject(TYPED_VALUES_BUFFER_SIZE * sizeof(DataType));

		    if ( dataBufferIndex > 0)
			    typedBuffer[0] = fragmentData;


		    bool failed = false;
		    while ( !failed )
		    {
			    lastDataBufferIndex = dataBufferPos;
			    DataType dataValue =toData(&dataBufferPos, bufferEnd, failed);
			    failed = failed | (dataBufferPos == bufferEnd);
			    if ( !failed )
			    {
#ifdef GENERATEDSAXPARSER_VALIDATION
                    if ( itemTypeValidationFunc != 0)
                    {
                        ParserError::ErrorType simpleTypeValidationResult = (itemTypeValidationFunc)(dataValue);
                        if ( simpleTypeValidationResult != ParserError::SIMPLE_TYPE_VALIDATION_OK )
                        {
                            ParserChar msg[21];
                            Utils::fillErrorMsg(msg, lastDataBufferIndex, 20);
                            if( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
                                simpleTypeValidationResult,
                                0,
                                msg) )
                            {
                                break;
                            }
                        }
                    }
#endif
				    typedBuffer[dataBufferIndex] = dataValue;
				    ++dataBufferIndex;
				    if ( dataBufferIndex == TYPED_VALUES_BUFFER_SIZE )
				    {
#ifdef GENERATEDSAXPARSER_VALIDATION
                        if ( listValidationFunc != 0)
                        {
                            *wholeListLength += dataBufferIndex;
                            ParserError::ErrorType simpleTypeValidationResult = (listValidationFunc)(0, *wholeListLength);
                            if ( simpleTypeValidationResult != ParserError::SIMPLE_TYPE_VALIDATION_OK )
                            {
                                ParserChar msg[21];
                                Utils::fillErrorMsg(msg, text, 20);
                                if( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
                                    simpleTypeValidationResult,
                                    0,
                                    msg) )
                                {
                                    mStackMemoryManager.deleteObject();
                                    if ( haveToDeleteParsedFragmentData )
                                        mStackMemoryManager.deleteObject(); // haveToDeleteParsedFragmentData
                                    if ( mLastIncompleteFragmentInCharacterData )
                                    {
                                        mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
                                        mLastIncompleteFragmentInCharacterData = 0;
                                        mEndOfDataInCurrentObjectOnStack = 0;
                                    }
                                    return false;
                                }
                            }
                        }
#endif
                        (mImpl->*dataFunction)(typedBuffer, dataBufferIndex);
					    dataBufferIndex = 0;
                        callsToDataFunc++;
				    }
			    }
		    }

		    if ( dataBufferPos == bufferEnd )
		    {
			    // we reached the end of the buffer while parsing.
			    // we pass the already parsed typed values
			    // we need to store the not parsed fraction
			    if ( dataBufferIndex > 0)
                {
#ifdef GENERATEDSAXPARSER_VALIDATION
                    if ( listValidationFunc != 0)
                    {
                        *wholeListLength += dataBufferIndex;
                        ParserError::ErrorType simpleTypeValidationResult = (listValidationFunc)(0, *wholeListLength);
                        if ( simpleTypeValidationResult != ParserError::SIMPLE_TYPE_VALIDATION_OK )
                        {
                            ParserChar msg[21];
                            Utils::fillErrorMsg(msg, text, 20);
                            if( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
                                simpleTypeValidationResult,
                                0,
                                msg) )
                            {
                                mStackMemoryManager.deleteObject();
                                if ( haveToDeleteParsedFragmentData )
                                    mStackMemoryManager.deleteObject(); // haveToDeleteParsedFragmentData
                                if ( mLastIncompleteFragmentInCharacterData )
                                {
                                    mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
                                    mLastIncompleteFragmentInCharacterData = 0;
                                    mEndOfDataInCurrentObjectOnStack = 0;
                                }
                                return false;
                            }
                        }
                    }
#endif
                    (mImpl->*dataFunction)(typedBuffer, dataBufferIndex);
                    callsToDataFunc++;
                }
			    mStackMemoryManager.deleteObject();
            }
        }

        if ( dataBufferPos == bufferEnd )
        {
            // we reached the end of the buffer while parsing.
            // we pass the already parsed typed values
            // we need to store the not parsed fraction
            size_t fragmentSize = (dataBufferPos - lastDataBufferIndex)*sizeof(ParserChar);
            if (!Utils::isWhiteSpaceOnly(lastDataBufferIndex, fragmentSize))
            {
                // if mLastIncompleteFragmentInCharacterData == 0 -> list with one element
                if ( callsToDataFunc == 0 && mLastIncompleteFragmentInCharacterData != 0 )
                {
                    // special case: last inclomplete fragment has to be reused
                    size_t oldPrefixDataSize = mEndOfDataInCurrentObjectOnStack - mLastIncompleteFragmentInCharacterData - 1;
                    mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
                    mLastIncompleteFragmentInCharacterData = (ParserChar*)mStackMemoryManager.newObject(fragmentSize + 1 + oldPrefixDataSize);
                    memcpy(mLastIncompleteFragmentInCharacterData + oldPrefixDataSize, lastDataBufferIndex, fragmentSize);
                    mEndOfDataInCurrentObjectOnStack = mLastIncompleteFragmentInCharacterData + fragmentSize + oldPrefixDataSize;

                }
                else
                {
                    mLastIncompleteFragmentInCharacterData = (ParserChar*)mStackMemoryManager.newObject(fragmentSize + 1);
                    memcpy(mLastIncompleteFragmentInCharacterData, lastDataBufferIndex, fragmentSize);
                    mEndOfDataInCurrentObjectOnStack = mLastIncompleteFragmentInCharacterData + fragmentSize;
                }
            }
            else
            {
                if ( haveToDeleteParsedFragmentData )
                    mStackMemoryManager.deleteObject(); // haveToDeleteParsedFragmentData
                if ( mLastIncompleteFragmentInCharacterData )
                {
                    mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
                    mLastIncompleteFragmentInCharacterData = 0;
                    mEndOfDataInCurrentObjectOnStack = 0;
                }
            }
			return true;

		}
		else
		{
			//something went wrong while parsing
			// we abort and don't pass the typed array
			mStackMemoryManager.deleteObject();  //typedBuffer
            if ( haveToDeleteParsedFragmentData )
                mStackMemoryManager.deleteObject(); // haveToDeleteParsedFragmentData
            if ( mLastIncompleteFragmentInCharacterData )
            {
                mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
                mLastIncompleteFragmentInCharacterData = 0;
                mEndOfDataInCurrentObjectOnStack = 0;
            }
			ParserChar dataBufferError[21];
			size_t length = std::min(20, (int)(bufferEnd-dataBufferPos));
			memcpy(dataBufferError, dataBufferPos, length);
			dataBufferError[length] = '\0';
			if ( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
				     	     ParserError::ERROR_TEXTDATA_PARSING_FAILED,
				             0,
				             dataBufferError))
			{
				return false;
            }
			else
			{
				return true;
			}
		}
	}

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    template<class EnumType, class BaseType, EnumType EnumMapCount
    >
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2EnumData(const ParserChar* text, size_t textLength, bool ( ImplClass::*dataFunction ) (const EnumType* data, size_t dataLength ),
        const std::pair<BaseType, EnumType>* enumMap,
        BaseType (*baseConversionFunctionPtr)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)
        ,
        EnumType (*toEnum)(const ParserChar** buffer,
        const ParserChar* bufferEnd,
        bool& failed,
        const std::pair<BaseType, EnumType>* enumMap,
        BaseType (*baseConversionFunctionPtr)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)
        ),
        EnumType (DerivedClass::*toEnumDataWithPrefix)(
        const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed,
        const std::pair<BaseType, EnumType>* enumMap,
        BaseType (*baseConversionFunctionPtr)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)
        )
    )
    {
        size_t dataBufferIndex = 0;
        const ParserChar* dataBufferPos = text;
        const ParserChar* bufferEnd = text + textLength;
        const ParserChar* lastDataBufferIndex = dataBufferPos;

        // handle incomplete fragment from last call to textData
        EnumType fragmentData = EnumMapCount;
        bool haveToDeleteParsedFragmentData = false;
        if ( mLastIncompleteFragmentInCharacterData )
        {
            bool failed = false;

            fragmentData = (static_cast<DerivedClass*>(this)->*toEnumDataWithPrefix)(mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, &dataBufferPos, bufferEnd, failed, enumMap, baseConversionFunctionPtr);
            if ( failed )
            {
                if ( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
                    ParserError::ERROR_TEXTDATA_PARSING_FAILED,
                    0,
                    mLastIncompleteFragmentInCharacterData))
                {
                    mStackMemoryManager.deleteObject(); // haveToDeleteParsedFragmentData
                    mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
                    mLastIncompleteFragmentInCharacterData = 0;
                    mEndOfDataInCurrentObjectOnStack = 0;
                    return false;
                }
                else
                {
                    mStackMemoryManager.deleteObject(); // haveToDeleteParsedFragmentData
                    mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
                    mLastIncompleteFragmentInCharacterData = 0;
                    mEndOfDataInCurrentObjectOnStack = 0;
                    return true;
                }
            }
            haveToDeleteParsedFragmentData = true;
            dataBufferIndex = 1;
        }

        size_t callsToDataFunc = 0;
        EnumType* typedBuffer = (EnumType*)mStackMemoryManager.newObject(TYPED_VALUES_BUFFER_SIZE * sizeof(EnumType));

        if ( dataBufferIndex > 0)
            typedBuffer[0] = fragmentData;


        bool failed = false;
        while ( !failed )
        {
            lastDataBufferIndex = dataBufferPos;
            EnumType dataValue = (*toEnum)(&dataBufferPos, bufferEnd, failed, enumMap, baseConversionFunctionPtr);
            failed = failed | (dataBufferPos == bufferEnd);
            if ( !failed )
            {
                typedBuffer[dataBufferIndex] = dataValue;
                ++dataBufferIndex;
                if ( dataBufferIndex == TYPED_VALUES_BUFFER_SIZE )
                {
                    (mImpl->*dataFunction)(typedBuffer, dataBufferIndex);
                    dataBufferIndex = 0;
                    callsToDataFunc++;
                }
            }
        }

        if ( dataBufferPos == bufferEnd )
        {
            // we reached the end of the buffer while parsing.
            // we pass the already parsed typed values
            // we need to store the not parsed fraction
            if ( dataBufferIndex > 0)
            {
                (mImpl->*dataFunction)(typedBuffer, dataBufferIndex);
                callsToDataFunc++;
            }
            mStackMemoryManager.deleteObject();

            size_t fragmentSize = (dataBufferPos - lastDataBufferIndex)*sizeof(ParserChar);
            if (!Utils::isWhiteSpaceOnly(lastDataBufferIndex, fragmentSize))
            {
                if (callsToDataFunc == 0)
                {
                    // special case: last inclomplete fragment has to be reused
                    size_t oldPrefixDataSize = mEndOfDataInCurrentObjectOnStack - mLastIncompleteFragmentInCharacterData;
                    mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
                    mLastIncompleteFragmentInCharacterData = (ParserChar*)mStackMemoryManager.newObject(fragmentSize + 1 + oldPrefixDataSize);
                    memcpy(mLastIncompleteFragmentInCharacterData + oldPrefixDataSize, lastDataBufferIndex, fragmentSize);
                    mEndOfDataInCurrentObjectOnStack = mLastIncompleteFragmentInCharacterData + fragmentSize + oldPrefixDataSize;

                }
                else
                {
                    mLastIncompleteFragmentInCharacterData = (ParserChar*)mStackMemoryManager.newObject(fragmentSize + 1);
                    memcpy(mLastIncompleteFragmentInCharacterData, lastDataBufferIndex, fragmentSize);
                    mEndOfDataInCurrentObjectOnStack = mLastIncompleteFragmentInCharacterData + fragmentSize;
                }
            }
            else
            {
                if ( haveToDeleteParsedFragmentData )
                    mStackMemoryManager.deleteObject(); // haveToDeleteParsedFragmentData
                if ( mLastIncompleteFragmentInCharacterData )
                {
                    mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
                    mLastIncompleteFragmentInCharacterData = 0;
                    mEndOfDataInCurrentObjectOnStack = 0;
                }
            }

            return true;

        }
        else
        {
            //something went wrong while parsing
            // we abort and don't pass the typed array
            mStackMemoryManager.deleteObject();  //typedBuffer
            if ( haveToDeleteParsedFragmentData )
                mStackMemoryManager.deleteObject(); // haveToDeleteParsedFragmentData
            if ( mLastIncompleteFragmentInCharacterData )
            {
                mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
                mLastIncompleteFragmentInCharacterData = 0;
                mEndOfDataInCurrentObjectOnStack = 0;
            }
            ParserChar dataBufferError[21];
            size_t length = std::min(20, (int)(bufferEnd-dataBufferPos));
            memcpy(dataBufferError, dataBufferPos, length);
            dataBufferError[length] = '\0';
            if ( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
                ParserError::ERROR_TEXTDATA_PARSING_FAILED,
                0,
                dataBufferError))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    template<class DataType,
        DataType (*toData)( const ParserChar**, bool& )>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2List(const ParserChar* text,
            XSList<DataType>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
            ,
            ParserError::ErrorType (*itemTypeValidationFunc)(DataType),
            StringHash elementHash,
            StringHash attributeHash
#endif
            )
    {
        size_t bufferSize = 1 * sizeof(DataType); // TODO find a sane start buffer size and make it a constant
        DataType* typedBuffer = (DataType*)mStackMemoryManager.newObject(bufferSize);

        size_t dataBufferIndex = 0;
        const ParserChar* dataBufferPos = text;

        bool failed = false;

        while ( !failed )
        {
            // just for error handling of item type validation
#ifdef GENERATEDSAXPARSER_VALIDATION
            const ParserChar* currentElementPtr = dataBufferPos;
#endif
            DataType dataValue = toData(&dataBufferPos, failed);
            if ( !failed )
            {
#ifdef GENERATEDSAXPARSER_VALIDATION
                if (itemTypeValidationFunc != 0)
                {
                    ParserError::ErrorType simpleTypeValidationResult = itemTypeValidationFunc(dataValue);
                    if (simpleTypeValidationResult != ParserError::SIMPLE_TYPE_VALIDATION_OK)
                    {
                        if( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
                            simpleTypeValidationResult,
                            elementHash,
                            attributeHash,
                            currentElementPtr) )
                        {
                            return false;
                        }
                    }
                }
#endif
                typedBuffer[dataBufferIndex] = dataValue;
                ++dataBufferIndex;
                if ( (dataBufferIndex * sizeof(DataType)) == bufferSize )
                {
                    typedBuffer = (DataType*)mStackMemoryManager.growObject(bufferSize);
                    bufferSize *= 2;
                }
            }
        }

        if ( *dataBufferPos == '\0' )
        {
            list.data = typedBuffer;
            list.size = dataBufferIndex;
            // note: buffer on stack could be shrinked here.
            return true;
        }
        else
        {
            list.data = 0;
            list.size = 0;
            mStackMemoryManager.deleteObject();

            int bufferLength = 0;
            while (dataBufferPos[bufferLength])
                ++bufferLength;
            ParserChar dataBufferError[21];
            size_t length = std::min(20, bufferLength);
            memcpy(dataBufferError, dataBufferPos, length);
            dataBufferError[length] = '\0';
#ifdef GENERATEDSAXPARSER_VALIDATION
            if ( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
                ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,
                elementHash,
                attributeHash,
                dataBufferError))
#else
            if ( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
                ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,
                0,
                dataBufferError))
#endif
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2FloatData(
        const ParserChar* text,
        size_t textLength,
        floatDataFunctionPtr floatDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const float*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( float )
#endif
        )
	{
		return characterData2Data<float, Utils::toFloat>(text, textLength, &DerivedClass::toFloatPrefix, floatDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}


	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2DoubleData(
        const ParserChar* text,
        size_t textLength,
        doubleDataFunctionPtr doubleDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const double*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( double )
#endif
        )
	{
		return characterData2Data<double, Utils::toDouble>(text, textLength, &DerivedClass::toDoublePrefix, doubleDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
    }


	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint8Data(
        const ParserChar* text,
        size_t textLength,
        sint8DataFunctionPtr charDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const sint8*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint8 )
#endif
        )
	{
		return characterData2Data<sint8, Utils::toSint8>(text, textLength, &DerivedClass::toSint8Prefix, charDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint8Data(
        const ParserChar* text,
        size_t textLength,
        uint8DataFunctionPtr unsignedCharDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const uint8*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint8 )
#endif
        )
	{
		return characterData2Data<uint8, Utils::toUint8>(text, textLength, &DerivedClass::toUint8Prefix, unsignedCharDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint16Data(
        const ParserChar* text,
        size_t textLength,
        sint16DataFunctionPtr shortDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const sint16*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint16 )
#endif
        )
	{
		return characterData2Data<sint16, Utils::toSint16>(text, textLength, &DerivedClass::toSint16Prefix, shortDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint16Data(
        const ParserChar* text,
        size_t textLength,
        uint16DataFunctionPtr unsignedShortDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const uint16*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint16 )
#endif
        )
	{
		return characterData2Data<uint16, Utils::toUint16>(text, textLength, &DerivedClass::toUint16Prefix, unsignedShortDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint32Data(
        const ParserChar* text,
        size_t textLength,
        sint32DataFunctionPtr intDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const sint32*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint32 )
#endif
        )
	{
		return characterData2Data<sint32, Utils::toSint32>(text, textLength, &DerivedClass::toSint32Prefix, intDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint32Data(
        const ParserChar* text,
        size_t textLength,
        uint32DataFunctionPtr unsignedIntDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const uint32*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint32 )
#endif
        )
	{
		return characterData2Data<uint32, Utils::toUint32>(text, textLength, &DerivedClass::toUint32Prefix, unsignedIntDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint64Data(
        const ParserChar* text,
        size_t textLength,
        sint64DataFunctionPtr longDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const sint64*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint64 )
#endif
        )
	{
		return characterData2Data<sint64, Utils::toSint64>(text, textLength, &DerivedClass::toSint64Prefix, longDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint64Data(
        const ParserChar* text,
        size_t textLength,
        uint64DataFunctionPtr unsignedLongDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const uint64*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint64 )
#endif
        )
	{
		return characterData2Data<uint64, Utils::toUint64>(text, textLength, &DerivedClass::toUint64Prefix, unsignedLongDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2BoolData(
        const ParserChar* text,
        size_t textLength,
        boolDataFunctionPtr boolDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const bool*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( bool )
#endif
        )
	{
		return characterData2Data<bool, Utils::toBool>(text, textLength, &DerivedClass::toBoolPrefix, boolDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}


    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2StringData(
        const ParserChar* text,
        size_t textLength,
        stringListDataFunctionPtr stringListDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const ParserString*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( ParserString )
#endif
        )
    {
        return characterData2Data<ParserString, Utils::toStringListItem>(text, textLength, &DerivedClass::toStringListPrefix, stringListDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
    }

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	template<class DataType, DataType (*toData)( const ParserChar**, const ParserChar*, bool& )>
	bool ParserTemplate<DerivedClass, ImplClass>::dataEnd(
        bool ( ImplClass::*dataFunction ) ( const DataType*, size_t )
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const DataType*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( DataType )
#endif
        )
	{
		if ( mLastIncompleteFragmentInCharacterData )
		{
			bool failed = false;
			const ParserChar* bufferBegin = mLastIncompleteFragmentInCharacterData;
            ParserChar* bufferEnd = mEndOfDataInCurrentObjectOnStack;
			DataType typedValue = toData(&bufferBegin, bufferEnd, failed);
			mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
			mLastIncompleteFragmentInCharacterData = 0;
            mEndOfDataInCurrentObjectOnStack = 0;
			if ( failed )
			{
				int bufferLength = (int)(bufferEnd - bufferBegin);
				if ( bufferLength != 0)
				{
					ParserChar dataBufferError[21];
					size_t length = std::min(20, bufferLength);
					memcpy(dataBufferError, bufferBegin, length);
					dataBufferError[length] = '\0';
					if ( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
						ParserError::ERROR_TEXTDATA_PARSING_FAILED,
						0,
						dataBufferError))
					{
						return false;
					}
				}
			}
#ifdef GENERATEDSAXPARSER_VALIDATION
            if ( !failed )
            {
                if ( itemTypeValidationFunc != 0)
                {
                    ParserError::ErrorType simpleTypeValidationResult = (itemTypeValidationFunc)(typedValue);
                    if ( simpleTypeValidationResult != ParserError::SIMPLE_TYPE_VALIDATION_OK )
                    {
                        ParserChar msg[21];
                        Utils::fillErrorMsg(msg, bufferBegin, 20);
                        if( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
                            simpleTypeValidationResult,
                            0,
                            msg) )
                        {
                            return false;
                        }
                    }
                }
            }

            if ( listValidationFunc != 0)
            {
                if ( !failed )
                    (*wholeListLength)++;
                ParserError::ErrorType simpleTypeValidationResult = (listValidationFunc)(0, *wholeListLength);
                if ( simpleTypeValidationResult != ParserError::SIMPLE_TYPE_VALIDATION_OK )
                {
                    ParserChar msg[21];
                    Utils::fillErrorMsg(msg, bufferBegin, 20);
                    if( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
                        simpleTypeValidationResult,
                        0,
                        msg) )
                    {
                        return false;
                    }
                }
            }
#endif
            if ( !failed )
                (mImpl->*dataFunction)(&typedValue, 1);

		}
		return true;
	}


    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    template<class EnumType, class BaseType, EnumType EnumMapCount
    >
    bool ParserTemplate<DerivedClass, ImplClass>::dataEnumEnd(bool ( ImplClass::*dataFunction ) (const EnumType* data, size_t dataLength ),
        const std::pair<BaseType, EnumType>* enumMap,
        BaseType (*baseConversionFunctionPtr)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed),
        EnumType (*toEnum)( const ParserChar** buffer,
            const ParserChar* bufferEnd,
            bool& failed,
            const std::pair<BaseType, EnumType>* enumMap,
            BaseType (*baseConversionFunctionPtr)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed))
    )
    {
        if ( mLastIncompleteFragmentInCharacterData )
        {
            bool failed = false;
            const ParserChar* bufferBegin = mLastIncompleteFragmentInCharacterData;
            ParserChar* bufferEnd = mEndOfDataInCurrentObjectOnStack;
            EnumType typedValue = (*toEnum)(&bufferBegin, bufferEnd, failed, enumMap, baseConversionFunctionPtr);
            mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
            mLastIncompleteFragmentInCharacterData = 0;
            mEndOfDataInCurrentObjectOnStack = 0;
            if ( failed )
            {
                int bufferLength = (int)(bufferEnd - bufferBegin);
                if ( bufferLength != 0)
                {
                    ParserChar dataBufferError[21];
                    size_t length = std::min(20, bufferLength);
                    memcpy(dataBufferError, bufferBegin, length);
                    dataBufferError[length] = '\0';
                    if ( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
                        ParserError::ERROR_TEXTDATA_PARSING_FAILED,
                        0,
                        dataBufferError))
                    {
                        return false;
                    }
                }
            }
            else
            {
                (mImpl->*dataFunction)(&typedValue, 1);
            }

        }
        return true;
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::stringListDataEnd(
        stringListDataFunctionPtr stringListDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const ParserString*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( ParserString )
#endif
        )
    {
        return dataEnd<ParserString, Utils::toStringListItem>(stringListDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::boolDataEnd(
        boolDataFunctionPtr boolDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const bool*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( bool )
#endif
        )
    {
        return dataEnd<bool, Utils::toBool>(boolDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
    }

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::floatDataEnd(
        floatDataFunctionPtr floatDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const float*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( float )
#endif
        )
	{
		return dataEnd<float, Utils::toFloat>(floatDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::doubleDataEnd(
        doubleDataFunctionPtr doubleDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const double*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( double )
#endif
        )
    {
        return dataEnd<double, Utils::toDouble>(doubleDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
    }

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::sint8DataEnd(
        sint8DataFunctionPtr charDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const sint8*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint8 )
#endif
        )
	{
		return dataEnd<sint8, Utils::toSint8>(charDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::uint8DataEnd(
        uint8DataFunctionPtr unsignedCharDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const uint8*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint8 )
#endif
        )
	{
		return dataEnd<uint8, Utils::toUint8>(unsignedCharDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::sint16DataEnd(
        sint16DataFunctionPtr shortDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const sint16*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint16 )
#endif
        )
	{
		return dataEnd<sint16, Utils::toSint16>(shortDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::uint16DataEnd(
        uint16DataFunctionPtr unsignedShortDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const uint16*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint16 )
#endif
        )
	{
		return dataEnd<uint16, Utils::toUint16>(unsignedShortDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::sint32DataEnd(
        sint32DataFunctionPtr intDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const sint32*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint32 )
#endif
        )
	{
		return dataEnd<sint32, Utils::toSint32>(intDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::uint32DataEnd(
        uint32DataFunctionPtr unsignedIntDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const uint32*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint32 )
#endif
        )
	{
		return dataEnd<uint32, Utils::toUint32>(unsignedIntDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::sint64DataEnd(
        sint64DataFunctionPtr longDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const sint64*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint64 )
#endif
        )
	{
		return dataEnd<sint64, Utils::toSint64>(longDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::uint64DataEnd(
        uint64DataFunctionPtr unsignedLongDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*listValidationFunc)( const uint64*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint64 )
#endif
        )
	{
		return dataEnd<uint64, Utils::toUint64>(unsignedLongDataFunction
#ifdef GENERATEDSAXPARSER_VALIDATION
            , listValidationFunc, wholeListLength, itemTypeValidationFunc
#endif
            );
	}


	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::textData(const ParserChar* text,
															  size_t textLength)
	{
        if ( mIgnoreElements > 0 )
        {
            return true;
        }
        if ( mUnknownElements > 0 )
        {
            if ( mUnknownHandler != 0 )
            {
                return mUnknownHandler->textData( text, textLength );
            }
            else
            {
                return true;
            }
        }
        if ( mNamespaceElements > 0 )
        {
            return mActiveNamespaceHandler->textData( text, textLength );
        }

        if ( mElementDataStack.empty() )
            return false;
        ElementData elementData = mElementDataStack.back();
        typename ElementFunctionMap::const_iterator it;

        const ElementFunctionMap* functionMapToUse;
        if ( mCurrentElementFunctionMap )
            functionMapToUse = mCurrentElementFunctionMap;
        else
            functionMapToUse = &mElementFunctionMap;
		it = functionMapToUse->find(elementData.generatedElementHash);
		if ( it == functionMapToUse->end() )
			return true;
		const FunctionStruct& functions = it->second;

		if ( !functions.textDataFunction || !(static_cast<DerivedClass*>(this)->*functions.textDataFunction)(text, textLength) )
			return false;

		return true;
	}


	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::elementEnd(const ParserChar* elementName)
	{
        if ( !mNamespacesStack.empty() )
        {
            mNamespacesStack.top().counter--;
            if ( mNamespacesStack.top().counter == 0 )
            {
                mNamespacesStack.pop();
            }
        }
        if ( mIgnoreElements > 0 )
        {
            mIgnoreElements--;
            return true;
        }
        if ( mUnknownElements > 0 )
        {
            mUnknownElements--;
            if ( mUnknownHandler != 0 )
            {
                return mUnknownHandler->elementEnd( elementName );
            }
            else
            {
                return true;
            }
        }
        if ( mNamespaceElements > 0 )
        {
            mNamespaceElements--;
            StringHashPair hashPair = Utils::calculateStringHashWithNamespace( elementName );
            return mActiveNamespaceHandler->elementEnd( hashPair.second, elementName );
        }

        if ( mElementDataStack.empty() )
            return false;
        ElementData elementData = mElementDataStack.back();

        const ElementFunctionMap* functionMapToUse;
        if ( mCurrentElementFunctionMap )
            functionMapToUse = mCurrentElementFunctionMap;
        else
            functionMapToUse = &mElementFunctionMap;
        typename ElementFunctionMap::const_iterator it = functionMapToUse->find(elementData.generatedElementHash);
		if ( it == functionMapToUse->end() )
        {
            mElementDataStack.pop_back();
			return false;
        }
		const FunctionStruct& functions = it->second;

		if ( !functions.validateEndFunction || !(static_cast<DerivedClass*>(this)->*functions.validateEndFunction)())
        {
            mElementDataStack.pop_back();
			return false;
        }

        mElementDataStack.pop_back();

        if ( !functions.endFunction || !(static_cast<DerivedClass*>(this)->*functions.endFunction)() )
			return false;

		if ( elementData.validationData )
			mStackMemoryManager.deleteObject(); // validation data

		return true;
	}


	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::elementBegin( const ParserChar* elementName,
																   const ParserAttributes& attributes)
	{
        if ( (mIgnoreElements > 0 || mUnknownElements > 0 || mNamespaceElements > 0) 
            && !mNamespacesStack.empty() )
        {
            mNamespacesStack.top().counter++;
        }
        if ( mIgnoreElements > 0 )
        {
            mIgnoreElements++;
            return true;
        }
        if ( mUnknownElements > 0 )
        {
            mUnknownElements++;
            if ( mUnknownHandler != 0 )
            {
                return mUnknownHandler->elementBegin( elementName, attributes.attributes );
            }
            else
            {
                return true;
            }
        }
        if ( mNamespaceElements > 0 )
        {
            mNamespaceElements++;
            StringHashPair hashPair = Utils::calculateStringHashWithNamespace( elementName );
            return mActiveNamespaceHandler->elementBegin( hashPair.second, elementName, attributes.attributes );
        }

        if ( isDifferentNamespaceAllowed() )
        {
            parseNamespaceDeclarations( attributes );
        }
        ElementData newElementData;
        StringHashPair elementNsPair = Utils::calculateStringHashWithNamespace(elementName);
        newElementData.elementHash = elementNsPair.second;
        StringHash currentNsPrefix = elementNsPair.first;
        StringHash namespaceHash = 0;
        if ( !mNamespacesStack.empty() )
        {
            mNamespacesStack.top().counter++;
            typename NamespacePrefixesMap::iterator nsIter = mNamespacesStack.top().namespaces.find( currentNsPrefix );
            if ( nsIter != mNamespacesStack.top().namespaces.end() )
            {
                namespaceHash = nsIter->second;
            }
        }
        newElementData.generatedElementHash = 0;
        newElementData.typeID = 0;
        newElementData.validationData = 0;
        bool foundElementHash = findElementHash( newElementData );

        bool correctNamespace = false;
        if ( foundElementHash )
        {
            typename NamespacePrefixesMap::const_iterator nsFromMap = mElementToNamespaceMap.find( newElementData.generatedElementHash );
            if ( nsFromMap != mElementToNamespaceMap.end() && nsFromMap->second == namespaceHash )
            {
                correctNamespace = true;
            }
        }

        const ElementFunctionMap* functionMapToUse;
        if ( mCurrentElementFunctionMap )
            functionMapToUse = mCurrentElementFunctionMap;
        else
            functionMapToUse = &mElementFunctionMap;
        typename ElementFunctionMap::const_iterator it = functionMapToUse->end();
        if ( foundElementHash && (correctNamespace || mLaxNamespaceHandling) )
            it = functionMapToUse->find(newElementData.generatedElementHash);
		if ( it == functionMapToUse->end() )
		{
            INamespaceHandler* nsHandler = mNamespaceHandlers[ namespaceHash ];
            if ( nsHandler != 0 )
            {
                mActiveNamespaceHandler = nsHandler;
                mNamespaceElements = 1;
                return nsHandler->elementBegin( newElementData.elementHash, elementName, attributes.attributes );
            }
            if ( isXsAnyAllowed( newElementData.elementHash ) )
            {
                mUnknownElements = 1;
            }
            else
            {
                it = mElementFunctionMap.find(newElementData.elementHash);
                if ( it != mElementFunctionMap.end() && correctNamespace )
                {
                    mIgnoreElements = 1;
                }
                else
                {
                    mUnknownElements = 1;
                }
            }
            if ( mIgnoreElements )
            {
                return true;
            }
            if ( mUnknownElements )
            {
                if ( mUnknownHandler != 0 )
                {
                    return mUnknownHandler->elementBegin( elementName, attributes.attributes );
                }
                else
                {
			        if ( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
							         ParserError::ERROR_UNKNOWN_ELEMENT,
				                     0,
				                     elementName))
			        {
				        return false;
			        }
			        else
			        {
				        return true;
			        }
                }
            }
		}
		const FunctionStruct& functions = it->second;

		void* attributeData = 0;
		void* validationData = 0;
		if ( !functions.validateBeginFunction || !(static_cast<DerivedClass*>(this)->*functions.validateBeginFunction)(attributes, &attributeData, &validationData) )
        {
            // avoid leak
            if ( attributeData )
            {
                (static_cast<DerivedClass*>(this)->*functions.freeAttributesFunction)(attributeData);
                mStackMemoryManager.deleteObject(); // attribute data
            }
			return false;
        }

		bool success = (static_cast<DerivedClass*>(this)->*functions.beginFunction)(attributeData);
		if ( attributeData )
        {
            bool attrFreeSuccess = (static_cast<DerivedClass*>(this)->*functions.freeAttributesFunction)(attributeData);
			mStackMemoryManager.deleteObject(); // attribute data
            if ( !attrFreeSuccess )
            {
                return false;
            }
        }

		if ( success )
		{
            mElementDataStack.push_back(newElementData);
			newElementData.validationData = validationData;
		}
		return success;
	}



    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2StringList(const ParserChar* text,
        XSList<ParserString>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*itemTypeValidationFunc)(ParserString),
        StringHash elementHash,
        StringHash attributeHash
#endif
        )
    {
        return characterData2List<ParserString, Utils::toStringListItem>(text, list
#ifdef GENERATEDSAXPARSER_VALIDATION
            , itemTypeValidationFunc, elementHash, attributeHash
#endif
            );
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2BoolList(const ParserChar* text,
        XSList<bool>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*itemTypeValidationFunc)(bool),
        StringHash elementHash,
        StringHash attributeHash
#endif
        )
    {
        return characterData2List<bool, Utils::toBool>(text, list
#ifdef GENERATEDSAXPARSER_VALIDATION
            , itemTypeValidationFunc, elementHash, attributeHash
#endif
            );
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2FloatList(const ParserChar* text,
        XSList<float>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*itemTypeValidationFunc)(float),
        StringHash elementHash,
        StringHash attributeHash
#endif
        )
    {
        return characterData2List<float, Utils::toFloat>(text, list
#ifdef GENERATEDSAXPARSER_VALIDATION
            , itemTypeValidationFunc, elementHash, attributeHash
#endif
            );
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2DoubleList(const ParserChar* text,
        XSList<double>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*itemTypeValidationFunc)(double),
        StringHash elementHash,
        StringHash attributeHash
#endif
        )
    {
        return characterData2List<double, Utils::toDouble>(text, list
#ifdef GENERATEDSAXPARSER_VALIDATION
            , itemTypeValidationFunc, elementHash, attributeHash
#endif
            );
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint8List(const ParserChar* text,
        XSList<sint8>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*itemTypeValidationFunc)(sint8),
        StringHash elementHash,
        StringHash attributeHash
#endif
        )
    {
        return characterData2List<sint8, Utils::toSint8>(text, list
#ifdef GENERATEDSAXPARSER_VALIDATION
            , itemTypeValidationFunc, elementHash, attributeHash
#endif
            );
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint16List(const ParserChar* text,
        XSList<sint16>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*itemTypeValidationFunc)(sint16),
        StringHash elementHash,
        StringHash attributeHash
#endif
        )
    {
        return characterData2List<sint16, Utils::toSint16>(text, list
#ifdef GENERATEDSAXPARSER_VALIDATION
            , itemTypeValidationFunc, elementHash, attributeHash
#endif
            );
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint32List(const ParserChar* text,
        XSList<sint32>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*itemTypeValidationFunc)(sint32),
        StringHash elementHash,
        StringHash attributeHash
#endif
        )
    {
        return characterData2List<sint32, Utils::toSint32>(text, list
#ifdef GENERATEDSAXPARSER_VALIDATION
            , itemTypeValidationFunc, elementHash, attributeHash
#endif
            );
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint64List(const ParserChar* text,
        XSList<sint64>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*itemTypeValidationFunc)(sint64),
        StringHash elementHash,
        StringHash attributeHash
#endif
        )
    {
        return characterData2List<sint64, Utils::toSint64>(text, list
#ifdef GENERATEDSAXPARSER_VALIDATION
            , itemTypeValidationFunc, elementHash, attributeHash
#endif
            );
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint8List(const ParserChar* text,
        XSList<uint8>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*itemTypeValidationFunc)(uint8),
        StringHash elementHash,
        StringHash attributeHash
#endif
        )
    {
        return characterData2List<uint8, Utils::toUint8>(text, list
#ifdef GENERATEDSAXPARSER_VALIDATION
            , itemTypeValidationFunc, elementHash, attributeHash
#endif
            );
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint16List(const ParserChar* text,
        XSList<uint16>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*itemTypeValidationFunc)(uint16),
        StringHash elementHash,
        StringHash attributeHash
#endif
        )
    {
        return characterData2List<uint16, Utils::toUint16>(text, list
#ifdef GENERATEDSAXPARSER_VALIDATION
            , itemTypeValidationFunc, elementHash, attributeHash
#endif
            );
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint32List(const ParserChar* text,
        XSList<uint32>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*itemTypeValidationFunc)(uint32),
        StringHash elementHash,
        StringHash attributeHash
#endif
        )
    {
        return characterData2List<uint32, Utils::toUint32>(text, list
#ifdef GENERATEDSAXPARSER_VALIDATION
            , itemTypeValidationFunc, elementHash, attributeHash
#endif
            );
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint64List(const ParserChar* text,
        XSList<uint64>& list
#ifdef GENERATEDSAXPARSER_VALIDATION
        ,
        ParserError::ErrorType (*itemTypeValidationFunc)(uint64),
        StringHash elementHash,
        StringHash attributeHash
#endif
        )
    {
        return characterData2List<uint64, Utils::toUint64>(text, list
#ifdef GENERATEDSAXPARSER_VALIDATION
            , itemTypeValidationFunc, elementHash, attributeHash
#endif
            );
    }


    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    void ParserTemplate<DerivedClass, ImplClass>::registerNamespaceHandler( const StringHash& namespaceHash, INamespaceHandler* handler )
    {
        if ( handler && namespaceHash )
        {
            mNamespaceHandlers[ namespaceHash ] = handler;
        }
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    void ParserTemplate<DerivedClass, ImplClass>::unregisterNamespaceHandler( const StringHash& namespaceHash )
    {
        mNamespaceHandlers.erase( namespaceHash );
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    void ParserTemplate<DerivedClass, ImplClass>::parseNamespaceDeclarations( const ParserAttributes& attributes )
    {
        const ParserChar** attributeArray = attributes.attributes;
        if ( attributeArray )
        {
            NamespaceStackFrame stackFrame;
            if ( !mNamespacesStack.empty() )
            {
                const NamespaceStackFrame& topElement = mNamespacesStack.top();
                typename NamespacePrefixesMap::const_iterator it = topElement.namespaces.begin();
                for (; it != topElement.namespaces.end(); ++it)
                {
                    stackFrame.namespaces.insert(*it);
                }
            }
            while (true)
            {
                const ParserChar * attribute = *attributeArray;
                if ( !attribute )
                    break;
                StringHashPair hashPair = GeneratedSaxParser::Utils::calculateStringHashWithNamespace(attribute);
                attributeArray++;
                if ( !attributeArray )
                    return;
                const ParserChar* attributeValue = *attributeArray;
                attributeArray++;

                StringHash prefix = hashPair.first;
                StringHash name = hashPair.second;
                if ( prefix == 0 && name == XML_ATTRIBUTE_XMLNS_HASH )
                {
                    // set default namespace
                    stackFrame.namespaces[ 0 ] = GeneratedSaxParser::Utils::calculateStringHash( attributeValue );
                }
                else if ( prefix == XML_ATTRIBUTE_XMLNS_HASH )
                {
                    // set namespace with prefix
                    stackFrame.namespaces[ name ] = GeneratedSaxParser::Utils::calculateStringHash( attributeValue );
                }
            }
            if ( !stackFrame.namespaces.empty() )
            {
                mNamespacesStack.push( stackFrame );
            }
        }
    }

} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_COLLADAPARSERTEMPLATE_H__
