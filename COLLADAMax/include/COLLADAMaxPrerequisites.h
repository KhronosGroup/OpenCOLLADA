/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/


#ifndef __COLLADAMAX_PREREQUISITES_H__
#define __COLLADAMAX_PREREQUISITES_H__

#define UNUSED(a) /**< Removes a piece of code during the pre-process. This macro is useful for these pesky unused variable warnings. */



// Max 2009 requires RTTI to be enabled
#ifdef MAX_2009
#ifndef _CPPRTTI
#error "Max 2009 requires RTTI to be enabled. Please enable and try again..."
#endif
#endif


#define TIME_INITIAL_POSE  0
#define TIME_EXPORT_START  0//OPTS->AnimStart()


#include <string>

namespace COLLADAMax
{
    typedef std::string String;

}



#endif //__COLLADAMAX_PREREQUISITES_H__
