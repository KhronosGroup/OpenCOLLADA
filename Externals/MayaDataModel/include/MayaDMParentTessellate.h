/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARENTTESSELLATE_H__
#define __MayaDM_PARENTTESSELLATE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseNurbsConversion.h"
namespace MayaDM
{
class ParentTessellate : public AbstractBaseNurbsConversion
{
public:
public:
	ParentTessellate(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseNurbsConversion(file, name, parent, "parentTessellate"){}
	virtual ~ParentTessellate(){}
	void setFormat(unsigned int f)
	{
		if(f == 1) return;
		fprintf(mFile,"setAttr \".f\" %i;\n", f);

	}
	void setPolygonType(unsigned int pt)
	{
		if(pt == 0) return;
		fprintf(mFile,"setAttr \".pt\" %i;\n", pt);

	}
	void setPolygonCount(int pc)
	{
		if(pc == 200) return;
		fprintf(mFile,"setAttr \".pc\" %i;\n", pc);

	}
	void setChordHeightRatio(double chr)
	{
		if(chr == 0.983) return;
		fprintf(mFile,"setAttr \".chr\" %f;\n", chr);

	}
	void setPre70ChordHeightRatio(bool pchr)
	{
		if(pchr == false) return;
		fprintf(mFile,"setAttr \".pchr\" %i;\n", pchr);

	}
	void setFractionalTolerance(double ft)
	{
		if(ft == 0.01) return;
		fprintf(mFile,"setAttr \".ft\" %f;\n", ft);

	}
	void setMinEdgeLength(double mel)
	{
		if(mel == 0) return;
		fprintf(mFile,"setAttr \".mel\" %f;\n", mel);

	}
	void setDelta(double d)
	{
		if(d == 0) return;
		fprintf(mFile,"setAttr \".d\" %f;\n", d);

	}
	void setUType(unsigned int ut)
	{
		if(ut == 3) return;
		fprintf(mFile,"setAttr \".ut\" %i;\n", ut);

	}
	void setUNumber(int un)
	{
		if(un == 3) return;
		fprintf(mFile,"setAttr \".un\" %i;\n", un);

	}
	void setVType(unsigned int vt)
	{
		if(vt == 3) return;
		fprintf(mFile,"setAttr \".vt\" %i;\n", vt);

	}
	void setVNumber(int vn)
	{
		if(vn == 3) return;
		fprintf(mFile,"setAttr \".vn\" %i;\n", vn);

	}
	void setUseChordHeight(bool uch)
	{
		if(uch == false) return;
		fprintf(mFile,"setAttr \".uch\" %i;\n", uch);

	}
	void setUseChordHeightRatio(bool ucr)
	{
		if(ucr == true) return;
		fprintf(mFile,"setAttr \".ucr\" %i;\n", ucr);

	}
	void setChordHeight(double cht)
	{
		if(cht == 0) return;
		fprintf(mFile,"setAttr \".cht\" %f;\n", cht);

	}
	void setEdgeSwap(bool es)
	{
		if(es == false) return;
		fprintf(mFile,"setAttr \".es\" %i;\n", es);

	}
	void setMatchNormalDir(bool mnd)
	{
		if(mnd == false) return;
		fprintf(mFile,"setAttr \".mnd\" %i;\n", mnd);

	}
	void setNormalizeTrimmedUVRange(bool ntr)
	{
		if(ntr == true) return;
		fprintf(mFile,"setAttr \".ntr\" %i;\n", ntr);

	}
	void getFormat()
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());

	}
	void getPolygonType()
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());

	}
	void getPolygonCount()
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());

	}
	void getChordHeightRatio()
	{
		fprintf(mFile,"\"%s.chr\"",mName.c_str());

	}
	void getPre70ChordHeightRatio()
	{
		fprintf(mFile,"\"%s.pchr\"",mName.c_str());

	}
	void getFractionalTolerance()
	{
		fprintf(mFile,"\"%s.ft\"",mName.c_str());

	}
	void getMinEdgeLength()
	{
		fprintf(mFile,"\"%s.mel\"",mName.c_str());

	}
	void getDelta()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getUType()
	{
		fprintf(mFile,"\"%s.ut\"",mName.c_str());

	}
	void getUNumber()
	{
		fprintf(mFile,"\"%s.un\"",mName.c_str());

	}
	void getVType()
	{
		fprintf(mFile,"\"%s.vt\"",mName.c_str());

	}
	void getVNumber()
	{
		fprintf(mFile,"\"%s.vn\"",mName.c_str());

	}
	void getUseChordHeight()
	{
		fprintf(mFile,"\"%s.uch\"",mName.c_str());

	}
	void getUseChordHeightRatio()
	{
		fprintf(mFile,"\"%s.ucr\"",mName.c_str());

	}
	void getChordHeight()
	{
		fprintf(mFile,"\"%s.cht\"",mName.c_str());

	}
	void getEdgeSwap()
	{
		fprintf(mFile,"\"%s.es\"",mName.c_str());

	}
	void getMatchNormalDir()
	{
		fprintf(mFile,"\"%s.mnd\"",mName.c_str());

	}
	void getNormalizeTrimmedUVRange()
	{
		fprintf(mFile,"\"%s.ntr\"",mName.c_str());

	}
	void getOutputPolygon()
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());

	}
protected:
	ParentTessellate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseNurbsConversion(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARENTTESSELLATE_H__
