/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CHOICE_H__
#define __MayaDM_CHOICE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
    This node is used to choose between one of many inputs. The selector
    attribute's value is an integer that specifies the index of which of
    the input multi-attributes should be passed on to the output.

</pre></p>
*/
class Choice : public DependNode
{
public:
public:
	Choice(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "choice"){}
	virtual ~Choice(){}
	/*Index determining which input is passed on to output*/
	void setSelector(int s){if(s == 0) return; fprintf_s(mFile, "setAttr \".s\" %i;\n", s);}
	/*Index determining which input is passed on to output*/
	void setSelector(const IntID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*Multi-input for which selector chooses the output*/
	void setInput(size_t i_i,const GenerictypeddataID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i]\";\n",mName.c_str(),i_i);}
	/*Multi-attribute input indexed by selector*/
	void setOutput(const GenerictypeddataID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Index determining which input is passed on to output*/
	IntID getSelector(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*Multi-input for which selector chooses the output*/
	const GenerictypeddataID& getInput(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i]",mName.c_str(),i_i);return (const char*)buffer;}
	/*Multi-attribute input indexed by selector*/
	GenerictypeddataID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	Choice(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CHOICE_H__
