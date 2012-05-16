/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libftoa.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "ftoaUnitTest.h"

#include "Commonftoa.h"

#include <iostream>
#include <limits>

static int errroCount = 0;


char ftoaBuffer[Common::FTOA_BUFFERSIZE];


static bool testFloat(float f, char* expectedString)
{
	int bytesWritten = Common::ftoa(f, ftoaBuffer);

	if ( strcmp( ftoaBuffer, expectedString) == 0)
	{
		std::cout << "match                 " << f << ":           " << ftoaBuffer << std::endl;
		return true;
	}
	else
	{
		std::cout << "      don't match     " << f << ":           " << ftoaBuffer << " and " <<  expectedString << std::endl;
		errroCount++;
		return false;
	}
}

bool ftoaUnitTest()
{
	std::cout << "ftoaUnitTest()" << std::endl;
	std::cout << std::endl;

	testFloat(std::numeric_limits<float>::infinity(),"INF");
	testFloat(-std::numeric_limits<float>::infinity(),"-INF");
	testFloat(std::numeric_limits<float>::quiet_NaN(),"NaN");
	testFloat(0,                 "0");
	testFloat(1,                 "1");
	testFloat(1.0,               "1");
	testFloat(1.00001f,           "1.00001");
	testFloat(1.00001e7f,         "1.00001e7");
	testFloat(1.234567f,          "1.234567");
	testFloat(123456,            "123456");
	testFloat(1234567,           "1.23457e6");
	testFloat(1234567e23f,        "1.23457e29");
	testFloat(1234567e-23f,       "1.23457e-17");
	testFloat(123456.789f,        "123456.8");

	std::cout << std::endl;
	std::cout << std::endl;

	testFloat(-1,                 "-1");
	testFloat(-1.0,               "-1");
	testFloat(-1.00001f,           "-1.00001");
	testFloat(-1.00001e7f,         "-1.00001e7");
	testFloat(-123456,            "-123456");
	testFloat(-1234567,           "-1.23457e6");
	testFloat(-1234567e23f,        "-1.23457e29");
	testFloat(-1234567e-23f,       "-1.23457e-17");
	testFloat(-123456.789f,        "-123456.8");

	std::cout << std::endl;
	std::cout << std::endl;

	testFloat(999999,             "999999");
	testFloat(999999.9f,           "1e6");
	testFloat(0.0001f,             "10e-5");
	testFloat(0.00010006f,         "1.0006e-4");
	testFloat(0.000098f,           "9.8e-5");

	std::cout << std::endl;
	std::cout << std::endl;

	testFloat(-999999,            "-999999");
	testFloat(-999999.9f,          "-1e6");
	testFloat(-0.0001f,            "-10e-5");
	testFloat(-0.000098f,          "-9.8e-5");

	std::cout << std::endl;
	std::cout << std::endl;

	testFloat(0.00001f,             "10e-6");
	testFloat(0.0001f,              "10e-5");
	testFloat(0.001f,               "0.000999987");
	testFloat(0.01f,                "0.00999999");
	testFloat(0.1f,                 "0.1");
	testFloat(1,                   "1");
	testFloat(1,                   "1");
	testFloat(10,                  "10");
	testFloat(100,                 "100");
	testFloat(1000,                "1000");
	testFloat(10000,               "10000");
	testFloat(100000,              "100000");
	testFloat(1000000,             "1e6");

	std::cout << std::endl;
	std::cout << std::endl;

	return errroCount == 0;
}