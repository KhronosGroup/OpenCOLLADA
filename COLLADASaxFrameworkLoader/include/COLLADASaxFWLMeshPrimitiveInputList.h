/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADASaxFrameworkLoader.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_INPUTLIST_H__
#define __COLLADASAXFWL_INPUTLIST_H__

#include "COLLADASaxFWLPrimitiveBase.h"
#include "COLLADASaxFWLInputShared.h"

#include "COLLADAFWMeshPrimitive.h"


namespace COLLADASaxFWL
{

    class MeshLoader;
	class Vertices;


    /**
    Geometric primitives, which assemble values from the inputs into vertex attribute data. 
    Can be any combination of any primitive types in any order. 

    To describe geometric primitives that are formed from the vertex data, the <mesh> element may 
    contain zero or more of the primitive elements <lines>, <linestrips>, <polygons>, <polylist>,
    <triangles>, <trifans>, and <tristrips>.
    The <vertices> element under <mesh> is used to describe mesh-vertices. Polygons, triangles, and 
    so forth index mesh-vertices, not positions directly. Mesh-vertices must have at least one 
    <input> (unshared) element with a semantic attribute whose value is POSITION.
    For texture coordinates, COLLADA’s right-handed coordinate system applies; therefore, an ST 
    texture coordinate of [0,0] maps to the lower-left texel of a texture image, when loaded in a 
    professional 2-D texture viewer/editor.
    */
    class MeshPrimitiveInputList 
    {

    private:
        /**
        * The input element may occur any number of times. This input is a local
        * input with the  offset and set attributes. 
        */
        InputSharedArray mInputArray;

        /**
         * The maximal offset value in the input element.
         */
        unsigned long long mInputArrayMaxOffset;
	
        /**
         * To convert the vertex input elements.
         */
		Vertices& mVertices;

    public:	

		/**
        * Constructor
        */
       MeshPrimitiveInputList ( Vertices& vertices ) 
            : mInputArray(InputSharedArray::OWNER)
            , mInputArrayMaxOffset (0)
			, mVertices(vertices)
        {}

        /**
        * Destructor
        */
        virtual ~MeshPrimitiveInputList() 
		{
			clearInputs();
		}

		/** Clears the inputs related contents but keeps the vertices.*/
		void clearInputs();
		
        /**
         * The input element may occur any number of times. This input is a 
         * local input with the  offset and set attributes.
         * @return const InputArray The array with the input elements.
         */
        const InputSharedArray& getInputArray () const 
        {
            return mInputArray; 
        }

        /**
         * Appends an input element in the list of input elements. 
         * Handle with care, new memory will be allocated!
         */
        const InputShared* appendInputElement ( InputShared* inputShared );

        /**
        * The input element may occur any number of times. This input is a 
        * local input with the  offset and set attributes.
        * @return const InputArray The array with the input elements.
        */
        const unsigned long long getInputArrayMaxOffset () const 
        {
            return mInputArrayMaxOffset;
        }


        /**
        * Returns the input element with the given semantic or 0 if it not exist.
        * @param semantic The semantic of the searched input element.
        * @param parent True, if the vertex element of the parent mesh should also searched.
        * @return InputShared* Pointer to the searched input element or 0 if it not exist.
        */
        const InputShared* getInputBySemantic ( const InputSemantic::Semantic& semantic ) const;

        /**
        * Returns the positions input element or 0 if it not exist.
        * @param parent True, if the vertex element of the parent mesh should also searched.
        * @return InputShared* Pointer to the searched input element or 0 if it not exist.
        */
        const InputShared* getPositionInput () const
        {
            return getInputBySemantic ( InputSemantic::POSITION );
        }

        /**
        * Returns the normals input element or 0 if it not exist.
        * @param parent True, if the vertex element of the parent mesh should also searched.
        * @return InputShared* Pointer to the searched input element or 0 if it not exist.
        */
        const InputShared* getNormalInput () const
        {
            return getInputBySemantic ( InputSemantic::NORMAL );
        }

        const InputShared* getTangentInput () const
        {
            return getInputBySemantic ( InputSemantic::TEXTANGENT );
        }

        const InputShared* getBinormalInput () const
        {
            return getInputBySemantic ( InputSemantic::TEXBINORMAL );
        }

    };

    
    typedef COLLADAFW::ArrayPrimitiveType<MeshPrimitiveInputList*> PolyBaseArray;

}

#endif // __COLLADASAXFWL_INPUTLIST_H__
