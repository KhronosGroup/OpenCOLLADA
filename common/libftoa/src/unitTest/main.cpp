/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libftoa.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "Commonftoa.h"
#include "Commondtoa.h"
#include "Commonitoa.h"
#include "ftoaUnitTest.h"
#include "dtoaUnitTest.h"
#include "itoaUnitTest.h"

#include <stdio.h>


int main()
{

	unsigned long long i = 0xFFFFFFFFFFFFFFFF;

	char ftoaBuffer[Common::FTOA_BUFFERSIZE];
	char dtoaBuffer[Common::DTOA_BUFFERSIZE];

	float testFloat = 1.23456789012345678f;
	double testDouble = 1.23456789012345678;
//	double testDouble = 1E67;

//	printf("%g", testDouble);

//	int fBytesWritten = Common::ftoa(testFloat, ftoaBuffer);
	int dBytesWritten = Common::dtoa(testDouble, dtoaBuffer, true);

//	ftoaUnitTest();
//	dtoaUnitTest();

	itoaUnitTest();

	return 0;
}