/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_CAMERA_H__
#define __COLLADAFW_CAMERA_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"


namespace COLLADAFW
{

    /** Camera class. The camera is either a perspective or an orthographic camera.
	The CameraType indicates of which type the camera is which. 
	For perspective cameras mXFovOrXMag and mYFovOrYMag store the horizontal or vertical field of view,
	for orthographic cameras mXFovOrXMag and mYFovOrYMag store the horizontal or vertical magnification of the view.*/
	class Camera : public ObjectTemplate < COLLADA_TYPE::CAMERA >
	{
	public:
		/** The type of the camera.*/
		enum CameraType
		{
			UNDEFINED_CAMERATYPE,
			ORTHOGRAPHIC,
			PERSPECTIVE
		};

		/** Defines which values are used to describe the camera.*/
		enum DescriptionType
		{
			UNDEFINED,					//!< The perspective camera object is invalid
			SINGLE_X,			    	//!< Only xfov or xmag, respectively describes the camera
			SINGLE_Y,                   //!< Only yfov or ymag, respectively describes the camera
			X_AND_Y,                    //!< xfov and yfov or xmag and ymag, respectively describe the camera
			ASPECTRATIO_AND_X,          //!< aspect ratio and xfov or xmag, respectively describe the camera
			ASPECTRATIO_AND_Y,          //!< aspect ratio and yfov or <mag, respectivelydescribe the camera
		};  


	
	private:
		/** The name of the camera*/
		String mName;

		/** The type of the camera*/
		CameraType mCameraType;

		/** The type of description used to define the perspective camera.*/
		DescriptionType mDescriptionType;

		/** The horizontal field of view or magnification of the view.*/ 
		double mXFovOrXMag;
        bool mHasXFovOrXMag;

		/** The vertical field of view or magnification of the view.*/ 
		double mYFovOrYMag;
        bool mHasYFovOrYMag;

		/** The aspect ratio.*/
		double mAspectRatio;
        bool mHasAspectRatio;

		/** The near clipping plane.*/
		double mNearClippingPlane;

		/** The far clipping plane.*/
		double mFarClippingPlane;
	public:
		/** @param objectId The object id of the camera.*/
		Camera( ObjectId objectId );

        /** Destructor. */
		virtual ~Camera();

		/** Returns the name of the camera.*/
		const COLLADAFW::String& getName() const { return mName; }

		/** Sets the name of the camera.*/
		void setName(const COLLADAFW::String& name) { mName = name; }

		/** Returns the type of the camera.*/
		const CameraType& getCameraType() const { return mCameraType; }

		/** Sets the type of the camera.*/
		void setCameraType( const CameraType& cameraType)  { mCameraType = cameraType; }

		/** Returns the type of description used to define the perspective camera.*/
		const DescriptionType& getDescriptionType() const { return mDescriptionType; }

		/** sets the type of description used to define the perspective camera.*/
		void setDescriptionType(const DescriptionType& descriptionType) { mDescriptionType = descriptionType; }

		/** Returns the horizontal field of view. Use only for perspective cameras.*/ 
		double getXFov() const { return mXFovOrXMag; }

		/** Sets the horizontal field of view. Use only for perspective cameras.*/ 
		void setXFov(double xFov) { mXFovOrXMag = xFov; mHasXFovOrXMag = true; }

		/** Returns the horizontal magnification of the view. Use only for orthographic cameras.*/ 
		double getXMag() const { return mXFovOrXMag; }

		/** Sets the horizontal magnification of the view. Use only for orthographic cameras.*/ 
		void setXMag(double xMag) { mXFovOrXMag = xMag; mHasXFovOrXMag = true; }

		/** Returns the vertical field of view. Use only for perspective cameras.*/ 
		double getYFov() const { return mYFovOrYMag; }

		/** Sets the vertical field of view. Use only for perspective cameras.*/ 
		void setYFov(double yFov) { mYFovOrYMag = yFov; mHasYFovOrYMag = true; }

		/** Returns the vertical magnification of the view. Use only for orthographic cameras.*/ 
		double getYMag() const { return mYFovOrYMag; }

		/** Sets the vertical magnification of the view. Use only for orthographic cameras.*/ 
		void setYMag(double yMag) { mYFovOrYMag = yMag; mHasYFovOrYMag = true; }

        /** The horizontal field of view or magnification of the view.*/ 
        const bool& getHasXFovOrXMag () const { return mHasXFovOrXMag; }

        /** The vertical field of view or magnification of the view.*/ 
        const bool& getHasYFovOrYMag () const { return mHasYFovOrYMag; }

		/** Returns the aspect ratio.*/ 
		double getAspectRatio() const { return mAspectRatio; }

		/** Sets the aspect ratio.*/ 
		void setAspectRatio(double aspectRatio) { mAspectRatio = aspectRatio; mHasAspectRatio = true; }

        /** The aspect ratio.*/
        const bool& getHasAspectRatio () const { return mHasAspectRatio; }

		/** Returns the near clipping plane.*/
		double getNearClippingPlane() const { return mNearClippingPlane; }

		/** Sets the near clipping plane.*/
		void setNearClippingPlane(double nearClippingPlane) { mNearClippingPlane = nearClippingPlane; }

		/** Returns the far clipping plane.*/
		double getFarClippingPlane() const { return mFarClippingPlane; }

		/** Sets the far clipping plane.*/
		void setFarClippingPlane(double farClippingPlane) { mFarClippingPlane = farClippingPlane; }

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_CAMERA_H__
