#ifndef ___WRITER_H__
#define ___WRITER_H__


#include "COLLADAFWIWriter.h"

namespace COLLADAFW
{
	class Formulas;
	class Formula;
}

class Writer : public COLLADAFW::IWriter
{
	// member declarations
private:

	// public function declarations
public:
	Writer() : IWriter() {}
	virtual ~Writer(){}

	/** This method will be called if an error in the loading process occurred and the loader cannot
	continue to to load. The writer should undo all operations that have been performed.
	@param errorMessage A message containing informations about the error that occurred.
	*/
	virtual void cancel(const COLLADAFW::String& errorMessage){}

	/** This is the method called. The writer hast to prepare to receive data.*/
	virtual void start(){}

	/** This method is called after the last write* method. No other methods will be called after this.*/
	virtual void finish(){}

	/** When this method is called, the writer must write the global document asset.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeGlobalAsset ( const COLLADAFW::FileInfo* asset )
	{
		return true;
	}

	/** When this method is called, the writer must write the entire visual scene.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeScene ( const COLLADAFW::Scene* scene )
	{
		return true;
	}

	/** When this method is called, the writer must write the entire visual scene.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeVisualScene ( const COLLADAFW::VisualScene* visualScene ) 
	{
		return true;
	}

	/** When this method is called, the writer must handle all nodes contained in the 
	library nodes.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeLibraryNodes ( const COLLADAFW::LibraryNodes* libraryNodes ) 
	{
		return true;
	}

	/** When this method is called, the writer must write the geometry.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeGeometry ( const COLLADAFW::Geometry* geometry )
	{
		return true;
	}

	/** When this method is called, the writer must write the material.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeMaterial( const COLLADAFW::Material* material )
	{
		return true;
	}

	/** When this method is called, the writer must write the effect.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeEffect( const COLLADAFW::Effect* effect )
	{
		return true;
	}

	/** When this method is called, the writer must write the camera.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeCamera( const COLLADAFW::Camera* camera )
	{
		return true;
	}

	/** When this method is called, the writer must write the image.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeImage( const COLLADAFW::Image* image )
	{
		return true;
	}

	/** When this method is called, the writer must write the light.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeLight( const COLLADAFW::Light* light )
	{
		return true;
	}

	/** Writes the animation.
	@return True on succeeded, false otherwise.*/
	virtual bool writeAnimation( const COLLADAFW::Animation* animation )
	{ 
		return true; 
	}

	/** When this method is called, the writer must write the AnimationList.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeAnimationList( const COLLADAFW::AnimationList* animationList )		
	{ 
		return true; 
	}

	/** When this method is called, the writer must write the skin controller data.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeSkinControllerData( const COLLADAFW::SkinControllerData* skinControllerData )
	{ 
		return true; 
	}

	/** When this method is called, the writer must write the controller.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeController( const COLLADAFW::Controller* controller )
	{ 
		return true; 
	}

	/** When this method is called, the writer must write the formula.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeFormulas( const COLLADAFW::Formulas* formulas )
	{ 
		return true; 
	}

	/** When this method is called, the writer must write the formula.
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeFormula( const COLLADAFW::Formula* formulas )
	{ 
		return true; 
	}

	/** When this method is called, the writer must write the kinematics scene. 
	@return The writer should return true, if writing succeeded, false otherwise.*/
	virtual bool writeKinematicsScene( const COLLADAFW::KinematicsScene* kinematicsScene )		
	{ 
		return true; 
	}

	// private function declarations
private:
/** Disable default copy ctor. */
	Writer( const Writer& pre );
/** Disable default assignment operator. */
	const Writer& operator= ( const Writer& pre );

};

#endif // ___WRITER_H__
