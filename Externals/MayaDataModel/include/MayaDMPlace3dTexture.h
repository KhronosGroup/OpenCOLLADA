/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PLACE3DTEXTURE_H__
#define __MayaDM_PLACE3DTEXTURE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
/*
<p><pre>
 This is the 3D placement node. It is nothing but a transform,
 with some special UI on it.  It has to be used by connecting its
 aWorldMatrixInverse[0] output to the placementMatrix input of a
 3D texture.



</pre></p>
*/
class Place3dTexture : public Transform
{
public:
public:
	Place3dTexture(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "place3dTexture"){}
	virtual ~Place3dTexture(){}
protected:
	Place3dTexture(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PLACE3DTEXTURE_H__
