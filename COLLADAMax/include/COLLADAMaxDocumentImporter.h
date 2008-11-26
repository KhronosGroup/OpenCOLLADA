/*
Copyright (c) 2008 NetAllied Systems GmbH

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

#ifndef __COLLADAMAX_DOCUMENTIMPORTER_H__
#define __COLLADAMAX_DOCUMENTIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include <max.h>


namespace COLLADAMax
{
	class DocumentImporter 	{
		// member declarations
	private:
		/** Max interface.*/
		Interface* mMaxInterface;

		/** File path of the COLLADA document to import.*/
		NativeString mImportFilePath;
	
		// public function declarations
	public:
		DocumentImporter(Interface * i, const NativeString &filepath);
		virtual ~DocumentImporter();

		// public static function declarations
	public:
	
		// protected function declarations
	protected:
	
		// private function declarations
	private:
        /** Disable default copy ctor. */
		DocumentImporter( const DocumentImporter& pre );
        /** Disable default assignment operator. */
		const DocumentImporter& operator= ( const DocumentImporter& pre );

	};
} // namespace COLLADAMAX

#endif // __COLLADAMAX_DOCUMENTIMPORTER_H__
