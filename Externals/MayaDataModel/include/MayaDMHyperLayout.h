/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HYPERLAYOUT_H__
#define __MayaDM_HYPERLAYOUT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This node stores Hypergraph layout information for a DAG graph.
This includes the position and collapse/expand state of nodes
that have been configured by the user and background image
information.
*/
class HyperLayout : public DependNode
{
public:
	/*stores user placement position for hypergraph node*/
	struct HyperPosition{
		float positionX;
		float positionY;
		bool isCollapsed;
		bool isFreeform;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", positionX);
			fprintf_s(file,"%f ", positionY);
			fprintf_s(file,"%i ", isCollapsed);
			fprintf_s(file,"%i ", isFreeform);
		}
	};
public:
	HyperLayout(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "hyperLayout"){}
	virtual ~HyperLayout(){}
	/*stores user placement position for hypergraph node*/
	void setHyperPosition(size_t hyp_i,const HyperPosition& hyp){fprintf_s(mFile, "setAttr \".hyp[%i]\" ",hyp_i);hyp.write(mFile);fprintf_s(mFile,";\n");}
	/*stores user placement position for hypergraph node*/
	void setHyperPosition(size_t hyp_i,const HyperPositionID& hyp){fprintf_s(mFile,"connectAttr \"");hyp.write(mFile);fprintf_s(mFile,"\" \"%s.hyp[%i]\";\n",mName.c_str(),hyp_i);}
	/*x position of freeform layout*/
	void setPositionX(size_t hyp_i,float x){if(x == 0.0) return; fprintf_s(mFile, "setAttr \".hyp[%i].x\" %f;\n", hyp_i,x);}
	/*x position of freeform layout*/
	void setPositionX(size_t hyp_i,const FloatID& x){fprintf_s(mFile,"connectAttr \"");x.write(mFile);fprintf_s(mFile,"\" \"%s.hyp[%i].x\";\n",mName.c_str(),hyp_i);}
	/*y position of freeform layout*/
	void setPositionY(size_t hyp_i,float y){if(y == 0.0) return; fprintf_s(mFile, "setAttr \".hyp[%i].y\" %f;\n", hyp_i,y);}
	/*y position of freeform layout*/
	void setPositionY(size_t hyp_i,const FloatID& y){fprintf_s(mFile,"connectAttr \"");y.write(mFile);fprintf_s(mFile,"\" \"%s.hyp[%i].y\";\n",mName.c_str(),hyp_i);}
	/*collapsed state of node*/
	void setIsCollapsed(size_t hyp_i,bool isc){if(isc == false) return; fprintf_s(mFile, "setAttr \".hyp[%i].isc\" %i;\n", hyp_i,isc);}
	/*collapsed state of node*/
	void setIsCollapsed(size_t hyp_i,const BoolID& isc){fprintf_s(mFile,"connectAttr \"");isc.write(mFile);fprintf_s(mFile,"\" \"%s.hyp[%i].isc\";\n",mName.c_str(),hyp_i);}
	/*freeform layout state*/
	void setIsFreeform(size_t hyp_i,bool isf){if(isf == false) return; fprintf_s(mFile, "setAttr \".hyp[%i].isf\" %i;\n", hyp_i,isf);}
	/*freeform layout state*/
	void setIsFreeform(size_t hyp_i,const BoolID& isf){fprintf_s(mFile,"connectAttr \"");isf.write(mFile);fprintf_s(mFile,"\" \"%s.hyp[%i].isf\";\n",mName.c_str(),hyp_i);}
	/*dependNode we are storing freeform position for*/
	void setDependNode(size_t hyp_i,const MessageID& dn){fprintf_s(mFile,"connectAttr \"");dn.write(mFile);fprintf_s(mFile,"\" \"%s.hyp[%i].dn\";\n",mName.c_str(),hyp_i);}
	/*background image name*/
	void setImageName(const string& img){if(img == "") return; fprintf_s(mFile, "setAttr \".img\" -type \"string\" ");img.write(mFile);fprintf_s(mFile,";\n");}
	/*background image name*/
	void setImageName(const StringID& img){fprintf_s(mFile,"connectAttr \"");img.write(mFile);fprintf_s(mFile,"\" \"%s.img\";\n",mName.c_str());}
	/*background image position.*/
	void setImagePosition(const double2& imp){if(imp == double2(0, 0)) return; fprintf_s(mFile, "setAttr \".imp\" -type \"double2\" ");imp.write(mFile);fprintf_s(mFile,";\n");}
	/*background image position.*/
	void setImagePosition(const Double2ID& imp){fprintf_s(mFile,"connectAttr \"");imp.write(mFile);fprintf_s(mFile,"\" \"%s.imp\";\n",mName.c_str());}
	/*The X coordinate of background image.*/
	void setImagePositionX(double ipx){if(ipx == 0.0) return; fprintf_s(mFile, "setAttr \".imp.ipx\" %f;\n", ipx);}
	/*The X coordinate of background image.*/
	void setImagePositionX(const DoubleID& ipx){fprintf_s(mFile,"connectAttr \"");ipx.write(mFile);fprintf_s(mFile,"\" \"%s.imp.ipx\";\n",mName.c_str());}
	/*The Y coordinate of background image.*/
	void setImagePositionY(double ipy){if(ipy == 0.0) return; fprintf_s(mFile, "setAttr \".imp.ipy\" %f;\n", ipy);}
	/*The Y coordinate of background image.*/
	void setImagePositionY(const DoubleID& ipy){fprintf_s(mFile,"connectAttr \"");ipy.write(mFile);fprintf_s(mFile,"\" \"%s.imp.ipy\";\n",mName.c_str());}
	/*image scale factor*/
	void setImageScale(float ims){if(ims == 1.0) return; fprintf_s(mFile, "setAttr \".ims\" %f;\n", ims);}
	/*image scale factor*/
	void setImageScale(const FloatID& ims){fprintf_s(mFile,"connectAttr \"");ims.write(mFile);fprintf_s(mFile,"\" \"%s.ims\";\n",mName.c_str());}
	/*all nodes are in freeform layout state*/
	void setAllNodesFreeform(bool anf){if(anf == false) return; fprintf_s(mFile, "setAttr \".anf\" %i;\n", anf);}
	/*all nodes are in freeform layout state*/
	void setAllNodesFreeform(const BoolID& anf){fprintf_s(mFile,"connectAttr \"");anf.write(mFile);fprintf_s(mFile,"\" \"%s.anf\";\n",mName.c_str());}
	/*stores user placement position for hypergraph node*/
	const HyperPositionID& getHyperPosition(size_t hyp_i){char buffer[4096];sprintf_s (buffer, "%s.hyp[%i]",mName.c_str(),hyp_i);return (const char*)buffer;}
	/*x position of freeform layout*/
	const FloatID& getPositionX(size_t hyp_i){char buffer[4096];sprintf_s (buffer, "%s.hyp[%i].x",mName.c_str(),hyp_i);return (const char*)buffer;}
	/*y position of freeform layout*/
	const FloatID& getPositionY(size_t hyp_i){char buffer[4096];sprintf_s (buffer, "%s.hyp[%i].y",mName.c_str(),hyp_i);return (const char*)buffer;}
	/*collapsed state of node*/
	const BoolID& getIsCollapsed(size_t hyp_i){char buffer[4096];sprintf_s (buffer, "%s.hyp[%i].isc",mName.c_str(),hyp_i);return (const char*)buffer;}
	/*freeform layout state*/
	const BoolID& getIsFreeform(size_t hyp_i){char buffer[4096];sprintf_s (buffer, "%s.hyp[%i].isf",mName.c_str(),hyp_i);return (const char*)buffer;}
	/*dependNode we are storing freeform position for*/
	const MessageID& getDependNode(size_t hyp_i){char buffer[4096];sprintf_s (buffer, "%s.hyp[%i].dn",mName.c_str(),hyp_i);return (const char*)buffer;}
	/*background image name*/
	StringID getImageName(){char buffer[4096];sprintf_s (buffer, "%s.img",mName.c_str());return (const char*)buffer;}
	/*background image position.*/
	Double2ID getImagePosition(){char buffer[4096];sprintf_s (buffer, "%s.imp",mName.c_str());return (const char*)buffer;}
	/*The X coordinate of background image.*/
	DoubleID getImagePositionX(){char buffer[4096];sprintf_s (buffer, "%s.imp.ipx",mName.c_str());return (const char*)buffer;}
	/*The Y coordinate of background image.*/
	DoubleID getImagePositionY(){char buffer[4096];sprintf_s (buffer, "%s.imp.ipy",mName.c_str());return (const char*)buffer;}
	/*image scale factor*/
	FloatID getImageScale(){char buffer[4096];sprintf_s (buffer, "%s.ims",mName.c_str());return (const char*)buffer;}
	/*all nodes are in freeform layout state*/
	BoolID getAllNodesFreeform(){char buffer[4096];sprintf_s (buffer, "%s.anf",mName.c_str());return (const char*)buffer;}
protected:
	HyperLayout(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HYPERLAYOUT_H__
