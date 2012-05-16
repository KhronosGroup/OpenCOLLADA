/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_MATERIALWRITER_H__
#define __DAE23DS_MATERIALWRITER_H__

#include "DAE23dsPrerequisites.h"
#include "DAE23dsMaterialsBase.h"


namespace DAE23ds
{

	class MaterialsWriter : public MaterialsBase 
	{
	private:
		Common::Buffer& mBuffer;

	public:

        /** Constructor. */
		MaterialsWriter(Writer* writer3ds);

        /** Destructor. */
		virtual ~MaterialsWriter();

		/** Writes all the material block and fill the Unique ID Material Number map.*/
		bool write();

	private:

        /** Disable default copy ctor. */
		MaterialsWriter( const MaterialsWriter& pre );

        /** Disable default assignment operator. */
		const MaterialsWriter& operator= ( const MaterialsWriter& pre );
		
		/** writes one color block using rgb byte .*/
		bool writeColorBlock(const COLLADAFW::Color& color, ChunkID chunkId);
	};

} // namespace DAE23DS

#endif // __DAE23DS_MATERIALWRITER_H__
