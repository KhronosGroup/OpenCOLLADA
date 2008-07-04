/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#ifndef __COLLADA_MAYA_CONTROLLER_LIBRARY_H___
#define __COLLADA_MAYA_CONTROLLER_LIBRARY_H___

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaSceneElement.h"

#include <vector>

namespace COLLADAMaya
{

//  typedef std::vector<ControllerInstance> ControllerInstanceList;
//  typedef std::vector<Controller> ControllerList;

    /**
     * Represents a controller.
     */

    class Controller
    {

    public:
        MDagPathArray influences; // export-only
//  FMMatrix44List bindPoses; // export-only
//  ControllerInstanceList instances; // export-only;

        Controller ( const MObject& node ) {}

        virtual ~Controller() {}
    };

    typedef std::vector<Controller> ControllerList;

    /**
     * Holds any controller associated with the given plug.
     */

    struct ControllerStackItem
    {
        bool isSkin;
        MObject skinControllerNode;
        MObjectArray morphControllerNodes;
        std::vector<long> nodeStates;
    };

    typedef std::vector<ControllerStackItem*> ControllerStack;

    /**
    * Represents a mesh controller item.
    */

    struct ControllerMeshItem
    {
        MObject mesh;
        bool isIntermediate;
        bool isVisible;
    };

    typedef std::vector<ControllerMeshItem> ControllerMeshStack;

    /**
     * Class to control the skins and morphs
     */

    class ControllerLibrary
    {

    private:

        DocumentExporter* mDocumentExporter;

        // A lookup table of elements we've already processed
        ControllerList importedMorphControllers;
        ControllerList skinControllers;
        unsigned long boneCounter; // ensure unique joint names

    public:
        ControllerLibrary ( COLLADA::StreamWriter* streamWriter, DocumentExporter* documentExporter );
        virtual ~ControllerLibrary();

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

        /**
         * @todo documentation
         * @param sceneNode
         * @param dagPath
         * @param isSkin
         * @param instantiate
         */
        void exportController ( SceneElement* sceneNode,
                                bool isSkin,
                                bool instantiate=true );

        /**
         * @todo documentation
         * @param sceneNode
         * @param node
        * @return True, if the controller was exported.
         */
        bool exportController ( SceneElement* sceneNode, const MObject& node );

//   DaeEntity* exportMorphController(FCDSceneNode* sceneNode, MObjectArray& controllerNodes, DaeEntity* target);
//   DaeEntity* exportSkinController(MObject controllerNode, MDagPath outputShape, DaeEntity* target);
//   FCDGeometry* exportMorphTarget(MPlug& vertexListPlug, MPlug& targetComponentListPlug, uint targetIndex, FCDGeometry* baseMesh);
//
//   void completeInstanceExport(FCDControllerInstance* instance, FCDController* entity);
//   void completeControllerExport();
//
        // Returns true if 'node' is of a supported shape type and it has a controller.
        bool hasController ( const MObject& node );
        bool hasSkinController ( const MObject& node );
        bool hasMorphController ( const MObject& node );

    private:

        // Support for Joint clusters pipeline
//  void getJointClusterInfluences(const MObject& controllerNode, MDagPathArray& influences, MObjectArray& weightFilters, uint clusterIndex);
    };

}

#endif // __COLLADA_MAYA_CONTROLLER_LIBRARY_H___