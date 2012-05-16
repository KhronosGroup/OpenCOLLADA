/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_FILE_TRANSLATOR_H__
#define __COLLADA_MAYA_FILE_TRANSLATOR_H__

//#include "vld.h"
//#include <crtdbg.h> 

#ifndef _MPxFileTranslator
#include <maya/MPxFileTranslator.h>
#endif // _MPxFileTranslator


namespace COLLADAMaya
{
    /**
     * The main class for the maya plug-in.
     */
    class FileTranslator : public MPxFileTranslator
    {

    public:

        static const String ASCII_PATH_EXTENSION;
        static const String ASCII_PATH_EXTENSION_DEBUG;

    private:

        /** Name of the current scene. */
        MString sceneName;

        /** Flag, if just the selection should be exported. */
        bool exportSelection;

        /** Flag, if we do an import. */
        bool isImporter;

        static uint readDepth;

    public:

        /**
         * Constructor
         * @param isImporter True, if we want to import.
         */
        FileTranslator ( bool isImporter );
        virtual ~FileTranslator();
        
        /**
         * Create a new instance of the translator
         * This method is registered to Maya's plugin module in the initializePlugin function.
         */
        static void* createImporter();
        
        /**
         * Create a new instance of the translator
         * This method is registered to Maya's plugin module in the initializePlugin function.
         */
        static void* createExporter();

        /**
         * The reader() method reads each line of the file and returns a
         * MS::kFailure if it cannot be opened by the translator. If a file type
         * cannot be recognized by the translator, the method creates a new
         * object via MEL to support the data in that file.
         * @param & The file object
         * @param optionsString String with the options
         * @param mode Mode of file access
         * @return MStatus Returns a MS::kFailure if it cannot be opened by the translator
         */
        virtual MStatus reader ( const MFileObject &,
                                 const MString &optionsString,
                                 MPxFileTranslator::FileAccessMode mode );
        
        /**
         * The writer() method provides a message through the script editor and
         * returns a status to indicate the results.
         * In this example, only ‘export all’ and ‘export selection’ options are
         * allowed when trying to save data. Other options will result in the
         * display of a failure message through the script editor and returns a
         * MS:kFailure, which indicates that the file type cannot be understood
         * by the translator.
         * @param & The file object
         * @param optionsString String with the options
         * @param mode Mode of file access
         * @return MStatus Returns a MS:kFailure, which indicates that the file type
         *   cannot be understood by the translator.
         */
        virtual MStatus writer ( const MFileObject &,
                                 const MString &optionsString,
                                 MPxFileTranslator::FileAccessMode mode );

        /**
         * The haveReadMethod() method checks if the translator provides a read
         * method. In the LepTranslator class, the method returns true because
         * the reader() method exists.
         * @return bool True, if it is an importer.
         */
        virtual bool haveReadMethod() const
        {
            return isImporter;
        }

        /**
         * The haveWriteMethod() method checks if the translator has a write
         * method. In the polyExporter class, the method returns true because
         * the writer() method is implemented.
         * @return bool True, if it is an exporter.
         */
        virtual bool haveWriteMethod() const
        {
            return !isImporter;
        }

        /**
         * Return the default extension for COLLADA files.
         * @return MString Default extension for COLLADA files
         */
        MString defaultExtension() const;

        /**
         * Returns valid file extension.
         * @return MString Valid file extensions.
         */
        MString filter() const;

        /**
         * Check the given file to see if it is COLLADA data
         * @param fileObject The file object.
         * @param buffer File buffer
         * @param size File size
         * @return MFileKind Kind of file.
         */
        virtual MFileKind identifyFile ( const MFileObject &fileObject, const char *buffer, short size ) const;

    private:
        /**
         * Parses the Maya DAG/DG graphs and writes out a COLLADA document.
         * @param filename Name of the collada file.
         * @return MStatus Status of export.
         */
        MStatus exportIntoFile ( const MString& filename, const bool selectionOnly );

        /**
         * Parses the COLLADA document and generates the Maya structures.
         * @param filename The collada document name to read in.
         * @return MStatus Error, if something went wrong.
         */
        MStatus importFromFile ( const String& filename );

    };

}

#endif //__COLLADA_MAYA_FILE_TRANSLATOR_H__
