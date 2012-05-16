/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libftoa.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "dtoaUnitTest.h"

#include "Commondtoa.h"

#include <iostream>
#include <limits>

static int errroCount = 0;


char dtoaBuffer[Common::DTOA_BUFFERSIZE];


static bool testDouble(double d, char* expectedString, bool doublePrecision = false)
{
	int bytesWritten = Common::dtoa(d, dtoaBuffer, doublePrecision);

	std::streamsize oldPrecision = 0;
	if ( doublePrecision )
	{
		oldPrecision = std::cout.precision(16);
	}

	if ( strcmp( dtoaBuffer, expectedString) == 0)
	{
		std::cout << "match                 " << d << ":           " << dtoaBuffer << std::endl;
		return true;
	}
	else
	{
		std::cout << "      don't match     " << d << ":           " << dtoaBuffer << " and " <<  expectedString << std::endl;
		errroCount++;
		return false;
	}

	if ( doublePrecision )
	{
		std::cout.precision(oldPrecision);
	}

}

bool dtoaUnitTest()
{
	std::cout << "dtoaUnitTest()" << std::endl;
	std::cout << std::endl;

	testDouble(std::numeric_limits<double>::infinity(),"INF");
	testDouble(-std::numeric_limits<double>::infinity(),"-INF");
	testDouble(std::numeric_limits<double>::quiet_NaN(),"NaN");
	testDouble(0,                 "0");
	testDouble(1,                 "1");
	testDouble(1.0,               "1");
	testDouble(1.00001,           "1.00001");
	testDouble(1.00001e7,         "1.00001e7");
	testDouble(1.234567,          "1.234567");
	testDouble(123456,            "123456");
	testDouble(1234567,           "1.23457e6");
	testDouble(1234567e23,        "1.23457e29");
	testDouble(1234567e-23,       "1.23457e-17");
	testDouble(123456.789,        "123456.8");

	std::cout << std::endl;
	std::cout << std::endl;

	testDouble(-1,                 "-1");
	testDouble(-1.0,               "-1");
	testDouble(-1.00001,           "-1.00001");
	testDouble(-1.00001e7,         "-1.00001e7");
	testDouble(-123456,            "-123456");
	testDouble(-1234567,           "-1.23457e6");
	testDouble(-1234567e23,        "-1.23457e29");
	testDouble(-1234567e-23,       "-1.23457e-17");
	testDouble(-123456.789,        "-123456.8");

	std::cout << std::endl;
	std::cout << std::endl;

	testDouble(999999,             "999999");
	testDouble(999999.9,           "10e5");
	testDouble(0.0001,             "10e-5");
	testDouble(0.00010006,         "1.0006e-4");
	testDouble(0.000098,           "9.8e-5");

	std::cout << std::endl;
	std::cout << std::endl;

	testDouble(-999999,            "-999999");
	testDouble(-999999.9,          "-10e5");
	testDouble(-0.0001,            "-10e-5");
	testDouble(-0.000098,          "-9.8e-5");

	std::cout << std::endl;
	std::cout << std::endl;

	testDouble(0.00001,             "10e-6");
	testDouble(0.0001,              "10e-5");
	testDouble(0.001,               "10e-4");
	testDouble(0.01,                "0.01");
	testDouble(0.1,                 "0.1");
	testDouble(1,                   "1");
	testDouble(1,                   "1");
	testDouble(10,                  "10");
	testDouble(100,                 "100");
	testDouble(1000,                "1000");
	testDouble(10000,               "10000");
	testDouble(100000,              "100000");
	testDouble(1000000,             "1e6");


	std::cout << std::endl;
	std::cout << "double precision" << std::endl;
	testDouble(123456789012345678,          "1.234567890123457e17", true);
	testDouble(1.23456789012345678,          "1.234567890123457", true);
	testDouble(0.00000000000000000000000023456789012345678,          "2.345678901234568e-25", true);
	testDouble(0.00000000000000000000000000000000000000000000000023456789012345678,          "2.345678901234568e-49", true);
	testDouble(0.9999999999999999,          "0.9999999999999998", true);

	std::cout << std::endl;
	std::cout << std::endl;

	return errroCount == 0;
}