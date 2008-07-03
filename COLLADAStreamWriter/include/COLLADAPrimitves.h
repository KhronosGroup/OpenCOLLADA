/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
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
        PrimitivesBase ( StreamWriter * streamWriter ) : ElementWriter ( streamWriter ), mInputList ( streamWriter ) {}

        /** Sets the material symbol*/
        void setMaterial ( const String & material )
        {
            mMaterial = material;
        }

        /** Returns the material Symbol*/
        const String & getMaterial() const
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
        InputList & getInputList()
        {
            return mInputList;
        }


        /** List of the number in the @a \<vcount\> element*/
        typedef std::vector<unsigned long> VCountList;
        VCountList mVCountList;

        /** Adds @a number to the array*/
        void appendValues ( unsigned long number )
        {
            mSW->appendValues ( number );
        }

        /** Adds @a number1  and @a number2 to the array*/
        void appendValues ( unsigned long number1, unsigned long number2 )
        {
            mSW->appendValues ( number1, number2 );
        }

        /** Adds @a number1, @a number2 and @a number3 to the array*/
        void appendValues ( unsigned long number1, unsigned long number2, unsigned long number3 )
        {
            mSW->appendValues ( number1, number2, number3 );
        }

        /** Adds @a number1, @a number2, @a number3 and @a number4 to the array*/
        void appendValues ( unsigned long number1, unsigned long number2, unsigned long number3, unsigned long number4 )
        {
            mSW->appendValues ( number1, number2, number3, number4 );
        };


        /** This function must be called after the last value has been added to the array and before another
        element has been opened*/
        void finish();

    protected:
        /** Prepares to fill the <p> element. This member must be called exactly once
        before add is called the first time.*/
        void prepareBaseToAppendValues ( const String * primitiveName, bool openPolylistElement=true );


    private:
        TagCloser mPrimitiveCloser;

        /** The material symbol*/
        String mMaterial;

        /** The primitive count*/
        unsigned long mCount;

        /** List of all the inputs*/
        InputList mInputList;

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



    class Polygons : public PrimitivesBase
    {

    public:
        Polygons ( StreamWriter* streamWriter ) : PrimitivesBase ( streamWriter ) {}

        /** Copy constructor */
        Polygons ( PrimitivesBase primitivesBase ) : PrimitivesBase ( primitivesBase ) {}

        /** We don't want to open the polylist tag */
        void prepareToAppendValues()
        {
            prepareBaseToAppendValues ( &CSWC::COLLADA_ELEMENT_POLYGONS, false );
        }

        void openPolylist()
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_P );
        }

        void openPolylistHole()
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_PH );
        }

        void openHole()
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_H );
        }

        void closeElement()
        {
            mSW->closeElement();
        }
    };



    typedef Primitive<&CSWC::COLLADA_ELEMENT_TRIANGLES> Triangles;
    typedef Primitive<&CSWC::COLLADA_ELEMENT_POLYLIST> Polylist;

} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_PRIMITIVES_H__


