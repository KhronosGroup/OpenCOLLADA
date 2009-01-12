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

		typedef bool ( ImplClass::*FloatDataFunctionPtr ) (const float* text, size_t textLength );
		typedef bool ( ImplClass::*DoubleDataFunctionPtr ) (const double* text, size_t textLength );

		typedef bool ( ImplClass::*CharDataFunctionPtr ) (const char* text, size_t textLength );
		typedef bool ( ImplClass::*UnsignedCharDataFunctionPtr ) (const unsigned char* text, size_t textLength );

		typedef bool ( ImplClass::*ShortDataFunctionPtr ) (const short* text, size_t textLength );
		typedef bool ( ImplClass::*UnsignedShortDataFunctionPtr ) (const unsigned short* text, size_t textLength );
		
		typedef bool ( ImplClass::*IntDataFunctionPtr ) (const int* text, size_t textLength );
		typedef bool ( ImplClass::*UnsignedIntDataFunctionPtr ) (const unsigned int* text, size_t textLength );
		
		typedef bool ( ImplClass::*LongDataFunctionPtr ) (const long* text, size_t textLength );
		typedef bool ( ImplClass::*UnsignedLongDataFunctionPtr ) (const unsigned long* text, size_t textLength );
		
		typedef bool ( ImplClass::*LongLongDataFunctionPtr ) (const long long* text, size_t textLength );
		typedef bool ( ImplClass::*UnsignedLongLongDataFunctionPtr ) (const unsigned long long* text, size_t textLength );

		typedef bool ( ImplClass::*BoolDataFunctionPtr ) (const bool* text, size_t textLength );

	protected:
		typedef bool ( DerivedClass::*ElementBeginFunctionPtr ) (void* attributeData );
		typedef bool ( DerivedClass::*TextDataFunctionPtr ) (const ParserChar* text, size_t textLength );
		typedef bool ( DerivedClass::*ElementEndFunctionPtr ) ();
		typedef bool ( DerivedClass::*ElementValidateBeginFunctionPtr ) (const ParserAttributes& attributes, void ** attributeDataPtr,  void ** validationDataPtr  );
		typedef bool ( DerivedClass::*ElementValidateEndFunctionPtr ) ( );


		struct FunctionStruct 
		{
			FunctionStruct()
				: beginFunction(0),
				endFunction(0),
				validateBeginFunction(0)
			{}

			FunctionStruct( ElementBeginFunctionPtr _beginFunction, 
				TextDataFunctionPtr _textDataFunction, 
				ElementEndFunctionPtr _endFunction, 
				ElementValidateBeginFunctionPtr _validateBeginFunction, 
				ElementValidateEndFunctionPtr _validateEndFunction)
				: beginFunction(_beginFunction),
				textDataFunction(_textDataFunction),
				endFunction(_endFunction),
				validateBeginFunction(_validateBeginFunction),
				validateEndFunction(_validateEndFunction)
			{}

			ElementBeginFunctionPtr beginFunction;
			TextDataFunctionPtr textDataFunction;
			ElementEndFunctionPtr endFunction;
			ElementValidateBeginFunctionPtr validateBeginFunction;
			ElementValidateEndFunctionPtr validateEndFunction;
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
			  mIgnoreElements(0),
			  mImpl(impl)
		  {};
		virtual ~ParserTemplate(){};

		/** Sets the object, that should receive all the callbacks from now on.*/
		void setCallbackObject(ImplClass* impl){ mImpl = impl; }

	public:
		bool elementBegin(const ParserChar* elementName, const ParserAttributes& attributes );

		bool elementEnd(const ParserChar* elementName );

		bool textData(const ParserChar* text, size_t textLength);



	protected:
		template<class DataType, 
				 DataType (*toData)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed),
				 DataType (ParserTemplateBase::*toDataWithPrefix)(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)>
		bool characterData2Data(const ParserChar* text, size_t textLength, bool ( ImplClass::*dataFunction ) (const DataType* data, size_t dataLength ) );

		bool characterData2FloatData( const ParserChar* text, size_t textLength, FloatDataFunctionPtr floatDataFunction );
		bool characterData2DoubleData( const ParserChar* text, size_t textLength, DoubleDataFunctionPtr doubleDataFunction );

		bool characterData2CharData( const ParserChar* text, size_t textLength, CharDataFunctionPtr charDataFunction );
		bool characterData2UnsignedCharData( const ParserChar* text, size_t textLength, UnsignedCharDataFunctionPtr unsignedCharDataFunction );

		bool characterData2ShortData( const ParserChar* text, size_t textLength, ShortDataFunctionPtr shortDataFunction );
		bool characterData2UnsignedShortData( const ParserChar* text, size_t textLength, UnsignedShortDataFunctionPtr unsignedShortDataFunction );

		bool characterData2IntData( const ParserChar* text, size_t textLength, IntDataFunctionPtr intDataFunction );
		bool characterData2UnsignedIntData( const ParserChar* text, size_t textLength, UnsignedIntDataFunctionPtr unsignedIntDataFunction );

		bool characterData2LongData( const ParserChar* text, size_t textLength, LongDataFunctionPtr longDataFunction );
		bool characterData2UnsignedLongData( const ParserChar* text, size_t textLength, UnsignedLongDataFunctionPtr unsignedLongDataFunction );

		bool characterData2LongLongData( const ParserChar* text, size_t textLength, LongLongDataFunctionPtr longLongDataFunction );
		bool characterData2UnsignedLongLongData( const ParserChar* text, size_t textLength, UnsignedLongLongDataFunctionPtr unsignedLongLongDataFunction );

		bool characterData2BoolData( const ParserChar* text, size_t textLength, BoolDataFunctionPtr boolDataFunction );

		template<class DataType, DataType (*toData)( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)>
		bool dataEnd(bool ( ImplClass::*dataFunction ) (const DataType* data, size_t dataLength ));

        bool boolDataEnd( BoolDataFunctionPtr boolDataFunction );
		bool floatDataEnd( FloatDataFunctionPtr floatDataFunction );
        bool doubleDataEnd( DoubleDataFunctionPtr doubleDataFunction );

		bool charDataEnd( CharDataFunctionPtr charDataFunction );
		bool unsignedCharDataEnd( UnsignedCharDataFunctionPtr unsignedCharDataFunction );

		bool shortDataEnd( ShortDataFunctionPtr shortDataFunction );
		bool unsignedShortDataEnd( UnsignedShortDataFunctionPtr unsignedShortDataFunction );

		bool intDataEnd( IntDataFunctionPtr intDataFunction );
		bool unsignedIntDataEnd( UnsignedIntDataFunctionPtr unsignedIntDataFunction );

		bool longDataEnd( LongDataFunctionPtr longDataFunction );
		bool unsignedLongDataEnd( UnsignedLongDataFunctionPtr unsignedLongDataFunction );

		bool longLongDataEnd( LongLongDataFunctionPtr longLongDataFunction );
		bool unsignedLongLongDataEnd( UnsignedLongLongDataFunctionPtr unsignedLongLongDataFunction );

	private:
		/** Disable default copy ctor. */
		ParserTemplate( const ParserTemplate& pre );
		/** Disable default assignment operator. */
		const ParserTemplate& operator= ( const ParserTemplate& pre );

	};

	template<class DerivedClass, class ImplClass>
	template<class DataType, 
		     DataType (*toData)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed),
			 DataType (ParserTemplateBase::*toDataWithPrefix)(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2Data(const ParserChar* text, size_t textLength, bool ( ImplClass::*dataFunction ) (const DataType* data, size_t dataLength ) )
	{
		size_t dataBufferIndex = 0;
		const ParserChar* dataBufferPos = text;
		const ParserChar* bufferEnd = text + textLength;
		const ParserChar* lastDataBufferIndex = dataBufferPos;

		// handle incomplete fragment from last call to textData
		DataType fragmentData = 0;
		if ( mLastIncompleteFragmentInChararterData )
		{
			bool failed = false;

			fragmentData = (this->*toDataWithPrefix)(mLastIncompleteFragmentInChararterData, &dataBufferPos, bufferEnd, failed);
			mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInChararterData
			mLastIncompleteFragmentInChararterData = 0;
			if ( failed )
			{
				if ( handleError(ParserError::SEVERITY_ERROR, 
					             ParserError::ERROR_TEXTDATA_PARSING_FAILED,
					             0,
					             mLastIncompleteFragmentInChararterData))
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

		DataType* typedBuffer = (DataType*)mStackMemoryManager.newObject(TYPED_VALUES_BUFFER_SIZE * sizeof(DataType));

		if ( dataBufferIndex > 0)
			typedBuffer[0] = fragmentData;


		bool failed = false;
		while ( !failed )
		{
			lastDataBufferIndex = dataBufferPos;
			DataType dataValue =toData(&dataBufferPos, bufferEnd, failed);
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
			mLastIncompleteFragmentInChararterData = (ParserChar*)mStackMemoryManager.newObject(fragmentSize + 1);
			memcpy(mLastIncompleteFragmentInChararterData, lastDataBufferIndex, fragmentSize);
			mLastIncompleteFragmentInChararterData[fragmentSize] = '\0';

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
			if ( handleError(ParserError::SEVERITY_ERROR, 
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
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2FloatData( const ParserChar* text, size_t textLength, FloatDataFunctionPtr floatDataFunction )
	{
		return characterData2Data<float, Utils::toFloat, &ParserTemplateBase::toFloatPrefix>(text, textLength, floatDataFunction);
	}


	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2DoubleData( const ParserChar* text, size_t textLength, DoubleDataFunctionPtr doubleDataFunction )
	{
		return characterData2Data<double, Utils::toDouble, &ParserTemplateBase::toDoublePrefix>(text, textLength, doubleDataFunction);
	}


	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2CharData( const ParserChar* text, size_t textLength, CharDataFunctionPtr charDataFunction )
	{
		return characterData2Data<char, Utils::toChar, &ParserTemplateBase::toCharPrefix>(text, textLength, charDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2UnsignedCharData( const ParserChar* text, size_t textLength, UnsignedCharDataFunctionPtr unsignedCharDataFunction )
	{
		return characterData2Data<unsigned char, Utils::toUnsignedChar, &ParserTemplateBase::toUnsignedCharPrefix>(text, textLength, unsignedCharDataFunction);
	}
	
	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2ShortData( const ParserChar* text, size_t textLength, ShortDataFunctionPtr shortDataFunction )
	{
		return characterData2Data<short, Utils::toShort, &ParserTemplateBase::toShortPrefix>(text, textLength, shortDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2UnsignedShortData( const ParserChar* text, size_t textLength, UnsignedShortDataFunctionPtr unsignedShortDataFunction )
	{
		return characterData2Data<unsigned short, Utils::toUnsignedShort, &ParserTemplateBase::toUnsignedShortPrefix>(text, textLength, unsignedShortDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2IntData( const ParserChar* text, size_t textLength, IntDataFunctionPtr intDataFunction )
	{
		return characterData2Data<int, Utils::toInt, &ParserTemplateBase::toIntPrefix>(text, textLength, intDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2UnsignedIntData( const ParserChar* text, size_t textLength, UnsignedIntDataFunctionPtr unsignedIntDataFunction )
	{
		return characterData2Data<unsigned int, Utils::toUnsignedInt, &ParserTemplateBase::toUnsignedIntPrefix>(text, textLength, unsignedIntDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2LongData( const ParserChar* text, size_t textLength, LongDataFunctionPtr longDataFunction )
	{
		return characterData2Data<long, Utils::toLong, &ParserTemplateBase::toLongPrefix>(text, textLength, longDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2UnsignedLongData( const ParserChar* text, size_t textLength, UnsignedLongDataFunctionPtr unsignedLongDataFunction )
	{
		return characterData2Data<unsigned long, Utils::toUnsignedLong, &ParserTemplateBase::toUnsignedLongPrefix>(text, textLength, unsignedLongDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2LongLongData( const ParserChar* text, size_t textLength, LongLongDataFunctionPtr longLongDataFunction )
	{
		return characterData2Data<long long, Utils::toLongLong, &ParserTemplateBase::toLongLongPrefix>(text, textLength, longLongDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2UnsignedLongLongData( const ParserChar* text, size_t textLength, UnsignedLongLongDataFunctionPtr unsignedLongLongDataFunction )
	{
		return characterData2Data<unsigned long long, Utils::toUnsignedLongLong, &ParserTemplateBase::toUnsignedLongLongPrefix>(text, textLength, unsignedLongLongDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::characterData2BoolData( const ParserChar* text, size_t textLength, BoolDataFunctionPtr boolDataFunction )
	{
		return characterData2Data<bool, Utils::toBool, &ParserTemplateBase::toBoolPrefix>(text, textLength, boolDataFunction);
	}


	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	template<class DataType, DataType (*toData)( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)>
	bool ParserTemplate<DerivedClass, ImplClass>::dataEnd(bool ( ImplClass::*dataFunction ) (const DataType* data, size_t dataLength ))
	{
		if ( mLastIncompleteFragmentInChararterData )
		{
			bool failed = false;
			const ParserChar* bufferBegin = mLastIncompleteFragmentInChararterData;
			ParserChar* bufferEnde = mLastIncompleteFragmentInChararterData;
			while ( *bufferEnde )
				++bufferEnde;
			*(bufferEnde++) = ' ';
			DataType floatValue = toData(&bufferBegin, bufferEnde, failed);
			mStackMemoryManager.deleteObject(); //mLastIncompleteFragmentInChararterData
			mLastIncompleteFragmentInChararterData = 0;
			if ( failed )
			{
				if ( bufferBegin != bufferEnde )
				{
					if ( handleError(ParserError::SEVERITY_ERROR, 
								     ParserError::ERROR_TEXTDATA_PARSING_FAILED,
								     0,
								     bufferBegin))
					{
						return false;
					}
				}
			}
			else
			{
				(mImpl->*dataFunction)(&floatValue, 1);
			}

		}
		return true;
	}


    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::boolDataEnd( BoolDataFunctionPtr boolDataFunction )
    {
        return dataEnd<bool, Utils::toBool>(boolDataFunction);
    }

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::floatDataEnd( FloatDataFunctionPtr floatDataFunction )
	{
		return dataEnd<float, Utils::toFloat>(floatDataFunction);
	}

    //--------------------------------------------------------------------
    template<class DerivedClass, class ImplClass>
    bool ParserTemplate<DerivedClass, ImplClass>::doubleDataEnd( DoubleDataFunctionPtr doubleDataFunction )
    {
        return dataEnd<double, Utils::toDouble>(doubleDataFunction);
    }

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::charDataEnd( CharDataFunctionPtr charDataFunction )
	{
		return dataEnd<char, Utils::toChar>(charDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::unsignedCharDataEnd( UnsignedCharDataFunctionPtr unsignedCharDataFunction )
	{
		return dataEnd<unsigned char, Utils::toUnsignedChar>(unsignedCharDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::shortDataEnd( ShortDataFunctionPtr shortDataFunction )
	{
		return dataEnd<short, Utils::toShort>(shortDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::unsignedShortDataEnd( UnsignedShortDataFunctionPtr unsignedShortDataFunction )
	{
		return dataEnd<unsigned short, Utils::toUnsignedShort>(unsignedShortDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::intDataEnd( IntDataFunctionPtr intDataFunction )
	{
		return dataEnd<int, Utils::toInt>(intDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::unsignedIntDataEnd( UnsignedIntDataFunctionPtr unsignedIntDataFunction )
	{
		return dataEnd<unsigned int, Utils::toUnsignedInt>(unsignedIntDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::longDataEnd( LongDataFunctionPtr longDataFunction )
	{
		return dataEnd<long, Utils::toLong>(longDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::unsignedLongDataEnd( UnsignedLongDataFunctionPtr unsignedLongDataFunction )
	{
		return dataEnd<unsigned long, Utils::toUnsignedLong>(unsignedLongDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::longLongDataEnd( LongLongDataFunctionPtr longLongDataFunction )
	{
		return dataEnd<long long, Utils::toLongLong>(longLongDataFunction);
	}

	//--------------------------------------------------------------------
	template<class DerivedClass, class ImplClass>
	bool ParserTemplate<DerivedClass, ImplClass>::unsignedLongLongDataEnd( UnsignedLongLongDataFunctionPtr unsignedLongLongDataFunction )
	{
		return dataEnd<unsigned long long, Utils::toUnsignedLongLong>(unsignedLongLongDataFunction);
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
		ElementData elementData = mElementDataStack.top();

		ElementFunctionMap::iterator it = mElementFunctionMap.find(elementData.combinedElementHash);
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
		ElementData elementData = mElementDataStack.top();

		ElementFunctionMap::iterator it = mElementFunctionMap.find(elementData.combinedElementHash);
		if ( it == mElementFunctionMap.end() )
			return false;
		FunctionStruct& functions = it->second;

		if ( !functions.validateEndFunction || !(static_cast<DerivedClass*>(this)->*functions.validateEndFunction)())
			return false;

		if ( !functions.endFunction || !(static_cast<DerivedClass*>(this)->*functions.endFunction)() )
			return false;

		if ( elementData.validationData )
			mStackMemoryManager.deleteObject(); // validation data
		mElementDataStack.pop();

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
		
		StringHash combinedHash = 0;
		StringHash elementHash = Utils::calculateStringHash(elementName);
		if ( !mElementDataStack.empty() )
		{
			combinedHash = Utils::calculateStringHash(mElementDataStack.top().elementHash, DerivedClass::PARENT_CHILD_ELEMENT_SEPARATOR, elementName);
		}
		else
		{
			combinedHash = elementHash;
		}

		ElementFunctionMap::iterator it = mElementFunctionMap.find(combinedHash);
		if ( it == mElementFunctionMap.end() )
		{
			if ( handleError(ParserError::SEVERITY_ERROR, 
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
                mStackMemoryManager.deleteObject(); // attribute data
			return false;
        }

		bool success = (static_cast<DerivedClass*>(this)->*functions.beginFunction)(attributeData);
		if ( attributeData )
			mStackMemoryManager.deleteObject(); // attribute data

		if ( success )
		{
			ElementData newElementData;
			newElementData.elementHash = elementHash;
			newElementData.combinedElementHash = combinedHash;
			newElementData.validationData = validationData;
			mElementDataStack.push(newElementData);
		}
		return success;
	}





} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_COLLADAPARSERTEMPLATE_H__
