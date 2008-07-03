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
#ifndef __COLLADA_MAYA_CONTROLLER_LIBRARY_H___
#define __COLLADA_MAYA_CONTROLLER_LIBRARY_H___

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentExporter.h"


namespace COLLADAMaya
{

//  typedef std::vector<ControllerInstance> ControllerInstanceList;
//  typedef std::vector<Controller> ControllerList;

    /**
     * Represents a controller.
     */

    class DaeController
    {

    public:
        MDagPathArray influences; // export-only
//  FMMatrix44List bindPoses; // export-only
//  ControllerInstanceList instances; // export-only;

        DaeController ( const MObject& node ) {}

        virtual ~DaeController() {}
    };


    /**
     * Class to control the skins and morphs
     */

    class ControllerLibrary
    {

    public:
        ControllerLibrary ( COLLADA::StreamWriter* streamWriter, DocumentExporter* documentExporter );
        ~ControllerLibrary();

//   // Create the requested controller instance
//   // Note: this function returns whether the id is a controller, not success
//   void Import();
//   DaeEntity* ImportController(FCDController* colladaController);
//   void InstantiateController(DaeEntity* sceneNode, FCDGeometryInstance* colladaInstance, FCDController* colladaController);
//   void AttachControllers();
//   MObject AttachMorphController(DaeController* controller, FCDGeometry* baseMesh);
//   bool ObjectMatchesInstance(const DaeEntityList& influences, const MDagPathArray& paths);
//   void LinkSkinControllerInstance(FCDControllerInstance* instance, FCDSkinController* skinController, DaeController* controller);
//   MObject AttachSkinController(DaeController* controller);
//   MObject AttachSkinController(DaeController* controller, MString meshName);
//   void ImportMorphTarget(MPlug& vertexListPlug, MPlug& componentListPlug, FCDGeometry* baseMesh, FCDGeometryMesh* targetMesh);

//   // After import: release the unnecessary memory hogging data
//   void leanMemory();
//   void leanSkin(SkinController* colladaSkin);
//
//   // If the given 'node' is of a supported shape type and has a controller,
//   // return true and set 'controllerNode'. Otherwise, return false.
//   bool getMorphController(const MObject& node, MObjectArray& controllerNodes);
//
//   // Export any controller associated with the given plug.
//   void addForceNodes(const MDagPath& dagPath);
//   void exportJoint(FCDSceneNode* sceneNode, const MDagPath& dagPath, bool isLocal);
//   DaeEntity* exportController(FCDSceneNode* sceneNode, const MDagPath& dagPath, bool isSkin,
//    bool instantiate=true);
//   DaeEntity* exportController(FCDSceneNode* sceneNode, const MObject& node);
//   DaeEntity* exportMorphController(FCDSceneNode* sceneNode, MObjectArray& controllerNodes, DaeEntity* target);
//   DaeEntity* exportSkinController(MObject controllerNode, MDagPath outputShape, DaeEntity* target);
//   FCDGeometry* exportMorphTarget(MPlug& vertexListPlug, MPlug& targetComponentListPlug, uint targetIndex, FCDGeometry* baseMesh);
//
//   void completeInstanceExport(FCDControllerInstance* instance, FCDController* entity);
//   void completeControllerExport();
//
//   // Returns true if 'node' is of a supported shape type and it has a controller.
//   bool hasController(const MObject& node);
//   bool hasSkinController(const MObject& node);
//   bool hasMorphController(const MObject& node);

    private:

        DocumentExporter* mDocumentExporter;

        // A lookup table of elements we've already processed
//   ControllerList importedMorphControllers;
//   ControllerList skinControllers;
        unsigned long boneCounter; // ensure unique joint names

        // Support for Joint clusters pipeline
//  void getJointClusterInfluences(const MObject& controllerNode, MDagPathArray& influences, MObjectArray& weightFilters, uint clusterIndex);
    };

}

#endif // __COLLADA_MAYA_CONTROLLER_LIBRARY_H___