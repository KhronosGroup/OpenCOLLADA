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

#include <dom/domTypes.h>

#include <maya/MFnDagNode.h>
#include <maya/MFnTransform.h>
#include <maya/MVector.h>


namespace COLLADAMaya
{
    
    // -----------------------------------
    VisualSceneImporter::VisualSceneImporter ( 
        DocumentImporter* documentImporter, 
        daeDocument* daeDoc ) 
    : BaseImporter ( documentImporter, daeDoc )
    {}

    // -----------------------------------
    void VisualSceneImporter::importVisualScenes ()
    {
        daeDocument* daeDoc = getDaeDocument();
        COLLADADH::Reader reader ( *daeDoc );

        COLLADADH::Reader::ElementIterator<domVisual_scene> visualScenesIter = reader.getVisualScenes();
        while ( visualScenesIter.more() )
        {
            domVisual_scene& visualScene = visualScenesIter.next();
            importVisualScene ( visualScene );
        }
    }

    // -----------------------------------
    void VisualSceneImporter::importVisualScene ( domVisual_scene& visualScene )
    {
        // Iterate recursively over nodes
        SceneNodeTraverser nodeTraverser ( getDocumentImporter(), visualScene );
        SceneTraverserListener nodeListener ( &nodeTraverser );
        nodeTraverser.traverse ( nodeListener );
    }

    // -----------------------------------
    bool VisualSceneImporter::importVisualSceneNode ( domNode& node, int level )
    {
        xsID nodeId = node.getId ();
        xsName nodeName = node.getName ();
        domNodeType nodeType = node.getType ();

        MObject transformObject = MObject::kNullObj;
        switch ( nodeType )
        {
        case NODETYPE_JOINT:
            {
                MFnDagNode dagFn;
                transformObject = dagFn.create ( NODE_TYPE_JOINT, nodeName );
                break;
            }
        case NODETYPE_NODE:
            {
                MFnTransform transformFn;
                transformObject = transformFn.create ( MObject::kNullObj );
                transformFn.setName ( nodeName );
                break;
            }
        default:
            MGlobal::displayError ( "Not a valid node type!" );
        }

        // Import the tranformations
        importTransforms ( transformObject, node );

        // Read the geometry instance
        GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();
        geometryImporter->importGeometries ( transformObject, node );


        DagHelper::setPlugValue( transformObject, ATTR_VISIBILITY, true );


        return true;
    }

    // -----------------------------------
    bool VisualSceneImporter::importTransforms ( MObject& transformObject, domNode& node )
    {
        // Attempt to bucket the transformations, forcing them to match Maya's transform stack
        if ( bucketTransforms ( transformObject ) ) return true;

        // The transforms for this node does not match Maya's transform stack, 
        // so read them in as matrices: while sampling any animations
        //         if (!ANIM->ImportAnimatedSceneNode(transform, colladaNode))
        //         {
        //             // Scene node transforms are not animated, so simply import as a matrix.
        //             MTransformationMatrix tm(MConvert::ToMMatrix(colladaNode->ToMatrix()));
        //             MFnTransform transformFn(transform);
        //             transformFn.set(tm);
        //         }

        // Import transform 
        domTranslate_Array translateArray = node.getTranslate_array ();
        size_t count = translateArray.getCount ();
        for ( size_t i=0; i<count; ++i )
        {
            domTranslateRef translateRef = translateArray.get ( i );
            xsID translateSid = translateRef->getSid ();
            domFloat3 translateValues = translateRef->getValue ();

            // Scene node transforms are not animated, so simply import as a matrix.
            MTransformationMatrix tm;
            MVector translationVec ( translateValues.get(0), translateValues.get(1), translateValues.get(2) );
            tm.setTranslation ( translationVec, MSpace::kTransform );

            // Set the transform to the transform object
            MFnTransform transformFn ( transformObject );
            transformFn.set ( tm );
        }

        // Import rotation
        domRotate_Array rotateArray = node.getRotate_array ();
        size_t rotationCount = rotateArray.getCount ();
        for ( size_t i=0; i<rotationCount; ++i )
        {
            domRotateRef rotateRef = rotateArray.get ( i );
            xsID rotateSid = rotateRef->getSid ();
            domFloat4 rotateValues = rotateRef->getValue ();

            // Scene node transforms are not animated, so simply import as a matrix.
            MTransformationMatrix tm;
            MVector rotationVec ( rotateValues.get(0), rotateValues.get(1), rotateValues.get(2) );
//             tm.setRotation ( rotateValues, MTransformationMatrix::kXYZ, MSpace::kTransform );
// 
//             // Set the transform to the transform object
//             MFnTransform transformFn ( transformObject );
//             transformFn.set ( tm );
        }

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