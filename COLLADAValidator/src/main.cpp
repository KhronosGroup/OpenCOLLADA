#include "Writer.h"

#include <iostream>
#include <string>

#include "ValidationErrorHandler.h"

#include "COLLADASaxFWLLoader.h"

#include "GeneratedSaxParserCoutErrorHandler.h"

#include "COLLADAFWRoot.h"

#ifdef WIN32
#   if defined(XMLPARSER_LIBXML)
        const char* programName = "COLLADAValidator_LibXML.exe";
#   elif defined(XMLPARSER_EXPAT)
        const char* programName = "COLLADAValidator_Expat.exe";
#   else
#	    error "No prepocesser flag set to chose the xml parser to use"
#   endif
#else
    const char* programName = "COLLADAValidator.exe";
#endif


COLLADASaxFWL::COLLADAVersion version = COLLADASaxFWL::COLLADA_UNKNOWN;

void parse(char* fileName, ValidationErrorHandler& errorHandler)
{
	COLLADASaxFWL::Loader loader(&errorHandler);

	Writer writer;

	COLLADAFW::Root root(&loader, &writer);

	root.loadDocument(fileName);
	version = loader.getCOLLADAVersion();
}

void printHelpText()
{
	std::cout << "Version 1.1.3" << std::endl;
	std::cout << "Usage: " << programName << " <filename>." << std::endl;
}


int main(int argc, char* argv[]) 
{
	if ( argc > 1 ) 
	{
		ValidationErrorHandler errorHandler;

		parse( argv[1], errorHandler);

		if ( errorHandler.getFileNotFound() )
		{
			printHelpText();
			return -2;
		} 
		
		if ( errorHandler.hasHandledSaxParserError() )
		{
			return -1;
		}
		else
		{
			std::cout << "\"" << argv[1]<< "\" is valid against the COLLADA ";
			switch ( version )
			{
			case COLLADASaxFWL::COLLADA_14:
				std::cout << "1.4.1";
				break;
			case COLLADASaxFWL::COLLADA_15:
				std::cout << "1.5.0";
				break;
			}
			std::cout << " schema." << std::endl;
			return 0;
		}
	}
	else
	{
		printHelpText();
		return 0;
	}

}