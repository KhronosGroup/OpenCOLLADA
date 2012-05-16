/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_POSTPROCESSOR_H__
#define __COLLADASAXFWL_POSTPROCESSOR_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLDocumentProcessor.h"


namespace COLLADASaxFWL
{

    /** TODO Documentation */
	class PostProcessor : public DocumentProcessor 
	{
	private:
	
	public:
		/** Constructor.
		@param colladaLoader The collada loader this file loader is being used by. Used to retrieve document 
		global properties.
		@param saxParserErrorHandler The error handler all sax parser errors should be passed to.
		@param objectFlags Flags (Loader::ObjectFlags) of objects that should be parsed. Set these 
		if you don't want to parse the entire file, but only those parts required to create the objects in 
		objectFlags.
		@param parsedObjectFlags Flags (Loader::ObjectFlags) of objects already parsed by @a colladaLoader. 
		Will be set to all objects parsed after a call of load().*/
		PostProcessor( Loader* colladaLoader, 
			           SaxParserErrorHandler* saxParserErrorHandler, 
			           int objectFlags,
			           int& /*[in,out]*/ parsedObjectFlags);


        /** Destructor. */
		virtual ~PostProcessor();

		/** Performs all the required post processing.:*/
		void postProcess();

		/**************   should be removed after a redesign of IFileLoader **********/

		/** Sets the parser to @a parserToBeSet.*/
		virtual void setParser( COLLADASaxFWL14::ColladaParserAutoGen14* parserToBeSet ){ COLLADABU_ASSERT(false);}
		/** Sets the parser to @a parserToBeSet.*/
		virtual void setParser( COLLADASaxFWL15::ColladaParserAutoGen15* parserToBeSet ){ COLLADABU_ASSERT(false);}
		/** Returns the absolute uri of the currently parsed file*/
		virtual const COLLADABU::URI& getFileUri(){ COLLADABU_ASSERT(false); return COLLADABU::URI::INVALID; }

		/****************************************************************************/


	private:

		/** Writes all the visual scenes.*/
		void writeVisualScenes();

		/** Writes all the library nodes.*/
		void writeLibraryNodes();

		/** Writes all the effects.*/
		void writeEffects();

		/** Writes all the lights.*/
		void writeLights();

		/** Writes all the cameras.*/
		void writeCameras();

		/** Creates all the animation lists.*/
		void createMissingAnimationLists();

		/** Stores the binding stored in @a binding in the appropriate animation list*/
		void createMissingAnimationList( const Loader::AnimationSidAddressBinding& binding );


		/** Writes all the morph controllers, stored in the loaders morph controller list.*/
		bool writeMorphControllers();

		/** Writes all animation lists.*/
		void writeAnimationLists();

		void linkAndWriteFormulas();

		/** Creates and writes the kinematics scene.*/
		void createAndWriteKinematicsScene();


		/** Returns a pointer to the file loader. */
		virtual FileLoader* getFileLoader() { return 0; }

		/** Returns a pointer to the file loader. */
		virtual const FileLoader* getFileLoader() const { return 0; }


        /** Disable default copy ctor. */
		PostProcessor( const PostProcessor& pre );

        /** Disable default assignment operator. */
		const PostProcessor& operator= ( const PostProcessor& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_POSTPROCESSOR_H__
