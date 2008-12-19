/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_GEOMETRYOBJECTLOADER_H__
#define __COLLADASAXFWL_GEOMETRYOBJECTLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSource.h"
#include "COLLADASaxFWLFilePartLoader.h"


namespace COLLADASaxFWL
{

    /** 
    Base class that describes geometric data. Must be exactly one of:
     • <convex_mesh>
     • <mesh>
     • <spline> 
    More about, read the class Geometry documentation.
    */
    class GeometryObjectLoader : public FilePartLoader
    {

	private:
	
        /**
        * Provides the bulk of the mesh’s vertex data. See main entry.
        */
        SourceArray mSourceArray;

		/** The source currently being parsed.*/
		SourceBase* mCurrentSoure;

		/** The id of the source being parsed.*/
		String mCurrentSourceId;

	protected:

        /** Constructor. */
		GeometryObjectLoader ( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~GeometryObjectLoader();

        /**
        * Provides the bulk of the mesh’s vertex data. See main entry.
        * @param sourceArraySize Parameter to get the size of the source array.
        * @return const SourceArray The source array.
        */
        const SourceArray& getSourceArray () const;

        /**
        * Provides the bulk of the mesh’s vertex data. See main entry.
        * @param sourceArray The source array.
        * @param sourceArraySize The size of the source array.
        */
        void setSourceArray ( const SourceArray& sourceArray );

        /**
        * Returns the source element of the source array with the given id or 0 if it not exist.
        * @param sourceId The source id of the searched source element.
        * @return COLLADAFW::Source The source element with the given id or 0 if it not exist.
        */
        const SourceBase* getSourceById ( const String& sourceId ) const;

        /**
        * Returns the source element of the source array with the given id or 0 if it not exist.
        * @param sourceId The source id of the searched source element.
        * @return COLLADAFW::Source The source element with the given id or 0 if it not exist.
        */
        SourceBase* getSourceById ( const String& sourceId );

		/** Handles the beginning of a source element.*/
		bool beginSource(const mesh__source__AttributeData& attributes);

	private:

        /** Disable default copy ctor. */
		GeometryObjectLoader( const GeometryObjectLoader& pre );

        /** Disable default assignment operator. */
		const GeometryObjectLoader& operator= ( const GeometryObjectLoader& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADASAXFWL_GEOMETRYOBJECTLOADER_H__
