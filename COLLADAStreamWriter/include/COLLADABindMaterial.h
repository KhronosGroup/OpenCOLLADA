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
