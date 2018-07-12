/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LIGHTFOG_H__
#define __MayaDM_LIGHTFOG_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class LightFog : public DependNode
{
public:
public:

	LightFog():DependNode(){}
	LightFog(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "lightFog", shared, create){}
	virtual ~LightFog(){}

	void setColor(const float3& c)
	{
		if(c == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".c\" -type \"float3\" ");
		c.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorR(float cr)
	{
		if(cr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c.cr\" %f;\n", cr);
	}
	void setColorG(float cg)
	{
		if(cg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c.cg\" %f;\n", cg);
	}
	void setColorB(float cb)
	{
		if(cb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c.cb\" %f;\n", cb);
	}
	void setDensity(float d)
	{
		if(d == 1.0) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setFastDropOff(bool fd)
	{
		if(fd == false) return;
		fprintf(mFile,"\tsetAttr \".fd\" %i;\n", fd);
	}
	void setColorBasedTransparency(bool cbt)
	{
		if(cbt == true) return;
		fprintf(mFile,"\tsetAttr \".cbt\" %i;\n", cbt);
	}
	void setMatteOpacityMode(unsigned int mom)
	{
		if(mom == 2) return;
		fprintf(mFile,"\tsetAttr \".mom\" %i;\n", mom);
	}
	void setMatteOpacity(float mog)
	{
		if(mog == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mog\" %f;\n", mog);
	}
	void getFilterSize()const
	{
		fprintf(mFile,"\"%s.fs\"",mName.c_str());
	}
	void getFilterSizeX()const
	{
		fprintf(mFile,"\"%s.fs.fsx\"",mName.c_str());
	}
	void getFilterSizeY()const
	{
		fprintf(mFile,"\"%s.fs.fsy\"",mName.c_str());
	}
	void getFilterSizeZ()const
	{
		fprintf(mFile,"\"%s.fs.fsz\"",mName.c_str());
	}
	void getLightDataArray(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i]\"",mName.c_str(),ltd_i);
	}
	void getLightDataArray()const
	{

		fprintf(mFile,"\"%s.ltd\"",mName.c_str());
	}
	void getLightDirection(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld\"",mName.c_str(),ltd_i);
	}
	void getLightDirection()const
	{

		fprintf(mFile,"\"%s.ltd.ld\"",mName.c_str());
	}
	void getLightDirectionX(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldx\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionX()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldx\"",mName.c_str());
	}
	void getLightDirectionY(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldy\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionY()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldy\"",mName.c_str());
	}
	void getLightDirectionZ(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldz\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionZ()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldz\"",mName.c_str());
	}
	void getLightIntensity(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li\"",mName.c_str(),ltd_i);
	}
	void getLightIntensity()const
	{

		fprintf(mFile,"\"%s.ltd.li\"",mName.c_str());
	}
	void getLightIntensityR(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lir\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityR()const
	{

		fprintf(mFile,"\"%s.ltd.li.lir\"",mName.c_str());
	}
	void getLightIntensityG(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lig\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityG()const
	{

		fprintf(mFile,"\"%s.ltd.li.lig\"",mName.c_str());
	}
	void getLightIntensityB(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lib\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityB()const
	{

		fprintf(mFile,"\"%s.ltd.li.lib\"",mName.c_str());
	}
	void getLightAmbient(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].la\"",mName.c_str(),ltd_i);
	}
	void getLightAmbient()const
	{

		fprintf(mFile,"\"%s.ltd.la\"",mName.c_str());
	}
	void getLightDiffuse(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ldf\"",mName.c_str(),ltd_i);
	}
	void getLightDiffuse()const
	{

		fprintf(mFile,"\"%s.ltd.ldf\"",mName.c_str());
	}
	void getLightSpecular(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ls\"",mName.c_str(),ltd_i);
	}
	void getLightSpecular()const
	{

		fprintf(mFile,"\"%s.ltd.ls\"",mName.c_str());
	}
	void getLightShadowFraction(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].lsf\"",mName.c_str(),ltd_i);
	}
	void getLightShadowFraction()const
	{

		fprintf(mFile,"\"%s.ltd.lsf\"",mName.c_str());
	}
	void getPreShadowIntensity(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].psi\"",mName.c_str(),ltd_i);
	}
	void getPreShadowIntensity()const
	{

		fprintf(mFile,"\"%s.ltd.psi\"",mName.c_str());
	}
	void getLightBlindData(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].lbd\"",mName.c_str(),ltd_i);
	}
	void getLightBlindData()const
	{

		fprintf(mFile,"\"%s.ltd.lbd\"",mName.c_str());
	}
	void getColor()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getColorR()const
	{
		fprintf(mFile,"\"%s.c.cr\"",mName.c_str());
	}
	void getColorG()const
	{
		fprintf(mFile,"\"%s.c.cg\"",mName.c_str());
	}
	void getColorB()const
	{
		fprintf(mFile,"\"%s.c.cb\"",mName.c_str());
	}
	void getDensity()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getFastDropOff()const
	{
		fprintf(mFile,"\"%s.fd\"",mName.c_str());
	}
	void getColorBasedTransparency()const
	{
		fprintf(mFile,"\"%s.cbt\"",mName.c_str());
	}
	void getMatteOpacityMode()const
	{
		fprintf(mFile,"\"%s.mom\"",mName.c_str());
	}
	void getMatteOpacity()const
	{
		fprintf(mFile,"\"%s.mog\"",mName.c_str());
	}
	void getOutMatteOpacity()const
	{
		fprintf(mFile,"\"%s.omo\"",mName.c_str());
	}
	void getOutMatteOpacityR()const
	{
		fprintf(mFile,"\"%s.omo.omor\"",mName.c_str());
	}
	void getOutMatteOpacityG()const
	{
		fprintf(mFile,"\"%s.omo.omog\"",mName.c_str());
	}
	void getOutMatteOpacityB()const
	{
		fprintf(mFile,"\"%s.omo.omob\"",mName.c_str());
	}
	void getOutColor()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
	void getOutColorR()const
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());
	}
	void getOutColorG()const
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());
	}
	void getOutColorB()const
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());
	}
	void getOutTransparency()const
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());
	}
	void getOutTransparencyR()const
	{
		fprintf(mFile,"\"%s.ot.otr\"",mName.c_str());
	}
	void getOutTransparencyG()const
	{
		fprintf(mFile,"\"%s.ot.otg\"",mName.c_str());
	}
	void getOutTransparencyB()const
	{
		fprintf(mFile,"\"%s.ot.otb\"",mName.c_str());
	}
protected:
	LightFog(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_LIGHTFOG_H__
