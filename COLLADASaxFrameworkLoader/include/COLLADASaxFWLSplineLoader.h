/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_SPLINELOADER_H__
#define __COLLADASAXFWL_SPLINELOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLVertices.h"
#include "COLLADASaxFWLSource.h"
#include "COLLADASaxFWLMeshPrimitiveInputList.h"
#include "COLLADASaxFWLSourceArrayLoader.h"

#include "COLLADAFWSpline.h"


namespace COLLADASaxFWL
{
    class SplineLoader : public SourceArrayLoader
    {
	private:

        typedef std::map< String /*Id of the name array*/,  StringList> StringListMap;
    private:

		/** The unique id of the mesh.*/
		COLLADAFW::UniqueId mSplineUniqueId;

        /**
         * The framework mesh element, to load the data. 
         */
        COLLADAFW::Spline* mSpline;

        StringList mInterpolations;

        /**
         * Describes the mesh-vertex attributes and establishes
         * their topological identity.
         */
        Vertices mVerticesInputs;

        InputUnshared * mCurrentVertexInput;

        /** Flag is true, if we are currently in the vertices part. */
        bool mInVertices;

        /** Flag for the extra tag preservation, to know if we are parsing in the mesh. */
        bool mInSpline;

        bool loadPositions();
        bool loadOutTangents();
        bool loadInTangents();
        bool loadInterpolations();

    public:

        /** Constructor. */
		SplineLoader ( IFilePartLoader* callingFilePartLoader, const String& geometryId, const String& geometryName );

        /** Destructor. */
        virtual ~SplineLoader () { delete mSpline; }

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();

        /** Returns the mesh that has just been loaded.*/
		COLLADAFW::Spline* getSpline() { return mSpline; }

		/** Sax callback function for the beginning of a source element.*/
		virtual bool begin__source(const source__AttributeData& attributes);

		/** Sax callback function for the ending of a source element.*/
		virtual bool end__source();
		
		/** Cleans up everything and gives control to calling file part loader.*/
		virtual bool end__spline();

        /** Flag for the extra tag preservation, to know if we are parsing in the mesh. */
        const bool& isInSpline () const { return mInSpline; }
        void setInSpline ( const bool& val ) { mInSpline = val; }


		/** Sax callback function for the beginning of a input element.*/
		virtual bool begin__input____InputLocal( const input____InputLocal__AttributeData& attributeData );

		/** Sax callback function for the ending of a input element.*/
		virtual bool end__input____InputLocal();

        virtual bool begin__control_vertices();
        virtual bool end__control_vertices();

        virtual bool begin__Name_array( const Name_array__AttributeData& attributeData );
        virtual bool end__Name_array();
        virtual bool data__Name_array( const ParserString* data, size_t length );

        bool beginInterpolationArray( bool isIdArray );
        bool dataInterpolationArray( const ParserString* data, size_t length );

	private:

    };
}

#endif // __COLLADASAXFWL_MESHLOADER_H__
