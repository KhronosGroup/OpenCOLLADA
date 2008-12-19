/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HYPERVIEW_H__
#define __MayaDM_HYPERVIEW_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class HyperView : public DependNode
{
public:
public:
	HyperView(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "hyperView"){}
	virtual ~HyperView(){}
	void setPosition(const double2& p)
	{
		if(p == double2(0, 0)) return;
		fprintf(mFile,"setAttr \".p\" -type \"double2\" ");
		p.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPositionX(double px)
	{
		if(px == 0.0) return;
		fprintf(mFile,"setAttr \".p.px\" %f;\n", px);

	}
	void setPositionY(double py)
	{
		if(py == 0.0) return;
		fprintf(mFile,"setAttr \".p.py\" %f;\n", py);

	}
	void setViewRectLow(const double2& vl)
	{
		if(vl == double2(0, 0)) return;
		fprintf(mFile,"setAttr \".vl\" -type \"double2\" ");
		vl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setViewXL(double xl)
	{
		if(xl == 0.0) return;
		fprintf(mFile,"setAttr \".vl.xl\" %f;\n", xl);

	}
	void setViewYL(double yl)
	{
		if(yl == 0.0) return;
		fprintf(mFile,"setAttr \".vl.yl\" %f;\n", yl);

	}
	void setViewRectHigh(const double2& vh)
	{
		if(vh == double2(0, 0)) return;
		fprintf(mFile,"setAttr \".vh\" -type \"double2\" ");
		vh.write(mFile);
		fprintf(mFile,";\n");

	}
	void setViewXH(double xh)
	{
		if(xh == 0.0) return;
		fprintf(mFile,"setAttr \".vh.xh\" %f;\n", xh);

	}
	void setViewYH(double yh)
	{
		if(yh == 0.0) return;
		fprintf(mFile,"setAttr \".vh.yh\" %f;\n", yh);

	}
	void setDagView(bool dag)
	{
		if(dag == true) return;
		fprintf(mFile,"setAttr \".dag\" %i;\n", dag);

	}
	void setDescription(const string& d)
	{
		if(d == "") return;
		fprintf(mFile,"setAttr \".d\" -type \"string\" ");
		d.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFullName(const string& fn)
	{
		if(fn == "") return;
		fprintf(mFile,"setAttr \".fn\" -type \"string\" ");
		fn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setShortName(const string& sn)
	{
		if(sn == "") return;
		fprintf(mFile,"setAttr \".sn\" -type \"string\" ");
		sn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBuildDirection(unsigned int bd)
	{
		if(bd == 2) return;
		fprintf(mFile,"setAttr \".bd\" %i;\n", bd);

	}
	void setGraphTraversalLimit(int gtl)
	{
		if(gtl == -1) return;
		fprintf(mFile,"setAttr \".gtl\" %i;\n", gtl);

	}
	void getPosition()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getPositionX()
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());

	}
	void getPositionY()
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());

	}
	void getViewRectLow()
	{
		fprintf(mFile,"\"%s.vl\"",mName.c_str());

	}
	void getViewXL()
	{
		fprintf(mFile,"\"%s.vl.xl\"",mName.c_str());

	}
	void getViewYL()
	{
		fprintf(mFile,"\"%s.vl.yl\"",mName.c_str());

	}
	void getViewRectHigh()
	{
		fprintf(mFile,"\"%s.vh\"",mName.c_str());

	}
	void getViewXH()
	{
		fprintf(mFile,"\"%s.vh.xh\"",mName.c_str());

	}
	void getViewYH()
	{
		fprintf(mFile,"\"%s.vh.yh\"",mName.c_str());

	}
	void getDagView()
	{
		fprintf(mFile,"\"%s.dag\"",mName.c_str());

	}
	void getDescription()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getFocusNode()
	{
		fprintf(mFile,"\"%s.fnd\"",mName.c_str());

	}
	void getRootNode(size_t rnd_i)
	{
		fprintf(mFile,"\"%s.rnd[%i]\"",mName.c_str(),rnd_i);

	}
	void getFullName()
	{
		fprintf(mFile,"\"%s.fn\"",mName.c_str());

	}
	void getShortName()
	{
		fprintf(mFile,"\"%s.sn\"",mName.c_str());

	}
	void getBuildDirection()
	{
		fprintf(mFile,"\"%s.bd\"",mName.c_str());

	}
	void getGraphTraversalLimit()
	{
		fprintf(mFile,"\"%s.gtl\"",mName.c_str());

	}
	void getHyperLayout()
	{
		fprintf(mFile,"\"%s.hl\"",mName.c_str());

	}
protected:
	HyperView(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_HYPERVIEW_H__
