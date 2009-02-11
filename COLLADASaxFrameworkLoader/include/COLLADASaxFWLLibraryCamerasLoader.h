/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYCAMERASLOADER_H__
#define __COLLADASAXFWL_LIBRARYCAMERASLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"

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

	public:

        /** Constructor. */
		LibraryCamerasLoader( IFilePartLoader* callingFilePartLoader  );

        /** Destructor. */
		virtual ~LibraryCamerasLoader();

		/** Resets all the variables used for the current camera.*/
		void resetCurrentValues();

		/** Finishes loading a library effects.*/
		virtual bool end__library_cameras();


		/** Stores camera id and name.*/
		virtual bool begin__camera( const camera__AttributeData& attributeData );

		/** Sends camera to the writer.*/
		virtual bool end__camera();


		/** We don't need to do anything here.*/
		virtual bool begin__optics(){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__optics(){return true;}


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


		/** We don't need to do anything here.*/
		virtual bool begin__xfov( const xfov__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__xfov(){return true;}
		
		/** Stores the xfov of the current camera.*/
		virtual bool data__xfov( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__yfov( const yfov__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__yfov(){return true;}

		/** Stores the yfov of the current camera.*/
		virtual bool data__yfov( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__xmag( const xmag__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__xmag(){return true;}

		/** Stores the xmag of the current camera.*/
		virtual bool data__xmag( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__ymag( const ymag__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__ymag(){return true;}

		/** Stores the ymag of the current camera.*/
		virtual bool data__ymag( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__perspective__aspect_ratio( const aspect_ratio__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__perspective__aspect_ratio(){return true;}

		/** Stores the aspect ratio of the current camera.*/
		virtual bool data__perspective__aspect_ratio( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__perspective__znear( const znear__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__perspective__znear(){return true;}

		/** Stores the near clipping plane of the current camera.*/
		virtual bool data__perspective__znear( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__perspective__zfar( const zfar__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__perspective__zfar(){return true;}

		/** Stores the far clipping plane of the current camera.*/
		virtual bool data__perspective__zfar( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__orthographic__aspect_ratio( const aspect_ratio__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__orthographic__aspect_ratio(){return true;}

		/** Stores the aspect ratio of the current camera.*/
		virtual bool data__orthographic__aspect_ratio( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__orthographic__znear( const znear__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__orthographic__znear(){return true;}

		/** Stores the near clipping plane of the current camera.*/
		virtual bool data__orthographic__znear( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__orthographic__zfar( const zfar__AttributeData& attributeData ){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__orthographic__zfar(){return true;}

		/** Stores the far clipping plane of the current camera.*/
		virtual bool data__orthographic__zfar( double value );


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
