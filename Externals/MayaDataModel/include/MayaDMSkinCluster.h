/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SKINCLUSTER_H__
#define __MayaDM_SKINCLUSTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
/*
<p><pre>
 Description:

 A skinCluster node allows you to associate a percentage per joint/transform
 for each CV in the geometry. In Maya, this creates the effect known as
 smooth skinning.

 The weights can be queried and edited using the skinPercent command,
 the skin weight painting tool, or the component editor.

</pre></p>
*/
class SkinCluster : public GeometryFilter
{
public:
	/*Bundle of weights for each CV*/
	struct WeightList{
		double* weights;
		void write(FILE* file) const
		{
			size_t size = sizeof(weights)/sizeof(double);
			for(size_t i=0; i<size; ++i)
			{
				fprintf_s(file,"%f", weights[i]);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
public:
	SkinCluster(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "skinCluster"){}
	virtual ~SkinCluster(){}
	/*Bundle of weights for each CV*/
	void setWeightList(size_t wl_i,const WeightList& wl){fprintf_s(mFile, "setAttr \".wl[%i]\" ",wl_i);wl.write(mFile);fprintf_s(mFile,";\n");}
	/*Bundle of weights for each CV*/
	void setWeightList(size_t wl_i,const WeightListID& wl){fprintf_s(mFile,"connectAttr \"");wl.write(mFile);fprintf_s(mFile,"\" \"%s.wl[%i]\";\n",mName.c_str(),wl_i);}
	/*weights for each target*/
	void setWeights(size_t wl_i,size_t w_i,double w){if(w == 0.0) return; fprintf_s(mFile, "setAttr \".wl[%i].w[%i]\" %f;\n", wl_i,w_i,w);}
	/*weights for each target*/
	void setWeights(size_t wl_i,size_t w_i,const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.wl[%i].w[%i]\";\n",mName.c_str(),wl_i,w_i);}
	/*The inclusive matrix inverse of the driving transform at the time of bind*/
	void setBindPreMatrix(size_t pm_i,const matrix& pm){if(pm == identity) return; fprintf_s(mFile, "setAttr \".pm[%i]\" -type \"matrix\" ",pm_i);pm.write(mFile);fprintf_s(mFile,";\n");}
	/*The inclusive matrix inverse of the driving transform at the time of bind*/
	void setBindPreMatrix(size_t pm_i,const MatrixID& pm){fprintf_s(mFile,"connectAttr \"");pm.write(mFile);fprintf_s(mFile,"\" \"%s.pm[%i]\";\n",mName.c_str(),pm_i);}
	/*The inclusive matrix of the geometry path at the time of the bound*/
	void setGeomMatrix(const matrix& gm){if(gm == identity) return; fprintf_s(mFile, "setAttr \".gm\" -type \"matrix\" ");gm.write(mFile);fprintf_s(mFile,";\n");}
	/*The inclusive matrix of the geometry path at the time of the bound*/
	void setGeomMatrix(const MatrixID& gm){fprintf_s(mFile,"connectAttr \"");gm.write(mFile);fprintf_s(mFile,"\" \"%s.gm\";\n",mName.c_str());}
	/*Driving transforms array*/
	void setMatrix(size_t ma_i,const matrix& ma){if(ma == identity) return; fprintf_s(mFile, "setAttr \".ma[%i]\" -type \"matrix\" ",ma_i);ma.write(mFile);fprintf_s(mFile,";\n");}
	/*Driving transforms array*/
	void setMatrix(size_t ma_i,const MatrixID& ma){fprintf_s(mFile,"connectAttr \"");ma.write(mFile);fprintf_s(mFile,"\" \"%s.ma[%i]\";\n",mName.c_str(),ma_i);}
	/*
	Old dropoff rate, kept around temporarily for compatibility
	purposes
	*/
	void setDropoffRate(const DoubleID& dr){fprintf_s(mFile,"connectAttr \"");dr.write(mFile);fprintf_s(mFile,"\" \"%s.dr\";\n",mName.c_str());}
	/*
	Rate of weight value dropoff per influence object
	(1 for linear, 2 for quadratic, etc. )
	*/
	void setDropoff(size_t dpf_i,double dpf){if(dpf == 4.0) return; fprintf_s(mFile, "setAttr \".dpf[%i]\" %f;\n", dpf_i,dpf);}
	/*
	Rate of weight value dropoff per influence object
	(1 for linear, 2 for quadratic, etc. )
	*/
	void setDropoff(size_t dpf_i,const DoubleID& dpf){fprintf_s(mFile,"connectAttr \"");dpf.write(mFile);fprintf_s(mFile,"\" \"%s.dpf[%i]\";\n",mName.c_str(),dpf_i);}
	/*
	Controls how smooth the deformation resulting from the
	a poly mesh influence object will be
	*/
	void setSmoothness(size_t smt_i,double smt){if(smt == 0.0) return; fprintf_s(mFile, "setAttr \".smt[%i]\" %f;\n", smt_i,smt);}
	/*
	Controls how smooth the deformation resulting from the
	a poly mesh influence object will be
	*/
	void setSmoothness(size_t smt_i,const DoubleID& smt){fprintf_s(mFile,"connectAttr \"");smt.write(mFile);fprintf_s(mFile,"\" \"%s.smt[%i]\";\n",mName.c_str(),smt_i);}
	/*
	Indicates whether the weights of the corresponding influence
	are allowed to change
	*/
	void setLockWeights(size_t lw_i,bool lw){if(lw == false) return; fprintf_s(mFile, "setAttr \".lw[%i]\" %i;\n", lw_i,lw);}
	/*
	Indicates whether the weights of the corresponding influence
	are allowed to change
	*/
	void setLockWeights(size_t lw_i,const BoolID& lw){fprintf_s(mFile,"connectAttr \"");lw.write(mFile);fprintf_s(mFile,"\" \"%s.lw[%i]\";\n",mName.c_str(),lw_i);}
	/*
	When true, the skinCluster will not allow a vertex to be weighted
	to more then "maxInfluences" transforms, as defined by the
	maxInfluences attribute.
	<p/>
	When this attribute is switched on, the skinCluster will not immediately
	reassign all of its skin weights. Instead, the skinCluster will begin
	enforcing the max influences as weights are edited. Alternatively, the
	attribute editor "Update Weights" button or the corresponding skinCluster
	command can be used to reassign all of the weights at once.
	<p/>
	Note that locked influences take precedence over max influences. Therefore,
	if more the maximum number of influences are locked and weighted, the
	weights are over-constrained. In this case, the max influences cannot
	be maintained unless you remove some of the locks on the influences.
	*/
	void setMaintainMaxInfluences(bool mmi){if(mmi == false) return; fprintf_s(mFile, "setAttr \".mmi\" %i;\n", mmi);}
	/*
	When true, the skinCluster will not allow a vertex to be weighted
	to more then "maxInfluences" transforms, as defined by the
	maxInfluences attribute.
	<p/>
	When this attribute is switched on, the skinCluster will not immediately
	reassign all of its skin weights. Instead, the skinCluster will begin
	enforcing the max influences as weights are edited. Alternatively, the
	attribute editor "Update Weights" button or the corresponding skinCluster
	command can be used to reassign all of the weights at once.
	<p/>
	Note that locked influences take precedence over max influences. Therefore,
	if more the maximum number of influences are locked and weighted, the
	weights are over-constrained. In this case, the max influences cannot
	be maintained unless you remove some of the locks on the influences.
	*/
	void setMaintainMaxInfluences(const BoolID& mmi){fprintf_s(mFile,"connectAttr \"");mmi.write(mFile);fprintf_s(mFile,"\" \"%s.mmi\";\n",mName.c_str());}
	/*
	When the related attribute 'obeyMaxInfluences' is true, this attribute
	specifies the maximum number of transforms that can influence a point.
	When the related attribute 'obeyMaxInfluences' is false, this attribute
	specifies the number of influences at the time the skin was bound.
	*/
	void setMaxInfluences(int mi){if(mi == 2) return; fprintf_s(mFile, "setAttr \".mi\" %i;\n", mi);}
	/*
	When the related attribute 'obeyMaxInfluences' is true, this attribute
	specifies the maximum number of transforms that can influence a point.
	When the related attribute 'obeyMaxInfluences' is false, this attribute
	specifies the number of influences at the time the skin was bound.
	*/
	void setMaxInfluences(const IntID& mi){fprintf_s(mFile,"connectAttr \"");mi.write(mFile);fprintf_s(mFile,"\" \"%s.mi\";\n",mName.c_str());}
	/*
	Stores the method by which the skinCluster was bound
	where 1 = ClosestDistance, 2 = Closest Joint
	*/
	void setBindMethod(int bm){if(bm == 1) return; fprintf_s(mFile, "setAttr \".bm\" %i;\n", bm);}
	/*
	Stores the method by which the skinCluster was bound
	where 1 = ClosestDistance, 2 = Closest Joint
	*/
	void setBindMethod(const IntID& bm){fprintf_s(mFile,"connectAttr \"");bm.write(mFile);fprintf_s(mFile,"\" \"%s.bm\";\n",mName.c_str());}
	/*The world space coordinates of the driver influence geometry*/
	void setDriverPoints(size_t drp_i,const GeometryID& drp){fprintf_s(mFile,"connectAttr \"");drp.write(mFile);fprintf_s(mFile,"\" \"%s.drp[%i]\";\n",mName.c_str(),drp_i);}
	/*The world space coordinates of the base influence geometry*/
	void setBasePoints(size_t bsp_i,const GeometryID& bsp){fprintf_s(mFile,"connectAttr \"");bsp.write(mFile);fprintf_s(mFile,"\" \"%s.bsp[%i]\";\n",mName.c_str(),bsp_i);}
	/*Set to dirty when the world space coordinates of one of the base influence geometries change*/
	void setBaseDirty(const MessageID& bsd){fprintf_s(mFile,"connectAttr \"");bsd.write(mFile);fprintf_s(mFile,"\" \"%s.bsd\";\n",mName.c_str());}
	/*Temporarily stores the weights for one of the influences*/
	void setPaintWeights(const doubleArray& ptw){if(ptw.size == 0) return; fprintf_s(mFile, "setAttr \".ptw\" -type \"doubleArray\" ");ptw.write(mFile);fprintf_s(mFile,";\n");}
	/*Temporarily stores the weights for one of the influences*/
	void setPaintWeights(const DoubleArrayID& ptw){fprintf_s(mFile,"connectAttr \"");ptw.write(mFile);fprintf_s(mFile,"\" \"%s.ptw\";\n",mName.c_str());}
	/*
	Identifies the influence whose weights are used in the
	paintWeights attribute
	*/
	void setPaintTrans(const MessageID& ptt){fprintf_s(mFile,"connectAttr \"");ptt.write(mFile);fprintf_s(mFile,"\" \"%s.ptt\";\n",mName.c_str());}
	/*Gets marked dirty when the values in paintWeights change*/
	void setPaintArrDirty(const MessageID& pad){fprintf_s(mFile,"connectAttr \"");pad.write(mFile);fprintf_s(mFile,"\" \"%s.pad\";\n",mName.c_str());}
	/*
	If set to true then moving the components of the influence
	objects will affect the skin deformation
	*/
	void setUseComponents(bool uc){if(uc == 0) return; fprintf_s(mFile, "setAttr \".uc\" %i;\n", uc);}
	/*
	If set to true then moving the components of the influence
	objects will affect the skin deformation
	*/
	void setUseComponents(const BoolID& uc){fprintf_s(mFile,"connectAttr \"");uc.write(mFile);fprintf_s(mFile,"\" \"%s.uc\";\n",mName.c_str());}
	/*The number of samples to be taken on influence curves/surfaces*/
	void setNurbsSamples(size_t ns_i,int ns){if(ns == 10) return; fprintf_s(mFile, "setAttr \".ns[%i]\" %i;\n", ns_i,ns);}
	/*The number of samples to be taken on influence curves/surfaces*/
	void setNurbsSamples(size_t ns_i,const IntID& ns){fprintf_s(mFile,"connectAttr \"");ns.write(mFile);fprintf_s(mFile,"\" \"%s.ns[%i]\";\n",mName.c_str(),ns_i);}
	/*
	This attribute is obsolete and is unused in versions past Maya 8.0.
	This attribute is only used when the useComponents attribute is true.
	When this attribute is true, we use the new algorithm for component-type
	influence objects so that the matrix of the influence object is taken
	into account in addition to the tweaks on any influence components.
	This means that the joints and the influence object can be scaled as a group
	without modifying the deformation behavior. This attribute is false by default
	in order to not change any existing scenes.
	*/
	void setUseComponentsMatrix(bool ucm){if(ucm == false) return; fprintf_s(mFile, "setAttr \".ucm\" %i;\n", ucm);}
	/*
	This attribute is obsolete and is unused in versions past Maya 8.0.
	This attribute is only used when the useComponents attribute is true.
	When this attribute is true, we use the new algorithm for component-type
	influence objects so that the matrix of the influence object is taken
	into account in addition to the tweaks on any influence components.
	This means that the joints and the influence object can be scaled as a group
	without modifying the deformation behavior. This attribute is false by default
	in order to not change any existing scenes.
	*/
	void setUseComponentsMatrix(const BoolID& ucm){fprintf_s(mFile,"connectAttr \"");ucm.write(mFile);fprintf_s(mFile,"\" \"%s.ucm\";\n",mName.c_str());}
	/*
	When this attribute is true, any time that the weight of a point is
	modified, all of the other weights on the point are changed such
	that the total of all the weights for the point sum to 1.0.
	When this attribute is false, the weights are not normalized, and
	will not sum to 1.0 unless the user specifically makes them sum to 1.0.
	Note: a "false" value for -nrm/-normalize flag on the skinPercent command overrides
	this attribute value. However, a "true" value for the -nrm/-normalize flag on
	the skinPercent command does not override this attribute value.
	*/
	void setNormalizeWeights(bool nw){if(nw == true) return; fprintf_s(mFile, "setAttr \".nw\" %i;\n", nw);}
	/*
	When this attribute is true, any time that the weight of a point is
	modified, all of the other weights on the point are changed such
	that the total of all the weights for the point sum to 1.0.
	When this attribute is false, the weights are not normalized, and
	will not sum to 1.0 unless the user specifically makes them sum to 1.0.
	Note: a "false" value for -nrm/-normalize flag on the skinPercent command overrides
	this attribute value. However, a "true" value for the -nrm/-normalize flag on
	the skinPercent command does not override this attribute value.
	*/
	void setNormalizeWeights(const BoolID& nw){fprintf_s(mFile,"connectAttr \"");nw.write(mFile);fprintf_s(mFile,"\" \"%s.nw\";\n",mName.c_str());}
	/*If set to true then the deformation will affect user normals*/
	void setDeformUserNormals(bool dun){if(dun == true) return; fprintf_s(mFile, "setAttr \".dun\" %i;\n", dun);}
	/*If set to true then the deformation will affect user normals*/
	void setDeformUserNormals(const BoolID& dun){fprintf_s(mFile,"connectAttr \"");dun.write(mFile);fprintf_s(mFile,"\" \"%s.dun\";\n",mName.c_str());}
	/*Gets marked dirty when the point weights need to be recomputed*/
	void setWtDrty(const MessageID& wtd){fprintf_s(mFile,"connectAttr \"");wtd.write(mFile);fprintf_s(mFile,"\" \"%s.wtd\";\n",mName.c_str());}
	/*
	The bind pose will be connected to this attribute to indicate
	that it is the bind pose for the skin.
	*/
	void setBindPose(const MessageID& bp){fprintf_s(mFile,"connectAttr \"");bp.write(mFile);fprintf_s(mFile,"\" \"%s.bp\";\n",mName.c_str());}
	/*Bundle of weights for each CV*/
	const WeightListID& getWeightList(size_t wl_i){char buffer[4096];sprintf_s (buffer, "%s.wl[%i]",mName.c_str(),wl_i);return (const char*)buffer;}
	/*weights for each target*/
	const DoubleID& getWeights(size_t wl_i,size_t w_i){char buffer[4096];sprintf_s (buffer, "%s.wl[%i].w[%i]",mName.c_str(),wl_i,w_i);return (const char*)buffer;}
	/*The inclusive matrix inverse of the driving transform at the time of bind*/
	const MatrixID& getBindPreMatrix(size_t pm_i){char buffer[4096];sprintf_s (buffer, "%s.pm[%i]",mName.c_str(),pm_i);return (const char*)buffer;}
	/*The inclusive matrix of the geometry path at the time of the bound*/
	MatrixID getGeomMatrix(){char buffer[4096];sprintf_s (buffer, "%s.gm",mName.c_str());return (const char*)buffer;}
	/*Driving transforms array*/
	const MatrixID& getMatrix(size_t ma_i){char buffer[4096];sprintf_s (buffer, "%s.ma[%i]",mName.c_str(),ma_i);return (const char*)buffer;}
	/*
	Old dropoff rate, kept around temporarily for compatibility
	purposes
	*/
	DoubleID getDropoffRate(){char buffer[4096];sprintf_s (buffer, "%s.dr",mName.c_str());return (const char*)buffer;}
	/*
	Rate of weight value dropoff per influence object
	(1 for linear, 2 for quadratic, etc. )
	*/
	const DoubleID& getDropoff(size_t dpf_i){char buffer[4096];sprintf_s (buffer, "%s.dpf[%i]",mName.c_str(),dpf_i);return (const char*)buffer;}
	/*
	Controls how smooth the deformation resulting from the
	a poly mesh influence object will be
	*/
	const DoubleID& getSmoothness(size_t smt_i){char buffer[4096];sprintf_s (buffer, "%s.smt[%i]",mName.c_str(),smt_i);return (const char*)buffer;}
	/*
	Indicates whether the weights of the corresponding influence
	are allowed to change
	*/
	const BoolID& getLockWeights(size_t lw_i){char buffer[4096];sprintf_s (buffer, "%s.lw[%i]",mName.c_str(),lw_i);return (const char*)buffer;}
	/*
	When true, the skinCluster will not allow a vertex to be weighted
	to more then "maxInfluences" transforms, as defined by the
	maxInfluences attribute.
	<p/>
	When this attribute is switched on, the skinCluster will not immediately
	reassign all of its skin weights. Instead, the skinCluster will begin
	enforcing the max influences as weights are edited. Alternatively, the
	attribute editor "Update Weights" button or the corresponding skinCluster
	command can be used to reassign all of the weights at once.
	<p/>
	Note that locked influences take precedence over max influences. Therefore,
	if more the maximum number of influences are locked and weighted, the
	weights are over-constrained. In this case, the max influences cannot
	be maintained unless you remove some of the locks on the influences.
	*/
	BoolID getMaintainMaxInfluences(){char buffer[4096];sprintf_s (buffer, "%s.mmi",mName.c_str());return (const char*)buffer;}
	/*
	When the related attribute 'obeyMaxInfluences' is true, this attribute
	specifies the maximum number of transforms that can influence a point.
	When the related attribute 'obeyMaxInfluences' is false, this attribute
	specifies the number of influences at the time the skin was bound.
	*/
	IntID getMaxInfluences(){char buffer[4096];sprintf_s (buffer, "%s.mi",mName.c_str());return (const char*)buffer;}
	/*
	Stores the method by which the skinCluster was bound
	where 1 = ClosestDistance, 2 = Closest Joint
	*/
	IntID getBindMethod(){char buffer[4096];sprintf_s (buffer, "%s.bm",mName.c_str());return (const char*)buffer;}
	/*The world space coordinates of the driver influence geometry*/
	const GeometryID& getDriverPoints(size_t drp_i){char buffer[4096];sprintf_s (buffer, "%s.drp[%i]",mName.c_str(),drp_i);return (const char*)buffer;}
	/*The world space coordinates of the base influence geometry*/
	const GeometryID& getBasePoints(size_t bsp_i){char buffer[4096];sprintf_s (buffer, "%s.bsp[%i]",mName.c_str(),bsp_i);return (const char*)buffer;}
	/*Set to dirty when the world space coordinates of one of the base influence geometries change*/
	MessageID getBaseDirty(){char buffer[4096];sprintf_s (buffer, "%s.bsd",mName.c_str());return (const char*)buffer;}
	/*Temporarily stores the weights for one of the influences*/
	DoubleArrayID getPaintWeights(){char buffer[4096];sprintf_s (buffer, "%s.ptw",mName.c_str());return (const char*)buffer;}
	/*
	Identifies the influence whose weights are used in the
	paintWeights attribute
	*/
	MessageID getPaintTrans(){char buffer[4096];sprintf_s (buffer, "%s.ptt",mName.c_str());return (const char*)buffer;}
	/*Gets marked dirty when the values in paintWeights change*/
	MessageID getPaintArrDirty(){char buffer[4096];sprintf_s (buffer, "%s.pad",mName.c_str());return (const char*)buffer;}
	/*
	If set to true then moving the components of the influence
	objects will affect the skin deformation
	*/
	BoolID getUseComponents(){char buffer[4096];sprintf_s (buffer, "%s.uc",mName.c_str());return (const char*)buffer;}
	/*The number of samples to be taken on influence curves/surfaces*/
	const IntID& getNurbsSamples(size_t ns_i){char buffer[4096];sprintf_s (buffer, "%s.ns[%i]",mName.c_str(),ns_i);return (const char*)buffer;}
	/*
	This attribute is obsolete and is unused in versions past Maya 8.0.
	This attribute is only used when the useComponents attribute is true.
	When this attribute is true, we use the new algorithm for component-type
	influence objects so that the matrix of the influence object is taken
	into account in addition to the tweaks on any influence components.
	This means that the joints and the influence object can be scaled as a group
	without modifying the deformation behavior. This attribute is false by default
	in order to not change any existing scenes.
	*/
	BoolID getUseComponentsMatrix(){char buffer[4096];sprintf_s (buffer, "%s.ucm",mName.c_str());return (const char*)buffer;}
	/*
	When this attribute is true, any time that the weight of a point is
	modified, all of the other weights on the point are changed such
	that the total of all the weights for the point sum to 1.0.
	When this attribute is false, the weights are not normalized, and
	will not sum to 1.0 unless the user specifically makes them sum to 1.0.
	Note: a "false" value for -nrm/-normalize flag on the skinPercent command overrides
	this attribute value. However, a "true" value for the -nrm/-normalize flag on
	the skinPercent command does not override this attribute value.
	*/
	BoolID getNormalizeWeights(){char buffer[4096];sprintf_s (buffer, "%s.nw",mName.c_str());return (const char*)buffer;}
	/*If set to true then the deformation will affect user normals*/
	BoolID getDeformUserNormals(){char buffer[4096];sprintf_s (buffer, "%s.dun",mName.c_str());return (const char*)buffer;}
	/*Gets marked dirty when the point weights need to be recomputed*/
	MessageID getWtDrty(){char buffer[4096];sprintf_s (buffer, "%s.wtd",mName.c_str());return (const char*)buffer;}
	/*
	The bind pose will be connected to this attribute to indicate
	that it is the bind pose for the skin.
	*/
	MessageID getBindPose(){char buffer[4096];sprintf_s (buffer, "%s.bp",mName.c_str());return (const char*)buffer;}
protected:
	SkinCluster(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SKINCLUSTER_H__
