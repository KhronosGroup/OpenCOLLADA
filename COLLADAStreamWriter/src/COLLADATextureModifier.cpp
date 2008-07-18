
#include "COLLADATextureModifier.h"
#include "FreeImage.h"

namespace COLLADA
{


	TextureModifier::TextureModifier( const String& inputFilePath, const String& outputFilePath )
		: mInputFilePath(inputFilePath)
		,mOutputFilePath(outputFilePath)
		,mUOffset(0)
		,mVOffset(0)
		,mUTiling(0)
		,mVTiling(0)
		,mRotationAngleDegree(0)
	{

	}


	bool TextureModifier::performModifications()
	{
		FREE_IMAGE_FORMAT imageFormat = FIF_TARGA;

		FIBITMAP* image = FreeImage_Load(imageFormat, mInputFilePath.c_str(), TARGA_DEFAULT);

		FIBITMAP* rotatedImage = FreeImage_RotateClassic(image, mRotationAngleDegree);
		

		FreeImage_Save(imageFormat, rotatedImage, mOutputFilePath.c_str());
		return true;
	}


} //namespace COLLADA

