/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_PARAM_H__
#define __COLLADASTREAMWRITER_PARAM_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWAnnotation.h"
#include "COLLADASWValueType.h"
#include "COLLADASWSampler.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    /** A class to add a param to the stream.*/
    class ParamBase : public ElementWriter
    {

    protected:

        /** Used to close the current param. */
        TagCloser mParamCloser;

        /** The parameter's name. */
        String mParamName;

        /** Flag, if the value element is opened. */
        bool mValueElementIsOpen;

        /** The type of the current parameter. */
        ValueType::ColladaType mParamType;

    public:

        /** Constructor
        @param streamWriter The stream the asset should be written to.*/
        ParamBase (
            StreamWriter* streamWriter,
            const String* paramName=&CSWC::CSW_ELEMENT_PARAM,
            const ValueType::ColladaType& paramType=ValueType::VALUE_TYPE_UNSPECIFIED );

        /** Destructor*/
        virtual ~ParamBase() {}

        /** Set the current param type. */
        void setParamType ( const ValueType::ColladaType& paramType );

        /** Set the current param name. */
        void setParamName ( const String& paramName );

        /** Returns the name of the current parameter. */
        const String& getParamName () const { return mParamName; }

        /** Opens the current param element. */
        virtual void openParam ( const String& refe="" );

        /** Set a param attribute */
        void appendAttribute ( const String& name, const String& val );

        /** Writes the semantic of the parameter. */
        void addSemantic ( const String &semantic );

        /** Adds a annotation to the param. */
        template <class T>
        void addAnnotation (
            const String &name,
            const ValueType::ColladaType &valueType,
            const T val )
        {
            COLLADASW::Annotation annotation ( mSW );
            annotation.openAnnotation ( name );
            annotation.openValuesElement ( valueType );
            annotation.appendValues ( val );
            annotation.closeValuesElement ();
            annotation.closeAnnotation ();
        }

        /** Adds a annotation to the param. */
        template <class T>
        void addAnnotation (
            const String &name,
            const ValueType::ColladaType &valueType,
            const T val,
            const int nval )
        {
            COLLADASW::Annotation annotation ( mSW );
            annotation.openAnnotation ( name );
            annotation.openValuesElement ( valueType );
            annotation.appendValues ( val, nval );
            annotation.closeValuesElement ();
            annotation.closeAnnotation ();
        }

        /** Adds a annotation to the param. */
        void addAnnotations ( std::vector<Annotation>& annotations )
        {
            for ( size_t i=0; i<annotations.size (); ++i )
            {
                COLLADASW::Annotation& annotation = annotations [i];
                annotation.add ();
            }
        }

        /** Opens the param's value element of the given type. */
        void openValuesElement ();

        /** Close the param's value element of the given type. */
        void closeValuesElement ();

        /** Adds @a value to the array*/
        template <class Type>
        void appendValues ( const std::vector<Type>& value )
        {
            openValuesElement ();
            mSW->appendValues ( value );
        }

        /** Adds @a value to the array*/
        template <class Type>
        void appendValues ( const Type value )
        {
            openValuesElement ();
            mSW->appendValues ( value );
        }

        /** Adds @a value1  and @a value2 to the array*/
        template <class Type>
        void appendValues ( const Type value1, const Type value2 )
        {
            openValuesElement ();
            mSW->appendValues ( value1, value2 );
        }


        /** Adds @a value1, @a value2 and @a value3 to the array*/
        template <class Type>
        void appendValues ( const Type value1, const Type value2, const Type value3 )
        {
            openValuesElement ();
            mSW->appendValues ( value1, value2, value3 );
        }

        /** Adds @a value1, @a value2, @a value3 and @a value4 to the array*/
        template <class Type>
        void appendValues ( const Type value1, const Type value2, const Type value3, const Type value4 )
        {
            openValuesElement ();
            mSW->appendValues ( value1, value2, value3, value4 );
        }

        /**
        * This function must be called after the last value has been added to the array
        * and before another element has been opened.
        * @param closeSourceElement false, if we want to add some extra tags and close the element later.
        */
        void closeParam ();

    protected:

    	/** Returns the closer tag for the current parameter. */
    	TagCloser& getParamCloser () { return mParamCloser; }

    	/** Set the current tag closer. */
    	void setParamCloser ( const TagCloser& tagCloser ) { mParamCloser = tagCloser; }

    };

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_PARAM_H__
