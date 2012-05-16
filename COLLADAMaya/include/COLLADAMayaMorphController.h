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

#ifndef __COLLADA_MAYA_MORPH_CONTROLLER_H___
#define __COLLADA_MAYA_MORPH_CONTROLLER_H___

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseController.h"

#include <vector>
#include <map>


namespace COLLADAMaya
{

    typedef std::vector<String> MorphControllerTargets;

    /**
    * Holds the data for the morph controller to export.
    */
    class MorphController : public BaseController
    {
    private:

        /** The list with the targets of the morph controller. */
        MorphControllerTargets mMorphControllerTargets;

        /** List of weights from the targets. */
        std::vector<float> mMorphWeights;

    public:
        /**
        * Constructor
        * @param _controllerId The unique id of the current controller.
        */
        MorphController ( const String& controllerId, const String& controllerName ) 
            : BaseController( controllerId, controllerName, true ) {}

        /**
        * Destructor.
        */
        virtual ~MorphController() {}

        /**
        * Returns the list of targets.
        * @return const MorphControllerTargets& List of targets.
        */
        const MorphControllerTargets& getMorphControllerTargets() const { return mMorphControllerTargets; }
        MorphControllerTargets& getMorphControllerTargets() { return mMorphControllerTargets; }

        /** The list with the weights for the collada document. */
        const std::vector<float>& getMorphControllerWeights() const { return mMorphWeights; }
        std::vector<float>& getMorphControllerWeights() { return mMorphWeights; }

    };

}

#endif // __COLLADA_MAYA_MORPH_CONTROLLER_H___