/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_BASE_IMPORTER_H__
#define __COLLADA_MAYA_BASE_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentImporter.h"

#include "Math/COLLADABUMathVector3.h"

#include "MayaDMTypes.h"
#include "MayaDMLambert.h"


namespace COLLADAMaya
{

    /** Declares the base import functionality. 
    This is the base class for all importers. */
    class BaseImporter
    {
    public:

        typedef std::set<const COLLADAFW::UniqueId> UniqueIdSet;
        typedef std::pair<COLLADAFW::UniqueId, COLLADAFW::UniqueId> UniqueIdsPair;

        typedef std::map<COLLADAFW::UniqueId, COLLADAFW::UniqueId> UniqueIdUniqueIdMap;
        typedef std::map<COLLADAFW::UniqueId, String> UniqueIdStringMap;

        typedef std::vector<COLLADAFW::UniqueId> UniqueIdVec;
        typedef std::map<COLLADAFW::UniqueId, UniqueIdVec> UniqueIdUniqueIdsMap;

        typedef std::vector<MayaNode*> MayaNodesList;
        typedef std::map<COLLADAFW::UniqueId, MayaNodesList> UniqueIdMayaNodesMap;

        typedef std::map<COLLADAFW::UniqueId, MayaNode*> UniqueIdMayaNodeMap;
        typedef std::map<COLLADAFW::UniqueId, MayaDM::Mesh> UniqueIdMayaDMMeshMap;

        typedef std::map<COLLADAFW::UniqueId, MayaDM::DependNode*> UniqueIdDependNodeMap;

        typedef std::pair<COLLADAFW::UniqueId,COLLADAFW::MaterialId> UniqueIdMaterialIdPair;
        typedef std::vector<size_t> IndicesVector;
        typedef std::map<UniqueIdMaterialIdPair, IndicesVector> CombinedIdIndicesMap;

        typedef std::map<COLLADAFW::UniqueId, size_t> UniqueIdElementCountMap;

        typedef std::vector<MayaDM::Lambert*> MayaEffectList;
        typedef std::map< COLLADAFW::UniqueId, MayaEffectList > UniqueIdMayaEffectsMap;

    public:

        /** The maya block size value for writing maya ascii files. */
        static const size_t MAYA_BLOCK_SIZE;

        /** The standard name for the collada id attribute. */
        static const String COLLADA_ID_ATTRIBUTE_NAME;

    private:

        /** Pointer to the current document importer. */
        DocumentImporter* mDocumentImporter;

    public:

        /** Constructor. */
        BaseImporter ( DocumentImporter* documentImporter )
        : mDocumentImporter ( documentImporter )
        {}

        /** Destructor. */
        virtual ~BaseImporter () {}

        /**
        * Converts the given value to the linear unit in meters.
        * How many real-world meters in one distance unit as a floating-point number.
        * For example, 1.0 for the name "meter"; 1000 for the name "kilometer";
        * 0.3048 for the name "foot".
        */
        MayaDM::double3 toLinearUnit ( const MayaDM::double3& val );

        /**
        * Converts the given value to the angular unit in meters.
        * For this we need a conversion from radians to degrees and have to look for the up-axis.
        */
        MayaDM::double3 toAngularUnit ( const MayaDM::double3& val );

        /**
         * In depend on the up axis, the order of the values will be changed.
         */
//        MayaDM::double3 toUpAxisTypeAxis ( const MayaDM::double3& val );

        /**
        * In depend on the up axis, the order of the values will be changed.
        */
//        MayaDM::double3 toUpAxisTypeFactor ( const MayaDM::double3& val );

        /**
        * Converts the given value to the linear unit in meters.
        * How many real-world meters in one distance unit as a floating-point number.
        * For example, 1.0 for the name "meter"; 1000 for the name "kilometer";
        * 0.3048 for the name "foot".
        */
        MVector toLinearUnit ( const MVector& val );

        /**
        * Converts the given value to the linear unit in meters.
        * How many real-world meters in one distance unit as a floating-point number.
        * For example, 1.0 for the name "meter"; 1000 for the name "kilometer";
        * 0.3048 for the name "foot".
        */
        void toLinearUnit ( const double val0, const double val1, const double val2, COLLADABU::Math::Vector3& retVal );

        /**
        * Converts the given value to the linear unit in meters.
        * How many real-world meters in one distance unit as a floating-point number.
        * For example, 1.0 for the name "meter"; 1000 for the name "kilometer";
        * 0.3048 for the name "foot".
        */
        double toLinearUnit ( const double val );

        /**
        * Converts the given value to the linear unit in meters.
        * How many real-world meters in one distance unit as a floating-point number.
        * For example, 1.0 for the name "meter"; 1000 for the name "kilometer";
        * 0.3048 for the name "foot".
        */
        float toLinearUnit ( const float val );

    protected:

        /** Returns a pointer to the current document importer. */
        DocumentImporter* getDocumentImporter () { return mDocumentImporter; }

        /** Returns a pointer to the current document importer. */
        const DocumentImporter* getDocumentImporter () const { return mDocumentImporter; }

        /** Returns the tolerance value for double value comparison. */
        const double getTolerance () const 
        {
            return getDocumentImporter ()->getTolerance ();
        }

    };
}

#endif // __COLLADA_MAYA_BASE_IMPORTER_H__