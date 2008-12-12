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
		static const size_t FLOATBUFFERSIZE = 1000;

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
		@param additionalText Additional text describing the error.*/
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
		@param additionalText Additional text describing the error.*/
		bool handleError(ParserError::Severity severity, 
        			     ParserError::ErrorType errorType, 
			             StringHash attributeHash, 
			             const ParserChar* additionalText);



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
		memcpy(data, &DataType::DEFAULT,  sizeof(DataType));
		*dataPtr = data;
		return data;
	}



} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_COLLADAPARSERAUTOGENBASE_H__
