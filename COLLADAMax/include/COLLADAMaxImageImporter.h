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

#ifndef __COLLADAMAX_IMAGEIMPORTER_H__
#define __COLLADAMAX_IMAGEIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"


namespace COLLADAFW
{
	class Material;
};


namespace COLLADAMax
{

	/** Imports one image ( only the url, not the imag data itself ) */
	class ImageImporter : public ImporterBase 
	{
	private:
		/** The image to import.*/
		const COLLADAFW::Image* mImage;

	
	public:

        /** Constructor. */
		ImageImporter( DocumentImporter* documentImporter, const COLLADAFW::Image* image );

        /** Destructor. */
		virtual ~ImageImporter();

		/** Performs the import of the image.
		@return True on success, false otherwise.*/
		bool import();


	private:

        /** Disable default copy ctor. */
		ImageImporter( const ImageImporter& pre );

        /** Disable default assignment operator. */
		const ImageImporter& operator= ( const ImageImporter& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_IMAGEIMPORTER_H__
