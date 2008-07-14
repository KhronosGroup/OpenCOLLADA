/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __COLLADASTREAMWRITER_BASE_ELEMENT_H__
#define __COLLADASTREAMWRITER_BASE_ELEMENT_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"

namespace COLLADA
{

    /** Template class representing a base element. */
//    template<const String& mElementName>
    class BaseElement : public ElementWriter
    {
    protected:

        /** Name of the element. */
        String mElementName;

        /** The id of the vertex element*/
        String mNodeId;

        /** The name of the vertex node*/
        String mNodeName;

    public:

        /**
         * Constructor.
         * @param streamWriter Pointer to the stream.
         */
        BaseElement ( StreamWriter* streamWriter, const String& elementName )
        : ElementWriter ( streamWriter )
        , mElementName( elementName )
        , mNodeId ( "" )
        , mNodeName ( "" )
        {}

        /**
         * Destructor.
         */
        virtual ~BaseElement() {};

        /** Returns a reference to the id of the element*/
        const String& getId() const
        {
            return mNodeId;
        }

        /** Sets the id of the element*/
        void setId ( const String& id )
        {
            mNodeId = id;
        }

        /** Returns a reference to the name of the element*/
        const String& getNodeName() const
        {
            return mNodeName;
        }

        /** Sets the id of the element*/
        void setNodeName ( const String& nodeName )
        {
            mNodeName = nodeName;
        }

        /** Adds the element to the stream */
        void add();

    };

    //---------------------------------------------------------------

    /**
    * Template class to define the typedefs.
    */
    template<const String& elementName>
    class BaseElementTemplate : public BaseElement
    {
    public:
        BaseElementTemplate ( StreamWriter* streamWriter ) 
            : BaseElement( streamWriter, elementName ) {};
    };


} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_BASE_ELEMENT_H__
