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

#ifndef __COLLADAMAX_MATERIALCREATOR_H__
#define __COLLADAMAX_MATERIALCREATOR_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"


namespace COLLADAMax
{

    /** TODO Documentation */
	class MaterialCreator : public ImporterBase 
	{
	public:
		/** Maps framework effects to max materials.*/
		typedef std::map<COLLADAFW::UniqueId, Mtl*> UniqueIdMaxMaterialMap;
	private:

		/** Maps all the framework effects already created a max material for, to the max 
		material.*/
		UniqueIdMaxMaterialMap mUniqueIdMaxMaterialMap;
	
	public:

        /** Constructor. */
		MaterialCreator( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~MaterialCreator();

		/** Performs the creation of all material.
		@return True on success, false otherwise.*/
		bool create();

		/** Creates all the material referenced in @a materialBinding, if not already created and 
		assigns them to the node in @a materialBinding.*/
		bool createAndAssingMaxMaterial( const DocumentImporter::NodeMaterialBindingsPair& materialBinding );

		/** Creates a standard material from @a effectCommon.*/ 
		StdMat2* createStandardMaterial( const COLLADAFW::EffectCommon& effectCommon, const String& name);

		/** Creates a material from @a effect.*/
		Mtl* createMaxMaterial( const COLLADAFW::Effect& effect);

		/** Returns the material created for @a effect. If for the same effect a max material has already been 
		created for, the formally created one is returned, otherwise a new one is created.*/
		Mtl* getMaxMaterial( const COLLADAFW::Effect& effect);

		/** Returns the effect used by @a materialBinding. It resolves first the material and than the effect.
		If the effect could not be resolved, null is returned.*/
		const COLLADAFW::Effect* getEffect( const COLLADAFW::InstanceGeometry::MaterialBinding& materialBinding );

	private:

        /** Disable default copy ctor. */
		MaterialCreator( const MaterialCreator& pre );

        /** Disable default assignment operator. */
		const MaterialCreator& operator= ( const MaterialCreator& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_MATERIALCREATOR_H__
