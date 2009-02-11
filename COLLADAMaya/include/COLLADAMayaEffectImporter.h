/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_EFFECTIMPORTER_H__
#define __COLLADAMAYA_EFFECTIMPORTER_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAMayaBaseImporter.h"

#include "COLLADABUIDList.h"


namespace COLLADAMaya
{

    /** TODO Documentation */
	class EffectImporter : public BaseImporter
    {
    public:

        typedef std::map<COLLADAFW::UniqueId, MayaDM::DependNode*> UniqueIdMayaDependNodeMap;
        typedef std::map<COLLADAFW::UniqueId, std::vector<MayaDM::DependNode*>> UniqueIdDependNodesMap;

    private:
	
        /** The standard name for a effect without name. */
        static const String EFFECT_NAME;

    private:

        /**
        * The list of the unique maya effect names.
        */
        COLLADABU::IDList mEffectIdList;

        /** 
        * The map holds the unique ids of the nodes to the maya effect name. 
        */
        UniqueIdNamesMap mMayaEffectNamesMap;

        /**
        * The map holds the maya effect objects.
        */
        UniqueIdMayaDependNodeMap mMayaEffectMap;

        /**
         * One effect can have multiple materials. But one material just one effect.
         */
        UniqueIdDependNodesMap mEffectMaterialsMap;

    public:

        /** Constructor. */
		EffectImporter (  DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~EffectImporter ();

        /** Imports the given material. */
        bool importEffect ( const COLLADAFW::Effect* effect );

        /**
        * The map holds the maya material objects.
        */
        const UniqueIdMayaDependNodeMap& getMayaEffectMap () const { return mMayaEffectMap; }

        /**
        * The map holds the maya material objects.
        */
        MayaDM::DependNode* findMayaEffect ( const COLLADAFW::UniqueId& val ) const;

        /**
        * The map holds the maya material objects.
        */
        void appendEffect ( const COLLADAFW::UniqueId& id, MayaDM::DependNode* effectNode );

        /**
        * One effect can have multiple materials. But one material just one effect.
        */
        const UniqueIdDependNodesMap getEffectMaterialsMap () const { return mEffectMaterialsMap; }


	private:

        /**
         * Imports a lambert shader effect.
         */
        void importLambertShader ( const COLLADAFW::Effect* effect );

        /** Disable default copy ctor. */
		EffectImporter( const EffectImporter& pre );

        /** Disable default assignment operator. */
		const EffectImporter& operator= ( const EffectImporter& pre );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_EFFECTIMPORTER_H__
