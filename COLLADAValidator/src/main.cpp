#include "Writer.h"

#include <iostream>
#include <string>

#include "ValidationErrorHandler.h"

#include "COLLADASaxFWLLoader.h"

#include "GeneratedSaxParserCoutErrorHandler.h"

#include "COLLADAFWRoot.h"

 



void parse(char* fileName)
{
	ValidationErrorHandler errorHandler;
	COLLADASaxFWL::Loader loader(&errorHandler);

	Writer writer;

	COLLADAFW::Root root(&loader, &writer);

	root.loadDocument(fileName); 

}




int main(int argc, char* argv[]) 
{

	if ( argc > 1 ) 
	{
		parse( argv[1]);
	}
	else
	{
		std::cout << "Usage: COLLADAValidator <filename>." << std::endl;
	}
}