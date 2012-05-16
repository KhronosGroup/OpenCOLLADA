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

#ifndef __COLLADA_MAYA_ROTATE_HELPER_H__
#define __COLLADA_MAYA_ROTATE_HELPER_H__

#include "COLLADAMayaPrerequisites.h"
#include <vector>

namespace COLLADAMaya
{

    /**
     * Generates the rotation matrix, depending on the rotation order.
     */
    class RotateHelper
    {

    private:

        /** The euler rotation with the rotation order to set. */
        MEulerRotation rotation;

        /** The rotation matrix to generate, depending on the rotation order. */
        std::vector< std::vector<double> > rotationMatrix;

        /** The vector with the rotation parameters in the rotation order. */
        std::vector<String> rotationParameters;

    public:

        /**
         * Constructor.
         * @param rotation The euler rotation.
         */
        RotateHelper( MEulerRotation rotation );

        /**
         * Returns the rotation vector (2x3 matrix).
         * @return std::vector< std::vector<double> >&
         */
        std::vector < std::vector<double> >& getRotationMatrix ()
        {
            return rotationMatrix;
        }

        /**
         * Returns the rotation parameters in the rotation order.
         * @return std::vector<String>&
         */
        std::vector<String>& getRotationParameters ()
        {
            return rotationParameters;
        }

    private:

        /**
         * Creates the rotation.
         */
        void createRotation ( );

        void createX ( uint pos );

        void createY ( uint pos );

        void createZ ( uint pos );

    };
}

#endif /* __COLLADA_MAYA_ROTATE_HELPER_H__ */

