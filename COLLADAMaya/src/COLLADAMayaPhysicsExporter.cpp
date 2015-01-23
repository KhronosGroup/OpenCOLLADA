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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaPhysicsExporter.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaRotateHelper.h"

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
	std::map<String, PhysicsExporter::BodyTarget> PhysicsExporter::myMap;

    // --------------------------------------------------------
	PhysicsExporter::PhysicsExporter(COLLADASW::StreamWriter* streamWriter,
		DocumentExporter* documentExporter)
		: COLLADASW::LibraryPhysicsModels(streamWriter)
		, mDocumentExporter(documentExporter)
		, mIsFirstRotation(true)
    {
    }

    // --------------------------------------------------------
	PhysicsExporter::~PhysicsExporter(void)
    {
 
    }

    // --------------------------------------------------------
	void PhysicsExporter::exportAllPhysics()
    {
        if ( !ExportOptions::exportPhysicsModels() ) return;

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

        endExport();
    }

    // --------------------------------------------------------
	void PhysicsExporter::exportAllPhysics(SceneElement* sceneElement, bool isVisible)
    {
        // If we have a external reference, we don't need to export the data here.
        if ( !sceneElement->getIsLocal() ) return;

        bool exportSceneElement = false;
        SceneElement::Type sceneElementType = sceneElement->getType();
		if (sceneElementType == SceneElement::PHYSIK)
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
		if (!ExportOptions::exportPhysicsModels()) return false;

        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();
        String pathName = dagPath.fullPathName ().asChar ();

        // Generate the unique collada mesh id.
        const String& colladaMeshId = generateColladaMeshId ( dagPath );
//        if ( colladaMeshId.empty () ) return false;

        // Set the node id.
        sceneElement->setNodeId ( colladaMeshId );

//        bool isInstanced = dagPath.isInstanced();
//        uint instanceNumber = dagPath.instanceNumber();

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
        MObject meshNode = dagPath.node();

        // Attach a function set to the mesh node.
        // We access all of the meshes data through the function set
        MStatus status;
        MFnMesh fnMesh ( meshNode, &status );
        if ( status != MStatus::kSuccess ) return colladaMeshId;

        // Check if there is an extra attribute "colladaId" and use this as export id.
        MString attributeValue;
        DagHelper::getPlugValue ( meshNode, COLLADA_ID_ATTRIBUTE_NAME, attributeValue );
        if ( attributeValue != EMPTY_CSTRING )
        {
            // Generate a valid collada name, if necessary.
            colladaMeshId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false );
        }
        else
        {
            // Generate a COLLADA id for the new object
            colladaMeshId = DocumentExporter::mayaNameToColladaName ( fnMesh.name() );
        }

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
		mTransformMatrix.asMatrix().get(resultFinal);

		bool mIsJoint = false;

		MVector translation = mTransformMatrix.translation(MSpace::kTransform);
		MPoint rotatePivotTranslation = mTransformMatrix.rotatePivotTranslation(MSpace::kTransform);
		MPoint rotatePivot = mTransformMatrix.rotatePivot(MSpace::kTransform, NULL);
		MVector scalePivotTranslation = mTransformMatrix.scalePivotTranslation(MSpace::kTransform);
		MVector scalePivot = mTransformMatrix.scalePivot(MSpace::kTransform);
		double shear[3] = { 0, 0, 0 };
		mTransformMatrix.getShear(shear, MSpace::kTransform);

		MEulerRotation jointOrientation, rotation, rotationAxis;
		if (mTransformObject != MObject::kNullObj)
		{
			mIsJoint = DagHelper::getPlugValue(mTransformObject, ATTR_JOINT_ORIENT, jointOrientation);

			if (!DagHelper::getPlugValue(mTransformObject, ATTR_ROTATE, rotation)) rotation.setValue(0, 0, 0);
			if (!DagHelper::getPlugValue(mTransformObject, ATTR_ROTATE_AXIS, rotationAxis)) rotationAxis.setValue(0, 0, 0);

			rotation.order = (MEulerRotation::RotationOrder) ((int)mTransformMatrix.rotationOrder() - MTransformationMatrix::kXYZ + MEulerRotation::kXYZ);
			rotationAxis.order = jointOrientation.order = MEulerRotation::kXYZ;
		}
		else
		{
			rotation = mTransformMatrix.eulerRotation();
			rotation.order = (MEulerRotation::RotationOrder) ((int)mTransformMatrix.rotationOrder() - MTransformationMatrix::kXYZ + MEulerRotation::kXYZ);
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


	void PrintConnections(MPlug& plug)
	{

		// will hold the connections to this node
		MPlugArray plugs;

		cout << "plug " << plug.name().asChar() << endl;
		String name = plug.name().asChar();

		// get input plugs
		plug.connectedTo(plugs, true, false);

		cout << "\tinputs " << plugs.length() << endl;
		for (int i = 0; i<plugs.length(); ++i) {

			cout << "\t\t" << plugs[i].name().asChar() << endl;
		}


		// get output plugs
		plug.connectedTo(plugs, false, true);

		cout << "\toutputs " << plugs.length() << endl;
		for (int i = 0; i<plugs.length(); ++i) {

			String name =  plugs[i].name().asChar();

			cout << "\t\t" << plugs[i].name().asChar() << endl;
		}
	}

	void PrintNodeConnections(MObject& node)
	{

		// will hold the connections to this node
		MPlugArray nodeplugs;

		MFnDependencyNode fn(node);

		cout << "node " << fn.name().asChar() << endl;
		String name = fn.name().asChar();
		// using the getConnections function we return a list
		// of attributes on THIS node that have connections. 
		fn.getConnections(nodeplugs);

		cout << "numplugs " << nodeplugs.length() << endl;
		for (int i = 0; i<nodeplugs.length(); ++i) {

			// use function from above to print all of the
			// connected attributes.
			PrintConnections(nodeplugs[i]);
		}

	}
	void PhysicsExporter::createShape(MDagPath& childDagPath)
	{
///////TEST
			MFnDagNode fnChild(mTransformObject);
			MString childName;
			childName = fnChild.name();
///////TEST

			MObject& childTransform = childDagPath.transform();
			MFnTransform fn(childTransform);
			mTransformMatrix = fn.transformation();

			// Write Tag
			openShape();

			//Get BoundingBox
			childDagPath.extendToShape();
			//String pathName1 = childDagPath.fullPathName().asChar();

			const MObject& meshNode = childDagPath.node();

			//MDagPath FnPath = MDagPath::getAPathTo(meshNode);
			//String pathName2 = FnPath.fullPathName().asChar();


			MFnMesh fnMesh(meshNode);
			MBoundingBox bb = fnMesh.boundingBox();
			

			/* MPoint p = bb.center();
			 double w = bb.width();
			 double h = bb.height();
			 double d = bb.depth();

			 MPoint min = bb.min();
			 MPoint max = bb.max();*/

			MString attributeValue;

			MFnAttribute pathAttribute(childTransform);
			String pathAttributeName = pathAttribute.name().asChar ();
			
			String name = "extra attributes";
			MStatus status;
			MPlug plug = MFnDependencyNode(meshNode).findPlug(name.c_str(), &status);
			MFnAttribute pathAttribute2(plug.attribute());
			String pathAttributeName2 = pathAttribute2.name().asChar();

			size_t numChildren = plug.numChildren();
			for (uint i = 0; i < numChildren; ++i)
			{
				MPlug childPlug = plug.child(i, &status);
				if (status != MStatus::kSuccess) continue;

				// Get the collada attribute.
				MFnAttribute pathAttribute(childPlug.attribute());
				String pathAttributeName = pathAttribute.name().asChar();
				//     
			}

			PrintNodeConnections(childTransform);
			PrintNodeConnections(const_cast<MObject&>(meshNode));


			DagHelper::getPlugValue(meshNode, "extra attributes", attributeValue);
			if (attributeValue != EMPTY_CSTRING)
			{
				String attributeName = attributeValue.asChar();

				if (attributeName.compare("box") == 0)
				{
					AddBoxShape(MDistance::internalToUI(bb.width() / 2), MDistance::internalToUI(bb.height() / 2), MDistance::internalToUI(bb.depth() / 2));
				}
			}

			AddBoxShape(MDistance::internalToUI(bb.width() / 2), MDistance::internalToUI(bb.height() / 2), MDistance::internalToUI(bb.depth() / 2));
			exportDecomposedTransform();
			closeShape();
	}

    // --------------------------------------------------------
	bool PhysicsExporter::exportPhysicModel(
		MDagPath& dagPath)
    {
		const String& colladaMeshId = generateColladaMeshId(dagPath);
		String meshName = mDocumentExporter->dagPathToColladaName(dagPath);

        // Opens the mesh tag in the collada document

		{
			MFnDagNode DagNode(dagPath.node());
			MObject parent = DagNode.parent(0);
			MFnDagNode fnParent(parent);
			MString parentName = fnParent.name();
			openPhysicsModel(parentName.asChar(), meshName);
		}
		
		openRigidBody(meshName, "");

		openTechniqueCommon();

		bool dynamic;
		DagHelper::getPlugValue(dagPath.node(), ATTR_DYNAMIC, dynamic);
		addDynamic(dynamic);

		float mass;
		MObject& node = dagPath.node();
		
///////TEST		
		//MFnDagNode fnNode(node);
		//MDagPath FnPath = fnNode.dagPath();  // not working
		MDagPath FnPath = MDagPath::getAPathTo(node);
		String pathName1 = FnPath.fullPathName().asChar();
		String pathName = dagPath.fullPathName().asChar();
///////TEST

		if (node.hasFn(MFn::kRigid))
		{
			DagHelper::getPlugValue(node, ATTR_MASS, mass);
			addMass(mass);
		}

		MVector inertia(1,1,1);
		//DagHelper::getPlugValue(dagPath.node(), ATTR_INERTIA, inertia);
		addInertia(inertia.x, inertia.y, inertia.z);
		

		// Add as many <shape> as childnode of the parent node of Rigidbody (except himself)
		//MObject& node1 = dagPath.transform();
		MFnDagNode DagNode(node);
		for (int i = 0; i < DagNode.parentCount(); ++i) {

			// get the MObject for the i'th parent
			MObject parent = DagNode.parent(i);

			// attach a function set to it
			MFnDagNode fnParent(parent);
			MString parentName = fnParent.name();
			
			// Parent 2 Level Upper
			MObject parent2 = fnParent.parent(0);
			MFnDagNode fnParent2(parent2);
			MString parentName2 = fnParent2.name();

			// Get Gravity Field
			for (int i = 0; i < fnParent2.childCount(); ++i) {
				
				MObject child = fnParent2.child(i);

				if (child.hasFn(MFn::kGravity))
				{
					MFnGravityField GravityField(child);
					MVector dir = GravityField.direction();
					double mag = GravityField.magnitude();
				}
			}

			for (int i = 0; i < fnParent.childCount(); ++i) {

				// get the MObject for the i'th child 
				MObject child = fnParent.child(i);

///////TEST
				MFnDagNode fnChild(child);
				MString childName = fnChild.name();
				MDagPath ChildPath = MDagPath::getAPathTo(child);
				String childDagPath = ChildPath.fullPathName().asChar();
///////TEST

				mTransformObject = ChildPath.node();

				if (mTransformObject.hasFn(MFn::kTransform))
					createShape(ChildPath);

				if (child.hasFn(MFn::kRigid))
				{
					MFnDagNode fnChild(child);
					MString childName;
					childName = fnChild.name();

					BodyTarget mBodyTarget;
					mBodyTarget.Body = childName.asChar();
					mBodyTarget.Target = (MString("#") + parentName2).asChar();
					myMap[(MString("#") + parentName).asChar()] = mBodyTarget;
				}
			}
		}

		closeTechniqueCommon();
		closeRigidBody();
		closePhysicsModel();

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

   
    // ------------------------------------
    //const String& PhysicsExporter::getColladaPhysicsId ( MDagPath dagPath )
    //{
    //    // Get the node of the current mesh
    //    MObject meshNode = dagPath.node();
    //    if ( !meshNode.hasFn ( MFn::kMesh ) ) 
    //    {
    //        MGlobal::displayError ( "No mesh object!" );
    //        return EMPTY_STRING;
    //    }

    //    // Attach a function set to the mesh node.
    //    // We access all of the meshes data through the function set
    //    MStatus status;
    //    MFnMesh fnMesh ( meshNode, &status );
    //    if ( status != MStatus::kSuccess ) 
    //    {
    //        MGlobal::displayError ( "No mesh object!" );
    //        return EMPTY_STRING;
    //    }

    //    // Get the maya mesh id.
    //    String mayaMeshId = mDocumentExporter->dagPathToColladaId ( dagPath );

    //    // Check for instances.
    //    bool isInstanced = fnMesh.isInstanced ( true );
    //    if ( isInstanced )
    //    {
    //        // Take the first instance.
    //        MDagPathArray dagPathes;
    //        fnMesh.getAllPaths ( dagPathes );
    //        mayaMeshId = mDocumentExporter->dagPathToColladaId ( dagPathes[0] );
    //    }

    //    // Get the geometry collada id.
    //    const String& colladaMeshId = findColladaPhysicsId ( mayaMeshId );

    //    return colladaMeshId;
    //}

}