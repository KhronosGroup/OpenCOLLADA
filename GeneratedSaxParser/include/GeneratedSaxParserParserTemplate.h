/*
    Copyright (c) 2008 NetAllied Systems GmbH

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

		typedef std::map<StringHash, FunctionStruct> ElementFunctionMap;


	protected:
		ElementFunctionMap mElementFunctionMap;
		ImplClass* mImpl;

	private:
		/** Number of elements that have been opened and should be ignored. Use for unknown elements.*/
		size_t mIgnoreElements;


	public:
		ParserTemplate(ImplClass* impl, IErrorHandler* errorHandler)
			:
		  ParserTemplateBase(errorHandler),
			  mImpl(impl),
			  mIgnoreElements(0)
		  {};
		virtual ~ParserTemplate(){};

		/** Sets the object, that should receive all the callbacks from now on.*/
		void setCallbackObject(ImplClass* impl){ mImpl = impl; }

	public:
		bool elementBegin(const ParserChar* elementName, const ParserAttributes& attributes );

		bool elementEnd(const ParserChar* elementName );

		bool textData(const ParserChar* text, size_t textLength);

    protected:
        virtual bool findElementHash( ElementData& elementData ) = 0;


	protected:
		template<class DataType,
				 DataType (*toData)( const ParserChar**, const ParserChar*, bool& ),
				 DataType (ParserTemplateBase::*toDataWithPrefix)( const ParserChar*, const ParserChar*, const ParserChar**, const ParserChar*, bool& )>
		bool characterData2Data(const ParserChar* text,
                size_t textLength,
                bool ( ImplClass::*dataFunction ) ( const DataType*, size_t ),
                ParserError::ErrorType (*listValidationFunc)( const DataType*, size_t ) = 0,
                size_t* wholeListLength = 0,
                ParserError::ErrorType (*itemTypeValidationFunc)( DataType ) = 0
                );

        bool characterData2BoolData(const ParserChar* text,
            size_t textLength,
            boolDataFunctionPtr boolDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const bool*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( bool ) = 0
            );

		bool characterData2FloatData( const ParserChar* text,
            size_t textLength,
            floatDataFunctionPtr floatDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const float*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( float ) = 0
            );
		bool characterData2DoubleData( const ParserChar* text,
            size_t textLength,
            doubleDataFunctionPtr doubleDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const double*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( double ) = 0
            );

		bool characterData2Sint8Data( const ParserChar* text,
            size_t textLength,
            sint8DataFunctionPtr charDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const sint8*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint8 ) = 0
            );
		bool characterData2Uint8Data( const ParserChar* text,
            size_t textLength,
            uint8DataFunctionPtr unsignedCharDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const uint8*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint8 ) = 0
            );

		bool characterData2Sint16Data( const ParserChar* text,
            size_t textLength,
            sint16DataFunctionPtr shortDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const sint16*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint16 ) = 0
            );
		bool characterData2Uint16Data( const ParserChar* text,
            size_t textLength,
            uint16DataFunctionPtr unsignedShortDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const uint16*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint16 ) = 0
            );

		bool characterData2Sint32Data( const ParserChar* text,
            size_t textLength,
            sint32DataFunctionPtr intDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const sint32*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint32 ) = 0
            );
		bool characterData2Uint32Data( const ParserChar* text,
            size_t textLength,
            uint32DataFunctionPtr unsignedIntDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const uint32*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint32 ) = 0
            );

		bool characterData2Sint64Data( const ParserChar* text,
            size_t textLength,
            sint64DataFunctionPtr longDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const sint64*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint64 ) = 0
            );
		bool characterData2Uint64Data( const ParserChar* text,
            size_t textLength,
            uint64DataFunctionPtr unsignedLongDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const uint64*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint64 ) = 0
            );

        template<class DataType, DataType (*toData)( const ParserChar**, const ParserChar*, bool& )>
		bool dataEnd(
            bool ( ImplClass::*dataFunction ) ( const DataType*, size_t ),
            ParserError::ErrorType (*listValidationFunc)( const DataType*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( DataType ) = 0
            );

        bool boolDataEnd(
            boolDataFunctionPtr boolDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const bool*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( bool ) = 0
            );
		bool floatDataEnd(
            floatDataFunctionPtr floatDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const float*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( float ) = 0
            );
        bool doubleDataEnd(
            doubleDataFunctionPtr doubleDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const double*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( double ) = 0
            );

		bool sint8DataEnd(
            sint8DataFunctionPtr charDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const sint8*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint8 ) = 0
            );
		bool uint8DataEnd(
            uint8DataFunctionPtr unsignedCharDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const uint8*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint8 ) = 0
            );

		bool sint16DataEnd(
            sint16DataFunctionPtr shortDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const sint16*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint16 ) = 0
            );
		bool uint16DataEnd(
            uint16DataFunctionPtr unsignedShortDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const uint16*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint16 ) = 0
            );

		bool sint32DataEnd(
            sint32DataFunctionPtr intDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const sint32*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint32 ) = 0
            );
		bool uint32DataEnd(
            uint32DataFunctionPtr unsignedIntDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const uint32*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint32 ) = 0
            );

		bool sint64DataEnd(
            sint64DataFunctionPtr longDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const sint64*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( sint64 ) = 0
            );
		bool uint64DataEnd(
            uint64DataFunctionPtr unsignedLongDataFunction,
            ParserError::ErrorType (*listValidationFunc)( const uint64*, size_t ) = 0,
            size_t* wholeListLength = 0,
            ParserError::ErrorType (*itemTypeValidationFunc)( uint64 ) = 0
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
            bool characterData2List(const ParserChar* text, XSList<DataType>& list,
                ParserError::ErrorType (*itemTypeValidationFunc)(DataType) = 0,
                StringHash elementHash = 0,
                StringHash attributeHash = 0);

        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2BoolList(const ParserChar* text, XSList<bool>& list,
            ParserError::ErrorType (*itemTypeValidationFunc)(bool) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0);
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2FloatList(const ParserChar* text, XSList<float>& list,
            ParserError::ErrorType (*itemTypeValidationFunc)(float) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0);
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2DoubleList(const ParserChar* text, XSList<double>& list,
            ParserError::ErrorType (*itemTypeValidationFunc)(double) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0);

        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Sint8List(const ParserChar* text, XSList<sint8>& list,
            ParserError::ErrorType (*itemTypeValidationFunc)(sint8) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0);
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Sint16List(const ParserChar* text, XSList<sint16>& list,
            ParserError::ErrorType (*itemTypeValidationFunc)(sint16) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0);
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Sint32List(const ParserChar* text, XSList<sint32>& list,
            ParserError::ErrorType (*itemTypeValidationFunc)(sint32) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0);
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Sint64List(const ParserChar* text, XSList<sint64>& list,
            ParserError::ErrorType (*itemTypeValidationFunc)(sint64) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0);

        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Uint8List(const ParserChar* text, XSList<uint8>& list,
            ParserError::ErrorType (*itemTypeValidationFunc)(uint8) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0);
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Uint16List(const ParserChar* text, XSList<uint16>& list,
            ParserError::ErrorType (*itemTypeValidationFunc)(uint16) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0);
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Uint32List(const ParserChar* text, XSList<uint32>& list,
            ParserError::ErrorType (*itemTypeValidationFunc)(uint32) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0);
        /** @see characterData2List(const ParserChar* text, XSList<DataType>& list). */
        bool characterData2Uint64List(const ParserChar* text, XSList<uint64>& list,
            ParserError::ErrorType (*itemTypeValidationFunc)(uint64) = 0,
            StringHash elementHash = 0,
            StringHash attributeHash = 0);

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
		     DataType (*toData)( const ParserChar**, const ParserChar*, bool& ),
			 DataType (ParserTemplateBase::*toDataWithPrefix)( const ParserChar*, const ParserChar*, const ParserChar**, const ParserChar*, bool& )>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Data(
            const ParserChar* text,
            size_t textLength,
            bool ( ImplClass::*dataFunction ) ( const DataType*, size_t ),
            ParserError::ErrorType (*listValidationFunc)( const DataType*, size_t ),
            size_t* wholeListLength,
            ParserError::ErrorType (*itemTypeValidationFunc)( DataType )
            )
	{
		size_t dataBufferIndex = 0;
		const ParserChar* dataBufferPos = text;
		const ParserChar* bufferEnd = text + textLength;
		const ParserChar* lastDataBufferIndex = dataBufferPos;

		// handle incomplete fragment from last call to textData
		DataType fragmentData = 0;
		if ( mLastIncompleteFragmentInCharacterData )
		{
			bool failed = false;

			fragmentData = (this->*toDataWithPrefix)(mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, &dataBufferPos, bufferEnd, failed);
			// TODO we need to copy the old mLastIncompleteFragmentInCharacterData into the new as well
			mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
			mLastIncompleteFragmentInCharacterData = 0;
            mEndOfDataInCurrentObjectOnStack = 0;
			if ( failed )
			{
				if ( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
					             ParserError::ERROR_TEXTDATA_PARSING_FAILED,
					             0,
					             mLastIncompleteFragmentInCharacterData))
				{
					return false;
				}
				else
				{
                    // TODO check if this is correct
					return true;
				}
			}
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
                        return false;
                    }
                }
            }
			dataBufferIndex = 1;
		}

        // we only need to start the general parsing 
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
				    typedBuffer[dataBufferIndex] = dataValue;
				    ++dataBufferIndex;
				    if ( dataBufferIndex == TYPED_VALUES_BUFFER_SIZE )
				    {
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
                                    return false;
                                }
                            }
                        }
					    (mImpl->*dataFunction)(typedBuffer, dataBufferIndex);
					    dataBufferIndex = 0;
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
                                return false;
                            }
                        }
                    }
				    (mImpl->*dataFunction)(typedBuffer, dataBufferIndex);
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
			mLastIncompleteFragmentInCharacterData = (ParserChar*)mStackMemoryManager.newObject(fragmentSize + 1);
			memcpy(mLastIncompleteFragmentInCharacterData, lastDataBufferIndex, fragmentSize);
            mEndOfDataInCurrentObjectOnStack = mLastIncompleteFragmentInCharacterData + fragmentSize;

			return true;

		}
		else
		{
			//something went wrong while parsing
			// we abort and don't pass the typed array
			mStackMemoryManager.deleteObject();  //typedBuffer
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
        if ( mLastIncompleteFragmentInCharacterData )
        {
            bool failed = false;

            fragmentData = (static_cast<DerivedClass*>(this)->*toEnumDataWithPrefix)(mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, &dataBufferPos, bufferEnd, failed, enumMap, baseConversionFunctionPtr);
            mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInCharacterData
            mLastIncompleteFragmentInCharacterData = 0;
            mEndOfDataInCurrentObjectOnStack = 0;
            if ( failed )
            {
                if ( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
                    ParserError::ERROR_TEXTDATA_PARSING_FAILED,
                    0,
                    mLastIncompleteFragmentInCharacterData))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            dataBufferIndex = 1;
        }

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
                }
            }
        }

        if ( dataBufferPos == bufferEnd )
        {
            // we reached the end of the buffer while parsing.
            // we pass the already parsed typed values
            // we need to store the not parsed fraction
            if ( dataBufferIndex > 0)
                (mImpl->*dataFunction)(typedBuffer, dataBufferIndex);
            mStackMemoryManager.deleteObject();
            size_t fragmentSize = (dataBufferPos - lastDataBufferIndex)*sizeof(ParserChar);
            mLastIncompleteFragmentInCharacterData = (ParserChar*)mStackMemoryManager.newObject(fragmentSize + 1);
            memcpy(mLastIncompleteFragmentInCharacterData, lastDataBufferIndex, fragmentSize);
            mEndOfDataInCurrentObjectOnStack = mLastIncompleteFragmentInCharacterData + fragmentSize;

            return true;

        }
        else
        {
            //something went wrong while parsing
            // we abort and don't pass the typed array
            mStackMemoryManager.deleteObject();  //typedBuffer
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
            XSList<DataType>& list,
            ParserError::ErrorType (*itemTypeValidationFunc)(DataType),
            StringHash elementHash,
            StringHash attributeHash)
    {
        size_t bufferSize = 1 * sizeof(DataType); // TODO find a sane start buffer size and make it a constant
        DataType* typedBuffer = (DataType*)mStackMemoryManager.newObject(bufferSize);

        size_t dataBufferIndex = 0;
        const ParserChar* dataBufferPos = text;

        bool failed = false;

        while ( !failed )
        {
            // just for error handling of item type validation
            const ParserChar* currentElementPtr = dataBufferPos;
            DataType dataValue = toData(&dataBufferPos, failed);
            if ( !failed )
            {
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
                typedBuffer[dataBufferIndex] = dataValue;
                ++dataBufferIndex;
                if ( (dataBufferIndex * sizeof(DataType)) == bufferSize )
                {
                    mStackMemoryManager.growObject(bufferSize);
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
            if ( handleError(ParserError::SEVERITY_ERROR_NONCRITICAL,
                ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,
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
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2FloatData(
        const ParserChar* text,
        size_t textLength,
        floatDataFunctionPtr floatDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const float*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( float )
        )
	{
		return characterData2Data<float, Utils::toFloat, &ParserTemplateBase::toFloatPrefix>(text, textLength, floatDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}


	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2DoubleData(
        const ParserChar* text,
        size_t textLength,
        doubleDataFunctionPtr doubleDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const double*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( double )
        )
	{
		return characterData2Data<double, Utils::toDouble, &ParserTemplateBase::toDoublePrefix>(text, textLength, doubleDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}


	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint8Data(
        const ParserChar* text,
        size_t textLength,
        sint8DataFunctionPtr charDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const sint8*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint8 )
        )
	{
		return characterData2Data<sint8, Utils::toSint8, &ParserTemplateBase::toSint8Prefix>(text, textLength, charDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint8Data(
        const ParserChar* text,
        size_t textLength,
        uint8DataFunctionPtr unsignedCharDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const uint8*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint8 )
        )
	{
		return characterData2Data<uint8, Utils::toUint8, &ParserTemplateBase::toUint8Prefix>(text, textLength, unsignedCharDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint16Data(
        const ParserChar* text,
        size_t textLength,
        sint16DataFunctionPtr shortDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const sint16*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint16 )
        )
	{
		return characterData2Data<sint16, Utils::toSint16, &ParserTemplateBase::toSint16Prefix>(text, textLength, shortDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint16Data(
        const ParserChar* text,
        size_t textLength,
        uint16DataFunctionPtr unsignedShortDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const uint16*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint16 )
        )
	{
		return characterData2Data<uint16, Utils::toUint16, &ParserTemplateBase::toUint16Prefix>(text, textLength, unsignedShortDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint32Data(
        const ParserChar* text,
        size_t textLength,
        sint32DataFunctionPtr intDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const sint32*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint32 )
        )
	{
		return characterData2Data<sint32, Utils::toSint32, &ParserTemplateBase::toSint32Prefix>(text, textLength, intDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint32Data(
        const ParserChar* text,
        size_t textLength,
        uint32DataFunctionPtr unsignedIntDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const uint32*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint32 )
        )
	{
		return characterData2Data<uint32, Utils::toUint32, &ParserTemplateBase::toUint32Prefix>(text, textLength, unsignedIntDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint64Data(
        const ParserChar* text,
        size_t textLength,
        sint64DataFunctionPtr longDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const sint64*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint64 )
        )
	{
		return characterData2Data<sint64, Utils::toSint64, &ParserTemplateBase::toSint64Prefix>(text, textLength, longDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint64Data(
        const ParserChar* text,
        size_t textLength,
        uint64DataFunctionPtr unsignedLongDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const uint64*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint64 )
        )
	{
		return characterData2Data<uint64, Utils::toUint64, &ParserTemplateBase::toUint64Prefix>(text, textLength, unsignedLongDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2BoolData(
        const ParserChar* text,
        size_t textLength,
        boolDataFunctionPtr boolDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const bool*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( bool )
        )
	{
		return characterData2Data<bool, Utils::toBool, &ParserTemplateBase::toBoolPrefix>(text, textLength, boolDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}


	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	template<class DataType, DataType (*toData)( const ParserChar**, const ParserChar*, bool& )>
	bool ParserTemplate<DerivedClass, ImplClass>::dataEnd(
        bool ( ImplClass::*dataFunction ) ( const DataType*, size_t ),
        ParserError::ErrorType (*listValidationFunc)( const DataType*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( DataType )
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
			else
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

                if ( listValidationFunc != 0)
                {
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

				(mImpl->*dataFunction)(&typedValue, 1);
			}

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
    bool ParserTemplate<DerivedClass, ImplClass>::boolDataEnd(
        boolDataFunctionPtr boolDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const bool*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( bool )
        )
    {
        return dataEnd<bool, Utils::toBool>(boolDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
    }

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::floatDataEnd(
        floatDataFunctionPtr floatDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const float*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( float )
        )
	{
		return dataEnd<float, Utils::toFloat>(floatDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::doubleDataEnd(
        doubleDataFunctionPtr doubleDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const double*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( double )
        )
    {
        return dataEnd<double, Utils::toDouble>(doubleDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
    }

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::sint8DataEnd(
        sint8DataFunctionPtr charDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const sint8*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint8 )
        )
	{
		return dataEnd<sint8, Utils::toSint8>(charDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::uint8DataEnd(
        uint8DataFunctionPtr unsignedCharDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const uint8*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint8 )
        )
	{
		return dataEnd<uint8, Utils::toUint8>(unsignedCharDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::sint16DataEnd(
        sint16DataFunctionPtr shortDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const sint16*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint16 )
        )
	{
		return dataEnd<sint16, Utils::toSint16>(shortDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::uint16DataEnd(
        uint16DataFunctionPtr unsignedShortDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const uint16*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint16 )
        )
	{
		return dataEnd<uint16, Utils::toUint16>(unsignedShortDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::sint32DataEnd(
        sint32DataFunctionPtr intDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const sint32*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint32 )
        )
	{
		return dataEnd<sint32, Utils::toSint32>(intDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::uint32DataEnd(
        uint32DataFunctionPtr unsignedIntDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const uint32*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint32 )
        )
	{
		return dataEnd<uint32, Utils::toUint32>(unsignedIntDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::sint64DataEnd(
        sint64DataFunctionPtr longDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const sint64*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( sint64 )
        )
	{
		return dataEnd<sint64, Utils::toSint64>(longDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::uint64DataEnd(
        uint64DataFunctionPtr unsignedLongDataFunction,
        ParserError::ErrorType (*listValidationFunc)( const uint64*, size_t ),
        size_t* wholeListLength,
        ParserError::ErrorType (*itemTypeValidationFunc)( uint64 )
        )
	{
		return dataEnd<uint64, Utils::toUint64>(unsignedLongDataFunction, listValidationFunc, wholeListLength, itemTypeValidationFunc);
	}


	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::textData(const ParserChar* text,
															  size_t textLength)
	{
		if ( mIgnoreElements > 0)
			return true;

		if ( mElementDataStack.empty() )
			return false;
		ElementData elementData = mElementDataStack.back();

		typename ElementFunctionMap::iterator it;
		it = mElementFunctionMap.find(elementData.generatedElementHash);
		if ( it == mElementFunctionMap.end() )
			return true;
		FunctionStruct& functions = it->second;

		if ( !functions.textDataFunction || !(static_cast<DerivedClass*>(this)->*functions.textDataFunction)(text, textLength) )
			return false;

		return true;
	}


	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::elementEnd(const ParserChar* elementName)
	{
		if ( mIgnoreElements > 0)
		{
			--mIgnoreElements;
			return true;
		}

		if ( mElementDataStack.empty() )
			return false;
		ElementData elementData = mElementDataStack.back();

		typename ElementFunctionMap::iterator it = mElementFunctionMap.find(elementData.generatedElementHash);
		if ( it == mElementFunctionMap.end() )
			return false;
		FunctionStruct& functions = it->second;

		if ( !functions.validateEndFunction || !(static_cast<DerivedClass*>(this)->*functions.validateEndFunction)())
			return false;

		if ( !functions.endFunction || !(static_cast<DerivedClass*>(this)->*functions.endFunction)() )
			return false;

		if ( elementData.validationData )
			mStackMemoryManager.deleteObject(); // validation data
		mElementDataStack.pop_back();

		return true;
	}


	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::elementBegin( const ParserChar* elementName,
																   const ParserAttributes& attributes)
	{
		if ( mIgnoreElements > 0)
		{
			++mIgnoreElements;
			return true;
		}

        ElementData newElementData;
        newElementData.elementHash = Utils::calculateStringHash(elementName);
        newElementData.generatedElementHash = 0;
        newElementData.typeID = 0;
        newElementData.validationData = 0;
        bool foundElementHash = findElementHash( newElementData );

        typename ElementFunctionMap::iterator it = mElementFunctionMap.end();
        if ( foundElementHash )
            it = mElementFunctionMap.find(newElementData.generatedElementHash);
		if ( it == mElementFunctionMap.end() )
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
				mIgnoreElements = 1;
				return true;
			}
		}
		FunctionStruct& functions = it->second;

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
			newElementData.validationData = validationData;
			mElementDataStack.push_back(newElementData);
		}
		return success;
	}



    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2BoolList(const ParserChar* text,
        XSList<bool>& list,
        ParserError::ErrorType (*itemTypeValidationFunc)(bool),
        StringHash elementHash,
        StringHash attributeHash)
    {
        return characterData2List<bool, Utils::toBool>(text, list, itemTypeValidationFunc, elementHash, attributeHash);
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2FloatList(const ParserChar* text,
        XSList<float>& list,
        ParserError::ErrorType (*itemTypeValidationFunc)(float),
        StringHash elementHash,
        StringHash attributeHash)
    {
        return characterData2List<float, Utils::toFloat>(text, list, itemTypeValidationFunc, elementHash, attributeHash);
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2DoubleList(const ParserChar* text,
        XSList<double>& list,
        ParserError::ErrorType (*itemTypeValidationFunc)(double),
        StringHash elementHash,
        StringHash attributeHash)
    {
        return characterData2List<double, Utils::toDouble>(text, list, itemTypeValidationFunc, elementHash, attributeHash);
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint8List(const ParserChar* text,
        XSList<sint8>& list,
        ParserError::ErrorType (*itemTypeValidationFunc)(sint8),
        StringHash elementHash,
        StringHash attributeHash)
    {
        return characterData2List<sint8, Utils::toSint8>(text, list, itemTypeValidationFunc, elementHash, attributeHash);
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint16List(const ParserChar* text,
        XSList<sint16>& list,
        ParserError::ErrorType (*itemTypeValidationFunc)(sint16),
        StringHash elementHash,
        StringHash attributeHash)
    {
        return characterData2List<sint16, Utils::toSint16>(text, list, itemTypeValidationFunc, elementHash, attributeHash);
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint32List(const ParserChar* text,
        XSList<sint32>& list,
        ParserError::ErrorType (*itemTypeValidationFunc)(sint32),
        StringHash elementHash,
        StringHash attributeHash)
    {
        return characterData2List<sint32, Utils::toSint32>(text, list, itemTypeValidationFunc, elementHash, attributeHash);
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Sint64List(const ParserChar* text,
        XSList<sint64>& list,
        ParserError::ErrorType (*itemTypeValidationFunc)(sint64),
        StringHash elementHash,
        StringHash attributeHash)
    {
        return characterData2List<sint64, Utils::toSint64>(text, list, itemTypeValidationFunc, elementHash, attributeHash);
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint8List(const ParserChar* text,
        XSList<uint8>& list,
        ParserError::ErrorType (*itemTypeValidationFunc)(uint8),
        StringHash elementHash,
        StringHash attributeHash)
    {
        return characterData2List<uint8, Utils::toUint8>(text, list, itemTypeValidationFunc, elementHash, attributeHash);
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint16List(const ParserChar* text,
        XSList<uint16>& list,
        ParserError::ErrorType (*itemTypeValidationFunc)(uint16),
        StringHash elementHash,
        StringHash attributeHash)
    {
        return characterData2List<uint16, Utils::toUint16>(text, list, itemTypeValidationFunc, elementHash, attributeHash);
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint32List(const ParserChar* text,
        XSList<uint32>& list,
        ParserError::ErrorType (*itemTypeValidationFunc)(uint32),
        StringHash elementHash,
        StringHash attributeHash)
    {
        return characterData2List<uint32, Utils::toUint32>(text, list, itemTypeValidationFunc, elementHash, attributeHash);
    }

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::characterData2Uint64List(const ParserChar* text,
        XSList<uint64>& list,
        ParserError::ErrorType (*itemTypeValidationFunc)(uint64),
        StringHash elementHash,
        StringHash attributeHash)
    {
        return characterData2List<uint64, Utils::toUint64>(text, list, itemTypeValidationFunc, elementHash, attributeHash);
    }


} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_COLLADAPARSERTEMPLATE_H__
