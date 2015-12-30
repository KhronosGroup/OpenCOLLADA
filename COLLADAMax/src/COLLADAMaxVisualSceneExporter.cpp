/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAMaxStableHeaders.h"

#include "COLLADASWNode.h"
#include "COLLADASWInstanceGeometry.h"
#include "COLLADASWInstanceController.h"
#include "COLLADASWInstanceCamera.h"
#include "COLLADASWInstanceLight.h"
#include "COLLADASWInstanceNode.h"
#include "COLLADASWInputList.h"

#include "Math/COLLADABUMathUtils.h"

#include "COLLADAMaxVisualSceneExporter.h"
#include "COLLADAMaxExportSceneGraph.h"
#include "COLLADAMaxGeometryExporter.h"
#include "COLLADAMaxMaterialExporter.h"
#include "COLLADAMaxAnimationExporter.h"
#include "COLLADAMaxCameraExporter.h"
#include "COLLADAMaxLightExporter.h"
#include "COLLADAMaxControllerExporter.h"
#include "COLLADAMaxDocumentExporter.h"

#include <decomp.h>
#include <iInstanceMgr.h>

#include <ILayerControl.h>

namespace COLLADAMax
{


	const String VisualSceneExporter::NODE_ID_PRAEFIX = "node-";
    const String VisualSceneExporter::XREF_NODE_NAME = "XRefs";

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
	VisualSceneExporter::VisualSceneExporter( COLLADASW::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, const String & sceneId, DocumentExporter * documentExporter )
		: COLLADASW::LibraryVisualScenes( streamWriter ),
		mExportSceneGraph ( exportSceneGraph ),
		mEffectMap ( documentExporter->getEffectExporter()->getEffectMap() ),
		mVisualSceneId ( sceneId ),
		mDocumentExporter ( documentExporter )
	{}

	//---------------------------------------------------------------
	void VisualSceneExporter::doExport()
	{
		openVisualScene( mVisualSceneId );
		exportEnvironmentAmbientLightNode();
		doExport( mExportSceneGraph->getRootExportNode());
		closeLibrary();
	}

	//---------------------------------------------------------------
	void VisualSceneExporter::exportEnvironmentAmbientLightNode()
	{
		COLLADASW::Node colladaNode( mSW );
		colladaNode.setNodeName( LightExporter::ENVIRONMENT_AMBIENT_LIGHT_NAME );
		colladaNode.start();

		COLLADASW::InstanceLight instanceLight(mSW, "#" + LightExporter::ENVIRONMENT_AMBIENT_LIGHT_ID );
		instanceLight.add();

		colladaNode.end();
	}

	//---------------------------------------------------------------
	void VisualSceneExporter::doExport ( ExportNode* exportNode )
	{
		if ( !exportNode->getIsInVisualScene() )
			return;

		INode *node = exportNode->getINode();

		// if true, we do not write a COLLADA node for this max node
		bool exportOnlyChilds = node->IsRootNode() != 0;

		COLLADASW::Node colladaNode( mSW );

		if ( !exportOnlyChilds )
		{
			colladaNode.setNodeId( getNodeId(*exportNode) );

			if ( exportNode->hasSid() )
				colladaNode.setNodeSid(exportNode->getSid());

			colladaNode.setNodeName( COLLADASW::Utils::checkNCName( NativeString(node->GetName()) ) );

			if ( exportNode->getIsJoint() )
			{
				colladaNode.setType( COLLADASW::Node::JOINT );
			}

			colladaNode.start();

			exportTransformations ( exportNode, colladaNode);

			ExportNode::Type nodeType = exportNode->getType();


			COLLADASW::Node colladaPivotNode ( mSW );

			bool hasPivotNode = !node->IsRootNode();

			if ( hasPivotNode )
			{
				hasPivotNode = !( (nodeType == ExportNode::BONE) || (nodeType == ExportNode::HELPER) );
			}

			if ( hasPivotNode )
			{
				hasPivotNode = !node->IsGroupHead();
			}

			if ( hasPivotNode )
			{
				Matrix3 objectOffsetTransformationMatrix(true); 

				// Calculate the pivot transform. It should already be in local space.
				calculateObjectOffsetTransformation(node, objectOffsetTransformationMatrix);

				hasPivotNode = !objectOffsetTransformationMatrix.IsIdentity();

				if ( hasPivotNode )
				{
					//open the pivot node and pivot transformation matrix
					colladaPivotNode.start();
					double matrix[ 4 ][ 4 ] ;
					matrix3ToDouble4x4 ( matrix, objectOffsetTransformationMatrix );
					colladaNode.addMatrix ( matrix );
				}
			}


			if ( exportNode->getType() == ExportNode::MESH )
			{
				if ( exportNode->hasControllers() )
				{
					COLLADASW::InstanceController instanceController ( mSW );
					ExportNodeSet referencedJoints = exportNode->getControllerList()->getReferencedJoints();

					for ( ExportNodeSet::const_iterator it = referencedJoints.begin(); it!=referencedJoints.end(); ++it)
						instanceController.addSkeleton('#' + getNodeId(**it));

					String controllerId = mDocumentExporter->getExportedObjectExportNode(ObjectIdentifier(exportNode->getLastController()->getDerivedObject(), 0))->getLastControllerId();
					assert( !controllerId.empty() );

					instanceController.setUrl ( "#" + controllerId );
					//				instanceController.setUrl ( "#" + exportNode->getLastControllerId() );
					fillInstanceMaterialList(instanceController.getBindMaterial().getInstanceMaterialList(), exportNode);
					instanceController.add();
				}
				else
				{
					COLLADASW::InstanceGeometry instanceGeometry ( mSW );

					String geometryId = GeometriesExporter::getGeometryId(*mDocumentExporter->getExportedObjectExportNode(ObjectIdentifier(exportNode->getInitialPose())));
					assert( !geometryId.empty() );

					instanceGeometry.setUrl ( "#" + geometryId );
					fillInstanceMaterialList(instanceGeometry.getBindMaterial().getInstanceMaterialList(), exportNode);
					instanceGeometry.add();
				}
			} 
			if ( exportNode->getType() == ExportNode::SPLINE )
			{
				COLLADASW::InstanceGeometry instanceGeometry ( mSW );

				String geometryId = GeometriesExporter::getGeometryId(*mDocumentExporter->getExportedObjectExportNode(ObjectIdentifier(exportNode->getInitialPose())));
				assert( !geometryId.empty() );

				instanceGeometry.setUrl ( "#" + geometryId );
				instanceGeometry.add();
			} 
			else if ( exportNode->getType() == ExportNode::CAMERA )
			{
				String cameraId = CameraExporter::getCameraId(*mDocumentExporter->getExportedObjectExportNode(ObjectIdentifier(exportNode->getCamera())));
				assert( !cameraId.empty() );

				COLLADASW::InstanceCamera instanceCamera(mSW, "#" + cameraId);
				//			COLLADASW::InstanceCamera instanceCamera(mSW, "#" + CameraExporter::getCameraId(*exportNode));
				instanceCamera.add();
			}
			else if ( exportNode->getType() == ExportNode::LIGHT )
			{
				String lightId = LightExporter::getLightId(*mDocumentExporter->getExportedObjectExportNode(ObjectIdentifier(exportNode->getLight())));
				assert( !lightId.empty() );

				COLLADASW::InstanceLight instanceLight(mSW, "#" + lightId);
				instanceLight.add();
			}

			if ( hasPivotNode )
			{
				//close the pivot node 
				colladaPivotNode.end();
			}
        }

        //export instance nodes for XRef scenes attached to current INode
        const ExportSceneGraph::XRefSceneGraphList* xRefScenes = xRefScenes = mExportSceneGraph->getXRefSceneGraphList(node);

		if ( xRefScenes != NULL )
		{
            //add new node if we do not have one yet
            if (exportOnlyChilds)
            {
                colladaNode.setNodeName(XREF_NODE_NAME);
                colladaNode.start();
            }

			for ( ExportSceneGraph::XRefSceneGraphList::const_iterator it = xRefScenes->begin(); it != xRefScenes->end(); ++it)
			{
				COLLADASW::URI target = mDocumentExporter->getXRefOutputURI(*it);
				target.setFragment(getNodeId( *(it->exportSceneGraph->getRootExportNode()) ) );

				COLLADASW::InstanceNode instanceNode(mSW, target);
				instanceNode.add();
			}

            //close new node if we've opened it before
            if (exportOnlyChilds)
            {
                colladaNode.end();
            }
		}

		//export the child nodes
		size_t numberOfChildren = exportNode->getNumberOfChildren();

		for ( size_t i = 0; i < numberOfChildren; ++i )
			doExport ( exportNode->getChild ( i ) );

		if ( !exportOnlyChilds )
		{
			colladaNode.addExtraTechniqueParameter(Extra::TECHNIQUE_PROFILE_OPENCOLLADA, Extra::CAST_SHADOWS_PROPERTY, exportNode->getCastShadows());
			colladaNode.addExtraTechniqueParameter(Extra::TECHNIQUE_PROFILE_OPENCOLLADA, Extra::RECEIVE_SHADOWS_PROPERTY, exportNode->getReceiveShadows());

			if (INode* node = exportNode->getINode()) {
				colladaNode.addExtraTechniqueParameter(Extra::TECHNIQUE_PROFILE_OPENCOLLADA, Extra::PRIMARY_VISIBILITY_PROPERTY, node->GetPrimaryVisibility());
				colladaNode.addExtraTechniqueParameter(Extra::TECHNIQUE_PROFILE_OPENCOLLADA, Extra::SECONDARY_VISIBILITY_PROPERTY, node->GetSecondaryVisibility());
			}

			if ( mDocumentExporter->getOptions().getExportUserDefinedProperties() )
			{
				// export user defined data stored for the max node
#ifdef MAX_9_OR_NEWER
				MSTR userPropertiesBuffer;
#else
				TSTR userPropertiesBuffer;
#endif
				node->GetUserPropBuffer(userPropertiesBuffer);
				if ( !userPropertiesBuffer.isNull() )
				{
					String xmlEncodedUserData = Utils::translateToXML(NativeString(userPropertiesBuffer.data()).toUtf8String());
					colladaNode.addExtraTechniqueParameter(Extra::TECHNIQUE_PROFILE_OPENCOLLADA, Extra::USERDEFINED_PROPERTIES, xmlEncodedUserData);
				}
			}
			colladaNode.end();
		}
	}

	//---------------------------------------------------------------
	void VisualSceneExporter::exportTransformations ( ExportNode * exportNode, const COLLADASW::Node & colladaNode )
	{
		const String & fullNodeId = getNodeId(*exportNode);

		INode * iNode = exportNode->getINode();

		INode *parent = iNode->GetParentNode();

		ExportNode::Type nodeType = exportNode->getType();

		bool exportObjectOffsetMatrix = !( (nodeType == ExportNode::BONE) || (nodeType == ExportNode::HELPER) );

#if 0
		// Add the inverse of the parents object transformation matrix, if its not  identity
		if ( !objectOffsetTransformationMatrix.IsIdentity() )
		{
			Matrix3 inverseObjectOffsetTransformationMatrix(objectOffsetTransformationMatrix);
			inverseObjectOffsetTransformationMatrix.Invert();
			double matrix[ 4 ][ 4 ] ;
			matrix3ToDouble4x4 ( matrix, inverseObjectOffsetTransformationMatrix );
			if ( exportObjectOffsetMatrix )
				colladaNode.addMatrix ( matrix );
		}

#endif

		//Matrix3 transformationMatrix = iNode->GetObjectTM ( 0 );
		Matrix3 transformationMatrix = getWorldTransform( iNode );

		if ( parent && !parent->IsRootNode() )
		{
			//transformationMatrix *= Inverse(parent->GetNodeTM(0));
			transformationMatrix *= Inverse ( getWorldTransform(parent) );
		}

		if ( !applyFirstInstanceTransform(transformationMatrix, iNode) )
			return;

		Control* transformationController = iNode->GetTMController();

		if ( transformationController )
		{
			SClass_ID sc = transformationController->SuperClassID();
			Class_ID c = transformationController->ClassID();
			int g = 5;
		}

		AnimationExporter * animationExporter = mDocumentExporter->getAnimationExporter();
		const Options& options = mDocumentExporter->getOptions();

		if ( options.getBakeMatrices() || AnimationExporter::forceSampleMatrices(iNode) )
		{
			double matrix[ 4 ][ 4 ] ;
			matrix3ToDouble4x4 ( matrix, transformationMatrix );
			bool animatedMatrix = animationExporter->addAnimatedFloat4x4 ( iNode, fullNodeId, MATRIX_SID, MATRIX_PARAMETERS, true );

			if ( animatedMatrix )
				colladaNode.addMatrix (MATRIX_SID, matrix );
			else
				colladaNode.addMatrix (matrix );
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

			if (!AnimationExporter::isAnimated(translationController)) {
				if (!affineParts.t.Equals(Point3::Origin, TOLERANCE))
					colladaNode.addTranslate(affineParts.t.x, affineParts.t.y, affineParts.t.z);
			}
			else {
				// Animated

				ILayerControl* ilc = GetILayerControlInterface(translationController);
				if (options.getExportLayersAsClips() && ilc != NULL && ilc->GetLayerCount() > 1)
				{
#if defined(MAX_RELEASE_R17) && (MAX_RELEASE >= MAX_RELEASE_R17)

					for (int i = 0; i < ilc->GetLayerCount(); ++i) {
						// Export layers as named animations
						NativeString layerName(i == 0 ? L"" : ilc->GetLayerName(i).data()); // Leave the base layer without a name

						Control* layerControl = ilc->GetSubCtrl(i);
						Point3 translation;
						layerControl->GetValue(mDocumentExporter->getOptions().getAnimationStart(), &translation, FOREVER, CTRL_ABSOLUTE);

						String sidAppend = (i == 0) ? "" : "_" + layerName;

						colladaNode.addTranslate(TRANSLATE_SID + sidAppend, translation.x, translation.y, translation.z);

						animationExporter->addAnimatedPoint3(layerControl, layerName, fullNodeId, TRANSLATE_SID + "_" + layerName, TRANSLATION_PARAMETERS, true);
					}
#endif
				}
				else
				{
					// No layers
					colladaNode.addTranslate(TRANSLATE_SID, affineParts.t.x, affineParts.t.y, affineParts.t.z);
					animationExporter->addAnimatedPoint3(translationController, "", fullNodeId, TRANSLATE_SID, TRANSLATION_PARAMETERS, true);
				}

			}


			// Rotation

			Control * rotationController = (transformationController) ? transformationController->GetRotationController() : 0;

			if ( !AnimationExporter::isAnimated(rotationController) )
			{
				// Save as axis-angle rotation.
				Matrix3 rotationMatrix;
				affineParts.q.MakeMatrix ( rotationMatrix );

				AngAxis angleAxisRotation = AngAxis ( rotationMatrix );

				if ( !angleAxisRotation.axis.Equals ( Point3::Origin ) && !COLLADASW::MathUtils::equalsZero ( angleAxisRotation.angle ) )
				{
					Point3 & rotationAxis = angleAxisRotation.axis;
					colladaNode.addRotate ( rotationAxis.x, rotationAxis.y, rotationAxis.z, -COLLADASW::MathUtils::radToDeg ( angleAxisRotation.angle ) );
				}
			}

			else
			{
				// Animated

				ILayerControl* ilc = GetILayerControlInterface(rotationController);
				if (options.getExportLayersAsClips() && ilc != NULL && ilc->GetLayerCount() > 1)
				{
#if defined(MAX_RELEASE_R17) && (MAX_RELEASE >= MAX_RELEASE_R17)

					for (int i = 0; i < ilc->GetLayerCount(); ++i) {
						// Export layers as named animations
						NativeString layerName(i == 0 ? L"" : ilc->GetLayerName(i).data()); // Leave the base layer without a name

						Control* layerControl = ilc->GetSubCtrl(i);

						float eulerAngles[3];
						Quat quaternion;
						layerControl->GetValue(mDocumentExporter->getOptions().getAnimationStart(), &quaternion, FOREVER, CTRL_ABSOLUTE);
						QuatToEuler(quaternion, eulerAngles, EULERTYPE_XYZ);

						String sidAppend = (i == 0) ? "" : "_" + layerName;

						// Add nodes for the additive animations to target
						colladaNode.addRotateZ(ROTATE_Z_SID + sidAppend, 0);
						colladaNode.addRotateY(ROTATE_Y_SID + sidAppend, 0);
						colladaNode.addRotateX(ROTATE_X_SID + sidAppend, 0);

						animationExporter->addAnimatedAngle(layerControl, layerName, fullNodeId, ROTATE_Z_SID + sidAppend, ROTATION_PARAMETER, Animation::ROTATION_Z, true);
						animationExporter->addAnimatedAngle(layerControl, layerName, fullNodeId, ROTATE_Y_SID + sidAppend, ROTATION_PARAMETER, Animation::ROTATION_Y, true);
						animationExporter->addAnimatedAngle(layerControl, layerName, fullNodeId, ROTATE_X_SID + sidAppend, ROTATION_PARAMETER, Animation::ROTATION_X, true);
					}
#endif
				}
				else
				{

					float eulerAngles[3];
					Quat quaternion;
					rotationController->GetValue(mDocumentExporter->getOptions().getAnimationStart(), &quaternion, FOREVER, CTRL_ABSOLUTE);
					QuatToEuler(quaternion, eulerAngles, EULERTYPE_XYZ);

					// Add the scene nodes
					colladaNode.addRotateZ(ROTATE_Z_SID, COLLADASW::MathUtils::radToDeg(eulerAngles[2]));
					colladaNode.addRotateY(ROTATE_Y_SID, COLLADASW::MathUtils::radToDeg(eulerAngles[1]));
					colladaNode.addRotateX(ROTATE_X_SID, COLLADASW::MathUtils::radToDeg(eulerAngles[0]));

					// Export the entire rotation as a single animation
					animationExporter->addAnimatedAngle(rotationController, "", fullNodeId, ROTATE_Z_SID, ROTATION_PARAMETER, Animation::ROTATION_Z, true);
					animationExporter->addAnimatedAngle(rotationController, "", fullNodeId, ROTATE_Y_SID, ROTATION_PARAMETER, Animation::ROTATION_Y, true);
					animationExporter->addAnimatedAngle(rotationController, "", fullNodeId, ROTATE_X_SID, ROTATION_PARAMETER, Animation::ROTATION_X, true);
				}

			}

			//Scaling

			// Check for animated scale. If not animated and equal to the identity, don't export.
			// Animated scale includes animated scale axis, so export that carefully.
			Control* scaleController = transformationController ? transformationController->GetScaleController() : 0;

			SClass_ID scid = scaleController ? scaleController->SuperClassID() : 0;
			Class_ID cid = scaleController ? scaleController->ClassID() : Class_ID();

			bool hasAnimatedScale = animationExporter->addAnimatedPoint3( scaleController, "", fullNodeId, SCALE_SID, TRANSLATION_PARAMETERS, true );

			if ( hasAnimatedScale || !affineParts.k.Equals ( Point3 ( 1.0f, 1.0f, 1.0f ), TOLERANCE ) )
			{
				AngAxis scaleRotation ( affineParts.u );

				// Rotate to match the scale axis
				bool hasScaleAxis = hasAnimatedScale ||
					!scaleRotation.axis.Equals ( Point3::Origin, TOLERANCE ) ||
					! ( COLLADASW::MathUtils::equalsZero ( scaleRotation.angle ) ) ||
					! ( COLLADASW::MathUtils::equals3 ( affineParts.k.x, affineParts.k.y, affineParts.k.z ) );

				bool hasAnimatedScaleAxis = false;
				if ( hasScaleAxis )
				{
					Point3 & rotationAxis = scaleRotation.axis;

					if ( hasAnimatedScale )
						hasAnimatedScaleAxis = animationExporter->addAnimatedAxisAngle( scaleController, fullNodeId, ROTATE_SCALE_AXIS_INVERSE_SID, ROTATION_PARAMETERS, Animation::SCALE_ROT_AXIS_R, true );

					if ( hasAnimatedScaleAxis )
						colladaNode.addRotate ( ROTATE_SCALE_AXIS_INVERSE_SID, rotationAxis.x, rotationAxis.y, rotationAxis.z, -COLLADASW::MathUtils::radToDeg ( scaleRotation.angle ) );
					else if ( !COLLADABU::Math::Utils::equalsZero(scaleRotation.angle) )
						colladaNode.addRotate ( rotationAxis.x, rotationAxis.y, rotationAxis.z, -COLLADASW::MathUtils::radToDeg ( scaleRotation.angle ) );
				}

				if ( hasAnimatedScale )
					colladaNode.addScale ( SCALE_SID, affineParts.k.x, affineParts.k.y, affineParts.k.z );
				else
					colladaNode.addScale ( affineParts.k.x, affineParts.k.y, affineParts.k.z );

				// Rotate back to the rotation basis
				if ( hasScaleAxis )
				{
					Point3 & rotationAxis = scaleRotation.axis;
					if ( hasAnimatedScaleAxis )
					{
						colladaNode.addRotate ( ROTATE_SCALE_AXIS_SID, rotationAxis.x, rotationAxis.y, rotationAxis.z, COLLADASW::MathUtils::radToDeg ( scaleRotation.angle ) );
						animationExporter->addAnimatedAxisAngle( scaleController, fullNodeId, ROTATE_SCALE_AXIS_SID, ROTATION_PARAMETERS, Animation::SCALE_ROT_AXIS, false );
					}
					else if ( !COLLADABU::Math::Utils::equalsZero(scaleRotation.angle) )
					{
						colladaNode.addRotate ( rotationAxis.x, rotationAxis.y, rotationAxis.z, COLLADASW::MathUtils::radToDeg ( scaleRotation.angle ) );
					}
				}
			}
		}

#if 0 
		Matrix3 thisNodeObjectOffsetTransformationMatrix(true); 
		if ( !iNode->IsRootNode() )
		{
			// Calculate the pivot transform. It should already be in local space.
			calculateObjectOffsetTransformation(iNode, thisNodeObjectOffsetTransformationMatrix);

			// only export the pivot node if the transform is not an identity
			// or if the node is a group head node (this is a temporary fix until we add a PIVOT type)
			if ( !thisNodeObjectOffsetTransformationMatrix.IsIdentity() || iNode->IsGroupHead() )
			{
				double matrix[ 4 ][ 4 ] ;
				matrix3ToDouble4x4 ( matrix, thisNodeObjectOffsetTransformationMatrix );
				if ( exportObjectOffsetMatrix )
					colladaNode.addMatrix ( matrix );
			}
		}

		return thisNodeObjectOffsetTransformationMatrix;
#endif
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
	void VisualSceneExporter::calculateObjectOffsetTransformation(INode* maxNode, Matrix3& transformationMatrix)
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
		transformationMatrix = maxNode->GetObjTMAfterWSM(t) * Inverse(maxNode->GetNodeTM(t));
		return;
		}
		}
		*/
		Point3 objectOffsetPosition = maxNode->GetObjOffsetPos();
		Quat objectOffsetRotation = maxNode->GetObjOffsetRot();
		ScaleValue objectOffsetScale = maxNode->GetObjOffsetScale();

		// this should already be in local space
		// only do this if necessary to preserve identity tags
		transformationMatrix.IdentityMatrix();
		ApplyScaling(transformationMatrix, objectOffsetScale);
		RotateMatrix(transformationMatrix, objectOffsetRotation);
		transformationMatrix.Translate(objectOffsetPosition);

		transformationMatrix.ValidateFlags();
	}

	//---------------------------------------------------------------
	String VisualSceneExporter::getNodeId( const ExportNode& exportNode )
	{
		return NODE_ID_PRAEFIX + exportNode.getId();
	}

	//---------------------------------------------------------------
	Matrix3 VisualSceneExporter::getWorldTransform( INode* node, TimeValue time )
	{
		return node->GetNodeTM( time );
	}

	//---------------------------------------------------------------
	Matrix3 VisualSceneExporter::getWorldTransform( INode* node )
	{
		return getWorldTransform( node, mDocumentExporter->getOptions().getAnimationStart() );
	}

	//---------------------------------------------------------------
	bool VisualSceneExporter::applyFirstInstanceTransform( Matrix3& transformationMatrix, INode* node )
	{
		bool hasSkinnedObject = SkinController::isSkinned(node->GetObjectRef());
		if (hasSkinnedObject)
		{
			// Figure out whether this is the instance or the original
			INodeTab instanceNodes;
			IInstanceMgr::GetInstanceMgr()->GetInstances(*node, instanceNodes);

			if ( instanceNodes.Count() == 0) 
				return false;

			INode* firstInstanceNode = instanceNodes[0];
			if (node == firstInstanceNode) 
				return false;

			// For all instances, export the difference between the first
			// instance's local transformation and the current local transformation.
			// Note that you cannot export animations for this.

			// Max is strange in this. It always moves back the skin to its original position,
			// when animating, whatever the new transform it might contain. So, we need to take out
			// both the initial TM and the first Instance's TM to figure out where to place this instance.

			// The first instance TM include its pivot TM
			Matrix3 firstInstanceTM = firstInstanceNode->GetObjTMBeforeWSM(0);
			INode *parentNode = firstInstanceNode->GetParentNode();
			if ( parentNode && !parentNode->IsRootNode() )
			{
				Matrix3 parentTM = getWorldTransform(parentNode);
				parentTM.Invert();
				firstInstanceTM *= parentTM;
			}

			firstInstanceTM.Invert();
			transformationMatrix *= firstInstanceTM;
		}
		return true;
	}

	//---------------------------------------------------------------
	void VisualSceneExporter::fillInstanceMaterialList( COLLADASW::InstanceMaterialList & instanceMaterialList, ExportNode * exportNode )
	{
		const ExportNode::MeshSymbolMap & symbolMap = exportNode->getMeshSymbolMap();

		if ( symbolMap.empty() )
		{
			String materialId = MaterialExporter::getMaterialIdFromEffectId( EffectExporter::getEffectId( exportNode->getWireFrameColor() ) );
			//String materialSymbol = symbolIt->first;
			const String & materialSymbol = GeometryExporter::COLOR_MATERIAL_SYMBOL;
			instanceMaterialList.push_back( COLLADASW::InstanceMaterial ( materialSymbol, "#" + materialId ) );
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
					EffectMap::const_iterator it = mEffectMap.find( material );
					assert( it != mEffectMap.end() );
					String materialId = MaterialExporter::getMaterialIdFromEffectId( it->second );
					instanceMaterialList.push_back( COLLADASW::InstanceMaterial( symbol.name, "#" + materialId ) );

					// if it is as stdmat2, we need to export the bind vertex input
					Class_ID materialClassId = material->ClassID();

					if ( materialClassId.PartA() == DMTL2_CLASS_ID || materialClassId.PartA() == DMTL_CLASS_ID )
					{
						StdMat2* standartMaterial = (StdMat2*)material;

						COLLADASW::InstanceMaterial& instanceMaterial = instanceMaterialList.back();

						int numSubTexMaps = standartMaterial->NumSubTexmaps();
						for ( int i = 0; i < numSubTexMaps; i++ )
						{
							bool exportThisMap = standartMaterial->GetMapState ( i ) == 2;
							if ( exportThisMap )
							{
								Texmap* texMap = standartMaterial->GetSubTexmap ( i );
								int mapChannel = texMap->GetMapChannel();
								String semantic = EffectExporter::createTexcoordSementicFromMapchannel( mapChannel );
								const String & inputSemantic = COLLADASW::InputList::getSemanticString(COLLADASW::InputSemantic::TEXCOORD);
								// max starts with 1 to index the texture maps. To start with 0 in COLLADA, we always substract one from the channel to get the set
								// This is also relevant when the inouts of texture coordinates
								instanceMaterial.push_back( COLLADASW::BindVertexInput( semantic, inputSemantic, mapChannel - 1) );
							}
						}
					}

				}
			}
		}

	}



}
