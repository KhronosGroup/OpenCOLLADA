/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_WRITER_H__
#define __COLLADA_MAYA_WRITER_H__

#include "COLLADAMayaPrerequisites.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWVisualScene.h"
#include "COLLADAFWGeometry.h"


namespace COLLADAMaya
{
    class DocumentImporter;


    class Writer : public COLLADAFW::IWriter 
	{
	private:
	
        /** Pointer to the current document importer. */
        DocumentImporter* mDocumentImporter;

	public:

        /** Constructor. */
        Writer () {};

        /** Constructor. */
        Writer ( DocumentImporter* documentImporter ) : mDocumentImporter ( documentImporter ) {};

        /** Destructor. */
		virtual ~Writer () {};

        /** This method will be called if an error in the loading process occurred and the loader cannot
        continue to to load. The writer should undo all operations that have been performed.
        @param errorMessage A message containing informations about the error that occurred.
        */
        virtual void cancel ( const String& errorMessage );

        /** This is the method called. The writer hast to prepare to receive data.*/
        virtual void start ();

        /** This method is called after the last write* method. No other methods will be called after this.*/
        virtual void finish ();

        /** When this method is called, the writer must write the entire visual scene.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeVisualScene ( const COLLADAFW::VisualScene* visualScene );

        /** When this method is called, the writer must write the geometry.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeGeometry ( const COLLADAFW::Geometry* geometry );

	private:

        /** Disable default copy ctor. */
		Writer( const Writer& pre );
        
        /** Disable default assignment operator. */
		const Writer& operator= ( const Writer& pre );

	};
	
} // namespace COLLADADH

#endif // __COLLADA_MAYA_WRITER_H__
