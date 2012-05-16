/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libftoa.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "itoaUnitTest.h"

#include "Commonitoa.h"

#include <iostream>

static int errroCount = 0;


template<class IntegerType>
static bool testInt(IntegerType i, char* expectedString)
{

	char itoaBuffer[Common::Itoa<IntegerType>::MINIMUM_BUFFERSIZE_10];

	size_t bytesWritten = Common::itoa<IntegerType>(i, itoaBuffer, 10);

	if ( strcmp( itoaBuffer, expectedString) == 0)
	{
		std::cout << "match                 " << i << ":           " << itoaBuffer << std::endl;
		return true;
	}
	else
	{
		std::cout << "      don't match     " << i << ":           " << itoaBuffer << " and " <<  expectedString << std::endl;
		errroCount++;
		return false;
	}
}

bool itoaUnitTest()
{
	std::cout << "itoaUnitTest()" << std::endl;
	std::cout << std::endl;

	testInt<char>(123                ,"123");
	testInt<char>(-123               ,"-123");
	testInt<unsigned char>(123       ,"123");
	testInt<short>(12345             ,"12345");
	testInt<short>(-12345            ,"-12345");
	testInt<unsigned short>(12345    ,"12345");

	return errroCount == 0;
}
