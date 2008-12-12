/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FLOW_H__
#define __MayaDM_FLOW_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This is the flow node which is an interfacing node among
 a motionPath node and lattice deformation related nodes.<p/>

 The flow node communicates with the motionPath node through
 messages to compute and construct a set of lattice points
 (used by the lattice node, and the ffd node) to deform the
 geometry objects connected to them.<p/>
<pre>

                  (motionPath) --------------
                      |                     |
                      |                     |
                    (flow)             (transform)
                    / |  \                  |
         -----------  |   ---------         |
        /             |            \        |
  (baseLattice)   (lattice)       (ffd) -----

</pre>
 The "flow" command, when executed on an object
 animated by a motion path that has its "follow" enabled,
 creates a flow node and all its necessary connections to
 the other nodes.<p/>

 When the latticeOnObject attribute is set to true,
 the lattice points are positioned around the animated object.
 Otherwise, they are positioned around the path curve.<p/>
*/
class Flow : public DependNode
{
public:
public:
	Flow(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "flow"){}
	virtual ~Flow(){}
	/*A flag for specifying the deformation lattice placement, either lattice around the object or lattice around the whole curve*/
	void setLatticeOnObject(bool lo){if(lo == false) return; fprintf_s(mFile, "setAttr \".lo\" %i;\n", lo);}
	/*For exchanging messages with a motionPath node during computation of the lattice points positions*/
	void setMotionPath(const MessageID& mp){fprintf_s(mFile,"connectAttr \"");mp.write(mFile);fprintf_s(mFile,"\" \"%s.mp\";\n",mName.c_str());}
	/*The current value of the curve parameter to use*/
	void setParmValue(double pv){if(pv == 0) return; fprintf_s(mFile, "setAttr \".pv\" %f;\n", pv);}
	/*The lattice division in the s direction*/
	void setSDivisions(short sdv){if(sdv == 2) return; fprintf_s(mFile, "setAttr \".sdv\" %i;\n", sdv);}
	/*The lattice division in the s direction*/
	void setSDivisions(const ShortID& sdv){fprintf_s(mFile,"connectAttr \"");sdv.write(mFile);fprintf_s(mFile,"\" \"%s.sdv\";\n",mName.c_str());}
	/*The lattice division in the t direction*/
	void setTDivisions(short tdv){if(tdv == 5) return; fprintf_s(mFile, "setAttr \".tdv\" %i;\n", tdv);}
	/*The lattice division in the t direction*/
	void setTDivisions(const ShortID& tdv){fprintf_s(mFile,"connectAttr \"");tdv.write(mFile);fprintf_s(mFile,"\" \"%s.tdv\";\n",mName.c_str());}
	/*The lattice division in the u direction*/
	void setUDivisions(short udv){if(udv == 2) return; fprintf_s(mFile, "setAttr \".udv\" %i;\n", udv);}
	/*The lattice division in the u direction*/
	void setUDivisions(const ShortID& udv){fprintf_s(mFile,"connectAttr \"");udv.write(mFile);fprintf_s(mFile,"\" \"%s.udv\";\n",mName.c_str());}
	/*A transformation matrix specifying the current scaling and orientation of the bounding box of the animated object*/
	void setInBaseMatrix(const matrix& ibm){if(ibm == identity) return; fprintf_s(mFile, "setAttr \".ibm\" -type \"matrix\" ");ibm.write(mFile);fprintf_s(mFile,";\n");}
	/*A matrix to transform the computed lattice point in the world space to the object space of the lattice*/
	void setDefMatrixInv(const matrix& dmi){if(dmi == identity) return; fprintf_s(mFile, "setAttr \".dmi\" -type \"matrix\" ");dmi.write(mFile);fprintf_s(mFile,";\n");}
	/*An index value specifying which local axis of the animated object is used as the front direction in the motionPath animation*/
	void setSetFrontAxis(unsigned int sfa){if(sfa == 1) return; fprintf_s(mFile, "setAttr \".sfa\" %i;\n", sfa);}
	/*An index value specifying which local axis of the animated object is used as the up direction in the motionPath animation*/
	void setSetUpAxis(unsigned int sua){if(sua == 2) return; fprintf_s(mFile, "setAttr \".sua\" %i;\n", sua);}
	/*A matrix specifying the current world space orientations of the animated object*/
	void setOrientMatrix(const matrix& omx){if(omx == identity) return; fprintf_s(mFile, "setAttr \".omx\" -type \"matrix\" ");omx.write(mFile);fprintf_s(mFile,";\n");}
	/*The current world space position of the animated object*/
	void setAllCoords(const double3& ac){if(ac == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ac\" -type \"double3\" ");ac.write(mFile);fprintf_s(mFile,";\n");}
	/*x-component of the current world space position of the animated object*/
	void setXCoord(double xc){if(xc == 0) return; fprintf_s(mFile, "setAttr \".ac.xc\" %f;\n", xc);}
	/*y-component of the current world space position of the animated object*/
	void setYCoord(double yc){if(yc == 0) return; fprintf_s(mFile, "setAttr \".ac.yc\" %f;\n", yc);}
	/*z-component of the current world space position of the animated object*/
	void setZCoord(double zc){if(zc == 0) return; fprintf_s(mFile, "setAttr \".ac.zc\" %f;\n", zc);}
	/*The local space position of the center of the bounding box of the animated object*/
	void setCenter(size_t ctr_i,const double3& ctr){if(ctr == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ctr[%i]\" -type \"double3\" ",ctr_i);ctr.write(mFile);fprintf_s(mFile,";\n");}
	/*The local space position of the center of the bounding box of the animated object*/
	void setCenter(size_t ctr_start,size_t ctr_end,double* ctr){fprintf_s(mFile,"setAttr \".ctr[%i:%i]\" ", ctr_start,ctr_end);size_t size = (ctr_end-ctr_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",ctr[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*x-component of the position of the center of the boundingBox*/
	void setCenterX(size_t ctr_i,double ctx){if(ctx == 0) return; fprintf_s(mFile, "setAttr \".ctr[%i].ctx\" %f;\n", ctr_i,ctx);}
	/*y-component of the position of the center of the boundingBox*/
	void setCenterY(size_t ctr_i,double cty){if(cty == 0) return; fprintf_s(mFile, "setAttr \".ctr[%i].cty\" %f;\n", ctr_i,cty);}
	/*z-component of the position of the center of the boundingBox*/
	void setCenterZ(size_t ctr_i,double ctz){if(ctz == 0) return; fprintf_s(mFile, "setAttr \".ctr[%i].ctz\" %f;\n", ctr_i,ctz);}
	/*A matrix to transform the local space position of the center of the bounding box to its world space position*/
	void setObjectWorldMatrix(size_t owmx_i,const matrix& owmx){if(owmx == identity) return; fprintf_s(mFile, "setAttr \".owmx[%i]\" -type \"matrix\" ",owmx_i);owmx.write(mFile);fprintf_s(mFile,";\n");}
	/*The resulting world space position of the bounding box of the animated object*/
	void setOutBaseMatrix(const MatrixID& obm){fprintf_s(mFile,"connectAttr \"");obm.write(mFile);fprintf_s(mFile,"\" \"%s.obm\";\n",mName.c_str());}
	/*The resulting local space lattice points*/
	void setDefPts(const LatticeID& dpt){fprintf_s(mFile,"connectAttr \"");dpt.write(mFile);fprintf_s(mFile,"\" \"%s.dpt\";\n",mName.c_str());}
	/*For exchanging messages with a motionPath node during computation of the lattice points positions*/
	MessageID getMotionPath(){char buffer[4096];sprintf_s (buffer, "%s.mp",mName.c_str());return (const char*)buffer;}
	/*The lattice division in the s direction*/
	ShortID getSDivisions(){char buffer[4096];sprintf_s (buffer, "%s.sdv",mName.c_str());return (const char*)buffer;}
	/*The lattice division in the t direction*/
	ShortID getTDivisions(){char buffer[4096];sprintf_s (buffer, "%s.tdv",mName.c_str());return (const char*)buffer;}
	/*The lattice division in the u direction*/
	ShortID getUDivisions(){char buffer[4096];sprintf_s (buffer, "%s.udv",mName.c_str());return (const char*)buffer;}
	/*The resulting world space position of the bounding box of the animated object*/
	MatrixID getOutBaseMatrix(){char buffer[4096];sprintf_s (buffer, "%s.obm",mName.c_str());return (const char*)buffer;}
	/*The resulting local space lattice points*/
	LatticeID getDefPts(){char buffer[4096];sprintf_s (buffer, "%s.dpt",mName.c_str());return (const char*)buffer;}
protected:
	Flow(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FLOW_H__
