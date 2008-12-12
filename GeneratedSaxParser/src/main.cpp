#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserParser.h"
#include "GeneratedSaxParserColladaParser.h"
#include "GeneratedSaxParserLibxmlSaxParser.h"
#include "GeneratedSaxParserUtils.h"

#include <iostream>
#include <string>

#include "GeneratedSaxParserElements.h"
#include "GeneratedSaxParserCoutErrorHandler.h"


void printHash(const char * name)
{
	std::cout << name << ": " << GeneratedSaxParser::Utils::calculateStringHash((GeneratedSaxParser::ParserChar*)name)<< std::endl;
};


void printHashes()
{

//	for ( size_t i = 0; i < elementsCount; ++i)
//		printHash(elements[i].c_str());
	printHash("COLLADA");
	printHash("library_nodes");
	printHash("visual_scene");
	printHash("node");
	printHash("xmlns");
	printHash("version");
	printHash("translate");
	printHash("number");
	printHash("number2");
	printHash("type");
	printHash("NODE");
	printHash("JOINT");
}


void parse()
{
	GeneratedSaxParser::CoutErrorHandler errorHandler;
	GeneratedSaxParser::ColladaParser parser(&errorHandler);
	GeneratedSaxParser::LibxmlSaxParser libxmlSaxParse(&parser);
	bool success = libxmlSaxParse.parseFile("c:\\temp\\test.xml"); 
}



void testToFloat()
{
	static const size_t length = 15 ;
	const GeneratedSaxParser::ParserChar  array[length][length] = {"1 ", "12 ", "1.0 ", "12.2 ", "1223.4545 ", 
													   ".00001 ", "1e10 ", "12.E-12 ", "e10 ", "1. ",
													   ".1 ", ".1e2 ", "1.e2 ", ". ", ".e2 "};
	const GeneratedSaxParser::ParserChar  array2[length][length] = {"1", "12", "1.0", "12.2", "1223.4545", 
														".00001", "1e10", "12.E-12", "e10", "1.",
														".1", ".1e2", "1.e2", ".", ".e2"};

	for ( size_t i = 0; i< length; ++i)
	{
		bool failed = false;
		const GeneratedSaxParser::ParserChar* c = array[i];
		const GeneratedSaxParser::ParserChar* end = array[i];
		while (*end)
			++end;
		std::string str((char*)c);
		std::cout.width(10);
		std::cout << str;
		std::cout.width(10);
		std::cout << "  :  ";
		std::cout.width(10);
		std::cout << GeneratedSaxParser::Utils::toFloat(&c, end, failed);
		std::cout.width(10);
		if ( failed )
			std::cout << "  failed";
		else
			std::cout << "";
		bool failed2 = false;
		std::cout.width(10);
		std::cout << GeneratedSaxParser::Utils::toFloat(array2[i], failed2);
		std::cout.width(10);
		if ( failed2 )
			std::cout << "  failed";
		else
			std::cout << "";
		std::cout.width(10);
		std::cout << atof(str.c_str()) << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	const GeneratedSaxParser::ParserChar prefixedBuffer[10] = "  3";
	const GeneratedSaxParser::ParserChar buffer[10] = "45 ";

	
	bool failed = false;
	const GeneratedSaxParser::ParserChar* bufferPtr = (const GeneratedSaxParser::ParserChar*)buffer;
//	std::cout << COLLADASAXPARSER::Utils::toFloat(prefixedBuffer, &bufferPtr, buffer+ sizeof(buffer), failed) << std::endl;
	if ( failed )
		std::cout << "  failed";
	else
		std::cout << "";

}


void testToInt()
{
	static const size_t length = 5 ;
	const GeneratedSaxParser::ParserChar  array[length][15] = {"1 ", "12 ", " -123 ", "12.2 ", " --34 "};
	const GeneratedSaxParser::ParserChar  array2[length][15] = {"1", "12", " -123", "12.2", " --34"};

	for ( size_t i = 0; i< length; ++i)
	{
		bool failed = false;
		const GeneratedSaxParser::ParserChar* c = array[i];
		const GeneratedSaxParser::ParserChar* end = array[i];
		while (*end)
			++end;
		std::string str((char*)c);
		std::cout.width(10);
		std::cout << str;
		std::cout.width(10);
		std::cout << "  :  ";
		std::cout.width(10);
		std::cout << GeneratedSaxParser::Utils::toInt(&c, end, failed);
		std::cout.width(10);
		if ( failed )
			std::cout << "  failed";
		else
			std::cout << "";
		bool failed2 = false;
		std::cout.width(10);
		std::cout << GeneratedSaxParser::Utils::toInt(array2[i], failed2);
		std::cout.width(10);
		if ( failed2 )
			std::cout << "  failed";
		else
			std::cout << "";
		std::cout.width(10);
		std::cout << atoi(str.c_str()) << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	const GeneratedSaxParser::ParserChar prefixedBuffer[10] = "  3";
	const GeneratedSaxParser::ParserChar buffer[10] = "45 ";


	bool failed = false;
	const GeneratedSaxParser::ParserChar* bufferPtr = (const GeneratedSaxParser::ParserChar*)buffer;
	//	std::cout << GeneratedSaxParser::Utils::toFloat(prefixedBuffer, &bufferPtr, buffer+ sizeof(buffer), failed) << std::endl;
	if ( failed )
		std::cout << "  failed";
	else
		std::cout << "";

}



void testToUInt()
{
	static const size_t length = 5 ;
	const GeneratedSaxParser::ParserChar  array[length][15] = {"1 ", "12 ", " -123 ", "12.2 ", " --34 "};
	const GeneratedSaxParser::ParserChar  array2[length][15] = {"1", "12", " -123", "12.2", " --34"};

	for ( size_t i = 0; i< length; ++i)
	{
		bool failed = false;
		const GeneratedSaxParser::ParserChar* c = array[i];
		const GeneratedSaxParser::ParserChar* end = array[i];
		while (*end)
			++end;
		std::string str((char*)c);
		std::cout.width(10);
		std::cout << str;
		std::cout.width(10);
		std::cout << "  :  ";
		std::cout.width(10);
		std::cout << GeneratedSaxParser::Utils::toUnsignedInt(&c, end, failed);
		std::cout.width(10);
		if ( failed )
			std::cout << "  failed";
		else
			std::cout << "";
		bool failed2 = false;
		std::cout.width(10);
		std::cout << GeneratedSaxParser::Utils::toUnsignedInt(array2[i], failed2);
		std::cout.width(10);
		if ( failed2 )
			std::cout << "  failed";
		else
			std::cout << "";
		std::cout.width(10);
		std::cout << atoi(str.c_str()) << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	const GeneratedSaxParser::ParserChar prefixedBuffer[10] = "  3";
	const GeneratedSaxParser::ParserChar buffer[10] = "45 ";


	bool failed = false;
	const GeneratedSaxParser::ParserChar* bufferPtr = (const GeneratedSaxParser::ParserChar*)buffer;
	//	std::cout << GeneratedSaxParser::Utils::toFloat(prefixedBuffer, &bufferPtr, buffer+ sizeof(buffer), failed) << std::endl;
	if ( failed )
		std::cout << "  failed";
	else
		std::cout << "";

}



int main()
{

		
//	printHashes();
    parse();

	//testToFloat();

//	testToUInt();

}