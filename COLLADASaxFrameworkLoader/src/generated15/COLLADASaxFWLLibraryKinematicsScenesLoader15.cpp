/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryKinematicsScenesLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryKinematicsScenesLoader15::begin__kinematics_scene( const COLLADASaxFWL15::kinematics_scene__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__kinematics_scene(attributeData));
COLLADASaxFWL::kinematics_scene__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__kinematics_scene(attrData);
}


bool LibraryKinematicsScenesLoader15::end__kinematics_scene()
{
SaxVirtualFunctionTest15(end__kinematics_scene());
return mLoader->end__kinematics_scene();
}


bool LibraryKinematicsScenesLoader15::begin__bind____kinematics_bind_type( const COLLADASaxFWL15::bind____kinematics_bind_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__bind____kinematics_bind_type(attributeData));
COLLADASaxFWL::bind____kinematics_bind_type__AttributeData attrData;
attrData.symbol = attributeData.symbol;
return mLoader->begin__bind____kinematics_bind_type(attrData);
}


bool LibraryKinematicsScenesLoader15::end__bind____kinematics_bind_type()
{
SaxVirtualFunctionTest15(end__bind____kinematics_bind_type());
return mLoader->end__bind____kinematics_bind_type();
}


bool LibraryKinematicsScenesLoader15::begin__param____kinematics_param_type( const COLLADASaxFWL15::param____kinematics_param_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__param____kinematics_param_type(attributeData));
COLLADASaxFWL::param____kinematics_param_type__AttributeData attrData;
attrData.ref = attributeData.ref;
return mLoader->begin__param____kinematics_param_type(attrData);
}


bool LibraryKinematicsScenesLoader15::end__param____kinematics_param_type()
{
SaxVirtualFunctionTest15(end__param____kinematics_param_type());
return mLoader->end__param____kinematics_param_type();
}



}
