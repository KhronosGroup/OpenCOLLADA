#include <iostream>

#include "ArgumentParser.h"
#include "DaeValidator.h"
#include "Dae.h"
#include "Log.h"
#include "PathUtil.h"
#include "StringUtil.h"

using namespace opencollada;
using namespace std;

namespace opencollada
{
	// Validation options
	const char* checkSchemaAuto = "--check-schema-auto";
	const char* checkSchema = "--check-schema";
	const char* checkUniqueIds = "--check-unique-ids";
	const char* recursive = "--recursive";
	const char* quiet = "--quiet";
	const char* help = "--help";

	const char* colladaNamespace141 = "http://www.collada.org/2005/11/COLLADASchema";
	const char* colladaSchemaFileName141 = "collada_schema_1_4_1.xsd";
	XmlSchema colladaSchema141;

	const char* colladaNamespace15 = "http://www.collada.org/2008/03/COLLADASchema";
	const char* colladaSchemaFileName15 = "collada_schema_1_5.xsd";
	XmlSchema colladaSchema15;
}

int main(int argc, char* argv[])
{
	// Parse arguments
	ArgumentParser argparse(argc, argv);
	argparse.addArgument().hint("path").help("Path to COLLADA document or directory to parse. If 'path' is a directory it is parsed for files with .DAE extension.");
	argparse.addArgument(checkSchemaAuto).help("Regular XML schema validation.");
	argparse.addArgument(checkSchema).numParameters(1).hint(0, "schema_path").help("Validate against given XML schema.");
	argparse.addArgument(checkUniqueIds).help("Check that ids in documents are unique.");
	argparse.addArgument(recursive).help("Recursively parse directories. Ignored if 'path' is not a directory.");
	argparse.addArgument(quiet).help("If set, no output is sent to standard out/err.");
	argparse.addArgument(help).help("Display help.");

	bool argparse_ok = argparse.parseArguments();

	if (argparse.findArgument(help)) {
		cout << argparse.usage() << endl;
		return 0;
	}

	if (!argparse_ok) {
		cerr << argparse.getParseError() << endl;
		cout << argparse.usage() << endl;
		return 1;
	}

	bool muted = argparse.findArgument(quiet);
	Log::Setup(muted);

	// Pre-load COLLADA schemas	
	colladaSchema141.readFile(Path::Join(Path::GetExecutableDirectory(), colladaSchemaFileName141));
	if (!colladaSchema141)
	{
		cerr << "Error loading " << Path::Join(Path::GetExecutableDirectory(), colladaSchemaFileName141) << endl;
		return 1;
	}

	// Disabled for the moment. COLLADA schema 1.5 generates errors.
	//colladaSchema15.readFile(Path::Join(GetExecutableDirectory(), colladaSchemaFileName15));
	//if (!colladaSchema15)
	//{
	//	cerr << "Error loading " << Path::Join(GetExecutableDirectory(), colladaSchemaFileName15) << endl;
	//	return 1;
	//}

	string path = argparse.findArgument(0).getValue<string>();

	list<string> daePaths;
	if (Path::IsDirectory(path))
	{
		daePaths = Path::ListDaes(path, argparse.findArgument(recursive));
	}
	else
	{
		daePaths.push_back(path);
	}

	if (daePaths.size() == 0)
	{
		cout << "No DAE found." << endl;
		return 0;
	}

	DaeValidator validator(daePaths);
	int result = 0;

	if (!argparse.findArgument(checkSchemaAuto) &&
		!argparse.findArgument(checkUniqueIds) &&
		!argparse.findArgument(checkSchema))
	{
		result |= validator.checkAll();
	}
	else
	{
		if (argparse.findArgument(checkSchemaAuto))
		{
			result |= validator.checkSchema();
		}

		if (argparse.findArgument(checkUniqueIds))
		{
			result |= validator.checkUniqueIds();
		}

		if (const auto & arg = argparse.findArgument(checkSchema))
		{
			result |= validator.checkSchema(arg.getValue<string>());
		}
	}

	if (result == 0)
		cout << "Validation SUCCEEDED." << endl;
	else
		cerr << "Validation FAILED." << endl;

	return result;
}