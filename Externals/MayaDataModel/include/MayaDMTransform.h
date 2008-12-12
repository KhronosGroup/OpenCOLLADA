/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TRANSFORM_H__
#define __MayaDM_TRANSFORM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDagNode.h"
namespace MayaDM
{
/*
transform nodes are dagNodes that are used to group and transform
 other dagNodes. All dagNodes that are not transform nodes in Maya
 must exist as a child of some transform node.
 <p/>
 <H4>Transformation Matrix (DAG)</H4>
 transform nodes have many attributes that make up the final
 transformation matrix as represented by the matrix attribute.
 This breakdown provides animators fine control over the animation
 of these parameters. Therefore, it is necessary to describe the
 order in which these attributes are applied to build the final
 matrix attribute.
 <p/>
 Note: matrices are post-multiplied in Maya. For example, to transform
 a point p from object-space to world-space you would need to
 post-multiply by the worldMatrix. (p' = p * wm)
 <pre>
              -1                      -1
   matrix = SP * S * SH * SP * ST * RP * RA * R * RP * RT * T
 </pre>
 (where '*' denotes matrix multiplication and '-1' denotes matrix inversion'
 <pre>
   SP = |  1    0    0    0 |     ST = |  1    0    0    0 |
        |  0    1    0    0 |          |  0    1    0    0 |
        |  0    0    1    0 |          |  0    0    1    0 |
        | spx  spy  spz   1 |          | sptx spty sptz  1 |

   S  = |  sx   0    0    0 |     SH = |  1    0    0    0 |
        |  0    sy   0    0 |          | shxy  1    0    0 |
        |  0    0    sz   0 |          | shxz shyz  1    0 |
        |  0    0    0    1 |          |  0    0    0    1 |

   RP = |  1    0    0    0 |     RT = |  1    0    0    0 |
        |  0    1    0    0 |          |  0    1    0    0 |
        |  0    0    1    0 |          |  0    0    1    0 |
        | rpx  rpy  rpz   1 |          | rptx rpty rptz  1 |

   RA = AX * AY * AZ

   AX = |  1    0    0    0 |     AY = |  cy   0   -sy   0 |
        |  0    cx   sx   0 |          |  0    1    0    0 |
        |  0   -sx   cx   0 |          |  sy   0    cy   0 |
        |  0    0    0    1 |          |  0    0    0    1 |

   AZ = |  cz   sz   0    0 |     sx = sin(rax), cx = cos(rax)
        | -sz   cz   0    0 |     sy = sin(ray), cx = cos(ray)
        |  0    0    1    0 |     sz = sin(raz), cz = cos(raz)
        |  0    0    0    1 |

   Rotate:
                If the rotationInterpolation attribute specifies quaternion
                interpolation, use the following OpenMaya API calls to construct
                the matrix:
                        Mquaternion q( rx, ry, rz, rw )
                        R  = q.asMatrix()

                Otherwise, for Euler-angle rotation use:
                        R  = RX * RY * RZ  (Note: order is determined by rotateOrder)

                        RX = |  1    0    0    0 |     RY = |  cy   0   -sy   0 |
                                 |  0    cx   sx   0 |          |  0    1    0    0 |
                                 |  0   -sx   cx   0 |          |  sy   0    cy   0 |
                                 |  0    0    0    1 |          |  0    0    0    1 |

                        RZ = |  cz   sz   0    0 |     sx = sin(rx), cx = cos(rx)
                                 | -sz   cz   0    0 |     sy = sin(ry), cx = cos(ry)
                                 |  0    0    1    0 |     sz = sin(rz), cz = cos(rz)
                                 |  0    0    0    1 |

   T  = |  1    0    0    0 |
        |  0    1    0    0 |
        |  0    0    1    0 |
        |  tx   ty   tz   1 |
 </pre>
 <p/>
*/
class Transform : public DagNode
{
public:
	/*Enable translate minimum.*/
	struct MinTransLimitEnable{
		bool minTransXLimitEnable;
		bool minTransYLimitEnable;
		bool minTransZLimitEnable;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", minTransXLimitEnable);
			fprintf_s(file,"%i ", minTransYLimitEnable);
			fprintf_s(file,"%i", minTransZLimitEnable);
		}
	};
	/*Enable translate maximum.*/
	struct MaxTransLimitEnable{
		bool maxTransXLimitEnable;
		bool maxTransYLimitEnable;
		bool maxTransZLimitEnable;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", maxTransXLimitEnable);
			fprintf_s(file,"%i ", maxTransYLimitEnable);
			fprintf_s(file,"%i", maxTransZLimitEnable);
		}
	};
	/*Enable rotate minimum.*/
	struct MinRotLimitEnable{
		bool minRotXLimitEnable;
		bool minRotYLimitEnable;
		bool minRotZLimitEnable;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", minRotXLimitEnable);
			fprintf_s(file,"%i ", minRotYLimitEnable);
			fprintf_s(file,"%i", minRotZLimitEnable);
		}
	};
	/*Enable rotate maximum.*/
	struct MaxRotLimitEnable{
		bool maxRotXLimitEnable;
		bool maxRotYLimitEnable;
		bool maxRotZLimitEnable;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", maxRotXLimitEnable);
			fprintf_s(file,"%i ", maxRotYLimitEnable);
			fprintf_s(file,"%i", maxRotZLimitEnable);
		}
	};
	/*Enable scale minimum.*/
	struct MinScaleLimitEnable{
		bool minScaleXLimitEnable;
		bool minScaleYLimitEnable;
		bool minScaleZLimitEnable;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", minScaleXLimitEnable);
			fprintf_s(file,"%i ", minScaleYLimitEnable);
			fprintf_s(file,"%i", minScaleZLimitEnable);
		}
	};
	/*Enable scale maximum.*/
	struct MaxScaleLimitEnable{
		bool maxScaleXLimitEnable;
		bool maxScaleYLimitEnable;
		bool maxScaleZLimitEnable;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", maxScaleXLimitEnable);
			fprintf_s(file,"%i ", maxScaleYLimitEnable);
			fprintf_s(file,"%i", maxScaleZLimitEnable);
		}
	};
	/*This is a root of following mental ray attributes.*/
	struct MentalRayControls{
		bool miDeriveFromMaya;
		bool miHide;
		unsigned int miVisible;
		unsigned int miTrace;
		unsigned int miShadow;
		unsigned int miCaustic;
		unsigned int miGlobillum;
		bool miExportGeoShader;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", miDeriveFromMaya);
			fprintf_s(file,"%i ", miHide);
			fprintf_s(file,"%i ", miVisible);
			fprintf_s(file,"%i ", miTrace);
			fprintf_s(file,"%i ", miShadow);
			fprintf_s(file,"%i ", miCaustic);
			fprintf_s(file,"%i ", miGlobillum);
			fprintf_s(file,"%i ", miExportGeoShader);
		}
	};
public:
	Transform(FILE* file,const std::string& name,const std::string& parent=""):DagNode(file, name, parent, "transform"){}
	virtual ~Transform(){}
	/*Translation.*/
	void setTranslate(const double3& t){fprintf_s(mFile, "setAttr \".t\" -type \"double3\" ");t.write(mFile);fprintf_s(mFile,";\n");}
	/*Translation.*/
	void setTranslate(const Double3ID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*Translate X.*/
	void setTranslateX(double tx){if(tx == 0) return; fprintf_s(mFile, "setAttr \".t.tx\" %f;\n", tx);}
	/*Translate X.*/
	void setTranslateX(const DoubleID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.t.tx\";\n",mName.c_str());}
	/*Translate Y.*/
	void setTranslateY(double ty){if(ty == 0) return; fprintf_s(mFile, "setAttr \".t.ty\" %f;\n", ty);}
	/*Translate Y.*/
	void setTranslateY(const DoubleID& ty){fprintf_s(mFile,"connectAttr \"");ty.write(mFile);fprintf_s(mFile,"\" \"%s.t.ty\";\n",mName.c_str());}
	/*Translate Z.*/
	void setTranslateZ(double tz){if(tz == 0) return; fprintf_s(mFile, "setAttr \".t.tz\" %f;\n", tz);}
	/*Translate Z.*/
	void setTranslateZ(const DoubleID& tz){fprintf_s(mFile,"connectAttr \"");tz.write(mFile);fprintf_s(mFile,"\" \"%s.t.tz\";\n",mName.c_str());}
	/*Rotation.*/
	void setRotate(const double3& r){fprintf_s(mFile, "setAttr \".r\" -type \"double3\" ");r.write(mFile);fprintf_s(mFile,";\n");}
	/*Rotation.*/
	void setRotate(const Double3ID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Rotate X.*/
	void setRotateX(double rx){if(rx == 0) return; fprintf_s(mFile, "setAttr \".r.rx\" %f;\n", rx);}
	/*Rotate X.*/
	void setRotateX(const DoubleID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.r.rx\";\n",mName.c_str());}
	/*Rotate Y.*/
	void setRotateY(double ry){if(ry == 0) return; fprintf_s(mFile, "setAttr \".r.ry\" %f;\n", ry);}
	/*Rotate Y.*/
	void setRotateY(const DoubleID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.r.ry\";\n",mName.c_str());}
	/*Rotate Z.*/
	void setRotateZ(double rz){if(rz == 0) return; fprintf_s(mFile, "setAttr \".r.rz\" %f;\n", rz);}
	/*Rotate Z.*/
	void setRotateZ(const DoubleID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.r.rz\";\n",mName.c_str());}
	/*
	This attribute controls the order in which rx, ry, rz are applied
	in the transformation matrix. Valid values for this attribute are
	0=xyz, 1=yzx, 2=zxy, 3=xzy, 4=yxz, 5=zyx.
	*/
	void setRotateOrder(unsigned int ro){if(ro == 0) return; fprintf_s(mFile, "setAttr \".ro\" %i;\n", ro);}
	/*
	This attribute controls the order in which rx, ry, rz are applied
	in the transformation matrix. Valid values for this attribute are
	0=xyz, 1=yzx, 2=zxy, 3=xzy, 4=yxz, 5=zyx.
	*/
	void setRotateOrder(const UnsignedintID& ro){fprintf_s(mFile,"connectAttr \"");ro.write(mFile);fprintf_s(mFile,"\" \"%s.ro\";\n",mName.c_str());}
	/*Scale.*/
	void setScale(const double3& s){fprintf_s(mFile, "setAttr \".s\" -type \"double3\" ");s.write(mFile);fprintf_s(mFile,";\n");}
	/*Scale.*/
	void setScale(const Double3ID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*Scale X.*/
	void setScaleX(double sx){if(sx == 1.0) return; fprintf_s(mFile, "setAttr \".s.sx\" %f;\n", sx);}
	/*Scale X.*/
	void setScaleX(const DoubleID& sx){fprintf_s(mFile,"connectAttr \"");sx.write(mFile);fprintf_s(mFile,"\" \"%s.s.sx\";\n",mName.c_str());}
	/*Scale Y.*/
	void setScaleY(double sy){if(sy == 1.0) return; fprintf_s(mFile, "setAttr \".s.sy\" %f;\n", sy);}
	/*Scale Y.*/
	void setScaleY(const DoubleID& sy){fprintf_s(mFile,"connectAttr \"");sy.write(mFile);fprintf_s(mFile,"\" \"%s.s.sy\";\n",mName.c_str());}
	/*Scale Z.*/
	void setScaleZ(double sz){if(sz == 1.0) return; fprintf_s(mFile, "setAttr \".s.sz\" %f;\n", sz);}
	/*Scale Z.*/
	void setScaleZ(const DoubleID& sz){fprintf_s(mFile,"connectAttr \"");sz.write(mFile);fprintf_s(mFile,"\" \"%s.s.sz\";\n",mName.c_str());}
	/*Shear.*/
	void setShear(const double3& sh){fprintf_s(mFile, "setAttr \".sh\" -type \"double3\" ");sh.write(mFile);fprintf_s(mFile,";\n");}
	/*Shear.*/
	void setShear(const Double3ID& sh){fprintf_s(mFile,"connectAttr \"");sh.write(mFile);fprintf_s(mFile,"\" \"%s.sh\";\n",mName.c_str());}
	/*Shear XY.*/
	void setShearXY(double shxy){if(shxy == 0.0) return; fprintf_s(mFile, "setAttr \".sh.shxy\" %f;\n", shxy);}
	/*Shear XY.*/
	void setShearXY(const DoubleID& shxy){fprintf_s(mFile,"connectAttr \"");shxy.write(mFile);fprintf_s(mFile,"\" \"%s.sh.shxy\";\n",mName.c_str());}
	/*Shear XZ.*/
	void setShearXZ(double shxz){if(shxz == 0.0) return; fprintf_s(mFile, "setAttr \".sh.shxz\" %f;\n", shxz);}
	/*Shear XZ.*/
	void setShearXZ(const DoubleID& shxz){fprintf_s(mFile,"connectAttr \"");shxz.write(mFile);fprintf_s(mFile,"\" \"%s.sh.shxz\";\n",mName.c_str());}
	/*Shear YZ.*/
	void setShearYZ(double shyz){if(shyz == 0.0) return; fprintf_s(mFile, "setAttr \".sh.shyz\" %f;\n", shyz);}
	/*Shear YZ.*/
	void setShearYZ(const DoubleID& shyz){fprintf_s(mFile,"connectAttr \"");shyz.write(mFile);fprintf_s(mFile,"\" \"%s.sh.shyz\";\n",mName.c_str());}
	/*Point about which to rotate.*/
	void setRotatePivot(const double3& rp){fprintf_s(mFile, "setAttr \".rp\" -type \"double3\" ");rp.write(mFile);fprintf_s(mFile,";\n");}
	/*Point about which to rotate.*/
	void setRotatePivot(const Double3ID& rp){fprintf_s(mFile,"connectAttr \"");rp.write(mFile);fprintf_s(mFile,"\" \"%s.rp\";\n",mName.c_str());}
	/*Rotate pivot X.*/
	void setRotatePivotX(double rpx){if(rpx == 0) return; fprintf_s(mFile, "setAttr \".rp.rpx\" %f;\n", rpx);}
	/*Rotate pivot X.*/
	void setRotatePivotX(const DoubleID& rpx){fprintf_s(mFile,"connectAttr \"");rpx.write(mFile);fprintf_s(mFile,"\" \"%s.rp.rpx\";\n",mName.c_str());}
	/*Rotate pivot Y.*/
	void setRotatePivotY(double rpy){if(rpy == 0) return; fprintf_s(mFile, "setAttr \".rp.rpy\" %f;\n", rpy);}
	/*Rotate pivot Y.*/
	void setRotatePivotY(const DoubleID& rpy){fprintf_s(mFile,"connectAttr \"");rpy.write(mFile);fprintf_s(mFile,"\" \"%s.rp.rpy\";\n",mName.c_str());}
	/*Rotate pivot Z.*/
	void setRotatePivotZ(double rpz){if(rpz == 0) return; fprintf_s(mFile, "setAttr \".rp.rpz\" %f;\n", rpz);}
	/*Rotate pivot Z.*/
	void setRotatePivotZ(const DoubleID& rpz){fprintf_s(mFile,"connectAttr \"");rpz.write(mFile);fprintf_s(mFile,"\" \"%s.rp.rpz\";\n",mName.c_str());}
	/*
	Rotate pivot correction. Used when moving the rotate pivot point
	without affecting the overall transformation matrix.
	*/
	void setRotatePivotTranslate(const double3& rpt){fprintf_s(mFile, "setAttr \".rpt\" -type \"double3\" ");rpt.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Rotate pivot correction. Used when moving the rotate pivot point
	without affecting the overall transformation matrix.
	*/
	void setRotatePivotTranslate(const Double3ID& rpt){fprintf_s(mFile,"connectAttr \"");rpt.write(mFile);fprintf_s(mFile,"\" \"%s.rpt\";\n",mName.c_str());}
	/*Rotate translation X.*/
	void setRotatePivotTranslateX(double rptx){if(rptx == 0) return; fprintf_s(mFile, "setAttr \".rpt.rptx\" %f;\n", rptx);}
	/*Rotate translation X.*/
	void setRotatePivotTranslateX(const DoubleID& rptx){fprintf_s(mFile,"connectAttr \"");rptx.write(mFile);fprintf_s(mFile,"\" \"%s.rpt.rptx\";\n",mName.c_str());}
	/*Rotate translation Y.*/
	void setRotatePivotTranslateY(double rpty){if(rpty == 0) return; fprintf_s(mFile, "setAttr \".rpt.rpty\" %f;\n", rpty);}
	/*Rotate translation Y.*/
	void setRotatePivotTranslateY(const DoubleID& rpty){fprintf_s(mFile,"connectAttr \"");rpty.write(mFile);fprintf_s(mFile,"\" \"%s.rpt.rpty\";\n",mName.c_str());}
	/*Rotate translation Z.*/
	void setRotatePivotTranslateZ(double rptz){if(rptz == 0) return; fprintf_s(mFile, "setAttr \".rpt.rptz\" %f;\n", rptz);}
	/*Rotate translation Z.*/
	void setRotatePivotTranslateZ(const DoubleID& rptz){fprintf_s(mFile,"connectAttr \"");rptz.write(mFile);fprintf_s(mFile,"\" \"%s.rpt.rptz\";\n",mName.c_str());}
	/*Point around which to scale.*/
	void setScalePivot(const double3& sp){fprintf_s(mFile, "setAttr \".sp\" -type \"double3\" ");sp.write(mFile);fprintf_s(mFile,";\n");}
	/*Point around which to scale.*/
	void setScalePivot(const Double3ID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp\";\n",mName.c_str());}
	/*Scale pivot X.*/
	void setScalePivotX(double spx){if(spx == 0) return; fprintf_s(mFile, "setAttr \".sp.spx\" %f;\n", spx);}
	/*Scale pivot X.*/
	void setScalePivotX(const DoubleID& spx){fprintf_s(mFile,"connectAttr \"");spx.write(mFile);fprintf_s(mFile,"\" \"%s.sp.spx\";\n",mName.c_str());}
	/*Scale pivot Y.*/
	void setScalePivotY(double spy){if(spy == 0) return; fprintf_s(mFile, "setAttr \".sp.spy\" %f;\n", spy);}
	/*Scale pivot Y.*/
	void setScalePivotY(const DoubleID& spy){fprintf_s(mFile,"connectAttr \"");spy.write(mFile);fprintf_s(mFile,"\" \"%s.sp.spy\";\n",mName.c_str());}
	/*Scale pivot Z.*/
	void setScalePivotZ(double spz){if(spz == 0) return; fprintf_s(mFile, "setAttr \".sp.spz\" %f;\n", spz);}
	/*Scale pivot Z.*/
	void setScalePivotZ(const DoubleID& spz){fprintf_s(mFile,"connectAttr \"");spz.write(mFile);fprintf_s(mFile,"\" \"%s.sp.spz\";\n",mName.c_str());}
	/*
	Scale pivot correction. Used to moving the scale pivot point
	without affecting the overall transformation matrix.
	*/
	void setScalePivotTranslate(const double3& spt){fprintf_s(mFile, "setAttr \".spt\" -type \"double3\" ");spt.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Scale pivot correction. Used to moving the scale pivot point
	without affecting the overall transformation matrix.
	*/
	void setScalePivotTranslate(const Double3ID& spt){fprintf_s(mFile,"connectAttr \"");spt.write(mFile);fprintf_s(mFile,"\" \"%s.spt\";\n",mName.c_str());}
	/*Scale translation X.*/
	void setScalePivotTranslateX(double sptx){if(sptx == 0) return; fprintf_s(mFile, "setAttr \".spt.sptx\" %f;\n", sptx);}
	/*Scale translation X.*/
	void setScalePivotTranslateX(const DoubleID& sptx){fprintf_s(mFile,"connectAttr \"");sptx.write(mFile);fprintf_s(mFile,"\" \"%s.spt.sptx\";\n",mName.c_str());}
	/*Scale translation Y.*/
	void setScalePivotTranslateY(double spty){if(spty == 0) return; fprintf_s(mFile, "setAttr \".spt.spty\" %f;\n", spty);}
	/*Scale translation Y.*/
	void setScalePivotTranslateY(const DoubleID& spty){fprintf_s(mFile,"connectAttr \"");spty.write(mFile);fprintf_s(mFile,"\" \"%s.spt.spty\";\n",mName.c_str());}
	/*Scale translation Z.*/
	void setScalePivotTranslateZ(double sptz){if(sptz == 0) return; fprintf_s(mFile, "setAttr \".spt.sptz\" %f;\n", sptz);}
	/*Scale translation Z.*/
	void setScalePivotTranslateZ(const DoubleID& sptz){fprintf_s(mFile,"connectAttr \"");sptz.write(mFile);fprintf_s(mFile,"\" \"%s.spt.sptz\";\n",mName.c_str());}
	/*
	Extra rotation to adjust the local axis prior to applying the
	rotate attribute.
	*/
	void setRotateAxis(const double3& ra){fprintf_s(mFile, "setAttr \".ra\" -type \"double3\" ");ra.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Extra rotation to adjust the local axis prior to applying the
	rotate attribute.
	*/
	void setRotateAxis(const Double3ID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*Rotate axis X.*/
	void setRotateAxisX(double rax){if(rax == 0) return; fprintf_s(mFile, "setAttr \".ra.rax\" %f;\n", rax);}
	/*Rotate axis X.*/
	void setRotateAxisX(const DoubleID& rax){fprintf_s(mFile,"connectAttr \"");rax.write(mFile);fprintf_s(mFile,"\" \"%s.ra.rax\";\n",mName.c_str());}
	/*Rotate axis Y.*/
	void setRotateAxisY(double ray){if(ray == 0) return; fprintf_s(mFile, "setAttr \".ra.ray\" %f;\n", ray);}
	/*Rotate axis Y.*/
	void setRotateAxisY(const DoubleID& ray){fprintf_s(mFile,"connectAttr \"");ray.write(mFile);fprintf_s(mFile,"\" \"%s.ra.ray\";\n",mName.c_str());}
	/*Rotate axis Z.*/
	void setRotateAxisZ(double raz){if(raz == 0) return; fprintf_s(mFile, "setAttr \".ra.raz\" %f;\n", raz);}
	/*Rotate axis Z.*/
	void setRotateAxisZ(const DoubleID& raz){fprintf_s(mFile,"connectAttr \"");raz.write(mFile);fprintf_s(mFile,"\" \"%s.ra.raz\";\n",mName.c_str());}
	/*
	Attribute to extract the offset of the translation
	from the rotate pivot. The offset is in the same transformation
	space as the translate attribute which is parent-space.
	This value is typically used in expressions where it is subtracted
	from a position before setting the translation attribute. This causes
	the object to move so that the rotate pivot point is positioned
	at the desired position.
	*/
	void setTransMinusRotatePivot(const Double3ID& tmrp){fprintf_s(mFile,"connectAttr \"");tmrp.write(mFile);fprintf_s(mFile,"\" \"%s.tmrp\";\n",mName.c_str());}
	/*Translation minus rotate pivot X.*/
	void setTransMinusRotatePivotX(const DoubleID& tmrx){fprintf_s(mFile,"connectAttr \"");tmrx.write(mFile);fprintf_s(mFile,"\" \"%s.tmrp.tmrx\";\n",mName.c_str());}
	/*Translation minus rotate pivot Y.*/
	void setTransMinusRotatePivotY(const DoubleID& tmry){fprintf_s(mFile,"connectAttr \"");tmry.write(mFile);fprintf_s(mFile,"\" \"%s.tmrp.tmry\";\n",mName.c_str());}
	/*Translation minus rotate pivot Z.*/
	void setTransMinusRotatePivotZ(const DoubleID& tmrz){fprintf_s(mFile,"connectAttr \"");tmrz.write(mFile);fprintf_s(mFile,"\" \"%s.tmrp.tmrz\";\n",mName.c_str());}
	/*
	Translate minimum. Translation values less than this value
	will be clamped to this value.
	*/
	void setMinTransLimit(const double3& mntl){fprintf_s(mFile, "setAttr \".mntl\" -type \"double3\" ");mntl.write(mFile);fprintf_s(mFile,";\n");}
	/*Minimum translation X.*/
	void setMinTransXLimit(double mtxl){if(mtxl == 1) return; fprintf_s(mFile, "setAttr \".mntl.mtxl\" %f;\n", mtxl);}
	/*Minimum translation Y.*/
	void setMinTransYLimit(double mtyl){if(mtyl == 1) return; fprintf_s(mFile, "setAttr \".mntl.mtyl\" %f;\n", mtyl);}
	/*Minimum translation Z.*/
	void setMinTransZLimit(double mtzl){if(mtzl == 1) return; fprintf_s(mFile, "setAttr \".mntl.mtzl\" %f;\n", mtzl);}
	/*
	Translate maximum. Translation values greater than this value
	will be clamped to this value.
	*/
	void setMaxTransLimit(const double3& mxtl){fprintf_s(mFile, "setAttr \".mxtl\" -type \"double3\" ");mxtl.write(mFile);fprintf_s(mFile,";\n");}
	/*Maximum translation X.*/
	void setMaxTransXLimit(double xtxl){if(xtxl == 1) return; fprintf_s(mFile, "setAttr \".mxtl.xtxl\" %f;\n", xtxl);}
	/*Maximum translation Y.*/
	void setMaxTransYLimit(double xtyl){if(xtyl == 1) return; fprintf_s(mFile, "setAttr \".mxtl.xtyl\" %f;\n", xtyl);}
	/*Maximum translation Z.*/
	void setMaxTransZLimit(double xtzl){if(xtzl == 1) return; fprintf_s(mFile, "setAttr \".mxtl.xtzl\" %f;\n", xtzl);}
	/*Enable translate minimum.*/
	void setMinTransLimitEnable(const MinTransLimitEnable& mtle){fprintf_s(mFile, "setAttr \".mtle\" ");mtle.write(mFile);fprintf_s(mFile,";\n");}
	/*Enable translate minimum X.*/
	void setMinTransXLimitEnable(bool mtxe){if(mtxe == false) return; fprintf_s(mFile, "setAttr \".mtle.mtxe\" %i;\n", mtxe);}
	/*Enable translate minimum Y.*/
	void setMinTransYLimitEnable(bool mtye){if(mtye == false) return; fprintf_s(mFile, "setAttr \".mtle.mtye\" %i;\n", mtye);}
	/*Enable translate minimum Z.*/
	void setMinTransZLimitEnable(bool mtze){if(mtze == false) return; fprintf_s(mFile, "setAttr \".mtle.mtze\" %i;\n", mtze);}
	/*Enable translate maximum.*/
	void setMaxTransLimitEnable(const MaxTransLimitEnable& xtle){fprintf_s(mFile, "setAttr \".xtle\" ");xtle.write(mFile);fprintf_s(mFile,";\n");}
	/*Enable translate maximum X.*/
	void setMaxTransXLimitEnable(bool xtxe){if(xtxe == false) return; fprintf_s(mFile, "setAttr \".xtle.xtxe\" %i;\n", xtxe);}
	/*Enable translate maximum Y.*/
	void setMaxTransYLimitEnable(bool xtye){if(xtye == false) return; fprintf_s(mFile, "setAttr \".xtle.xtye\" %i;\n", xtye);}
	/*Enable translate maximum Z.*/
	void setMaxTransZLimitEnable(bool xtze){if(xtze == false) return; fprintf_s(mFile, "setAttr \".xtle.xtze\" %i;\n", xtze);}
	/*
	Rotate minimum. Rotation values less than this value
	will be clamped to this value.
	*/
	void setMinRotLimit(const double3& mnrl){fprintf_s(mFile, "setAttr \".mnrl\" -type \"double3\" ");mnrl.write(mFile);fprintf_s(mFile,";\n");}
	/*Minimum rotation X.*/
	void setMinRotXLimit(double mrxl){if(mrxl == 4) return; fprintf_s(mFile, "setAttr \".mnrl.mrxl\" %f;\n", mrxl);}
	/*Minimum rotation Y.*/
	void setMinRotYLimit(double mryl){if(mryl == 4) return; fprintf_s(mFile, "setAttr \".mnrl.mryl\" %f;\n", mryl);}
	/*Minimum rotation Z.*/
	void setMinRotZLimit(double mrzl){if(mrzl == 4) return; fprintf_s(mFile, "setAttr \".mnrl.mrzl\" %f;\n", mrzl);}
	/*
	Rotate maximum. Rotation values greater than this value
	will be clamped to this value.
	*/
	void setMaxRotLimit(const double3& mxrl){fprintf_s(mFile, "setAttr \".mxrl\" -type \"double3\" ");mxrl.write(mFile);fprintf_s(mFile,";\n");}
	/*Maximum rotation X.*/
	void setMaxRotXLimit(double xrxl){if(xrxl == 4) return; fprintf_s(mFile, "setAttr \".mxrl.xrxl\" %f;\n", xrxl);}
	/*Maximum rotation Y.*/
	void setMaxRotYLimit(double xryl){if(xryl == 4) return; fprintf_s(mFile, "setAttr \".mxrl.xryl\" %f;\n", xryl);}
	/*Maximum rotation Z.*/
	void setMaxRotZLimit(double xrzl){if(xrzl == 4) return; fprintf_s(mFile, "setAttr \".mxrl.xrzl\" %f;\n", xrzl);}
	/*Enable rotate minimum.*/
	void setMinRotLimitEnable(const MinRotLimitEnable& mrle){fprintf_s(mFile, "setAttr \".mrle\" ");mrle.write(mFile);fprintf_s(mFile,";\n");}
	/*Enable rotate minimum X.*/
	void setMinRotXLimitEnable(bool mrxe){if(mrxe == false) return; fprintf_s(mFile, "setAttr \".mrle.mrxe\" %i;\n", mrxe);}
	/*Enable rotate minimum Y.*/
	void setMinRotYLimitEnable(bool mrye){if(mrye == false) return; fprintf_s(mFile, "setAttr \".mrle.mrye\" %i;\n", mrye);}
	/*Enable rotate minimum Z.*/
	void setMinRotZLimitEnable(bool mrze){if(mrze == false) return; fprintf_s(mFile, "setAttr \".mrle.mrze\" %i;\n", mrze);}
	/*Enable rotate maximum.*/
	void setMaxRotLimitEnable(const MaxRotLimitEnable& xrle){fprintf_s(mFile, "setAttr \".xrle\" ");xrle.write(mFile);fprintf_s(mFile,";\n");}
	/*Enable rotate maximum X.*/
	void setMaxRotXLimitEnable(bool xrxe){if(xrxe == false) return; fprintf_s(mFile, "setAttr \".xrle.xrxe\" %i;\n", xrxe);}
	/*Enable rotate maximum Y.*/
	void setMaxRotYLimitEnable(bool xrye){if(xrye == false) return; fprintf_s(mFile, "setAttr \".xrle.xrye\" %i;\n", xrye);}
	/*Enable rotate maximum Z.*/
	void setMaxRotZLimitEnable(bool xrze){if(xrze == false) return; fprintf_s(mFile, "setAttr \".xrle.xrze\" %i;\n", xrze);}
	/*
	Scale minimum. Scale values less than this value
	will be clamped to this value.
	*/
	void setMinScaleLimit(const double3& mnsl){fprintf_s(mFile, "setAttr \".mnsl\" -type \"double3\" ");mnsl.write(mFile);fprintf_s(mFile,";\n");}
	/*Scale minimum X.*/
	void setMinScaleXLimit(double msxl){if(msxl == -1) return; fprintf_s(mFile, "setAttr \".mnsl.msxl\" %f;\n", msxl);}
	/*Scale minimum Y.*/
	void setMinScaleYLimit(double msyl){if(msyl == -1) return; fprintf_s(mFile, "setAttr \".mnsl.msyl\" %f;\n", msyl);}
	/*Scale minimum Z.*/
	void setMinScaleZLimit(double mszl){if(mszl == -1) return; fprintf_s(mFile, "setAttr \".mnsl.mszl\" %f;\n", mszl);}
	/*
	Scale maximum. Scale values greater than this value
	will be clamped to this value.
	*/
	void setMaxScaleLimit(const double3& mxsl){fprintf_s(mFile, "setAttr \".mxsl\" -type \"double3\" ");mxsl.write(mFile);fprintf_s(mFile,";\n");}
	/*Scale maximum X.*/
	void setMaxScaleXLimit(double xsxl){if(xsxl == 1) return; fprintf_s(mFile, "setAttr \".mxsl.xsxl\" %f;\n", xsxl);}
	/*Scale maximum Y.*/
	void setMaxScaleYLimit(double xsyl){if(xsyl == 1) return; fprintf_s(mFile, "setAttr \".mxsl.xsyl\" %f;\n", xsyl);}
	/*Scale maximum Z.*/
	void setMaxScaleZLimit(double xszl){if(xszl == 1) return; fprintf_s(mFile, "setAttr \".mxsl.xszl\" %f;\n", xszl);}
	/*Enable scale minimum.*/
	void setMinScaleLimitEnable(const MinScaleLimitEnable& msle){fprintf_s(mFile, "setAttr \".msle\" ");msle.write(mFile);fprintf_s(mFile,";\n");}
	/*Enable scale minimum X.*/
	void setMinScaleXLimitEnable(bool msxe){if(msxe == false) return; fprintf_s(mFile, "setAttr \".msle.msxe\" %i;\n", msxe);}
	/*Enable scale minimum Y.*/
	void setMinScaleYLimitEnable(bool msye){if(msye == false) return; fprintf_s(mFile, "setAttr \".msle.msye\" %i;\n", msye);}
	/*Enable scale minimum Z.*/
	void setMinScaleZLimitEnable(bool msze){if(msze == false) return; fprintf_s(mFile, "setAttr \".msle.msze\" %i;\n", msze);}
	/*Enable scale maximum.*/
	void setMaxScaleLimitEnable(const MaxScaleLimitEnable& xsle){fprintf_s(mFile, "setAttr \".xsle\" ");xsle.write(mFile);fprintf_s(mFile,";\n");}
	/*Enable scale maximum X.*/
	void setMaxScaleXLimitEnable(bool xsxe){if(xsxe == false) return; fprintf_s(mFile, "setAttr \".xsle.xsxe\" %i;\n", xsxe);}
	/*Enable scale maximum Y.*/
	void setMaxScaleYLimitEnable(bool xsye){if(xsye == false) return; fprintf_s(mFile, "setAttr \".xsle.xsye\" %i;\n", xsye);}
	/*Enable scale maximum Z.*/
	void setMaxScaleZLimitEnable(bool xsze){if(xsze == false) return; fprintf_s(mFile, "setAttr \".xsle.xsze\" %i;\n", xsze);}
	/*
	Local transformation matrix. Contains the same information as
	the matrix attribute on dagNode but it is stored in a format
	that can be interpolated easily.
	*/
	void setXformMatrix(const MatrixID& xm){fprintf_s(mFile,"connectAttr \"");xm.write(mFile);fprintf_s(mFile,"\" \"%s.xm\";\n",mName.c_str());}
	/*Selection handle position for this node in object-space coordinates.*/
	void setSelectHandle(const double3& hdl){fprintf_s(mFile, "setAttr \".hdl\" -type \"double3\" ");hdl.write(mFile);fprintf_s(mFile,";\n");}
	/*Selection handle position for this node in object-space coordinates.*/
	void setSelectHandle(const Double3ID& hdl){fprintf_s(mFile,"connectAttr \"");hdl.write(mFile);fprintf_s(mFile,"\" \"%s.hdl\";\n",mName.c_str());}
	/*Selection handle X.*/
	void setSelectHandleX(double hdlx){if(hdlx == 0) return; fprintf_s(mFile, "setAttr \".hdl.hdlx\" %f;\n", hdlx);}
	/*Selection handle X.*/
	void setSelectHandleX(const DoubleID& hdlx){fprintf_s(mFile,"connectAttr \"");hdlx.write(mFile);fprintf_s(mFile,"\" \"%s.hdl.hdlx\";\n",mName.c_str());}
	/*Selection handle X.*/
	void setSelectHandleY(double hdly){if(hdly == 0) return; fprintf_s(mFile, "setAttr \".hdl.hdly\" %f;\n", hdly);}
	/*Selection handle X.*/
	void setSelectHandleY(const DoubleID& hdly){fprintf_s(mFile,"connectAttr \"");hdly.write(mFile);fprintf_s(mFile,"\" \"%s.hdl.hdly\";\n",mName.c_str());}
	/*Selection handle Z.*/
	void setSelectHandleZ(double hdlz){if(hdlz == 0) return; fprintf_s(mFile, "setAttr \".hdl.hdlz\" %f;\n", hdlz);}
	/*Selection handle Z.*/
	void setSelectHandleZ(const DoubleID& hdlz){fprintf_s(mFile,"connectAttr \"");hdlz.write(mFile);fprintf_s(mFile,"\" \"%s.hdl.hdlz\";\n",mName.c_str());}
	/*
	Attribute that controls whether this transform inherits
	transformations from its parent transform. If this value is false
	then the transform will act as though it is in world-space. In other
	words, transformations to its parent will not affect the world-space
	position of this transform and the parentMatrix attribute on this
	transform will return the identity matrix.
	This is primarily used when grouping objects with their construction
	history to prevent double transformations on the output object.
	*/
	void setInheritsTransform(bool it){if(it == true) return; fprintf_s(mFile, "setAttr \".it\" %i;\n", it);}
	/*
	Attribute that controls whether this transform inherits
	transformations from its parent transform. If this value is false
	then the transform will act as though it is in world-space. In other
	words, transformations to its parent will not affect the world-space
	position of this transform and the parentMatrix attribute on this
	transform will return the identity matrix.
	This is primarily used when grouping objects with their construction
	history to prevent double transformations on the output object.
	*/
	void setInheritsTransform(const BoolID& it){fprintf_s(mFile,"connectAttr \"");it.write(mFile);fprintf_s(mFile,"\" \"%s.it\";\n",mName.c_str());}
	/*
	Boolean indicating whether the selection handle for this
	transform should be displayed.
	*/
	void setDisplayHandle(bool dh){if(dh == false) return; fprintf_s(mFile, "setAttr \".dh\" %i;\n", dh);}
	/*
	Boolean indicating whether the selection handle for this
	transform should be displayed.
	*/
	void setDisplayHandle(const BoolID& dh){fprintf_s(mFile,"connectAttr \"");dh.write(mFile);fprintf_s(mFile,"\" \"%s.dh\";\n",mName.c_str());}
	/*
	Boolean indicating whether the scale pivot point for this
	transform should be displayed.
	*/
	void setDisplayScalePivot(bool dsp){if(dsp == false) return; fprintf_s(mFile, "setAttr \".dsp\" %i;\n", dsp);}
	/*
	Boolean indicating whether the scale pivot point for this
	transform should be displayed.
	*/
	void setDisplayScalePivot(const BoolID& dsp){fprintf_s(mFile,"connectAttr \"");dsp.write(mFile);fprintf_s(mFile,"\" \"%s.dsp\";\n",mName.c_str());}
	/*
	Boolean indicating whether the rotate pivot point for this
	transform should be displayed.
	*/
	void setDisplayRotatePivot(bool drp){if(drp == false) return; fprintf_s(mFile, "setAttr \".drp\" %i;\n", drp);}
	/*
	Boolean indicating whether the rotate pivot point for this
	transform should be displayed.
	*/
	void setDisplayRotatePivot(const BoolID& drp){fprintf_s(mFile,"connectAttr \"");drp.write(mFile);fprintf_s(mFile,"\" \"%s.drp\";\n",mName.c_str());}
	/*
	Boolean indicating whether the local rotation axis for this
	transform should be displayed.
	*/
	void setDisplayLocalAxis(bool dla){if(dla == false) return; fprintf_s(mFile, "setAttr \".dla\" %i;\n", dla);}
	/*
	Boolean indicating whether the local rotation axis for this
	transform should be displayed.
	*/
	void setDisplayLocalAxis(const BoolID& dla){fprintf_s(mFile,"connectAttr \"");dla.write(mFile);fprintf_s(mFile,"\" \"%s.dla\";\n",mName.c_str());}
	/*
	This attribute indicates the default manipulator that should
	be shown when this object is selected and the show manipulator
	tool is active. Valid values are
	0=no default manipulator, 1=translation, 2=rotation, 3=scale.
	4=transform, 5=global default, 6=smart, 7=specified
	*/
	void setShowManipDefault(unsigned int smd){if(smd == 0) return; fprintf_s(mFile, "setAttr \".smd\" %i;\n", smd);}
	/*
	This attribute indicates the default manipulator that should
	be shown when this object is selected and the show manipulator
	tool is active. Valid values are
	0=no default manipulator, 1=translation, 2=rotation, 3=scale.
	4=transform, 5=global default, 6=smart, 7=specified
	*/
	void setShowManipDefault(const UnsignedintID& smd){fprintf_s(mFile,"connectAttr \"");smd.write(mFile);fprintf_s(mFile,"\" \"%s.smd\";\n",mName.c_str());}
	/*Quaternion-based rotation (q=Xi+Yj+Zk+W).*/
	void setRotateQuaternion(const double4& rq){fprintf_s(mFile, "setAttr \".rq\" -type \"double4\" ");rq.write(mFile);fprintf_s(mFile,";\n");}
	/*Quaternion-based rotation (q=Xi+Yj+Zk+W).*/
	void setRotateQuaternion(const Double4ID& rq){fprintf_s(mFile,"connectAttr \"");rq.write(mFile);fprintf_s(mFile,"\" \"%s.rq\";\n",mName.c_str());}
	/*
	X channel of quaternion-based rotation (q=Xi+Yj+Zk+W).
	This attribute is only valid if the object is driven by quaternion animation curves.
	It is not used to control the object's rotation, but can be used to query the rotation in quaternion space.
	To use this attribute, connect it to rotateX's associated paramCurve's ".rawValue" attribute.
	*/
	void setRotateQuaternionX(double rqx){if(rqx == 0.0) return; fprintf_s(mFile, "setAttr \".rq.rqx\" %f;\n", rqx);}
	/*
	X channel of quaternion-based rotation (q=Xi+Yj+Zk+W).
	This attribute is only valid if the object is driven by quaternion animation curves.
	It is not used to control the object's rotation, but can be used to query the rotation in quaternion space.
	To use this attribute, connect it to rotateX's associated paramCurve's ".rawValue" attribute.
	*/
	void setRotateQuaternionX(const DoubleID& rqx){fprintf_s(mFile,"connectAttr \"");rqx.write(mFile);fprintf_s(mFile,"\" \"%s.rq.rqx\";\n",mName.c_str());}
	/*
	Y channel of quaternion-based rotation (q=Xi+Yj+Zk+W).
	This attribute is only valid if the object is driven by quaternion animation curves.
	It is not used to control the object's rotation, but can be used to query the rotation in quaternion space.
	To use this attribute, connect it to rotateY's associated paramCurve's ".rawValue" attribute.
	*/
	void setRotateQuaternionY(double rqy){if(rqy == 0.0) return; fprintf_s(mFile, "setAttr \".rq.rqy\" %f;\n", rqy);}
	/*
	Y channel of quaternion-based rotation (q=Xi+Yj+Zk+W).
	This attribute is only valid if the object is driven by quaternion animation curves.
	It is not used to control the object's rotation, but can be used to query the rotation in quaternion space.
	To use this attribute, connect it to rotateY's associated paramCurve's ".rawValue" attribute.
	*/
	void setRotateQuaternionY(const DoubleID& rqy){fprintf_s(mFile,"connectAttr \"");rqy.write(mFile);fprintf_s(mFile,"\" \"%s.rq.rqy\";\n",mName.c_str());}
	/*
	Z channel of quaternion-based rotation (q=Xi+Yj+Zk+W).
	This attribute is only valid if the object is driven by quaternion animation curves.
	It is not used to control the object's rotation, but can be used to query the rotation in quaternion space.
	To use this attribute, connect it to rotateZ's associated paramCurves ".rawValue" attribute.
	*/
	void setRotateQuaternionZ(double rqz){if(rqz == 0.0) return; fprintf_s(mFile, "setAttr \".rq.rqz\" %f;\n", rqz);}
	/*
	Z channel of quaternion-based rotation (q=Xi+Yj+Zk+W).
	This attribute is only valid if the object is driven by quaternion animation curves.
	It is not used to control the object's rotation, but can be used to query the rotation in quaternion space.
	To use this attribute, connect it to rotateZ's associated paramCurves ".rawValue" attribute.
	*/
	void setRotateQuaternionZ(const DoubleID& rqz){fprintf_s(mFile,"connectAttr \"");rqz.write(mFile);fprintf_s(mFile,"\" \"%s.rq.rqz\";\n",mName.c_str());}
	/*
	W channel of quaternion-based rotation (q=Xi+Yj+Zk+W).
	This attribute is only valid if the object is driven by quaternion animation curves.
	To use this attribute, connect it to one is the rotation animCurve's ".quaternionW" attributes.
	*/
	void setRotateQuaternionW(double rqw){if(rqw == 0.0) return; fprintf_s(mFile, "setAttr \".rq.rqw\" %f;\n", rqw);}
	/*
	W channel of quaternion-based rotation (q=Xi+Yj+Zk+W).
	This attribute is only valid if the object is driven by quaternion animation curves.
	To use this attribute, connect it to one is the rotation animCurve's ".quaternionW" attributes.
	*/
	void setRotateQuaternionW(const DoubleID& rqw){fprintf_s(mFile,"connectAttr \"");rqw.write(mFile);fprintf_s(mFile,"\" \"%s.rq.rqw\";\n",mName.c_str());}
	/*
	This attribute specifies the type of rotation data used when
	computing the transformation matrix. Valid values are:
	0=none (independent Euler-angle rotation values), 1=euler
	(synchronized Euler-angle curves), 2=quaternion (synchronized
	quaternion curves).
	To use this attribute, connect it to one is the rotation animCurve's ".rotationInterpolation" attributes.
	*/
	void setRotationInterpolation(const UnsignedintID& roi){fprintf_s(mFile,"connectAttr \"");roi.write(mFile);fprintf_s(mFile,"\" \"%s.roi\";\n",mName.c_str());}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControls& mrc){fprintf_s(mFile, "setAttr \".mrc\" ");mrc.write(mFile);fprintf_s(mFile,";\n");}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControlsID& mrc){fprintf_s(mFile,"connectAttr \"");mrc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc\";\n",mName.c_str());}
	/*
	If enabled the mental ray 'instance' flags will be derived
	from Maya attributes and internal settings, otherwise the
	mental ray attributes will be used to determine the flags.
	*/
	void setMiDeriveFromMaya(bool dfm){if(dfm == true) return; fprintf_s(mFile, "setAttr \".mrc.dfm\" %i;\n", dfm);}
	/*
	If enabled the mental ray 'instance' flags will be derived
	from Maya attributes and internal settings, otherwise the
	mental ray attributes will be used to determine the flags.
	*/
	void setMiDeriveFromMaya(const BoolID& dfm){fprintf_s(mFile,"connectAttr \"");dfm.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.dfm\";\n",mName.c_str());}
	/*
	Control the mental ray 'hide' instance flag (hide the instance during rendering).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	void setMiHide(bool hde){if(hde == false) return; fprintf_s(mFile, "setAttr \".mrc.hde\" %i;\n", hde);}
	/*
	Control the mental ray 'hide' instance flag (hide the instance during rendering).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	void setMiHide(const BoolID& hde){fprintf_s(mFile,"connectAttr \"");hde.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.hde\";\n",mName.c_str());}
	/*
	Control the mental ray 'visible' instance flag (primary visibility).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	void setMiVisible(unsigned int vsb){if(vsb == 2) return; fprintf_s(mFile, "setAttr \".mrc.vsb\" %i;\n", vsb);}
	/*
	Control the mental ray 'visible' instance flag (primary visibility).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	void setMiVisible(const UnsignedintID& vsb){fprintf_s(mFile,"connectAttr \"");vsb.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.vsb\";\n",mName.c_str());}
	/*
	Control the mental ray 'trace' instance flag (secondary rays, like
	reflection, refraction, final gathering).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	void setMiTrace(unsigned int trc){if(trc == 2) return; fprintf_s(mFile, "setAttr \".mrc.trc\" %i;\n", trc);}
	/*
	Control the mental ray 'trace' instance flag (secondary rays, like
	reflection, refraction, final gathering).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	void setMiTrace(const UnsignedintID& trc){fprintf_s(mFile,"connectAttr \"");trc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.trc\";\n",mName.c_str());}
	/*
	Control the mental ray 'shadow' instance flag (shadow casting).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	void setMiShadow(unsigned int shd){if(shd == 2) return; fprintf_s(mFile, "setAttr \".mrc.shd\" %i;\n", shd);}
	/*
	Control the mental ray 'shadow' instance flag (shadow casting).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	void setMiShadow(const UnsignedintID& shd){fprintf_s(mFile,"connectAttr \"");shd.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.shd\";\n",mName.c_str());}
	/*
	Control the mental ray 'caustic' instance mode (caustic flags).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	void setMiCaustic(unsigned int cst){if(cst == 5) return; fprintf_s(mFile, "setAttr \".mrc.cst\" %i;\n", cst);}
	/*
	Control the mental ray 'caustic' instance mode (caustic flags).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	void setMiCaustic(const UnsignedintID& cst){fprintf_s(mFile,"connectAttr \"");cst.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.cst\";\n",mName.c_str());}
	/*
	Control the mental ray 'global illumination' instance mode (globillum flags).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	void setMiGlobillum(unsigned int glb){if(glb == 5) return; fprintf_s(mFile, "setAttr \".mrc.glb\" %i;\n", glb);}
	/*
	Control the mental ray 'global illumination' instance mode (globillum flags).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	void setMiGlobillum(const UnsignedintID& glb){fprintf_s(mFile,"connectAttr \"");glb.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.glb\";\n",mName.c_str());}
	/*Respect the mental ray custom geometry shader connected to 'miGeoShader' for translation.*/
	void setMiExportGeoShader(bool mieg){if(mieg == false) return; fprintf_s(mFile, "setAttr \".mrc.mieg\" %i;\n", mieg);}
	/*Respect the mental ray custom geometry shader connected to 'miGeoShader' for translation.*/
	void setMiExportGeoShader(const BoolID& mieg){fprintf_s(mFile,"connectAttr \"");mieg.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mieg\";\n",mName.c_str());}
	/*Port to connect custom mental ray node of type geometry shader.*/
	void setMiGeoShader(const GenerictypeddataID& migs){fprintf_s(mFile,"connectAttr \"");migs.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.migs\";\n",mName.c_str());}
	/*Translation.*/
	Double3ID getTranslate(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*Translate X.*/
	DoubleID getTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.t.tx",mName.c_str());return (const char*)buffer;}
	/*Translate Y.*/
	DoubleID getTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.t.ty",mName.c_str());return (const char*)buffer;}
	/*Translate Z.*/
	DoubleID getTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.t.tz",mName.c_str());return (const char*)buffer;}
	/*Rotation.*/
	Double3ID getRotate(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Rotate X.*/
	DoubleID getRotateX(){char buffer[4096];sprintf_s (buffer, "%s.r.rx",mName.c_str());return (const char*)buffer;}
	/*Rotate Y.*/
	DoubleID getRotateY(){char buffer[4096];sprintf_s (buffer, "%s.r.ry",mName.c_str());return (const char*)buffer;}
	/*Rotate Z.*/
	DoubleID getRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.r.rz",mName.c_str());return (const char*)buffer;}
	/*
	This attribute controls the order in which rx, ry, rz are applied
	in the transformation matrix. Valid values for this attribute are
	0=xyz, 1=yzx, 2=zxy, 3=xzy, 4=yxz, 5=zyx.
	*/
	UnsignedintID getRotateOrder(){char buffer[4096];sprintf_s (buffer, "%s.ro",mName.c_str());return (const char*)buffer;}
	/*Scale.*/
	Double3ID getScale(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*Scale X.*/
	DoubleID getScaleX(){char buffer[4096];sprintf_s (buffer, "%s.s.sx",mName.c_str());return (const char*)buffer;}
	/*Scale Y.*/
	DoubleID getScaleY(){char buffer[4096];sprintf_s (buffer, "%s.s.sy",mName.c_str());return (const char*)buffer;}
	/*Scale Z.*/
	DoubleID getScaleZ(){char buffer[4096];sprintf_s (buffer, "%s.s.sz",mName.c_str());return (const char*)buffer;}
	/*Shear.*/
	Double3ID getShear(){char buffer[4096];sprintf_s (buffer, "%s.sh",mName.c_str());return (const char*)buffer;}
	/*Shear XY.*/
	DoubleID getShearXY(){char buffer[4096];sprintf_s (buffer, "%s.sh.shxy",mName.c_str());return (const char*)buffer;}
	/*Shear XZ.*/
	DoubleID getShearXZ(){char buffer[4096];sprintf_s (buffer, "%s.sh.shxz",mName.c_str());return (const char*)buffer;}
	/*Shear YZ.*/
	DoubleID getShearYZ(){char buffer[4096];sprintf_s (buffer, "%s.sh.shyz",mName.c_str());return (const char*)buffer;}
	/*Point about which to rotate.*/
	Double3ID getRotatePivot(){char buffer[4096];sprintf_s (buffer, "%s.rp",mName.c_str());return (const char*)buffer;}
	/*Rotate pivot X.*/
	DoubleID getRotatePivotX(){char buffer[4096];sprintf_s (buffer, "%s.rp.rpx",mName.c_str());return (const char*)buffer;}
	/*Rotate pivot Y.*/
	DoubleID getRotatePivotY(){char buffer[4096];sprintf_s (buffer, "%s.rp.rpy",mName.c_str());return (const char*)buffer;}
	/*Rotate pivot Z.*/
	DoubleID getRotatePivotZ(){char buffer[4096];sprintf_s (buffer, "%s.rp.rpz",mName.c_str());return (const char*)buffer;}
	/*
	Rotate pivot correction. Used when moving the rotate pivot point
	without affecting the overall transformation matrix.
	*/
	Double3ID getRotatePivotTranslate(){char buffer[4096];sprintf_s (buffer, "%s.rpt",mName.c_str());return (const char*)buffer;}
	/*Rotate translation X.*/
	DoubleID getRotatePivotTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.rpt.rptx",mName.c_str());return (const char*)buffer;}
	/*Rotate translation Y.*/
	DoubleID getRotatePivotTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.rpt.rpty",mName.c_str());return (const char*)buffer;}
	/*Rotate translation Z.*/
	DoubleID getRotatePivotTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.rpt.rptz",mName.c_str());return (const char*)buffer;}
	/*Point around which to scale.*/
	Double3ID getScalePivot(){char buffer[4096];sprintf_s (buffer, "%s.sp",mName.c_str());return (const char*)buffer;}
	/*Scale pivot X.*/
	DoubleID getScalePivotX(){char buffer[4096];sprintf_s (buffer, "%s.sp.spx",mName.c_str());return (const char*)buffer;}
	/*Scale pivot Y.*/
	DoubleID getScalePivotY(){char buffer[4096];sprintf_s (buffer, "%s.sp.spy",mName.c_str());return (const char*)buffer;}
	/*Scale pivot Z.*/
	DoubleID getScalePivotZ(){char buffer[4096];sprintf_s (buffer, "%s.sp.spz",mName.c_str());return (const char*)buffer;}
	/*
	Scale pivot correction. Used to moving the scale pivot point
	without affecting the overall transformation matrix.
	*/
	Double3ID getScalePivotTranslate(){char buffer[4096];sprintf_s (buffer, "%s.spt",mName.c_str());return (const char*)buffer;}
	/*Scale translation X.*/
	DoubleID getScalePivotTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.spt.sptx",mName.c_str());return (const char*)buffer;}
	/*Scale translation Y.*/
	DoubleID getScalePivotTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.spt.spty",mName.c_str());return (const char*)buffer;}
	/*Scale translation Z.*/
	DoubleID getScalePivotTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.spt.sptz",mName.c_str());return (const char*)buffer;}
	/*
	Extra rotation to adjust the local axis prior to applying the
	rotate attribute.
	*/
	Double3ID getRotateAxis(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*Rotate axis X.*/
	DoubleID getRotateAxisX(){char buffer[4096];sprintf_s (buffer, "%s.ra.rax",mName.c_str());return (const char*)buffer;}
	/*Rotate axis Y.*/
	DoubleID getRotateAxisY(){char buffer[4096];sprintf_s (buffer, "%s.ra.ray",mName.c_str());return (const char*)buffer;}
	/*Rotate axis Z.*/
	DoubleID getRotateAxisZ(){char buffer[4096];sprintf_s (buffer, "%s.ra.raz",mName.c_str());return (const char*)buffer;}
	/*
	Attribute to extract the offset of the translation
	from the rotate pivot. The offset is in the same transformation
	space as the translate attribute which is parent-space.
	This value is typically used in expressions where it is subtracted
	from a position before setting the translation attribute. This causes
	the object to move so that the rotate pivot point is positioned
	at the desired position.
	*/
	Double3ID getTransMinusRotatePivot(){char buffer[4096];sprintf_s (buffer, "%s.tmrp",mName.c_str());return (const char*)buffer;}
	/*Translation minus rotate pivot X.*/
	DoubleID getTransMinusRotatePivotX(){char buffer[4096];sprintf_s (buffer, "%s.tmrp.tmrx",mName.c_str());return (const char*)buffer;}
	/*Translation minus rotate pivot Y.*/
	DoubleID getTransMinusRotatePivotY(){char buffer[4096];sprintf_s (buffer, "%s.tmrp.tmry",mName.c_str());return (const char*)buffer;}
	/*Translation minus rotate pivot Z.*/
	DoubleID getTransMinusRotatePivotZ(){char buffer[4096];sprintf_s (buffer, "%s.tmrp.tmrz",mName.c_str());return (const char*)buffer;}
	/*
	Local transformation matrix. Contains the same information as
	the matrix attribute on dagNode but it is stored in a format
	that can be interpolated easily.
	*/
	MatrixID getXformMatrix(){char buffer[4096];sprintf_s (buffer, "%s.xm",mName.c_str());return (const char*)buffer;}
	/*Selection handle position for this node in object-space coordinates.*/
	Double3ID getSelectHandle(){char buffer[4096];sprintf_s (buffer, "%s.hdl",mName.c_str());return (const char*)buffer;}
	/*Selection handle X.*/
	DoubleID getSelectHandleX(){char buffer[4096];sprintf_s (buffer, "%s.hdl.hdlx",mName.c_str());return (const char*)buffer;}
	/*Selection handle X.*/
	DoubleID getSelectHandleY(){char buffer[4096];sprintf_s (buffer, "%s.hdl.hdly",mName.c_str());return (const char*)buffer;}
	/*Selection handle Z.*/
	DoubleID getSelectHandleZ(){char buffer[4096];sprintf_s (buffer, "%s.hdl.hdlz",mName.c_str());return (const char*)buffer;}
	/*
	Attribute that controls whether this transform inherits
	transformations from its parent transform. If this value is false
	then the transform will act as though it is in world-space. In other
	words, transformations to its parent will not affect the world-space
	position of this transform and the parentMatrix attribute on this
	transform will return the identity matrix.
	This is primarily used when grouping objects with their construction
	history to prevent double transformations on the output object.
	*/
	BoolID getInheritsTransform(){char buffer[4096];sprintf_s (buffer, "%s.it",mName.c_str());return (const char*)buffer;}
	/*
	Boolean indicating whether the selection handle for this
	transform should be displayed.
	*/
	BoolID getDisplayHandle(){char buffer[4096];sprintf_s (buffer, "%s.dh",mName.c_str());return (const char*)buffer;}
	/*
	Boolean indicating whether the scale pivot point for this
	transform should be displayed.
	*/
	BoolID getDisplayScalePivot(){char buffer[4096];sprintf_s (buffer, "%s.dsp",mName.c_str());return (const char*)buffer;}
	/*
	Boolean indicating whether the rotate pivot point for this
	transform should be displayed.
	*/
	BoolID getDisplayRotatePivot(){char buffer[4096];sprintf_s (buffer, "%s.drp",mName.c_str());return (const char*)buffer;}
	/*
	Boolean indicating whether the local rotation axis for this
	transform should be displayed.
	*/
	BoolID getDisplayLocalAxis(){char buffer[4096];sprintf_s (buffer, "%s.dla",mName.c_str());return (const char*)buffer;}
	/*
	This attribute indicates the default manipulator that should
	be shown when this object is selected and the show manipulator
	tool is active. Valid values are
	0=no default manipulator, 1=translation, 2=rotation, 3=scale.
	4=transform, 5=global default, 6=smart, 7=specified
	*/
	UnsignedintID getShowManipDefault(){char buffer[4096];sprintf_s (buffer, "%s.smd",mName.c_str());return (const char*)buffer;}
	/*Quaternion-based rotation (q=Xi+Yj+Zk+W).*/
	Double4ID getRotateQuaternion(){char buffer[4096];sprintf_s (buffer, "%s.rq",mName.c_str());return (const char*)buffer;}
	/*
	X channel of quaternion-based rotation (q=Xi+Yj+Zk+W).
	This attribute is only valid if the object is driven by quaternion animation curves.
	It is not used to control the object's rotation, but can be used to query the rotation in quaternion space.
	To use this attribute, connect it to rotateX's associated paramCurve's ".rawValue" attribute.
	*/
	DoubleID getRotateQuaternionX(){char buffer[4096];sprintf_s (buffer, "%s.rq.rqx",mName.c_str());return (const char*)buffer;}
	/*
	Y channel of quaternion-based rotation (q=Xi+Yj+Zk+W).
	This attribute is only valid if the object is driven by quaternion animation curves.
	It is not used to control the object's rotation, but can be used to query the rotation in quaternion space.
	To use this attribute, connect it to rotateY's associated paramCurve's ".rawValue" attribute.
	*/
	DoubleID getRotateQuaternionY(){char buffer[4096];sprintf_s (buffer, "%s.rq.rqy",mName.c_str());return (const char*)buffer;}
	/*
	Z channel of quaternion-based rotation (q=Xi+Yj+Zk+W).
	This attribute is only valid if the object is driven by quaternion animation curves.
	It is not used to control the object's rotation, but can be used to query the rotation in quaternion space.
	To use this attribute, connect it to rotateZ's associated paramCurves ".rawValue" attribute.
	*/
	DoubleID getRotateQuaternionZ(){char buffer[4096];sprintf_s (buffer, "%s.rq.rqz",mName.c_str());return (const char*)buffer;}
	/*
	W channel of quaternion-based rotation (q=Xi+Yj+Zk+W).
	This attribute is only valid if the object is driven by quaternion animation curves.
	To use this attribute, connect it to one is the rotation animCurve's ".quaternionW" attributes.
	*/
	DoubleID getRotateQuaternionW(){char buffer[4096];sprintf_s (buffer, "%s.rq.rqw",mName.c_str());return (const char*)buffer;}
	/*
	This attribute specifies the type of rotation data used when
	computing the transformation matrix. Valid values are:
	0=none (independent Euler-angle rotation values), 1=euler
	(synchronized Euler-angle curves), 2=quaternion (synchronized
	quaternion curves).
	To use this attribute, connect it to one is the rotation animCurve's ".rotationInterpolation" attributes.
	*/
	UnsignedintID getRotationInterpolation(){char buffer[4096];sprintf_s (buffer, "%s.roi",mName.c_str());return (const char*)buffer;}
	/*This is a root of following mental ray attributes.*/
	MentalRayControlsID getMentalRayControls(){char buffer[4096];sprintf_s (buffer, "%s.mrc",mName.c_str());return (const char*)buffer;}
	/*
	If enabled the mental ray 'instance' flags will be derived
	from Maya attributes and internal settings, otherwise the
	mental ray attributes will be used to determine the flags.
	*/
	BoolID getMiDeriveFromMaya(){char buffer[4096];sprintf_s (buffer, "%s.mrc.dfm",mName.c_str());return (const char*)buffer;}
	/*
	Control the mental ray 'hide' instance flag (hide the instance during rendering).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	BoolID getMiHide(){char buffer[4096];sprintf_s (buffer, "%s.mrc.hde",mName.c_str());return (const char*)buffer;}
	/*
	Control the mental ray 'visible' instance flag (primary visibility).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	UnsignedintID getMiVisible(){char buffer[4096];sprintf_s (buffer, "%s.mrc.vsb",mName.c_str());return (const char*)buffer;}
	/*
	Control the mental ray 'trace' instance flag (secondary rays, like
	reflection, refraction, final gathering).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	UnsignedintID getMiTrace(){char buffer[4096];sprintf_s (buffer, "%s.mrc.trc",mName.c_str());return (const char*)buffer;}
	/*
	Control the mental ray 'shadow' instance flag (shadow casting).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	UnsignedintID getMiShadow(){char buffer[4096];sprintf_s (buffer, "%s.mrc.shd",mName.c_str());return (const char*)buffer;}
	/*
	Control the mental ray 'caustic' instance mode (caustic flags).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	UnsignedintID getMiCaustic(){char buffer[4096];sprintf_s (buffer, "%s.mrc.cst",mName.c_str());return (const char*)buffer;}
	/*
	Control the mental ray 'global illumination' instance mode (globillum flags).
	Only respected if <b>miDeriveFromMaya</b> if off.
	*/
	UnsignedintID getMiGlobillum(){char buffer[4096];sprintf_s (buffer, "%s.mrc.glb",mName.c_str());return (const char*)buffer;}
	/*Respect the mental ray custom geometry shader connected to 'miGeoShader' for translation.*/
	BoolID getMiExportGeoShader(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mieg",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type geometry shader.*/
	GenerictypeddataID getMiGeoShader(){char buffer[4096];sprintf_s (buffer, "%s.mrc.migs",mName.c_str());return (const char*)buffer;}
protected:
	Transform(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DagNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TRANSFORM_H__
