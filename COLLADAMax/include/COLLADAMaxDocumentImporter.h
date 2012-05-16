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

#ifndef __COLLADAMAX_DOCUMENTIMPORTER_H__
#define __COLLADAMAX_DOCUMENTIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxConversionFunctor.h"
#include "COLLADAMaxTypes.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWMaterial.h"
#include "COLLADAFWEffect.h"
#include "COLLADAFWColor.h"
#include "COLLADAFWImage.h"
#include "COLLADAFWInstanceGeometry.h"
#include "COLLADAFWController.h"
#include "COLLADAFWMorphController.h"
#include "COLLADAFWSkinController.h"

#include <list>


class Interface;
class ImpInterface;
class DummyObject;
class Control;

namespace COLLADAFW
{
	class VisualScene;
	class Geometry;
	class UniqueId;
	class LibraryNodes;
	class Node;
	class Camera;
	class AnimationList;
}

namespace COLLADAMax
{

	class MaterialCreator;
	class ExtraDataHandler;


	class DocumentImporter 	: COLLADAFW::IWriter
	{
	public:
		enum ParsingPasses
		{
			GENERAL_PASS,			//!< The first pass to gather all data except controller data
			CONTROLLER_DATA_PASS    //!< The second pass to gather controller data
		};

		/** Maps Unique id to INodes.*/
		typedef std::multimap<COLLADAFW::UniqueId, INode*> UniqueIdINodeMultiMap;

		/** Const iterator of the map above.*/
		typedef UniqueIdINodeMultiMap::const_iterator UniqueIdINodeMultiMapConstIterator;

		/** Maps Unique id to ImpNodes.*/
		typedef std::multimap<COLLADAFW::UniqueId, ImpNode*> UniqueIdImpNodeMultiMap;

		/** Maps Unique id to INodes.*/
		typedef std::map<COLLADAFW::UniqueId, INode*> UniqueIdINodeMap;

		/** Maps Unique id to Objects.*/
		typedef std::map<COLLADAFW::UniqueId, Object*> UniqueIdObjectMap;

		/** Maps objects to Unique id to.*/
		typedef std::map< INode*, COLLADAFW::UniqueId> ObjectINodeUniqueIdMap;

		/** List of library nodes.*/
		typedef std::list<const COLLADAFW::LibraryNodes*> LibraryNodesList;

		/** List of nodes visual scenes.*/
		typedef std::map<COLLADAFW::UniqueId, const COLLADAFW::VisualScene*> UniqueIdVisualSceneMap;

		/** Maps Unique id to framework nodes.*/
		typedef std::map<COLLADAFW::UniqueId, const COLLADAFW::Node*> UniqueIdFWNodeMap;

		/** Maps unique ids of framework materials to the corresponding framework material.*/
		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Material> UniqueIdFWMaterialMap;

		/** Maps unique ids of framework images to the corresponding framework image.*/
		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Image> UniqueIdFWImageMap;

		/** Maps unique ids of framework effects to the corresponding framework material.*/
		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Effect> UniqueIdFWEffectMap;

		/** Vector of material bindings.*/
		typedef std::vector<COLLADAFW::MaterialBinding> MaterialBindingVector;

		/** Pair of nodes an the instantiated materials.*/
		struct NodeMaterialBindingsPair
		{
			INode* maxNode;
			MaterialBindingVector materialBindings;
		};

		/** List of all max nodes that reference a material and their material bindings.*/
		typedef std::list<NodeMaterialBindingsPair> NodeMaterialBindingsList;

		/** Maps frame work material ids to max material ids.*/
		typedef std::map<COLLADAFW::MaterialId,	MtlID > FWMaterialIdMaxMtlIdMap;

		/** Maps the unique id of a geometry to the material id mapping.*/
		typedef std::map<COLLADAFW::UniqueId, FWMaterialIdMaxMtlIdMap > GeometryMaterialIdMapMap;

		/** Maps sets ( index for multiple texcoords) to the max map channel this set of tex coordinates has been saved in.*/
		typedef std::map<size_t /* Set index*/, int /* Max map channel*/ > SetMapChannelMap;

		/** Maps each geometry to its  SetMapChannelMap.*/
		typedef std::map<COLLADAFW::UniqueId /* geometry unique id*/, SetMapChannelMap > GeometrySetMapChannelMap;

		/** List of inode inode pairs.*/
		typedef std::vector<std::pair<INode*, INode*>> INodeINodePairList;

		/** Maps an object to its name.*/
		typedef std::map<Object*, String > ObjectObjectNameMap;

		/** A list of max controllers.*/
		typedef std::vector<Control*> MaxControllerList;

		/** Maps each already imported frame work animation to a list of created max float controllers.*/
		typedef std::map< COLLADAFW::UniqueId /* Animation*/, MaxControllerList> UniqueIdMaxControllerListMap;

		/** Holds all already imported animation list, sorted by their unique id.*/
		typedef std::map< COLLADAFW::UniqueId /* AnimationList*/, COLLADAFW::AnimationList*> UniqueIdAnimationListMap;

		/** Maps unique ids of controller data to the corresponding controller.*/
		typedef std::multimap< COLLADAFW::UniqueId /* Controller data*/, const COLLADAFW::Controller*> UniqueIdControllerMultiMap;

		/** Maps Unique ids of morph controllers to the morph controller.*/
		typedef std::map< COLLADAFW::UniqueId /* Controller data*/, const COLLADAFW::MorphController* > UniqueIdMorphControllerMap;

		/** Maps Unique ids of skin controllers to the skin controller.*/
		typedef std::map< COLLADAFW::UniqueId /* Controller data*/, const COLLADAFW::SkinController* > UniqueIdSkinControllerMap;

		/** List of light pairs.*/
		typedef std::vector< COLLADAFW::Light > LightList;

		struct FileInfo
		{
			COLLADABU::URI absoluteFileUri;
			float unitScale;

		};

		/** List of unique ids.*/
		typedef std::vector< COLLADAFW::UniqueId > UniqueIdList;

		struct UnitConversionFunctors
		{
			ConversionFunctor* lengthConversion;
			ConversionFunctor* inverseLengthConversion;
			ConversionFunctor* angleConversion;
			ConversionFunctor* timeConversion;
		};

		/** Maps unique ids of framework materials to the corresponding framework material.*/
		typedef std::map<COLLADAFW::UniqueId, SkyLightParameters> UniqueIdSkyLightMap;
			
	private:
		/** Max interface.*/
		Interface* mMaxInterface;

		/** Max import interface.*/
		ImpInterface* mMaxImportInterface;

		/** File path of the COLLADA document to import.*/
		NativeString mImportFilePath;

		/** Time in seconds when the instance of th importer was created.*/
		double mStartTime;

		/** The accumulated ambient color.*/
		COLLADAFW::Color mAmbientColor;

		/** The number of ambient colors already added.*/
		size_t mNumberOfAmbientColors;

		/** A dummy helper, that is used for nodes that do not have an object assigned to.*/
		DummyObject* mDummyObject;
		
		/** Maps the unique ids of objects (geometries, controllers,...) that are referenced by INodes to 
		these referencing INodes. This map is being filled while importing the visual scene. It is 
		required for objects that are referenced before they are imported.*/
		UniqueIdINodeMultiMap mUniqueIdObjectINodeMap;

		/** Maps the unique ids of objects (geometries, controllers,...) to the created max object. This map 
		is being filled while importing geometries. */
		UniqueIdObjectMap mUniqueIdObjectMap;

		/** Maps the unique ids of nodes to the created max INode. This map is being filled while importing 
		the visual scene. It is required when ever nodes are referenced, after they have been imported.*/
		UniqueIdINodeMap mUniqueIdINodeMap;

		/** Maps the unique ids of nodes that are instantiated to the created instantiating max INode. This 
		map is being filled while importing the visual scene. It is required when ever nodes are referenced, 
		before they have been imported.*/
		UniqueIdImpNodeMultiMap mUniqueIdReferencingImpNodeMap;

		/** Maps each already imported object to its Unique id. When ever a new object is created it 
		should be added to this map. .*/
		ObjectINodeUniqueIdMap mObjectINodeUniqueIdMap;

		/** Maps Unique ids of nodes that are in a library nodes but not already in the max scene graph to
		the frame word node itself. Each frame work node, that is in a library nodes but not immediately added 
		to the max scene graph should be added to that map. When looking for referenced nodes check this map if
		the referenced node is not already in the max scene graph.*/
		UniqueIdFWNodeMap mUniqueIdFWNodeMap;

		/** This vector contains all library nodes already received by the importer.*/
		LibraryNodesList mLibraryNodesList;

		/** Maps unique ids to visual scene already received by the importer.*/
		UniqueIdVisualSceneMap mUniqueIdVisualSceneMap;

		/** Maps unique ids of framework materials to the corresponding framework material.*/
		UniqueIdFWMaterialMap mUniqueIdFWMaterialMap;

		/** Maps unique ids of framework effects to the corresponding framework effect.*/
		UniqueIdFWEffectMap mUniqueIdFWEffectMap;

		/** Maps unique ids of framework images to the corresponding framework image.*/
		UniqueIdFWImageMap mUniqueIdFWImageMap;

		/** of all max nodes that reference a material and their material bindings.*/
		NodeMaterialBindingsList mNodeMaterialBindingsList;

		/** Maps the unique id of a geometry to the material id mapping.*/
		GeometryMaterialIdMapMap mGeometryMaterialIdMapMap;

		/** Maps each geometry to its  SetMapChannelMap.*/
		GeometrySetMapChannelMap mGeometrySetMapChannelMap;

		/** List of pairs of cloned nodes and their originals. This is used to assign materials. When ever
		an inode is cloned, the cloned one and itself should be added to that list.*/
		INodeINodePairList mClonedINodeOriginalINodePairList;

		/** Maps an object to its name. Whenever an object is created, add it with its name to this map.*/
		ObjectObjectNameMap mObjectObjectNameMap;

		/** List of unique ids of objects that use vertex color. When ever a geometry that uses vertex color is created,
		its unique id should be added to this list.*/
		UniqueIdList mVertexColorObjects;

		/** Maps each already imported frame work animation to a list of created max float controllers.*/
		UniqueIdMaxControllerListMap mAnimationUniqueIdMaxControllerListMap;

		/** Holds all already imported animation list, sorted by their unique id.*/
		UniqueIdAnimationListMap mUniqueIdAnimationListMap;

		/** Maps unique ids of controller data to the corresponding controller.*/
		UniqueIdControllerMultiMap mUniqueIdControllerMap;

		/** Maps Unique ids of all morph controllers found during the first pass to the morph controller.*/
		UniqueIdMorphControllerMap mUniqueIdMorphControllersMap;

		/** Maps the unique ids of  morph controllers that are NOT instantiated in the scene graph but 
		used as source by a skin controller to the INode that references this skin controller.*/
		UniqueIdINodeMap mMorphUniqueIdINodeMap;

		/** Maps Unique ids of all skin controllers found during the first pass to the skin controller.*/
		UniqueIdSkinControllerMap mUniqueIdSkinControllersMap;

		/** List of light pairs. USed to assign animations to light parameters.*/
		LightList mLightList;

		// TODO check if we need this map
		/** Maps unique ids of  skin controller to the INode that references the controller.*/
		UniqueIdINodeMap mSkinControllerINodeMap;

		/** Holds informations about the entire file being loaded.*/
		FileInfo mFileInfo;

		/** Functors used to convert values from frame work units into max units.*/
		UnitConversionFunctors mUnitConversionFunctors;

		/** The current pass we are performing.*/
		ParsingPasses mCurrentParsingPass;

		/** If set to true, 1-transparency is used as transparency. This used to circumvent wrong transparency 
		handling Google SketchUp COLLADA exporter*/
		bool mInvertTransparency;

		ExtraDataHandler* mExtraDataHandler;

		UniqueIdSkyLightMap mUniqueIdSkyLightMap;

	public:
		/** Constructor .
		@param maxInterface The max interface.
		@param the file name of the file to import.*/
		DocumentImporter(Interface * maxInterface, ImpInterface* maxImportInterface, const NativeString &filepath);

		virtual ~DocumentImporter();

		/** Start the import of the model.
		@return True on success, false otherwise. */
		bool import();

		/** Prints a message in the max gui. Only for debugging purposes.*/
		void printMessage( const String& message);

		/* Returns the time elapsed the instantiation of the importer.*/
		double getElapsedTime() const;

		/** Creates a new max object with @a superClassId and @a classId. If the object could not be created, 
		null is returned.*/
		void* createMaxObject(SClass_ID superClassId, Class_ID classId);

		/** Returns the max interface.*/
		Interface* getMaxInterface() { return mMaxInterface; }

		/** Returns the max interface.*/
		ImpInterface* getMaxImportInterface() { return mMaxImportInterface; }

		/** Returns the accumulated ambient color.*/
		const COLLADAFW::Color& getAmbientColor() const { return mAmbientColor; }

		/** Returns the number of accumulated ambient colors.*/
		size_t getNumberOfAmbientColors() const { return mNumberOfAmbientColors; }

		/** Adds @a ambientColor to the total ambient color.*/
		void addAmbientColor( const COLLADAFW::Color& ambientColor);

		/** Converts @a originalValue in units provided by file info to units currently set in max.*/
		float convertSpaceUnit( float originalValue );

		/** If set to true, 1-transparency is used as transparency. This used to circumvent wrong transparency 
		handling Google SketchUp COLLADA exporter*/
		bool getInvertTransparency() const { return mInvertTransparency; }


		/** Deletes the entire scene.
		@param errorMessage A message containing informations about the error that occurred.
		*/
		void cancel(const String& errorMessage){};

		/** Prepare to receive data.*/
		void start(){};

		/** Remove all objects that don't have an object. Deletes unused visual scenes.*/
		void finish(){};

		/** When this method is called, the writer must write the global document asset.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeGlobalAsset ( const COLLADAFW::FileInfo* asset );;

		/** Writes the scene.
		@return True on succeeded, false otherwise.*/
		virtual bool writeScene ( const COLLADAFW::Scene* Scene )
		{
			return true;
		}

		/** Writes the entire visual scene.
		@return True on succeeded, false otherwise.*/
		virtual bool writeVisualScene ( const COLLADAFW::VisualScene* visualScene );

		/** Handles all nodes in the library nodes.
		@return True on succeeded, false otherwise.*/
		virtual bool writeLibraryNodes( const COLLADAFW::LibraryNodes* libraryNodes );

		/** Writes the geometry.
		@return True on succeeded, false otherwise.*/
		virtual bool writeGeometry ( const COLLADAFW::Geometry* geometry );

		/** Writes the material.
		@return True on succeeded, false otherwise.*/
		virtual bool writeMaterial( const COLLADAFW::Material* material );

		/** Writes the effect.
		@return True on succeeded, false otherwise.*/
		virtual bool writeEffect( const COLLADAFW::Effect* effect );

		/** Writes the camera.
		@return True on succeeded, false otherwise.*/
		virtual bool writeCamera( const COLLADAFW::Camera* camera );

		/** Writes the image.
		@return True on succeeded, false otherwise.*/
		virtual bool writeImage( const COLLADAFW::Image* image );

		/** Writes the light.
		@return True on succeeded, false otherwise.*/
		virtual bool writeLight( const COLLADAFW::Light* light );

		/** Writes the animation.
		@return True on succeeded, false otherwise.*/
		virtual bool writeAnimation( const COLLADAFW::Animation* animation );

		/** Writes the animation.
		@return True on succeeded, false otherwise.*/
		virtual bool writeAnimationList( const COLLADAFW::AnimationList* animationList );

		/** When this method is called, the writer must write the skin controller data.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeSkinControllerData( const COLLADAFW::SkinControllerData* skinControllerData );

		/** When this method is called, the writer must write the controller.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeController( const COLLADAFW::Controller* Controller );

		/** When this method is called, the writer must write the formulas. All the formulas of the entire
		COLLADA file are contained in @a formulas.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeFormulas( const COLLADAFW::Formulas* formulas ) { return true; }

		/** When this method is called, the writer must write the kinematics scene. 
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeKinematicsScene( const COLLADAFW::KinematicsScene* kinematicsScene ) { return true; }


	private:
        /** Disable default copy ctor. */
		DocumentImporter( const DocumentImporter& pre );
        /** Disable default assignment operator. */
		const DocumentImporter& operator= ( const DocumentImporter& pre );

		/** Assigns the imported controllers (animations)to the corresponding objects.*/
		bool assignControllers( const MaterialCreator& materialCreator );

		/** Creates the scene graph.*/
		bool createSceneGraph();

		/** Creates the scene graph.*/
		bool createMorphController();

		/** Returns the dummy object used for nodes that do not have an object assigned to.*/
		DummyObject* getDummyObject(){ return mDummyObject; }

		/** Returns the UniqueId Object INode Mapping.*/
		UniqueIdINodeMultiMap& getUniqueIdObjectINodeMap(){ return mUniqueIdObjectINodeMap; }

		/** Returns the UniqueId Referencing INode Mapping.*/
		UniqueIdImpNodeMultiMap& getUniqueIdReferencingImpNodeMap(){ return mUniqueIdReferencingImpNodeMap; }

		/** Returns the UniqueId object Mapping.*/
		UniqueIdObjectMap& getUniqueIdObjectMap(){ return mUniqueIdObjectMap; }

		/** Returns the UniqueId INode Mapping.*/
		UniqueIdINodeMap& getUniqueIdINodeMap(){ return mUniqueIdINodeMap; }

		/** Returns the object UniqueId Mapping.*/
		ObjectINodeUniqueIdMap& getObjectINodeUniqueIdMap(){ return mObjectINodeUniqueIdMap; }

		/** Returns the Unique id framework node map.*/
		UniqueIdFWNodeMap& getUniqueIdFWNodeMap() { return mUniqueIdFWNodeMap; }

		/** Returns the list of library nodes.*/
		LibraryNodesList& getLibraryNodesList(){ return mLibraryNodesList; }

		/** Returns the map of unique id to visual scenes.*/
		UniqueIdVisualSceneMap& getUniqueIdVisualSceneMap(){ return mUniqueIdVisualSceneMap; }

		/** Returns the UniqueIdFWMaterialMap.*/
		UniqueIdFWMaterialMap& getUniqueIdFWMaterialMap() { return mUniqueIdFWMaterialMap; }

		/** Returns the UniqueIdFWEffectMap.*/
		UniqueIdFWEffectMap& getUniqueIdFWEffectMap() { return mUniqueIdFWEffectMap; }

		/** Returns the UniqueIdFWImageMap.*/
		UniqueIdFWImageMap& getUniqueIdFWImageMap() { return mUniqueIdFWImageMap; }

		/** Returns the NodeMaterialBindingsList.*/
		NodeMaterialBindingsList& getNodeMaterialBindingsList() { return mNodeMaterialBindingsList; }

		/** Return the GeometryMaterialIdMapMap.*/
		GeometryMaterialIdMapMap& getGeometryMaterialIdMapMap() { return  mGeometryMaterialIdMapMap; }

		/** Returns the GeometrySetMapChannelMap.*/
		GeometrySetMapChannelMap& getGeometrySetMapChannelMap() { return mGeometrySetMapChannelMap; }

		UniqueIdSkyLightMap& getUniqueIdSkyLightMap() { return mUniqueIdSkyLightMap; }

		/**Returns the list of pairs of cloned nodes and their originals. This is used to assign materials. 
		When ever an inode is cloned, the cloned one and itself should be added to that list.*/
		INodeINodePairList& getClonedINodeOriginalINodePairList() { return mClonedINodeOriginalINodePairList; }

		/** Returns the map, that maps an object to its name. Whenever an object is created, add it with 
		its name to this map.*/
		ObjectObjectNameMap& getObjectObjectNameMap() { return mObjectObjectNameMap; }

		/** Returns the list of unique ids of objects that use vertex color. When ever a geometry that uses vertex color is created,
		its unique id should be added to this list.*/
		UniqueIdList& getVertexColorObjects() { return  mVertexColorObjects; }

		/** Maps each already imported frame work animation to a list of created max float controllers.*/
		UniqueIdMaxControllerListMap& getAnimationUniqueIdMaxControllerListMap() { return mAnimationUniqueIdMaxControllerListMap; }

		/** Holds all already imported animation list, sorted by their unique id.*/
		UniqueIdAnimationListMap&  getUniqueIdAnimationListMap() { return mUniqueIdAnimationListMap; }

		/** Maps unique ids of controller data to the corresponding controller.*/
		UniqueIdControllerMultiMap& getUniqueIdControllerMap() { return mUniqueIdControllerMap; }

		/** Maps Unique ids of all morph controllers found during the first pass to the morph controller.*/
		UniqueIdMorphControllerMap& getUniqueIdMorphControllerMap() { return mUniqueIdMorphControllersMap; }

		/** Maps Unique ids of all skin controllers found during the first pass to the skin controller.*/
		UniqueIdSkinControllerMap& getUniqueIdSkinControllerMap() { return mUniqueIdSkinControllersMap; }

		/** List of light pairs. Used to assign animations to light parameters.*/
		LightList& getLightList() { return  mLightList; }

		/** Maps unique ids of  skin controller to the INode that references the controller.*/
		UniqueIdINodeMap& getSkinControllerINodeMap() { return mSkinControllerINodeMap; }

		/** Maps the unique ids of  morph controllers that are NOT instantiated in the scene graph but 
		used as source by a skin controller to the INode that references this skin controller.*/
		UniqueIdINodeMap& getMorphUniqueIdINodeMap() { return mMorphUniqueIdINodeMap; }

		/** Functors used to convert values from frame work units into max units.*/
		const UnitConversionFunctors& getUnitConversionFunctors() const { return mUnitConversionFunctors; }

		/** Returns informations about the entire file being loaded.*/
		const FileInfo& getFileInfo() const { return mFileInfo; }
		friend class ImporterBase;

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_DOCUMENTIMPORTER_H__
