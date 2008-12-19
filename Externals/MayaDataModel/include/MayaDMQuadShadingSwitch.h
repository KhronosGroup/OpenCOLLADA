/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_QUADSHADINGSWITCH_H__
#define __MayaDM_QUADSHADINGSWITCH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseShadingSwitch.h"
namespace MayaDM
{
class QuadShadingSwitch : public BaseShadingSwitch
{
public:
	struct Input{
		struct InQuad{
			float3 inTriple;
			float inSingle;
			void write(FILE* file) const
			{
				inTriple.write(file);
				fprintf(file, " ");
				fprintf(file,"%f", inSingle);
			}
		} inQuad;
		void write(FILE* file) const
		{
			inQuad.write(file);
			fprintf(file, " ");
		}
	};
	struct Default{
		float3 defTriple;
		float defSingle;
		void write(FILE* file) const
		{
			defTriple.write(file);
			fprintf(file, " ");
			fprintf(file,"%f", defSingle);
		}
	};
	struct Output{
		void write(FILE* file) const
		{
		}
	};
public:
	QuadShadingSwitch(FILE* file,const std::string& name,const std::string& parent=""):BaseShadingSwitch(file, name, parent, "quadShadingSwitch"){}
	virtual ~QuadShadingSwitch(){}
	void setInput(size_t i_i,const Input& i)
	{
		fprintf(mFile,"setAttr \".i[%i]\" ",i_i);
		i.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInQuad(size_t i_i,const Input::InQuad& iq)
	{
		fprintf(mFile,"setAttr \".i[%i].iq\" ",i_i);
		iq.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInTriple(size_t i_i,const float3& itr)
	{
		fprintf(mFile,"setAttr \".i[%i].iq.itr\" -type \"float3\" ",i_i);
		itr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInComp1(size_t i_i,float ic1)
	{
		if(ic1 == 0.0) return;
		fprintf(mFile,"setAttr \".i[%i].iq.itr.ic1\" %f;\n", i_i,ic1);

	}
	void setInComp2(size_t i_i,float ic2)
	{
		if(ic2 == 0.0) return;
		fprintf(mFile,"setAttr \".i[%i].iq.itr.ic2\" %f;\n", i_i,ic2);

	}
	void setInComp3(size_t i_i,float ic3)
	{
		if(ic3 == 0.0) return;
		fprintf(mFile,"setAttr \".i[%i].iq.itr.ic3\" %f;\n", i_i,ic3);

	}
	void setInSingle(size_t i_i,float isi)
	{
		if(isi == 0.0) return;
		fprintf(mFile,"setAttr \".i[%i].iq.isi\" %f;\n", i_i,isi);

	}
	void setDefault(const Default& def)
	{
		fprintf(mFile,"setAttr \".def\" ");
		def.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDefTriple(const float3& dtr)
	{
		if(dtr == float3(0.8f,0.8f,0.8f)) return;
		fprintf(mFile,"setAttr \".def.dtr\" -type \"float3\" ");
		dtr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDefComp1(float dc1)
	{
		if(dc1 == 0.0) return;
		fprintf(mFile,"setAttr \".def.dtr.dc1\" %f;\n", dc1);

	}
	void setDefComp2(float dc2)
	{
		if(dc2 == 0.0) return;
		fprintf(mFile,"setAttr \".def.dtr.dc2\" %f;\n", dc2);

	}
	void setDefComp3(float dc3)
	{
		if(dc3 == 0.0) return;
		fprintf(mFile,"setAttr \".def.dtr.dc3\" %f;\n", dc3);

	}
	void setDefSingle(float dsi)
	{
		if(dsi == 0.0) return;
		fprintf(mFile,"setAttr \".def.dsi\" %f;\n", dsi);

	}
	void getInput(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i]\"",mName.c_str(),i_i);

	}
	void getInQuad(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].iq\"",mName.c_str(),i_i);

	}
	void getInTriple(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].iq.itr\"",mName.c_str(),i_i);

	}
	void getInComp1(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].iq.itr.ic1\"",mName.c_str(),i_i);

	}
	void getInComp2(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].iq.itr.ic2\"",mName.c_str(),i_i);

	}
	void getInComp3(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].iq.itr.ic3\"",mName.c_str(),i_i);

	}
	void getInSingle(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].iq.isi\"",mName.c_str(),i_i);

	}
	void getInShape(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].is\"",mName.c_str(),i_i);

	}
	void getDefault()
	{
		fprintf(mFile,"\"%s.def\"",mName.c_str());

	}
	void getDefTriple()
	{
		fprintf(mFile,"\"%s.def.dtr\"",mName.c_str());

	}
	void getDefComp1()
	{
		fprintf(mFile,"\"%s.def.dtr.dc1\"",mName.c_str());

	}
	void getDefComp2()
	{
		fprintf(mFile,"\"%s.def.dtr.dc2\"",mName.c_str());

	}
	void getDefComp3()
	{
		fprintf(mFile,"\"%s.def.dtr.dc3\"",mName.c_str());

	}
	void getDefSingle()
	{
		fprintf(mFile,"\"%s.def.dsi\"",mName.c_str());

	}
	void getOutput()
	{
		fprintf(mFile,"\"%s.out\"",mName.c_str());

	}
	void getOutTriple()
	{
		fprintf(mFile,"\"%s.out.otr\"",mName.c_str());

	}
	void getOutComp1()
	{
		fprintf(mFile,"\"%s.out.otr.oc1\"",mName.c_str());

	}
	void getOutComp2()
	{
		fprintf(mFile,"\"%s.out.otr.oc2\"",mName.c_str());

	}
	void getOutComp3()
	{
		fprintf(mFile,"\"%s.out.otr.oc3\"",mName.c_str());

	}
	void getOutSingle()
	{
		fprintf(mFile,"\"%s.out.osi\"",mName.c_str());

	}
protected:
	QuadShadingSwitch(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BaseShadingSwitch(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_QUADSHADINGSWITCH_H__
