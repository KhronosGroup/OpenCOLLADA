/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FLUIDSHAPE_H__
#define __MayaDM_FLUIDSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSurfaceShape.h"
namespace MayaDM
{
/*
<p><pre>
 Manage a fluid shape

</pre></p>
*/
class FluidShape : public SurfaceShape
{
public:
	/*
	Resolution of the grid
	Users should be aware that changing this attribute will affect the
	density currently contained in the grid.
	*/
	struct Resolution{
		int resolutionW;
		int resolutionH;
		int resolutionD;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", resolutionW);
			fprintf_s(file,"%i ", resolutionH);
			fprintf_s(file,"%i", resolutionD);
		}
	};
	/*
	Dimensions of the grid. The dimensions are used internally by the
	solver and should not be changed unless you really know what you're
	doing. Use the scale on the transform to increase the size of the grid
	instead.
	*/
	struct Dimensions{
		double dimensionsW;
		double dimensionsH;
		double dimensionsD;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", dimensionsW);
			fprintf_s(file,"%f ", dimensionsH);
			fprintf_s(file,"%f", dimensionsD);
		}
	};
	/*
	This is the compound that holds all of the default attribute for the
	fields to connect to.
	*/
	struct FieldData{
		void write(FILE* file) const
		{
		}
	};
	/*
	Parent multi-attribute to store the field's function attribute
	connections. (No longer used)
	*/
	struct FieldList{
		/*
		Function attribute for field computation. No longer used - see the
		fieldData attributes and the inputForce for how a field is connected
		to a fluidShape
		*/
		struct FieldFunction{
			/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
			struct FieldFunction_Inmap{
				short fieldFunction_InmapTo;
				short fieldFunction_InmapFrom;
				void write(FILE* file) const
				{
					fprintf_s(file,"%i ", fieldFunction_InmapTo);
					fprintf_s(file,"%i", fieldFunction_InmapFrom);
				}
			}* fieldFunction_Inmap;
			/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
			struct FieldFunction_Outmap{
				short fieldFunction_OutmapTo;
				short fieldFunction_OutmapFrom;
				void write(FILE* file) const
				{
					fprintf_s(file,"%i ", fieldFunction_OutmapTo);
					fprintf_s(file,"%i", fieldFunction_OutmapFrom);
				}
			}* fieldFunction_Outmap;
			void write(FILE* file) const
			{
				size_t size = sizeof(fieldFunction_Inmap)/sizeof(FieldFunction_Inmap);
				for(size_t i=0; i<size; ++i)
				{
					fieldFunction_Inmap[i].write(file);
					fprintf_s(file, " ");
					if(i+1<size) fprintf_s(file," ");
				}
				size = sizeof(fieldFunction_Outmap)/sizeof(FieldFunction_Outmap);
				for(size_t i=0; i<size; ++i)
				{
					fieldFunction_Outmap[i].write(file);
					if(i+1<size) fprintf_s(file," ");
				}
			}
		} fieldFunction;
		void write(FILE* file) const
		{
			fieldFunction.write(file);
		}
	};
	/*Parent attribute for emission function.*/
	struct EmissionList{
		/*
		The function attribute an emitter gets connected to to emit into this
		fluidShape.
		*/
		struct EmissionFunction{
			/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
			struct EmissionFunction_Inmap{
				short emissionFunction_InmapTo;
				short emissionFunction_InmapFrom;
				void write(FILE* file) const
				{
					fprintf_s(file,"%i ", emissionFunction_InmapTo);
					fprintf_s(file,"%i", emissionFunction_InmapFrom);
				}
			}* emissionFunction_Inmap;
			/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
			struct EmissionFunction_Outmap{
				short emissionFunction_OutmapTo;
				short emissionFunction_OutmapFrom;
				void write(FILE* file) const
				{
					fprintf_s(file,"%i ", emissionFunction_OutmapTo);
					fprintf_s(file,"%i", emissionFunction_OutmapFrom);
				}
			}* emissionFunction_Outmap;
			void write(FILE* file) const
			{
				size_t size = sizeof(emissionFunction_Inmap)/sizeof(EmissionFunction_Inmap);
				for(size_t i=0; i<size; ++i)
				{
					emissionFunction_Inmap[i].write(file);
					fprintf_s(file, " ");
					if(i+1<size) fprintf_s(file," ");
				}
				size = sizeof(emissionFunction_Outmap)/sizeof(EmissionFunction_Outmap);
				for(size_t i=0; i<size; ++i)
				{
					emissionFunction_Outmap[i].write(file);
					if(i+1<size) fprintf_s(file," ");
				}
			}
		} emissionFunction;
		void write(FILE* file) const
		{
			emissionFunction.write(file);
		}
	};
	/*The center (in voxel grid coordinates) of the sub-volume to be drawn.*/
	struct SubVolumeCenter{
		int subVolumeCenterW;
		int subVolumeCenterH;
		int subVolumeCenterD;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", subVolumeCenterW);
			fprintf_s(file,"%i ", subVolumeCenterH);
			fprintf_s(file,"%i ", subVolumeCenterD);
		}
	};
	/*The dimensions (in voxels) of the sub-volume to be drawn.*/
	struct SubVolumeSize{
		int subVolumeSizeW;
		int subVolumeSizeH;
		int subVolumeSizeD;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", subVolumeSizeW);
			fprintf_s(file,"%i ", subVolumeSizeH);
			fprintf_s(file,"%i ", subVolumeSizeD);
		}
	};
	/*
	Data from dynamic nodes for computing new output force.
	The field gets data from a set of "points" (particles, locations
	on a rigid body, etc.) and returns a force computed for each
	point.  Arbitrary user-defined nodes can make use of the field
	as Tint32 as they can give data for a set of points and can interpret
	the outputs.  Nodes using the field should take care to set
	up their attributes so as not to cause a DG loop.
	*/
	struct InputData{
		vectorArray inputPositions;
		vectorArray inputVelocities;
		doubleArray inputMass;
		void write(FILE* file) const
		{
			inputPositions.write(file);
			fprintf_s(file, " ");
			inputVelocities.write(file);
			fprintf_s(file, " ");
			inputMass.write(file);
			fprintf_s(file, " ");
		}
	};
	/*
	<b>Color</b> defines a range of color values used to render the volume.
	The particular color selected from this range is determined by the
	<b>Color Input</b> parameter. The color represents how much
	incoming light is absorbed or scattered. If it is black all
	light is absorbed, while white materials scatter all incoming light.
	*/
	struct Color{
		float color_Position;
		float3 color_Color;
		unsigned int color_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", color_Position);
			color_Color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", color_Interp);
		}
	};
	/*
	<b>Opacity</b> defines a range of opacity values used to render the volume.
	The particular opacity value selected from this range is determined by the
	<b>Opacity Input</b> parameter. The opacity represents how much the material
	will block light. If the opacity is zero then the material is totally transparent.
	*/
	struct Opacity{
		float opacity_Position;
		float opacity_FloatValue;
		unsigned int opacity_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", opacity_Position);
			fprintf_s(file,"%f ", opacity_FloatValue);
			fprintf_s(file,"%i", opacity_Interp);
		}
	};
	/*
	<b>Incandescence</b> controls the amount of light emitted from
	regions of density due to self illumination. The
	The particular color selected from this range is determined by the
	<b>Incandescence Input</b> parameter. Incandescent emission is not
	affected by illumination or shadowing.
	*/
	struct Incandescence{
		float incandescence_Position;
		float3 incandescence_Color;
		unsigned int incandescence_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", incandescence_Position);
			incandescence_Color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", incandescence_Interp);
		}
	};
	/*
	<b>Environment</b> defines a simple sky to ground environmental
	reflection using a ramp. The left of the ramp is the top of the
	sky and the right is the bottom.
	*/
	struct Environment{
		float environment_Position;
		float3 environment_Color;
		unsigned int environment_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", environment_Position);
			environment_Color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", environment_Interp);
		}
	};
	/*Parent attribute for all collision input data.*/
	struct CollisionData{
		void write(FILE* file) const
		{
		}
	};
	/*
	This is a root of following mental ray attributes.
	The following override flags applies to fluidShape node only,
	and does not have any effect on fluid texture nodes (both 2D and 3D).
	*/
	struct MentalRayControls{
		bool miOverrideCaustics;
		short miCausticAccuracy;
		float miCausticRadius;
		bool miOverrideGlobalIllumination;
		short miGlobillumAccuracy;
		float miGlobillumRadius;
		bool miOverrideFinalGather;
		int miFinalGatherRays;
		float miFinalGatherMinRadius;
		float miFinalGatherMaxRadius;
		short miFinalGatherFilter;
		bool miFinalGatherView;
		bool miOverrideSamples;
		short miMinSamples;
		short miMaxSamples;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", miOverrideCaustics);
			fprintf_s(file,"%i ", miCausticAccuracy);
			fprintf_s(file,"%f ", miCausticRadius);
			fprintf_s(file,"%i ", miOverrideGlobalIllumination);
			fprintf_s(file,"%i ", miGlobillumAccuracy);
			fprintf_s(file,"%f ", miGlobillumRadius);
			fprintf_s(file,"%i ", miOverrideFinalGather);
			fprintf_s(file,"%i ", miFinalGatherRays);
			fprintf_s(file,"%f ", miFinalGatherMinRadius);
			fprintf_s(file,"%f ", miFinalGatherMaxRadius);
			fprintf_s(file,"%i ", miFinalGatherFilter);
			fprintf_s(file,"%i ", miFinalGatherView);
			fprintf_s(file,"%i ", miOverrideSamples);
			fprintf_s(file,"%i ", miMinSamples);
			fprintf_s(file,"%i", miMaxSamples);
		}
	};
public:
	FluidShape(FILE* file,const std::string& name,const std::string& parent=""):SurfaceShape(file, name, parent, "fluidShape"){}
	virtual ~FluidShape(){}
	/*The output grid.*/
	void setOutGrid(const FluidID& out){fprintf_s(mFile,"connectAttr \"");out.write(mFile);fprintf_s(mFile,"\" \"%s.out\";\n",mName.c_str());}
	/*
	This is the current time used for the fluid simulation.
	By default, it is given an incoming connection from the main time node.
	This can be replaced with some other connection (e.g. from an expression
	or param curve), and then the solving is done based
	on that time value.  There must be some incoming connection in order
	for the fluid object to simulate.
	*/
	void setCurrentTime(const TimeID& cti){fprintf_s(mFile,"connectAttr \"");cti.write(mFile);fprintf_s(mFile,"\" \"%s.cti\";\n",mName.c_str());}
	/*
	The time after which the simulation will be run for this fluid object.
	This is set from the startFrame attribute.
	Users should set startFrame instead of this attribute.
	*/
	void setStartTime(const TimeID& sti){fprintf_s(mFile,"connectAttr \"");sti.write(mFile);fprintf_s(mFile,"\" \"%s.sti\";\n",mName.c_str());}
	/*
	This is the frame after which the simulation will run. Nothing
	will play back for this object prior to startFrame.
	*/
	void setStartFrame(double stf){if(stf == 1.0) return; fprintf_s(mFile, "setAttr \".stf\" %f;\n", stf);}
	/*
	This is the frame after which the simulation will run. Nothing
	will play back for this object prior to startFrame.
	*/
	void setStartFrame(const DoubleID& stf){fprintf_s(mFile,"connectAttr \"");stf.write(mFile);fprintf_s(mFile,"\" \"%s.stf\";\n",mName.c_str());}
	/*
	Used to turn off memory allocation, solving and contents draw
	during interactive, but still allows batch render
	*/
	void setDisableInteractiveEval(bool die){if(die == false) return; fprintf_s(mFile, "setAttr \".die\" %i;\n", die);}
	/*
	Used to turn off memory allocation, solving and contents draw
	during interactive, but still allows batch render
	*/
	void setDisableInteractiveEval(const BoolID& die){fprintf_s(mFile,"connectAttr \"");die.write(mFile);fprintf_s(mFile,"\" \"%s.die\";\n",mName.c_str());}
	/*Used to specify whether this is a 2D or 3D fluid.*/
	void setIs2d(bool is2){if(is2 == false) return; fprintf_s(mFile, "setAttr \".is2\" %i;\n", is2);}
	/*Used to specify whether this is a 2D or 3D fluid.*/
	void setIs2d(const BoolID& is2){fprintf_s(mFile,"connectAttr \"");is2.write(mFile);fprintf_s(mFile,"\" \"%s.is2\";\n",mName.c_str());}
	/*
	Resolution of the grid
	Users should be aware that changing this attribute will affect the
	density currently contained in the grid.
	*/
	void setResolution(const Resolution& res){fprintf_s(mFile, "setAttr \".res\" ");res.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Resolution of the grid
	Users should be aware that changing this attribute will affect the
	density currently contained in the grid.
	*/
	void setResolution(const ResolutionID& res){fprintf_s(mFile,"connectAttr \"");res.write(mFile);fprintf_s(mFile,"\" \"%s.res\";\n",mName.c_str());}
	/*Resolution of the grid - width*/
	void setResolutionW(int rw){if(rw == 10) return; fprintf_s(mFile, "setAttr \".res.rw\" %i;\n", rw);}
	/*Resolution of the grid - width*/
	void setResolutionW(const IntID& rw){fprintf_s(mFile,"connectAttr \"");rw.write(mFile);fprintf_s(mFile,"\" \"%s.res.rw\";\n",mName.c_str());}
	/*Resolution of the grid - height*/
	void setResolutionH(int rh){if(rh == 10) return; fprintf_s(mFile, "setAttr \".res.rh\" %i;\n", rh);}
	/*Resolution of the grid - height*/
	void setResolutionH(const IntID& rh){fprintf_s(mFile,"connectAttr \"");rh.write(mFile);fprintf_s(mFile,"\" \"%s.res.rh\";\n",mName.c_str());}
	/*Resolution of the grid - depth*/
	void setResolutionD(int rd){if(rd == 10) return; fprintf_s(mFile, "setAttr \".res.rd\" %i;\n", rd);}
	/*Resolution of the grid - depth*/
	void setResolutionD(const IntID& rd){fprintf_s(mFile,"connectAttr \"");rd.write(mFile);fprintf_s(mFile,"\" \"%s.res.rd\";\n",mName.c_str());}
	/*
	Dimensions of the grid. The dimensions are used internally by the
	solver and should not be changed unless you really know what you're
	doing. Use the scale on the transform to increase the size of the grid
	instead.
	*/
	void setDimensions(const Dimensions& dim){fprintf_s(mFile, "setAttr \".dim\" ");dim.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Dimensions of the grid. The dimensions are used internally by the
	solver and should not be changed unless you really know what you're
	doing. Use the scale on the transform to increase the size of the grid
	instead.
	*/
	void setDimensions(const DimensionsID& dim){fprintf_s(mFile,"connectAttr \"");dim.write(mFile);fprintf_s(mFile,"\" \"%s.dim\";\n",mName.c_str());}
	/*Width Dimension of the grid*/
	void setDimensionsW(double dw){if(dw == 3) return; fprintf_s(mFile, "setAttr \".dim.dw\" %f;\n", dw);}
	/*Width Dimension of the grid*/
	void setDimensionsW(const DoubleID& dw){fprintf_s(mFile,"connectAttr \"");dw.write(mFile);fprintf_s(mFile,"\" \"%s.dim.dw\";\n",mName.c_str());}
	/*Height Dimension of the grid*/
	void setDimensionsH(double dh){if(dh == 3) return; fprintf_s(mFile, "setAttr \".dim.dh\" %f;\n", dh);}
	/*Height Dimension of the grid*/
	void setDimensionsH(const DoubleID& dh){fprintf_s(mFile,"connectAttr \"");dh.write(mFile);fprintf_s(mFile,"\" \"%s.dim.dh\";\n",mName.c_str());}
	/*Depth Dimension of the grid*/
	void setDimensionsD(double dd){if(dd == 3) return; fprintf_s(mFile, "setAttr \".dim.dd\" %f;\n", dd);}
	/*Depth Dimension of the grid*/
	void setDimensionsD(const DoubleID& dd){fprintf_s(mFile,"connectAttr \"");dd.write(mFile);fprintf_s(mFile,"\" \"%s.dim.dd\";\n",mName.c_str());}
	/*Initial conditions for the fluidShape - currently unused.*/
	void setInitialConditions(const MessageID& inc){fprintf_s(mFile,"connectAttr \"");inc.write(mFile);fprintf_s(mFile,"\" \"%s.inc\";\n",mName.c_str());}
	/*A toggle - if false, ignore all connected fields*/
	void setDoFields(bool dfr){if(dfr == true) return; fprintf_s(mFile, "setAttr \".dfr\" %i;\n", dfr);}
	/*A toggle - if false, ignore all connected fields*/
	void setDoFields(const BoolID& dfr){fprintf_s(mFile,"connectAttr \"");dfr.write(mFile);fprintf_s(mFile,"\" \"%s.dfr\";\n",mName.c_str());}
	/*
	This is the input multi-attribute where any fields acting on
	this fluid object are connected. The input forces are collected
	when the outGrid does it's update.
	*/
	void setInputForce(size_t ifc_i,const VectorArrayID& ifc){fprintf_s(mFile,"connectAttr \"");ifc.write(mFile);fprintf_s(mFile,"\" \"%s.ifc[%i]\";\n",mName.c_str(),ifc_i);}
	/*
	This is the compound that holds all of the default attribute for the
	fields to connect to.
	*/
	void setFieldData(const FieldDataID& fd){fprintf_s(mFile,"connectAttr \"");fd.write(mFile);fprintf_s(mFile,"\" \"%s.fd\";\n",mName.c_str());}
	/*
	This is the default place that the fields will get this fluidShape's
	position data from. These positions are the (worldspace) midpoints of
	the each cell.
	*/
	void setFieldDataPosition(const VectorArrayID& fdp){fprintf_s(mFile,"connectAttr \"");fdp.write(mFile);fprintf_s(mFile,"\" \"%s.fd.fdp\";\n",mName.c_str());}
	/*
	This attribute stores the velocity for each cell, for the fields to
	use in calculations.
	*/
	void setFieldDataVelocity(const VectorArrayID& fdv){fprintf_s(mFile,"connectAttr \"");fdv.write(mFile);fprintf_s(mFile,"\" \"%s.fd.fdv\";\n",mName.c_str());}
	/*
	This is where connected fields get mass data for the fluid shape. The
	density of fluid for a particular cell is converted to an appropriate
	amount of mass for fields which consider mass.
	*/
	void setFieldDataMass(const DoubleArrayID& fdm){fprintf_s(mFile,"connectAttr \"");fdm.write(mFile);fprintf_s(mFile,"\" \"%s.fd.fdm\";\n",mName.c_str());}
	/*
	This is where the fields will get this fluidShape's
	timeStep size from.
	*/
	void setFieldDataDeltaTime(const TimeID& fdt){fprintf_s(mFile,"connectAttr \"");fdt.write(mFile);fprintf_s(mFile,"\" \"%s.fd.fdt\";\n",mName.c_str());}
	/*
	Parent multi-attribute to store the field's function attribute
	connections. (No longer used)
	*/
	void setFieldList(size_t fll_i,const FieldList& fll){fprintf_s(mFile, "setAttr \".fll[%i]\" ",fll_i);fll.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Parent multi-attribute to store the field's function attribute
	connections. (No longer used)
	*/
	void setFieldList(size_t fll_i,const FieldListID& fll){fprintf_s(mFile,"connectAttr \"");fll.write(mFile);fprintf_s(mFile,"\" \"%s.fll[%i]\";\n",mName.c_str(),fll_i);}
	/*
	Function attribute for field computation. No longer used - see the
	fieldData attributes and the inputForce for how a field is connected
	to a fluidShape
	*/
	void setFieldFunction(size_t fll_i,const FieldList::FieldFunction& frf){fprintf_s(mFile, "setAttr \".fll[%i].frf\" ",fll_i);frf.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Function attribute for field computation. No longer used - see the
	fieldData attributes and the inputForce for how a field is connected
	to a fluidShape
	*/
	void setFieldFunction(size_t fll_i,const FieldFunctionID& frf){fprintf_s(mFile,"connectAttr \"");frf.write(mFile);fprintf_s(mFile,"\" \"%s.fll[%i].frf\";\n",mName.c_str(),fll_i);}
	/*For Internal Use Only<br/>Actual function being applied at this attribute*/
	void setFieldFunction_Raw(size_t fll_i,const FunctionID& frfr){fprintf_s(mFile,"connectAttr \"");frfr.write(mFile);fprintf_s(mFile,"\" \"%s.fll[%i].frf.frfr\";\n",mName.c_str(),fll_i);}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	void setFieldFunction_Inmap(size_t fll_i,size_t frfi_i,const FieldList::FieldFunction::FieldFunction_Inmap& frfi){fprintf_s(mFile, "setAttr \".fll[%i].frf.frfi[%i]\" ",fll_i,frfi_i);frfi.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	void setFieldFunction_Inmap(size_t fll_i,size_t frfi_i,const FieldFunction_InmapID& frfi){fprintf_s(mFile,"connectAttr \"");frfi.write(mFile);fprintf_s(mFile,"\" \"%s.fll[%i].frf.frfi[%i]\";\n",mName.c_str(),fll_i,frfi_i);}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	void setFieldFunction_InmapTo(size_t fll_i,size_t frfi_i,short frfit){if(frfit == 0) return; fprintf_s(mFile, "setAttr \".fll[%i].frf.frfi[%i].frfit\" %i;\n", fll_i,frfi_i,frfit);}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	void setFieldFunction_InmapTo(size_t fll_i,size_t frfi_i,const ShortID& frfit){fprintf_s(mFile,"connectAttr \"");frfit.write(mFile);fprintf_s(mFile,"\" \"%s.fll[%i].frf.frfi[%i].frfit\";\n",mName.c_str(),fll_i,frfi_i);}
	/*For Internal Use Only<br/>Function data input parameter index*/
	void setFieldFunction_InmapFrom(size_t fll_i,size_t frfi_i,short frfif){if(frfif == 0) return; fprintf_s(mFile, "setAttr \".fll[%i].frf.frfi[%i].frfif\" %i;\n", fll_i,frfi_i,frfif);}
	/*For Internal Use Only<br/>Function data input parameter index*/
	void setFieldFunction_InmapFrom(size_t fll_i,size_t frfi_i,const ShortID& frfif){fprintf_s(mFile,"connectAttr \"");frfif.write(mFile);fprintf_s(mFile,"\" \"%s.fll[%i].frf.frfi[%i].frfif\";\n",mName.c_str(),fll_i,frfi_i);}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	void setFieldFunction_Outmap(size_t fll_i,size_t frfo_i,const FieldList::FieldFunction::FieldFunction_Outmap& frfo){fprintf_s(mFile, "setAttr \".fll[%i].frf.frfo[%i]\" ",fll_i,frfo_i);frfo.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	void setFieldFunction_Outmap(size_t fll_i,size_t frfo_i,const FieldFunction_OutmapID& frfo){fprintf_s(mFile,"connectAttr \"");frfo.write(mFile);fprintf_s(mFile,"\" \"%s.fll[%i].frf.frfo[%i]\";\n",mName.c_str(),fll_i,frfo_i);}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	void setFieldFunction_OutmapTo(size_t fll_i,size_t frfo_i,short frfot){if(frfot == 0) return; fprintf_s(mFile, "setAttr \".fll[%i].frf.frfo[%i].frfot\" %i;\n", fll_i,frfo_i,frfot);}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	void setFieldFunction_OutmapTo(size_t fll_i,size_t frfo_i,const ShortID& frfot){fprintf_s(mFile,"connectAttr \"");frfot.write(mFile);fprintf_s(mFile,"\" \"%s.fll[%i].frf.frfo[%i].frfot\";\n",mName.c_str(),fll_i,frfo_i);}
	/*For Internal Use Only<br/>Function data output parameter index*/
	void setFieldFunction_OutmapFrom(size_t fll_i,size_t frfo_i,short frfof){if(frfof == 0) return; fprintf_s(mFile, "setAttr \".fll[%i].frf.frfo[%i].frfof\" %i;\n", fll_i,frfo_i,frfof);}
	/*For Internal Use Only<br/>Function data output parameter index*/
	void setFieldFunction_OutmapFrom(size_t fll_i,size_t frfo_i,const ShortID& frfof){fprintf_s(mFile,"connectAttr \"");frfof.write(mFile);fprintf_s(mFile,"\" \"%s.fll[%i].frf.frfo[%i].frfof\";\n",mName.c_str(),fll_i,frfo_i);}
	/*A toggle - if false, ignore all connected emitters*/
	void setDoEmission(bool de){if(de == true) return; fprintf_s(mFile, "setAttr \".de\" %i;\n", de);}
	/*A toggle - if false, ignore all connected emitters*/
	void setDoEmission(const BoolID& de){fprintf_s(mFile,"connectAttr \"");de.write(mFile);fprintf_s(mFile,"\" \"%s.de\";\n",mName.c_str());}
	/*Tells any object whether this fluid object has room for more emission*/
	void setIsFull(const BoolID& ifl){fprintf_s(mFile,"connectAttr \"");ifl.write(mFile);fprintf_s(mFile,"\" \"%s.ifl\";\n",mName.c_str());}
	/*
	Fraction of emitter velocity that density emitted into this
	object inherit.
	*/
	void setInheritFactor(double inh){if(inh == 0.0) return; fprintf_s(mFile, "setAttr \".inh\" %f;\n", inh);}
	/*
	Fraction of emitter velocity that density emitted into this
	object inherit.
	*/
	void setInheritFactor(const DoubleID& inh){fprintf_s(mFile,"connectAttr \"");inh.write(mFile);fprintf_s(mFile,"\" \"%s.inh\";\n",mName.c_str());}
	/*
	Random number stream seed for emitter's random number stream.
	Separate seed for each emitter. Set seeds equal to get identical
	stream.  Resetting the seed at a particular frame will restart
	the stream.
	*/
	void setSeed(size_t sd_i,int sd){if(sd == 1) return; fprintf_s(mFile, "setAttr \".sd[%i]\" %i;\n", sd_i,sd);}
	/*
	Random number stream seed for emitter's random number stream.
	Separate seed for each emitter. Set seeds equal to get identical
	stream.  Resetting the seed at a particular frame will restart
	the stream.
	*/
	void setSeed(size_t sd_i,const IntID& sd){fprintf_s(mFile,"connectAttr \"");sd.write(mFile);fprintf_s(mFile,"\" \"%s.sd[%i]\";\n",mName.c_str(),sd_i);}
	/*Indicates whether color is being emitted along with density.*/
	void setFluidColorEmission(size_t fce_i,const BoolID& fce){fprintf_s(mFile,"connectAttr \"");fce.write(mFile);fprintf_s(mFile,"\" \"%s.fce[%i]\";\n",mName.c_str(),fce_i);}
	/*Indicates whether the reaction grid is being emitted into along with density.*/
	void setFluidReactantEmission(size_t frm_i,const BoolID& frm){fprintf_s(mFile,"connectAttr \"");frm.write(mFile);fprintf_s(mFile,"\" \"%s.frm[%i]\";\n",mName.c_str(),frm_i);}
	/*Parent attribute for emission function.*/
	void setEmissionList(size_t eml_i,const EmissionList& eml){fprintf_s(mFile, "setAttr \".eml[%i]\" ",eml_i);eml.write(mFile);fprintf_s(mFile,";\n");}
	/*Parent attribute for emission function.*/
	void setEmissionList(size_t eml_i,const EmissionListID& eml){fprintf_s(mFile,"connectAttr \"");eml.write(mFile);fprintf_s(mFile,"\" \"%s.eml[%i]\";\n",mName.c_str(),eml_i);}
	/*
	The function attribute an emitter gets connected to to emit into this
	fluidShape.
	*/
	void setEmissionFunction(size_t eml_i,const EmissionList::EmissionFunction& emf){fprintf_s(mFile, "setAttr \".eml[%i].emf\" ",eml_i);emf.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The function attribute an emitter gets connected to to emit into this
	fluidShape.
	*/
	void setEmissionFunction(size_t eml_i,const EmissionFunctionID& emf){fprintf_s(mFile,"connectAttr \"");emf.write(mFile);fprintf_s(mFile,"\" \"%s.eml[%i].emf\";\n",mName.c_str(),eml_i);}
	/*For Internal Use Only<br/>Actual function being applied at this attribute*/
	void setEmissionFunction_Raw(size_t eml_i,const FunctionID& emfr){fprintf_s(mFile,"connectAttr \"");emfr.write(mFile);fprintf_s(mFile,"\" \"%s.eml[%i].emf.emfr\";\n",mName.c_str(),eml_i);}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	void setEmissionFunction_Inmap(size_t eml_i,size_t emfi_i,const EmissionList::EmissionFunction::EmissionFunction_Inmap& emfi){fprintf_s(mFile, "setAttr \".eml[%i].emf.emfi[%i]\" ",eml_i,emfi_i);emfi.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	void setEmissionFunction_Inmap(size_t eml_i,size_t emfi_i,const EmissionFunction_InmapID& emfi){fprintf_s(mFile,"connectAttr \"");emfi.write(mFile);fprintf_s(mFile,"\" \"%s.eml[%i].emf.emfi[%i]\";\n",mName.c_str(),eml_i,emfi_i);}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	void setEmissionFunction_InmapTo(size_t eml_i,size_t emfi_i,short emfit){if(emfit == 0) return; fprintf_s(mFile, "setAttr \".eml[%i].emf.emfi[%i].emfit\" %i;\n", eml_i,emfi_i,emfit);}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	void setEmissionFunction_InmapTo(size_t eml_i,size_t emfi_i,const ShortID& emfit){fprintf_s(mFile,"connectAttr \"");emfit.write(mFile);fprintf_s(mFile,"\" \"%s.eml[%i].emf.emfi[%i].emfit\";\n",mName.c_str(),eml_i,emfi_i);}
	/*For Internal Use Only<br/>Function data input parameter index*/
	void setEmissionFunction_InmapFrom(size_t eml_i,size_t emfi_i,short emfif){if(emfif == 0) return; fprintf_s(mFile, "setAttr \".eml[%i].emf.emfi[%i].emfif\" %i;\n", eml_i,emfi_i,emfif);}
	/*For Internal Use Only<br/>Function data input parameter index*/
	void setEmissionFunction_InmapFrom(size_t eml_i,size_t emfi_i,const ShortID& emfif){fprintf_s(mFile,"connectAttr \"");emfif.write(mFile);fprintf_s(mFile,"\" \"%s.eml[%i].emf.emfi[%i].emfif\";\n",mName.c_str(),eml_i,emfi_i);}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	void setEmissionFunction_Outmap(size_t eml_i,size_t emfo_i,const EmissionList::EmissionFunction::EmissionFunction_Outmap& emfo){fprintf_s(mFile, "setAttr \".eml[%i].emf.emfo[%i]\" ",eml_i,emfo_i);emfo.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	void setEmissionFunction_Outmap(size_t eml_i,size_t emfo_i,const EmissionFunction_OutmapID& emfo){fprintf_s(mFile,"connectAttr \"");emfo.write(mFile);fprintf_s(mFile,"\" \"%s.eml[%i].emf.emfo[%i]\";\n",mName.c_str(),eml_i,emfo_i);}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	void setEmissionFunction_OutmapTo(size_t eml_i,size_t emfo_i,short emfot){if(emfot == 0) return; fprintf_s(mFile, "setAttr \".eml[%i].emf.emfo[%i].emfot\" %i;\n", eml_i,emfo_i,emfot);}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	void setEmissionFunction_OutmapTo(size_t eml_i,size_t emfo_i,const ShortID& emfot){fprintf_s(mFile,"connectAttr \"");emfot.write(mFile);fprintf_s(mFile,"\" \"%s.eml[%i].emf.emfo[%i].emfot\";\n",mName.c_str(),eml_i,emfo_i);}
	/*For Internal Use Only<br/>Function data output parameter index*/
	void setEmissionFunction_OutmapFrom(size_t eml_i,size_t emfo_i,short emfof){if(emfof == 0) return; fprintf_s(mFile, "setAttr \".eml[%i].emf.emfo[%i].emfof\" %i;\n", eml_i,emfo_i,emfof);}
	/*For Internal Use Only<br/>Function data output parameter index*/
	void setEmissionFunction_OutmapFrom(size_t eml_i,size_t emfo_i,const ShortID& emfof){fprintf_s(mFile,"connectAttr \"");emfof.write(mFile);fprintf_s(mFile,"\" \"%s.eml[%i].emf.emfo[%i].emfof\";\n",mName.c_str(),eml_i,emfo_i);}
	/*
	The number of slices to draw for each grid cell most aligned with the
	view direction when in 'slice' shaded draw mode. Increasing this value
	will give more detailed hardware draws (at the cost of slower drawing)
	*/
	void setSlices(int sli){if(sli == 2) return; fprintf_s(mFile, "setAttr \".sli\" %i;\n", sli);}
	/*
	The number of slices to draw for each grid cell most aligned with the
	view direction when in 'slice' shaded draw mode. Increasing this value
	will give more detailed hardware draws (at the cost of slower drawing)
	*/
	void setSlices(const IntID& sli){fprintf_s(mFile,"connectAttr \"");sli.write(mFile);fprintf_s(mFile,"\" \"%s.sli\";\n",mName.c_str());}
	/*
	In hardware draw mode, we normally draw quads with vertices at the
	centers of voxels. If the VoxelQuality attr is set to 2 (Better), then we split
	this up, doubling the number of quads in each direction, for a total
	of 4.
	*/
	void setVoxelQuality(unsigned int vqu){if(vqu == 0) return; fprintf_s(mFile, "setAttr \".vqu\" %i;\n", vqu);}
	/*
	In hardware draw mode, we normally draw quads with vertices at the
	centers of voxels. If the VoxelQuality attr is set to 2 (Better), then we split
	this up, doubling the number of quads in each direction, for a total
	of 4.
	*/
	void setVoxelQuality(const UnsignedintID& vqu){fprintf_s(mFile,"connectAttr \"");vqu.write(mFile);fprintf_s(mFile,"\" \"%s.vqu\";\n",mName.c_str());}
	/*
	When turned on, only a portion of the fluid's internal volume is
	is drawn, as specified by the next set of attributes.
	*/
	void setDrawSubVolume(bool dsv){if(dsv == false) return; fprintf_s(mFile, "setAttr \".dsv\" %i;\n", dsv);}
	/*
	When turned on, only a portion of the fluid's internal volume is
	is drawn, as specified by the next set of attributes.
	*/
	void setDrawSubVolume(const BoolID& dsv){fprintf_s(mFile,"connectAttr \"");dsv.write(mFile);fprintf_s(mFile,"\" \"%s.dsv\";\n",mName.c_str());}
	/*The center (in voxel grid coordinates) of the sub-volume to be drawn.*/
	void setSubVolumeCenter(const SubVolumeCenter& svc){fprintf_s(mFile, "setAttr \".svc\" ");svc.write(mFile);fprintf_s(mFile,";\n");}
	/*The center (in voxel grid coordinates) of the sub-volume to be drawn.*/
	void setSubVolumeCenter(const SubVolumeCenterID& svc){fprintf_s(mFile,"connectAttr \"");svc.write(mFile);fprintf_s(mFile,"\" \"%s.svc\";\n",mName.c_str());}
	/*Width component of aSubVolumeCenter.*/
	void setSubVolumeCenterW(int scw){if(scw == -1) return; fprintf_s(mFile, "setAttr \".svc.scw\" %i;\n", scw);}
	/*Width component of aSubVolumeCenter.*/
	void setSubVolumeCenterW(const IntID& scw){fprintf_s(mFile,"connectAttr \"");scw.write(mFile);fprintf_s(mFile,"\" \"%s.svc.scw\";\n",mName.c_str());}
	/*Height component of aSubVolumeCenter.*/
	void setSubVolumeCenterH(int sch){if(sch == -1) return; fprintf_s(mFile, "setAttr \".svc.sch\" %i;\n", sch);}
	/*Height component of aSubVolumeCenter.*/
	void setSubVolumeCenterH(const IntID& sch){fprintf_s(mFile,"connectAttr \"");sch.write(mFile);fprintf_s(mFile,"\" \"%s.svc.sch\";\n",mName.c_str());}
	/*Depth component of aSubVolumeCenter.*/
	void setSubVolumeCenterD(int scd){if(scd == -1) return; fprintf_s(mFile, "setAttr \".svc.scd\" %i;\n", scd);}
	/*Depth component of aSubVolumeCenter.*/
	void setSubVolumeCenterD(const IntID& scd){fprintf_s(mFile,"connectAttr \"");scd.write(mFile);fprintf_s(mFile,"\" \"%s.svc.scd\";\n",mName.c_str());}
	/*The dimensions (in voxels) of the sub-volume to be drawn.*/
	void setSubVolumeSize(const SubVolumeSize& svs){fprintf_s(mFile, "setAttr \".svs\" ");svs.write(mFile);fprintf_s(mFile,";\n");}
	/*The dimensions (in voxels) of the sub-volume to be drawn.*/
	void setSubVolumeSize(const SubVolumeSizeID& svs){fprintf_s(mFile,"connectAttr \"");svs.write(mFile);fprintf_s(mFile,"\" \"%s.svs\";\n",mName.c_str());}
	/*Width component of aSubVolumeSize.*/
	void setSubVolumeSizeW(int ssw){if(ssw == -1) return; fprintf_s(mFile, "setAttr \".svs.ssw\" %i;\n", ssw);}
	/*Width component of aSubVolumeSize.*/
	void setSubVolumeSizeW(const IntID& ssw){fprintf_s(mFile,"connectAttr \"");ssw.write(mFile);fprintf_s(mFile,"\" \"%s.svs.ssw\";\n",mName.c_str());}
	/*Height component of aSubVolumeSize.*/
	void setSubVolumeSizeH(int ssh){if(ssh == -1) return; fprintf_s(mFile, "setAttr \".svs.ssh\" %i;\n", ssh);}
	/*Height component of aSubVolumeSize.*/
	void setSubVolumeSizeH(const IntID& ssh){fprintf_s(mFile,"connectAttr \"");ssh.write(mFile);fprintf_s(mFile,"\" \"%s.svs.ssh\";\n",mName.c_str());}
	/*Depth component of aSubVolumeSize.*/
	void setSubVolumeSizeD(int ssd){if(ssd == -1) return; fprintf_s(mFile, "setAttr \".svs.ssd\" %i;\n", ssd);}
	/*Depth component of aSubVolumeSize.*/
	void setSubVolumeSizeD(const IntID& ssd){fprintf_s(mFile,"connectAttr \"");ssd.write(mFile);fprintf_s(mFile,"\" \"%s.svs.ssd\";\n",mName.c_str());}
	/*
	Determines whether the fluid drawing axis changes orientation with
	respect to the camera angle.  If false, orientation of the draw
	slice is locked and does not change with the camera angle.
	If true, orientation changes as the camera angle changes.
	*/
	void setLockDrawAxis(const BoolID& lda){fprintf_s(mFile,"connectAttr \"");lda.write(mFile);fprintf_s(mFile,"\" \"%s.lda\";\n",mName.c_str());}
	/*
	This attribute controls how the grid is drawn in 3d views. 0 or
	"Bottom", the default, indicates the bottom 'wall' of the grid
	should be drawn, bounding lines only for the rest. 1, "Reduced"
	indicates draw the 'walls' for the three sides furthest away from
	the camera, lines for the rest. 2, or "Outline", draws all sides of
	the grid with full resolution. 3, or "Full", draws everything.
	"Bounding box", value 4, draws just the bounding box for the grid,
	and 5, or "None", means don't draw the grid at all.
	*/
	void setBoundaryDraw(unsigned int bod){if(bod == 0) return; fprintf_s(mFile, "setAttr \".bod\" %i;\n", bod);}
	/*
	This attribute controls how the grid is drawn in 3d views. 0 or
	"Bottom", the default, indicates the bottom 'wall' of the grid
	should be drawn, bounding lines only for the rest. 1, "Reduced"
	indicates draw the 'walls' for the three sides furthest away from
	the camera, lines for the rest. 2, or "Outline", draws all sides of
	the grid with full resolution. 3, or "Full", draws everything.
	"Bounding box", value 4, draws just the bounding box for the grid,
	and 5, or "None", means don't draw the grid at all.
	*/
	void setBoundaryDraw(const UnsignedintID& bod){fprintf_s(mFile,"connectAttr \"");bod.write(mFile);fprintf_s(mFile,"\" \"%s.bod\";\n",mName.c_str());}
	/*
	If false, the velocity arrows are drawn as line segments only.
	Will speed up drawing and may make the volume less cluttered for
	visualization.
	*/
	void setDrawHeads(bool dhd){if(dhd == true) return; fprintf_s(mFile, "setAttr \".dhd\" %i;\n", dhd);}
	/*
	If false, the velocity arrows are drawn as line segments only.
	Will speed up drawing and may make the volume less cluttered for
	visualization.
	*/
	void setDrawHeads(const BoolID& dhd){fprintf_s(mFile,"connectAttr \"");dhd.write(mFile);fprintf_s(mFile,"\" \"%s.dhd\";\n",mName.c_str());}
	/*If true, draws arrows or lines for the veloicty field.*/
	void setVelocityDraw(bool vld){if(vld == false) return; fprintf_s(mFile, "setAttr \".vld\" %i;\n", vld);}
	/*If true, draws arrows or lines for the veloicty field.*/
	void setVelocityDraw(const BoolID& vld){fprintf_s(mFile,"connectAttr \"");vld.write(mFile);fprintf_s(mFile,"\" \"%s.vld\";\n",mName.c_str());}
	/*
	The larger this value, the longer the velocity segments or arrows.
	For very low-force simulations, the velocity field may be very small
	in magnitude. If this is the case, bumping this atribute up will help
	to visualize the velocity flow.
	*/
	void setVelocityDrawLength(double vdl){if(vdl == 1) return; fprintf_s(mFile, "setAttr \".vdl\" %f;\n", vdl);}
	/*
	The larger this value, the longer the velocity segments or arrows.
	For very low-force simulations, the velocity field may be very small
	in magnitude. If this is the case, bumping this atribute up will help
	to visualize the velocity flow.
	*/
	void setVelocityDrawLength(const DoubleID& vdl){fprintf_s(mFile,"connectAttr \"");vdl.write(mFile);fprintf_s(mFile,"\" \"%s.vdl\";\n",mName.c_str());}
	/*
	The larger this value, the less velocity arrows that are drawn
	If the value is 1 then every other arrow will be omitted. If it
	is zero then all arrows will be drawn.
	*/
	void setVelocityDrawSkip(int vds){if(vds == 1) return; fprintf_s(mFile, "setAttr \".vds\" %i;\n", vds);}
	/*
	The larger this value, the less velocity arrows that are drawn
	If the value is 1 then every other arrow will be omitted. If it
	is zero then all arrows will be drawn.
	*/
	void setVelocityDrawSkip(const IntID& vds){fprintf_s(mFile,"connectAttr \"");vds.write(mFile);fprintf_s(mFile,"\" \"%s.vds\";\n",mName.c_str());}
	/*
	Shaded Display determines what is displayed in the modeling view when in shaded mode.
	<b>As Render</b> attempts to match the final software rendered look.
	The other methods allow one to view isolated sub elements of the
	fluid, which can be useful when painting or tweeking these elements.
	Tweek the <b>Display Opacity Scale</b> to map the current element to
	a useful range of opacity in the grid. The methods combining density
	with another attribute display this other attribute using color.
	*/
	void setShadedDisplay(unsigned int sdp){if(sdp == 1) return; fprintf_s(mFile, "setAttr \".sdp\" %i;\n", sdp);}
	/*
	Shaded Display determines what is displayed in the modeling view when in shaded mode.
	<b>As Render</b> attempts to match the final software rendered look.
	The other methods allow one to view isolated sub elements of the
	fluid, which can be useful when painting or tweeking these elements.
	Tweek the <b>Display Opacity Scale</b> to map the current element to
	a useful range of opacity in the grid. The methods combining density
	with another attribute display this other attribute using color.
	*/
	void setShadedDisplay(const UnsignedintID& sdp){fprintf_s(mFile,"connectAttr \"");sdp.write(mFile);fprintf_s(mFile,"\" \"%s.sdp\";\n",mName.c_str());}
	/*
	<b>Opacity Preview Gain</b> adjusts the opacity of the hardware
	redraw when the shaded display is not <b>As Render</b>. This is
	useful when painting values into the grid.
	*/
	void setOpacityPreviewGain(float opg){if(opg == 0.5) return; fprintf_s(mFile, "setAttr \".opg\" %f;\n", opg);}
	/*
	<b>Opacity Preview Gain</b> adjusts the opacity of the hardware
	redraw when the shaded display is not <b>As Render</b>. This is
	useful when painting values into the grid.
	*/
	void setOpacityPreviewGain(const FloatID& opg){fprintf_s(mFile,"connectAttr \"");opg.write(mFile);fprintf_s(mFile,"\" \"%s.opg\";\n",mName.c_str());}
	/*How to simulate the opacity of the grid when in wireframe mode.*/
	void setWireframeDisplay(unsigned int wdp){if(wdp == 2) return; fprintf_s(mFile, "setAttr \".wdp\" %i;\n", wdp);}
	/*How to simulate the opacity of the grid when in wireframe mode.*/
	void setWireframeDisplay(const UnsignedintID& wdp){fprintf_s(mFile,"connectAttr \"");wdp.write(mFile);fprintf_s(mFile,"\" \"%s.wdp\";\n",mName.c_str());}
	/*Display selected attribute as a grid of numbers.*/
	void setNumericDisplay(unsigned int nud){if(nud == 0) return; fprintf_s(mFile, "setAttr \".nud\" %i;\n", nud);}
	/*Display selected attribute as a grid of numbers.*/
	void setNumericDisplay(const UnsignedintID& nud){fprintf_s(mFile,"connectAttr \"");nud.write(mFile);fprintf_s(mFile,"\" \"%s.nud\";\n",mName.c_str());}
	/*
	A toggle to turn self-shadowing on or off during the hardware draw.
	Currently this attribute is only used in 'slice' draw mode.
	A directional light <-1,-1,-1> is the only light used to compute
	self-shadowing currently.
	*/
	void setHardwareSelfShadow(bool hss){if(hss == true) return; fprintf_s(mFile, "setAttr \".hss\" %i;\n", hss);}
	/*
	A toggle to turn self-shadowing on or off during the hardware draw.
	Currently this attribute is only used in 'slice' draw mode.
	A directional light <-1,-1,-1> is the only light used to compute
	self-shadowing currently.
	*/
	void setHardwareSelfShadow(const BoolID& hss){fprintf_s(mFile,"connectAttr \"");hss.write(mFile);fprintf_s(mFile,"\" \"%s.hss\";\n",mName.c_str());}
	/*
	This defines how texture coordinates are defined.
	<b>Fixed</b> sets the values to equal the object space
	coordinate system (0-1 for the volume in x,y and z).
	<b>Grid</b> uses a grid of points and interpolates for in between values.
	If grid is set then the coordinate values will be moved using the
	current density solver. This will allow the texture to move and swirl with
	the density, rather than appearing fixed in space.
	<b>File</b> loads the texture coordinates from a file.
	*/
	void setCoordinateMethod(unsigned int cmet){if(cmet == 0) return; fprintf_s(mFile, "setAttr \".cmet\" %i;\n", cmet);}
	/*
	This defines how texture coordinates are defined.
	<b>Fixed</b> sets the values to equal the object space
	coordinate system (0-1 for the volume in x,y and z).
	<b>Grid</b> uses a grid of points and interpolates for in between values.
	If grid is set then the coordinate values will be moved using the
	current density solver. This will allow the texture to move and swirl with
	the density, rather than appearing fixed in space.
	<b>File</b> loads the texture coordinates from a file.
	*/
	void setCoordinateMethod(const UnsignedintID& cmet){fprintf_s(mFile,"connectAttr \"");cmet.write(mFile);fprintf_s(mFile,"\" \"%s.cmet\";\n",mName.c_str());}
	/*
	Tells the emitter the time step to emit for: this is
	the time since the last evaluation times the
	simulation rate scale.
	*/
	void setOverrideTimeStep(const TimeID& ots){fprintf_s(mFile,"connectAttr \"");ots.write(mFile);fprintf_s(mFile,"\" \"%s.ots\";\n",mName.c_str());}
	/*Scale the time step used in emission and solving*/
	void setSimulationRateScale(float srs){if(srs == 1) return; fprintf_s(mFile, "setAttr \".srs\" %f;\n", srs);}
	/*Scale the time step used in emission and solving*/
	void setSimulationRateScale(const FloatID& srs){fprintf_s(mFile,"connectAttr \"");srs.write(mFile);fprintf_s(mFile,"\" \"%s.srs\";\n",mName.c_str());}
	/*
	Which interpolation algorithm to use when retrieving values from
	fractional points within a fluid grid.
	Linear is the fastest. Linear with collisions or Hermite must be used
	for friction at boundaries to be computed. Hermite causes less
	diffusion than linear, but will make the simulation run several times
	more slowly, especially when one has collisions with geometry.
	*/
	void setGridInterpolator(unsigned int gdi){if(gdi == 0) return; fprintf_s(mFile, "setAttr \".gdi\" %i;\n", gdi);}
	/*
	Which interpolation algorithm to use when retrieving values from
	fractional points within a fluid grid.
	Linear is the fastest. Linear with collisions or Hermite must be used
	for friction at boundaries to be computed. Hermite causes less
	diffusion than linear, but will make the simulation run several times
	more slowly, especially when one has collisions with geometry.
	*/
	void setGridInterpolator(const UnsignedintID& gdi){fprintf_s(mFile,"connectAttr \"");gdi.write(mFile);fprintf_s(mFile,"\" \"%s.gdi\";\n",mName.c_str());}
	/*
	By requesting this attribute, the fluid will be forced to evaluate.
	used for runup.
	*/
	void setForceDynamics(bool fdn){if(fdn == false) return; fprintf_s(mFile, "setAttr \".fdn\" %i;\n", fdn);}
	/*
	Which solver to use. "Navier-Strokes" is a fast Navier-Stokes solver.
	"Spring Mesh" defines a simple water surface.
	*/
	void setSolver(unsigned int sol){if(sol == 1) return; fprintf_s(mFile, "setAttr \".sol\" %i;\n", sol);}
	/*
	Which solver to use. "Navier-Strokes" is a fast Navier-Stokes solver.
	"Spring Mesh" defines a simple water surface.
	*/
	void setSolver(const UnsignedintID& sol){fprintf_s(mFile,"connectAttr \"");sol.write(mFile);fprintf_s(mFile,"\" \"%s.sol\";\n",mName.c_str());}
	/*
	Increasing the quality will increase the number of steps used internally
	by the Navier-Stokes solver, which may increase the accuracy of
	the simulation and will certainly increase the time required to run.
	Depending on your fluids material properties, you may get satisfactory
	results lowering this from the default value of 20.
	*/
	void setSolverQuality(int sql){if(sql == 20) return; fprintf_s(mFile, "setAttr \".sql\" %i;\n", sql);}
	/*
	Increasing the quality will increase the number of steps used internally
	by the Navier-Stokes solver, which may increase the accuracy of
	the simulation and will certainly increase the time required to run.
	Depending on your fluids material properties, you may get satisfactory
	results lowering this from the default value of 20.
	*/
	void setSolverQuality(const IntID& sql){fprintf_s(mFile,"connectAttr \"");sql.write(mFile);fprintf_s(mFile,"\" \"%s.sql\";\n",mName.c_str());}
	/*
	This attribute can be used to create more detailed simulations
	without requiring higher resolution grids. With highDetailSolve
	turned off simulations will run faster, but there will be a lot
	of diffusion of both density and velocity as the the simulation
	progresses. The velocity grid is used not only to push around
	other grid values, like density, but it also pushes its own
	velocity values to new positions in the grid. Propagating velocity
	is much more computationally intensive than propagating scalar
	grid values like density, thus enabling Scalar and Velocity will
	increase the simulation compute time by a factor of 2, while
	enabling just the scalar grids only will not slow the solve
	by much. There will be much more detail in the flow, however,
	when using the scalar and velocity setting. In some cases
	the effect of high detail on a scalar grid such as density may
	not look smooth enough, in which case the velocity only method
	might be preferable.
	*/
	void setHighDetailSolve(unsigned int hds){if(hds == 0) return; fprintf_s(mFile, "setAttr \".hds\" %i;\n", hds);}
	/*
	This attribute can be used to create more detailed simulations
	without requiring higher resolution grids. With highDetailSolve
	turned off simulations will run faster, but there will be a lot
	of diffusion of both density and velocity as the the simulation
	progresses. The velocity grid is used not only to push around
	other grid values, like density, but it also pushes its own
	velocity values to new positions in the grid. Propagating velocity
	is much more computationally intensive than propagating scalar
	grid values like density, thus enabling Scalar and Velocity will
	increase the simulation compute time by a factor of 2, while
	enabling just the scalar grids only will not slow the solve
	by much. There will be much more detail in the flow, however,
	when using the scalar and velocity setting. In some cases
	the effect of high detail on a scalar grid such as density may
	not look smooth enough, in which case the velocity only method
	might be preferable.
	*/
	void setHighDetailSolve(const UnsignedintID& hds){fprintf_s(mFile,"connectAttr \"");hds.write(mFile);fprintf_s(mFile,"\" \"%s.hds\";\n",mName.c_str());}
	/*
	This controls the way the solver treats density at the boundaries.
	A closed boundary is like a wall. An open boundary allows outflows.
	A wrapping boundary causes flows that go off one side to enter in the
	opposite side. This can be useful if you wish to have a windy fog, yet
	do not want to continually replenish the density at the inflowing regions.
	*/
	void setBoundaryX(unsigned int bndx){if(bndx == 1) return; fprintf_s(mFile, "setAttr \".bndx\" %i;\n", bndx);}
	/*
	This controls the way the solver treats density at the boundaries.
	A closed boundary is like a wall. An open boundary allows outflows.
	A wrapping boundary causes flows that go off one side to enter in the
	opposite side. This can be useful if you wish to have a windy fog, yet
	do not want to continually replenish the density at the inflowing regions.
	*/
	void setBoundaryX(const UnsignedintID& bndx){fprintf_s(mFile,"connectAttr \"");bndx.write(mFile);fprintf_s(mFile,"\" \"%s.bndx\";\n",mName.c_str());}
	/*
	This controls the way the solver treats density at the boundaries.
	A closed boundary is like a wall. An open boundary allows outflows.
	A wrapping boundary causes flows that go off one side to enter in the
	opposite side. This can be useful if you wish to have a windy fog, yet
	do not want to continually replenish the density at the inflowing regions.
	*/
	void setBoundaryY(unsigned int bndy){if(bndy == 1) return; fprintf_s(mFile, "setAttr \".bndy\" %i;\n", bndy);}
	/*
	This controls the way the solver treats density at the boundaries.
	A closed boundary is like a wall. An open boundary allows outflows.
	A wrapping boundary causes flows that go off one side to enter in the
	opposite side. This can be useful if you wish to have a windy fog, yet
	do not want to continually replenish the density at the inflowing regions.
	*/
	void setBoundaryY(const UnsignedintID& bndy){fprintf_s(mFile,"connectAttr \"");bndy.write(mFile);fprintf_s(mFile,"\" \"%s.bndy\";\n",mName.c_str());}
	/*
	This controls the way the solver treats density at the boundaries.
	A closed boundary is like a wall. An open boundary allows outflows.
	A wrapping boundary causes flows that go off one side to enter in the
	opposite side. This can be useful if you wish to have a windy fog, yet
	do not want to continually replenish the density at the inflowing regions.
	*/
	void setBoundaryZ(unsigned int bndz){if(bndz == 1) return; fprintf_s(mFile, "setAttr \".bndz\" %i;\n", bndz);}
	/*
	This controls the way the solver treats density at the boundaries.
	A closed boundary is like a wall. An open boundary allows outflows.
	A wrapping boundary causes flows that go off one side to enter in the
	opposite side. This can be useful if you wish to have a windy fog, yet
	do not want to continually replenish the density at the inflowing regions.
	*/
	void setBoundaryZ(const UnsignedintID& bndz){fprintf_s(mFile,"connectAttr \"");bndz.write(mFile);fprintf_s(mFile,"\" \"%s.bndz\";\n",mName.c_str());}
	/*
	This attribute controls how density is converted to mass for
	field operations.
	*/
	void setMassConversion(double mcv){if(mcv == 1) return; fprintf_s(mFile, "setAttr \".mcv\" %f;\n", mcv);}
	/*
	This attribute controls how density is converted to mass for
	field operations.
	*/
	void setMassConversion(const DoubleID& mcv){fprintf_s(mFile,"connectAttr \"");mcv.write(mFile);fprintf_s(mFile,"\" \"%s.mcv\";\n",mName.c_str());}
	/*
	This defines how the optional grid of falloff values (used to soften
	the opacity of the fluid in user-defined ways) is defined.
	These values are only used if the Dropoff Shape is set to Grid.
	<b>Off</b> sets the grid to 0.0 across the volume, meaning that
	the fluid will become completely transparent everywhere.
	<b>Static Grid</b> Uses a grid without dynamic behavior to store the
	falloff values.
	*/
	void setFalloffMethod(unsigned int fmt){if(fmt == 0) return; fprintf_s(mFile, "setAttr \".fmt\" %i;\n", fmt);}
	/*
	This defines how the optional grid of falloff values (used to soften
	the opacity of the fluid in user-defined ways) is defined.
	These values are only used if the Dropoff Shape is set to Grid.
	<b>Off</b> sets the grid to 0.0 across the volume, meaning that
	the fluid will become completely transparent everywhere.
	<b>Static Grid</b> Uses a grid without dynamic behavior to store the
	falloff values.
	*/
	void setFalloffMethod(const UnsignedintID& fmt){fprintf_s(mFile,"connectAttr \"");fmt.write(mFile);fprintf_s(mFile,"\" \"%s.fmt\";\n",mName.c_str());}
	/*
	This defines how density is defined.
	<b>Off</b> sets the value to 0.0 across the volume.
	<b>Static Grid</b> Uses a grid without dynamic behavior.
	<b>Dynamic Grid</b> Uses a grid with a dynamic solver.
	<b>Gradient</b> ramps the value based on DensityGradient.
	*/
	void setDensityMethod(unsigned int dmt){if(dmt == 2) return; fprintf_s(mFile, "setAttr \".dmt\" %i;\n", dmt);}
	/*
	This defines how density is defined.
	<b>Off</b> sets the value to 0.0 across the volume.
	<b>Static Grid</b> Uses a grid without dynamic behavior.
	<b>Dynamic Grid</b> Uses a grid with a dynamic solver.
	<b>Gradient</b> ramps the value based on DensityGradient.
	*/
	void setDensityMethod(const UnsignedintID& dmt){fprintf_s(mFile,"connectAttr \"");dmt.write(mFile);fprintf_s(mFile,"\" \"%s.dmt\";\n",mName.c_str());}
	/*
	This defines how density can be ramped
	<b>Constant</b> sets the value to 1.0 across the volume.
	<b>X Gradient</b> ramps the value from zero to one along the X axis.
	<b>Y Gradient</b> ramps the value from zero to one along the Y axis.
	<b>Z Gradient</b> ramps the value from zero to one along the Z axis.
	<b>Center Gradient</b> ramps the value from one at the center to zero at the edges.
	*/
	void setDensityGradient(unsigned int dgr){if(dgr == 0) return; fprintf_s(mFile, "setAttr \".dgr\" %i;\n", dgr);}
	/*
	This defines how density can be ramped
	<b>Constant</b> sets the value to 1.0 across the volume.
	<b>X Gradient</b> ramps the value from zero to one along the X axis.
	<b>Y Gradient</b> ramps the value from zero to one along the Y axis.
	<b>Z Gradient</b> ramps the value from zero to one along the Z axis.
	<b>Center Gradient</b> ramps the value from one at the center to zero at the edges.
	*/
	void setDensityGradient(const UnsignedintID& dgr){fprintf_s(mFile,"connectAttr \"");dgr.write(mFile);fprintf_s(mFile,"\" \"%s.dgr\";\n",mName.c_str());}
	/*<b>Density Scale</b> multiplies the value determined by the <b>Density Method</b>*/
	void setDensityScale(float dsc){if(dsc == 0.5) return; fprintf_s(mFile, "setAttr \".dsc\" %f;\n", dsc);}
	/*<b>Density Scale</b> multiplies the value determined by the <b>Density Method</b>*/
	void setDensityScale(const FloatID& dsc){fprintf_s(mFile,"connectAttr \"");dsc.write(mFile);fprintf_s(mFile,"\" \"%s.dsc\";\n",mName.c_str());}
	/*How much the density dissipates.*/
	void setDensityDissipation(double dds){if(dds == 0) return; fprintf_s(mFile, "setAttr \".dds\" %f;\n", dds);}
	/*How much the density dissipates.*/
	void setDensityDissipation(const DoubleID& dds){fprintf_s(mFile,"connectAttr \"");dds.write(mFile);fprintf_s(mFile,"\" \"%s.dds\";\n",mName.c_str());}
	/*Diffusion of the density*/
	void setDensityDiffusion(double ddf){if(ddf == 0) return; fprintf_s(mFile, "setAttr \".ddf\" %f;\n", ddf);}
	/*Diffusion of the density*/
	void setDensityDiffusion(const DoubleID& ddf){fprintf_s(mFile,"connectAttr \"");ddf.write(mFile);fprintf_s(mFile,"\" \"%s.ddf\";\n",mName.c_str());}
	/*For the density update step - conserve mass on update or not.*/
	void setConserveMass(bool cm){if(cm == true) return; fprintf_s(mFile, "setAttr \".cm\" %i;\n", cm);}
	/*For the density update step - conserve mass on update or not.*/
	void setConserveMass(const BoolID& cm){fprintf_s(mFile,"connectAttr \"");cm.write(mFile);fprintf_s(mFile,"\" \"%s.cm\";\n",mName.c_str());}
	/*
	<b>Density Buoyancy</b> simulates a difference in mass density between the regions with
	density and the regions without. If the value is positive the density
	represents a substance that is lighter than the surrounding medium,
	like bubbles in water, and will thus rise. Negative values will cause the
	density to fall.
	*/
	void setDensityBuoyancy(float dsb){if(dsb == 1.0) return; fprintf_s(mFile, "setAttr \".dsb\" %f;\n", dsb);}
	/*
	<b>Density Buoyancy</b> simulates a difference in mass density between the regions with
	density and the regions without. If the value is positive the density
	represents a substance that is lighter than the surrounding medium,
	like bubbles in water, and will thus rise. Negative values will cause the
	density to fall.
	*/
	void setDensityBuoyancy(const FloatID& dsb){fprintf_s(mFile,"connectAttr \"");dsb.write(mFile);fprintf_s(mFile,"\" \"%s.dsb\";\n",mName.c_str());}
	/*
	Gravitational constant that simulates mass of the world the simulation is occuring on.
	Values of zero simulate being in outer space. Note that density and heat buoyancy will
	have no effect if gravity is zero.
	*/
	void setGravity(float grv){if(grv == 9.8) return; fprintf_s(mFile, "setAttr \".grv\" %f;\n", grv);}
	/*
	Gravitational constant that simulates mass of the world the simulation is occuring on.
	Values of zero simulate being in outer space. Note that density and heat buoyancy will
	have no effect if gravity is zero.
	*/
	void setGravity(const FloatID& grv){fprintf_s(mFile,"connectAttr \"");grv.write(mFile);fprintf_s(mFile,"\" \"%s.grv\";\n",mName.c_str());}
	/*
	This defines how velocity is defined.
	<b>Off</b> sets the value to (0.0,0.0,0.0) across the volume.
	<b>Center Gradient</b> ramps the value from (1.0,1.0,1.0) at the center to (0.0,0.0,0.0) at the edges.
	Both grid methods use a grid of points and interpolatefor in between values.
	These are the required methods if dynamic emitters are to be used.
	Also required if one wishes to paint values for this attribute.
	<b>Static Grid</b> Uses a grid without dynamic behavior.
	<b>Dynamic Grid</b> Uses a grid with a dynamic solver.
	<b>Gradient</b> ramps the value based on VelocityGradient.
	*/
	void setVelocityMethod(unsigned int vmt){if(vmt == 2) return; fprintf_s(mFile, "setAttr \".vmt\" %i;\n", vmt);}
	/*
	This defines how velocity is defined.
	<b>Off</b> sets the value to (0.0,0.0,0.0) across the volume.
	<b>Center Gradient</b> ramps the value from (1.0,1.0,1.0) at the center to (0.0,0.0,0.0) at the edges.
	Both grid methods use a grid of points and interpolatefor in between values.
	These are the required methods if dynamic emitters are to be used.
	Also required if one wishes to paint values for this attribute.
	<b>Static Grid</b> Uses a grid without dynamic behavior.
	<b>Dynamic Grid</b> Uses a grid with a dynamic solver.
	<b>Gradient</b> ramps the value based on VelocityGradient.
	*/
	void setVelocityMethod(const UnsignedintID& vmt){fprintf_s(mFile,"connectAttr \"");vmt.write(mFile);fprintf_s(mFile,"\" \"%s.vmt\";\n",mName.c_str());}
	/*
	This defines how velocity can be ramped
	<b>Constant</b> sets the value to 1.0 across the volume.
	<b>X Gradient</b> ramps the value from (0.0,0.0,0.0) to (1.0,1.0,1.0) along the X axis.
	<b>Y Gradient</b> ramps the value from (0.0,0.0,0.0) to (1.0,1.0,1.0) along the Y axis.
	<b>Z Gradient</b> ramps the value from (0.0,0.0,0.0) to (1.0,1.0,1.0) along the Z axis.
	<b>-X Gradient</b> ramps the value from (1.0,0.0,0.0) to (0.0,0.0,0.0) along the X axis.
	<b>-Y Gradient</b> ramps the value from (0.0,1.0,0.0) to (0.0,0.0,0.0) along the Y axis.
	<b>-Z Gradient</b> ramps the value from (0.0,0.0,1.0) to (0.0,0.0,0.0) along the Z axis.
	<b>Center Gradient</b> ramps the value from one at the center to zero at the edges.
	*/
	void setVelocityGradient(unsigned int vgr){if(vgr == 0) return; fprintf_s(mFile, "setAttr \".vgr\" %i;\n", vgr);}
	/*
	This defines how velocity can be ramped
	<b>Constant</b> sets the value to 1.0 across the volume.
	<b>X Gradient</b> ramps the value from (0.0,0.0,0.0) to (1.0,1.0,1.0) along the X axis.
	<b>Y Gradient</b> ramps the value from (0.0,0.0,0.0) to (1.0,1.0,1.0) along the Y axis.
	<b>Z Gradient</b> ramps the value from (0.0,0.0,0.0) to (1.0,1.0,1.0) along the Z axis.
	<b>-X Gradient</b> ramps the value from (1.0,0.0,0.0) to (0.0,0.0,0.0) along the X axis.
	<b>-Y Gradient</b> ramps the value from (0.0,1.0,0.0) to (0.0,0.0,0.0) along the Y axis.
	<b>-Z Gradient</b> ramps the value from (0.0,0.0,1.0) to (0.0,0.0,0.0) along the Z axis.
	<b>Center Gradient</b> ramps the value from one at the center to zero at the edges.
	*/
	void setVelocityGradient(const UnsignedintID& vgr){fprintf_s(mFile,"connectAttr \"");vgr.write(mFile);fprintf_s(mFile,"\" \"%s.vgr\";\n",mName.c_str());}
	/*<b>Velocity Scale</b> multiplies the value determined by the <b>Velocity Method</b>*/
	void setVelocityScale(const float3& vsc){if(vsc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".vsc\" -type \"float3\" ");vsc.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Velocity Scale</b> multiplies the value determined by the <b>Velocity Method</b>*/
	void setVelocityScale(const Float3ID& vsc){fprintf_s(mFile,"connectAttr \"");vsc.write(mFile);fprintf_s(mFile,"\" \"%s.vsc\";\n",mName.c_str());}
	/*The x component of the velocityScale*/
	void setVelocityScaleX(float vsx){if(vsx == 0.0) return; fprintf_s(mFile, "setAttr \".vsc.vsx\" %f;\n", vsx);}
	/*The x component of the velocityScale*/
	void setVelocityScaleX(const FloatID& vsx){fprintf_s(mFile,"connectAttr \"");vsx.write(mFile);fprintf_s(mFile,"\" \"%s.vsc.vsx\";\n",mName.c_str());}
	/*The y component of the velocityScale*/
	void setVelocityScaleY(float vsy){if(vsy == 0.0) return; fprintf_s(mFile, "setAttr \".vsc.vsy\" %f;\n", vsy);}
	/*The y component of the velocityScale*/
	void setVelocityScaleY(const FloatID& vsy){fprintf_s(mFile,"connectAttr \"");vsy.write(mFile);fprintf_s(mFile,"\" \"%s.vsc.vsy\";\n",mName.c_str());}
	/*The z component of the velocityScale*/
	void setVelocityScaleZ(float vsz){if(vsz == 0.0) return; fprintf_s(mFile, "setAttr \".vsc.vsz\" %f;\n", vsz);}
	/*The z component of the velocityScale*/
	void setVelocityScaleZ(const FloatID& vsz){fprintf_s(mFile,"connectAttr \"");vsz.write(mFile);fprintf_s(mFile,"\" \"%s.vsc.vsz\";\n",mName.c_str());}
	/*
	This parameter determines how thick and non-liquid the material is.
	At high values it is like tar, while at low values it is like water.
	When this is 1, the material reynolds number is 0, when it is 0,
	the reynolds number is 100000. At a value of 0.5 the reynolds is 1.
	*/
	void setViscosity(float viy){if(viy == 0) return; fprintf_s(mFile, "setAttr \".viy\" %f;\n", viy);}
	/*
	This parameter determines how thick and non-liquid the material is.
	At high values it is like tar, while at low values it is like water.
	When this is 1, the material reynolds number is 0, when it is 0,
	the reynolds number is 100000. At a value of 0.5 the reynolds is 1.
	*/
	void setViscosity(const FloatID& viy){fprintf_s(mFile,"connectAttr \"");viy.write(mFile);fprintf_s(mFile,"\" \"%s.viy\";\n",mName.c_str());}
	/*Internal Friction in velocity solving*/
	void setFriction(float fri){if(fri == 0) return; fprintf_s(mFile, "setAttr \".fri\" %f;\n", fri);}
	/*Internal Friction in velocity solving*/
	void setFriction(const FloatID& fri){fprintf_s(mFile,"connectAttr \"");fri.write(mFile);fprintf_s(mFile,"\" \"%s.fri\";\n",mName.c_str());}
	/*Amount of swirliness effects in velocity solution*/
	void setVelocitySwirl(float vsw){if(vsw == 0) return; fprintf_s(mFile, "setAttr \".vsw\" %f;\n", vsw);}
	/*Amount of swirliness effects in velocity solution*/
	void setVelocitySwirl(const FloatID& vsw){fprintf_s(mFile,"connectAttr \"");vsw.write(mFile);fprintf_s(mFile,"\" \"%s.vsw\";\n",mName.c_str());}
	/*
	Amount velocity solution is damped towards zero each time step.
	At a value the flow is totally suppressed. Small amounts of damping
	can be useful when boundaries are open to keep strong winds from
	building up and leading to instability.
	*/
	void setVelocityDamp(float vdp){if(vdp == 0) return; fprintf_s(mFile, "setAttr \".vdp\" %f;\n", vdp);}
	/*
	Amount velocity solution is damped towards zero each time step.
	At a value the flow is totally suppressed. Small amounts of damping
	can be useful when boundaries are open to keep strong winds from
	building up and leading to instability.
	*/
	void setVelocityDamp(const FloatID& vdp){fprintf_s(mFile,"connectAttr \"");vdp.write(mFile);fprintf_s(mFile,"\" \"%s.vdp\";\n",mName.c_str());}
	/*Turn on velocity solver.*/
	void setVelocityAdvect(bool va){if(va == true) return; fprintf_s(mFile, "setAttr \".va\" %i;\n", va);}
	/*Turn on velocity solver.*/
	void setVelocityAdvect(const BoolID& va){fprintf_s(mFile,"connectAttr \"");va.write(mFile);fprintf_s(mFile,"\" \"%s.va\";\n",mName.c_str());}
	/*Turn on projection for velocity solver*/
	void setVelocityProject(bool vi){if(vi == true) return; fprintf_s(mFile, "setAttr \".vi\" %i;\n", vi);}
	/*Turn on projection for velocity solver*/
	void setVelocityProject(const BoolID& vi){fprintf_s(mFile,"connectAttr \"");vi.write(mFile);fprintf_s(mFile,"\" \"%s.vi\";\n",mName.c_str());}
	/*
	Increasing this will increase the amount of force applied
	by the turbulence
	*/
	void setTurbulenceStrength(float tst){if(tst == 0) return; fprintf_s(mFile, "setAttr \".tst\" %f;\n", tst);}
	/*
	Increasing this will increase the amount of force applied
	by the turbulence
	*/
	void setTurbulenceStrength(const FloatID& tst){fprintf_s(mFile,"connectAttr \"");tst.write(mFile);fprintf_s(mFile,"\" \"%s.tst\";\n",mName.c_str());}
	/*
	Lowering this will make the turbulence vortices larger. This
	is a spacial scale factor on the turbulence function and has
	no effect if the turbulence strength is zero.
	*/
	void setTurbulenceFrequency(float tfr){if(tfr == 0.2) return; fprintf_s(mFile, "setAttr \".tfr\" %f;\n", tfr);}
	/*
	Lowering this will make the turbulence vortices larger. This
	is a spacial scale factor on the turbulence function and has
	no effect if the turbulence strength is zero.
	*/
	void setTurbulenceFrequency(const FloatID& tfr){fprintf_s(mFile,"connectAttr \"");tfr.write(mFile);fprintf_s(mFile,"\" \"%s.tfr\";\n",mName.c_str());}
	/*Rate at which turbulence pattern changes over time*/
	void setTurbulenceSpeed(float tbs){if(tbs == .2) return; fprintf_s(mFile, "setAttr \".tbs\" %f;\n", tbs);}
	/*Rate at which turbulence pattern changes over time*/
	void setTurbulenceSpeed(const FloatID& tbs){fprintf_s(mFile,"connectAttr \"");tbs.write(mFile);fprintf_s(mFile,"\" \"%s.tbs\";\n",mName.c_str());}
	/*Scale of turbulence pattern relative to the fluid*/
	void setTurbulenceRes(int trs){if(trs == 10) return; fprintf_s(mFile, "setAttr \".trs\" %i;\n", trs);}
	/*Scale of turbulence pattern relative to the fluid*/
	void setTurbulenceRes(const IntID& trs){fprintf_s(mFile,"connectAttr \"");trs.write(mFile);fprintf_s(mFile,"\" \"%s.trs\";\n",mName.c_str());}
	/*
	This defines how temperature is defined.
	<b>Off</b> sets the value to 0.0 across the volume.
	<b>Static Grid</b> Uses a grid without dynamic behavior.
	<b>Dynamic Grid</b> Uses a grid with a dynamic solver.
	<b>Gradient</b> ramps the value based on TemperatureGradient.
	*/
	void setTemperatureMethod(unsigned int tmet){if(tmet == 0) return; fprintf_s(mFile, "setAttr \".tmet\" %i;\n", tmet);}
	/*
	This defines how temperature is defined.
	<b>Off</b> sets the value to 0.0 across the volume.
	<b>Static Grid</b> Uses a grid without dynamic behavior.
	<b>Dynamic Grid</b> Uses a grid with a dynamic solver.
	<b>Gradient</b> ramps the value based on TemperatureGradient.
	*/
	void setTemperatureMethod(const UnsignedintID& tmet){fprintf_s(mFile,"connectAttr \"");tmet.write(mFile);fprintf_s(mFile,"\" \"%s.tmet\";\n",mName.c_str());}
	/*
	This defines how temperature can be ramped
	<b>Constant</b> sets the value to 1.0 across the volume.
	<b>X Gradient</b> ramps the value from zero to one along the X axis.
	<b>Y Gradient</b> ramps the value from zero to one along the Y axis.
	<b>Z Gradient</b> ramps the value from zero to one along the Z axis.
	<b>-X Gradient</b> ramps the value from one to zero along the X axis.
	<b>-Y Gradient</b> ramps the value from one to zero along the Y axis.
	<b>-Z Gradient</b> ramps the value from one to zero along the Z axis.
	<b>Center Gradient</b> ramps the value from one at the center to zero at the edges.
	*/
	void setTemperatureGradient(unsigned int tgr){if(tgr == 0) return; fprintf_s(mFile, "setAttr \".tgr\" %i;\n", tgr);}
	/*
	This defines how temperature can be ramped
	<b>Constant</b> sets the value to 1.0 across the volume.
	<b>X Gradient</b> ramps the value from zero to one along the X axis.
	<b>Y Gradient</b> ramps the value from zero to one along the Y axis.
	<b>Z Gradient</b> ramps the value from zero to one along the Z axis.
	<b>-X Gradient</b> ramps the value from one to zero along the X axis.
	<b>-Y Gradient</b> ramps the value from one to zero along the Y axis.
	<b>-Z Gradient</b> ramps the value from one to zero along the Z axis.
	<b>Center Gradient</b> ramps the value from one at the center to zero at the edges.
	*/
	void setTemperatureGradient(const UnsignedintID& tgr){fprintf_s(mFile,"connectAttr \"");tgr.write(mFile);fprintf_s(mFile,"\" \"%s.tgr\";\n",mName.c_str());}
	/*<b>Temperature Scale</b> multiplies the value determined by the <b>Temperature Method</b>*/
	void setTemperatureScale(float tmsc){if(tmsc == 1.0) return; fprintf_s(mFile, "setAttr \".tmsc\" %f;\n", tmsc);}
	/*<b>Temperature Scale</b> multiplies the value determined by the <b>Temperature Method</b>*/
	void setTemperatureScale(const FloatID& tmsc){fprintf_s(mFile,"connectAttr \"");tmsc.write(mFile);fprintf_s(mFile,"\" \"%s.tmsc\";\n",mName.c_str());}
	/*Rate at which the temperature dissipates*/
	void setTemperatureDissipation(double tds){if(tds == 0.1) return; fprintf_s(mFile, "setAttr \".tds\" %f;\n", tds);}
	/*Rate at which the temperature dissipates*/
	void setTemperatureDissipation(const DoubleID& tds){fprintf_s(mFile,"connectAttr \"");tds.write(mFile);fprintf_s(mFile,"\" \"%s.tds\";\n",mName.c_str());}
	/*Rate at which the temperature diffuses between voxels*/
	void setTemperatureDiffusion(double tdf){if(tdf == 0.1) return; fprintf_s(mFile, "setAttr \".tdf\" %f;\n", tdf);}
	/*Rate at which the temperature diffuses between voxels*/
	void setTemperatureDiffusion(const DoubleID& tdf){fprintf_s(mFile,"connectAttr \"");tdf.write(mFile);fprintf_s(mFile,"\" \"%s.tdf\";\n",mName.c_str());}
	/*Multiplier on the turbulence applied to the temperature*/
	void setTemperatureTurbulence(float ttb){if(ttb == 0.1) return; fprintf_s(mFile, "setAttr \".ttb\" %f;\n", ttb);}
	/*Multiplier on the turbulence applied to the temperature*/
	void setTemperatureTurbulence(const FloatID& ttb){fprintf_s(mFile,"connectAttr \"");ttb.write(mFile);fprintf_s(mFile,"\" \"%s.ttb\";\n",mName.c_str());}
	/*Built in buoyancy strength for temperature solving*/
	void setBuoyancy(float buo){if(buo == 3) return; fprintf_s(mFile, "setAttr \".buo\" %f;\n", buo);}
	/*Built in buoyancy strength for temperature solving*/
	void setBuoyancy(const FloatID& buo){fprintf_s(mFile,"connectAttr \"");buo.write(mFile);fprintf_s(mFile,"\" \"%s.buo\";\n",mName.c_str());}
	/*
	This defines how color is defined
	<b>Off</b> use the Shading Color instead
	<b>Static Grid</b> Uses a grid without dynamic behavior.
	<b>Dynamic Grid</b> Uses a grid with a dynamic solver.
	*/
	void setColorMethod(unsigned int cmt){if(cmt == 0) return; fprintf_s(mFile, "setAttr \".cmt\" %i;\n", cmt);}
	/*
	This defines how color is defined
	<b>Off</b> use the Shading Color instead
	<b>Static Grid</b> Uses a grid without dynamic behavior.
	<b>Dynamic Grid</b> Uses a grid with a dynamic solver.
	*/
	void setColorMethod(const UnsignedintID& cmt){fprintf_s(mFile,"connectAttr \"");cmt.write(mFile);fprintf_s(mFile,"\" \"%s.cmt\";\n",mName.c_str());}
	/*How much the color dissipates.*/
	void setColorDissipation(double cds){if(cds == 0) return; fprintf_s(mFile, "setAttr \".cds\" %f;\n", cds);}
	/*How much the color dissipates.*/
	void setColorDissipation(const DoubleID& cds){fprintf_s(mFile,"connectAttr \"");cds.write(mFile);fprintf_s(mFile,"\" \"%s.cds\";\n",mName.c_str());}
	/*Diffusion of the color*/
	void setColorDiffusion(double cdf){if(cdf == 0) return; fprintf_s(mFile, "setAttr \".cdf\" %f;\n", cdf);}
	/*Diffusion of the color*/
	void setColorDiffusion(const DoubleID& cdf){fprintf_s(mFile,"connectAttr \"");cdf.write(mFile);fprintf_s(mFile,"\" \"%s.cdf\";\n",mName.c_str());}
	/*
	This defines how the fuel value is defined.
	<b>Off</b> sets the value to 0.0 across the volume.
	<b>Dynamic Grid</b> Creates a grid for the fuel. This grid will
	be transported along with the density grid. The grid method must be
	used for the fuel to evolve over time.
	<b>Gradient</b> ramps the value based on FuelGradient.
	*/
	void setFuelMethod(unsigned int fmet){if(fmet == 0) return; fprintf_s(mFile, "setAttr \".fmet\" %i;\n", fmet);}
	/*
	This defines how the fuel value is defined.
	<b>Off</b> sets the value to 0.0 across the volume.
	<b>Dynamic Grid</b> Creates a grid for the fuel. This grid will
	be transported along with the density grid. The grid method must be
	used for the fuel to evolve over time.
	<b>Gradient</b> ramps the value based on FuelGradient.
	*/
	void setFuelMethod(const UnsignedintID& fmet){fprintf_s(mFile,"connectAttr \"");fmet.write(mFile);fprintf_s(mFile,"\" \"%s.fmet\";\n",mName.c_str());}
	/*
	This defines how fuel can be ramped
	<b>Constant</b> sets the value to 1.0 across the volume.
	<b>X Gradient</b> ramps the value from zero to one along the X axis.
	<b>Y Gradient</b> ramps the value from zero to one along the Y axis.
	<b>Z Gradient</b> ramps the value from zero to one along the Z axis.
	<b>-X Gradient</b> ramps the value from one to zero along the X axis.
	<b>-Y Gradient</b> ramps the value from one to zero along the Y axis.
	<b>-Z Gradient</b> ramps the value from one to zero along the Z axis.
	<b>Center Gradient</b> ramps the value from one at the center to zero at the edges.
	*/
	void setFuelGradient(unsigned int fgr){if(fgr == 0) return; fprintf_s(mFile, "setAttr \".fgr\" %i;\n", fgr);}
	/*
	This defines how fuel can be ramped
	<b>Constant</b> sets the value to 1.0 across the volume.
	<b>X Gradient</b> ramps the value from zero to one along the X axis.
	<b>Y Gradient</b> ramps the value from zero to one along the Y axis.
	<b>Z Gradient</b> ramps the value from zero to one along the Z axis.
	<b>-X Gradient</b> ramps the value from one to zero along the X axis.
	<b>-Y Gradient</b> ramps the value from one to zero along the Y axis.
	<b>-Z Gradient</b> ramps the value from one to zero along the Z axis.
	<b>Center Gradient</b> ramps the value from one at the center to zero at the edges.
	*/
	void setFuelGradient(const UnsignedintID& fgr){fprintf_s(mFile,"connectAttr \"");fgr.write(mFile);fprintf_s(mFile,"\" \"%s.fgr\";\n",mName.c_str());}
	/*<b>Fuel Scale</b> multiplies the value determined by the <b>Fuel Method</b>*/
	void setFuelScale(float fesc){if(fesc == 1.0) return; fprintf_s(mFile, "setAttr \".fesc\" %f;\n", fesc);}
	/*<b>Fuel Scale</b> multiplies the value determined by the <b>Fuel Method</b>*/
	void setFuelScale(const FloatID& fesc){fprintf_s(mFile,"connectAttr \"");fesc.write(mFile);fprintf_s(mFile,"\" \"%s.fesc\";\n",mName.c_str());}
	/*
	<b>Reaction Speed</b> determines how quickly the reaction converts
	from a value of 1 to zero when the temperature is at or above the
	<b>Max Reaction Temperature</b> value. A value of 1.0 will result in
	an instantanious reaction.
	*/
	void setReactionSpeed(float resp){if(resp == 0.05) return; fprintf_s(mFile, "setAttr \".resp\" %f;\n", resp);}
	/*
	<b>Reaction Speed</b> determines how quickly the reaction converts
	from a value of 1 to zero when the temperature is at or above the
	<b>Max Reaction Temperature</b> value. A value of 1.0 will result in
	an instantanious reaction.
	*/
	void setReactionSpeed(const FloatID& resp){fprintf_s(mFile,"connectAttr \"");resp.write(mFile);fprintf_s(mFile,"\" \"%s.resp\";\n",mName.c_str());}
	/*
	<b>Fuel Ignition Temp</b> determines the lowest temperature at
	which a reaction will occur. The reaction rate is zero at this
	temperature increasing to the value defined by the <b>Reaction Speed</b>
	at the <b>Max Reaction Temperature</b>.
	*/
	void setFuelIgnitionTemp(float fuit){if(fuit == 0.0) return; fprintf_s(mFile, "setAttr \".fuit\" %f;\n", fuit);}
	/*
	<b>Fuel Ignition Temp</b> determines the lowest temperature at
	which a reaction will occur. The reaction rate is zero at this
	temperature increasing to the value defined by the <b>Reaction Speed</b>
	at the <b>Max Reaction Temperature</b>.
	*/
	void setFuelIgnitionTemp(const FloatID& fuit){fprintf_s(mFile,"connectAttr \"");fuit.write(mFile);fprintf_s(mFile,"\" \"%s.fuit\";\n",mName.c_str());}
	/*
	<b>Max Reaction Temp</b> determines the temperature beyond which
	which a reaction occurs at the fastest speed.
	*/
	void setMaxReactionTemp(float mxrt){if(mxrt == 1.0) return; fprintf_s(mFile, "setAttr \".mxrt\" %f;\n", mxrt);}
	/*
	<b>Max Reaction Temp</b> determines the temperature beyond which
	which a reaction occurs at the fastest speed.
	*/
	void setMaxReactionTemp(const FloatID& mxrt){fprintf_s(mFile,"connectAttr \"");mxrt.write(mFile);fprintf_s(mFile,"\" \"%s.mxrt\";\n",mName.c_str());}
	/*
	<b>Heat Released</b> determines how much much heat is
	released into the temperature grid by a total reaction.
	This is how many reactions sustain themselves after an initial
	spark of ignition. The amount of heat added in a given step
	is proportional to the percentage of reacted material. One
	needs to have the <b>Temperature Method</b> set to Grid to use this
	option.
	*/
	void setHeatReleased(float hre){if(hre == 1.0) return; fprintf_s(mFile, "setAttr \".hre\" %f;\n", hre);}
	/*
	<b>Heat Released</b> determines how much much heat is
	released into the temperature grid by a total reaction.
	This is how many reactions sustain themselves after an initial
	spark of ignition. The amount of heat added in a given step
	is proportional to the percentage of reacted material. One
	needs to have the <b>Temperature Method</b> set to Grid to use this
	option.
	*/
	void setHeatReleased(const FloatID& hre){fprintf_s(mFile,"connectAttr \"");hre.write(mFile);fprintf_s(mFile,"\" \"%s.hre\";\n",mName.c_str());}
	/*
	<b>Light Released</b> determines how much much light is
	released by the reaction. This is directly added into the
	final incandescent intensity of the shading and does not
	input into any grids.
	*/
	void setLightReleased(float lre){if(lre == 0.0) return; fprintf_s(mFile, "setAttr \".lre\" %f;\n", lre);}
	/*
	<b>Light Released</b> determines how much much light is
	released by the reaction. This is directly added into the
	final incandescent intensity of the shading and does not
	input into any grids.
	*/
	void setLightReleased(const FloatID& lre){fprintf_s(mFile,"connectAttr \"");lre.write(mFile);fprintf_s(mFile,"\" \"%s.lre\";\n",mName.c_str());}
	/*
	<b>Light Color</b> is the color of the light released by
	the reaction. The parameter <b>Light Released</b> along with
	the amount of fuel reacted in a given time step scales
	the overall brightness of this light.
	*/
	void setLightColor(const float3& lco){fprintf_s(mFile, "setAttr \".lco\" -type \"float3\" ");lco.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Light Color</b> is the color of the light released by
	the reaction. The parameter <b>Light Released</b> along with
	the amount of fuel reacted in a given time step scales
	the overall brightness of this light.
	*/
	void setLightColor(const Float3ID& lco){fprintf_s(mFile,"connectAttr \"");lco.write(mFile);fprintf_s(mFile,"\" \"%s.lco\";\n",mName.c_str());}
	/*light color red value*/
	void setLightColorR(float lcor){if(lcor == 1.0) return; fprintf_s(mFile, "setAttr \".lco.lcor\" %f;\n", lcor);}
	/*light color red value*/
	void setLightColorR(const FloatID& lcor){fprintf_s(mFile,"connectAttr \"");lcor.write(mFile);fprintf_s(mFile,"\" \"%s.lco.lcor\";\n",mName.c_str());}
	/*light color green value*/
	void setLightColorG(float lcog){if(lcog == 1.0) return; fprintf_s(mFile, "setAttr \".lco.lcog\" %f;\n", lcog);}
	/*light color green value*/
	void setLightColorG(const FloatID& lcog){fprintf_s(mFile,"connectAttr \"");lcog.write(mFile);fprintf_s(mFile,"\" \"%s.lco.lcog\";\n",mName.c_str());}
	/*light color blue value*/
	void setLightColorB(float lcob){if(lcob == 1.0) return; fprintf_s(mFile, "setAttr \".lco.lcob\" %f;\n", lcob);}
	/*light color blue value*/
	void setLightColorB(const FloatID& lcob){fprintf_s(mFile,"connectAttr \"");lcob.write(mFile);fprintf_s(mFile,"\" \"%s.lco.lcob\";\n",mName.c_str());}
	/*
	Match the pre Maya7.0 dynamics behavior for the fluid.
	In 7.0 the damp, reactionSpeed and turbulence intensity
	were modified to preserve behavior when changing the
	frame rate or the sample rate. If you have loaded a fluid
	an older file this variable will automatically be enabled.
	If you wish the new behavior for such scenes use setAttr
	to turn off this attribute.
	*/
	void setUsePre70Dynamics(bool updy){if(updy == false) return; fprintf_s(mFile, "setAttr \".updy\" %i;\n", updy);}
	/*
	Match the pre Maya7.0 dynamics behavior for the fluid.
	In 7.0 the damp, reactionSpeed and turbulence intensity
	were modified to preserve behavior when changing the
	frame rate or the sample rate. If you have loaded a fluid
	an older file this variable will automatically be enabled.
	If you wish the new behavior for such scenes use setAttr
	to turn off this attribute.
	*/
	void setUsePre70Dynamics(const BoolID& updy){fprintf_s(mFile,"connectAttr \"");updy.write(mFile);fprintf_s(mFile,"\" \"%s.updy\";\n",mName.c_str());}
	/*Output implicit surface.*/
	void setOutMesh(const MeshID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*
	Data from dynamic nodes for computing new output force.
	The field gets data from a set of "points" (particles, locations
	on a rigid body, etc.) and returns a force computed for each
	point.  Arbitrary user-defined nodes can make use of the field
	as Tint32 as they can give data for a set of points and can interpret
	the outputs.  Nodes using the field should take care to set
	up their attributes so as not to cause a DG loop.
	*/
	void setInputData(size_t ind_i,const InputData& ind){fprintf_s(mFile, "setAttr \".ind[%i]\" ",ind_i);ind.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Data from dynamic nodes for computing new output force.
	The field gets data from a set of "points" (particles, locations
	on a rigid body, etc.) and returns a force computed for each
	point.  Arbitrary user-defined nodes can make use of the field
	as Tint32 as they can give data for a set of points and can interpret
	the outputs.  Nodes using the field should take care to set
	up their attributes so as not to cause a DG loop.
	*/
	void setInputData(size_t ind_i,const InputDataID& ind){fprintf_s(mFile,"connectAttr \"");ind.write(mFile);fprintf_s(mFile,"\" \"%s.ind[%i]\";\n",mName.c_str(),ind_i);}
	/*Input position array*/
	void setInputPositions(size_t ind_i,const vectorArray& inp){if(inp.size == 0) return; fprintf_s(mFile, "setAttr \".ind[%i].inp\" -type \"vectorArray\" ",ind_i);inp.write(mFile);fprintf_s(mFile,";\n");}
	/*Input position array*/
	void setInputPositions(size_t ind_i,const VectorArrayID& inp){fprintf_s(mFile,"connectAttr \"");inp.write(mFile);fprintf_s(mFile,"\" \"%s.ind[%i].inp\";\n",mName.c_str(),ind_i);}
	/*Input velocity array*/
	void setInputVelocities(size_t ind_i,const vectorArray& inv){if(inv.size == 0) return; fprintf_s(mFile, "setAttr \".ind[%i].inv\" -type \"vectorArray\" ",ind_i);inv.write(mFile);fprintf_s(mFile,";\n");}
	/*Input velocity array*/
	void setInputVelocities(size_t ind_i,const VectorArrayID& inv){fprintf_s(mFile,"connectAttr \"");inv.write(mFile);fprintf_s(mFile,"\" \"%s.ind[%i].inv\";\n",mName.c_str(),ind_i);}
	/*Input mass array*/
	void setInputMass(size_t ind_i,const doubleArray& inm){if(inm.size == 0) return; fprintf_s(mFile, "setAttr \".ind[%i].inm\" -type \"doubleArray\" ",ind_i);inm.write(mFile);fprintf_s(mFile,";\n");}
	/*Input mass array*/
	void setInputMass(size_t ind_i,const DoubleArrayID& inm){fprintf_s(mFile,"connectAttr \"");inm.write(mFile);fprintf_s(mFile,"\" \"%s.ind[%i].inm\";\n",mName.c_str(),ind_i);}
	/*
	Some fields may need deltaTime to compute force.  Of the standard
	nodes, vortex is the only one.  User-defined nodes can use this
	attribute if they wish.
	*/
	void setDeltaTime(size_t ind_i,const TimeID& dt){fprintf_s(mFile,"connectAttr \"");dt.write(mFile);fprintf_s(mFile,"\" \"%s.ind[%i].dt\";\n",mName.c_str(),ind_i);}
	/*
	Force data from dynamic nodes for computing new output force.
	If an array of forces is supplied here, the field will ADD its
	force to that array instead of writing it to outputForce.
	The particle shape uses this to gain some important efficiencies.
	*/
	void setInputForce2(size_t in2_i,const VectorArrayID& in2){fprintf_s(mFile,"connectAttr \"");in2.write(mFile);fprintf_s(mFile,"\" \"%s.in2[%i]\";\n",mName.c_str(),in2_i);}
	/*
	Force data output to dynamic nodes.
	The entries in this output array match the input entries
	in inputPositions et al.
	*/
	void setOutputForce(size_t of_i,const VectorArrayID& of){fprintf_s(mFile,"connectAttr \"");of.write(mFile);fprintf_s(mFile,"\" \"%s.of[%i]\";\n",mName.c_str(),of_i);}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you don't want the background to show through them.
	<p/>
	<b>Black Hole</b>:  The value of Matte Opacity is ignored, and all
	the matte for this material is set to be transparent.  Use this when
	you are creating substitute geometry in a scene, which is standing
	in for objects in a background image that you will be compositing with
	later.  Your stand-in objects will 'punch
	a hole' in the matte.  This allows other computer-generated
	geometry to pass behind your stand-in objects. Later, when
	foreground and background are composited, the results will be correct,
	with the background object showing through the 'black hole' areas.
	</ul>
	*/
	void setMatteOpacityMode(unsigned int mom){if(mom == 2) return; fprintf_s(mFile, "setAttr \".mom\" %i;\n", mom);}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you don't want the background to show through them.
	<p/>
	<b>Black Hole</b>:  The value of Matte Opacity is ignored, and all
	the matte for this material is set to be transparent.  Use this when
	you are creating substitute geometry in a scene, which is standing
	in for objects in a background image that you will be compositing with
	later.  Your stand-in objects will 'punch
	a hole' in the matte.  This allows other computer-generated
	geometry to pass behind your stand-in objects. Later, when
	foreground and background are composited, the results will be correct,
	with the background object showing through the 'black hole' areas.
	</ul>
	*/
	void setMatteOpacityMode(const UnsignedintID& mom){fprintf_s(mFile,"connectAttr \"");mom.write(mFile);fprintf_s(mFile,"\" \"%s.mom\";\n",mName.c_str());}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	void setMatteOpacity(float mog){if(mog == 1.0) return; fprintf_s(mFile, "setAttr \".mog\" %f;\n", mog);}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	void setMatteOpacity(const FloatID& mog){fprintf_s(mFile,"connectAttr \"");mog.write(mFile);fprintf_s(mFile,"\" \"%s.mog\";\n",mName.c_str());}
	/*The transform to go from eye to world space*/
	void setMatrixEyeToWorld(const FltMatrixID& e2w){fprintf_s(mFile,"connectAttr \"");e2w.write(mFile);fprintf_s(mFile,"\" \"%s.e2w\";\n",mName.c_str());}
	/*The transform to go from world to object space*/
	void setMatrixWorldToObject(const FltMatrixID& w2o){fprintf_s(mFile,"connectAttr \"");w2o.write(mFile);fprintf_s(mFile,"\" \"%s.w2o\";\n",mName.c_str());}
	/*The current start point of the volume interval*/
	void setPointWorld(const Float3ID& pw){fprintf_s(mFile,"connectAttr \"");pw.write(mFile);fprintf_s(mFile,"\" \"%s.pw\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointWorldX(const FloatID& pwx){fprintf_s(mFile,"connectAttr \"");pwx.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwx\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointWorldY(const FloatID& pwy){fprintf_s(mFile,"connectAttr \"");pwy.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointWorldZ(const FloatID& pwz){fprintf_s(mFile,"connectAttr \"");pwz.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwz\";\n",mName.c_str());}
	/*The end of the volume interval in world space.*/
	void setFarPointWorld(const Float3ID& fw){fprintf_s(mFile,"connectAttr \"");fw.write(mFile);fprintf_s(mFile,"\" \"%s.fw\";\n",mName.c_str());}
	/*The x-component of the world far-position.*/
	void setFarPointWorldX(const FloatID& fwx){fprintf_s(mFile,"connectAttr \"");fwx.write(mFile);fprintf_s(mFile,"\" \"%s.fw.fwx\";\n",mName.c_str());}
	/*The y-component of the world far-position.*/
	void setFarPointWorldY(const FloatID& fwy){fprintf_s(mFile,"connectAttr \"");fwy.write(mFile);fprintf_s(mFile,"\" \"%s.fw.fwy\";\n",mName.c_str());}
	/*The z-component of the world far-position.*/
	void setFarPointWorldZ(const FloatID& fwz){fprintf_s(mFile,"connectAttr \"");fwz.write(mFile);fprintf_s(mFile,"\" \"%s.fw.fwz\";\n",mName.c_str());}
	/*The current start point of the volume interval in object space*/
	void setPointObj(const Float3ID& po){fprintf_s(mFile,"connectAttr \"");po.write(mFile);fprintf_s(mFile,"\" \"%s.po\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointObjX(const FloatID& pox){fprintf_s(mFile,"connectAttr \"");pox.write(mFile);fprintf_s(mFile,"\" \"%s.po.pox\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointObjY(const FloatID& poy){fprintf_s(mFile,"connectAttr \"");poy.write(mFile);fprintf_s(mFile,"\" \"%s.po.poy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointObjZ(const FloatID& poz){fprintf_s(mFile,"connectAttr \"");poz.write(mFile);fprintf_s(mFile,"\" \"%s.po.poz\";\n",mName.c_str());}
	/*The end of the volume interval in world space.*/
	void setFarPointObj(const Float3ID& fo){fprintf_s(mFile,"connectAttr \"");fo.write(mFile);fprintf_s(mFile,"\" \"%s.fo\";\n",mName.c_str());}
	/*The x-component of the object space far-position.*/
	void setFarPointObjectX(const FloatID& fox){fprintf_s(mFile,"connectAttr \"");fox.write(mFile);fprintf_s(mFile,"\" \"%s.fo.fox\";\n",mName.c_str());}
	/*The y-component of the object space far-position.*/
	void setFarPointObjectY(const FloatID& foy){fprintf_s(mFile,"connectAttr \"");foy.write(mFile);fprintf_s(mFile,"\" \"%s.fo.foy\";\n",mName.c_str());}
	/*The z-component of the object space far-position.*/
	void setFarPointObjectZ(const FloatID& foz){fprintf_s(mFile,"connectAttr \"");foz.write(mFile);fprintf_s(mFile,"\" \"%s.fo.foz\";\n",mName.c_str());}
	/*
	Unique ray identifier controlling the sampling distribution for
	volume light depth map shadows, fluid volume rendering, light
	fog, ray traced shadows, and motion blur.
	*/
	void setRayInstance(const IntID& ryi){fprintf_s(mFile,"connectAttr \"");ryi.write(mFile);fprintf_s(mFile,"\" \"%s.ryi\";\n",mName.c_str());}
	/*Determines whether self-shadowing should be computed or not*/
	void setSelfShadowing(bool ss){if(ss == false) return; fprintf_s(mFile, "setAttr \".ss\" %i;\n", ss);}
	/*Determines whether self-shadowing should be computed or not*/
	void setSelfShadowing(const BoolID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*<b>Quality</b> determines the quality (number of samples per ray) used in the rendering*/
	void setQuality(float qua){if(qua == 1.0) return; fprintf_s(mFile, "setAttr \".qua\" %f;\n", qua);}
	/*<b>Quality</b> determines the quality (number of samples per ray) used in the rendering*/
	void setQuality(const FloatID& qua){fprintf_s(mFile,"connectAttr \"");qua.write(mFile);fprintf_s(mFile,"\" \"%s.qua\";\n",mName.c_str());}
	/*
	Which interpolation algorithm to use when retrieving values from
	fractional points within a fluid grid when shading a ray. Sharply
	contrasting densitys may show grid artifacts( like a mesh with no
	normal smoothing ) with linear interpolation. Smooth interpolation
	renders slower, but gets rid of these problems.
	*/
	void setRenderInterpolator(unsigned int rin){if(rin == 0) return; fprintf_s(mFile, "setAttr \".rin\" %i;\n", rin);}
	/*
	Which interpolation algorithm to use when retrieving values from
	fractional points within a fluid grid when shading a ray. Sharply
	contrasting densitys may show grid artifacts( like a mesh with no
	normal smoothing ) with linear interpolation. Smooth interpolation
	renders slower, but gets rid of these problems.
	*/
	void setRenderInterpolator(const UnsignedintID& rin){fprintf_s(mFile,"connectAttr \"");rin.write(mFile);fprintf_s(mFile,"\" \"%s.rin\";\n",mName.c_str());}
	/*
	<b>Color</b> defines a range of color values used to render the volume.
	The particular color selected from this range is determined by the
	<b>Color Input</b> parameter. The color represents how much
	incoming light is absorbed or scattered. If it is black all
	light is absorbed, while white materials scatter all incoming light.
	*/
	void setColor(size_t cl_i,const Color& cl){fprintf_s(mFile, "setAttr \".cl[%i]\" ",cl_i);cl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color</b> defines a range of color values used to render the volume.
	The particular color selected from this range is determined by the
	<b>Color Input</b> parameter. The color represents how much
	incoming light is absorbed or scattered. If it is black all
	light is absorbed, while white materials scatter all incoming light.
	*/
	void setColor(size_t cl_i,const ColorID& cl){fprintf_s(mFile,"connectAttr \"");cl.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i]\";\n",mName.c_str(),cl_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setColor_Position(size_t cl_i,float clp){if(clp == 0.0) return; fprintf_s(mFile, "setAttr \".cl[%i].clp\" %f;\n", cl_i,clp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setColor_Position(size_t cl_i,const FloatID& clp){fprintf_s(mFile,"connectAttr \"");clp.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i].clp\";\n",mName.c_str(),cl_i);}
	/*Ramp color at the sibling position*/
	void setColor_Color(size_t cl_i,const float3& clc){fprintf_s(mFile, "setAttr \".cl[%i].clc\" -type \"float3\" ",cl_i);clc.write(mFile);fprintf_s(mFile,";\n");}
	/*Ramp color at the sibling position*/
	void setColor_Color(size_t cl_i,const Float3ID& clc){fprintf_s(mFile,"connectAttr \"");clc.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i].clc\";\n",mName.c_str(),cl_i);}
	/*Ramp red channel value at the sibling position*/
	void setColor_ColorR(size_t cl_i,float clcr){if(clcr == 0.0) return; fprintf_s(mFile, "setAttr \".cl[%i].clc.clcr\" %f;\n", cl_i,clcr);}
	/*Ramp red channel value at the sibling position*/
	void setColor_ColorR(size_t cl_i,const FloatID& clcr){fprintf_s(mFile,"connectAttr \"");clcr.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i].clc.clcr\";\n",mName.c_str(),cl_i);}
	/*Ramp green channel value at the sibling position*/
	void setColor_ColorG(size_t cl_i,float clcg){if(clcg == 0.0) return; fprintf_s(mFile, "setAttr \".cl[%i].clc.clcg\" %f;\n", cl_i,clcg);}
	/*Ramp green channel value at the sibling position*/
	void setColor_ColorG(size_t cl_i,const FloatID& clcg){fprintf_s(mFile,"connectAttr \"");clcg.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i].clc.clcg\";\n",mName.c_str(),cl_i);}
	/*Ramp blue channel value at the sibling position*/
	void setColor_ColorB(size_t cl_i,float clcb){if(clcb == 0.0) return; fprintf_s(mFile, "setAttr \".cl[%i].clc.clcb\" %f;\n", cl_i,clcb);}
	/*Ramp blue channel value at the sibling position*/
	void setColor_ColorB(size_t cl_i,const FloatID& clcb){fprintf_s(mFile,"connectAttr \"");clcb.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i].clc.clcb\";\n",mName.c_str(),cl_i);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setColor_Interp(size_t cl_i,unsigned int cli){if(cli == 0) return; fprintf_s(mFile, "setAttr \".cl[%i].cli\" %i;\n", cl_i,cli);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setColor_Interp(size_t cl_i,const UnsignedintID& cli){fprintf_s(mFile,"connectAttr \"");cli.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i].cli\";\n",mName.c_str(),cl_i);}
	/*
	Defines a the attribute used to index the color value.
	<b>Constant</b> sets the input to 1.0 or the end of the ramp.
	<b>Color</b> overrides the color range using the value defined by the
	grid and the color scale. This is useful when using color emission
	into the grid.
	The other options all sets the input to corresponding value from the grid.
	For example if density is used the start of the color ramp will be
	used for density values of 0 and the end value for densities of 1.0.
	The way midrange values map out is determined by the <b>Color Input Bias</b>
	*/
	void setColorInput(unsigned int coi){if(coi == 0) return; fprintf_s(mFile, "setAttr \".coi\" %i;\n", coi);}
	/*
	Defines a the attribute used to index the color value.
	<b>Constant</b> sets the input to 1.0 or the end of the ramp.
	<b>Color</b> overrides the color range using the value defined by the
	grid and the color scale. This is useful when using color emission
	into the grid.
	The other options all sets the input to corresponding value from the grid.
	For example if density is used the start of the color ramp will be
	used for density values of 0 and the end value for densities of 1.0.
	The way midrange values map out is determined by the <b>Color Input Bias</b>
	*/
	void setColorInput(const UnsignedintID& coi){fprintf_s(mFile,"connectAttr \"");coi.write(mFile);fprintf_s(mFile,"\" \"%s.coi\";\n",mName.c_str());}
	/*
	<b>Color Input Bias</b> adjusts the sensitivity of the selected
	color input used. Input values of 0 and 1 will always map to the
	start and end of the ramp value, although the bias determines
	where in the ramp a value of 0.5 will index. For example if one
	used density as an input, and the material becomes relatively
	opaque at a density of 0.001, then the density bias can be used
	to shift most of the ramp into this density range. This is easier
	Instead of cramming several values at the beginning of the ramp
	one can use the full range. If the input bias is 0.0 then a
	value of 0.5 will map to the exact middle of the color ramp.
	*/
	void setColorInputBias(float cib){if(cib == 0.0) return; fprintf_s(mFile, "setAttr \".cib\" %f;\n", cib);}
	/*
	<b>Color Input Bias</b> adjusts the sensitivity of the selected
	color input used. Input values of 0 and 1 will always map to the
	start and end of the ramp value, although the bias determines
	where in the ramp a value of 0.5 will index. For example if one
	used density as an input, and the material becomes relatively
	opaque at a density of 0.001, then the density bias can be used
	to shift most of the ramp into this density range. This is easier
	Instead of cramming several values at the beginning of the ramp
	one can use the full range. If the input bias is 0.0 then a
	value of 0.5 will map to the exact middle of the color ramp.
	*/
	void setColorInputBias(const FloatID& cib){fprintf_s(mFile,"connectAttr \"");cib.write(mFile);fprintf_s(mFile,"\" \"%s.cib\";\n",mName.c_str());}
	/*
	<b>Opacity</b> defines a range of opacity values used to render the volume.
	The particular opacity value selected from this range is determined by the
	<b>Opacity Input</b> parameter. The opacity represents how much the material
	will block light. If the opacity is zero then the material is totally transparent.
	*/
	void setOpacity(size_t opa_i,const Opacity& opa){fprintf_s(mFile, "setAttr \".opa[%i]\" ",opa_i);opa.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Opacity</b> defines a range of opacity values used to render the volume.
	The particular opacity value selected from this range is determined by the
	<b>Opacity Input</b> parameter. The opacity represents how much the material
	will block light. If the opacity is zero then the material is totally transparent.
	*/
	void setOpacity(size_t opa_i,const OpacityID& opa){fprintf_s(mFile,"connectAttr \"");opa.write(mFile);fprintf_s(mFile,"\" \"%s.opa[%i]\";\n",mName.c_str(),opa_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setOpacity_Position(size_t opa_i,float opap){if(opap == 0.0) return; fprintf_s(mFile, "setAttr \".opa[%i].opap\" %f;\n", opa_i,opap);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setOpacity_Position(size_t opa_i,const FloatID& opap){fprintf_s(mFile,"connectAttr \"");opap.write(mFile);fprintf_s(mFile,"\" \"%s.opa[%i].opap\";\n",mName.c_str(),opa_i);}
	/*Ramp value at the sibling position*/
	void setOpacity_FloatValue(size_t opa_i,float opafv){if(opafv == 0.0) return; fprintf_s(mFile, "setAttr \".opa[%i].opafv\" %f;\n", opa_i,opafv);}
	/*Ramp value at the sibling position*/
	void setOpacity_FloatValue(size_t opa_i,const FloatID& opafv){fprintf_s(mFile,"connectAttr \"");opafv.write(mFile);fprintf_s(mFile,"\" \"%s.opa[%i].opafv\";\n",mName.c_str(),opa_i);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setOpacity_Interp(size_t opa_i,unsigned int opai){if(opai == 0) return; fprintf_s(mFile, "setAttr \".opa[%i].opai\" %i;\n", opa_i,opai);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setOpacity_Interp(size_t opa_i,const UnsignedintID& opai){fprintf_s(mFile,"connectAttr \"");opai.write(mFile);fprintf_s(mFile,"\" \"%s.opa[%i].opai\";\n",mName.c_str(),opa_i);}
	/*
	Defines a the attribute used to index the opacity value.
	<b>Constant</b> sets the input to 1.0 or the end of the curve.
	The other options all sets the input to corresponding value from the grid.
	For example if density is used the start of the curve will be
	used for density values of 0 and the end value for densities of 1.0.
	The way midrange values map out is determined by the <b>Opacity Input Bias</b>
	*/
	void setOpacityInput(unsigned int opi){if(opi == 5) return; fprintf_s(mFile, "setAttr \".opi\" %i;\n", opi);}
	/*
	Defines a the attribute used to index the opacity value.
	<b>Constant</b> sets the input to 1.0 or the end of the curve.
	The other options all sets the input to corresponding value from the grid.
	For example if density is used the start of the curve will be
	used for density values of 0 and the end value for densities of 1.0.
	The way midrange values map out is determined by the <b>Opacity Input Bias</b>
	*/
	void setOpacityInput(const UnsignedintID& opi){fprintf_s(mFile,"connectAttr \"");opi.write(mFile);fprintf_s(mFile,"\" \"%s.opi\";\n",mName.c_str());}
	/*
	<b>Opacity Input Bias</b> adjusts the sensitivity of the selected
	opacity input used. Input values of 0 and 1 will always map to the
	start and end of the opacity curve, although the bias determines
	where in the curve a value of 0.5 will index. For example if one
	used density as an input, and one wishes the material to become
	opaque at a density of 0.001, then the density bias can be used
	to shift most of the curve into this density range.
	Instead of cramming several values at the beginning of the ramp
	one can use the full range. If the input bias is 0.0 then a
	value of 0.5 will map to the exact middle of the opacity curve.
	*/
	void setOpacityInputBias(float oib){if(oib == 0.0) return; fprintf_s(mFile, "setAttr \".oib\" %f;\n", oib);}
	/*
	<b>Opacity Input Bias</b> adjusts the sensitivity of the selected
	opacity input used. Input values of 0 and 1 will always map to the
	start and end of the opacity curve, although the bias determines
	where in the curve a value of 0.5 will index. For example if one
	used density as an input, and one wishes the material to become
	opaque at a density of 0.001, then the density bias can be used
	to shift most of the curve into this density range.
	Instead of cramming several values at the beginning of the ramp
	one can use the full range. If the input bias is 0.0 then a
	value of 0.5 will map to the exact middle of the opacity curve.
	*/
	void setOpacityInputBias(const FloatID& oib){fprintf_s(mFile,"connectAttr \"");oib.write(mFile);fprintf_s(mFile,"\" \"%s.oib\";\n",mName.c_str());}
	/*
	<b>Transparency</b> combined with <b>Opacity</b> determine how
	much light can penetrate the defined density. Transparency scales
	the single channel opacity value allowing for a colored opacity.
	Note that a transparency of 0.5 0.5 0.5 may render
	slightly faster than other values.
	*/
	void setTransparency(const float3& t){fprintf_s(mFile, "setAttr \".t\" -type \"float3\" ");t.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Transparency</b> combined with <b>Opacity</b> determine how
	much light can penetrate the defined density. Transparency scales
	the single channel opacity value allowing for a colored opacity.
	Note that a transparency of 0.5 0.5 0.5 may render
	slightly faster than other values.
	*/
	void setTransparency(const Float3ID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*transparency red value*/
	void setTransparencyR(float tr){if(tr == 0.25) return; fprintf_s(mFile, "setAttr \".t.tr\" %f;\n", tr);}
	/*transparency red value*/
	void setTransparencyR(const FloatID& tr){fprintf_s(mFile,"connectAttr \"");tr.write(mFile);fprintf_s(mFile,"\" \"%s.t.tr\";\n",mName.c_str());}
	/*transparency green value*/
	void setTransparencyG(float tg){if(tg == 0.25) return; fprintf_s(mFile, "setAttr \".t.tg\" %f;\n", tg);}
	/*transparency green value*/
	void setTransparencyG(const FloatID& tg){fprintf_s(mFile,"connectAttr \"");tg.write(mFile);fprintf_s(mFile,"\" \"%s.t.tg\";\n",mName.c_str());}
	/*transparency blue value*/
	void setTransparencyB(float tb){if(tb == 0.25) return; fprintf_s(mFile, "setAttr \".t.tb\" %f;\n", tb);}
	/*transparency blue value*/
	void setTransparencyB(const FloatID& tb){fprintf_s(mFile,"connectAttr \"");tb.write(mFile);fprintf_s(mFile,"\" \"%s.t.tb\";\n",mName.c_str());}
	/*
	<b>ShadowOpacity</b> used to brighten-up or darken shadows
	cast from the volume. At 0.5 the shadows are attenuated in exact
	proportion to the transparency of the volume. At 0.0 no shadowing
	occurs and at 1.0 shadows are completely black and the volume is
	totally in shadow. To account for multiple-scattering values
	less than 0.5 can help make thick clouds appear more translucent.
	Values above 0.5 make the clouds unnaturally opaque to lights, but
	may be useful to accentuate self shadowing.
	*/
	void setShadowOpacity(float shp){if(shp == 0.5) return; fprintf_s(mFile, "setAttr \".shp\" %f;\n", shp);}
	/*
	<b>ShadowOpacity</b> used to brighten-up or darken shadows
	cast from the volume. At 0.5 the shadows are attenuated in exact
	proportion to the transparency of the volume. At 0.0 no shadowing
	occurs and at 1.0 shadows are completely black and the volume is
	totally in shadow. To account for multiple-scattering values
	less than 0.5 can help make thick clouds appear more translucent.
	Values above 0.5 make the clouds unnaturally opaque to lights, but
	may be useful to accentuate self shadowing.
	*/
	void setShadowOpacity(const FloatID& shp){fprintf_s(mFile,"connectAttr \"");shp.write(mFile);fprintf_s(mFile,"\" \"%s.shp\";\n",mName.c_str());}
	/*
	<b>Incandescence</b> controls the amount of light emitted from
	regions of density due to self illumination. The
	The particular color selected from this range is determined by the
	<b>Incandescence Input</b> parameter. Incandescent emission is not
	affected by illumination or shadowing.
	*/
	void setIncandescence(size_t i_i,const Incandescence& i){fprintf_s(mFile, "setAttr \".i[%i]\" ",i_i);i.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Incandescence</b> controls the amount of light emitted from
	regions of density due to self illumination. The
	The particular color selected from this range is determined by the
	<b>Incandescence Input</b> parameter. Incandescent emission is not
	affected by illumination or shadowing.
	*/
	void setIncandescence(size_t i_i,const IncandescenceID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i]\";\n",mName.c_str(),i_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setIncandescence_Position(size_t i_i,float ip){if(ip == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].ip\" %f;\n", i_i,ip);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setIncandescence_Position(size_t i_i,const FloatID& ip){fprintf_s(mFile,"connectAttr \"");ip.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].ip\";\n",mName.c_str(),i_i);}
	/*Ramp color at the sibling position*/
	void setIncandescence_Color(size_t i_i,const float3& ic){fprintf_s(mFile, "setAttr \".i[%i].ic\" -type \"float3\" ",i_i);ic.write(mFile);fprintf_s(mFile,";\n");}
	/*Ramp color at the sibling position*/
	void setIncandescence_Color(size_t i_i,const Float3ID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].ic\";\n",mName.c_str(),i_i);}
	/*Ramp red channel value at the sibling position*/
	void setIncandescence_ColorR(size_t i_i,float icr){if(icr == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].ic.icr\" %f;\n", i_i,icr);}
	/*Ramp red channel value at the sibling position*/
	void setIncandescence_ColorR(size_t i_i,const FloatID& icr){fprintf_s(mFile,"connectAttr \"");icr.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].ic.icr\";\n",mName.c_str(),i_i);}
	/*Ramp green channel value at the sibling position*/
	void setIncandescence_ColorG(size_t i_i,float icg){if(icg == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].ic.icg\" %f;\n", i_i,icg);}
	/*Ramp green channel value at the sibling position*/
	void setIncandescence_ColorG(size_t i_i,const FloatID& icg){fprintf_s(mFile,"connectAttr \"");icg.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].ic.icg\";\n",mName.c_str(),i_i);}
	/*Ramp blue channel value at the sibling position*/
	void setIncandescence_ColorB(size_t i_i,float icb){if(icb == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].ic.icb\" %f;\n", i_i,icb);}
	/*Ramp blue channel value at the sibling position*/
	void setIncandescence_ColorB(size_t i_i,const FloatID& icb){fprintf_s(mFile,"connectAttr \"");icb.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].ic.icb\";\n",mName.c_str(),i_i);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setIncandescence_Interp(size_t i_i,unsigned int ii){if(ii == 0) return; fprintf_s(mFile, "setAttr \".i[%i].ii\" %i;\n", i_i,ii);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setIncandescence_Interp(size_t i_i,const UnsignedintID& ii){fprintf_s(mFile,"connectAttr \"");ii.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].ii\";\n",mName.c_str(),i_i);}
	/*
	Defines a the attribute used to index the incandescence value.
	<b>Constant</b> sets the input to 1.0 or the end of the ramp.
	<b>Color</b> overrides the incandescence range using the value defined by the
	grid and the color scale. This is useful when using color emission
	into the grid.
	The other options all sets the input to corresponding value from the grid.
	For example if density is used the start of the color ramp will be
	used for density values of 0 and the end value for densities of 1.0.
	The way midrange values map out is determined by the <b>Incandescence Input Bias</b>
	*/
	void setIncandescenceInput(unsigned int ili){if(ili == 6) return; fprintf_s(mFile, "setAttr \".ili\" %i;\n", ili);}
	/*
	Defines a the attribute used to index the incandescence value.
	<b>Constant</b> sets the input to 1.0 or the end of the ramp.
	<b>Color</b> overrides the incandescence range using the value defined by the
	grid and the color scale. This is useful when using color emission
	into the grid.
	The other options all sets the input to corresponding value from the grid.
	For example if density is used the start of the color ramp will be
	used for density values of 0 and the end value for densities of 1.0.
	The way midrange values map out is determined by the <b>Incandescence Input Bias</b>
	*/
	void setIncandescenceInput(const UnsignedintID& ili){fprintf_s(mFile,"connectAttr \"");ili.write(mFile);fprintf_s(mFile,"\" \"%s.ili\";\n",mName.c_str());}
	/*
	<b>Incandescence Input Bias</b> adjusts the sensitivity of the selected
	incandescence input used. Input values of 0 and 1 will always map to the
	start and end of the ramp value, although the bias determines
	where in the ramp a value of 0.5 will index. For example if one
	used density as an input, and the material becomes relatively
	opaque at a density of 0.001, then the density bias can be used
	to shift most of the ramp into this density range. This is easier
	Instead of cramming several values at the beginning of the ramp
	one can use the full range. If the input bias is 0.0 then a
	value of 0.5 will map to the exact middle of the incandescence ramp.
	*/
	void setIncandescenceInputBias(float iib){if(iib == 0.0) return; fprintf_s(mFile, "setAttr \".iib\" %f;\n", iib);}
	/*
	<b>Incandescence Input Bias</b> adjusts the sensitivity of the selected
	incandescence input used. Input values of 0 and 1 will always map to the
	start and end of the ramp value, although the bias determines
	where in the ramp a value of 0.5 will index. For example if one
	used density as an input, and the material becomes relatively
	opaque at a density of 0.001, then the density bias can be used
	to shift most of the ramp into this density range. This is easier
	Instead of cramming several values at the beginning of the ramp
	one can use the full range. If the input bias is 0.0 then a
	value of 0.5 will map to the exact middle of the incandescence ramp.
	*/
	void setIncandescenceInputBias(const FloatID& iib){fprintf_s(mFile,"connectAttr \"");iib.write(mFile);fprintf_s(mFile,"\" \"%s.iib\";\n",mName.c_str());}
	/*
	<b>Glow Intensity</b> is 0 by default, meaning that no glow is added to the
	material.  As this is turned up, the material seems to 'glow'
	with a faint halo of light around it.
	<p/>Note that this is different from the Incandescence attribute
	in a few important ways.  First, glow is added as a post-process
	at the end of rendering.  (Incandescence just makes the surface
	appear brighter.)  Second, glow adds a halo, which incandescence
	does not.
	*/
	void setGlowIntensity(float gi){if(gi == 0.0) return; fprintf_s(mFile, "setAttr \".gi\" %f;\n", gi);}
	/*
	<b>Glow Intensity</b> is 0 by default, meaning that no glow is added to the
	material.  As this is turned up, the material seems to 'glow'
	with a faint halo of light around it.
	<p/>Note that this is different from the Incandescence attribute
	in a few important ways.  First, glow is added as a post-process
	at the end of rendering.  (Incandescence just makes the surface
	appear brighter.)  Second, glow adds a halo, which incandescence
	does not.
	*/
	void setGlowIntensity(const FloatID& gi){fprintf_s(mFile,"connectAttr \"");gi.write(mFile);fprintf_s(mFile,"\" \"%s.gi\";\n",mName.c_str());}
	/*
	<b>Specular</b> controls the amount of light emitted from
	regions of density due to self illumination.
	*/
	void setSpecularColor(const float3& spc){fprintf_s(mFile, "setAttr \".spc\" -type \"float3\" ");spc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Specular</b> controls the amount of light emitted from
	regions of density due to self illumination.
	*/
	void setSpecularColor(const Float3ID& spc){fprintf_s(mFile,"connectAttr \"");spc.write(mFile);fprintf_s(mFile,"\" \"%s.spc\";\n",mName.c_str());}
	/*specular red value*/
	void setSpecularColorR(float spr){if(spr == 0.0) return; fprintf_s(mFile, "setAttr \".spc.spr\" %f;\n", spr);}
	/*specular red value*/
	void setSpecularColorR(const FloatID& spr){fprintf_s(mFile,"connectAttr \"");spr.write(mFile);fprintf_s(mFile,"\" \"%s.spc.spr\";\n",mName.c_str());}
	/*specular green value*/
	void setSpecularColorG(float spg){if(spg == 0.0) return; fprintf_s(mFile, "setAttr \".spc.spg\" %f;\n", spg);}
	/*specular green value*/
	void setSpecularColorG(const FloatID& spg){fprintf_s(mFile,"connectAttr \"");spg.write(mFile);fprintf_s(mFile,"\" \"%s.spc.spg\";\n",mName.c_str());}
	/*specular blue value*/
	void setSpecularColorB(float spb){if(spb == 0.0) return; fprintf_s(mFile, "setAttr \".spc.spb\" %f;\n", spb);}
	/*specular blue value*/
	void setSpecularColorB(const FloatID& spb){fprintf_s(mFile,"connectAttr \"");spb.write(mFile);fprintf_s(mFile,"\" \"%s.spc.spb\";\n",mName.c_str());}
	/*
	<b>Cosine Power</b> is used to control the "tightness" of
	the specular highlights (also called 'hot spots') on the surface.
	The minimum value is 2.
	The higher the value, the more tighly focussed (smaller) is
	the highlight.
	*/
	void setCosinePower(float csp){if(csp == 20.0) return; fprintf_s(mFile, "setAttr \".csp\" %f;\n", csp);}
	/*
	<b>Cosine Power</b> is used to control the "tightness" of
	the specular highlights (also called 'hot spots') on the surface.
	The minimum value is 2.
	The higher the value, the more tighly focussed (smaller) is
	the highlight.
	*/
	void setCosinePower(const FloatID& csp){fprintf_s(mFile,"connectAttr \"");csp.write(mFile);fprintf_s(mFile,"\" \"%s.csp\";\n",mName.c_str());}
	/*
	<b>Environment</b> defines a simple sky to ground environmental
	reflection using a ramp. The left of the ramp is the top of the
	sky and the right is the bottom.
	*/
	void setEnvironment(size_t env_i,const Environment& env){fprintf_s(mFile, "setAttr \".env[%i]\" ",env_i);env.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Environment</b> defines a simple sky to ground environmental
	reflection using a ramp. The left of the ramp is the top of the
	sky and the right is the bottom.
	*/
	void setEnvironment(size_t env_i,const EnvironmentID& env){fprintf_s(mFile,"connectAttr \"");env.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i]\";\n",mName.c_str(),env_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setEnvironment_Position(size_t env_i,float envp){if(envp == 0.0) return; fprintf_s(mFile, "setAttr \".env[%i].envp\" %f;\n", env_i,envp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setEnvironment_Position(size_t env_i,const FloatID& envp){fprintf_s(mFile,"connectAttr \"");envp.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envp\";\n",mName.c_str(),env_i);}
	/*Ramp color at the sibling position*/
	void setEnvironment_Color(size_t env_i,const float3& envc){fprintf_s(mFile, "setAttr \".env[%i].envc\" -type \"float3\" ",env_i);envc.write(mFile);fprintf_s(mFile,";\n");}
	/*Ramp color at the sibling position*/
	void setEnvironment_Color(size_t env_i,const Float3ID& envc){fprintf_s(mFile,"connectAttr \"");envc.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envc\";\n",mName.c_str(),env_i);}
	/*Ramp red channel value at the sibling position*/
	void setEnvironment_ColorR(size_t env_i,float envcr){if(envcr == 0.0) return; fprintf_s(mFile, "setAttr \".env[%i].envc.envcr\" %f;\n", env_i,envcr);}
	/*Ramp red channel value at the sibling position*/
	void setEnvironment_ColorR(size_t env_i,const FloatID& envcr){fprintf_s(mFile,"connectAttr \"");envcr.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envc.envcr\";\n",mName.c_str(),env_i);}
	/*Ramp green channel value at the sibling position*/
	void setEnvironment_ColorG(size_t env_i,float envcg){if(envcg == 0.0) return; fprintf_s(mFile, "setAttr \".env[%i].envc.envcg\" %f;\n", env_i,envcg);}
	/*Ramp green channel value at the sibling position*/
	void setEnvironment_ColorG(size_t env_i,const FloatID& envcg){fprintf_s(mFile,"connectAttr \"");envcg.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envc.envcg\";\n",mName.c_str(),env_i);}
	/*Ramp blue channel value at the sibling position*/
	void setEnvironment_ColorB(size_t env_i,float envcb){if(envcb == 0.0) return; fprintf_s(mFile, "setAttr \".env[%i].envc.envcb\" %f;\n", env_i,envcb);}
	/*Ramp blue channel value at the sibling position*/
	void setEnvironment_ColorB(size_t env_i,const FloatID& envcb){fprintf_s(mFile,"connectAttr \"");envcb.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envc.envcb\";\n",mName.c_str(),env_i);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setEnvironment_Interp(size_t env_i,unsigned int envi){if(envi == 0) return; fprintf_s(mFile, "setAttr \".env[%i].envi\" %i;\n", env_i,envi);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setEnvironment_Interp(size_t env_i,const UnsignedintID& envi){fprintf_s(mFile,"connectAttr \"");envi.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envi\";\n",mName.c_str(),env_i);}
	/*
	Defines a shape to use to define an outer boundary for
	creating a soft edged volume. If one
	is rendering a box volume then Cube should match the
	edges of the volume. Likewise for Sphere and Cone volumes.
	*/
	void setDropoffShape(unsigned int dos){if(dos == 2) return; fprintf_s(mFile, "setAttr \".dos\" %i;\n", dos);}
	/*
	Defines a shape to use to define an outer boundary for
	creating a soft edged volume. If one
	is rendering a box volume then Cube should match the
	edges of the volume. Likewise for Sphere and Cone volumes.
	*/
	void setDropoffShape(const UnsignedintID& dos){fprintf_s(mFile,"connectAttr \"");dos.write(mFile);fprintf_s(mFile,"\" \"%s.dos\";\n",mName.c_str());}
	/*
	Defines the rate at which the density drops off towards the edge
	defined by the <b>Dropoff Shape</b>.
	*/
	void setEdgeDropoff(float edr){if(edr == .05) return; fprintf_s(mFile, "setAttr \".edr\" %f;\n", edr);}
	/*
	Defines the rate at which the density drops off towards the edge
	defined by the <b>Dropoff Shape</b>.
	*/
	void setEdgeDropoff(const FloatID& edr){fprintf_s(mFile,"connectAttr \"");edr.write(mFile);fprintf_s(mFile,"\" \"%s.edr\";\n",mName.c_str());}
	/*
	The maximum contrast in effective transparency of
	a volume span allowed by the adaptive subdivision
	sample method. When the contrast between two
	spans is greater than this value we subdivide the
	span. The contrast is defined as the effective difference
	in accumulated transparency from the viewpoint.
	If this value is high, then the sampling will look like
	uniform sampling. If the contrastTolerance is low then
	the quality will improve and the render time will increase,
	although we will not require as many samples as uniform
	sampling for a given render quality. The quality setting
	should be just high enough that one does not miss dense regions
	altogether( this creates artifacts like dotty fringes around clouds ).
	*/
	void setContrastTolerance(float ctl){if(ctl == 0.01) return; fprintf_s(mFile, "setAttr \".ctl\" %f;\n", ctl);}
	/*
	The maximum contrast in effective transparency of
	a volume span allowed by the adaptive subdivision
	sample method. When the contrast between two
	spans is greater than this value we subdivide the
	span. The contrast is defined as the effective difference
	in accumulated transparency from the viewpoint.
	If this value is high, then the sampling will look like
	uniform sampling. If the contrastTolerance is low then
	the quality will improve and the render time will increase,
	although we will not require as many samples as uniform
	sampling for a given render quality. The quality setting
	should be just high enough that one does not miss dense regions
	altogether( this creates artifacts like dotty fringes around clouds ).
	*/
	void setContrastTolerance(const FloatID& ctl){fprintf_s(mFile,"connectAttr \"");ctl.write(mFile);fprintf_s(mFile,"\" \"%s.ctl\";\n",mName.c_str());}
	/*
	If this is on then we draw a 2D surface as a heightfield rather
	than a flat plane. The opacity value is mapped to the height.
	*/
	void setHeightField(bool hfld){if(hfld == false) return; fprintf_s(mFile, "setAttr \".hfld\" %i;\n", hfld);}
	/*
	If this is on then we draw a 2D surface as a heightfield rather
	than a flat plane. The opacity value is mapped to the height.
	*/
	void setHeightField(const BoolID& hfld){fprintf_s(mFile,"connectAttr \"");hfld.write(mFile);fprintf_s(mFile,"\" \"%s.hfld\";\n",mName.c_str());}
	/*
	If this is on then we draw a surface instead of a soft
	volume. Shaded Display must be set to <b>AsRender</b> in
	order to see the surface in the interactive draw, or the
	outMesh must have a connection. The surface location is
	determined by the current opacity combined with the surface
	threshold.
	*/
	void setSurfaceRender(bool srr){if(srr == false) return; fprintf_s(mFile, "setAttr \".srr\" %i;\n", srr);}
	/*
	If this is on then we draw a surface instead of a soft
	volume. Shaded Display must be set to <b>AsRender</b> in
	order to see the surface in the interactive draw, or the
	outMesh must have a connection. The surface location is
	determined by the current opacity combined with the surface
	threshold.
	*/
	void setSurfaceRender(const BoolID& srr){fprintf_s(mFile,"connectAttr \"");srr.write(mFile);fprintf_s(mFile,"\" \"%s.srr\";\n",mName.c_str());}
	/*Threshold value used to generate implicit surface*/
	void setSurfaceThreshold(float srt){if(srt == 0.01) return; fprintf_s(mFile, "setAttr \".srt\" %f;\n", srt);}
	/*Threshold value used to generate implicit surface*/
	void setSurfaceThreshold(const FloatID& srt){fprintf_s(mFile,"connectAttr \"");srt.write(mFile);fprintf_s(mFile,"\" \"%s.srt\";\n",mName.c_str());}
	/*
	This determines how close points sampled for a
	surface lie to the the exact surfaceThreshold density.
	The quality setting should be made just high enough that
	we do not miss regions containing the surface. The render
	then further refines the surface using this tolerance.
	If this is high then the surface will look dotty and of
	poor quality. Very low values will result in longer render times
	and better quality. The tolerance value is defined relative to
	the quality setting. The quality determines the uniform step size,
	so that the actual distance this defines is equal to
	the step size * surfaceTolerance.
	*/
	void setSurfaceTolerance(float stl){if(stl == 0.1) return; fprintf_s(mFile, "setAttr \".stl\" %f;\n", stl);}
	/*
	This determines how close points sampled for a
	surface lie to the the exact surfaceThreshold density.
	The quality setting should be made just high enough that
	we do not miss regions containing the surface. The render
	then further refines the surface using this tolerance.
	If this is high then the surface will look dotty and of
	poor quality. Very low values will result in longer render times
	and better quality. The tolerance value is defined relative to
	the quality setting. The quality determines the uniform step size,
	so that the actual distance this defines is equal to
	the step size * surfaceTolerance.
	*/
	void setSurfaceTolerance(const FloatID& stl){fprintf_s(mFile,"connectAttr \"");stl.write(mFile);fprintf_s(mFile,"\" \"%s.stl\";\n",mName.c_str());}
	/*
	This takes internal density variations into account when
	doing surface renders. If soft surface is on then the inside
	of the density will not be a constant substance like glass
	but rather a continuously varying density such as a cloud.
	*/
	void setSoftSurface(bool ssf){if(ssf == false) return; fprintf_s(mFile, "setAttr \".ssf\" %i;\n", ssf);}
	/*
	This takes internal density variations into account when
	doing surface renders. If soft surface is on then the inside
	of the density will not be a constant substance like glass
	but rather a continuously varying density such as a cloud.
	*/
	void setSoftSurface(const BoolID& ssf){fprintf_s(mFile,"connectAttr \"");ssf.write(mFile);fprintf_s(mFile,"\" \"%s.ssf\";\n",mName.c_str());}
	/*
	Index of refraction. This property affects how
	reflectivity changes with viewing angle. It makes
	use of Fresnel's law. Materials with a low refractive
	index are generally only reflective at glancing angles.
	This is useful for a wet look or for water, because water
	has a lower refractive index than most solids. At a refractive
	index of 1.0 the material is considered to be the same as
	the medium, and theoretically there should be no specularity
	in this case( as with a cloud ). However we turn on full specularity
	in this case (ie. no view angle modulation), for convenience.
	*/
	void setRefractiveIndex(float rei){if(rei == 1.8) return; fprintf_s(mFile, "setAttr \".rei\" %f;\n", rei);}
	/*
	Index of refraction. This property affects how
	reflectivity changes with viewing angle. It makes
	use of Fresnel's law. Materials with a low refractive
	index are generally only reflective at glancing angles.
	This is useful for a wet look or for water, because water
	has a lower refractive index than most solids. At a refractive
	index of 1.0 the material is considered to be the same as
	the medium, and theoretically there should be no specularity
	in this case( as with a cloud ). However we turn on full specularity
	in this case (ie. no view angle modulation), for convenience.
	*/
	void setRefractiveIndex(const FloatID& rei){fprintf_s(mFile,"connectAttr \"");rei.write(mFile);fprintf_s(mFile,"\" \"%s.rei\";\n",mName.c_str());}
	/*
	Controls how fluid is sampled during rendering
	Jitter avoids banding artifacts, but adds noise
	to the final image unless the quality is set high.
	*/
	void setSampleMethod(unsigned int smpm){if(smpm == 3) return; fprintf_s(mFile, "setAttr \".smpm\" %i;\n", smpm);}
	/*
	Controls how fluid is sampled during rendering
	Jitter avoids banding artifacts, but adds noise
	to the final image unless the quality is set high.
	*/
	void setSampleMethod(const UnsignedintID& smpm){fprintf_s(mFile,"connectAttr \"");smpm.write(mFile);fprintf_s(mFile,"\" \"%s.smpm\";\n",mName.c_str());}
	/*
	Determines whether to use normal lights or a single built in
	directional light. The simple built in lighting is faster, especially for
	self shadowing, and it does not cast shadows or light onto other objects.
	Nor does it receive shadows from other objects.
	*/
	void setRealLights(bool rl){if(rl == true) return; fprintf_s(mFile, "setAttr \".rl\" %i;\n", rl);}
	/*
	Determines whether to use normal lights or a single built in
	directional light. The simple built in lighting is faster, especially for
	self shadowing, and it does not cast shadows or light onto other objects.
	Nor does it receive shadows from other objects.
	*/
	void setRealLights(const BoolID& rl){fprintf_s(mFile,"connectAttr \"");rl.write(mFile);fprintf_s(mFile,"\" \"%s.rl\";\n",mName.c_str());}
	/*
	<b>DirectionalLight</b> is the direction of the internal
	directional light used when <b>RealLights</b> is off.
	*/
	void setDirectionalLight(const float3& dl){fprintf_s(mFile, "setAttr \".dl\" -type \"float3\" ");dl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>DirectionalLight</b> is the direction of the internal
	directional light used when <b>RealLights</b> is off.
	*/
	void setDirectionalLight(const Float3ID& dl){fprintf_s(mFile,"connectAttr \"");dl.write(mFile);fprintf_s(mFile,"\" \"%s.dl\";\n",mName.c_str());}
	/*directionalLight X value*/
	void setDirectionalLightX(float dlx){if(dlx == 0.5) return; fprintf_s(mFile, "setAttr \".dl.dlx\" %f;\n", dlx);}
	/*directionalLight X value*/
	void setDirectionalLightX(const FloatID& dlx){fprintf_s(mFile,"connectAttr \"");dlx.write(mFile);fprintf_s(mFile,"\" \"%s.dl.dlx\";\n",mName.c_str());}
	/*directionalLight Y value*/
	void setDirectionalLightY(float dly){if(dly == 0.8) return; fprintf_s(mFile, "setAttr \".dl.dly\" %f;\n", dly);}
	/*directionalLight Y value*/
	void setDirectionalLightY(const FloatID& dly){fprintf_s(mFile,"connectAttr \"");dly.write(mFile);fprintf_s(mFile,"\" \"%s.dl.dly\";\n",mName.c_str());}
	/*directionalLight Z value*/
	void setDirectionalLightZ(float dlz){if(dlz == 0.5) return; fprintf_s(mFile, "setAttr \".dl.dlz\" %f;\n", dlz);}
	/*directionalLight Z value*/
	void setDirectionalLightZ(const FloatID& dlz){fprintf_s(mFile,"connectAttr \"");dlz.write(mFile);fprintf_s(mFile,"\" \"%s.dl.dlz\";\n",mName.c_str());}
	/*
	Determines how to texture the volume's density.
	<b>Perlin Noise</b> is the standard 3D noise used in the solidFractal texture.
	<b>Billow</b> has a pluffy, cloudlike effect.
	<b>Wispy</b> is a perlin noise that uses a second noise as a smear
	map. This makes the noise stretch out in places, looking wispy. When the time
	attribute is animated the smear noise is moved causing an undulating effect.
	<b>Volume Wave</b> is a sum of 3D waves in space.
	<b>SpaceTime</b> is a 4 dimensional version of the perlin noise, where
	time is the 4th dimension.
	*/
	void setTextureType(unsigned int tty){if(tty == 0) return; fprintf_s(mFile, "setAttr \".tty\" %i;\n", tty);}
	/*
	Determines how to texture the volume's density.
	<b>Perlin Noise</b> is the standard 3D noise used in the solidFractal texture.
	<b>Billow</b> has a pluffy, cloudlike effect.
	<b>Wispy</b> is a perlin noise that uses a second noise as a smear
	map. This makes the noise stretch out in places, looking wispy. When the time
	attribute is animated the smear noise is moved causing an undulating effect.
	<b>Volume Wave</b> is a sum of 3D waves in space.
	<b>SpaceTime</b> is a 4 dimensional version of the perlin noise, where
	time is the 4th dimension.
	*/
	void setTextureType(const UnsignedintID& tty){fprintf_s(mFile,"connectAttr \"");tty.write(mFile);fprintf_s(mFile,"\" \"%s.tty\";\n",mName.c_str());}
	/*
	<b>Color Texture</b> toggles the application of the current
	texture( determined by the texture type ) to the color input
	value.
	*/
	void setColorTexture(bool ctx){if(ctx == false) return; fprintf_s(mFile, "setAttr \".ctx\" %i;\n", ctx);}
	/*
	<b>Color Texture</b> toggles the application of the current
	texture( determined by the texture type ) to the color input
	value.
	*/
	void setColorTexture(const BoolID& ctx){fprintf_s(mFile,"connectAttr \"");ctx.write(mFile);fprintf_s(mFile,"\" \"%s.ctx\";\n",mName.c_str());}
	/*
	<b>Color Tex Gain</b> determines how much the texture affects
	the input value to the color. If the color range is red to blue,
	then texturing will cause red to blue variations. At a value of
	zero there will be no color texturing.
	*/
	void setColorTexGain(float ctxg){if(ctxg == 1.0) return; fprintf_s(mFile, "setAttr \".ctxg\" %f;\n", ctxg);}
	/*
	<b>Color Tex Gain</b> determines how much the texture affects
	the input value to the color. If the color range is red to blue,
	then texturing will cause red to blue variations. At a value of
	zero there will be no color texturing.
	*/
	void setColorTexGain(const FloatID& ctxg){fprintf_s(mFile,"connectAttr \"");ctxg.write(mFile);fprintf_s(mFile,"\" \"%s.ctxg\";\n",mName.c_str());}
	/*
	<b>Incand Texture</b> toggles the application of the current
	texture( determined by the texture type ) to the incandescence input
	value.
	*/
	void setIncandTexture(bool itx){if(itx == false) return; fprintf_s(mFile, "setAttr \".itx\" %i;\n", itx);}
	/*
	<b>Incand Texture</b> toggles the application of the current
	texture( determined by the texture type ) to the incandescence input
	value.
	*/
	void setIncandTexture(const BoolID& itx){fprintf_s(mFile,"connectAttr \"");itx.write(mFile);fprintf_s(mFile,"\" \"%s.itx\";\n",mName.c_str());}
	/*
	<b>Incand Tex Gain</b> determines how much the texture affects
	the input value to the incandescence. If the incandescence
	range is red to blue, then texturing will cause red to blue
	variations. At a value of zero there will be no incandescence texturing.
	*/
	void setIncandTexGain(float itxg){if(itxg == 1.0) return; fprintf_s(mFile, "setAttr \".itxg\" %f;\n", itxg);}
	/*
	<b>Incand Tex Gain</b> determines how much the texture affects
	the input value to the incandescence. If the incandescence
	range is red to blue, then texturing will cause red to blue
	variations. At a value of zero there will be no incandescence texturing.
	*/
	void setIncandTexGain(const FloatID& itxg){fprintf_s(mFile,"connectAttr \"");itxg.write(mFile);fprintf_s(mFile,"\" \"%s.itxg\";\n",mName.c_str());}
	/*
	<b>Opacity Texture</b> toggles the application of the current
	texture( determined by the texture type ) to the opacity input
	value.
	*/
	void setOpacityTexture(bool otx){if(otx == false) return; fprintf_s(mFile, "setAttr \".otx\" %i;\n", otx);}
	/*
	<b>Opacity Texture</b> toggles the application of the current
	texture( determined by the texture type ) to the opacity input
	value.
	*/
	void setOpacityTexture(const BoolID& otx){fprintf_s(mFile,"connectAttr \"");otx.write(mFile);fprintf_s(mFile,"\" \"%s.otx\";\n",mName.c_str());}
	/*
	<b>Opacity Tex Gain</b> determines how much the texture affects
	the input value to the opacity. If the opacity curve goes
	from 0.0 to 0.6, then texturing will cause
	variations between these values. At a value of
	zero there will be no opacity texturing.
	*/
	void setOpacityTexGain(float otxg){if(otxg == 1.0) return; fprintf_s(mFile, "setAttr \".otxg\" %f;\n", otxg);}
	/*
	<b>Opacity Tex Gain</b> determines how much the texture affects
	the input value to the opacity. If the opacity curve goes
	from 0.0 to 0.6, then texturing will cause
	variations between these values. At a value of
	zero there will be no opacity texturing.
	*/
	void setOpacityTexGain(const FloatID& otxg){fprintf_s(mFile,"connectAttr \"");otxg.write(mFile);fprintf_s(mFile,"\" \"%s.otxg\";\n",mName.c_str());}
	/*
	<b>InvertTexture</b> This reverses the range of the texture
	so that dense regions become thin and thin become dense.
	If it is on, then the texture = 1 - texture.
	*/
	void setInvertTexture(bool ivt){if(ivt == false) return; fprintf_s(mFile, "setAttr \".ivt\" %i;\n", ivt);}
	/*
	<b>InvertTexture</b> This reverses the range of the texture
	so that dense regions become thin and thin become dense.
	If it is on, then the texture = 1 - texture.
	*/
	void setInvertTexture(const BoolID& ivt){fprintf_s(mFile,"connectAttr \"");ivt.write(mFile);fprintf_s(mFile,"\" \"%s.ivt\";\n",mName.c_str());}
	/*
	<b>Amplitude</b> is a scaling factor applied to all the
	values in the texture, centered around the texture's
	average value.  This means that when you increase Amplitude,
	the light areas get lighter and the dark areas get darker.
	<p/>
	If the Volume Noise is being used as a bump map, then
	increasing Amplitude will make the bumps higher and the
	valleys deeper.
	<p/>If you set Amplitude to a value greater than 1.0, then
	those parts of the texture that scale out of range will be
	clipped.  On a bump map, this will show up as plateau regions.
	*/
	void setAmplitude(float a){if(a == 1.0) return; fprintf_s(mFile, "setAttr \".a\" %f;\n", a);}
	/*
	<b>Amplitude</b> is a scaling factor applied to all the
	values in the texture, centered around the texture's
	average value.  This means that when you increase Amplitude,
	the light areas get lighter and the dark areas get darker.
	<p/>
	If the Volume Noise is being used as a bump map, then
	increasing Amplitude will make the bumps higher and the
	valleys deeper.
	<p/>If you set Amplitude to a value greater than 1.0, then
	those parts of the texture that scale out of range will be
	clipped.  On a bump map, this will show up as plateau regions.
	*/
	void setAmplitude(const FloatID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*
	<b>Ratio</b> controls the frequency of the fractal
	noise.  Increase this value to increase the fineness of
	detail in the fractal,
	*/
	void setRatio(float ra){if(ra == 0.707) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*
	<b>Ratio</b> controls the frequency of the fractal
	noise.  Increase this value to increase the fineness of
	detail in the fractal,
	*/
	void setRatio(const FloatID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*
	<b>Threshold</b> is a number that is added to the whole
	fractal, making it uniformly brighter.  If some parts of
	the fractal are pushed up out of range (greater than 1.0),
	then they will be clipped to 1.0.  If the Volume Noise is being
	used as a bump map, this will show up as plateau regions.
	*/
	void setThreshold(float th){if(th == 0.0) return; fprintf_s(mFile, "setAttr \".th\" %f;\n", th);}
	/*
	<b>Threshold</b> is a number that is added to the whole
	fractal, making it uniformly brighter.  If some parts of
	the fractal are pushed up out of range (greater than 1.0),
	then they will be clipped to 1.0.  If the Volume Noise is being
	used as a bump map, this will show up as plateau regions.
	*/
	void setThreshold(const FloatID& th){fprintf_s(mFile,"connectAttr \"");th.write(mFile);fprintf_s(mFile,"\" \"%s.th\";\n",mName.c_str());}
	/*
	<b>Texture Scale</b> determines the scale of the noise in
	the local x,y and z directions. It has a similar to scaling
	the transform node for the texture.
	<p/>
	If you increase Scale in any particular direction, the
	fractal detail will seem to smear out in that direction.
	*/
	void setTextureScale(const float3& txsc){if(txsc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".txsc\" -type \"float3\" ");txsc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Texture Scale</b> determines the scale of the noise in
	the local x,y and z directions. It has a similar to scaling
	the transform node for the texture.
	<p/>
	If you increase Scale in any particular direction, the
	fractal detail will seem to smear out in that direction.
	*/
	void setTextureScale(const Float3ID& txsc){fprintf_s(mFile,"connectAttr \"");txsc.write(mFile);fprintf_s(mFile,"\" \"%s.txsc\";\n",mName.c_str());}
	/*Scale X value*/
	void setTextureScaleX(float tscx){if(tscx == 0.0) return; fprintf_s(mFile, "setAttr \".txsc.tscx\" %f;\n", tscx);}
	/*Scale X value*/
	void setTextureScaleX(const FloatID& tscx){fprintf_s(mFile,"connectAttr \"");tscx.write(mFile);fprintf_s(mFile,"\" \"%s.txsc.tscx\";\n",mName.c_str());}
	/*Scale Y value*/
	void setTextureScaleY(float tscy){if(tscy == 0.0) return; fprintf_s(mFile, "setAttr \".txsc.tscy\" %f;\n", tscy);}
	/*Scale Y value*/
	void setTextureScaleY(const FloatID& tscy){fprintf_s(mFile,"connectAttr \"");tscy.write(mFile);fprintf_s(mFile,"\" \"%s.txsc.tscy\";\n",mName.c_str());}
	/*Scale Z value*/
	void setTextureScaleZ(float tscz){if(tscz == 0.0) return; fprintf_s(mFile, "setAttr \".txsc.tscz\" %f;\n", tscz);}
	/*Scale Z value*/
	void setTextureScaleZ(const FloatID& tscz){fprintf_s(mFile,"connectAttr \"");tscz.write(mFile);fprintf_s(mFile,"\" \"%s.txsc.tscz\";\n",mName.c_str());}
	/*
	<b>Texture Origin</b> is the zero point for the noise.
	changing this value translates the noise through space.
	*/
	void setTextureOrigin(const float3& tor){if(tor == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".tor\" -type \"float3\" ");tor.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Texture Origin</b> is the zero point for the noise.
	changing this value translates the noise through space.
	*/
	void setTextureOrigin(const Float3ID& tor){fprintf_s(mFile,"connectAttr \"");tor.write(mFile);fprintf_s(mFile,"\" \"%s.tor\";\n",mName.c_str());}
	/*Origin X value*/
	void setTextureOriginX(float torx){if(torx == 0.0) return; fprintf_s(mFile, "setAttr \".tor.torx\" %f;\n", torx);}
	/*Origin X value*/
	void setTextureOriginX(const FloatID& torx){fprintf_s(mFile,"connectAttr \"");torx.write(mFile);fprintf_s(mFile,"\" \"%s.tor.torx\";\n",mName.c_str());}
	/*Origin Y value*/
	void setTextureOriginY(float tory){if(tory == 0.0) return; fprintf_s(mFile, "setAttr \".tor.tory\" %f;\n", tory);}
	/*Origin Y value*/
	void setTextureOriginY(const FloatID& tory){fprintf_s(mFile,"connectAttr \"");tory.write(mFile);fprintf_s(mFile,"\" \"%s.tor.tory\";\n",mName.c_str());}
	/*Origin Z value*/
	void setTextureOriginZ(float torz){if(torz == 0.0) return; fprintf_s(mFile, "setAttr \".tor.torz\" %f;\n", torz);}
	/*Origin Z value*/
	void setTextureOriginZ(const FloatID& torz){fprintf_s(mFile,"connectAttr \"");torz.write(mFile);fprintf_s(mFile,"\" \"%s.tor.torz\";\n",mName.c_str());}
	/*
	<b>DepthMax</b> controls
	how much calculation is done by the
	Volume Noise texture.  Fractal textures
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use
	Depth Max to control the maximum amount
	of calculation that the texure will do.
	*/
	void setDepthMax(short dm){if(dm == 2) return; fprintf_s(mFile, "setAttr \".dm\" %i;\n", dm);}
	/*
	<b>DepthMax</b> controls
	how much calculation is done by the
	Volume Noise texture.  Fractal textures
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use
	Depth Max to control the maximum amount
	of calculation that the texure will do.
	*/
	void setDepthMax(const ShortID& dm){fprintf_s(mFile,"connectAttr \"");dm.write(mFile);fprintf_s(mFile,"\" \"%s.dm\";\n",mName.c_str());}
	/*
	<b>Frequency</b> This determines the fundamental frequency
	for the noise. As this value increases the noise becomes more
	detailed. It has the inverse effect of the scale parameter.
	*/
	void setFrequency(float fq){if(fq == 1.0) return; fprintf_s(mFile, "setAttr \".fq\" %f;\n", fq);}
	/*
	<b>Frequency</b> This determines the fundamental frequency
	for the noise. As this value increases the noise becomes more
	detailed. It has the inverse effect of the scale parameter.
	*/
	void setFrequency(const FloatID& fq){fprintf_s(mFile,"connectAttr \"");fq.write(mFile);fprintf_s(mFile,"\" \"%s.fq\";\n",mName.c_str());}
	/*
	<b>Frequency Ratio</b> This determines the relative spacial
	scale of the noise frequencies. If this ratio is not a whole integer then
	the fractal will not repeat  at the integer uv boundaries. A
	cylinder with default placement would then display a seam.
	*/
	void setFrequencyRatio(float fr){if(fr == 2.0) return; fprintf_s(mFile, "setAttr \".fr\" %f;\n", fr);}
	/*
	<b>Frequency Ratio</b> This determines the relative spacial
	scale of the noise frequencies. If this ratio is not a whole integer then
	the fractal will not repeat  at the integer uv boundaries. A
	cylinder with default placement would then display a seam.
	*/
	void setFrequencyRatio(const FloatID& fr){fprintf_s(mFile,"connectAttr \"");fr.write(mFile);fprintf_s(mFile,"\" \"%s.fr\";\n",mName.c_str());}
	/*
	<b>Inflection</b> This applies a kink in the noise function
	This is useful for creating puffy or bumpy effects.
	It is equivalent to abs(noise) * 2 - 1.
	*/
	void setInflection(bool in){if(in == false) return; fprintf_s(mFile, "setAttr \".in\" %i;\n", in);}
	/*
	<b>Inflection</b> This applies a kink in the noise function
	This is useful for creating puffy or bumpy effects.
	It is equivalent to abs(noise) * 2 - 1.
	*/
	void setInflection(const BoolID& in){fprintf_s(mFile,"connectAttr \"");in.write(mFile);fprintf_s(mFile,"\" \"%s.in\";\n",mName.c_str());}
	/*
	<b>Texture Time</b> is used to animate the Noise texture.
	You can keyframe the Time attribute to control
	the rate and amount of change of the texture.
	Typing the expression "= time" into the edit cell will cause
	the texture to billow when rendered in an animation.
	Typing "= time * 2" will make it billow twice as fast.
	*/
	void setTextureTime(float tti){if(tti == 0.0) return; fprintf_s(mFile, "setAttr \".tti\" %f;\n", tti);}
	/*
	<b>Texture Time</b> is used to animate the Noise texture.
	You can keyframe the Time attribute to control
	the rate and amount of change of the texture.
	Typing the expression "= time" into the edit cell will cause
	the texture to billow when rendered in an animation.
	Typing "= time * 2" will make it billow twice as fast.
	*/
	void setTextureTime(const FloatID& tti){fprintf_s(mFile,"connectAttr \"");tti.write(mFile);fprintf_s(mFile,"\" \"%s.tti\";\n",mName.c_str());}
	/*
	<b>Billow Density</b> controls how many cells there are imbedded
	in the medium used by the <b>Billow</b> noise type.
	At 1.0, the medium is completely packed
	with cells.  Reduce this value to make the cells more sparse.
	<p/>If the texture is being used as a bump map, then
	low values for Density will make it look like a smooth surface
	with occasional bumps on it.
	*/
	void setBillowDensity(float bd){if(bd == 1.0) return; fprintf_s(mFile, "setAttr \".bd\" %f;\n", bd);}
	/*
	<b>Billow Density</b> controls how many cells there are imbedded
	in the medium used by the <b>Billow</b> noise type.
	At 1.0, the medium is completely packed
	with cells.  Reduce this value to make the cells more sparse.
	<p/>If the texture is being used as a bump map, then
	low values for Density will make it look like a smooth surface
	with occasional bumps on it.
	*/
	void setBillowDensity(const FloatID& bd){fprintf_s(mFile,"connectAttr \"");bd.write(mFile);fprintf_s(mFile,"\" \"%s.bd\";\n",mName.c_str());}
	/*
	<b>Spottyness</b> controls the randomization of the density
	of the individual cells used by the <b>Billow</b> noise type.
	When Spottyness is close to 0,
	all the cells will be the same density.  As you increase
	Spottyness, some cells will be denser or thinner than others,
	in a random fashion.
	*/
	void setSpottyness(float sp){if(sp == 0.1) return; fprintf_s(mFile, "setAttr \".sp\" %f;\n", sp);}
	/*
	<b>Spottyness</b> controls the randomization of the density
	of the individual cells used by the <b>Billow</b> noise type.
	When Spottyness is close to 0,
	all the cells will be the same density.  As you increase
	Spottyness, some cells will be denser or thinner than others,
	in a random fashion.
	*/
	void setSpottyness(const FloatID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp\";\n",mName.c_str());}
	/*
	<b>Size Rand</b> controls the randomization of the size
	of the individual blobs used by the <b>Billow</b> noise type.
	When it is close to 0,
	all the cells will be the same size.  As you increase
	<b>Size Rand</b>, some cells will be smaller than others,
	in a random fashion.
	*/
	void setSizeRand(float sr){if(sr == 0.0) return; fprintf_s(mFile, "setAttr \".sr\" %f;\n", sr);}
	/*
	<b>Size Rand</b> controls the randomization of the size
	of the individual blobs used by the <b>Billow</b> noise type.
	When it is close to 0,
	all the cells will be the same size.  As you increase
	<b>Size Rand</b>, some cells will be smaller than others,
	in a random fashion.
	*/
	void setSizeRand(const FloatID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sr\";\n",mName.c_str());}
	/*
	<b>Randomness</b> controls how the cells for the <b>Billow</b>
	noise type are arranged relative to one another.
	Set randomness to 1.0 to get a realistic
	random distribution of cells, as would be found in nature.
	If you set Randomness to 0, all the spots are laid out in a
	completely regular pattern.  This can provide interesting
	effects when used as a bump map;  you can make things like
	insect eyes, or machine-tooled raspy surfaces.
	*/
	void setRandomness(float rnd){if(rnd == 1.0) return; fprintf_s(mFile, "setAttr \".rnd\" %f;\n", rnd);}
	/*
	<b>Randomness</b> controls how the cells for the <b>Billow</b>
	noise type are arranged relative to one another.
	Set randomness to 1.0 to get a realistic
	random distribution of cells, as would be found in nature.
	If you set Randomness to 0, all the spots are laid out in a
	completely regular pattern.  This can provide interesting
	effects when used as a bump map;  you can make things like
	insect eyes, or machine-tooled raspy surfaces.
	*/
	void setRandomness(const FloatID& rnd){fprintf_s(mFile,"connectAttr \"");rnd.write(mFile);fprintf_s(mFile,"\" \"%s.rnd\";\n",mName.c_str());}
	/*
	This controls the way intensity falls off for individual blobs for
	the <b>Billow</b> noise type. <b>Linear</b> is a uniform falloff from the
	center to a value of zero at the edges of the blobs.<b>Smooth</b> is
	more natural looking, using a gaussian falloff. <b>Fast</b> focuses the
	intensity more towards the center of the blobs. <b>Bubble</b> uses a
	reverse falloff, fading to zero at the blob center.
	*/
	void setFalloff(unsigned int falo){if(falo == 2) return; fprintf_s(mFile, "setAttr \".falo\" %i;\n", falo);}
	/*
	This controls the way intensity falls off for individual blobs for
	the <b>Billow</b> noise type. <b>Linear</b> is a uniform falloff from the
	center to a value of zero at the edges of the blobs.<b>Smooth</b> is
	more natural looking, using a gaussian falloff. <b>Fast</b> focuses the
	intensity more towards the center of the blobs. <b>Bubble</b> uses a
	reverse falloff, fading to zero at the blob center.
	*/
	void setFalloff(const UnsignedintID& falo){fprintf_s(mFile,"connectAttr \"");falo.write(mFile);fprintf_s(mFile,"\" \"%s.falo\";\n",mName.c_str());}
	/*
	<b>NumWaves</b> determines how many waves to generate for the <b>VolumeWave</b>
	noise type. The larger this number the more random looking and slower the texture.
	*/
	void setNumWaves(short nw){if(nw == 5) return; fprintf_s(mFile, "setAttr \".nw\" %i;\n", nw);}
	/*
	<b>NumWaves</b> determines how many waves to generate for the <b>VolumeWave</b>
	noise type. The larger this number the more random looking and slower the texture.
	*/
	void setNumWaves(const ShortID& nw){fprintf_s(mFile,"connectAttr \"");nw.write(mFile);fprintf_s(mFile,"\" \"%s.nw\";\n",mName.c_str());}
	/*
	<b>Implode</b> warps the noise function in a concentric fashion
	about a point defined by the <b>Implode Center</b>.
	At a value of zero there is no effect, while at a value of
	1.0 it is a spherical projection of the noise function, creating
	a starburst effect. Negative values can be used to skew the noise
	outward instead of inward.
	*/
	void setImplode(float imp){if(imp == 0.0) return; fprintf_s(mFile, "setAttr \".imp\" %f;\n", imp);}
	/*
	<b>Implode</b> warps the noise function in a concentric fashion
	about a point defined by the <b>Implode Center</b>.
	At a value of zero there is no effect, while at a value of
	1.0 it is a spherical projection of the noise function, creating
	a starburst effect. Negative values can be used to skew the noise
	outward instead of inward.
	*/
	void setImplode(const FloatID& imp){fprintf_s(mFile,"connectAttr \"");imp.write(mFile);fprintf_s(mFile,"\" \"%s.imp\";\n",mName.c_str());}
	/*
	<b>Implode Center</b> defines the center point about which the
	implode effect is defined.
	*/
	void setImplodeCenter(const float3& imc){if(imc == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".imc\" -type \"float3\" ");imc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Implode Center</b> defines the center point about which the
	implode effect is defined.
	*/
	void setImplodeCenter(const Float3ID& imc){fprintf_s(mFile,"connectAttr \"");imc.write(mFile);fprintf_s(mFile,"\" \"%s.imc\";\n",mName.c_str());}
	/*<b>Implode Center X</b> x position for implode effect*/
	void setImplodeCenterX(float imx){if(imx == 0.0) return; fprintf_s(mFile, "setAttr \".imc.imx\" %f;\n", imx);}
	/*<b>Implode Center X</b> x position for implode effect*/
	void setImplodeCenterX(const FloatID& imx){fprintf_s(mFile,"connectAttr \"");imx.write(mFile);fprintf_s(mFile,"\" \"%s.imc.imx\";\n",mName.c_str());}
	/*<b>Implode Center Y</b> y position for implode effect*/
	void setImplodeCenterY(float imy){if(imy == 0.0) return; fprintf_s(mFile, "setAttr \".imc.imy\" %f;\n", imy);}
	/*<b>Implode Center Y</b> y position for implode effect*/
	void setImplodeCenterY(const FloatID& imy){fprintf_s(mFile,"connectAttr \"");imy.write(mFile);fprintf_s(mFile,"\" \"%s.imc.imy\";\n",mName.c_str());}
	/*<b>Implode Center Z</b> z position for implode effect*/
	void setImplodeCenterZ(float imz){if(imz == 0.0) return; fprintf_s(mFile, "setAttr \".imc.imz\" %f;\n", imz);}
	/*<b>Implode Center Z</b> z position for implode effect*/
	void setImplodeCenterZ(const FloatID& imz){fprintf_s(mFile,"connectAttr \"");imz.write(mFile);fprintf_s(mFile,"\" \"%s.imc.imz\";\n",mName.c_str());}
	/*The fog  output color.*/
	void setOutColor(const Float3ID& ocl){fprintf_s(mFile,"connectAttr \"");ocl.write(mFile);fprintf_s(mFile,"\" \"%s.ocl\";\n",mName.c_str());}
	/*The red component of the fog  output color.*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.ocl.ocr\";\n",mName.c_str());}
	/*The green component of the fog  output color.*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.ocl.ocg\";\n",mName.c_str());}
	/*The blue component of the fog  output color.*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.ocl.ocb\";\n",mName.c_str());}
	/*
	Out Glow Color is the final output glow color from this node
	(if this node is glowing)
	*/
	void setOutGlowColor(const Float3ID& ogc){fprintf_s(mFile,"connectAttr \"");ogc.write(mFile);fprintf_s(mFile,"\" \"%s.ogc\";\n",mName.c_str());}
	/*out glow color red value*/
	void setOutGlowColorR(const FloatID& ogr){fprintf_s(mFile,"connectAttr \"");ogr.write(mFile);fprintf_s(mFile,"\" \"%s.ogc.ogr\";\n",mName.c_str());}
	/*out glow color green value*/
	void setOutGlowColorG(const FloatID& ogg){fprintf_s(mFile,"connectAttr \"");ogg.write(mFile);fprintf_s(mFile,"\" \"%s.ogc.ogg\";\n",mName.c_str());}
	/*out glow color blue value*/
	void setOutGlowColorB(const FloatID& ogb){fprintf_s(mFile,"connectAttr \"");ogb.write(mFile);fprintf_s(mFile,"\" \"%s.ogc.ogb\";\n",mName.c_str());}
	/*The fog output transparency.*/
	void setOutTransparency(const Float3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*The red component of the fog output transparency.*/
	void setOutTransparencyR(const FloatID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otr\";\n",mName.c_str());}
	/*The green component of the fog output transparency.*/
	void setOutTransparencyG(const FloatID& otg){fprintf_s(mFile,"connectAttr \"");otg.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otg\";\n",mName.c_str());}
	/*The blue component of the fog output transparency.*/
	void setOutTransparencyB(const FloatID& otb){fprintf_s(mFile,"connectAttr \"");otb.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otb\";\n",mName.c_str());}
	/*output Matte Opacity*/
	void setOutMatteOpacity(const Float3ID& omo){fprintf_s(mFile,"connectAttr \"");omo.write(mFile);fprintf_s(mFile,"\" \"%s.omo\";\n",mName.c_str());}
	/*output Matte Opacity red value*/
	void setOutMatteOpacityR(const FloatID& omor){fprintf_s(mFile,"connectAttr \"");omor.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omor\";\n",mName.c_str());}
	/*output Matte Opacity green value*/
	void setOutMatteOpacityG(const FloatID& omog){fprintf_s(mFile,"connectAttr \"");omog.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omog\";\n",mName.c_str());}
	/*output Matte Opacity blue value*/
	void setOutMatteOpacityB(const FloatID& omob){fprintf_s(mFile,"connectAttr \"");omob.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omob\";\n",mName.c_str());}
	/*Connection for playback cache node*/
	void setDiskCache(const MessageID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*Connection for initial conditions node*/
	void setDiskCacheIC(const MessageID& dcic){fprintf_s(mFile,"connectAttr \"");dcic.write(mFile);fprintf_s(mFile,"\" \"%s.dcic\";\n",mName.c_str());}
	/*
	During cache creation, if this object has a density grid
	write the grid to the disk cache
	*/
	void setCacheDensity(bool cdns){if(cdns == true) return; fprintf_s(mFile, "setAttr \".cdns\" %i;\n", cdns);}
	/*
	During cache creation, if this object has a density grid
	write the grid to the disk cache
	*/
	void setCacheDensity(const BoolID& cdns){fprintf_s(mFile,"connectAttr \"");cdns.write(mFile);fprintf_s(mFile,"\" \"%s.cdns\";\n",mName.c_str());}
	/*
	When reading from a cache, if the cache contains a density grid
	read the density from the cache
	*/
	void setLoadDensity(bool ldns){if(ldns == true) return; fprintf_s(mFile, "setAttr \".ldns\" %i;\n", ldns);}
	/*
	When reading from a cache, if the cache contains a density grid
	read the density from the cache
	*/
	void setLoadDensity(const BoolID& ldns){fprintf_s(mFile,"connectAttr \"");ldns.write(mFile);fprintf_s(mFile,"\" \"%s.ldns\";\n",mName.c_str());}
	/*
	During cache creation, if this object has a velocity grid
	write the grid to the disk cache
	*/
	void setCacheVelocity(bool cvel){if(cvel == true) return; fprintf_s(mFile, "setAttr \".cvel\" %i;\n", cvel);}
	/*
	During cache creation, if this object has a velocity grid
	write the grid to the disk cache
	*/
	void setCacheVelocity(const BoolID& cvel){fprintf_s(mFile,"connectAttr \"");cvel.write(mFile);fprintf_s(mFile,"\" \"%s.cvel\";\n",mName.c_str());}
	/*
	When reading from a cache, if the cache contains a velocity grid
	read the velocity from the cache
	*/
	void setLoadVelocity(bool lvel){if(lvel == true) return; fprintf_s(mFile, "setAttr \".lvel\" %i;\n", lvel);}
	/*
	When reading from a cache, if the cache contains a velocity grid
	read the velocity from the cache
	*/
	void setLoadVelocity(const BoolID& lvel){fprintf_s(mFile,"connectAttr \"");lvel.write(mFile);fprintf_s(mFile,"\" \"%s.lvel\";\n",mName.c_str());}
	/*
	During cache creation, if this object has a Temperature  grid
	write the grid to the disk cache
	*/
	void setCacheTemperature(bool ctmp){if(ctmp == true) return; fprintf_s(mFile, "setAttr \".ctmp\" %i;\n", ctmp);}
	/*
	During cache creation, if this object has a Temperature  grid
	write the grid to the disk cache
	*/
	void setCacheTemperature(const BoolID& ctmp){fprintf_s(mFile,"connectAttr \"");ctmp.write(mFile);fprintf_s(mFile,"\" \"%s.ctmp\";\n",mName.c_str());}
	/*
	When reading from a cache, if the cache contains a Temperature grid
	read the temperature from the cache
	*/
	void setLoadTemperature(bool ltmp){if(ltmp == true) return; fprintf_s(mFile, "setAttr \".ltmp\" %i;\n", ltmp);}
	/*
	When reading from a cache, if the cache contains a Temperature grid
	read the temperature from the cache
	*/
	void setLoadTemperature(const BoolID& ltmp){fprintf_s(mFile,"connectAttr \"");ltmp.write(mFile);fprintf_s(mFile,"\" \"%s.ltmp\";\n",mName.c_str());}
	/*
	During cache creation, if this object has a Color  grid
	write the grid to the disk cache
	*/
	void setCacheColor(bool ccol){if(ccol == true) return; fprintf_s(mFile, "setAttr \".ccol\" %i;\n", ccol);}
	/*
	During cache creation, if this object has a Color  grid
	write the grid to the disk cache
	*/
	void setCacheColor(const BoolID& ccol){fprintf_s(mFile,"connectAttr \"");ccol.write(mFile);fprintf_s(mFile,"\" \"%s.ccol\";\n",mName.c_str());}
	/*
	When reading from a cache, if the cache contains a Color grid
	read the color from the cache
	*/
	void setLoadColor(bool lcol){if(lcol == true) return; fprintf_s(mFile, "setAttr \".lcol\" %i;\n", lcol);}
	/*
	When reading from a cache, if the cache contains a Color grid
	read the color from the cache
	*/
	void setLoadColor(const BoolID& lcol){fprintf_s(mFile,"connectAttr \"");lcol.write(mFile);fprintf_s(mFile,"\" \"%s.lcol\";\n",mName.c_str());}
	/*
	During cache creation, if this object has a Reaction  grid
	write the grid to the disk cache
	*/
	void setCacheReaction(bool crea){if(crea == true) return; fprintf_s(mFile, "setAttr \".crea\" %i;\n", crea);}
	/*
	During cache creation, if this object has a Reaction  grid
	write the grid to the disk cache
	*/
	void setCacheReaction(const BoolID& crea){fprintf_s(mFile,"connectAttr \"");crea.write(mFile);fprintf_s(mFile,"\" \"%s.crea\";\n",mName.c_str());}
	/*
	When reading from a cache, if the cache contains a Fuel grid
	read the fuel from the cache
	*/
	void setLoadReaction(bool lrea){if(lrea == true) return; fprintf_s(mFile, "setAttr \".lrea\" %i;\n", lrea);}
	/*
	When reading from a cache, if the cache contains a Fuel grid
	read the fuel from the cache
	*/
	void setLoadReaction(const BoolID& lrea){fprintf_s(mFile,"connectAttr \"");lrea.write(mFile);fprintf_s(mFile,"\" \"%s.lrea\";\n",mName.c_str());}
	/*
	During cache creation, if this object has a Texture Coordinate grid
	write the grid to the disk cache
	*/
	void setCacheTextureCoordinates(bool catc){if(catc == true) return; fprintf_s(mFile, "setAttr \".catc\" %i;\n", catc);}
	/*
	During cache creation, if this object has a Texture Coordinate grid
	write the grid to the disk cache
	*/
	void setCacheTextureCoordinates(const BoolID& catc){fprintf_s(mFile,"connectAttr \"");catc.write(mFile);fprintf_s(mFile,"\" \"%s.catc\";\n",mName.c_str());}
	/*
	When reading from a cache, if the cache contains a Texture
	Coordinate grid read the grid from the cache
	*/
	void setLoadTextureCoordinates(bool lotc){if(lotc == true) return; fprintf_s(mFile, "setAttr \".lotc\" %i;\n", lotc);}
	/*
	When reading from a cache, if the cache contains a Texture
	Coordinate grid read the grid from the cache
	*/
	void setLoadTextureCoordinates(const BoolID& lotc){fprintf_s(mFile,"connectAttr \"");lotc.write(mFile);fprintf_s(mFile,"\" \"%s.lotc\";\n",mName.c_str());}
	/*
	During cache creation, if this object has a falloff grid
	write the grid to the disk cache
	*/
	void setCacheFalloff(bool cfal){if(cfal == true) return; fprintf_s(mFile, "setAttr \".cfal\" %i;\n", cfal);}
	/*
	During cache creation, if this object has a falloff grid
	write the grid to the disk cache
	*/
	void setCacheFalloff(const BoolID& cfal){fprintf_s(mFile,"connectAttr \"");cfal.write(mFile);fprintf_s(mFile,"\" \"%s.cfal\";\n",mName.c_str());}
	/*
	When reading from a cache, if the cache contains a falloff grid
	read the falloff from the cache
	*/
	void setLoadFalloff(bool lfal){if(lfal == true) return; fprintf_s(mFile, "setAttr \".lfal\" %i;\n", lfal);}
	/*
	When reading from a cache, if the cache contains a falloff grid
	read the falloff from the cache
	*/
	void setLoadFalloff(const BoolID& lfal){fprintf_s(mFile,"connectAttr \"");lfal.write(mFile);fprintf_s(mFile,"\" \"%s.lfal\";\n",mName.c_str());}
	/*
	A toggle to turn enable collision of fluid flow with attached
	geometry.
	*/
	void setCollide(bool cld){if(cld == true) return; fprintf_s(mFile, "setAttr \".cld\" %i;\n", cld);}
	/*
	A toggle to turn enable collision of fluid flow with attached
	geometry.
	*/
	void setCollide(const BoolID& cld){fprintf_s(mFile,"connectAttr \"");cld.write(mFile);fprintf_s(mFile,"\" \"%s.cld\";\n",mName.c_str());}
	/*The type of object being shaded.*/
	void setObjectType(char obt){if(obt == 2) return; fprintf_s(mFile, "setAttr \".obt\" %;\n", obt);}
	/*
	<b>Surface Shader Depth</b> controls how far in worldspace beyond a surface that
	we compute the fluid when used as a shader for surfaces(nurbs and polysets).
	*/
	void setSurfaceShaderDepth(float susd){if(susd == 1.0) return; fprintf_s(mFile, "setAttr \".susd\" %f;\n", susd);}
	/*
	<b>Surface Shader Depth</b> controls how far in worldspace beyond a surface that
	we compute the fluid when used as a shader for surfaces(nurbs and polysets).
	*/
	void setSurfaceShaderDepth(const FloatID& susd){fprintf_s(mFile,"connectAttr \"");susd.write(mFile);fprintf_s(mFile,"\" \"%s.susd\";\n",mName.c_str());}
	/*the weight in the intensity calculation*/
	void setParticleWeight(const FloatID& we){fprintf_s(mFile,"connectAttr \"");we.write(mFile);fprintf_s(mFile,"\" \"%s.we\";\n",mName.c_str());}
	/*
	This parameter scales how fast coordinates are moved by the velocity
	when the coordinate method is GRID. At a value of 1.0 the coordinates
	are pushed through the volume at the same speed as the other contents,
	such as density. However this tends to result in the texture becoming
	smeared out after a few steps. Lower values tend to preserve the character
	of the texture and can look more natural. Animating this value can be
	useful in some situations, such as when one does not wish the texture to
	deform before a certain point( keyframe it to zero until the desired
	start point ).
	*/
	void setCoordinateSpeed(float csd){if(csd == 0.2) return; fprintf_s(mFile, "setAttr \".csd\" %f;\n", csd);}
	/*
	This parameter scales how fast coordinates are moved by the velocity
	when the coordinate method is GRID. At a value of 1.0 the coordinates
	are pushed through the volume at the same speed as the other contents,
	such as density. However this tends to result in the texture becoming
	smeared out after a few steps. Lower values tend to preserve the character
	of the texture and can look more natural. Animating this value can be
	useful in some situations, such as when one does not wish the texture to
	deform before a certain point( keyframe it to zero until the desired
	start point ).
	*/
	void setCoordinateSpeed(const FloatID& csd){fprintf_s(mFile,"connectAttr \"");csd.write(mFile);fprintf_s(mFile,"\" \"%s.csd\";\n",mName.c_str());}
	/*
	This is a root of following mental ray attributes.
	The following override flags applies to fluidShape node only,
	and does not have any effect on fluid texture nodes (both 2D and 3D).
	*/
	void setMentalRayControls(const MentalRayControls& mrc){fprintf_s(mFile, "setAttr \".mrc\" ");mrc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is a root of following mental ray attributes.
	The following override flags applies to fluidShape node only,
	and does not have any effect on fluid texture nodes (both 2D and 3D).
	*/
	void setMentalRayControls(const MentalRayControlsID& mrc){fprintf_s(mFile,"connectAttr \"");mrc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc\";\n",mName.c_str());}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideCaustics(bool oca){if(oca == false) return; fprintf_s(mFile, "setAttr \".mrc.oca\" %i;\n", oca);}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideCaustics(const BoolID& oca){fprintf_s(mFile,"connectAttr \"");oca.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.oca\";\n",mName.c_str());}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticAccuracy(short caa){if(caa == 64) return; fprintf_s(mFile, "setAttr \".mrc.caa\" %i;\n", caa);}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticAccuracy(const ShortID& caa){fprintf_s(mFile,"connectAttr \"");caa.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.caa\";\n",mName.c_str());}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticRadius(float car){if(car == 0) return; fprintf_s(mFile, "setAttr \".mrc.car\" %f;\n", car);}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticRadius(const FloatID& car){fprintf_s(mFile,"connectAttr \"");car.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.car\";\n",mName.c_str());}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideGlobalIllumination(bool ogi){if(ogi == false) return; fprintf_s(mFile, "setAttr \".mrc.ogi\" %i;\n", ogi);}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideGlobalIllumination(const BoolID& ogi){fprintf_s(mFile,"connectAttr \"");ogi.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ogi\";\n",mName.c_str());}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumAccuracy(short gia){if(gia == 64) return; fprintf_s(mFile, "setAttr \".mrc.gia\" %i;\n", gia);}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumAccuracy(const ShortID& gia){fprintf_s(mFile,"connectAttr \"");gia.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.gia\";\n",mName.c_str());}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumRadius(float gir){if(gir == 0) return; fprintf_s(mFile, "setAttr \".mrc.gir\" %f;\n", gir);}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumRadius(const FloatID& gir){fprintf_s(mFile,"connectAttr \"");gir.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.gir\";\n",mName.c_str());}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideFinalGather(bool ofg){if(ofg == false) return; fprintf_s(mFile, "setAttr \".mrc.ofg\" %i;\n", ofg);}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideFinalGather(const BoolID& ofg){fprintf_s(mFile,"connectAttr \"");ofg.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ofg\";\n",mName.c_str());}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherRays(int fry){if(fry == 1000) return; fprintf_s(mFile, "setAttr \".mrc.fry\" %i;\n", fry);}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherRays(const IntID& fry){fprintf_s(mFile,"connectAttr \"");fry.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fry\";\n",mName.c_str());}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMinRadius(float fmn){if(fmn == 0) return; fprintf_s(mFile, "setAttr \".mrc.fmn\" %f;\n", fmn);}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMinRadius(const FloatID& fmn){fprintf_s(mFile,"connectAttr \"");fmn.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fmn\";\n",mName.c_str());}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMaxRadius(float fmx){if(fmx == 0) return; fprintf_s(mFile, "setAttr \".mrc.fmx\" %f;\n", fmx);}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMaxRadius(const FloatID& fmx){fprintf_s(mFile,"connectAttr \"");fmx.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fmx\";\n",mName.c_str());}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherFilter(short ffi){if(ffi == 1) return; fprintf_s(mFile, "setAttr \".mrc.ffi\" %i;\n", ffi);}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherFilter(const ShortID& ffi){fprintf_s(mFile,"connectAttr \"");ffi.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ffi\";\n",mName.c_str());}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherView(bool fgv){if(fgv == false) return; fprintf_s(mFile, "setAttr \".mrc.fgv\" %i;\n", fgv);}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherView(const BoolID& fgv){fprintf_s(mFile,"connectAttr \"");fgv.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fgv\";\n",mName.c_str());}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default.
	*/
	void setMiOverrideSamples(bool oos){if(oos == false) return; fprintf_s(mFile, "setAttr \".mrc.oos\" %i;\n", oos);}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default.
	*/
	void setMiOverrideSamples(const BoolID& oos){fprintf_s(mFile,"connectAttr \"");oos.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.oos\";\n",mName.c_str());}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	void setMiMinSamples(short mins){if(mins == 1) return; fprintf_s(mFile, "setAttr \".mrc.mins\" %i;\n", mins);}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	void setMiMinSamples(const ShortID& mins){fprintf_s(mFile,"connectAttr \"");mins.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mins\";\n",mName.c_str());}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	void setMiMaxSamples(short maxs){if(maxs == 2) return; fprintf_s(mFile, "setAttr \".mrc.maxs\" %i;\n", maxs);}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	void setMiMaxSamples(const ShortID& maxs){fprintf_s(mFile,"connectAttr \"");maxs.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.maxs\";\n",mName.c_str());}
	/*The output grid.*/
	FluidID getOutGrid(){char buffer[4096];sprintf_s (buffer, "%s.out",mName.c_str());return (const char*)buffer;}
	/*
	This is the current time used for the fluid simulation.
	By default, it is given an incoming connection from the main time node.
	This can be replaced with some other connection (e.g. from an expression
	or param curve), and then the solving is done based
	on that time value.  There must be some incoming connection in order
	for the fluid object to simulate.
	*/
	TimeID getCurrentTime(){char buffer[4096];sprintf_s (buffer, "%s.cti",mName.c_str());return (const char*)buffer;}
	/*
	The time after which the simulation will be run for this fluid object.
	This is set from the startFrame attribute.
	Users should set startFrame instead of this attribute.
	*/
	TimeID getStartTime(){char buffer[4096];sprintf_s (buffer, "%s.sti",mName.c_str());return (const char*)buffer;}
	/*
	This is the frame after which the simulation will run. Nothing
	will play back for this object prior to startFrame.
	*/
	DoubleID getStartFrame(){char buffer[4096];sprintf_s (buffer, "%s.stf",mName.c_str());return (const char*)buffer;}
	/*
	Used to turn off memory allocation, solving and contents draw
	during interactive, but still allows batch render
	*/
	BoolID getDisableInteractiveEval(){char buffer[4096];sprintf_s (buffer, "%s.die",mName.c_str());return (const char*)buffer;}
	/*Used to specify whether this is a 2D or 3D fluid.*/
	BoolID getIs2d(){char buffer[4096];sprintf_s (buffer, "%s.is2",mName.c_str());return (const char*)buffer;}
	/*
	Resolution of the grid
	Users should be aware that changing this attribute will affect the
	density currently contained in the grid.
	*/
	ResolutionID getResolution(){char buffer[4096];sprintf_s (buffer, "%s.res",mName.c_str());return (const char*)buffer;}
	/*Resolution of the grid - width*/
	IntID getResolutionW(){char buffer[4096];sprintf_s (buffer, "%s.res.rw",mName.c_str());return (const char*)buffer;}
	/*Resolution of the grid - height*/
	IntID getResolutionH(){char buffer[4096];sprintf_s (buffer, "%s.res.rh",mName.c_str());return (const char*)buffer;}
	/*Resolution of the grid - depth*/
	IntID getResolutionD(){char buffer[4096];sprintf_s (buffer, "%s.res.rd",mName.c_str());return (const char*)buffer;}
	/*
	Dimensions of the grid. The dimensions are used internally by the
	solver and should not be changed unless you really know what you're
	doing. Use the scale on the transform to increase the size of the grid
	instead.
	*/
	DimensionsID getDimensions(){char buffer[4096];sprintf_s (buffer, "%s.dim",mName.c_str());return (const char*)buffer;}
	/*Width Dimension of the grid*/
	DoubleID getDimensionsW(){char buffer[4096];sprintf_s (buffer, "%s.dim.dw",mName.c_str());return (const char*)buffer;}
	/*Height Dimension of the grid*/
	DoubleID getDimensionsH(){char buffer[4096];sprintf_s (buffer, "%s.dim.dh",mName.c_str());return (const char*)buffer;}
	/*Depth Dimension of the grid*/
	DoubleID getDimensionsD(){char buffer[4096];sprintf_s (buffer, "%s.dim.dd",mName.c_str());return (const char*)buffer;}
	/*Initial conditions for the fluidShape - currently unused.*/
	MessageID getInitialConditions(){char buffer[4096];sprintf_s (buffer, "%s.inc",mName.c_str());return (const char*)buffer;}
	/*A toggle - if false, ignore all connected fields*/
	BoolID getDoFields(){char buffer[4096];sprintf_s (buffer, "%s.dfr",mName.c_str());return (const char*)buffer;}
	/*
	This is the input multi-attribute where any fields acting on
	this fluid object are connected. The input forces are collected
	when the outGrid does it's update.
	*/
	const VectorArrayID& getInputForce(size_t ifc_i){char buffer[4096];sprintf_s (buffer, "%s.ifc[%i]",mName.c_str(),ifc_i);return (const char*)buffer;}
	/*
	This is the compound that holds all of the default attribute for the
	fields to connect to.
	*/
	FieldDataID getFieldData(){char buffer[4096];sprintf_s (buffer, "%s.fd",mName.c_str());return (const char*)buffer;}
	/*
	This is the default place that the fields will get this fluidShape's
	position data from. These positions are the (worldspace) midpoints of
	the each cell.
	*/
	VectorArrayID getFieldDataPosition(){char buffer[4096];sprintf_s (buffer, "%s.fd.fdp",mName.c_str());return (const char*)buffer;}
	/*
	This attribute stores the velocity for each cell, for the fields to
	use in calculations.
	*/
	VectorArrayID getFieldDataVelocity(){char buffer[4096];sprintf_s (buffer, "%s.fd.fdv",mName.c_str());return (const char*)buffer;}
	/*
	This is where connected fields get mass data for the fluid shape. The
	density of fluid for a particular cell is converted to an appropriate
	amount of mass for fields which consider mass.
	*/
	DoubleArrayID getFieldDataMass(){char buffer[4096];sprintf_s (buffer, "%s.fd.fdm",mName.c_str());return (const char*)buffer;}
	/*
	This is where the fields will get this fluidShape's
	timeStep size from.
	*/
	TimeID getFieldDataDeltaTime(){char buffer[4096];sprintf_s (buffer, "%s.fd.fdt",mName.c_str());return (const char*)buffer;}
	/*
	Parent multi-attribute to store the field's function attribute
	connections. (No longer used)
	*/
	const FieldListID& getFieldList(size_t fll_i){char buffer[4096];sprintf_s (buffer, "%s.fll[%i]",mName.c_str(),fll_i);return (const char*)buffer;}
	/*
	Function attribute for field computation. No longer used - see the
	fieldData attributes and the inputForce for how a field is connected
	to a fluidShape
	*/
	const FieldFunctionID& getFieldFunction(size_t fll_i){char buffer[4096];sprintf_s (buffer, "%s.fll[%i].frf",mName.c_str(),fll_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Actual function being applied at this attribute*/
	const FunctionID& getFieldFunction_Raw(size_t fll_i){char buffer[4096];sprintf_s (buffer, "%s.fll[%i].frf.frfr",mName.c_str(),fll_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	const FieldFunction_InmapID& getFieldFunction_Inmap(size_t fll_i,size_t frfi_i){char buffer[4096];sprintf_s (buffer, "%s.fll[%i].frf.frfi[%i]",mName.c_str(),fll_i,frfi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	const ShortID& getFieldFunction_InmapTo(size_t fll_i,size_t frfi_i){char buffer[4096];sprintf_s (buffer, "%s.fll[%i].frf.frfi[%i].frfit",mName.c_str(),fll_i,frfi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Function data input parameter index*/
	const ShortID& getFieldFunction_InmapFrom(size_t fll_i,size_t frfi_i){char buffer[4096];sprintf_s (buffer, "%s.fll[%i].frf.frfi[%i].frfif",mName.c_str(),fll_i,frfi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	const FieldFunction_OutmapID& getFieldFunction_Outmap(size_t fll_i,size_t frfo_i){char buffer[4096];sprintf_s (buffer, "%s.fll[%i].frf.frfo[%i]",mName.c_str(),fll_i,frfo_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	const ShortID& getFieldFunction_OutmapTo(size_t fll_i,size_t frfo_i){char buffer[4096];sprintf_s (buffer, "%s.fll[%i].frf.frfo[%i].frfot",mName.c_str(),fll_i,frfo_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Function data output parameter index*/
	const ShortID& getFieldFunction_OutmapFrom(size_t fll_i,size_t frfo_i){char buffer[4096];sprintf_s (buffer, "%s.fll[%i].frf.frfo[%i].frfof",mName.c_str(),fll_i,frfo_i);return (const char*)buffer;}
	/*A toggle - if false, ignore all connected emitters*/
	BoolID getDoEmission(){char buffer[4096];sprintf_s (buffer, "%s.de",mName.c_str());return (const char*)buffer;}
	/*Tells any object whether this fluid object has room for more emission*/
	BoolID getIsFull(){char buffer[4096];sprintf_s (buffer, "%s.ifl",mName.c_str());return (const char*)buffer;}
	/*
	Fraction of emitter velocity that density emitted into this
	object inherit.
	*/
	DoubleID getInheritFactor(){char buffer[4096];sprintf_s (buffer, "%s.inh",mName.c_str());return (const char*)buffer;}
	/*
	Random number stream seed for emitter's random number stream.
	Separate seed for each emitter. Set seeds equal to get identical
	stream.  Resetting the seed at a particular frame will restart
	the stream.
	*/
	const IntID& getSeed(size_t sd_i){char buffer[4096];sprintf_s (buffer, "%s.sd[%i]",mName.c_str(),sd_i);return (const char*)buffer;}
	/*Indicates whether color is being emitted along with density.*/
	const BoolID& getFluidColorEmission(size_t fce_i){char buffer[4096];sprintf_s (buffer, "%s.fce[%i]",mName.c_str(),fce_i);return (const char*)buffer;}
	/*Indicates whether the reaction grid is being emitted into along with density.*/
	const BoolID& getFluidReactantEmission(size_t frm_i){char buffer[4096];sprintf_s (buffer, "%s.frm[%i]",mName.c_str(),frm_i);return (const char*)buffer;}
	/*Parent attribute for emission function.*/
	const EmissionListID& getEmissionList(size_t eml_i){char buffer[4096];sprintf_s (buffer, "%s.eml[%i]",mName.c_str(),eml_i);return (const char*)buffer;}
	/*
	The function attribute an emitter gets connected to to emit into this
	fluidShape.
	*/
	const EmissionFunctionID& getEmissionFunction(size_t eml_i){char buffer[4096];sprintf_s (buffer, "%s.eml[%i].emf",mName.c_str(),eml_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Actual function being applied at this attribute*/
	const FunctionID& getEmissionFunction_Raw(size_t eml_i){char buffer[4096];sprintf_s (buffer, "%s.eml[%i].emf.emfr",mName.c_str(),eml_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	const EmissionFunction_InmapID& getEmissionFunction_Inmap(size_t eml_i,size_t emfi_i){char buffer[4096];sprintf_s (buffer, "%s.eml[%i].emf.emfi[%i]",mName.c_str(),eml_i,emfi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	const ShortID& getEmissionFunction_InmapTo(size_t eml_i,size_t emfi_i){char buffer[4096];sprintf_s (buffer, "%s.eml[%i].emf.emfi[%i].emfit",mName.c_str(),eml_i,emfi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Function data input parameter index*/
	const ShortID& getEmissionFunction_InmapFrom(size_t eml_i,size_t emfi_i){char buffer[4096];sprintf_s (buffer, "%s.eml[%i].emf.emfi[%i].emfif",mName.c_str(),eml_i,emfi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	const EmissionFunction_OutmapID& getEmissionFunction_Outmap(size_t eml_i,size_t emfo_i){char buffer[4096];sprintf_s (buffer, "%s.eml[%i].emf.emfo[%i]",mName.c_str(),eml_i,emfo_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	const ShortID& getEmissionFunction_OutmapTo(size_t eml_i,size_t emfo_i){char buffer[4096];sprintf_s (buffer, "%s.eml[%i].emf.emfo[%i].emfot",mName.c_str(),eml_i,emfo_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Function data output parameter index*/
	const ShortID& getEmissionFunction_OutmapFrom(size_t eml_i,size_t emfo_i){char buffer[4096];sprintf_s (buffer, "%s.eml[%i].emf.emfo[%i].emfof",mName.c_str(),eml_i,emfo_i);return (const char*)buffer;}
	/*
	The number of slices to draw for each grid cell most aligned with the
	view direction when in 'slice' shaded draw mode. Increasing this value
	will give more detailed hardware draws (at the cost of slower drawing)
	*/
	IntID getSlices(){char buffer[4096];sprintf_s (buffer, "%s.sli",mName.c_str());return (const char*)buffer;}
	/*
	In hardware draw mode, we normally draw quads with vertices at the
	centers of voxels. If the VoxelQuality attr is set to 2 (Better), then we split
	this up, doubling the number of quads in each direction, for a total
	of 4.
	*/
	UnsignedintID getVoxelQuality(){char buffer[4096];sprintf_s (buffer, "%s.vqu",mName.c_str());return (const char*)buffer;}
	/*
	When turned on, only a portion of the fluid's internal volume is
	is drawn, as specified by the next set of attributes.
	*/
	BoolID getDrawSubVolume(){char buffer[4096];sprintf_s (buffer, "%s.dsv",mName.c_str());return (const char*)buffer;}
	/*The center (in voxel grid coordinates) of the sub-volume to be drawn.*/
	SubVolumeCenterID getSubVolumeCenter(){char buffer[4096];sprintf_s (buffer, "%s.svc",mName.c_str());return (const char*)buffer;}
	/*Width component of aSubVolumeCenter.*/
	IntID getSubVolumeCenterW(){char buffer[4096];sprintf_s (buffer, "%s.svc.scw",mName.c_str());return (const char*)buffer;}
	/*Height component of aSubVolumeCenter.*/
	IntID getSubVolumeCenterH(){char buffer[4096];sprintf_s (buffer, "%s.svc.sch",mName.c_str());return (const char*)buffer;}
	/*Depth component of aSubVolumeCenter.*/
	IntID getSubVolumeCenterD(){char buffer[4096];sprintf_s (buffer, "%s.svc.scd",mName.c_str());return (const char*)buffer;}
	/*The dimensions (in voxels) of the sub-volume to be drawn.*/
	SubVolumeSizeID getSubVolumeSize(){char buffer[4096];sprintf_s (buffer, "%s.svs",mName.c_str());return (const char*)buffer;}
	/*Width component of aSubVolumeSize.*/
	IntID getSubVolumeSizeW(){char buffer[4096];sprintf_s (buffer, "%s.svs.ssw",mName.c_str());return (const char*)buffer;}
	/*Height component of aSubVolumeSize.*/
	IntID getSubVolumeSizeH(){char buffer[4096];sprintf_s (buffer, "%s.svs.ssh",mName.c_str());return (const char*)buffer;}
	/*Depth component of aSubVolumeSize.*/
	IntID getSubVolumeSizeD(){char buffer[4096];sprintf_s (buffer, "%s.svs.ssd",mName.c_str());return (const char*)buffer;}
	/*
	Determines whether the fluid drawing axis changes orientation with
	respect to the camera angle.  If false, orientation of the draw
	slice is locked and does not change with the camera angle.
	If true, orientation changes as the camera angle changes.
	*/
	BoolID getLockDrawAxis(){char buffer[4096];sprintf_s (buffer, "%s.lda",mName.c_str());return (const char*)buffer;}
	/*
	This attribute controls how the grid is drawn in 3d views. 0 or
	"Bottom", the default, indicates the bottom 'wall' of the grid
	should be drawn, bounding lines only for the rest. 1, "Reduced"
	indicates draw the 'walls' for the three sides furthest away from
	the camera, lines for the rest. 2, or "Outline", draws all sides of
	the grid with full resolution. 3, or "Full", draws everything.
	"Bounding box", value 4, draws just the bounding box for the grid,
	and 5, or "None", means don't draw the grid at all.
	*/
	UnsignedintID getBoundaryDraw(){char buffer[4096];sprintf_s (buffer, "%s.bod",mName.c_str());return (const char*)buffer;}
	/*
	If false, the velocity arrows are drawn as line segments only.
	Will speed up drawing and may make the volume less cluttered for
	visualization.
	*/
	BoolID getDrawHeads(){char buffer[4096];sprintf_s (buffer, "%s.dhd",mName.c_str());return (const char*)buffer;}
	/*If true, draws arrows or lines for the veloicty field.*/
	BoolID getVelocityDraw(){char buffer[4096];sprintf_s (buffer, "%s.vld",mName.c_str());return (const char*)buffer;}
	/*
	The larger this value, the longer the velocity segments or arrows.
	For very low-force simulations, the velocity field may be very small
	in magnitude. If this is the case, bumping this atribute up will help
	to visualize the velocity flow.
	*/
	DoubleID getVelocityDrawLength(){char buffer[4096];sprintf_s (buffer, "%s.vdl",mName.c_str());return (const char*)buffer;}
	/*
	The larger this value, the less velocity arrows that are drawn
	If the value is 1 then every other arrow will be omitted. If it
	is zero then all arrows will be drawn.
	*/
	IntID getVelocityDrawSkip(){char buffer[4096];sprintf_s (buffer, "%s.vds",mName.c_str());return (const char*)buffer;}
	/*
	Shaded Display determines what is displayed in the modeling view when in shaded mode.
	<b>As Render</b> attempts to match the final software rendered look.
	The other methods allow one to view isolated sub elements of the
	fluid, which can be useful when painting or tweeking these elements.
	Tweek the <b>Display Opacity Scale</b> to map the current element to
	a useful range of opacity in the grid. The methods combining density
	with another attribute display this other attribute using color.
	*/
	UnsignedintID getShadedDisplay(){char buffer[4096];sprintf_s (buffer, "%s.sdp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Opacity Preview Gain</b> adjusts the opacity of the hardware
	redraw when the shaded display is not <b>As Render</b>. This is
	useful when painting values into the grid.
	*/
	FloatID getOpacityPreviewGain(){char buffer[4096];sprintf_s (buffer, "%s.opg",mName.c_str());return (const char*)buffer;}
	/*How to simulate the opacity of the grid when in wireframe mode.*/
	UnsignedintID getWireframeDisplay(){char buffer[4096];sprintf_s (buffer, "%s.wdp",mName.c_str());return (const char*)buffer;}
	/*Display selected attribute as a grid of numbers.*/
	UnsignedintID getNumericDisplay(){char buffer[4096];sprintf_s (buffer, "%s.nud",mName.c_str());return (const char*)buffer;}
	/*
	A toggle to turn self-shadowing on or off during the hardware draw.
	Currently this attribute is only used in 'slice' draw mode.
	A directional light <-1,-1,-1> is the only light used to compute
	self-shadowing currently.
	*/
	BoolID getHardwareSelfShadow(){char buffer[4096];sprintf_s (buffer, "%s.hss",mName.c_str());return (const char*)buffer;}
	/*
	This defines how texture coordinates are defined.
	<b>Fixed</b> sets the values to equal the object space
	coordinate system (0-1 for the volume in x,y and z).
	<b>Grid</b> uses a grid of points and interpolates for in between values.
	If grid is set then the coordinate values will be moved using the
	current density solver. This will allow the texture to move and swirl with
	the density, rather than appearing fixed in space.
	<b>File</b> loads the texture coordinates from a file.
	*/
	UnsignedintID getCoordinateMethod(){char buffer[4096];sprintf_s (buffer, "%s.cmet",mName.c_str());return (const char*)buffer;}
	/*
	Tells the emitter the time step to emit for: this is
	the time since the last evaluation times the
	simulation rate scale.
	*/
	TimeID getOverrideTimeStep(){char buffer[4096];sprintf_s (buffer, "%s.ots",mName.c_str());return (const char*)buffer;}
	/*Scale the time step used in emission and solving*/
	FloatID getSimulationRateScale(){char buffer[4096];sprintf_s (buffer, "%s.srs",mName.c_str());return (const char*)buffer;}
	/*
	Which interpolation algorithm to use when retrieving values from
	fractional points within a fluid grid.
	Linear is the fastest. Linear with collisions or Hermite must be used
	for friction at boundaries to be computed. Hermite causes less
	diffusion than linear, but will make the simulation run several times
	more slowly, especially when one has collisions with geometry.
	*/
	UnsignedintID getGridInterpolator(){char buffer[4096];sprintf_s (buffer, "%s.gdi",mName.c_str());return (const char*)buffer;}
	/*
	Which solver to use. "Navier-Strokes" is a fast Navier-Stokes solver.
	"Spring Mesh" defines a simple water surface.
	*/
	UnsignedintID getSolver(){char buffer[4096];sprintf_s (buffer, "%s.sol",mName.c_str());return (const char*)buffer;}
	/*
	Increasing the quality will increase the number of steps used internally
	by the Navier-Stokes solver, which may increase the accuracy of
	the simulation and will certainly increase the time required to run.
	Depending on your fluids material properties, you may get satisfactory
	results lowering this from the default value of 20.
	*/
	IntID getSolverQuality(){char buffer[4096];sprintf_s (buffer, "%s.sql",mName.c_str());return (const char*)buffer;}
	/*
	This attribute can be used to create more detailed simulations
	without requiring higher resolution grids. With highDetailSolve
	turned off simulations will run faster, but there will be a lot
	of diffusion of both density and velocity as the the simulation
	progresses. The velocity grid is used not only to push around
	other grid values, like density, but it also pushes its own
	velocity values to new positions in the grid. Propagating velocity
	is much more computationally intensive than propagating scalar
	grid values like density, thus enabling Scalar and Velocity will
	increase the simulation compute time by a factor of 2, while
	enabling just the scalar grids only will not slow the solve
	by much. There will be much more detail in the flow, however,
	when using the scalar and velocity setting. In some cases
	the effect of high detail on a scalar grid such as density may
	not look smooth enough, in which case the velocity only method
	might be preferable.
	*/
	UnsignedintID getHighDetailSolve(){char buffer[4096];sprintf_s (buffer, "%s.hds",mName.c_str());return (const char*)buffer;}
	/*
	This controls the way the solver treats density at the boundaries.
	A closed boundary is like a wall. An open boundary allows outflows.
	A wrapping boundary causes flows that go off one side to enter in the
	opposite side. This can be useful if you wish to have a windy fog, yet
	do not want to continually replenish the density at the inflowing regions.
	*/
	UnsignedintID getBoundaryX(){char buffer[4096];sprintf_s (buffer, "%s.bndx",mName.c_str());return (const char*)buffer;}
	/*
	This controls the way the solver treats density at the boundaries.
	A closed boundary is like a wall. An open boundary allows outflows.
	A wrapping boundary causes flows that go off one side to enter in the
	opposite side. This can be useful if you wish to have a windy fog, yet
	do not want to continually replenish the density at the inflowing regions.
	*/
	UnsignedintID getBoundaryY(){char buffer[4096];sprintf_s (buffer, "%s.bndy",mName.c_str());return (const char*)buffer;}
	/*
	This controls the way the solver treats density at the boundaries.
	A closed boundary is like a wall. An open boundary allows outflows.
	A wrapping boundary causes flows that go off one side to enter in the
	opposite side. This can be useful if you wish to have a windy fog, yet
	do not want to continually replenish the density at the inflowing regions.
	*/
	UnsignedintID getBoundaryZ(){char buffer[4096];sprintf_s (buffer, "%s.bndz",mName.c_str());return (const char*)buffer;}
	/*
	This attribute controls how density is converted to mass for
	field operations.
	*/
	DoubleID getMassConversion(){char buffer[4096];sprintf_s (buffer, "%s.mcv",mName.c_str());return (const char*)buffer;}
	/*
	This defines how the optional grid of falloff values (used to soften
	the opacity of the fluid in user-defined ways) is defined.
	These values are only used if the Dropoff Shape is set to Grid.
	<b>Off</b> sets the grid to 0.0 across the volume, meaning that
	the fluid will become completely transparent everywhere.
	<b>Static Grid</b> Uses a grid without dynamic behavior to store the
	falloff values.
	*/
	UnsignedintID getFalloffMethod(){char buffer[4096];sprintf_s (buffer, "%s.fmt",mName.c_str());return (const char*)buffer;}
	/*
	This defines how density is defined.
	<b>Off</b> sets the value to 0.0 across the volume.
	<b>Static Grid</b> Uses a grid without dynamic behavior.
	<b>Dynamic Grid</b> Uses a grid with a dynamic solver.
	<b>Gradient</b> ramps the value based on DensityGradient.
	*/
	UnsignedintID getDensityMethod(){char buffer[4096];sprintf_s (buffer, "%s.dmt",mName.c_str());return (const char*)buffer;}
	/*
	This defines how density can be ramped
	<b>Constant</b> sets the value to 1.0 across the volume.
	<b>X Gradient</b> ramps the value from zero to one along the X axis.
	<b>Y Gradient</b> ramps the value from zero to one along the Y axis.
	<b>Z Gradient</b> ramps the value from zero to one along the Z axis.
	<b>Center Gradient</b> ramps the value from one at the center to zero at the edges.
	*/
	UnsignedintID getDensityGradient(){char buffer[4096];sprintf_s (buffer, "%s.dgr",mName.c_str());return (const char*)buffer;}
	/*<b>Density Scale</b> multiplies the value determined by the <b>Density Method</b>*/
	FloatID getDensityScale(){char buffer[4096];sprintf_s (buffer, "%s.dsc",mName.c_str());return (const char*)buffer;}
	/*How much the density dissipates.*/
	DoubleID getDensityDissipation(){char buffer[4096];sprintf_s (buffer, "%s.dds",mName.c_str());return (const char*)buffer;}
	/*Diffusion of the density*/
	DoubleID getDensityDiffusion(){char buffer[4096];sprintf_s (buffer, "%s.ddf",mName.c_str());return (const char*)buffer;}
	/*For the density update step - conserve mass on update or not.*/
	BoolID getConserveMass(){char buffer[4096];sprintf_s (buffer, "%s.cm",mName.c_str());return (const char*)buffer;}
	/*
	<b>Density Buoyancy</b> simulates a difference in mass density between the regions with
	density and the regions without. If the value is positive the density
	represents a substance that is lighter than the surrounding medium,
	like bubbles in water, and will thus rise. Negative values will cause the
	density to fall.
	*/
	FloatID getDensityBuoyancy(){char buffer[4096];sprintf_s (buffer, "%s.dsb",mName.c_str());return (const char*)buffer;}
	/*
	Gravitational constant that simulates mass of the world the simulation is occuring on.
	Values of zero simulate being in outer space. Note that density and heat buoyancy will
	have no effect if gravity is zero.
	*/
	FloatID getGravity(){char buffer[4096];sprintf_s (buffer, "%s.grv",mName.c_str());return (const char*)buffer;}
	/*
	This defines how velocity is defined.
	<b>Off</b> sets the value to (0.0,0.0,0.0) across the volume.
	<b>Center Gradient</b> ramps the value from (1.0,1.0,1.0) at the center to (0.0,0.0,0.0) at the edges.
	Both grid methods use a grid of points and interpolatefor in between values.
	These are the required methods if dynamic emitters are to be used.
	Also required if one wishes to paint values for this attribute.
	<b>Static Grid</b> Uses a grid without dynamic behavior.
	<b>Dynamic Grid</b> Uses a grid with a dynamic solver.
	<b>Gradient</b> ramps the value based on VelocityGradient.
	*/
	UnsignedintID getVelocityMethod(){char buffer[4096];sprintf_s (buffer, "%s.vmt",mName.c_str());return (const char*)buffer;}
	/*
	This defines how velocity can be ramped
	<b>Constant</b> sets the value to 1.0 across the volume.
	<b>X Gradient</b> ramps the value from (0.0,0.0,0.0) to (1.0,1.0,1.0) along the X axis.
	<b>Y Gradient</b> ramps the value from (0.0,0.0,0.0) to (1.0,1.0,1.0) along the Y axis.
	<b>Z Gradient</b> ramps the value from (0.0,0.0,0.0) to (1.0,1.0,1.0) along the Z axis.
	<b>-X Gradient</b> ramps the value from (1.0,0.0,0.0) to (0.0,0.0,0.0) along the X axis.
	<b>-Y Gradient</b> ramps the value from (0.0,1.0,0.0) to (0.0,0.0,0.0) along the Y axis.
	<b>-Z Gradient</b> ramps the value from (0.0,0.0,1.0) to (0.0,0.0,0.0) along the Z axis.
	<b>Center Gradient</b> ramps the value from one at the center to zero at the edges.
	*/
	UnsignedintID getVelocityGradient(){char buffer[4096];sprintf_s (buffer, "%s.vgr",mName.c_str());return (const char*)buffer;}
	/*<b>Velocity Scale</b> multiplies the value determined by the <b>Velocity Method</b>*/
	Float3ID getVelocityScale(){char buffer[4096];sprintf_s (buffer, "%s.vsc",mName.c_str());return (const char*)buffer;}
	/*The x component of the velocityScale*/
	FloatID getVelocityScaleX(){char buffer[4096];sprintf_s (buffer, "%s.vsc.vsx",mName.c_str());return (const char*)buffer;}
	/*The y component of the velocityScale*/
	FloatID getVelocityScaleY(){char buffer[4096];sprintf_s (buffer, "%s.vsc.vsy",mName.c_str());return (const char*)buffer;}
	/*The z component of the velocityScale*/
	FloatID getVelocityScaleZ(){char buffer[4096];sprintf_s (buffer, "%s.vsc.vsz",mName.c_str());return (const char*)buffer;}
	/*
	This parameter determines how thick and non-liquid the material is.
	At high values it is like tar, while at low values it is like water.
	When this is 1, the material reynolds number is 0, when it is 0,
	the reynolds number is 100000. At a value of 0.5 the reynolds is 1.
	*/
	FloatID getViscosity(){char buffer[4096];sprintf_s (buffer, "%s.viy",mName.c_str());return (const char*)buffer;}
	/*Internal Friction in velocity solving*/
	FloatID getFriction(){char buffer[4096];sprintf_s (buffer, "%s.fri",mName.c_str());return (const char*)buffer;}
	/*Amount of swirliness effects in velocity solution*/
	FloatID getVelocitySwirl(){char buffer[4096];sprintf_s (buffer, "%s.vsw",mName.c_str());return (const char*)buffer;}
	/*
	Amount velocity solution is damped towards zero each time step.
	At a value the flow is totally suppressed. Small amounts of damping
	can be useful when boundaries are open to keep strong winds from
	building up and leading to instability.
	*/
	FloatID getVelocityDamp(){char buffer[4096];sprintf_s (buffer, "%s.vdp",mName.c_str());return (const char*)buffer;}
	/*Turn on velocity solver.*/
	BoolID getVelocityAdvect(){char buffer[4096];sprintf_s (buffer, "%s.va",mName.c_str());return (const char*)buffer;}
	/*Turn on projection for velocity solver*/
	BoolID getVelocityProject(){char buffer[4096];sprintf_s (buffer, "%s.vi",mName.c_str());return (const char*)buffer;}
	/*
	Increasing this will increase the amount of force applied
	by the turbulence
	*/
	FloatID getTurbulenceStrength(){char buffer[4096];sprintf_s (buffer, "%s.tst",mName.c_str());return (const char*)buffer;}
	/*
	Lowering this will make the turbulence vortices larger. This
	is a spacial scale factor on the turbulence function and has
	no effect if the turbulence strength is zero.
	*/
	FloatID getTurbulenceFrequency(){char buffer[4096];sprintf_s (buffer, "%s.tfr",mName.c_str());return (const char*)buffer;}
	/*Rate at which turbulence pattern changes over time*/
	FloatID getTurbulenceSpeed(){char buffer[4096];sprintf_s (buffer, "%s.tbs",mName.c_str());return (const char*)buffer;}
	/*Scale of turbulence pattern relative to the fluid*/
	IntID getTurbulenceRes(){char buffer[4096];sprintf_s (buffer, "%s.trs",mName.c_str());return (const char*)buffer;}
	/*
	This defines how temperature is defined.
	<b>Off</b> sets the value to 0.0 across the volume.
	<b>Static Grid</b> Uses a grid without dynamic behavior.
	<b>Dynamic Grid</b> Uses a grid with a dynamic solver.
	<b>Gradient</b> ramps the value based on TemperatureGradient.
	*/
	UnsignedintID getTemperatureMethod(){char buffer[4096];sprintf_s (buffer, "%s.tmet",mName.c_str());return (const char*)buffer;}
	/*
	This defines how temperature can be ramped
	<b>Constant</b> sets the value to 1.0 across the volume.
	<b>X Gradient</b> ramps the value from zero to one along the X axis.
	<b>Y Gradient</b> ramps the value from zero to one along the Y axis.
	<b>Z Gradient</b> ramps the value from zero to one along the Z axis.
	<b>-X Gradient</b> ramps the value from one to zero along the X axis.
	<b>-Y Gradient</b> ramps the value from one to zero along the Y axis.
	<b>-Z Gradient</b> ramps the value from one to zero along the Z axis.
	<b>Center Gradient</b> ramps the value from one at the center to zero at the edges.
	*/
	UnsignedintID getTemperatureGradient(){char buffer[4096];sprintf_s (buffer, "%s.tgr",mName.c_str());return (const char*)buffer;}
	/*<b>Temperature Scale</b> multiplies the value determined by the <b>Temperature Method</b>*/
	FloatID getTemperatureScale(){char buffer[4096];sprintf_s (buffer, "%s.tmsc",mName.c_str());return (const char*)buffer;}
	/*Rate at which the temperature dissipates*/
	DoubleID getTemperatureDissipation(){char buffer[4096];sprintf_s (buffer, "%s.tds",mName.c_str());return (const char*)buffer;}
	/*Rate at which the temperature diffuses between voxels*/
	DoubleID getTemperatureDiffusion(){char buffer[4096];sprintf_s (buffer, "%s.tdf",mName.c_str());return (const char*)buffer;}
	/*Multiplier on the turbulence applied to the temperature*/
	FloatID getTemperatureTurbulence(){char buffer[4096];sprintf_s (buffer, "%s.ttb",mName.c_str());return (const char*)buffer;}
	/*Built in buoyancy strength for temperature solving*/
	FloatID getBuoyancy(){char buffer[4096];sprintf_s (buffer, "%s.buo",mName.c_str());return (const char*)buffer;}
	/*
	This defines how color is defined
	<b>Off</b> use the Shading Color instead
	<b>Static Grid</b> Uses a grid without dynamic behavior.
	<b>Dynamic Grid</b> Uses a grid with a dynamic solver.
	*/
	UnsignedintID getColorMethod(){char buffer[4096];sprintf_s (buffer, "%s.cmt",mName.c_str());return (const char*)buffer;}
	/*How much the color dissipates.*/
	DoubleID getColorDissipation(){char buffer[4096];sprintf_s (buffer, "%s.cds",mName.c_str());return (const char*)buffer;}
	/*Diffusion of the color*/
	DoubleID getColorDiffusion(){char buffer[4096];sprintf_s (buffer, "%s.cdf",mName.c_str());return (const char*)buffer;}
	/*
	This defines how the fuel value is defined.
	<b>Off</b> sets the value to 0.0 across the volume.
	<b>Dynamic Grid</b> Creates a grid for the fuel. This grid will
	be transported along with the density grid. The grid method must be
	used for the fuel to evolve over time.
	<b>Gradient</b> ramps the value based on FuelGradient.
	*/
	UnsignedintID getFuelMethod(){char buffer[4096];sprintf_s (buffer, "%s.fmet",mName.c_str());return (const char*)buffer;}
	/*
	This defines how fuel can be ramped
	<b>Constant</b> sets the value to 1.0 across the volume.
	<b>X Gradient</b> ramps the value from zero to one along the X axis.
	<b>Y Gradient</b> ramps the value from zero to one along the Y axis.
	<b>Z Gradient</b> ramps the value from zero to one along the Z axis.
	<b>-X Gradient</b> ramps the value from one to zero along the X axis.
	<b>-Y Gradient</b> ramps the value from one to zero along the Y axis.
	<b>-Z Gradient</b> ramps the value from one to zero along the Z axis.
	<b>Center Gradient</b> ramps the value from one at the center to zero at the edges.
	*/
	UnsignedintID getFuelGradient(){char buffer[4096];sprintf_s (buffer, "%s.fgr",mName.c_str());return (const char*)buffer;}
	/*<b>Fuel Scale</b> multiplies the value determined by the <b>Fuel Method</b>*/
	FloatID getFuelScale(){char buffer[4096];sprintf_s (buffer, "%s.fesc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Reaction Speed</b> determines how quickly the reaction converts
	from a value of 1 to zero when the temperature is at or above the
	<b>Max Reaction Temperature</b> value. A value of 1.0 will result in
	an instantanious reaction.
	*/
	FloatID getReactionSpeed(){char buffer[4096];sprintf_s (buffer, "%s.resp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fuel Ignition Temp</b> determines the lowest temperature at
	which a reaction will occur. The reaction rate is zero at this
	temperature increasing to the value defined by the <b>Reaction Speed</b>
	at the <b>Max Reaction Temperature</b>.
	*/
	FloatID getFuelIgnitionTemp(){char buffer[4096];sprintf_s (buffer, "%s.fuit",mName.c_str());return (const char*)buffer;}
	/*
	<b>Max Reaction Temp</b> determines the temperature beyond which
	which a reaction occurs at the fastest speed.
	*/
	FloatID getMaxReactionTemp(){char buffer[4096];sprintf_s (buffer, "%s.mxrt",mName.c_str());return (const char*)buffer;}
	/*
	<b>Heat Released</b> determines how much much heat is
	released into the temperature grid by a total reaction.
	This is how many reactions sustain themselves after an initial
	spark of ignition. The amount of heat added in a given step
	is proportional to the percentage of reacted material. One
	needs to have the <b>Temperature Method</b> set to Grid to use this
	option.
	*/
	FloatID getHeatReleased(){char buffer[4096];sprintf_s (buffer, "%s.hre",mName.c_str());return (const char*)buffer;}
	/*
	<b>Light Released</b> determines how much much light is
	released by the reaction. This is directly added into the
	final incandescent intensity of the shading and does not
	input into any grids.
	*/
	FloatID getLightReleased(){char buffer[4096];sprintf_s (buffer, "%s.lre",mName.c_str());return (const char*)buffer;}
	/*
	<b>Light Color</b> is the color of the light released by
	the reaction. The parameter <b>Light Released</b> along with
	the amount of fuel reacted in a given time step scales
	the overall brightness of this light.
	*/
	Float3ID getLightColor(){char buffer[4096];sprintf_s (buffer, "%s.lco",mName.c_str());return (const char*)buffer;}
	/*light color red value*/
	FloatID getLightColorR(){char buffer[4096];sprintf_s (buffer, "%s.lco.lcor",mName.c_str());return (const char*)buffer;}
	/*light color green value*/
	FloatID getLightColorG(){char buffer[4096];sprintf_s (buffer, "%s.lco.lcog",mName.c_str());return (const char*)buffer;}
	/*light color blue value*/
	FloatID getLightColorB(){char buffer[4096];sprintf_s (buffer, "%s.lco.lcob",mName.c_str());return (const char*)buffer;}
	/*
	Match the pre Maya7.0 dynamics behavior for the fluid.
	In 7.0 the damp, reactionSpeed and turbulence intensity
	were modified to preserve behavior when changing the
	frame rate or the sample rate. If you have loaded a fluid
	an older file this variable will automatically be enabled.
	If you wish the new behavior for such scenes use setAttr
	to turn off this attribute.
	*/
	BoolID getUsePre70Dynamics(){char buffer[4096];sprintf_s (buffer, "%s.updy",mName.c_str());return (const char*)buffer;}
	/*Output implicit surface.*/
	MeshID getOutMesh(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*
	Data from dynamic nodes for computing new output force.
	The field gets data from a set of "points" (particles, locations
	on a rigid body, etc.) and returns a force computed for each
	point.  Arbitrary user-defined nodes can make use of the field
	as Tint32 as they can give data for a set of points and can interpret
	the outputs.  Nodes using the field should take care to set
	up their attributes so as not to cause a DG loop.
	*/
	const InputDataID& getInputData(size_t ind_i){char buffer[4096];sprintf_s (buffer, "%s.ind[%i]",mName.c_str(),ind_i);return (const char*)buffer;}
	/*Input position array*/
	const VectorArrayID& getInputPositions(size_t ind_i){char buffer[4096];sprintf_s (buffer, "%s.ind[%i].inp",mName.c_str(),ind_i);return (const char*)buffer;}
	/*Input velocity array*/
	const VectorArrayID& getInputVelocities(size_t ind_i){char buffer[4096];sprintf_s (buffer, "%s.ind[%i].inv",mName.c_str(),ind_i);return (const char*)buffer;}
	/*Input mass array*/
	const DoubleArrayID& getInputMass(size_t ind_i){char buffer[4096];sprintf_s (buffer, "%s.ind[%i].inm",mName.c_str(),ind_i);return (const char*)buffer;}
	/*
	Some fields may need deltaTime to compute force.  Of the standard
	nodes, vortex is the only one.  User-defined nodes can use this
	attribute if they wish.
	*/
	const TimeID& getDeltaTime(size_t ind_i){char buffer[4096];sprintf_s (buffer, "%s.ind[%i].dt",mName.c_str(),ind_i);return (const char*)buffer;}
	/*
	Force data from dynamic nodes for computing new output force.
	If an array of forces is supplied here, the field will ADD its
	force to that array instead of writing it to outputForce.
	The particle shape uses this to gain some important efficiencies.
	*/
	const VectorArrayID& getInputForce2(size_t in2_i){char buffer[4096];sprintf_s (buffer, "%s.in2[%i]",mName.c_str(),in2_i);return (const char*)buffer;}
	/*
	Force data output to dynamic nodes.
	The entries in this output array match the input entries
	in inputPositions et al.
	*/
	const VectorArrayID& getOutputForce(size_t of_i){char buffer[4096];sprintf_s (buffer, "%s.of[%i]",mName.c_str(),of_i);return (const char*)buffer;}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you don't want the background to show through them.
	<p/>
	<b>Black Hole</b>:  The value of Matte Opacity is ignored, and all
	the matte for this material is set to be transparent.  Use this when
	you are creating substitute geometry in a scene, which is standing
	in for objects in a background image that you will be compositing with
	later.  Your stand-in objects will 'punch
	a hole' in the matte.  This allows other computer-generated
	geometry to pass behind your stand-in objects. Later, when
	foreground and background are composited, the results will be correct,
	with the background object showing through the 'black hole' areas.
	</ul>
	*/
	UnsignedintID getMatteOpacityMode(){char buffer[4096];sprintf_s (buffer, "%s.mom",mName.c_str());return (const char*)buffer;}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	FloatID getMatteOpacity(){char buffer[4096];sprintf_s (buffer, "%s.mog",mName.c_str());return (const char*)buffer;}
	/*The transform to go from eye to world space*/
	FltMatrixID getMatrixEyeToWorld(){char buffer[4096];sprintf_s (buffer, "%s.e2w",mName.c_str());return (const char*)buffer;}
	/*The transform to go from world to object space*/
	FltMatrixID getMatrixWorldToObject(){char buffer[4096];sprintf_s (buffer, "%s.w2o",mName.c_str());return (const char*)buffer;}
	/*The current start point of the volume interval*/
	Float3ID getPointWorld(){char buffer[4096];sprintf_s (buffer, "%s.pw",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointWorldX(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwx",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointWorldY(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointWorldZ(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwz",mName.c_str());return (const char*)buffer;}
	/*The end of the volume interval in world space.*/
	Float3ID getFarPointWorld(){char buffer[4096];sprintf_s (buffer, "%s.fw",mName.c_str());return (const char*)buffer;}
	/*The x-component of the world far-position.*/
	FloatID getFarPointWorldX(){char buffer[4096];sprintf_s (buffer, "%s.fw.fwx",mName.c_str());return (const char*)buffer;}
	/*The y-component of the world far-position.*/
	FloatID getFarPointWorldY(){char buffer[4096];sprintf_s (buffer, "%s.fw.fwy",mName.c_str());return (const char*)buffer;}
	/*The z-component of the world far-position.*/
	FloatID getFarPointWorldZ(){char buffer[4096];sprintf_s (buffer, "%s.fw.fwz",mName.c_str());return (const char*)buffer;}
	/*The current start point of the volume interval in object space*/
	Float3ID getPointObj(){char buffer[4096];sprintf_s (buffer, "%s.po",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointObjX(){char buffer[4096];sprintf_s (buffer, "%s.po.pox",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointObjY(){char buffer[4096];sprintf_s (buffer, "%s.po.poy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointObjZ(){char buffer[4096];sprintf_s (buffer, "%s.po.poz",mName.c_str());return (const char*)buffer;}
	/*The end of the volume interval in world space.*/
	Float3ID getFarPointObj(){char buffer[4096];sprintf_s (buffer, "%s.fo",mName.c_str());return (const char*)buffer;}
	/*The x-component of the object space far-position.*/
	FloatID getFarPointObjectX(){char buffer[4096];sprintf_s (buffer, "%s.fo.fox",mName.c_str());return (const char*)buffer;}
	/*The y-component of the object space far-position.*/
	FloatID getFarPointObjectY(){char buffer[4096];sprintf_s (buffer, "%s.fo.foy",mName.c_str());return (const char*)buffer;}
	/*The z-component of the object space far-position.*/
	FloatID getFarPointObjectZ(){char buffer[4096];sprintf_s (buffer, "%s.fo.foz",mName.c_str());return (const char*)buffer;}
	/*
	Unique ray identifier controlling the sampling distribution for
	volume light depth map shadows, fluid volume rendering, light
	fog, ray traced shadows, and motion blur.
	*/
	IntID getRayInstance(){char buffer[4096];sprintf_s (buffer, "%s.ryi",mName.c_str());return (const char*)buffer;}
	/*Determines whether self-shadowing should be computed or not*/
	BoolID getSelfShadowing(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*<b>Quality</b> determines the quality (number of samples per ray) used in the rendering*/
	FloatID getQuality(){char buffer[4096];sprintf_s (buffer, "%s.qua",mName.c_str());return (const char*)buffer;}
	/*
	Which interpolation algorithm to use when retrieving values from
	fractional points within a fluid grid when shading a ray. Sharply
	contrasting densitys may show grid artifacts( like a mesh with no
	normal smoothing ) with linear interpolation. Smooth interpolation
	renders slower, but gets rid of these problems.
	*/
	UnsignedintID getRenderInterpolator(){char buffer[4096];sprintf_s (buffer, "%s.rin",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color</b> defines a range of color values used to render the volume.
	The particular color selected from this range is determined by the
	<b>Color Input</b> parameter. The color represents how much
	incoming light is absorbed or scattered. If it is black all
	light is absorbed, while white materials scatter all incoming light.
	*/
	const ColorID& getColor(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i]",mName.c_str(),cl_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getColor_Position(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i].clp",mName.c_str(),cl_i);return (const char*)buffer;}
	/*Ramp color at the sibling position*/
	const Float3ID& getColor_Color(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i].clc",mName.c_str(),cl_i);return (const char*)buffer;}
	/*Ramp red channel value at the sibling position*/
	const FloatID& getColor_ColorR(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i].clc.clcr",mName.c_str(),cl_i);return (const char*)buffer;}
	/*Ramp green channel value at the sibling position*/
	const FloatID& getColor_ColorG(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i].clc.clcg",mName.c_str(),cl_i);return (const char*)buffer;}
	/*Ramp blue channel value at the sibling position*/
	const FloatID& getColor_ColorB(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i].clc.clcb",mName.c_str(),cl_i);return (const char*)buffer;}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	const UnsignedintID& getColor_Interp(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i].cli",mName.c_str(),cl_i);return (const char*)buffer;}
	/*
	Defines a the attribute used to index the color value.
	<b>Constant</b> sets the input to 1.0 or the end of the ramp.
	<b>Color</b> overrides the color range using the value defined by the
	grid and the color scale. This is useful when using color emission
	into the grid.
	The other options all sets the input to corresponding value from the grid.
	For example if density is used the start of the color ramp will be
	used for density values of 0 and the end value for densities of 1.0.
	The way midrange values map out is determined by the <b>Color Input Bias</b>
	*/
	UnsignedintID getColorInput(){char buffer[4096];sprintf_s (buffer, "%s.coi",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color Input Bias</b> adjusts the sensitivity of the selected
	color input used. Input values of 0 and 1 will always map to the
	start and end of the ramp value, although the bias determines
	where in the ramp a value of 0.5 will index. For example if one
	used density as an input, and the material becomes relatively
	opaque at a density of 0.001, then the density bias can be used
	to shift most of the ramp into this density range. This is easier
	Instead of cramming several values at the beginning of the ramp
	one can use the full range. If the input bias is 0.0 then a
	value of 0.5 will map to the exact middle of the color ramp.
	*/
	FloatID getColorInputBias(){char buffer[4096];sprintf_s (buffer, "%s.cib",mName.c_str());return (const char*)buffer;}
	/*
	<b>Opacity</b> defines a range of opacity values used to render the volume.
	The particular opacity value selected from this range is determined by the
	<b>Opacity Input</b> parameter. The opacity represents how much the material
	will block light. If the opacity is zero then the material is totally transparent.
	*/
	const OpacityID& getOpacity(size_t opa_i){char buffer[4096];sprintf_s (buffer, "%s.opa[%i]",mName.c_str(),opa_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getOpacity_Position(size_t opa_i){char buffer[4096];sprintf_s (buffer, "%s.opa[%i].opap",mName.c_str(),opa_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getOpacity_FloatValue(size_t opa_i){char buffer[4096];sprintf_s (buffer, "%s.opa[%i].opafv",mName.c_str(),opa_i);return (const char*)buffer;}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	const UnsignedintID& getOpacity_Interp(size_t opa_i){char buffer[4096];sprintf_s (buffer, "%s.opa[%i].opai",mName.c_str(),opa_i);return (const char*)buffer;}
	/*
	Defines a the attribute used to index the opacity value.
	<b>Constant</b> sets the input to 1.0 or the end of the curve.
	The other options all sets the input to corresponding value from the grid.
	For example if density is used the start of the curve will be
	used for density values of 0 and the end value for densities of 1.0.
	The way midrange values map out is determined by the <b>Opacity Input Bias</b>
	*/
	UnsignedintID getOpacityInput(){char buffer[4096];sprintf_s (buffer, "%s.opi",mName.c_str());return (const char*)buffer;}
	/*
	<b>Opacity Input Bias</b> adjusts the sensitivity of the selected
	opacity input used. Input values of 0 and 1 will always map to the
	start and end of the opacity curve, although the bias determines
	where in the curve a value of 0.5 will index. For example if one
	used density as an input, and one wishes the material to become
	opaque at a density of 0.001, then the density bias can be used
	to shift most of the curve into this density range.
	Instead of cramming several values at the beginning of the ramp
	one can use the full range. If the input bias is 0.0 then a
	value of 0.5 will map to the exact middle of the opacity curve.
	*/
	FloatID getOpacityInputBias(){char buffer[4096];sprintf_s (buffer, "%s.oib",mName.c_str());return (const char*)buffer;}
	/*
	<b>Transparency</b> combined with <b>Opacity</b> determine how
	much light can penetrate the defined density. Transparency scales
	the single channel opacity value allowing for a colored opacity.
	Note that a transparency of 0.5 0.5 0.5 may render
	slightly faster than other values.
	*/
	Float3ID getTransparency(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*transparency red value*/
	FloatID getTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.t.tr",mName.c_str());return (const char*)buffer;}
	/*transparency green value*/
	FloatID getTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.t.tg",mName.c_str());return (const char*)buffer;}
	/*transparency blue value*/
	FloatID getTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.t.tb",mName.c_str());return (const char*)buffer;}
	/*
	<b>ShadowOpacity</b> used to brighten-up or darken shadows
	cast from the volume. At 0.5 the shadows are attenuated in exact
	proportion to the transparency of the volume. At 0.0 no shadowing
	occurs and at 1.0 shadows are completely black and the volume is
	totally in shadow. To account for multiple-scattering values
	less than 0.5 can help make thick clouds appear more translucent.
	Values above 0.5 make the clouds unnaturally opaque to lights, but
	may be useful to accentuate self shadowing.
	*/
	FloatID getShadowOpacity(){char buffer[4096];sprintf_s (buffer, "%s.shp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Incandescence</b> controls the amount of light emitted from
	regions of density due to self illumination. The
	The particular color selected from this range is determined by the
	<b>Incandescence Input</b> parameter. Incandescent emission is not
	affected by illumination or shadowing.
	*/
	const IncandescenceID& getIncandescence(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i]",mName.c_str(),i_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getIncandescence_Position(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].ip",mName.c_str(),i_i);return (const char*)buffer;}
	/*Ramp color at the sibling position*/
	const Float3ID& getIncandescence_Color(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].ic",mName.c_str(),i_i);return (const char*)buffer;}
	/*Ramp red channel value at the sibling position*/
	const FloatID& getIncandescence_ColorR(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].ic.icr",mName.c_str(),i_i);return (const char*)buffer;}
	/*Ramp green channel value at the sibling position*/
	const FloatID& getIncandescence_ColorG(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].ic.icg",mName.c_str(),i_i);return (const char*)buffer;}
	/*Ramp blue channel value at the sibling position*/
	const FloatID& getIncandescence_ColorB(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].ic.icb",mName.c_str(),i_i);return (const char*)buffer;}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	const UnsignedintID& getIncandescence_Interp(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].ii",mName.c_str(),i_i);return (const char*)buffer;}
	/*
	Defines a the attribute used to index the incandescence value.
	<b>Constant</b> sets the input to 1.0 or the end of the ramp.
	<b>Color</b> overrides the incandescence range using the value defined by the
	grid and the color scale. This is useful when using color emission
	into the grid.
	The other options all sets the input to corresponding value from the grid.
	For example if density is used the start of the color ramp will be
	used for density values of 0 and the end value for densities of 1.0.
	The way midrange values map out is determined by the <b>Incandescence Input Bias</b>
	*/
	UnsignedintID getIncandescenceInput(){char buffer[4096];sprintf_s (buffer, "%s.ili",mName.c_str());return (const char*)buffer;}
	/*
	<b>Incandescence Input Bias</b> adjusts the sensitivity of the selected
	incandescence input used. Input values of 0 and 1 will always map to the
	start and end of the ramp value, although the bias determines
	where in the ramp a value of 0.5 will index. For example if one
	used density as an input, and the material becomes relatively
	opaque at a density of 0.001, then the density bias can be used
	to shift most of the ramp into this density range. This is easier
	Instead of cramming several values at the beginning of the ramp
	one can use the full range. If the input bias is 0.0 then a
	value of 0.5 will map to the exact middle of the incandescence ramp.
	*/
	FloatID getIncandescenceInputBias(){char buffer[4096];sprintf_s (buffer, "%s.iib",mName.c_str());return (const char*)buffer;}
	/*
	<b>Glow Intensity</b> is 0 by default, meaning that no glow is added to the
	material.  As this is turned up, the material seems to 'glow'
	with a faint halo of light around it.
	<p/>Note that this is different from the Incandescence attribute
	in a few important ways.  First, glow is added as a post-process
	at the end of rendering.  (Incandescence just makes the surface
	appear brighter.)  Second, glow adds a halo, which incandescence
	does not.
	*/
	FloatID getGlowIntensity(){char buffer[4096];sprintf_s (buffer, "%s.gi",mName.c_str());return (const char*)buffer;}
	/*
	<b>Specular</b> controls the amount of light emitted from
	regions of density due to self illumination.
	*/
	Float3ID getSpecularColor(){char buffer[4096];sprintf_s (buffer, "%s.spc",mName.c_str());return (const char*)buffer;}
	/*specular red value*/
	FloatID getSpecularColorR(){char buffer[4096];sprintf_s (buffer, "%s.spc.spr",mName.c_str());return (const char*)buffer;}
	/*specular green value*/
	FloatID getSpecularColorG(){char buffer[4096];sprintf_s (buffer, "%s.spc.spg",mName.c_str());return (const char*)buffer;}
	/*specular blue value*/
	FloatID getSpecularColorB(){char buffer[4096];sprintf_s (buffer, "%s.spc.spb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Cosine Power</b> is used to control the "tightness" of
	the specular highlights (also called 'hot spots') on the surface.
	The minimum value is 2.
	The higher the value, the more tighly focussed (smaller) is
	the highlight.
	*/
	FloatID getCosinePower(){char buffer[4096];sprintf_s (buffer, "%s.csp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Environment</b> defines a simple sky to ground environmental
	reflection using a ramp. The left of the ramp is the top of the
	sky and the right is the bottom.
	*/
	const EnvironmentID& getEnvironment(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i]",mName.c_str(),env_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getEnvironment_Position(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envp",mName.c_str(),env_i);return (const char*)buffer;}
	/*Ramp color at the sibling position*/
	const Float3ID& getEnvironment_Color(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envc",mName.c_str(),env_i);return (const char*)buffer;}
	/*Ramp red channel value at the sibling position*/
	const FloatID& getEnvironment_ColorR(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envc.envcr",mName.c_str(),env_i);return (const char*)buffer;}
	/*Ramp green channel value at the sibling position*/
	const FloatID& getEnvironment_ColorG(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envc.envcg",mName.c_str(),env_i);return (const char*)buffer;}
	/*Ramp blue channel value at the sibling position*/
	const FloatID& getEnvironment_ColorB(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envc.envcb",mName.c_str(),env_i);return (const char*)buffer;}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	const UnsignedintID& getEnvironment_Interp(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envi",mName.c_str(),env_i);return (const char*)buffer;}
	/*
	Defines a shape to use to define an outer boundary for
	creating a soft edged volume. If one
	is rendering a box volume then Cube should match the
	edges of the volume. Likewise for Sphere and Cone volumes.
	*/
	UnsignedintID getDropoffShape(){char buffer[4096];sprintf_s (buffer, "%s.dos",mName.c_str());return (const char*)buffer;}
	/*
	Defines the rate at which the density drops off towards the edge
	defined by the <b>Dropoff Shape</b>.
	*/
	FloatID getEdgeDropoff(){char buffer[4096];sprintf_s (buffer, "%s.edr",mName.c_str());return (const char*)buffer;}
	/*
	The maximum contrast in effective transparency of
	a volume span allowed by the adaptive subdivision
	sample method. When the contrast between two
	spans is greater than this value we subdivide the
	span. The contrast is defined as the effective difference
	in accumulated transparency from the viewpoint.
	If this value is high, then the sampling will look like
	uniform sampling. If the contrastTolerance is low then
	the quality will improve and the render time will increase,
	although we will not require as many samples as uniform
	sampling for a given render quality. The quality setting
	should be just high enough that one does not miss dense regions
	altogether( this creates artifacts like dotty fringes around clouds ).
	*/
	FloatID getContrastTolerance(){char buffer[4096];sprintf_s (buffer, "%s.ctl",mName.c_str());return (const char*)buffer;}
	/*
	If this is on then we draw a 2D surface as a heightfield rather
	than a flat plane. The opacity value is mapped to the height.
	*/
	BoolID getHeightField(){char buffer[4096];sprintf_s (buffer, "%s.hfld",mName.c_str());return (const char*)buffer;}
	/*
	If this is on then we draw a surface instead of a soft
	volume. Shaded Display must be set to <b>AsRender</b> in
	order to see the surface in the interactive draw, or the
	outMesh must have a connection. The surface location is
	determined by the current opacity combined with the surface
	threshold.
	*/
	BoolID getSurfaceRender(){char buffer[4096];sprintf_s (buffer, "%s.srr",mName.c_str());return (const char*)buffer;}
	/*Threshold value used to generate implicit surface*/
	FloatID getSurfaceThreshold(){char buffer[4096];sprintf_s (buffer, "%s.srt",mName.c_str());return (const char*)buffer;}
	/*
	This determines how close points sampled for a
	surface lie to the the exact surfaceThreshold density.
	The quality setting should be made just high enough that
	we do not miss regions containing the surface. The render
	then further refines the surface using this tolerance.
	If this is high then the surface will look dotty and of
	poor quality. Very low values will result in longer render times
	and better quality. The tolerance value is defined relative to
	the quality setting. The quality determines the uniform step size,
	so that the actual distance this defines is equal to
	the step size * surfaceTolerance.
	*/
	FloatID getSurfaceTolerance(){char buffer[4096];sprintf_s (buffer, "%s.stl",mName.c_str());return (const char*)buffer;}
	/*
	This takes internal density variations into account when
	doing surface renders. If soft surface is on then the inside
	of the density will not be a constant substance like glass
	but rather a continuously varying density such as a cloud.
	*/
	BoolID getSoftSurface(){char buffer[4096];sprintf_s (buffer, "%s.ssf",mName.c_str());return (const char*)buffer;}
	/*
	Index of refraction. This property affects how
	reflectivity changes with viewing angle. It makes
	use of Fresnel's law. Materials with a low refractive
	index are generally only reflective at glancing angles.
	This is useful for a wet look or for water, because water
	has a lower refractive index than most solids. At a refractive
	index of 1.0 the material is considered to be the same as
	the medium, and theoretically there should be no specularity
	in this case( as with a cloud ). However we turn on full specularity
	in this case (ie. no view angle modulation), for convenience.
	*/
	FloatID getRefractiveIndex(){char buffer[4096];sprintf_s (buffer, "%s.rei",mName.c_str());return (const char*)buffer;}
	/*
	Controls how fluid is sampled during rendering
	Jitter avoids banding artifacts, but adds noise
	to the final image unless the quality is set high.
	*/
	UnsignedintID getSampleMethod(){char buffer[4096];sprintf_s (buffer, "%s.smpm",mName.c_str());return (const char*)buffer;}
	/*
	Determines whether to use normal lights or a single built in
	directional light. The simple built in lighting is faster, especially for
	self shadowing, and it does not cast shadows or light onto other objects.
	Nor does it receive shadows from other objects.
	*/
	BoolID getRealLights(){char buffer[4096];sprintf_s (buffer, "%s.rl",mName.c_str());return (const char*)buffer;}
	/*
	<b>DirectionalLight</b> is the direction of the internal
	directional light used when <b>RealLights</b> is off.
	*/
	Float3ID getDirectionalLight(){char buffer[4096];sprintf_s (buffer, "%s.dl",mName.c_str());return (const char*)buffer;}
	/*directionalLight X value*/
	FloatID getDirectionalLightX(){char buffer[4096];sprintf_s (buffer, "%s.dl.dlx",mName.c_str());return (const char*)buffer;}
	/*directionalLight Y value*/
	FloatID getDirectionalLightY(){char buffer[4096];sprintf_s (buffer, "%s.dl.dly",mName.c_str());return (const char*)buffer;}
	/*directionalLight Z value*/
	FloatID getDirectionalLightZ(){char buffer[4096];sprintf_s (buffer, "%s.dl.dlz",mName.c_str());return (const char*)buffer;}
	/*
	Determines how to texture the volume's density.
	<b>Perlin Noise</b> is the standard 3D noise used in the solidFractal texture.
	<b>Billow</b> has a pluffy, cloudlike effect.
	<b>Wispy</b> is a perlin noise that uses a second noise as a smear
	map. This makes the noise stretch out in places, looking wispy. When the time
	attribute is animated the smear noise is moved causing an undulating effect.
	<b>Volume Wave</b> is a sum of 3D waves in space.
	<b>SpaceTime</b> is a 4 dimensional version of the perlin noise, where
	time is the 4th dimension.
	*/
	UnsignedintID getTextureType(){char buffer[4096];sprintf_s (buffer, "%s.tty",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color Texture</b> toggles the application of the current
	texture( determined by the texture type ) to the color input
	value.
	*/
	BoolID getColorTexture(){char buffer[4096];sprintf_s (buffer, "%s.ctx",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color Tex Gain</b> determines how much the texture affects
	the input value to the color. If the color range is red to blue,
	then texturing will cause red to blue variations. At a value of
	zero there will be no color texturing.
	*/
	FloatID getColorTexGain(){char buffer[4096];sprintf_s (buffer, "%s.ctxg",mName.c_str());return (const char*)buffer;}
	/*
	<b>Incand Texture</b> toggles the application of the current
	texture( determined by the texture type ) to the incandescence input
	value.
	*/
	BoolID getIncandTexture(){char buffer[4096];sprintf_s (buffer, "%s.itx",mName.c_str());return (const char*)buffer;}
	/*
	<b>Incand Tex Gain</b> determines how much the texture affects
	the input value to the incandescence. If the incandescence
	range is red to blue, then texturing will cause red to blue
	variations. At a value of zero there will be no incandescence texturing.
	*/
	FloatID getIncandTexGain(){char buffer[4096];sprintf_s (buffer, "%s.itxg",mName.c_str());return (const char*)buffer;}
	/*
	<b>Opacity Texture</b> toggles the application of the current
	texture( determined by the texture type ) to the opacity input
	value.
	*/
	BoolID getOpacityTexture(){char buffer[4096];sprintf_s (buffer, "%s.otx",mName.c_str());return (const char*)buffer;}
	/*
	<b>Opacity Tex Gain</b> determines how much the texture affects
	the input value to the opacity. If the opacity curve goes
	from 0.0 to 0.6, then texturing will cause
	variations between these values. At a value of
	zero there will be no opacity texturing.
	*/
	FloatID getOpacityTexGain(){char buffer[4096];sprintf_s (buffer, "%s.otxg",mName.c_str());return (const char*)buffer;}
	/*
	<b>InvertTexture</b> This reverses the range of the texture
	so that dense regions become thin and thin become dense.
	If it is on, then the texture = 1 - texture.
	*/
	BoolID getInvertTexture(){char buffer[4096];sprintf_s (buffer, "%s.ivt",mName.c_str());return (const char*)buffer;}
	/*
	<b>Amplitude</b> is a scaling factor applied to all the
	values in the texture, centered around the texture's
	average value.  This means that when you increase Amplitude,
	the light areas get lighter and the dark areas get darker.
	<p/>
	If the Volume Noise is being used as a bump map, then
	increasing Amplitude will make the bumps higher and the
	valleys deeper.
	<p/>If you set Amplitude to a value greater than 1.0, then
	those parts of the texture that scale out of range will be
	clipped.  On a bump map, this will show up as plateau regions.
	*/
	FloatID getAmplitude(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ratio</b> controls the frequency of the fractal
	noise.  Increase this value to increase the fineness of
	detail in the fractal,
	*/
	FloatID getRatio(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*
	<b>Threshold</b> is a number that is added to the whole
	fractal, making it uniformly brighter.  If some parts of
	the fractal are pushed up out of range (greater than 1.0),
	then they will be clipped to 1.0.  If the Volume Noise is being
	used as a bump map, this will show up as plateau regions.
	*/
	FloatID getThreshold(){char buffer[4096];sprintf_s (buffer, "%s.th",mName.c_str());return (const char*)buffer;}
	/*
	<b>Texture Scale</b> determines the scale of the noise in
	the local x,y and z directions. It has a similar to scaling
	the transform node for the texture.
	<p/>
	If you increase Scale in any particular direction, the
	fractal detail will seem to smear out in that direction.
	*/
	Float3ID getTextureScale(){char buffer[4096];sprintf_s (buffer, "%s.txsc",mName.c_str());return (const char*)buffer;}
	/*Scale X value*/
	FloatID getTextureScaleX(){char buffer[4096];sprintf_s (buffer, "%s.txsc.tscx",mName.c_str());return (const char*)buffer;}
	/*Scale Y value*/
	FloatID getTextureScaleY(){char buffer[4096];sprintf_s (buffer, "%s.txsc.tscy",mName.c_str());return (const char*)buffer;}
	/*Scale Z value*/
	FloatID getTextureScaleZ(){char buffer[4096];sprintf_s (buffer, "%s.txsc.tscz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Texture Origin</b> is the zero point for the noise.
	changing this value translates the noise through space.
	*/
	Float3ID getTextureOrigin(){char buffer[4096];sprintf_s (buffer, "%s.tor",mName.c_str());return (const char*)buffer;}
	/*Origin X value*/
	FloatID getTextureOriginX(){char buffer[4096];sprintf_s (buffer, "%s.tor.torx",mName.c_str());return (const char*)buffer;}
	/*Origin Y value*/
	FloatID getTextureOriginY(){char buffer[4096];sprintf_s (buffer, "%s.tor.tory",mName.c_str());return (const char*)buffer;}
	/*Origin Z value*/
	FloatID getTextureOriginZ(){char buffer[4096];sprintf_s (buffer, "%s.tor.torz",mName.c_str());return (const char*)buffer;}
	/*
	<b>DepthMax</b> controls
	how much calculation is done by the
	Volume Noise texture.  Fractal textures
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use
	Depth Max to control the maximum amount
	of calculation that the texure will do.
	*/
	ShortID getDepthMax(){char buffer[4096];sprintf_s (buffer, "%s.dm",mName.c_str());return (const char*)buffer;}
	/*
	<b>Frequency</b> This determines the fundamental frequency
	for the noise. As this value increases the noise becomes more
	detailed. It has the inverse effect of the scale parameter.
	*/
	FloatID getFrequency(){char buffer[4096];sprintf_s (buffer, "%s.fq",mName.c_str());return (const char*)buffer;}
	/*
	<b>Frequency Ratio</b> This determines the relative spacial
	scale of the noise frequencies. If this ratio is not a whole integer then
	the fractal will not repeat  at the integer uv boundaries. A
	cylinder with default placement would then display a seam.
	*/
	FloatID getFrequencyRatio(){char buffer[4096];sprintf_s (buffer, "%s.fr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Inflection</b> This applies a kink in the noise function
	This is useful for creating puffy or bumpy effects.
	It is equivalent to abs(noise) * 2 - 1.
	*/
	BoolID getInflection(){char buffer[4096];sprintf_s (buffer, "%s.in",mName.c_str());return (const char*)buffer;}
	/*
	<b>Texture Time</b> is used to animate the Noise texture.
	You can keyframe the Time attribute to control
	the rate and amount of change of the texture.
	Typing the expression "= time" into the edit cell will cause
	the texture to billow when rendered in an animation.
	Typing "= time * 2" will make it billow twice as fast.
	*/
	FloatID getTextureTime(){char buffer[4096];sprintf_s (buffer, "%s.tti",mName.c_str());return (const char*)buffer;}
	/*
	<b>Billow Density</b> controls how many cells there are imbedded
	in the medium used by the <b>Billow</b> noise type.
	At 1.0, the medium is completely packed
	with cells.  Reduce this value to make the cells more sparse.
	<p/>If the texture is being used as a bump map, then
	low values for Density will make it look like a smooth surface
	with occasional bumps on it.
	*/
	FloatID getBillowDensity(){char buffer[4096];sprintf_s (buffer, "%s.bd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Spottyness</b> controls the randomization of the density
	of the individual cells used by the <b>Billow</b> noise type.
	When Spottyness is close to 0,
	all the cells will be the same density.  As you increase
	Spottyness, some cells will be denser or thinner than others,
	in a random fashion.
	*/
	FloatID getSpottyness(){char buffer[4096];sprintf_s (buffer, "%s.sp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Size Rand</b> controls the randomization of the size
	of the individual blobs used by the <b>Billow</b> noise type.
	When it is close to 0,
	all the cells will be the same size.  As you increase
	<b>Size Rand</b>, some cells will be smaller than others,
	in a random fashion.
	*/
	FloatID getSizeRand(){char buffer[4096];sprintf_s (buffer, "%s.sr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Randomness</b> controls how the cells for the <b>Billow</b>
	noise type are arranged relative to one another.
	Set randomness to 1.0 to get a realistic
	random distribution of cells, as would be found in nature.
	If you set Randomness to 0, all the spots are laid out in a
	completely regular pattern.  This can provide interesting
	effects when used as a bump map;  you can make things like
	insect eyes, or machine-tooled raspy surfaces.
	*/
	FloatID getRandomness(){char buffer[4096];sprintf_s (buffer, "%s.rnd",mName.c_str());return (const char*)buffer;}
	/*
	This controls the way intensity falls off for individual blobs for
	the <b>Billow</b> noise type. <b>Linear</b> is a uniform falloff from the
	center to a value of zero at the edges of the blobs.<b>Smooth</b> is
	more natural looking, using a gaussian falloff. <b>Fast</b> focuses the
	intensity more towards the center of the blobs. <b>Bubble</b> uses a
	reverse falloff, fading to zero at the blob center.
	*/
	UnsignedintID getFalloff(){char buffer[4096];sprintf_s (buffer, "%s.falo",mName.c_str());return (const char*)buffer;}
	/*
	<b>NumWaves</b> determines how many waves to generate for the <b>VolumeWave</b>
	noise type. The larger this number the more random looking and slower the texture.
	*/
	ShortID getNumWaves(){char buffer[4096];sprintf_s (buffer, "%s.nw",mName.c_str());return (const char*)buffer;}
	/*
	<b>Implode</b> warps the noise function in a concentric fashion
	about a point defined by the <b>Implode Center</b>.
	At a value of zero there is no effect, while at a value of
	1.0 it is a spherical projection of the noise function, creating
	a starburst effect. Negative values can be used to skew the noise
	outward instead of inward.
	*/
	FloatID getImplode(){char buffer[4096];sprintf_s (buffer, "%s.imp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Implode Center</b> defines the center point about which the
	implode effect is defined.
	*/
	Float3ID getImplodeCenter(){char buffer[4096];sprintf_s (buffer, "%s.imc",mName.c_str());return (const char*)buffer;}
	/*<b>Implode Center X</b> x position for implode effect*/
	FloatID getImplodeCenterX(){char buffer[4096];sprintf_s (buffer, "%s.imc.imx",mName.c_str());return (const char*)buffer;}
	/*<b>Implode Center Y</b> y position for implode effect*/
	FloatID getImplodeCenterY(){char buffer[4096];sprintf_s (buffer, "%s.imc.imy",mName.c_str());return (const char*)buffer;}
	/*<b>Implode Center Z</b> z position for implode effect*/
	FloatID getImplodeCenterZ(){char buffer[4096];sprintf_s (buffer, "%s.imc.imz",mName.c_str());return (const char*)buffer;}
	/*The fog  output color.*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.ocl",mName.c_str());return (const char*)buffer;}
	/*The red component of the fog  output color.*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.ocl.ocr",mName.c_str());return (const char*)buffer;}
	/*The green component of the fog  output color.*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.ocl.ocg",mName.c_str());return (const char*)buffer;}
	/*The blue component of the fog  output color.*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.ocl.ocb",mName.c_str());return (const char*)buffer;}
	/*
	Out Glow Color is the final output glow color from this node
	(if this node is glowing)
	*/
	Float3ID getOutGlowColor(){char buffer[4096];sprintf_s (buffer, "%s.ogc",mName.c_str());return (const char*)buffer;}
	/*out glow color red value*/
	FloatID getOutGlowColorR(){char buffer[4096];sprintf_s (buffer, "%s.ogc.ogr",mName.c_str());return (const char*)buffer;}
	/*out glow color green value*/
	FloatID getOutGlowColorG(){char buffer[4096];sprintf_s (buffer, "%s.ogc.ogg",mName.c_str());return (const char*)buffer;}
	/*out glow color blue value*/
	FloatID getOutGlowColorB(){char buffer[4096];sprintf_s (buffer, "%s.ogc.ogb",mName.c_str());return (const char*)buffer;}
	/*The fog output transparency.*/
	Float3ID getOutTransparency(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*The red component of the fog output transparency.*/
	FloatID getOutTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.ot.otr",mName.c_str());return (const char*)buffer;}
	/*The green component of the fog output transparency.*/
	FloatID getOutTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.ot.otg",mName.c_str());return (const char*)buffer;}
	/*The blue component of the fog output transparency.*/
	FloatID getOutTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.ot.otb",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity*/
	Float3ID getOutMatteOpacity(){char buffer[4096];sprintf_s (buffer, "%s.omo",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity red value*/
	FloatID getOutMatteOpacityR(){char buffer[4096];sprintf_s (buffer, "%s.omo.omor",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity green value*/
	FloatID getOutMatteOpacityG(){char buffer[4096];sprintf_s (buffer, "%s.omo.omog",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity blue value*/
	FloatID getOutMatteOpacityB(){char buffer[4096];sprintf_s (buffer, "%s.omo.omob",mName.c_str());return (const char*)buffer;}
	/*Connection for playback cache node*/
	MessageID getDiskCache(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*Connection for initial conditions node*/
	MessageID getDiskCacheIC(){char buffer[4096];sprintf_s (buffer, "%s.dcic",mName.c_str());return (const char*)buffer;}
	/*
	During cache creation, if this object has a density grid
	write the grid to the disk cache
	*/
	BoolID getCacheDensity(){char buffer[4096];sprintf_s (buffer, "%s.cdns",mName.c_str());return (const char*)buffer;}
	/*
	When reading from a cache, if the cache contains a density grid
	read the density from the cache
	*/
	BoolID getLoadDensity(){char buffer[4096];sprintf_s (buffer, "%s.ldns",mName.c_str());return (const char*)buffer;}
	/*
	During cache creation, if this object has a velocity grid
	write the grid to the disk cache
	*/
	BoolID getCacheVelocity(){char buffer[4096];sprintf_s (buffer, "%s.cvel",mName.c_str());return (const char*)buffer;}
	/*
	When reading from a cache, if the cache contains a velocity grid
	read the velocity from the cache
	*/
	BoolID getLoadVelocity(){char buffer[4096];sprintf_s (buffer, "%s.lvel",mName.c_str());return (const char*)buffer;}
	/*
	During cache creation, if this object has a Temperature  grid
	write the grid to the disk cache
	*/
	BoolID getCacheTemperature(){char buffer[4096];sprintf_s (buffer, "%s.ctmp",mName.c_str());return (const char*)buffer;}
	/*
	When reading from a cache, if the cache contains a Temperature grid
	read the temperature from the cache
	*/
	BoolID getLoadTemperature(){char buffer[4096];sprintf_s (buffer, "%s.ltmp",mName.c_str());return (const char*)buffer;}
	/*
	During cache creation, if this object has a Color  grid
	write the grid to the disk cache
	*/
	BoolID getCacheColor(){char buffer[4096];sprintf_s (buffer, "%s.ccol",mName.c_str());return (const char*)buffer;}
	/*
	When reading from a cache, if the cache contains a Color grid
	read the color from the cache
	*/
	BoolID getLoadColor(){char buffer[4096];sprintf_s (buffer, "%s.lcol",mName.c_str());return (const char*)buffer;}
	/*
	During cache creation, if this object has a Reaction  grid
	write the grid to the disk cache
	*/
	BoolID getCacheReaction(){char buffer[4096];sprintf_s (buffer, "%s.crea",mName.c_str());return (const char*)buffer;}
	/*
	When reading from a cache, if the cache contains a Fuel grid
	read the fuel from the cache
	*/
	BoolID getLoadReaction(){char buffer[4096];sprintf_s (buffer, "%s.lrea",mName.c_str());return (const char*)buffer;}
	/*
	During cache creation, if this object has a Texture Coordinate grid
	write the grid to the disk cache
	*/
	BoolID getCacheTextureCoordinates(){char buffer[4096];sprintf_s (buffer, "%s.catc",mName.c_str());return (const char*)buffer;}
	/*
	When reading from a cache, if the cache contains a Texture
	Coordinate grid read the grid from the cache
	*/
	BoolID getLoadTextureCoordinates(){char buffer[4096];sprintf_s (buffer, "%s.lotc",mName.c_str());return (const char*)buffer;}
	/*
	During cache creation, if this object has a falloff grid
	write the grid to the disk cache
	*/
	BoolID getCacheFalloff(){char buffer[4096];sprintf_s (buffer, "%s.cfal",mName.c_str());return (const char*)buffer;}
	/*
	When reading from a cache, if the cache contains a falloff grid
	read the falloff from the cache
	*/
	BoolID getLoadFalloff(){char buffer[4096];sprintf_s (buffer, "%s.lfal",mName.c_str());return (const char*)buffer;}
	/*
	A toggle to turn enable collision of fluid flow with attached
	geometry.
	*/
	BoolID getCollide(){char buffer[4096];sprintf_s (buffer, "%s.cld",mName.c_str());return (const char*)buffer;}
	/*
	<b>Surface Shader Depth</b> controls how far in worldspace beyond a surface that
	we compute the fluid when used as a shader for surfaces(nurbs and polysets).
	*/
	FloatID getSurfaceShaderDepth(){char buffer[4096];sprintf_s (buffer, "%s.susd",mName.c_str());return (const char*)buffer;}
	/*the weight in the intensity calculation*/
	FloatID getParticleWeight(){char buffer[4096];sprintf_s (buffer, "%s.we",mName.c_str());return (const char*)buffer;}
	/*
	This parameter scales how fast coordinates are moved by the velocity
	when the coordinate method is GRID. At a value of 1.0 the coordinates
	are pushed through the volume at the same speed as the other contents,
	such as density. However this tends to result in the texture becoming
	smeared out after a few steps. Lower values tend to preserve the character
	of the texture and can look more natural. Animating this value can be
	useful in some situations, such as when one does not wish the texture to
	deform before a certain point( keyframe it to zero until the desired
	start point ).
	*/
	FloatID getCoordinateSpeed(){char buffer[4096];sprintf_s (buffer, "%s.csd",mName.c_str());return (const char*)buffer;}
	/*
	This is a root of following mental ray attributes.
	The following override flags applies to fluidShape node only,
	and does not have any effect on fluid texture nodes (both 2D and 3D).
	*/
	MentalRayControlsID getMentalRayControls(){char buffer[4096];sprintf_s (buffer, "%s.mrc",mName.c_str());return (const char*)buffer;}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideCaustics(){char buffer[4096];sprintf_s (buffer, "%s.mrc.oca",mName.c_str());return (const char*)buffer;}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	ShortID getMiCausticAccuracy(){char buffer[4096];sprintf_s (buffer, "%s.mrc.caa",mName.c_str());return (const char*)buffer;}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	FloatID getMiCausticRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.car",mName.c_str());return (const char*)buffer;}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideGlobalIllumination(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ogi",mName.c_str());return (const char*)buffer;}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	ShortID getMiGlobillumAccuracy(){char buffer[4096];sprintf_s (buffer, "%s.mrc.gia",mName.c_str());return (const char*)buffer;}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	FloatID getMiGlobillumRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.gir",mName.c_str());return (const char*)buffer;}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideFinalGather(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ofg",mName.c_str());return (const char*)buffer;}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	IntID getMiFinalGatherRays(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fry",mName.c_str());return (const char*)buffer;}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	FloatID getMiFinalGatherMinRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fmn",mName.c_str());return (const char*)buffer;}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	FloatID getMiFinalGatherMaxRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fmx",mName.c_str());return (const char*)buffer;}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	ShortID getMiFinalGatherFilter(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ffi",mName.c_str());return (const char*)buffer;}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	BoolID getMiFinalGatherView(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fgv",mName.c_str());return (const char*)buffer;}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default.
	*/
	BoolID getMiOverrideSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.oos",mName.c_str());return (const char*)buffer;}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	ShortID getMiMinSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mins",mName.c_str());return (const char*)buffer;}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	ShortID getMiMaxSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.maxs",mName.c_str());return (const char*)buffer;}
protected:
	FluidShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SurfaceShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FLUIDSHAPE_H__
