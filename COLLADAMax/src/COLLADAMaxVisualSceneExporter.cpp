/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#include "ColladaMaxStableHeaders.h"

#include "COLLADANode.h"
#include "COLLADAInstanceGeometry.h"
#include "COLLADAMathUtils.h"


#include "COLLADAMaxVisualSceneExporter.h"
#include "COLLADAMaxExportSceneGraph.h"
#include "COLLADAMaxGeometryExporter.h"
#include "COLLADAMaxMaterialExporter.h"
#include "COLLADAMaxAnimationExporter.h"

#include <decomp.h>

namespace COLLADAMax
{


    const String VisualSceneExporter::NODE_ID_PRAEFIX = "node-";

    const String VisualSceneExporter::TRANSLATE_SID = "translation";
    const String VisualSceneExporter::ROTATE_SID = "rotation";
    const String VisualSceneExporter::ROTATE_X_SID = "rotationX";
    const String VisualSceneExporter::ROTATE_Y_SID = "rotationY";
    const String VisualSceneExporter::ROTATE_Z_SID = "rotationZ";
    const String VisualSceneExporter::ROTATE_SCALE_AXIS_SID = "ScaleAxisRotation";
    const String VisualSceneExporter::ROTATE_SCALE_AXIS_INVERSE_SID = "InverseScaleAxisRotation";
    const String VisualSceneExporter::SCALE_SID = "scale";


    const String VisualSceneExporter::TRANSLATION_PARAMETERS[ 3 ] =
        {"X", "Y", "Z"
        };

    const String VisualSceneExporter::ROTATION_PARAMETER[ 1 ] =
        {"ANGLE"
        };

    const String VisualSceneExporter::ROTATION_PARAMETERS[ 4 ] =
        {"X", "Y", "Z", "ANGLE"
        };


    //---------------------------------------------------------------
    VisualSceneExporter::VisualSceneExporter ( COLLADA::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, const String & sceneId, DocumentExporter * documentExporter )
            : COLLADA::LibraryVisualScenes ( streamWriter ),
            mExportSceneGraph ( exportSceneGraph ),
            mEffectMap ( documentExporter->getEffectExporter() ->getEffectMap() ),
            mVisualSceneId ( sceneId ),
            mDocumentExporter ( documentExporter )
    {}

    //---------------------------------------------------------------
    void VisualSceneExporter::doExport()
    {
        openVisualScene ( mVisualSceneId );
        doExport ( mExportSceneGraph->getRootExportNode() );
        closeLibrary();
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::doExport ( ExportNode* exportNode )
    {

        COLLADA::Node colladaNode ( mSW );

        INode *node = exportNode->getINode();

        colladaNode.setId ( NODE_ID_PRAEFIX + exportNode->getId() );
        colladaNode.setNodeName ( COLLADA::Utils::checkNCName ( node->GetName() ) );

        colladaNode.start();

        exportTransformations ( exportNode, colladaNode );

        if ( exportNode->getType() == ExportNode::MESH )
        {
            // 13.05.08 SL: This is neccessary, too. See example Messerschmidt for node "Spot01.Target"
            Object * object = exportNode->getINode() ->EvalWorldState ( 0 ).obj;

            if ( object )
            {
                if ( object->CanConvertToType ( Class_ID ( TRIOBJ_CLASS_ID, 0 ) ) )
                {
                    COLLADA::InstanceGeometry instanceGeometry ( mSW );
                    instanceGeometry.setUrl ( "#" + COLLADA::LibraryGeometries::GEOMETRY_ID_PRAEFIX + exportNode->getId() );

                    COLLADA::InstanceMaterialList & instanceMaterialList = instanceGeometry.getBindMaterial().getInstanceMaterialList();
                    const ExportNode::MeshSymbolMap & symbolMap = exportNode->getMeshSymbolMap();

                    if ( symbolMap.empty() )
                    {
                        String materialId = MaterialExporter::getMaterialIdFromEffectId ( EffectExporter::getEffectId ( exportNode->getWireFrameColor() ) );
                        //String materialSymbol = symbolIt->first;
                        const String & materialSymbol = GeometryExporter::COLOR_MATERIAL_SYMBOL;
                        instanceMaterialList.push_back ( COLLADA::InstanceMaterial ( materialSymbol, "#" + materialId ) );
                    }

                    else
                    {
                        ExportNode::MeshSymbolMap::const_iterator symbolIt = symbolMap.begin();

                        for ( ; symbolIt != symbolMap.end(); ++symbolIt )
                        {
                            ExportNode::Symbol symbol = symbolIt->second;

                            if ( symbol.used )
                            {
                                Mtl * material = symbolIt->first;
                                EffectMap::const_iterator it = mEffectMap.find ( material );
                                assert ( it != mEffectMap.end() );
                                String materialId = MaterialExporter::getMaterialIdFromEffectId ( it->second );
                                //String materialSymbol = symbolIt->first;
                                instanceMaterialList.push_back ( COLLADA::InstanceMaterial ( symbol.name, "#" + materialId ) );
                            }
                        }
                    }

                    instanceGeometry.add();
                }
            }
        }

        //export the child nodes
        size_t numberOfChildren = exportNode->getNumberOfChildren();

        for ( size_t i = 0; i < numberOfChildren; ++i )
            doExport ( exportNode->getChild ( i ) );

        colladaNode.end();
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportTransformations ( ExportNode * exportNode, const COLLADA::Node & colladaNode )
    {
        const String & fullNodeId = NODE_ID_PRAEFIX + exportNode->getId();

        INode * iNode = exportNode->getINode();

        INode *parent = iNode->GetParentNode();

        Matrix3 transformationMatrix = iNode->GetObjectTM ( 0 );

        if ( parent != NULL && !parent->IsRootNode() )
        {
            //transformationMatrix *= Inverse(parent->GetNodeTM(0));
            transformationMatrix *= Inverse ( parent->GetObjectTM ( 0 ) );
        }

        Control* transformationController = iNode->GetTMController();

        AnimationExporter * animationExporter = mDocumentExporter->getAnimationExporter();

        if ( mDocumentExporter->getOptions().bakeMatrices() )
        {
            /// @TODO implement export of baked matrices
            double matrix[ 4 ][ 4 ] ;
            Matrix3ToDouble4x4 ( matrix, transformationMatrix );
            colladaNode.addMatrix ( matrix );
        }

        else
        {
            // Decompose the transform
            AffineParts affineParts;
            decomp_affine ( transformationMatrix, &affineParts );
            affineParts.k *= affineParts.f;
            affineParts.f = 1.0f;

            // Translation
            Control * translationController = ( transformationController ) ? transformationController->GetPositionController() : 0 ;

            if ( transformationController && translationController->IsAnimated() )
            {
                colladaNode.addTranslate ( TRANSLATE_SID, affineParts.t.x, affineParts.t.y, affineParts.t.z );
                animationExporter->addAnimatedPoint3 ( translationController, fullNodeId, TRANSLATE_SID, TRANSLATION_PARAMETERS );
            }

            else
                if ( !affineParts.t.Equals ( Point3::Origin, TOLERANCE ) )
                    colladaNode.addTranslate ( affineParts.t.x, affineParts.t.y, affineParts.t.z );

            // Rotation

            // first try with the Rotation controller
            Control * rotationController = ( transformationController ) ? transformationController->GetRotationController() : 0;

            ///@TODO: add controller
            //  exportNode->setRotationController(rotationController);
            if ( !rotationController || !rotationController->IsAnimated() )
            {
                // Save as axis-angle rotation.
                Matrix3 rotationMatrix;
                affineParts.q.MakeMatrix ( rotationMatrix );

                AngAxis angleAxisRotation = AngAxis ( rotationMatrix );

                if ( !angleAxisRotation.axis.Equals ( Point3::Origin ) && !COLLADA::MathUtils::equalsZero ( angleAxisRotation.angle ) )
                {
                    Point3 & rotationAxis = angleAxisRotation.axis;
                    colladaNode.addRotate ( rotationAxis.x, rotationAxis.y, rotationAxis.z, -COLLADA::MathUtils::radToDeg ( angleAxisRotation.angle ) );
                }
            }

            else
            {
                float eulerAngles[ 3 ];
                Quat quaternion;
                rotationController->GetValue ( mDocumentExporter->getOptions().animationStart(), &quaternion, FOREVER, CTRL_ABSOLUTE );
                QuatToEuler ( quaternion, eulerAngles, EULERTYPE_XYZ );

                // Export XYZ euler rotation in Z Y X order in the file
                colladaNode.addRotateZ ( ROTATE_Z_SID, COLLADA::MathUtils::radToDeg ( eulerAngles[ 2 ] ) );
                animationExporter->addAnimatedAngle ( rotationController, fullNodeId, ROTATE_Z_SID, ROTATION_PARAMETER, Animation::ROTATION_Z );

                colladaNode.addRotateY ( ROTATE_Y_SID, COLLADA::MathUtils::radToDeg ( eulerAngles[ 1 ] ) );
                animationExporter->addAnimatedAngle ( rotationController, fullNodeId, ROTATE_Y_SID, ROTATION_PARAMETER, Animation::ROTATION_Y );

                colladaNode.addRotateX ( ROTATE_X_SID, COLLADA::MathUtils::radToDeg ( eulerAngles[ 0 ] ) );
                animationExporter->addAnimatedAngle ( rotationController, fullNodeId, ROTATE_X_SID, ROTATION_PARAMETER, Animation::ROTATION_X );
            }

            //Scaling

            // Check for animated scale. If not animated and equal to the identity, don't export.
            // Animated scale includes animated scale axis, so export that carefully.
            Control* scaleController = transformationController ? transformationController->GetScaleController() : 0;

            bool hasAnimatedScale = scaleController && scaleController->IsAnimated();

            if ( hasAnimatedScale || !affineParts.k.Equals ( Point3 ( 1.0f, 1.0f, 1.0f ), TOLERANCE ) )
            {
                AngAxis scaleRotation ( affineParts.u );

                // Rotate to match the scale axis
                bool hasScaleAxis = hasAnimatedScale ||
                                    !scaleRotation.axis.Equals ( Point3::Origin, TOLERANCE ) ||
                                    ! ( COLLADA::MathUtils::equalsZero ( scaleRotation.angle ) ) ||
                                    ! ( COLLADA::MathUtils::equals3 ( affineParts.k.x, affineParts.k.y, affineParts.k.z ) );

                if ( hasScaleAxis )
                {
                    Point3 & rotationAxis = scaleRotation.axis;
                    colladaNode.addRotate ( ROTATE_SCALE_AXIS_INVERSE_SID, rotationAxis.x, rotationAxis.y, rotationAxis.z, -COLLADA::MathUtils::radToDeg ( scaleRotation.angle ) );

                    /// @TODO find a way to handle this problem
                    // Once the animation has been exported, verify that there was, indeed, something animated.
                    /*if (animatedScaleAxis == NULL && Equals(scaleRotation.angle, 0.0f))
                    {
                     SAFE_DELETE(rotation);
                     hasScaleAxis = false;
                    }*/
                }

                colladaNode.addScale ( SCALE_SID, affineParts.k.x, affineParts.k.y, affineParts.k.z );

                // Rotate back to the rotation basis

                if ( hasScaleAxis )
                {
                    Point3 & rotationAxis = scaleRotation.axis;
                    colladaNode.addRotate ( ROTATE_SCALE_AXIS_SID, rotationAxis.x, rotationAxis.y, rotationAxis.z, COLLADA::MathUtils::radToDeg ( scaleRotation.angle ) );
                }
            }
        }
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::Matrix3ToDouble4x4 ( double copy[][ 4 ], const Matrix3 & original )
    {
        copy[ 0 ][ 0 ] = original[ 0 ][ 0 ];
        copy[ 1 ][ 0 ] = original[ 0 ][ 1 ];
        copy[ 2 ][ 0 ] = original[ 0 ][ 2 ];
        copy[ 3 ][ 0 ] = 0;
        copy[ 0 ][ 1 ] = original[ 1 ][ 0 ];
        copy[ 1 ][ 1 ] = original[ 1 ][ 1 ];
        copy[ 2 ][ 1 ] = original[ 1 ][ 2 ];
        copy[ 3 ][ 1 ] = 0,
                         copy[ 0 ][ 2 ] = original[ 2 ][ 0 ];
        copy[ 1 ][ 2 ] = original[ 2 ][ 1 ];
        copy[ 2 ][ 2 ] = original[ 2 ][ 2 ];
        copy[ 3 ][ 2 ] = 0;
        copy[ 0 ][ 3 ] = original[ 3 ][ 0 ];
        copy[ 1 ][ 3 ] = original[ 3 ][ 1 ];
        copy[ 2 ][ 3 ] = original[ 3 ][ 2 ];
        copy[ 3 ][ 3 ] = 1;

    }

}
