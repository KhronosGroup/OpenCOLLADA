/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	PolyPoke(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyPoke"){}
	virtual ~PolyPoke(){}
	void setTranslate(const double3& t)
	{
		if(t == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"setAttr \".t\" -type \"double3\" ");
		t.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTranslateX(double tx)
	{
		if(tx == 0) return;
		fprintf(mFile,"setAttr \".t.tx\" %f;\n", tx);

	}
	void setTranslateY(double ty)
	{
		if(ty == 0) return;
		fprintf(mFile,"setAttr \".t.ty\" %f;\n", ty);

	}
	void setTranslateZ(double tz)
	{
		if(tz == 0) return;
		fprintf(mFile,"setAttr \".t.tz\" %f;\n", tz);

	}
	void setLocalTranslate(const double3& lt)
	{
		if(lt == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"setAttr \".lt\" -type \"double3\" ");
		lt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLocalTranslateX(double ltx)
	{
		if(ltx == 0) return;
		fprintf(mFile,"setAttr \".lt.ltx\" %f;\n", ltx);

	}
	void setLocalTranslateY(double lty)
	{
		if(lty == 0) return;
		fprintf(mFile,"setAttr \".lt.lty\" %f;\n", lty);

	}
	void setLocalTranslateZ(double ltz)
	{
		if(ltz == 0) return;
		fprintf(mFile,"setAttr \".lt.ltz\" %f;\n", ltz);

	}
	void setMaya70(bool m70)
	{
		if(m70 == true) return;
		fprintf(mFile,"setAttr \".m70\" %i;\n", m70);

	}
	void getTranslate()
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());

	}
	void getTranslateX()
	{
		fprintf(mFile,"\"%s.t.tx\"",mName.c_str());

	}
	void getTranslateY()
	{
		fprintf(mFile,"\"%s.t.ty\"",mName.c_str());

	}
	void getTranslateZ()
	{
		fprintf(mFile,"\"%s.t.tz\"",mName.c_str());

	}
	void getLocalTranslate()
	{
		fprintf(mFile,"\"%s.lt\"",mName.c_str());

	}
	void getLocalTranslateX()
	{
		fprintf(mFile,"\"%s.lt.ltx\"",mName.c_str());

	}
	void getLocalTranslateY()
	{
		fprintf(mFile,"\"%s.lt.lty\"",mName.c_str());

	}
	void getLocalTranslateZ()
	{
		fprintf(mFile,"\"%s.lt.ltz\"",mName.c_str());

	}
	void getMatrix()
	{
		fprintf(mFile,"\"%s.cma\"",mName.c_str());

	}
protected:
	PolyPoke(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYPOKE_H__
