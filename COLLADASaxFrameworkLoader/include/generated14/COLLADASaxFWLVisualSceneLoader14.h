/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_VISUALSCENELOADER14_H__
#define __COLLADASAXFWL_VISUALSCENELOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLVisualSceneLoader.h"
#include "COLLADASaxFWLNodeLoader14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class VisualSceneLoader14 : public NodeLoader14
{
private:
VisualSceneLoader* mLoader;

public:
VisualSceneLoader14(VisualSceneLoader* loader)
 : NodeLoader14(loader)
 , mLoader(loader)
{}


virtual bool begin__node( const COLLADASaxFWL14::node__AttributeData& attributeData );

virtual bool end__node();

virtual bool end__visual_scene();

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
VisualSceneLoader14(const VisualSceneLoader14&);
/** Disable default assignment operator. */
const VisualSceneLoader14& operator=(const VisualSceneLoader14&);
};
}
#endif // __COLLADASAXFWL_VISUALSCENELOADER14_H__
