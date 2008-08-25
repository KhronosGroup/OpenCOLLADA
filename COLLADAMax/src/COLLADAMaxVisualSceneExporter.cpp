/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"

#include "COLLADANode.h"
#include "COLLADAInstanceGeometry.h"
#include "COLLADAInstanceController.h"
#include "COLLADAInstanceCamera.h"
#include "COLLADAMathUtils.h"
#include "COLLADAURI.h"


#include "COLLADAMaxVisualSceneExporter.h"
#include "COLLADAMaxExportSceneGraph.h"
#include "COLLADAMaxGeometryExporter.h"
#include "COLLADAMaxMaterialExporter.h"
#include "COLLADAMaxAnimationExporter.h"
#include "COLLADAMaxCameraExporter.h"
#include "COLLADAMaxDocumentExporter.h"

#include <decomp.h>

namespace COLLADAMax
{


    const String VisualSceneExporter::NODE_ID_PRAEFIX = "node-";

	const String VisualSceneExporter::MATRIX_SID = "matrix";
    const String VisualSceneExporter::TRANSLATE_SID = "translation";
    const String VisualSceneExporter::ROTATE_SID = "rotation";
    const String VisualSceneExporter::ROTATE_X_SID = "rotationX";
    const String VisualSceneExporter::ROTATE_Y_SID = "rotationY";
    const String VisualSceneExporter::ROTATE_Z_SID = "rotationZ";
    const String VisualSceneExporter::ROTATE_SCALE_AXIS_SID = "ScaleAxisRotation";
    const String VisualSceneExporter::ROTATE_SCALE_AXIS_INVERSE_SID = "InverseScaleAxisRotation";
    const String VisualSceneExporter::SCALE_SID = "scale";


	const String VisualSceneExporter::MATRIX_PARAMETERS[ 1 ] =
	{"TRANSFORM"
	};

	
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
		if ( !exportNode->getIsInVisualScene() )
			return;

        COLLADA::Node colladaNode ( mSW );

        INode *node = exportNode->getINode();

        colladaNode.setNodeId ( getNodeId(*exportNode) );

		if ( exportNode->hasSid() )
			colladaNode.setNodeSid(exportNode->getSid());

        colladaNode.setNodeName ( COLLADA::Utils::checkNCName ( node->GetName() ) );

		if ( exportNode->getIsJoint() )
		{
			colladaNode.setType( COLLADA::Node::JOINT );
		}

        colladaNode.start();

        exportTransformations ( exportNode, colladaNode );

        if ( exportNode->getType() == ExportNode::MESH )
        {
			if ( exportNode->hasControllers() )
			{
				COLLADA::InstanceController instanceController ( mSW );
				ExportNodeSet referencedJoints = exportNode->getControllerList()->getReferencedJoints();
				
				for ( ExportNodeSet::const_iterator it = referencedJoints.begin(); it!=referencedJoints.end(); ++it)
					instanceController.addSkeleton('#' + getNodeId(**it));
				
				instanceController.setUrl ( "#" + exportNode->getLastControllerId() );
				fillInstanceMaterialList(instanceController.getBindMaterial().getInstanceMaterialList(), exportNode);
				instanceController.add();

			}
			else
			{
				COLLADA::InstanceGeometry instanceGeometry ( mSW );
				instanceGeometry.setUrl ( "#" + GeometriesExporter::getGeometryId(*exportNode) );
				fillInstanceMaterialList(instanceGeometry.getBindMaterial().getInstanceMaterialList(), exportNode);
				instanceGeometry.add();
			}
        } 
		else if ( exportNode->getType() == ExportNode::CAMERA )
		{
			COLLADA::InstanceCamera instanceCamera(mSW, "#" + CameraExporter::getCameraId(*exportNode));
			instanceCamera.add();
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
        const String & fullNodeId = getNodeId(*exportNode);

        INode * iNode = exportNode->getINode();

        INode *parent = iNode->GetParentNode();

		//Matrix3 transformationMatrix = iNode->GetObjectTM ( 0 );
		Matrix3 transformationMatrix = iNode->GetNodeTM ( 0 );

        if ( parent != NULL && !parent->IsRootNode() )
        {
            //transformationMatrix *= Inverse(parent->GetNodeTM(0));
            transformationMatrix *= Inverse ( parent->GetObjectTM ( 0 ) );
        }

        Control* transformationController = iNode->GetTMController();

        AnimationExporter * animationExporter = mDocumentExporter->getAnimationExporter();

		if ( mDocumentExporter->getOptions().getBakeMatrices() || AnimationExporter::forceSampleMatrices(iNode))
        {
            double matrix[ 4 ][ 4 ] ;
            matrix3ToDouble4x4 ( matrix, transformationMatrix );
			/// @TODO check if matrix is animated
            colladaNode.addMatrix (MATRIX_SID, matrix );
			animationExporter->addAnimatedFloat4x4 ( iNode, fullNodeId, MATRIX_SID, MATRIX_PARAMETERS );
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

			if ( AnimationExporter::isAnimated(transformationController) )
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
            if ( !AnimationExporter::isAnimated(rotationController) )
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
                rotationController->GetValue ( mDocumentExporter->getOptions().getAnimationStart(), &quaternion, FOREVER, CTRL_ABSOLUTE );
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

			bool hasAnimatedScale = AnimationExporter::isAnimated(scaleController);

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
					if ( hasAnimatedScale )
					{
	                    colladaNode.addRotate ( ROTATE_SCALE_AXIS_INVERSE_SID, rotationAxis.x, rotationAxis.y, rotationAxis.z, -COLLADA::MathUtils::radToDeg ( scaleRotation.angle ) );
						animationExporter->addAnimatedAxisAngle( scaleController, fullNodeId, ROTATE_SCALE_AXIS_INVERSE_SID, ROTATION_PARAMETERS, Animation::SCALE_ROT_AXIS_R );
					}
					else
					{
						colladaNode.addRotate ( rotationAxis.x, rotationAxis.y, rotationAxis.z, -COLLADA::MathUtils::radToDeg ( scaleRotation.angle ) );
					}

                    /// @TODO find a way to handle this problem
                    // Once the animation has been exported, verify that there was, indeed, something animated.
                    /*if (animatedScaleAxis == NULL && Equals(scaleRotation.angle, 0.0f))
                    {
                     SAFE_DELETE(rotation);
                     hasScaleAxis = false;
                    }*/
                }
				
				if ( hasAnimatedScale )
				{
					colladaNode.addScale ( SCALE_SID, affineParts.k.x, affineParts.k.y, affineParts.k.z );
					animationExporter->addAnimatedPoint3( scaleController, fullNodeId, SCALE_SID, TRANSLATION_PARAMETERS );
				}
				else
				{
					colladaNode.addScale ( affineParts.k.x, affineParts.k.y, affineParts.k.z );
				}

                // Rotate back to the rotation basis
                if ( hasScaleAxis )
                {
                    Point3 & rotationAxis = scaleRotation.axis;
					if ( hasAnimatedScale )
					{
		                colladaNode.addRotate ( ROTATE_SCALE_AXIS_SID, rotationAxis.x, rotationAxis.y, rotationAxis.z, COLLADA::MathUtils::radToDeg ( scaleRotation.angle ) );
						animationExporter->addAnimatedAxisAngle( scaleController, fullNodeId, ROTATE_SCALE_AXIS_SID, ROTATION_PARAMETERS, Animation::SCALE_ROT_AXIS );
					}
					else
					{
						colladaNode.addRotate ( rotationAxis.x, rotationAxis.y, rotationAxis.z, COLLADA::MathUtils::radToDeg ( scaleRotation.angle ) );
					}
                }
            }
        }

		if ( !iNode->IsRootNode() )
		{
			// Calculate the pivot transform. It should already be in local space.
			Matrix3 objectOffsetTransformationMatrix(1); 
			calculateObjectOffsetTransformation(iNode, objectOffsetTransformationMatrix);

			// only export the pivot node if the transform is not an identity
			// or if the node is a group head node (this is a temporary fix until we add a PIVOT type)
			if ( !objectOffsetTransformationMatrix.IsIdentity() || iNode->IsGroupHead() )
			{
				double matrix[ 4 ][ 4 ] ;
				matrix3ToDouble4x4 ( matrix, objectOffsetTransformationMatrix );
				colladaNode.addMatrix ( matrix );
			}
		}
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::matrix3ToDouble4x4 ( double copy[][ 4 ], const Matrix3 & original )
    {
        copy[ 0 ][ 0 ] = original[ 0 ][ 0 ];
        copy[ 1 ][ 0 ] = original[ 0 ][ 1 ];
        copy[ 2 ][ 0 ] = original[ 0 ][ 2 ];
        copy[ 3 ][ 0 ] = 0;
        copy[ 0 ][ 1 ] = original[ 1 ][ 0 ];
        copy[ 1 ][ 1 ] = original[ 1 ][ 1 ];
        copy[ 2 ][ 1 ] = original[ 1 ][ 2 ];
        copy[ 3 ][ 1 ] = 0;
		copy[ 0 ][ 2 ] = original[ 2 ][ 0 ];
        copy[ 1 ][ 2 ] = original[ 2 ][ 1 ];
        copy[ 2 ][ 2 ] = original[ 2 ][ 2 ];
        copy[ 3 ][ 2 ] = 0;
        copy[ 0 ][ 3 ] = original[ 3 ][ 0 ];
        copy[ 1 ][ 3 ] = original[ 3 ][ 1 ];
        copy[ 2 ][ 3 ] = original[ 3 ][ 2 ];
        copy[ 3 ][ 3 ] = 1;

    }

	//---------------------------------------------------------------
	void VisualSceneExporter::calculateObjectOffsetTransformation(INode* maxNode, Matrix3& tm)
	{

		// When sampling matrices, we apply the sample the ObjTMAfterWSM
		// to get the final 
/*		if (OPTS->BakeMatrices())
		{
			IDerivedObject* derivedObj = maxNode->GetWSMDerivedObject();
			if (derivedObj != NULL)
			{
				// If we have WSM attached, always export a pivot
				TimeValue t = OPTS->AnimStart();
				tm = maxNode->GetObjTMAfterWSM(t) * Inverse(maxNode->GetNodeTM(t));
				return;
			}
		}
*/
		Point3 objectOffsetPosition = maxNode->GetObjOffsetPos();
		Quat objectOffsetRotation = maxNode->GetObjOffsetRot();
		ScaleValue objectOffsetScale = maxNode->GetObjOffsetScale();

		// this should already be in local space
		// only do this if necessary to preserve identity tags
		ApplyScaling(tm, objectOffsetScale);
		RotateMatrix(tm, objectOffsetRotation);
		tm.Translate(objectOffsetPosition);

		tm.ValidateFlags();
	}

	//---------------------------------------------------------------
	String VisualSceneExporter::getNodeId( const ExportNode& exportNode )
	{
		return NODE_ID_PRAEFIX + exportNode.getId();
	}


	//---------------------------------------------------------------
	void COLLADAMax::VisualSceneExporter::fillInstanceMaterialList( COLLADA::InstanceMaterialList & instanceMaterialList, ExportNode * exportNode )
	{
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

	}



}
