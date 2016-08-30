#include <libxml/parser.h>
#include <iostream>
#include "ArgumentParser.h"
#include "DaeValidator.h"
#include "Dae.h"

using namespace opencollada;
using namespace std;

// Validation options
const char* checkAll = "--check-all";
const char* checkSchema = "--check-schema";
const char* checkUniqueIds = "--check-unique-ids";

int main(int argc, char* argv[])
{
	// Parse arguments
	ArgumentParser argparse(argc, argv);
	argparse.addArgument(); // dae
	argparse.addArgument(checkAll);
	argparse.addArgument(checkSchema);
	argparse.addArgument(checkUniqueIds);
	if (!argparse.parseArguments())
		return 1;

	string daePath = argparse.findArgument(0).getValue<string>();

	// Open dae
	cout << "Opening " << daePath << endl;
	Dae dae;
	dae.readFile(daePath.c_str());
	if (!dae)
	{
		cerr << "Error loading " << daePath << endl;
		return 1;
	}

	DaeValidator validator(dae);
	int result = 0;

	if (argparse.findArgument(checkAll))
	{
		result |= validator.checkAll();
	}
	else
	{
		if (argparse.findArgument(checkSchema))
		{
			result |= validator.checkSchema();
		}

		if (argparse.findArgument(checkUniqueIds))
		{
			result |= validator.checkUniqueIds();
		}
	}

	return result;
}