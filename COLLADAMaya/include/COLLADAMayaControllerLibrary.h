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
#include "COLLADALibraryControllers.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaSceneElement.h"

#include <vector>
#include <map>

#include <maya/MFnGeometryFilter.h>
#include <maya/MFnMesh.h>


namespace COLLADAMaya
{

#define WEIGHT_TOLERANCE 0.001f

#if MAYA_API_VERSION >= 650
#define MWeight double
#define MWeightArray MDoubleArray
#else
#define MWeight float
#define MWeightArray MFloatArray
#endif

//  typedef std::vector<ControllerInstance> ControllerInstanceList;
//  typedef std::vector<Controller> ControllerList;

    /**
     * Represents a controller.
     */
    class MayaController
    {
    public:

        /** The unique controller id. */
        String controllerId;

        /** The name of the controller. */
        String controllerName;

        /** List of influences. */
        MDagPathArray influences; // export-only

        /** A dynamically-sized array of 4x4 matrices. */
        std::vector<MMatrix> bindPoses; // export-only

//  ControllerInstanceList instances; // export-only;

        /**
         * Constructor
         * @param _controllerId The unique id of the current controller.
         */
        MayaController ( const String& _controllerId, const String& _controllerName ) 
        : controllerId(_controllerId) 
        , controllerName(_controllerName)
        {}

        /**
         * Destructor.
         */
        virtual ~MayaController() {}
    };
    typedef std::vector<MayaController*> ControllerList;


    typedef std::map<int, float> SkinControllerVertex;
    typedef std::map<String, MMatrix> SkinControllerJoint;

   /**
     * Holds the data for the skin controller to export.
     */
    class ColladaSkinController
    {
    public:

        /** The unique controller id. */
        String controllerId;

        /** The bind shape transform matrix. 
            Provides extra information about the position 
            and orientation of the base mesh before binding.*/
        MMatrix bindShapeTransform; 

        /** The list with the influences for the collada document. */
        std::vector<SkinControllerVertex> colladaVertexInfluences;

        /** The list with the joints for the collada document. */
        std::vector<SkinControllerJoint> colladaJoints;

    public:
        /**
        * Constructor
        * @param _controllerId The unique id of the current controller.
        */
        ColladaSkinController ( const String& _controllerId ) : controllerId(_controllerId) {}

        /**
        * Destructor.
        */
        virtual ~ColladaSkinController() {}
    };

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
    class ControllerLibrary : public COLLADA::LibraryControllers
    {

    private:
        
        /** Parameter, used for the bind poses transform. */
        static const String PARAM_TYPE_TRANSFORM;

        /** Parameter, used for the joint. */
        static const String PARAM_TYPE_JOINT;

        /** Parameter, used for the weight. */
        static const String PARAM_TYPE_WEIGHT;

        /** Pointer to the document exporter. */
        DocumentExporter* mDocumentExporter;

        // A lookup table of elements we've already processed
        ControllerList importedMorphControllers;
        ControllerList skinControllers;
        unsigned long boneCounter; // ensure unique joint names

    public:
        ControllerLibrary ( COLLADA::StreamWriter* streamWriter, DocumentExporter* documentExporter );
        virtual ~ControllerLibrary();

        /**
         * Exports all controllers in the current scene graph.
         */
        void exportControllers();

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

        /**
         * Recursive call to exports the controller of the current scene element
         * and all child elements.
         * @param sceneElement The element to export. 
         */
        void exportControllers(SceneElement* sceneElement);

        /**
        * Recursive call to exports the controller of the current scene element
        * and all child elements.
        * @param sceneElement The element to export. 
        * @return bool True, if a controller element was exported.
        */
        bool exportController(SceneElement* sceneElement);

        /**
        * Exports all the mesh affected nodes in the controller stack.
        * @param stack The controller stack.
        */
        void exportControllerStack( 
            const SceneElement* sceneElement, 
            const ControllerStack& stack );

        /**
        * Iterate upstream finding all the nodes which affect the mesh.
        * @param node The mesh node.
        * @param stack The controller stack for the affected nodes.
        * @param meshStack The controller stack for the affected meshes.
        * @return bool False, if the "inMesh" attribute is connected we don't have affected nodes.
        */
        bool findAffectedNodes( 
            const MObject& node, 
            ControllerStack& stack, 
            ControllerMeshStack& meshStack );

        /**
         * Exports a skin/joint cluster.
         * @param sceneElement The scene element to export.
         * @param controllerNode The node for the controller to export.
         * @param outputShape The path to the output shape.
         */
        void exportSkinController(
            const SceneElement* sceneElement, 
            const MObject controllerNode, 
            MDagPath outputShape );

        /**
         * Exports the current controller element.
         * @param skinTarget
         * @param colladaSkinController
         * @param targetController
         */
        void exportController( 
            String skinTarget, 
            ColladaSkinController colladaSkinController, 
            MayaController* targetController );

        /**
         * Exports the bind shape transform of the given controller.
         * @param colladaSkinController The collada skin controller with the values to export.
         */
        void exportBindShapeTransform( ColladaSkinController& colladaSkinController );

        /**
        * Exports the bind poses source of the given controller.
        * @param controllerId The controller id to export.
        * @param colladaSkinController The collada skin controller with the values to export.
        */
        void exportWeightSource( String controllerId, ColladaSkinController& colladaSkinController );

        /**
        * Exports the bind poses source of the given controller.
        * @param targetController The controller with the data to export.
         */
        void exportBindPosesSource( MayaController* targetController );

        /**
         * Exports the joint source of the given controller.
         * @param targetController The controller with the data to export.
         */
        void exportJointSource( MayaController* targetController );

        /**
         * Retrieve the instance information for this skinned character.
         * @param meshFn The current mesh object with the function set.
         * @param clusterFn The skinned character.
         * @param outputShape The output shape
         * @return uint The current cluster index.
         */
        uint retrieveInstanceInformation( 
            const MFnMesh& meshFn, 
            const MFnGeometryFilter& clusterFn, 
            MDagPath& outputShape );

        /**
         * Export the transform matrix for the shape.
         * @param clusterFn The cluster function set.
         * @param isJointCluster True, if it is a joint cluster.
         * @param clusterIndex The current cluster index for the skinned character.
         */
        void getBindShapeTransform(
            ColladaSkinController* skinController,
            const MFnGeometryFilter& clusterFn,
            const bool isJointCluster,
            const uint clusterIndex );

        /**
         * Gather the joints of the current controller node and writes them as 
         * the influences in the target controller object.
         * @param targetController The controller object to fill the bind poses.
         * @param controllerNode The controller node of the current object.
         * @param weightFilters The weight filters to fill.
         * @param clusterIndex The current cluster index for the skinned character.
         */
        void gatherJoints( 
            MayaController* targetController, 
            const MObject& controllerNode, 
            MObjectArray& weightFilters, 
            const uint clusterIndex );

        /**
         * Gather the bind matrices of the current controller node and writes 
         * them as the bind poses in the target controller object.
         * @param targetController The target controller to hold the data.
         * @param influences The list of 
         * @param controllerNode The controller node of the current object.
         */
        void gatherBindMatrices( 
            MayaController* targetController, 
            const MObject& controllerNode );

        /**
         * Support for joint clusters pipeline.
         * @param controllerNode The controller node.
         * @param influences The influences to fill.
         * @param weightFilters The weight filters to fill.
         * @param clusterIndex The current cluster index for the skinned character.
         */
        void getJointClusterInfluences(
            const MObject& controllerNode, 
            MDagPathArray& influences, 
            MObjectArray& weightFilters, 
            const uint clusterIndex );

         /**
          * Collects the data of the vertex weights and push it into the collada 
          * skin controller object.
          * @param skinController The collada skin controller object to export.
          * @param controllerNode The controller node.
          * @param outputShape The output shape
          * @param weightFilters The list of the weight filters of the current node.
          * @param clusterIndex The current cluster index for the skinned character.
          * @param numInfluences The number of influences.
          */
         void collectVertexWeights( 
             ColladaSkinController* skinController, 
             const MObject& controllerNode, 
             const MDagPath& outputShape,
             const MObjectArray& weightFilters, 
             const uint clusterIndex, 
             uint numInfluences );

         /**
          * Collects the vertex weights of a skin cluster filter.
          * @param colladaInfluences List for the vertex influences.
          * @param controllerNode The current controller node.
          * @param outputShape The current output shape.
          * @param numInfluences The number of vertex influences.
          */
         void collectSkinClusterFilterVertexWeights( 
             std::vector<SkinControllerVertex>& colladaInfluences, 
             const MObject& controllerNode, 
             const MDagPath& outputShape, 
             uint numInfluences );

         /**
          * @todo documentation
          * @param colladaInfluences List for the vertex influences.
          * @param weightFilters The list with the weight filters.
          * @param outputShape The current output shape.
          * @param clusterIndex The current cluster index.
          */
         void collectJointClusterVertexWeights( 
             std::vector<SkinControllerVertex>& colladaInfluences, 
             const MObjectArray &weightFilters, 
             const MDagPath &outputShape, 
             const uint clusterIndex );


        // Support for Joint clusters pipeline
//  void getJointClusterInfluences(const MObject& controllerNode, MDagPathArray& influences, MObjectArray& weightFilters, uint clusterIndex);
    };

}

#endif // __COLLADA_MAYA_CONTROLLER_LIBRARY_H___