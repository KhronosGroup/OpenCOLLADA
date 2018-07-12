/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "G3DStableHeaders.h"
#include "G3DFileUnzipper.h"

#include <SYS\Stat.h>
#include <direct.h>

#include "zzip/zzip.h"

#include "COLLADABUStringUtils.h"



namespace G3D
{

	const char IMAGES_DIRECTORY[] = "images";
	const char MODEL_PATH[] = "models/model.dae";
	const char WAREHOUSE_MODEL_PATH[] = "models/warehouse_model.dae";
	const char MODEL_DIR[] = "models";

	const String SLASH("/");
	const String BACKSLASH("\\");



	String unzipFile_( ZZIP_DIR * dir, const ZZIP_DIRENT& d, const String& extractPath, String& errorString )
	{
		ZZIP_FILE* input = zzip_file_open (dir, d.d_name, O_RDONLY);
		if ( !input)
		{  
			errorString = zzip_strerror_of(dir);
			return String();
		}
		String filePath(d.d_name);
		COLLADABU::StringUtils::stringFindAndReplace(filePath, SLASH, BACKSLASH);
		String extractedFilePath = extractPath + filePath;
		FILE* outFile;
		errno_t  error = fopen_s( &outFile, extractedFilePath.c_str(), "wb"  );
		if (error)
		{
			errorString = String("Could not open output file") + d.d_name;
			perror(d.d_name);
			zzip_file_close (input);
			return String();
		}

		{ 
			char buf[17]; zzip_ssize_t n;
			/* read chunks of 16 bytes into buf */
			while (0 < (n = zzip_read (input, buf, 16)))
			{
				fwrite (buf, 1, n, outFile);
			}

			if (n == -1)
				perror (d.d_name);
		}
		fclose (outFile);
		zzip_file_close (input);

		return extractedFilePath;
	}



	//--------------------------------------------------------------------
	FileUnzipper::FileUnzipper( const String& zipFile, const String& extractPath )
	{
		mSucceeded = unzipFile(zipFile, extractPath);
	}

	//--------------------------------------------------------------------
	FileUnzipper::~FileUnzipper()
	{
	}

	//--------------------------------------------------------------------
	bool FileUnzipper::unzipFile( const String& zipFile, const String& extractPath )
	{

		ZZIP_DIR * dir;
		ZZIP_DIRENT d;
		zzip_error_t error;

		dir = zzip_dir_open(zipFile.c_str(), &error);
		if (! dir)
		{
			mLastErrorString = zzip_strerror(error);
			return false;
		}

		/* read each dir entry and show one line of info per file */
		while (zzip_dir_read (dir, &d))
		{

			if ( (strcmp(d.d_name, MODEL_PATH) == 0) || (strcmp(d.d_name, WAREHOUSE_MODEL_PATH) == 0) )
			{
				_mkdir( (extractPath+MODEL_DIR).c_str() );
				mDAEFilePath = unzipFile_(dir, d, extractPath, mLastErrorString);
				continue;
			}


			String filePath(d.d_name);
			size_t separatorPos =  filePath.find_first_of('/');
			String filePathDir(filePath, 0, separatorPos);

			if ( filePathDir == IMAGES_DIRECTORY )
			{
				_mkdir( (extractPath+IMAGES_DIRECTORY).c_str() );
				unzipFile_(dir, d, extractPath, mLastErrorString);
				continue;
			}

		}
		return true;
	}

	/*
	bool FileUnzipper::unzipDirectory( ZZIP_DIR * dir, ZZIP_DIRENT d, const String& extractPath )
	{

	}

	*/




}