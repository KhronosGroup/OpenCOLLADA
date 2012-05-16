/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef ___G3D_FILEUNZIPPER_H__
#define ___G3D_FILEUNZIPPER_H__

#include "G3DPrerequisites.h"
#include <string>


namespace G3D
{
	/** Extracts the model (model.dae) and all the images of a zip file, downloaded from the 
	google 3d Warehouse.*/
	class FileUnzipper 
	{
	private:
		String mLastErrorString;

		String mDAEFilePath;

		/** True, if unzipping succeeded.*/
		bool mSucceeded;
	
	public:
		/** Constructor. Extracts the model and the images contained in @a zipFile into the
		directory @a extractPath. @a extractPath must exist.*/
		FileUnzipper( const String& zipFile,  const String& extractPath );
		virtual ~FileUnzipper();

		/** Returns the path to the model.dae file.*/
		String getDAEFilePath() const { return mDAEFilePath; };

		/** True, if unzipping succeeded.*/
		bool getSucceeded() const { return mSucceeded; }

		/** Returns the error string of the last error that occurred.*/
		const String& getLastErrorString() const { return mLastErrorString; }
	
	
		// private function declarations
	private:
        /** Disable default copy ctor. */
		FileUnzipper( const FileUnzipper& pre );
        /** Disable default assignment operator. */
		const FileUnzipper& operator= ( const FileUnzipper& pre );

		bool unzipFile( const String& zipFile,  const String& extractPath );

	};
} // namespace 

#endif // ___G3D_FILEUNZIPPER_H__
