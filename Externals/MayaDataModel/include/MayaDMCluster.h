/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLUSTER_H__
#define __MayaDM_CLUSTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMWeightGeometryFilter.h"
namespace MayaDM
{
/*
<p><pre>
 Description:

  The cluster node deforms one or more geometries by transforming them
  by some percentage of the transformation of another object in the scene.
  The default percentage is one, so the default cluster will rigidly
  deform the geometries.

  A different percentage can be associated with each CV in the deformed
  object.

  The accuracy of the deformation is controlled by the percentResolution
  attribute.

  The envelope attribute can be used to globally attenuate the amount of deformation.

</pre></p>
*/
class Cluster : public WeightGeometryFilter
{
public:
	/*the bundled cluster transforms*/
	struct ClusterXforms{
		void write(FILE* file) const
		{
		}
	};
public:
	Cluster(FILE* file,const std::string& name,const std::string& parent=""):WeightGeometryFilter(file, name, parent, "cluster"){}
	virtual ~Cluster(){}
	/*resolution by which cluster percents can differ without being lumped together as a single percentage for efficiency*/
	void setPercentResolution(float ptr){if(ptr == 5) return; fprintf_s(mFile, "setAttr \".ptr\" %f;\n", ptr);}
	/*whether or not to use the partial resolution*/
	void setUsePartialResolution(unsigned int upr){if(upr == 0) return; fprintf_s(mFile, "setAttr \".upr\" %i;\n", upr);}
	/*whether or not to use the partial resolution*/
	void setUsePartialResolution(const UnsignedintID& upr){fprintf_s(mFile,"connectAttr \"");upr.write(mFile);fprintf_s(mFile,"\" \"%s.upr\";\n",mName.c_str());}
	/*relative => only use weighted node i.e. no pre, post matrix*/
	void setRelative(bool rel){if(rel == false) return; fprintf_s(mFile, "setAttr \".rel\" %i;\n", rel);}
	/*relative => only use weighted node i.e. no pre, post matrix*/
	void setRelative(const BoolID& rel){fprintf_s(mFile,"connectAttr \"");rel.write(mFile);fprintf_s(mFile,"\" \"%s.rel\";\n",mName.c_str());}
	/*the bundled cluster transforms*/
	void setClusterXforms(const ClusterXformsID& x){fprintf_s(mFile,"connectAttr \"");x.write(mFile);fprintf_s(mFile,"\" \"%s.x\";\n",mName.c_str());}
	/*Represents the transformation in the DAG above the weighted node.*/
	void setPreMatrix(const MatrixID& pre){fprintf_s(mFile,"connectAttr \"");pre.write(mFile);fprintf_s(mFile,"\" \"%s.x.pre\";\n",mName.c_str());}
	/*cluster weighted matrix*/
	void setWeightedMatrix(const MatrixID& wt){fprintf_s(mFile,"connectAttr \"");wt.write(mFile);fprintf_s(mFile,"\" \"%s.x.wt\";\n",mName.c_str());}
	/*Represents the transformation in the DAG below the weighted node.*/
	void setPostMatrix(const MatrixID& post){fprintf_s(mFile,"connectAttr \"");post.write(mFile);fprintf_s(mFile,"\" \"%s.x.post\";\n",mName.c_str());}
	/*cluster weighted matrix compensation*/
	void setWeightedCompensationMatrix(const matrix& wcm){if(wcm == identity) return; fprintf_s(mFile, "setAttr \".wcm\" -type \"matrix\" ");wcm.write(mFile);fprintf_s(mFile,";\n");}
	/*cluster weighted matrix compensation*/
	void setWeightedCompensationMatrix(const MatrixID& wcm){fprintf_s(mFile,"connectAttr \"");wcm.write(mFile);fprintf_s(mFile,"\" \"%s.wcm\";\n",mName.c_str());}
	/*Matrix to set account for the geom matrix at cluster creation time.*/
	void setGeomMatrix(size_t gm_i,const matrix& gm){if(gm == identity) return; fprintf_s(mFile, "setAttr \".gm[%i]\" -type \"matrix\" ",gm_i);gm.write(mFile);fprintf_s(mFile,";\n");}
	/*Matrix to set account for the geom matrix at cluster creation time.*/
	void setGeomMatrix(size_t gm_i,const MatrixID& gm){fprintf_s(mFile,"connectAttr \"");gm.write(mFile);fprintf_s(mFile,"\" \"%s.gm[%i]\";\n",mName.c_str(),gm_i);}
	/*transform that we will rigidly deform by when all percentages are at one*/
	void setMatrix(const matrix& ma){if(ma == identity) return; fprintf_s(mFile, "setAttr \".ma\" -type \"matrix\" ");ma.write(mFile);fprintf_s(mFile,";\n");}
	/*transform that we will rigidly deform by when all percentages are at one*/
	void setMatrix(const MatrixID& ma){fprintf_s(mFile,"connectAttr \"");ma.write(mFile);fprintf_s(mFile,"\" \"%s.ma\";\n",mName.c_str());}
	/*compensation matrix used when we rigidly deform the geometry*/
	void setBindPreMatrix(const matrix& pm){if(pm == identity) return; fprintf_s(mFile, "setAttr \".pm\" -type \"matrix\" ");pm.write(mFile);fprintf_s(mFile,";\n");}
	/*compensation matrix used when we rigidly deform the geometry*/
	void setBindPreMatrix(const MatrixID& pm){fprintf_s(mFile,"connectAttr \"");pm.write(mFile);fprintf_s(mFile,"\" \"%s.pm\";\n",mName.c_str());}
	/*not used*/
	void setBindState(const BoolID& bs){fprintf_s(mFile,"connectAttr \"");bs.write(mFile);fprintf_s(mFile,"\" \"%s.bs\";\n",mName.c_str());}
	/*WorldSpace matrix below cluster weighted matrix compensation*/
	void setPostCompensationMatrix(const MatrixID& psc){fprintf_s(mFile,"connectAttr \"");psc.write(mFile);fprintf_s(mFile,"\" \"%s.psc\";\n",mName.c_str());}
	/*WorldSpace matrix above cluster weighted matrix comp (-bs)*/
	void setPreCompensationMatrix(const MatrixID& prc){fprintf_s(mFile,"connectAttr \"");prc.write(mFile);fprintf_s(mFile,"\" \"%s.prc\";\n",mName.c_str());}
	/*
	The direction of angle interpolation.  In most cases
	0 (Closest) will work the best.  However, if components
	appear to be rotating in the wrong direction, a value
	of 1 (Positive) or 2 (Negative) may be needed.
	*/
	void setAngleInterpolation(unsigned int ait){if(ait == 0) return; fprintf_s(mFile, "setAttr \".ait\" %i;\n", ait);}
	/*
	The direction of angle interpolation.  In most cases
	0 (Closest) will work the best.  However, if components
	appear to be rotating in the wrong direction, a value
	of 1 (Positive) or 2 (Negative) may be needed.
	*/
	void setAngleInterpolation(const UnsignedintID& ait){fprintf_s(mFile,"connectAttr \"");ait.write(mFile);fprintf_s(mFile,"\" \"%s.ait\";\n",mName.c_str());}
	/*whether or not to use the partial resolution*/
	UnsignedintID getUsePartialResolution(){char buffer[4096];sprintf_s (buffer, "%s.upr",mName.c_str());return (const char*)buffer;}
	/*relative => only use weighted node i.e. no pre, post matrix*/
	BoolID getRelative(){char buffer[4096];sprintf_s (buffer, "%s.rel",mName.c_str());return (const char*)buffer;}
	/*the bundled cluster transforms*/
	ClusterXformsID getClusterXforms(){char buffer[4096];sprintf_s (buffer, "%s.x",mName.c_str());return (const char*)buffer;}
	/*Represents the transformation in the DAG above the weighted node.*/
	MatrixID getPreMatrix(){char buffer[4096];sprintf_s (buffer, "%s.x.pre",mName.c_str());return (const char*)buffer;}
	/*cluster weighted matrix*/
	MatrixID getWeightedMatrix(){char buffer[4096];sprintf_s (buffer, "%s.x.wt",mName.c_str());return (const char*)buffer;}
	/*Represents the transformation in the DAG below the weighted node.*/
	MatrixID getPostMatrix(){char buffer[4096];sprintf_s (buffer, "%s.x.post",mName.c_str());return (const char*)buffer;}
	/*cluster weighted matrix compensation*/
	MatrixID getWeightedCompensationMatrix(){char buffer[4096];sprintf_s (buffer, "%s.wcm",mName.c_str());return (const char*)buffer;}
	/*Matrix to set account for the geom matrix at cluster creation time.*/
	const MatrixID& getGeomMatrix(size_t gm_i){char buffer[4096];sprintf_s (buffer, "%s.gm[%i]",mName.c_str(),gm_i);return (const char*)buffer;}
	/*transform that we will rigidly deform by when all percentages are at one*/
	MatrixID getMatrix(){char buffer[4096];sprintf_s (buffer, "%s.ma",mName.c_str());return (const char*)buffer;}
	/*compensation matrix used when we rigidly deform the geometry*/
	MatrixID getBindPreMatrix(){char buffer[4096];sprintf_s (buffer, "%s.pm",mName.c_str());return (const char*)buffer;}
	/*not used*/
	BoolID getBindState(){char buffer[4096];sprintf_s (buffer, "%s.bs",mName.c_str());return (const char*)buffer;}
	/*WorldSpace matrix below cluster weighted matrix compensation*/
	MatrixID getPostCompensationMatrix(){char buffer[4096];sprintf_s (buffer, "%s.psc",mName.c_str());return (const char*)buffer;}
	/*WorldSpace matrix above cluster weighted matrix comp (-bs)*/
	MatrixID getPreCompensationMatrix(){char buffer[4096];sprintf_s (buffer, "%s.prc",mName.c_str());return (const char*)buffer;}
	/*
	The direction of angle interpolation.  In most cases
	0 (Closest) will work the best.  However, if components
	appear to be rotating in the wrong direction, a value
	of 1 (Positive) or 2 (Negative) may be needed.
	*/
	UnsignedintID getAngleInterpolation(){char buffer[4096];sprintf_s (buffer, "%s.ait",mName.c_str());return (const char*)buffer;}
protected:
	Cluster(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):WeightGeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CLUSTER_H__
