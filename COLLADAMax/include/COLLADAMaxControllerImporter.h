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

#ifndef __COLLADAMAX_CONTROLLERIMPORTER_H__
#define __COLLADAMAX_CONTROLLERIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"



namespace COLLADAFW
{
	class Controller;
};


namespace COLLADAMax
{

    /** Imports the controller information by storing it in a map. This information will be used
	in the second pass to create and assign controllers.*/
	class ControllerImporter : public ImporterBase 
		{
	private:
		/** The controller to import.*/
		const COLLADAFW::Controller* mController;

	public:

        /** Constructor. */
		ControllerImporter( DocumentImporter* documentImporter, const COLLADAFW::Controller* controller );

        /** Destructor. */
		virtual ~ControllerImporter();

		/** Performs the import of the controller.
		@return True on success, false otherwise.*/
		bool import();


	private:

        /** Disable default copy ctor. */
		ControllerImporter( const ControllerImporter& pre );

        /** Disable default assignment operator. */
		const ControllerImporter& operator= ( const ControllerImporter& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_CONTROLLERIMPORTER_H__
