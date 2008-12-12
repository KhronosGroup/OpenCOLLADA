/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NRIGID_H__
#define __MayaDM_NRIGID_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMNParticle.h"
namespace MayaDM
{
/*
<p><pre> The rigid node implements a non-deformable dynamic object.
</pre></p>
*/
class NRigid : public NParticle
{
public:
public:
	NRigid(FILE* file,const std::string& name,const std::string& parent=""):NParticle(file, name, parent, "nRigid"){}
	virtual ~NRigid(){}
	/*Interactive display of internal solver info.*/
	void setSolverDisplay(unsigned int svds){if(svds == 0) return; fprintf_s(mFile, "setAttr \".svds\" %i;\n", svds);}
	/*Interactive display of internal solver info.*/
	void setSolverDisplay(const UnsignedintID& svds){fprintf_s(mFile,"connectAttr \"");svds.write(mFile);fprintf_s(mFile,"\" \"%s.svds\";\n",mName.c_str());}
	/*Interactive display of internal solver info.*/
	UnsignedintID getSolverDisplay(){char buffer[4096];sprintf_s (buffer, "%s.svds",mName.c_str());return (const char*)buffer;}
protected:
	NRigid(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):NParticle(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NRIGID_H__
