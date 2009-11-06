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

#include "COLLADABUIDList.h"
#include "Math/COLLADABUMathVector3.h"

#include "MayaDMTypes.h"
#include "MayaDMLambert.h"

#include "COLLADAFWFloatOrDoubleArray.h"
#include "COLLADAFWExtraData.h"


namespace COLLADAMaya
{

    /** Declares the base import functionality. 
    This is the base class for all importers. */
    class BaseImporter
    {
    public:

        typedef std::map<COLLADAFW::UniqueId, COLLADAFW::UniqueId> UniqueIdUniqueIdMap;
        typedef std::map<COLLADAFW::UniqueId, String> UniqueIdStringMap;

        typedef std::vector<COLLADAFW::UniqueId> UniqueIdVec;
        typedef std::map<COLLADAFW::UniqueId, UniqueIdVec> UniqueIdUniqueIdsMap;

        typedef std::vector<MayaNode*> MayaNodesList;
        typedef std::map<COLLADAFW::UniqueId, MayaNodesList> UniqueIdMayaNodesMap;

        typedef std::map<COLLADAFW::UniqueId, MayaNode*> UniqueIdMayaNodeMap;
        typedef std::map<COLLADAFW::UniqueId, MayaDM::Mesh> UniqueIdMayaDMMeshMap;

        typedef std::map<COLLADAFW::UniqueId, MayaDM::DependNode*> UniqueIdDependNodeMap;

        typedef std::map<COLLADAFW::UniqueId, size_t> UniqueIdElementCountMap;

        typedef std::vector<MayaDM::Lambert*> MayaEffectList;
        typedef std::map< COLLADAFW::UniqueId, MayaEffectList > UniqueIdMayaEffectsMap;

        /** Maps Unique id to framework nodes.*/
        typedef std::map<COLLADAFW::UniqueId, const COLLADAFW::Node*> UniqueIdFWNodeMap;

    public:

        /** The maya block size value for writing maya ascii files. */
        static const size_t MAYA_BLOCK_SIZE;

        static const String ATTRIBUTE_DATA_TYPE;
        static const String ATTRIBUTE_TYPE;
        static const String ATTRIBUTE_TYPE_STRING;

    protected:

        /** The standard name for a group without name. */
        static const String GROUP_ID_NAME;
        static const String GROUP_ID_NAME_APPEND;
        static const String GROUP_PARTS_NAME;
        static const String GROUP_PARTS_NAME_APPEND;

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

        /**
        * This unit convert factor calculates always the centimeter unit, because this is 
        * the maya internal unit.
        * This is need for conversion of the skin controller bind shape and geometry (?) matrix
        * translate values conversion, because maya doesn't calculate the right values on linear
        * unit switching.
        */
        double toMayaBindShapeBugLinearUnit ( const double val );

        /**
        * This unit convert factor calculates always the centimeter unit, because this is 
        * the maya internal unit.
        * This is need for conversion of the skin controller bind shape and geometry (?) matrix
        * translate values conversion, because maya doesn't calculate the right values on linear
        * unit switching.
        */
        float toMayaBindShapeBugLinearUnit ( const float val );

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

        /**
        * Returns the value at the given position of the given array as double value.
        */
        double getDoubleValue ( 
            const COLLADAFW::FloatOrDoubleArray &inputValuesArray, 
            const size_t position );

        /**
        * Returns the value at the given position of the given array as float value.
        */
        float getFloatValue ( 
            const COLLADAFW::FloatOrDoubleArray &inputValuesArray, 
            const size_t position );

        /**
        * Generates a unique depend node id and add the node in all necessary lists. 
        */
        String generateUniqueDependNodeName ( 
            String nodeName,
            bool returnConverted = true, 
            bool alwaysAddNumberSuffix = false );

        /**
         * Generates a unique scene graph dag node id and add the node in all necessary lists. 
         */
        String generateUniqueDagNodeName ( 
            String nodeName, 
            MayaNode* parentMayaNode,
            bool returnConverted = true, 
            bool alwaysAddNumberSuffix = false );

        /**
         * Reads the original maya id from the extra tags, if it exist in the framework data.
         */
        String getOriginalMayaId ( const COLLADAFW::ExtraDataArray &extraDataArray );

    };
}

#endif // __COLLADA_MAYA_BASE_IMPORTER_H__