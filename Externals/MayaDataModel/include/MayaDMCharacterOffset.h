/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CHARACTEROFFSET_H__
#define __MayaDM_CHARACTEROFFSET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class CharacterOffset : public DependNode
{
public:
public:
	CharacterOffset(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "characterOffset"){}
	virtual ~CharacterOffset(){}
	void setInRootTranslate(const double3& rti)
	{
		fprintf(mFile,"setAttr \".rti\" -type \"double3\" ");
		rti.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInRootTranslateX(double rtix)
	{
		if(rtix == 0) return;
		fprintf(mFile,"setAttr \".rti.rtix\" %f;\n", rtix);

	}
	void setInRootTranslateY(double rtiy)
	{
		if(rtiy == 0) return;
		fprintf(mFile,"setAttr \".rti.rtiy\" %f;\n", rtiy);

	}
	void setInRootTranslateZ(double rtiz)
	{
		if(rtiz == 0) return;
		fprintf(mFile,"setAttr \".rti.rtiz\" %f;\n", rtiz);

	}
	void setInRootRotate(const double3& rri)
	{
		fprintf(mFile,"setAttr \".rri\" -type \"double3\" ");
		rri.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInRootRotateX(double rrix)
	{
		if(rrix == 0) return;
		fprintf(mFile,"setAttr \".rri.rrix\" %f;\n", rrix);

	}
	void setInRootRotateY(double rriy)
	{
		if(rriy == 0) return;
		fprintf(mFile,"setAttr \".rri.rriy\" %f;\n", rriy);

	}
	void setInRootRotateZ(double rriz)
	{
		if(rriz == 0) return;
		fprintf(mFile,"setAttr \".rri.rriz\" %f;\n", rriz);

	}
	void setRootRotateOrder(unsigned int rror)
	{
		if(rror == 0) return;
		fprintf(mFile,"setAttr \".rror\" %i;\n", rror);

	}
	void setRootJointOrient(const double3& rjo)
	{
		fprintf(mFile,"setAttr \".rjo\" -type \"double3\" ");
		rjo.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRootJointOrientX(double rjox)
	{
		if(rjox == 0) return;
		fprintf(mFile,"setAttr \".rjo.rjox\" %f;\n", rjox);

	}
	void setRootJointOrientY(double rjoy)
	{
		if(rjoy == 0) return;
		fprintf(mFile,"setAttr \".rjo.rjoy\" %f;\n", rjoy);

	}
	void setRootJointOrientZ(double rjoz)
	{
		if(rjoz == 0) return;
		fprintf(mFile,"setAttr \".rjo.rjoz\" %f;\n", rjoz);

	}
	void setRootParentMatrix(const matrix& rpm)
	{
		if(rpm == identity) return;
		fprintf(mFile,"setAttr \".rpm\" -type \"matrix\" ");
		rpm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRootParentInverseMatrix(const matrix& rpim)
	{
		if(rpim == identity) return;
		fprintf(mFile,"setAttr \".rpim\" -type \"matrix\" ");
		rpim.write(mFile);
		fprintf(mFile,";\n");

	}
	void setApplyControlParentTransform(bool acpx)
	{
		if(acpx == false) return;
		fprintf(mFile,"setAttr \".acpx\" %i;\n", acpx);

	}
	void setEnable(bool nabl)
	{
		if(nabl == true) return;
		fprintf(mFile,"setAttr \".nabl\" %i;\n", nabl);

	}
	void setOffsetRootTranslate(const double3& rtf)
	{
		fprintf(mFile,"setAttr \".rtf\" -type \"double3\" ");
		rtf.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOffsetRootTranslateX(double rtfx)
	{
		if(rtfx == 0) return;
		fprintf(mFile,"setAttr \".rtf.rtfx\" %f;\n", rtfx);

	}
	void setOffsetRootTranslateY(double rtfy)
	{
		if(rtfy == 0) return;
		fprintf(mFile,"setAttr \".rtf.rtfy\" %f;\n", rtfy);

	}
	void setOffsetRootTranslateZ(double rtfz)
	{
		if(rtfz == 0) return;
		fprintf(mFile,"setAttr \".rtf.rtfz\" %f;\n", rtfz);

	}
	void setInitialOffsetRootTranslate(const double3& itf)
	{
		fprintf(mFile,"setAttr \".itf\" -type \"double3\" ");
		itf.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInitialOffsetRootTranslateX(double itfx)
	{
		if(itfx == 0) return;
		fprintf(mFile,"setAttr \".itf.itfx\" %f;\n", itfx);

	}
	void setInitialOffsetRootTranslateY(double itfy)
	{
		if(itfy == 0) return;
		fprintf(mFile,"setAttr \".itf.itfy\" %f;\n", itfy);

	}
	void setInitialOffsetRootTranslateZ(double itfz)
	{
		if(itfz == 0) return;
		fprintf(mFile,"setAttr \".itf.itfz\" %f;\n", itfz);

	}
	void setRotateControlScale(const double3& rcs)
	{
		fprintf(mFile,"setAttr \".rcs\" -type \"double3\" ");
		rcs.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRotateControlScaleX(double rcsx)
	{
		if(rcsx == 1.0) return;
		fprintf(mFile,"setAttr \".rcs.rcsx\" %f;\n", rcsx);

	}
	void setRotateControlScaleY(double rcsy)
	{
		if(rcsy == 1.0) return;
		fprintf(mFile,"setAttr \".rcs.rcsy\" %f;\n", rcsy);

	}
	void setRotateControlScaleZ(double rcsz)
	{
		if(rcsz == 1.0) return;
		fprintf(mFile,"setAttr \".rcs.rcsz\" %f;\n", rcsz);

	}
	void setRotateControlParentMatrix(const matrix& rcpm)
	{
		if(rcpm == identity) return;
		fprintf(mFile,"setAttr \".rcpm\" -type \"matrix\" ");
		rcpm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOffsetRootRotate(const double3& rrf)
	{
		fprintf(mFile,"setAttr \".rrf\" -type \"double3\" ");
		rrf.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOffsetRootRotateX(double rrfx)
	{
		if(rrfx == 0) return;
		fprintf(mFile,"setAttr \".rrf.rrfx\" %f;\n", rrfx);

	}
	void setOffsetRootRotateY(double rrfy)
	{
		if(rrfy == 0) return;
		fprintf(mFile,"setAttr \".rrf.rrfy\" %f;\n", rrfy);

	}
	void setOffsetRootRotateZ(double rrfz)
	{
		if(rrfz == 0) return;
		fprintf(mFile,"setAttr \".rrf.rrfz\" %f;\n", rrfz);

	}
	void setOffsetRootRotateOrder(unsigned int rfor)
	{
		if(rfor == 0) return;
		fprintf(mFile,"setAttr \".rfor\" %i;\n", rfor);

	}
	void setOffsetRootRotatePivot(const double3& rpf)
	{
		fprintf(mFile,"setAttr \".rpf\" -type \"double3\" ");
		rpf.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOffsetRootRotatePivotX(double rppfx)
	{
		if(rppfx == 0) return;
		fprintf(mFile,"setAttr \".rpf.rppfx\" %f;\n", rppfx);

	}
	void setOffsetRootRotatePivotY(double rppfy)
	{
		if(rppfy == 0) return;
		fprintf(mFile,"setAttr \".rpf.rppfy\" %f;\n", rppfy);

	}
	void setOffsetRootRotatePivotZ(double rppfz)
	{
		if(rppfz == 0) return;
		fprintf(mFile,"setAttr \".rpf.rppfz\" %f;\n", rppfz);

	}
	void getInRootTranslate()
	{
		fprintf(mFile,"\"%s.rti\"",mName.c_str());

	}
	void getInRootTranslateX()
	{
		fprintf(mFile,"\"%s.rti.rtix\"",mName.c_str());

	}
	void getInRootTranslateY()
	{
		fprintf(mFile,"\"%s.rti.rtiy\"",mName.c_str());

	}
	void getInRootTranslateZ()
	{
		fprintf(mFile,"\"%s.rti.rtiz\"",mName.c_str());

	}
	void getInRootRotate()
	{
		fprintf(mFile,"\"%s.rri\"",mName.c_str());

	}
	void getInRootRotateX()
	{
		fprintf(mFile,"\"%s.rri.rrix\"",mName.c_str());

	}
	void getInRootRotateY()
	{
		fprintf(mFile,"\"%s.rri.rriy\"",mName.c_str());

	}
	void getInRootRotateZ()
	{
		fprintf(mFile,"\"%s.rri.rriz\"",mName.c_str());

	}
	void getRootRotateOrder()
	{
		fprintf(mFile,"\"%s.rror\"",mName.c_str());

	}
	void getRootJointOrient()
	{
		fprintf(mFile,"\"%s.rjo\"",mName.c_str());

	}
	void getRootJointOrientX()
	{
		fprintf(mFile,"\"%s.rjo.rjox\"",mName.c_str());

	}
	void getRootJointOrientY()
	{
		fprintf(mFile,"\"%s.rjo.rjoy\"",mName.c_str());

	}
	void getRootJointOrientZ()
	{
		fprintf(mFile,"\"%s.rjo.rjoz\"",mName.c_str());

	}
	void getRootParentMatrix()
	{
		fprintf(mFile,"\"%s.rpm\"",mName.c_str());

	}
	void getRootParentInverseMatrix()
	{
		fprintf(mFile,"\"%s.rpim\"",mName.c_str());

	}
	void getApplyControlParentTransform()
	{
		fprintf(mFile,"\"%s.acpx\"",mName.c_str());

	}
	void getEnable()
	{
		fprintf(mFile,"\"%s.nabl\"",mName.c_str());

	}
	void getOffsetRootTranslate()
	{
		fprintf(mFile,"\"%s.rtf\"",mName.c_str());

	}
	void getOffsetRootTranslateX()
	{
		fprintf(mFile,"\"%s.rtf.rtfx\"",mName.c_str());

	}
	void getOffsetRootTranslateY()
	{
		fprintf(mFile,"\"%s.rtf.rtfy\"",mName.c_str());

	}
	void getOffsetRootTranslateZ()
	{
		fprintf(mFile,"\"%s.rtf.rtfz\"",mName.c_str());

	}
	void getInitialOffsetRootTranslate()
	{
		fprintf(mFile,"\"%s.itf\"",mName.c_str());

	}
	void getInitialOffsetRootTranslateX()
	{
		fprintf(mFile,"\"%s.itf.itfx\"",mName.c_str());

	}
	void getInitialOffsetRootTranslateY()
	{
		fprintf(mFile,"\"%s.itf.itfy\"",mName.c_str());

	}
	void getInitialOffsetRootTranslateZ()
	{
		fprintf(mFile,"\"%s.itf.itfz\"",mName.c_str());

	}
	void getRotateControlScale()
	{
		fprintf(mFile,"\"%s.rcs\"",mName.c_str());

	}
	void getRotateControlScaleX()
	{
		fprintf(mFile,"\"%s.rcs.rcsx\"",mName.c_str());

	}
	void getRotateControlScaleY()
	{
		fprintf(mFile,"\"%s.rcs.rcsy\"",mName.c_str());

	}
	void getRotateControlScaleZ()
	{
		fprintf(mFile,"\"%s.rcs.rcsz\"",mName.c_str());

	}
	void getRotateControlParentMatrix()
	{
		fprintf(mFile,"\"%s.rcpm\"",mName.c_str());

	}
	void getOffsetRootRotate()
	{
		fprintf(mFile,"\"%s.rrf\"",mName.c_str());

	}
	void getOffsetRootRotateX()
	{
		fprintf(mFile,"\"%s.rrf.rrfx\"",mName.c_str());

	}
	void getOffsetRootRotateY()
	{
		fprintf(mFile,"\"%s.rrf.rrfy\"",mName.c_str());

	}
	void getOffsetRootRotateZ()
	{
		fprintf(mFile,"\"%s.rrf.rrfz\"",mName.c_str());

	}
	void getOffsetRootRotateOrder()
	{
		fprintf(mFile,"\"%s.rfor\"",mName.c_str());

	}
	void getOffsetRootRotatePivot()
	{
		fprintf(mFile,"\"%s.rpf\"",mName.c_str());

	}
	void getOffsetRootRotatePivotX()
	{
		fprintf(mFile,"\"%s.rpf.rppfx\"",mName.c_str());

	}
	void getOffsetRootRotatePivotY()
	{
		fprintf(mFile,"\"%s.rpf.rppfy\"",mName.c_str());

	}
	void getOffsetRootRotatePivotZ()
	{
		fprintf(mFile,"\"%s.rpf.rppfz\"",mName.c_str());

	}
	void getOutRootTranslate()
	{
		fprintf(mFile,"\"%s.rto\"",mName.c_str());

	}
	void getOutRootTranslateX()
	{
		fprintf(mFile,"\"%s.rto.rtox\"",mName.c_str());

	}
	void getOutRootTranslateY()
	{
		fprintf(mFile,"\"%s.rto.rtoy\"",mName.c_str());

	}
	void getOutRootTranslateZ()
	{
		fprintf(mFile,"\"%s.rto.rtoz\"",mName.c_str());

	}
	void getOutRootRotate()
	{
		fprintf(mFile,"\"%s.rro\"",mName.c_str());

	}
	void getOutRootRotateX()
	{
		fprintf(mFile,"\"%s.rro.rrox\"",mName.c_str());

	}
	void getOutRootRotateY()
	{
		fprintf(mFile,"\"%s.rro.rroy\"",mName.c_str());

	}
	void getOutRootRotateZ()
	{
		fprintf(mFile,"\"%s.rro.rroz\"",mName.c_str());

	}
protected:
	CharacterOffset(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CHARACTEROFFSET_H__
