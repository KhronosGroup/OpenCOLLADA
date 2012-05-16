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
    class SkinController : public BaseController
    {
    private:

        /** The bind shape transform matrix. 
        Provides extra information about the position 
        and orientation of the base mesh before binding.*/
        MMatrix mBindShapeTransform; 

        /** The list with the influences for the collada document. */
        SkinControllerVertices mVertexInfluences;

        /** The list with the joints for the collada document. */
        SkinControllerJoints mJoints;

        /** List of influences. The combination of a transform (node) 
        and its corresponding weight is called an influence. */
        MDagPathArray mInfluences; // export-only

        /** A dynamically-sized array of 4x4 matrices. */
        std::vector<MMatrix> mBindPoses; // export-only

    public:
        /**
        * Constructor
        * @param _controllerId The unique id of the current controller.
        */
        SkinController ( const String& controllerId, const String& controllerName ) 
            : BaseController( controllerId, controllerName, true ) {}

        /**
        * Destructor.
        */
        virtual ~SkinController() {}

        /**
        * Returns the bind shape transform matrix.
        * @return MMatrix The bind shape transform matrix.
        */
        const MMatrix& getBindShapeTransform() const { return mBindShapeTransform; }

        /**
        * Sets the bind shape transform matrix.
        * @param val The bind shape transform matrix.
        */
        void setBindShapeTransform(MMatrix val) { mBindShapeTransform = val; }

        /**
        * Returns the list of influence vertices.
        * @return const SkinControllerVertices& List of influences.
        */
        const SkinControllerVertices& getVertexInfluences() const { return mVertexInfluences; }
        SkinControllerVertices& getVertexInfluences() { return mVertexInfluences; }

        /** The list with the joints for the collada document. */
        const SkinControllerJoints& getJoints() const { return mJoints; }
        SkinControllerJoints& getJoints() { return mJoints; }

        /**
        * Returns the list of influence joints.
        * @return MDagPathArray List of joint influences.
        */
        const MDagPathArray& getInfluences() const { return mInfluences; }
        MDagPathArray& getInfluences() { return mInfluences; }

        /**
        * Returns the bind poses.
        * @return const std::vector<MMatrix>& Bind poses.
        */
        const std::vector<MMatrix>& getBindPoses() const { return mBindPoses; }
        std::vector<MMatrix>& getBindPoses() { return mBindPoses; }


    };

}

#endif // __COLLADA_MAYA_SKIN_CONTROLLER_H___