/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_BASE_CONTROLLER_H___
#define __COLLADA_MAYA_BASE_CONTROLLER_H___

#include "COLLADAMayaStableHeaders.h"

#include <vector>
#include <map>


namespace COLLADAMaya
{

    //  typedef std::vector<ControllerInstance> ControllerInstanceList;
    //  typedef std::vector<Controller> ControllerList;

    /**
    * Represents a controller.
    * The affected geometry is called the skin, the combination of a 
    * transform (node) and its corresponding weight is called an
    * influence, and the set of influencing nodes (usually a hierarchy) 
    * is called a skeleton.
    */
    class BaseController
    {
    private:

        /** The unique controller id. */
        String mControllerId;

        /** The name of the controller. */
        String mControllerName;

        //  ControllerInstanceList instances; // export-only;

        /** True, if the current controller is a instance of a skin controller. */
        bool mIsSkinController;

        /** True, if the current controller is a instance of a morph controller. */
        bool mIsMorphController;

    public:

        /**
        * Constructor
        * @param _controllerId The unique id of the current controller.
        */
        BaseController ( const String& controllerId, const String& controllerName, 
                         bool isSkin=false, bool isMorph=false ) 
            : mControllerId( controllerId ) 
            , mControllerName( controllerName )
            , mIsSkinController( isSkin )
            , mIsMorphController( isMorph )
        {}

        /**
        * Destructor.
        */
        virtual ~BaseController() {}

        /** True, if the current controller is a instance of a skin controller. */
        bool isSkinController() const { return mIsSkinController; }

        /**
        * Returns the unique controller id.
        * @return COLLADAMaya::String The controller id.
        */
        const COLLADAMaya::String& getControllerId() const { return mControllerId; }

        /**
        * Returns the controller name.
        * @return COLLADAMaya::String The controller name.
        */
        const COLLADAMaya::String& getControllerName() const { return mControllerName; }

    };
    typedef std::vector<BaseController*> ControllerList;

}

#endif // __COLLADA_MAYA_BASE_CONTROLLER_H___