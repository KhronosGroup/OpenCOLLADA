/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_READER_H__
#define __COLLADA_READER_H__

namespace COLLADADomHelper
{
	/** A helper class for reading COLLADA files.
	*/
	class Reader
	{

    protected:

        /** the reference to the document */
        daeDocument &mDoc;

	public:

		/** Iterator over the elements in a specific library. */
		template<class T>
		class ElementIterator
		{
			friend class Reader;
		protected:
			ElementIterator(const std::vector<T*> &array);
		public:
			virtual ~ElementIterator();
			bool more();
			T& next();
			T& current();
		private:
			std::vector<T*> mArray;
			size_t mCurrentIndex;
		};

	public:
		/** Constructor.
		 @param doc. The document to read.
		*/
		Reader ( daeDocument& doc );

		/// Destruktor.
		virtual ~Reader();

		/** Creates an iterator to step over all visual scenes.
		 @return the iterator
		*/
		ElementIterator<domVisual_scene> getVisualScenes();

		/** Creates an iterator to step over all materials.
		 @return the iterator
		*/
		ElementIterator<domMaterial> getMaterials();
		
		ElementIterator<domLibrary_nodes> getLibNodes();


	};

	//-----------------------------------------------------------------------
	template<class T>
	Reader::ElementIterator<T>::ElementIterator(const std::vector<T*> &array)
		:	mArray(array)
	{
		mCurrentIndex = 0;
	}

	//-----------------------------------------------------------------------
	template<class T>
	Reader::ElementIterator<T>::~ElementIterator()
	{
	}	

	//-----------------------------------------------------------------------
	template<class T>
	T& Reader::ElementIterator<T>::next()
	{
		T* element = mArray[mCurrentIndex++];

		return *element;
	}

	//-----------------------------------------------------------------------
	template<class T>
	T& Reader::ElementIterator<T>::current()
	{
		T* element = mArray[mCurrentIndex];

		return *element;
	}

	//-----------------------------------------------------------------------
	template<class T>
	bool Reader::ElementIterator<T>::more()
	{
		bool bRet = false;
		size_t size = mArray.size();
		if (mCurrentIndex < size)
			bRet = true;

		return bRet;
	}
};
#endif //__COLLADA_READER_H__
