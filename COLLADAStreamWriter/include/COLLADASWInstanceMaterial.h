/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_INSTANCE_MATERIAL_H__
#define __COLLADASTREAMWRITER_INSTANCE_MATERIAL_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWConstants.h"

#include "COLLADABUURI.h"


namespace COLLADASW
{

    class BindVertexInput
	{
	private:
		/** Which effect parameter to bind. Required.*/
		String mSemantic;

		/** Which input semantic to bind. Required.*/
		String mInputSemantic;

		/** Which input set to bind. Optional. -1 if not set.*/
		int mInputSet;
	public:

		BindVertexInput(const COLLADASW::String& semantic, const COLLADASW::String& inputSemantic, int inputSet = -1)
			: mSemantic(semantic), mInputSemantic(inputSemantic), mInputSet(inputSet){}

		/** Which effect parameter to bind. Required.*/
		const COLLADASW::String& getSemantic() const { return mSemantic; }

		/** Which effect parameter to bind. Required.*/
		void setSemantic(const COLLADASW::String& semantic) { mSemantic = semantic; }

		/** Which input semantic to bind. Required.*/
		const COLLADASW::String& getInputSemantic() const { return mInputSemantic; }

		/** Which input semantic to bind. Required.*/
		void setInputSemantic(const COLLADASW::String& inputSemantic) { mInputSemantic = inputSemantic; }
		
		/** Which input set to bind. Optional. -1 if not set.*/
		int getInputSet() const { return mInputSet; }

		/** Which input set to bind. Optional. -1 if not set.*/
		void setInputSet(int inputSet) { mInputSet = inputSet; }

	private:
		/** Set this class a friend, so it can call the add() method.  */
		friend class InstanceMaterial;

		/** Add all the instance materials, added using push_back(), to the stream*/
		void add( StreamWriter* sw);

	};


    class InstanceMaterialList;

    /** A class that holds informations of an @a \<instance_material\> element*/
    class InstanceMaterial
    {
	private:
		/** List of all the BindVertexInput*/
		typedef std::list<BindVertexInput> BindVertexInputList;
    private:

		BindVertexInputList mBindVertexInputList;
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
        const String & getSymbol() const {return mSymbol; }

        /** Returns the target*/
        const URI & getTarget() const { return mTarget; }

		/** Adds @a input to list of inputs that should be added*/
		void push_back ( const BindVertexInput& input ) { mBindVertexInputList.push_back ( input ); }

	private:
		/** Set this class a friend, so it can call the add() method.  */
		friend class InstanceMaterialList;

		/** Add all the instance materials, added using push_back(), to the stream*/
		void add( StreamWriter* sw);


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
        void push_back ( const InstanceMaterial& input ) { mList.push_back ( input ); }

		/** Returns a reference to the last InstanceMaterial in the list. The material list must not be empty.*/
		InstanceMaterial& back() { return mList.back(); }

        /** Return true, if the list of material bindings is empty, false otherwise*/
        bool empty() const { return mList.empty(); }

    private:

        /** Set this class a friend, so it can call the add() method.  */
        friend class BindMaterial;

        /** List of all the inputs*/
        typedef std::list<InstanceMaterial> List;
        List mList;

        /** Add all the instance materials, added using push_back(), to the stream*/
        void add();

    };

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_INSTANCE_MATERIAL_H__
