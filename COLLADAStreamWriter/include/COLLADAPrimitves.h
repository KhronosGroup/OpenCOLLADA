/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_PRIMITIVES_H__
#define __COLLADASTREAMWRITER_PRIMITIVES_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include "COLLADAInputList.h"
#include "COLLADASWC.h"

#include <vector>
#include <assert.h>

namespace COLLADA
{

    class PrimitivesBase : public ElementWriter
    {

    public:

        /** The list of v-counts. */
        typedef std::vector<unsigned long> VCountList;

    private:

        TagCloser mPrimitiveCloser;

        /** The material symbol*/
        String mMaterial;

        /** The primitive count*/
        unsigned long mCount;

        /** List of all the inputs*/
        InputList mInputList;

        /** List of the number in the @a \<vcount\> element*/
        VCountList mVCountList;

    public:

        /**
         * Constructor.
         * @param streamWriter Pointer to the collada stream.
         */
        PrimitivesBase ( StreamWriter * streamWriter ) 
        : ElementWriter ( streamWriter )
        , mInputList ( streamWriter ) 
        {}

        /**
         * Destructor.
         */
        virtual ~PrimitivesBase() {}

        /** Sets the material symbol*/
        void setMaterial ( const String & material )
        {
            mMaterial = material;
        }

        /** Returns the material Symbol*/
        const String& getMaterial() const
        {
            return mMaterial;
        }

        /** Sets the primitive count*/
        void setCount ( unsigned long count )
        {
            mCount = count;
        }

        /** Returns the primitive count*/
        unsigned long getCount() const
        {
            return mCount;
        }

        /** Returns a reference to the list of all the inputs*/
        InputList& getInputList()
        {
            return mInputList;
        }

        /**
        * Returns a reference to the vCountList.         
        * @return VCountList& Reference to the vCountList.
        */
        VCountList& getVCountList() 
        { 
            return mVCountList; 
        }

        /**
        * Set the vCountList.         
        * @param VCountList& The vCountList.
        */
        void setVCountList(VCountList vCountList) 
        { 
            mVCountList = vCountList; 
        }

        /** Adds @a number to the array*/
        void appendValues ( const std::vector<unsigned long>& numberVec )
        {
            mSW->appendValues ( numberVec );
        }

        /** Adds @a number to the array*/
        void appendValues ( const unsigned long number )
        {
            mSW->appendValues ( number );
        }

        /** Adds @a number1  and @a number2 to the array*/
        void appendValues ( const unsigned long number1, const unsigned long number2 )
        {
            mSW->appendValues ( number1, number2 );
        }

        /** Adds @a number1, @a number2 and @a number3 to the array*/
        void appendValues ( const unsigned long number1, const unsigned long number2, const unsigned long number3 )
        {
            mSW->appendValues ( number1, number2, number3 );
        }

        /** Adds @a number1, @a number2, @a number3 and @a number4 to the array*/
        void appendValues ( const unsigned long number1, const unsigned long number2, const unsigned long number3, const unsigned long number4 )
        {
            mSW->appendValues ( number1, number2, number3, number4 );
        };

        /** 
         * This function must be called after the last value has been added to 
         * the array and before another element has been opened
         */
        void finish();

    protected:

        /** Prepares to fill the <p> element. This member must be called exactly once
        before add is called the first time.*/
        void prepareBaseToAppendValues ( const String * primitiveName, bool openPolylistElement=true );

    };


    template<const String * primitiveName>
    class Primitive : public PrimitivesBase
    {

    public:
        Primitive ( StreamWriter * streamWriter ) : PrimitivesBase ( streamWriter ) {}

        /** This constructor should never be called. It is only provided to make std::map happy*/
        Primitive() : PrimitivesBase ( 0 )
        {
            assert ( false );
        }

        /** Copy constructor */
        Primitive ( PrimitivesBase primitivesBase ) : PrimitivesBase ( primitivesBase ) {}

        /** Prepares to fill the @a \<p\> element.
        This member must be called exactly once before add is called the first time.*/
        void prepareToAppendValues()
        {
            prepareBaseToAppendValues ( primitiveName );
        }

    };


    /**
     * Class for the polygons element.
     */
    class Polygons : public PrimitivesBase
    {

    public:
        /**
         * Constructor.
         * @param streamWriter Pointer to the collada stream.
         */
        Polygons ( StreamWriter* streamWriter ) : PrimitivesBase ( streamWriter ) {}

        /** Copy constructor */
        Polygons ( PrimitivesBase primitivesBase ) : PrimitivesBase ( primitivesBase ) {}

        /** We don't want to open the polylist tag */
        void prepareToAppendValues()
        {
            prepareBaseToAppendValues ( &CSWC::COLLADA_ELEMENT_POLYGONS, false );
        }

        /**
         * Opens the polylist element.
         */
        void openPolylist()
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_P );
        }

        /**
        * Opens the polylist hole element.
        */
        void openPolylistHole()
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_PH );
        }

        /**
        * Opens the hole element.
        */
        void openHole()
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_H );
        }

        /**
        * Close the last opened element.
        */
        void closeElement()
        {
            mSW->closeElement();
        }
    };



    typedef Primitive<&CSWC::COLLADA_ELEMENT_TRIANGLES> Triangles;
    typedef Primitive<&CSWC::COLLADA_ELEMENT_POLYLIST> Polylist;
    typedef Primitive<&CSWC::COLLADA_ELEMENT_VERTEX_WEIGHTS> VertexWeightsElement;

} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_PRIMITIVES_H__


