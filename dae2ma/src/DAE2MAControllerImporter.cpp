/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MAControllerImporter.h"
#include "DAE2MAVisualSceneImporter.h"
#include "DAE2MAGeometryImporter.h"
#include "DAE2MAConversion.h"

#include "COLLADAFWSkinController.h"
#include "COLLADAFWSkinControllerData.h"
#include "COLLADAFWMorphController.h"

#include "MayaDMCommands.h"


namespace DAE2MA
{

    /** 
    * For one controller, we need the following objects:
    *
    * createNode skinCluster -n "skinCluster1";
    * createNode objectSet -n "skinCluster1set";
    *
    * createNode tweak -n "tweak1";
    * createNode objectSet -n "tweak1set";
    *
    * createNode groupId -n "groupId1";
    * createNode groupParts -n "groupParts1";
    * createNode groupId -n "groupId2";
    * createNode groupParts -n "groupParts2";
    */
    const String ControllerImporter::SKIN_CLUSTER_NAME = "skinCluster";
    const String ControllerImporter::BLEND_SHAPE_NAME = "blendShape";
    const String ControllerImporter::TWEAK_NAME = "tweak";
    const String ControllerImporter::SET_NAME = "Set";


    //------------------------------
	ControllerImporter::ControllerImporter ( DocumentImporter* documentImporter )
        : BaseImporter ( documentImporter )
	{
	}
	
    //------------------------------
	ControllerImporter::~ControllerImporter()
	{
        {
            UniqueIdMayaNodeMap::iterator it = mMayaControllerNodesMap.begin ();
            while ( it != mMayaControllerNodesMap.end () )
            {
                MayaNode* mayaNode = it->second;
                delete mayaNode;
                ++it;
            }
            mMayaControllerNodesMap.clear ();
        }

        {
            std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::SkinController*> >::iterator it = mSkinControllersMap.begin ();
            while ( it != mSkinControllersMap.end () )
            {
                std::vector<COLLADAFW::SkinController*>& skinControllers = it->second;
                for ( size_t i=0; i<skinControllers.size (); ++i )
                {
                    COLLADAFW::SkinController* skinController = skinControllers[i];
                    delete skinController;
                }
                skinControllers.clear ();
                ++it;
            }
            mSkinControllersMap.clear ();
        }

        {
            std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::MorphController*> >::iterator it = mMorphControllersMap.begin ();
            while ( it != mMorphControllersMap.end () )
            {
                std::vector<COLLADAFW::MorphController*>& morphControllers = it->second;
                for ( size_t i=0; i<morphControllers.size (); ++i )
                {
                    COLLADAFW::MorphController* morphController = morphControllers[i];
                    delete morphController;
                }
                morphControllers.clear ();
                ++it;
            }
            mMorphControllersMap.clear ();
        }

        {
            std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::MorphController*> >::iterator it = mMorphTargetsMap.begin ();
            while ( it != mMorphTargetsMap.end () )
            {
                std::vector<COLLADAFW::MorphController*>& morphControllers = it->second;
                for ( size_t i=0; i<morphControllers.size (); ++i )
                {
                    COLLADAFW::MorphController* morphController = morphControllers[i];
                    delete morphController;
                }
                morphControllers.clear ();
                ++it;
            }
            mMorphControllersMap.clear ();
        }

        {
            std::map<COLLADAFW::UniqueId, GeometryFilterData*>::iterator it = mGeometryFilterDataMap.begin ();
            while ( it != mGeometryFilterDataMap.end () )
            {
                GeometryFilterData* mayaGeometryFilterData = it->second;
                delete mayaGeometryFilterData;
                ++it;
            }
            mGeometryFilterDataMap.clear ();
        }
    }

    //------------------------------
    void ControllerImporter::storeController ( const COLLADAFW::Controller* controller )
    {
        // This is the first parsing. We just copy the controller.
        // On the second parsing, we create the maya skinController object with the data.
        if ( controller == 0 ) return;

        // Check if the current controller is already imported.
        const COLLADAFW::UniqueId& controllerId = controller->getUniqueId ();
        if ( findMayaControllerNode ( controllerId ) != 0 ) return;

        COLLADAFW::Controller::ControllerType controllerType = controller->getControllerType ();
        switch ( controllerType )
        {
        case COLLADAFW::Controller::CONTROLLER_TYPE_SKIN:
            {
                // Get the skin controller object.
                COLLADAFW::SkinController* skinController = (COLLADAFW::SkinController*)controller;

                // Returns the unique id of the source that gets modified by this controller. 
                // Must be a mesh or a controller.
                const COLLADAFW::UniqueId& sourceId = skinController->getSource ();

                // Make a copy of the controller element.
                mSkinControllersMap [ sourceId ].push_back ( new COLLADAFW::SkinController (*skinController) );
            }
            break;
        case COLLADAFW::Controller::CONTROLLER_TYPE_MORPH:
            {
                // Get the skin controller object.
                COLLADAFW::MorphController* morphController = (COLLADAFW::MorphController*)controller;

                // Returns the unique id of the source that gets modified by this controller. 
                // Must be a mesh.
                const COLLADAFW::UniqueId& sourceId = morphController->getSource ();

                // Make a copy of the controller element and push it in the list of morph controlled elements.
                mMorphControllersMap [ sourceId ].push_back ( new COLLADAFW::MorphController (*morphController) );

                // The morph targets must also be stored (every morph target has to be imported).
                const COLLADAFW::UniqueIdArray& morphTargets = morphController->getMorphTargets ();
                for ( size_t targetIndex=0; targetIndex<morphTargets.getCount (); ++targetIndex )
                {
                    const COLLADAFW::UniqueId& targetId = morphTargets [targetIndex];
                    if ( targetId != sourceId )
                        mMorphTargetsMap [ targetId ].push_back ( new COLLADAFW::MorphController (*morphController) );
                }
            }
            break;
        default:
            std::cerr << "Unknown controller type!" << std::endl;
        }
    }

    // --------------------------------------------
    void ControllerImporter::importMorphControllers ()
    {
        // Iterate over all existing morph controllers and import them.
        // The map holds the morph controller objects for every source (mesh).
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::MorphController*> >::iterator it = mMorphControllersMap.begin ();
        while ( it != mMorphControllersMap.end () )
        {
            std::vector<COLLADAFW::MorphController*> morphControllers = it->second;
            for ( size_t i=0; i<morphControllers.size (); ++i )
            {
                COLLADAFW::MorphController* morphController = morphControllers [i];
                importMorphController ( morphController );
            }

            ++it;
        }
    }

    // --------------------------------------------
    const bool ControllerImporter::importMorphController ( 
        COLLADAFW::MorphController* morphController )
    {
        if ( morphController == 0 ) return false;

        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();

        // The source of a morph controller is always a geometry.
        const COLLADAFW::UniqueId& geometryId = morphController->getSource ();

        // Check if the current controller is already imported.
        const COLLADAFW::UniqueId& morphControllerId = morphController->getUniqueId ();
        if ( morphControllerExported ( morphControllerId ) ) return false;
        mMorphControllerIds.push_back ( morphControllerId );

        // Get the current maya file.
        FILE* file = getDocumentImporter ()->getFile ();
        
        // Just import the morph controller, if it is either directly referenced as an 
        // instance_controller element from a transform node or as a skin source element from 
        // a skin controller.
        const UniqueIdVec* transformIds = visualSceneImporter->findControllerTransformIds ( morphControllerId );
        if ( transformIds == 0 ) 
        {
            // Check if the morph controller is referenced from a skin controller.
            const std::vector<COLLADAFW::SkinController*>* skinControllers = findSkinControllersBySourceId ( morphControllerId );
            if ( skinControllers == 0 || skinControllers->size () == 0 ) return false;
        }

        // Create a data store object to hold all the MayaDM objects of the current controller.
        // The objects will be needed, to make all the connections.
        BlendShapeData* blendShapeData = new BlendShapeData ();

        // SkinCluster nodes are created during a smooth bindSkin. The purpose of the skinCluster 
        // is to store a weight per influence object for each component of each geometry that is 
        // deformed. Influence objects can be joints or any transform.
        String blendShapeName = createBlendShape ( morphController, *blendShapeData );
        if ( blendShapeName.empty () ) return false;

        // Create all maya objects, which are needed to connect a maya skinCluster to a geometry.
        createGeometryFilterBindingObjects ( *blendShapeData, blendShapeName );

        // Hold the controller data in a map.
        mGeometryFilterDataMap [ morphControllerId ] = blendShapeData;

        // Every controller has two groupIds, which have to be connected to the geometry object 
        // groups. About this, the initial index position for connections to the geometry's 
        // object groups have to be on a later index position.
        addControllerToObjectGroupsInitialIndex ( morphControllerId );

        return true;
    }

    // --------------------------------------------
    const String ControllerImporter::createBlendShape ( 
        COLLADAFW::MorphController* morphController, 
        BlendShapeData& blendShapeData )
    {
        // The uniqueId.
        const COLLADAFW::UniqueId& controllerId = morphController->getUniqueId ();

        // Create a unique blend shape name.
        String blendShapeName = morphController->getName ();
        if ( blendShapeName.empty () ) blendShapeName = BLEND_SHAPE_NAME;
        blendShapeName = DocumentImporter::frameworkNameToMayaName ( blendShapeName );
        const ExtraDataCallbackHandler& callbackHandler = getDocumentImporter ()->getMayaIdCallbackHandler ();
        String originalMayaId = getOriginalMayaId ( callbackHandler, controllerId, COLLADASaxFWL15::HASH_ELEMENT_CONTROLLER );
        if ( !originalMayaId.empty () ) blendShapeName = originalMayaId;
        blendShapeName = generateUniqueDependNodeName ( blendShapeName, true, true );

        // Create the skin cluster
        FILE* file = getDocumentImporter ()->getFile ();
        MayaDM::BlendShape* blendShape = new MayaDM::BlendShape ( file, blendShapeName );
        blendShapeData.setBlendShape ( blendShape );

        // Add the original id attribute.
        String colladaId = morphController->getOriginalId ();
        if ( !colladaId.empty () )
        {
            MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_DATA_TYPE, ATTRIBUTE_TYPE_STRING );
            MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_STRING, colladaId );
        }
//         // TODO Add the attributes for all the extra tags.
//         setExtraData ( morphController->getExtraDataArray () );

        // Write the weights
        const COLLADAFW::UniqueIdArray& morphTargets = morphController->getMorphTargets ();
        size_t numMorphTargets = morphTargets.getCount ();
        COLLADAFW::FloatOrDoubleArray& morphWeights = morphController->getMorphWeights ();
        size_t numMorphWeights = morphWeights.getValuesCount ();
        if (  numMorphTargets != numMorphWeights )
        {
            std::cerr << "The number of morph targets differs from the number of morph weights!" << std::endl;
            return EMPTY_STRING;
        }

        // Add the morph targets in the list of targets.
        for ( size_t targetIndex=0; targetIndex<numMorphTargets; ++targetIndex )
        {
            const COLLADAFW::UniqueId& morphTargetId = morphTargets [targetIndex];
            mMorphTargetIds [controllerId].push_back ( morphTargetId );
        }

        // setAttr -size 5 ".weight[0:4]"  0 1 0 0 0;
        if ( numMorphWeights == 1 )
        {
            float weight = getFloatValue ( morphWeights, 0 );
            blendShape->setWeight ( 0, weight );
        }
        else
        {
            const COLLADAFW::FloatOrDoubleArray::DataType& inputDataType = morphWeights.getType ();
            if ( inputDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT )
            {
                COLLADAFW::FloatArray* floatArray = morphWeights.getFloatValues ();
                blendShape->setWeight ( 0, numMorphWeights-1, floatArray->getData () );
            }
            else
            {
                blendShape->startWeight ( 0, numMorphWeights-1 );
                for ( size_t weightIndex=0; weightIndex<numMorphWeights; ++weightIndex )
                {
                    float weight = getFloatValue ( morphWeights, weightIndex );
                    blendShape->appendWeight ( weight );
                }
                blendShape->endWeight ();
            }
        }

        // Import the animations.
        const COLLADAFW::UniqueId& animationListId = morphWeights.getAnimationList ();
        if ( animationListId.isValid () )
        {
            // Create a TransformAnimation objekt and push it in the list.
            MorphAnimation morphAnim;
            morphAnim.setAnimationListId ( animationListId );
            morphAnim.setAnimationSourceId ( controllerId );
            morphAnim.setBlendShapeTarget ( *blendShape );
            mMorphAnimationMap [animationListId] = morphAnim;
        }


//         // TODO
//         // setAttr -size 5 ".inputTarget[0].inputTargetGroup";
//         // setAttr ( file, blendShape->getInputTargetGroup (0), numMorphTargets );
// 
//         // Create the attribute alias list.
//         String attributeName = "attributeAliasList";
//         String attributeType = "attributeAlias";
// 
//         // addAttr -cachedInternally true -hidden true -shortName "aal" -longName "attributeAliasList" -binaryTag "ATAL" -dataType "attributeAlias";
//         // addAttr -cachedInternally true -hidden true -shortName "aal" -longName "attributeAliasList" -binaryTag "ATAL" -dataType "attributeAlias";
//         MayaDM::startAddAttr ( file, true );
//         MayaDM::appendAddAttr ( file, "cachedInternally", true );
//         MayaDM::appendAddAttr ( file, "hidden", true );
//         MayaDM::appendAddAttr ( file, "shortName", String ("aal") );
//         MayaDM::appendAddAttr ( file, "longName", attributeName );
//         MayaDM::appendAddAttr ( file, "binaryTag", String ("ATAL") );
//         MayaDM::appendAddAttr ( file, "dataType", attributeType );
//         MayaDM::endAddAttr ( file );
// 
//         // setAttr ".attributeAliasList" -type "attributeAlias" {"Target0__polySurfaceShape2","weight[0]","Target1__polySurfaceShape3","weight[1]"} ;
//         // setAttr ".attributeAliasList" -type "attributeAlias" {"Target0__StemKink","weight[0]","Target1__CapPoint","weight[1]","Target2__CapFltDstrt","weight[2]","Target3__CapFlatten","weight[3]","Target4__CapDistort","weight[4]"} ;
//         MayaDM::startSetAttr ( file, attributeName, EMPTY_STRING );
//         MayaDM::appendSetAttr ( file, ATTRIBUTE_TYPE, attributeType );
//         MayaDM::appendSetAttrStartValues ( file );
//         for ( size_t i=0; i<numMorphTargets; ++i )
//         {
//             const COLLADAFW::UniqueId& morphTargetId = morphTargets [i];
//             GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();
//             // TODO the geometries are not created!
//             MayaDM::Mesh* mesh = geometryImporter->findMayaDMMeshNode ( morphTargetId );
//             if ( mesh == 0 )
//                 mesh = geometryImporter->findMayaDMControllerMeshNode ( morphTargetId );
//             std::ostringstream stream; stream << "weight[" << i << "]";
//             MayaDM::appendSetAttrAppendValue ( file, mesh->getName (), String (stream.str ()) );
//         }
//         MayaDM::appendSetAttrEndValues ( file );
//         MayaDM::endSetAttr ( file );

        // Create skin cluster object set.
        String blendShapeSetName = blendShapeName + SET_NAME;
        MayaDM::ObjectSet blendShapeSet ( file, blendShapeSetName );
        blendShapeSet.setIsHistoricallyInteresting (0);
        blendShapeSet.setVerticesOnlySet (true);
        blendShapeData.setBlendShapeSet ( blendShapeSet );

        return blendShapeName;
    }

    // --------------------------------------------
    bool ControllerImporter::importSkinControllerData ( 
        const COLLADAFW::SkinControllerData* skinControllerData )
    {
        // This is the second parsing. On the first parsing, we have already copied the controller.
        if ( skinControllerData == 0 ) return false;

        // Check if the current controller is already imported.
        const COLLADAFW::UniqueId& skinControllerDataId = skinControllerData->getUniqueId ();
        if ( skinControllerDataExported ( skinControllerDataId ) ) return false;
        mSkinControllerDataIds.push_back ( skinControllerDataId );

        // Get the current maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get all controller objects, which use the current skinControllerData.
        // We have to create the skinController data for every skinController object.
        const std::vector<COLLADAFW::SkinController*>& skinControllers = findSkinControllersByDataId ( skinControllerDataId );
        for ( size_t i=0; i<skinControllers.size (); ++i )
        {
            // Get the current controller.
            const COLLADAFW::SkinController* skinController = skinControllers[i];
            const COLLADAFW::UniqueId& controllerId = skinController->getUniqueId ();

            // Just import the skin controller elements, which are directly referenced as an 
            // instance_controller element from a transform node.
            VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
            const UniqueIdVec* transformIds = visualSceneImporter->findControllerTransformIds ( controllerId );
            if ( transformIds == 0 ) continue;

            // Create a data store object to hold all the MayaDM objects of the current controller.
            // The objects will be needed, to make all the connections.
            SkinClusterData* skinClusterData = new SkinClusterData ();

            // SkinCluster nodes are created during a smooth bindSkin. The purpose of the skinCluster 
            // is to store a weight per influence object for each component of each geometry that is 
            // deformed. Influence objects can be joints or any transform.
            const String skinClusterName = createSkinCluster ( skinControllerData, *skinClusterData );
            if ( skinClusterName.empty () ) return false;

            // Create all maya objects, which are needed to connect a maya skinCluster to a geometry.
            createGeometryFilterBindingObjects ( *skinClusterData, skinClusterName );

            // Hold the controller data in a map.
            mGeometryFilterDataMap [ controllerId ] = skinClusterData;

            // Every controller has two groupIds, which have to be connected to the geometry object 
            // groups. About this, the initial index position for connections to the geometry's 
            // object groups have to be on a later index position.
            addControllerToObjectGroupsInitialIndex ( controllerId );

            // Calculate the transformation of the skin cluster's transform nodes
            const COLLADABU::Math::Matrix4& bindShapeMatrix = skinControllerData->getBindShapeMatrix ();
            if ( !bindShapeMatrix.isIdentiy () )
            {
                // Get all transformations, which reference to this skin cluster and get the transformations.
                const UniqueIdVec* transformIdVec = visualSceneImporter->findControllerTransformIds ( controllerId );
                if ( transformIdVec != 0 )
                {
                    for ( size_t i=0; i<transformIdVec->size (); ++i )
                    {
                        // Get the nodes.
                        const COLLADAFW::UniqueId& transformId = (*transformIdVec) [i];
                        MayaDM::Transform* transformNode = visualSceneImporter->findMayaDMTransform ( transformId );
                        MayaNodesList* mayaTransformNodes = visualSceneImporter->findMayaTransformNodes ( transformId );

                        // No different transformations on multiple instances. We can use the first.
                        MayaNode* mayaTransformNode = (*mayaTransformNodes) [0];
                        const COLLADABU::Math::Matrix4& localTransformMatrix = mayaTransformNode->getTransformationMatrix ();

                        // Calculate the new transform matrix.
                        COLLADABU::Math::Matrix4 transformMatrix = bindShapeMatrix * localTransformMatrix;

                        // Write it in the maya file.
                        String nodeName = mayaTransformNode->getNodePath ();
                        mayaSelect ( file, nodeName, true );

                        // Maya bind shape bug on unit conversion!
                        // @see DocumentImporter::getLinearUnitMayaBindShapeBugConvertFactor ()

                        // Translate
                        COLLADABU::Math::Vector3 trans = transformMatrix.getTrans ();
                        transformNode->setTranslate ( toLinearUnit ( MayaDM::double3 ( trans.x, trans.y, trans.z ) ) );
                        MayaDM::setAttr ( file, ATTR_TRANSLATE, FLAG_LOCK, true, EMPTY_STRING );

                        // To get the rotation, we have to remove the scale from the matrix. After this, we have to 
                        // check if there is also a shear on the matrix. If not, we can get the rotation.
                        COLLADABU::Math::Matrix3 m3x3 = extract3x3MatrixWithNormalizedColumns ( transformMatrix );

                        // Get the scale.
                        COLLADABU::Math::Vector3 scale = transformMatrix.getScale ();

                        // Get the determinant of the matrix. If it is smaller or equal zero, we have to change 
                        // the matrix to get the correct rotation.
                        double determinant = m3x3.determinant ();
                        if ( determinant <= 0 )
                        {
                            scale.x *= -1;
                            COLLADABU::Math::Matrix3 m3x3Det ( -1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 );
                            m3x3 = m3x3 * m3x3Det;
                        }

                        // Now we can get the rotation and set it into the document.
                        double x=0.0, y=0.0, z=0.0;
                        m3x3.toEulerAnglesZYX ( z, y, x );
                        transformNode->setRotate ( toAngularUnit ( MayaDM::double3 ( x, y, z ) ) );
                        MayaDM::setAttr ( file, ATTR_ROTATE, FLAG_LOCK, true, EMPTY_STRING );
                        MayaDM::setAttr ( file, ATTR_ROTATE_ORDER, FLAG_LOCK, true, EMPTY_STRING );

                        // Write the scale.
                        transformNode->setScale ( ( MayaDM::double3 ( scale.x, scale.y, scale.z ) ) );
                        MayaDM::setAttr ( file, ATTR_SCALE, FLAG_LOCK, true, EMPTY_STRING );

                        // TODO Shear
//                         double shear[3];
//                         tm.getShear ( shear, MSpace::kTransform );
//                         transformNode->setShear ( ( MayaDM::double3 ( shear[0], shear[1], shear[2] ) ) );
                    }
                }
            }


//             // TODO Read the controllers bind pose joint matrix of every joint and set it.
//             // Get the joints and the bindPose matrices of the skinController.
//             const COLLADAFW::UniqueIdArray& jointIds = skinController->getJoints ();
//             const COLLADAFW::Matrix4Array& inverseBindMatrices = skinControllerData->getInverseBindMatrices ();
//             if ( jointIds.getCount () != inverseBindMatrices.getCount () )
//             {
//                 std::cerr << "The number of joints in the skinCluster is not the same then the number of bind matrices! Can't import!" << std::endl;
//                 continue;
//             }
// 
//             for ( size_t i=0; i<jointIds.getCount (); ++i )
//             {
//                 // Get the current joint.
//                 const COLLADAFW::UniqueId& jointId = jointIds [i];
//                 VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
//                 const MayaDM::Transform* transformNode = visualSceneImporter->findMayaDMTransform ( jointId );
//                 MayaDM::Joint* jointNode = (MayaDM::Joint*)transformNode;
// 
//                 // Get the bindPose matrix of the skinController for the current joint.
//                 const COLLADABU::Math::Matrix4& inverseBindMatrix = inverseBindMatrices [i];
// 
//                 const COLLADABU::Math::Matrix3 matrix3 ( 
//                     inverseBindMatrix[0][0], inverseBindMatrix[0][1], inverseBindMatrix[0][2],
//                     inverseBindMatrix[1][0], inverseBindMatrix[1][1], inverseBindMatrix[1][2],
//                     inverseBindMatrix[2][0], inverseBindMatrix[2][1], inverseBindMatrix[2][2] );
//                 const COLLADABU::Math::Vector3 vector3_1 ( inverseBindMatrix[0][3], inverseBindMatrix[1][3], inverseBindMatrix[2][3] );
//                 const COLLADABU::Math::Vector3 vector3_2 = matrix3.inverse ( getTolerance () ) * vector3_1 * (-1);
// 
//                 // Generate the bindPose matrix.
//                 COLLADABU::Math::Matrix4 bindPoseMatrix = inverseBindMatrix.transpose ();
//                 bindPoseMatrix.setElement ( 3, 0, 0 );
//                 bindPoseMatrix.setElement ( 3, 1, 0 );
//                 bindPoseMatrix.setElement ( 3, 2, 0 );
//                 bindPoseMatrix.setElement ( 3, 3, 1 );
// 
//                 bindPoseMatrix.setElement ( 0, 3, vector3_2 [0] );
//                 bindPoseMatrix.setElement ( 1, 3, vector3_2 [1] );
//                 bindPoseMatrix.setElement ( 2, 3, vector3_2 [2] );
// 
//                 // Convert the matrix to a double[4][4] and then to a mayaDM matrix.
//                 double m[4][4];
//                 convertMatrix4ToTransposedDouble4x4 ( m, bindPoseMatrix, getTolerance () );
//                 MayaDM::matrix bpm (m);
// 
//                 // Convert the matrix to a maya matrix.
//                 MMatrix matrix ( m );
//                 MTransformationMatrix tm ( matrix );
// 
//                 double rotation[3];
//                 MTransformationMatrix::RotationOrder order;
//                 tm.getRotation ( rotation, order, MSpace::kTransform );
// 
//                 // Select the joint object and set the bindPose attribute.
//                 mayaSelect ( file, jointNode->getName (), true );
//                 jointNode->setBindPose ( bpm );
//                 //jointNode->setRotate ( toAngularUnit ( MayaDM::double3 ( rotation[0], rotation[1], rotation[2] ) ) );
//             }
        }

        return true;
    }

    // --------------------------------------------
    const String ControllerImporter::createSkinCluster ( 
        const COLLADAFW::SkinControllerData* skinControllerData, 
        SkinClusterData& skinClusterData )
    {
        // The uniqueId of the element.
        const COLLADAFW::UniqueId& skinControllerDataId = skinControllerData->getUniqueId ();

        // Create a unique skin cluster name.
        String skinClusterName = skinControllerData->getName ();
        if ( skinClusterName.empty () ) skinClusterName = SKIN_CLUSTER_NAME;
        skinClusterName = DocumentImporter::frameworkNameToMayaName ( skinClusterName );
        const ExtraDataCallbackHandler& callbackHandler = getDocumentImporter ()->getMayaIdCallbackHandler ();
        String originalMayaId = getOriginalMayaId ( callbackHandler, skinControllerDataId, COLLADASaxFWL15::HASH_ELEMENT_CONTROLLER );
        if ( !originalMayaId.empty () ) skinClusterName = originalMayaId;
        skinClusterName = generateUniqueDependNodeName ( skinClusterName, true, true );

        // Create the skin cluster
        FILE* file = getDocumentImporter ()->getFile ();
        MayaDM::SkinCluster* skinCluster = new MayaDM::SkinCluster ( file, skinClusterName );
        skinClusterData.setSkinCluster ( skinCluster );

        // Add the original id attribute.
        String colladaId = skinControllerData->getOriginalId ();
        if ( !colladaId.empty () )
        {
            MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_DATA_TYPE, ATTRIBUTE_TYPE_STRING );
            MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_STRING, colladaId );
        }
//         // TODO Add the attributes for all the extra tags.
//         setExtraData ( skinControllerData->getExtraDataArray () );

        // Weights for each target.
        {
            // The number of influences is the number of vertices in the mesh.
            size_t vertexCount = skinControllerData->getVertexCount ();
            // The list with the numbers of influences per vertex.
            const COLLADAFW::UIntValuesArray& jointsPerVertex = skinControllerData->getJointsPerVertex ();
            // The joint indices
            const COLLADAFW::IntValuesArray& jointIndices = skinControllerData->getJointIndices ();
            // The list of indices to the weight list.
            const COLLADAFW::UIntValuesArray& weightIndices = skinControllerData->getWeightIndices ();
            // The weight list.
            const COLLADAFW::FloatOrDoubleArray& weights = skinControllerData->getWeights ();

            size_t weightIndicesIndex = 0;
            for ( size_t influenceIndex=0; influenceIndex<vertexCount; ++influenceIndex )
            {
                // Number of influences
                unsigned int numVertexInfluences = jointsPerVertex [influenceIndex];

                // The list of the current weights array.
                std::vector<double> currentWeights;

                // Flag, if the weight list should be written.
                bool doWriteWeights = false;
                bool weightInserted = false;
                unsigned int jointStartIndex = 0;
                unsigned int jointEndIndex = 0;
                unsigned int previousJointIndex = 0;

                // Go through the weights and write them.
                // If the previous weight is from the joint before the current weight,
                // they can be written as an array. Otherwise, they have to be written separately.
                for ( size_t j=0; j<numVertexInfluences; ++j, ++weightIndicesIndex )
                {
                    // Get the current weight. 
                    unsigned int weightIndex = weightIndices [ weightIndicesIndex ];
                    double weight = getDoubleValue ( weights, weightIndex );
                    doWriteWeights = false;
                    weightInserted = false;

                    // Handle the indices.
                    unsigned int jointIndex = jointIndices [ weightIndicesIndex ];
                    if ( j == 0 ) 
                    {
                        // The begin is the end of the current array.
                        jointStartIndex = jointEndIndex = jointIndex;

                        // Push the current weight in the list of current weights.
                        currentWeights.push_back ( weight );
                        weightInserted = true;
                    }
                    else if ( jointIndex == jointEndIndex+1 )
                    {
                        // The next joint is the next neighbour. We can write an array.
                        jointEndIndex = jointIndex;

                        // Push the current weight in the list of current weights.
                        currentWeights.push_back ( weight );
                        weightInserted = true;
                    }
                    else 
                    {
                        // A hole in the index list, we have to write the current weight list.
                        doWriteWeights = true;
                    }

                    // At the last influence, the data will be written.
                    if ( j+1 == numVertexInfluences )
                    {
                        doWriteWeights = true;
                    }

                    // Write the weights, if necessary.
                    if ( doWriteWeights )
                    {
                        writeWeights ( skinCluster, currentWeights, influenceIndex, jointStartIndex, jointEndIndex );
                        jointStartIndex = jointEndIndex = jointIndex;
                    }

                    // Push the current weight in the list of current weights, if not already done.
                    if ( !weightInserted )
                    {
                        currentWeights.push_back ( weight );
                    }
                }

                // Write the last weights, if necessary.
                if ( currentWeights.size () > 0 )
                {
                    writeWeights ( skinCluster, currentWeights, influenceIndex, jointStartIndex, jointEndIndex );
                }
            }
        }

        // Set the inverse bind matrices
        const COLLADAFW::Matrix4Array& inverseBindMatrices = skinControllerData->getInverseBindMatrices ();
        size_t numInverseBindMatrices = inverseBindMatrices.getCount ();
        for ( size_t i=0; i<numInverseBindMatrices; ++i )
        {
            // Get the inverse bind matrix.
            const COLLADABU::Math::Matrix4& inverseBindMatrix = inverseBindMatrices [i];

            // Convert the matrix to a double[4][4]
            double pm[4][4];
            convertMatrix4ToTransposedDouble4x4 ( pm, inverseBindMatrix, getTolerance () );
            MayaDM::matrix mayaPm ( pm );

            // Do the unit conversion of the transform values, if necessary.
//             mayaPm[3][0] = toLinearUnit ( mayaPm[3][0] );
//             mayaPm[3][1] = toLinearUnit ( mayaPm[3][1] );
//             mayaPm[3][2] = toLinearUnit ( mayaPm[3][2] );

            // Maya bug on unit conversion...
            mayaPm[3][0] = toMayaBindShapeBugLinearUnit ( mayaPm[3][0] );
            mayaPm[3][1] = toMayaBindShapeBugLinearUnit ( mayaPm[3][1] );
            mayaPm[3][2] = toMayaBindShapeBugLinearUnit ( mayaPm[3][2] );

            // Set the maya inclusive matrix inverse of the driving transform at the time of bind.
            skinCluster->setBindPreMatrix ( i, mayaPm );
        }

        // Set the bind shape matrix
        {
            // Get the bind shape matrix.
            const COLLADABU::Math::Matrix4& bindShapeMatrix = skinControllerData->getBindShapeMatrix ();

            // Convert the matrix to a double[4][4]
            double gm[4][4];
            convertMatrix4ToTransposedDouble4x4 ( gm, bindShapeMatrix, getTolerance () );

            // Do the unit conversion of the transform values, if necessary.
//             gm[3][0] = toLinearUnit ( gm[3][0] );
//             gm[3][1] = toLinearUnit ( gm[3][1] );
//             gm[3][2] = toLinearUnit ( gm[3][2] );

            // Maya bug on unit conversion...
            gm[3][0] = toMayaBindShapeBugLinearUnit ( gm[3][0] );
            gm[3][1] = toMayaBindShapeBugLinearUnit ( gm[3][1] );
            gm[3][2] = toMayaBindShapeBugLinearUnit ( gm[3][2] );

            // Set the maya inclusive matrix of the geometry path at the time of the bound.
            skinCluster->setGeomMatrix ( gm );
        }

        // Create skin cluster object set.
        String skinClusterSetName = skinClusterName + SET_NAME;
        MayaDM::ObjectSet skinClusterSet ( file, skinClusterSetName );
        skinClusterSet.setIsHistoricallyInteresting (0);
        skinClusterSet.setVerticesOnlySet (true);
        skinClusterData.setSkinClusterSet ( skinClusterSet );

        return skinClusterName;
    }

    //------------------------------
    void ControllerImporter::writeWeights ( 
        MayaDM::SkinCluster* skinCluster, 
        std::vector<double>& currentWeightList, 
        const size_t influenceIndex, 
        const unsigned int jointStartIndex, 
        const unsigned int jointEndIndex )
    {
        // We have to write the weights.
        size_t currentWeightListSize = currentWeightList.size ();
        if ( currentWeightListSize == 1 )
        {
            skinCluster->setWeights ( influenceIndex, jointStartIndex, currentWeightList[0] );
        }
        else if ( currentWeightListSize > 1 )
        {
            if ( jointEndIndex-jointStartIndex+1 != currentWeightList.size () )
            {
                std::cerr << "No valid weight list!" << std::endl;
                return;
            }
            skinCluster->startWeights ( influenceIndex, jointStartIndex, jointEndIndex );
            for ( size_t n=0; n<currentWeightList.size (); ++n )
                skinCluster->appendWeights ( currentWeightList[n] );
            skinCluster->endWeights ();
        }
        // Clear the list again and reset the variables.
        currentWeightList.clear ();
    }

    // --------------------------------------------
    void ControllerImporter::createGeometryFilterBindingObjects ( 
        GeometryFilterData &controllerData, 
        const String& geometryFilterName )
    {
        // Get a pointer to the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Create the groupId and the groupParts for the skinCluster.
        String geometryFilterGroupIdName = geometryFilterName + GROUP_ID_NAME_APPEND;
        geometryFilterGroupIdName = generateUniqueDependNodeName ( geometryFilterGroupIdName );
        MayaDM::GroupId geometryFilterGroupId ( file, geometryFilterGroupIdName );
        geometryFilterGroupId.setIsHistoricallyInteresting (0);
        controllerData.setGeometryFilterGroupId ( geometryFilterGroupId );

        MayaDM::componentList compList;
        compList.push_back ( "vtx[*]" );

        String geometryFilterGroupPartsName = geometryFilterName + GROUP_PARTS_NAME_APPEND;
        geometryFilterGroupPartsName = generateUniqueDependNodeName ( geometryFilterGroupPartsName );
        MayaDM::GroupParts geometryFilterGroupParts ( file, geometryFilterGroupPartsName );
        geometryFilterGroupParts.setIsHistoricallyInteresting (0);
        geometryFilterGroupParts.setInputComponents ( compList );
        controllerData.setGeometryFilterGroupParts ( geometryFilterGroupParts );

        // Create the tweak object and the set.
        String tweakName = TWEAK_NAME;
        tweakName = DocumentImporter::frameworkNameToMayaName ( tweakName );
        tweakName = generateUniqueDependNodeName ( tweakName, true, true );
        MayaDM::Tweak tweak ( file, tweakName );
        controllerData.setTweak ( tweak );

        String tweakSetName = tweakName + SET_NAME;
        tweakSetName = generateUniqueDependNodeName ( tweakSetName );
        MayaDM::ObjectSet tweakSet ( file, tweakSetName );
        tweakSet.setIsHistoricallyInteresting (0);
        tweakSet.setVerticesOnlySet (true);
        controllerData.setTweakSet ( tweakSet );

        // Create the groupId and the groupParts for the tweak.
        String tweakGroupIdName = tweakName + GROUP_ID_NAME_APPEND;
        tweakGroupIdName = generateUniqueDependNodeName ( tweakGroupIdName );
        MayaDM::GroupId tweakGroupId ( file, tweakGroupIdName );
        tweakGroupId.setIsHistoricallyInteresting (0);
        controllerData.setTweakGroupId ( tweakGroupId );

        String tweakGroupPartsName = tweakName + GROUP_PARTS_NAME_APPEND;
        tweakGroupPartsName = generateUniqueDependNodeName ( tweakGroupPartsName );
        MayaDM::GroupParts tweakGroupParts ( file, tweakGroupPartsName );
        tweakGroupParts.setIsHistoricallyInteresting (0);
        tweakGroupParts.setInputComponents ( compList );
        controllerData.setTweakGroupParts ( tweakGroupParts );
    }

    // --------------------------------------------
    MayaNode* ControllerImporter::findMayaControllerNode ( const COLLADAFW::UniqueId& controllerId ) 
    {
        UniqueIdMayaNodeMap::iterator it = mMayaControllerNodesMap.find ( controllerId );
        if ( it != mMayaControllerNodesMap.end () )
            return it->second;

        return 0;
    }

    // --------------------------------------------
    const bool ControllerImporter::skinControllerDataExported ( 
        const COLLADAFW::UniqueId& skinControllerDataId ) const
    {
        for ( size_t i=0; i<mSkinControllerDataIds.size (); ++i )
        {
            if ( mSkinControllerDataIds[i] == skinControllerDataId ) 
                return true;
        }
        return false;
    }

    // --------------------------------------------
    bool ControllerImporter::morphControllerExported ( 
        const COLLADAFW::UniqueId& morphControllerId ) 
    {
        for ( size_t i=0; i<mMorphControllerIds.size (); ++i )
        {
            if ( mMorphControllerIds[i] == morphControllerId ) 
                return true;
        }
        return false;
    }

    // --------------------------------------------
    const std::vector<COLLADAFW::SkinController*> ControllerImporter::findSkinControllersByDataId ( 
        const COLLADAFW::UniqueId& skinControllerDataId )
    {
        std::vector<COLLADAFW::SkinController*> skinControllersNewList (0);

        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::SkinController*> >::iterator it = mSkinControllersMap.begin ();
        while ( it != mSkinControllersMap.end () )
        {
            std::vector<COLLADAFW::SkinController*>& skinControllers = it->second;
            for ( size_t i=0; i<skinControllers.size (); ++i )
            {
                COLLADAFW::SkinController* skinController = skinControllers[i];
                if ( skinController->getSkinControllerData () == skinControllerDataId )
                {
                    skinControllersNewList.push_back ( skinController );
                }
            }
            ++it;
        }
        return skinControllersNewList;
    }

    // --------------------------------------------
    const COLLADAFW::Controller* ControllerImporter::findController ( 
        const COLLADAFW::UniqueId& controllerId )
    {
        const COLLADAFW::Controller* controller = findSkinController ( controllerId );
        if ( controller != 0 ) return controller;

        return findMorphController ( controllerId );
    }

    // --------------------------------------------
    const COLLADAFW::MorphController* ControllerImporter::findMorphController ( 
        const COLLADAFW::UniqueId& controllerId )
    {
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::MorphController*> >::const_iterator it = mMorphControllersMap.begin ();
        while ( it != mMorphControllersMap.end () )
        {
            const std::vector<COLLADAFW::MorphController*>& morphControllers = it->second;
            for ( size_t i=0; i<morphControllers.size (); ++i )
            {
                const COLLADAFW::MorphController* morphController = morphControllers[i];
                if ( morphController->getUniqueId () == controllerId )
                    return morphController;
            }
            ++it;
        }
        return 0;
    }

    // --------------------------------------------
    const COLLADAFW::SkinController* ControllerImporter::findSkinController ( 
        const COLLADAFW::UniqueId& controllerId )
    {
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::SkinController*> >::const_iterator it = mSkinControllersMap.begin ();
        while ( it != mSkinControllersMap.end () )
        {
            const std::vector<COLLADAFW::SkinController*>& skinControllers = it->second;
            for ( size_t i=0; i<skinControllers.size (); ++i )
            {
                const COLLADAFW::SkinController* skinController = skinControllers[i];
                if ( skinController->getUniqueId () == controllerId )
                    return skinController;
            }
            ++it;
        }
        return 0;
    }

    // --------------------------------------------
    bool ControllerImporter::isSourceControlled (
        const COLLADAFW::UniqueId& sourceId ) 
    {
        bool hasController = false;

        // Get the skin controllers and append them in the list.
        const std::vector<COLLADAFW::SkinController*>* skinControllers = findSkinControllersBySourceId ( sourceId );
        if ( skinControllers ) hasController = true;

        if ( !hasController )
        {
            // Get the morph controllers and append them in the list.
            const std::vector<COLLADAFW::MorphController*>* morphControllers = findMorphControllersBySourceId ( sourceId );
            if ( morphControllers ) hasController = true;
        }

        return hasController;
    }

    // --------------------------------------------
    std::vector<COLLADAFW::Controller*> ControllerImporter::findControllersBySourceId ( 
        const COLLADAFW::UniqueId& sourceId ) 
    {
        // Push the skin controllers in the list.
        std::vector<COLLADAFW::Controller*> controllers;

        // Get the skin controllers and append them in the list.
        std::vector<COLLADAFW::SkinController*>* skinControllers = findSkinControllersBySourceId ( sourceId );
        if ( skinControllers )
            controllers.assign ( skinControllers->begin (), skinControllers->end () );

        // Get the morph controllers and append them in the list.
        std::vector<COLLADAFW::MorphController*>* morphControllers = findMorphControllersBySourceId ( sourceId );
        if ( morphControllers )
        {
            if ( controllers.size () > 0 )
            {
                for ( size_t i=0; i<morphControllers->size (); ++i )
                {
                    COLLADAFW::MorphController* morphController = (*morphControllers) [i];
                    controllers.push_back ( morphController );
                }
            }
            else
            {
                controllers.assign ( morphControllers->begin (), morphControllers->end () );
            }
        }

        return controllers;
    }
    
    // --------------------------------------------
    std::vector<COLLADAFW::MorphController*>* ControllerImporter::findMorphControllersByMorphTargetId ( 
        const COLLADAFW::UniqueId& geometryId )
    {
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::MorphController*> >::iterator it;
        it = mMorphTargetsMap.find ( geometryId );
        if ( it != mMorphTargetsMap.end () )
        {
            std::vector<COLLADAFW::MorphController*>& morphControllers = it->second;
            return &morphControllers;
        }
        return 0;
    }

    // --------------------------------------------
    const std::vector<COLLADAFW::MorphController*>* ControllerImporter::findMorphControllersByMorphTargetId ( 
        const COLLADAFW::UniqueId& geometryId ) const
    {
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::MorphController*> >::const_iterator it;
        it = mMorphTargetsMap.find ( geometryId );
        if ( it != mMorphTargetsMap.end () )
        {
            const std::vector<COLLADAFW::MorphController*>& morphControllers = it->second;
            return &morphControllers;
        }
        return 0;
    }

    // --------------------------------------------
    std::vector<COLLADAFW::MorphController*>* ControllerImporter::findMorphControllersBySourceId ( 
        const COLLADAFW::UniqueId& sourceId ) 
    {
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::MorphController*> >::iterator it;
        it = mMorphControllersMap.find ( sourceId );
        if ( it != mMorphControllersMap.end () )
        {
            std::vector<COLLADAFW::MorphController*>& morphControllers = it->second;
            return &morphControllers;
        }
        return 0;
    }

    // --------------------------------------------
    const std::vector<COLLADAFW::MorphController*>* ControllerImporter::findMorphControllersBySourceId ( 
        const COLLADAFW::UniqueId& sourceId ) const
    {
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::MorphController*> >::const_iterator it;
        it = mMorphControllersMap.find ( sourceId );
        if ( it != mMorphControllersMap.end () )
        {
            const std::vector<COLLADAFW::MorphController*>& morphControllers = it->second;
            return &morphControllers;
        }
        return 0;
    }

    // --------------------------------------------
    std::vector<COLLADAFW::SkinController*>* ControllerImporter::findSkinControllersBySourceId ( 
        const COLLADAFW::UniqueId& sourceId ) 
    {
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::SkinController*> >::iterator it;
        it = mSkinControllersMap.find ( sourceId );
        if ( it != mSkinControllersMap.end () )
        {
            std::vector<COLLADAFW::SkinController*>& skinControllers = it->second;
            return &skinControllers;
        }
        return 0;
    }

    // --------------------------------------------
    const std::vector<COLLADAFW::SkinController*>* ControllerImporter::findSkinControllersBySourceId ( 
        const COLLADAFW::UniqueId& sourceId ) const
    {
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::SkinController*> >::const_iterator it;
        it = mSkinControllersMap.find ( sourceId );
        if ( it != mSkinControllersMap.end () )
        {
            const std::vector<COLLADAFW::SkinController*>& skinControllers = it->second;
            return &skinControllers;
        }
        return 0;
    }

    // --------------------------------------------
    const COLLADAFW::UniqueId* ControllerImporter::getControllerSourceId ( 
        const COLLADAFW::UniqueId& controllerId ) const
    {
        {
            std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::SkinController*> >::const_iterator it = mSkinControllersMap.begin ();
            while ( it != mSkinControllersMap.end () )
            {
                const std::vector<COLLADAFW::SkinController*>& skinControllers = it->second;
                for ( size_t i=0; i<skinControllers.size (); ++i )
                {
                    const COLLADAFW::SkinController* skinController = skinControllers[i];
                    if ( skinController->getUniqueId () == controllerId )
                        return &(skinController->getSource ());
                }
                ++it;
            }
        }

        {
            std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::MorphController*> >::const_iterator it = mMorphControllersMap.begin ();
            while ( it != mMorphControllersMap.end () )
            {
                const std::vector<COLLADAFW::MorphController*>& morphControllers = it->second;
                for ( size_t i=0; i<morphControllers.size (); ++i )
                {
                    const COLLADAFW::MorphController* morphController = morphControllers[i];
                    if ( morphController->getUniqueId () == controllerId )
                        return &(morphController->getSource ());
                }
                ++it;
            }
            return 0;
        }
    }

    // --------------------------------------------
    const ControllerImporter::GeometryFilterData* ControllerImporter::findGeometryFilterData ( 
        const COLLADAFW::UniqueId& controllerId )
    {
        std::map<COLLADAFW::UniqueId, GeometryFilterData*>::const_iterator it = mGeometryFilterDataMap.find ( controllerId );
        if ( it != mGeometryFilterDataMap.end () )
            return it->second;
        return 0;
    }

    // --------------------------------------------
    const size_t ControllerImporter::findObjectGroupsInitialIndex ( 
        const COLLADAFW::UniqueId& controllerId ) const
    {
        UniqueIdSizeTMap::const_iterator it = mObjectGroupsInitialIndexMap.find ( controllerId ); 
        if ( it != mObjectGroupsInitialIndexMap.end () )
        {
            return it->second;
        }
        return 0;
    }

    // --------------------------------------------
    const BaseImporter::UniqueIdVec* ControllerImporter::findMorphTargets ( 
        const COLLADAFW::UniqueId& controllerId )
    {
        UniqueIdUniqueIdsMap::const_iterator it = mMorphTargetIds.find ( controllerId );
        if ( it != mMorphTargetIds.end () )
        {
            return &(it->second);
        }
        return 0;
    }

    // --------------------------------------------
    void ControllerImporter::addControllerToObjectGroupsInitialIndex ( 
        const COLLADAFW::UniqueId& controllerId )
    {
        size_t objectGroupsInitialIndex = findObjectGroupsInitialIndex ( controllerId );
        objectGroupsInitialIndex += 2; 
        mObjectGroupsInitialIndexMap [ controllerId ] = objectGroupsInitialIndex;
    }

    // --------------------------------------------
    const MorphAnimation* ControllerImporter::findMorphAnimation ( 
        const COLLADAFW::UniqueId& animationListId )
    {
        std::map <COLLADAFW::UniqueId, MorphAnimation>::const_iterator it = mMorphAnimationMap.find ( animationListId );
        if ( it != mMorphAnimationMap.end () )
        {
            return &(it->second);
        }
        return 0;
    }

    // --------------------------------------------
    void ControllerImporter::writeConnections ()
    {
        connectSkinControllerJoints ();
        connectGeometries ();
        connectControllers ();
        connectMorphControllerTargets ();
    }

    // --------------------------------------------
    void ControllerImporter::connectSkinControllerJoints ()
    {
        // Get a pointer to the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();

        // Connect the skin cluster's joints world matrix with the skin cluster matrix.
        std::map<COLLADAFW::UniqueId, GeometryFilterData*>::const_iterator it2 = mGeometryFilterDataMap.begin ();
        while ( it2 != mGeometryFilterDataMap.end () )
        {
            // Get the current controller.
            const COLLADAFW::UniqueId& controllerId = it2->first;
            const COLLADAFW::SkinController* skinController = findSkinController ( controllerId );
            if ( skinController == 0 ) 
            {
                // The controller element can also be a morph controller. Then we don't need 
                // a connection to the joints.
                //std::cerr << "No skin controller element found!" << std::endl;
                ++it2; continue;
            }

            // Get the maya controller data object.
            const GeometryFilterData* controllerData = it2->second;
            MayaDM::SkinCluster* skinCluster = (MayaDM::SkinCluster*)controllerData->getGeometryFilter ();

            // Iterate over the joints of the current controller and make the connections.
            const COLLADAFW::UniqueIdArray& joints = skinController->getJoints ();
            for ( size_t i=0; i<joints.getCount (); ++i )
            {
                // Get the maya joint node.
                const COLLADAFW::UniqueId& jointId = joints [i];
                MayaDM::Joint* jointNode = ( MayaDM::Joint* ) visualSceneImporter->findMayaDMTransform ( jointId );

                // connectAttr "joint1.worldMatrix" "skinCluster1.matrix[0]";
                connectAttr ( file, jointNode->getWorldMatrix (), skinCluster->getMatrix ( i ) );

                // - ".liw" stands for "Lock Influence Weight". By default, a joint doesn't have this 
                // attribute, but when it is smooth bound to geometry, each joint receives this new 
                // attribute. It is just a custom attribute. Its output connects to the respective 
                // skinCluster's ".lockWeights[]" (.lw) imput attribute. ".lockWeights[]" is an 
                // array attribute, that can receive inputs from multiple joint.liw attrs.
                // - There is no reference to this attribute (.liw) in the documentation, since it 
                // is a custom attr generated by the smoothBind process. You can find documentation 
                // for the ".lw" attr in the "joint" documentation.
                // connectAttr "joint1.lockInfluenceWeights" "skinCluster1.lockWeights[0]";
                //connectAttr ( file, jointNode->lockInfluenceWeights (), skinCluster.getLockWeights ( i ) );
            }            

            ++it2;
        }
    }

    // --------------------------------------------
    const BaseImporter::UniqueIdVec* ControllerImporter::getSkinControllerTransforms ( 
        const COLLADAFW::UniqueId& controllerId )
    {
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();
        ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();

        const UniqueIdVec* transformIds = 0;

        // Get the skin controllers, which instantiates the morph controller 
        // and get the transformations of the skin controller.
        const std::vector<COLLADAFW::SkinController*>* skinControllers = controllerImporter->findSkinControllersBySourceId ( controllerId );
        if ( skinControllers == 0 ) 
        {
            // The current morph controller is not referenced, neither from the scene 
            // graph nor from another skin controller element.
            std::cerr << "The morph controller is not used!" << std::endl;
            return transformIds;
        }
        for ( size_t i=0; i<skinControllers->size (); ++i )
        {
            const COLLADAFW::SkinController* skinController = (*skinControllers) [i];
            const COLLADAFW::UniqueId& skinControllerId = skinController->getUniqueId ();
            transformIds = visualSceneImporter->findControllerTransformIds ( skinControllerId );
            if ( transformIds == 0 )
            {
                // The skin controller, which use the current morph controller is not
                // referenced from the scene graph.
                std::cerr << "The skin controller is not used!" << std::endl;
            }
            else
            {
                return transformIds;
            }
        }

        return transformIds;
    }

    // --------------------------------------------
    void ControllerImporter::connectGeometries ()
    {
        // Get a pointer to the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();
        ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();

        // Get the geometry objects of the controllers and make the required connections.
        std::map<COLLADAFW::UniqueId, GeometryFilterData*>::const_iterator it = mGeometryFilterDataMap.begin ();
        while ( it != mGeometryFilterDataMap.end () )
        {
            // Get the maya controller with the data objects.
            const COLLADAFW::UniqueId& controllerId = it->first;
            const GeometryFilterData* geometryFilterData = it->second;

            // Get the current controller.
            const COLLADAFW::Controller* controller = findController ( controllerId );
            if ( controller == 0 ) 
            {
                std::cerr << "No controller element found!" << std::endl;
                ++it; continue;
            }

            // The meshControllerData object.
            GeometryImporter::MeshControllerData* meshControllerData = 0;

            // Flag, if the current controller element is direct instantiated or just over another controller.
            bool isInstantiated = true;

            // Check for multiple mesh instances. If there are multiple instances, 
            // we have to use the full path to the mesh object.
            const UniqueIdVec* transformIds = visualSceneImporter->findControllerTransformIds ( controllerId );
            if ( transformIds == 0 )
            {
                // The controller is not directly instantiated from the scene graph.
                isInstantiated = false;

                // The controller is not directly instantiated in the scene graph.
                // Could be a morph controller, which is instantiated from a skin controller.
                if ( controller->getControllerType () == COLLADAFW::Controller::CONTROLLER_TYPE_MORPH )
                {
                    transformIds = getSkinControllerTransforms ( controllerId );
                    if ( transformIds == 0 )
                    {
                        // The skin controller, which use the current morph controller is not
                        // referenced from the scene graph.
                        std::cerr << "The skin controller is not used!" << std::endl;
                        ++it; continue;
                    }
                }
            }

            // Just take the first element, this one is the one, where all data depends on.
            const COLLADAFW::UniqueId& transformId = (*transformIds) [0];

            // Get the meshControllerData
            meshControllerData = geometryImporter->findMeshControllerDataByControllerAndTransformId ( controllerId, transformId );
            if ( meshControllerData == 0 )
            {
                std::cerr << "No meshControllerData!" << std::endl;
                ++it; continue;
            }

            // Get the controller mesh object.
            MayaDM::Mesh& mesh = meshControllerData->getControllerMeshNode ();

            // Get the original mesh object for the connection to the worldMesh.
            const MayaDM::Mesh& meshOrig = meshControllerData->getOriginalMeshNode ();

            // connectAttr "pCubeShape1Orig.worldMesh" "groupParts2.inputGeometry";
            const MayaDM::GroupParts& groupParts2 = geometryFilterData->getTweakGroupParts ();
            connectAttr ( file, meshOrig.getWorldMesh (), groupParts2.getInputGeometry () );

            // Just one controller per geometry, always at the beginning, the primitve element 
            // indices come always after the controller indices.

            // connectAttr "skinCluster1GroupId.groupId" "pCubeShape1.instObjGroups.objectGroups[0].objectGroupId";
            const MayaDM::GroupId& geometryFilterGroupId = geometryFilterData->getGeometryFilterGroupId ();
            connectAttr ( file, geometryFilterGroupId.getGroupId (), mesh.getObjectGroupId (0) );

            // connectAttr "skinCluster1Set.memberWireframeColor" "pCubeShape1.instObjGroups.objectGroups[0].objectGrpColor";
            const MayaDM::ObjectSet& geometryFilterSet = geometryFilterData->getGeometryFilterSet();
            connectAttr ( file, geometryFilterSet.getMemberWireframeColor (), mesh.getObjectGrpColor (0) );

            // connectAttr "groupId2.groupId" "pCubeShape1.instObjGroups.objectGroups[1].objectGroupId";
            const MayaDM::GroupId& tweakGroupId = geometryFilterData->getTweakGroupId ();
            connectAttr ( file, tweakGroupId.getGroupId (), mesh.getObjectGroupId (1) );

            // connectAttr "tweakSet1.memberWireframeColor" "pCubeShape1.instObjGroups.objectGroups[1].objectGrpColor";
            const MayaDM::ObjectSet& tweakSet = geometryFilterData->getTweakSet ();
            connectAttr ( file, tweakSet.getMemberWireframeColor (), mesh.getObjectGrpColor (1) );

            // Just do this connection, if we don't use groupParts (either no multiple mesh 
            // primitive elements in the current geometry or we have a morph controller object, 
            // which is just referenced from a skin controller, not from the scene graph).
            const COLLADAFW::UniqueId& geometryId = meshControllerData->getGeometryId ();
            const size_t numPrimitiveElements = geometryImporter->findPrimitivesCount ( geometryId );
            if ( numPrimitiveElements==1 || !isInstantiated )
            {
                // connectAttr "skinCluster1.outputGeometry[0]" "pCubeShape1.inMesh";
                const MayaDM::GeometryFilter* geometryFilter = geometryFilterData->getGeometryFilter ();
                connectAttr ( file, geometryFilter->getOutputGeometry (0), mesh.getInMesh () );
            }

            // connectAttr "tweak1.vlist[0].vertex[0]" "pCubeShape1.tweakLocation";
            const MayaDM::Tweak& tweak = geometryFilterData->getTweak ();
            connectAttr ( file, tweak.getVertex (0,0), mesh.getTweakLocation () );

            // connectAttr "pCubeShape1.instObjGroups.objectGroups[0]" "skinCluster1Set.dagSetMembers" -nextAvailable;
            connectNextAttr ( file, mesh.getObjectGroups (0), geometryFilterSet.getDagSetMembers () );

            // connectAttr "pCubeShape1.instObjGroups.objectGroups[1]" "tweakSet1.dagSetMembers" -nextAvailable;
            connectNextAttr ( file, mesh.getObjectGroups (1), tweakSet.getDagSetMembers () );

            ++it;
        }
    }

    // --------------------------------------------
    void ControllerImporter::connectMorphControllerTargets ()
    {
        // Get a pointer to the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();

        // Get the geometry objects of the controllers and make the required connections.
        std::map<COLLADAFW::UniqueId, GeometryFilterData*>::iterator it = mGeometryFilterDataMap.begin ();
        while ( it != mGeometryFilterDataMap.end () )
        {
            // Get the maya controller with the data objects.
            const COLLADAFW::UniqueId& controllerId = it->first;
            GeometryFilterData* geometryFilterData = it->second;

            // The connection from the mesh to the blendShape inputGeomTarget.
            // connectAttr "pCubeShape1.worldMesh" "blendShape1.inputTarget[0].inputTargetGroup[0].inputTargetItem[6000].inputGeomTarget";
            // inputTarget (it): 
            //  Bundled list of target info for a shape that is being deformed. The array index of 
            //  this attribute corresponds to the array index of the input attribute, meaning that 
            //  this target info is used to deform a given input shape.
            // inputTargetGroup (itg): 
            //  Bundled group of target information for a particular target weight. The array index 
            //  of this attribute corresponds to the array index of the weight attribute, meaning 
            //  that the corresponding weight value controls this target.
            // inputTargetItem (iti):
            //  Collection of all targets in a sequential target chain. The array index of this 
            //  attribute is used to control which two target items we are interpolating between 
            //  with the relationship: index = wt * 1000 + 5000. Thus a weight of 1 corresponds to 
            //  the index 6000. An inbetween placed at a weight of 0.5 would be at the index 5500.
            // inputGeomTarget (igt):
            //  The target geometry input.
            if ( geometryFilterData->getGeometryFilterType () == GeometryFilterData::GEOMETRY_FILTER_TYPE_BLEND_SHAPE )
            {
                BlendShapeData* blendShapeData = ( BlendShapeData* ) geometryFilterData;
                MayaDM::BlendShape* blendShape = blendShapeData->getBlendShape ();

                // Get the morph targets.
                const UniqueIdVec* morphTargets = findMorphTargets ( controllerId );
                if ( morphTargets != 0 )
                {
                    for ( size_t targetIndex=0; targetIndex<morphTargets->size (); ++targetIndex )
                    {
                        // The target can be a mesh or a skin controller.
                        const COLLADAFW::UniqueId& targetId = (*morphTargets)[targetIndex];

                        // Get the mesh target.
                        GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();
                        MayaDM::Mesh* mesh = geometryImporter->findMayaDMMeshNode ( targetId );
                        if ( mesh == 0 )
                        {
                            std::cerr << "No mesh object for the current morph target!" << std::endl;
                            continue;
                        }

                        // TODO Get the weight and calculate the input target index.
                        double weight = 1;
                        size_t inputTargetItemIndex = (size_t)(weight * 1000 + 5000);

                        // Make the connection.
                        connectAttr ( file, mesh->getWorldMesh (), blendShape->getInputGeomTarget ( 0, targetIndex, inputTargetItemIndex ) );
                    }
                }
            }
            
            ++it;
        }
    }

    // --------------------------------------------
    void ControllerImporter::connectControllers ()
    {
        // Get a pointer to the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        std::map<COLLADAFW::UniqueId, GeometryFilterData*>::const_iterator it = mGeometryFilterDataMap.begin ();
        while ( it != mGeometryFilterDataMap.end () )
        {
            const GeometryFilterData* geometryFilterData = it->second;

            // connectAttr "skinCluster1GroupParts.outputGeometry" "skinCluster1.input[0].inputGeometry";
            const MayaDM::GroupParts& groupParts1 = geometryFilterData->getGeometryFilterGroupParts ();
            const MayaDM::GeometryFilter* geometryFilter = geometryFilterData->getGeometryFilter ();
            connectAttr ( file, groupParts1.getOutputGeometry (), geometryFilter->getInputGeometry (0) );

            // connectAttr "skinCluster1GroupId.groupId" "skinCluster1.input[0].groupId";
            const MayaDM::GroupId& skinClusterGroupId = geometryFilterData->getGeometryFilterGroupId ();
            connectAttr ( file, skinClusterGroupId.getGroupId (), geometryFilter->getGroupId (0) );

            // connectAttr "groupParts2.outputGeometry" "tweak1.input[0].inputGeometry";
            const MayaDM::GroupParts& groupParts2 = geometryFilterData->getTweakGroupParts ();
            const MayaDM::Tweak& tweak = geometryFilterData->getTweak ();
            connectAttr ( file, groupParts2.getOutputGeometry (), tweak.getInputGeometry (0) );

            // connectAttr "groupId2.groupId" "tweak1.input[0].groupId";
            const MayaDM::GroupId& groupId2 = geometryFilterData->getTweakGroupId ();
            connectAttr ( file, groupId2.getGroupId (), tweak.getGroupId (0) );

            // connectAttr "skinCluster1GroupId.message" "skinCluster1Set.groupNodes" -nextAvailable;
            const MayaDM::ObjectSet& geometryFilterSet = geometryFilterData->getGeometryFilterSet ();
            connectNextAttr ( file, skinClusterGroupId.getMessage (), geometryFilterSet.getGroupNodes () );

            // connectAttr "skinCluster1.message" "skinCluster1Set.usedBy[0]";
            connectAttr ( file, geometryFilter->getMessage (), geometryFilterSet.getUsedBy (0) );

            // connectAttr "tweak1.outputGeometry[0]" "skinCluster1GroupParts.inputGeometry";
            connectAttr ( file, tweak.getOutputGeometry (0), groupParts1.getInputGeometry () );

            // connectAttr "skinCluster1GroupId.groupId" "skinCluster1GroupParts.groupId";
            connectAttr ( file, skinClusterGroupId.getGroupId (), groupParts1.getGroupId () );

            // connectAttr "groupId2.message" "tweakSet1.groupNodes" -nextAvailable;
            const MayaDM::ObjectSet& tweakSet = geometryFilterData->getTweakSet ();
            connectNextAttr ( file, groupId2.getMessage (), tweakSet.getGroupNodes () );

            // connectAttr "tweak1.message" "tweakSet1.usedBy[0]";
            connectAttr ( file, tweak.getMessage (), tweakSet.getUsedBy (0) );

            // connectAttr "groupId2.groupId" "groupParts2.groupId";
            connectAttr ( file, groupId2.getGroupId (), groupParts2.getGroupId () );

            ++it;
        }
    }

} // namespace DAE2MA
