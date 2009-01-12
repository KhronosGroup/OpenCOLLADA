/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_COLLADAPARSERAUTOGENBASE_H__
#define __GENERATEDSAXPARSER_COLLADAPARSERAUTOGENBASE_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserParser.h"
#include "GeneratedSaxParserStackMemoryManager.h"
#include "GeneratedSaxParserUtils.h"
#include "GeneratedSaxParserParserError.h"


#include <map>
#include <stack>



namespace GeneratedSaxParser
{
	class IErrorHandler;


	class ParserTemplateBase : public Parser	
	{
	public:

		static const size_t STACKSIZE = 1024*1024;

		/** Number of floats that fit into the buffer, used to convert text data to a float array.*/
		static const size_t TYPED_VALUES_BUFFER_SIZE = 1000;

		struct ElementData 
		{
			StringHash elementHash;
			StringHash combinedElementHash;
			void* validationData;
			void* userData;
		};


		typedef std::stack<ElementData> ElementDataStack;
		typedef std::map<StringHash, const char*> ElementNameMap;

	protected:
		ElementDataStack mElementDataStack;

		StackMemoryManager mStackMemoryManager;

		bool mValidate;

		ParserChar* mLastIncompleteFragmentInChararterData;

		ElementNameMap mHashNameMap;

	private:
		IErrorHandler* mErrorHandler;

	public:
		ParserTemplateBase(IErrorHandler* errorHandler)
			: mStackMemoryManager(STACKSIZE),
			mLastIncompleteFragmentInChararterData(0),
			mErrorHandler(errorHandler){}
		virtual ~ParserTemplateBase(){};

		/** Returns the element or attribute name that corresponds to @a hash. Null is returned,
		if no corresponding name could be found.*/
		const char* getNameByStringHash(const StringHash& hash)const;


	protected:
		/** Converts the first string representing a float within a ParserChar buffer with prefixedBuffer 
		prefixed to a float and advances the character pointer to the first position after the last 
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached 
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		float toFloatPrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing a double within a ParserChar buffer with prefixedBuffer 
		prefixed to a double and advances the character pointer to the first position after the last 
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached 
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		double toDoublePrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing a char within a ParserChar buffer with prefixedBuffer 
		prefixed to a char and advances the character interpreted to the first position after the last 
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached 
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		char toCharPrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing an unsigned char within a ParserChar buffer with prefixedBuffer 
		prefixed to an unsigned char and advances the character char to the first position after the last 
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached 
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		unsigned char toUnsignedCharPrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing a short within a ParserChar buffer with prefixedBuffer 
		prefixed to a short and advances the character interpreted to the first position after the last 
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached 
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		short toShortPrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing an unsigned short within a ParserChar buffer with prefixedBuffer 
		prefixed to an unsigned short and advances the character short to the first position after the last 
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached 
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		unsigned short toUnsignedShortPrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing an integer within a ParserChar buffer with prefixedBuffer 
		prefixed to an integer and advances the character pointer to the first position after the last 
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached 
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		int toIntPrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing an unsigned integer within a ParserChar buffer with prefixedBuffer 
		prefixed to an unsigned integer and advances the character pointer to the first position after the last 
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached 
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		unsigned int toUnsignedIntPrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing an integer within a ParserChar buffer with prefixedBuffer 
		prefixed to an integer and advances the character pointer to the first position after the last 
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached 
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		long toLongPrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing an unsigned integer within a ParserChar buffer with prefixedBuffer 
		prefixed to an unsigned integer and advances the character pointer to the first position after the last 
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached 
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		unsigned long toUnsignedLongPrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing a long long within a ParserChar buffer with prefixedBuffer 
		prefixed to a long long and advances the character pointer to the first position after the last 
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached 
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		long long toLongLongPrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing an unsigned long long  within a ParserChar buffer with prefixedBuffer 
		prefixed to an unsigned long long and advances the character pointer to the first position after the last 
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached 
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		unsigned long long toUnsignedLongLongPrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing a bool within a ParserChar buffer with prefixedBuffer 
		prefixed to a bool and advances the character interpreted to the first position after the last 
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached 
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		bool toBoolPrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Creates a new object of type @a DataType and sets the member variables to the default ones, using 
		a static member of type @a DataType called DEFAULT. @a data is set to the created object and @a dataPtr
		to the address of the created object.
		@param DataType The type of the object, that should be created. Must have a static member of type @ DataType 
		called DEFAULT.
		@param data Will be set to the location of the created object.
		@param dataPtr Will be set to the address of the created object.*/
		template<class DataType>
		DataType* newData(void** dataPtr);


		/** Passes an error with the specified properties to the error handler.
		@param severity The severity of the error.
		@param errorType The error type of the error.
		@param elementHash The hash of the element the error occurred in.
		@param attributeHash The hash of the element the error occurred in.
		@param additionalText Additional text describing the error.
        @return True when abort required, false when continue is possible.
        */
		bool handleError(ParserError::Severity severity, 
						 ParserError::ErrorType errorType, 
						 StringHash elementHash, 
						 StringHash attributeHash, 
						 const ParserChar* additionalText);


		/** Passes an error with the specified properties to the error handler. The last opened element
		is passed to the error handler.
		@param severity The severity of the error.
		@param errorType The error type of the error.
		@param attributeHash The hash of the element the error occurred in.
		@param additionalText Additional text describing the error.
        @return True when abort required, false when continue is possible.
        */
		bool handleError(ParserError::Severity severity, 
        			     ParserError::ErrorType errorType, 
			             StringHash attributeHash, 
			             const ParserChar* additionalText);



        /**
         * Converts buffer representing a xs:list to a buffer containing the list as C++ item type.
         * Input buffer must contain all data from XML file. This method does not support partial buffers.
         * @tparam DataType C++ list item type.
         * @tparam toData Function which does actual conversion.
         * @param text Buffer containing xs:list as text.
         * @param textLength Length of input buffer.
         * @param list Output parameter. Must be freed by caller.
         * @return True on success, false on failure.
         */
        template<typename DataType, 
            DataType (*toData)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)>
        bool characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list);

        /** @see characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list). */
        bool characterData2BoolData(const ParserChar* text, size_t textLength, XSList<bool>& list);
        /** @see characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list). */
        bool characterData2FloatData(const ParserChar* text, size_t textLength, XSList<float>& list);
        /** @see characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list). */
        bool characterData2DoubleData(const ParserChar* text, size_t textLength, XSList<double>& list);

        /** @see characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list). */
        bool characterData2CharData(const ParserChar* text, size_t textLength, XSList<char>& list);
        /** @see characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list). */
        bool characterData2ShortData(const ParserChar* text, size_t textLength, XSList<short>& list);
        /** @see characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list). */
        bool characterData2IntData(const ParserChar* text, size_t textLength, XSList<int>& list);
        /** @see characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list). */
        bool characterData2LongData(const ParserChar* text, size_t textLength, XSList<long>& list);
        /** @see characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list). */
        bool characterData2LongLongData(const ParserChar* text, size_t textLength, XSList<long long>& list);

        /** @see characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list). */
        bool characterData2UnsignedCharData(const ParserChar* text, size_t textLength, XSList<unsigned char>& list);
        /** @see characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list). */
        bool characterData2UnsignedShortData(const ParserChar* text, size_t textLength, XSList<unsigned short>& list);
        /** @see characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list). */
        bool characterData2UnsignedIntData(const ParserChar* text, size_t textLength, XSList<unsigned int>& list);
        /** @see characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list). */
        bool characterData2UnsignedLongData(const ParserChar* text, size_t textLength, XSList<unsigned long>& list);
        /** @see characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list). */
        bool characterData2UnsignedLongLongData(const ParserChar* text, size_t textLength, XSList<unsigned long long>& list);

    protected:
	private:
		/** Disable default copy ctor. */
		ParserTemplateBase( const ParserTemplateBase& pre );
		/** Disable default assignment operator. */
		const ParserTemplateBase& operator= ( const ParserTemplateBase& pre );

		template<class DataType,
				 DataType (*toData)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)>
		DataType toDataPrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

	};



	template<class DataType>
	DataType* ParserTemplateBase::newData(void** dataPtr)
	{
		DataType* data = (DataType*)mStackMemoryManager.newObject(sizeof(DataType));
		memcpy(data, &DataType::DEFAULT, sizeof(DataType));
		*dataPtr = data;
		return data;
	}


    template<class DataType, 
        DataType (*toData)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)>
    bool ParserTemplateBase::characterData2Data(const ParserChar* text, size_t textLength, XSList<DataType>& list)
    {
        size_t bufferSize = textLength / 2;
        DataType* typedBuffer = (DataType*)mStackMemoryManager.newObject(bufferSize * sizeof(DataType));

        size_t dataBufferIndex = 0;
        const ParserChar* dataBufferPos = text;
        const ParserChar* bufferEnd = text + textLength;

        bool failed = false;

        while ( !failed )
        {
            DataType dataValue = toData(&dataBufferPos, bufferEnd, failed);
            if ( !failed )
            {
                typedBuffer[dataBufferIndex] = dataValue;
                ++dataBufferIndex;
                if ( dataBufferIndex == bufferSize )
                {
                    mStackMemoryManager.growObject(bufferSize);
                    bufferSize *= 2;
                }
            }
        }

        if ( dataBufferPos == bufferEnd )
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

            ParserChar dataBufferError[21];
            size_t length = std::min(20, (int)(bufferEnd-dataBufferPos));
            memcpy(dataBufferError, dataBufferPos, length);
            dataBufferError[length] = '\0';
            if ( handleError(ParserError::SEVERITY_ERROR, 
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

} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_COLLADAPARSERAUTOGENBASE_H__
