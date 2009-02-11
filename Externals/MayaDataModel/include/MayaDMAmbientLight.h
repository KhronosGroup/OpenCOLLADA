/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_AMBIENTLIGHT_H__
#define __MayaDM_AMBIENTLIGHT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMRenderLight.h"
namespace MayaDM
{
class AmbientLight : public RenderLight
{
public:
public:
	AmbientLight():RenderLight(){}
	AmbientLight(FILE* file,const std::string& name,const std::string& parent=""):RenderLight(file, name, parent, "ambientLight"){}
	virtual ~AmbientLight(){}
	void setAmbientShade(float as)
	{
		if(as == 0.45) return;
		fprintf(mFile,"\tsetAttr \".as\" %f;\n", as);

	}
	void setObjectType(char ot)
	{
		if(ot == 1) return;
		fprintf(mFile,"\tsetAttr \".ot\" %;\n", ot);

	}
	void setShadowRadius(float sr)
	{
		if(sr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sr\" %f;\n", sr);

	}
	void setCastSoftShadows(bool cw)
	{
		if(cw == false) return;
		fprintf(mFile,"\tsetAttr \".cw\" %i;\n", cw);

	}
	void setReceiveShadows(bool gs)
	{
		if(gs == true) return;
		fprintf(mFile,"\tsetAttr \".gs\" %i;\n", gs);

	}
	void getAmbientShade()
	{
		fprintf(mFile,"\"%s.as\"",mName.c_str());

	}
	void getObjectType()
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());

	}
	void getShadowRadius()
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());

	}
	void getCastSoftShadows()
	{
		fprintf(mFile,"\"%s.cw\"",mName.c_str());

	}
	void getNormalCamera()
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());

	}
	void getNormalCameraX()
	{
		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());

	}
	void getNormalCameraY()
	{
		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());

	}
	void getNormalCameraZ()
	{
		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());

	}
	void getReceiveShadows()
	{
		fprintf(mFile,"\"%s.gs\"",mName.c_str());

	}
protected:
	AmbientLight(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:RenderLight(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_AMBIENTLIGHT_H__
