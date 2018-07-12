/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryCamerasLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryCamerasLoader15::end__library_cameras()
{
SaxVirtualFunctionTest15(end__library_cameras());
return mLoader->end__library_cameras();
}


bool LibraryCamerasLoader15::begin__camera( const COLLADASaxFWL15::camera__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__camera(attributeData));
COLLADASaxFWL::camera__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__camera(attrData);
}


bool LibraryCamerasLoader15::end__camera()
{
SaxVirtualFunctionTest15(end__camera());
return mLoader->end__camera();
}


bool LibraryCamerasLoader15::begin__optics()
{
SaxVirtualFunctionTest15(begin__optics());
return mLoader->begin__optics();
}


bool LibraryCamerasLoader15::end__optics()
{
SaxVirtualFunctionTest15(end__optics());
return mLoader->end__optics();
}


bool LibraryCamerasLoader15::begin__optics__technique_common()
{
SaxVirtualFunctionTest15(begin__optics__technique_common());
return mLoader->begin__optics__technique_common();
}


bool LibraryCamerasLoader15::end__optics__technique_common()
{
SaxVirtualFunctionTest15(end__optics__technique_common());
return mLoader->end__optics__technique_common();
}


bool LibraryCamerasLoader15::begin__perspective()
{
SaxVirtualFunctionTest15(begin__perspective());
return mLoader->begin__perspective();
}


bool LibraryCamerasLoader15::end__perspective()
{
SaxVirtualFunctionTest15(end__perspective());
return mLoader->end__perspective();
}


bool LibraryCamerasLoader15::begin__orthographic()
{
SaxVirtualFunctionTest15(begin__orthographic());
return mLoader->begin__orthographic();
}


bool LibraryCamerasLoader15::end__orthographic()
{
SaxVirtualFunctionTest15(end__orthographic());
return mLoader->end__orthographic();
}


bool LibraryCamerasLoader15::begin__xfov( const COLLADASaxFWL15::xfov__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__xfov(attributeData));
COLLADASaxFWL::xfov__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__xfov(attrData);
}


bool LibraryCamerasLoader15::end__xfov()
{
SaxVirtualFunctionTest15(end__xfov());
return mLoader->end__xfov();
}


bool LibraryCamerasLoader15::data__xfov( float value )
{
SaxVirtualFunctionTest15(data__xfov(value));
return mLoader->data__xfov(value);
}


bool LibraryCamerasLoader15::begin__yfov( const COLLADASaxFWL15::yfov__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__yfov(attributeData));
COLLADASaxFWL::yfov__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__yfov(attrData);
}


bool LibraryCamerasLoader15::end__yfov()
{
SaxVirtualFunctionTest15(end__yfov());
return mLoader->end__yfov();
}


bool LibraryCamerasLoader15::data__yfov( float value )
{
SaxVirtualFunctionTest15(data__yfov(value));
return mLoader->data__yfov(value);
}


bool LibraryCamerasLoader15::begin__xmag( const COLLADASaxFWL15::xmag__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__xmag(attributeData));
COLLADASaxFWL::xmag__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__xmag(attrData);
}


bool LibraryCamerasLoader15::end__xmag()
{
SaxVirtualFunctionTest15(end__xmag());
return mLoader->end__xmag();
}


bool LibraryCamerasLoader15::data__xmag( float value )
{
SaxVirtualFunctionTest15(data__xmag(value));
return mLoader->data__xmag(value);
}


bool LibraryCamerasLoader15::begin__ymag( const COLLADASaxFWL15::ymag__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__ymag(attributeData));
COLLADASaxFWL::ymag__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__ymag(attrData);
}


bool LibraryCamerasLoader15::end__ymag()
{
SaxVirtualFunctionTest15(end__ymag());
return mLoader->end__ymag();
}


bool LibraryCamerasLoader15::data__ymag( float value )
{
SaxVirtualFunctionTest15(data__ymag(value));
return mLoader->data__ymag(value);
}


bool LibraryCamerasLoader15::begin__aspect_ratio( const COLLADASaxFWL15::aspect_ratio__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__aspect_ratio(attributeData));
COLLADASaxFWL::aspect_ratio__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__aspect_ratio(attrData);
}


bool LibraryCamerasLoader15::end__aspect_ratio()
{
SaxVirtualFunctionTest15(end__aspect_ratio());
return mLoader->end__aspect_ratio();
}


bool LibraryCamerasLoader15::data__aspect_ratio( float value )
{
SaxVirtualFunctionTest15(data__aspect_ratio(value));
return mLoader->data__aspect_ratio(value);
}


bool LibraryCamerasLoader15::begin__znear( const COLLADASaxFWL15::znear__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__znear(attributeData));
COLLADASaxFWL::znear__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__znear(attrData);
}


bool LibraryCamerasLoader15::end__znear()
{
SaxVirtualFunctionTest15(end__znear());
return mLoader->end__znear();
}


bool LibraryCamerasLoader15::data__znear( float value )
{
SaxVirtualFunctionTest15(data__znear(value));
return mLoader->data__znear(value);
}


bool LibraryCamerasLoader15::begin__zfar( const COLLADASaxFWL15::zfar__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__zfar(attributeData));
COLLADASaxFWL::zfar__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__zfar(attrData);
}


bool LibraryCamerasLoader15::end__zfar()
{
SaxVirtualFunctionTest15(end__zfar());
return mLoader->end__zfar();
}


bool LibraryCamerasLoader15::data__zfar( float value )
{
SaxVirtualFunctionTest15(data__zfar(value));
return mLoader->data__zfar(value);
}


bool LibraryCamerasLoader15::begin__imager()
{
SaxVirtualFunctionTest15(begin__imager());
return mLoader->begin__imager();
}


bool LibraryCamerasLoader15::end__imager()
{
SaxVirtualFunctionTest15(end__imager());
return mLoader->end__imager();
}


bool LibraryCamerasLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryCamerasLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
