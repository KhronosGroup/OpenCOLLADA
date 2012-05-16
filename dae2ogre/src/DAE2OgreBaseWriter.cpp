/*
Copyright (c) 2009 NetAllied Systems GmbH

This file is part of dae2ogre.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2OgreStableHeaders.h"
#include "DAE2OgreBaseWriter.h"

#include "DAE2OgreOgreWriter.h"


namespace DAE2Ogre
{

    //------------------------------
	BaseWriter::BaseWriter( OgreWriter* ogreWriter )
		: mOgreWriter(ogreWriter)
	{
	}

    //------------------------------
	BaseWriter::~BaseWriter()
	{
	}

	//------------------------------
	void BaseWriter::reportError( const String& method, const String& message, OgreWriter::Severity severity )
	{
		OgreWriter::reportError(method, message, severity);
	}

	//------------------------------
	const OgreWriter::GeometryUniqueIdInstanceGeometryInfoMap& BaseWriter::getGeometryUniqueIdInstanceGeometryInfoMap()
	{
		return mOgreWriter->getGeometryUniqueIdInstanceGeometryInfoMap();
	}

	//------------------------------
	void BaseWriter::addGeometryUniqueIdInstanceGeometryInfoPair( const COLLADAFW::UniqueId& geoId, const OgreWriter::InstanceGeometryInfo& instanceGeoInfo )
	{
		OgreWriter::GeometryUniqueIdInstanceGeometryInfoMap& map = mOgreWriter->getGeometryUniqueIdInstanceGeometryInfoMap();
		map.insert(std::make_pair(geoId, instanceGeoInfo));
	}


} // namespace DAE2Ogre
