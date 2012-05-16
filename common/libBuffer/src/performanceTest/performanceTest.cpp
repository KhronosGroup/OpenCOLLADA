/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "performanceTest.h"

#include "CommonCharacterBuffer.h"
#include "CommonFWriteBufferFlusher.h"
#include "CommonStreamBufferFlusher.h"
#include "math.h"

#include <iostream>
 #include <errno.h>

#include <sys/types.h>
#include <sys/timeb.h> 


#ifdef WIN32
#   define FPRINTF fprintf_s
#else
#   define FPRINTF fprintf
#endif



void performanceTest()
{

	const size_t BUFFERSIZE = /*1024**/1024*64;
	char *mBuffer = new char[BUFFERSIZE];
	FILE* stream;
	std::string mLocale = setlocale(LC_NUMERIC, 0);
	setlocale(LC_NUMERIC, "C");


#ifdef WIN32
	char fileNameBuffer[] = "c:\\temp\\testBuffer.txt";
	char fileNameFwrite[] = "c:\\temp\\testFwrite.txt";
#else
	char fileNameBuffer[] = "/tmp/testBuffer.txt";
	char fileNameFwrite[] = "/tmp/testFwrite.txt";
#endif
	
	int error = 0;
#ifdef WIN32
	error = fopen_s ( &stream, fileNameFwrite, "wb" );
#else
    stream = fopen( fileNameBuffer, "wb" );
	error = stream ? 0 : errno;
#endif

	bool failed = ( setvbuf ( stream , mBuffer, _IOFBF, BUFFERSIZE ) != 0 );



	Common::FWriteBufferFlusher bufferFlusher(fileNameBuffer, BUFFERSIZE);
//	Common::StreamBufferFlusher bufferFlusher(fileNameBuffer, BUFFERSIZE);
	Common::CharacterBuffer buffer(64*BUFFERSIZE, &bufferFlusher);
	buffer.setDirectFlushSize( 40 );


//	char testString[] = "01234567890123456789012345678901234567890123456789";
	char testString[] = "1.23456";
	char testChar = '1';


	float testFloat = 1.23456;
	double testDouble = 1;

	int testInt = 123;

#ifdef WIN32
#pragma warning(disable: 4996)
	_timeb startTimeBuffer;
	_ftime( &startTimeBuffer );
#pragma warning(default: 4996)
#else
	timeb startTimeBuffer;
	ftime( &startTimeBuffer );
#endif

	double startTime = (double)startTimeBuffer.time + (double)startTimeBuffer.millitm / 1000;


	for ( size_t i= 0; i < 100000000; ++i)
	{
//		fwrite( testString, sizeof(char), sizeof(testString)-1, stream);

//	    FPRINTF( stream, "%g", testFloat);

//		FPRINTF( stream, "%g", testDouble);

//		FPRINTF( stream, "%d", testInt);

		buffer.copyToBufferAsChar( testFloat );

//		buffer.copyToBufferAsChar( testDouble );

//		buffer.copyToBufferAsChar( testInt );

//		buffer.copyToBuffer( testString, sizeof(testString)-1);
//		buffer.copyToBuffer( testChar);
	}


#ifdef WIN32
#pragma warning(disable: 4996)
	_timeb endTimeBuffer;
	_ftime(&endTimeBuffer);
#pragma warning(default: 4996)
#else
	timeb endTimeBuffer;
	ftime(&endTimeBuffer);
#endif




	fclose ( stream );

	delete[] mBuffer;

	double endTime = (double)endTimeBuffer.time + (double)endTimeBuffer.millitm / 1000;

	std::cout << std::endl << "time elapsed: " << endTime - startTime << std::endl;

};
