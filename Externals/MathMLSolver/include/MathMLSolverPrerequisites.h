/******************************************************************************
Copyright (c) 2007 netAllied GmbH, Tettnang

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************/

#ifndef __MATHML_PREREQUISITES_H___
#define __MATHML_PREREQUISITES_H___


// disable: "<type> needs to have dll-interface to be used by clients'
// Happens on STL member variables which are not public therefore is ok
#pragma warning (disable : 4251)


#include "MathMLPlatform.h"
#include <sstream>


namespace MathML
{
 #define MML_VERSION_MAJOR 0
 #define MML_VERSION_MINOR 4
 #define MML_VERSION_PATCH 0
 #define MML_VERSION_SUFFIX ""
 #define MML_VERSION_NAME ""

#define MML_VERSION ((MML_VERSION_MAJOR << 16) | (MML_VERSION_MINOR << 8) | MML_VERSION_PATCH)

	inline std::string getVersion()
    {
		std::ostringstream version;
        version << MML_VERSION_MAJOR << ".";
        version << MML_VERSION_MINOR << ".";
        version << MML_VERSION_PATCH << ".";
		version << MML_VERSION_SUFFIX;
        return version.str();
    }

    //----------------------------------------------------------------------------
    inline std::string getVersionName()
    {
        return MML_VERSION_NAME;
    }
}

#endif //__MATHML_PREREQUISITES_H___
