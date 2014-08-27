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
#include "COLLADAMaxDocumentImporter.h"
#include "COLLADAMaxVisualSceneImporter.h"
#include "COLLADAMaxLibraryNodesImporter.h"
#include "COLLADAMaxGeometryImporter.h"
#include "COLLADAMaxMaterialImporter.h"
#include "COLLADAMaxMaterialCreator.h"
#include "COLLADAMaxEffectImporter.h"
#include "COLLADAMaxCameraImporter.h"
#include "COLLADAMaxLightImporter.h"
#include "COLLADAMaxImageImporter.h"
#include "COLLADAMaxAnimationImporter.h"
#include "COLLADAMaxAnimationListImporter.h"
#include "COLLADAMaxControllerImporter.h"
#include "COLLADAMaxSkinControllerDataImporter.h"
#include "COLLADAMaxAnimationAssigner.h"
#include "COLLADAMaxSceneGraphCreator.h"
#include "COLLADAMaxMorphControllerCreator.h"
#include "COLLADAMaxFWLErrorHandler.h"
#include "COLLADAMaxExtraDataHandler.h"

#include "COLLADAFWFileInfo.h"

#include "COLLADAFWLibraryNodes.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWVisualScene.h"
#include "COLLADAFWInstanceVisualScene.h"
#include "COLLADAFWScene.h"


#include "COLLADASaxFWLLoader.h"
#include "COLLADAFWRoot.h"

#include <sys/types.h>
#include <sys/timeb.h> 


namespace COLLADAMax
{

	const char AUTORING_TOOL[] = "authoring_tool";
	const char GOOGLE_SKETCHUP6[] = "Google SketchUp 6";
	const char GOOGLE_SKETCHUP70[] = "Google SketchUp 7.0";
	const char MICROSTATION[] = "MicroStation";

	static const COLLADABU::Math::Matrix4 X_UPAXIS_CORRECTION( 0, 0, -1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1);
	static const COLLADABU::Math::Matrix4 Y_UPAXIS_CORRECTION( 1, 0, 0, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 1);


	//--------------------------------------------------------------------
	DocumentImporter::DocumentImporter(Interface * maxInterface, ImpInterface* maxImportInterface, const NativeString &filepath)
		: mMaxInterface(maxInterface)
		, mMaxImportInterface(maxImportInterface)
		, mImportFilePath(filepath)
		, mNumberOfAmbientColors(0)
		, mDummyObject((DummyObject*) getMaxImportInterface()->Create(HELPER_CLASS_ID, Class_ID(DUMMY_CLASS_ID, 0)))
		, mCurrentParsingPass(GENERAL_PASS)
		, mInvertTransparency(false)
		, mExtraDataHandler(0)
		, mUniqueIdSkyLightMap()
		, mVisualSceneUniqueId( COLLADAFW::UniqueId::INVALID )
	{
		mUnitConversionFunctors.lengthConversion = 0;
		mUnitConversionFunctors.inverseLengthConversion = 0;
		mUnitConversionFunctors.angleConversion = 0;
		mUnitConversionFunctors.timeConversion = new ScaleConversionFunctor( (float)(GetTicksPerFrame() * GetFrameRate()));

		mExtraDataHandler = new ExtraDataHandler(this);

#pragma warning(disable: 4996)
		_timeb startTimeBuffer;
		_ftime( &startTimeBuffer );
		mStartTime = (double)startTimeBuffer.time + (double)startTimeBuffer.millitm / 1000;
#pragma warning(default: 4996)
	}
	
	//--------------------------------------------------------------------
	DocumentImporter::~DocumentImporter()
	{
		// Delete all the stored library nodes
		for ( LibraryNodesList::const_iterator it = mLibraryNodesList.begin(); it != mLibraryNodesList.end(); ++it)
			delete *it;

		// Delete all the stored library nodes
		for ( UniqueIdVisualSceneMap::const_iterator it = mUniqueIdVisualSceneMap.begin(); it != mUniqueIdVisualSceneMap.end(); ++it)
			delete it->second;

		// Delete all the animation lists
		for ( UniqueIdAnimationListMap::const_iterator it = mUniqueIdAnimationListMap.begin(); it != mUniqueIdAnimationListMap.end(); ++it)
			delete it->second;

		// Delete all the controllers
		for ( UniqueIdSkinControllerMap::const_iterator it = mUniqueIdSkinControllersMap.begin(); it != mUniqueIdSkinControllersMap.end(); ++it)
			delete it->second;

		// Delete all the controllers
		for ( UniqueIdMorphControllerMap::const_iterator it = mUniqueIdMorphControllersMap.begin(); it != mUniqueIdMorphControllersMap.end(); ++it)
			delete it->second;


		delete mUnitConversionFunctors.lengthConversion;
		delete mUnitConversionFunctors.angleConversion;
		delete mUnitConversionFunctors.timeConversion;

		delete mExtraDataHandler;
	}

	//---------------------------------------------------------------
	bool DocumentImporter::import()
	{
		FWLErrorHandler errorHandler;
		COLLADASaxFWL::Loader loader(&errorHandler);
		loader.registerExtraDataCallbackHandler(mExtraDataHandler);
		COLLADAFW::Root root(&loader, this);

		if ( !root.loadDocument(mImportFilePath) )
			return false;

		if ( (mNumberOfAmbientColors > 0) && mAmbientColor.isValid() )
		{
			mMaxImportInterface->SetAmbient(0, Point3(mAmbientColor.getRed(), mAmbientColor.getGreen(), mAmbientColor.getBlue() ));
		}

		if( errorHandler.hasCriticalError() )
			return false;

		if ( !createSceneGraph() )
			return false;

		if( errorHandler.hasCriticalError() )
			return false;

		if ( !createMorphController() )
			return false;

		if( errorHandler.hasCriticalError() )
			return false;

		mCurrentParsingPass = CONTROLLER_DATA_PASS;

		COLLADASaxFWL::Loader loader2(&errorHandler);

		// We need the second pass to create skin controllers
		COLLADAFW::Root root2(&loader2, this);
		if ( !root2.loadDocument(mImportFilePath) )
			return false;

		if( errorHandler.hasCriticalError() )
			return false;

		MaterialCreator materialCreator(this);
		if ( !materialCreator.create() )
			return false;

		if( errorHandler.hasCriticalError() )
			return false;

		if ( !assignControllers(materialCreator) )
			return false;

		if( errorHandler.hasCriticalError() )
			return false;

		return true;
	}

	//------------------------------
	void DocumentImporter::printMessage( const String& message )
	{
		char* str = (char *)message.c_str();
#ifdef UNICODE
		WideString wide = COLLADABU::StringUtils::toWideString(str);
		mMaxInterface->ReplacePrompt(wide.c_str());
#else
		mMaxInterface->ReplacePrompt(str);
#endif
//		mMaxInterface->PushPrompt(str);
	}

	//---------------------------------------------------------------
	double DocumentImporter::getElapsedTime() const
	{
#pragma warning(disable: 4996)
		_timeb endTimeBuffer;
		_ftime(&endTimeBuffer);
#pragma warning(default: 4996)
		double endTime = (double)endTimeBuffer.time + (double)endTimeBuffer.millitm / 1000;
		return endTime - mStartTime;
	}

	//---------------------------------------------------------------
	void* DocumentImporter::createMaxObject(SClass_ID superClassId, Class_ID classId)
	{
		void* c = mMaxImportInterface->Create(superClassId, classId);

		if ( !c )
		{
			// This can be caused if the object referred to is in a deffered plugin.
			DllDir* dllDir = GetCOREInterface()->GetDllDirectory();
			ClassDirectory& classDir = dllDir->ClassDir();
			ClassEntry* classEntry = classDir.FindClassEntry(superClassId, classId);

			if ( !classEntry )
				return 0;

			// This will force the loading of the specified plug-in
			classEntry->FullCD();

			if ( !classEntry->IsLoaded() )
				return 0;

			c = mMaxImportInterface->Create(superClassId, classId);
		}
		return c;
	}

	//---------------------------------------------------------------
	bool DocumentImporter::assignControllers( const MaterialCreator& materialCreator ) 
	{
		AnimationAssigner animationAssigner(this, materialCreator);
		return animationAssigner.assign();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::createSceneGraph()
	{
		//set first available visual scene for fallback if no scene is defined
		UniqueIdVisualSceneMap::const_iterator it = mUniqueIdVisualSceneMap.begin();

		if(mVisualSceneUniqueId != COLLADAFW::UniqueId::INVALID)
		{
			it = mUniqueIdVisualSceneMap.find( mVisualSceneUniqueId );

			//reset first available visual scene for fallback if referenced visual scene could not be found
			if( it == mUniqueIdVisualSceneMap.end() )
				it = mUniqueIdVisualSceneMap.begin(); 
		}

		bool visualSceneAvailable = (it != mUniqueIdVisualSceneMap.end());
		if ( visualSceneAvailable )
		{
			COLLADABU::Math::Matrix4 upAxisRotation = COLLADABU::Math::Matrix4::IDENTITY;
			if( COLLADAFW::FileInfo::X_UP == mFileInfo.upAxis )
				upAxisRotation = X_UPAXIS_CORRECTION;
			else if( COLLADAFW::FileInfo::Y_UP == mFileInfo.upAxis )
				upAxisRotation = Y_UPAXIS_CORRECTION;
			//else upAxis unknown or z  -> no rotation
			
			SceneGraphCreator sceneGraphCreator(this, it->second, upAxisRotation);
			return sceneGraphCreator.create();
		}

		return true;
	}

	//---------------------------------------------------------------
	bool DocumentImporter::createMorphController()
	{
		MorphControllerCreator morphControllerCreator(this);
		return morphControllerCreator.create();
	}

	//---------------------------------------------------------------
	void DocumentImporter::addAmbientColor( const COLLADAFW::Color& ambientColor )
	{
		if ( mAmbientColor.isValid())
		{
			mAmbientColor.setRed( (mAmbientColor.getRed() * mNumberOfAmbientColors + ambientColor.getRed())/(mNumberOfAmbientColors+1) );
			mAmbientColor.setGreen( (mAmbientColor.getGreen() * mNumberOfAmbientColors + ambientColor.getGreen())/(mNumberOfAmbientColors+1) );
			mAmbientColor.setBlue( (mAmbientColor.getBlue() * mNumberOfAmbientColors + ambientColor.getBlue())/(mNumberOfAmbientColors+1) );
			mNumberOfAmbientColors++;
		}
		else
		{
			mAmbientColor = ambientColor;
			mNumberOfAmbientColors = 1;
		}

	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeGlobalAsset( const COLLADAFW::FileInfo* asset )
	{
		mFileInfo.absoluteFileUri = asset->getAbsoluteFileUri();

		const COLLADAFW::FileInfo::ValuePairPointerArray& valuePairs = asset->getValuePairArray();

		for ( size_t i = 0, count = valuePairs.getCount(); i < count; ++i)
		{
			const COLLADAFW::FileInfo::ValuePair* valuePair = valuePairs[i];
			const String& key = valuePair->first;
			const String& value = valuePair->second;
			if ( key == AUTORING_TOOL )
			{
				int googleSketchUpResult6 = value.compare(0, sizeof(GOOGLE_SKETCHUP6)-1, GOOGLE_SKETCHUP6);
				int googleSketchUpResult70 = value.compare(0, sizeof(GOOGLE_SKETCHUP70)-1, GOOGLE_SKETCHUP70);
				int microstationResult = value.compare(0, sizeof(MICROSTATION)-1, MICROSTATION);
				if ( (googleSketchUpResult6 == 0) || (microstationResult == 0) || (googleSketchUpResult70 == 0))
				{
					mInvertTransparency = true;
				}
			}
		}

		float systemUnitScale = 1.0f;

		// Retrieve the system unit information
		int systemUnitType = UNITS_CENTIMETERS;
		GetMasterUnitInfo(&systemUnitType, &systemUnitScale);

		switch (systemUnitType)
		{
		case UNITS_INCHES: 
			systemUnitScale *= 0.0254f; 
			break;
		case UNITS_FEET: 
			systemUnitScale *= 0.3048f; 
			break;
		case UNITS_MILES: 
			systemUnitScale *= 1609.344f; 
			break;
		case UNITS_MILLIMETERS: 
			systemUnitScale *= 0.001f; 
			break;
		case UNITS_CENTIMETERS: 
			systemUnitScale *= 0.01f; 
			break;
		case UNITS_METERS: 
			break;
		case UNITS_KILOMETERS: 
			systemUnitScale *= 1000.0f; 
			break;
		default: break;
		}
		mFileInfo.unitScale = (float)asset->getUnit().getLinearUnitMeter() / systemUnitScale;
		delete mUnitConversionFunctors.lengthConversion;
		mUnitConversionFunctors.lengthConversion = new ScaleConversionFunctor(mFileInfo.unitScale);
		if ( mFileInfo.unitScale != 0)
		{
			mUnitConversionFunctors.inverseLengthConversion = new ScaleConversionFunctor(1/mFileInfo.unitScale);
		}

		COLLADAFW::FileInfo::Unit::AngularUnit angularUnit = asset->getUnit().getAngularUnit();
		if ( angularUnit == COLLADAFW::FileInfo::Unit::DEGREES )
		{
     		delete mUnitConversionFunctors.angleConversion;
			mUnitConversionFunctors.angleConversion = ConversionFunctors::degToRad.clone();
		}

		mFileInfo.upAxis = asset->getUpAxisType();

		return true;
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeVisualScene( const COLLADAFW::VisualScene* visualScene )
	{
		if ( mCurrentParsingPass != GENERAL_PASS )
			return true;

		VisualSceneImporter visualSceneImporter(this, visualScene);
		return visualSceneImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeLibraryNodes( const COLLADAFW::LibraryNodes* libraryNodes )
	{
		if ( mCurrentParsingPass != GENERAL_PASS )
			return true;

		LibraryNodesImporter libraryNodesImporter(this, libraryNodes);
		bool success = libraryNodesImporter.import();
		return success;
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeGeometry( const COLLADAFW::Geometry* geometry )
	{
		if ( mCurrentParsingPass != GENERAL_PASS )
			return true;

		GeometryImporter geometryImporter(this, geometry);
		return geometryImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeMaterial( const COLLADAFW::Material* material )
	{
		if ( mCurrentParsingPass != GENERAL_PASS )
			return true;

		MaterialImporter materialImporter(this, material);
		return materialImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeEffect( const COLLADAFW::Effect* effect )
	{
		if ( mCurrentParsingPass != GENERAL_PASS )
			return true;

		EffectImporter effectImporter(this, effect);
		return effectImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeCamera( const COLLADAFW::Camera* camera )
	{
		if ( mCurrentParsingPass != GENERAL_PASS )
			return true;

		CameraImporter cameraImporter(this, camera);
		return cameraImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeImage( const COLLADAFW::Image* image )
	{
		if ( mCurrentParsingPass != GENERAL_PASS )
			return true;

		ImageImporter imageImporter(this, image);
		return imageImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeLight( const COLLADAFW::Light* light )
	{
		if ( mCurrentParsingPass != GENERAL_PASS )
			return true;

		LightImporter lightImporter(this, light);
		return lightImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeAnimation( const COLLADAFW::Animation* animation )
	{
		if ( mCurrentParsingPass != GENERAL_PASS )
			return true;

		AnimationImporter animationImporter(this, animation);
		return animationImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeAnimationList( const COLLADAFW::AnimationList* animationList )
	{
		if ( mCurrentParsingPass != GENERAL_PASS )
			return true;

		AnimationListImporter animationListImporter(this, animationList);
		return animationListImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeController( const COLLADAFW::Controller* controller )
	{
		if ( mCurrentParsingPass != GENERAL_PASS )
			return true;

		ControllerImporter controllerImporter(this, controller);
		return controllerImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeSkinControllerData( const COLLADAFW::SkinControllerData* skinControllerData )
	{
		if ( mCurrentParsingPass != CONTROLLER_DATA_PASS )
			return true;

		SkinControllerDataImporter skinControllerDataImporter(this, skinControllerData);
		return skinControllerDataImporter.import();
	}

	//---------------------------------------------------------------
	float DocumentImporter::convertSpaceUnit( float originalValue )
	{
		return originalValue * mFileInfo.unitScale;
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeScene( const COLLADAFW::Scene* scene )
	{
		if( scene == 0 )
			return true;

		const COLLADAFW::InstanceVisualScene* instanceVisualScene = scene->getInstanceVisualScene();
		COLLADAFW::UniqueId id = instanceVisualScene->getInstanciatedObjectId();
		if(id.getFileId() == 0)
			mVisualSceneUniqueId = id;
		return true;
	}

	//---------------------------------------------------------------
	void DocumentImporter::addUniqueIdEffectBumpMapParametersPair( const COLLADAFW::UniqueId& effectUniqueId, const BumpMap& bumpParameters )
	{
		EffectMaps& effectMaps = getUniqueIdEffectMapsMap()[effectUniqueId];
		effectMaps.mBumpMap.bumpType = bumpParameters.bumpType;
		if( effectMaps.mBumpMap.bumpType != BUMP_TYPE_INVALID )
		{
			if( bumpParameters.textureAttributes )
				effectMaps.mBumpMap.textureAttributes = bumpParameters.textureAttributes;
		}
	}
} // namespace COLLADAMax
