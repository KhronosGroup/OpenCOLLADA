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
#ifndef __COLLADA_MAYA_CONTROLLER_EXPORTER_H___
#define __COLLADA_MAYA_CONTROLLER_EXPORTER_H___

#include "COLLADAMayaStableHeaders.h"
#include "COLLADASWLibraryControllers.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaSceneElement.h"
#include "COLLADAMayaBaseController.h"
#include "COLLADAMayaSkinController.h"
#include "COLLADAMayaMorphController.h"

#include "COLLADABUIDList.h"

#include <vector>
#include <map>

#include <maya/MFnGeometryFilter.h>
#include <maya/MFnMesh.h>


namespace COLLADAMaya
{

#define WEIGHT_TOLERANCE 0.001f

#if MAYA_API_VERSION >= 650 
#define Weight double
#define WeightArray MDoubleArray
#else
#define Weight float
#define WeightArray MFloatArray
#endif


    /**
     * Holds any controller associated with the given plug.
     */
    struct ControllerStackItem
    {
        bool isSkin;
        MObject skinControllerNode;
        float envelope; // Used to disable the blend shape.
        MObjectArray morphControllerNodes;
        std::vector<int> nodeStates;
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
    class ControllerExporter : public COLLADASW::LibraryControllers
    {
    private:

        /** Parameter, used for the bind poses transform. */
        static const String PARAM_TYPE_TRANSFORM;

        /** Parameter, used for the joint. */
        static const String PARAM_TYPE_JOINT;

        /** Parameter, used for the morph target. */
        static const String PARAM_TYPE_MORPH_TARGET;

        /** Parameter, used for the morph weight. */
        static const String PARAM_TYPE_MORPH_WEIGHT;

        /** Parameter, used for the weight. */
        static const String PARAM_TYPE_WEIGHT;

    private:

        /** 
         * Pointer to the document exporter. 
         */
        DocumentExporter* mDocumentExporter;

        /**
        * The list of the unique collada ids.
        */
        COLLADABU::IDList mControllerIdList;

        /**
        * A collada id for every maya id.
        */
        StringToStringMap mMayaIdColladaIdMap;

        /** 
         * List of controllerIds from the already exported controllers. 
         */
        std::vector<String> mExportedControllers;

        /** 
         * A list of the exported controller scene elements. 
         */
        std::vector<SceneElement*> mExportedControllerSceneElements;

    public:

        /**
         * Constructor.
         * @param streamWriter
         * @param documentExporter
         */
        ControllerExporter ( COLLADASW::StreamWriter* streamWriter, DocumentExporter* documentExporter );
        virtual ~ControllerExporter();

        /**
         * Exports all controllers in the current scene graph.
         */
        void exportControllers();

        /** Returns true if 'node' is of a supported shape type and it has a controller. */
        bool hasController ( const MObject& node );
        bool hasSkinController ( const MObject& node );
        bool hasMorphController ( const MObject& node );

        /**
        * Iterate upstream finding all the nodes which affect the mesh.
        * @param node The mesh node.
        * @param stack The controller stack for the affected nodes.
        * @param meshStack The controller stack for the affected meshes.
        * @return bool False, if the "inMesh" attribute is connected we don't have affected nodes.
        */
        static bool findAffectedNodes(
            const MObject& node,
            ControllerStack& stack,
            ControllerMeshStack& meshStack );

        /** Disable the blend shape influences. */
        static void disableBlendShape ( ControllerStack &stack );

        /** Enable the blend shape influences. */
        static void enableBlendShape ( ControllerStack &stack );

        /**
         * Disables any effects on the node so that fewer calculations are
         * necessary at the time of redraw. The effect does not render until
         * you reset the Node State back to Normal. Maya evaluates the nodes in
         * the node’s history, but not the node itself.
         * @param stack The stack with the controller nodes.
         */
        static void setControllerNodeStatesToNoEffect( ControllerStack &stack );

        /**
        * Reset all the controller node states.
        * @param stack The stack with the controller nodes.
        */
        static void resetControllerNodeStates( ControllerStack &stack );

        /**
         * Set all meshes as visible and not intermediate.
         * @param meshStack The stack with the meshes to reset the parameters.
         */
        static void setValidMeshParameters( ControllerMeshStack &meshStack );

        /**
        * Reset the intermediate and visibility mesh parameters.
        * @param meshStack The stack with the meshes to reset the parameters.
        */
        static void resetMeshParameters( ControllerMeshStack &meshStack );

        /**
         * Delete the stack items.
         * @param stack The stack with the controller nodes.
         */
        static void deleteControllerStackItems ( ControllerStack &stack );

        /**
        * A collada id for every maya id.
        */
        const String findColladaControllerId ( const String& mayaControllerId );

    private:

        /** Returns the tolerance value for double value comparison. */
        const double getTolerance () const 
        {
            return mDocumentExporter->getTolerance ();
        }

        /**
         * Recursive call to exports the controller of the current scene element
         * and all child elements.
         * @param sceneElement The element to export.
         */
        void exportControllers ( SceneElement* sceneElement );

        /**
        * Recursive call to exports the controller of the current scene element
        * and all child elements.
        * @param sceneElement The element to export.
        * @return bool True, if a controller element was exported.
        */
        bool exportController ( SceneElement* sceneElement );

        /**
        * Returns true, if the scene element is in the list of exporterd elements.
        */
        bool findExportedContollerSceneElement ( const SceneElement* sceneElement );

        /**
        * Exports all the mesh affected nodes in the controller stack.
        * @param stack The controller stack.
        */
        void exportControllerStack (
            SceneElement* sceneElement,
            const ControllerStack& stack );

        /**
         * Exports a skin/joint cluster.
         * @param sceneElement The scene element to export.
         * @param controllerNode The node for the controller to export.
         * @param outputShape The path to the output shape.
         */
        void exportSkinController (
            SceneElement* sceneElement,
            const MObject controllerNode,
            MDagPath outputShape );

        /**
         * Exports the morph controllers of a mesh.
         * @param sceneElement The scene element to export.
         * @param controllerNodes The morph controller nodes to export.
         */
        void exportMorphController (
            SceneElement* sceneElement,
            MObjectArray& controllerNodes );


        void exportMorphTarget (
            MPlug& targetVertexListPlug,
            MPlug& targetComponentListPlug,
            uint currentIndex );

        /**
         * Writes all data of the current controller element into the collada file.
         * @param skinTarget The skin target.
         * @param skinController Reference to the collada skin controller with the export data.
         */
        void writeSkinController (
            const String skinTarget,
            const SkinController& skinController );

        /**
         * Writes all data of the current controller element into the collada file.
         * @param skinTarget The morph target.
         * @param skinController Reference to the collada morph controller with the export data.
         */
        void writeMorphController (
            const String morphTarget,
            const MorphController &morphController );

        /**
         * Writes the joint element into the collada document.
         * @param skinController
         *          Reference to the collada skin controller with the export data.
         */
        void writeSkinElementJoints( const SkinController& skinController );

        /**
         * Writes the target element into the collada document.
         * @param morphController
         *          Reference to the collada controller with the export data.
         */
        void writeMorphElementTargets( const MorphController &morphController );

        /**
         * Writes the vertex weights element into the collada document.
         * @param skinController
         *          Reference to the collada skin controller with the export data.
         */
        void writeSkinElementVertexWeights( const SkinController &skinController );

        /**
         * Exports the bind shape transform of the given controller.
         * @param skinController
         *          Reference to the collada skin controller with the export data.
         */
        void writeSkinBindShapeTransform( const SkinController& skinController );

        /**
        * Exports the bind poses source of the given controller.
        * @param skinController
        *          Reference to the collada skin controller with the export data.
        */
        void writeSkinWeightSource( const SkinController& skinController );

        /**
        * Exports the bind poses source of the given controller.
        * @param morphController
        *          Reference to the collada morph controller with the export data.
        */
        void writeMorphWeightSource( const MorphController& morphController );

        /**
        * Exports the bind poses source of the given controller.
        * @param skinController
        *          Reference to the collada skin controller with the export data.
         */
        void writeSkinBindPosesSource( const SkinController& skinController );

        /**
         * Exports the joint source of the given controller.
         * @param skinController
         *          Reference to the collada skin controller with the export data.
         */
        void writeSkinJointSource( const SkinController& skinController );

        /**
        * Exports the target source of the given controller.
        * @param morphController
        *          Reference to the collada morph controller with the export data.
         */
        void writeMorphTargetSource( const MorphController &morphController );

        /**
         * Retrieve the instance information for this skinned character.
         * @param clusterFn The skinned character.
         * @param outputShape The output shape
         * @return uint The current cluster index.
         */
        uint retrieveInstanceInformation(
            const MFnGeometryFilter& clusterFn,
            MDagPath& outputShape );

        /**
         * Export the transform matrix for the shape.
         * @param clusterFn The cluster function set.
         * @param isJointCluster True, if it is a joint cluster.
         * @param clusterIndex The current cluster index for the skinned character.
         */
        void getBindShapeTransform(
            SkinController* skinController,
            const MFnGeometryFilter& clusterFn,
            const bool isJointCluster,
            const uint clusterIndex, 
            SceneElement* sceneElement );

        /**
         * Gather the joints of the current controller node and writes them as
         * the influences in the target controller object.
         * @param targetController The controller object to fill the bind poses.
         * @param controllerNode The controller node of the current object.
         * @param weightFilters The weight filters to fill.
         * @param clusterIndex The current cluster index for the skinned character.
         */
        void gatherJoints(
            SkinController* skinController,
            const MObject& controllerNode,
            MObjectArray& weightFilters,
            const uint clusterIndex );

        /**
         * Gather the bind matrices of the current controller node and writes
         * them as the bind poses in the target controller object.
         * @param skinController The controller to hold the data.
         * @param controllerNode The controller node of the current object.
         */
        void gatherBindMatrices(
            SkinController* skinController,
            const MObject& controllerNode,
			SceneElement* UpperSceneNode);

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
        * Creates the joints.
        * @param skinController The skin controller with the joint imformation.
        */
        void createJoints( SkinController* skinController );

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
             SkinController* skinController,
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
    };

}

#endif // __COLLADA_MAYA_CONTROLLER_EXPORTER_H___
