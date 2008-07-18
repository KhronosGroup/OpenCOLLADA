/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAStreamWriter.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_TEXTUREMODIFIER_H__
#define __COLLADASTREAMWRITER_TEXTUREMODIFIER_H__

#include "COLLADAPrerequisites.h"

namespace COLLADA
{

	/** Class to modify texture files, i.e. rotate and repeate the image*/
	class TextureModifier
	{
	public:
		TextureModifier(const String& inputFilePath, const String& outputFilePath);

		void setUOffset(double uOffset) {mUOffset = uOffset;}
		void setVOffset(double vOffset) {mVOffset = vOffset;}

		void setUTiling(double uTiling) {mUTiling = uTiling;}
		void setVTiling(double vTiling) {mVTiling = vTiling;}

		void setRotationAngle(double rotationAngel) {mRotationAngleDegree = rotationAngel;}

		bool performModifications();

	private:
		String mInputFilePath;
		String mOutputFilePath;

		double mUOffset; 
		double mVOffset; 

		double mUTiling; 
		double mVTiling; 

		double mRotationAngleDegree;
	};


} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_TEXTUREMODIFIER_H__

