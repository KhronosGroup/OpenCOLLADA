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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaVisualSceneImporter.h"
#include "COLLADAMayaSceneNodeTraverser.h"
#include "COLLADAMayaSceneTraverserListener.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaGeometryImporter.h"

#include "COLLADADHReader.h"

#include "Math/COLLADABUMathMatrix4.h"

#include <maya/MFnDagNode.h>
#include <maya/MFnTransform.h>
#include <maya/MVector.h>


namespace COLLADAMaya
{
    
    // -----------------------------------
    VisualSceneImporter::VisualSceneImporter ( DocumentImporter* documentImporter ) 
    : BaseImporter ( documentImporter )
    {}

    // -----------------------------------
    bool VisualSceneImporter::importVisualScene ( const COLLADAFW::VisualScene* visualScene )
    {
        String id = visualScene->getId ();
        String visualSceneName = visualScene->getName ();

        const COLLADAFW::NodeArray& rootNodes = visualScene->getRootNodes ();
        size_t count = rootNodes.getCount ();
        for ( size_t i=0; i<count; ++i )
        {
            MObject parent = MObject::kNullObj;

            COLLADAFW::Node* rootNode = rootNodes [i];
            String nodeName = rootNode->getName ();
            String nodeSid = rootNode->getSid ();
            COLLADAFW::Node::NodeType nodeType = rootNode->getType ();

            MObject transformObject = MObject::kNullObj;
            switch ( nodeType )
            {
            case NODETYPE_JOINT:
                {
                    MFnDagNode dagFn;
                    transformObject = dagFn.create ( NODE_TYPE_JOINT, nodeName.c_str (), parent );
                    break;
                }
            case NODETYPE_NODE:
                {
                    MFnTransform transformFn;
                    transformObject = transformFn.create ( MObject::kNullObj );
                    transformFn.setName ( nodeName.c_str () );
                    break;
                }
            default:
                MGlobal::displayError ( "Not a valid node type!" );
            }

            // Import the tranformations
            importTransforms ( transformObject, rootNode );

            // Set the node visible
            DagHelper::setPlugValue( transformObject, ATTR_VISIBILITY, true );
        }

        return true;
    }

    // -----------------------------------
    bool VisualSceneImporter::importTransforms ( MObject& transformObject, const COLLADAFW::Node* rootNode )
    {
        // Attempt to bucket the transformations, forcing them to match Maya's transform stack
        if ( bucketTransforms ( transformObject ) ) return true;

        // Set the transform matrix to the transform object
        COLLADABU::Math::Matrix4 transformMatrix;
        rootNode->getTransformationMatrix ( transformMatrix );
        double mtx[4][4];
        transformMatrix.convertToDouble4x4 ( mtx );
        MMatrix matrix ( mtx );
        MTransformationMatrix tm ( matrix );
        MFnTransform transformFn ( transformObject );
        transformFn.set ( tm );

        // Look for more transformations
        const COLLADAFW::TransformationArray& transformations = rootNode->getTransformations ();
        size_t count = transformations.getCount ();
        for ( size_t j=0; j<count; ++j )
        {
            const COLLADAFW::Transformation* transformation = transformations [j];
            String transformSid = transformation->getSid ();
            COLLADAFW::Transformation::TransformationType transformType;
            transformType = transformation->getTransformationType ();


        }


//         // Import rotation
//         domRotate_Array rotateArray = node.getRotate_array ();
//         size_t rotationCount = rotateArray.getCount ();
//         for ( size_t i=0; i<rotationCount; ++i )
//         {
//             domRotateRef rotateRef = rotateArray.get ( i );
//             xsID rotateSid = rotateRef->getSid ();
//             domFloat4 rotateValues = rotateRef->getValue ();
// 
//             // Scene node transforms are not animated, so simply import as a matrix.
//             MTransformationMatrix tm;
//             MVector rotationVec ( rotateValues.get(0), rotateValues.get(1), rotateValues.get(2) );
//             tm.setRotation ( rotateValues, MTransformationMatrix::kXYZ, MSpace::kTransform );
// 
//             // Set the transform to the transform object
//             MFnTransform transformFn ( transformObject );
//             transformFn.set ( tm );
//        }

        return true;
    }

    // -----------------------------------
    bool VisualSceneImporter::bucketTransforms ( MObject& transformObject )
    {
        // Transform buckets: matches Maya's transform stack
        // Any deviation in the COLLADA scene node from this will force baking of the transform
        // Yes, Maya's transform stack is that NASTY.
        // See Maya's API doc on "All about: transform node" and "All about: joint node".
        // Remember that you can change the rotation order :(

        // Initialize the buckets and the rotation order
        //for (uint32 i = 0; i < BUCKET_COUNT; ++i) buckets[i] = NULL;
        bucketDepth = -1;
        rotationOrderCount = 0;
        noRotationOrder = false;
        for (uint i = 0; i < 3; ++i) rotationOrder[i] = -1;

        // Attempt to fill in the buckets with the COLLADA scene node transforms
        
//         size_t transformCount = node->GetTransformCount();
//         for (size_t t = 0; t < transformCount; ++t)
//         {
//             FCDTransform* transform = node->GetTransform(t);
//             switch (transform->GetType())
//             {
//             case FCDTransform::TRANSLATION: if (!BucketTranslation((FCDTTranslation*) transform)) return false; break;
//             case FCDTransform::ROTATION: if (!BucketRotation((FCDTRotation*) transform)) return false; break;
//             case FCDTransform::SCALE: if (!BucketScale((FCDTScale*) transform)) return false; break;
//             case FCDTransform::SKEW: if (!BucketSkew((FCDTSkew*) transform)) return false; break;
// 
//             case FCDTransform::MATRIX:
//             case FCDTransform::LOOKAT:
//             default:
//                 // No place for these in the Maya transform stack: force sampling
//                 return false;
//             }
//         }


        return false;
    }


}