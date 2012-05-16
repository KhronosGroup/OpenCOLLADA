/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_LIBRARY_CONTROLLERS_H__
#define __COLLADASTREAMWRITER_LIBRARY_CONTROLLERS_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWLibrary.h"
#include "COLLADASWInputList.h"

namespace COLLADASW
{

    /** Class to simply the creation of @a \<library_controllers\> and @a \<controller\>'s*/
    class LibraryControllers : public Library
    {

    public:

        static const String ARRAY_ID_SUFFIX;
        static const String BIND_POSES_SOURCE_ID_SUFFIX;
        static const String MORPH_CONTROLLER_ID_SUFFIX;
        static const String MORPH_WEIGHTS_SOURCE_ID_SUFFIX;
        static const String JOINTS_SOURCE_ID_SUFFIX;
        static const String SKIN_CONTROLLER_ID_SUFFIX;
        static const String TARGETS_SOURCE_ID_SUFFIX;
        static const String WEIGHTS_SOURCE_ID_SUFFIX;

        static const String ATTRIBUTE_METHOD_NORMALIZED;
        static const String ATTRIBUTE_METHOD_RELATIVE;

    private:

        /** Used to close the current controller element */
        TagCloser mControllerCloser;  

        /** Used to close the current skin element */
        TagCloser mSkinCloser;

        /** Used to close the current morph element */
        TagCloser mMorphCloser;

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
         * @param controllerId The id of the controller
         * @param controllerName The Name of the geometry
         * @param skinSource The target of the skin (the id of the geometry)
         */
        void openSkin ( 
            const String& controllerId, 
            const String& controllerName, 
            const URI& skinTarget );

        /** 
        * Writes the opening \<controller\> and \<skin\> tags 
        * and, if necessary the opening @a \<library_controllers\> tag.
        * closeSkin() must be use to close the opened tags.
        * @param controllerId The id of the controller
        * @param skinSource The target of the skin (the id of the geometry)
        */
        void openSkin ( 
            const String& controllerId, 
            const URI& skinSource )
        {
            openSkin( controllerId, EMPTY_STRING, skinSource );
        }

        /** Closes the tag opened by openSkin(). */
        void closeSkin();

        /** 
        * Writes the opening \<controller\> and \<morph\> tags 
        * and, if necessary the opening @a \<library_controllers\> tag.
        * closeMorph() must be use to close the opened tags.
        * @param controllerId The id of the controller
        * @param controllerName The Name of the geometry
        * @param morphTarget The target of the morph (the id of the geometry)
        */
        void openMorph ( 
            const String& controllerId, 
            const String& controllerName, 
            const URI& morphSource, 
            const String& morphMethod = ATTRIBUTE_METHOD_NORMALIZED );

        /** Closes the tag opened by openMorph(). */
        void closeMorph();

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

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_LIBRARY_CONTROLLERS_H__
