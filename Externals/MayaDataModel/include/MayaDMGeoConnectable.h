/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GEOCONNECTABLE_H__
#define __MayaDM_GEOCONNECTABLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
The geoConnectable node is obsolete.
It has been replaced by the geoConnector node. It is retained in version 2
only to allow version 1 files to load.  It will be removed in version 3.
Other than allowing files to load, it has no effect whatsoever.<p/>
*/
class GeoConnectable : public Shape
{
public:
public:
	GeoConnectable(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "geoConnectable"){}
	virtual ~GeoConnectable(){}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	void setConnectionsToMe(size_t ct_i,const MessageID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct[%i]\";\n",mName.c_str(),ct_i);}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	void setAuxiliariesOwned(const MessageID& ao){fprintf_s(mFile,"connectAttr \"");ao.write(mFile);fprintf_s(mFile,"\" \"%s.ao\";\n",mName.c_str());}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	void setVelocityValid(const BoolID& vv){fprintf_s(mFile,"connectAttr \"");vv.write(mFile);fprintf_s(mFile,"\" \"%s.vv\";\n",mName.c_str());}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	void setDoVelocity(const BoolID& dv){fprintf_s(mFile,"connectAttr \"");dv.write(mFile);fprintf_s(mFile,"\" \"%s.dv\";\n",mName.c_str());}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	void setPrevTime(const DoubleID& pt){fprintf_s(mFile,"connectAttr \"");pt.write(mFile);fprintf_s(mFile,"\" \"%s.pt\";\n",mName.c_str());}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	void setCachedPositions(const VectorArrayID& cpo){fprintf_s(mFile,"connectAttr \"");cpo.write(mFile);fprintf_s(mFile,"\" \"%s.cpo\";\n",mName.c_str());}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	void setCachedVelocities(const VectorArrayID& cve){fprintf_s(mFile,"connectAttr \"");cve.write(mFile);fprintf_s(mFile,"\" \"%s.cve\";\n",mName.c_str());}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	void setComponentPositions(size_t cpp_i,const BoolID& cpp){fprintf_s(mFile,"connectAttr \"");cpp.write(mFile);fprintf_s(mFile,"\" \"%s.cpp[%i]\";\n",mName.c_str(),cpp_i);}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	void setGroupId(size_t gri_i,const IntID& gri){fprintf_s(mFile,"connectAttr \"");gri.write(mFile);fprintf_s(mFile,"\" \"%s.gri[%i]\";\n",mName.c_str(),gri_i);}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	void setInputGeometryMsg(const MessageID& igm){fprintf_s(mFile,"connectAttr \"");igm.write(mFile);fprintf_s(mFile,"\" \"%s.igm\";\n",mName.c_str());}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	void setSurfaceGeometry(const GenericID& sge){fprintf_s(mFile,"connectAttr \"");sge.write(mFile);fprintf_s(mFile,"\" \"%s.sge\";\n",mName.c_str());}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	void setLocalSurfaceGeometry(const GenericID& lsg){fprintf_s(mFile,"connectAttr \"");lsg.write(mFile);fprintf_s(mFile,"\" \"%s.lsg\";\n",mName.c_str());}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	const MessageID& getConnectionsToMe(size_t ct_i){char buffer[4096];sprintf_s (buffer, "%s.ct[%i]",mName.c_str(),ct_i);return (const char*)buffer;}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	MessageID getAuxiliariesOwned(){char buffer[4096];sprintf_s (buffer, "%s.ao",mName.c_str());return (const char*)buffer;}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	BoolID getVelocityValid(){char buffer[4096];sprintf_s (buffer, "%s.vv",mName.c_str());return (const char*)buffer;}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	BoolID getDoVelocity(){char buffer[4096];sprintf_s (buffer, "%s.dv",mName.c_str());return (const char*)buffer;}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	DoubleID getPrevTime(){char buffer[4096];sprintf_s (buffer, "%s.pt",mName.c_str());return (const char*)buffer;}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	VectorArrayID getCachedPositions(){char buffer[4096];sprintf_s (buffer, "%s.cpo",mName.c_str());return (const char*)buffer;}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	VectorArrayID getCachedVelocities(){char buffer[4096];sprintf_s (buffer, "%s.cve",mName.c_str());return (const char*)buffer;}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	const BoolID& getComponentPositions(size_t cpp_i){char buffer[4096];sprintf_s (buffer, "%s.cpp[%i]",mName.c_str(),cpp_i);return (const char*)buffer;}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	const IntID& getGroupId(size_t gri_i){char buffer[4096];sprintf_s (buffer, "%s.gri[%i]",mName.c_str(),gri_i);return (const char*)buffer;}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	MessageID getInputGeometryMsg(){char buffer[4096];sprintf_s (buffer, "%s.igm",mName.c_str());return (const char*)buffer;}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	GenericID getSurfaceGeometry(){char buffer[4096];sprintf_s (buffer, "%s.sge",mName.c_str());return (const char*)buffer;}
	/*OBSOLETE NODE. THIS ATTRIBUTE HAS NO EFFECT.*/
	GenericID getLocalSurfaceGeometry(){char buffer[4096];sprintf_s (buffer, "%s.lsg",mName.c_str());return (const char*)buffer;}
protected:
	GeoConnectable(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GEOCONNECTABLE_H__
