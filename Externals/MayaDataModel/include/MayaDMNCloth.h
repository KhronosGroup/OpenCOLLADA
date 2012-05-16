/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NCLOTH_H__
#define __MayaDM_NCLOTH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMNParticle.h"
namespace MayaDM
{
class NCloth : public NParticle
{
public:
public:

	NCloth():NParticle(){}
	NCloth(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:NParticle(file, name, parent, "nCloth", shared, create){}
	virtual ~NCloth(){}

	void setNumSubdivisions(int nsub)
	{
		if(nsub == 2) return;
		fprintf(mFile,"\tsetAttr \".nsub\" %i;\n", nsub);
	}
	void setScalingRelation(unsigned int srl)
	{
		if(srl == 0) return;
		fprintf(mFile,"\tsetAttr \".srl\" %i;\n", srl);
	}
	void setStretchResistance(float stch)
	{
		if(stch == 20.0) return;
		fprintf(mFile,"\tsetAttr \".stch\" %f;\n", stch);
	}
	void setCompressionResistance(float comr)
	{
		if(comr == 10.0) return;
		fprintf(mFile,"\tsetAttr \".comr\" %f;\n", comr);
	}
	void setStretchMap(float stmp)
	{
		if(stmp == 1.0) return;
		fprintf(mFile,"\tsetAttr \".stmp\" %f;\n", stmp);
	}
	void setStretchPerVertex(const doubleArray& spv)
	{
		if(spv.size == 0) return;
		fprintf(mFile,"\tsetAttr \".spv\" -type \"doubleArray\" ");
		spv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBendResistance(float bnd)
	{
		if(bnd == 0.1) return;
		fprintf(mFile,"\tsetAttr \".bnd\" %f;\n", bnd);
	}
	void setBendMap(float bemp)
	{
		if(bemp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bemp\" %f;\n", bemp);
	}
	void setBendPerVertex(const doubleArray& bdpv)
	{
		if(bdpv.size == 0) return;
		fprintf(mFile,"\tsetAttr \".bdpv\" -type \"doubleArray\" ");
		bdpv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBendAngleDropoff(float bnad)
	{
		if(bnad == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bnad\" %f;\n", bnad);
	}
	void setRestitutionTension(float retn)
	{
		if(retn == 1000.0) return;
		fprintf(mFile,"\tsetAttr \".retn\" %f;\n", retn);
	}
	void setRestitutionAngle(float reae)
	{
		if(reae == 3) return;
		fprintf(mFile,"\tsetAttr \".reae\" %f;\n", reae);
	}
	void setShearResistance(float shr)
	{
		if(shr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".shr\" %f;\n", shr);
	}
	void setRigidity(float rity)
	{
		if(rity == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rity\" %f;\n", rity);
	}
	void setRigidityMap(float rimp)
	{
		if(rimp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rimp\" %f;\n", rimp);
	}
	void setRigidityPerVertex(const doubleArray& rpv)
	{
		if(rpv.size == 0) return;
		fprintf(mFile,"\tsetAttr \".rpv\" -type \"doubleArray\" ");
		rpv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDeformResistance(float dety)
	{
		if(dety == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dety\" %f;\n", dety);
	}
	void setDeformMap(float demp)
	{
		if(demp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".demp\" %f;\n", demp);
	}
	void setDeformPerVertex(const doubleArray& dfpv)
	{
		if(dfpv.size == 0) return;
		fprintf(mFile,"\tsetAttr \".dfpv\" -type \"doubleArray\" ");
		dfpv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputMeshAttract(float imat)
	{
		if(imat == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imat\" %f;\n", imat);
	}
	void setInputAttractMap(float iamp)
	{
		if(iamp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".iamp\" %f;\n", iamp);
	}
	void setInputAttractPerVertex(const doubleArray& iapv)
	{
		if(iapv.size == 0) return;
		fprintf(mFile,"\tsetAttr \".iapv\" -type \"doubleArray\" ");
		iapv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputAttractDamp(float iadm)
	{
		if(iadm == 0.5) return;
		fprintf(mFile,"\tsetAttr \".iadm\" %f;\n", iadm);
	}
	void setWrinkleMap(float wkmp)
	{
		if(wkmp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wkmp\" %f;\n", wkmp);
	}
	void setWrinklePerVertex(const doubleArray& wpv)
	{
		if(wpv.size == 0) return;
		fprintf(mFile,"\tsetAttr \".wpv\" -type \"doubleArray\" ");
		wpv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWrinkleMapScale(float wms)
	{
		if(wms == 1.0) return;
		fprintf(mFile,"\tsetAttr \".wms\" %f;\n", wms);
	}
	void setBendAngleScale(float basc)
	{
		if(basc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".basc\" %f;\n", basc);
	}
	void setSortLinks(bool stlk)
	{
		if(stlk == 0) return;
		fprintf(mFile,"\tsetAttr \".stlk\" %i;\n", stlk);
	}
	void setEvaluationOrder(unsigned int evo)
	{
		if(evo == 0) return;
		fprintf(mFile,"\tsetAttr \".evo\" %i;\n", evo);
	}
	void setAddCrossLinks(bool aclk)
	{
		if(aclk == true) return;
		fprintf(mFile,"\tsetAttr \".aclk\" %i;\n", aclk);
	}
	void setStretchDamp(float sdmp)
	{
		if(sdmp == 0.1) return;
		fprintf(mFile,"\tsetAttr \".sdmp\" %f;\n", sdmp);
	}
	void setSelfCollideWidthScale(float scws)
	{
		if(scws == 1.0) return;
		fprintf(mFile,"\tsetAttr \".scws\" %f;\n", scws);
	}
	void setSelfCollisionSoftness(float scsf)
	{
		if(scsf == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scsf\" %f;\n", scsf);
	}
	void setSelfCrossoverPush(float scpu)
	{
		if(scpu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scpu\" %f;\n", scpu);
	}
	void setSelfTrappedCheck(bool stpc)
	{
		if(stpc == 0) return;
		fprintf(mFile,"\tsetAttr \".stpc\" %i;\n", stpc);
	}
	void setPressureMethod(unsigned int pmth)
	{
		if(pmth == 0) return;
		fprintf(mFile,"\tsetAttr \".pmth\" %i;\n", pmth);
	}
	void setPressure(float pres)
	{
		if(pres == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pres\" %f;\n", pres);
	}
	void setStartPressure(float stpe)
	{
		if(stpe == 0.0) return;
		fprintf(mFile,"\tsetAttr \".stpe\" %f;\n", stpe);
	}
	void setIncompressibility(float incm)
	{
		if(incm == 5.0) return;
		fprintf(mFile,"\tsetAttr \".incm\" %f;\n", incm);
	}
	void setPressureDamping(float prdg)
	{
		if(prdg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".prdg\" %f;\n", prdg);
	}
	void setPumpRate(float pure)
	{
		if(pure == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pure\" %f;\n", pure);
	}
	void setAirTightness(float aits)
	{
		if(aits == 1.0) return;
		fprintf(mFile,"\tsetAttr \".aits\" %f;\n", aits);
	}
	void setSealHoles(bool shol)
	{
		if(shol == true) return;
		fprintf(mFile,"\tsetAttr \".shol\" %i;\n", shol);
	}
	void setIgnoreSolverGravity(bool igsg)
	{
		if(igsg == 0) return;
		fprintf(mFile,"\tsetAttr \".igsg\" %i;\n", igsg);
	}
	void setIgnoreSolverWind(bool igsw)
	{
		if(igsw == 0) return;
		fprintf(mFile,"\tsetAttr \".igsw\" %i;\n", igsw);
	}
	void setWindSelfShadow(bool wssh)
	{
		if(wssh == 0) return;
		fprintf(mFile,"\tsetAttr \".wssh\" %i;\n", wssh);
	}
	void setLift(float lft)
	{
		if(lft == 0.05) return;
		fprintf(mFile,"\tsetAttr \".lft\" %f;\n", lft);
	}
	void setDrag(float drg)
	{
		if(drg == 0.05) return;
		fprintf(mFile,"\tsetAttr \".drg\" %f;\n", drg);
	}
	void setTangentialDrag(float tdrg)
	{
		if(tdrg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tdrg\" %f;\n", tdrg);
	}
	void setSolverDisplay(unsigned int svds)
	{
		if(svds == 0) return;
		fprintf(mFile,"\tsetAttr \".svds\" %i;\n", svds);
	}
	void setStretchMapType(unsigned int smt)
	{
		if(smt == 2) return;
		fprintf(mFile,"\tsetAttr \".smt\" %i;\n", smt);
	}
	void setBendMapType(unsigned int bdmt)
	{
		if(bdmt == 2) return;
		fprintf(mFile,"\tsetAttr \".bdmt\" %i;\n", bdmt);
	}
	void setRigidityMapType(unsigned int rmt)
	{
		if(rmt == 2) return;
		fprintf(mFile,"\tsetAttr \".rmt\" %i;\n", rmt);
	}
	void setDeformMapType(unsigned int dmmt)
	{
		if(dmmt == 2) return;
		fprintf(mFile,"\tsetAttr \".dmmt\" %i;\n", dmmt);
	}
	void setInputAttractMapType(unsigned int iamt)
	{
		if(iamt == 2) return;
		fprintf(mFile,"\tsetAttr \".iamt\" %i;\n", iamt);
	}
	void setWrinkleMapType(unsigned int wmt)
	{
		if(wmt == 2) return;
		fprintf(mFile,"\tsetAttr \".wmt\" %i;\n", wmt);
	}
	void getOutputMesh()const
	{
		fprintf(mFile,"\"%s.omsh\"",mName.c_str());
	}
	void getRestShapeMesh()const
	{
		fprintf(mFile,"\"%s.rsmh\"",mName.c_str());
	}
	void getNumSubdivisions()const
	{
		fprintf(mFile,"\"%s.nsub\"",mName.c_str());
	}
	void getScalingRelation()const
	{
		fprintf(mFile,"\"%s.srl\"",mName.c_str());
	}
	void getStretchResistance()const
	{
		fprintf(mFile,"\"%s.stch\"",mName.c_str());
	}
	void getCompressionResistance()const
	{
		fprintf(mFile,"\"%s.comr\"",mName.c_str());
	}
	void getStretchMap()const
	{
		fprintf(mFile,"\"%s.stmp\"",mName.c_str());
	}
	void getStretchPerVertex()const
	{
		fprintf(mFile,"\"%s.spv\"",mName.c_str());
	}
	void getBendResistance()const
	{
		fprintf(mFile,"\"%s.bnd\"",mName.c_str());
	}
	void getBendMap()const
	{
		fprintf(mFile,"\"%s.bemp\"",mName.c_str());
	}
	void getBendPerVertex()const
	{
		fprintf(mFile,"\"%s.bdpv\"",mName.c_str());
	}
	void getBendAngleDropoff()const
	{
		fprintf(mFile,"\"%s.bnad\"",mName.c_str());
	}
	void getRestitutionTension()const
	{
		fprintf(mFile,"\"%s.retn\"",mName.c_str());
	}
	void getRestitutionAngle()const
	{
		fprintf(mFile,"\"%s.reae\"",mName.c_str());
	}
	void getShearResistance()const
	{
		fprintf(mFile,"\"%s.shr\"",mName.c_str());
	}
	void getRigidity()const
	{
		fprintf(mFile,"\"%s.rity\"",mName.c_str());
	}
	void getRigidityMap()const
	{
		fprintf(mFile,"\"%s.rimp\"",mName.c_str());
	}
	void getRigidityPerVertex()const
	{
		fprintf(mFile,"\"%s.rpv\"",mName.c_str());
	}
	void getDeformResistance()const
	{
		fprintf(mFile,"\"%s.dety\"",mName.c_str());
	}
	void getDeformMap()const
	{
		fprintf(mFile,"\"%s.demp\"",mName.c_str());
	}
	void getDeformPerVertex()const
	{
		fprintf(mFile,"\"%s.dfpv\"",mName.c_str());
	}
	void getInputMeshAttract()const
	{
		fprintf(mFile,"\"%s.imat\"",mName.c_str());
	}
	void getInputAttractMap()const
	{
		fprintf(mFile,"\"%s.iamp\"",mName.c_str());
	}
	void getInputAttractPerVertex()const
	{
		fprintf(mFile,"\"%s.iapv\"",mName.c_str());
	}
	void getInputAttractDamp()const
	{
		fprintf(mFile,"\"%s.iadm\"",mName.c_str());
	}
	void getWrinkleMap()const
	{
		fprintf(mFile,"\"%s.wkmp\"",mName.c_str());
	}
	void getWrinklePerVertex()const
	{
		fprintf(mFile,"\"%s.wpv\"",mName.c_str());
	}
	void getWrinkleMapScale()const
	{
		fprintf(mFile,"\"%s.wms\"",mName.c_str());
	}
	void getBendAngleScale()const
	{
		fprintf(mFile,"\"%s.basc\"",mName.c_str());
	}
	void getSortLinks()const
	{
		fprintf(mFile,"\"%s.stlk\"",mName.c_str());
	}
	void getEvaluationOrder()const
	{
		fprintf(mFile,"\"%s.evo\"",mName.c_str());
	}
	void getAddCrossLinks()const
	{
		fprintf(mFile,"\"%s.aclk\"",mName.c_str());
	}
	void getStretchDamp()const
	{
		fprintf(mFile,"\"%s.sdmp\"",mName.c_str());
	}
	void getMinimalStretch()const
	{
		fprintf(mFile,"\"%s.msso\"",mName.c_str());
	}
	void getMinimalBend()const
	{
		fprintf(mFile,"\"%s.mbso\"",mName.c_str());
	}
	void getMinimalShear()const
	{
		fprintf(mFile,"\"%s.mshs\"",mName.c_str());
	}
	void getStretchHierarchyLevels()const
	{
		fprintf(mFile,"\"%s.shlv\"",mName.c_str());
	}
	void getStretchHierarchyPercent()const
	{
		fprintf(mFile,"\"%s.shpe\"",mName.c_str());
	}
	void getSelfCollideWidthScale()const
	{
		fprintf(mFile,"\"%s.scws\"",mName.c_str());
	}
	void getSelfCollisionSoftness()const
	{
		fprintf(mFile,"\"%s.scsf\"",mName.c_str());
	}
	void getSelfCrossoverPush()const
	{
		fprintf(mFile,"\"%s.scpu\"",mName.c_str());
	}
	void getSelfTrappedCheck()const
	{
		fprintf(mFile,"\"%s.stpc\"",mName.c_str());
	}
	void getPressureMethod()const
	{
		fprintf(mFile,"\"%s.pmth\"",mName.c_str());
	}
	void getPressure()const
	{
		fprintf(mFile,"\"%s.pres\"",mName.c_str());
	}
	void getStartPressure()const
	{
		fprintf(mFile,"\"%s.stpe\"",mName.c_str());
	}
	void getIncompressibility()const
	{
		fprintf(mFile,"\"%s.incm\"",mName.c_str());
	}
	void getPressureDamping()const
	{
		fprintf(mFile,"\"%s.prdg\"",mName.c_str());
	}
	void getPumpRate()const
	{
		fprintf(mFile,"\"%s.pure\"",mName.c_str());
	}
	void getAirTightness()const
	{
		fprintf(mFile,"\"%s.aits\"",mName.c_str());
	}
	void getSealHoles()const
	{
		fprintf(mFile,"\"%s.shol\"",mName.c_str());
	}
	void getIgnoreSolverGravity()const
	{
		fprintf(mFile,"\"%s.igsg\"",mName.c_str());
	}
	void getIgnoreSolverWind()const
	{
		fprintf(mFile,"\"%s.igsw\"",mName.c_str());
	}
	void getWindSelfShadow()const
	{
		fprintf(mFile,"\"%s.wssh\"",mName.c_str());
	}
	void getLift()const
	{
		fprintf(mFile,"\"%s.lft\"",mName.c_str());
	}
	void getDrag()const
	{
		fprintf(mFile,"\"%s.drg\"",mName.c_str());
	}
	void getTangentialDrag()const
	{
		fprintf(mFile,"\"%s.tdrg\"",mName.c_str());
	}
	void getSolverDisplay()const
	{
		fprintf(mFile,"\"%s.svds\"",mName.c_str());
	}
	void getStretchMapType()const
	{
		fprintf(mFile,"\"%s.smt\"",mName.c_str());
	}
	void getBendMapType()const
	{
		fprintf(mFile,"\"%s.bdmt\"",mName.c_str());
	}
	void getRigidityMapType()const
	{
		fprintf(mFile,"\"%s.rmt\"",mName.c_str());
	}
	void getDeformMapType()const
	{
		fprintf(mFile,"\"%s.dmmt\"",mName.c_str());
	}
	void getInputAttractMapType()const
	{
		fprintf(mFile,"\"%s.iamt\"",mName.c_str());
	}
	void getWrinkleMapType()const
	{
		fprintf(mFile,"\"%s.wmt\"",mName.c_str());
	}
protected:
	NCloth(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:NParticle(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_NCLOTH_H__
