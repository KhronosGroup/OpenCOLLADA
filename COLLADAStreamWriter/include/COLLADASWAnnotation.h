/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_ANNOTATION_H__
#define __COLLADASTREAMWRITER_ANNOTATION_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWValueType.h"

namespace COLLADASW
{
    
    /** Adds a strongly typed annotation remark to the parent object into 
    the collada document. 
    Concepts: Annotations represent objects of the form SYMBOL = VALUE, 
    where SYMBOL is a user-defined identifier and VALUE is a strongly 
    typed value. Annotations communicate metainformation from the Effect 
    Runtime to the application only and are not interpreted by the COLLADASW 
    document. 
    Parent elements:
    effect, technique (FX) (in profile_CG, profile_GLES, profile_GLSL), pass,
    newparam (in profile_CG, profile_GLES, profile_GLSL, and effect),
    technique/newparam (in profile_CG, profile_GLES, profile_GLSL),
    technique/setparam (in profile_GLSL and profile_GLES), generator,
    generator/setparam, shader
    */
    class Annotation : public ElementWriter
    {

    private:

        enum UnionType
        {
            UNION_TYPE_FLOAT,
            UNION_TYPE_BOOL,
            UNION_TYPE_INT,
            UNION_TYPE_STRING,
            UNION_TYPE_UNKNOWN,
        };

    private:

        /** The name of the current annotation. */
        String mName;

        /** Consists of a COLLADASW type element that contains a 
        value of that type. Valid type elements are:
        bool, bool2, bool3, bool4, int, int2, int3, int4, float,
        float2, float3, float4, float2x2, float3x3, float4x4, string */
        ValueType::ColladaType mValueType;

        /**
         * The union stores the value, in depend on the type.
         */
        union AnnotationValues {
            const char* strVal;
            const int* intVal;
            const bool* boolVal;
            const float* floatVal;
        } mValue;

        /** Number of values to insert (for arrays and pointer) */
        int mNumValues;

		/** The value type of the used union value. */
        UnionType mUnionType;

        /** Tag closer for the annotation. */
        TagCloser mAnnoCloser;

    public:
        
        /** Constructor. */
        Annotation ( StreamWriter *sw ) : ElementWriter ( sw ), mUnionType ( UNION_TYPE_UNKNOWN ) {}

        /** Constructor. */
        Annotation ( 
            StreamWriter *sw, 
            const String &name, 
            const ValueType::ColladaType &valueType, 
            const float* val, 
            int nVal=-1 ) 
        : ElementWriter ( sw ) 
        , mName ( name ) 
        , mValueType ( valueType )
        , mNumValues ( nVal )
        , mUnionType ( UNION_TYPE_FLOAT )
        {
            mValue.floatVal = val; 
        }

        /** Constructor. */
        Annotation ( 
            StreamWriter *sw, 
            const String &name, 
            const ValueType::ColladaType &valueType, 
            const bool* val, 
            int nVal=-1 ) 
            : ElementWriter ( sw ) 
            , mName ( name ) 
            , mValueType ( valueType )
            , mNumValues ( nVal )
            , mUnionType ( UNION_TYPE_BOOL )
        {
            mValue.boolVal = val;
        }

        /** Constructor. */
        Annotation ( 
            StreamWriter *sw, 
            const String &name, 
            const ValueType::ColladaType &valueType, 
            const int* val, 
            int nVal=-1 ) 
            : ElementWriter ( sw ) 
            , mName ( name ) 
            , mValueType ( valueType )
            , mNumValues ( nVal )
            , mUnionType ( UNION_TYPE_INT )
        {
            mValue.intVal = val;
        }

        /** Constructor. */
        Annotation ( 
            StreamWriter *sw, 
            const String &name, 
            const ValueType::ColladaType &valueType, 
            const char* val, 
            int nVal=-1 ) 
            : ElementWriter ( sw ) 
            , mName ( name ) 
            , mValueType ( valueType )
            , mNumValues ( nVal )
            , mUnionType ( UNION_TYPE_STRING )
        {
            mValue.strVal = val;
        }

        /** Destructor. */
        virtual ~Annotation () {}

//         const float* getFloatValues ( int& numValues ) const { numValues = mNumValues; return mValue.floatVal; }
//         void setFloatValues ( float* val, const int numValues ) { mNumValues = numValues; mValue.floatVal = val; }
// 
//         const int* getIntValues ( int& numValues ) const { numValues = mNumValues; return mValue.intVal; }
//         void setIntValues ( int* val, const int numValues ) { mNumValues = numValues; mValue.intVal = val; }
// 
//         const bool* getBoolValues ( int& numValues ) const { numValues = mNumValues; return mValue.boolVal; }
//         void setBoolValues ( bool* val, const int numValues ) { mNumValues = numValues; mValue.boolVal = val; }
// 
//         const String getStringValue () const { return String(mValue.strVal); }
//         void setStringValue ( char* val ) { mNumValues = 1; mValue.strVal = val; }

        /** Write the annotation manual. */
        void openAnnotation ( const String &name ) 
        {
            mAnnoCloser = mSW->openElement ( CSWC::CSW_ELEMENT_ANNOTATE );

            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, name );
        }

        /** Write the annotation manual. */
        void closeAnnotation () 
        {
            mAnnoCloser.close ();
        }

        /** Write the annotation manual. */
        void openValuesElement ( const ValueType::ColladaType &valueType ) 
        {
            mSW->openElement ( ValueType::getColladaTypeString ( valueType ) );
        }

        /** Write the annotation manual. */
        void closeValuesElement () 
        {
            mSW->closeElement ();
        }

        /** Write the annotation manual. */
        template <class T> 
        void appendValues ( const T values )
        {
            mSW->appendValues ( values );
        }

        /** Write the annotation manual. */
        template <class T> 
        void appendValues ( const T* values, int nval )
        {
            if ( nval > 0 )
            {
                for ( int i=0; i<nval; ++i )
                {
                    mSW->appendValues ( values[i] );
                }
            }
        }

        /** Adds a strongly typed annotation remark to the parent object into 
         the collada document. 
         @param name The name of the current annotation.
         @param dataTypeName Consists of a COLLADASW type element that contains a 
                    value of that type. Valid type elements are:
                    bool, bool2, bool3, bool4, int, int2, int3, int4, float,
                    float2, float3, float4, float2x2, float3x3, float4x4, string
         @param val The value for the element.
        */
        template <class T>
        void add ( 
            const String &name, 
            const ValueType::ColladaType &type, 
            const T val )
        {
            openAnnotation ( name );
            openValuesElement ( type );
            appendValues ( val );
            closeValuesElement ();
            closeAnnotation ();
        }

        /**
         * Adds a strongly typed annotation remark to the parent object into the collada document.
         */
        void add () 
        {
            openAnnotation ( mName );
            openValuesElement ( mValueType );

            switch ( mUnionType )
            {
            case UNION_TYPE_FLOAT:
                appendValues ( mValue.floatVal, mNumValues );
                break;
            case UNION_TYPE_INT:
                appendValues ( mValue.intVal, mNumValues );
                break;
            case UNION_TYPE_STRING:
                appendValues ( String (mValue.strVal) );
                break;
            case UNION_TYPE_BOOL:
                appendValues ( mValue.boolVal, mNumValues );
                break;
            default:
                break;
            }
            closeValuesElement ();
            closeAnnotation ();
        }
    };

}

#endif // __COLLADASTREAMWRITER_ANNOTATION_H__
