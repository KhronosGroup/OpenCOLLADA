/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LEASTSQUARESMODIFIER_H__
#define __MayaDM_LEASTSQUARESMODIFIER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
The 'leastSquaresModifier' node modifies the control vertices
 of an input NURBS object such that the object passes through the
 XYZ position or gets as close as possible to the XYZ position
 of one or more specified point constraints. Only NURBS curves
 can be modified.
 <p/>
 For a NURBS curve, the i-th point constraint 'pc[i]' is specified
 by a 3D point in space ('pc[i].ppx', 'pc[i].ppy', 'pc[i].ppz'),
 a parameter space location 'pc[i].pcu' on the curve and  a weight
 'pc[i].wt'.
 <p/>
 For any given point constraint, only the control vertices on
 the curve which have a influence at the parameter space location
 are modified. The weight of the constraint determines how strong an
 influence the point constraint is. So, for two point constraints
 defined at the same parameter space location, the one with a
 greater weight will have more of an influence on the curve.
 <p/>
 The user may chooses to apply a transformation on the computed
 result using the attribute 'wto'.
 <p/>
 caution: In general, the curve cannot be modified always to
 passes through all the positions.
*/
class LeastSquaresModifier : public AbstractBaseCreate
{
public:
	/*Place holder housing an input NURBS object, constraints on the object and the modified NURBS object.*/
	struct AttributeCollection{
		matrix worldSpaceToObjectSpace;
		/*Place holder holding point constraints. A point constraint comprises of XYZ, UV, Wt information.*/
		struct PointConstraint{
			double3 pointPositionXYZ;
			double3 pointConstraintUVW;
			double pointWeight;
			void write(FILE* file) const
			{
				pointPositionXYZ.write(file);
				fprintf_s(file, " ");
				pointConstraintUVW.write(file);
				fprintf_s(file, " ");
				fprintf_s(file,"%f", pointWeight);
			}
		}* pointConstraint;
		void write(FILE* file) const
		{
			worldSpaceToObjectSpace.write(file);
			fprintf_s(file, " ");
			size_t size = sizeof(pointConstraint)/sizeof(PointConstraint);
			for(size_t i=0; i<size; ++i)
			{
				pointConstraint[i].write(file);
				fprintf_s(file, " ");
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
	/*Internal attribute to track  symbolic index corresponding to each valid constraint.*/
	struct PointSymbolicIndex{
	};
public:
	LeastSquaresModifier(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "leastSquaresModifier"){}
	virtual ~LeastSquaresModifier(){}
	/*Place holder housing an input NURBS object, constraints on the object and the modified NURBS object.*/
	void setAttributeCollection(const AttributeCollection& ac){fprintf_s(mFile, "setAttr \".ac\" ");ac.write(mFile);fprintf_s(mFile,";\n");}
	/*The input NURBS object to be modified.*/
	void setInputNurbsObject(const GenericID& ino){fprintf_s(mFile,"connectAttr \"");ino.write(mFile);fprintf_s(mFile,"\" \"%s.ac.ino\";\n",mName.c_str());}
	/*Transform the result with matrix.*/
	void setWorldSpaceToObjectSpace(const matrix& wto){if(wto == identity) return; fprintf_s(mFile, "setAttr \".ac.wto\" -type \"matrix\" ");wto.write(mFile);fprintf_s(mFile,";\n");}
	/*Transform the result with matrix.*/
	void setWorldSpaceToObjectSpace(const MatrixID& wto){fprintf_s(mFile,"connectAttr \"");wto.write(mFile);fprintf_s(mFile,"\" \"%s.ac.wto\";\n",mName.c_str());}
	/*Place holder holding point constraints. A point constraint comprises of XYZ, UV, Wt information.*/
	void setPointConstraint(size_t pc_i,const AttributeCollection::PointConstraint& pc){fprintf_s(mFile, "setAttr \".ac.pc[%i]\" ",pc_i);pc.write(mFile);fprintf_s(mFile,";\n");}
	/*Point constraint 3D XYZ location. The NURBS curve is modified to pass through this location.*/
	void setPointPositionXYZ(size_t pc_i,const double3& xyz){fprintf_s(mFile, "setAttr \".ac.pc[%i].xyz\" -type \"double3\" ",pc_i);xyz.write(mFile);fprintf_s(mFile,";\n");}
	/*Point constraint 3D XYZ location. The NURBS curve is modified to pass through this location.*/
	void setPointPositionXYZ(size_t pc_i,const Double3ID& xyz){fprintf_s(mFile,"connectAttr \"");xyz.write(mFile);fprintf_s(mFile,"\" \"%s.ac.pc[%i].xyz\";\n",mName.c_str(),pc_i);}
	/*Point constraint 3D X coordinate.*/
	void setPointPositionX(size_t pc_i,double ppx){if(ppx == 1) return; fprintf_s(mFile, "setAttr \".ac.pc[%i].xyz.ppx\" %f;\n", pc_i,ppx);}
	/*Point constraint 3D X coordinate.*/
	void setPointPositionX(size_t pc_i,const DoubleID& ppx){fprintf_s(mFile,"connectAttr \"");ppx.write(mFile);fprintf_s(mFile,"\" \"%s.ac.pc[%i].xyz.ppx\";\n",mName.c_str(),pc_i);}
	/*Point constraint 3D space Y coordinate.*/
	void setPointPositionY(size_t pc_i,double ppy){if(ppy == 1) return; fprintf_s(mFile, "setAttr \".ac.pc[%i].xyz.ppy\" %f;\n", pc_i,ppy);}
	/*Point constraint 3D space Y coordinate.*/
	void setPointPositionY(size_t pc_i,const DoubleID& ppy){fprintf_s(mFile,"connectAttr \"");ppy.write(mFile);fprintf_s(mFile,"\" \"%s.ac.pc[%i].xyz.ppy\";\n",mName.c_str(),pc_i);}
	/*Point constraint 3D space Z coordinate.*/
	void setPointPositionZ(size_t pc_i,double ppz){if(ppz == 1) return; fprintf_s(mFile, "setAttr \".ac.pc[%i].xyz.ppz\" %f;\n", pc_i,ppz);}
	/*Point constraint 3D space Z coordinate.*/
	void setPointPositionZ(size_t pc_i,const DoubleID& ppz){fprintf_s(mFile,"connectAttr \"");ppz.write(mFile);fprintf_s(mFile,"\" \"%s.ac.pc[%i].xyz.ppz\";\n",mName.c_str(),pc_i);}
	/*Point constraint parameter space location on input NURBS Object*/
	void setPointConstraintUVW(size_t pc_i,const double3& puv){fprintf_s(mFile, "setAttr \".ac.pc[%i].puv\" -type \"double3\" ",pc_i);puv.write(mFile);fprintf_s(mFile,";\n");}
	/*Point constraint parameter space location on input NURBS Object*/
	void setPointConstraintUVW(size_t pc_i,const Double3ID& puv){fprintf_s(mFile,"connectAttr \"");puv.write(mFile);fprintf_s(mFile,"\" \"%s.ac.pc[%i].puv\";\n",mName.c_str(),pc_i);}
	/*Point constraint u parameter space location. The control vertices around this location are modified.*/
	void setPointConstraintU(size_t pc_i,double pcu){if(pcu == -100000.0) return; fprintf_s(mFile, "setAttr \".ac.pc[%i].puv.pcu\" %f;\n", pc_i,pcu);}
	/*Point constraint u parameter space location. The control vertices around this location are modified.*/
	void setPointConstraintU(size_t pc_i,const DoubleID& pcu){fprintf_s(mFile,"connectAttr \"");pcu.write(mFile);fprintf_s(mFile,"\" \"%s.ac.pc[%i].puv.pcu\";\n",mName.c_str(),pc_i);}
	/*Point constraint v parameter space location. Applicable only if NURBS object is a surface.*/
	void setPointConstraintV(size_t pc_i,double pcv){if(pcv == -100000.0) return; fprintf_s(mFile, "setAttr \".ac.pc[%i].puv.pcv\" %f;\n", pc_i,pcv);}
	/*Point constraint v parameter space location. Applicable only if NURBS object is a surface.*/
	void setPointConstraintV(size_t pc_i,const DoubleID& pcv){fprintf_s(mFile,"connectAttr \"");pcv.write(mFile);fprintf_s(mFile,"\" \"%s.ac.pc[%i].puv.pcv\";\n",mName.c_str(),pc_i);}
	/*Point constraints w parameter space location. Not used.*/
	void setPointConstraintW(size_t pc_i,double pcw){if(pcw == -100000.0) return; fprintf_s(mFile, "setAttr \".ac.pc[%i].puv.pcw\" %f;\n", pc_i,pcw);}
	/*Point constraints w parameter space location. Not used.*/
	void setPointConstraintW(size_t pc_i,const DoubleID& pcw){fprintf_s(mFile,"connectAttr \"");pcw.write(mFile);fprintf_s(mFile,"\" \"%s.ac.pc[%i].puv.pcw\";\n",mName.c_str(),pc_i);}
	/*Point constraint weight. Determines how strong an influence the constraint has on the input NURBS object.*/
	void setPointWeight(size_t pc_i,double pw){if(pw == 1.0) return; fprintf_s(mFile, "setAttr \".ac.pc[%i].pw\" %f;\n", pc_i,pw);}
	/*Point constraint weight. Determines how strong an influence the constraint has on the input NURBS object.*/
	void setPointWeight(size_t pc_i,const DoubleID& pw){fprintf_s(mFile,"connectAttr \"");pw.write(mFile);fprintf_s(mFile,"\" \"%s.ac.pc[%i].pw\";\n",mName.c_str(),pc_i);}
	/*Output NURBS object which meets the given point constraints.*/
	void setOutputNurbsObject(const GenericID& ono){fprintf_s(mFile,"connectAttr \"");ono.write(mFile);fprintf_s(mFile,"\" \"%s.ac.ono\";\n",mName.c_str());}
	/*The input NURBS object to be modified.*/
	GenericID getInputNurbsObject(){char buffer[4096];sprintf_s (buffer, "%s.ac.ino",mName.c_str());return (const char*)buffer;}
	/*Transform the result with matrix.*/
	MatrixID getWorldSpaceToObjectSpace(){char buffer[4096];sprintf_s (buffer, "%s.ac.wto",mName.c_str());return (const char*)buffer;}
	/*Output NURBS object which meets the given point constraints.*/
	GenericID getOutputNurbsObject(){char buffer[4096];sprintf_s (buffer, "%s.ac.ono",mName.c_str());return (const char*)buffer;}
protected:
	LeastSquaresModifier(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LEASTSQUARESMODIFIER_H__
