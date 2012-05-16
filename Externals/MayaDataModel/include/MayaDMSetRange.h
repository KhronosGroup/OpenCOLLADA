/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	SetRange():DependNode(){}
	SetRange(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "setRange", shared, create){}
	virtual ~SetRange(){}

	void setValue(const float3& v)
	{
		if(v == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".v\" -type \"float3\" ");
		v.write(mFile);
		fprintf(mFile,";\n");
	}
	void setValueX(float vx)
	{
		if(vx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".v.vx\" %f;\n", vx);
	}
	void setValueY(float vy)
	{
		if(vy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".v.vy\" %f;\n", vy);
	}
	void setValueZ(float vz)
	{
		if(vz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".v.vz\" %f;\n", vz);
	}
	void setMin(const float3& n)
	{
		if(n == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".n\" -type \"float3\" ");
		n.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMinX(float nx)
	{
		if(nx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".n.nx\" %f;\n", nx);
	}
	void setMinY(float ny)
	{
		if(ny == 0.0) return;
		fprintf(mFile,"\tsetAttr \".n.ny\" %f;\n", ny);
	}
	void setMinZ(float nz)
	{
		if(nz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".n.nz\" %f;\n", nz);
	}
	void setMax(const float3& m)
	{
		if(m == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".m\" -type \"float3\" ");
		m.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMaxX(float mx)
	{
		if(mx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".m.mx\" %f;\n", mx);
	}
	void setMaxY(float my)
	{
		if(my == 0.0) return;
		fprintf(mFile,"\tsetAttr \".m.my\" %f;\n", my);
	}
	void setMaxZ(float mz)
	{
		if(mz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".m.mz\" %f;\n", mz);
	}
	void setOldMin(const float3& on)
	{
		if(on == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".on\" -type \"float3\" ");
		on.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOldMinX(float onx)
	{
		if(onx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".on.onx\" %f;\n", onx);
	}
	void setOldMinY(float ony)
	{
		if(ony == 0.0) return;
		fprintf(mFile,"\tsetAttr \".on.ony\" %f;\n", ony);
	}
	void setOldMinZ(float onz)
	{
		if(onz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".on.onz\" %f;\n", onz);
	}
	void setOldMax(const float3& om)
	{
		if(om == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".om\" -type \"float3\" ");
		om.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOldMaxX(float omx)
	{
		if(omx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".om.omx\" %f;\n", omx);
	}
	void setOldMaxY(float omy)
	{
		if(omy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".om.omy\" %f;\n", omy);
	}
	void setOldMaxZ(float omz)
	{
		if(omz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".om.omz\" %f;\n", omz);
	}
	void getValue()const
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getValueX()const
	{
		fprintf(mFile,"\"%s.v.vx\"",mName.c_str());
	}
	void getValueY()const
	{
		fprintf(mFile,"\"%s.v.vy\"",mName.c_str());
	}
	void getValueZ()const
	{
		fprintf(mFile,"\"%s.v.vz\"",mName.c_str());
	}
	void getMin()const
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());
	}
	void getMinX()const
	{
		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());
	}
	void getMinY()const
	{
		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());
	}
	void getMinZ()const
	{
		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());
	}
	void getMax()const
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());
	}
	void getMaxX()const
	{
		fprintf(mFile,"\"%s.m.mx\"",mName.c_str());
	}
	void getMaxY()const
	{
		fprintf(mFile,"\"%s.m.my\"",mName.c_str());
	}
	void getMaxZ()const
	{
		fprintf(mFile,"\"%s.m.mz\"",mName.c_str());
	}
	void getOldMin()const
	{
		fprintf(mFile,"\"%s.on\"",mName.c_str());
	}
	void getOldMinX()const
	{
		fprintf(mFile,"\"%s.on.onx\"",mName.c_str());
	}
	void getOldMinY()const
	{
		fprintf(mFile,"\"%s.on.ony\"",mName.c_str());
	}
	void getOldMinZ()const
	{
		fprintf(mFile,"\"%s.on.onz\"",mName.c_str());
	}
	void getOldMax()const
	{
		fprintf(mFile,"\"%s.om\"",mName.c_str());
	}
	void getOldMaxX()const
	{
		fprintf(mFile,"\"%s.om.omx\"",mName.c_str());
	}
	void getOldMaxY()const
	{
		fprintf(mFile,"\"%s.om.omy\"",mName.c_str());
	}
	void getOldMaxZ()const
	{
		fprintf(mFile,"\"%s.om.omz\"",mName.c_str());
	}
	void getOutValue()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getOutValueX()const
	{
		fprintf(mFile,"\"%s.o.ox\"",mName.c_str());
	}
	void getOutValueY()const
	{
		fprintf(mFile,"\"%s.o.oy\"",mName.c_str());
	}
	void getOutValueZ()const
	{
		fprintf(mFile,"\"%s.o.oz\"",mName.c_str());
	}
protected:
	SetRange(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SETRANGE_H__
