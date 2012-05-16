/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libftoa.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "performanceTest.h"

#include "Commonftoa.h"
#include "Commondtoa.h"
#include "math.h"

#include <iostream>

#include <sys/types.h>
#include <sys/timeb.h> 


void performanceTest()
{

	std::string mLocale = setlocale(LC_NUMERIC, 0);
	setlocale(LC_NUMERIC, "C");

	char testString[] = "01234";

	float testFloat = 0;
	double testDouble = 1.23456;

#pragma warning(disable: 4996)
	_timeb startTimeBuffer;
	_ftime( &startTimeBuffer );
	double startTime = (double)startTimeBuffer.time + (double)startTimeBuffer.millitm / 1000;


	char ftoaBuffer[Common::FTOA_BUFFERSIZE];
	static float sum = 0 ;
	static int sumi = 0;

	for ( size_t i= 0; i < 10000000 ; ++i)
	{


		int bytesWritten;

//		bytesWritten=sprintf(ftoaBuffer, "%g", testFloat);

//		bytesWritten=sprintf(ftoaBuffer, "%.16f", testDouble);

//		bytesWritten = Common::ftoa(testFloat, ftoaBuffer);

		bytesWritten = Common::dtoa(testDouble, ftoaBuffer);

		sumi += bytesWritten;

	}


	setlocale(LC_NUMERIC, mLocale.c_str());
	_timeb endTimeBuffer;
	_ftime(&endTimeBuffer);
#pragma warning(default: 4996)

	double endTime = (double)endTimeBuffer.time + (double)endTimeBuffer.millitm / 1000;

	std::cout << std::endl << "time elapsed: " << endTime - startTime << std::endl;

};