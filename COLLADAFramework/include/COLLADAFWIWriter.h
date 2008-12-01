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
	class VisualScene;
	class Geometry;

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

		/** When this method is called, the writer must write the entire visual scene.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeVisualScene ( const VisualScene* visualScene ) = 0;

		/** When this method is called, the writer must write the geometry.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeGeometry ( const Geometry* geometry ) = 0;


	private:

        /** Disable default copy ctor. */
		IWriter ( const IWriter& pre );

        /** Disable default assignment operator. */
		const IWriter& operator= ( const IWriter& pre );

	};
} // namespace COLLADAFW

#endif // __COLLADAFW_IWRITER_H__
