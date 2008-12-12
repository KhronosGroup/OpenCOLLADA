/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLENDSHAPE_H__
#define __MayaDM_BLENDSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
/*
This node takes geometry as input and deforms it
based on pairs of target shapes and weight values, to produce a
new shape that is the specified blending of the input shapes.
*/
class BlendShape : public GeometryFilter
{
public:
	/*
	Bundled list of target info for a shape that is being deformed.
	The array index of this attribute corresponds
	to the array index of the input attribute, meaning that this
	target info is used to deform a given input shape.
	*/
	struct InputTarget{
		/*
		Bundled group of target information for a particular target weight.
		The array index of this attribute corresponds
		to the array index of the weight attribute, meaning that the
		corresponding weight value controls this target.
		*/
		struct InputTargetGroup{
			/*
			Collection of all targets in a sequential target chain.
			The array index of this attribute is used to control which two target
			items we are interpolating between with the relationship:
			index = wt * 1000 + 5000. Thus a weight of 1 corresponds to the
			index 6000. An inbetween placed at a weight of 0.5 would be at
			the index 5500.
			*/
			struct InputTargetItem{
				pointArray inputPointsTarget;
				componentList inputComponentsTarget;
				void write(FILE* file) const
				{
					inputPointsTarget.write(file);
					fprintf_s(file, " ");
					inputComponentsTarget.write(file);
				}
			}* inputTargetItem;
			float* targetWeights;
			void write(FILE* file) const
			{
				size_t size = sizeof(inputTargetItem)/sizeof(InputTargetItem);
				for(size_t i=0; i<size; ++i)
				{
					inputTargetItem[i].write(file);
					fprintf_s(file, " ");
					if(i+1<size) fprintf_s(file," ");
				}
				size = sizeof(targetWeights)/sizeof(float);
				for(size_t i=0; i<size; ++i)
				{
					fprintf_s(file,"%f", targetWeights[i]);
					if(i+1<size) fprintf_s(file," ");
				}
			}
		}* inputTargetGroup;
		void write(FILE* file) const
		{
			size_t size = sizeof(inputTargetGroup)/sizeof(InputTargetGroup);
			for(size_t i=0; i<size; ++i)
			{
				inputTargetGroup[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
public:
	BlendShape(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "blendShape"){}
	virtual ~BlendShape(){}
	/*Should the deformation check to see if the input topologies match?*/
	void setTopologyCheck(bool tc){if(tc == true) return; fprintf_s(mFile, "setAttr \".tc\" %i;\n", tc);}
	/*Should the deformation check to see if the input topologies match?*/
	void setTopologyCheck(const BoolID& tc){fprintf_s(mFile,"connectAttr \"");tc.write(mFile);fprintf_s(mFile,"\" \"%s.tc\";\n",mName.c_str());}
	/*The array of weight values (one per target shape)*/
	void setWeight(size_t w_i,float w){if(w == 0) return; fprintf_s(mFile, "setAttr \".w[%i]\" %f;\n", w_i,w);}
	/*The array of weight values (one per target shape)*/
	void setWeight(size_t w_i,const FloatID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w[%i]\";\n",mName.c_str(),w_i);}
	/*
	The name of a file containing an icon per target shape
	(not currently supported).
	*/
	void setIcon(size_t icn_i,const string& icn){if(icn == "NULL") return; fprintf_s(mFile, "setAttr \".icn[%i]\" -type \"string\" ",icn_i);icn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Bundled list of target info for a shape that is being deformed.
	The array index of this attribute corresponds
	to the array index of the input attribute, meaning that this
	target info is used to deform a given input shape.
	*/
	void setInputTarget(size_t it_i,const InputTarget& it){fprintf_s(mFile, "setAttr \".it[%i]\" ",it_i);it.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Bundled list of target info for a shape that is being deformed.
	The array index of this attribute corresponds
	to the array index of the input attribute, meaning that this
	target info is used to deform a given input shape.
	*/
	void setInputTarget(size_t it_i,const InputTargetID& it){fprintf_s(mFile,"connectAttr \"");it.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i]\";\n",mName.c_str(),it_i);}
	/*
	Bundled group of target information for a particular target weight.
	The array index of this attribute corresponds
	to the array index of the weight attribute, meaning that the
	corresponding weight value controls this target.
	*/
	void setInputTargetGroup(size_t it_i,size_t itg_i,const InputTarget::InputTargetGroup& itg){fprintf_s(mFile, "setAttr \".it[%i].itg[%i]\" ",it_i,itg_i);itg.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Bundled group of target information for a particular target weight.
	The array index of this attribute corresponds
	to the array index of the weight attribute, meaning that the
	corresponding weight value controls this target.
	*/
	void setInputTargetGroup(size_t it_i,size_t itg_i,const InputTargetGroupID& itg){fprintf_s(mFile,"connectAttr \"");itg.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i].itg[%i]\";\n",mName.c_str(),it_i,itg_i);}
	/*
	Collection of all targets in a sequential target chain.
	The array index of this attribute is used to control which two target
	items we are interpolating between with the relationship:
	index = wt * 1000 + 5000. Thus a weight of 1 corresponds to the
	index 6000. An inbetween placed at a weight of 0.5 would be at
	the index 5500.
	*/
	void setInputTargetItem(size_t it_i,size_t itg_i,size_t iti_i,const InputTarget::InputTargetGroup::InputTargetItem& iti){fprintf_s(mFile, "setAttr \".it[%i].itg[%i].iti[%i]\" ",it_i,itg_i,iti_i);iti.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Collection of all targets in a sequential target chain.
	The array index of this attribute is used to control which two target
	items we are interpolating between with the relationship:
	index = wt * 1000 + 5000. Thus a weight of 1 corresponds to the
	index 6000. An inbetween placed at a weight of 0.5 would be at
	the index 5500.
	*/
	void setInputTargetItem(size_t it_i,size_t itg_i,size_t iti_i,const InputTargetItemID& iti){fprintf_s(mFile,"connectAttr \"");iti.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i].itg[%i].iti[%i]\";\n",mName.c_str(),it_i,itg_i,iti_i);}
	/*The target geometry input*/
	void setInputGeomTarget(size_t it_i,size_t itg_i,size_t iti_i,const GeometryID& igt){fprintf_s(mFile,"connectAttr \"");igt.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i].itg[%i].iti[%i].igt\";\n",mName.c_str(),it_i,itg_i,iti_i);}
	/*Delta values for points in a target geometry.*/
	void setInputPointsTarget(size_t it_i,size_t itg_i,size_t iti_i,const pointArray& ipt){fprintf_s(mFile, "setAttr \".it[%i].itg[%i].iti[%i].ipt\" -type \"pointArray\" ",it_i,itg_i,iti_i);ipt.write(mFile);fprintf_s(mFile,";\n");}
	/*Delta values for points in a target geometry.*/
	void setInputPointsTarget(size_t it_i,size_t itg_i,size_t iti_i,const PointArrayID& ipt){fprintf_s(mFile,"connectAttr \"");ipt.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i].itg[%i].iti[%i].ipt\";\n",mName.c_str(),it_i,itg_i,iti_i);}
	/*Component list for points in a target geometry.*/
	void setInputComponentsTarget(size_t it_i,size_t itg_i,size_t iti_i,const componentList& ict){fprintf_s(mFile, "setAttr \".it[%i].itg[%i].iti[%i].ict\" -type \"componentList\" ",it_i,itg_i,iti_i);ict.write(mFile);fprintf_s(mFile,";\n");}
	/*Component list for points in a target geometry.*/
	void setInputComponentsTarget(size_t it_i,size_t itg_i,size_t iti_i,const ComponentListID& ict){fprintf_s(mFile,"connectAttr \"");ict.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i].itg[%i].iti[%i].ict\";\n",mName.c_str(),it_i,itg_i,iti_i);}
	/*
	The weights themselves, in the same order as the components deformed
	by the deformation.
	*/
	void setTargetWeights(size_t it_i,size_t itg_i,size_t tw_i,float tw){if(tw == 1.0) return; fprintf_s(mFile, "setAttr \".it[%i].itg[%i].tw[%i]\" %f;\n", it_i,itg_i,tw_i,tw);}
	/*
	The weights themselves, in the same order as the components deformed
	by the deformation.
	*/
	void setTargetWeights(size_t it_i,size_t itg_i,size_t tw_i,const FloatID& tw){fprintf_s(mFile,"connectAttr \"");tw.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i].itg[%i].tw[%i]\";\n",mName.c_str(),it_i,itg_i,tw_i);}
	/*
	Specifies the space in which point deltas are calculated.
	Valid values are 0 = "world", 1 = "local", 2 = "user".
	*/
	void setOrigin(unsigned int or){if(or == 1) return; fprintf_s(mFile, "setAttr \".or\" %i;\n", or);}
	/*
	Specifies the space in which point deltas are calculated.
	Valid values are 0 = "world", 1 = "local", 2 = "user".
	*/
	void setOrigin(const UnsignedintID& or){fprintf_s(mFile,"connectAttr \"");or.write(mFile);fprintf_s(mFile,"\" \"%s.or\";\n",mName.c_str());}
	/*
	When the origin flag is userDefined, the origin of the base shape
	is computed with respect to this point.
	*/
	void setBaseOrigin(const double3& bo){fprintf_s(mFile, "setAttr \".bo\" -type \"double3\" ");bo.write(mFile);fprintf_s(mFile,";\n");}
	/*
	When the origin flag is userDefined, the origin of the base shape
	is computed with respect to this point.
	*/
	void setBaseOrigin(const Double3ID& bo){fprintf_s(mFile,"connectAttr \"");bo.write(mFile);fprintf_s(mFile,"\" \"%s.bo\";\n",mName.c_str());}
	/*X position of baseOrigin.*/
	void setBaseOriginX(double bx){if(bx == 0) return; fprintf_s(mFile, "setAttr \".bo.bx\" %f;\n", bx);}
	/*X position of baseOrigin.*/
	void setBaseOriginX(const DoubleID& bx){fprintf_s(mFile,"connectAttr \"");bx.write(mFile);fprintf_s(mFile,"\" \"%s.bo.bx\";\n",mName.c_str());}
	/*Y position of baseOrigin.*/
	void setBaseOriginY(double by){if(by == 0) return; fprintf_s(mFile, "setAttr \".bo.by\" %f;\n", by);}
	/*Y position of baseOrigin.*/
	void setBaseOriginY(const DoubleID& by){fprintf_s(mFile,"connectAttr \"");by.write(mFile);fprintf_s(mFile,"\" \"%s.bo.by\";\n",mName.c_str());}
	/*Z position of baseOrigin.*/
	void setBaseOriginZ(double bz){if(bz == 0) return; fprintf_s(mFile, "setAttr \".bo.bz\" %f;\n", bz);}
	/*Z position of baseOrigin.*/
	void setBaseOriginZ(const DoubleID& bz){fprintf_s(mFile,"connectAttr \"");bz.write(mFile);fprintf_s(mFile,"\" \"%s.bo.bz\";\n",mName.c_str());}
	/*
	When the origin flag is userDefined, the origin of the target
	is computed with respect to this point.
	*/
	void setTargetOrigin(const double3& to){fprintf_s(mFile, "setAttr \".to\" -type \"double3\" ");to.write(mFile);fprintf_s(mFile,";\n");}
	/*
	When the origin flag is userDefined, the origin of the target
	is computed with respect to this point.
	*/
	void setTargetOrigin(const Double3ID& to){fprintf_s(mFile,"connectAttr \"");to.write(mFile);fprintf_s(mFile,"\" \"%s.to\";\n",mName.c_str());}
	/*X position of targetOrigin.*/
	void setTargetOriginX(double tx){if(tx == 0) return; fprintf_s(mFile, "setAttr \".to.tx\" %f;\n", tx);}
	/*X position of targetOrigin.*/
	void setTargetOriginX(const DoubleID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.to.tx\";\n",mName.c_str());}
	/*Y position of targetOrigin.*/
	void setTargetOriginY(double ty){if(ty == 0) return; fprintf_s(mFile, "setAttr \".to.ty\" %f;\n", ty);}
	/*Y position of targetOrigin.*/
	void setTargetOriginY(const DoubleID& ty){fprintf_s(mFile,"connectAttr \"");ty.write(mFile);fprintf_s(mFile,"\" \"%s.to.ty\";\n",mName.c_str());}
	/*Z position of targetOrigin.*/
	void setTargetOriginZ(double tz){if(tz == 0) return; fprintf_s(mFile, "setAttr \".to.tz\" %f;\n", tz);}
	/*Z position of targetOrigin.*/
	void setTargetOriginZ(const DoubleID& tz){fprintf_s(mFile,"connectAttr \"");tz.write(mFile);fprintf_s(mFile,"\" \"%s.to.tz\";\n",mName.c_str());}
	/*This is true if the blendShape is used to blend parallel deformations.*/
	void setParallelBlender(bool pb){if(pb == 0) return; fprintf_s(mFile, "setAttr \".pb\" %i;\n", pb);}
	/*Should the deformation check to see if the input topologies match?*/
	BoolID getTopologyCheck(){char buffer[4096];sprintf_s (buffer, "%s.tc",mName.c_str());return (const char*)buffer;}
	/*The array of weight values (one per target shape)*/
	const FloatID& getWeight(size_t w_i){char buffer[4096];sprintf_s (buffer, "%s.w[%i]",mName.c_str(),w_i);return (const char*)buffer;}
	/*
	Bundled list of target info for a shape that is being deformed.
	The array index of this attribute corresponds
	to the array index of the input attribute, meaning that this
	target info is used to deform a given input shape.
	*/
	const InputTargetID& getInputTarget(size_t it_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i]",mName.c_str(),it_i);return (const char*)buffer;}
	/*
	Bundled group of target information for a particular target weight.
	The array index of this attribute corresponds
	to the array index of the weight attribute, meaning that the
	corresponding weight value controls this target.
	*/
	const InputTargetGroupID& getInputTargetGroup(size_t it_i,size_t itg_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i].itg[%i]",mName.c_str(),it_i,itg_i);return (const char*)buffer;}
	/*
	Collection of all targets in a sequential target chain.
	The array index of this attribute is used to control which two target
	items we are interpolating between with the relationship:
	index = wt * 1000 + 5000. Thus a weight of 1 corresponds to the
	index 6000. An inbetween placed at a weight of 0.5 would be at
	the index 5500.
	*/
	const InputTargetItemID& getInputTargetItem(size_t it_i,size_t itg_i,size_t iti_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i].itg[%i].iti[%i]",mName.c_str(),it_i,itg_i,iti_i);return (const char*)buffer;}
	/*The target geometry input*/
	const GeometryID& getInputGeomTarget(size_t it_i,size_t itg_i,size_t iti_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i].itg[%i].iti[%i].igt",mName.c_str(),it_i,itg_i,iti_i);return (const char*)buffer;}
	/*Delta values for points in a target geometry.*/
	const PointArrayID& getInputPointsTarget(size_t it_i,size_t itg_i,size_t iti_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i].itg[%i].iti[%i].ipt",mName.c_str(),it_i,itg_i,iti_i);return (const char*)buffer;}
	/*Component list for points in a target geometry.*/
	const ComponentListID& getInputComponentsTarget(size_t it_i,size_t itg_i,size_t iti_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i].itg[%i].iti[%i].ict",mName.c_str(),it_i,itg_i,iti_i);return (const char*)buffer;}
	/*
	The weights themselves, in the same order as the components deformed
	by the deformation.
	*/
	const FloatID& getTargetWeights(size_t it_i,size_t itg_i,size_t tw_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i].itg[%i].tw[%i]",mName.c_str(),it_i,itg_i,tw_i);return (const char*)buffer;}
	/*
	Specifies the space in which point deltas are calculated.
	Valid values are 0 = "world", 1 = "local", 2 = "user".
	*/
	UnsignedintID getOrigin(){char buffer[4096];sprintf_s (buffer, "%s.or",mName.c_str());return (const char*)buffer;}
	/*
	When the origin flag is userDefined, the origin of the base shape
	is computed with respect to this point.
	*/
	Double3ID getBaseOrigin(){char buffer[4096];sprintf_s (buffer, "%s.bo",mName.c_str());return (const char*)buffer;}
	/*X position of baseOrigin.*/
	DoubleID getBaseOriginX(){char buffer[4096];sprintf_s (buffer, "%s.bo.bx",mName.c_str());return (const char*)buffer;}
	/*Y position of baseOrigin.*/
	DoubleID getBaseOriginY(){char buffer[4096];sprintf_s (buffer, "%s.bo.by",mName.c_str());return (const char*)buffer;}
	/*Z position of baseOrigin.*/
	DoubleID getBaseOriginZ(){char buffer[4096];sprintf_s (buffer, "%s.bo.bz",mName.c_str());return (const char*)buffer;}
	/*
	When the origin flag is userDefined, the origin of the target
	is computed with respect to this point.
	*/
	Double3ID getTargetOrigin(){char buffer[4096];sprintf_s (buffer, "%s.to",mName.c_str());return (const char*)buffer;}
	/*X position of targetOrigin.*/
	DoubleID getTargetOriginX(){char buffer[4096];sprintf_s (buffer, "%s.to.tx",mName.c_str());return (const char*)buffer;}
	/*Y position of targetOrigin.*/
	DoubleID getTargetOriginY(){char buffer[4096];sprintf_s (buffer, "%s.to.ty",mName.c_str());return (const char*)buffer;}
	/*Z position of targetOrigin.*/
	DoubleID getTargetOriginZ(){char buffer[4096];sprintf_s (buffer, "%s.to.tz",mName.c_str());return (const char*)buffer;}
protected:
	BlendShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BLENDSHAPE_H__
