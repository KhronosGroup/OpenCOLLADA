/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYCAMERASLOADER14_H__
#define __COLLADASAXFWL_LIBRARYCAMERASLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryCamerasLoader.h"
#include "COLLADASaxFWLIParserImpl14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryCamerasLoader14 : public IParserImpl14
{
private:
LibraryCamerasLoader* mLoader;

public:
LibraryCamerasLoader14(LibraryCamerasLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_cameras();

virtual bool begin__camera( const COLLADASaxFWL14::camera__AttributeData& attributeData );

virtual bool end__camera();

virtual bool begin__optics();

virtual bool end__optics();

virtual bool begin__optics__technique_common();

virtual bool end__optics__technique_common();

virtual bool begin__perspective();

virtual bool end__perspective();

virtual bool begin__orthographic();

virtual bool end__orthographic();

virtual bool begin__xfov( const COLLADASaxFWL14::xfov__AttributeData& attributeData );

virtual bool end__xfov();

virtual bool data__xfov( float value );

virtual bool begin__yfov( const COLLADASaxFWL14::yfov__AttributeData& attributeData );

virtual bool end__yfov();

virtual bool data__yfov( float value );

virtual bool begin__xmag( const COLLADASaxFWL14::xmag__AttributeData& attributeData );

virtual bool end__xmag();

virtual bool data__xmag( float value );

virtual bool begin__ymag( const COLLADASaxFWL14::ymag__AttributeData& attributeData );

virtual bool end__ymag();

virtual bool data__ymag( float value );

virtual bool begin__aspect_ratio( const COLLADASaxFWL14::aspect_ratio__AttributeData& attributeData );

virtual bool end__aspect_ratio();

virtual bool data__aspect_ratio( float value );

virtual bool begin__znear( const COLLADASaxFWL14::znear__AttributeData& attributeData );

virtual bool end__znear();

virtual bool data__znear( float value );

virtual bool begin__zfar( const COLLADASaxFWL14::zfar__AttributeData& attributeData );

virtual bool end__zfar();

virtual bool data__zfar( float value );

virtual bool begin__imager();

virtual bool end__imager();

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
LibraryCamerasLoader14(const LibraryCamerasLoader14&);
/** Disable default assignment operator. */
const LibraryCamerasLoader14& operator=(const LibraryCamerasLoader14&);
};
}
#endif // __COLLADASAXFWL_LIBRARYCAMERASLOADER14_H__
