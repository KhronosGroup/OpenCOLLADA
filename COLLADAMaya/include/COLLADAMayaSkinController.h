/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_SKIN_CONTROLLER_H___
#define __COLLADA_MAYA_SKIN_CONTROLLER_H___

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseController.h"

#include <vector>
#include <map>


namespace COLLADAMaya
{

    typedef std::map<int, float> SkinControllerVertex;
    typedef std::vector<SkinControllerVertex> SkinControllerVertices;

    typedef std::pair<String, MMatrix> SkinControllerJoint;
    typedef std::vector<SkinControllerJoint> SkinControllerJoints;

    /**
    * Holds the data for the skin controller to export.
    */
    class ColladaSkinController : public BaseController
    {
    private:

        /** The bind shape transform matrix. 
        Provides extra information about the position 
        and orientation of the base mesh before binding.*/
        MMatrix bindShapeTransform; 

        /** The list with the influences for the collada document. */
        SkinControllerVertices colladaVertexInfluences;

        /** The list with the joints for the collada document. */
        SkinControllerJoints colladaJoints;

    public:
        /**
        * Constructor
        * @param _controllerId The unique id of the current controller.
        */
        ColladaSkinController ( const String& controllerId, const String& controllerName ) 
            : BaseController( controllerId, controllerName, true ) {}

        /**
        * Destructor.
        */
        virtual ~ColladaSkinController() {}

        /**
        * Returns the bind shape transform matrix.
        * @return MMatrix The bind shape transform matrix.
        */
        const MMatrix& getBindShapeTransform() const { return bindShapeTransform; }

        /**
        * Sets the bind shape transform matrix.
        * @param val The bind shape transform matrix.
        */
        void setBindShapeTransform(MMatrix val) { bindShapeTransform = val; }

        /**
        * Returns the list of influence vertices.
        * @return const SkinControllerVertices& List of influences.
        */
        const SkinControllerVertices& getColladaVertexInfluences() const { return colladaVertexInfluences; }

        /** The list with the joints for the collada document. */
        const SkinControllerJoints& getColladaJoints() const { return colladaJoints; }
        SkinControllerJoints& getColladaJoints() { return colladaJoints; }

    };

}

#endif // __COLLADA_MAYA_SKIN_CONTROLLER_H___