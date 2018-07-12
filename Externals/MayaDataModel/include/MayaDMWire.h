/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	Wire():WeightGeometryFilter(){}
	Wire(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:WeightGeometryFilter(file, name, parent, "wire", shared, create){}
	virtual ~Wire(){}

	void setCrossingEffect(float ce)
	{
		if(ce == 0) return;
		fprintf(mFile,"\tsetAttr \".ce\" %f;\n", ce);
	}
	void setTension(float te)
	{
		if(te == 1) return;
		fprintf(mFile,"\tsetAttr \".te\" %f;\n", te);
	}
	void setLocalInfluence(float li)
	{
		if(li == 0) return;
		fprintf(mFile,"\tsetAttr \".li\" %f;\n", li);
	}
	void setRotation(float ro)
	{
		if(ro == 1) return;
		fprintf(mFile,"\tsetAttr \".ro\" %f;\n", ro);
	}
	void setFreezeGeometry(bool fg)
	{
		if(fg == 0) return;
		fprintf(mFile,"\tsetAttr \".fg\" %i;\n", fg);
	}
	void setDropoffDistance(size_t dds_i,float dds)
	{
		if(dds == 1) return;
		fprintf(mFile,"\tsetAttr \".dds[%i]\" %f;\n", dds_i,dds);
	}
	void setDropoffDistance(size_t dds_start,size_t dds_end,float* dds)
	{
		fprintf(mFile,"\tsetAttr \".dds[%i:%i]\" ", dds_start,dds_end);
		size_t size = (dds_end-dds_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",dds[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startDropoffDistance(size_t dds_start,size_t dds_end)const
	{
		fprintf(mFile,"\tsetAttr \".dds[%i:%i]\"",dds_start,dds_end);
	}
	void appendDropoffDistance(float dds)const
	{
		fprintf(mFile," %f",dds);
	}
	void endDropoffDistance()const
	{
		fprintf(mFile,";\n");
	}
	void setScale(size_t sc_i,float sc)
	{
		if(sc == 1) return;
		fprintf(mFile,"\tsetAttr \".sc[%i]\" %f;\n", sc_i,sc);
	}
	void setScale(size_t sc_start,size_t sc_end,float* sc)
	{
		fprintf(mFile,"\tsetAttr \".sc[%i:%i]\" ", sc_start,sc_end);
		size_t size = (sc_end-sc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",sc[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startScale(size_t sc_start,size_t sc_end)const
	{
		fprintf(mFile,"\tsetAttr \".sc[%i:%i]\"",sc_start,sc_end);
	}
	void appendScale(float sc)const
	{
		fprintf(mFile," %f",sc);
	}
	void endScale()const
	{
		fprintf(mFile,";\n");
	}
	void setWireLocatorPercentage(size_t wlpc_i,float wlpc)
	{
		if(wlpc == 1) return;
		fprintf(mFile,"\tsetAttr \".wlpc[%i]\" %f;\n", wlpc_i,wlpc);
	}
	void setWireLocatorPercentage(size_t wlpc_start,size_t wlpc_end,float* wlpc)
	{
		fprintf(mFile,"\tsetAttr \".wlpc[%i:%i]\" ", wlpc_start,wlpc_end);
		size_t size = (wlpc_end-wlpc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",wlpc[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startWireLocatorPercentage(size_t wlpc_start,size_t wlpc_end)const
	{
		fprintf(mFile,"\tsetAttr \".wlpc[%i:%i]\"",wlpc_start,wlpc_end);
	}
	void appendWireLocatorPercentage(float wlpc)const
	{
		fprintf(mFile," %f",wlpc);
	}
	void endWireLocatorPercentage()const
	{
		fprintf(mFile,";\n");
	}
	void setWireLocatorParameter(size_t wlp_i,float wlp)
	{
		if(wlp == 0) return;
		fprintf(mFile,"\tsetAttr \".wlp[%i]\" %f;\n", wlp_i,wlp);
	}
	void setWireLocatorParameter(size_t wlp_start,size_t wlp_end,float* wlp)
	{
		fprintf(mFile,"\tsetAttr \".wlp[%i:%i]\" ", wlp_start,wlp_end);
		size_t size = (wlp_end-wlp_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",wlp[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startWireLocatorParameter(size_t wlp_start,size_t wlp_end)const
	{
		fprintf(mFile,"\tsetAttr \".wlp[%i:%i]\"",wlp_start,wlp_end);
	}
	void appendWireLocatorParameter(float wlp)const
	{
		fprintf(mFile," %f",wlp);
	}
	void endWireLocatorParameter()const
	{
		fprintf(mFile,";\n");
	}
	void setWireLocatorEnvelope(size_t wle_i,float wle)
	{
		if(wle == 1) return;
		fprintf(mFile,"\tsetAttr \".wle[%i]\" %f;\n", wle_i,wle);
	}
	void setWireLocatorEnvelope(size_t wle_start,size_t wle_end,float* wle)
	{
		fprintf(mFile,"\tsetAttr \".wle[%i:%i]\" ", wle_start,wle_end);
		size_t size = (wle_end-wle_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",wle[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startWireLocatorEnvelope(size_t wle_start,size_t wle_end)const
	{
		fprintf(mFile,"\tsetAttr \".wle[%i:%i]\"",wle_start,wle_end);
	}
	void appendWireLocatorEnvelope(float wle)const
	{
		fprintf(mFile," %f",wle);
	}
	void endWireLocatorEnvelope()const
	{
		fprintf(mFile,";\n");
	}
	void setWireLocatorTwist(size_t wlt_i,float wlt)
	{
		if(wlt == 0) return;
		fprintf(mFile,"\tsetAttr \".wlt[%i]\" %f;\n", wlt_i,wlt);
	}
	void setWireLocatorTwist(size_t wlt_start,size_t wlt_end,float* wlt)
	{
		fprintf(mFile,"\tsetAttr \".wlt[%i:%i]\" ", wlt_start,wlt_end);
		size_t size = (wlt_end-wlt_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",wlt[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startWireLocatorTwist(size_t wlt_start,size_t wlt_end)const
	{
		fprintf(mFile,"\tsetAttr \".wlt[%i:%i]\"",wlt_start,wlt_end);
	}
	void appendWireLocatorTwist(float wlt)const
	{
		fprintf(mFile," %f",wlt);
	}
	void endWireLocatorTwist()const
	{
		fprintf(mFile,";\n");
	}
	void setDeformedWire(size_t dw_i,const nurbsCurve& dw)
	{
		fprintf(mFile,"\tsetAttr \".dw[%i]\" -type \"nurbsCurve\" ",dw_i);
		dw.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDeformedWire(size_t dw_start,size_t dw_end,nurbsCurve* dw)
	{
		fprintf(mFile,"\tsetAttr \".dw[%i:%i]\" ", dw_start,dw_end);
		size_t size = (dw_end-dw_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			dw[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startDeformedWire(size_t dw_start,size_t dw_end)const
	{
		fprintf(mFile,"\tsetAttr \".dw[%i:%i]\"",dw_start,dw_end);
		fprintf(mFile," -type \"nurbsCurve\" ");
	}
	void appendDeformedWire(const nurbsCurve& dw)const
	{
		fprintf(mFile," ");
		dw.write(mFile);
	}
	void endDeformedWire()const
	{
		fprintf(mFile,";\n");
	}
	void setBaseWire(size_t bw_i,const nurbsCurve& bw)
	{
		fprintf(mFile,"\tsetAttr \".bw[%i]\" -type \"nurbsCurve\" ",bw_i);
		bw.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBaseWire(size_t bw_start,size_t bw_end,nurbsCurve* bw)
	{
		fprintf(mFile,"\tsetAttr \".bw[%i:%i]\" ", bw_start,bw_end);
		size_t size = (bw_end-bw_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			bw[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startBaseWire(size_t bw_start,size_t bw_end)const
	{
		fprintf(mFile,"\tsetAttr \".bw[%i:%i]\"",bw_start,bw_end);
		fprintf(mFile," -type \"nurbsCurve\" ");
	}
	void appendBaseWire(const nurbsCurve& bw)const
	{
		fprintf(mFile," ");
		bw.write(mFile);
	}
	void endBaseWire()const
	{
		fprintf(mFile,";\n");
	}
	void getCrossingEffect()const
	{
		fprintf(mFile,"\"%s.ce\"",mName.c_str());
	}
	void getTension()const
	{
		fprintf(mFile,"\"%s.te\"",mName.c_str());
	}
	void getLocalInfluence()const
	{
		fprintf(mFile,"\"%s.li\"",mName.c_str());
	}
	void getRotation()const
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());
	}
	void getFreezeGeometry()const
	{
		fprintf(mFile,"\"%s.fg\"",mName.c_str());
	}
	void getDropoffDistance(size_t dds_i)const
	{
		fprintf(mFile,"\"%s.dds[%i]\"",mName.c_str(),dds_i);
	}
	void getDropoffDistance()const
	{

		fprintf(mFile,"\"%s.dds\"",mName.c_str());
	}
	void getScale(size_t sc_i)const
	{
		fprintf(mFile,"\"%s.sc[%i]\"",mName.c_str(),sc_i);
	}
	void getScale()const
	{

		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getWireLocatorPercentage(size_t wlpc_i)const
	{
		fprintf(mFile,"\"%s.wlpc[%i]\"",mName.c_str(),wlpc_i);
	}
	void getWireLocatorPercentage()const
	{

		fprintf(mFile,"\"%s.wlpc\"",mName.c_str());
	}
	void getWireLocatorParameter(size_t wlp_i)const
	{
		fprintf(mFile,"\"%s.wlp[%i]\"",mName.c_str(),wlp_i);
	}
	void getWireLocatorParameter()const
	{

		fprintf(mFile,"\"%s.wlp\"",mName.c_str());
	}
	void getWireLocatorEnvelope(size_t wle_i)const
	{
		fprintf(mFile,"\"%s.wle[%i]\"",mName.c_str(),wle_i);
	}
	void getWireLocatorEnvelope()const
	{

		fprintf(mFile,"\"%s.wle\"",mName.c_str());
	}
	void getWireLocatorTwist(size_t wlt_i)const
	{
		fprintf(mFile,"\"%s.wlt[%i]\"",mName.c_str(),wlt_i);
	}
	void getWireLocatorTwist()const
	{

		fprintf(mFile,"\"%s.wlt\"",mName.c_str());
	}
	void getDeformedWire(size_t dw_i)const
	{
		fprintf(mFile,"\"%s.dw[%i]\"",mName.c_str(),dw_i);
	}
	void getDeformedWire()const
	{

		fprintf(mFile,"\"%s.dw\"",mName.c_str());
	}
	void getBaseWire(size_t bw_i)const
	{
		fprintf(mFile,"\"%s.bw[%i]\"",mName.c_str(),bw_i);
	}
	void getBaseWire()const
	{

		fprintf(mFile,"\"%s.bw\"",mName.c_str());
	}
	void getHolder(size_t ho_i)const
	{
		fprintf(mFile,"\"%s.ho[%i]\"",mName.c_str(),ho_i);
	}
	void getHolder()const
	{

		fprintf(mFile,"\"%s.ho\"",mName.c_str());
	}
protected:
	Wire(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:WeightGeometryFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_WIRE_H__
