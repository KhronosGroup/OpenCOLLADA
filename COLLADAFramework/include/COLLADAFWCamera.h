/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_CAMERA_H__
#define __COLLADAFW_CAMERA_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"
#include "COLLADAFWAnimatableFloat.h"


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

        /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;

		/** The name of the camera*/
		String mName;

		/** The type of the camera*/
		CameraType mCameraType;

		/** The type of description used to define the perspective camera.*/
		DescriptionType mDescriptionType;

		/** The horizontal field of view or magnification of the view.*/ 
		AnimatableFloat mXFovOrXMag;

		/** The vertical field of view or magnification of the view.*/ 
		AnimatableFloat mYFovOrYMag;

		/** The aspect ratio.*/
		AnimatableFloat mAspectRatio;

		/** The near clipping plane.*/
		AnimatableFloat mNearClippingPlane;

		/** The far clipping plane.*/
		AnimatableFloat mFarClippingPlane;

	public:

		/** @param objectId The object id of the camera.*/
		Camera( const UniqueId& uniqueId );

        /** Destructor. */
		virtual ~Camera();

        /**
        * The original object id, if it in the original file format exist. 
        */
        const String& getOriginalId () const { return mOriginalId; }

        /**
        * The original object id, if it in the original file format exist. 
        */
        void setOriginalId ( const String& val ) { mOriginalId = val; }

		/** Returns the name of the camera.*/
		const String& getName() const { return mName; }

		/** Sets the name of the camera.*/
		void setName(const String& name) { mName = name; }

		/** Returns the type of the camera.*/
		CameraType getCameraType() const { return mCameraType; }

		/** Sets the type of the camera.*/
		void setCameraType( CameraType cameraType)  { mCameraType = cameraType; }

		/** Returns the type of description used to define the perspective camera.*/
		DescriptionType getDescriptionType() const { return mDescriptionType; }

		/** sets the type of description used to define the perspective camera.*/
		void setDescriptionType(DescriptionType descriptionType) { mDescriptionType = descriptionType; }

		/** Returns the horizontal field of view. Use only for perspective cameras.*/ 
		const AnimatableFloat& getXFov() const { return mXFovOrXMag; }

		/** Returns the horizontal field of view. Use only for perspective cameras.*/ 
		AnimatableFloat& getXFov() { return mXFovOrXMag; }

		/** Sets the horizontal field of view. Use only for perspective cameras.*/ 
		void setXFov(double xFov) { mXFovOrXMag = xFov; }

		/** Returns the horizontal magnification of the view. Use only for orthographic cameras.*/ 
		const AnimatableFloat& getXMag() const { return mXFovOrXMag; }

		/** Returns the horizontal magnification of the view. Use only for orthographic cameras.*/ 
		AnimatableFloat& getXMag() { return mXFovOrXMag; }

		/** Sets the horizontal magnification of the view. Use only for orthographic cameras.*/ 
		void setXMag(double xMag) { mXFovOrXMag = xMag; }

		/** Returns the vertical field of view. Use only for perspective cameras.*/ 
		const AnimatableFloat& getYFov() const { return mYFovOrYMag; }

		/** Returns the vertical field of view. Use only for perspective cameras.*/ 
		AnimatableFloat& getYFov() { return mYFovOrYMag; }

		/** Sets the vertical field of view. Use only for perspective cameras.*/ 
		void setYFov(double yFov) { mYFovOrYMag = yFov; }

		/** Returns the vertical magnification of the view. Use only for orthographic cameras.*/ 
		const AnimatableFloat& getYMag() const { return mYFovOrYMag; }

		/** Returns the vertical magnification of the view. Use only for orthographic cameras.*/ 
		AnimatableFloat& getYMag() { return mYFovOrYMag; }

		/** Sets the vertical magnification of the view. Use only for orthographic cameras.*/ 
		void setYMag(double yMag) { mYFovOrYMag = yMag; }

		/** Returns the aspect ratio.*/ 
		const AnimatableFloat& getAspectRatio() const { return mAspectRatio; }

		/** Returns the aspect ratio.*/ 
		AnimatableFloat& getAspectRatio() { return mAspectRatio; }

		/** Sets the aspect ratio.*/ 
		void setAspectRatio(double aspectRatio) { mAspectRatio = aspectRatio; }

		/** Returns the near clipping plane.*/
		const AnimatableFloat& getNearClippingPlane() const { return mNearClippingPlane; }

		/** Returns the near clipping plane.*/
		AnimatableFloat& getNearClippingPlane() { return mNearClippingPlane; }

		/** Sets the near clipping plane.*/
		void setNearClippingPlane(double nearClippingPlane) { mNearClippingPlane = nearClippingPlane; }

		/** Returns the far clipping plane.*/
		const AnimatableFloat& getFarClippingPlane() const { return mFarClippingPlane; }

		/** Returns the far clipping plane.*/
		AnimatableFloat& getFarClippingPlane() { return mFarClippingPlane; }

		/** Sets the far clipping plane.*/
		void setFarClippingPlane(double farClippingPlane) { mFarClippingPlane = farClippingPlane; }

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_CAMERA_H__
