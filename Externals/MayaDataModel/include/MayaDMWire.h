/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_WIRE_H__
#define __MayaDM_WIRE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMWeightGeometryFilter.h"
namespace MayaDM
{
class Wire : public WeightGeometryFilter
{
public:
public:
	Wire(FILE* file,const std::string& name,const std::string& parent=""):WeightGeometryFilter(file, name, parent, "wire"){}
	virtual ~Wire(){}
	void setCrossingEffect(float ce)
	{
		if(ce == 0) return;
		fprintf(mFile,"setAttr \".ce\" %f;\n", ce);

	}
	void setTension(float te)
	{
		if(te == 1) return;
		fprintf(mFile,"setAttr \".te\" %f;\n", te);

	}
	void setLocalInfluence(float li)
	{
		if(li == 0) return;
		fprintf(mFile,"setAttr \".li\" %f;\n", li);

	}
	void setRotation(float ro)
	{
		if(ro == 1) return;
		fprintf(mFile,"setAttr \".ro\" %f;\n", ro);

	}
	void setFreezeGeometry(bool fg)
	{
		if(fg == 0) return;
		fprintf(mFile,"setAttr \".fg\" %i;\n", fg);

	}
	void setDropoffDistance(size_t dds_i,float dds)
	{
		if(dds == 1) return;
		fprintf(mFile,"setAttr \".dds[%i]\" %f;\n", dds_i,dds);

	}
	void setDropoffDistance(size_t dds_start,size_t dds_end,float* dds)
	{
		fprintf(mFile,"setAttr \".dds[%i:%i]\" ", dds_start,dds_end);
		size_t size = (dds_end-dds_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",dds[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startDropoffDistance(size_t dds_start,size_t dds_end)
	{
		fprintf(mFile,"setAttr \".dds[%i:%i]\"",dds_start,dds_end);

	}
	void appendDropoffDistance(float dds)
	{
		fprintf(mFile," %f",dds);

	}
	void endDropoffDistance()
	{
		fprintf(mFile,";\n");

	}
	void setScale(size_t sc_i,float sc)
	{
		if(sc == 1) return;
		fprintf(mFile,"setAttr \".sc[%i]\" %f;\n", sc_i,sc);

	}
	void setScale(size_t sc_start,size_t sc_end,float* sc)
	{
		fprintf(mFile,"setAttr \".sc[%i:%i]\" ", sc_start,sc_end);
		size_t size = (sc_end-sc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",sc[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startScale(size_t sc_start,size_t sc_end)
	{
		fprintf(mFile,"setAttr \".sc[%i:%i]\"",sc_start,sc_end);

	}
	void appendScale(float sc)
	{
		fprintf(mFile," %f",sc);

	}
	void endScale()
	{
		fprintf(mFile,";\n");

	}
	void setWireLocatorPercentage(size_t wlpc_i,float wlpc)
	{
		if(wlpc == 1) return;
		fprintf(mFile,"setAttr \".wlpc[%i]\" %f;\n", wlpc_i,wlpc);

	}
	void setWireLocatorPercentage(size_t wlpc_start,size_t wlpc_end,float* wlpc)
	{
		fprintf(mFile,"setAttr \".wlpc[%i:%i]\" ", wlpc_start,wlpc_end);
		size_t size = (wlpc_end-wlpc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",wlpc[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startWireLocatorPercentage(size_t wlpc_start,size_t wlpc_end)
	{
		fprintf(mFile,"setAttr \".wlpc[%i:%i]\"",wlpc_start,wlpc_end);

	}
	void appendWireLocatorPercentage(float wlpc)
	{
		fprintf(mFile," %f",wlpc);

	}
	void endWireLocatorPercentage()
	{
		fprintf(mFile,";\n");

	}
	void setWireLocatorParameter(size_t wlp_i,float wlp)
	{
		if(wlp == 0) return;
		fprintf(mFile,"setAttr \".wlp[%i]\" %f;\n", wlp_i,wlp);

	}
	void setWireLocatorParameter(size_t wlp_start,size_t wlp_end,float* wlp)
	{
		fprintf(mFile,"setAttr \".wlp[%i:%i]\" ", wlp_start,wlp_end);
		size_t size = (wlp_end-wlp_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",wlp[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startWireLocatorParameter(size_t wlp_start,size_t wlp_end)
	{
		fprintf(mFile,"setAttr \".wlp[%i:%i]\"",wlp_start,wlp_end);

	}
	void appendWireLocatorParameter(float wlp)
	{
		fprintf(mFile," %f",wlp);

	}
	void endWireLocatorParameter()
	{
		fprintf(mFile,";\n");

	}
	void setWireLocatorEnvelope(size_t wle_i,float wle)
	{
		if(wle == 1) return;
		fprintf(mFile,"setAttr \".wle[%i]\" %f;\n", wle_i,wle);

	}
	void setWireLocatorEnvelope(size_t wle_start,size_t wle_end,float* wle)
	{
		fprintf(mFile,"setAttr \".wle[%i:%i]\" ", wle_start,wle_end);
		size_t size = (wle_end-wle_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",wle[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startWireLocatorEnvelope(size_t wle_start,size_t wle_end)
	{
		fprintf(mFile,"setAttr \".wle[%i:%i]\"",wle_start,wle_end);

	}
	void appendWireLocatorEnvelope(float wle)
	{
		fprintf(mFile," %f",wle);

	}
	void endWireLocatorEnvelope()
	{
		fprintf(mFile,";\n");

	}
	void setWireLocatorTwist(size_t wlt_i,float wlt)
	{
		if(wlt == 0) return;
		fprintf(mFile,"setAttr \".wlt[%i]\" %f;\n", wlt_i,wlt);

	}
	void setWireLocatorTwist(size_t wlt_start,size_t wlt_end,float* wlt)
	{
		fprintf(mFile,"setAttr \".wlt[%i:%i]\" ", wlt_start,wlt_end);
		size_t size = (wlt_end-wlt_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",wlt[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startWireLocatorTwist(size_t wlt_start,size_t wlt_end)
	{
		fprintf(mFile,"setAttr \".wlt[%i:%i]\"",wlt_start,wlt_end);

	}
	void appendWireLocatorTwist(float wlt)
	{
		fprintf(mFile," %f",wlt);

	}
	void endWireLocatorTwist()
	{
		fprintf(mFile,";\n");

	}
	void setDeformedWire(size_t dw_i,const nurbsCurve& dw)
	{
		fprintf(mFile,"setAttr \".dw[%i]\" -type \"nurbsCurve\" ",dw_i);
		dw.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDeformedWire(size_t dw_start,size_t dw_end,nurbsCurve* dw)
	{
		fprintf(mFile,"setAttr \".dw[%i:%i]\" ", dw_start,dw_end);
		size_t size = (dw_end-dw_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			dw[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");

	}
	void startDeformedWire(size_t dw_start,size_t dw_end)
	{
		fprintf(mFile,"setAttr \".dw[%i:%i]\"",dw_start,dw_end);
		fprintf(mFile," -type \"nurbsCurve\" ");

	}
	void appendDeformedWire(const nurbsCurve& dw)
	{
		fprintf(mFile,"\n");
		dw.write(mFile);

	}
	void endDeformedWire()
	{
		fprintf(mFile,";\n");

	}
	void setBaseWire(size_t bw_i,const nurbsCurve& bw)
	{
		fprintf(mFile,"setAttr \".bw[%i]\" -type \"nurbsCurve\" ",bw_i);
		bw.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBaseWire(size_t bw_start,size_t bw_end,nurbsCurve* bw)
	{
		fprintf(mFile,"setAttr \".bw[%i:%i]\" ", bw_start,bw_end);
		size_t size = (bw_end-bw_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			bw[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");

	}
	void startBaseWire(size_t bw_start,size_t bw_end)
	{
		fprintf(mFile,"setAttr \".bw[%i:%i]\"",bw_start,bw_end);
		fprintf(mFile," -type \"nurbsCurve\" ");

	}
	void appendBaseWire(const nurbsCurve& bw)
	{
		fprintf(mFile,"\n");
		bw.write(mFile);

	}
	void endBaseWire()
	{
		fprintf(mFile,";\n");

	}
	void getCrossingEffect()
	{
		fprintf(mFile,"\"%s.ce\"",mName.c_str());

	}
	void getTension()
	{
		fprintf(mFile,"\"%s.te\"",mName.c_str());

	}
	void getLocalInfluence()
	{
		fprintf(mFile,"\"%s.li\"",mName.c_str());

	}
	void getRotation()
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());

	}
	void getFreezeGeometry()
	{
		fprintf(mFile,"\"%s.fg\"",mName.c_str());

	}
	void getDropoffDistance(size_t dds_i)
	{
		fprintf(mFile,"\"%s.dds[%i]\"",mName.c_str(),dds_i);

	}
	void getScale(size_t sc_i)
	{
		fprintf(mFile,"\"%s.sc[%i]\"",mName.c_str(),sc_i);

	}
	void getWireLocatorPercentage(size_t wlpc_i)
	{
		fprintf(mFile,"\"%s.wlpc[%i]\"",mName.c_str(),wlpc_i);

	}
	void getWireLocatorParameter(size_t wlp_i)
	{
		fprintf(mFile,"\"%s.wlp[%i]\"",mName.c_str(),wlp_i);

	}
	void getWireLocatorEnvelope(size_t wle_i)
	{
		fprintf(mFile,"\"%s.wle[%i]\"",mName.c_str(),wle_i);

	}
	void getWireLocatorTwist(size_t wlt_i)
	{
		fprintf(mFile,"\"%s.wlt[%i]\"",mName.c_str(),wlt_i);

	}
	void getDeformedWire(size_t dw_i)
	{
		fprintf(mFile,"\"%s.dw[%i]\"",mName.c_str(),dw_i);

	}
	void getBaseWire(size_t bw_i)
	{
		fprintf(mFile,"\"%s.bw[%i]\"",mName.c_str(),bw_i);

	}
	void getHolder(size_t ho_i)
	{
		fprintf(mFile,"\"%s.ho[%i]\"",mName.c_str(),ho_i);

	}
protected:
	Wire(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):WeightGeometryFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_WIRE_H__
