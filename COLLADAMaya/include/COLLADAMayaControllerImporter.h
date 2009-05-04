/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_CONTROLLERIMPORTER_H__
#define __COLLADAMAYA_CONTROLLERIMPORTER_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaBaseImporter.h"

#include "COLLADABUIDList.h"


namespace COLLADAMaya
{

    /** TODO Documentation */
    class ControllerImporter : public BaseImporter
    {
    private:

        /** The standard name for controller without name. */
        static const String CONTROLLER_NAME;

    private:

        /**
        * The list of the unique maya controller names.
        */
        COLLADABU::IDList mControllerIdList;

        /** 
        * The map holds the unique ids of the controller nodes to the maya specific nodes. 
        */
        UniqueIdMayaNodeMap mMayaControllerNodesMap;

	
	public:

        /** Constructor. */
		ControllerImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~ControllerImporter();

        /**
        * Imports the data of the current controller.
        */
//        void importController ( const COLLADAFW::Controller* controller );

    private:

        MayaNode* findMayaControllerNode ( const COLLADAFW::UniqueId& controllerId );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_CONTROLLERIMPORTER_H__
