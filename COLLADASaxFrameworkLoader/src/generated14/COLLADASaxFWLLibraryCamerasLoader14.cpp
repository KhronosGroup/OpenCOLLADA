/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryCamerasLoader14.h"


namespace COLLADASaxFWL
{


bool LibraryCamerasLoader14::end__library_cameras()
{
SaxVirtualFunctionTest14(end__library_cameras());
return mLoader->end__library_cameras();
}


bool LibraryCamerasLoader14::begin__camera( const COLLADASaxFWL14::camera__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__camera(attributeData));
COLLADASaxFWL::camera__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__camera(attrData);
}


bool LibraryCamerasLoader14::end__camera()
{
SaxVirtualFunctionTest14(end__camera());
return mLoader->end__camera();
}


bool LibraryCamerasLoader14::begin__optics()
{
SaxVirtualFunctionTest14(begin__optics());
return mLoader->begin__optics();
}


bool LibraryCamerasLoader14::end__optics()
{
SaxVirtualFunctionTest14(end__optics());
return mLoader->end__optics();
}


bool LibraryCamerasLoader14::begin__optics__technique_common()
{
SaxVirtualFunctionTest14(begin__optics__technique_common());
return mLoader->begin__optics__technique_common();
}


bool LibraryCamerasLoader14::end__optics__technique_common()
{
SaxVirtualFunctionTest14(end__optics__technique_common());
return mLoader->end__optics__technique_common();
}


bool LibraryCamerasLoader14::begin__perspective()
{
SaxVirtualFunctionTest14(begin__perspective());
return mLoader->begin__perspective();
}


bool LibraryCamerasLoader14::end__perspective()
{
SaxVirtualFunctionTest14(end__perspective());
return mLoader->end__perspective();
}


bool LibraryCamerasLoader14::begin__orthographic()
{
SaxVirtualFunctionTest14(begin__orthographic());
return mLoader->begin__orthographic();
}


bool LibraryCamerasLoader14::end__orthographic()
{
SaxVirtualFunctionTest14(end__orthographic());
return mLoader->end__orthographic();
}


bool LibraryCamerasLoader14::begin__xfov( const COLLADASaxFWL14::xfov__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__xfov(attributeData));
COLLADASaxFWL::xfov__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__xfov(attrData);
}


bool LibraryCamerasLoader14::end__xfov()
{
SaxVirtualFunctionTest14(end__xfov());
return mLoader->end__xfov();
}


bool LibraryCamerasLoader14::data__xfov( float value )
{
SaxVirtualFunctionTest14(data__xfov(value));
return mLoader->data__xfov(value);
}


bool LibraryCamerasLoader14::begin__yfov( const COLLADASaxFWL14::yfov__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__yfov(attributeData));
COLLADASaxFWL::yfov__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__yfov(attrData);
}


bool LibraryCamerasLoader14::end__yfov()
{
SaxVirtualFunctionTest14(end__yfov());
return mLoader->end__yfov();
}


bool LibraryCamerasLoader14::data__yfov( float value )
{
SaxVirtualFunctionTest14(data__yfov(value));
return mLoader->data__yfov(value);
}


bool LibraryCamerasLoader14::begin__xmag( const COLLADASaxFWL14::xmag__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__xmag(attributeData));
COLLADASaxFWL::xmag__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__xmag(attrData);
}


bool LibraryCamerasLoader14::end__xmag()
{
SaxVirtualFunctionTest14(end__xmag());
return mLoader->end__xmag();
}


bool LibraryCamerasLoader14::data__xmag( float value )
{
SaxVirtualFunctionTest14(data__xmag(value));
return mLoader->data__xmag(value);
}


bool LibraryCamerasLoader14::begin__ymag( const COLLADASaxFWL14::ymag__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__ymag(attributeData));
COLLADASaxFWL::ymag__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__ymag(attrData);
}


bool LibraryCamerasLoader14::end__ymag()
{
SaxVirtualFunctionTest14(end__ymag());
return mLoader->end__ymag();
}


bool LibraryCamerasLoader14::data__ymag( float value )
{
SaxVirtualFunctionTest14(data__ymag(value));
return mLoader->data__ymag(value);
}


bool LibraryCamerasLoader14::begin__aspect_ratio( const COLLADASaxFWL14::aspect_ratio__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__aspect_ratio(attributeData));
COLLADASaxFWL::aspect_ratio__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__aspect_ratio(attrData);
}


bool LibraryCamerasLoader14::end__aspect_ratio()
{
SaxVirtualFunctionTest14(end__aspect_ratio());
return mLoader->end__aspect_ratio();
}


bool LibraryCamerasLoader14::data__aspect_ratio( float value )
{
SaxVirtualFunctionTest14(data__aspect_ratio(value));
return mLoader->data__aspect_ratio(value);
}


bool LibraryCamerasLoader14::begin__znear( const COLLADASaxFWL14::znear__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__znear(attributeData));
COLLADASaxFWL::znear__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__znear(attrData);
}


bool LibraryCamerasLoader14::end__znear()
{
SaxVirtualFunctionTest14(end__znear());
return mLoader->end__znear();
}


bool LibraryCamerasLoader14::data__znear( float value )
{
SaxVirtualFunctionTest14(data__znear(value));
return mLoader->data__znear(value);
}


bool LibraryCamerasLoader14::begin__zfar( const COLLADASaxFWL14::zfar__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__zfar(attributeData));
COLLADASaxFWL::zfar__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__zfar(attrData);
}


bool LibraryCamerasLoader14::end__zfar()
{
SaxVirtualFunctionTest14(end__zfar());
return mLoader->end__zfar();
}


bool LibraryCamerasLoader14::data__zfar( float value )
{
SaxVirtualFunctionTest14(data__zfar(value));
return mLoader->data__zfar(value);
}


bool LibraryCamerasLoader14::begin__imager()
{
SaxVirtualFunctionTest14(begin__imager());
return mLoader->begin__imager();
}


bool LibraryCamerasLoader14::end__imager()
{
SaxVirtualFunctionTest14(end__imager());
return mLoader->end__imager();
}


bool LibraryCamerasLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryCamerasLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
