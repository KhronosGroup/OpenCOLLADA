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

#ifndef __COLLADASTREAMWRITER_BIND_MATERIAL_H__
#define __COLLADASTREAMWRITER_BIND_MATERIAL_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    class InstanceMaterialList;

    class BindMaterial;

    /** A class that holds informations of an @a \<instance_material\> element*/

    class InstanceMaterial
    {

    public:
        /** Constructor
        @param symbol The symbol name
        @param target The target
        */
        InstanceMaterial ( String symbol, String target ) : mSymbol ( symbol ), mTarget ( target ) {}

        /** Returns the symbol*/
        const String & getSymbol() const
        {
            return mSymbol;
        }

        /** Returns the target*/
        const String & getTarget() const
        {
            return mTarget;
        }

    private:
        String mSymbol;
        String mTarget;

    };

    /** A class that hold a list of instances of InstanceMaterial and writes it to stream*/

    class InstanceMaterialList : public ElementWriter
    {

    public:
        /** Constructor
        @param streamWriter The stream writer the list should be written to
        */
        InstanceMaterialList ( StreamWriter * streamWriter ) : ElementWriter ( streamWriter ) {}

        /** Destructor*/
        virtual ~InstanceMaterialList() {}

        /** Adds @a input to list of inputs that should be added*/
        void push_back ( InstanceMaterial input )
        {
            mList.push_back ( input );
        }

        /** Return true, if the list of material bindings is empty, false otherwise*/
        bool empty() const
        {
            return mList.empty();
        }

    private:

        friend class BindMaterial;
        /** List of all the inputs*/
        typedef std::list<InstanceMaterial> List;
        List mList;

        /** Add all the instance materials, added using push_back(), to the stream*/
        void add();
    };

    /** A class to write a @a \<bind_material\> element*/

    class BindMaterial : public ElementWriter
    {

    public:
        /** Constructor
        @param streamWriter The stream writer the @a \<bind_material\> element should be written to
        */
        BindMaterial ( StreamWriter * streamWriter )
                : ElementWriter ( streamWriter ),
                mInstanceMaterialList ( streamWriter ) {}

        /** Returns a reference to list of instance material objects. Use this together with InstanceMaterialList::push_back() to add
        instance materials.*/
        InstanceMaterialList & getInstanceMaterialList()
        {
            return mInstanceMaterialList;
        }

    private:
        TagCloser mBindMaterialCloser;

        friend class InstanceGeometry;

        /** List of all the instance materials*/
        InstanceMaterialList mInstanceMaterialList;

        /** Adds the BindMaterial to the stream*/
        void add();
    };

} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_BIND_MATERIAL_H__
