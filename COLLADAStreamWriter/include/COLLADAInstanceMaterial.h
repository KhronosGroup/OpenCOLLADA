/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_INSTANCE_MATERIAL_H__
#define __COLLADASTREAMWRITER_INSTANCE_MATERIAL_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include "COLLADASWC.h"
#include "COLLADAURI.h"

namespace COLLADA
{

    class InstanceMaterialList;

    /** A class that holds informations of an @a \<instance_material\> element*/
    class InstanceMaterial
    {

    private:

        String mSymbol;
        URI mTarget;

    public:

        /** Constructor
        @param symbol The symbol name
        @param target The target
        */
        InstanceMaterial ( const String& symbol, const URI& target ) 
        : mSymbol ( symbol ), mTarget ( target ) {}

        /** Returns the symbol*/
        const String & getSymbol() const
        {
            return mSymbol;
        }

        /** Returns the target*/
        const URI & getTarget() const
        {
            return mTarget;
        }

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

        /** Set this class a friend, so it can call the add() method.  */
        friend class BindMaterial;

        /** List of all the inputs*/
        typedef std::list<InstanceMaterial> List;
        List mList;

        /** Add all the instance materials, added using push_back(), to the stream*/
        void add();

    };

} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_INSTANCE_MATERIAL_H__
