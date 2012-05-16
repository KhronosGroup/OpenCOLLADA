/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAX_CAMERAIMPORTER_H__
#define __COLLADAMAX_CAMERAIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"


class GenCamera;

namespace COLLADAFW
{
	class Camera;
};


namespace COLLADAMax
{

    /** Imports a camera into the max scene */
	class CameraImporter : public ImporterBase 
	{
	private:
		/** The camera to import.*/
		const COLLADAFW::Camera* mCamera;
	
	public:

        /** Constructor. */
		CameraImporter( DocumentImporter* documentImporter, const COLLADAFW::Camera* camera );

        /** Destructor. */
		virtual ~CameraImporter();

		/** Performs the import of the camera.
		@return True on success, false otherwise.*/
		bool import();

		/** Creates a new GenCamera from @a camera and returns a pointer to it. */
		GenCamera* createCamera( const COLLADAFW::Camera* camera );


	private:

        /** Disable default copy ctor. */
		CameraImporter( const CameraImporter& pre );

        /** Disable default assignment operator. */
		const CameraImporter& operator= ( const CameraImporter& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_CAMERAIMPORTER_H__
