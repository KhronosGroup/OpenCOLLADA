/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FILTER_H__
#define __MayaDM_FILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
The filter node is the base class for the
 motion capture data filters
 used by the applyTake command to process recorded motion capture data.
 Since the inputs to this node are unconnectable, this node cannot be used
 in the tradition dependency graph sense.

 <p/>Each derived filter node
 class supports a number of filter specific settings which affect the
 operation of the filter as it is invoked by applyTake.  These settings
 are presevered when the Maya file is saved.
*/
class Filter : public DependNode
{
public:
	/*input timestamp, data, and type inputs*/
	struct Input{
		void write(FILE* file) const
		{
		}
	};
	/*resulting timestamp, data, and type from filter computation*/
	struct Output{
		void write(FILE* file) const
		{
		}
	};
public:
	Filter(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "filter"){}
	virtual ~Filter(){}
	/*Sets the active/inactive state of the filter in the deviceEditor.*/
	void setDeviceEditorActive(bool dea){if(dea == false) return; fprintf_s(mFile, "setAttr \".dea\" %i;\n", dea);}
	/*Sets the active/inactive state of the filter in the deviceEditor.*/
	void setDeviceEditorActive(const BoolID& dea){fprintf_s(mFile,"connectAttr \"");dea.write(mFile);fprintf_s(mFile,"\" \"%s.dea\";\n",mName.c_str());}
	/*Sets the active/inactive state of the filter in the deviceEditor.*/
	BoolID getDeviceEditorActive(){char buffer[4096];sprintf_s (buffer, "%s.dea",mName.c_str());return (const char*)buffer;}
protected:
	Filter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FILTER_H__
