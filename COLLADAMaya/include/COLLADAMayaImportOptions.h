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

#ifndef __COLLADA_MAYA_IMPORT_OPTIONS_H__
#define __COLLADA_MAYA_IMPORT_OPTIONS_H__

#include <maya/MPxFileTranslator.h>


namespace COLLADAMaya
{

    /**
    * Class which manages the import options.
    */
    class ImportOptions
    {

    private:
        static bool mIsOpenCall;
        static bool mIsReferenceCall;
        static bool mHasError;

        static bool mImportUpAxis;
        static bool mImportUnits;
        static bool mImportNormals;

    public:

        static void set ( const MString &optionsString, MPxFileTranslator::FileAccessMode mode );

        static bool isOpenMode();

        static bool isReferenceMode();

        static bool hasError();

        static bool importUpAxis();

        static bool importUnits();

        static bool importNormals();

        static bool importSoftEdges();

        static void setErrorFlag();

    };

}

#endif // __COLLADA_MAYA_IMPORT_OPTIONS_H__