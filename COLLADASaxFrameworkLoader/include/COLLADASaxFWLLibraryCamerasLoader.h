/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYCAMERASLOADER_H__
#define __COLLADASAXFWL_LIBRARYCAMERASLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLXmlTypes.h"


namespace COLLADAFW
{
	class Camera;
}

namespace COLLADASaxFWL
{

    /** Loads all the cameras in a library cameras.  */
	class LibraryCamerasLoader : public FilePartLoader
	{
	private:
		/** The current camera.*/
		COLLADAFW::Camera* mCurrentCamera;

		/** The current camera has xfov or xmag ( depending on optics ).*/
		bool mCurrentCameraHasX;

		/** The current camera has yfov or ymag ( depending on optics ).*/
		bool mCurrentCameraHasY;

		/** The current camera has apect ratio.*/
		bool mCurrentCameraHasAspectRatio;

		/** True, if we are inside an optics element, false otherwise. Is used extra tag key generation.*/
		bool mInOptics;

	public:

        /** Constructor. */
		LibraryCamerasLoader( IFilePartLoader* callingFilePartLoader  );

        /** Destructor. */
		virtual ~LibraryCamerasLoader();

		/** Resets all the variables used for the current camera.*/
		void resetCurrentValues();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();

		/** Finishes loading a library cameras.*/
		virtual bool end__library_cameras();


		/** Creates a new camera.*/
		virtual bool begin__camera( const camera__AttributeData& attributeData );

		/** Sends camera to the writer.*/
		virtual bool end__camera();


		/** Store that we are inside an optics element.*/
		virtual bool begin__optics(){mInOptics = true; return true;}

		/** Store that we are NOT inside an optics element.*/
		virtual bool end__optics(){mInOptics = false; return true;}


		/** We don't need to do anything here.*/
		virtual bool begin__optics__technique_common(){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__optics__technique_common(){return true;}


		/** Set camera type to perspective.*/
		virtual bool begin__perspective();

		/** We don't need to do anything here.*/
		virtual bool end__perspective(){return true;}


		/** Set camera type to orthographic.*/
		virtual bool begin__orthographic();

		/** We don't need to do anything here.*/
		virtual bool end__orthographic(){return true;}


		/** Add animatable float to sid tree*/
		virtual bool begin__xfov( const xfov__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__xfov();
		
		/** Stores the xfov of the current camera.*/
		virtual bool data__xfov( float value );


		/** Add animatable float to sid tree*/
		virtual bool begin__yfov( const yfov__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__yfov();

		/** Stores the yfov of the current camera.*/
		virtual bool data__yfov( float value );


		/** Add animatable float to sid tree*/
		virtual bool begin__xmag( const xmag__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__xmag();

		/** Stores the xmag of the current camera.*/
		virtual bool data__xmag( float value );


		/** Add animatable float to sid tree*/
		virtual bool begin__ymag( const ymag__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__ymag();

		/** Stores the ymag of the current camera.*/
		virtual bool data__ymag( float value );


		/** Add animatable float to sid tree*/
		virtual bool begin__aspect_ratio( const aspect_ratio__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__aspect_ratio();

		/** Stores the aspect ratio of the current camera.*/
		virtual bool data__aspect_ratio( float value );


		/** Add animatable float to sid tree*/
		virtual bool begin__znear( const znear__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__znear();

		/** Stores the near clipping plane of the current camera.*/
		virtual bool data__znear( float value );


		/** Add animatable float to sid tree*/
		virtual bool begin__zfar( const zfar__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__zfar();

		/** Stores the far clipping plane of the current camera.*/
		virtual bool data__zfar( float value );


		/** We don't need to do anything here.*/
		virtual bool begin__imager(){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__imager(){return true;}

    private:

        /** Disable default copy ctor. */
		LibraryCamerasLoader( const LibraryCamerasLoader& pre );

        /** Disable default assignment operator. */
		const LibraryCamerasLoader& operator= ( const LibraryCamerasLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYCAMERASLOADER_H__
