#pragma once

#include "no_warning_begin"
#pragma warning(disable:4987)
#include <SDKDDKVer.h>
#include <CppUnitTest.h>
#include <string>
#include "no_warning_end"

//C4628: digraphs not supported with -Ze. Character sequence '<:' not interpreted as alternate token for '['
#pragma warning(disable:4628)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace opencollada_test
{
	std::string data_path(const std::string & relative_path = std::string());
}