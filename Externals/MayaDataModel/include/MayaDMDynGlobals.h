/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DYNGLOBALS_H__
#define __MayaDM_DYNGLOBALS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>    The dynGlobals node allows editing and file storage of system-wide
    values for dynamics, such as oversampling.
</pre></p>
*/
class DynGlobals : public DependNode
{
public:
public:
	DynGlobals(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "dynGlobals"){}
	virtual ~DynGlobals(){}
	/*
	This is the oversample value for dynamics simulation.
	A value of 0 or 1 indicates no oversampling.
	A value of greater than 1 will cause Maya to take that
	number of sub-steps for each complete frame.
	*/
	void setOverSamples(int os){if(os == 1) return; fprintf_s(mFile, "setAttr \".os\" %i;\n", os);}
	/*
	This is the oversample value for dynamics simulation.
	A value of 0 or 1 indicates no oversampling.
	A value of greater than 1 will cause Maya to take that
	number of sub-steps for each complete frame.
	*/
	void setOverSamples(const IntID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*
	This is the actual oversampling value that is used.  It
	is used to convert the value of "overSamples" into a value
	that will divide the time into an integer number of "ticks".
	A tick is the smallest unit of time, and we can not make
	the oversampling try to divide into smaller units, so we
	convert into the closest possible value that will give
	whole tick values.  This value should not be explicitly
	set.  It derives its value from the "overSamples"
	attribute.  Setting this value directly can result in
	the strange behaviour that it is intended to avoid.
	*/
	void setInternalOverSamples(const IntID& ios){fprintf_s(mFile,"connectAttr \"");ios.write(mFile);fprintf_s(mFile,"\" \"%s.ios\";\n",mName.c_str());}
	/*
	Setting this attribute to true tells Maya to use cached particle data files.
	Setting this attribute does not create the cache.
	Setting this attribute to false tells Maya to ignore cache files,
	but it does not delete those files.
	*/
	void setUseParticleDiskCache(bool upd){if(upd == 0) return; fprintf_s(mFile, "setAttr \".upd\" %i;\n", upd);}
	/*
	Setting this attribute to true tells Maya to use cached particle data files.
	Setting this attribute does not create the cache.
	Setting this attribute to false tells Maya to ignore cache files,
	but it does not delete those files.
	*/
	void setUseParticleDiskCache(const BoolID& upd){fprintf_s(mFile,"connectAttr \"");upd.write(mFile);fprintf_s(mFile,"\" \"%s.upd\";\n",mName.c_str());}
	/*
	Directory for files used for particle render cache. This directory is
	always relative to the particle data directory of the current
	workspace.  It is used only
	for the render cache (pdc files).  If you set this value and
	then save cache files, those files will be sent to this
	directory, and then Maya will read them from there when rendering.
	*/
	void setCacheDirectory(const string& cd){if(cd == "NULL") return; fprintf_s(mFile, "setAttr \".cd\" -type \"string\" ");cd.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Directory for files used for particle render cache. This directory is
	always relative to the particle data directory of the current
	workspace.  It is used only
	for the render cache (pdc files).  If you set this value and
	then save cache files, those files will be sent to this
	directory, and then Maya will read them from there when rendering.
	*/
	void setCacheDirectory(const StringID& cd){fprintf_s(mFile,"connectAttr \"");cd.write(mFile);fprintf_s(mFile,"\" \"%s.cd\";\n",mName.c_str());}
	/*
	This attribute records the minimum frame for the last particle
	render cache you have created (corresponds to the -mnf argument in
	the dynExport command).  This does not in any way guarantee that
	the cache is still valid or that the files still exist.  It just
	records what was the last cache you wrote out.  If you have not
	moved/removed the files or changed something affecting the particles,
	the cache will still be valid.
	This attribute is set by the command that does the caching.
	It is here only to display useful information.
	Setting this attribute has no effect whatever.
	*/
	void setMinFrameCached(int mnf){if(mnf == 0) return; fprintf_s(mFile, "setAttr \".mnf\" %i;\n", mnf);}
	/*
	This attribute records the minimum frame for the last particle
	render cache you have created (corresponds to the -mnf argument in
	the dynExport command).  This does not in any way guarantee that
	the cache is still valid or that the files still exist.  It just
	records what was the last cache you wrote out.  If you have not
	moved/removed the files or changed something affecting the particles,
	the cache will still be valid.
	This attribute is set by the command that does the caching.
	It is here only to display useful information.
	Setting this attribute has no effect whatever.
	*/
	void setMinFrameCached(const IntID& mnf){fprintf_s(mFile,"connectAttr \"");mnf.write(mFile);fprintf_s(mFile,"\" \"%s.mnf\";\n",mName.c_str());}
	/*
	This attribute records the maximum frame for the last particle
	render cache you have created (corresponds to the -mxf argument in
	the dynExport command).  This does not in any way guarantee that
	the cache is still valid or that the files still exist.  It just
	records what was the last cache you wrote out.  If you have not
	moved/removed the files or changed something affecting the particles,
	the cache will still be valid.
	This attribute is set by the command that does the caching.
	It is here only to display useful information.
	Setting this attribute has no effect whatever.
	*/
	void setMaxFrameCached(int mxf){if(mxf == 0) return; fprintf_s(mFile, "setAttr \".mxf\" %i;\n", mxf);}
	/*
	This attribute records the maximum frame for the last particle
	render cache you have created (corresponds to the -mxf argument in
	the dynExport command).  This does not in any way guarantee that
	the cache is still valid or that the files still exist.  It just
	records what was the last cache you wrote out.  If you have not
	moved/removed the files or changed something affecting the particles,
	the cache will still be valid.
	This attribute is set by the command that does the caching.
	It is here only to display useful information.
	Setting this attribute has no effect whatever.
	*/
	void setMaxFrameCached(const IntID& mxf){fprintf_s(mFile,"connectAttr \"");mxf.write(mFile);fprintf_s(mFile,"\" \"%s.mxf\";\n",mName.c_str());}
	/*
	This attribute controls the display of confirm dialogs for paths.
	It should not be set by the user.
	*/
	void setConfirmedPath(const string& cnp){if(cnp == "NULL") return; fprintf_s(mFile, "setAttr \".cnp\" -type \"string\" ");cnp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This attribute controls the display of confirm dialogs for paths.
	It should not be set by the user.
	*/
	void setConfirmSceneName(const string& csn){if(csn == "NULL") return; fprintf_s(mFile, "setAttr \".csn\" -type \"string\" ");csn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is the oversample value for dynamics simulation.
	A value of 0 or 1 indicates no oversampling.
	A value of greater than 1 will cause Maya to take that
	number of sub-steps for each complete frame.
	*/
	IntID getOverSamples(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
	/*
	This is the actual oversampling value that is used.  It
	is used to convert the value of "overSamples" into a value
	that will divide the time into an integer number of "ticks".
	A tick is the smallest unit of time, and we can not make
	the oversampling try to divide into smaller units, so we
	convert into the closest possible value that will give
	whole tick values.  This value should not be explicitly
	set.  It derives its value from the "overSamples"
	attribute.  Setting this value directly can result in
	the strange behaviour that it is intended to avoid.
	*/
	IntID getInternalOverSamples(){char buffer[4096];sprintf_s (buffer, "%s.ios",mName.c_str());return (const char*)buffer;}
	/*
	Setting this attribute to true tells Maya to use cached particle data files.
	Setting this attribute does not create the cache.
	Setting this attribute to false tells Maya to ignore cache files,
	but it does not delete those files.
	*/
	BoolID getUseParticleDiskCache(){char buffer[4096];sprintf_s (buffer, "%s.upd",mName.c_str());return (const char*)buffer;}
	/*
	Directory for files used for particle render cache. This directory is
	always relative to the particle data directory of the current
	workspace.  It is used only
	for the render cache (pdc files).  If you set this value and
	then save cache files, those files will be sent to this
	directory, and then Maya will read them from there when rendering.
	*/
	StringID getCacheDirectory(){char buffer[4096];sprintf_s (buffer, "%s.cd",mName.c_str());return (const char*)buffer;}
	/*
	This attribute records the minimum frame for the last particle
	render cache you have created (corresponds to the -mnf argument in
	the dynExport command).  This does not in any way guarantee that
	the cache is still valid or that the files still exist.  It just
	records what was the last cache you wrote out.  If you have not
	moved/removed the files or changed something affecting the particles,
	the cache will still be valid.
	This attribute is set by the command that does the caching.
	It is here only to display useful information.
	Setting this attribute has no effect whatever.
	*/
	IntID getMinFrameCached(){char buffer[4096];sprintf_s (buffer, "%s.mnf",mName.c_str());return (const char*)buffer;}
	/*
	This attribute records the maximum frame for the last particle
	render cache you have created (corresponds to the -mxf argument in
	the dynExport command).  This does not in any way guarantee that
	the cache is still valid or that the files still exist.  It just
	records what was the last cache you wrote out.  If you have not
	moved/removed the files or changed something affecting the particles,
	the cache will still be valid.
	This attribute is set by the command that does the caching.
	It is here only to display useful information.
	Setting this attribute has no effect whatever.
	*/
	IntID getMaxFrameCached(){char buffer[4096];sprintf_s (buffer, "%s.mxf",mName.c_str());return (const char*)buffer;}
protected:
	DynGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DYNGLOBALS_H__
