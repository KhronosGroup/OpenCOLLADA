/*
Copyright (c) 2009 NetAllied Systems GmbH

This file is part of dae2ogre.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2OGRE_OGREWRITER_H__
#define __DAE2OGRE_OGREWRITER_H__

#include "DAE2OgrePrerequisites.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWUniqueId.h"
#include "COLLADAFWVisualScene.h"
#include "COLLADAFWLibraryNodes.h"
#include "COLLADAFWMaterial.h"
#include "COLLADAFWEffect.h"
#include "COLLADAFWImage.h"

#include "COLLADABUURI.h"
#include "Math/COLLADABUMathMatrix4.h"

#include <stack>
#include <list>
#include <map>

namespace DAE2Ogre
{

	class BaseWriter;

	class OgreWriter : public COLLADAFW::IWriter
	{
	public:
		enum Runs
		{
			SCENEGRAPH_RUN,
			GEOMETRY_RUN
		};

		typedef std::list<COLLADAFW::LibraryNodes> LibraryNodesList;

		struct InstanceGeometryInfo
		{
			InstanceGeometryInfo( COLLADAFW::InstanceGeometry* _fwInstanceGeometry, const COLLADABU::Math::Matrix4& _worldMatrix)
				:  fwInstanceGeometry(_fwInstanceGeometry), worldMatrix(_worldMatrix) {}
			COLLADAFW::InstanceGeometry* fwInstanceGeometry;
			COLLADABU::Math::Matrix4 worldMatrix;
		};

		typedef std::multimap<COLLADAFW::UniqueId, InstanceGeometryInfo> GeometryUniqueIdInstanceGeometryInfoMap;

		/** Maps unique ids of framework materials to the corresponding framework material.*/
		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Material> UniqueIdFWMaterialMap;

		/** Maps unique ids of framework images to the corresponding framework image.*/
		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Image> UniqueIdFWImageMap;

		/** Maps unique ids of framework effects to the corresponding framework material.*/
		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Effect> UniqueIdFWEffectMap;

		enum Severity
		{
			SEVERITY_INFORMATION,
			SEVERITY_WARNING,
			_SEVERITY_ERROR
		};


	private:
		COLLADABU::URI mInputFile;
		COLLADABU::URI mOutputFile;
		Runs mCurrentRun;

		const COLLADAFW::VisualScene* mVisualScene;
		LibraryNodesList mLibrayNodesList;

		GeometryUniqueIdInstanceGeometryInfoMap mGeometryUniqueIdInstanceGeometryInfoMap;

		UniqueIdFWMaterialMap mUniqueIdFWMaterialMap;
		UniqueIdFWImageMap mUniqueIdFWImageMap;
		UniqueIdFWEffectMap mUniqueIdFWEffectMap;
	
	public:
		OgreWriter( const COLLADABU::URI& inputFile, const COLLADABU::URI& outputFile );
		virtual ~OgreWriter();

	public:
		static void reportError(const String& method, const String& message, Severity severity);

	public:

		bool write();

		/** Deletes the entire scene.
		@param errorMessage A message containing informations about the error that occurred.
		*/
		void cancel(const String& errorMessage);;

		/** Prepare to receive data.*/
		void start();;

		/** Remove all objects that don't have an object. Deletes unused visual scenes.*/
		void finish();;

		/** When this method is called, the writer must write the global document asset.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeGlobalAsset ( const COLLADAFW::FileInfo* asset );

		/** Writes the entire visual scene.
		@return True on succeeded, false otherwise.*/
		virtual bool writeVisualScene ( const COLLADAFW::VisualScene* visualScene );

		/** Writes the scene.
		@return True on succeeded, false otherwise.*/
		virtual bool writeScene ( const COLLADAFW::Scene* scene );

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

		/** Writes the skin controller data.
		@return True on succeeded, false otherwise.*/
		virtual bool writeSkinControllerData( const COLLADAFW::SkinControllerData* skinControllerData );

		/** Writes the controller.
		@return True on succeeded, false otherwise.*/
		virtual bool writeController( const COLLADAFW::Controller* Controller );

		/** When this method is called, the writer must write the formulas. All the formulas of the entire
		COLLADA file are contained in @a formulas.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeFormulas( const COLLADAFW::Formulas* formulas ){return true;}

		/** When this method is called, the writer must write the kinematics scene. 
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeKinematicsScene( const COLLADAFW::KinematicsScene* kinematicsScene ){return true;};


	
	protected:
		friend class BaseWriter;

		GeometryUniqueIdInstanceGeometryInfoMap& getGeometryUniqueIdInstanceGeometryInfoMap() { return mGeometryUniqueIdInstanceGeometryInfoMap; }

		UniqueIdFWMaterialMap& getUniqueIdFWMaterialMap() { return mUniqueIdFWMaterialMap; }

		UniqueIdFWImageMap& getUniqueIdFWImageMap() { return mUniqueIdFWImageMap; }

		UniqueIdFWEffectMap& getUniqueIdFWEffectMap() { return mUniqueIdFWEffectMap; }

		const COLLADABU::URI& getInputFile() const { return mInputFile; }

		const COLLADABU::URI& getOutputFile() const { return mOutputFile; }


	private:
        /** Disable default copy ctor. */
		OgreWriter( const OgreWriter& pre );
        /** Disable default assignment operator. */
		const OgreWriter& operator= ( const OgreWriter& pre );

	};
} // namespace DAE2Ogre

#endif // __DAE2OGRE_OGREWRITER_H__
