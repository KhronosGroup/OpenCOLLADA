/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_VERTICES_H__
#define __COLLADAFW_VERTICES_H__

#include "COLLADAFWPrerequisites.h"

namespace COLLADAFW
{

    /** Declares the storage for the graphical representation of an object. */
    class Vertices
    {

    private:

        /** 
        * A text string containing the unique identifier of the element. 
        * This value must be unique within the instance document. Required. 
        */
        String mNodeId;

        /** 
        * The text string name of this element. Optional. 
        */
        String mNodeName;

        /**
        * One input must specify semantic="POSITION" to establish the 
        * topological identity of each vertex in the mesh.
        */
        InputArray mInputArray;

        /**
         * The size of the current input array. 
         */
        size_t mInputArraySize;

    public:

        /** Constructor. */
        Vertices () {}

        /** Destructor. */
        virtual ~Vertices () {}

        /** 
        * A text string containing the unique identifier of the element. 
        * This value must be unique within the instance document. Required. 
        */
        const String getNodeId () const { return mNodeId; }
        void setNodeId ( const String val ) { mNodeId = val; }

        /** 
        * The text string name of this element. Optional. 
        */
        const String getNodeName () const { return mNodeName; }
        void setNodeName ( const String val ) { mNodeName = val; }

        /**
         * One input must specify semantic="POSITION" to establish the 
         * topological identity of each vertex in the mesh.
         * @param inputArraySize Parameter for the size of the array.
         * @return const COLLADAFW::InputArray The input array.
         */
        const COLLADAFW::InputArray getInputArray ( size_t& inputArraySize ) const 
        { 
            inputArraySize = mInputArraySize;
            return mInputArray; 
        }

        /**
         * One input must specify semantic="POSITION" to establish the 
         * topological identity of each vertex in the mesh.
         * @param inputArray The input array to set.
         * @param inputArraySize The size of the array.
         */
        void setInputArray ( const COLLADAFW::InputArray inputArray, size_t inputArraySize ) 
        { 
            mInputArraySize = inputArraySize;
            mInputArray = inputArray; 
        }

    };
}

#endif // __COLLADAFW_VERTICES_H__