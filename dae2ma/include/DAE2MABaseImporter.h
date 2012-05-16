/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_BASE_IMPORTER_H__
#define __DAE2MA_BASE_IMPORTER_H__

#include "DAE2MAStableHeaders.h"
#include "DAE2MADocumentImporter.h"

#include "COLLADABUIDList.h"
#include "Math/COLLADABUMathVector3.h"
#include "Math/COLLADABUMathMatrix3.h"

#include "MayaDMTypes.h"
#include "MayaDMLambert.h"

#include "COLLADAFWFloatOrDoubleArray.h"


namespace DAE2MA
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

        typedef std::map<COLLADAFW::UniqueId, size_t> UniqueIdSizeTMap;

        typedef std::vector<MayaDM::Lambert*> MayaEffectList;
        typedef std::map<COLLADAFW::UniqueId, MayaEffectList> UniqueIdMayaEffectsMap;

        /** Maps Unique id to framework nodes.*/
        typedef std::map<COLLADAFW::UniqueId, const COLLADAFW::Node*> UniqueIdFWNodeMap;

    public:

        /** The maya block size value for writing maya ascii files. */
        static const size_t MAYA_BLOCK_SIZE;

    protected:

        /** The standard name for a group without name. */
        static const String GROUP_ID_NAME;
        static const String GROUP_ID_NAME_APPEND;
        static const String GROUP_PARTS_NAME;
        static const String GROUP_PARTS_NAME_APPEND;

        static const String ATTRIBUTE_DATA_TYPE;
        static const String ATTRIBUTE_ATTRIBUTE_TYPE;
        static const String ATTRIBUTE_TYPE;
        static const String ATTRIBUTE_TYPE_STRING;
        static const String ATTRIBUTE_TYPE_STRING_ARRAY;
        static const String ATTRIBUTE_TYPE_COMPOUND;
        static const String ATTRIBUTE_PARENT;
        static const String ATTRIBUTE_NUMBER_OF_CHILDREN;
        static const String ATTRIBUTE_HIDDEN;

    private:

        /** An element of the class represent a extra element of the framework. 
        Every element has only one parent element, but can have multiple childs. */
        class ExtraTreeElement
        {
        private:
            String mName;
            String mValue;
            ExtraTreeElement* mParent;
            std::map<String, ExtraTreeElement*> mChildren;

        public:
            ExtraTreeElement ( const String& name, ExtraTreeElement* parent = 0 ) 
                : mName ( name ), mParent ( parent )  {}
            ExtraTreeElement ( const String& name, const String& val, ExtraTreeElement* parent = 0) 
                : mName ( name ), mValue ( val ), mParent ( parent ) {}
            virtual ~ExtraTreeElement () 
            {
                std::map<String, ExtraTreeElement*>::iterator it = mChildren.begin ();
                while ( it != mChildren.end () )
                {
                    ExtraTreeElement* childElement = it->second;
                    delete childElement;
                    childElement = 0;
                    ++it;
                }
                mChildren.clear ();
            }

            const String& getName () const { return mName; }
            const ExtraTreeElement* getParent () const { return mParent; }
            const String& getValue () const { return mValue; }
            void appendValue ( const String& val ) { mValue.append ( val ); }
            const std::map<String, ExtraTreeElement*>& getChildren () const { return mChildren; }

            /** Returns true, if the current element contains a child element with the given name. */
            ExtraTreeElement* getChild ( const String& childElementName )
            {
                std::map<String, ExtraTreeElement*>::const_iterator it = mChildren.find ( childElementName );
                if ( it != mChildren.end () ) return it->second;
                return 0;
            }

            /** Adds the given child element to the list of childs of the current element. 
            No check, if there already exist an element with the given name! */
            void addChild ( ExtraTreeElement* childElement )
            {
                mChildren [childElement->getName ()] = childElement;
            }
        };

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
         * Get the original maya id from the ExtraDataCallbackHandler, if it exist in the framework data.
         */
        String getOriginalMayaId ( 
            const ExtraDataCallbackHandler& mayaIdCallbackHandler, 
            const COLLADAFW::UniqueId& uniqueId, 
            const StringHash& hashElement );

//         /**
//          * First we have to build a tree. With this tree, we know the number of children of every 
//          * knot in the tree. We have to create a compound attribute for every knot. After we have
//          * created the compound attributes, we can set the extra data values.
//          */
//         void setExtraData ( const COLLADAFW::ExtraDataArray &extraDataArray );

        /**
        * Extract the 3x3 matrix from the transform matrix and normalize the columns of it.
        * @param const COLLADABU::Math::Matrix4 & transformMatrix
        * @return COLLADABU::Math::Matrix3
        */
        COLLADABU::Math::Matrix3 extract3x3MatrixWithNormalizedColumns ( 
            const COLLADABU::Math::Matrix4 &transformMatrix );

    private:

        /** Get the root extra element in the tree with the given name. */
        ExtraTreeElement* getRootExtraElement ( 
            const String& name, 
            const std::map<String, ExtraTreeElement*>& rootExtraTreeElements );

//         /**
//         * Build a tree of the extra data elements.
//         */
//         void createExtraDataTree ( 
//             const COLLADAFW::ExtraDataArray& extraDataArray, 
//             std::map<String, ExtraTreeElement*>& rootExtraTreeElements );

        /**
        * After we filled the tree, we have to create the attributes.
        */
        void addExtraDataAttributes ( const std::map<String, ExtraTreeElement*>& rootExtraTreeElements );

        /**
         * Recursive call to add an attribute.
         */
        void addExtraDataAttribute ( const ExtraTreeElement* extraTreeElement );

        /**
        * After all the attributes are created, we can set the attribute values.
        */
        void setExtraDataAttributes ( const std::map<String, ExtraTreeElement*>& rootExtraTreeElements );

        /**
        * Recursive call to set an attribute.
        */
        void setExtraDataAttribute ( const ExtraTreeElement* extraTreeElement );

    };
}

#endif // __DAE2MA_BASE_IMPORTER_H__