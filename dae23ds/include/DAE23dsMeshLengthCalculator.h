/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_MESHLENGTHCALCULATOR_H__
#define __DAE23DS_MESHLENGTHCALCULATOR_H__

#include "DAE23dsPrerequisites.h"
#include "DAE23dsMeshBase.h"


namespace DAE23ds
{

	class MeshLengthCalculator: public MeshBase 
	{
	private:

	public:

		/** Constructor. */
		MeshLengthCalculator(Writer* writer3ds, const Writer::MeshData& meshData);

		/** Destructor. */
		virtual ~MeshLengthCalculator();

		/** Writes the mesh using @a materialBindings to assign materials.*/
		bool writeMeshIntoMultipleObjects( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const WriteMeshIntoMultipleObjectsData& data, const COLLADAFW::InstanceGeometry* alreadyUsingInstance);

		/** Writes the mesh using @a materialBindings to assign materials.*/
		bool writeMeshIntoOneObject( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const WriteMeshIntoOneObject& data, const COLLADAFW::InstanceGeometry* alreadyUsingInstance);


	private:

		/** Disable default copy ctor. */
		MeshLengthCalculator( const MeshLengthCalculator& pre );

		/** Disable default assignment operator. */
		const MeshLengthCalculator& operator= ( const MeshLengthCalculator& pre );

	};

} // namespace DAE23DS

#endif // __DAE23DS_MESHLENGTHCALCULATOR_H__
