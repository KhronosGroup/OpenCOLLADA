/*
Copyright (c) 2009 NetAllied Systems GmbH

This file is part of dae2ogre.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2OGRE_BASEWRITER_H__
#define __DAE2OGRE_BASEWRITER_H__

#include "DAE2OgrePrerequisites.h"
#include "DAE2OgreOgreWriter.h"

namespace DAE2Ogre
{

	class BaseWriter 	
	{
	private:
		OgreWriter* mOgreWriter;
	
	public:
		BaseWriter( OgreWriter* ogreWriter);

		virtual ~BaseWriter();

		static void reportError(const String& method, const String& message, OgreWriter::Severity severity);

		const OgreWriter::GeometryUniqueIdInstanceGeometryInfoMap& getGeometryUniqueIdInstanceGeometryInfoMap();
		
		void addGeometryUniqueIdInstanceGeometryInfoPair(const COLLADAFW::UniqueId& geoId, const OgreWriter::InstanceGeometryInfo& instanceGeoInfo);

		const OgreWriter::UniqueIdFWMaterialMap& getUniqueIdFWMaterialMap() { return mOgreWriter->getUniqueIdFWMaterialMap(); }

		const OgreWriter::UniqueIdFWImageMap& getUniqueIdFWImageMap() { return mOgreWriter->getUniqueIdFWImageMap(); }

		const OgreWriter::UniqueIdFWEffectMap& getUniqueIdFWEffectMap() { return mOgreWriter->getUniqueIdFWEffectMap(); }

		const COLLADABU::URI& getInputFile() const { return mOgreWriter->getInputFile(); }

		const COLLADABU::URI& getOutputFile() const { return mOgreWriter->getOutputFile(); }



	private:

        /** Disable default copy ctor. */
		BaseWriter( const BaseWriter& pre );

        /** Disable default assignment operator. */
		const BaseWriter& operator= ( const BaseWriter& pre );

	};

} // namespace DAE2Ogre

#endif // __DAE2OGRE_BASEWRITER_H__
