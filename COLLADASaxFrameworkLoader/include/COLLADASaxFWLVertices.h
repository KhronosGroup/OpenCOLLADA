/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_VERTICES_H__
#define __COLLADASAXFWL_VERTICES_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLInputUnshared.h"


namespace COLLADASaxFWL
{

    /** 
     * Declares the attributes and identity of mesh-vertices.
     * The <vertices> element describes mesh-vertices in a mesh. The mesh-vertices represent the 
     * position (identity) of the vertices comprising the mesh and other vertex attributes that 
     * are invariant to tessellation.
     */
    class Vertices
    {

    private:

        /** 
        * A text string containing the unique identifier of the element. 
        * This value must be unique within the instance document. Required. 
        */
        String mId;

        /** 
        * The text string name of this element. Optional. 
        */
        String mName;

        /**
        * One input must specify semantic="POSITION" to establish the 
        * topological identity of each vertex in the mesh.
        */
        InputUnsharedArray mInputArray;

    public:

        /** Constructor. */
        Vertices ()  : mInputArray(InputUnsharedArray::OWNER) {}

        /** Destructor. */
		virtual ~Vertices ()
		{
			for ( size_t i = 0, count = mInputArray.getCount(); i < count; ++i)
				delete mInputArray[i];
		}

        /** 
        * A text string containing the unique identifier of the element. 
        * This value must be unique within the instance document. Required. 
        * @return String& Reference to the unique identifier of the element.
        */
        const String& getId () const { return mId; }

        /**
         * A text string containing the unique identifier of the element.
         * This value must be unique within the instance document. Required. 
         * @param val The unique identifier of the element.
         */
        void setId ( const String& val ) { mId = val; }

        /**
         * The text string name of this element. Optional. 
         * @return const String& Reference to the name.
         */
        const String& getName () const { return mName; }

        /**
         * The text string name of this element. Optional. 
         * @param val The name of the element.
         */
        void setName ( const String& val ) { mName = val; }

        /**
         * One input must specify semantic="POSITION" to establish the 
         * topological identity of each vertex in the mesh.
         * @return const COLLADAFW::InputArray The input array.
         */
        const InputUnsharedArray& getInputArray () const 
        { 
            return mInputArray; 
        }

        /**
        * One input must specify semantic="POSITION" to establish the 
        * topological identity of each vertex in the mesh.
        * @return const COLLADAFW::InputArray The input array.
        */
        InputUnsharedArray& getInputArray () 
        { 
            return mInputArray; 
        }

        /**
         * One input must specify semantic="POSITION" to establish the 
         * topological identity of each vertex in the mesh.
         * @param inputArray The input array to set.
         */
        void setInputArray ( const InputUnsharedArray& inputArray ) 
        { 
            mInputArray = inputArray; 
        }

        /**
         * Returns the first found input element with the given semantic or 0 if it not exist.
         * @param semantic The semantic of the searched input element.
         * @return InputUnshared* Pointer to the searched input element or 0 if it not exist.
         */
        const InputUnshared* getInputBySemantic ( const InputSemantic::Semantic& semantic ) const
        {
            for ( size_t i=0; i<mInputArray.getCount (); ++i )
            {
                InputUnshared* input = mInputArray [ i ];
                if ( input->getSemantic () == semantic )
                    return input;
            }
            return 0;
        }

    };
}

#endif // __COLLADASAXFWL_VERTICES_H__
