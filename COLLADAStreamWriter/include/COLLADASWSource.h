/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_SOURCE_H__
#define __COLLADASTREAMWRITER_SOURCE_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWConstants.h"

#include <string>
#include <vector>

namespace COLLADASW
{

    /** A class to add a source, including the array and an accessor.
    It is the base class for the Source template class.*/

    class SourceBase : public ElementWriter
    {

    public:

        /** A list that contains the names of all the parameter in the accessor*/
        typedef std::vector<String> ParameterNameList;

    private:

        TagCloser mSourceCloser;

        /** The id of the source*/
        String mNodeId;

        /** The name of source node */
        String mNodeName;

        /** The id of the array*/
        String mArrayId;

        /** The value of the count attribute of the accessor*/
        unsigned long mAccessorCount;

        /** The value of the stride attribute of the accessor*/
        unsigned long mAccessorStride;

        /** The list with the parameters. */
        ParameterNameList mParameterNameList;

    public:

    	SourceBase ( StreamWriter* streamWriter ) 
            : ElementWriter ( streamWriter )
            , mAccessorCount (0)
            , mAccessorStride (0)
        {}

        /** Returns a reference to the id of the source*/
        const String& getId() const
        {
            return mNodeId;
        }

        /** Sets the id of the source*/
        void setId ( const String& id )
        {
            mNodeId = id;
        }

        /** Returns a reference to the name of the source*/
        const String& getNodeName() const
        {
            return mNodeName;
        }

        /** Sets the name of the source*/
        void setNodeName ( const String& name )
        {
            mNodeName = name;
        }

        /** Returns a reference to the id of the array of the node*/
        const String& getArrayId() const
        {
            return mArrayId;
        }

        /** Sets the id of the array of the node*/
        void setArrayId ( const String& arrayId )
        {
            mArrayId = arrayId;
        }

        /** Returns the value of the count attribute of the accessor*/
        unsigned long getAccessorCount() const
        {
            return mAccessorCount;
        }

        /** Sets the count attribute of the accessor*/
        void setAccessorCount ( unsigned long accessorCount )
        {
            mAccessorCount = accessorCount;
        }

        /** Returns the value of the stride attribute of the accessor*/
        unsigned long getAccessorStride() const
        {
            return mAccessorStride;
        }

        /** Sets the stride attribute of the accessor*/
        void setAccessorStride ( unsigned long accessorStride )
        {
            mAccessorStride = accessorStride;
        }

        /** Returns a reference to the parameter list*/
        ParameterNameList& getParameterNameList()
        {
            return mParameterNameList;
        }


    protected:

        /** Prepares to fill the array. This member must be called exactly once
        before add is called the first time.*/
        void prepareBaseToAppendValues ( const String* arrayName );

        /** This function must be called after the last value has been added to the array and before another
        element has been opened*/
        void finishBase ( const String* parameterTypeName, bool closeSourceElement=true );

        /** Close the array element. */
        void closeArray();

        /** Close the source element. */
        void closeSource();

        /** Adds the base technique common to the source. */
        void addBaseTechnique ( const String* parameterTypeName );

    };

    /** A class template to add a source, including an the array and an accessor*/
    template < class Type, const String* arrayName, const String* parameterTypeName >
    class Source : public SourceBase
    {

    private:

        const String* mParameterTypeName;

    public:
        Source ( StreamWriter * streamWriter )
        : SourceBase ( streamWriter )
        , mParameterTypeName ( parameterTypeName )
        {}

        /** Prepares to fill the array. This member must be called exactly once
        before add is called the first time.*/
        inline void prepareToAppendValues()
        {
            prepareBaseToAppendValues ( arrayName );
        }

        /** Adds @a value to the array*/
        void appendValues ( const double matrix[][4] )
        {
            mSW->appendValues ( matrix );
        }

        /** Adds @a value to the array*/
        void appendValues ( const float matrix[][4] )
        {
            mSW->appendValues ( matrix );
        }

        /** Adds @a value to the array*/
        void appendValues ( const std::vector<Type>& value )
        {
            mSW->appendValues ( value );
        }

        /** Adds @a value to the array*/
        void appendValues ( const Type value )
        {
            mSW->appendValues ( value );
        }

        /** Adds @a value1  and @a value2 to the array*/
        void appendValues ( const Type value1, const Type value2 )
        {
            mSW->appendValues ( value1, value2 );
        }

        /** Adds @a value1, @a value2 and @a value3 to the array*/
        void appendValues ( const Type value1, const Type value2, const Type value3 )
        {
            mSW->appendValues ( value1, value2, value3 );
        }

        /** Adds @a value1, @a value2, @a value3 and @a value4 to the array*/
        void appendValues ( const Type value1, const Type value2, const Type value3, const Type value4 )
        {
            mSW->appendValues ( value1, value2, value3, value4 );
        }

        /**
         * This function must be called after the last value has been added to the array
         * and before another element has been opened.
         * @param closeSourceElement false, if we want to add some extra tags and close the element later.
         */
        void finish ( bool closeSourceElement=true )
        {
            finishBase ( mParameterTypeName, closeSourceElement );
        }

        /** Close the source element. */
        void closeSourceElement()
        {
            closeSource();
        }

        /** Sets the parameter type name */
        void setParameterTypeName ( const String* paramTypeName )
        {
            mParameterTypeName = paramTypeName;
        }
    };

    /** Param type independent source with double values. */
    typedef Source < double, &CSWC::CSW_ELEMENT_FLOAT_ARRAY, &CSWC::EMPTY_STRING > TypeIndependentSource;
    /** Param type independent source with float values. */
    typedef Source < float, &CSWC::CSW_ELEMENT_FLOAT_ARRAY, &CSWC::EMPTY_STRING > TypeIndependentSourceF;

    /** Param type "FLOAT" source with double values. */
    typedef Source < double, &CSWC::CSW_ELEMENT_FLOAT_ARRAY, &CSWC::CSW_VALUE_TYPE_FLOAT > FloatSource;
    /** Param type "FLOAT" source with float values. */
    typedef Source < float, &CSWC::CSW_ELEMENT_FLOAT_ARRAY, &CSWC::CSW_VALUE_TYPE_FLOAT > FloatSourceF;

    /** Param type "FLOAT4x4" source with double values. */
    typedef Source < double, &CSWC::CSW_ELEMENT_FLOAT_ARRAY, &CSWC::CSW_VALUE_TYPE_FLOAT4x4 > Float4x4Source;
    /** Param type "FLOAT4x4" source with double values. */
    typedef Source < float, &CSWC::CSW_ELEMENT_FLOAT_ARRAY, &CSWC::CSW_VALUE_TYPE_FLOAT4x4 > Float4x4SourceF;

    /** Param type "NAME" source with String values. */
    typedef Source < String, &CSWC::CSW_ELEMENT_NAME_ARRAY, &CSWC::CSW_VALUE_TYPE_NAME > NameSource;

    /** Param type "NAME" source with String values. */
    typedef Source < String, &CSWC::CSW_ELEMENT_IDREF_ARRAY, &CSWC::CSW_VALUE_TYPE_IDREF > IdRefSource;

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_SOURCE_H_
