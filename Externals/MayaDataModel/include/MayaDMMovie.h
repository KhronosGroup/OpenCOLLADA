/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MOVIE_H__
#define __MayaDM_MOVIE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFile.h"
namespace MayaDM
{
class Movie : public File
{
public:
	Movie():File(){}
	Movie(FILE* file,const std::string& name,const std::string& parent="",bool create=true)
		:File(file, name, parent, "movie", create){}
	virtual ~Movie(){}
protected:
	Movie(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool create=true)
		:File(file, name, parent, nodeType, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MOVIE_H__
