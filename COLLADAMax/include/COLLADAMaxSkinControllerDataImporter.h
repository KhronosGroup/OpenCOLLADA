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

#ifndef __COLLADAMAX_SKINCONTROLLERDATAIMPORTER_H__
#define __COLLADAMAX_SKINCONTROLLERDATAIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"


namespace COLLADAFW
{
	class SkinControllerData;
	class SkinController;
};



namespace COLLADAMax
{

    /** Creates and assigns skin controllers using SkinControllerData  and the controller information 
	stored in the first pass.*/
	class SkinControllerDataImporter : public ImporterBase 
	{
	private:
		/** The controller data to import.*/
		const COLLADAFW::SkinControllerData* mSkinControllerData;

		/** The derived object. References the base object and has a skin controller assigned.*/
		IDerivedObject* mDerivedObject;
	
	public:

		/** Constructor. */
		SkinControllerDataImporter( DocumentImporter* documentImporter, const COLLADAFW::SkinControllerData* skinControllerData );

        /** Destructor. */
		virtual ~SkinControllerDataImporter();

		/** Performs the import of the skin controller data.
		@return True on success, false otherwise.*/
		bool import();

		/** Creates a skin modifier using @a controller and @a skinControllerData.*/
		bool createSkinModifier( const COLLADAFW::SkinController* skinController, const COLLADAFW::SkinControllerData* skinControllerData);

	private:

        /** Disable default copy ctor. */
		SkinControllerDataImporter( const SkinControllerDataImporter& pre );

        /** Disable default assignment operator. */
		const SkinControllerDataImporter& operator= ( const SkinControllerDataImporter& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_SKINCONTROLLERDATAIMPORTER_H__
