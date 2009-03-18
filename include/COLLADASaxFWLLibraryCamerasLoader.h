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

		/** Finishes loading a library cameras.*/
		virtual bool end__library_cameras();


		/** Creates a new camera.*/
		virtual bool begin__camera( const camera__AttributeData& attributeData );

		/** Sends camera to the writer.*/
		virtual bool end__camera();


		/** We don't need to do anything here.*/
		virtual bool begin__optics(){SaxVirtualFunctionTest(begin__optics()); return true;}

		/** We don't need to do anything here.*/
		virtual bool end__optics(){SaxVirtualFunctionTest(end__optics()); return true;}


		/** We don't need to do anything here.*/
		virtual bool begin__optics__technique_common(){SaxVirtualFunctionTest(begin__optics__technique_common()); return true;}

		/** We don't need to do anything here.*/
		virtual bool end__optics__technique_common(){SaxVirtualFunctionTest(end__optics__technique_common()); return true;}


		/** Set camera type to perspective.*/
		virtual bool begin__perspective();

		/** We don't need to do anything here.*/
		virtual bool end__perspective(){SaxVirtualFunctionTest(end__perspective()); return true;}


		/** Set camera type to orthographic.*/
		virtual bool begin__orthographic();

		/** We don't need to do anything here.*/
		virtual bool end__orthographic(){SaxVirtualFunctionTest(end__orthographic()); return true;}


		/** We don't need to do anything here.*/
		virtual bool begin__xfov( const xfov__AttributeData& attributeData ){SaxVirtualFunctionTest(begin__xfov(attributeData)); return true;}

		/** We don't need to do anything here.*/
		virtual bool end__xfov(){SaxVirtualFunctionTest(end__xfov()); return true;}
		
		/** Stores the xfov of the current camera.*/
		virtual bool data__xfov( float value );


		/** We don't need to do anything here.*/
		virtual bool begin__yfov( const yfov__AttributeData& attributeData ){SaxVirtualFunctionTest(begin__yfov(attributeData)); return true;}

		/** We don't need to do anything here.*/
		virtual bool end__yfov(){SaxVirtualFunctionTest(end__yfov()); return true;}

		/** Stores the yfov of the current camera.*/
		virtual bool data__yfov( float value );


		/** We don't need to do anything here.*/
		virtual bool begin__xmag( const xmag__AttributeData& attributeData ){SaxVirtualFunctionTest(begin__xmag(attributeData)); return true;}

		/** We don't need to do anything here.*/
		virtual bool end__xmag(){SaxVirtualFunctionTest(end__xmag()); return true;}

		/** Stores the xmag of the current camera.*/
		virtual bool data__xmag( float value );


		/** We don't need to do anything here.*/
		virtual bool begin__ymag( const ymag__AttributeData& attributeData ){SaxVirtualFunctionTest(begin__ymag(attributeData)); return true;}

		/** We don't need to do anything here.*/
		virtual bool end__ymag(){SaxVirtualFunctionTest(end__ymag()); return true;}

		/** Stores the ymag of the current camera.*/
		virtual bool data__ymag( float value );


		/** We don't need to do anything here.*/
		virtual bool begin__aspect_ratio( const aspect_ratio__AttributeData& attributeData ){SaxVirtualFunctionTest(begin__aspect_ratio(attributeData)); return true;}

		/** We don't need to do anything here.*/
		virtual bool end__aspect_ratio(){SaxVirtualFunctionTest(end__aspect_ratio()); return true;}

		/** Stores the aspect ratio of the current camera.*/
		virtual bool data__aspect_ratio( float value );


		/** We don't need to do anything here.*/
		virtual bool begin__znear( const znear__AttributeData& attributeData ){SaxVirtualFunctionTest(begin__znear(attributeData)); return true;}

		/** We don't need to do anything here.*/
		virtual bool end__znear(){SaxVirtualFunctionTest(end__znear()); return true;}

		/** Stores the near clipping plane of the current camera.*/
		virtual bool data__znear( float value );


		/** We don't need to do anything here.*/
		virtual bool begin__zfar( const zfar__AttributeData& attributeData ){SaxVirtualFunctionTest(begin__zfar(attributeData)); return true;}

		/** We don't need to do anything here.*/
		virtual bool end__zfar(){SaxVirtualFunctionTest(end__zfar()); return true;}

		/** Stores the far clipping plane of the current camera.*/
		virtual bool data__zfar( float value );

#if 0
		/** We don't need to do anything here.*/
		virtual bool begin__orthographic__aspect_ratio( const aspect_ratio__AttributeData& attributeData ){SaxVirtualFunctionTest(begin__orthographic__aspect_ratio(attributeData)); return true;}

		/** We don't need to do anything here.*/
		virtual bool end__orthographic__aspect_ratio(){SaxVirtualFunctionTest(end__orthographic__aspect_ratio()); return true;}

		/** Stores the aspect ratio of the current camera.*/
		virtual bool data__orthographic__aspect_ratio( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__orthographic__znear( const znear__AttributeData& attributeData ){SaxVirtualFunctionTest(begin__orthographic__znear(attributeData)); return true;}

		/** We don't need to do anything here.*/
		virtual bool end__orthographic__znear(){SaxVirtualFunctionTest(end__orthographic__znear()); return true;}

		/** Stores the near clipping plane of the current camera.*/
		virtual bool data__orthographic__znear( double value );


		/** We don't need to do anything here.*/
		virtual bool begin__orthographic__zfar( const zfar__AttributeData& attributeData ){SaxVirtualFunctionTest(begin__orthographic__zfar(attributeData)); return true;}

		/** We don't need to do anything here.*/
		virtual bool end__orthographic__zfar(){SaxVirtualFunctionTest(end__orthographic__zfar()); return true;}

		/** Stores the far clipping plane of the current camera.*/
		virtual bool data__orthographic__zfar( double value );
#endif

		/** We don't need to do anything here.*/
		virtual bool begin__imager(){SaxVirtualFunctionTest(begin__imager()); return true;}

		/** We don't need to do anything here.*/
		virtual bool end__imager(){SaxVirtualFunctionTest(end__imager()); return true;}

	private:

        /** Disable default copy ctor. */
		LibraryCamerasLoader( const LibraryCamerasLoader& pre );

        /** Disable default assignment operator. */
		const LibraryCamerasLoader& operator= ( const LibraryCamerasLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYCAMERASLOADER_H__
