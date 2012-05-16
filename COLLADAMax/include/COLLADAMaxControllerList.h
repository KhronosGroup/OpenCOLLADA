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


#ifndef __COLLADAMAX_CONTROLLERLIST_H__
#define __COLLADAMAX_CONTROLLERLIST_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAMaxController.h"
#include "COLLADAMaxTypes.h"

namespace COLLADAMax
{

	class ExportNode;

	/** Base class to export extra tags in max.*/

    class ControllerList
    {

    public:

    private:
		Controllers mControllers;
		/** Set of all the joints, that are referenced (using their sid) in at least one controller.*/
		ExportNodeSet mReferencedJoints;

    public:
        /** Constructor
         */
        ControllerList ( const ExportNode& exportNode );

        /** Destructor*/
        virtual ~ControllerList();

		/** Returns, if the Controller list contains controllers.*/
		bool hasControllers()const { return !mControllers.empty(); }

		/** Returns the number of controllers, regardless if they are enabled or not.*/
		size_t getControllerCount()const{ return mControllers.size();}

		/** Returns the index'th controller*/
		Controller* getController(size_t index)const {return mControllers.at(index);}

		/** Returns the set of joints, referenced in at least one controller in this controller list.*/
		const ExportNodeSet& getReferencedJoints()const{return mReferencedJoints;}

		/** Add @a joint to the set of referenced joints.*/
		void addReferencedJoint(ExportNode* joint){mReferencedJoints.insert(joint);}

		/** Returns the initial pose of the object, before all controllers that will be exported are applied.*/
		Object* getInitialPose()const;

	private:
		/** Resolves all the controllers of the node, represented by the exportNode and stores them in @a mControllers.
		We iterate thru the modifier stack, starting with the last one that is applied, until we hit the first modifier
		that is not support by COLLADASW, i.e. is neither a skin nor a morph controller.*/
		void resolveControllers(const ExportNode& exportNode);

    protected:



    };

}


#endif //__COLLADAMAX_CONTROLLERLIST_H__

