/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POSITIONMARKER_H__
#define __MayaDM_POSITIONMARKER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMLocator.h"
namespace MayaDM
{
class PositionMarker : public Locator
{
public:
public:
	PositionMarker():Locator(){}
	PositionMarker(FILE* file,const std::string& name,const std::string& parent=""):Locator(file, name, parent, "positionMarker"){}
	virtual ~PositionMarker(){}
	void getTime()
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());

	}
protected:
	PositionMarker(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Locator(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POSITIONMARKER_H__
