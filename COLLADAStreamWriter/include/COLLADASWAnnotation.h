/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASWStreamWriter.

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

//         /** The name of the current annotation. */
//         String mName;
// 
//         /** Consists of a COLLADASW type element that contains a 
//         value of that type. Valid type elements are:
//         bool, bool2, bool3, bool4, int, int2, int3, int4, float,
//         float2, float3, float4, float2x2, float3x3, float4x4, string */
//         ValueType::ColladaType mValueType;
// 
//         /** The value for the element. */
//         Type mValue;
// 
//         /** Number of values to insert (for arrays and pointer) */
//        int mNValues;

        /** Tag closer for the annotation. */
        TagCloser mAnnoCloser;

    public:
        
        /** Constructor. */
        Annotation ( StreamWriter *sw ) : ElementWriter ( sw ) {}

//         /** Constructor. */
//         Annotation ( 
//             StreamWriter *sw, 
//             const String &name, 
//             const ValueType::ColladaType &valueType, 
//             const Type val, 
//             int nVal=-1 ) 
//         : ElementWriter ( sw ) 
//         , mName ( name ) 
//         , mValueType ( valueType )
//         , mValue ( val ) 
//         , mNValues ( nVal )
//         {}

        /** Destructor. */
        virtual ~Annotation () {}

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
            mSW->appendValues ( values, nval );
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
            const T val ) const
        {
            openAnnotation ( name );
            openValuesElement ( type );
            appendValues ( val );
            closeValuesElement ();
            closeAnnotation ();
        }

    };

}

#endif // __COLLADASTREAMWRITER_ANNOTATION_H__