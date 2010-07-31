/*
	Copyright (c) 2010 yaoyansi<yaoyansi2@yahoo.com.cn>

	This file is part of dae23ds_lib3ds.

	Licensed under the MIT Open Source License, 
	for details please see LICENSE file or the website
	http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE23dsStableHeaders.h"
#include "DAE23dsWriter.h"
#include "DAE23dsSceneGraphHandler.h"

#include "COLLADASaxFWLLoader.h"

#include "COLLADAFWRoot.h"
#include "COLLADAFWGeometry.h"
#include "COLLADAFWNode.h"
#include "COLLADAFWVisualScene.h"
#include "COLLADAFWInstanceGeometry.h"
#include <lib3ds.h>

#define _Log(x) std::cout << x << std::endl;


namespace DAE23ds
{

	static size_t FLUSHERBUFFERSIZE = 1024*1024*4;
	static size_t BUFFERSIZE = 1024*1024*2;

	static const size_t RESERVED_OBJECTIDS_COUNT = 0;
	static const size_t RESERVED_MATERIALNUMBERS_COUNT = 1;

	Writer* Writer::m_instance = NULL;
	//--------------------------------------------------------------------
	bool Writer::InstanceGeometryInfo::operator<( const InstanceGeometryInfo& rhs ) const
	{
		if (fwInstanceGeometry < rhs.fwInstanceGeometry)
			return true;
		if (fwInstanceGeometry > rhs.fwInstanceGeometry)
			return false;

		return false;
	}

	//--------------------------------------------------------------------
	Writer::Writer()
		: mVisualScene(0)
		,_3dsfile(NULL)
	{

	}
	//--------------------------------------------------------------------

	Writer* Writer::getInstance()
	{
		if(!m_instance){
			m_instance = new Writer();
		}
		return m_instance;
	}
	//--------------------------------------------------------------------
	void Writer::init( const COLLADABU::URI& inputFile, const COLLADABU::URI& outputFile, bool applyTransformationsToMeshes )
	{
		mInputFile = inputFile;
		mOutputFile = outputFile;
		mApplyTransformationsToMeshes = applyTransformationsToMeshes;
	}

	//--------------------------------------------------------------------
	Writer::~Writer()
	{
		delete mVisualScene;
	}

	//--------------------------------------------------------------------
	void Writer::reportError( const String& method, const String& message, Severity severity )
	{
		switch ( severity )
		{
		case SEVERITY_INFORMATION:
			std::cout << "Information"; 
			break;
		case SEVERITY_WARNING:
			std::cout << "Warning"; 
			break;
		case _SEVERITY_ERROR:
			std::cout << "Error"; 
			break;
		}
		if ( !method.empty() )
			std::cout << " in " << method;
		std::cout << ": ";
		std::cout << message << std::endl;
	}

	//--------------------------------------------------------------------
	bool Writer::write()
	{
		_Log("write()");
		
		// new 3ds file
		{
			_3dsfile = lib3ds_file_new();
		}


		COLLADASaxFWL::Loader loader;
		COLLADAFW::Root root(&loader, this);

		// Load scene graph 
		loader.setObjectFlags( COLLADASaxFWL::Loader::ALL_OBJECTS_MASK );
		if ( !root.loadDocument(mInputFile.toNativePath()) )
			return false;

		createUniqueIdNodeMap();

		SceneGraphHandler sceneGraphHandler( mVisualScene );
		sceneGraphHandler.handle();

		writeMaterial_lib3ds();

		writeInstanceMesh_lib3ds();


		//printMaps();
		
		// write 3ds file
		{
			std::string outputfile(mOutputFile.getURIString());
			size_t i=outputfile.find_last_of('.');
			outputfile.insert(i,"_lib3ds");
			if (!lib3ds_file_save(_3dsfile, outputfile.c_str())) {
				_Log("ERROR: Saving 3ds file failed!\n");
			}
			lib3ds_file_free(_3dsfile);
			_Log("3ds file closed.");
		}

		return true;
	}

	//------------------------------
	void Writer::createUniqueIdNodeMap( COLLADAFW::Node* node )
	{
		_Log("createUniqueIdNodeMap("<< node->getName()<< ")");
		mUniqueIdNodeMap[node->getUniqueId()] = node;
		createUniqueIdNodeMap( node->getChildNodes() );
	}

	//------------------------------
	void Writer::createUniqueIdNodeMap( const COLLADAFW::NodePointerArray& nodes )
	{
		for ( size_t i = 0, cout = nodes.getCount(); i < cout; ++i)
		{
			COLLADAFW::Node* node = nodes[i];
			createUniqueIdNodeMap( node );
		}
	}

	//------------------------------
	void Writer::createUniqueIdNodeMap()
	{
		createUniqueIdNodeMap( mVisualScene->getRootNodes() );
		Writer::LibraryNodesList::const_iterator it = mLibraryNodesList.begin();
		for ( ; it != mLibraryNodesList.end(); ++it )
		{
			const COLLADAFW::LibraryNodes& libraryNodes = *it;
			createUniqueIdNodeMap( libraryNodes.getNodes() );
		}
	}


	//--------------------------------------------------------------------
	void Writer::cancel( const String& errorMessage )
	{		
		_Log("cancel()");
	}

	//--------------------------------------------------------------------
	void Writer::start()
	{	
		_Log("start()");
	}

	//--------------------------------------------------------------------
	void Writer::finish()
	{
		_Log("finish()");
	}

	//--------------------------------------------------------------------
	bool Writer::writeGlobalAsset( const COLLADAFW::FileInfo* asset )
	{
		_Log("writeGlobalAsset()");
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeVisualScene( const COLLADAFW::VisualScene* visualScene )
	{
		_Log("writeVisualScene()");
		mVisualScene = new COLLADAFW::VisualScene(*visualScene);
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeLibraryNodes( const COLLADAFW::LibraryNodes* libraryNodes )
	{
		_Log("writeLibraryNodes()");
		mLibraryNodesList.push_back(*libraryNodes);
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeGeometry( const COLLADAFW::Geometry* geometry )
	{
		_Log("writeGeometry("<< geometry->getName()
			<<",name="<<geometry->getName()
			<<",objid="<<geometry->getObjectId()
			<<",clsid="<<geometry->getClassId()
			<<",uid="<<geometry->getUniqueId().toAscii());
		if ( geometry->getType() != COLLADAFW::Geometry::GEO_TYPE_MESH )
			return true;

		_writeGeometry_lib3ds( geometry );

		//////////////////////////////////////////////////////////////////////////
		meshUID.insert( geometry->getUniqueId() );

		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeMaterial( const COLLADAFW::Material* material )
	{
		_Log("writeMaterial("<< material->getName()<<",uid="<< material->getOriginalId()<<",effect="<<material->getInstantiatedEffect().toAscii()<<")");
		mUniqueIdFWMaterialMap.insert(std::make_pair(material->getUniqueId(),*material ));

		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeEffect( const COLLADAFW::Effect* effect )
	{
		_Log("writeEffect("<< effect->getName()<<")");
		mUniqueIdFWEffectMap.insert(std::make_pair(effect->getUniqueId(),*effect ));
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeCamera( const COLLADAFW::Camera* camera )
	{	
		_Log("writeCamera("<< camera->getName()<<")");
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeImage( const COLLADAFW::Image* image )
	{
		_Log("writeImage("<< image->getName()<<")");
		mUniqueIdFWImageMap.insert(std::make_pair(image->getUniqueId(),*image ));
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeLight( const COLLADAFW::Light* light )
	{
		_Log("writeLight("<< light->getName()<<")");
		_Log(",type="<<light->getLightType()
			<<",uid="<<light->getUniqueId().toAscii()
			<<",oid="<<light->getObjectId()
			<<",orid="<<light->getOriginalId()
			<<"light name="<< light->getName()
			<<",type="<< light->getLightType()
			<<",color="<< light->getColor().getRed()<<","<< light->getColor().getGreen()<<","<<light->getColor().getBlue()
			<<",const attenuation="<< light->getConstantAttenuation().getValue()
			<<",linear attenuation="<< light->getLinearAttenuation().getValue()
			<<",quadratic attenuation="<< light->getQuadraticAttenuation().getValue()
			<<",fallOffAngle="<< light->getFallOffAngle().getValue()
			<<",fallOffExp="<< light->getFallOffExponent().getValue()
			);
		lightMap.insert( std::make_pair(light->getUniqueId(),light) );

		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeAnimation( const COLLADAFW::Animation* animation )
	{
		_Log("writeAnimation("<< animation->getName()<<")");
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeAnimationList( const COLLADAFW::AnimationList* animationList )
	{
		_Log("writeAnimationList()");
		return true;
	}

	//--------------------------------------------------------------------
	Lib3dsMesh* Writer::find3dsMesh(const COLLADAFW::UniqueId &uid)
	{
		std::map<COLLADAFW::UniqueId, Lib3dsMesh*>::iterator i = _3dsmeshMap.find(uid);
		if( _3dsmeshMap.end()== i){
			return NULL;
		}
		return i->second;

	}
	//--------------------------------------------------------------------
	void Writer::printMaps()
	{
		_Log("====================================");
		_Log("\nmGeometryUniqueIdInstanceGeometryInfoMap");
		GeometryUniqueIdInstanceGeometryInfoMap::iterator i0=mGeometryUniqueIdInstanceGeometryInfoMap.begin();
		for(; i0!=mGeometryUniqueIdInstanceGeometryInfoMap.end(); ++i0){
			_Log(i0->first.toAscii());
			printMaterialBindingArray("\t", i0->second.fwInstanceGeometry->getMaterialBindings());
		}

		//_Log("\nmInstanceGeometryObjectIdMap");
		_Log("\nmUniqueIdFWMaterialMap");
		UniqueIdFWMaterialMap::iterator i2 = mUniqueIdFWMaterialMap.begin();
		for(; i2!=mUniqueIdFWMaterialMap.end(); ++i2){
			_Log(i2->first.toAscii()
				<<",\tmat(name="<<i2->second.getName()
				<<",oid="<<i2->second.getOriginalId()
				<<",efc="<<i2->second.getInstantiatedEffect().toAscii()
				<<")");
		}

		_Log("\nmUniqueIdFWEffectMap");
		UniqueIdFWEffectMap::iterator i3 = mUniqueIdFWEffectMap.begin();
		for(; i3!=mUniqueIdFWEffectMap.end(); ++i3){
			_Log(i3->first.toAscii()
				<<",\tefc(name="<<i3->second.getName()
				<<",oid"<<i3->second.getOriginalId()
				//<<",efc="<<i2->second.getInstantiatedEffect().toAscii()
				<<")");
			printCommonEffectPointerArray("\t",i3->second.getCommonEffects());
		}
	}
	//--------------------------------------------------------------------
	void Writer::printMaterialBindingArray(const String&tip, const COLLADAFW::MaterialBindingArray& array)
	{
		const size_t LEN = array.getCount();
		for(size_t i=0; i<LEN; ++i){
			_Log(tip<< ",mid="<<array[i].getMaterialId() 
				<<",\t"<<array[i].getName()
				<<",\t"<<array[i].getReferencedMaterial().toAscii()
				<<",\ti="<<getMaterialIndex(array[i].getReferencedMaterial())
				//<<",\ti="<<getMaterialIndex(COLLADAFW::UniqueId("aaa"))
				);

		}
	}
	//--------------------------------------------------------------------
	int Writer::getMaterialIndex(const COLLADAFW::UniqueId& uid)
	{
		return distance(mUniqueIdFWMaterialMap.begin(),
			mUniqueIdFWMaterialMap.find(uid));
	}
	//--------------------------------------------------------------------

	void Writer::printCommonEffectPointerArray(const String&tip, const COLLADAFW::CommonEffectPointerArray& array)
	{
		const size_t LEN = array.getCount();
		for(size_t i=0; i<LEN; ++i){
			_Log(tip<< ",\t"<<array[i]->getOriginalId());
		}
	}

	//--------------------------------------------------------------------
	// write the material in order of tempMaterialIndex,
	// and find the material pointer by uid from mUniqueIdFWMaterialMap.
	void Writer::writeMaterial_lib3ds()
	{
		_Log("Writer::writeMaterial_lib3ds()");

		for(size_t i=0; i<tempMaterialIndex.getSize(); ++i)
		{
			std::string materialName = tempMaterialIndex.getName(i);//e.g.blinn1SG
			_Log("material name="<<materialName);

			//1.find uid of mateialName
			COLLADAFW::UniqueId materialuid;
			bool bfound = false;
			GeometryUniqueIdInstanceGeometryInfoMap::iterator
				it = mGeometryUniqueIdInstanceGeometryInfoMap.begin();
			for(; it!=mGeometryUniqueIdInstanceGeometryInfoMap.end(); ++it)//each geometry
			{
				assert(it->second.fwInstanceGeometry);
				const COLLADAFW::MaterialBindingArray& 
					mba = it->second.fwInstanceGeometry->getMaterialBindings();

				for(size_t i=0; i<mba.getCount(); ++i)//each material of this geometry
				{
					//_Log("\t("<<mba[i].getName()<<" == "<< materialName<<") ?");
					if(mba[i].getName() == materialName){
						materialuid = mba[i].getReferencedMaterial();
						bfound = true;
						break;
					}
				}//for
				if(bfound)
					break;
			}//for
			if(!bfound)
			{
				_Log(materialName<<" not found in mGeometryUniqueIdInstanceGeometryInfoMap.");
				return ;
			}

			//2.find the material pointer of this uid in mUniqueIdFWMaterialMap
			UniqueIdFWMaterialMap::iterator mid = mUniqueIdFWMaterialMap.find(materialuid);
			if(mid==mUniqueIdFWMaterialMap.end())
			{
				_Log(materialuid.toAscii()<<" not found in mUniqueIdFWMaterialMap");
				return ;//not found.
			}

			_writeMaterial_lib3ds(&(mid->second));
		}
	}
	//--------------------------------------------------------------------
	void Writer::_writeMaterial_lib3ds( const COLLADAFW::Material* material )
	{
			_Log("mat "
				//<<"uid="<<it->first.toAscii()
				<<",name=" <<material->getName()
				<<",effect="<<material->getInstantiatedEffect().toAscii()
				<<",oid="<<material->getOriginalId()
				<<",uid="<<material->getUniqueId().toAscii()
				);

			const COLLADAFW::EffectCommon* effectCommon = getEffectCommon(material);
			assert(effectCommon);
			_Log("effect type="<<effectCommon->getShaderType() 
				<<",oid="<<effectCommon->getOriginalId()
				);

			Lib3dsMaterial *_3dsMtrl = lib3ds_material_new( material->getName().c_str() );
			lib3ds_file_insert_material(get3dsFile(), _3dsMtrl, -1);
			{
				//shader type
				switch( effectCommon->getShaderType() )
				{
				case COLLADAFW::EffectCommon::SHADER_BLINN:		_3dsMtrl->shading = LIB3DS_SHADING_METAL;	break;
				case COLLADAFW::EffectCommon::SHADER_CONSTANT:	_3dsMtrl->shading = LIB3DS_SHADING_FLAT;	break;
				case COLLADAFW::EffectCommon::SHADER_PHONG:		_3dsMtrl->shading = LIB3DS_SHADING_PHONG;	break;
				case COLLADAFW::EffectCommon::SHADER_LAMBERT:	_3dsMtrl->shading = LIB3DS_SHADING_GOURAUD;	break;

				case COLLADAFW::EffectCommon::SHADER_UNKNOWN:				
				default:
					_3dsMtrl->shading = LIB3DS_SHADING_WIRE_FRAME;
				}
				//------------------------ emission ---------------------------
				//------------------------ ambient ---------------------------
				if( effectCommon->getAmbient().isTexture() ){
					//how to set in .3ds format
				}
				if( effectCommon->getAmbient().isColor() ){
					_3dsMtrl->ambient[0] = effectCommon->getAmbient().getColor().getRed(); 
					_3dsMtrl->ambient[1] = effectCommon->getAmbient().getColor().getGreen(); 
					_3dsMtrl->ambient[2] = effectCommon->getAmbient().getColor().getBlue(); 
				}
				_Log("\t amb "
					<< _3dsMtrl->ambient[0] <<" "
					<< _3dsMtrl->ambient[1] <<" "
					<< _3dsMtrl->ambient[2]);
				//------------------------ color ---------------------------
 				//if( effectCommon->getDiffuse().isTexture() ){
 				//	assignTextureName( _3dsMtrl->texture1_map, effectCommon->getDiffuse(), effectCommon);
 
 				//	_3dsMtrl->texture1_map.scale[0] = _3dsMtrl->texture1_map.scale[1] = 1.0;
 				//	_3dsMtrl->texture1_map.percent = 1.0;
 				//	_3DSDEBUG("\t color tex:"<< _3dsMtrl->texture1_map.name <<"\n" );
 				//}
 				//_3DSDEBUG("\t color "
 				//	<< mayaMtrl2.color.value.r <<" " 
 				//	<< mayaMtrl2.color.value.g <<" " 
 				//	<< mayaMtrl2.color.value.b <<"\n");

				//------------------------ diffuse ---------------------------
				if( effectCommon->getDiffuse().isTexture() ){
					assignTextureName( &_3dsMtrl->texture1_map, effectCommon->getDiffuse(), effectCommon);

					_3dsMtrl->texture1_map.scale[0] = _3dsMtrl->texture2_map.scale[1] = 1.0;
					_3dsMtrl->texture1_map.percent = 1.0;
					_Log("\t diffuse tex:"<< _3dsMtrl->texture2_map.name << "\n" );
				}
				if(effectCommon->getDiffuse().isColor()){
					_3dsMtrl->diffuse[0] = effectCommon->getDiffuse().getColor().getRed();
					_3dsMtrl->diffuse[1] = effectCommon->getDiffuse().getColor().getGreen();
					_3dsMtrl->diffuse[2] = effectCommon->getDiffuse().getColor().getBlue();
					_Log("\t dif "
						<< _3dsMtrl->diffuse[0] <<" "
						<< _3dsMtrl->diffuse[1] <<" "
						<< _3dsMtrl->diffuse[2]);
				}

				//_3dsMtrl->self_illum_flag = 1;
				//_3dsMtrl->self_illum = mtrl.selfIllumination;

				//------------------------ incandescence/self_illum ------------
				if( effectCommon->getEmission().isTexture() ){
					assignTextureName( &_3dsMtrl->self_illum_map, effectCommon->getEmission(), effectCommon);
					_3dsMtrl->self_illum_map.scale[0] = _3dsMtrl->self_illum_map.scale[1] = 1.0;
					_3dsMtrl->self_illum_map.percent = 1.0;
					_3dsMtrl->self_illum_flag  = true;
					_Log("\t incandescence/self_illum tex:" << _3dsMtrl->self_illum_map.name <<"\n" );
				}
				if(effectCommon->getEmission().isColor()){
					if(effectCommon->getEmission().getColor().getRed() >= 0.01){
						_3dsMtrl->self_illum_flag  = true;
						_3dsMtrl->self_illum = effectCommon->getEmission().getColor().getRed();
					}else {
						_3dsMtrl->self_illum_flag  = false;
					}
				}
				_Log("\t incandescence/self_illum (flag=" <<_3dsMtrl->self_illum_flag<< ") " 
					<< _3dsMtrl->self_illum );

				//------------------------ transparency ---------------------------
				if( effectCommon->getOpacity().isTexture() ){
					assignTextureName( &_3dsMtrl->opacity_map, effectCommon->getOpacity(), effectCommon);
					_3dsMtrl->opacity_map.scale[0] = _3dsMtrl->opacity_map.scale[1] = 1.0;//need test
					_3dsMtrl->opacity_map.percent = 1.0;//need test
					_Log("\t transparency tex:"<< _3dsMtrl->opacity_map.name <<"\n" );
				}
				if( effectCommon->getOpacity().isColor() ){
					_3dsMtrl->transparency = (effectCommon->getOpacity().getColor().getRed()
						+ effectCommon->getOpacity().getColor().getGreen()
						+ effectCommon->getOpacity().getColor().getBlue())/3.0f;//according to DeepExploreration
					_Log("\t trans =(r+g+b)/3=" << _3dsMtrl->transparency );
				}
				//------------------------ bump ---------------------------
				//if( mayaMtrl2.bump.bUseTex() ){
				//	assignTextureName( _3dsMtrl->bump_map, *(mayaMtrl2.bump.texture.begin()));
				//	_3dsMtrl->bump_map.scale[0] = _3dsMtrl->bump_map.scale[1] = 1.0;
				//	_3dsMtrl->bump_map.percent = 1.0;
				//	_3DSDEBUG("\t bump tex:"<< _3dsMtrl->bump_map.name <<" \n" );
				//}else{}
				//------------------------ specular color---------------------------
				if( effectCommon->getSpecular().isTexture() ){
					assignTextureName( &_3dsMtrl->specular_map, effectCommon->getSpecular(), effectCommon);
					_3dsMtrl->specular_map.scale[0] = _3dsMtrl->specular_map.scale[1] = 1.0;
					_3dsMtrl->specular_map.percent = 1.0;
					_Log("\t specular tex:"<< _3dsMtrl->specular_map.name);
				}
				if( effectCommon->getSpecular().isColor()  ){
					_3dsMtrl->specular[0] = effectCommon->getSpecular().getColor().getRed();
					_3dsMtrl->specular[1] = effectCommon->getSpecular().getColor().getGreen();
					_3dsMtrl->specular[2] = effectCommon->getSpecular().getColor().getBlue();
				}
				_Log("\t specular color "
					<<_3dsMtrl->specular[0] <<" "
					<<_3dsMtrl->specular[1] <<" "
					<<_3dsMtrl->specular[2] );

				//------------------------ shininess ---------------------------
				//if( mayaMtrl2.shininess.bUseTex() ){
				//	assignTextureName( _3dsMtrl->shininess_map, *(mayaMtrl2.shininess.texture.begin()));
				//	_3dsMtrl->shininess_map.scale[0] = _3dsMtrl->shininess_map.scale[1] = 1.0;
				//	_3dsMtrl->shininess_map.percent = 1.0;
				//	_3DSDEBUG("\t shininess tex:" << _3dsMtrl->shininess_map.name <<"\n" );
				//}
				if( COLLADAFW::FloatOrParam::PARAM==effectCommon->getShininess().getType()){
					_3dsMtrl->shininess = effectCommon->getShininess().getFloatValue();
				}
				_3dsMtrl->shin_strength = 1.0f;//(deepExplorer:高光等级)
				_Log("\t shininess " << _3dsMtrl->shininess <<"\n" );	
				_Log("\t shin_strength "<< _3dsMtrl->shin_strength);	
				//-------------------------other-----------------------------
				_3dsMtrl->soften = true;
			}

	}
	//--------------------------------------------------------------------
	void Writer::_writeGeometry_lib3ds(const COLLADAFW::Geometry* geometry)
	{


			Lib3dsMesh *_3dsmesh = lib3ds_mesh_new(geometry->getName().c_str());
			_3dsmeshMap.insert(std::make_pair(geometry->getUniqueId(), _3dsmesh));
			lib3ds_file_insert_mesh(_3dsfile, _3dsmesh, -1);
			{
				COLLADAFW::Mesh *mesh = (COLLADAFW::Mesh*)geometry;
				//values
				const COLLADAFW::MeshVertexData &positions = mesh->getPositions();
				const COLLADAFW::MeshVertexData &uvs = mesh->getUVCoords();
				//index
				const COLLADAFW::MeshPrimitiveArray &primitives = mesh->getMeshPrimitives();

				// vertex
				lib3ds_mesh_resize_vertices(_3dsmesh, positions.getValuesCount()/3, 1, 0);
				//_Log("positions.getValuesCount()="<<positions.getValuesCount());
				{
					//position
					if(COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT==positions.getType())
					{
						const COLLADAFW::FloatArray* pos = positions.getFloatValues();
						_Log("FloatArray pos count="<<pos->getCount());
						for (size_t i = 0; i < positions.getValuesCount()/3; ++i) 
						{
							_3dsmesh->vertices[i][0] =  (*pos)[3*i+0];
							_3dsmesh->vertices[i][1] =  (*pos)[3*i+1];
							_3dsmesh->vertices[i][2] =  (*pos)[3*i+2];
						}
					}else if(COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE==positions.getType()){
						const COLLADAFW::DoubleArray* pos = positions.getDoubleValues();
						_Log("DoubleArray pos count="<<pos->getCount());
						for (size_t i = 0; i < positions.getValuesCount()/3; ++i) 
						{
							_3dsmesh->vertices[i][0] =  (float)(*pos)[3*i+0];
							_3dsmesh->vertices[i][1] =  (float)(*pos)[3*i+1];
							_3dsmesh->vertices[i][2] =  (float)(*pos)[3*i+2];
						}
					}
					//uv
					// NOTE:  the number of uv pair is more than vertex number in most cases,
					//        but the number of uv pair in lib3ds is equal to the vertex number,
					//        so we have to truncate the number of uv pair to the vertex number to avoid buffer overflow.
					//        This is a limitation of lib3ds.
					const size_t UVLEN = min(positions.getValuesCount()/3, uvs.getValuesCount()/2);
					//const size_t UVLEN = uvs.getValuesCount()/2;
					_Log("UVLEN ="<< UVLEN<<",min("<<positions.getValuesCount()/3<<","<< uvs.getValuesCount()/2<<")");
					if(COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT==uvs.getType())
					{
						const COLLADAFW::FloatArray* uv = uvs.getFloatValues();

						_Log("FloatArray uv count="<<uv->getCount());
						for (size_t i = 0; i < UVLEN/*uvs.getValuesCount()/2*/; ++i) 
						{
							_3dsmesh->texcos[i][0] =  (*uv)[2*i+0];
							_3dsmesh->texcos[i][1] =  (*uv)[2*i+1];
							//_Log("uv<"<<_3dsmesh->texcos[i][0]<<","<<_3dsmesh->texcos[i][1]<<">");
						}
					}else if(COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE==uvs.getType()){
						const COLLADAFW::DoubleArray* uv = uvs.getDoubleValues();
						_Log("DoubleArray uv count="<<uv->getCount());
						for (size_t i = 0; i < UVLEN/*uvs.getValuesCount()/2*/; ++i) 
						{
							_3dsmesh->texcos[i][0] =  (float)(*uv)[2*i+0];
							_3dsmesh->texcos[i][1] =  (float)(*uv)[2*i+1];
							//_Log("uv<"<<_3dsmesh->texcos[i][0]<<","<<_3dsmesh->texcos[i][1]<<">");
						}
					}
				}

				//faces
				size_t faceIndex = 0;
				lib3ds_mesh_resize_faces(_3dsmesh, mesh->getTrianglesCount());
				for(size_t pi=0; pi<primitives.getCount(); ++pi)
				{
					assert(COLLADAFW::MeshPrimitive::TRIANGLES==primitives[pi]->getPrimitiveType());

					const COLLADAFW::UIntValuesArray &vertexi = primitives[pi]->getPositionIndices();
					assert(primitives[pi]->getFaceCount()==vertexi.getCount()/3);

					//we write the primitives[pi]->getMaterial() as the tempMIndex'th material to 3ds file.
					size_t tempMIndex = tempMaterialIndex.add(primitives[pi]->getMaterial());
					for (size_t fi = 0; fi < primitives[pi]->getFaceCount(); ++fi)
					{
						_3dsmesh->faces[faceIndex].index[0] = vertexi[3*fi+0];
						_3dsmesh->faces[faceIndex].index[1] = vertexi[3*fi+1];
						_3dsmesh->faces[faceIndex].index[2] = vertexi[3*fi+2];

						_3dsmesh->faces[faceIndex].material = tempMIndex;

						faceIndex++;
					}
					_Log("vertexi.getCount()="<<vertexi.getCount());
					_Log("material id="<<primitives[pi]->getMaterialId()<<", mat name="<<primitives[pi]->getMaterial() );
				}

			}
	}
	//--------------------------------------------------------------------

	void Writer::writeMesh_lib3ds()
	{
// 		for(size_t i=0; i<geometryArray.size(); ++i)
// 		{
// 			_writeMesh_lib3ds(  geometryArray[i] );
// 		}
	}
	//--------------------------------------------------------------------
	
	void Writer::_writeInstanceMesh_lib3ds(const COLLADAFW::UniqueId& meshUniqueId)
	{

			const Writer::GeometryUniqueIdInstanceGeometryInfoMap& instanceGeometryMap 
				= getGeometryUniqueIdInstanceGeometryInfoMap();
			Writer::GeometryUniqueIdInstanceGeometryInfoMap::const_iterator lowerBound = instanceGeometryMap.lower_bound(meshUniqueId);
			Writer::GeometryUniqueIdInstanceGeometryInfoMap::const_iterator upperBound = instanceGeometryMap.upper_bound(meshUniqueId);

			for ( Writer::GeometryUniqueIdInstanceGeometryInfoMap::const_iterator it = lowerBound; it != upperBound; ++it)
			{
				const Writer::InstanceGeometryInfo& instanceGeometryInfo = it->second;

				const COLLADAFW::MaterialBindingArray& mba 
					= instanceGeometryInfo.fwInstanceGeometry->getMaterialBindings();
				for(size_t i=0; i<mba.getCount(); ++i)
				{
					_Log("material id="<<mba[i].getMaterialId()<<","
						<<"name="<<mba[i].getName()<<","
						<<"ReferencedMat="<<mba[i].getReferencedMaterial().toAscii()
						);
				}


				Lib3dsMesh *_3dsMesh = find3dsMesh(it->first);
				if(!_3dsMesh)
				{
					_Log("mesh uid="<<it->first<<" not exist.");
					continue;
				}

				//set transform for this instance
				float pos[3], scl[3], rot[4];
				//translate
				COLLADABU::Math::Vector3 translation(instanceGeometryInfo.worldMatrix.getTrans());
				pos[0] = translation.x;
				pos[1] = translation.y;
				pos[2] = translation.z;
				//scale
				COLLADABU::Math::Vector3 scale(instanceGeometryInfo.worldMatrix.getScale());
				scl[0] = scale.x;
				scl[1] = scale.y;
				scl[2] = scale.z;
				//rotate
				COLLADABU::Math::Matrix3 matrix3;
				instanceGeometryInfo.worldMatrix.extract3x3Matrix(matrix3);
				double scaleFactor = scl[0]*scl[1]*scl[2];
				COLLADABU::Math::Vector3 rotationAxis = COLLADABU::Math::Vector3::UNIT_Z;
				double rotationAngle = 0; // in radians
				double inverseScaleFactor = 1 / scaleFactor;
				( inverseScaleFactor* matrix3 ).toAxisAngle( rotationAxis, rotationAngle);
				COLLADABU::Math::Quaternion rotate(instanceGeometryInfo.worldMatrix.extractQuaternion());
				if(rotationAxis.isZeroLength())	
					rotationAngle = 0.0f;
				rot[0] = rotationAxis.x;
				rot[1] = rotationAxis.y;
				rot[2] = rotationAxis.z;
				rot[3] = rotationAngle;

				_Log("tran<"<<pos[0]<<","<<pos[1]<<","<<pos[2]<<">");
				_Log("scale<"<<scl[0]<<","<<scl[1]<<","<<scl[2]<<">");
				_Log("rotate<"<<rot[0]<<","<<rot[1]<<","<<rot[2]<<","<<rot[3]<<">");

				//
				Lib3dsMeshInstanceNode *inst 
					= lib3ds_node_new_mesh_instance(_3dsMesh, instanceGeometryInfo.fwInstanceGeometry->getName().c_str(), pos, scl, rot);
				//base matrix
				for(size_t i=0; i<4; ++i) 
				{
					for(size_t j=0; j<4; ++j) 
					{
						inst->base.matrix[i][j] = instanceGeometryInfo.worldMatrix.getElement(i,j);
						_Log( inst->base.matrix[i][j]<<", ");
					}
					_Log(std::endl);
				}
	  			//pos
 				inst->pos[0] = pos[0];
 				inst->pos[1] = pos[1];
 				inst->pos[2] = pos[2];
 				//scale
 				inst->scl[0] = scl[0];
 				inst->scl[1] = scl[1];
 				inst->scl[2] = scl[2];
 				//rot
 				inst->rot[0] = rot[0];
 				inst->rot[1] = rot[1];
 				inst->rot[2] = rot[2];
 				inst->rot[3] = rot[3];
				//
 				//inst->pos_track.keys[0].value[0] = translation.x;
 				//inst->pos_track.keys[0].value[1] = translation.y;
 				//inst->pos_track.keys[0].value[2] = translation.z;
 				//inst->pos_track.keys[0].value[3] = 0;

				lib3ds_file_append_node(get3dsFile(), (Lib3dsNode*)inst, NULL);



			}//for

	}
	//--------------------------------------------------------------------
	void Writer::writeInstanceMesh_lib3ds()
	{
		std::set<const COLLADAFW::UniqueId>::const_iterator it = meshUID.begin();
		for(; it!=meshUID.end(); ++it)
		{
 			_writeInstanceMesh_lib3ds( *it );
		}


	}
	//--------------------------------------------------------------------
	void Writer::assignTextureName(Lib3dsTextureMap* _3dsTexMap, const COLLADAFW::ColorOrTexture &texture, const COLLADAFW::EffectCommon *effectcommon)
	{
		const COLLADAFW::SamplerID sid = texture.getTexture().getSamplerId();
		const String &imageid = effectcommon->getSamplerPointerArray()[ sid ]->getSourceImage().toAscii();
		_Log("image name="<<imageid);
		strcpy_s(_3dsTexMap->name, 64, imageid.c_str());
	}
	//--------------------------------------------------------------------
	const COLLADAFW::EffectCommon* Writer::getEffectCommon( const COLLADAFW::Material* material)
	{
		const COLLADAFW::UniqueId& effectUniqueId = material->getInstantiatedEffect();
		const COLLADAFW::Effect* effect = getFWEffectByUniqueId(effectUniqueId);
		const COLLADAFW::CommonEffectPointerArray& commonEffects = effect->getCommonEffects();

		if ( commonEffects.getCount() == 0 )
		{
			return 0;
		}
		else
		{
			return commonEffects[0];
		}
	}
	//--------------------------------------------------------------------
	const COLLADAFW::Effect* Writer::getFWEffectByUniqueId( const COLLADAFW::UniqueId& effectUniqueId )
	{
		const Writer::UniqueIdFWEffectMap& map = this->getUniqueIdFWEffectMap();
		Writer::UniqueIdFWEffectMap::const_iterator it = map.find(effectUniqueId);
		if ( it == map.end() )
		{
			return 0;
		}
		else
		{
			return &it->second;
		}
	}
} // namespace DAE23ds
