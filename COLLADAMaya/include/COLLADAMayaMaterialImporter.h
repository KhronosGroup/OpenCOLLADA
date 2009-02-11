/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_MATERIAL_IMPORTER_H__
#define __COLLADA_MAYA_MATERIAL_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseImporter.h"

#include "COLLADABUIDList.h"

#include "MayaDMDependNode.h"


namespace COLLADAMaya
{

    /** Declares the importer class for import materials. */
    class MaterialImporter : public BaseImporter
    {
    public:

        typedef std::map<COLLADAFW::UniqueId, MayaDM::DependNode*> UniqueIdMayaMaterialMap;

    private:

        /** The standard name for a material without name. */
        static const String MATERIAL_NAME;

    private:

        /**
        * The list of the unique maya material names.
        */
        COLLADABU::IDList mMaterialIdList;

        /** 
        * The map holds the unique ids of the nodes to the maya material name. 
        */
        UniqueIdNamesMap mMayaMaterialNamesMap;

        /**
         * The map holds the maya material objects.
         */
        UniqueIdMayaMaterialMap mMayaMaterialMap;

    public:

        /** Constructor. */
        MaterialImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
        virtual ~MaterialImporter () {}

        /** Imports the given material. */
        bool importMaterial ( const COLLADAFW::Material* material );

        /**
        * The map holds the maya material objects.
        */
        const UniqueIdMayaMaterialMap& getMayaMaterialMap () const { return mMayaMaterialMap; }

        /**
        * The map holds the maya material objects.
        */
        MayaDM::DependNode* findMayaMaterial ( const COLLADAFW::UniqueId& val ) const;

        /**
        * The map holds the maya material objects.
        */
        void appendMaterial ( const COLLADAFW::UniqueId& id, MayaDM::DependNode* materialNode );


    };
}

#endif // __COLLADA_MAYA_MATERIAL_IMPORTER_H__