/*
Copyright (c) 2008 NetAllied Systems GmbH

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

#ifndef __COLLADAMAX_GEOMETRYIMPORTER_H__
#define __COLLADAMAX_GEOMETRYIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"

namespace COLLADAFW
{
	class Geometry;
	class Mesh;
};


namespace COLLADAMax
{

    /** TODO Documentation */
	class GeometryImporter 	: public ImporterBase
	{
	private:
		/** The geometry that should be imported.*/
		const COLLADAFW::Geometry* mGeometry;
	
	public:

        /** Constructor. */
		GeometryImporter( DocumentImporter* documentImporter, const COLLADAFW::Geometry* geometry );

        /** Destructor. */
		virtual ~GeometryImporter();

		/** Performs the import of the geometry.
		@return True on success, false otherwise.*/
		bool import();


		/** Performs the import of the mesh.
		@return True on success, false otherwise.*/
		bool importMesh();


		/** Performs the import of the mesh positions .
		@return True on success, false otherwise.*/
		bool importMeshPositions( TriObject* triangleObject );

		/** Performs the import of the mesh normals .
		@return True on success, false otherwise.*/
		bool importMeshNormals( TriObject* triangleObject );

	private:

        /** Disable default copy ctor. */
		GeometryImporter( const GeometryImporter& pre );

        /** Disable default assignment operator. */
		const GeometryImporter& operator= ( const GeometryImporter& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_GEOMETRYIMPORTER_H__
