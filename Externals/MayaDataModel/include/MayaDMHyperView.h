/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HYPERVIEW_H__
#define __MayaDM_HYPERVIEW_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*This dependency node represents a hypergraph view bookmark. <p/>*/
class HyperView : public DependNode
{
public:
public:
	HyperView(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "hyperView"){}
	virtual ~HyperView(){}
	/*The position of the focus node.*/
	void setPosition(const double2& p){if(p == double2(0, 0)) return; fprintf_s(mFile, "setAttr \".p\" -type \"double2\" ");p.write(mFile);fprintf_s(mFile,";\n");}
	/*The position of the focus node.*/
	void setPosition(const Double2ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*The X coordinate of the focus node.*/
	void setPositionX(double px){if(px == 0.0) return; fprintf_s(mFile, "setAttr \".p.px\" %f;\n", px);}
	/*The X coordinate of the focus node.*/
	void setPositionX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*The Y coordinate of the focus node.*/
	void setPositionY(double py){if(py == 0.0) return; fprintf_s(mFile, "setAttr \".p.py\" %f;\n", py);}
	/*The Y coordinate of the focus node.*/
	void setPositionY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*The lower-left coordinate of the view rectangle.*/
	void setViewRectLow(const double2& vl){if(vl == double2(0, 0)) return; fprintf_s(mFile, "setAttr \".vl\" -type \"double2\" ");vl.write(mFile);fprintf_s(mFile,";\n");}
	/*The lower-left coordinate of the view rectangle.*/
	void setViewRectLow(const Double2ID& vl){fprintf_s(mFile,"connectAttr \"");vl.write(mFile);fprintf_s(mFile,"\" \"%s.vl\";\n",mName.c_str());}
	/*The X component.*/
	void setViewXL(double xl){if(xl == 0.0) return; fprintf_s(mFile, "setAttr \".vl.xl\" %f;\n", xl);}
	/*The X component.*/
	void setViewXL(const DoubleID& xl){fprintf_s(mFile,"connectAttr \"");xl.write(mFile);fprintf_s(mFile,"\" \"%s.vl.xl\";\n",mName.c_str());}
	/*The Y component.*/
	void setViewYL(double yl){if(yl == 0.0) return; fprintf_s(mFile, "setAttr \".vl.yl\" %f;\n", yl);}
	/*The Y component.*/
	void setViewYL(const DoubleID& yl){fprintf_s(mFile,"connectAttr \"");yl.write(mFile);fprintf_s(mFile,"\" \"%s.vl.yl\";\n",mName.c_str());}
	/*The upper-right coordinate of the view rectangle.*/
	void setViewRectHigh(const double2& vh){if(vh == double2(0, 0)) return; fprintf_s(mFile, "setAttr \".vh\" -type \"double2\" ");vh.write(mFile);fprintf_s(mFile,";\n");}
	/*The upper-right coordinate of the view rectangle.*/
	void setViewRectHigh(const Double2ID& vh){fprintf_s(mFile,"connectAttr \"");vh.write(mFile);fprintf_s(mFile,"\" \"%s.vh\";\n",mName.c_str());}
	/*The X component.*/
	void setViewXH(double xh){if(xh == 0.0) return; fprintf_s(mFile, "setAttr \".vh.xh\" %f;\n", xh);}
	/*The X component.*/
	void setViewXH(const DoubleID& xh){fprintf_s(mFile,"connectAttr \"");xh.write(mFile);fprintf_s(mFile,"\" \"%s.vh.xh\";\n",mName.c_str());}
	/*The Y component.*/
	void setViewYH(double yh){if(yh == 0.0) return; fprintf_s(mFile, "setAttr \".vh.yh\" %f;\n", yh);}
	/*The Y component.*/
	void setViewYH(const DoubleID& yh){fprintf_s(mFile,"connectAttr \"");yh.write(mFile);fprintf_s(mFile,"\" \"%s.vh.yh\";\n",mName.c_str());}
	/*Indicates if the bookmark represents a DAG or DG view.*/
	void setDagView(bool dag){if(dag == true) return; fprintf_s(mFile, "setAttr \".dag\" %i;\n", dag);}
	/*Indicates if the bookmark represents a DAG or DG view.*/
	void setDagView(const BoolID& dag){fprintf_s(mFile,"connectAttr \"");dag.write(mFile);fprintf_s(mFile,"\" \"%s.dag\";\n",mName.c_str());}
	/*The description of the hypergraph view.*/
	void setDescription(const string& d){if(d == "") return; fprintf_s(mFile, "setAttr \".d\" -type \"string\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*The description of the hypergraph view.*/
	void setDescription(const StringID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The focus node which the view tracks.*/
	void setFocusNode(const MessageID& fnd){fprintf_s(mFile,"connectAttr \"");fnd.write(mFile);fprintf_s(mFile,"\" \"%s.fnd\";\n",mName.c_str());}
	/*The root node connection list for DG bookmarks.*/
	void setRootNode(size_t rnd_i,const MessageID& rnd){fprintf_s(mFile,"connectAttr \"");rnd.write(mFile);fprintf_s(mFile,"\" \"%s.rnd[%i]\";\n",mName.c_str(),rnd_i);}
	/*The focus node full path name.*/
	void setFullName(const string& fn){if(fn == "") return; fprintf_s(mFile, "setAttr \".fn\" -type \"string\" ");fn.write(mFile);fprintf_s(mFile,";\n");}
	/*The focus node full path name.*/
	void setFullName(const StringID& fn){fprintf_s(mFile,"connectAttr \"");fn.write(mFile);fprintf_s(mFile,"\" \"%s.fn\";\n",mName.c_str());}
	/*The focus node name.*/
	void setShortName(const string& sn){if(sn == "") return; fprintf_s(mFile, "setAttr \".sn\" -type \"string\" ");sn.write(mFile);fprintf_s(mFile,";\n");}
	/*The focus node name.*/
	void setShortName(const StringID& sn){fprintf_s(mFile,"connectAttr \"");sn.write(mFile);fprintf_s(mFile,"\" \"%s.sn\";\n",mName.c_str());}
	/*Specifies the build direction for DG graphs.  The following are legal values: 0=Upstream, 1=Downstream, 2=All.*/
	void setBuildDirection(unsigned int bd){if(bd == 2) return; fprintf_s(mFile, "setAttr \".bd\" %i;\n", bd);}
	/*Specifies the build direction for DG graphs.  The following are legal values: 0=Upstream, 1=Downstream, 2=All.*/
	void setBuildDirection(const UnsignedintID& bd){fprintf_s(mFile,"connectAttr \"");bd.write(mFile);fprintf_s(mFile,"\" \"%s.bd\";\n",mName.c_str());}
	/*The graph traversal limit.*/
	void setGraphTraversalLimit(int gtl){if(gtl == -1) return; fprintf_s(mFile, "setAttr \".gtl\" %i;\n", gtl);}
	/*The graph traversal limit.*/
	void setGraphTraversalLimit(const IntID& gtl){fprintf_s(mFile,"connectAttr \"");gtl.write(mFile);fprintf_s(mFile,"\" \"%s.gtl\";\n",mName.c_str());}
	/*hyperLayoutDG node which stores the depend nodes and their positions in the layout.*/
	void setHyperLayout(const MessageID& hl){fprintf_s(mFile,"connectAttr \"");hl.write(mFile);fprintf_s(mFile,"\" \"%s.hl\";\n",mName.c_str());}
	/*The position of the focus node.*/
	Double2ID getPosition(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*The X coordinate of the focus node.*/
	DoubleID getPositionX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*The Y coordinate of the focus node.*/
	DoubleID getPositionY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*The lower-left coordinate of the view rectangle.*/
	Double2ID getViewRectLow(){char buffer[4096];sprintf_s (buffer, "%s.vl",mName.c_str());return (const char*)buffer;}
	/*The X component.*/
	DoubleID getViewXL(){char buffer[4096];sprintf_s (buffer, "%s.vl.xl",mName.c_str());return (const char*)buffer;}
	/*The Y component.*/
	DoubleID getViewYL(){char buffer[4096];sprintf_s (buffer, "%s.vl.yl",mName.c_str());return (const char*)buffer;}
	/*The upper-right coordinate of the view rectangle.*/
	Double2ID getViewRectHigh(){char buffer[4096];sprintf_s (buffer, "%s.vh",mName.c_str());return (const char*)buffer;}
	/*The X component.*/
	DoubleID getViewXH(){char buffer[4096];sprintf_s (buffer, "%s.vh.xh",mName.c_str());return (const char*)buffer;}
	/*The Y component.*/
	DoubleID getViewYH(){char buffer[4096];sprintf_s (buffer, "%s.vh.yh",mName.c_str());return (const char*)buffer;}
	/*Indicates if the bookmark represents a DAG or DG view.*/
	BoolID getDagView(){char buffer[4096];sprintf_s (buffer, "%s.dag",mName.c_str());return (const char*)buffer;}
	/*The description of the hypergraph view.*/
	StringID getDescription(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The focus node which the view tracks.*/
	MessageID getFocusNode(){char buffer[4096];sprintf_s (buffer, "%s.fnd",mName.c_str());return (const char*)buffer;}
	/*The root node connection list for DG bookmarks.*/
	const MessageID& getRootNode(size_t rnd_i){char buffer[4096];sprintf_s (buffer, "%s.rnd[%i]",mName.c_str(),rnd_i);return (const char*)buffer;}
	/*The focus node full path name.*/
	StringID getFullName(){char buffer[4096];sprintf_s (buffer, "%s.fn",mName.c_str());return (const char*)buffer;}
	/*The focus node name.*/
	StringID getShortName(){char buffer[4096];sprintf_s (buffer, "%s.sn",mName.c_str());return (const char*)buffer;}
	/*Specifies the build direction for DG graphs.  The following are legal values: 0=Upstream, 1=Downstream, 2=All.*/
	UnsignedintID getBuildDirection(){char buffer[4096];sprintf_s (buffer, "%s.bd",mName.c_str());return (const char*)buffer;}
	/*The graph traversal limit.*/
	IntID getGraphTraversalLimit(){char buffer[4096];sprintf_s (buffer, "%s.gtl",mName.c_str());return (const char*)buffer;}
	/*hyperLayoutDG node which stores the depend nodes and their positions in the layout.*/
	MessageID getHyperLayout(){char buffer[4096];sprintf_s (buffer, "%s.hl",mName.c_str());return (const char*)buffer;}
protected:
	HyperView(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HYPERVIEW_H__
