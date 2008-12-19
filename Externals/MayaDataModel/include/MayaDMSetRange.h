/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SETRANGE_H__
#define __MayaDM_SETRANGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class SetRange : public DependNode
{
public:
public:
	SetRange(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "setRange"){}
	virtual ~SetRange(){}
	void setValue(const float3& v)
	{
		if(v == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".v\" -type \"float3\" ");
		v.write(mFile);
		fprintf(mFile,";\n");

	}
	void setValueX(float vx)
	{
		if(vx == 0.0) return;
		fprintf(mFile,"setAttr \".v.vx\" %f;\n", vx);

	}
	void setValueY(float vy)
	{
		if(vy == 0.0) return;
		fprintf(mFile,"setAttr \".v.vy\" %f;\n", vy);

	}
	void setValueZ(float vz)
	{
		if(vz == 0.0) return;
		fprintf(mFile,"setAttr \".v.vz\" %f;\n", vz);

	}
	void setMin(const float3& n)
	{
		if(n == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".n\" -type \"float3\" ");
		n.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMinX(float nx)
	{
		if(nx == 0.0) return;
		fprintf(mFile,"setAttr \".n.nx\" %f;\n", nx);

	}
	void setMinY(float ny)
	{
		if(ny == 0.0) return;
		fprintf(mFile,"setAttr \".n.ny\" %f;\n", ny);

	}
	void setMinZ(float nz)
	{
		if(nz == 0.0) return;
		fprintf(mFile,"setAttr \".n.nz\" %f;\n", nz);

	}
	void setMax(const float3& m)
	{
		if(m == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".m\" -type \"float3\" ");
		m.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMaxX(float mx)
	{
		if(mx == 0.0) return;
		fprintf(mFile,"setAttr \".m.mx\" %f;\n", mx);

	}
	void setMaxY(float my)
	{
		if(my == 0.0) return;
		fprintf(mFile,"setAttr \".m.my\" %f;\n", my);

	}
	void setMaxZ(float mz)
	{
		if(mz == 0.0) return;
		fprintf(mFile,"setAttr \".m.mz\" %f;\n", mz);

	}
	void setOldMin(const float3& on)
	{
		if(on == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".on\" -type \"float3\" ");
		on.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOldMinX(float onx)
	{
		if(onx == 0.0) return;
		fprintf(mFile,"setAttr \".on.onx\" %f;\n", onx);

	}
	void setOldMinY(float ony)
	{
		if(ony == 0.0) return;
		fprintf(mFile,"setAttr \".on.ony\" %f;\n", ony);

	}
	void setOldMinZ(float onz)
	{
		if(onz == 0.0) return;
		fprintf(mFile,"setAttr \".on.onz\" %f;\n", onz);

	}
	void setOldMax(const float3& om)
	{
		if(om == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".om\" -type \"float3\" ");
		om.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOldMaxX(float omx)
	{
		if(omx == 0.0) return;
		fprintf(mFile,"setAttr \".om.omx\" %f;\n", omx);

	}
	void setOldMaxY(float omy)
	{
		if(omy == 0.0) return;
		fprintf(mFile,"setAttr \".om.omy\" %f;\n", omy);

	}
	void setOldMaxZ(float omz)
	{
		if(omz == 0.0) return;
		fprintf(mFile,"setAttr \".om.omz\" %f;\n", omz);

	}
	void getValue()
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());

	}
	void getValueX()
	{
		fprintf(mFile,"\"%s.v.vx\"",mName.c_str());

	}
	void getValueY()
	{
		fprintf(mFile,"\"%s.v.vy\"",mName.c_str());

	}
	void getValueZ()
	{
		fprintf(mFile,"\"%s.v.vz\"",mName.c_str());

	}
	void getMin()
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());

	}
	void getMinX()
	{
		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());

	}
	void getMinY()
	{
		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());

	}
	void getMinZ()
	{
		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());

	}
	void getMax()
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());

	}
	void getMaxX()
	{
		fprintf(mFile,"\"%s.m.mx\"",mName.c_str());

	}
	void getMaxY()
	{
		fprintf(mFile,"\"%s.m.my\"",mName.c_str());

	}
	void getMaxZ()
	{
		fprintf(mFile,"\"%s.m.mz\"",mName.c_str());

	}
	void getOldMin()
	{
		fprintf(mFile,"\"%s.on\"",mName.c_str());

	}
	void getOldMinX()
	{
		fprintf(mFile,"\"%s.on.onx\"",mName.c_str());

	}
	void getOldMinY()
	{
		fprintf(mFile,"\"%s.on.ony\"",mName.c_str());

	}
	void getOldMinZ()
	{
		fprintf(mFile,"\"%s.on.onz\"",mName.c_str());

	}
	void getOldMax()
	{
		fprintf(mFile,"\"%s.om\"",mName.c_str());

	}
	void getOldMaxX()
	{
		fprintf(mFile,"\"%s.om.omx\"",mName.c_str());

	}
	void getOldMaxY()
	{
		fprintf(mFile,"\"%s.om.omy\"",mName.c_str());

	}
	void getOldMaxZ()
	{
		fprintf(mFile,"\"%s.om.omz\"",mName.c_str());

	}
	void getOutValue()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getOutValueX()
	{
		fprintf(mFile,"\"%s.o.ox\"",mName.c_str());

	}
	void getOutValueY()
	{
		fprintf(mFile,"\"%s.o.oy\"",mName.c_str());

	}
	void getOutValueZ()
	{
		fprintf(mFile,"\"%s.o.oz\"",mName.c_str());

	}
protected:
	SetRange(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SETRANGE_H__
