/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_BASE_INPUT_ELEMENT_H__
#define __COLLADASTREAMWRITER_BASE_INPUT_ELEMENT_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWBaseElement.h"
#include "COLLADASWInputList.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
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
    typedef BaseInputElementTemplate<CSWC::CSW_ELEMENT_VERTICES> VerticesElement;

    /** Joints input element for the controller. */
    typedef BaseInputElementTemplate<CSWC::CSW_ELEMENT_JOINTS> JointsElement;

    /** Joints input element for the controller. */
    typedef BaseInputElementTemplate<CSWC::CSW_ELEMENT_TARGETS> TargetsElement;


} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_BASE_INPUT_ELEMENT_H__
