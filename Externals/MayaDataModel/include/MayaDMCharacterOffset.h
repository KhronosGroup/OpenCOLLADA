/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	CharacterOffset():DependNode(){}
	CharacterOffset(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "characterOffset", shared, create){}
	virtual ~CharacterOffset(){}

	void setInRootTranslate(const double3& rti)
	{
		fprintf(mFile,"\tsetAttr \".rti\" -type \"double3\" ");
		rti.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInRootTranslateX(double rtix)
	{
		if(rtix == 0) return;
		fprintf(mFile,"\tsetAttr \".rti.rtix\" %f;\n", rtix);
	}
	void setInRootTranslateY(double rtiy)
	{
		if(rtiy == 0) return;
		fprintf(mFile,"\tsetAttr \".rti.rtiy\" %f;\n", rtiy);
	}
	void setInRootTranslateZ(double rtiz)
	{
		if(rtiz == 0) return;
		fprintf(mFile,"\tsetAttr \".rti.rtiz\" %f;\n", rtiz);
	}
	void setInRootRotate(const double3& rri)
	{
		fprintf(mFile,"\tsetAttr \".rri\" -type \"double3\" ");
		rri.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInRootRotateX(double rrix)
	{
		if(rrix == 0) return;
		fprintf(mFile,"\tsetAttr \".rri.rrix\" %f;\n", rrix);
	}
	void setInRootRotateY(double rriy)
	{
		if(rriy == 0) return;
		fprintf(mFile,"\tsetAttr \".rri.rriy\" %f;\n", rriy);
	}
	void setInRootRotateZ(double rriz)
	{
		if(rriz == 0) return;
		fprintf(mFile,"\tsetAttr \".rri.rriz\" %f;\n", rriz);
	}
	void setRootRotateOrder(unsigned int rror)
	{
		if(rror == 0) return;
		fprintf(mFile,"\tsetAttr \".rror\" %i;\n", rror);
	}
	void setRootJointOrient(const double3& rjo)
	{
		fprintf(mFile,"\tsetAttr \".rjo\" -type \"double3\" ");
		rjo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRootJointOrientX(double rjox)
	{
		if(rjox == 0) return;
		fprintf(mFile,"\tsetAttr \".rjo.rjox\" %f;\n", rjox);
	}
	void setRootJointOrientY(double rjoy)
	{
		if(rjoy == 0) return;
		fprintf(mFile,"\tsetAttr \".rjo.rjoy\" %f;\n", rjoy);
	}
	void setRootJointOrientZ(double rjoz)
	{
		if(rjoz == 0) return;
		fprintf(mFile,"\tsetAttr \".rjo.rjoz\" %f;\n", rjoz);
	}
	void setRootParentMatrix(const matrix& rpm)
	{
		if(rpm == identity) return;
		fprintf(mFile,"\tsetAttr \".rpm\" -type \"matrix\" ");
		rpm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRootParentInverseMatrix(const matrix& rpim)
	{
		if(rpim == identity) return;
		fprintf(mFile,"\tsetAttr \".rpim\" -type \"matrix\" ");
		rpim.write(mFile);
		fprintf(mFile,";\n");
	}
	void setApplyControlParentTransform(bool acpx)
	{
		if(acpx == false) return;
		fprintf(mFile,"\tsetAttr \".acpx\" %i;\n", acpx);
	}
	void setEnable(bool nabl)
	{
		if(nabl == true) return;
		fprintf(mFile,"\tsetAttr \".nabl\" %i;\n", nabl);
	}
	void setOffsetRootTranslate(const double3& rtf)
	{
		fprintf(mFile,"\tsetAttr \".rtf\" -type \"double3\" ");
		rtf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOffsetRootTranslateX(double rtfx)
	{
		if(rtfx == 0) return;
		fprintf(mFile,"\tsetAttr \".rtf.rtfx\" %f;\n", rtfx);
	}
	void setOffsetRootTranslateY(double rtfy)
	{
		if(rtfy == 0) return;
		fprintf(mFile,"\tsetAttr \".rtf.rtfy\" %f;\n", rtfy);
	}
	void setOffsetRootTranslateZ(double rtfz)
	{
		if(rtfz == 0) return;
		fprintf(mFile,"\tsetAttr \".rtf.rtfz\" %f;\n", rtfz);
	}
	void setInitialOffsetRootTranslate(const double3& itf)
	{
		fprintf(mFile,"\tsetAttr \".itf\" -type \"double3\" ");
		itf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInitialOffsetRootTranslateX(double itfx)
	{
		if(itfx == 0) return;
		fprintf(mFile,"\tsetAttr \".itf.itfx\" %f;\n", itfx);
	}
	void setInitialOffsetRootTranslateY(double itfy)
	{
		if(itfy == 0) return;
		fprintf(mFile,"\tsetAttr \".itf.itfy\" %f;\n", itfy);
	}
	void setInitialOffsetRootTranslateZ(double itfz)
	{
		if(itfz == 0) return;
		fprintf(mFile,"\tsetAttr \".itf.itfz\" %f;\n", itfz);
	}
	void setRotateControlScale(const double3& rcs)
	{
		fprintf(mFile,"\tsetAttr \".rcs\" -type \"double3\" ");
		rcs.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRotateControlScaleX(double rcsx)
	{
		if(rcsx == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rcs.rcsx\" %f;\n", rcsx);
	}
	void setRotateControlScaleY(double rcsy)
	{
		if(rcsy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rcs.rcsy\" %f;\n", rcsy);
	}
	void setRotateControlScaleZ(double rcsz)
	{
		if(rcsz == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rcs.rcsz\" %f;\n", rcsz);
	}
	void setRotateControlParentMatrix(const matrix& rcpm)
	{
		if(rcpm == identity) return;
		fprintf(mFile,"\tsetAttr \".rcpm\" -type \"matrix\" ");
		rcpm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOffsetRootRotate(const double3& rrf)
	{
		fprintf(mFile,"\tsetAttr \".rrf\" -type \"double3\" ");
		rrf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOffsetRootRotateX(double rrfx)
	{
		if(rrfx == 0) return;
		fprintf(mFile,"\tsetAttr \".rrf.rrfx\" %f;\n", rrfx);
	}
	void setOffsetRootRotateY(double rrfy)
	{
		if(rrfy == 0) return;
		fprintf(mFile,"\tsetAttr \".rrf.rrfy\" %f;\n", rrfy);
	}
	void setOffsetRootRotateZ(double rrfz)
	{
		if(rrfz == 0) return;
		fprintf(mFile,"\tsetAttr \".rrf.rrfz\" %f;\n", rrfz);
	}
	void setOffsetRootRotateOrder(unsigned int rfor)
	{
		if(rfor == 0) return;
		fprintf(mFile,"\tsetAttr \".rfor\" %i;\n", rfor);
	}
	void setOffsetRootRotatePivot(const double3& rpf)
	{
		fprintf(mFile,"\tsetAttr \".rpf\" -type \"double3\" ");
		rpf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOffsetRootRotatePivotX(double rppfx)
	{
		if(rppfx == 0) return;
		fprintf(mFile,"\tsetAttr \".rpf.rppfx\" %f;\n", rppfx);
	}
	void setOffsetRootRotatePivotY(double rppfy)
	{
		if(rppfy == 0) return;
		fprintf(mFile,"\tsetAttr \".rpf.rppfy\" %f;\n", rppfy);
	}
	void setOffsetRootRotatePivotZ(double rppfz)
	{
		if(rppfz == 0) return;
		fprintf(mFile,"\tsetAttr \".rpf.rppfz\" %f;\n", rppfz);
	}
	void getInRootTranslate()const
	{
		fprintf(mFile,"\"%s.rti\"",mName.c_str());
	}
	void getInRootTranslateX()const
	{
		fprintf(mFile,"\"%s.rti.rtix\"",mName.c_str());
	}
	void getInRootTranslateY()const
	{
		fprintf(mFile,"\"%s.rti.rtiy\"",mName.c_str());
	}
	void getInRootTranslateZ()const
	{
		fprintf(mFile,"\"%s.rti.rtiz\"",mName.c_str());
	}
	void getInRootRotate()const
	{
		fprintf(mFile,"\"%s.rri\"",mName.c_str());
	}
	void getInRootRotateX()const
	{
		fprintf(mFile,"\"%s.rri.rrix\"",mName.c_str());
	}
	void getInRootRotateY()const
	{
		fprintf(mFile,"\"%s.rri.rriy\"",mName.c_str());
	}
	void getInRootRotateZ()const
	{
		fprintf(mFile,"\"%s.rri.rriz\"",mName.c_str());
	}
	void getRootRotateOrder()const
	{
		fprintf(mFile,"\"%s.rror\"",mName.c_str());
	}
	void getRootJointOrient()const
	{
		fprintf(mFile,"\"%s.rjo\"",mName.c_str());
	}
	void getRootJointOrientX()const
	{
		fprintf(mFile,"\"%s.rjo.rjox\"",mName.c_str());
	}
	void getRootJointOrientY()const
	{
		fprintf(mFile,"\"%s.rjo.rjoy\"",mName.c_str());
	}
	void getRootJointOrientZ()const
	{
		fprintf(mFile,"\"%s.rjo.rjoz\"",mName.c_str());
	}
	void getRootParentMatrix()const
	{
		fprintf(mFile,"\"%s.rpm\"",mName.c_str());
	}
	void getRootParentInverseMatrix()const
	{
		fprintf(mFile,"\"%s.rpim\"",mName.c_str());
	}
	void getApplyControlParentTransform()const
	{
		fprintf(mFile,"\"%s.acpx\"",mName.c_str());
	}
	void getEnable()const
	{
		fprintf(mFile,"\"%s.nabl\"",mName.c_str());
	}
	void getOffsetRootTranslate()const
	{
		fprintf(mFile,"\"%s.rtf\"",mName.c_str());
	}
	void getOffsetRootTranslateX()const
	{
		fprintf(mFile,"\"%s.rtf.rtfx\"",mName.c_str());
	}
	void getOffsetRootTranslateY()const
	{
		fprintf(mFile,"\"%s.rtf.rtfy\"",mName.c_str());
	}
	void getOffsetRootTranslateZ()const
	{
		fprintf(mFile,"\"%s.rtf.rtfz\"",mName.c_str());
	}
	void getInitialOffsetRootTranslate()const
	{
		fprintf(mFile,"\"%s.itf\"",mName.c_str());
	}
	void getInitialOffsetRootTranslateX()const
	{
		fprintf(mFile,"\"%s.itf.itfx\"",mName.c_str());
	}
	void getInitialOffsetRootTranslateY()const
	{
		fprintf(mFile,"\"%s.itf.itfy\"",mName.c_str());
	}
	void getInitialOffsetRootTranslateZ()const
	{
		fprintf(mFile,"\"%s.itf.itfz\"",mName.c_str());
	}
	void getRotateControlScale()const
	{
		fprintf(mFile,"\"%s.rcs\"",mName.c_str());
	}
	void getRotateControlScaleX()const
	{
		fprintf(mFile,"\"%s.rcs.rcsx\"",mName.c_str());
	}
	void getRotateControlScaleY()const
	{
		fprintf(mFile,"\"%s.rcs.rcsy\"",mName.c_str());
	}
	void getRotateControlScaleZ()const
	{
		fprintf(mFile,"\"%s.rcs.rcsz\"",mName.c_str());
	}
	void getRotateControlParentMatrix()const
	{
		fprintf(mFile,"\"%s.rcpm\"",mName.c_str());
	}
	void getOffsetRootRotate()const
	{
		fprintf(mFile,"\"%s.rrf\"",mName.c_str());
	}
	void getOffsetRootRotateX()const
	{
		fprintf(mFile,"\"%s.rrf.rrfx\"",mName.c_str());
	}
	void getOffsetRootRotateY()const
	{
		fprintf(mFile,"\"%s.rrf.rrfy\"",mName.c_str());
	}
	void getOffsetRootRotateZ()const
	{
		fprintf(mFile,"\"%s.rrf.rrfz\"",mName.c_str());
	}
	void getOffsetRootRotateOrder()const
	{
		fprintf(mFile,"\"%s.rfor\"",mName.c_str());
	}
	void getOffsetRootRotatePivot()const
	{
		fprintf(mFile,"\"%s.rpf\"",mName.c_str());
	}
	void getOffsetRootRotatePivotX()const
	{
		fprintf(mFile,"\"%s.rpf.rppfx\"",mName.c_str());
	}
	void getOffsetRootRotatePivotY()const
	{
		fprintf(mFile,"\"%s.rpf.rppfy\"",mName.c_str());
	}
	void getOffsetRootRotatePivotZ()const
	{
		fprintf(mFile,"\"%s.rpf.rppfz\"",mName.c_str());
	}
	void getOutRootTranslate()const
	{
		fprintf(mFile,"\"%s.rto\"",mName.c_str());
	}
	void getOutRootTranslateX()const
	{
		fprintf(mFile,"\"%s.rto.rtox\"",mName.c_str());
	}
	void getOutRootTranslateY()const
	{
		fprintf(mFile,"\"%s.rto.rtoy\"",mName.c_str());
	}
	void getOutRootTranslateZ()const
	{
		fprintf(mFile,"\"%s.rto.rtoz\"",mName.c_str());
	}
	void getOutRootRotate()const
	{
		fprintf(mFile,"\"%s.rro\"",mName.c_str());
	}
	void getOutRootRotateX()const
	{
		fprintf(mFile,"\"%s.rro.rrox\"",mName.c_str());
	}
	void getOutRootRotateY()const
	{
		fprintf(mFile,"\"%s.rro.rroy\"",mName.c_str());
	}
	void getOutRootRotateZ()const
	{
		fprintf(mFile,"\"%s.rro.rroz\"",mName.c_str());
	}
protected:
	CharacterOffset(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CHARACTEROFFSET_H__
