/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
#include <string.h> // needed for memcpy() and gcc



namespace GeneratedSaxParser
{
	class IErrorHandler;


	class ParserTemplateBase : public Parser
	{
	public:

		static const size_t STACK_SIZE = 1024*1024;

		/** Number of floats that fit into the buffer, used to convert text data to a float array.*/
		static const size_t TYPED_VALUES_BUFFER_SIZE = 1000;

		struct ElementData
		{
			StringHash elementHash;
			StringHash generatedElementHash;
            size_t typeID;
			void* validationData;
		};


        // We cannot use std::stack because we need access to elements somewhere in the middle.
        // deque is the container std::stack uses by default.
		typedef std::deque<ElementData> ElementDataStack;
		typedef std::map<StringHash, const char*> ElementNameMap;

	protected:
		ElementDataStack mElementDataStack;

		StackMemoryManager mStackMemoryManager;

        /** Stack containing validation data only. */
        StackMemoryManager mValidationDataStack;

        /** Indicates if input file shall be validated while parsed. */
        bool mValidate;

        /**
         * Points to begin of object on memory manager stack.
         * @see mStackMemoryManager.
         */
		ParserChar* mLastIncompleteFragmentInCharacterData;

        /**
         * When an object is allocated on mem manager stack and the containing
         * data don't fill out whole object, this pointer points to the end of
         * the data inside the object on stack.
         */
        ParserChar* mEndOfDataInCurrentObjectOnStack;

        ElementNameMap mHashNameMap;

	public:
		ParserTemplateBase(IErrorHandler* errorHandler)
			: Parser(errorHandler),
			mStackMemoryManager(STACK_SIZE),
            mValidationDataStack(STACK_SIZE),
            mValidate(true),
			mLastIncompleteFragmentInCharacterData(0){}
		virtual ~ParserTemplateBase(){};

		/** Returns the element or attribute name that corresponds to @a hash. Null is returned,
		if no corresponding name could be found.*/
		const char* getNameByStringHash(const StringHash& hash)const;

		/** Returns the element of the element in level @a level, where the previous element is level 0. 
		If level is invalid, 0 is returned.*/
		StringHash getElementHash( size_t level = 0 )const;


	protected:
		/** Converts the first string representing a float within a ParserChar buffer with prefixedBuffer
		prefixed to a float and advances the character pointer to the first position after the last
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first
		character after the last interpreted.
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		float toFloatPrefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing a double within a ParserChar buffer with prefixedBuffer
		prefixed to a double and advances the character pointer to the first position after the last
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first
		character after the last interpreted.
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		double toDoublePrefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing a char within a ParserChar buffer with prefixedBuffer
		prefixed to a char and advances the character interpreted to the first position after the last
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first
		character after the last interpreted.
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		sint8 toSint8Prefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing an unsigned char within a ParserChar buffer with prefixedBuffer
		prefixed to an unsigned char and advances the character char to the first position after the last
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first
		character after the last interpreted.
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		uint8 toUint8Prefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing a short within a ParserChar buffer with prefixedBuffer
		prefixed to a short and advances the character interpreted to the first position after the last
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first
		character after the last interpreted.
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		sint16 toSint16Prefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing an unsigned short within a ParserChar buffer with prefixedBuffer
		prefixed to an unsigned short and advances the character short to the first position after the last
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first
		character after the last interpreted.
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		uint16 toUint16Prefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing an integer within a ParserChar buffer with prefixedBuffer
		prefixed to an integer and advances the character pointer to the first position after the last
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first
		character after the last interpreted.
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		sint32 toSint32Prefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing an unsigned integer within a ParserChar buffer with prefixedBuffer
		prefixed to an unsigned integer and advances the character pointer to the first position after the last
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first
		character after the last interpreted.
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		uint32 toUint32Prefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing an integer within a ParserChar buffer with prefixedBuffer
		prefixed to an integer and advances the character pointer to the first position after the last
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first
		character after the last interpreted.
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		sint64 toSint64Prefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing an unsigned integer within a ParserChar buffer with prefixedBuffer
		prefixed to an unsigned integer and advances the character pointer to the first position after the last
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first
		character after the last interpreted.
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		uint64 toUint64Prefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing a bool within a ParserChar buffer with prefixedBuffer
		prefixed to a bool and advances the character interpreted to the first position after the last
		interpreted character in buffer. If buffer is set to bufferEnd, the end of the buffer was reached
		during conversion. In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first
		character after the last interpreted.
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		bool toBoolPrefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


        /** @see toDataPrefix. */
        ParserString toStringListPrefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


        /**
         * Handles remaining stuff from last data-call and converts it to a list of enums.
         * @see toDataPrefix
         */
        template<class EnumType, class BaseType, EnumType EnumMapCount,
            EnumType (*toEnum)(const ParserChar** buffer,
            const ParserChar* bufferEnd,
            bool& failed,
            const std::pair<BaseType, EnumType>* enumMap,
            BaseType (*baseConversionFunctionPtr)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)
            )
        >
        EnumType toEnumDataPrefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed,
            const std::pair<BaseType, EnumType>* enumMap,
            BaseType (*baseConversionFunctionPtr)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)
            );

        template<class DataType>
        DataType toDataPrefix(
            const ParserChar* prefixedBuffer,
            const ParserChar* prefixedBufferEnd,
            const ParserChar** buffer,
            const ParserChar* bufferEnd,
            bool& failed,
            DataType (*toData)(const ParserChar**, const ParserChar*, bool&)
            );


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
		@param attributeHash The hash of the attribute the error occurred in.
		@param additionalText Additional text describing the error.
        @return True when abort required, false when continue is possible.
        */
		bool handleError(ParserError::Severity severity,
        			     ParserError::ErrorType errorType,
			             StringHash attributeHash,
			             const ParserChar* additionalText);

        /** Passes an error with the specified properties to the error handler.
        @param severity The severity of the error.
        @param errorType The error type of the error.
        @param elementHash The hash of the element the error occurred in.
        @param attribute The name of the attribute the error occurred in.
        @param additionalText Additional text describing the error.
        @return True when abort required, false when continue is possible.
        */
        bool handleError( ParserError::Severity severity,
            ParserError::ErrorType errorType,
            StringHash elementHash,
            const ParserChar* attribute,
            const ParserChar* additionalText );


    protected:
    private:
		/** Disable default copy ctor. */
		ParserTemplateBase( const ParserTemplateBase& pre );
		/** Disable default assignment operator. */
		const ParserTemplateBase& operator= ( const ParserTemplateBase& pre );

        template<class DataType,
            DataType (*toData)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)>
            DataType toDataPrefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);
	};


    //--------------------------------------------------------------------
	template<class DataType>
	DataType* ParserTemplateBase::newData(void** dataPtr)
	{
		void* mem = mStackMemoryManager.newObject(sizeof(DataType));
		DataType* data = new(mem) DataType(DataType::DEFAULT);
		*dataPtr = data;
		return data;
	}

    //--------------------------------------------------------------------
    template<class EnumType, class BaseType, EnumType EnumMapCount,
        EnumType (*toEnum)(const ParserChar** buffer,
        const ParserChar* bufferEnd,
        bool& failed,
        const std::pair<BaseType, EnumType>* enumMap,
        BaseType (*baseConversionFunctionPtr)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)
        )
    >
    EnumType ParserTemplateBase::toEnumDataPrefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed,
        const std::pair<BaseType, EnumType>* enumMap,
        BaseType (*baseConversionFunctionPtr)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed))
    {
        const ParserChar* prefixBufferPos = prefixedBuffer;
        const ParserChar* prefixBufferStartPos = 0;
        while ( prefixBufferPos != prefixedBufferEnd )
        {
            if (!Utils::isWhiteSpace(*prefixBufferPos ) && !prefixBufferStartPos)
                prefixBufferStartPos = prefixBufferPos;
            ++prefixBufferPos;
        }

        //if prefixedBuffer contains only white spaces, we can ignore it.
        if ( !prefixBufferStartPos )
            return toEnum(buffer, bufferEnd, failed, enumMap, baseConversionFunctionPtr);

        //find first whitespace in buffer
        const ParserChar* bufferPos = *buffer;
        while ( !Utils::isWhiteSpace(*bufferPos) )
            ++bufferPos;

        size_t prefixBufferSize = prefixBufferPos - prefixBufferStartPos;
        size_t bufferSize = bufferPos - *buffer;
        size_t newBufferSize = prefixBufferSize + bufferSize;
        ParserChar* newBuffer =  (ParserChar*)mStackMemoryManager.newObject((newBufferSize + 1)*sizeof(ParserChar));
        memcpy(newBuffer, prefixBufferStartPos, prefixBufferSize*sizeof(ParserChar));
        memcpy(newBuffer + prefixBufferSize, *buffer, bufferSize*sizeof(ParserChar));
        newBuffer[newBufferSize] = ' ';
        ParserChar* newBufferPostParse = newBuffer;
        EnumType value = toEnum( (const ParserChar**)&newBufferPostParse, newBuffer + newBufferSize + 1, failed, enumMap, baseConversionFunctionPtr);
        *buffer += (newBufferPostParse - newBuffer - prefixBufferSize);
        return value;
    }

    //--------------------------------------------------------------------
    template<class DataType,
        DataType (*toData)( const ParserChar**, const ParserChar*, bool& )>
        DataType ParserTemplateBase::toDataPrefix(
        const ParserChar* prefixedBuffer,
        const ParserChar* prefixedBufferEnd,
        const ParserChar** buffer,
        const ParserChar* bufferEnd,
        bool& failed
        )
    {
        const ParserChar* prefixBufferPos = prefixedBuffer;
        const ParserChar* prefixBufferStartPos = 0;
        while ( prefixBufferPos != prefixedBufferEnd )
        {
            if (!Utils::isWhiteSpace(*prefixBufferPos ) && !prefixBufferStartPos)
                prefixBufferStartPos = prefixBufferPos;
            ++prefixBufferPos;
        }

        //if prefixedBuffer contains only white spaces, we can ignore it.
        if ( !prefixBufferStartPos )
            return toData(buffer, bufferEnd, failed);

        //find first whitespace in buffer
        const ParserChar* bufferPos = *buffer;
        while ( !Utils::isWhiteSpace(*bufferPos) && bufferPos < bufferEnd )
            ++bufferPos;

        size_t prefixBufferSize = prefixBufferPos - prefixBufferStartPos;
        size_t bufferSize = bufferPos - *buffer;
        size_t newBufferSize = prefixBufferSize + bufferSize;
        ParserChar* newBuffer =  (ParserChar*)mStackMemoryManager.newObject((newBufferSize + 1)*sizeof(ParserChar));
        memcpy(newBuffer, prefixBufferStartPos, prefixBufferSize*sizeof(ParserChar));
        memcpy(newBuffer + prefixBufferSize, *buffer, bufferSize*sizeof(ParserChar));
        newBuffer[newBufferSize] = ' ';
        ParserChar* newBufferPostParse = newBuffer;
        DataType value = toData( (const ParserChar**)&newBufferPostParse, newBuffer + newBufferSize + 1, failed);
        *buffer += (newBufferPostParse - newBuffer - prefixBufferSize);
        // note: we cannot delete that object here because
        // DataType maybe ParserString and this deleteObject call
        // would delete the string ParserString::str points at.
        //mStackMemoryManager.deleteObject();
        return value;
    }

    //--------------------------------------------------------------------
    template<class DataType>
    DataType ParserTemplateBase::toDataPrefix(
        const ParserChar* prefixedBuffer,
        const ParserChar* prefixedBufferEnd,
        const ParserChar** buffer,
        const ParserChar* bufferEnd,
        bool& failed,
        DataType (*toData)( const ParserChar**, const ParserChar*, bool& )
        )
    {
        const ParserChar* prefixBufferPos = prefixedBuffer;
        const ParserChar* prefixBufferStartPos = 0;
        while ( prefixBufferPos != prefixedBufferEnd )
        {
            if (!Utils::isWhiteSpace(*prefixBufferPos ) && !prefixBufferStartPos)
                prefixBufferStartPos = prefixBufferPos;
            ++prefixBufferPos;
        }

        //if prefixedBuffer contains only white spaces, we can ignore it.
        if ( !prefixBufferStartPos )
            return toData(buffer, bufferEnd, failed);

        //find first whitespace in buffer
        const ParserChar* bufferPos = *buffer;
        while ( !Utils::isWhiteSpace(*bufferPos) )
            ++bufferPos;

        size_t prefixBufferSize = prefixBufferPos - prefixBufferStartPos;
        size_t bufferSize = bufferPos - *buffer;
        size_t newBufferSize = prefixBufferSize + bufferSize;
        ParserChar* newBuffer =  (ParserChar*)mStackMemoryManager.newObject((newBufferSize + 1)*sizeof(ParserChar));
        memcpy(newBuffer, prefixBufferStartPos, prefixBufferSize*sizeof(ParserChar));
        memcpy(newBuffer + prefixBufferSize, *buffer, bufferSize*sizeof(ParserChar));
        newBuffer[newBufferSize] = ' ';
        ParserChar* newBufferPostParse = newBuffer;
        DataType value = toData( (const ParserChar**)&newBufferPostParse, newBuffer + newBufferSize + 1, failed);
        *buffer += (newBufferPostParse - newBuffer - prefixBufferSize);

        // see comment in overloaded method
        //mStackMemoryManager.deleteObject();

        return value;
    }

} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_COLLADAPARSERAUTOGENBASE_H__
