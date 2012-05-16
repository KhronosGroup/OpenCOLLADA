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

#ifndef __COLLADAMAX_MATERIALIMPORTER_H__
#define __COLLADAMAX_MATERIALIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"


namespace COLLADAFW
{
	class Material;
};


namespace COLLADAMax
{


    /** Imports one material */
	class MaterialImporter : public ImporterBase 
	{
	private:
		/** The material to import.*/
		const COLLADAFW::Material* mMaterial;
	
	public:
		/** Constructor. */
		MaterialImporter( DocumentImporter* documentImporter, const COLLADAFW::Material* material );

		/** Destructor. */
		virtual ~MaterialImporter();

		/** Performs the import of the material.
		@return True on success, false otherwise.*/
		bool import();

	private:

        /** Disable default copy ctor. */
		MaterialImporter( const MaterialImporter& pre );

        /** Disable default assignment operator. */
		const MaterialImporter& operator= ( const MaterialImporter& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_MATERIALIMPORTER_H__
