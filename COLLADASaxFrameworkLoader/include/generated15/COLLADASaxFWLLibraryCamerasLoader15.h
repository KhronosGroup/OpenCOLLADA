/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYCAMERASLOADER15_H__
#define __COLLADASAXFWL_LIBRARYCAMERASLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryCamerasLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryCamerasLoader15 : public IParserImpl15
{
private:
LibraryCamerasLoader* mLoader;

public:
LibraryCamerasLoader15(LibraryCamerasLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_cameras();

virtual bool begin__camera( const COLLADASaxFWL15::camera__AttributeData& attributeData );

virtual bool end__camera();

virtual bool begin__optics();

virtual bool end__optics();

virtual bool begin__optics__technique_common();

virtual bool end__optics__technique_common();

virtual bool begin__perspective();

virtual bool end__perspective();

virtual bool begin__orthographic();

virtual bool end__orthographic();

virtual bool begin__xfov( const COLLADASaxFWL15::xfov__AttributeData& attributeData );

virtual bool end__xfov();

virtual bool data__xfov( float value );

virtual bool begin__yfov( const COLLADASaxFWL15::yfov__AttributeData& attributeData );

virtual bool end__yfov();

virtual bool data__yfov( float value );

virtual bool begin__xmag( const COLLADASaxFWL15::xmag__AttributeData& attributeData );

virtual bool end__xmag();

virtual bool data__xmag( float value );

virtual bool begin__ymag( const COLLADASaxFWL15::ymag__AttributeData& attributeData );

virtual bool end__ymag();

virtual bool data__ymag( float value );

virtual bool begin__aspect_ratio( const COLLADASaxFWL15::aspect_ratio__AttributeData& attributeData );

virtual bool end__aspect_ratio();

virtual bool data__aspect_ratio( float value );

virtual bool begin__znear( const COLLADASaxFWL15::znear__AttributeData& attributeData );

virtual bool end__znear();

virtual bool data__znear( float value );

virtual bool begin__zfar( const COLLADASaxFWL15::zfar__AttributeData& attributeData );

virtual bool end__zfar();

virtual bool data__zfar( float value );

virtual bool begin__imager();

virtual bool end__imager();

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
LibraryCamerasLoader15(const LibraryCamerasLoader15&);
/** Disable default assignment operator. */
const LibraryCamerasLoader15& operator=(const LibraryCamerasLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYCAMERASLOADER15_H__
