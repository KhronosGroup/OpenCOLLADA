/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYJOINTSLOADER15_H__
#define __COLLADASAXFWL_LIBRARYJOINTSLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryJointsLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryJointsLoader15 : public IParserImpl15
{
private:
LibraryJointsLoader* mLoader;

public:
LibraryJointsLoader15(LibraryJointsLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_joints();

virtual bool begin__joint( const COLLADASaxFWL15::joint__AttributeData& attributeData );

virtual bool end__joint();

virtual bool begin__prismatic( const COLLADASaxFWL15::prismatic__AttributeData& attributeData );

virtual bool end__prismatic();

virtual bool begin__axis____axis_type( const COLLADASaxFWL15::axis____axis_type__AttributeData& attributeData );

virtual bool end__axis____axis_type();

virtual bool data__axis____axis_type( const float* data, size_t length );

virtual bool begin__limits____joint_limits_type();

virtual bool end__limits____joint_limits_type();

virtual bool begin__min____minmax_type( const COLLADASaxFWL15::min____minmax_type__AttributeData& attributeData );

virtual bool end__min____minmax_type();

virtual bool data__min____minmax_type( float value );

virtual bool begin__max____minmax_type( const COLLADASaxFWL15::max____minmax_type__AttributeData& attributeData );

virtual bool end__max____minmax_type();

virtual bool data__max____minmax_type( float value );

virtual bool begin__revolute( const COLLADASaxFWL15::revolute__AttributeData& attributeData );

virtual bool end__revolute();

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
LibraryJointsLoader15(const LibraryJointsLoader15&);
/** Disable default assignment operator. */
const LibraryJointsLoader15& operator=(const LibraryJointsLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYJOINTSLOADER15_H__
