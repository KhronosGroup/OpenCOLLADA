/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SAMPLER_H__
#define __MayaDM_SAMPLER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>    Sampler node
</pre></p>
*/
class Sampler : public DependNode
{
public:
	/*For Internal Use Only*/
	struct Function{
		/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
		struct Function_Inmap{
			short function_InmapTo;
			short function_InmapFrom;
			void write(FILE* file) const
			{
				fprintf_s(file,"%i ", function_InmapTo);
				fprintf_s(file,"%i", function_InmapFrom);
			}
		}* function_Inmap;
		/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
		struct Function_Outmap{
			short function_OutmapTo;
			short function_OutmapFrom;
			void write(FILE* file) const
			{
				fprintf_s(file,"%i ", function_OutmapTo);
				fprintf_s(file,"%i", function_OutmapFrom);
			}
		}* function_Outmap;
		double function_Default;
		void write(FILE* file) const
		{
			size_t size = sizeof(function_Inmap)/sizeof(Function_Inmap);
			for(size_t i=0; i<size; ++i)
			{
				function_Inmap[i].write(file);
				fprintf_s(file, " ");
				if(i+1<size) fprintf_s(file," ");
			}
			size = sizeof(function_Outmap)/sizeof(Function_Outmap);
			for(size_t i=0; i<size; ++i)
			{
				function_Outmap[i].write(file);
				fprintf_s(file, " ");
				if(i+1<size) fprintf_s(file," ");
			}
			fprintf_s(file,"%f", function_Default);
		}
	};
public:
	Sampler(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "sampler"){}
	virtual ~Sampler(){}
	/*Low point of the sample interval*/
	void setMinimum(double min){if(min == 0.0) return; fprintf_s(mFile, "setAttr \".min\" %f;\n", min);}
	/*Low point of the sample interval*/
	void setMinimum(const DoubleID& min){fprintf_s(mFile,"connectAttr \"");min.write(mFile);fprintf_s(mFile,"\" \"%s.min\";\n",mName.c_str());}
	/*High point of the sample interval*/
	void setMaximum(double max){if(max == 0.0) return; fprintf_s(mFile, "setAttr \".max\" %f;\n", max);}
	/*High point of the sample interval*/
	void setMaximum(const DoubleID& max){fprintf_s(mFile,"connectAttr \"");max.write(mFile);fprintf_s(mFile,"\" \"%s.max\";\n",mName.c_str());}
	/*Amount to step by from low to high point of the sample interval*/
	void setStep(double s){if(s == 0.0) return; fprintf_s(mFile, "setAttr \".s\" %f;\n", s);}
	/*Amount to step by from low to high point of the sample interval*/
	void setStep(const DoubleID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*If set then go from high to low in the sample interval*/
	void setInvert(bool i){if(i == false) return; fprintf_s(mFile, "setAttr \".i\" %i;\n", i);}
	/*If set then go from high to low in the sample interval*/
	void setInvert(const BoolID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*Sampled value*/
	void setValue(size_t v_i,const DoubleID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v[%i]\";\n",mName.c_str(),v_i);}
	/*For Internal Use Only*/
	void setFunction(const Function& f){fprintf_s(mFile, "setAttr \".f\" ");f.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only*/
	void setFunction(const FunctionID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*For Internal Use Only<br/>Actual function being applied at this attribute*/
	void setFunction_Raw(const FunctionID& fr){fprintf_s(mFile,"connectAttr \"");fr.write(mFile);fprintf_s(mFile,"\" \"%s.f.fr\";\n",mName.c_str());}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	void setFunction_Inmap(size_t fi_i,const Function::Function_Inmap& fi){fprintf_s(mFile, "setAttr \".f.fi[%i]\" ",fi_i);fi.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	void setFunction_Inmap(size_t fi_i,const Function_InmapID& fi){fprintf_s(mFile,"connectAttr \"");fi.write(mFile);fprintf_s(mFile,"\" \"%s.f.fi[%i]\";\n",mName.c_str(),fi_i);}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	void setFunction_InmapTo(size_t fi_i,short fit){if(fit == 0) return; fprintf_s(mFile, "setAttr \".f.fi[%i].fit\" %i;\n", fi_i,fit);}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	void setFunction_InmapTo(size_t fi_i,const ShortID& fit){fprintf_s(mFile,"connectAttr \"");fit.write(mFile);fprintf_s(mFile,"\" \"%s.f.fi[%i].fit\";\n",mName.c_str(),fi_i);}
	/*For Internal Use Only<br/>Function data input parameter index*/
	void setFunction_InmapFrom(size_t fi_i,short fif){if(fif == 0) return; fprintf_s(mFile, "setAttr \".f.fi[%i].fif\" %i;\n", fi_i,fif);}
	/*For Internal Use Only<br/>Function data input parameter index*/
	void setFunction_InmapFrom(size_t fi_i,const ShortID& fif){fprintf_s(mFile,"connectAttr \"");fif.write(mFile);fprintf_s(mFile,"\" \"%s.f.fi[%i].fif\";\n",mName.c_str(),fi_i);}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	void setFunction_Outmap(size_t fo_i,const Function::Function_Outmap& fo){fprintf_s(mFile, "setAttr \".f.fo[%i]\" ",fo_i);fo.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	void setFunction_Outmap(size_t fo_i,const Function_OutmapID& fo){fprintf_s(mFile,"connectAttr \"");fo.write(mFile);fprintf_s(mFile,"\" \"%s.f.fo[%i]\";\n",mName.c_str(),fo_i);}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	void setFunction_OutmapTo(size_t fo_i,short fot){if(fot == 0) return; fprintf_s(mFile, "setAttr \".f.fo[%i].fot\" %i;\n", fo_i,fot);}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	void setFunction_OutmapTo(size_t fo_i,const ShortID& fot){fprintf_s(mFile,"connectAttr \"");fot.write(mFile);fprintf_s(mFile,"\" \"%s.f.fo[%i].fot\";\n",mName.c_str(),fo_i);}
	/*For Internal Use Only<br/>Function data output parameter index*/
	void setFunction_OutmapFrom(size_t fo_i,short fof){if(fof == 0) return; fprintf_s(mFile, "setAttr \".f.fo[%i].fof\" %i;\n", fo_i,fof);}
	/*For Internal Use Only<br/>Function data output parameter index*/
	void setFunction_OutmapFrom(size_t fo_i,const ShortID& fof){fprintf_s(mFile,"connectAttr \"");fof.write(mFile);fprintf_s(mFile,"\" \"%s.f.fo[%i].fof\";\n",mName.c_str(),fo_i);}
	/*Function to be sampled*/
	void setFunction_Default(double fd){if(fd == 0.0) return; fprintf_s(mFile, "setAttr \".f.fd\" %f;\n", fd);}
	/*Function to be sampled*/
	void setFunction_Default(const DoubleID& fd){fprintf_s(mFile,"connectAttr \"");fd.write(mFile);fprintf_s(mFile,"\" \"%s.f.fd\";\n",mName.c_str());}
	/*Low point of the sample interval*/
	DoubleID getMinimum(){char buffer[4096];sprintf_s (buffer, "%s.min",mName.c_str());return (const char*)buffer;}
	/*High point of the sample interval*/
	DoubleID getMaximum(){char buffer[4096];sprintf_s (buffer, "%s.max",mName.c_str());return (const char*)buffer;}
	/*Amount to step by from low to high point of the sample interval*/
	DoubleID getStep(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*If set then go from high to low in the sample interval*/
	BoolID getInvert(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*Sampled value*/
	const DoubleID& getValue(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i]",mName.c_str(),v_i);return (const char*)buffer;}
	/*For Internal Use Only*/
	FunctionID getFunction(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*For Internal Use Only<br/>Actual function being applied at this attribute*/
	FunctionID getFunction_Raw(){char buffer[4096];sprintf_s (buffer, "%s.f.fr",mName.c_str());return (const char*)buffer;}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	const Function_InmapID& getFunction_Inmap(size_t fi_i){char buffer[4096];sprintf_s (buffer, "%s.f.fi[%i]",mName.c_str(),fi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	const ShortID& getFunction_InmapTo(size_t fi_i){char buffer[4096];sprintf_s (buffer, "%s.f.fi[%i].fit",mName.c_str(),fi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Function data input parameter index*/
	const ShortID& getFunction_InmapFrom(size_t fi_i){char buffer[4096];sprintf_s (buffer, "%s.f.fi[%i].fif",mName.c_str(),fi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	const Function_OutmapID& getFunction_Outmap(size_t fo_i){char buffer[4096];sprintf_s (buffer, "%s.f.fo[%i]",mName.c_str(),fo_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	const ShortID& getFunction_OutmapTo(size_t fo_i){char buffer[4096];sprintf_s (buffer, "%s.f.fo[%i].fot",mName.c_str(),fo_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Function data output parameter index*/
	const ShortID& getFunction_OutmapFrom(size_t fo_i){char buffer[4096];sprintf_s (buffer, "%s.f.fo[%i].fof",mName.c_str(),fo_i);return (const char*)buffer;}
	/*Function to be sampled*/
	DoubleID getFunction_Default(){char buffer[4096];sprintf_s (buffer, "%s.f.fd",mName.c_str());return (const char*)buffer;}
protected:
	Sampler(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SAMPLER_H__
