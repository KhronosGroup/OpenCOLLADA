#include <libxml/parser.h>
#include <iostream>
#include <list>

#if defined(_WIN32)
#include <Windows.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#elif defined(__LINUX__)
#include <unistd.h>
#endif

#include "ArgumentParser.h"
#include "DaeValidator.h"
#include "Dae.h"
#include "PathUtil.h"
#include "StringUtil.h"

#include "dirent.h"

using namespace opencollada;
using namespace std;

namespace opencollada
{
	// Validation options
	const char* checkSchemaAuto = "--check-schema-auto";
	const char* checkSchema = "--check-schema";
	const char* checkUniqueIds = "--check-unique-ids";
	const char* recursive = "--recursive";

	const char* colladaNamespace141 = "http://www.collada.org/2005/11/COLLADASchema";
	const char* colladaSchemaFileName141 = "collada_schema_1_4_1.xsd";
	XmlSchema colladaSchema141;

	const char* colladaNamespace15 = "http://www.collada.org/2008/03/COLLADASchema";
	const char* colladaSchemaFileName15 = "collada_schema_1_5.xsd";
	XmlSchema colladaSchema15;

	string GetExecutablePath()
	{
#if defined(_WIN32)
		vector<string::value_type> path;
		path.resize(MAX_PATH);
		GetModuleFileName(NULL, &path.front(), static_cast<DWORD>(path.size()));
		while (GetLastError() == ERROR_INSUFFICIENT_BUFFER) {
			path.resize(path.size() * 2);
			GetModuleFileNameA(NULL, &path.front(), static_cast<DWORD>(path.size()));
		}
		return string(&path.front());
#elif defined(__APPLE__)
		// TODO test
		uint32_t size = 0;
		_NSGetExecutablePath(nullptr, &size);
		string path;
		path.resize(size - 1);
		if (_NSGetExecutablePath(&path.front(), &size) == 0)
			return path;
		return string();
#elif defined(__LINUX__)
		// TODO test
		static const char* proc_self_exe = "/proc/self/exe";
		stat st = { 0 };
		if (lstat(proc_self_exe, &st) == 0)
		{
			string path;
			path.resize(st.st_size);
			if (readlink(proc_self_exe, &path.front(), st.st_size) != -1)
				return path;
		}
		return string();
#else
#error not implemented
#endif
	}

	string GetExecutableDirectory()
	{
		string exePath = GetExecutablePath();
		if (exePath.length() > 0)
		{
			size_t sep = exePath.rfind(Path::Separator());
			if (sep != string::npos)
			{
				return exePath.substr(0, sep);
			}
		}
		return string();
	}

	list<string> ListDaes(const string & path, bool recursive)
	{
		list<string> daes;
		DIR* dir = nullptr;
		struct dirent* ent = nullptr;
		list<string> dirs;
		dirs.push_back(path);
		while (dirs.size() > 0)
		{
			if ((dir = opendir(dirs.front().c_str())) != nullptr) {
				while ((ent = readdir(dir)) != nullptr) {
					string d_name = ent->d_name;
					if (recursive &&
						(ent->d_type & DT_DIR) &&
						d_name != "." &&
						d_name != "..")
					{
						dirs.push_back(Path::Join(dirs.front(), ent->d_name));
					}
					else if (String::EndsWith(String::Lower(ent->d_name), ".dae"))
					{
						daes.push_back(Path::Join(dirs.front(), ent->d_name));
					}
				}
				closedir(dir);
			}
			dirs.pop_front();
		}
		return daes;
	}
}

int main(int argc, char* argv[])
{
	// Parse arguments
	ArgumentParser argparse(argc, argv);
	argparse.addArgument(); // dae or directory
	argparse.addArgument(checkSchemaAuto);
	argparse.addArgument(checkSchema).numParameters(1);
	argparse.addArgument(checkUniqueIds);
	argparse.addArgument(recursive);
	if (!argparse.parseArguments())
		return 1;

	// Pre-load COLLADA schemas	
	colladaSchema141.readFile(Path::Join(GetExecutableDirectory(), colladaSchemaFileName141));
	if (!colladaSchema141)
	{
		cerr << "Error loading " << Path::Join(GetExecutableDirectory(), colladaSchemaFileName141) << endl;
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
		daePaths = ListDaes(path, argparse.findArgument(recursive));
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
		cerr << "Validation SUCCEEDED." << endl;
	else
		cout << "Validation FAILED." << endl;

	return result;
}