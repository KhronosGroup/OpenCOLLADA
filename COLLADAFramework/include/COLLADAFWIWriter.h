/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_IWRITER_H__
#define __COLLADAFW_IWRITER_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{
    class FileInfo;
	class VisualScene;
	class Geometry;
	class LibraryNodes;
	class Material;
	class Effect;
	class Camera;


	/** Class that needs to be implemented by a writer. 
	IMPORTANT: The write functions are called in arbitrary order.*/
	class IWriter 	
	{
	private:
	
	public:

        /** Constructor. */
        IWriter() {};

        /** Destructor. */
        virtual ~IWriter() {};

		/** This method will be called if an error in the loading process occurred and the loader cannot
		continue to to load. The writer should undo all operations that have been performed.
		@param errorMessage A message containing informations about the error that occurred.
		*/
		virtual void cancel(const String& errorMessage)=0;

		/** This is the method called. The writer hast to prepare to receive data.*/
		virtual void start()=0;

		/** This method is called after the last write* method. No other methods will be called after this.*/
		virtual void finish()=0;

        /** When this method is called, the writer must write the global document asset.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeGlobalAsset ( const FileInfo* asset ) = 0;

		/** When this method is called, the writer must write the entire visual scene.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeVisualScene ( const VisualScene* visualScene ) = 0;

		/** When this method is called, the writer must handle all nodes contained in the 
		library nodes.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeLibraryNodes ( const LibraryNodes* libraryNodes ) = 0;

		/** When this method is called, the writer must write the geometry.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeGeometry ( const Geometry* geometry ) = 0;

		/** When this method is called, the writer must write the material.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeMaterial( const Material* material ) = 0;

		/** When this method is called, the writer must write the effect.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeEffect( const Effect* effect ) = 0;

		/** When this method is called, the writer must write the camera.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeCamera( const Camera* camera ) = 0;

	private:

        /** Disable default copy ctor. */
		IWriter ( const IWriter& pre );

        /** Disable default assignment operator. */
		const IWriter& operator= ( const IWriter& pre );

	};
} // namespace COLLADAFW

#endif // __COLLADAFW_IWRITER_H__
