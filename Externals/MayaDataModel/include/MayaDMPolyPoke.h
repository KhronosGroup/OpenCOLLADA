/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYPOKE_H__
#define __MayaDM_POLYPOKE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolyPoke : public PolyModifierWorld
{
public:
public:

	PolyPoke():PolyModifierWorld(){}
	PolyPoke(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, "polyPoke", shared, create){}
	virtual ~PolyPoke(){}

	void setTranslate(const double3& t)
	{
		if(t == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".t\" -type \"double3\" ");
		t.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTranslateX(double tx)
	{
		if(tx == 0) return;
		fprintf(mFile,"\tsetAttr \".t.tx\" %f;\n", tx);
	}
	void setTranslateY(double ty)
	{
		if(ty == 0) return;
		fprintf(mFile,"\tsetAttr \".t.ty\" %f;\n", ty);
	}
	void setTranslateZ(double tz)
	{
		if(tz == 0) return;
		fprintf(mFile,"\tsetAttr \".t.tz\" %f;\n", tz);
	}
	void setLocalTranslate(const double3& lt)
	{
		if(lt == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".lt\" -type \"double3\" ");
		lt.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLocalTranslateX(double ltx)
	{
		if(ltx == 0) return;
		fprintf(mFile,"\tsetAttr \".lt.ltx\" %f;\n", ltx);
	}
	void setLocalTranslateY(double lty)
	{
		if(lty == 0) return;
		fprintf(mFile,"\tsetAttr \".lt.lty\" %f;\n", lty);
	}
	void setLocalTranslateZ(double ltz)
	{
		if(ltz == 0) return;
		fprintf(mFile,"\tsetAttr \".lt.ltz\" %f;\n", ltz);
	}
	void setMaya70(bool m70)
	{
		if(m70 == true) return;
		fprintf(mFile,"\tsetAttr \".m70\" %i;\n", m70);
	}
	void getTranslate()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getTranslateX()const
	{
		fprintf(mFile,"\"%s.t.tx\"",mName.c_str());
	}
	void getTranslateY()const
	{
		fprintf(mFile,"\"%s.t.ty\"",mName.c_str());
	}
	void getTranslateZ()const
	{
		fprintf(mFile,"\"%s.t.tz\"",mName.c_str());
	}
	void getLocalTranslate()const
	{
		fprintf(mFile,"\"%s.lt\"",mName.c_str());
	}
	void getLocalTranslateX()const
	{
		fprintf(mFile,"\"%s.lt.ltx\"",mName.c_str());
	}
	void getLocalTranslateY()const
	{
		fprintf(mFile,"\"%s.lt.lty\"",mName.c_str());
	}
	void getLocalTranslateZ()const
	{
		fprintf(mFile,"\"%s.lt.ltz\"",mName.c_str());
	}
	void getMatrix()const
	{
		fprintf(mFile,"\"%s.cma\"",mName.c_str());
	}
protected:
	PolyPoke(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYPOKE_H__
