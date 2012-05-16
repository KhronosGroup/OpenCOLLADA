/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_PRIMITIVES_H__
#define __COLLADASTREAMWRITER_PRIMITIVES_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWInputList.h"
#include "COLLADASWConstants.h"

#include <vector>
#include <string.h>

namespace COLLADASW
{

    class PrimitivesBase : public ElementWriter
    {

    public:

        /** The list of vertex counts per polygons. */
        typedef std::vector<unsigned long> VCountList;

    private:

        /** Pointer to the primitives closer. */
        TagCloser mPrimitiveCloser;

		/** List of all the inputs*/
        InputList mInputList;

        /** Name of the current primitive. */
        String mPrimitiveName;

        /** The material symbol*/
        String mMaterial;

        /** The primitive count*/
        unsigned long mCount;

        /** List of the number in the @a \<vcount\> element*/
        VCountList mVCountList;

    public:

        /**
         * Constructor.
         * @param streamWriter Pointer to the collada stream.
         */
        PrimitivesBase ( StreamWriter* streamWriter, const String& primitiveName=EMPTY_STRING ) 
        : ElementWriter ( streamWriter )
        , mInputList ( streamWriter )
        , mPrimitiveName ( primitiveName )
        {
            if ( strcmp(primitiveName.c_str(), mPrimitiveName.c_str() ) != 0)
            {
                mPrimitiveCloser = mSW->openElement ( primitiveName );
            }
        }

        /**
         * Destructor.
         */
        virtual ~PrimitivesBase() {}

        /** Opens the primitives name element. */
        void openPrimitiveElement ( );

        /** Appends the material symbol. */
        void appendMaterial ( const String& material );

        /** Appends the input list. */
        void appendInputList ( );

        /** Append the given count to the list. */
        void appendCount ( const unsigned int count );

        /** Appends the the count. */
        void appendCount ( const unsigned long count );

        /** Appends the vertex count element. */
        void appendVertexCount( const unsigned long vCount );

        /** Appends the vertex count elements in the list. */
        void appendVertexCount( const VCountList& vCountList );

        /** Opens the vertex count list element. */
        void openVertexCountListElement();

		/** Closes the \<vcount\> element and opens the \<v\> element. Call openVertexCountListElement() to open
		the \<vcount\> element. Call finish() to close the \<v\> element.*/
		void CloseVCountAndOpenVElement();

        /** Close the last opened element. */
        void closeElement ();

        /** Opens the polylist element. */
        void openPolylistElement ();

        /** Sets the material symbol*/
        void setMaterial ( const String& material )
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
        void appendValues ( const int number )
        {
            mSW->appendValues ( number );
        }

        /** Adds @a number to the array*/
        void appendValues ( const unsigned int number )
        {
            mSW->appendValues ( number );
        }

        /** Adds @a number to the array*/
        void appendValues ( const long number )
        {
            mSW->appendValues ( number );
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
        /** 
         * Prepares to fill the <p> element. This member must be called exactly 
         * once before add is called the first time.
         * @param openPolyListElement If true, the <p> element will be opened.
         * @param openVertexListElement 
         *          If true, and the parameter @openPolylistElement is false, 
         *          the <v> element will be opened.
         */
        void prepareBaseToAppendValues ( bool openPolyListElement=true, bool openVertexListElement=false );

    };


    template<const String& primitiveName>
    class Primitive : public PrimitivesBase
    {

    public:
        Primitive ( StreamWriter* streamWriter ) 
        : PrimitivesBase ( streamWriter, primitiveName ) 
        {}

        /** This constructor should never be called. It is only provided to make std::map happy*/
        Primitive() : PrimitivesBase ( 0 )
        {
            assert ( false );
        }

        /** Copy constructor */
        Primitive ( PrimitivesBase primitivesBase ) 
        : PrimitivesBase ( primitivesBase ) {}

        /** Prepares to fill the @a \<p\> element.
        This member must be called exactly once before add is called the first time.*/
        void prepareToAppendValues()
        {
            prepareBaseToAppendValues ( );
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
        Polygons ( StreamWriter* streamWriter ) 
        : PrimitivesBase ( streamWriter, CSWC::CSW_ELEMENT_POLYGONS ) {}

        /** Copy constructor */
        Polygons ( PrimitivesBase primitivesBase ) 
        : PrimitivesBase ( primitivesBase ) {}

        /** We don't want to open the polylist tag */
        void prepareToAppendValues()
        {
            prepareBaseToAppendValues ( false );
        }

        /**
        * Opens the polylist hole element.
        */
        void openPolylistHoleElement()
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_PH );
        }

        /**
        * Opens the hole element.
        */
        void openHoleElement()
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_H );
        }

    };

    /**
    * Class for the polygons element.
    */
    class VertexWeightsElement : public PrimitivesBase
    {
    public:

        /**
        * Constructor.
        * @param streamWriter Pointer to the collada stream.
        */
        VertexWeightsElement ( StreamWriter* streamWriter ) 
            : PrimitivesBase ( streamWriter, CSWC::CSW_ELEMENT_VERTEX_WEIGHTS ) {}

        /** Copy constructor */
        VertexWeightsElement ( PrimitivesBase primitivesBase ) 
            : PrimitivesBase ( primitivesBase ) {}

        /** We want to open the vertexlist tag. */
        void prepareToAppendValues()
        {
            prepareBaseToAppendValues ( false, true );
        }

		/** Writes the \<wertex_weights\> element until the opening \<vcount\> element. Use this 
		function if you want to fill the \<vcount\> element using appandValues(). Call CloseVCountAndOpenVElement()
		to start filling the \<v\> element.*/
		void prepareToAppendVCountValues();

	};

	/**
	* Class for the linestrips element.
	*/
	class Linestrips : public PrimitivesBase
	{
	public:
		Linestrips ( StreamWriter* streamWriter ) 
			: PrimitivesBase ( streamWriter, CSWC::CSW_ELEMENT_LINE_STRIPS ) {}

		void prepareToAppendValues()
		{
			prepareBaseToAppendValues ( false, false );
		}

	private:
		Linestrips ( const Linestrips& primitivesBase );
		Linestrips& operator= ( const Linestrips& primitivesBase );

	};

	/**
	* Class for the trifans element.
	*/
	class Trifans : public PrimitivesBase
	{
	public:
		Trifans ( StreamWriter* streamWriter ) 
			: PrimitivesBase ( streamWriter, CSWC::CSW_ELEMENT_TRIFANS ) {}

		void prepareToAppendValues()
		{
			prepareBaseToAppendValues ( false, false );
		}

	private:
		Trifans ( const Trifans& primitivesBase );
		Trifans& operator= ( const Trifans& primitivesBase );

	};

	/**
	* Class for the tristrips element.
	*/
	class Tristrips : public PrimitivesBase
	{
	public:
		Tristrips ( StreamWriter* streamWriter ) 
			: PrimitivesBase ( streamWriter, CSWC::CSW_ELEMENT_TRISTRIPS ) {}

		void prepareToAppendValues()
		{
			prepareBaseToAppendValues ( false, false );
		}

	private:
		Tristrips ( const Tristrips& primitivesBase );
		Tristrips& operator= ( const Tristrips& primitivesBase );

	};


	typedef Primitive<CSWC::CSW_ELEMENT_LINES> Lines;	
    typedef Primitive<CSWC::CSW_ELEMENT_TRIANGLES> Triangles;
    typedef Primitive<CSWC::CSW_ELEMENT_POLYLIST> Polylist;

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_PRIMITIVES_H__


