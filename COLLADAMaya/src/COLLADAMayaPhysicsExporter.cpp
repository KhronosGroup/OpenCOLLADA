/*
    Copyright (c) 2015 Starbreeze

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
#include "COLLADAMayaPhysicsExporter.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaRotateHelper.h"
#include "COLLADAMayaGeometryExporter.h"
#include "COLLADASWInstanceGeometry.h"
#include "COLLADAMayaSceneElement.h"

#include <algorithm>

#include <maya/MItDependencyNodes.h>
#include <maya/MFnMesh.h>
#include <maya/MItDag.h>
#include <maya/MFnNumericData.h>
#include <maya/MFnTransform.h>
#include <maya/MFnGravityField.h>
#include <maya/MFnAttribute.h>


namespace COLLADAMaya
{
	static const char* NAME_SUFFIX_INVALID = "_MAKE_NAME_INVALID";
	std::map<String, PhysicsExporter::BodyTarget> PhysicsExporter::bodyTargetMap;
	MVector PhysicsExporter::gravityField;

    // --------------------------------------------------------
	PhysicsExporter::PhysicsExporter(COLLADASW::StreamWriter* streamWriter,
		DocumentExporter* documentExporter)
		: COLLADASW::LibraryPhysicsModels(streamWriter)
		, mDocumentExporter(documentExporter)
		, mIsFirstRotation(true)
    {
			bodyTargetMap.clear();
			firstimeOpenPhysModel = true;
    }

    // --------------------------------------------------------
	PhysicsExporter::~PhysicsExporter(void)
    {
 
    }

    // --------------------------------------------------------
	void PhysicsExporter::exportAllPhysics()
    {
        if ( !ExportOptions::exportPhysic() ) return;

        // Get the list with the transform nodes.
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

        // Export all/selected DAG nodes
        size_t length = exportNodesTree->size();
        for ( size_t i = 0; i < length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];
			exportAllPhysics(sceneElement, sceneElement->getIsVisible());
        }

		if (!firstimeOpenPhysModel)
			closePhysicsModel();

        endExport();
    }

    // --------------------------------------------------------
	void PhysicsExporter::exportAllPhysics(SceneElement* sceneElement, bool isVisible)
    {
        // If we have a external reference, we don't need to export the data here.
        if ( !sceneElement->getIsLocal() ) return;

        bool exportSceneElement = false;
        SceneElement::Type sceneElementType = sceneElement->getType();
		if (sceneElementType == SceneElement::PHYSIK || sceneElementType == SceneElement::PHYSIK_BULLET)
        {
            if ( sceneElement->getIsExportNode () ) exportSceneElement = true;
            else 
            {
                if ( sceneElement->getIsForced () ) exportSceneElement = true;
                else if ( !isVisible && ExportOptions::exportInvisibleNodes () ) exportSceneElement = true;
            }
        }

        if ( exportSceneElement )
        {
            // Get the current dag path
            MDagPath dagPath = sceneElement->getPath();

            // Check if the current scene element isn't already exported.
            SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
            if ( sceneGraph->findExportedElement ( dagPath ) ) return;

            // Check if the current element is an instance. 
            // We don't need to export instances, because we export the original instanced element.
            bool isInstance = ( dagPath.isInstanced() && dagPath.instanceNumber() > 0 );

            // If the original instanced element isn't already exported, we have to export it now.
            if ( isInstance )
            {
                // Get the original instanced element.
                MDagPath instancedPath;
                dagPath.getPath ( instancedPath, 0 );

                // Check if the original instanced element is already exported.
                SceneElement* exportedElement = sceneGraph->findExportedElement ( instancedPath );
                if ( exportedElement == 0 )
                {
                    // Export the original instanced element.
                    SceneElement* instancedSceneElement = sceneGraph->findElement ( instancedPath );
//                    exportControllerOrGeometry ( instancedSceneElement );
                }
            }
            else
            {
                exportPhysics ( sceneElement );
            }
        }

        // Check if the element is visible (inherit visibility to children)
        if ( isVisible ) isVisible = sceneElement->getIsVisible ();

        // Recursive call for all the child elements
        for ( uint i=0; i<sceneElement->getChildCount(); ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );
			exportAllPhysics(childElement, isVisible);
        }
    }

    // --------------------------------------------------------
    void PhysicsExporter::exportPhysics ( 
        SceneElement* sceneElement )
    {
        // Export the element and push it in the exported scene graph. 
        if ( exportPhysicsElement ( sceneElement ) )
        {
            SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
            sceneGraph->addExportedElement( sceneElement );
        }
    }

    // --------------------------------------------------------
	bool PhysicsExporter::exportPhysicsElement(SceneElement* sceneElement)
    {
		if (!ExportOptions::exportPhysic()) return false;

        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();
        String pathName = dagPath.fullPathName ().asChar ();

        // Generate the unique collada mesh id.
        const String& colladaMeshId = generateColladaMeshId ( dagPath );
//        if ( colladaMeshId.empty () ) return false;

        // Set the node id.
        sceneElement->setNodeId ( colladaMeshId );

		return exportPhysicModel(dagPath);
    }

    // --------------------------------------------------------
    const String PhysicsExporter::generateColladaMeshId ( const MDagPath dagPath )
    {
        // Get the maya mesh id.
        String mayaMeshId = mDocumentExporter->dagPathToColladaId ( dagPath );

        // Generate a COLLADA id for the new object.
		String colladaMeshId = findColladaPhysicsId(mayaMeshId);

        // Check, if the unique id for the current geometry is already generated.
        if ( !colladaMeshId.empty () ) return colladaMeshId;

        // Get the node of the current mesh
		 colladaMeshId = mDocumentExporter->dagPathToColladaName ( dagPath );

        // Make the id unique and store it in a map.
        colladaMeshId = mPhysicsIdList.addId ( colladaMeshId );
        mMayaIdColladaIdMap [ mayaMeshId ] = colladaMeshId;

        return colladaMeshId;
    }


	//---------------------------------------------------------------
	void PhysicsExporter::exportTranslation(
		const String name,
		const MPoint& translation)
	{
		exportTranslation(name, MVector(translation));
	}

	//---------------------------------------------------------------
	void PhysicsExporter::exportTranslation(
		const String name,
		const MVector& translation)
	{
		bool isZero = true;
		for (int i = 0; i<3 && isZero; ++i)
		{
			if (translation[i] != 0) isZero = false;
		}

		if (!isZero)
		{
			// Convert the  maya internal unit type from centimeters
			// into the working units of the current scene!
			addTranslate(
				name,
				COLLADABU::Math::Utils::equalsZero(translation.x, getTolerance()) ? 0 : MDistance::internalToUI(translation.x),
				COLLADABU::Math::Utils::equalsZero(translation.y, getTolerance()) ? 0 : MDistance::internalToUI(translation.y),
				COLLADABU::Math::Utils::equalsZero(translation.z, getTolerance()) ? 0 : MDistance::internalToUI(translation.z));
		}
	}

	//---------------------------------------------------------------
	void PhysicsExporter::exportRotation(
		const String name,
		const MEulerRotation& rotation)
	{
		RotateHelper rotateHelper(rotation);
		std::vector<std::vector<double> >& matrixRotate = rotateHelper.getRotationMatrix();
		std::vector<String>& rotateParams = rotateHelper.getRotationParameters();

		// Set zero flags, where the rotation is zero. The order of rotation is ZYX.
		bool isZero[3] = { COLLADABU::Math::Utils::equalsZero(matrixRotate[0][3], getTolerance()),
			COLLADABU::Math::Utils::equalsZero(matrixRotate[1][3], getTolerance()),
			COLLADABU::Math::Utils::equalsZero(matrixRotate[2][3], getTolerance()) };

		// Go through the axes for the rotations.
		for (uint i = 0; i<3; ++i)
		{
			bool rotationIsNecessary = false;

			// Check, if we have to write the rotation.
			if (mIsJoint && COLLADABU::Utils::equalsIgnoreCase(name, ATTR_JOINT_ORIENT))
			{
				// A joint must always have a rotation.
				rotationIsNecessary = true;
			}
			else
			{
				// You have to write the rotation, if the element is animated.
				rotationIsNecessary = ( !(!mIsFirstRotation && isZero[i]));
			}

			if (mTransformObject != MObject::kNullObj && rotationIsNecessary)
			{
				// Add the rotation in the order ZYX
				addRotate(
					name + rotateParams[i],
					COLLADABU::Math::Utils::equalsZero(matrixRotate[i][0], getTolerance()) ? 0 : matrixRotate[i][0],
					COLLADABU::Math::Utils::equalsZero(matrixRotate[i][1], getTolerance()) ? 0 : matrixRotate[i][1],
					COLLADABU::Math::Utils::equalsZero(matrixRotate[i][2], getTolerance()) ? 0 : matrixRotate[i][2],
					COLLADABU::Math::Utils::equalsZero(matrixRotate[i][3], getTolerance()) ? 0 : matrixRotate[i][3]);
			}
		}

		mIsFirstRotation = false;
	}

	void PhysicsExporter::exportDecomposedTransform()
	{
		double resultFinal[4][4];
		mFinalTransformMatrix.asMatrix().get(resultFinal);

		bool mIsJoint = false;

		MVector translation = mFinalTransformMatrix.translation(MSpace::kTransform);
		MPoint rotatePivotTranslation = mFinalTransformMatrix.rotatePivotTranslation(MSpace::kTransform);
		MPoint rotatePivot = mFinalTransformMatrix.rotatePivot(MSpace::kTransform, NULL);
		MVector scalePivotTranslation = mFinalTransformMatrix.scalePivotTranslation(MSpace::kTransform);
		MVector scalePivot = mFinalTransformMatrix.scalePivot(MSpace::kTransform);
		double shear[3] = { 0, 0, 0 };
		mFinalTransformMatrix.getShear(shear, MSpace::kTransform);

		MEulerRotation jointOrientation, rotation, rotationAxis;
		if (mTransformObject != MObject::kNullObj)
		{
			mIsJoint = DagHelper::getPlugValue(mTransformObject, ATTR_JOINT_ORIENT, jointOrientation);

			if (!DagHelper::getPlugValue(mTransformObject, ATTR_ROTATE, rotation)) rotation.setValue(0, 0, 0);
			if (!DagHelper::getPlugValue(mTransformObject, ATTR_ROTATE_AXIS, rotationAxis)) rotationAxis.setValue(0, 0, 0);

			rotation.order = (MEulerRotation::RotationOrder) ((int)mFinalTransformMatrix.rotationOrder() - MTransformationMatrix::kXYZ + MEulerRotation::kXYZ);
			rotationAxis.order = jointOrientation.order = MEulerRotation::kXYZ;
		}
		else
		{
			rotation = mFinalTransformMatrix.eulerRotation();
			rotation.order = (MEulerRotation::RotationOrder) ((int)mFinalTransformMatrix.rotationOrder() - MTransformationMatrix::kXYZ + MEulerRotation::kXYZ);
			mIsJoint = false;
		}

		// This is the order of the transforms:
		//
		// matrix = [SP-1 * S * SH * SP * ST] * [RP-1 * RA * R * JO * RP * RT] * T
		//          [        scale          ] * [          rotation          ] * translation
		//
		// Where SP is scale pivot translation, S is scale, SH is shear, ST is scale pivot translation
		// RP is rotation pivot, RA is rotation axis, R is rotation, RP is rotation pivot,
		// RT is rotation pivot translation, T is translation, JO is joint orientation
		//
		// references: Maya documentation - transform node, Maya documentation - joint node
		// NOTE: Left multiplying, column-order matrices
		//

		// Translate
		exportTranslation(ATTR_TRANSLATE, translation);

		//Rotate
		exportTranslation(ATTR_ROTATE_PIVOT_TRANSLATION, rotatePivotTranslation);
		exportTranslation(ATTR_ROTATE_PIVOT, rotatePivot);
		if (mIsJoint) exportRotation(ATTR_JOINT_ORIENT, jointOrientation);
		exportRotation(ATTR_ROTATE, rotation);
		if (mIsJoint) exportRotation(ATTR_ROTATE_AXIS, rotationAxis);
		exportTranslation(ATTR_ROTATE_PIVOT_INVERSE, rotatePivot * -1);
	}

	void PhysicsExporter::createShape(MDagPath& childDagPath, MTransformationMatrix mPhysicsShapeTransformMatrix, MTransformationMatrix mGraphicShapeTransformMatrix)
	{
			MFnDagNode fnChild(mTransformObject);
			MString childName(fnChild.name());

			MObject childTransform = childDagPath.transform();


			double resultPhys[4][4];
			mPhysicsShapeTransformMatrix.asMatrix().get(resultPhys);
			MMatrix MatPhysShape(mPhysicsShapeTransformMatrix.asMatrix());

			double resultGraph[4][4];
			mGraphicShapeTransformMatrix.asMatrix().get(resultGraph);
			MMatrix MatGraphShape(mGraphicShapeTransformMatrix.asMatrixInverse());


			// PhysicShape Matrix relative to Graphic Shape Space
			MMatrix result = MatPhysShape * MatGraphShape;
			double result2[4][4];
			result.get(result2);

			mFinalTransformMatrix = result;

			//Get BoundingBox
			childDagPath.extendToShape(); 

			const MObject& meshNode = childDagPath.node();
			MFnMesh fnMesh(meshNode);
			MBoundingBox bb = fnMesh.boundingBox();
			

			int shape;
			bool shapeResult = DagHelper::getPlugValue(childTransform, ATTR_COLLISION_SHAPE, shape);

			if (shapeResult)
			{
				// Write Tag
				openShape();

				if (shape == COLLADAMaya::PhysicsExporter::Box)
				{
					AddBoxShape(MDistance::internalToUI(bb.width() / 2), MDistance::internalToUI(bb.height() / 2), MDistance::internalToUI(bb.depth() / 2));
				}
				else if (shape == COLLADAMaya::PhysicsExporter::Capsule)
				{
					float radius = MDistance::internalToUI(bb.width() / 2);
					float height = MDistance::internalToUI(bb.depth()) - 2 * radius;
					AddCapsuleShape(radius, radius, radius, height);
				}
				else if (shape == COLLADAMaya::PhysicsExporter::Convex_mesh)
				{
					MDagPath dagPath = MDagPath::getAPathTo(meshNode);
					GeometryExporter* geometryExporter = mDocumentExporter->getGeometryExporter();
					const String& colladaMeshId = geometryExporter->getColladaGeometryId(dagPath);
					//AddConvexMeshShape(colladaMeshId);

					COLLADASW::URI uri( (String("#") + String(colladaMeshId) + String("_")));

					// Get the streamWriter from the export document
					COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

					// Write the geometry instance
					COLLADASW::InstanceGeometry instanceGeometry(streamWriter);
					instanceGeometry.setUrl(uri);

					instanceGeometry.add();
				}
				else if (shape == COLLADAMaya::PhysicsExporter::Mesh)
				{
					MDagPath dagPath = MDagPath::getAPathTo(meshNode);
					GeometryExporter* geometryExporter = mDocumentExporter->getGeometryExporter();
					const String& colladaMeshId = geometryExporter->getColladaGeometryId(dagPath);
					//AddConvexMeshShape(colladaMeshId);

					COLLADASW::URI uri((String("#") + String(colladaMeshId)));

					// Get the streamWriter from the export document
					COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

					// Write the geometry instance
					COLLADASW::InstanceGeometry instanceGeometry(streamWriter);
					instanceGeometry.setUrl(uri);

					instanceGeometry.add();
				}

				exportDecomposedTransform();
				closeShape();
			}
	}

	

	bool PhysicsExporter::isBulletRigidBodySolverNode(MDagPath& dagPath)
	{
		MStatus status;
		MObject node(dagPath.node());
		MFnDependencyNode shaderNode(node, &status);
		MString shaderNodeTypeName(shaderNode.typeName());

		return (shaderNodeTypeName == BULLET_PHYSIKS_SOLVER_NODE);
	}


	bool PhysicsExporter::isBulletRigidBodyNode(MDagPath& dagPath)
	{

		MStatus status;
		MObject node(dagPath.node());
		MFnDependencyNode shaderNode(node, &status);
		MString shaderNodeTypeName(shaderNode.typeName());

		return (shaderNodeTypeName == BULLET_PHYSIKS_NODE);
	}


	void PhysicsExporter::getGravityField()
	{
		MItDag it(MItDag::kDepthFirst);

		while (!it.isDone()) 
		{
			MFnDagNode fn(it.item());

			MDagPath DagPath = MDagPath::getAPathTo(it.item());
			if (isBulletRigidBodySolverNode(DagPath))
			{
				MStatus status;
				MPlug plug = MFnDependencyNode(DagPath.node()).findPlug(MString(COLLADASW::CSWC::CSW_ELEMENT_GRAVITY.c_str()), &status);
				if (status == MStatus::kSuccess) 
				if (plug.isCompound() && plug.numChildren() >= 3)
				{
					status = plug.child(0).getValue(PhysicsExporter::gravityField.x);
					status = plug.child(1).getValue(PhysicsExporter::gravityField.y);
					status = plug.child(2).getValue(PhysicsExporter::gravityField.z);
				}
			}

			it.next();
		}
	}

	static void searchAndUpdate(SceneElement* sceneElement, MDagPath& ChildPath, bool result, bool needExport)
	{

		if (sceneElement->getType() == SceneElement::TRANSFORM && sceneElement->getPath() == ChildPath)
		{
			if (!result)
				sceneElement->setIsPhysicNode(true);
			else
			{
				if (needExport)
					sceneElement->setIsPhysicNode(false);
				else
					sceneElement->setIsPhysicNode(true);
			}
		}

		for (uint i = 0; i < sceneElement->getChildCount(); ++i)
		{
			SceneElement* childElement = sceneElement->getChild(i);
			searchAndUpdate(childElement, ChildPath, result, needExport);
		}
	}


	void PhysicsExporter::UpdateSceneElement(MObject& child, bool result, bool needExport)
	{
		MDagPath ChildPath = MDagPath::getAPathTo(child);

		SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
		SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();
		
		for (std::vector<SceneElement*>::iterator it = exportNodesTree->begin(); it != exportNodesTree->end(); ++it)
		{
			String childDagPath = (*it)->getPath().fullPathName().asChar();
			SceneElement* sceneElement = (*it);
			searchAndUpdate(sceneElement, ChildPath, result, needExport);
		}
	}

    // --------------------------------------------------------
	bool PhysicsExporter::exportPhysicModel(
		MDagPath& dagPath)
    {
		const String& colladaMeshId = generateColladaMeshId(dagPath);
		String meshName = mDocumentExporter->dagPathToColladaName(dagPath);

        // Opens the mesh tag in the collada document
		MFnDagNode DagNode(dagPath.node());
		MObject parent = DagNode.parent(0);
		MFnDagNode fnParent(parent);
		MString parentName = fnParent.name();
		if (firstimeOpenPhysModel)
		{
			openPhysicsModel(PHYSIC_MODEL_ID, "");
			firstimeOpenPhysModel = false;
		}
				
		openRigidBody(colladaMeshId, "");

		openTechniqueCommon();

		
		// Get BodyType
		int type;
		DagHelper::getPlugValue(dagPath.node(), ATTR_BODY_TYPE, type);
		
		enum bodytype
		{
			Static,
			Kinematic,
			Dynamic
		};

		if (type == Kinematic || type == Dynamic)
			addDynamic(true);
		else if (type == Static)
			addDynamic(false);


		//Get Mass
		float mass;
		MObject node = dagPath.node();
		
		if (isBulletRigidBodyNode(dagPath))
		{
			DagHelper::getPlugValue(node, ATTR_MASS, mass);
			addMass(mass);
		}


		//Get Inertia 
		MVector inertia(1,1,1);
		//DagHelper::getPlugValue(dagPath.node(), ATTR_INERTIA, inertia);
		addInertia(inertia.x, inertia.y, inertia.z);
		
		for (int i = 0; i < DagNode.parentCount(); ++i)
		{
			// Parent 1 level upper
			MObject parent = DagNode.parent(i);
			MFnDagNode fnParent(parent);
			MString parentName = fnParent.name();

			bool needExportParent = false;
			bool resultParent = DagHelper::getPlugValue(parent, ATTR_COLLISION_EXPORT_NODE, needExportParent);
			UpdateSceneElement(parent, resultParent, needExportParent);

			// Parent 2 level upper
			MObject parent2 = fnParent.parent(0);
			MFnDagNode fnParent2(parent2);
			MString parentName2 = fnParent2.name();

			// Search for Solver, Gravity Field
			getGravityField();


			MTransformationMatrix mGraphicShapeTransformMatrix;
			if (!needExportParent)
			{
				MDagPath path;
				fnParent2.getPath(path);
				mGraphicShapeTransformMatrix = MTransformationMatrix(path.inclusiveMatrix());
			}
			else
			{
				mGraphicShapeTransformMatrix = MTransformationMatrix(dagPath.inclusiveMatrix());
			}


			for (int i = 0; i < fnParent.childCount(); ++i)
			{
				MObject child = fnParent.child(i);
				MFnDagNode fnChild(child);
				MString childName = fnChild.name();
				MDagPath ChildPath = MDagPath::getAPathTo(child);
				String childDagPath = ChildPath.fullPathName().asChar();

				UpdateSceneElement(child, resultParent, needExportParent);

				if (isBulletRigidBodyNode(ChildPath))
				{
					MFnDagNode fnChild(child);
					MString childName;
					childName = fnChild.name();
					const String& colladaBodyId = generateColladaMeshId(ChildPath);

					BodyTarget mBodyTarget;
					mBodyTarget.Body = colladaBodyId;

					if (!needExportParent)
						mBodyTarget.Target = (MString("#") + parentName2).asChar();
					else
						mBodyTarget.Target = (MString("#") + parentName).asChar();

					bodyTargetMap[(MString("#") + parentName).asChar()] = mBodyTarget;
				}
				else
				{
					mTransformObject = ChildPath.transform();
					MTransformationMatrix mPhysicShapeTransformMatrix(ChildPath.inclusiveMatrix());
					createShape(ChildPath, mPhysicShapeTransformMatrix, mGraphicShapeTransformMatrix);
				}
			}
		}


		closeTechniqueCommon();
		closeRigidBody();

        return true;
    }

    // --------------------------------------------------
    void PhysicsExporter::endExport()
    {
        closeLibrary();
    }


    // ------------------------------------
    const String& PhysicsExporter::findColladaPhysicsId ( const String& mayaMeshId )
    {
        const StringToStringMap::const_iterator it = mMayaIdColladaIdMap.find ( mayaMeshId );
        if ( it != mMayaIdColladaIdMap.end () )
        {
            return it->second;
        }
        return EMPTY_STRING;
    }
}