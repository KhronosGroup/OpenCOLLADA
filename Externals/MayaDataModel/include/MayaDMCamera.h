/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CAMERA_H__
#define __MayaDM_CAMERA_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
*/
class Camera : public Shape
{
public:
	/*
	This compound holds the post projection attributes that
	are used to define the post projection matrix.
	After the projection matrix is computed these attributes
	define how the projected image is ultimately displayed.
	*/
	struct PostProjection{
		double preScale;
		double2 filmTranslate;
		/*
		Film back roll control.  This compound contains the attributes
		that control the rotation of the projected image in the 3d view.
		*/
		struct FilmRollControl{
			double2 filmRollPivot;
			double filmRollValue;
			unsigned int filmRollOrder;
			void write(FILE* file) const
			{
				filmRollPivot.write(file);
				fprintf_s(file, " ");
				fprintf_s(file,"%f ", filmRollValue);
				fprintf_s(file,"%i", filmRollOrder);
			}
		} filmRollControl;
		double postScale;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", preScale);
			filmTranslate.write(file);
			fprintf_s(file, " ");
			filmRollControl.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%f", postScale);
		}
	};
	/*This is a root of following mental ray attributes.*/
	struct MentalRayControls{
		bool miFbComputeColor;
		short miFbBitsizeColor;
		bool miFbComputeAlpha;
		short miFbBitsizeAlpha;
		bool miFbComputeDepth;
		bool miFbComputeNormal;
		bool miFbComputeMotion;
		bool miFbComputeCoverage;
		bool miFbComputeTag;
		bool miFbComputeContour;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", miFbComputeColor);
			fprintf_s(file,"%i ", miFbBitsizeColor);
			fprintf_s(file,"%i ", miFbComputeAlpha);
			fprintf_s(file,"%i ", miFbBitsizeAlpha);
			fprintf_s(file,"%i ", miFbComputeDepth);
			fprintf_s(file,"%i ", miFbComputeNormal);
			fprintf_s(file,"%i ", miFbComputeMotion);
			fprintf_s(file,"%i ", miFbComputeCoverage);
			fprintf_s(file,"%i ", miFbComputeTag);
			fprintf_s(file,"%i ", miFbComputeContour);
		}
	};
public:
	Camera(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "camera"){}
	virtual ~Camera(){}
	/*If this camera is to be rendered*/
	void setRenderable(bool rnd){if(rnd == true) return; fprintf_s(mFile, "setAttr \".rnd\" %i;\n", rnd);}
	/*If this camera is to be rendered*/
	void setRenderable(const BoolID& rnd){fprintf_s(mFile,"connectAttr \"");rnd.write(mFile);fprintf_s(mFile,"\" \"%s.rnd\";\n",mName.c_str());}
	/*Camera aperture (inches)*/
	void setCameraAperture(const double2& cap){if(cap == double2(3.6, 2.4)) return; fprintf_s(mFile, "setAttr \".cap\" -type \"double2\" ");cap.write(mFile);fprintf_s(mFile,";\n");}
	/*Camera aperture (inches)*/
	void setCameraAperture(const Double2ID& cap){fprintf_s(mFile,"connectAttr \"");cap.write(mFile);fprintf_s(mFile,"\" \"%s.cap\";\n",mName.c_str());}
	/*Horizontal camera aperture (inches)*/
	void setHorizontalFilmAperture(double hfa){if(hfa == 0.0) return; fprintf_s(mFile, "setAttr \".cap.hfa\" %f;\n", hfa);}
	/*Horizontal camera aperture (inches)*/
	void setHorizontalFilmAperture(const DoubleID& hfa){fprintf_s(mFile,"connectAttr \"");hfa.write(mFile);fprintf_s(mFile,"\" \"%s.cap.hfa\";\n",mName.c_str());}
	/*Vertical camera aperture (inches)*/
	void setVerticalFilmAperture(double vfa){if(vfa == 0.0) return; fprintf_s(mFile, "setAttr \".cap.vfa\" %f;\n", vfa);}
	/*Vertical camera aperture (inches)*/
	void setVerticalFilmAperture(const DoubleID& vfa){fprintf_s(mFile,"connectAttr \"");vfa.write(mFile);fprintf_s(mFile,"\" \"%s.cap.vfa\";\n",mName.c_str());}
	/*Camera rendered overscan for camera shake*/
	void setShakeOverscan(double sos){if(sos == 1.0) return; fprintf_s(mFile, "setAttr \".sos\" %f;\n", sos);}
	/*Camera rendered overscan for camera shake*/
	void setShakeOverscan(const DoubleID& sos){fprintf_s(mFile,"connectAttr \"");sos.write(mFile);fprintf_s(mFile,"\" \"%s.sos\";\n",mName.c_str());}
	/*
	Camera Shake Overscan toggle
	When true, the shakeOverscan value is multiplied to the film aperture
	values.  Otherwise they are ignored.
	*/
	void setShakeOverscanEnabled(bool soe){if(soe == false) return; fprintf_s(mFile, "setAttr \".soe\" %i;\n", soe);}
	/*
	Camera Shake Overscan toggle
	When true, the shakeOverscan value is multiplied to the film aperture
	values.  Otherwise they are ignored.
	*/
	void setShakeOverscanEnabled(const BoolID& soe){fprintf_s(mFile,"connectAttr \"");soe.write(mFile);fprintf_s(mFile,"\" \"%s.soe\";\n",mName.c_str());}
	/*Film back offset (inches)*/
	void setFilmOffset(const double2& fio){if(fio == double2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".fio\" -type \"double2\" ");fio.write(mFile);fprintf_s(mFile,";\n");}
	/*Film back offset (inches)*/
	void setFilmOffset(const Double2ID& fio){fprintf_s(mFile,"connectAttr \"");fio.write(mFile);fprintf_s(mFile,"\" \"%s.fio\";\n",mName.c_str());}
	/*Horizontal film back offset (inches)*/
	void setHorizontalFilmOffset(double hfo){if(hfo == 0.0) return; fprintf_s(mFile, "setAttr \".fio.hfo\" %f;\n", hfo);}
	/*Horizontal film back offset (inches)*/
	void setHorizontalFilmOffset(const DoubleID& hfo){fprintf_s(mFile,"connectAttr \"");hfo.write(mFile);fprintf_s(mFile,"\" \"%s.fio.hfo\";\n",mName.c_str());}
	/*Vertical film back offset (inches)*/
	void setVerticalFilmOffset(double vfo){if(vfo == 0.0) return; fprintf_s(mFile, "setAttr \".fio.vfo\" %f;\n", vfo);}
	/*Vertical film back offset (inches)*/
	void setVerticalFilmOffset(const DoubleID& vfo){fprintf_s(mFile,"connectAttr \"");vfo.write(mFile);fprintf_s(mFile,"\" \"%s.fio.vfo\";\n",mName.c_str());}
	/*
	Camera Shake attribute toggle
	When true, the cameraShake values are added to the film offset
	values.  Otherwise they are ignored.
	*/
	void setShakeEnabled(bool se){if(se == false) return; fprintf_s(mFile, "setAttr \".se\" %i;\n", se);}
	/*
	Camera Shake attribute toggle
	When true, the cameraShake values are added to the film offset
	values.  Otherwise they are ignored.
	*/
	void setShakeEnabled(const BoolID& se){fprintf_s(mFile,"connectAttr \"");se.write(mFile);fprintf_s(mFile,"\" \"%s.se\";\n",mName.c_str());}
	/*Camera Shake offset (inches)*/
	void setShake(const double2& shk){if(shk == double2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".shk\" -type \"double2\" ");shk.write(mFile);fprintf_s(mFile,";\n");}
	/*Camera Shake offset (inches)*/
	void setShake(const Double2ID& shk){fprintf_s(mFile,"connectAttr \"");shk.write(mFile);fprintf_s(mFile,"\" \"%s.shk\";\n",mName.c_str());}
	/*Horizontal camera shake offset (inches)*/
	void setHorizontalShake(double hs){if(hs == 0.0) return; fprintf_s(mFile, "setAttr \".shk.hs\" %f;\n", hs);}
	/*Horizontal camera shake offset (inches)*/
	void setHorizontalShake(const DoubleID& hs){fprintf_s(mFile,"connectAttr \"");hs.write(mFile);fprintf_s(mFile,"\" \"%s.shk.hs\";\n",mName.c_str());}
	/*Vertical camera shake offset (inches)*/
	void setVerticalShake(double vs){if(vs == 0.0) return; fprintf_s(mFile, "setAttr \".shk.vs\" %f;\n", vs);}
	/*Vertical camera shake offset (inches)*/
	void setVerticalShake(const DoubleID& vs){fprintf_s(mFile,"connectAttr \"");vs.write(mFile);fprintf_s(mFile,"\" \"%s.shk.vs\";\n",mName.c_str());}
	/*Toggles the stereoHIT attribute's contribution*/
	void setStereoHorizontalImageTranslateEnabled(bool hte){if(hte == false) return; fprintf_s(mFile, "setAttr \".hte\" %i;\n", hte);}
	/*Toggles the stereoHIT attribute's contribution*/
	void setStereoHorizontalImageTranslateEnabled(const BoolID& hte){fprintf_s(mFile,"connectAttr \"");hte.write(mFile);fprintf_s(mFile,"\" \"%s.hte\";\n",mName.c_str());}
	/*Film Back offset (inches) for stereo*/
	void setStereoHorizontalImageTranslate(double hit){if(hit == 0.0) return; fprintf_s(mFile, "setAttr \".hit\" %f;\n", hit);}
	/*Film Back offset (inches) for stereo*/
	void setStereoHorizontalImageTranslate(const DoubleID& hit){fprintf_s(mFile,"connectAttr \"");hit.write(mFile);fprintf_s(mFile,"\" \"%s.hit\";\n",mName.c_str());}
	/*
	This compound holds the post projection attributes that
	are used to define the post projection matrix.
	After the projection matrix is computed these attributes
	define how the projected image is ultimately displayed.
	*/
	void setPostProjection(const PostProjection& ppj){fprintf_s(mFile, "setAttr \".ppj\" ");ppj.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This compound holds the post projection attributes that
	are used to define the post projection matrix.
	After the projection matrix is computed these attributes
	define how the projected image is ultimately displayed.
	*/
	void setPostProjection(const PostProjectionID& ppj){fprintf_s(mFile,"connectAttr \"");ppj.write(mFile);fprintf_s(mFile,"\" \"%s.ppj\";\n",mName.c_str());}
	/*
	Scale factor. First component added to the projection
	matrix.
	*/
	void setPreScale(double psc){if(psc == 1.0) return; fprintf_s(mFile, "setAttr \".ppj.psc\" %f;\n", psc);}
	/*
	Scale factor. First component added to the projection
	matrix.
	*/
	void setPreScale(const DoubleID& psc){fprintf_s(mFile,"connectAttr \"");psc.write(mFile);fprintf_s(mFile,"\" \"%s.ppj.psc\";\n",mName.c_str());}
	/*
	Post projection translation component. Translate the film back
	by the given values.  The values are normalized with respect to
	viewing area.
	*/
	void setFilmTranslate(const double2& ct){if(ct == double2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ppj.ct\" -type \"double2\" ");ct.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Post projection translation component. Translate the film back
	by the given values.  The values are normalized with respect to
	viewing area.
	*/
	void setFilmTranslate(const Double2ID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ppj.ct\";\n",mName.c_str());}
	/*Translate in horizontal direction.*/
	void setFilmTranslateH(double fth){if(fth == 0.0) return; fprintf_s(mFile, "setAttr \".ppj.ct.fth\" %f;\n", fth);}
	/*Translate in horizontal direction.*/
	void setFilmTranslateH(const DoubleID& fth){fprintf_s(mFile,"connectAttr \"");fth.write(mFile);fprintf_s(mFile,"\" \"%s.ppj.ct.fth\";\n",mName.c_str());}
	/*Translate in vertical direction.*/
	void setFilmTranslateV(double ftv){if(ftv == 0.0) return; fprintf_s(mFile, "setAttr \".ppj.ct.ftv\" %f;\n", ftv);}
	/*Translate in vertical direction.*/
	void setFilmTranslateV(const DoubleID& ftv){fprintf_s(mFile,"connectAttr \"");ftv.write(mFile);fprintf_s(mFile,"\" \"%s.ppj.ct.ftv\";\n",mName.c_str());}
	/*
	Film back roll control.  This compound contains the attributes
	that control the rotation of the projected image in the 3d view.
	*/
	void setFilmRollControl(const PostProjection::FilmRollControl& frc){fprintf_s(mFile, "setAttr \".ppj.frc\" ");frc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Film back roll control.  This compound contains the attributes
	that control the rotation of the projected image in the 3d view.
	*/
	void setFilmRollControl(const FilmRollControlID& frc){fprintf_s(mFile,"connectAttr \"");frc.write(mFile);fprintf_s(mFile,"\" \"%s.ppj.frc\";\n",mName.c_str());}
	/*
	The 2D point on the projected image to rotate film back around.
	These values are normalized to the viewing area of the camera.
	*/
	void setFilmRollPivot(const double2& frp){if(frp == double2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ppj.frc.frp\" -type \"double2\" ");frp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The 2D point on the projected image to rotate film back around.
	These values are normalized to the viewing area of the camera.
	*/
	void setFilmRollPivot(const Double2ID& frp){fprintf_s(mFile,"connectAttr \"");frp.write(mFile);fprintf_s(mFile,"\" \"%s.ppj.frc.frp\";\n",mName.c_str());}
	/*Horizontal roll pivot.*/
	void setHorizontalRollPivot(double hrp){if(hrp == 0.0) return; fprintf_s(mFile, "setAttr \".ppj.frc.frp.hrp\" %f;\n", hrp);}
	/*Horizontal roll pivot.*/
	void setHorizontalRollPivot(const DoubleID& hrp){fprintf_s(mFile,"connectAttr \"");hrp.write(mFile);fprintf_s(mFile,"\" \"%s.ppj.frc.frp.hrp\";\n",mName.c_str());}
	/*Vertical roll pivot.*/
	void setVerticalRollPivot(double vrp){if(vrp == 0.0) return; fprintf_s(mFile, "setAttr \".ppj.frc.frp.vrp\" %f;\n", vrp);}
	/*Vertical roll pivot.*/
	void setVerticalRollPivot(const DoubleID& vrp){fprintf_s(mFile,"connectAttr \"");vrp.write(mFile);fprintf_s(mFile,"\" \"%s.ppj.frc.frp.vrp\";\n",mName.c_str());}
	/*Roll value. The amount of rotation to apply to the film back.*/
	void setFilmRollValue(double frv){if(frv == 0) return; fprintf_s(mFile, "setAttr \".ppj.frc.frv\" %f;\n", frv);}
	/*Roll value. The amount of rotation to apply to the film back.*/
	void setFilmRollValue(const DoubleID& frv){fprintf_s(mFile,"connectAttr \"");frv.write(mFile);fprintf_s(mFile,"\" \"%s.ppj.frc.frv\";\n",mName.c_str());}
	/*
	The order in which to apply the rotation with respect to the
	filmTranslate, rotate-translate or translate-rotate.
	rotate-translate implies that the rotate will occur before the
	translation, and the translate-rotate implies that the translation
	will occur before the rotation.
	*/
	void setFilmRollOrder(unsigned int fro){if(fro == 0) return; fprintf_s(mFile, "setAttr \".ppj.frc.fro\" %i;\n", fro);}
	/*
	The order in which to apply the rotation with respect to the
	filmTranslate, rotate-translate or translate-rotate.
	rotate-translate implies that the rotate will occur before the
	translation, and the translate-rotate implies that the translation
	will occur before the rotation.
	*/
	void setFilmRollOrder(const UnsignedintID& fro){fprintf_s(mFile,"connectAttr \"");fro.write(mFile);fprintf_s(mFile,"\" \"%s.ppj.frc.fro\";\n",mName.c_str());}
	/*
	Scale factor applied after all of the other pre-projection
	attributes have been applied.
	*/
	void setPostScale(double ptsc){if(ptsc == 1.0) return; fprintf_s(mFile, "setAttr \".ppj.ptsc\" %f;\n", ptsc);}
	/*
	Scale factor applied after all of the other pre-projection
	attributes have been applied.
	*/
	void setPostScale(const DoubleID& ptsc){fprintf_s(mFile,"connectAttr \"");ptsc.write(mFile);fprintf_s(mFile,"\" \"%s.ppj.ptsc\";\n",mName.c_str());}
	/*Match the view to film aspect ratio using a: 0 fill, 1 horizontal, 2 vertical, 3 overscan fit.*/
	void setFilmFit(unsigned int ff){if(ff == 1) return; fprintf_s(mFile, "setAttr \".ff\" %i;\n", ff);}
	/*Match the view to film aspect ratio using a: 0 fill, 1 horizontal, 2 vertical, 3 overscan fit.*/
	void setFilmFit(const UnsignedintID& ff){fprintf_s(mFile,"connectAttr \"");ff.write(mFile);fprintf_s(mFile,"\" \"%s.ff\";\n",mName.c_str());}
	/*Amount to move the smaller image within the larger one (inches)*/
	void setFilmFitOffset(double ffo){if(ffo == 0.0) return; fprintf_s(mFile, "setAttr \".ffo\" %f;\n", ffo);}
	/*Amount to move the smaller image within the larger one (inches)*/
	void setFilmFitOffset(const DoubleID& ffo){fprintf_s(mFile,"connectAttr \"");ffo.write(mFile);fprintf_s(mFile,"\" \"%s.ffo\";\n",mName.c_str());}
	/*The percent over the film viewable frustum to display*/
	void setOverscan(double ovr){if(ovr == 1.0) return; fprintf_s(mFile, "setAttr \".ovr\" %f;\n", ovr);}
	/*The percent over the film viewable frustum to display*/
	void setOverscan(const DoubleID& ovr){fprintf_s(mFile,"connectAttr \"");ovr.write(mFile);fprintf_s(mFile,"\" \"%s.ovr\";\n",mName.c_str());}
	/*Camera focal length in millimeters*/
	void setFocalLength(double fl){if(fl == 35.0) return; fprintf_s(mFile, "setAttr \".fl\" %f;\n", fl);}
	/*Camera focal length in millimeters*/
	void setFocalLength(const DoubleID& fl){fprintf_s(mFile,"connectAttr \"");fl.write(mFile);fprintf_s(mFile,"\" \"%s.fl\";\n",mName.c_str());}
	/*Lens squeeze ratio*/
	void setLensSqueezeRatio(double lsr){if(lsr == 1.0) return; fprintf_s(mFile, "setAttr \".lsr\" %f;\n", lsr);}
	/*Lens squeeze ratio*/
	void setLensSqueezeRatio(const DoubleID& lsr){fprintf_s(mFile,"connectAttr \"");lsr.write(mFile);fprintf_s(mFile,"\" \"%s.lsr\";\n",mName.c_str());}
	/*Scale of the camera focal length for simulating differently sized cameras without changing other attributes.*/
	void setCameraScale(double cs){if(cs == 1.0) return; fprintf_s(mFile, "setAttr \".cs\" %f;\n", cs);}
	/*Scale of the camera focal length for simulating differently sized cameras without changing other attributes.*/
	void setCameraScale(const DoubleID& cs){fprintf_s(mFile,"connectAttr \"");cs.write(mFile);fprintf_s(mFile,"\" \"%s.cs\";\n",mName.c_str());}
	/*
	Trigger an update, which includes refreshing of any active viewports.
	By dirtying this attribute, an update will be triggered. You can
	connect an output attribute from some other node that needs to
	trigger an update to this attribute. The actual value has no meaning:
	its the fact that it gets set that triggers the update.
	*/
	void setTriggerUpdate(double tu){if(tu == 0.0) return; fprintf_s(mFile, "setAttr \".tu\" %f;\n", tu);}
	/*
	Trigger an update, which includes refreshing of any active viewports.
	By dirtying this attribute, an update will be triggered. You can
	connect an output attribute from some other node that needs to
	trigger an update to this attribute. The actual value has no meaning:
	its the fact that it gets set that triggers the update.
	*/
	void setTriggerUpdate(const DoubleID& tu){fprintf_s(mFile,"connectAttr \"");tu.write(mFile);fprintf_s(mFile,"\" \"%s.tu\";\n",mName.c_str());}
	/*Distance from the camera to the near clipping plane (object space)*/
	void setNearClipPlane(double ncp){if(ncp == 0) return; fprintf_s(mFile, "setAttr \".ncp\" %f;\n", ncp);}
	/*Distance from the camera to the near clipping plane (object space)*/
	void setNearClipPlane(const DoubleID& ncp){fprintf_s(mFile,"connectAttr \"");ncp.write(mFile);fprintf_s(mFile,"\" \"%s.ncp\";\n",mName.c_str());}
	/*Distance from the camera to the far clipping plane (object space)*/
	void setFarClipPlane(double fcp){if(fcp == 1) return; fprintf_s(mFile, "setAttr \".fcp\" %f;\n", fcp);}
	/*Distance from the camera to the far clipping plane (object space)*/
	void setFarClipPlane(const DoubleID& fcp){fprintf_s(mFile,"connectAttr \"");fcp.write(mFile);fprintf_s(mFile,"\" \"%s.fcp\";\n",mName.c_str());}
	/*Set the camera F/Stop*/
	void setFStop(double fs){if(fs == 5.6) return; fprintf_s(mFile, "setAttr \".fs\" %f;\n", fs);}
	/*Set the camera F/Stop*/
	void setFStop(const DoubleID& fs){fprintf_s(mFile,"connectAttr \"");fs.write(mFile);fprintf_s(mFile,"\" \"%s.fs\";\n",mName.c_str());}
	/*Distance to the focus point*/
	void setFocusDistance(double fd){if(fd == 5) return; fprintf_s(mFile, "setAttr \".fd\" %f;\n", fd);}
	/*Distance to the focus point*/
	void setFocusDistance(const DoubleID& fd){fprintf_s(mFile,"connectAttr \"");fd.write(mFile);fprintf_s(mFile,"\" \"%s.fd\";\n",mName.c_str());}
	/*The shutter angle for motion blur*/
	void setShutterAngle(double sa){if(sa == 1) return; fprintf_s(mFile, "setAttr \".sa\" %f;\n", sa);}
	/*The shutter angle for motion blur*/
	void setShutterAngle(const DoubleID& sa){fprintf_s(mFile,"connectAttr \"");sa.write(mFile);fprintf_s(mFile,"\" \"%s.sa\";\n",mName.c_str());}
	/*Distance to the center of interest (object space)*/
	void setCenterOfInterest(double coi){if(coi == 5) return; fprintf_s(mFile, "setAttr \".coi\" %f;\n", coi);}
	/*Distance to the center of interest (object space)*/
	void setCenterOfInterest(const DoubleID& coi){fprintf_s(mFile,"connectAttr \"");coi.write(mFile);fprintf_s(mFile,"\" \"%s.coi\";\n",mName.c_str());}
	/*Distance of the orthographic width*/
	void setOrthographicWidth(double ow){if(ow == 1) return; fprintf_s(mFile, "setAttr \".ow\" %f;\n", ow);}
	/*Distance of the orthographic width*/
	void setOrthographicWidth(const DoubleID& ow){fprintf_s(mFile,"connectAttr \"");ow.write(mFile);fprintf_s(mFile,"\" \"%s.ow\";\n",mName.c_str());}
	/*Image name*/
	void setImageName(const string& imn){if(imn == "NULL") return; fprintf_s(mFile, "setAttr \".imn\" -type \"string\" ");imn.write(mFile);fprintf_s(mFile,";\n");}
	/*Image name*/
	void setImageName(const StringID& imn){fprintf_s(mFile,"connectAttr \"");imn.write(mFile);fprintf_s(mFile,"\" \"%s.imn\";\n",mName.c_str());}
	/*Depth name*/
	void setDepthName(const string& den){if(den == "NULL") return; fprintf_s(mFile, "setAttr \".den\" -type \"string\" ");den.write(mFile);fprintf_s(mFile,";\n");}
	/*Depth name*/
	void setDepthName(const StringID& den){fprintf_s(mFile,"connectAttr \"");den.write(mFile);fprintf_s(mFile,"\" \"%s.den\";\n",mName.c_str());}
	/*Mask name*/
	void setMaskName(const string& man){if(man == "NULL") return; fprintf_s(mFile, "setAttr \".man\" -type \"string\" ");man.write(mFile);fprintf_s(mFile,";\n");}
	/*Mask name*/
	void setMaskName(const StringID& man){fprintf_s(mFile,"connectAttr \"");man.write(mFile);fprintf_s(mFile,"\" \"%s.man\";\n",mName.c_str());}
	/*World point to tumble about (world space)*/
	void setTumblePivot(const double3& tp){if(tp == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".tp\" -type \"double3\" ");tp.write(mFile);fprintf_s(mFile,";\n");}
	/*World point to tumble about (world space)*/
	void setTumblePivot(const Double3ID& tp){fprintf_s(mFile,"connectAttr \"");tp.write(mFile);fprintf_s(mFile,"\" \"%s.tp\";\n",mName.c_str());}
	/*World X to tumble about*/
	void setTumblePivotX(double tpx){if(tpx == 0.0) return; fprintf_s(mFile, "setAttr \".tp.tpx\" %f;\n", tpx);}
	/*World X to tumble about*/
	void setTumblePivotX(const DoubleID& tpx){fprintf_s(mFile,"connectAttr \"");tpx.write(mFile);fprintf_s(mFile,"\" \"%s.tp.tpx\";\n",mName.c_str());}
	/*World Y to tumble about*/
	void setTumblePivotY(double tpy){if(tpy == 0.0) return; fprintf_s(mFile, "setAttr \".tp.tpy\" %f;\n", tpy);}
	/*World Y to tumble about*/
	void setTumblePivotY(const DoubleID& tpy){fprintf_s(mFile,"connectAttr \"");tpy.write(mFile);fprintf_s(mFile,"\" \"%s.tp.tpy\";\n",mName.c_str());}
	/*World Z to tumble about*/
	void setTumblePivotZ(double tpz){if(tpz == 0.0) return; fprintf_s(mFile, "setAttr \".tp.tpz\" %f;\n", tpz);}
	/*World Z to tumble about*/
	void setTumblePivotZ(const DoubleID& tpz){fprintf_s(mFile,"connectAttr \"");tpz.write(mFile);fprintf_s(mFile,"\" \"%s.tp.tpz\";\n",mName.c_str());}
	/*
	How this camera wants to be tumbled: false to use the setting from
	the tumble tool, and true to tumble about the camera's axis.
	*/
	void setUsePivotAsLocalSpace(bool uls){if(uls == 0) return; fprintf_s(mFile, "setAttr \".uls\" %i;\n", uls);}
	/*
	How this camera wants to be tumbled: false to use the setting from
	the tumble tool, and true to tumble about the camera's axis.
	*/
	void setUsePivotAsLocalSpace(const BoolID& uls){fprintf_s(mFile,"connectAttr \"");uls.write(mFile);fprintf_s(mFile,"\" \"%s.uls\";\n",mName.c_str());}
	/*Command to get a camera back to its home position*/
	void setHomeCommand(const string& hc){if(hc == "NULL") return; fprintf_s(mFile, "setAttr \".hc\" -type \"string\" ");hc.write(mFile);fprintf_s(mFile,";\n");}
	/*Command to get a camera back to its home position*/
	void setHomeCommand(const StringID& hc){fprintf_s(mFile,"connectAttr \"");hc.write(mFile);fprintf_s(mFile,"\" \"%s.hc\";\n",mName.c_str());}
	/*Scales factor for the camera locator.*/
	void setLocatorScale(double lls){if(lls == 1.0) return; fprintf_s(mFile, "setAttr \".lls\" %f;\n", lls);}
	/*Scales factor for the camera locator.*/
	void setLocatorScale(const DoubleID& lls){fprintf_s(mFile,"connectAttr \"");lls.write(mFile);fprintf_s(mFile,"\" \"%s.lls\";\n",mName.c_str());}
	/*Display the icons to show the film gate*/
	void setDisplayFilmGate(bool dfg){if(dfg == false) return; fprintf_s(mFile, "setAttr \".dfg\" %i;\n", dfg);}
	/*Display the icons to show the film gate*/
	void setDisplayFilmGate(const BoolID& dfg){fprintf_s(mFile,"connectAttr \"");dfg.write(mFile);fprintf_s(mFile,"\" \"%s.dfg\";\n",mName.c_str());}
	/*Display the icons to show the rendering resolution*/
	void setDisplayResolution(bool dr){if(dr == false) return; fprintf_s(mFile, "setAttr \".dr\" %i;\n", dr);}
	/*Display the icons to show the rendering resolution*/
	void setDisplayResolution(const BoolID& dr){fprintf_s(mFile,"connectAttr \"");dr.write(mFile);fprintf_s(mFile,"\" \"%s.dr\";\n",mName.c_str());}
	/*Display the video safe action area*/
	void setDisplaySafeAction(bool dsa){if(dsa == false) return; fprintf_s(mFile, "setAttr \".dsa\" %i;\n", dsa);}
	/*Display the video safe action area*/
	void setDisplaySafeAction(const BoolID& dsa){fprintf_s(mFile,"connectAttr \"");dsa.write(mFile);fprintf_s(mFile,"\" \"%s.dsa\";\n",mName.c_str());}
	/*Display the video safe title area*/
	void setDisplaySafeTitle(bool dst){if(dst == false) return; fprintf_s(mFile, "setAttr \".dst\" %i;\n", dst);}
	/*Display the video safe title area*/
	void setDisplaySafeTitle(const BoolID& dst){fprintf_s(mFile,"connectAttr \"");dst.write(mFile);fprintf_s(mFile,"\" \"%s.dst\";\n",mName.c_str());}
	/*Display the video field chart*/
	void setDisplayFieldChart(bool dfc){if(dfc == false) return; fprintf_s(mFile, "setAttr \".dfc\" %i;\n", dfc);}
	/*Display the video field chart*/
	void setDisplayFieldChart(const BoolID& dfc){fprintf_s(mFile,"connectAttr \"");dfc.write(mFile);fprintf_s(mFile,"\" \"%s.dfc\";\n",mName.c_str());}
	/*Display the film back pivot point*/
	void setDisplayFilmPivot(bool dfp){if(dfp == false) return; fprintf_s(mFile, "setAttr \".dfp\" %i;\n", dfp);}
	/*Display the film back pivot point*/
	void setDisplayFilmPivot(const BoolID& dfp){fprintf_s(mFile,"connectAttr \"");dfp.write(mFile);fprintf_s(mFile,"\" \"%s.dfp\";\n",mName.c_str());}
	/*Display the location of the origin on the filmback.*/
	void setDisplayFilmOrigin(bool dfo){if(dfo == false) return; fprintf_s(mFile, "setAttr \".dfo\" %i;\n", dfo);}
	/*Display the location of the origin on the filmback.*/
	void setDisplayFilmOrigin(const BoolID& dfo){fprintf_s(mFile,"connectAttr \"");dfo.write(mFile);fprintf_s(mFile,"\" \"%s.dfo\";\n",mName.c_str());}
	/*Unused attribute; will be removed in a future release*/
	void setClippingPlanes(bool cp){if(cp == true) return; fprintf_s(mFile, "setAttr \".cp\" %i;\n", cp);}
	/*Unused attribute; will be removed in a future release*/
	void setClippingPlanes(const BoolID& cp){fprintf_s(mFile,"connectAttr \"");cp.write(mFile);fprintf_s(mFile,"\" \"%s.cp\";\n",mName.c_str());}
	/*Activate manual clipping planes for rendering*/
	void setBestFitClippingPlanes(bool bfc){if(bfc == true) return; fprintf_s(mFile, "setAttr \".bfc\" %i;\n", bfc);}
	/*Activate manual clipping planes for rendering*/
	void setBestFitClippingPlanes(const BoolID& bfc){fprintf_s(mFile,"connectAttr \"");bfc.write(mFile);fprintf_s(mFile,"\" \"%s.bfc\";\n",mName.c_str());}
	/*Activate the depth of field effect*/
	void setDepthOfField(bool dof){if(dof == false) return; fprintf_s(mFile, "setAttr \".dof\" %i;\n", dof);}
	/*Activate the depth of field effect*/
	void setDepthOfField(const BoolID& dof){fprintf_s(mFile,"connectAttr \"");dof.write(mFile);fprintf_s(mFile,"\" \"%s.dof\";\n",mName.c_str());}
	/*Activate the motion blur effect*/
	void setMotionBlur(bool mb){if(mb == false) return; fprintf_s(mFile, "setAttr \".mb\" %i;\n", mb);}
	/*Activate the motion blur effect*/
	void setMotionBlur(const BoolID& mb){fprintf_s(mFile,"connectAttr \"");mb.write(mFile);fprintf_s(mFile,"\" \"%s.mb\";\n",mName.c_str());}
	/*Activate the orthographic projection*/
	void setOrthographic(bool o){if(o == false) return; fprintf_s(mFile, "setAttr \".o\" %i;\n", o);}
	/*Activate the orthographic projection*/
	void setOrthographic(const BoolID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Activate journaling*/
	void setJournalCommand(bool jc){if(jc == false) return; fprintf_s(mFile, "setAttr \".jc\" %i;\n", jc);}
	/*Activate journaling*/
	void setJournalCommand(const BoolID& jc){fprintf_s(mFile,"connectAttr \"");jc.write(mFile);fprintf_s(mFile,"\" \"%s.jc\";\n",mName.c_str());}
	/*Activate image output*/
	void setImage(bool img){if(img == true) return; fprintf_s(mFile, "setAttr \".img\" %i;\n", img);}
	/*Activate image output*/
	void setImage(const BoolID& img){fprintf_s(mFile,"connectAttr \"");img.write(mFile);fprintf_s(mFile,"\" \"%s.img\";\n",mName.c_str());}
	/*Activate depth output*/
	void setDepth(bool dep){if(dep == false) return; fprintf_s(mFile, "setAttr \".dep\" %i;\n", dep);}
	/*Activate depth output*/
	void setDepth(const BoolID& dep){fprintf_s(mFile,"connectAttr \"");dep.write(mFile);fprintf_s(mFile,"\" \"%s.dep\";\n",mName.c_str());}
	/*Activate Transparency based depth output*/
	void setTransparencyBasedDepth(bool tdth){if(tdth == true) return; fprintf_s(mFile, "setAttr \".tdth\" %i;\n", tdth);}
	/*Activate Transparency based depth output*/
	void setTransparencyBasedDepth(const BoolID& tdth){fprintf_s(mFile,"connectAttr \"");tdth.write(mFile);fprintf_s(mFile,"\" \"%s.tdth\";\n",mName.c_str());}
	/*Threshold of the transparency value used for transparency based depth output*/
	void setThreshold(double tthd){if(tthd == 0.9) return; fprintf_s(mFile, "setAttr \".tthd\" %f;\n", tthd);}
	/*Threshold of the transparency value used for transparency based depth output*/
	void setThreshold(const DoubleID& tthd){fprintf_s(mFile,"connectAttr \"");tthd.write(mFile);fprintf_s(mFile,"\" \"%s.tthd\";\n",mName.c_str());}
	/*Depth output based on 0: closest visible or 1:furthest visible object*/
	void setDepthType(unsigned int dptp){if(dptp == 1) return; fprintf_s(mFile, "setAttr \".dptp\" %i;\n", dptp);}
	/*Depth output based on 0: closest visible or 1:furthest visible object*/
	void setDepthType(const UnsignedintID& dptp){fprintf_s(mFile,"connectAttr \"");dptp.write(mFile);fprintf_s(mFile,"\" \"%s.dptp\";\n",mName.c_str());}
	/*Use explore format for depth output, something we will delete eventually.*/
	void setUseExploreDepthFormat(bool uexd){if(uexd == false) return; fprintf_s(mFile, "setAttr \".uexd\" %i;\n", uexd);}
	/*Use explore format for depth output, something we will delete eventually.*/
	void setUseExploreDepthFormat(const BoolID& uexd){fprintf_s(mFile,"connectAttr \"");uexd.write(mFile);fprintf_s(mFile,"\" \"%s.uexd\";\n",mName.c_str());}
	/*Activate mask output*/
	void setMask(bool ma){if(ma == true) return; fprintf_s(mFile, "setAttr \".ma\" %i;\n", ma);}
	/*Activate mask output*/
	void setMask(const BoolID& ma){fprintf_s(mFile,"connectAttr \"");ma.write(mFile);fprintf_s(mFile,"\" \"%s.ma\";\n",mName.c_str());}
	/*background color*/
	void setBackgroundColor(const float3& col){fprintf_s(mFile, "setAttr \".col\" -type \"float3\" ");col.write(mFile);fprintf_s(mFile,";\n");}
	/*background color*/
	void setBackgroundColor(const Float3ID& col){fprintf_s(mFile,"connectAttr \"");col.write(mFile);fprintf_s(mFile,"\" \"%s.col\";\n",mName.c_str());}
	/*background R value*/
	void setBackgroundColorR(float colr){if(colr == 0.0) return; fprintf_s(mFile, "setAttr \".col.colr\" %f;\n", colr);}
	/*background R value*/
	void setBackgroundColorR(const FloatID& colr){fprintf_s(mFile,"connectAttr \"");colr.write(mFile);fprintf_s(mFile,"\" \"%s.col.colr\";\n",mName.c_str());}
	/*background G value*/
	void setBackgroundColorG(float colg){if(colg == 0.0) return; fprintf_s(mFile, "setAttr \".col.colg\" %f;\n", colg);}
	/*background G value*/
	void setBackgroundColorG(const FloatID& colg){fprintf_s(mFile,"connectAttr \"");colg.write(mFile);fprintf_s(mFile,"\" \"%s.col.colg\";\n",mName.c_str());}
	/*background B value*/
	void setBackgroundColorB(float colb){if(colb == 0.0) return; fprintf_s(mFile, "setAttr \".col.colb\" %f;\n", colb);}
	/*background B value*/
	void setBackgroundColorB(const FloatID& colb){fprintf_s(mFile,"connectAttr \"");colb.write(mFile);fprintf_s(mFile,"\" \"%s.col.colb\";\n",mName.c_str());}
	/*scale factor applied to the focus distance and the value of each DOF depth image pixel during the Depth-of-Field computation*/
	void setFocusRegionScale(double frs){if(frs == 1.0) return; fprintf_s(mFile, "setAttr \".frs\" %f;\n", frs);}
	/*scale factor applied to the focus distance and the value of each DOF depth image pixel during the Depth-of-Field computation*/
	void setFocusRegionScale(const DoubleID& frs){fprintf_s(mFile,"connectAttr \"");frs.write(mFile);fprintf_s(mFile,"\" \"%s.frs\";\n",mName.c_str());}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControls& mrc){fprintf_s(mFile, "setAttr \".mrc\" ");mrc.write(mFile);fprintf_s(mFile,";\n");}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControlsID& mrc){fprintf_s(mFile,"connectAttr \"");mrc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc\";\n",mName.c_str());}
	/*Port to connect custom mental ray node of type output shader.*/
	void setMiOutputShader(const GenerictypeddataID& mios){fprintf_s(mFile,"connectAttr \"");mios.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mios\";\n",mName.c_str());}
	/*Request color framebuffer for custom output shader (rgb).*/
	void setMiFbComputeColor(bool micc){if(micc == true) return; fprintf_s(mFile, "setAttr \".mrc.micc\" %i;\n", micc);}
	/*Request color framebuffer for custom output shader (rgb).*/
	void setMiFbComputeColor(const BoolID& micc){fprintf_s(mFile,"connectAttr \"");micc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.micc\";\n",mName.c_str());}
	/*
	Request bitdepth for color framebuffer, either
	8 (0), 16 (1), or 32 (2) bits per color component.
	*/
	void setMiFbBitsizeColor(short mict){if(mict == 0) return; fprintf_s(mFile, "setAttr \".mrc.mict\" %i;\n", mict);}
	/*
	Request bitdepth for color framebuffer, either
	8 (0), 16 (1), or 32 (2) bits per color component.
	*/
	void setMiFbBitsizeColor(const ShortID& mict){fprintf_s(mFile,"connectAttr \"");mict.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mict\";\n",mName.c_str());}
	/*Request alpha channel framebuffer for custom output.*/
	void setMiFbComputeAlpha(bool mica){if(mica == false) return; fprintf_s(mFile, "setAttr \".mrc.mica\" %i;\n", mica);}
	/*Request alpha channel framebuffer for custom output.*/
	void setMiFbComputeAlpha(const BoolID& mica){fprintf_s(mFile,"connectAttr \"");mica.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mica\";\n",mName.c_str());}
	/*
	Request bitdepth for alpha framebuffer,
	either 8 (0), 16 (1), or 32 (2) bits.
	*/
	void setMiFbBitsizeAlpha(short miat){if(miat == 0) return; fprintf_s(mFile, "setAttr \".mrc.miat\" %i;\n", miat);}
	/*
	Request bitdepth for alpha framebuffer,
	either 8 (0), 16 (1), or 32 (2) bits.
	*/
	void setMiFbBitsizeAlpha(const ShortID& miat){fprintf_s(mFile,"connectAttr \"");miat.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.miat\";\n",mName.c_str());}
	/*Request z-depth scalar framebuffer for custom output.*/
	void setMiFbComputeDepth(bool micd){if(micd == false) return; fprintf_s(mFile, "setAttr \".mrc.micd\" %i;\n", micd);}
	/*Request z-depth scalar framebuffer for custom output.*/
	void setMiFbComputeDepth(const BoolID& micd){fprintf_s(mFile,"connectAttr \"");micd.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.micd\";\n",mName.c_str());}
	/*Request normal vector framebuffer for custom output.*/
	void setMiFbComputeNormal(bool micn){if(micn == false) return; fprintf_s(mFile, "setAttr \".mrc.micn\" %i;\n", micn);}
	/*Request normal vector framebuffer for custom output.*/
	void setMiFbComputeNormal(const BoolID& micn){fprintf_s(mFile,"connectAttr \"");micn.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.micn\";\n",mName.c_str());}
	/*Request motion vector framebuffer for custom output.*/
	void setMiFbComputeMotion(bool micm){if(micm == false) return; fprintf_s(mFile, "setAttr \".mrc.micm\" %i;\n", micm);}
	/*Request motion vector framebuffer for custom output.*/
	void setMiFbComputeMotion(const BoolID& micm){fprintf_s(mFile,"connectAttr \"");micm.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.micm\";\n",mName.c_str());}
	/*Request coverage scalar framebuffer for custom output.*/
	void setMiFbComputeCoverage(bool micv){if(micv == false) return; fprintf_s(mFile, "setAttr \".mrc.micv\" %i;\n", micv);}
	/*Request coverage scalar framebuffer for custom output.*/
	void setMiFbComputeCoverage(const BoolID& micv){fprintf_s(mFile,"connectAttr \"");micv.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.micv\";\n",mName.c_str());}
	/*Request label integer framebuffer for custom output.*/
	void setMiFbComputeTag(bool mitg){if(mitg == false) return; fprintf_s(mFile, "setAttr \".mrc.mitg\" %i;\n", mitg);}
	/*Request label integer framebuffer for custom output.*/
	void setMiFbComputeTag(const BoolID& mitg){fprintf_s(mFile,"connectAttr \"");mitg.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mitg\";\n",mName.c_str());}
	/*Request contour framebuffer for custom output.*/
	void setMiFbComputeContour(bool mico){if(mico == false) return; fprintf_s(mFile, "setAttr \".mrc.mico\" %i;\n", mico);}
	/*Request contour framebuffer for custom output.*/
	void setMiFbComputeContour(const BoolID& mico){fprintf_s(mFile,"connectAttr \"");mico.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mico\";\n",mName.c_str());}
	/*Port to connect custom mental ray node of type volume shader.*/
	void setMiVolumeShader(const GenerictypeddataID& mivs){fprintf_s(mFile,"connectAttr \"");mivs.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mivs\";\n",mName.c_str());}
	/*Port to connect custom mental ray node of type lens shader.*/
	void setMiLensShader(const GenerictypeddataID& mils){fprintf_s(mFile,"connectAttr \"");mils.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mils\";\n",mName.c_str());}
	/*Port to connect custom mental ray node of type environment shader.*/
	void setMiEnvironmentShader(const GenerictypeddataID& mies){fprintf_s(mFile,"connectAttr \"");mies.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mies\";\n",mName.c_str());}
	/*
	Port to connect multiple custom mental ray nodes of type output shader.
	Appended to the output shader list.
	*/
	void setMiOutputShaderList(size_t miol_i,const GenerictypeddataID& miol){fprintf_s(mFile,"connectAttr \"");miol.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.miol[%i]\";\n",mName.c_str(),miol_i);}
	/*
	Port to connect multiple custom mental ray nodes of type lens shader
	Appended to the lens shader list.
	*/
	void setMiLensShaderList(size_t mill_i,const GenerictypeddataID& mill){fprintf_s(mFile,"connectAttr \"");mill.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mill[%i]\";\n",mName.c_str(),mill_i);}
	/*Connect multiple render passes.*/
	void setMiRenderPassList(size_t mirp_i,const MessageID& mirp){fprintf_s(mFile,"connectAttr \"");mirp.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mirp[%i]\";\n",mName.c_str(),mirp_i);}
	/*If this camera is to be rendered*/
	BoolID getRenderable(){char buffer[4096];sprintf_s (buffer, "%s.rnd",mName.c_str());return (const char*)buffer;}
	/*Camera aperture (inches)*/
	Double2ID getCameraAperture(){char buffer[4096];sprintf_s (buffer, "%s.cap",mName.c_str());return (const char*)buffer;}
	/*Horizontal camera aperture (inches)*/
	DoubleID getHorizontalFilmAperture(){char buffer[4096];sprintf_s (buffer, "%s.cap.hfa",mName.c_str());return (const char*)buffer;}
	/*Vertical camera aperture (inches)*/
	DoubleID getVerticalFilmAperture(){char buffer[4096];sprintf_s (buffer, "%s.cap.vfa",mName.c_str());return (const char*)buffer;}
	/*Camera rendered overscan for camera shake*/
	DoubleID getShakeOverscan(){char buffer[4096];sprintf_s (buffer, "%s.sos",mName.c_str());return (const char*)buffer;}
	/*
	Camera Shake Overscan toggle
	When true, the shakeOverscan value is multiplied to the film aperture
	values.  Otherwise they are ignored.
	*/
	BoolID getShakeOverscanEnabled(){char buffer[4096];sprintf_s (buffer, "%s.soe",mName.c_str());return (const char*)buffer;}
	/*Film back offset (inches)*/
	Double2ID getFilmOffset(){char buffer[4096];sprintf_s (buffer, "%s.fio",mName.c_str());return (const char*)buffer;}
	/*Horizontal film back offset (inches)*/
	DoubleID getHorizontalFilmOffset(){char buffer[4096];sprintf_s (buffer, "%s.fio.hfo",mName.c_str());return (const char*)buffer;}
	/*Vertical film back offset (inches)*/
	DoubleID getVerticalFilmOffset(){char buffer[4096];sprintf_s (buffer, "%s.fio.vfo",mName.c_str());return (const char*)buffer;}
	/*
	Camera Shake attribute toggle
	When true, the cameraShake values are added to the film offset
	values.  Otherwise they are ignored.
	*/
	BoolID getShakeEnabled(){char buffer[4096];sprintf_s (buffer, "%s.se",mName.c_str());return (const char*)buffer;}
	/*Camera Shake offset (inches)*/
	Double2ID getShake(){char buffer[4096];sprintf_s (buffer, "%s.shk",mName.c_str());return (const char*)buffer;}
	/*Horizontal camera shake offset (inches)*/
	DoubleID getHorizontalShake(){char buffer[4096];sprintf_s (buffer, "%s.shk.hs",mName.c_str());return (const char*)buffer;}
	/*Vertical camera shake offset (inches)*/
	DoubleID getVerticalShake(){char buffer[4096];sprintf_s (buffer, "%s.shk.vs",mName.c_str());return (const char*)buffer;}
	/*Toggles the stereoHIT attribute's contribution*/
	BoolID getStereoHorizontalImageTranslateEnabled(){char buffer[4096];sprintf_s (buffer, "%s.hte",mName.c_str());return (const char*)buffer;}
	/*Film Back offset (inches) for stereo*/
	DoubleID getStereoHorizontalImageTranslate(){char buffer[4096];sprintf_s (buffer, "%s.hit",mName.c_str());return (const char*)buffer;}
	/*
	This compound holds the post projection attributes that
	are used to define the post projection matrix.
	After the projection matrix is computed these attributes
	define how the projected image is ultimately displayed.
	*/
	PostProjectionID getPostProjection(){char buffer[4096];sprintf_s (buffer, "%s.ppj",mName.c_str());return (const char*)buffer;}
	/*
	Scale factor. First component added to the projection
	matrix.
	*/
	DoubleID getPreScale(){char buffer[4096];sprintf_s (buffer, "%s.ppj.psc",mName.c_str());return (const char*)buffer;}
	/*
	Post projection translation component. Translate the film back
	by the given values.  The values are normalized with respect to
	viewing area.
	*/
	Double2ID getFilmTranslate(){char buffer[4096];sprintf_s (buffer, "%s.ppj.ct",mName.c_str());return (const char*)buffer;}
	/*Translate in horizontal direction.*/
	DoubleID getFilmTranslateH(){char buffer[4096];sprintf_s (buffer, "%s.ppj.ct.fth",mName.c_str());return (const char*)buffer;}
	/*Translate in vertical direction.*/
	DoubleID getFilmTranslateV(){char buffer[4096];sprintf_s (buffer, "%s.ppj.ct.ftv",mName.c_str());return (const char*)buffer;}
	/*
	Film back roll control.  This compound contains the attributes
	that control the rotation of the projected image in the 3d view.
	*/
	FilmRollControlID getFilmRollControl(){char buffer[4096];sprintf_s (buffer, "%s.ppj.frc",mName.c_str());return (const char*)buffer;}
	/*
	The 2D point on the projected image to rotate film back around.
	These values are normalized to the viewing area of the camera.
	*/
	Double2ID getFilmRollPivot(){char buffer[4096];sprintf_s (buffer, "%s.ppj.frc.frp",mName.c_str());return (const char*)buffer;}
	/*Horizontal roll pivot.*/
	DoubleID getHorizontalRollPivot(){char buffer[4096];sprintf_s (buffer, "%s.ppj.frc.frp.hrp",mName.c_str());return (const char*)buffer;}
	/*Vertical roll pivot.*/
	DoubleID getVerticalRollPivot(){char buffer[4096];sprintf_s (buffer, "%s.ppj.frc.frp.vrp",mName.c_str());return (const char*)buffer;}
	/*Roll value. The amount of rotation to apply to the film back.*/
	DoubleID getFilmRollValue(){char buffer[4096];sprintf_s (buffer, "%s.ppj.frc.frv",mName.c_str());return (const char*)buffer;}
	/*
	The order in which to apply the rotation with respect to the
	filmTranslate, rotate-translate or translate-rotate.
	rotate-translate implies that the rotate will occur before the
	translation, and the translate-rotate implies that the translation
	will occur before the rotation.
	*/
	UnsignedintID getFilmRollOrder(){char buffer[4096];sprintf_s (buffer, "%s.ppj.frc.fro",mName.c_str());return (const char*)buffer;}
	/*
	Scale factor applied after all of the other pre-projection
	attributes have been applied.
	*/
	DoubleID getPostScale(){char buffer[4096];sprintf_s (buffer, "%s.ppj.ptsc",mName.c_str());return (const char*)buffer;}
	/*Match the view to film aspect ratio using a: 0 fill, 1 horizontal, 2 vertical, 3 overscan fit.*/
	UnsignedintID getFilmFit(){char buffer[4096];sprintf_s (buffer, "%s.ff",mName.c_str());return (const char*)buffer;}
	/*Amount to move the smaller image within the larger one (inches)*/
	DoubleID getFilmFitOffset(){char buffer[4096];sprintf_s (buffer, "%s.ffo",mName.c_str());return (const char*)buffer;}
	/*The percent over the film viewable frustum to display*/
	DoubleID getOverscan(){char buffer[4096];sprintf_s (buffer, "%s.ovr",mName.c_str());return (const char*)buffer;}
	/*Camera focal length in millimeters*/
	DoubleID getFocalLength(){char buffer[4096];sprintf_s (buffer, "%s.fl",mName.c_str());return (const char*)buffer;}
	/*Lens squeeze ratio*/
	DoubleID getLensSqueezeRatio(){char buffer[4096];sprintf_s (buffer, "%s.lsr",mName.c_str());return (const char*)buffer;}
	/*Scale of the camera focal length for simulating differently sized cameras without changing other attributes.*/
	DoubleID getCameraScale(){char buffer[4096];sprintf_s (buffer, "%s.cs",mName.c_str());return (const char*)buffer;}
	/*
	Trigger an update, which includes refreshing of any active viewports.
	By dirtying this attribute, an update will be triggered. You can
	connect an output attribute from some other node that needs to
	trigger an update to this attribute. The actual value has no meaning:
	its the fact that it gets set that triggers the update.
	*/
	DoubleID getTriggerUpdate(){char buffer[4096];sprintf_s (buffer, "%s.tu",mName.c_str());return (const char*)buffer;}
	/*Distance from the camera to the near clipping plane (object space)*/
	DoubleID getNearClipPlane(){char buffer[4096];sprintf_s (buffer, "%s.ncp",mName.c_str());return (const char*)buffer;}
	/*Distance from the camera to the far clipping plane (object space)*/
	DoubleID getFarClipPlane(){char buffer[4096];sprintf_s (buffer, "%s.fcp",mName.c_str());return (const char*)buffer;}
	/*Set the camera F/Stop*/
	DoubleID getFStop(){char buffer[4096];sprintf_s (buffer, "%s.fs",mName.c_str());return (const char*)buffer;}
	/*Distance to the focus point*/
	DoubleID getFocusDistance(){char buffer[4096];sprintf_s (buffer, "%s.fd",mName.c_str());return (const char*)buffer;}
	/*The shutter angle for motion blur*/
	DoubleID getShutterAngle(){char buffer[4096];sprintf_s (buffer, "%s.sa",mName.c_str());return (const char*)buffer;}
	/*Distance to the center of interest (object space)*/
	DoubleID getCenterOfInterest(){char buffer[4096];sprintf_s (buffer, "%s.coi",mName.c_str());return (const char*)buffer;}
	/*Distance of the orthographic width*/
	DoubleID getOrthographicWidth(){char buffer[4096];sprintf_s (buffer, "%s.ow",mName.c_str());return (const char*)buffer;}
	/*Image name*/
	StringID getImageName(){char buffer[4096];sprintf_s (buffer, "%s.imn",mName.c_str());return (const char*)buffer;}
	/*Depth name*/
	StringID getDepthName(){char buffer[4096];sprintf_s (buffer, "%s.den",mName.c_str());return (const char*)buffer;}
	/*Mask name*/
	StringID getMaskName(){char buffer[4096];sprintf_s (buffer, "%s.man",mName.c_str());return (const char*)buffer;}
	/*World point to tumble about (world space)*/
	Double3ID getTumblePivot(){char buffer[4096];sprintf_s (buffer, "%s.tp",mName.c_str());return (const char*)buffer;}
	/*World X to tumble about*/
	DoubleID getTumblePivotX(){char buffer[4096];sprintf_s (buffer, "%s.tp.tpx",mName.c_str());return (const char*)buffer;}
	/*World Y to tumble about*/
	DoubleID getTumblePivotY(){char buffer[4096];sprintf_s (buffer, "%s.tp.tpy",mName.c_str());return (const char*)buffer;}
	/*World Z to tumble about*/
	DoubleID getTumblePivotZ(){char buffer[4096];sprintf_s (buffer, "%s.tp.tpz",mName.c_str());return (const char*)buffer;}
	/*
	How this camera wants to be tumbled: false to use the setting from
	the tumble tool, and true to tumble about the camera's axis.
	*/
	BoolID getUsePivotAsLocalSpace(){char buffer[4096];sprintf_s (buffer, "%s.uls",mName.c_str());return (const char*)buffer;}
	/*Command to get a camera back to its home position*/
	StringID getHomeCommand(){char buffer[4096];sprintf_s (buffer, "%s.hc",mName.c_str());return (const char*)buffer;}
	/*Scales factor for the camera locator.*/
	DoubleID getLocatorScale(){char buffer[4096];sprintf_s (buffer, "%s.lls",mName.c_str());return (const char*)buffer;}
	/*Display the icons to show the film gate*/
	BoolID getDisplayFilmGate(){char buffer[4096];sprintf_s (buffer, "%s.dfg",mName.c_str());return (const char*)buffer;}
	/*Display the icons to show the rendering resolution*/
	BoolID getDisplayResolution(){char buffer[4096];sprintf_s (buffer, "%s.dr",mName.c_str());return (const char*)buffer;}
	/*Display the video safe action area*/
	BoolID getDisplaySafeAction(){char buffer[4096];sprintf_s (buffer, "%s.dsa",mName.c_str());return (const char*)buffer;}
	/*Display the video safe title area*/
	BoolID getDisplaySafeTitle(){char buffer[4096];sprintf_s (buffer, "%s.dst",mName.c_str());return (const char*)buffer;}
	/*Display the video field chart*/
	BoolID getDisplayFieldChart(){char buffer[4096];sprintf_s (buffer, "%s.dfc",mName.c_str());return (const char*)buffer;}
	/*Display the film back pivot point*/
	BoolID getDisplayFilmPivot(){char buffer[4096];sprintf_s (buffer, "%s.dfp",mName.c_str());return (const char*)buffer;}
	/*Display the location of the origin on the filmback.*/
	BoolID getDisplayFilmOrigin(){char buffer[4096];sprintf_s (buffer, "%s.dfo",mName.c_str());return (const char*)buffer;}
	/*Unused attribute; will be removed in a future release*/
	BoolID getClippingPlanes(){char buffer[4096];sprintf_s (buffer, "%s.cp",mName.c_str());return (const char*)buffer;}
	/*Activate manual clipping planes for rendering*/
	BoolID getBestFitClippingPlanes(){char buffer[4096];sprintf_s (buffer, "%s.bfc",mName.c_str());return (const char*)buffer;}
	/*Activate the depth of field effect*/
	BoolID getDepthOfField(){char buffer[4096];sprintf_s (buffer, "%s.dof",mName.c_str());return (const char*)buffer;}
	/*Activate the motion blur effect*/
	BoolID getMotionBlur(){char buffer[4096];sprintf_s (buffer, "%s.mb",mName.c_str());return (const char*)buffer;}
	/*Activate the orthographic projection*/
	BoolID getOrthographic(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*Activate journaling*/
	BoolID getJournalCommand(){char buffer[4096];sprintf_s (buffer, "%s.jc",mName.c_str());return (const char*)buffer;}
	/*Activate image output*/
	BoolID getImage(){char buffer[4096];sprintf_s (buffer, "%s.img",mName.c_str());return (const char*)buffer;}
	/*Activate depth output*/
	BoolID getDepth(){char buffer[4096];sprintf_s (buffer, "%s.dep",mName.c_str());return (const char*)buffer;}
	/*Activate Transparency based depth output*/
	BoolID getTransparencyBasedDepth(){char buffer[4096];sprintf_s (buffer, "%s.tdth",mName.c_str());return (const char*)buffer;}
	/*Threshold of the transparency value used for transparency based depth output*/
	DoubleID getThreshold(){char buffer[4096];sprintf_s (buffer, "%s.tthd",mName.c_str());return (const char*)buffer;}
	/*Depth output based on 0: closest visible or 1:furthest visible object*/
	UnsignedintID getDepthType(){char buffer[4096];sprintf_s (buffer, "%s.dptp",mName.c_str());return (const char*)buffer;}
	/*Use explore format for depth output, something we will delete eventually.*/
	BoolID getUseExploreDepthFormat(){char buffer[4096];sprintf_s (buffer, "%s.uexd",mName.c_str());return (const char*)buffer;}
	/*Activate mask output*/
	BoolID getMask(){char buffer[4096];sprintf_s (buffer, "%s.ma",mName.c_str());return (const char*)buffer;}
	/*background color*/
	Float3ID getBackgroundColor(){char buffer[4096];sprintf_s (buffer, "%s.col",mName.c_str());return (const char*)buffer;}
	/*background R value*/
	FloatID getBackgroundColorR(){char buffer[4096];sprintf_s (buffer, "%s.col.colr",mName.c_str());return (const char*)buffer;}
	/*background G value*/
	FloatID getBackgroundColorG(){char buffer[4096];sprintf_s (buffer, "%s.col.colg",mName.c_str());return (const char*)buffer;}
	/*background B value*/
	FloatID getBackgroundColorB(){char buffer[4096];sprintf_s (buffer, "%s.col.colb",mName.c_str());return (const char*)buffer;}
	/*scale factor applied to the focus distance and the value of each DOF depth image pixel during the Depth-of-Field computation*/
	DoubleID getFocusRegionScale(){char buffer[4096];sprintf_s (buffer, "%s.frs",mName.c_str());return (const char*)buffer;}
	/*This is a root of following mental ray attributes.*/
	MentalRayControlsID getMentalRayControls(){char buffer[4096];sprintf_s (buffer, "%s.mrc",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type output shader.*/
	GenerictypeddataID getMiOutputShader(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mios",mName.c_str());return (const char*)buffer;}
	/*Request color framebuffer for custom output shader (rgb).*/
	BoolID getMiFbComputeColor(){char buffer[4096];sprintf_s (buffer, "%s.mrc.micc",mName.c_str());return (const char*)buffer;}
	/*
	Request bitdepth for color framebuffer, either
	8 (0), 16 (1), or 32 (2) bits per color component.
	*/
	ShortID getMiFbBitsizeColor(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mict",mName.c_str());return (const char*)buffer;}
	/*Request alpha channel framebuffer for custom output.*/
	BoolID getMiFbComputeAlpha(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mica",mName.c_str());return (const char*)buffer;}
	/*
	Request bitdepth for alpha framebuffer,
	either 8 (0), 16 (1), or 32 (2) bits.
	*/
	ShortID getMiFbBitsizeAlpha(){char buffer[4096];sprintf_s (buffer, "%s.mrc.miat",mName.c_str());return (const char*)buffer;}
	/*Request z-depth scalar framebuffer for custom output.*/
	BoolID getMiFbComputeDepth(){char buffer[4096];sprintf_s (buffer, "%s.mrc.micd",mName.c_str());return (const char*)buffer;}
	/*Request normal vector framebuffer for custom output.*/
	BoolID getMiFbComputeNormal(){char buffer[4096];sprintf_s (buffer, "%s.mrc.micn",mName.c_str());return (const char*)buffer;}
	/*Request motion vector framebuffer for custom output.*/
	BoolID getMiFbComputeMotion(){char buffer[4096];sprintf_s (buffer, "%s.mrc.micm",mName.c_str());return (const char*)buffer;}
	/*Request coverage scalar framebuffer for custom output.*/
	BoolID getMiFbComputeCoverage(){char buffer[4096];sprintf_s (buffer, "%s.mrc.micv",mName.c_str());return (const char*)buffer;}
	/*Request label integer framebuffer for custom output.*/
	BoolID getMiFbComputeTag(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mitg",mName.c_str());return (const char*)buffer;}
	/*Request contour framebuffer for custom output.*/
	BoolID getMiFbComputeContour(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mico",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type volume shader.*/
	GenerictypeddataID getMiVolumeShader(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mivs",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type lens shader.*/
	GenerictypeddataID getMiLensShader(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mils",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type environment shader.*/
	GenerictypeddataID getMiEnvironmentShader(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mies",mName.c_str());return (const char*)buffer;}
	/*
	Port to connect multiple custom mental ray nodes of type output shader.
	Appended to the output shader list.
	*/
	const GenerictypeddataID& getMiOutputShaderList(size_t miol_i){char buffer[4096];sprintf_s (buffer, "%s.mrc.miol[%i]",mName.c_str(),miol_i);return (const char*)buffer;}
	/*
	Port to connect multiple custom mental ray nodes of type lens shader
	Appended to the lens shader list.
	*/
	const GenerictypeddataID& getMiLensShaderList(size_t mill_i){char buffer[4096];sprintf_s (buffer, "%s.mrc.mill[%i]",mName.c_str(),mill_i);return (const char*)buffer;}
	/*Connect multiple render passes.*/
	const MessageID& getMiRenderPassList(size_t mirp_i){char buffer[4096];sprintf_s (buffer, "%s.mrc.mirp[%i]",mName.c_str(),mirp_i);return (const char*)buffer;}
protected:
	Camera(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CAMERA_H__
