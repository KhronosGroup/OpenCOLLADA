/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	ParentTessellate():AbstractBaseNurbsConversion(){}
	ParentTessellate(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseNurbsConversion(file, name, parent, "parentTessellate", shared, create){}
	virtual ~ParentTessellate(){}

	void setFormat(unsigned int f)
	{
		if(f == 1) return;
		fprintf(mFile,"\tsetAttr \".f\" %i;\n", f);
	}
	void setPolygonType(unsigned int pt)
	{
		if(pt == 0) return;
		fprintf(mFile,"\tsetAttr \".pt\" %i;\n", pt);
	}
	void setPolygonCount(int pc)
	{
		if(pc == 200) return;
		fprintf(mFile,"\tsetAttr \".pc\" %i;\n", pc);
	}
	void setChordHeightRatio(double chr)
	{
		if(chr == 0.983) return;
		fprintf(mFile,"\tsetAttr \".chr\" %f;\n", chr);
	}
	void setPre70ChordHeightRatio(bool pchr)
	{
		if(pchr == false) return;
		fprintf(mFile,"\tsetAttr \".pchr\" %i;\n", pchr);
	}
	void setFractionalTolerance(double ft)
	{
		if(ft == 0.01) return;
		fprintf(mFile,"\tsetAttr \".ft\" %f;\n", ft);
	}
	void setMinEdgeLength(double mel)
	{
		if(mel == 0) return;
		fprintf(mFile,"\tsetAttr \".mel\" %f;\n", mel);
	}
	void setDelta(double d)
	{
		if(d == 0) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setUType(unsigned int ut)
	{
		if(ut == 3) return;
		fprintf(mFile,"\tsetAttr \".ut\" %i;\n", ut);
	}
	void setUNumber(int un)
	{
		if(un == 3) return;
		fprintf(mFile,"\tsetAttr \".un\" %i;\n", un);
	}
	void setVType(unsigned int vt)
	{
		if(vt == 3) return;
		fprintf(mFile,"\tsetAttr \".vt\" %i;\n", vt);
	}
	void setVNumber(int vn)
	{
		if(vn == 3) return;
		fprintf(mFile,"\tsetAttr \".vn\" %i;\n", vn);
	}
	void setUseChordHeight(bool uch)
	{
		if(uch == false) return;
		fprintf(mFile,"\tsetAttr \".uch\" %i;\n", uch);
	}
	void setUseChordHeightRatio(bool ucr)
	{
		if(ucr == true) return;
		fprintf(mFile,"\tsetAttr \".ucr\" %i;\n", ucr);
	}
	void setChordHeight(double cht)
	{
		if(cht == 0) return;
		fprintf(mFile,"\tsetAttr \".cht\" %f;\n", cht);
	}
	void setEdgeSwap(bool es)
	{
		if(es == false) return;
		fprintf(mFile,"\tsetAttr \".es\" %i;\n", es);
	}
	void setMatchNormalDir(bool mnd)
	{
		if(mnd == false) return;
		fprintf(mFile,"\tsetAttr \".mnd\" %i;\n", mnd);
	}
	void setNormalizeTrimmedUVRange(bool ntr)
	{
		if(ntr == true) return;
		fprintf(mFile,"\tsetAttr \".ntr\" %i;\n", ntr);
	}
	void getFormat()const
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());
	}
	void getPolygonType()const
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());
	}
	void getPolygonCount()const
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());
	}
	void getChordHeightRatio()const
	{
		fprintf(mFile,"\"%s.chr\"",mName.c_str());
	}
	void getPre70ChordHeightRatio()const
	{
		fprintf(mFile,"\"%s.pchr\"",mName.c_str());
	}
	void getFractionalTolerance()const
	{
		fprintf(mFile,"\"%s.ft\"",mName.c_str());
	}
	void getMinEdgeLength()const
	{
		fprintf(mFile,"\"%s.mel\"",mName.c_str());
	}
	void getDelta()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getUType()const
	{
		fprintf(mFile,"\"%s.ut\"",mName.c_str());
	}
	void getUNumber()const
	{
		fprintf(mFile,"\"%s.un\"",mName.c_str());
	}
	void getVType()const
	{
		fprintf(mFile,"\"%s.vt\"",mName.c_str());
	}
	void getVNumber()const
	{
		fprintf(mFile,"\"%s.vn\"",mName.c_str());
	}
	void getUseChordHeight()const
	{
		fprintf(mFile,"\"%s.uch\"",mName.c_str());
	}
	void getUseChordHeightRatio()const
	{
		fprintf(mFile,"\"%s.ucr\"",mName.c_str());
	}
	void getChordHeight()const
	{
		fprintf(mFile,"\"%s.cht\"",mName.c_str());
	}
	void getEdgeSwap()const
	{
		fprintf(mFile,"\"%s.es\"",mName.c_str());
	}
	void getMatchNormalDir()const
	{
		fprintf(mFile,"\"%s.mnd\"",mName.c_str());
	}
	void getNormalizeTrimmedUVRange()const
	{
		fprintf(mFile,"\"%s.ntr\"",mName.c_str());
	}
	void getOutputPolygon()const
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());
	}
protected:
	ParentTessellate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseNurbsConversion(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARENTTESSELLATE_H__
