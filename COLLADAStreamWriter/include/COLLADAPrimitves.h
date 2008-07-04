/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
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


