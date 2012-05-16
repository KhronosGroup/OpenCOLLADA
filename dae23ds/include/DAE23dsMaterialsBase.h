/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_MATERIALSBASE_H__
#define __DAE23DS_MATERIALSBASE_H__

#include "DAE23dsPrerequisites.h"
#include "DAE23dsBaseWriter.h"


namespace DAE23ds
{

	class MaterialsBase : public BaseWriter 
	{
	protected:
		const Writer::UniqueIdFWMaterialMap& mUniqueIdFWMaterialMap;
//		const Writer::UniqueIdFWImageMap& mUniqueIdFWImageMap;
		const Writer::UniqueIdFWEffectMap& mUniqueIdFWEffectMap;
	
	public:

        /** Constructor. */
		MaterialsBase(Writer* writer3ds);

        /** Destructor. */
		virtual ~MaterialsBase();

	protected:
		/** Returns the first common effect of the effect referenced by material.*/
		const COLLADAFW::EffectCommon* getEffectCommon( const COLLADAFW::Material* material);

		/** Calculates the length of the material block that will be created for @a material.*/
		ChunkLength calculateMaterialBlockLength( const COLLADAFW::Material* material);

		/** Calculates the length of the color blocks that will be created for @a material.*/
		ChunkLength MaterialsBase::calculateMaterialColorLength( const COLLADAFW::Material* material);

	private:

        /** Disable default copy ctor. */
		MaterialsBase( const MaterialsBase& pre );

        /** Disable default assignment operator. */
		const MaterialsBase& operator= ( const MaterialsBase& pre );

	};

} // namespace DAE23DS

#endif // __DAE23DS_MATERIALSBASE_H__
