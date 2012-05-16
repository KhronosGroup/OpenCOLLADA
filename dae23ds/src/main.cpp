/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE23dsStableHeaders.h"

#include "DAE23dsPrerequisites.h"

#include "DAE23dsWriter.h"

#include "COLLADABUURI.h"

#include <iostream>
#include <sys/types.h>
#include <sys/timeb.h>


int main(int argc, char* argv[]) 
{
	if ( argc > 2 ) 
	{

 		DAE23ds::String inputFile = argv[1];
 		DAE23ds::String outputFile = argv[2];

#pragma warning(disable: 4996)
		_timeb startTimeBuffer;
		_ftime( &startTimeBuffer );
		double startTime = (double)startTimeBuffer.time + (double)startTimeBuffer.millitm / 1000;


//		DAE23ds::Writer writer( COLLADABU::URI::nativePathToUri(inputFile), COLLADABU::URI::nativePathToUri(outputFile), false);
		DAE23ds::Writer writer( COLLADABU::URI::nativePathToUri(inputFile), COLLADABU::URI::nativePathToUri(outputFile), true);
		writer.write();


		_timeb endTimeBuffer;
		_ftime(&endTimeBuffer);
#pragma warning(default: 4996)

		double endTime = (double)endTimeBuffer.time + (double)endTimeBuffer.millitm / 1000;

		std::cout << "Time elapsed: " << endTime - startTime  << std::endl;
	
	}
	else
	{
		std::cout << "You must specify an input and output file name" << std::endl;

		std::cout << "Usage: dae23ds <inputfilename> <outputfilename>" << std::endl;
	}
}