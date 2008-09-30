/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __COLLADASTREAMWRITER_BASE_INPUT_ELEMENT_H__
#define __COLLADASTREAMWRITER_BASE_INPUT_ELEMENT_H__

#include "COLLADAPrerequisites.h"
#include "COLLADABaseElement.h"
#include "COLLADAInputList.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    /** Template class representing a base input element. */
    class BaseInputElement : public BaseElement
    {

    private:

        /** List of all the inputs*/
        InputList mInputList;

    public:

        /**
         * Constructor.
         * @param streamWriter Pointer to the stream.
         */
        BaseInputElement ( StreamWriter* streamWriter, const String& elementName )
        : BaseElement ( streamWriter, elementName )
        , mInputList ( streamWriter )
        {}

        /**
         * Destructor.
         */
        virtual ~BaseInputElement() {};

        /** Returns a reference to the input list */
        InputList& getInputList()
        {
            return mInputList;
        }

        /** Adds the element to the stream */
        void add();

    };

    //---------------------------------------------------------------

    /**
     * Template class to define the typedefs.
     */
    template<const String& elementName>
    class BaseInputElementTemplate : public BaseInputElement
    {
    public:
        BaseInputElementTemplate ( StreamWriter* streamWriter )
            : BaseInputElement( streamWriter, elementName ) {};
    };

    //---------------------------------------------------------------
    /** Vertices input element for the geometry. */
    typedef BaseInputElementTemplate<CSWC::COLLADA_ELEMENT_VERTICES> VerticesElement;

    /** Joints input element for the controller. */
    typedef BaseInputElementTemplate<CSWC::COLLADA_ELEMENT_JOINTS> JointsElement;

    /** Joints input element for the controller. */
    typedef BaseInputElementTemplate<CSWC::COLLADA_ELEMENT_TARGETS> TargetsElement;


} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_BASE_INPUT_ELEMENT_H__
