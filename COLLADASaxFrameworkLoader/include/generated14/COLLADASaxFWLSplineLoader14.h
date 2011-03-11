/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_SPLINELOADER14_H__
#define __COLLADASAXFWL_SPLINELOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSplineLoader.h"
#include "COLLADASaxFWLSourceArrayLoader14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class SplineLoader14 : public SourceArrayLoader14
{
private:
SplineLoader* mLoader;

public:
SplineLoader14(SplineLoader* loader)
 : SourceArrayLoader14(loader)
 , mLoader(loader)
{}


virtual bool begin__source( const COLLADASaxFWL14::source__AttributeData& attributeData );

virtual bool end__source();

virtual bool end__spline();

virtual bool begin__input____InputLocal( const COLLADASaxFWL14::input____InputLocal__AttributeData& attributeData );

virtual bool end__input____InputLocal();

virtual bool begin__control_vertices();
virtual bool end__control_vertices();


virtual bool begin__Name_array( const COLLADASaxFWL14::Name_array__AttributeData& attributeData );
virtual bool end__Name_array();
virtual bool data__Name_array( const ParserString* data, size_t length );

private:
/** Disable default copy ctor. */
SplineLoader14(const SplineLoader14&);
/** Disable default assignment operator. */
const SplineLoader14& operator=(const SplineLoader14&);
};
}
#endif // __COLLADASAXFWL_MESHLOADER14_H__
