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
#include "COLLADASaxFWLSaxFWLError.h"
#include "COLLADASaxFWLXmlTypes.h"
#include "COLLADASaxFWLLoader.h"
#include "COLLADASaxFWLExtraDataLoader.h"

#include "COLLADAFWUniqueId.h"
#include "COLLADAFWInstanceController.h"

#include <list>
#include <map>


namespace COLLADASaxFWL14
{
    class ColladaParserAutoGen14;
    class ColladaParserAutoGen14Private;
}
namespace COLLADASaxFWL15
{
    class ColladaParserAutoGen15;
    class ColladaParserAutoGen15Private;
}
namespace COLLADAFW
{
	class IWriter;
	class Object;
	class Animatable;
	class AnimationList;
	class MorphController;
}

namespace COLLADABU
{
	class URI;
}

namespace COLLADASaxFWL
{
//	class Loader;
	class FileLoader;
	class GeometryMaterialIdInfo;
	class SidTreeNode;
	class SidAddress;
    class RootParser14;
    class RootParser15;
    class IParserImpl;
	class IntermediateTargetable;

    /** Base class for all loaders that load parts of files or entire files */
    class IFilePartLoader : public ExtraDataLoader
	{
	public:

        friend class RootParser14;
        friend class RootParser15;

	private:

		/** The currently working file part loader.*/
		IFilePartLoader* mPartLoader;

        /** Object derived from a generated parser. */
        IParserImpl* mParserImpl;

    public:

        /** Constructor. */
        IFilePartLoader();

        /** Destructor. */
        virtual ~IFilePartLoader();

		/** Returns a pointer to the collada loader. */
		virtual Loader* getColladaLoader() =0;

		/** Returns a const pointer to the collada document. */
		virtual const Loader* getColladaLoader()const =0;

		/** Returns the writer the data will be written to.*/
		COLLADAFW::IWriter* writer();

		/** Reports an error to the error handler. If this method returns true, the 
		loader stops parsing immediately. If severity is not CRITICAL and this method 
		returns true, the loader continues loading. */
		bool handleFWLError( const SaxFWLError& saxFWLError );

		/** Reports an error to the error handler. If this method returns true, the 
		loader stops parsing immediately. If severity is not CRITICAL and this method 
		returns true, the loader continues loading. 
		@param errorType The type of the error.
		@param errorMessage The error message describing the error.
		@param reportLineAndColumnNumber If true, the current line and number of the xml parser are set.
		@param severity The severity of the error. */
		bool handleFWLError( SaxFWLError::ErrorType errorType, 
			              String errorMessage,
			              IError::Severity severity = IError::SEVERITY_ERROR_NONCRITICAL );

		/** Returns the COLLADAFW::UniqueId of the element with uri @a uriString. If the uri has been
		passed to this method before, the same 	COLLADAFW::UniqueId will be returned, if not, a
		new one is created.
		@param uriString The uriString of the element to get the COLLADAFW::UniqueId for
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		const COLLADAFW::UniqueId& createUniqueId(const String& uriString, COLLADAFW::ClassId classId);

		/** Returns the COLLADAFW::UniqueId of the element with uri @a uri. If the uri has been
		passed to this method before, the same 	COLLADAFW::UniqueId will be returned,  if not, an 
		invalid unique id will be returned.
		@param uriString The uriString of the element to get the COLLADAFW::UniqueId for
		@return The elements COLLADAFW::UniqueId or COLLADAFW::UniqueId::INVALID*/
		const COLLADAFW::UniqueId& getUniqueIdByUrl(const String& uriString);

		/** Returns the COLLADAFW::UniqueId of the element with id  @a colladaId in the current file.
		If the id within this file has been passed to this method before, the same 	COLLADAFW::UniqueId
		will be returned, if not, a new one is created.
		@param id The collada id of the element to get the COLLADAFW::UniqueId for
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		COLLADAFW::UniqueId createUniqueIdFromId( const ParserChar* colladaId, COLLADAFW::ClassId classId );

		/** Returns the COLLADAFW::UniqueId of the element with id @a colladaId  in the current document. If the 
		colladaId has been	passed to this method before while in the same file, the same COLLADAFW::UniqueId will 
		be returned, if not, an invalid unique id will be returned.
		@param id The id of the element to get the COLLADAFW::UniqueId for
		@return The elements COLLADAFW::UniqueId or COLLADAFW::UniqueId::INVALID*/
		const COLLADAFW::UniqueId& getUniqueIdById(const ParserChar* colladaId);

		/** Returns the COLLADAFW::UniqueId of the element referenced by the url  @a url. If the has
		been passed to this method before, the same COLLADAFW::UniqueId will be returned, if not,
		a new one is created.
		@param url The url of the element to get the COLLADAFW::UniqueId for
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		const COLLADAFW::UniqueId& createUniqueIdFromUrl( const ParserChar* url, COLLADAFW::ClassId classId );

		/** Returns the COLLADAFW::UniqueId of the element referenced by the url  @a url. If the has
		been passed to this method before, the same COLLADAFW::UniqueId will be returned, if not,
		a new one is created.
		@param url The url of the element to get the COLLADAFW::UniqueId for
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@param isAbsolute If true, the url is assumed to be absolute, otherwise it will be made absolute 
		using the current file urie.
		@return The elements COLLADAFW::UniqueId */
		const COLLADAFW::UniqueId& createUniqueIdFromUrl( const COLLADABU::URI& url, COLLADAFW::ClassId classId, bool isAbsolute = false );

		/** Returns the COLLADAFW::UniqueId of the element referenced by the url  @a url. If the has
		been passed to this method before, the same COLLADAFW::UniqueId will be returned,   if not, an 
		invalid unique id will be returned.
		@param uriString The uriString of the element to get the COLLADAFW::UniqueId for
		@param isAbsolute If true, the url is assumed to be absolute, otherwise it will be made absolute 
		using the current file uri.
		@return The elements COLLADAFW::UniqueId or COLLADAFW::UniqueId::INVALID*/
		const COLLADAFW::UniqueId& getUniqueIdByUrl( const COLLADABU::URI& url, bool isAbsolute = false  );

		/** Returns the COLLADAFW::UniqueId of an element with no uri.  At each call a new
		COLLADAFW::UniqueId will be created and returned. Use this member for collada elements that
		do not have an id.
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		COLLADAFW::UniqueId createUniqueId(COLLADAFW::ClassId classId);

		/** Returns the GeometryMaterialIdInfo to map symbols to ids*/
		GeometryMaterialIdInfo& getMeshMaterialIdInfo( );

		/** Returns TextureMapId for @a semantic. Successive call with same semantic return the same TextureMapId.*/
		COLLADAFW::TextureMapId getTextureMapIdBySematic( const String& semantic );

		/** Creates a new in the sid tree. Call this method for every collada element that has an sid or that has an id 
		and can have children with sids. For every call of this method you have to call addToSidTree() when the element
		is closed.
		@param id The id of the element. Might be 0;
		@param sid The sid of the element. Might be 0;
		*/
		SidTreeNode*  addToSidTree( const char* colladaId, const char* colladaSid );

		/** Creates a new node in the sid tree. Call this method for every collada element that has an sid or that has an id 
		and can have children with sids. For every call of this method you have to call moveUpInSidTree() when the element
		is closed.
		@param id The id of the element. Might be 0;
		@param sid The sid of the element. Might be 0;
		@param target The target assigned to the sid tree node
		*/
		SidTreeNode*  addToSidTree( const char* colladaId, const char* colladaSid, COLLADAFW::Object* target );

		/** Creates a new node in the sid tree. Call this method for every collada element that has an sid or that has an id 
		and can have children with sids. For every call of this method you have to call moveUpInSidTree() when the element
		is closed.
		@param id The id of the element. Might be 0;
		@param sid The sid of the element. Might be 0;
		@param target The target assigned to the sid tree node
		*/
		SidTreeNode*  addToSidTree( const char* colladaId, const char* colladaSid, COLLADAFW::Animatable* target );

		/** Creates a new node in the sid tree. Call this method for every collada element that has an sid or that has an id 
		and can have children with sids. For every call of this method you have to call moveUpInSidTree() when the element
		is closed.
		@param id The id of the element. Might be 0;
		@param sid The sid of the element. Might be 0;
		@param target The target assigned to the sid tree node
		*/
		SidTreeNode*  addToSidTree( const char* colladaId, const char* colladaSid, IntermediateTargetable* target );

		/** Moves one node up in the sid tree. Call this method whenever an element, for which addToSidTree() was
		called, is closed.*/
		void  moveUpInSidTree();

		/** Tries to resolve the a sidaddress. If resolving failed, null is returned.*/
		const SidTreeNode* resolveSid( const SidAddress& sidAddress);

		/** Stores the bindig of an animation to an object, referenced by @a targetSidAddress.*/
		void addToAnimationSidAddressBindings( const AnimationInfo& animationInfo, const SidAddress& targetSidAddress);

		/** Returns the animation list with Unique id @a animationListUniqueId. If it could not be found, a new map 
		entry is created.*/
		COLLADAFW::AnimationList*& getAnimationListByUniqueId( const COLLADAFW::UniqueId& animationListUniqueId);

		/** Adds the pair @a skinDataUniqueId, @a jointSids to mSkinDataJointSidsMap.*/
		void addSkinDataJointSidsPair( const COLLADAFW::UniqueId& skinDataUniqueId, const StringList& sidsOrIds, bool areIds );

		/** Adds the pair @a skinDataUniqueId, @a skinSource to mSkinDataSkinSourceMap.*/
		void addSkinDataSkinSourcePair( const COLLADAFW::UniqueId& skinDataUniqueId, const COLLADABU::URI& skinSource );

		/** Adds @a morphController to the list of morph controllers. The morph controller will be deleted after
		if has been written through the IWriter interface.*/
		void addMorphController( COLLADAFW::MorphController* morphController);

		/** Returns the sids or ids of the nodes used by a skin controller using skin data with unique id 
		@a skinDataUniqueId*/
		const Loader::JointSidsOrIds& getJointSidsOrIdsBySkinDataUniqueId(const COLLADAFW::UniqueId& skinDataUniqueId) const;

		/** Returns the mapping of the Unique generated from the id of the COLLADA controller element to the 
		InstanceControllerDataList containing all instance controllers that reference the same controller.*/
		const Loader::InstanceControllerDataListMap& getInstanceControllerDataListMap() const ;

		/** Returns the InstanceControllerDataList of the controller with Unique @a controllerUniqueId.*/
		const Loader::InstanceControllerDataList& getInstanceControllerDataListByControllerUniqueId(const COLLADAFW::UniqueId& controllerUniqueId)const;

		/** Returns the InstanceControllerDataList of the controller with Unique @a controllerUniqueId.*/
		Loader::InstanceControllerDataList& getInstanceControllerDataListByControllerUniqueId(const COLLADAFW::UniqueId& controllerUniqueId);


		/** After this functions, the next sax callback should be caught by this the file part loader.*/
		void setMeAsParser();

        /** Sets the parser to @a parserToBeSet.*/
        virtual void setParser( COLLADASaxFWL14::ColladaParserAutoGen14* parserToBeSet )=0;
        /** Sets the parser to @a parserToBeSet.*/
        virtual void setParser( COLLADASaxFWL15::ColladaParserAutoGen15* parserToBeSet )=0;

        /** Sets abstract parser implementation. */
        void setParserImpl( IParserImpl* parserImpl ){mParserImpl = parserImpl;}
        /** Returns currently set parser implementation. */
        IParserImpl* getParserImpl(){return mParserImpl;}

		/** Sets the part loader.*/
		void setPartLoader(IFilePartLoader* partLoader){mPartLoader=partLoader;}
		const IFilePartLoader* getPartLoader() const {return mPartLoader;}

		/** Returns the absolute uri of the currently parsed file*/
		virtual const COLLADABU::URI& getFileUri()=0;

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


        /** Starts loading a extra tag. */
        virtual bool begin__technique( const technique__AttributeData& attributeData );

		virtual bool end__technique();


	protected:
		/** Deletes the part loader mPartLoader, if it is not needed anymore. Always call this method,
		when creating a new FilePartLoader and switching to it.*/
		void deleteFilePartLoader();

	private:

        /** Disable default copy ctor. */
		IFilePartLoader( const IFilePartLoader& pre );

        /** Disable default assignment operator. */
		const IFilePartLoader& operator= ( const IFilePartLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_IFILEPARTLOADER_H__
