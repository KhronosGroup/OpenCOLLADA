/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ROUNDCONSTANTRADIUS_H__
#define __MayaDM_ROUNDCONSTANTRADIUS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
This node generates the surfaces for the "roundConstantRadius" operation.
        It is strongly suggested that you use the "roundConstantRadius"
        command to set up a round dependency node since many of the
  attributes are interrelated.
 <p/>
  This node generates constant radius NURBS fillets and NURBS
  corner surfaces for matching edge pairs on NURBS surfaces.  An
  edge pair is a matching pair of surface isoparms or trim edges.
 <p/>
  A simple example of an edge pair is an edge of a NURBS cube,
  where two faces of the cube meet.  This node generates a NURBS
  fillet at the edge and trims back the faces.
 <p/>
  Another example is a NURBS cylinder with a planar trim surface cap.
  This node will create a NURBS fillet where the cap meets the
  the cylinder and will trim back the cap and the cylinder.
 <p/>
  Another example involves all 12 edges of a NURBS cube.  NURBS fillets
  are created where any face meets another face.  NURBS corners are
  created whenever 3 edges meet at a corner.
 <p/>
        This node has three main parts: a list of input surfaces,
        a list of edge pairs and a list of radius values.
 <ul>
 <li> The list of input surfaces is a list
        of all unique surfaces that are involved in this round operation.
        For example, if all four edges of a face of a cube are rounded
        then the face only appears in the input surface list once.</li>
 <li> The list of edge pairs stores the "topology" of the round
 operation.  Each edge pair consists of a "sideA" and a "sideB".
 The attribute inputCurveA is the curve on sideA (which can be
 made up of more than one curve).
 The attribute inputCurveB is the curve on sideB (which can be
 made up of more than one curve).
 For each input curve, there is a corresponding surface index,
 called inSurfIdxA and inSurfIdxB.  This refers to a position
 in the input surface list.</li>
 <li> The list of radius values defines the radius for each
 edge pair.  This attribute must be the same size as the edge attribute.
 .radius[0] defines the radius to be used by .edge[0].</li>
 </ul>
 For example, one edge of a cube (involving two faces of the cube)
 is rounded to produce a circular fillet along the edge.
        In this case, the input surface list will have two surfaces.
        There will be only one edge pair, which has a single input curve on
 sideA and a single input curve on sideB.  There will only be one entry
 in each of inSurfIdxA and inSurfIdxB to indicate which of the
 surfaces in the input surface list the input curve is from.
 <p/>
 Examples:
 <br/><code>
        getAttr -size roundConstantRadius1.inputSurface; ---> returns how many unique surface are in this round operation
<br/>    getAttr -size roundConstantRadius1.edge; ---> returns how many edges are in this round operation
<br/>  getAttr -size roundConstantRadius1.edge[0].inputCurveA; ---> returns how many curves make up sideA of the first edge
<br/>  getAttr -size roundConstantRadius1.edge[0].inputCurveB; ---> returns how many curves make up sideB of the first edge
<br/>  getAttr roundConstantRadius1.edge[0].inSurfIdxA[0]; ---> returns an index into the surface list that the first curve on sideA is from.  eg. if "2" is returned, then roundConstantRadius1.surface[2] is the corresponding surface.
<br/>    getAttr roundConstantRadius1.radius[0]; ---> returns the radius value used when creating a circular fillet for the first edge.
 </code><br/>
*/
class RoundConstantRadius : public AbstractBaseCreate
{
public:
	/*List of edge pairs.*/
	struct Edge{
		nurbsCurve* inputCurveA;
		nurbsCurve* inputCurveB;
		int* inSurfIdxA;
		int* inSurfIdxB;
		bool edgeValid;
		void write(FILE* file) const
		{
			size_t size = sizeof(inputCurveA)/sizeof(nurbsCurve);
			for(size_t i=0; i<size; ++i)
			{
				inputCurveA[i].write(file);
				fprintf_s(file, " ");
				if(i+1<size) fprintf_s(file," ");
			}
			size = sizeof(inputCurveB)/sizeof(nurbsCurve);
			for(size_t i=0; i<size; ++i)
			{
				inputCurveB[i].write(file);
				fprintf_s(file, " ");
				if(i+1<size) fprintf_s(file," ");
			}
			size = sizeof(inSurfIdxA)/sizeof(int);
			for(size_t i=0; i<size; ++i)
			{
				fprintf_s(file,"%i ", inSurfIdxA[i]);
				if(i+1<size) fprintf_s(file," ");
			}
			size = sizeof(inSurfIdxB)/sizeof(int);
			for(size_t i=0; i<size; ++i)
			{
				fprintf_s(file,"%i ", inSurfIdxB[i]);
				if(i+1<size) fprintf_s(file," ");
			}
			fprintf_s(file,"%i", edgeValid);
		}
	};
public:
	RoundConstantRadius(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "roundConstantRadius"){}
	virtual ~RoundConstantRadius(){}
	/*List of unique input surfaces.*/
	void setInputSurface(size_t is_i,const nurbsSurface& is){fprintf_s(mFile, "setAttr \".is[%i]\" -type \"nurbsSurface\" ",is_i);is.write(mFile);fprintf_s(mFile,";\n");}
	/*List of unique input surfaces.*/
	void setInputSurface(size_t is_i,const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is[%i]\";\n",mName.c_str(),is_i);}
	/*
	Radius of fillet along edge.  The number of radius values must
	match the number of items in the edge attribute.
	*/
	void setRadius(size_t r_i,double r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r[%i]\" %f;\n", r_i,r);}
	/*
	Radius of fillet along edge.  The number of radius values must
	match the number of items in the edge attribute.
	*/
	void setRadius(size_t r_i,const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r[%i]\";\n",mName.c_str(),r_i);}
	/*List of edge pairs.*/
	void setEdge(size_t e_i,const Edge& e){fprintf_s(mFile, "setAttr \".e[%i]\" ",e_i);e.write(mFile);fprintf_s(mFile,";\n");}
	/*List of input curves on side A of this edge*/
	void setInputCurveA(size_t e_i,size_t ica_i,const nurbsCurve& ica){fprintf_s(mFile, "setAttr \".e[%i].ica[%i]\" -type \"nurbsCurve\" ",e_i,ica_i);ica.write(mFile);fprintf_s(mFile,";\n");}
	/*List of input curves on side A of this edge*/
	void setInputCurveA(size_t e_i,size_t ica_i,const NurbsCurveID& ica){fprintf_s(mFile,"connectAttr \"");ica.write(mFile);fprintf_s(mFile,"\" \"%s.e[%i].ica[%i]\";\n",mName.c_str(),e_i,ica_i);}
	/*List of input curves on side B of this edge*/
	void setInputCurveB(size_t e_i,size_t icb_i,const nurbsCurve& icb){fprintf_s(mFile, "setAttr \".e[%i].icb[%i]\" -type \"nurbsCurve\" ",e_i,icb_i);icb.write(mFile);fprintf_s(mFile,";\n");}
	/*List of input curves on side B of this edge*/
	void setInputCurveB(size_t e_i,size_t icb_i,const NurbsCurveID& icb){fprintf_s(mFile,"connectAttr \"");icb.write(mFile);fprintf_s(mFile,"\" \"%s.e[%i].icb[%i]\";\n",mName.c_str(),e_i,icb_i);}
	/*Index of each surface that each curve on side A is from.*/
	void setInSurfIdxA(size_t e_i,size_t isa_i,int isa){if(isa == 123456) return; fprintf_s(mFile, "setAttr \".e[%i].isa[%i]\" %i;\n", e_i,isa_i,isa);}
	/*Index of each surface that each curve on side B is from.*/
	void setInSurfIdxB(size_t e_i,size_t isb_i,int isb){if(isb == 123456) return; fprintf_s(mFile, "setAttr \".e[%i].isb[%i]\" %i;\n", e_i,isb_i,isb);}
	/*
	True means that this edge is valid.  Invalid means that this
	edge is ignored completely. Note: This flag is not stored.
	*/
	void setEdgeValid(size_t e_i,bool ev){if(ev == 1) return; fprintf_s(mFile, "setAttr \".e[%i].ev\" %i;\n", e_i,ev);}
	/*The tolerance with which to trim.*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*The tolerance with which to trim.*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*
	List of status values that indicate whether or not a
	circular fillet was successfully created for a particular edge.
	The number of status values is the same as the number of edge pairs.
	-2 means the fillet failed on trim.
	-1 means the fillet failed on creation.
	0 means the fillet has not been attempted yet.
	1 means the fillet was successfully created.
	2 means the fillet is being computed
	*/
	void setFilletStatus(size_t fis_i,const ShortID& fis){fprintf_s(mFile,"connectAttr \"");fis.write(mFile);fprintf_s(mFile,"\" \"%s.fis[%i]\";\n",mName.c_str(),fis_i);}
	/*List of surfaces that are the trimmed original surfaces*/
	void setOriginalSurface(size_t os_i,const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os[%i]\";\n",mName.c_str(),os_i);}
	/*List of new fillet surfaces created by this operation*/
	void setFilletSurface(size_t fs_i,const NurbsSurfaceID& fs){fprintf_s(mFile,"connectAttr \"");fs.write(mFile);fprintf_s(mFile,"\" \"%s.fs[%i]\";\n",mName.c_str(),fs_i);}
	/*List of new corner surfaces created by this operation*/
	void setCornerSurface(size_t cs_i,const NurbsSurfaceID& cs){fprintf_s(mFile,"connectAttr \"");cs.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i]\";\n",mName.c_str(),cs_i);}
	/*List of unique input surfaces.*/
	const NurbsSurfaceID& getInputSurface(size_t is_i){char buffer[4096];sprintf_s (buffer, "%s.is[%i]",mName.c_str(),is_i);return (const char*)buffer;}
	/*
	Radius of fillet along edge.  The number of radius values must
	match the number of items in the edge attribute.
	*/
	const DoubleID& getRadius(size_t r_i){char buffer[4096];sprintf_s (buffer, "%s.r[%i]",mName.c_str(),r_i);return (const char*)buffer;}
	/*List of input curves on side A of this edge*/
	const NurbsCurveID& getInputCurveA(size_t e_i,size_t ica_i){char buffer[4096];sprintf_s (buffer, "%s.e[%i].ica[%i]",mName.c_str(),e_i,ica_i);return (const char*)buffer;}
	/*List of input curves on side B of this edge*/
	const NurbsCurveID& getInputCurveB(size_t e_i,size_t icb_i){char buffer[4096];sprintf_s (buffer, "%s.e[%i].icb[%i]",mName.c_str(),e_i,icb_i);return (const char*)buffer;}
	/*The tolerance with which to trim.*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*
	List of status values that indicate whether or not a
	circular fillet was successfully created for a particular edge.
	The number of status values is the same as the number of edge pairs.
	-2 means the fillet failed on trim.
	-1 means the fillet failed on creation.
	0 means the fillet has not been attempted yet.
	1 means the fillet was successfully created.
	2 means the fillet is being computed
	*/
	const ShortID& getFilletStatus(size_t fis_i){char buffer[4096];sprintf_s (buffer, "%s.fis[%i]",mName.c_str(),fis_i);return (const char*)buffer;}
	/*List of surfaces that are the trimmed original surfaces*/
	const NurbsSurfaceID& getOriginalSurface(size_t os_i){char buffer[4096];sprintf_s (buffer, "%s.os[%i]",mName.c_str(),os_i);return (const char*)buffer;}
	/*List of new fillet surfaces created by this operation*/
	const NurbsSurfaceID& getFilletSurface(size_t fs_i){char buffer[4096];sprintf_s (buffer, "%s.fs[%i]",mName.c_str(),fs_i);return (const char*)buffer;}
	/*List of new corner surfaces created by this operation*/
	const NurbsSurfaceID& getCornerSurface(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i]",mName.c_str(),cs_i);return (const char*)buffer;}
protected:
	RoundConstantRadius(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ROUNDCONSTANTRADIUS_H__
