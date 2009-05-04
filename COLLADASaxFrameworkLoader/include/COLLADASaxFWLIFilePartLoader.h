/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_IFILEPARTLOADER_H__
#define __COLLADASAXFWL_IFILEPARTLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLTypes.h"
#include "COLLADASaxFWLColladaParserAutoGen.h"

#include "COLLADAFWUniqueId.h"
#include "COLLADAFWExtraData.h"


namespace COLLADAFW
{
	class IWriter;
	class Object;
	class Animatable;
	class AnimationList;
}

namespace COLLADABU
{
	class URI;
}

namespace COLLADASaxFWL
{
	class Loader;
	class FileLoader;
	class GeometryMaterialIdInfo;
	class SidTreeNode;
	class SidAddress;

    /** Base class for all loaders that load parts of files or entire files */
	class IFilePartLoader : protected ColladaParserAutoGen
	{
	private:
		/** The currently working file part loader.*/
		IFilePartLoader* mPartLoader;

		/** The name of the profile of the last parsed technique element.*/
		String mTechniqueProfileName;

	public:

		/** Returns a pointer to the collada loader. */
		virtual Loader* getColladaLoader() =0;

		/** Returns a const pointer to the collada document. */
		virtual const Loader* getColladaLoader()const =0;

		/** Returns a pointer to the file loader. */
		virtual FileLoader* getFileLoader() =0;

		/** Returns a pointer to the file loader. */
		virtual const FileLoader* getFileLoader() const =0;

		/** Returns the writer the data will be written to.*/
		COLLADAFW::IWriter* writer();

		/** Returns the COLLADAFW::UniqueId of the element with uri @a uri. If the uri has been
		passed to this method before, the same 	COLLADAFW::UniqueId will be returned, if not, a
		new one is created.
		@param uri The uri of the element to get the COLLADAFW::UniqueId for
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		const COLLADAFW::UniqueId& getUniqueId(const String& uriString, COLLADAFW::ClassId classId);

		/** Returns the COLLADAFW::UniqueId of the element with id  @a colladaId in the current file.
		If the id within this file has been passed to this method before, the same 	COLLADAFW::UniqueId
		will be returned, if not, a new one is created.
		@param id The collada id of the element to get the COLLADAFW::UniqueId for
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		COLLADAFW::UniqueId getUniqueIdFromId( const ParserChar* colladaId, COLLADAFW::ClassId classId );

		/** Returns the COLLADAFW::UniqueId of the element referenced by the url  @a url. If the has
		been passed to this method before, the same COLLADAFW::UniqueId will be returned, if not,
		a new one is created.
		@param url The url of the element to get the COLLADAFW::UniqueId for
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		const COLLADAFW::UniqueId& getUniqueIdFromUrl( const ParserChar* url, COLLADAFW::ClassId classId );

		/** Returns the COLLADAFW::UniqueId of the element referenced by the url  @a url. If the has
		been passed to this method before, the same COLLADAFW::UniqueId will be returned, if not,
		a new one is created.
		@param url The url of the element to get the COLLADAFW::UniqueId for
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		const COLLADAFW::UniqueId& getUniqueIdFromUrl( const COLLADABU::URI& url, COLLADAFW::ClassId classId );

		/** Returns the COLLADAFW::UniqueId of an element with no uri.  At each call a new
		COLLADAFW::UniqueId will be created and returned. Use this member for collada elements that
		do not have an id.
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		COLLADAFW::UniqueId getUniqueId(COLLADAFW::ClassId classId);

		/** Returns the GeometryMaterialIdInfo object of the geometry with @a uniqueId. If this method has
		not been called before with the same uniqueId, an empty GeometryMaterialIdInfo is created, added to
		the map and returned.*/
		GeometryMaterialIdInfo& getMeshMaterialIdInfo( const COLLADAFW::UniqueId& uniqueId);

		/** Returns TextureMapId for @a semantic. Successive call with same semantic return the same TextureMapId.*/
		COLLADAFW::TextureMapId getTextureMapIdBySematic( const String& semantic );

		/** Creates a new in the sid tree. Call this method for every collada element that has an sid or that has an id 
		and can have children with sids. For every call of this method you have to call addToSidTree() when the element
		is closed.
		@param id The id of the element. Might be 0;
		@param sid The sid of the element. Might be 0;
		*/
		void addToSidTree( const char* colladaId, const char* colladaSid );

		/** Creates a new node in the sid tree. Call this method for every collada element that has an sid or that has an id 
		and can have children with sids. For every call of this method you have to call moveUpInSidTree() when the element
		is closed.
		@param id The id of the element. Might be 0;
		@param sid The sid of the element. Might be 0;
		@param target The target assigned to the sid tree node
		*/
		void addToSidTree( const char* colladaId, const char* colladaSid, COLLADAFW::Object* target );

		/** Creates a new node in the sid tree. Call this method for every collada element that has an sid or that has an id 
		and can have children with sids. For every call of this method you have to call moveUpInSidTree() when the element
		is closed.
		@param id The id of the element. Might be 0;
		@param sid The sid of the element. Might be 0;
		@param target The target assigned to the sid tree node
		*/
		void addToSidTree( const char* colladaId, const char* colladaSid, COLLADAFW::Animatable* target );


		/** Moves one node up in the sid tree. Call this method whenever an element, for which addToSidTree() was
		called, is closed.*/
		void moveUpInSidTree();

		/** Tries to resolve the a sidaddress. If resolving failed, null is returned.*/
		const SidTreeNode* resolveSid( const SidAddress& sidAddress);

		/** Stores the bindig of an animation to an object, referenced by @a targetSidAddress.*/
		void addToAnimationSidAddressBindings( const AnimationInfo& animationInfo, const SidAddress& targetSidAddress);

		/** Returns the animation list with Unique id @a animationListUniqueId. If it could not be found, a new map 
		entry is created.*/
		COLLADAFW::AnimationList*& getAnimationListByUniqueId( const COLLADAFW::UniqueId& animationListUniqueId);

		/** After this functions, the next sax callback should be caught by this the file part loader.*/
		void setMeAsParser();

		/** Sets the parser to @a parserToBeSet.*/
		virtual void setParser(IFilePartLoader* parserToBeSet)=0;

		/** Sets the part loader.*/
		void setPartLoader(IFilePartLoader* partLoader){mPartLoader=partLoader;}

		/** Returns the absolute uri of the currently parsed file*/
		virtual const COLLADABU::URI& getFileUri()=0;

		/** Returns the ExtraData object, that should be used to store the extra data.*/
		virtual COLLADAFW::ExtraData* getExtraData() { return 0; }

		/** Returns the second part of the key, usually the current parent element name.*/
		virtual const char* getSecondKey() { return 0; }

		/** Copies the contents of the STL container @a stlContainer into the framework array
		@a clonedArray.*/
		template<class StlContainer, class Array >
		static void copyStlContainerToArray( const StlContainer& stlContainer, Array& clonedArray)
		{
			size_t stlContainerSize = stlContainer.size();
			if ( stlContainerSize > 0 )
			{
				clonedArray.allocMemory( stlContainerSize);
				typename StlContainer::const_iterator it = stlContainer.begin();
				size_t index = 0;
				for (; it != stlContainer.end(); ++it, ++index)
				{
					clonedArray[index] = *it;
				}
				clonedArray.setCount(stlContainerSize);
			}
		}


		virtual bool begin__technique( const technique__AttributeData& attributeData );

		virtual bool end__technique();


	protected:
		/** Deletes the part loader mPartLoader, if it is not needed anymore. Always call this method,
		when creating a new FilePartLoader and switching to it.*/
		void deleteFilePartLoader();


	public:

        /** Constructor. */
		IFilePartLoader();

        /** Destructor. */
		virtual ~IFilePartLoader();

	private:

        /** Disable default copy ctor. */
		IFilePartLoader( const IFilePartLoader& pre );

        /** Disable default assignment operator. */
		const IFilePartLoader& operator= ( const IFilePartLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_IFILEPARTLOADER_H__
