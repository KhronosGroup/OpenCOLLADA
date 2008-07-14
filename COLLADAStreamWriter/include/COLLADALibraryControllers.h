/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_LIBRARY_CONTROLLERS_H__
#define __COLLADASTREAMWRITER_LIBRARY_CONTROLLERS_H__

#include "COLLADAPrerequisites.h"
#include "COLLADALibrary.h"
#include "COLLADAInputList.h"

namespace COLLADA
{

    /** Class to simply the creation of @a \<library_controllers\> and @a \<controller\>'s*/

    class LibraryControllers : public Library
    {

    public:

        static const String SKIN_CONTROLLER_ID_SUFFIX;
        static const String MORPH_CONTROLLER_ID_SUFFIX;
        static const String ARRAY_ID_SUFFIX;
        static const String JOINTS_SOURCE_ID_SUFFIX;
        static const String BIND_POSES_SOURCE_ID_SUFFIX;
        static const String WEIGHTS_SOURCE_ID_SUFFIX;

    private:

        /** Used to close the current controller element */
        TagCloser mControllerCloser;  

        /** Used to close the current skin element */
        TagCloser mSkinCloser;

    public:

        /** 
         * Constructor
         * @param streamWriter The stream.
        */
        LibraryControllers ( StreamWriter * streamWriter );

        virtual ~LibraryControllers() {}

        /** 
         * Writes the opening \<controller\> and \<skin\> tags 
         * and, if necessary the opening @a \<library_controllers\> tag.
         * closeSkin() must be use to close the opened tags.
         * @param controllerId The id of the geometry
         * @param controllerName The Name of the geometry
         * @param skinTarget The target of the skin
         */
        void openSkin ( 
            const String& controllerId, 
            const String& controllerName, 
            const String& skinTarget );

        /** 
        * Writes the opening \<controller\> and \<skin\> tags 
        * and, if necessary the opening @a \<library_controllers\> tag.
        * closeSkin() must be use to close the opened tags.
        * @param controllerId The id of the geometry
        * @param controllerName The Name of the geometry
        * @param skinTarget The target of the skin
        */
        void openSkin ( 
            const String& controllerId, 
            const String& skinTarget )
        {
            openSkin(controllerId, EMPTY_STRING, skinTarget);
        }

        /** Closes the tag opened by openSkin()*/
        void closeSkin();

        /** 
         * Writes the opening \<controller\> tag 
         * and, if necessary the opening \<library_controllers\> tag.
         * closeController() must be use to close the opened tags.
         * @param controllerId The id of the controller.
         * @param controllerName The name of the controller.
         */
        void openController ( const String& controllerId, const String& controllerName = EMPTY_STRING );

        /** Closes the tag open by openController()*/
        void closeController();

        /**
         * Adds the given matrix to the bind_shape_matrix element.
         * @param matrix[][4] The bind_shape_matrix.
         */
        void addBindShapeTransform ( const double matrix[][4] ) const;

    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_LIBRARY_CONTROLLERS_H__
