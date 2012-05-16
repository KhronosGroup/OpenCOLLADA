/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_SOURCEARRAYLOADER_H__
#define __COLLADASAXFWL_SOURCEARRAYLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSource.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLXmlTypes.h"
#include "COLLADAFWFloatOrDoubleArray.h"


namespace COLLADASaxFWL
{

    /** 
    Base class for elements, that contain source arrays. The derived classes need to implement 
	the corresponding begin_source and end_soure callback function and call the beginSource and 
	endSource function. All the tags in between are handled by this class. It provides an array,
	containing all the loaded sources.
    */
    class SourceArrayLoader : public FilePartLoader
    {
	public:
		static const COLLADAFW::FloatOrDoubleArray::DataType DATA_TYPE_REAL;

	protected:
	
        /**
        * Provides the bulk of the mesh’s vertex data. See main entry.
        */
        SourceArray mSourceArray;

		/** The source currently being parsed.*/
		SourceBase* mCurrentSoure;

		/** The id of the source being parsed.*/
		String mCurrentSourceId;

		/** The id of the array being parsed.*/
		String mCurrentArrayId;

	public:
		/** Takes a null terminated string, that represents an uriFragment of URIFragmentType defined in the 
		COLLADA XSD and returns the id it points to.*/
		static String getIdFromURIFragmentType( const char* uriFragment );

		/** Copies the values contained in @a realSource into @a realsArray .*/
		static void setRealValues( COLLADAFW::FloatOrDoubleArray& realsArray, const RealSource* realSource );

	protected:

        /** Constructor. */
		SourceArrayLoader ( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~SourceArrayLoader();

		/** Assigns the float or double values, stored in @a source in @a floatOrDoubleArray. If type of 
		@a source is neither float nor double, false is returned and no assignment performed. The values 
		are not copied, but the source number array is assignment to the @a floatOrDoubleArray array.*/
		bool assignSourceValuesToFloatOrDoubleArray( SourceBase* source, COLLADAFW::FloatOrDoubleArray& floatOrDoubleArray);

		/** Returns the id of the source being parsed.*/
		const String& getCurrentSourceId() const { return mCurrentSourceId; }

		/** Clears all the source loaded by the source array loader.*/
		void clearSources();

        /**
        * Provides the bulk of the mesh’s vertex data. See main entry.
        * @param sourceArraySize Parameter to get the size of the source array.
        * @return const SourceArray The source array.
        */
        const SourceArray& getSourceArray () const;

        /**
        * Provides the bulk of the mesh’s vertex data. See main entry.
        * @param sourceArray The source array.
        * @param sourceArraySize The size of the source array.
        */
        void setSourceArray ( const SourceArray& sourceArray );

        /**
        * Returns the source element of the source array with the given id or 0 if it not exist.
        * @param sourceId The source id of the searched source element.
        * @return COLLADAFW::Source The source element with the given id or 0 if it not exist.
        */
        const SourceBase* getSourceById ( const String& sourceId ) const;

        /**
        * Returns the source element of the source array with the given id or 0 if it not exist.
        * @param sourceId The source id of the searched source element.
        * @return COLLADAFW::Source The source element with the given id or 0 if it not exist.
        */
        SourceBase* getSourceById ( const String& sourceId );

		/** Handles the beginning of a source element. Should be called by derived classes, 
		when an opening \<source\> tag is detected.*/
		bool beginSource(const source__AttributeData& attributes);

		/** Handles the ending of a source element. Should be called by derived classes, 
		when a closing \<source\> tag is detected.*/
		bool endSource();

		/** Handles the beginning of a array element. Should be called when ever an array is opened.
		@tparam SourceType Type of source to create a new instance from for the opened array, e.g. FloatSource for <float_array>
		@param count The Value of the count attribute of the aray
		@param id The if of the array element
		@return The new created source*/
		template<class SourceType> 
		SourceType* beginArray( uint64 count, const ParserChar* id );


    public:
		/** Sax callback function for the beginning of a float array element.*/
		virtual bool begin__float_array( const float_array__AttributeData& attributeData );

		/** Sax callback function for the ending of a float array element.*/
		virtual bool end__float_array();

		/** Sax callback function for the float data of a float array element.*/
		virtual bool data__float_array( const float* data, size_t length );


		/** Sax callback function for the beginning of a technique_common element.*/
		virtual bool begin__animation__source__technique_common();

		/** Sax callback function for the ending of a technique_common element.*/
		virtual bool end__animation__source__technique_common();


		/** Sax callback function for the beginning of a accessor element.*/
		virtual bool begin__accessor( const accessor__AttributeData& attributeData );

		/** Sax callback function for the ending of a accessor element.*/
		virtual bool end__accessor();


		/** Store the accessor parameter in the source's accessor.*/
		virtual bool begin__param( const param__AttributeData& attributeData );

		/** We don't need to do anything here.*/
		virtual bool end__param(){return true;}

		/** We don't need to do anything here.*/
		virtual bool data__param( const ParserChar* value, size_t length ){return true;}


	private:

        /** Disable default copy ctor. */
		SourceArrayLoader( const SourceArrayLoader& pre );

        /** Disable default assignment operator. */
		const SourceArrayLoader& operator= ( const SourceArrayLoader& pre );
	};


	//------------------------------
	template<class SourceType>
	SourceType* SourceArrayLoader::beginArray( uint64 count,  const ParserChar* id )
	{
		SourceType* newSource = new SourceType();
		newSource->getArrayElement().getValues().allocMemory((size_t)count);
		newSource->setId(mCurrentSourceId);
		mCurrentSoure = newSource;
		if ( id )
			mCurrentArrayId = id;
		return newSource;
	}



} // namespace COLLADAFW

#endif // __COLLADASAXFWL_SOURCEARRAYLOADER_H__
