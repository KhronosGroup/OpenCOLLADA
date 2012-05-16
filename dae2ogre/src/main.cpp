/*
Copyright (c) 2009 NetAllied Systems GmbH

This file is part of dae2ogre.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2OgrePrerequisites.h"
#include "DAE2OgreOgreWriter.h"

#include <iostream>
#include "COLLADABUURI.h"

#if defined(WIN32) && !defined(NDEBUG)
#	include <crtdbg.h> 
#endif

int main(int argc, char* argv[]) 
{

#if defined(WIN32) && !defined(NDEBUG)
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF ); 
#endif

	if ( argc > 2 ) 
	{

		DAE2Ogre::String inputFile = argv[1];
		DAE2Ogre::String outputFile = argv[2];

		DAE2Ogre::OgreWriter writer( COLLADABU::URI::nativePathToUri(inputFile), COLLADABU::URI::nativePathToUri(outputFile));
		writer.write();

	
	}
	else
	{
		std::cout << "You must specify an input and output file name" << std::endl;

		std::cout << "Usage: dae2ogre <inputfilename> <outputfilename>" << std::endl;
	}
}